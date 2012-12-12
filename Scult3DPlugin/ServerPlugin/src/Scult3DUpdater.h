#ifndef SCULT3DUPDATER_H
#define SCULT3DUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class Scult3DUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "Scult2DUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // SCULT3DUPDATER_H
