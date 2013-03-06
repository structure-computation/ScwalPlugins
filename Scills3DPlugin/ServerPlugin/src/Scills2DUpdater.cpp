#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include "Scills2DUpdater.h"
#include "ScwalScillsFunction.h"


#ifdef METIL_COMP_DIRECTIVE
    #pragma src_file multiscale_geometry_mesh.cpp
    #pragma src_file assignation_material_properties_Sst.cpp
    #pragma src_file assignation_material_properties_Interface.cpp
    #pragma src_file multiscale_operateurs.cpp

    #pragma src_file formulation_2_double_elasticity_isotropy_stat_Qstat.cpp
    #pragma src_file formulation_2_double_elasticity_orthotropy_stat_Qstat.cpp
    #pragma src_file formulation_2_double_elasticity_damageable_isotropy_stat_Qstat.cpp
    #pragma src_file formulation_2_double_plasticity_isotropy_stat_Qstat.cpp
    #pragma src_file formulation_2_double_mesomodele.cpp

    #pragma src_file iterate_stat_Qstat.cpp
    #pragma src_file affichage.cpp
#endif
#include "Process.h"
#ifndef INFO_TIME
#define INFO_TIME
#endif 

#include "../LMT/include/io/ioexception.h"
Crout crout;


// convert MP_filter_edges to data_user_edges definition
DataUser::Json_edges new_data_user_edge_from_edge_filter(DataUser &data_user, MP edge_filter, int id_boundary_condition){
    DataUser::Json_edges data_edge;
    int id_edge_filter = edge_filter[ "_id" ];
    MP lst_edge_filter = edge_filter[ "type.lst" ];
    int num_type_edge_filter = edge_filter[ "type.num" ];
    MP type_edge_filter = lst_edge_filter[num_type_edge_filter];
    
    MP name_type_edge_filter = type_edge_filter[ "_name" ];
    MP filter_type_edge_filter = type_edge_filter[ "filter" ];
    Sc2String name = convert_MP_to_Sc2String(name_type_edge_filter);
    
    // initialisation a 0
    data_edge.id_in_calcul = id_edge_filter;
    data_edge.boundary_condition_id = id_boundary_condition;
    data_edge.assigned = 1;
    data_edge.geometry = "undefined";
    data_edge.criteria = "surface";    
    data_edge.direction_x = 0;
    data_edge.direction_y = 0;
    data_edge.direction_z = 0;
    data_edge.point_1_x = 0;
    data_edge.point_1_y = 0;
    data_edge.point_1_z = 0;
    data_edge.point_2_x = 0;
    data_edge.point_2_y = 0;
    data_edge.point_2_z = 0;
    data_edge.radius = 0;
    data_edge.equation = "0";
    //data_edge.equation = convert_MP_to_Sc2String(edge_filter[ "filter" ]);
    
    
    if (name=="parameterized"){
        data_edge.criteria =    "surface";
        data_edge.geometry =    "parameterized";
        data_edge.equation =    convert_MP_to_Sc2String(filter_type_edge_filter);
    }else if (name=="in_box"){
        data_edge.criteria =    "volume";
        data_edge.geometry =    "box";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point_1[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point_1[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point_1[2]" ]);
        data_edge.point_2_x =   convert_MP_to_int(type_edge_filter[ "point_2[0]" ]);
        data_edge.point_2_y =   convert_MP_to_int(type_edge_filter[ "point_2[1]" ]);
//         data_edge.point_2_z =   convert_MP_to_int(type_edge_filter[ "point_2[2]" ]);
    }else if (name=="in_cylinder"){
        data_edge.criteria =    "volume";
        data_edge.geometry =    "cylinder";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.direction_x = convert_MP_to_int(type_edge_filter[ "direction[0]" ]);
        data_edge.direction_y = convert_MP_to_int(type_edge_filter[ "direction[1]" ]);
//         data_edge.direction_z = convert_MP_to_int(type_edge_filter[ "direction[2]" ]);
        data_edge.radius =      convert_MP_to_int(type_edge_filter[ "radius" ]);
    }else if (name=="in_sphere"){
        data_edge.criteria =    "volume";
        data_edge.geometry =    "sphere";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.radius =      convert_MP_to_int(type_edge_filter[ "radius" ]);
    }else if (name=="on_plan"){
        data_edge.criteria =    "surface";
        data_edge.geometry =    "plan";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.direction_x = convert_MP_to_int(type_edge_filter[ "direction[0]" ]);
        data_edge.direction_y = convert_MP_to_int(type_edge_filter[ "direction[1]" ]);
//         data_edge.direction_z = convert_MP_to_int(type_edge_filter[ "direction[2]" ]);
    }else if (name=="on_disc"){
        data_edge.criteria =    "surface";
        data_edge.geometry =    "disc";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.direction_x = convert_MP_to_int(type_edge_filter[ "direction[0]" ]);
        data_edge.direction_y = convert_MP_to_int(type_edge_filter[ "direction[1]" ]);
//         data_edge.direction_z = convert_MP_to_int(type_edge_filter[ "direction[2]" ]);
        data_edge.radius =      convert_MP_to_int(type_edge_filter[ "radius" ]);
    }else if (name=="on_cylinder"){
        data_edge.criteria =    "surface";
        data_edge.geometry =    "cylinder";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.direction_x = convert_MP_to_int(type_edge_filter[ "direction[0]" ]);
        data_edge.direction_y = convert_MP_to_int(type_edge_filter[ "direction[1]" ]);
//         data_edge.direction_z = convert_MP_to_int(type_edge_filter[ "direction[2]" ]);
        data_edge.radius =      convert_MP_to_int(type_edge_filter[ "radius" ]);
    }else if (name=="on_sphere"){
        data_edge.criteria =    "surface";
        data_edge.geometry =    "sphere";
        data_edge.point_1_x =   convert_MP_to_int(type_edge_filter[ "point[0]" ]);
        data_edge.point_1_y =   convert_MP_to_int(type_edge_filter[ "point[1]" ]);
//         data_edge.point_1_z =   convert_MP_to_int(type_edge_filter[ "point[2]" ]);
        data_edge.radius =      convert_MP_to_int(type_edge_filter[ "radius" ]);
    }
    return data_edge;
}

// add default data_user_edges definition
DataUser::Json_edges new_data_user_edge_default(DataUser &data_user){
    DataUser::Json_edges data_edge;
    data_edge.id_in_calcul = -1;
    data_edge.assigned = 1;
    data_edge.criteria = "all";
    //data_edge.geometry = convert_MP_to_Sc2String(edge_filter[ "type" ]);
    data_edge.geometry = "parameterized";
    
    data_edge.direction_x = 0;
    data_edge.direction_y = 0;
    data_edge.direction_z = 0;
    data_edge.point_1_x = 0;
    data_edge.point_1_y = 0;
    data_edge.point_1_z = 0;
    data_edge.point_2_x = 0;
    data_edge.point_2_y = 0;
    data_edge.point_2_z = 0;
    data_edge.radius = 0;
    data_edge.equation = "0";
    data_edge.boundary_condition_id = -1;
    PRINT(data_edge.geometry);
    return data_edge;  
}


// traitement des paramètres du calculs
void add_MP_computation_parameters_to_data_user(MP computation_parameters, DataUser &data_user, QString _dir_name){
    //traitement des paramètre LATIN
    MP  latin_parameters = computation_parameters[ "_children[ 0 ]" ];
    
    Sc2String calcul_path_name = convert_QString_to_Sc2String(_dir_name);
    Sc2String result_path_name;
    result_path_name << calcul_path_name << "/" ;
    
    data_user.options.mode            = "normal";
//     data_user.result_path             = "/home/jbellec/cas_test/test_scwal/";
//     data_user.calcul_path             = "/home/jbellec/cas_test/test_scwal";
    data_user.result_path             = result_path_name;
    data_user.calcul_path             = calcul_path_name;
    
    //qDebug() << latin_parameters;
    data_user.options.convergence_method_LATIN.max_iteration            = convert_MP_to_int(latin_parameters[ "max_iteration.val" ]);
    data_user.options.convergence_method_LATIN.convergence_rate         = convert_MP_to_reel(latin_parameters[ "convergence_rate.val" ]);
    
    PRINT(data_user.options.convergence_method_LATIN.max_iteration);
    PRINT(data_user.options.convergence_method_LATIN.convergence_rate);
    
//     assert(0);
    
    
    //traitement des paramètre TIME-----------------------------------------------------------
    MP  time_parameters = computation_parameters[ "_children[ 1 ]" ];
    
    MP lst_time_type = time_parameters[ "type.lst" ];
    int num_time_type = time_parameters[ "type.num" ];
    MP type_time = lst_time_type[num_time_type];
    Sc2String name_time_scheme = convert_MP_to_Sc2String(type_time);
    
//     qDebug() << type_time;
    PRINT(name_time_scheme);
    
    if (name_time_scheme == "static") { data_user.time_steps.time_scheme = "static";}
    else if (name_time_scheme == "quasistatic") { data_user.time_steps.time_scheme = "quasistatic";}
    
    //traitement des steps temporels---------------------
    MP  time_step_set = time_parameters[ "_children[ 0 ]" ];
    int nb_time_steps = convert_MP_to_int(time_parameters[ "nb_steps" ]);
    data_user.time_steps.collection_vec.resize(nb_time_steps);
//     qDebug() << time_step_set;
    for(int i_step = 0;i_step < nb_time_steps; ++i_step){
        MP  time_step_i = time_step_set[ "_children" ][ i_step ];
        qDebug() << time_step_i;
        data_user.time_steps.collection_vec[i_step].id_in_calcul        = convert_MP_to_int(time_step_i[ "_id" ]);
        data_user.time_steps.collection_vec[i_step].name                = convert_MP_to_Sc2String(time_step_i[ "name" ]);
        data_user.time_steps.collection_vec[i_step].initial_time        = convert_MP_to_int(time_step_i[ "initial_time" ]);
        data_user.time_steps.collection_vec[i_step].final_time          = convert_MP_to_int(time_step_i[ "final_time" ]);
        data_user.time_steps.collection_vec[i_step].time_step           = convert_MP_to_int(time_step_i[ "time_step" ]);
        data_user.time_steps.collection_vec[i_step].nb_time_steps       = convert_MP_to_int(time_step_i[ "nb_steps" ]);
    }
    
    //traitement des parametres temporels-----------------
    MP  time_parameter_set = time_parameters[ "_children[ 1 ]" ];
    int nb_time_parameters = convert_MP_to_int(time_parameters[ "nb_paramaters" ]);
    data_user.time_steps.parameter_collection_vec.resize(nb_time_parameters);
//     qDebug() << time_parameter_set;
    for(int i_param = 0;i_param < nb_time_parameters; ++i_param){
        PRINT(i_param);
        MP  time_param_i = time_parameter_set[ "_children" ][ i_param ];
        data_user.time_steps.parameter_collection_vec[i_param].id_in_calcul        = convert_MP_to_int(time_param_i[ "_id" ]);
        data_user.time_steps.parameter_collection_vec[i_param].id_param            = convert_MP_to_int(time_param_i[ "_id" ]);
        data_user.time_steps.parameter_collection_vec[i_param].name                = convert_MP_to_Sc2String(time_param_i[ "_name" ]);
        data_user.time_steps.parameter_collection_vec[i_param].alias_name          = convert_MP_to_Sc2String(time_param_i[ "_name" ]);
        data_user.time_steps.parameter_collection_vec[i_param].stepFunctions_vec.resize(nb_time_steps);
        for(int i_step = 0;i_step < nb_time_steps; ++i_step){
            PRINT(i_step);
            qDebug() << time_param_i[ "_children" ];
            MP  time_function_i = time_param_i[ "_children" ][ i_step ];
            data_user.time_steps.parameter_collection_vec[i_param].stepFunctions_vec[i_step].step_id                    = i_step;
            data_user.time_steps.parameter_collection_vec[i_param].stepFunctions_vec[i_step].temporal_function_t        = convert_MP_to_Sc2String(time_function_i[ "your_function" ]);
        }
    }
    
    for(int i_param = 0;i_param < nb_time_parameters; ++i_param){
        PRINT(data_user.time_steps.parameter_collection_vec[i_param].id_in_calcul);
        PRINT(data_user.time_steps.parameter_collection_vec[i_param].id_param);
        PRINT(data_user.time_steps.parameter_collection_vec[i_param].name);
        PRINT(data_user.time_steps.parameter_collection_vec[i_param].alias_name);
        for(int i_step = 0;i_step < nb_time_steps; ++i_step){
            PRINT(data_user.time_steps.parameter_collection_vec[i_param].stepFunctions_vec[i_step].step_id);
            PRINT(data_user.time_steps.parameter_collection_vec[i_param].stepFunctions_vec[i_step].temporal_function_t);
        }
    }
    
//     assert(0);
    
    //traitement des variables parametric-----------------------------------------------------------
    MP  parametric_parameters = computation_parameters[ "_children[ 2 ]" ];
    MP lst_parametric_type = parametric_parameters[ "type.lst" ];
    int num_parametric_type = parametric_parameters[ "type.num" ];
    MP type_parametric = lst_parametric_type[num_parametric_type];
    Sc2String name_parametric_scheme = convert_MP_to_Sc2String(type_parametric);
    PRINT(name_parametric_scheme);
    
    
    if (name_parametric_scheme == "off") { data_user.multiresolution_parameters.multiresolution_type = "off";}
    else if (name_parametric_scheme == "sequential") { data_user.multiresolution_parameters.multiresolution_type = "sequential";}
    PRINT(data_user.multiresolution_parameters.multiresolution_type);
    
    data_user.multiresolution_parameters.resolution_number = convert_MP_to_int(parametric_parameters[ "nb_resolutions.val" ]);
    PRINT(data_user.multiresolution_parameters.resolution_number);
    
    int nb_parametric_variables = convert_MP_to_int(parametric_parameters[ "nb_parameters" ]);
    PRINT(nb_parametric_variables);
    
    data_user.multiresolution_parameters.collection_vec.resize(nb_parametric_variables);
    for(int i_param = 0;i_param < nb_parametric_variables; ++i_param){
        PRINT("-----------parametric_variables---------------");
        MP  parametric_item = parametric_parameters[ "_children" ][ i_param ];
        // valeurs communes
        // selon le type : ...
        Sc2String parameter_type = convert_MP_to_Sc2String(parametric_item["_name_class"]);
        PRINT(parameter_type);
        if(parameter_type == "Basic1DFunctionItem"){        // ... fonction
            data_user.multiresolution_parameters.collection_vec[i_param].id_in_calcul               = convert_MP_to_int(parametric_item[ "_id" ]);
            data_user.multiresolution_parameters.collection_vec[i_param].name                       = convert_MP_to_Sc2String(parametric_item[ "_name" ]);
            data_user.multiresolution_parameters.collection_vec[i_param].type                       = "function";
            data_user.multiresolution_parameters.collection_vec[i_param].nb_values                  = 0;    /// Valeur par defaut
            data_user.multiresolution_parameters.collection_vec[i_param].function                   = convert_MP_to_Sc2String(parametric_item[ "your_function" ]);
            //* Debug
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].id_in_calcul);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].name);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].type);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].nb_values);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].function);
            //*/
        }
        else if(parameter_type == "ParametricListItem"){    // ... liste
            data_user.multiresolution_parameters.collection_vec[i_param].id_in_calcul               = convert_MP_to_int(parametric_item[ "_id" ]);
            data_user.multiresolution_parameters.collection_vec[i_param].name                       = convert_MP_to_Sc2String(parametric_item[ "_name" ]);
            data_user.multiresolution_parameters.collection_vec[i_param].type                       = "list";
            MP values_list = parametric_item[ "_values" ];
            int nb_values = convert_MP_to_int(parametric_item[ "_size" ]);
            data_user.multiresolution_parameters.collection_vec[i_param].nb_values                  = nb_values;
            data_user.multiresolution_parameters.collection_vec[i_param].values.reserve(nb_values);
            for(int i_value = 0; i_value < nb_values; i_value++){
                Sc2String value = convert_MP_to_Sc2String(values_list[ i_value ]);
                data_user.multiresolution_parameters.collection_vec[i_param].values << value;
                //PRINT(value);
            }
            //* Debug
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].id_in_calcul);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].name);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].type);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].nb_values);
            PRINT(data_user.multiresolution_parameters.collection_vec[i_param].values);
            //*/
        }
    }
    
    //assert(0);
}

