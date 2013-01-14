#include "CorrelationApp.h"

CorrelationApp::CorrelationApp() : cl( &db, QHostAddress::Any, 8890 ) {
    cl.reg_type_for_callback( "DiscretizationItem", this, SLOT(new_Correlation_callback(quint64)) );
}

void CorrelationApp::run() {
    QEventLoop qe;
    qe.exec();
}

void CorrelationApp::new_Correlation_callback( quint64 ptr ) {
    qDebug() << "new ->" << ptr;
    //Model *m = cl.load_ptr_async( ptr );
    Model *m = cl.load_async( "/" );
    qDebug() << m->type();
    qDebug() << m;
}


