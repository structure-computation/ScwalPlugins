#include <Soca/Com/SodaClient.h>
#include "Scills3DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    sc.reg_type( "Scills3DItem" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "Scills3DItem" ) {
            Scills3DUpdater scru;
            scru.sc = &sc;
            scru.exec( mp );
        } 
    }
}
