#include <Soca/Com/SodaClient.h>
#include "TestUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
    sc.reg_type( "TestAllItem" );
    
    //id du model à traiter
//     quint64 model_id = atoi(argv[1]);   
//     
//     MP mp = sc.load_ptr(model_id);
//     qDebug() << "###############   launch TestItem ###############" ;
//     TestUpdater updater;
//     updater.sc = &sc;
//     updater.exec( mp );
//     qDebug() << "###############   finish stand alone TestItem ###############" ;
    
    
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "TestAllItem" ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            qDebug() << mp[ "_ready_state" ]       ;
            qDebug() << mp[ "_computation_state" ] ;
            qDebug() << mp[ "_pending_state" ]     ;
            qDebug() << mp[ "_processing_state" ]  ;
            qDebug() << mp[ "_finish_state" ]      ;
            qDebug() << mp[ "_stop_state" ]        ;
            qDebug() << mp[ "_computation_mode" ]  ; 
            
            
            if( model_stop_state == true ){
                mp[ "_stop_state" ]         = false;
                mp[ "_finish_state" ]       = false;
                qDebug() << "###############   stop TestAllItem ###############" ;
                break;
            }else{
                qDebug() << "###############   launch TestAllItem ###############" ;
                TestUpdater updater;
                updater.sc = &sc;
                updater.exec( mp );
                
                quint64 model_finish_state = mp[ "_finish_state" ];
                // if computation is finished, if not, there is somthing to compute
//                 if(model_finish_state == true){
//                     qDebug() << "###############   finish normal TestAllItem ###############" ;
//                     break;
//                 }
            }
        }
    }
}
