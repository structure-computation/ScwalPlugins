#ifndef FIELDSCOMPARATORUPDATER_H
#define FIELDSCOMPARATORUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;


/**
*/
class FieldsComparatorUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "FieldsComparatorUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // FIELDSCOMPARATORUPDATER_H
