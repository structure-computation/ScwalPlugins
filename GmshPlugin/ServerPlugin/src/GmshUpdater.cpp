#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QFile>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>
#include "GmshUpdater.h"

typedef LMT::Vec<double,3> Pvec;

struct AutoRm {
    AutoRm( QString f ) : f( f ) {}
    ~AutoRm() { QFile::remove( f ); }
    QString f;
};

bool GmshUpdater::run( MP mp ) {
    MP ch = mp[ "_children[ 0 ]" ];
    if ( ch.ok() ) {
        // check if a .geo file has been provided
        QString name = ch["_name"];
        bool test_geo = (ch.type() == "FileItem" and name.endsWith(".geo"));
        bool test_unv = (ch.type() == "FileItem" and name.endsWith(".unv"));
        bool test_stp = (ch.type() == "FileItem" and name.endsWith(".stp"));
        
        // retrieve or make a .geo file
        QFile* geo = 0;
        if(test_geo or test_unv or test_stp){
            MP file_geo = mp["_children[0]"];
            quint64 ptr = file_geo[ "_ptr" ];
            PRINT(file_geo.type().toStdString());
            QString name = file_geo[ "_name" ];
            MP data = sc->load_ptr( ptr );
            QString path;
            if( data.ok() and data.type() == "Path") {
                path = (QString) data;
            }
            else {
                add_message( mp, ET_Error, "Unable to find .geo path" );
                return false;
            }
            //qDebug() << "Path : " << path_csv;
            std::string filename(path.toStdString());
            PRINT(filename);
            PRINT(name.toStdString());
            geo = new QFile(filename.c_str());
            if(!geo->open(QIODevice::ReadOnly)){
                add_message( mp, ET_Error, "Unable to open .geo file" );
                return false;
            }
        }
        else {
            double base_size = mp[ "base_size" ];
            if ( base_size <= 0 ) {
                add_message( mp, ET_Error, "Please specify a valid base size" );
                return false;
            }
            QTemporaryFile* tmp = new QTemporaryFile();
            geo = tmp;
            tmp->open();
            QTextStream out( tmp );
            MP ch_mesh = ch["mesh"];
            make_geo( out, ch_mesh, base_size );
            out.flush();
            tmp->flush();
        }

        // output mesh
        MP output = mp[ "_output[0]" ];
        MP om = output[ "_mesh" ];
        om[ "points" ].clear();
        om[ "_elements" ].clear();

        // .geo -> .msh
        AutoRm arm( geo->fileName() + ".msh" );
        AutoRm arm2( geo->fileName() + ".unv" );
        AutoRm arm3( geo->fileName() + ".stp" );
        QString cmd;
        if(test_unv){
          cmd = "cp " + geo->fileName() + "  " + geo->fileName() + ".unv; gmsh " + geo->fileName() + ".unv -o " + geo->fileName() + ".msh -3 > /dev/null";
          qDebug() << cmd;
          PRINT("unv");
        }else if(test_stp){
          cmd = "cp " + geo->fileName() + "  " + geo->fileName() + ".stp; gmsh " + geo->fileName() + ".stp -o " + geo->fileName() + ".msh -3 -clcurv -optimize > /dev/null";
          qDebug() << cmd;
          PRINT("stp");
        }else{
          cmd = "cat " + geo->fileName() + "; gmsh -o " + geo->fileName() + ".msh -3 -clcurv -optimize " + geo->fileName() + " > /dev/null";
        }
        qDebug() << cmd;
        if ( system( cmd.toAscii().data() ) ) {
            add_message( mp, ET_Error, "gmsh has crashed generating msh file" );
            return true;
        }
        // Debug
        cmd = "cp " + geo->fileName() + ".msh ~/test.msh";
        system( cmd.toAscii().data() );

        TypedArray<int> *triangle_con = new TypedArray<int>;
        TypedArray<int> *tetro_con = new TypedArray<int>;
        typedef QPair<int,int> TL;
        QSet<TL> lines;

        // read the .msh file
        QFile msh( geo->fileName() + ".msh" );
        msh.open( QFile::ReadOnly );
        QTextStream inp( &msh );
        int mode = 0;
        while( true ) {
            QString l = inp.readLine();
            if ( not l.size() )
                break;

            QTextStream ls( &l );
            switch ( mode ) {
            case 0:
                if ( l == "$Nodes"    ) { mode = 1; continue; }
                if ( l == "$Elements" ) { mode = 3; continue; }
                continue;
            case 1: // nb nodes
                mode = 2;
                continue;
            case 2: { // node
                if ( l == "$EndNodes" ) { mode = 0; continue; }
                int n; double x, y, z;
                ls >> n >> x >> y >> z;

                MP pos = MP::new_lst( "Vec_3" );
                pos << x << y << z;

                MP pnt = MP::new_obj( "Point" );
                pnt[ "pos" ] = pos;

                om[ "points" ] << pnt;
                continue;
            } case 3: // nb elements
                mode = 4;
                continue;
            case 4: // element
                if ( l == "$EndElements" ) { mode = 0; continue; }
                int n, type_elem, nb_tags;
                ls >> n >> type_elem >> nb_tags;
                for( int i = 0; i < nb_tags; ++i )
                    ls >> n;

                if ( type_elem == 2 ) { // triangle
                    int triangle[ 3 ];
                    for( int i = 0; i < 3; ++i ) {
                        ls >> n;
                        triangle[ i ] = n - 1;
                        triangle_con->_data << n - 1;
                    }
                    //for( int i = 0; i < 3; ++i )
                    //    for( int j = 0; j < i; ++j )
                    //        lines.insert( qMakePair( qMin( triangle[ j ], triangle[ i ] ), qMax( triangle[ j ], triangle[ i ] ) ) );
                } else if ( type_elem == 4 ) { // tetra
                    int tetra[ 4 ];
                    for( int i = 0; i < 4; ++i ) {
                        ls >> n;
                        tetra[ i ] = n - 1;
                        tetro_con->_data << n - 1;
                    }
                    //for( int i = 0; i < 3; ++i )
                    //    for( int j = 0; j < i; ++j )
                    //        lines.insert( qMakePair( qMin( triangle[ j ], triangle[ i ] ), qMax( triangle[ j ], triangle[ i ] ) ) );
                }
                continue;
            }
        }

        // triangle
        triangle_con->_size.resize( 2 );
        triangle_con->_size[ 0 ] = 3;
        triangle_con->_size[ 1 ] = triangle_con->_data.size() / 3;

        MP triangles = MP::new_obj( "Element_TriangleList" );
        triangles[ "indices" ] = triangle_con;
        om[ "_elements" ] << triangles;

        // tetrahedra
        tetro_con->_size.resize( 2 );
        tetro_con->_size[ 0 ] = 4;
        tetro_con->_size[ 1 ] = tetro_con->_data.size() / 4;

        MP tetrahedra = MP::new_obj( "Element_TetrahedraList" );
        tetrahedra[ "indices" ] = tetro_con;
        om[ "_elements" ] << tetrahedra;
        
        /* .geo -> .unv (TODO: comment referencer le fichier)
        int generate_unv = mp["generate_unv"];
        if(generate_unv) {
            //QString cmd_unv = "gmsh -o " + geo->fileName() + ".unv -3 " + geo->fileName() + " > /dev/null";
            QString cmd_unv = "gmsh -o ~/test.unv -3 " + geo->fileName() + " > /dev/null";
            if ( system( cmd_unv.toAscii().data() ) ) {
                add_message( mp, ET_Error, "gmsh has crashed generating unv file" );
                return true;
            }
            //MP unv_file = MP::new_file(geo->fileName() + ".unv");
            //mp["output"] << unv_file;
            // Debug
            //cmd_unv = "cp " + geo->fileName() + ".unv ~/test.unv";
            //system( cmd_unv.toAscii().data() );
        }//*/
        
        //mp.flush();
        //        foreach( TL l, lines ) {
        //            MP rs = MP::new_lst();
        //            rs << l.first << l.second;
        //            om[ "lines" ] << rs;
        //        }
        
        //qDebug() << om;
    }
    //qDebug() << "GmshItem : ";
    //qDebug() << mp;
    add_message( mp, ET_Info, "Mesher -> OK" );
    qDebug() << "Mesher just finish";
}

