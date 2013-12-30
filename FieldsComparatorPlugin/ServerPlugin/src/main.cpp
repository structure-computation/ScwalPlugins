#include <Soca/Com/SodaClient.h>
#include "FieldsComparatorUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    
    qDebug() << "###############   launch FieldsComparatorItem ###############" ;
    //id du model à traiter
    quint64 model_id = atoi(argv[1]);
    sc.reg_type( "FieldsComparatorItem" );
    //chargement du model
    MP mp = sc.load_ptr(model_id);
    qDebug() << "model_id : " << model_id;
    
    FieldsComparatorUpdater updater;
    updater.sc = &sc;
    updater.exec( mp );
    
    qDebug() << "###############   finish FieldsComparatorItem ###############" ;
}