// traitement des matériaux du calculs
void add_MP_materials_to_data_user(MP material_set, DataUser &data_user){
    //traitement des matériaux---------------------
    int nb_materials = convert_MP_to_int(material_set[ "_nb_materials" ]);
    data_user.materials_vec.resize(nb_materials);
    for(int i_mat = 0;i_mat < nb_materials; ++i_mat){
        MP material_i = material_set[ "_children" ][ i_mat ];
        MP name_type_material_i = material_i[ "_name" ];
        MP lst_material_type = material_i[ "type.lst" ];
        int num_type_material_i = material_i[ "type.num" ];
        MP type_material_i = lst_material_type[num_type_material_i];
        Sc2String name_i = convert_MP_to_Sc2String(type_material_i[ "_name" ]);
        
        
        data_user.materials_vec[i_mat].id_in_calcul             = convert_MP_to_int(material_i[ "_id" ]);
        data_user.materials_vec[i_mat].name                     = convert_MP_to_Sc2String(material_i[ "_name" ]);
        data_user.materials_vec[i_mat].type_num                 = convert_MP_to_int(type_material_i[ "_type_num" ]);
        
        qDebug() << type_material_i[ "_type_plast" ];
        qDebug() << type_material_i[ "_type_endo" ];
        
        qDebug() << type_material_i[ "elasticity.E" ];
        qDebug() << type_material_i[ "elasticity.nu" ];
        PRINT(name_i);
        
        data_user.materials_vec[i_mat].type_plast               = convert_MP_to_Sc2String(type_material_i[ "_type_plast" ]);
        data_user.materials_vec[i_mat].type_endo                = convert_MP_to_Sc2String(type_material_i[ "_type_endo" ]);
        
        if(name_i == "isotropic elastic"){
            data_user.materials_vec[i_mat].mtype                = "isotrope"; 
            data_user.materials_vec[i_mat].comp                 = "el";
            
            data_user.materials_vec[i_mat].E_1                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E" ]);
            data_user.materials_vec[i_mat].nu_12                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu" ]);
            data_user.materials_vec[i_mat].alpha_1              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha" ]); 
        }
        
        else if(name_i == "orthotropic elastic"){
            data_user.materials_vec[i_mat].mtype = "orthotrope"; 
            data_user.materials_vec[i_mat].comp = "el";

            data_user.materials_vec[i_mat].E_1                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[0]" ]);
            data_user.materials_vec[i_mat].E_2                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[1]" ]);
//             data_user.materials_vec[i_mat].E_3                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].nu_12                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[0]" ]);
            data_user.materials_vec[i_mat].nu_13                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[1]" ]);
//             data_user.materials_vec[i_mat].nu_23                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].cis_1                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[0]" ]);
            data_user.materials_vec[i_mat].cis_2                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[1]" ]);
//             data_user.materials_vec[i_mat].cis_3                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].alpha_1              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[0]" ]); 
            data_user.materials_vec[i_mat].alpha_2              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[1]" ]);
//             data_user.materials_vec[i_mat].alpha_3              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_1_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[0]" ]); 
            data_user.materials_vec[i_mat].dir_1_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[1]" ]);
//             data_user.materials_vec[i_mat].dir_1_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_2_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[0]" ]); 
            data_user.materials_vec[i_mat].dir_2_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[1]" ]);
//             data_user.materials_vec[i_mat].dir_2_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_3_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[0]" ]); 
            data_user.materials_vec[i_mat].dir_3_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[1]" ]);
//             data_user.materials_vec[i_mat].dir_3_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[2]" ]);// DIM 3
        }
        else if(name_i == "isotropic plastic")  {
            data_user.materials_vec[i_mat].mtype = "isotrope"; 
            data_user.materials_vec[i_mat].comp = "pl";

            data_user.materials_vec[i_mat].E_1                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E" ]);
            data_user.materials_vec[i_mat].nu_12                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu" ]);
            data_user.materials_vec[i_mat].alpha_1              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha" ]);
            
            data_user.materials_vec[i_mat].R0                   = convert_MP_to_Sc2String(type_material_i[ "plasticity.R0" ]);
            data_user.materials_vec[i_mat].k_p                  = convert_MP_to_Sc2String(type_material_i[ "plasticity.Kp" ]);
            data_user.materials_vec[i_mat].m_p                  = convert_MP_to_Sc2String(type_material_i[ "plasticity.Mp" ]);
            data_user.materials_vec[i_mat].coeff_plast_cinematique       = convert_MP_to_Sc2String(type_material_i[ "plasticity.C" ]);
          
        }
        else if(name_i == "isotropic damageable")  {
            data_user.materials_vec[i_mat].mtype = "isotrope"; 
            data_user.materials_vec[i_mat].comp = "en";

            data_user.materials_vec[i_mat].E_1                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E" ]);
            data_user.materials_vec[i_mat].nu_12                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu" ]);
            data_user.materials_vec[i_mat].alpha_1              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha" ]);
            
            data_user.materials_vec[i_mat].Yo                   = convert_MP_to_Sc2String(type_material_i[ "dammage.Yo" ]);
            data_user.materials_vec[i_mat].dmax                 = convert_MP_to_reel(type_material_i[ "dammage.dmax" ]);
            data_user.materials_vec[i_mat].b_c                  = convert_MP_to_reel(type_material_i[ "dammage.bc" ]);
        }
        else if(name_i == "mesomodel")          {
            data_user.materials_vec[i_mat].mtype = "orthotrope"; 
            data_user.materials_vec[i_mat].comp = "mesomodele";
            
            data_user.materials_vec[i_mat].E_1                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[0]" ]);
            data_user.materials_vec[i_mat].E_2                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[1]" ]);
//             data_user.materials_vec[i_mat].E_3                  = convert_MP_to_Sc2String(type_material_i[ "elasticity.E[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].nu_12                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[0]" ]);
            data_user.materials_vec[i_mat].nu_13                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[1]" ]);
//             data_user.materials_vec[i_mat].nu_23                = convert_MP_to_Sc2String(type_material_i[ "elasticity.nu[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].cis_1                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[0]" ]);
            data_user.materials_vec[i_mat].cis_2                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[1]" ]);
//             data_user.materials_vec[i_mat].cis_3                = convert_MP_to_Sc2String(type_material_i[ "elasticity.G[2]" ]);// DIM 3
            data_user.materials_vec[i_mat].alpha_1              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[0]" ]); 
            data_user.materials_vec[i_mat].alpha_2              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[1]" ]);
//             data_user.materials_vec[i_mat].alpha_3              = convert_MP_to_Sc2String(type_material_i[ "generic.alpha[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_1_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[0]" ]); 
            data_user.materials_vec[i_mat].dir_1_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[1]" ]);
//             data_user.materials_vec[i_mat].dir_1_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_1[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_2_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[0]" ]); 
            data_user.materials_vec[i_mat].dir_2_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[1]" ]);
//             data_user.materials_vec[i_mat].dir_2_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_2[2]" ]);// DIM 3
            
            data_user.materials_vec[i_mat].dir_3_x              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[0]" ]); 
            data_user.materials_vec[i_mat].dir_3_y              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[1]" ]);
//             data_user.materials_vec[i_mat].dir_3_z              = convert_MP_to_reel(type_material_i[ "main_directions.direction_3[2]" ]); // DIM 3
            
            data_user.materials_vec[i_mat].Yo                   = convert_MP_to_Sc2String(type_material_i[ "dammage.Yo" ]);
            data_user.materials_vec[i_mat].Yc                   = convert_MP_to_Sc2String(type_material_i[ "dammage.Yc" ]);
            data_user.materials_vec[i_mat].Ycf                  = convert_MP_to_Sc2String(type_material_i[ "dammage.Ycf" ]);
            data_user.materials_vec[i_mat].dmax                 = convert_MP_to_reel(type_material_i[ "dammage.dmax" ]);
            data_user.materials_vec[i_mat].b_c                  = convert_MP_to_reel(type_material_i[ "dammage.bc" ]);
            data_user.materials_vec[i_mat].a                    = convert_MP_to_reel(type_material_i[ "dammage.a" ]);
            data_user.materials_vec[i_mat].tau_c                = convert_MP_to_reel(type_material_i[ "dammage.tau" ]);
        } 
    }
    
    for(int i_edge=0; i_edge<data_user.materials_vec.size(); i_edge++){
        PRINT("-----------materials---------------");
        PRINT(data_user.materials_vec[i_edge].name);
        PRINT(data_user.materials_vec[i_edge].id_in_calcul);
        PRINT(data_user.materials_vec[i_edge].type_plast);
        PRINT(data_user.materials_vec[i_edge].type_endo);
        PRINT(data_user.materials_vec[i_edge].E_1);
        PRINT(data_user.materials_vec[i_edge].E_2);
        PRINT(data_user.materials_vec[i_edge].E_3);
        PRINT(data_user.materials_vec[i_edge].nu_12);
        PRINT(data_user.materials_vec[i_edge].nu_13);
        PRINT(data_user.materials_vec[i_edge].nu_23);
    }  
    PRINT(data_user.materials_vec.size());
}


