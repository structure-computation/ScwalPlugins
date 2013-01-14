#ifndef MAKEIMGRAWVOLUME_H
#define MAKEIMGRAWVOLUME_H

#include <Soca/MP.h>
class SodaClient;

void _make_img_raw_volume( unsigned char *ptr, float *z, int width, int height, MP mp, MP view_item, double time, SodaClient *sc );

#endif // MAKEIMGRAWVOLUME_H
