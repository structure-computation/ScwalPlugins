#include <Soca/Com/SodaClient.h>
#include "JobList.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    qDebug() << "argv : " << argv;
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);
    //qDebug() << "model_id : " << model_id;
    // type d'item observé
    sc.reg_type( "UnvReaderItem2D" );
    sc.reg_type( "UnvReaderItem3D" );
    sc.reg_type( "Scult2DItem" );
    sc.reg_type( "Scult3DItem" );
    sc.reg_type( "Scills3DItem" );
    sc.reg_type( "CorrelationItem" );
    sc.reg_type( "MesherItem" );
    sc.reg_type( "File" );
    sc.reg_type( "Img" );
    sc.reg_type( "ServerAssistedVisualization" );
    sc.reg_type( "AcquisitionItem" );
    
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    
    // lancement de la bonne commade
    std::stringstream str_model_id;
    str_model_id << model_id;
    std::string temp_str = str_model_id.str();
    std::string commande;
    
    if(mp.type() == "UnvReaderItem2D" ){
        commande = "../UnvReaderPlugin2D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "UnvReaderItem3D" ){
        commande = "../UnvReaderPlugin3D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "Scult2DItem" ){
        commande = "../Scult2DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "Scult3DItem" ){
        commande = "../Scult3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "Scills3DItem" ){
        commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "ScilabItem" ){
        commande = "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/scilab-5.4.0/lib/scilab:/home/ubuntu/scilab-5.4.0/lib/thirdparty ; ../ScilabPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "CorrelationItem" or mp.type() == "MesherItem" or mp.type() == "File" or mp.type() == "Img" or mp.type() == "ServerAssistedVisualization" ){
        commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    else if(mp.type() == "AcquisitionItem" ){
        commande = "../AcquisitionPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
        std::system(commande.c_str());
    }
    
    sleep(1);
    mp[ "_computation_mode" ] = false;
    mp[ "_computation_state" ] = false;
    mp[ "_processing_state" ] = false;
    mp.flush();
    SodaClient::Event event = sc.event();
}
