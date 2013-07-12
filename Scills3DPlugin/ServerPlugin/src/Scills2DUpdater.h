#ifndef SCILLS2DUPDATER_H
#define SCILLS2DUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class Scills2DUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "Scills3DUpdater"; }
    
public:
    SodaClient *sc;
    int argc;
    char** argv;
};

#endif // SCILLS2DUPDATER_H