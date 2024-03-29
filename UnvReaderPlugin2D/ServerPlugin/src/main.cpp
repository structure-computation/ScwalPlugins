#include <Soca/Com/SodaClient.h>
#include "UnvReaderUpdater2D.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
    
    qDebug() << "###############   launch UnvReaderItem2D ###############" ;
//     //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "UnvReaderItem2D" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    
    UnvReaderUpdater2D unv_reader;
    unv_reader.sc = &sc;
    unv_reader.exec( mp );
    qDebug() << "###############   finish UnvReaderItem2D ###############" ;

    
//     //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     sc.reg_type( "UnvReaderItem2D" );
//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "UnvReaderItem2D" and mp.get_server_id() == model_id ) {
//             quint64 model_stop_state = mp[ "_stop_state" ];  
//             if( model_stop_state == true ){
//                 qDebug() << "###############   finish UnvReaderItem2D ###############" ;
//                 break;
//             }else{
//                 qDebug() << "###############   launch UnvReaderItem2D ###############" ;
//                 UnvReaderUpdater2D updater;
//                 updater.sc = &sc;
//                 updater.exec( mp );
//             }
//         }
//     }
}


