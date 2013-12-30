#include "FieldSet.h"

FieldSet::FieldSet(MP fieldsetitem)
{
    load(fieldsetitem);
}

void FieldSet::load(MP fieldsetitem)
{
    const int nb_fields = fieldsetitem["visualization.color_by.lst"].size();
    if(nb_fields)
    {
        /// Recuperation du maillage
        const int nb_times = fieldsetitem["visualization.color_by.lst[0].data._data"].size();
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
        for(int f = 0; f < nb_fields - 1; f++)
            fields << Field(fieldsetitem["visualization.color_by.lst"][f],&mesh);   /// voir Field.cpp
    }
    else
    {
        //TODO Gestion erreur : aucun champs defini
    }
}

void FieldSet::save(MP fieldsetitem) const
{
    for(int f = 0; f < fields.size(); f++)
    {
        MP field = MP::new_obj("NamedParametrizedDrawable");
        fields[f].save(field);
        fieldsetitem["visualization.color_by.lst"] << field;
    }
}

FieldSet FieldSet::operator+(const FieldSet& other) const
{
    FieldSet result;
    result.mesh = mesh;
    
    for(int f = 0; f < fields.size(); f++)
    {
        result.fields << (fields[f] + other.fields[f]);
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
        result.fields << (fields[f] - other.fields[f]);
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
        result.fields << (fields[f] * other.fields[f]);
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
        result.fields << (fields[f] / other.fields[f]);
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
