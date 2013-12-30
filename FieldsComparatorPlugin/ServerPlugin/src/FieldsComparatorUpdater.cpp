#include "FieldsComparatorUpdater.h"
#include "FieldSet.h"

bool FieldsComparatorUpdater::run( MP mp ) {
    //qDebug() << "Loading";
    FieldSet input_0(mp["_children[0]"]);
    FieldSet input_1(mp["_children[1]"]);
    /*
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
    //*/
    //qDebug() << "Computing";
    FieldSet output_0 = input_0 - input_1;
    FieldSet output_1 = output_0 / (input_0 + input_1);
    
    for(int f = 0; f < input_0.fields.size(); f++)
    {
        qDebug() << "**************************************************";
        for(int n = 0; n < input_0.fields[0].values[0].data.size(); n++)
        {
            double a = input_0.fields[f].values[0].data[n];
            double b = input_1.fields[f].values[0].data[n];
            double x = output_0.fields[f].values[0].data[n];
            double y = output_1.fields[f].values[0].data[n];
            
            qDebug() << a << " , " << b << " , " << x << " , " << y << " , " << x - (a-b) << "," << y - (a-b)/(a+b);
        }
    }
    
    //qDebug() << "Saving";
    output_0.save(mp["_output[0]._children[0]"]);
    output_1.save(mp["_output[0]._children[1]"]);
    
    add_message( mp, ET_Info, "FieldsComparatorUpdater just finish" );
    qDebug() << "FieldsComparatorUpdater just finish";
}


