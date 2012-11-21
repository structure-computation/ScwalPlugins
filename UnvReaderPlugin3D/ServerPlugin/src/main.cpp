#include <Soca/Com/SodaClient.h>
#include "UnvReaderUpdater3D.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    sc.reg_type( "UnvReaderItem3D" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "UnvReaderItem3D" ) {
            UnvReaderUpdater3D mu;
            mu.sc = &sc;
            mu.exec( mp );
        }
    }
}
