#ifndef IMGUPDATER_H
#define IMGUPDATER_H

#include <Soca/MP.h>
class SodaClient;

/**
*/
class ImgUpdater {
public:
    void exec( MP mp );

    SodaClient *sc;
};

#endif // IMGUPDATER_H
