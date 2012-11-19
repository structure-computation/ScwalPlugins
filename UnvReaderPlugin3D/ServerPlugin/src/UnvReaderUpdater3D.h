#ifndef SCILLSRASULTUPDATER_H
#define SCILLSRASULTUPDATER_H

#include <Soca/Updater.h>
class QDataStream;


/**
*/
class UnvReaderUpdater3D : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "UnvReaderUpdater"; }
    
};

#endif // SCILLSRASULTUPDATER_H
