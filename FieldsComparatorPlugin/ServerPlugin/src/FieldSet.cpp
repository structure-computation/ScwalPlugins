#include "FieldSet.h"

FieldSet::FieldSet(MP fieldsetitem)
{
    load(fieldsetitem);
    correspondance_computed = false;
}

void FieldSet::load(MP fieldsetitem)
{
    const int nb_fields = fieldsetitem["visualization.color_by.lst"].size();
    current_field = fieldsetitem["visualization.color_by.num"];
    if(nb_fields)
    {
        /// Recuperation du maillage
        qDebug() << "-----récupération du maillage-----" ;
        const int nb_times = fieldsetitem["visualization.color_by.lst[0].data._data"].size();
        PRINT(nb_times);
        if(nb_times)
        {
            MP mesh_data = fieldsetitem["visualization.color_by.lst[0].data._data[0].field._mesh"];
            mesh = mesh_data;   /// voir Mesh.cpp
        }
        else
        {
            //TODO Gestion d'erreur : aucune valeur de pas de temps
        }
        
        /// Recuperation des champs
        qDebug() << "-----récupération des champs-----" ;
        PRINT(nb_fields);
        
//         // récupération de tous les champs
//         for(int f = 0; f < nb_fields - 1; f++){
//             PRINT(f);
//             //qDebug() << fieldsetitem["visualization.color_by.lst"][f];
//             fields << Field(fieldsetitem["visualization.color_by.lst"][f],&mesh);   /// voir Field.cpp
//         }
        
        // récupération du current field uniquement
        PRINT(current_field);
        //qDebug() << fieldsetitem["visualization.color_by.lst"][current_field];
        fields << Field(fieldsetitem["visualization.color_by.lst"][current_field],&mesh);   /// voir Field.cpp
            
    }
    else
    {
        //TODO Gestion erreur : aucun champs defini
    }
}

void FieldSet::load_current_time_step(int time_step)
{
    current_time_step = time_step;
    for(int f = 0; f < fields.size(); f++){
        fields[f].current_time_step = current_time_step;
    }
}

void FieldSet::save(MP fieldsetitem) const
{
    int nb_fields_out = fieldsetitem["visualization.color_by.lst"].size();
    PRINT(nb_fields_out);
    fieldsetitem["visualization.color_by.lst"].clear();
    nb_fields_out = fieldsetitem["visualization.color_by.lst"].size();
    PRINT(nb_fields_out);
    fieldsetitem.flush();
    for(int f = 0; f < fields.size(); f++)
    {
        MP field = MP::new_obj("NamedParametrizedDrawable");
        fields[f].save(field);
        if(nb_fields_out) fieldsetitem["visualization.color_by.lst"][0] = field; 
        else fieldsetitem["visualization.color_by.lst"] << field; 
    }
    qDebug() << "nb_fields_out : " << fieldsetitem["visualization.color_by.lst"].size();
    fieldsetitem.flush();
}

FieldSet FieldSet::operator+(const FieldSet& other) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        Field other_field = other.fields[f];
        other_field.change_connectivity(correspondance);
        result.fields << (fields[f] + other_field);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

FieldSet FieldSet::operator-(const FieldSet& other) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {   
        Field other_field = other.fields[f];
        other_field.change_connectivity(correspondance);
        result.fields << (fields[f] - other_field);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

FieldSet FieldSet::operator*(const FieldSet& other) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        Field other_field = other.fields[f];
        other_field.change_connectivity(correspondance);
        result.fields << (fields[f] * other_field);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

FieldSet FieldSet::operator/(const FieldSet& other) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        Field other_field = other.fields[f];
        other_field.change_connectivity(correspondance);
        result.fields << (fields[f] / other_field);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

FieldSet FieldSet::operator*(double value) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        result.fields << (fields[f] * value);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

FieldSet FieldSet::operator/(double value) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        result.fields << (fields[f] / value);
        result.fields[f].mesh = &(result.mesh);
    }
    
    return result;
}

void FieldSet::other_field_mesh_correspondance(const FieldSet& other)
{
  
    if(!correspondance_computed){
        LMT::Vec< LMT::Vec<double> >   nodes_0;
        LMT::Vec< LMT::Vec<double> >   nodes_1;
        
        nodes_0 = mesh.nodes;
        nodes_1 = other.mesh.nodes;
        
        // creation de la h_table
        LMT::Vec< LMT::Vec<int> > ht;
        ht.resize(nodes_0.size());
        
        for(int i = 0; i < nodes_0.size(); i++){
            for(int j = 0; j < nodes_1.size(); j++){
                if(nodes_0[i][0] == nodes_1[j][0]){
                    ht[i].push_back(j);
                }
            } 
        }
        
        correspondance.resize(nodes_0.size(),-1);
        for(int i = 0; i < ht.size(); i++){
            for(int j = 0; j < ht[i].size(); j++){
                if(nodes_0[i] == nodes_1[ht[i][j]]){
                    correspondance[i] = ht[i][j];
                    break;
                }
            } 
        }
        
        PRINT(correspondance);
        correspondance_computed = true;
    }
    
}
