#ifndef APPLICATION_H
#define APPLICATION_H

#include <Soca/Com/ClientLoop.h>

/**
*/
class CorrelationApp : public QObject {
    Q_OBJECT
public:
    CorrelationApp();
    void run();

private slots:
    void new_Correlation_callback( quint64 ptr ); ///< called if new Model create somewhere

private:
    Database db;
    ClientLoop cl;
};

#endif // APPLICATION_H
