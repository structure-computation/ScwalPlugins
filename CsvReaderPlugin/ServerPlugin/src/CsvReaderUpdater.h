#ifndef CSVREADERUPDATER_H
#define CSVREADERUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;

class CsvReaderUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "CsvReaderUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // CSVREADERUPDATER_H