// traitement des liaisons du calculs
void add_MP_links_to_data_user(MP link_set, DataUser &data_user){
    //traitement des liaisons---------------------
    int nb_links = convert_MP_to_int(link_set[ "_nb_links" ]);
    data_user.links_vec.resize(nb_links);
    for(int i_link = 0;i_link < nb_links; ++i_link){
        MP link_i = link_set[ "_children" ][ i_link ];
        MP name_type_link_i = link_i[ "_name" ];
        MP lst_link_type = link_i[ "type.lst" ];
        int num_type_link_i = link_i[ "type.num" ];
        MP type_link_i = lst_link_type[num_type_link_i];
        
        
        Sc2String name_i = convert_MP_to_Sc2String(type_link_i[ "_name" ]);
        PRINT(name_i);
        data_user.links_vec[i_link].id_in_calcul             = convert_MP_to_int(link_i[ "_id" ]);
        data_user.links_vec[i_link].name                     = convert_MP_to_Sc2String(link_i[ "_name" ]);
        data_user.links_vec[i_link].type_num                 = convert_MP_to_int(type_link_i[ "_type_num" ]);
        qDebug() << type_link_i[ "_type_num" ] ;
        data_user.links_vec[i_link].Ep_type                  = 0;
        
        //initialisation
        data_user.links_vec[i_link].Ep_n                        = "0";
        data_user.links_vec[i_link].Ep_x                        = "0";
        data_user.links_vec[i_link].Ep_y                        = "0";
        data_user.links_vec[i_link].Ep_z                        = "0";
        data_user.links_vec[i_link].Preload_z                   = "0";
        data_user.links_vec[i_link].Preload_y                   = "0";
        data_user.links_vec[i_link].Preload_x                   = "0";
        data_user.links_vec[i_link].Preload_n                   = "0";
        data_user.links_vec[i_link].f                           = "0";
        data_user.links_vec[i_link].Fcr_t                       = "0";
        data_user.links_vec[i_link].Fcr_n                       = "0";
        data_user.links_vec[i_link].Rop                         = "0";
        data_user.links_vec[i_link].kp                          = "0";
        data_user.links_vec[i_link].np                          = "0";
        data_user.links_vec[i_link].Kn                          = "0";
        data_user.links_vec[i_link].Knc                         = "0";
        data_user.links_vec[i_link].Kt                          = "0";
        data_user.links_vec[i_link].Yo                          = "0";
        data_user.links_vec[i_link].Yc                          = "0";
        data_user.links_vec[i_link].alpha                       = "0";
        data_user.links_vec[i_link].gamma                       = "0";
        data_user.links_vec[i_link].n                           = "0";
        
        
        if(name_i == "perfect"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
        } 
        else if(name_i == "elastic"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
            data_user.links_vec[i_link].Kn                      = convert_MP_to_Sc2String(type_link_i[ "normal_rigidity" ]);
            data_user.links_vec[i_link].Kt                      = convert_MP_to_Sc2String(type_link_i[ "tangent_rigidity" ]);
            data_user.links_vec[i_link].Knc                     = convert_MP_to_Sc2String(type_link_i[ "compression_rigidity" ]);
        }
        else if(name_i == "contact"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
            data_user.links_vec[i_link].f                       = convert_MP_to_Sc2String(type_link_i[ "friction" ]);
        }
        else if(name_i == "perfect breakable"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
            data_user.links_vec[i_link].Fcr_n                   = convert_MP_to_Sc2String(type_link_i[ "Fc_n" ]);
            data_user.links_vec[i_link].Fcr_t                   = convert_MP_to_Sc2String(type_link_i[ "Fc_t" ]);    
            data_user.links_vec[i_link].f                       = convert_MP_to_Sc2String(type_link_i[ "friction" ]);
        }
        else if(name_i == "elastic breakable"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
            data_user.links_vec[i_link].Kn                      = convert_MP_to_Sc2String(type_link_i[ "normal_rigidity" ]);
            data_user.links_vec[i_link].Kt                      = convert_MP_to_Sc2String(type_link_i[ "tangent_rigidity" ]);
            data_user.links_vec[i_link].Knc                     = convert_MP_to_Sc2String(type_link_i[ "compression_rigidity" ]);
            data_user.links_vec[i_link].Fcr_n                   = convert_MP_to_Sc2String(type_link_i[ "Fc_n" ]);
            data_user.links_vec[i_link].Fcr_t                   = convert_MP_to_Sc2String(type_link_i[ "Fc_t" ]);    
            data_user.links_vec[i_link].f                       = convert_MP_to_Sc2String(type_link_i[ "friction" ]);
        }
        else if(name_i == "cohesiv"){
            data_user.links_vec[i_link].Ep_n                    = convert_MP_to_Sc2String(type_link_i[ "thickness" ]);
            data_user.links_vec[i_link].Kn                      = convert_MP_to_Sc2String(type_link_i[ "normal_rigidity" ]);
            data_user.links_vec[i_link].Kt                      = convert_MP_to_Sc2String(type_link_i[ "tangent_rigidity" ]);
            data_user.links_vec[i_link].Knc                     = convert_MP_to_Sc2String(type_link_i[ "compression_rigidity" ]);
            data_user.links_vec[i_link].Fcr_n                   = convert_MP_to_Sc2String(type_link_i[ "Fc_n" ]);
            data_user.links_vec[i_link].Fcr_t                   = convert_MP_to_Sc2String(type_link_i[ "Fc_t" ]);    
            data_user.links_vec[i_link].Yo                      = convert_MP_to_Sc2String(type_link_i[ "Yo" ]);
            data_user.links_vec[i_link].Yc                      = convert_MP_to_Sc2String(type_link_i[ "Yc" ]);
            data_user.links_vec[i_link].alpha                   = convert_MP_to_Sc2String(type_link_i[ "alpha" ]);
            data_user.links_vec[i_link].gamma                   = convert_MP_to_Sc2String(type_link_i[ "gamma" ]);
            data_user.links_vec[i_link].n                       = convert_MP_to_Sc2String(type_link_i[ "n" ]);
            data_user.links_vec[i_link].f                       = convert_MP_to_Sc2String(type_link_i[ "friction" ]);
        }
    }
    
    for(int i_edge=0; i_edge<data_user.links_vec.size(); i_edge++){
        PRINT("-----------links---------------");
        PRINT(data_user.links_vec[i_edge].name);
        PRINT(data_user.links_vec[i_edge].id_in_calcul);
        PRINT(data_user.links_vec[i_edge].type_num);
        PRINT(data_user.links_vec[i_edge].Ep_type);
        
        PRINT(data_user.links_vec[i_edge].Ep_n);
        PRINT(data_user.links_vec[i_edge].f);
        PRINT(data_user.links_vec[i_edge].Fcr_t);
        PRINT(data_user.links_vec[i_edge].Fcr_n);
        PRINT(data_user.links_vec[i_edge].Rop);
        PRINT(data_user.links_vec[i_edge].kp);
        PRINT(data_user.links_vec[i_edge].np);
        PRINT(data_user.links_vec[i_edge].Kt);
        PRINT(data_user.links_vec[i_edge].Kn);
        PRINT(data_user.links_vec[i_edge].Knc);
    }  
    PRINT(data_user.links_vec.size());
    
}

