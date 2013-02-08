#ifndef FILEUPDATER_H
#define FILEUPDATER_H

#include <Soca/MP.h>
class SodaClient;

/**
*/
class FileUpdater {
public:
    void exec( MP mp );

    SodaClient *sc;
};

#endif // FILEUPDATER_H