void GmshUpdater::make_geo( QTextStream &geo, const MP &ch, double base_size ) {
    // points
    MP points = ch[ "points" ];
    int np = points.size(), ne = 0;
    for( int i = 0; i < np; ++i ) {
        MP pos = points[ i ][ "pos" ];
        geo << "Point(" << i + 1 << ") = { " << double( pos[ 0 ] ) << ", " << double( pos[ 1 ] ) << ", " << double( pos[ 2 ] ) << ", " << base_size << " };\n";
    }

    // elements
    MP elements = ch[ "_elements" ];
    QMap<Model *,QVector<int> > elem_corr;
    for( int i = 0; i < elements.size(); ++i )
        make_geo_rec( elem_corr, geo, elements[ i ], base_size, points, np, ne );
}

void GmshUpdater::make_geo_rec( QMap<Model *,QVector<int> > &elem_corr, QTextStream &geo, const MP &elem, double base_size, const MP &points, int &np, int &ne ) {
    if ( elem.ok() ) {
        // recursivity
        QVector<int> &res = elem_corr[ elem.model() ];
        if ( not res.size() ) {
            MP boundaries = elem[ "boundaries" ];
            for( int i = 0; i < boundaries.size(); ++i )
                make_geo_rec( elem_corr, geo, boundaries[ i ][ "e" ], base_size, points, np, ne );

            // -> geo
            if ( elem.type() == "Element_Line" ) {
                int n = ++ne; res << n;
                geo << "Line(" << n << ") = { " << int( elem[ "indices" ][ 0 ] ) + 1 << ", " << int( elem[ "indices" ][ 1 ] ) + 1 << " };\n";

            } else if ( elem.type() == "Element_Arc" ) {
                // get the coordinates
                int ind[] = { elem[ "indices" ][ 0 ], elem[ "indices" ][ 1 ], elem[ "indices" ][ 2 ] };
                Pvec P[ 3 ];
                for( int n = 0; n < 3; ++n ) {
                    MP pos = points[ ind[ n ] ][ "pos" ];
                    for( int d = 0; d < 3; ++d )
                        P[ n ][ d ] = pos[ d ];
                }

                // compute the center
                Pvec P01( P[ 1 ] - P[ 0 ] ), P02( P[ 2 ] - P[ 0 ] );
                double x1 = LMT::length( P01 );
                P01 /= x1;
                double x2 = LMT::dot( P02, P01 );
                P02 -= x2 * P01;

                double y2 = LMT::length( P02 );
                P02 /= y2;

                double C0 = x1 * 0.5;
                double C1 = ( x2 * x2 + y2 * y2 - x2 * x1 ) / ( 2.0 * y2 );

                Pvec C = P[ 0 ] + C0 * P01 + C1 * P02;

                double a0 = atan2(  0 - C1,  0 - C0 );
                double a1 = atan2(  0 - C1, x1 - C0 );
                double a2 = atan2( y2 - C1, x2 - C0 );

                double ma = 0.5 * ( a0 + a2 );
                if ( LMT::abs( a1 - ma ) > LMT::abs( a0 - ma ) ) { // si a1 n'est pas compris dans l'intervalle
                    if ( a2 < a0 )
                        a2 += 2 * M_PI;
                    else
                        a0 += 2 * M_PI;
                }

                ma = 0.5 * ( a0 + a2 );
                if ( LMT::abs( a1 - ma ) > LMT::abs( a0 - ma ) ) // si a1 n'est toujours pas compris dans l'intervalle
                    a1 += 2 * M_PI;



                int ind_C = ++np;
                geo << "Point(" << ind_C << ") = { " << C[ 0 ] << ", " << C[ 1 ] << ", " << C[ 2 ] << ", " << base_size << " };\n";

                if ( LMT::abs( a2 - a0 ) >= M_PI ) {
                    double ma = 0.5 * ( a0 + a2 );
                    double R = length( P[ 0 ] - C );
                    Pvec I = C + cos( ma ) * R * P01 + sin( ma ) * R * P02;

                    int ind_I = ++np;
                    geo << "Point(" << ind_I << ") = { " << I[ 0 ] << ", " << I[ 1 ] << ", " << I[ 2 ] << ", " << base_size << " };\n";

                    int n0 = ++ne; res << n0;
                    geo << "Circle(" << n0 << ") = { " << ind[ 0 ] + 1 << ", " << ind_C << ", " << ind_I        << " };\n";
                    int n1 = ++ne; res << n1;
                    geo << "Circle(" << n1 << ") = { " << ind_I        << ", " << ind_C << ", " << ind[ 2 ] + 1 << " };\n";
                } else {
                    int n0 = ++ne; res << n0;
                    geo << "Circle(" << n0 << ") = { " << ind[ 0 ] + 1 << ", " << ind_C << ", " << ind[ 2 ] + 1 << " };\n";
                }
            } else if ( elem.type() == "Element_BoundedSurf" ) {
                int n = ++ne; res << n;
                geo << "Line Loop(" << n << ") = { ";
                for( int i = 0, c = 0; i < boundaries.size(); ++i ) {
                    Model *m = boundaries[ i ][ "e" ].model();
                    int o = boundaries[ i ][ "o" ];
                    for( int j = 0; j < elem_corr[ m ].size(); ++j, ++c )
                        geo << ( c ? ", " : "" ) << elem_corr[ m ][ j ] * o;
                }
                geo << " };\n";

                if ( boundaries.size() <= 4 )
                    geo << "Ruled Surface(" << n << ") = { " << n << " };\n";
                else
                    geo << "Plane Surface(" << n << ") = { " << n << " };\n";
            } else if ( elem.type() == "Element_BoundedVolume" ) {
                int n = ++ne; res << n;
                geo << "Surface Loop(" << n << ") = { ";
                for( int i = 0, c = 0; i < boundaries.size(); ++i ) {
                    Model *m = boundaries[ i ][ "e" ].model();
                    int o = boundaries[ i ][ "o" ];
                    for( int j = 0; j < elem_corr[ m ].size(); ++j, ++c )
                        geo << ( c ? ", " : "" ) << elem_corr[ m ][ j ] * o;
                }
                geo << " };\n";

                geo << "Volume(" << n << ") = { " << n << " };\n";
            }
        }
    }
}


