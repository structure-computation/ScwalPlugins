#ifndef MESHUPDATER_H
#define MESHUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;

/**
*/
class StepReaderUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "StepReaderUpdater"; }
    
public:
    SodaClient *sc;
    const char*& geo();
};

#endif // MESHUPDATER_H
