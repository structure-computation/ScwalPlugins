#include "FieldsComparatorUpdater.h"
#include "FieldSet.h"

bool FieldsComparatorUpdater::run( MP mp ) {
    //qDebug() << "Loading";
    
    int time_step_input_0 = mp["field_1.time_step"];
    int time_step_input_1 = mp["field_2.time_step"];
    
    FieldSet input_0(mp["_children[0]"]);
    FieldSet input_1(mp["_children[1]"]);
    input_0.load_current_time_step(time_step_input_0);
    input_1.load_current_time_step(time_step_input_1);
    
    qDebug() << "pour le champs 1 : ";
    qDebug() << "Nombre de champs : " << input_0.fields.size();
    for(int f = 0; f < input_0.fields.size(); f++)
    {
        qDebug() << "Champs " << f << " :";
        Field& field = input_0.fields[f];
        qDebug() << "    name : " << field.name;
        qDebug() << "    type : " << ((int) field.type);
        qDebug() << "    order: " << field.order;
        qDebug() << "    nbval: " << field.values[0].data.size();
    }
    
    qDebug() << "pour le champs 2 : ";
    qDebug() << "Nombre de champs : " << input_1.fields.size();
    for(int f = 0; f < input_1.fields.size(); f++)
    {
        qDebug() << "Champs " << f << " :";
        Field& field = input_1.fields[f];
        qDebug() << "    name : " << field.name;
        qDebug() << "    type : " << ((int) field.type);
        qDebug() << "    order: " << field.order;
        qDebug() << "    nbval: " << field.values[0].data.size();
    }
    
    input_0.other_field_mesh_correspondance(input_1);
    
    //
    qDebug() << "----Computing absolute";
    FieldSet output_0 = input_0 - input_1;
    output_0.correspondance_computed = false;
    output_0.other_field_mesh_correspondance(input_0);
    qDebug() << "----Computing relative";
    FieldSet output_1 = output_0 / (input_0 + input_1);
    
    
    qDebug() << "----verification";
    for(int f = 0; f < input_0.fields.size(); f++)
    {
        qDebug() << "**************************************************";
        for(int n = 0; n < input_0.fields[0].values[0].data.size(); n++)
        {
            double a = input_0.fields[f].values[time_step_input_0].data[n];
            double b = input_1.fields[f].values[time_step_input_1].data[input_0.correspondance[n]];
            double x = output_0.fields[f].values[0].data[n];
            double y = output_1.fields[f].values[0].data[n];
            
            double posx_0 = input_0.mesh.nodes[n][0];
            double posx_1 = input_1.mesh.nodes[input_0.correspondance[n]][0];
            
            qDebug() << n << " , " << a << " , " << b << " , " << x << " , " << y << " , " << x - (a-b) << "," << y - (a-b)/(a+b) << ", pos_0 : " << posx_0 << ", pos_1 : " << posx_1;
        }
    }
    
    //qDebug() << "Saving";
    output_0.save(mp["_output[0]._children[0]"]);
    output_1.save(mp["_output[0]._children[1]"]);
    
    add_message( mp, ET_Info, "FieldsComparatorUpdater just finish" );
    qDebug() << "FieldsComparatorUpdater just finish";
}


