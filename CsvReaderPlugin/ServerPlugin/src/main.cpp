#include <Soca/Com/SodaClient.h>
#include "CsvReaderUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
    
    
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "CsvReaderItem" );
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "CsvReaderItem" and mp.get_server_id() == model_id ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            if( model_stop_state == true ){
                qDebug() << "###############   finish CsvReaderItem   ###############" ;
                break;
            }else{
                qDebug() << "###############   launch CsvReaderItem   ###############" ;
                CsvReaderUpdater updater;
                updater.sc = &sc;
                updater.exec( mp );
            }
        }
    }
}
