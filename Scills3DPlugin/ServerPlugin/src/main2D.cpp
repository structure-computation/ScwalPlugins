#include <Soca/Com/SodaClient.h>
#include "Scills2DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "Scills2DItem" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    
    Scills2DUpdater updater;
    updater.sc = &sc;
    updater.exec( mp );
    
    mp[ "_computation_mode" ] = false;
    mp[ "_computation_state" ] = false;
    mp[ "_processing_state" ] = false; 
    mp.flush();
    
    
//     //
//     sc.reg_type( "Scills3DItem" );
// 
//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "Scills3DItem" ) {
//             Scills3DUpdater scru;
//             scru.sc = &sc;
//             scru.exec( mp );
//         } 
//     }
}