// traitement des liaisons du calculs
void add_MP_bcs_to_data_user(MP boundary_condition_set, DataUser &data_user){
    //traitement des liaisons---------------------
    int nb_bcs = convert_MP_to_int(boundary_condition_set[ "_nb_bcs" ]);
    data_user.boundary_conditions_vec.resize(nb_bcs);
    for(int i_bc = 0;i_bc < nb_bcs; ++i_bc){
        MP bc_i = boundary_condition_set[ "_children" ][ i_bc ];
        MP name_type_bc_i = bc_i[ "_name" ];
        MP lst_bc_type = bc_i[ "type.lst" ];
        int num_type_bc_i = bc_i[ "type.num" ];
        MP type_bc_i = lst_bc_type[num_type_bc_i];
        
        data_user.boundary_conditions_vec[i_bc].id_in_calcul             = convert_MP_to_int(bc_i[ "_id" ]);
        data_user.boundary_conditions_vec[i_bc].name                     = convert_MP_to_Sc2String(bc_i[ "_name" ]);
        Sc2String name_i = convert_MP_to_Sc2String(type_bc_i[ "_name" ]);
        PRINT(name_i);
        
        if(name_i == "displacement"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "depl" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function[0]" ]);
            data_user.boundary_conditions_vec[i_bc].spatial_function_y       = convert_MP_to_Sc2String(type_bc_i[ "space_function[1]" ]);
//             data_user.boundary_conditions_vec[i_bc].spatial_function_z       = convert_MP_to_Sc2String(type_bc_i[ "space_function[2]" ]); // DIM 3
        }
        else if(name_i == "normal displacement"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "depl_normal" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function" ]);
        }
        else if(name_i == "speed"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "vit" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function[0]" ]);
            data_user.boundary_conditions_vec[i_bc].spatial_function_y       = convert_MP_to_Sc2String(type_bc_i[ "space_function[1]" ]);
//             data_user.boundary_conditions_vec[i_bc].spatial_function_z       = convert_MP_to_Sc2String(type_bc_i[ "space_function[2]" ]); // DIM 3
        }
        else if(name_i == "normal speed"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "vit_normale" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function" ]);
        }
        else if(name_i == "symetry"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "sym" ;
        }
        else if(name_i == "stress density"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "effort" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function[0]" ]);
            data_user.boundary_conditions_vec[i_bc].spatial_function_y       = convert_MP_to_Sc2String(type_bc_i[ "space_function[1]" ]);
//             data_user.boundary_conditions_vec[i_bc].spatial_function_z       = convert_MP_to_Sc2String(type_bc_i[ "space_function[2]" ]); // DIM 3
        }
        else if(name_i == "normal stress density"){
            data_user.boundary_conditions_vec[i_bc].condition_type = "effort_normal" ;
            data_user.boundary_conditions_vec[i_bc].spatial_function_x       = convert_MP_to_Sc2String(type_bc_i[ "space_function" ]);
        }
    }
    
    for(int i_edge=0; i_edge<data_user.boundary_conditions_vec.size(); i_edge++){
        PRINT("-----------boundary_conditions---------------");
        PRINT(data_user.boundary_conditions_vec[i_edge].name);
        PRINT(data_user.boundary_conditions_vec[i_edge].condition_type);
        PRINT(data_user.boundary_conditions_vec[i_edge].spatial_function_x);
        PRINT(data_user.boundary_conditions_vec[i_edge].spatial_function_y);
//         PRINT(data_user.boundary_conditions_vec[i_edge].spatial_function_z);
    }  
    PRINT(data_user.boundary_conditions_vec.size());
    
}

