#ifndef CORRELIUPDATER_H
#define CORRELIUPDATER_H

#include <Soca/Updater.h>
class SodaClient;

/**
*/
class CorreliUpdater : public Updater {
public:
    int _ok( const MP &mp ) const;

    virtual bool run( MP mp );
    virtual QString type() const { return "CorreliUpdater"; }

    SodaClient *sc;
};

#endif // CORRELIUPDATER_H
