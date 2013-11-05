#include "Scult3DUpdater.h"
#include "ScwalScillsFunction.h"


void visualisation_parts(MP mp){
    MP assembly = mp[ "_output[ 0 ]" ]; 
    QString path_hdf = assembly[ "_path" ];
    int _path_loaded = assembly[ "_path_loaded" ];
    
    qDebug() << path_hdf;
    QByteArray byteArray_hdf = path_hdf.toUtf8();
    const char* c_path_hdf = byteArray_hdf.constData();
    Sc2String file_output_hdf5;
    file_output_hdf5 << c_path_hdf;
  
    GeometryUser geometry_user;
    qDebug() << "lecture du fichier hdf en mémoire : " << path_hdf;
    geometry_user.initialisation(file_output_hdf5);
    geometry_user.read_hdf5(false,true,"test");                           /// true si on lit les info micro, true si on lit toutes les infos
    
    MP opc = assembly[ "_children[ 0 ]" ];            // output Part collection
    MP oic = assembly[ "_children[ 1 ]" ];            // output Interface collection
    MP oec = assembly[ "_children[ 2 ]" ];            // output Edge collection
    
    // traitement des éléments ------------------------------------------------------------------------------------------------
    qDebug() << "traitement des elements"; 
    for (int i_group=0; i_group < opc[ "_children" ].size(); i_group++) {
        MP child = opc[ "_children" ][i_group];
        child[ "_mesh.points" ].clear();
        child[ "_mesh._elements" ].clear();
        child[ "_mesh" ].clear();
    }
    
    MP ovp = mp[ "_output[ 1 ]" ];            // output visualisation Part 
    for (int i_group_f=0; i_group_f < ovp[ "_children" ].size(); i_group_f++) {
        MP opfc = ovp[ "_children" ][i_group_f];
        for (int i_group=0; i_group < opfc[ "_children" ].size(); i_group++) {
            MP part = opfc[ "_children" ][i_group];
            qDebug() << "id_part_mp : " << part["id"];
            int id_group = part[ "id" ]; 
            int index_group = geometry_user.find_index_group_elements(id_group);
            qDebug() << "index_group : " << index_group;
            
            part[ "_mesh" ] = MP::new_obj( "Mesh" );
            MP om = part[ "_mesh" ];
            new_mesh(om);
            new_mesh_part_3D(om, geometry_user, index_group);
        }
    }
    
    // traitement des interfaces ------------------------------------------------------------------------------------------------
    qDebug() << "traitement des interfaces"; 
    for (int i_group=0; i_group < oic[ "_children" ].size(); i_group++) {
        MP child = oic[ "_children" ][i_group];
        child[ "_mesh.points" ].clear();
        child[ "_mesh._elements" ].clear();
        child[ "_mesh" ].clear();
    }
    
    MP ovi = mp[ "_output[ 2 ]" ];            // output visualisation Interface 
    for (int i_group_f=0; i_group_f < ovi[ "_children" ].size(); i_group_f++) {
        MP oifc = ovi[ "_children" ][i_group_f];
        for (int i_group=0; i_group < oifc[ "_children" ].size(); i_group++) {
            MP inter = oifc[ "_children" ][i_group];
            qDebug() << "id_inter_mp : " << inter["id"];
            int id_group = inter[ "id" ]; 
            int index_group = geometry_user.find_index_group_interfaces(id_group);
            qDebug() << "index_group : " << index_group;
            
            inter[ "_mesh" ] = MP::new_obj( "Mesh" );
            MP om = inter[ "_mesh" ];
            new_mesh(om);
            new_list_points_mesh_3D(om, geometry_user.group_interfaces[index_group]);
            new_list_elements_mesh_3D(om, geometry_user.group_interfaces[index_group]);
        }
    }
    mp.flush();
}



