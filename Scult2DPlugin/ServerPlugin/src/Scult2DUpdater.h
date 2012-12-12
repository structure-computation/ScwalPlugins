#ifndef SCULT2DUPDATER_H
#define SCULT2DUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class Scult2DUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "Scult2DUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // SCULT2DUPDATER_H
