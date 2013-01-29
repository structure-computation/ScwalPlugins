#include <Soca/Com/SodaClient.h>
#include "ServerAssistedVisualizationUpdater.h"
#include "CorreliUpdater.h"
#include "MeshUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);   
    sc.reg_type( "MesherItem" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    

    MeshUpdater updater;
    //updater.sc = &sc;
    updater.exec( mp );
    
    
    //qDebug() << mp;
    
    mp[ "_computation_mode" ] = false;
    mp[ "_computation_state" ] = false;
    mp[ "_processing_state" ] = false; 
    mp.flush();
    SodaClient::Event event = sc.event();
    qDebug() << "flush passé !";
    sleep(5);
    
    

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