void add_MP_thermal_loads_to_data_user(MP thermal_load, DataUser &data_user){
    data_user.thermal_load.function   = convert_MP_to_Sc2String(thermal_load[ "thermal_function" ]);
    data_user.thermal_load.name       = convert_MP_to_Sc2String(thermal_load[ "_name" ]);
}

void add_MP_volumic_loads_to_data_user(MP volumic_load_set, DataUser &data_user){
    int nb_loads = convert_MP_to_int(volumic_load_set[ "_nb_loads" ]);
    data_user.volumic_forces_vec.resize(nb_loads);
    for(int i_load = 0;i_load < nb_loads; ++i_load){
        MP vload_i = volumic_load_set[ "_children" ][ i_load ];
        data_user.volumic_forces_vec[i_load].name       = convert_MP_to_Sc2String(vload_i[ "_name" ]);
        data_user.volumic_forces_vec[i_load].gamma      = convert_MP_to_Sc2String(vload_i[ "gamma" ]);
        data_user.volumic_forces_vec[i_load].dx         = convert_MP_to_Sc2String(vload_i[ "space_function[0]" ]);
        data_user.volumic_forces_vec[i_load].dy         = convert_MP_to_Sc2String(vload_i[ "space_function[1]" ]);
//         data_user.volumic_forces_vec[i_load].dz         = convert_MP_to_Sc2String(vload_i[ "space_function[2]" ]);// DIM 3
    }
    
    for(int i_edge=0; i_edge<data_user.volumic_forces_vec.size(); i_edge++){
        PRINT("-----------volumic_forces---------------");
        PRINT(data_user.volumic_forces_vec[i_edge].name);
        PRINT(data_user.volumic_forces_vec[i_edge].gamma);
        PRINT(data_user.volumic_forces_vec[i_edge].dx);
        PRINT(data_user.volumic_forces_vec[i_edge].dy);
//         PRINT(data_user.volumic_forces_vec[i_edge].dz);
    }  
    PRINT(data_user.volumic_forces_vec.size());
}

