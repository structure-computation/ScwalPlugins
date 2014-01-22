#include "Field.h"
#include "Mesh.h"
#include <Soca/Model/TypedArray.h>


Field::Field()
{
    current_time_step = 0;
}

Field::Field(MP fielditem, Mesh* mesh):
    mesh(mesh)
{
    load(fielditem);
    current_time_step = 0;
}

void Field::load(MP fielditem)
{
    name = (QString) fielditem["name"];
    //qDebug() << "Nom : " << name;
    
    const int nb_times = fielditem["data._data"].size();
    if(nb_times)
    {
        /// Determination du type de champs
        const int nb_nodes = mesh->nodes.size();
        const int nb_elems = mesh->elements.size();
        TypedArray<double> *val = dynamic_cast<TypedArray<double> *>( fielditem["data._data[0].field._data"].model() );
        const int nb_data = val->size();
        //qDebug() << "nb_data : " << nb_data;
        if(nb_data % nb_nodes == 0)
        {
            type = Nodal;
        }
        else if (nb_data % nb_elems == 0)
        {
            type = Elemental;
            qDebug() << "ALARM!";
            exit(-1);
        }
        else
        {
            // TODO Gestion erreur : impossible de determiner le type du champs
            qDebug() << "impossible de determiner le type du champs";
            exit(-1);
        }
        
        /// Determination de l'ordre tensoriel du champs
        
        /// Recuperation des valeurs du champs
        values.resize(nb_times);
        for(int t = 0; t < nb_times; t++)
        {
            MP fieldvalue = fielditem["data._data"][t];
            values[t].time = fieldvalue["pos.axe_value"];
            TypedArray<double> *val = dynamic_cast<TypedArray<double> *>( fieldvalue["field._data"].model() );
            values[t].data.resize(nb_data);
            for(int n = 0; n < nb_data; n++)
                values[t].data[n] = val->operator[](n);
        }
    }
    else
    {
        // TODO Gestion erreur: aucun pas de temps
    }
}

void Field::save(MP fielditem) const
{
    MP interpolated_field = MP::new_obj( "InterpolatedField" );
    interpolated_field[ "_data" ] = MP::new_lst();
    
    fielditem[ "name" ] = name;
    fielditem[ "data" ] = interpolated_field;
    
    QString type_field;
    if(type == Nodal)
        type_field = "NodalField";
    else
        type_field = "ElementalField";
    
    for(int v = 0; v < values.size(); v++)
    {
        MP value = MP::new_obj( type_field );
        value[ "_mesh" ] = mesh->save();
        //qDebug() << value["_mesh"];
        
        QVector<int> indices;
        indices << values[v].data.size();
        TypedArray<double> *data = new TypedArray<double>(indices);
        for(int i = 0; i < values[v].data.size(); i++)
            data->operator[](i) = values[v].data[i];
        value[ "_data" ] = data;
        
        MP disp = MP::new_obj();
        disp[ "field" ] = value;
        disp[ "pos" ] = MP::new_lst();
        
        MP pos_v = MP::new_obj();
        pos_v[ "axe_value" ] = values[v].time;
        pos_v[ "axe_name" ] = "time";
        disp[ "pos" ] << pos_v;
        
        interpolated_field[ "_data" ] << disp;
    }
}

Field Field::operator+(const Field& other) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
//     // pour tous les pas de temps
//     result.values.resize( values.size() );
//     for(int v = 0; v < values.size(); v++)
//     {
//         result.values[v].time = values[v].time;
//         result.values[v].data.resize(values[v].data.size());
//         for(unsigned n = 0; n < values[v].data.size(); n++)
//             result.values[v].data[n] = values[v].data[n] + other.values[v].data[n];
//     }
//     return result;
    
    //pour le pas de temps considéré
    result.values.resize( 1 );
    result.values[0].time = values[current_time_step].time;
    result.values[0].data.resize(values[current_time_step].data.size());
    for(unsigned n = 0; n < values[current_time_step].data.size(); n++)
        result.values[0].data[n] = values[current_time_step].data[n] + other.values[other.current_time_step].data[n];
    return result;
}

