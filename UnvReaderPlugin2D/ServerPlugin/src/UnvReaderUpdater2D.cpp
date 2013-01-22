#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>
#include "UnvReaderUpdater2D.h"

#include <string.h>

#include "MeshUser.h"


typedef LMT::Vec<double,3> Pvec;

struct AutoRm {
    AutoRm( QString f ) : f( f ) {}
    ~AutoRm() { QFile::remove( f ); }
    QString f;
};


void new_scills_obg(MP obj, MP obj_profile, int id, Sc2String name){
    Sc2String str_name_obj;
    str_name_obj << name << "_" << id;
    obj[ "_ico" ] = obj_profile["_ico" ];
    obj[ "_name" ] = str_name_obj.c_str();
    obj[ "_viewable" ] = true;
    obj[ "_children" ] = MP::new_lst();
    obj[ "_output" ] = MP::new_lst();
    obj[ "_name_class" ] = "";
    obj[ "_allow_vmod" ] = true;  
};

void new_mesh(MP om){
    om[ "visualization" ] = MP::new_obj();
    om[ "visualization.display_style" ] = MP::new_obj( "Choice" );
    om[ "visualization.display_style.num" ] = 1;
    om[ "visualization.display_style.lst" ] = MP::new_lst();
    om[ "visualization.display_style.lst" ] << "Points";
    om[ "visualization.display_style.lst" ] << "Wireframe";
    om[ "visualization.display_style.lst" ] << "Surface";
    om[ "visualization.display_style.lst" ] << "Surface with Edges";
    om[ "visualization.point_edition" ] = false;
    
    om[ "points" ] = MP::new_lst( "Lst_Point" );
    om[ "_elements" ] = MP::new_lst();
    om[ "_selected_points" ] = MP::new_lst();
    om[ "_pelected_points" ] = MP::new_lst();
    om[ "_selected_elements" ] = MP::new_lst();
    om[ "_pelected_elements" ] = MP::new_lst();
};


//création de la liste des point a partire du maillage MeshUser de scult
void new_list_points_mesh_2D(MP om, MeshUser &mesh_user){
//     qDebug() << mesh_user.mesh_pos_nodes[0].size();
//     qDebug() << mesh_user.mesh_pos_nodes.size();
//     
//     qDebug() << mesh_user.mesh_pos_nodes[0][0];
//     qDebug() << mesh_user.mesh_pos_nodes[1][0];
    
    for(int i=0; i<mesh_user.mesh_pos_nodes[0].size(); i++){
        MP pos = MP::new_lst( "Vec_3" );
        for(int d=0; d<3; d++){
            if(d==2){
                pos << 0;
            }else{
                pos << mesh_user.mesh_pos_nodes[d][i];
            }
        }
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        om[ "points" ] << pnt;
        
    }
    //qDebug() << om[ "points" ] ;
};

//création de la liste des éléments a partire du maillage MeshUser de scult
void new_list_elements_mesh_2D(MP om, MeshUser &mesh_user){
    TypedArray<int> *connectivity = new TypedArray<int>;
    for(int i=0; i<mesh_user.list_elements.size(); i++){
        for(int d=0; d<mesh_user.list_elements[i].mesh_connectivity.size(); d++){
            connectivity->_data << mesh_user.list_elements[i].mesh_connectivity[d];
        }
    }
    connectivity->_size.resize( 2 );
    connectivity->_size[ 0 ] = 3;
    connectivity->_size[ 1 ] = connectivity->_data.size() / 3;
    MP triangles = MP::new_obj( "Element_TriangleList" );
    triangles[ "indices" ] = connectivity;
    om[ "_elements" ] << triangles;
};



bool UnvReaderUpdater2D::run( MP mp ) {
    MP  file_unv = mp[ "_children[ 0 ]" ];
//     qDebug() << mp;
    QString file_unv_name = file_unv[ "_name" ];
    qDebug() << file_unv_name;
    if (file_unv.ok()){
        quint64 ptr = file_unv[ "_ptr" ];
        QString name = file_unv[ "_name" ];
        MP data = sc->load_ptr( ptr );
        qDebug() << "on lit le path";
        QString path_unv;
        if( data.ok() and data.type() == "Path") {
            QString path_temp = data;
            path_unv = path_temp;
            qDebug() << path_unv; 
        }
    
        //lecture du maillage utilisateur -------------------------------------------
        QByteArray byteArray = path_unv.toUtf8();
        const char* c_path_unv = byteArray.constData();
        Sc2String file;
        file << c_path_unv;
        
        qDebug() << "on lit le maillage unv";
        MeshUser mesh_user( file, "0" );
//         qDebug() << "on lit le maillage unv";
        mesh_user.create_mesh_unv( file, ".unv");
        
//         qDebug() << "on lit le path";
        
        //MP om = mp[ "_mesh" ];
        MP om = mp[  "_output[ 0 ].mesh" ];
        //MP mm = mp[  "_mesh" ];
        om[ "points" ].clear();
        om[ "_elements" ].clear();
        
        //mm = om;
        //liste des points du maillage------------
        new_list_points_mesh_2D(om, mesh_user);
        
        //liste des éléments du maillage----------
        new_list_elements_mesh_2D(om, mesh_user);
    }
    add_message( mp, ET_Info, "UnvReaderUpdater2D just finish" );
    qDebug() << "UnvReaderUpdater2D just finish";
}


