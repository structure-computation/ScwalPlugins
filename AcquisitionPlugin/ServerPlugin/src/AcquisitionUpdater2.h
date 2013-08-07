#ifndef ACQUISITIONUPDATER_H
#define ACQUISITIONUPDATER_H

#include <Soca/Updater.h>
#include <Soca/MP.h>

class SodaClient;

/**
*/
class AcquisitionUpdater : public Updater {
public:

    virtual bool run( MP mp );
    virtual QString type() const { return "AcquisitionUpdater"; }

    SodaClient *sc;
};

#endif // ACQUISITIONUPDATER_H
