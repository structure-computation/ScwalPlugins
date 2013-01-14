#include "CorreliUpdater_2D.h"
#include "CorreliUpdater_3D.h"
#include "CorreliUpdater.h"

int CorreliUpdater::_ok( const MP &mp ) const {
    int nb_images = 0, dim = 2;
    MP ch = mp[ "_children" ];
    for( int i = 0; i < ch.size(); ++i ) {
        MP c = ch[ i ];
        if ( c.type() == "ImgSetItem" ) {
            for( int j = 0; j < c[ "_children" ].size(); ++j )
                nb_images += c[ "_children" ][ j ].type() == "ImgItem" or
                             c[ "_children" ][ j ].type() == "RawVolume";
        } else if ( c.type() == "DiscretizationItem" ) {
            MP m = c[ "_children[ 0 ]._mesh" ];
            if ( not m.ok() or not m[ "points" ].size() )
                return false;
// <<<<<<< HEAD
//         }
//     }
//     return nb_images >= 2;
// }
// 
// struct GetEps {
//     template<class TE,class TD>
//     void operator()( const TE &e, int i, TD *data, int d ) const {
//             data->operator[]( i ) = e.epsilon[ 0 ][ d ];
//     }
// };
// 
// 
// void _save_img( MP mp, const QImage &res, int j ) {
//     res.save( "pouet.png" );
// 
//     // -> png
//     QByteArray ba;
//     QBuffer buffer( &ba );
//     buffer.open( QIODevice::WriteOnly );
//     res.save( &buffer, "PNG" );
// 
//     // -> base64
//     QByteArray b6;
//     b6.append( "data:image/png;base64," );
//     b6.append( ba.toBase64() );
// 
//     MP field = MP::new_obj( "ImageField" );
//     field[ "src" ] = QString::fromAscii( b6.data(), b6.size() );
// 
//     // Interpolated field fill-in
//     MP disp = MP::new_obj();
//     disp[ "field" ] = field;
//     disp[ "pos" ] = MP::new_lst();
//     MP pos_v = MP::new_obj();
//     pos_v[ "axe_value" ] = j;
//     pos_v[ "axe_name" ] = "time";
//     disp[ "pos" ] << pos_v;
// 
//     mp[ "data._data" ] << disp;
// }
// 
// static void check_image_field( MP mp, QString n, QString N ) {
//     for( int i = 0; ; ++i ) {
//         if ( i == mp[ "visualization.color_by.lst" ].size() ) {
//             mp[ "visualization.color_by.lst" ] << mp[ n ];
//             break;
//         }
//         MP l = mp[ "visualization.color_by.lst" ][ i ];
//         if ( QString( l[ "name" ] ) == N )
//             break;
//     }
//     mp[ n + ".data._data" ].clear();
// }
// 
// template<class TM>
// MP soda_mesh_from_lmtpp_mesh( const TM &m ) {
//     MP om = MP::new_obj( "Mesh" );
//     om[ "points" ] = MP::new_lst( "Lst_Point" );
//     om[ "_elements" ] = MP::new_lst();
//     om[ "_selected_points" ] = MP::new_lst();
//     om[ "_pelected_points" ] = MP::new_lst();
//     om[ "_selected_elements" ] = MP::new_lst();
//     om[ "_pelected_elements" ] = MP::new_lst();
// 
//     // nodes
//     for( int i = 0; i < m.node_list.size(); ++i ) {
//         MP pos = MP::new_lst( "Vec_3" );
//         for( int d = 0; d < 3; ++d )
//             pos << m.node_list[ i ].pos[ d ];
// 
//         MP pnt = MP::new_obj( "Point" );
//         pnt[ "pos" ] = pos;
// 
//         om[ "points" ] << pnt;
//     }
// 
//     // elements
//     TypedArray<int> *connectivity = new TypedArray<int>;
//     for( int n = 0; n < m.elem_list.size(); ++n )
//         for( int i = 0; i < m.elem_list[ n ]->nb_nodes_virtual(); ++i )
//             connectivity->_data << m.elem_list[ n ]->node_virtual( i )->number;
// 
//     connectivity->_size.resize( 2 );
//     connectivity->_size[ 0 ] = 3;
//     connectivity->_size[ 1 ] = m.elem_list.size();
// 
//     MP triangles = MP::new_obj( "Element_TriangleList" );
//     triangles[ "indices" ] = connectivity;
//     om[ "_elements" ] << triangles;
// 
//     return om;
// }
// 
// 
// bool CorreliUpdater::run( MP mp ) {
//     if ( not _ok( mp ) )
//         return false;
// 
//     DC2 dic;
//     TM2 dic_mesh;
//     LMT::Vec<I2> images;
//     TF2 form( dic_mesh );
//     TB2 bord( dic_mesh );
// 
//     // load data
//     MP mesh;
//     MP ch = mp[ "_children" ];
//     Vec<Vec<Pvec,2> > contrained_lines;
//     for( int i = 0; i < ch.size(); ++i ) {
//         MP c = ch[ i ];
//         if ( c.type() == "ImgSetItem" ) {
//             for( int j = 0; j < c[ "_children" ].size(); ++j ) {
//                 MP im = c[ "_children" ][ j ];
//                 if ( im.type() == "ImgItem" ) {
//                     I2 *img = images.new_elem();
//                     QString name = im[ "img.src" ];
// 
//                     if ( im[ "img._path" ].ok() )
//                         name = QString( im[ "img._path" ] );		
//                     else
//                         //name = "../CorreliOnline/html/" + name;
// 			name = "/home/jbellec/code_dev_soja/CorreliOnline/data.db/" + name;
// 
//                     try {
//                         img->load( name.toAscii().data() );
//                         img->reverse_y();
//                     } catch ( std::string msg ) {
//                         add_message( mp, ET_Error, "Img " + name + " does not exist" );
//                         return false;
//                     }
//                 }
//             }
//         }
//         if ( c.type() == "DiscretizationItem" ) {
//             mesh.reassign( c[ "_children[ 0 ]._mesh" ] );
//             for( int i = 0, n = mesh[ "points" ].size(); i < n; ++i ) {
//                 MP pos = mesh[ "points" ][ i ][ "pos" ];
//                 dic_mesh.add_node( Pvec( pos[ 0 ], pos[ 1 ], pos[ 2 ] ) );
//             }
// =======
// >>>>>>> 08d8a00becceb41fc489c2fe6b856238303c0f2f

            MP mesh = c[ "_children[ 0 ]._mesh" ];
            for( int nel = 0, mel = mesh[ "_elements" ].size(); nel < mel; ++nel ) {
                MP el = mesh[ "_elements" ][ nel ];
                if ( el.type() == "Element_TetrahedraList" and el[ "indices" ].size() )
                    dim = 3;
            }
        }
    }
    return ( nb_images >= 2 ) * dim;
}

bool CorreliUpdater::run( MP mp ) {
    if ( int d = _ok( mp ) ) {
        qDebug() << d;
        switch ( d ) {
        case 2: return correli_updater_2D( this, mp );
        case 3: return correli_updater_3D( this, mp );
        }
    }
    return false;
}
