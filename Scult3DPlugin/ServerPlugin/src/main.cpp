#include <Soca/Com/SodaClient.h>
#include "Scult3DUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    sc.reg_type( "Scult3DItem" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        //qDebug() << mp.type();
        if ( mp.type() == "Scult3DItem" ) {
            Scult3DUpdater mu;
            //qDebug() << mp.type();
            mu.sc = &sc;
            mu.exec( mp );
        }
    }
}