Field Field::operator-(const Field& other) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
    
    qDebug() << "input_0 : " << values.size() << "  " << current_time_step;
    qDebug() << "input_1 : " << other.values.size() << "  " << other.current_time_step;
//     // pour tous les pas de temps
//     result.values.resize( values.size() );
//     for(int v = 0; v < values.size(); v++)
//     {
//         result.values[v].time = values[v].time;
//         result.values[v].data.resize(values[v].data.size());
//         for(unsigned n = 0; n < values[v].data.size(); n++)
//             result.values[v].data[n] = values[v].data[n] - other.values[v].data[n];
//     }
//     return result;
    
    //pour le pas de temps considéré
    result.values.resize( 1 );
    result.values[0].time = values[current_time_step].time;
    result.values[0].data.resize(values[current_time_step].data.size());
    for(unsigned n = 0; n < values[current_time_step].data.size(); n++){
        qDebug() << values[current_time_step].data[n] << " , " << other.values[other.current_time_step].data[n];
        result.values[0].data[n] = values[current_time_step].data[n] - other.values[other.current_time_step].data[n];
    }
    return result;
}

Field Field::operator*(const Field& other) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
    
//     // pour tous les pas de temps
//     result.values.resize( values.size() );
//     for(int v = 0; v < values.size(); v++)
//     {
//         result.values[v].time = values[v].time;
//         result.values[v].data.resize(values[v].data.size());
//         for(unsigned n = 0; n < values[v].data.size(); n++)
//             result.values[v].data[n] = values[v].data[n] * other.values[v].data[n];
//     }
//     return result;
    
    //pour le pas de temps considéré
    result.values.resize( 1 );
    result.values[0].time = values[current_time_step].time;
    result.values[0].data.resize(values[current_time_step].data.size());
    for(unsigned n = 0; n < values[current_time_step].data.size(); n++)
        result.values[0].data[n] = values[current_time_step].data[n] * other.values[other.current_time_step].data[n];
    return result;
}

Field Field::operator/(const Field& other) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
    
//     // pour tous les pas de temps
//     result.values.resize( values.size() );
//     for(int v = 0; v < values.size(); v++)
//     {
//         result.values[v].time = values[v].time;
//         result.values[v].data.resize(values[v].data.size());
//         for(unsigned n = 0; n < values[v].data.size(); n++)
//             result.values[v].data[n] = values[v].data[n] / other.values[v].data[n];
//     }
//     return result;
    
    //pour le pas de temps considéré
   result.values.resize( 1 );
    result.values[0].time = values[current_time_step].time;
    result.values[0].data.resize(values[current_time_step].data.size());
    for(unsigned n = 0; n < values[current_time_step].data.size(); n++)
        result.values[0].data[n] = values[current_time_step].data[n] / other.values[other.current_time_step].data[n];
    return result;
}

Field Field::operator*(double value) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
    result.values.resize( values.size() );
    for(int v = 0; v < values.size(); v++)
    {
        result.values[v].time = values[v].time;
        result.values[v].data = values[v].data * value;
    }
    return result;
}

Field Field::operator/(double value) const
{
    Field result;
    result.name = name;
    result.type = type;
    result.order = order;
    result.values.resize( values.size() );
    for(int v = 0; v < values.size(); v++)
    {
        result.values[v].time = values[v].time;
        result.values[v].data = values[v].data / value;
    }
    return result;
}


void Field::change_connectivity(const LMT::Vec< int > correspondance){
    QVector<FieldValue> changed_values;
    changed_values = values;
    for(int v = 0; v < values.size(); v++)
    {
        for(unsigned n = 0; n < values[v].data.size(); n++){
            changed_values[v].data[n] = values[v].data[correspondance[n]];
        }
    }
    values = changed_values;
  
}
