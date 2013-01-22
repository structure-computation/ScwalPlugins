#include <Soca/Com/SodaClient.h>
#include "UnvReaderUpdater3D.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "UnvReaderItem3D" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    
    UnvReaderUpdater3D unv_reader;
    unv_reader.sc = &sc;
    unv_reader.exec( mp );
    
    mp[ "_computation_mode" ] = false;
    mp[ "_computation_state" ] = false;
    mp[ "_processing_state" ] = false; 
    mp.flush();
    
    
//     //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     sc.reg_type( "UnvReaderItem3D" );
// 
//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "UnvReaderItem3D" and mp.get_server_id() == model_id ) {
//             UnvReaderUpdater3D mu;
//             mu.sc = &sc;
//             mu.exec( mp );
//             mp[ "_computation_mode" ] = false;
//             mp[ "_computation_state" ] = false;
//             mp[ "_processing_state" ] = false; 
//             mp.flush();
//         }
//     }
}
