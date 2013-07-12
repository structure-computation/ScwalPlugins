#include <Soca/Com/SodaClient.h>
#include "Scills2DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

//     //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     sc.reg_type( "Scills2DItem" );
//     //chargement du model
//     MP mp = sc.load_ptr(model_id);
//     qDebug() << "model_id : " << model_id;
//     
//     Scills2DUpdater updater;
//     updater.sc = &sc;
//     updater.exec( mp );
//     
//     mp[ "_computation_mode" ] = false;
//     mp[ "_computation_state" ] = false;
//     mp[ "_processing_state" ] = false; 
//     mp.flush();
    
    
//id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "Scills2DItem" );
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "Scills2DItem" and mp.get_server_id() == model_id ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            if( model_stop_state == true ){
                qDebug() << "###############   finish Scills2DItem ###############" ;
                break;
            }else{
                qDebug() << "###############   launch Scills2DItem ###############" ;
                Scills2DUpdater updater;
                updater.argc = argc;
                updater.argv = argv;
                updater.sc = &sc;
                updater.exec( mp );
            }
        }
    }
}
