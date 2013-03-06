#include <Soca/Com/SodaClient.h>
#include "GmshUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
  
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "GmshItem" );
    MP mp = sc.load_ptr(model_id);
    qDebug() << "###############   launch GmshItem ###############" ;
    GmshUpdater updater;
    updater.sc = &sc;
    updater.exec( mp );
    qDebug() << "###############   finish stand alone GmshItem ###############" ;
    
    
//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "GmshItem" and mp.get_server_id() == model_id ) {
//             quint64 model_stop_state = mp[ "_stop_state" ];  
//             qDebug() << mp[ "_ready_state" ]       ;
//             qDebug() << mp[ "_computation_state" ] ;
//             qDebug() << mp[ "_pending_state" ]     ;
//             qDebug() << mp[ "_processing_state" ]  ;
//             qDebug() << mp[ "_finish_state" ]      ;
//             qDebug() << mp[ "_stop_state" ]        ;
//             qDebug() << mp[ "_computation_mode" ]  ; 
//             
//             
//             if( model_stop_state == true ){
//                 qDebug() << "###############   finish GmshItem ###############" ;
//                 break;
//             }else{
//                 qDebug() << "###############   launch GmshItem ###############" ;
//                 GmshUpdater updater;
//                 //updater.sc = &sc;
//                 updater.exec( mp );
//                 
//                 quint64 model_finish_state = mp[ "_finish_state" ];
//                 // if computation is finished, if not, there is somthing to compute
//                 if(model_finish_state == true){
//                     qDebug() << "###############   finish normal GmshItem ###############" ;
//                     break;
//                 }
//             }
//         }
//     }
}
