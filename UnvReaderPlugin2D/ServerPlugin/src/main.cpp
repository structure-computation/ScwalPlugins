#include <Soca/Com/SodaClient.h>
#include "UnvReaderUpdater2D.h"
// #include "UnvReaderUpdater3D.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    //
    sc.reg_type( "UnvReaderItem2D" );
//     sc.reg_type( "UnvReaderItem3D" );

    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        if ( mp.type() == "UnvReaderItem2D" ) {
            UnvReaderUpdater2D mu;
            mu.exec( mp );
        }
//         if ( mp.type() == "UnvReaderItem3D" ) {
//             UnvReaderUpdater_3D mu;
//             mu.exec( mp );
//         }
    }
}
