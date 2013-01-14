#include <Soca/Com/SodaClient.h>
#include "ServerAssistedVisualizationUpdater.h"
#include "CorreliUpdater.h"
#include "MeshUpdater.h"
#include "FileUpdater.h"
#include "ImgUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    sc.reg_type( "ServerAssistedVisualization" );
    sc.reg_type( "CorrelationItem" );
    sc.reg_type( "MesherItem" );
    sc.reg_type( "File" );
    sc.reg_type( "Img" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "CorrelationItem" ) {
            CorreliUpdater cu;
            cu.sc = &sc;
            cu.exec( mp );
        } else if ( mp.type() == "ServerAssistedVisualization" ) {
            ServerAssistedVisualizationUpdater mu;
            mu.sc = &sc;
            mu.exec( mp );
        } else if ( mp.type() == "MesherItem" ) {
            MeshUpdater mu;
            mu.exec( mp );
        } else if ( mp.type() == "File" ) {
            FileUpdater fu;
            fu.sc = &sc;
            fu.exec( mp );
        } else if ( mp.type() == "Img" ) {
            ImgUpdater iu;
            iu.sc = &sc;
            iu.exec( mp );
        }
    }
}