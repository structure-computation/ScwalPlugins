#ifndef SCWALSCILLSFUNCTION_H
#define SCWALSCILLSFUNCTION_H


#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>

#include <string.h>
#include "MeshUser.h"
#include "GeometryUser.h"
#include "DataUser.h"
#include "FieldStructureUser.h"

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




//création de la liste des point a partire du maillage GeometryUser de scult
void new_list_points_mesh_3D(MP om, GroupInterfacesUser &group_interface_i){
    for(int i=0; i<group_interface_i.local_nodes[0].size(); i++){
        MP pos = MP::new_lst( "Vec_3" );
        for(int d=0; d<group_interface_i.local_nodes.size(); d++){
            pos << group_interface_i.local_nodes[d][i];
        }
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        om[ "points" ] << pnt;
    }
};

//création de la liste des éléments a partire du maillage GeometryUser de scult
void new_list_elements_mesh_3D(MP om, GroupInterfacesUser &group_interface_i, int offset = 0){
    TypedArray<int> *connectivity = new TypedArray<int>;
    for(int i=0; i<group_interface_i.local_connectivities[0].size(); i++){
        for(int d=0; d<group_interface_i.local_connectivities.size(); d++){
            connectivity->_data << group_interface_i.local_connectivities[d][i] + offset;
        }
    }
    connectivity->_size.resize( 2 );
    connectivity->_size[ 0 ] = 3;
    connectivity->_size[ 1 ] = connectivity->_data.size() / 3;
    MP triangles = MP::new_obj( "Element_TriangleList" );
    triangles[ "indices" ] = connectivity;
    om[ "_elements" ] << triangles;
};

//création de la liste des point a partire du maillage GeometryUser de scult
void new_mesh_part_3D(MP om, GeometryUser &geometry_user, int i_group){
    TypedArray<int> *connectivity = new TypedArray<int>;
    for (int j_group=0; j_group<geometry_user.group_interfaces.size(); j_group++) {
        int offset = om["points"].size();
        if(geometry_user.group_interfaces[j_group].type == 0 or geometry_user.group_interfaces[j_group].type ==2){
            bool is_edge_of = false;
            for(int i_e=0; i_e<geometry_user.group_interfaces[j_group].group_elements_id.size(); i_e++){ 
                if(geometry_user.group_interfaces[j_group].group_elements_id[i_e] == geometry_user.group_elements[i_group].id){
                    is_edge_of = true;
                    break;
                }
            }
            if (is_edge_of){
                //liste des points du maillage------------
                new_list_points_mesh_3D(om, geometry_user.group_interfaces[j_group]);

                //liste des éléments du maillage----------
                //new_list_elements_mesh(om, geometry_user.group_interfaces[j_group],offset);
                for(int i=0; i<geometry_user.group_interfaces[j_group].local_connectivities[0].size(); i++){
                    for(int d=0; d<geometry_user.group_interfaces[j_group].local_connectivities.size(); d++){
                        connectivity->_data << geometry_user.group_interfaces[j_group].local_connectivities[d][i] + offset;
                    }
                }
            }                      
        }
        //qDebug() << offset; 
        
    }
    connectivity->_size.resize( 2 );
    connectivity->_size[ 0 ] = 3;
    connectivity->_size[ 1 ] = connectivity->_data.size() / 3;
    MP triangles = MP::new_obj( "Element_TriangleList" );
    triangles[ "indices" ] = connectivity;
    om[ "_elements" ] << triangles;
};


//création de la liste des point a partire du maillage GeometryUser de scult
void new_list_points_mesh_2D(MP om, GroupInterfacesUser &group_interface_i){
    //     qDebug() << "group_interface_i.local_nodes[0].size() = " << group_interface_i.local_nodes[0].size();
    //     qDebug() << "group_interface_i.local_nodes.size() = " << group_interface_i.local_nodes.size();
    for(int i=0; i<group_interface_i.local_nodes[0].size(); i++){
        MP pos = MP::new_lst( "Vec_3" );
        for(int d=0; d<3; d++){
            if(d==2){
                pos << 0;
            }else{
                pos << group_interface_i.local_nodes[d][i];
            }
        }
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        om[ "points" ] << pnt;
        
    }
    //qDebug() << om[ "points" ] ;
};

//création de la liste des éléments a partire du maillage GeometryUser de scult
void new_list_elements_mesh_2D(MP om, GroupInterfacesUser &group_interface_i, int offset = 0){
    for(int i=0; i<group_interface_i.local_connectivities[0].size(); i++){
        MP indices = MP::new_lst( "Vec" );
        for(int d=0; d<group_interface_i.local_connectivities.size(); d++){
            indices << group_interface_i.local_connectivities[d][i] + offset;
        }
        MP bars = MP::new_obj( "Element_Line" );
        bars[ "indices" ] = indices;
        om[ "_elements" ] << bars;
    }
    //qDebug() << om[ "_elements" ] ;
};


//création de la liste des point a partire du maillage GeometryUser de scult
void new_list_points_mesh_2D(MP om, GroupElementsUser &group_interface_i){
    for(int i=0; i<group_interface_i.local_nodes[0].size(); i++){
        MP pos = MP::new_lst( "Vec_3" );
        for(int d=0; d<3; d++){
            if(d==2){
                pos << 0;
            }else{
                pos << group_interface_i.local_nodes[d][i];
            }
        }
//         for(int d=0; d<group_interface_i.local_nodes.size(); d++){
//             pos << group_interface_i.local_nodes[d][i];
//         }
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        om[ "points" ] << pnt;
    }
};

//création de la liste des éléments a partire du maillage GeometryUser de scult
void new_list_elements_mesh_2D(MP om, GroupElementsUser &group_interface_i, int offset = 0){
    TypedArray<int> *connectivity = new TypedArray<int>;
    for(int i=0; i<group_interface_i.local_connectivities[0].size(); i++){
        for(int d=0; d<group_interface_i.local_connectivities.size(); d++){
            connectivity->_data << group_interface_i.local_connectivities[d][i] + offset;
        }
    }
    connectivity->_size.resize( 2 );
    connectivity->_size[ 0 ] = 3;
    connectivity->_size[ 1 ] = connectivity->_data.size() / 3;
    MP triangles = MP::new_obj( "Element_TriangleList" );
    triangles[ "indices" ] = connectivity;
    om[ "_elements" ] << triangles;
};

#endif // SCWALSCILLSFUNCTION_H