bool Scult3DUpdater::run( MP mp ) {
    //qDebug() << mp.type();
    
    int run_type = mp["run_type.num"];
    
    // does the input file exists ?
    MP  input_mesh = mp[ "_children[ 0 ]" ];
    QString input_mesh_name = input_mesh[ "_name" ];
    
    bool test_unv = (input_mesh.type() == "FileItem" and input_mesh_name.endsWith(".unv"));
    bool test_msh = (input_mesh.type() == "MeshItem");
    
    
    if ((input_mesh.ok() or test_msh) and run_type==0){
        // see if the hdf5 file of the assembly as allready been load
        GeometryUser geometry_user;
        MP assembly = mp[ "_output[ 0 ]" ]; 
        QString path_hdf = assembly[ "_path" ];
        int _path_loaded = assembly[ "_path_loaded" ];
        
        //qDebug() << path_hdf;
        QByteArray byteArray_hdf = path_hdf.toUtf8();
        const char* c_path_hdf = byteArray_hdf.constData();
        Sc2String file_output_hdf5;
        file_output_hdf5 << c_path_hdf;

        // if not load, build the assembly from the unv mesh
        // if not load, build the assembly from the unv mesh
        if(test_unv){
            quint64 ptr = input_mesh[ "_ptr" ];
            QString name = input_mesh[ "_name" ];
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
            Sc2String name_geometry_hdf5 = "/Level_0/Geometry";
            geometry_user.write_xdmf(file_output_hdf5, file_output_hdf5, name_geometry_hdf5,0);
            
            assembly[ "_path_loaded" ] = true;  
            
        // if load, build the assembly from the hdf file
        }else if( test_msh){
            // création du maillage à partir des du maillage de la plateforme
            qDebug() << "création du maillage à partir de gmsh";
            
            MeshUser mesh_user("test", "0" );
          
            MP mesh = input_mesh["_mesh" ]; 
            for( int i = 0, n = mesh[ "points" ].size(); i < n; ++i ) {
                mesh_user.mesh_num_nodes.push_back(i);
                MP pos = mesh[ "points" ][ i ][ "pos" ];
                BasicVec<TYPE,DIM> vec;
                for (int di=0;di<DIM;di++) {
                    vec[di] = pos[ di ];
                    mesh_user.mesh_pos_nodes[di].push_back(vec[di]);
                    qDebug() << vec[0] << " " << vec[1];
                }
            }
            
            qDebug() << mesh_user.mesh_pos_nodes.size();
            qDebug() << mesh_user.mesh_pos_nodes[0].size();
            qDebug() << mesh_user.mesh_num_nodes.size();
            

            for( int nel = 0, mel = mesh[ "_elements" ].size(); nel < mel; ++nel ) {
                MP el = mesh[ "_elements" ][ nel ]; 
                if ( el.type() == "Element_TetrahedraList" ) {
                    if ( TypedArray<int> *indices = dynamic_cast<TypedArray<int> *>( el[ "indices" ].model() ) ) {
                        for( int nt = 0, ct = 0; nt < indices->size( 1 ); ++nt ) {
                            unsigned o[ 4 ];
                            for( int j = 0; j < 4; ++j ){
                                o[ j ] = indices->operator[]( ct++ );
                            }
                            //qDebug() << o[0] << " " << o[1] << " " << o[2];
                            int pattern_base_id = 2;
                            int nb_sides_pattern = mesh_user.patterns.find_type(pattern_base_id).nb_sides;
                            BasicVec< int > mesh_connectivity;
                            int n_nodes = 4;
                            mesh_connectivity.resize(n_nodes);

                            for(int i=0;i<n_nodes;i++){
                                mesh_connectivity[i] = o[ i ];
                            }
                            EntityElementUser current_element(pattern_base_id, nel, 0, mesh_connectivity, nb_sides_pattern); //numero de groupe a assigner plus tard si necessaire
                            mesh_user.list_elements.push_back(current_element);
                        }
                    }
                }
            }
            mesh_user.nb_elements = mesh_user.list_elements.size();
            mesh_user.map_num_group_name_group[0] = "part_0";
            for( int i = 0; i < mesh_user.list_elements.size(); ++i ) {
                mesh_user.list_elements[i].num_piece_in_mesh = 0;
            }
            
            qDebug() << mesh_user.nb_elements;
            
            //assert(0);
            
            std::cout << "** create interfaces *******************************************************************************************" << std::endl;
            mesh_user.test_create_list_interfaces();
            PRINT(mesh_user.nb_interfaces);
            PRINT(mesh_user.list_interfaces.size());
            std::cout << "** create interfaces ok" << std::endl;
            
            std::cout << "** create elements *********************************************************************************************" << std::endl;
            for( int i_elem = 0; i_elem < mesh_user.nb_elements; i_elem++ ){
                std::cout << "\rElements a traiter : " << mesh_user.nb_elements-i_elem << "          ";
                mesh_user.create_list_elements( i_elem );
            }
            std::cout << std::endl << "** create elements ok" << std::endl;
          
          
            //initialisation de geometryUser et traitement du maillage ------------------
            geometry_user.initialisation( mesh_user, "test" );
            geometry_user.write_hdf5( file_output_hdf5 );
            
            assembly[ "_path_loaded" ] = true;    
          
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
            part[ "_name" ] = geometry_user.group_elements[i_group].name_in_mesh.c_str();
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
                interface[ "group_id" ] = -1;
                
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
    } else if (input_mesh.ok() and  run_type==1){
        visualisation_parts(mp);
    }
    add_message( mp, ET_Info, "Scult3DUpdater just finish" );
    qDebug() << "Scult3DUpdater just finish";
}


