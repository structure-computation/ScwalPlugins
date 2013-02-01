#include <Soca/Com/SodaClient.h>
#include "CorreliUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "CorrelationItem" );
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "CorrelationItem" and mp.get_server_id() == model_id ) {
            quint64 model_stop_state = mp[ "_stop_state" ];  
            if( model_stop_state == true ){
                qDebug() << "###############   finish CorrelationItem ###############" ;
                break;
            }else{
                qDebug() << "###############   launch CorrelationItem ###############" ;
                CorreliUpdater updater;
                //updater.sc = &sc;
                updater.exec( mp );
            }
        }
    }
    
    

//     // attente
//     while ( SodaClient::Event event = sc.event() ) {
//         MP mp = event.mp();
//         if ( mp.type() == "CorrelationItem" ) {
//             CorreliUpdater cu;
//             cu.sc = &sc;
//             cu.exec( mp );
//         } else if ( mp.type() == "ServerAssistedVisualization" ) {
//             ServerAssistedVisualizationUpdater mu;
//             mu.sc = &sc;
//             mu.exec( mp );
//         } else if ( mp.type() == "MesherItem" ) {
//             MeshUpdater mu;
//             mu.exec( mp );
//         } else if ( mp.type() == "File" ) {
//             FileUpdater fu;
//             fu.sc = &sc;
//             fu.exec( mp );
//         } else if ( mp.type() == "Img" ) {
//             ImgUpdater iu;
//             iu.sc = &sc;
//             iu.exec( mp );
//         }
//     }
}