// add all the sst to data_user
void add_MP_sst_to_data_user(MP sst_set, DataUser &data_user){
    int nb_ssts = sst_set[ "_children" ].size();
    data_user.pieces_vec.resize(nb_ssts);
    for(int i_sst=0; i_sst<nb_ssts; i_sst++){
        MP sst_i = sst_set[ "_children" ][i_sst];
        data_user.pieces_vec[i_sst].id_in_calcul        = convert_MP_to_int(sst_i[ "id" ]);
        data_user.pieces_vec[i_sst].material_id         = convert_MP_to_int(sst_i[ "material_id" ]);
        data_user.pieces_vec[i_sst].name                = convert_MP_to_Sc2String(sst_i[ "_name" ]);
        
        PRINT("-----------sst---------------");
        PRINT(data_user.pieces_vec[i_sst].id_in_calcul);
        PRINT(data_user.pieces_vec[i_sst].material_id);
        PRINT(data_user.pieces_vec[i_sst].name);
        
    }
    PRINT(data_user.pieces_vec.size());
}

// add all the sst to data_user
void add_MP_interfaces_to_data_user(MP interface_set, DataUser &data_user){
    int nb_interfaces = interface_set[ "_children" ].size();
    data_user.interfaces_vec.resize(nb_interfaces);
    for(int i_inter=0; i_inter<nb_interfaces; i_inter++){
        MP inter_i = interface_set[ "_children" ][i_inter];
        data_user.interfaces_vec[i_inter].id_in_calcul          = convert_MP_to_int(inter_i[ "id" ]);
        data_user.interfaces_vec[i_inter].id                    = convert_MP_to_int(inter_i[ "id" ]);
        data_user.interfaces_vec[i_inter].link_id               = convert_MP_to_int(inter_i[ "link_id" ]);
        data_user.interfaces_vec[i_inter].name                  = convert_MP_to_Sc2String(inter_i[ "_name" ]);
        //data_user.interfaces_vec[i_inter].adj_num_group         = convert_MP_to_Sc2String(inter_i[ "group_elements_id[0]" ]) + " " + convert_MP_to_Sc2String(inter_i[ "group_elements_id[1]" ]);
        
        int  test_0 = convert_MP_to_int(inter_i[ "group_elements_id[0]" ]);
        int  test_1 = convert_MP_to_int(inter_i[ "group_elements_id[1]" ]);
        data_user.interfaces_vec[i_inter].adj_num_group << test_0 << " " << test_1;
        
        
//         PRINT(inter_i[ "group_elements_id" ].size());
//         PRINT(test_0);
//         PRINT(test_1);
        PRINT("-----------interface---------------");
        PRINT(data_user.interfaces_vec[i_inter].id_in_calcul);
        PRINT(data_user.interfaces_vec[i_inter].id);
        PRINT(data_user.interfaces_vec[i_inter].link_id);
        PRINT(data_user.interfaces_vec[i_inter].name);
        PRINT(data_user.interfaces_vec[i_inter].adj_num_group);
    }
    PRINT(data_user.interfaces_vec.size());
}

