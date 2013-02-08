#ifndef SERVERASSISTEDVISUALIZATIONUPDATER_H
#define SERVERASSISTEDVISUALIZATIONUPDATER_H

#include <Soca/MP.h>
class SodaClient;


/**
*/
class ServerAssistedVisualizationUpdater {
public:
    void exec( MP mp );
    SodaClient *sc;
};

#endif // SERVERASSISTEDVISUALIZATIONUPDATER_H
