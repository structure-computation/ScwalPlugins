#ifndef SCILLSRASULTUPDATER_H
#define SCILLSRASULTUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class UnvReaderUpdater3D : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "UnvReaderUpdater"; }
    
public:
    SodaClient *sc;  
};

#endif // SCILLSRASULTUPDATER_H
