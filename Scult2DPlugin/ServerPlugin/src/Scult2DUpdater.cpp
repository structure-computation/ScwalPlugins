#include "Scult2DUpdater.h"
#include "ScwalScillsFunction.h"

bool Scult2DUpdater::run( MP mp ) {
    qDebug() << mp.type();
    
    // does the input file exists ?
    MP  file_unv = mp[ "_children[ 0 ]" ];
    qDebug() << file_unv;
    QString file_unv_name = file_unv[ "_name" ];
    if (file_unv.ok()){
        // see if the hdf5 file of the assembly as allready been load
        GeometryUser geometry_user;
        MP assembly = mp[ "_output[ 0 ]" ]; 
        QString path_hdf = assembly[ "_path" ];
        int _path_loaded = assembly[ "_path_loaded" ];
        
        qDebug() << path_hdf;
        QByteArray byteArray_hdf = path_hdf.toUtf8();
        const char* c_path_hdf = byteArray_hdf.constData();
        Sc2String file_output_hdf5;
        file_output_hdf5 << c_path_hdf;

        // if not load, build the assembly from the unv mesh
        if(!_path_loaded){
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
            
            //lecture du fichier unv et insertion dans le maillage ---------------------- 
            MeshUser mesh_user( file, "0" );
            mesh_user.create_mesh_scwal( file, ".unv");
            qDebug() << "fin de mesh_user";
            
            //initialisation de geometryUser et traitement du maillage ------------------
            geometry_user.initialisation( mesh_user, file );
            geometry_user.write_hdf5( file_output_hdf5 );
            
//             MP path_obj_hdf = assembly[ "_path" ];
//             int int_project_id = mp[ "_model_id" ];
//             QString project_id ;
//             project_id.setNum(int_project_id);
//             QString name_project_folder = "/home/projet_" + project_id;
//             qDebug() << name_project_folder;
//             MP project_folder = sc->load( name_project_folder );
//             QString name_output = mp[ "hdf_output_name" ];
//             project_folder << MP::new_file( name_output, path_obj_hdf );
            
            
            assembly[ "_path_loaded" ] = true;    
            
        // if load, build the assembly from the hdf file
        }else{
            qDebug() << "lecture du fichier hdf en mémoire : " << path_hdf;
            geometry_user.initialisation(file_output_hdf5);
            geometry_user.read_hdf5(false,true,"test");                           /// true si on lit les info micro, true si on lit toutes les infos
        }
        qDebug() << "fin de geometry_user";
        
        MP opc = assembly[ "_children[ 0 ]" ];            // output Part collection
        MP oic = assembly[ "_children[ 1 ]" ];            // output Interface collection
        MP oec = assembly[ "_children[ 2 ]" ];            // output Edge collection
        
        int compute_parts = assembly[ "compute_parts" ]; 
        int compute_interfaces = assembly[ "compute_interfaces" ]; 
        int compute_edges = assembly[ "compute_edges" ]; 
        
        for (int i_group=0; i_group < opc[ "_children" ].size(); i_group++) {
            MP child = opc[ "_children" ][i_group];
            child[ "_mesh.points" ].clear();
            child[ "_mesh._elements" ].clear();
            child[ "_mesh" ].clear();
        }
        opc[ "_children" ].clear() ; 
        for (int i_group=0; i_group < oic[ "_children" ].size(); i_group++) {
            MP child = oic[ "_children" ][i_group];
            child[ "_mesh.points" ].clear();
            child[ "_mesh._elements" ].clear();
            child[ "_mesh" ].clear();
        }
        oic[ "_children" ].clear() ; 
        for (int i_group=0; i_group < oec[ "_children" ].size(); i_group++) {
            MP child = oec[ "_children" ][i_group];
            child[ "_mesh.points" ].clear();
            child[ "_mesh._elements" ].clear();
            child[ "_mesh" ].clear();
        }
        oec[ "_children" ].clear() ; 
        
        //qDebug() << oec[ "_edge_profile" ]; 
        
        int nb_parts = 0;
        int nb_interfaces = 0;
        int nb_edges = 0;
        int dimention = DIM;
        
        qDebug() << "traitement des elements"; 
        qDebug() << geometry_user.group_elements.size(); 
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
            part[ "material_id" ] = -1;
            part[ "group_id" ] = -1;
            
            if(compute_parts){
                if(dimention == 2){
                    //liste des points du maillage------------
                    new_list_points_mesh_2D(om, geometry_user.group_elements[i_group]);

                    //liste des éléments du maillage----------
                    new_list_elements_mesh_2D(om, geometry_user.group_elements[i_group]);
                    
                }else if(dimention == 3){
                    new_mesh_part_3D(om, geometry_user, i_group);
                }
            }
            nb_parts += 1;
            opc[ "_children" ] << part;
        }
        
        qDebug() << "traitement des interfaces"; 
        qDebug() << geometry_user.group_interfaces.size(); 
        for (int i_group=0; i_group<geometry_user.group_interfaces.size(); i_group++) {
            //qDebug() << "num = " << i_group << " type = " << geometry_user.group_interfaces[i_group].type; 
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
                interface[ "link_id" ] = -1;
                
                interface[ "group_elements_id" ] = MP::new_lst( "Vec" );
                interface[ "group_elements_id" ] << geometry_user.group_interfaces[i_group].group_elements_id[0];
                interface[ "group_elements_id" ] << geometry_user.group_interfaces[i_group].group_elements_id[1];
                
                if(compute_interfaces){
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
                qDebug() << "création maillage " ; 
                edge[ "_mesh" ] = MP::new_obj( "Mesh" );
                MP om = edge[ "_mesh" ];
                new_mesh(om);
                edge[ "visualization" ] = om[ "visualization" ];
                edge[ "id" ] = geometry_user.group_interfaces[i_group].id;
                
                if(compute_edges){
                    if(dimention == 2){
                        //liste des points du maillage------------
                        qDebug() << "création points " ; 
                        new_list_points_mesh_2D(om, geometry_user.group_interfaces[i_group]);

                        //liste des éléments du maillage----------
                        qDebug() << "création éléments " ; 
                        new_list_elements_mesh_2D(om, geometry_user.group_interfaces[i_group]);
                    
                    }else if(dimention == 3){  
                        //liste des points du maillage------------
                        new_list_points_mesh_3D(om, geometry_user.group_interfaces[i_group]);

                        //liste des éléments du maillage----------
                        new_list_elements_mesh_3D(om, geometry_user.group_interfaces[i_group]);
                    }
                }

                //ajout du edge à l'assemblage------------
                nb_edges += 1;
                oec[ "_children" ] << edge; 
            }
        }
        assembly[ "nb_parts" ] = nb_parts;
        assembly[ "nb_interfaces" ] = nb_interfaces;
        assembly[ "nb_edges" ] = nb_edges;
    } 
    add_message( mp, ET_Info, "Scult2DUpdater just finish" );
    qDebug() << "Scult2DUpdater just finish";
}


