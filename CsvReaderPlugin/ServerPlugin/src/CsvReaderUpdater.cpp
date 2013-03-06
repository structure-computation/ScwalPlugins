#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>

#include "parameterscsvreader.h"
#include "CsvReaderUpdater.h"


ParametersCsvReader::Orientation readOrientation(QString fromMP) {
    //qDebug() << QString("Read ") + fromMP;
    if(fromMP == "byRow") {
        return ParametersCsvReader::Row;
    }
    else if(fromMP == "byColumn") {
        return ParametersCsvReader::Column;
    } 
}


char readValueSeparator(QString fromMP) {
    //qDebug() << QString("Separator ") + fromMP;
    if(fromMP == ";") {
        return ';';
    }
    else if(fromMP == ",") {
        return ',';
    } 
}


MP new_list_parametric(QString name){
    //Sc2String str_name_obj;
    //str_name_obj << name << "_" << id;
    //obj[ "_ico" ] = obj_profile["_ico" ];
    MP obj = MP::new_obj("ListParameterItem");
    obj[ "_name" ] = name; // str_name_obj.c_str();
    obj[ "_viewable" ] = true;
    obj[ "_children" ] = MP::new_lst();
    obj[ "_values" ] = MP::new_lst();
    obj[ "_name_class" ] = "";
    obj[ "_allow_vmod" ] = true;
    return obj;
};


bool CsvReaderUpdater::run( MP mp ) {
    // recuperation des informations sur le fichier
    MP  file_csv = mp[ "_children[ 0 ]" ];
    /* pour debug
    {
        qDebug() << file_csv;
        QString file_csv_name = file_csv[ "_name" ];
        qDebug() << file_csv_name;
    }//*/
    QString orientation_csv = mp["orientation.lst"][(int) mp["orientation.num"]];
    QString values_separator = mp["values_separator.lst"][(int) mp["values_separator.num"]];
    int has_headers = mp[ "has_headers" ]; // booleen en realite...
    if (file_csv.ok()){
        // recuperation du path du fichier
        quint64 ptr = file_csv[ "_ptr" ];
        QString name = file_csv[ "_name" ];
        MP data = sc->load_ptr( ptr );
        QString path_csv;
        if( data.ok() and data.type() == "Path") {
            QString path_temp = data;
            path_csv = path_temp;
        }
        //qDebug() << "Path : " << path_csv;
        QByteArray byteArray = path_csv.toUtf8();
        const char* c_path_csv = byteArray.constData();
        std::string filename(c_path_csv);
        
        //lecture du fichier CSV -------------------------------------------
        ParametersCsvReader csv_data(
            filename,
            readOrientation(orientation_csv),
            readValueSeparator(values_separator),
            has_headers
        );
        
        // Remplissage de la liste des parametres...
        MP list_param = mp[ "_parameters" ];
        // Suppression des parametres existant
        list_param[ "_output" ].clear();
        for(unsigned i_param = 0; i_param < csv_data.nbParameters(); i_param++) {
            // Creation du nouveau parametre
            MP param = new_list_parametric( QString(csv_data.getHeader(i_param).c_str()) );  // Avec recuperation du header ("" par defaut)
            //qDebug() << "Param " << i_param << " : " << QString(csv_data.getHeader(i_param).c_str());
            for(unsigned i_value = 0; i_value < csv_data.nbValues(); i_value++) {
                // Ajout des valeurs
                param[ "_values" ] << QString(csv_data.getValue(i_param, i_value).c_str());
            }
            // Ajout a la liste des parametres
            list_param[ "_output" ] << param;
            //qDebug() << param;
        }
        qDebug() << list_param;
        
    }
    add_message( mp, ET_Info, "CsvReaderUpdater just finish" );
}

