#include <Soca/Com/SodaClient.h>
#include "Scills3DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

//     //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     sc.reg_type( "Scills3DItem" );
//     //chargement du model
//     MP mp = sc.load_ptr(model_id);
//     qDebug() << "model_id : " << model_id;
//     
//     Scills3DUpdater updater;
//     updater.sc = &sc;
//     updater.exec( mp );
//     
//     mp[ "_computation_mode" ] = false;
//     mp[ "_computation_state" ] = false;
//     mp[ "_processing_state" ] = false; 
//     mp.flush();
    
    
//id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "Scills3DItem" );
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "Scills3DItem" and mp.get_server_id() == model_id ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            if( model_stop_state == true ){
                qDebug() << "###############   finish Scills3DItem ###############" ;
                break;
            }else{
                qDebug() << "###############   launch Scills3DItem ###############" ;
                Scills3DUpdater updater;
                updater.sc = &sc;
                updater.exec( mp );
            }
        }
    }
}
