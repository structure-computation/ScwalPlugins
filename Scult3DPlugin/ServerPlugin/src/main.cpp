#include <Soca/Com/SodaClient.h>
#include "Scult3DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    
    qDebug() << "###############   launch Scult3DItem ###############" ;
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "Scult3DItem" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    
    Scult3DUpdater updater;
    updater.sc = &sc;
    updater.exec( mp );
    
    qDebug() << "###############   finish Scult3DItem ###############" ;
    
    
    
//    //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     sc.reg_type( "Scult3DItem" );
//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "Scult3DItem" and mp.get_server_id() == model_id ) {
//             quint64 model_stop_state = mp[ "_stop_state" ];  
//             if( model_stop_state == true ){
//                 qDebug() << "###############   finish Scult3DItem ###############" ;
//                 break;
//             }else{
//                 qDebug() << "###############   launch Scult3DItem ###############" ;
//                 Scult3DUpdater updater;
//                 updater.sc = &sc;
//                 updater.exec( mp );
//             }
//         }
//     }
}

