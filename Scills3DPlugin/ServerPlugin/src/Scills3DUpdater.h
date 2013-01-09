#ifndef SCILLS3DUPDATER_H
#define SCILLS3DUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class Scills3DUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "Scills3DUpdater"; }
    
public:
    SodaClient *sc;   
};

#endif // SCILLS3DUPDATER_H