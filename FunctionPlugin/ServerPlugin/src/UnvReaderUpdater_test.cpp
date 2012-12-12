#include <Soca/Model/TypedArray.h>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>
#include "UnvReaderUpdater.h"

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
    for(int i=0; i<group_interface_i.local_nodes[0].size(); i++){
        MP pos = MP::new_lst( "Vec_3" );
        for(int d=0; d<3; d++){
            if(d==3){
                pos << 0;
            }else{
                pos << group_interface_i.local_nodes[d][i];
            }
        }
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        om[ "points" ] << pnt;
        
    }
    qDebug() << om[ "points" ] ;
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
    qDebug() << om[ "_elements" ] ;
};


//création de la liste des point a partire du maillage GeometryUser de scult
void new_list_points_mesh_2D(MP om, GroupElementsUser &group_interface_i){
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


bool ScillsResultUpdater::run( MP mp ) {
    // add_message( mp, ET_Info, "Test info msg" );
      int nb_parts_ = mp[ "nb_parts" ];
      qDebug() << nb_parts_; 
      double id_model = mp[ "id_model" ];
      if ( id_model == -1 ) {
          add_message( mp, ET_Error, "Model is not available" );
          //return false;
      }
    
      double id_calcul = mp[ "id_calcul" ];
      if ( id_calcul <= -2 ) {
          add_message( mp, ET_Error, "Data are not available" );
      }else if( id_calcul == -1 and nb_parts_ == 0){
          add_message( mp, ET_Info, "You choose to visualize the base mesh" );
//           using namespace Metil;
//           using namespace LMT;
          
          
          // version 1------------------------------------------------------------------
          Sc2String str_id_model;
          str_id_model << id_model;
          Sc2String str_id_calcul;
          str_id_calcul << id_calcul;
          
          GeometryUser        geometry_user;                                    /// structure de stockage des informations du fichier HDF5
          geometry_user.initialisation(str_id_model, str_id_calcul);
          geometry_user.read_hdf5(false,true,"test");                           /// true si on lit les info micro, true si on lit toutes les infos
           
          MP opc = mp[ "_children[ 0 ]" ];            // output Part collection
          MP oic = mp[ "_children[ 1 ]" ];            // output Interface collection
          MP oec = mp[ "_children[ 2 ]" ];            // output Edge collection
          //qDebug() << oec[ "_edge_profile" ]; 
          
          int nb_parts = 0;
          int nb_interfaces = 0;
          int nb_edges = 0;
          int dimention;
          if(geometry_user.group_elements[0].pattern_id == 0 or geometry_user.group_elements[0].pattern_id == 1){
              dimention = 2;
          }else{
              dimention = 3;
          }
    
          for (int i_group=0; i_group<geometry_user.group_elements.size(); i_group++) {
              MP part_profile = oic[ "_part_profile" ];
              MP part = MP::new_obj( "ScillsPartItem" );
              new_scills_obg(part, part_profile, geometry_user.group_elements[i_group].id, "Part");
              
              //création du sous maillage de part ------
              part[ "_mesh" ] = MP::new_obj( "Mesh" );
              MP om = part[ "_mesh" ];
              new_mesh(om);
              part[ "visualization" ] = om[ "visualization" ];
              part[ "id" ] = geometry_user.group_elements[i_group].id;
              
              if(dimention == 2){
                  //liste des points du maillage------------
                  new_list_points_mesh_2D(om, geometry_user.group_elements[i_group]);

                  //liste des éléments du maillage----------
                  new_list_elements_mesh_2D(om, geometry_user.group_elements[i_group]);
                  
              }else if(dimention == 3){
                  new_mesh_part_3D(om, geometry_user, i_group);
              }
              nb_parts += 1;
              opc[ "_children" ] << part;
          }
    
          for (int i_group=0; i_group<geometry_user.group_interfaces.size(); i_group++) {
              if(geometry_user.group_interfaces[i_group].type == 2){
                  //création de l'interface-------------------------
                  MP interface_profile = oic[ "_interface_profile" ];
                  MP interface = MP::new_obj( "ScillsInterfaceItem" );
                  new_scills_obg(interface, interface_profile, geometry_user.group_interfaces[i_group].id, "Interface");
                  
                  //création du sous maillage de interface ------
                  interface[ "_mesh" ] = MP::new_obj( "Mesh" );
                  MP om = interface[ "_mesh" ];
                  new_mesh(om);
                  interface[ "visualization" ] = om[ "visualization" ];
                  interface[ "id" ] = geometry_user.group_interfaces[i_group].id;
            
                  if(dimention == 2){
                      //liste des points du maillage------------
                      new_list_points_mesh_2D(om, geometry_user.group_interfaces[i_group]);

                      //liste des éléments du maillage----------
                      new_list_elements_mesh_2D(om, geometry_user.group_interfaces[i_group]);
                  
                  }else if(dimention == 3){  
                      //liste des points du maillage------------
                      new_list_points_mesh_3D(om, geometry_user.group_interfaces[i_group]);

                      //liste des éléments du maillage----------
                      new_list_elements_mesh_3D(om, geometry_user.group_interfaces[i_group]);
                  }
                  
                  //ajout de l'interface à l'assemblage------------
                  nb_interfaces += 1;
                  oic[ "_children" ] << interface; 
              }else if(geometry_user.group_interfaces[i_group].type == 0){
                  //création du edge-------------------------
                  MP edge_profile = oec[ "_edge_profile" ];
                  MP edge = MP::new_obj( "ScillsEdgeItem" );
                  new_scills_obg(edge, edge_profile, geometry_user.group_interfaces[i_group].id, "Edge");
                  
                  //création du sous maillage de edge ------
                  edge[ "_mesh" ] = MP::new_obj( "Mesh" );
                  MP om = edge[ "_mesh" ];
                  new_mesh(om);
                  edge[ "visualization" ] = om[ "visualization" ];
                  edge[ "id" ] = geometry_user.group_interfaces[i_group].id;
            
                  if(dimention == 2){
                      //liste des points du maillage------------
                      new_list_points_mesh_2D(om, geometry_user.group_interfaces[i_group]);

                      //liste des éléments du maillage----------
                      new_list_elements_mesh_2D(om, geometry_user.group_interfaces[i_group]);
                  
                  }else if(dimention == 3){  
                      //liste des points du maillage------------
                      new_list_points_mesh_3D(om, geometry_user.group_interfaces[i_group]);

                      //liste des éléments du maillage----------
                      new_list_elements_mesh_3D(om, geometry_user.group_interfaces[i_group]);
                  }

                  //ajout du edge à l'assemblage------------
                  nb_edges += 1;
                  oec[ "_children" ] << edge; 
              }
          }
          
          mp[ "nb_parts" ] = nb_parts;
          mp[ "nb_interfaces" ] = nb_interfaces;
          mp[ "nb_edges" ] = nb_edges;
          
          mp.flush();
      }else{
          add_message( mp, ET_Info, "You choose to visualize a result" );
      }
      add_message( mp, ET_Info, "ScillsResult just finish" );
      
}


