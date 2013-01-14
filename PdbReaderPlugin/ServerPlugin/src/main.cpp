#include <Soca/Com/SodaClient.h>
#include "UnvReaderUpdater2D.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    // type d'item observé
    sc.reg_type( "UnvReaderItem2D" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "UnvReaderItem2D" ) {
            UnvReaderUpdater2D mu;
            mu.sc = &sc;
            mu.exec( mp );
        }
    }
}
