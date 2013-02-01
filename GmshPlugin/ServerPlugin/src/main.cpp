#include <Soca/Com/SodaClient.h>
#include "GmshUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
  
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "GmshItem" );
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "GmshItem" and mp.get_server_id() == model_id ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            if( model_stop_state == true ){
                qDebug() << "###############   finish GmshItem ###############" ;
                break;
            }else{
                qDebug() << "###############   launch GmshItem ###############" ;
                GmshUpdater updater;
                //updater.sc = &sc;
                updater.exec( mp );
//                 mp[ "_ready_state" ]        = false;
//                 mp[ "_computation_state" ]  = false;
//                 mp[ "_pending_state" ]      = false;
//                 mp[ "_processing_state" ]   = false;
//                 mp[ "_finish_state" ]       = true;
//                 mp[ "_stop_state" ]         = false;
//                 mp[ "_computation_mode" ] = false; 
//                 mp.flush();
            }
        }
    }
}