// add all the edge filters to data_user
void add_MP_edges_to_data_user(MP boundary_condition_set, DataUser &data_user){
    MP  boundary_condition_set_children = boundary_condition_set[ "_children" ];
    for(int i_bc=0; i_bc<boundary_condition_set_children.size(); i_bc++){
        MP boundary_condition = boundary_condition_set_children[i_bc];
        int id_boundary_condition = boundary_condition[ "_id" ];
        qDebug() << "id_boundary_condition = " << id_boundary_condition;
        MP edge_filter_set = boundary_condition[ "_children" ];
        for(int i_edge=0; i_edge<edge_filter_set.size(); i_edge++){
            MP edge_filter = edge_filter_set[i_edge];
            int id_edge_filter = edge_filter[ "_id" ];
            qDebug() << "    id_edge_filter : " << id_edge_filter;
            
            DataUser::Json_edges data_edge = new_data_user_edge_from_edge_filter(data_user, edge_filter, id_boundary_condition);
            if (data_edge.geometry != "undefined"){
                data_user.edges_vec.push_back(data_edge);
            }
        }   
    }
    DataUser::Json_edges data_edge_default = new_data_user_edge_default(data_user);
    data_user.edges_vec.push_back(data_edge_default);
    
    for(int i_edge=0; i_edge<data_user.edges_vec.size(); i_edge++){
        PRINT("-----------edges---------------");
        PRINT(data_user.edges_vec[i_edge].id_in_calcul);
        PRINT(data_user.edges_vec[i_edge].boundary_condition_id);
    }  
    PRINT(data_user.edges_vec.size());
}



// add all the edge filters to data_user
void add_MP_edges_to_data_user_for_visu(MP boundary_condition_set, DataUser &data_user){
    MP  boundary_condition_set_children = boundary_condition_set[ "_children" ];
    for(int i_bc=0; i_bc<boundary_condition_set_children.size(); i_bc++){
        MP boundary_condition = boundary_condition_set_children[i_bc];
        int id_boundary_condition = boundary_condition[ "_id" ];
        qDebug() << "id_boundary_condition = " << id_boundary_condition;
        MP edge_filter_set = boundary_condition[ "_children" ];
        for(int i_edge=0; i_edge<edge_filter_set.size(); i_edge++){
            MP edge_filter = edge_filter_set[i_edge];
            int id_edge_filter = edge_filter[ "_id" ];
            qDebug() << "    id_edge_filter : " << id_edge_filter;
            
            
            for (int i_group=0; i_group < edge_filter[ "_children" ].size(); i_group++) {
                MP child = edge_filter[ "_children" ][i_group];
                child[ "_mesh.points" ].clear();
                child[ "_mesh._elements" ].clear();
                child[ "_mesh" ].clear();
            }
            edge_filter[ "_children" ].clear() ; 
            
            DataUser::Json_edges data_edge = new_data_user_edge_from_edge_filter(data_user, edge_filter, id_boundary_condition);
            if (data_edge.geometry != "undefined"){
                data_user.edges_vec.push_back(data_edge);
            }
        }   
    }
    DataUser::Json_edges data_edge_default = new_data_user_edge_default(data_user);
    data_user.edges_vec.push_back(data_edge_default);
    PRINT(data_user.edges_vec.size());
}

