#ifndef IPOLLSDUPDATER_H
#define IPOLLSDUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
//class QDataStream;

/**
*/
class IpolLsdUpdater : public Updater {
protected:
    bool run( MP mp );
    //void make_geo( QTextStream &geo, const MP &ch, double base_size );
    //void make_geo_rec( QMap<Model *,QVector<int> > &elem_corr, QTextStream &geo, const MP &elem, double base_size, const MP &points, int &np, int &ne );
    //inline void _save_img( MP outputImage, const QImage &res );
    virtual QString type() const { return "IpolLsdItem"; }
    
public:
    SodaClient *sc;
};

#endif // IPOLLSDUPDATER_H
