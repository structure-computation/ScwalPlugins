#ifndef TESTUPDATER_H
#define TESTUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;

/**
*/
class TestUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "TestUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // TESTUPDATER_H