// add Geometry edges to MP mesh format
void add_edges_to_MP_assembly(MP  oec, MP boundary_condition_set, DataUser &data_user, GeometryUser &geometry_user){
    geometry_user.split_group_edges_within_geometry(data_user);
    MP  boundary_condition_set_children = boundary_condition_set[ "_children" ];
    for (int i_group=0; i_group<geometry_user.group_interfaces.size(); i_group++) {
        if(geometry_user.group_interfaces[i_group].type == 0){
          qDebug() << "bord --------------------------------------";
          qDebug() << geometry_user.group_interfaces[i_group].id ;
          qDebug() << geometry_user.group_interfaces[i_group].is_splited ;
          qDebug() << geometry_user.group_interfaces[i_group].edge_id ;
          qDebug() << geometry_user.group_interfaces[i_group].from_group_id ;
        }
      
      
        if(geometry_user.group_interfaces[i_group].type == 0 and geometry_user.group_interfaces[i_group].is_splited == 0 and geometry_user.group_interfaces[i_group].edge_id != -1 and geometry_user.group_interfaces[i_group].edge_id != -2){
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
            
            //liste des points du maillage------------
            new_list_points_mesh_2D(om, geometry_user.group_interfaces[i_group]);

            //liste des éléments du maillage----------
            new_list_elements_mesh_2D(om, geometry_user.group_interfaces[i_group]);
            
            //ajout du edge à l'assemblage------------
            //nb_edges += 1;
            
            qDebug() << "edge[ 'id' ] = " << edge[ "id" ];
            for(int i_bc=0; i_bc<boundary_condition_set_children.size(); i_bc++){
                MP boundary_condition = boundary_condition_set_children[i_bc];
                int id_boundary_condition = boundary_condition[ "_id" ];
                MP edge_filter_set = boundary_condition[ "_children" ];
                for(int i_edge=0; i_edge<edge_filter_set.size(); i_edge++){
                    MP edge_filter = edge_filter_set[i_edge];
                    int id_edge_filter = edge_filter[ "_id" ];
                    qDebug() << "id_edge_filter = " << id_edge_filter;
                    if(id_edge_filter == geometry_user.group_interfaces[i_group].edge_id){
                        edge_filter[ "_children" ] << edge; 
                        break;
                    }
                }
            } 
        }
    }
}



bool Scills2DUpdater::run( MP mp ) {
    qDebug() << mp.type();
    quint64 MP_model_id = mp.get_server_id();
    // does the input file exists ?
    
    int  compute_edges   = mp[ "_compute_edges" ];
    qDebug() << "compute_edges = " << compute_edges;
    int  compute_scills  = mp[ "_compute_scills" ];
    
    MP  structure = mp[ "_children[ 0 ]" ];
    MP  assembly = structure[ "_children[ 0 ]" ];
    MP  oec = assembly[ "_children[ 2 ]" ];
    
    DataUser data_user;
    GeometryUser geometry_user;
    Process process;
    
    // visualisation des bords demandés -------------------------------------------------------------------------
    if (assembly.ok() and compute_edges){
        // see if the hdf5 file of the assembly as allready been load
        QString path_hdf = assembly[ "_path" ];
        qDebug() << path_hdf;
        
        Sc2String file_output_hdf5 = convert_MP_to_Sc2String(assembly[ "_path" ]);
        qDebug() << "lecture du fichier hdf en mémoire : " << path_hdf;
        geometry_user.initialisation(file_output_hdf5);
        geometry_user.read_hdf5(false,true,"test");
        
        // ajout des boundary condition et des edges
        MP  boundary_condition_set = mp[ "_children[ 4 ]" ];
        MP  boundary_condition_set_children = boundary_condition_set[ "_children" ];
        add_MP_edges_to_data_user_for_visu(boundary_condition_set, data_user);
        add_edges_to_MP_assembly(oec, boundary_condition_set, data_user, geometry_user);
        
    // mise en données de Data_User et vérification des données --------------------------------------------------------------
    }else if(assembly.ok() and compute_scills){
        // see if the hdf5 file of the assembly as allready been load
        
        QString path_hdf = assembly[ "_path" ];
        qDebug() << path_hdf;
        
        // répertoire des resultat vtu
//         QFileInfo info1(path_hdf);
//         QDir dir(info1.dir());
//         QString dir_name = dir.absolutePath() ; 
//         qDebug() << dir_name ;
//         QString path_result = dir_name + "/result_" + QString::number(MP_model_id);
        
        QString path_result = mp[ "_path" ];
        qDebug() << path_result ;
        mp[ "path_result" ] = path_result;
        
        Sc2String file_output_hdf5 = convert_MP_to_Sc2String(assembly[ "_path" ]);
        qDebug() << "lecture du fichier hdf en mémoire : " << path_hdf;
        geometry_user.initialisation(file_output_hdf5);
        geometry_user.read_hdf5(false,true,"test");
      
        // ajout des sous structures
        MP  sst_set = assembly[ "_children[ 0 ]" ];
        add_MP_sst_to_data_user(sst_set, data_user);
        
        // ajout des interfaces
        MP  interface_set = assembly[ "_children[ 1 ]" ];
        add_MP_interfaces_to_data_user(interface_set, data_user);
        
        // ajout des paramètres LATIN
        MP  computation_parameters = mp[ "_children[ 1 ]" ];
        add_MP_computation_parameters_to_data_user(computation_parameters, data_user, path_result);
        
        // ajout des matériaux
        MP  material_set = mp[ "_children[ 2 ]" ];
        add_MP_materials_to_data_user(material_set, data_user);
        
        // ajout des liaisons
        MP  link_set = mp[ "_children[ 3 ]" ];
        add_MP_links_to_data_user(link_set, data_user);
        
        // ajout des edges
        MP  boundary_condition_set = mp[ "_children[ 4 ]" ];
        MP  boundary_condition_set_children = boundary_condition_set[ "_children" ];
        add_MP_edges_to_data_user(boundary_condition_set, data_user);
        // ajout des boundary condition et des edges
        //MP  boundary_condition_set = mp[ "_children[ 4 ]" ];
        add_MP_bcs_to_data_user(boundary_condition_set, data_user);
      
        // ajout des thermal_load
        MP  thermal_load = mp[ "_children[ 5 ]" ];
        add_MP_thermal_loads_to_data_user(thermal_load, data_user);
        
        // ajout des volumic_load
        MP  volumic_load_set = mp[ "_children[ 6 ]" ];
        add_MP_volumic_loads_to_data_user(volumic_load_set, data_user);
        
        // réalisation du calcul
        process.initialisation_MPI_for_scwal();
        process.data_user = &data_user;
        process.geometry_user = &geometry_user;
        
        process.geometry_user->split_group_edges_within_geometry(*process.data_user);
        process.preparation_calcul();
        PRINT("fin préparation calcul");
        process.boucle_multi_resolution();
        
        process.finalisation_MPI();
        PRINT("fin calcul");
        
        
        // zip du fichier de résultat
        zip_result(mp);
        
    }

    mp[ "_compute_edges" ] = false;
    mp[ "compute_scills" ] = false;
    mp[ "_compute_scills" ] = false;
    mp[ "_computation_mode" ] = false;
    mp.flush();
    add_message( mp, ET_Info, "Scills2DUpdater just finish" );
}


