#include <Soca/Com/SodaClient.h>
#include "MakeImgRawVolume.h"
#include <containers/vec.h>
#include <fstream>
#include <limits>
#include <cmath>
using namespace LMT;
typedef double T;
typedef Vec<T,3> Pvec;

struct CamData {
    CamData( MP cam ) {
        O = Pvec( cam[ "O[0]" ], cam[ "O[1]" ], cam[ "O[2]" ] );
        X = Pvec( cam[ "X[0]" ], cam[ "X[1]" ], cam[ "X[2]" ] );
        Y = Pvec( cam[ "Y[0]" ], cam[ "Y[1]" ], cam[ "Y[2]" ] );
        d = cam[ "d" ];
        a = cam[ "a.val" ];
    }
    Pvec O, X, Y;
    double d, a;
};

struct TransEye {
    TransEye( MP cam, double w, double h ) {
        double mwh = std::min( w, h );

        CamData d( cam );
        double c = d.d / mwh;
        double r = 1; // d.r or 1;

        X = normalized( d.X );
        Y = normalized( d.Y - dot( X, d.Y ) * X );
        Z = vect_prod( X, Y );

        X *= c * r;
        Y *= - c;
        Z *= c;

        double ap = tan( d.a / 2 * 3.14159265358979323846 / 180 );
        p = 2 * ap / mwh;
        O = d.O;
        o_x = - w / 2;
        o_y = - h / 2;
    }

    Pvec dir( int x, int y ) {
        return normalized( ( ( x + o_x ) * X + ( y + o_y ) * Y ) * p + Z );
    }

    Pvec pos( int x, int y, int z = 0 ) {
        return O + ( x + o_x ) * X + ( y + o_y ) * Y + z * Z;
    }

    Pvec X, Y, Z, O;
    double p, o_x, o_y;
};

struct Volume {
    void get_inter( Pvec &rd, double &min_dist, double &max_dist, Pvec p, Pvec d, Pvec n, Pvec o ) const {
        if ( double c = dot( d, n ) ) {
            double lp = dot( o - p, n );
            double di = lp / c;
            Pvec inter = p + di * d;
            if ( inter[ 0 ] >= -1e-6    and inter[ 1 ] >= -1e-6    and inter[ 2 ] >= -1e-6 and
                 inter[ 0 ] < size[ 0 ] and inter[ 1 ] < size[ 1 ] and inter[ 2 ] < size[ 2 ] ) {
                if ( di < min_dist )
                    rd = n;
                min_dist = min( min_dist, di );
                max_dist = max( max_dist, di );
            }
        }
    }

    unsigned char val( Vec<int,3> p ) const {
        int ind = p[ 0 ] + p[ 1 ] * size[ 0 ] + p[ 2 ] * size[ 0 ] * size[ 1 ];
        return ind < data.size() ? data[ ind ] : 0;
    }

    void update_pix( unsigned char *p, float *z, Pvec pos, Pvec dir, double min_val, double max_val ) const {
        double min_dist = +std::numeric_limits<double>::max();
        double max_dist = -std::numeric_limits<double>::max();
        Pvec rd;
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( -1, 0, 0 ), Pvec(             0, 0, 0 ) );
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( +1, 0, 0 ), Pvec( size[ 0 ] - 1, 0, 0 ) );
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( 0, -1, 0 ), Pvec( 0,             0, 0 ) );
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( 0, +1, 0 ), Pvec( 0, size[ 1 ] - 1, 0 ) );
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( 0, 0, -1 ), Pvec( 0, 0,             0 ) );
        get_inter( rd, min_dist, max_dist, pos, dir, Pvec( 0, 0, +1 ), Pvec( 0, 0, size[ 2 ] - 1 ) );

        if ( min_dist != std::numeric_limits<double>::max() ) {
            for( double step = 0.5 / max( abs( dir ) ); min_dist <= max_dist; min_dist += step ) {
                Pvec inter = pos + min_dist * dir;
                Vec<int,3> o = inter + 1e-6;
                T g = val( o );
                if ( g >= min_val and g <= max_val ) {
                    double n;
                    if ( all( o > 0 ) and all( o + 1 < size ) ) {
                        Pvec gr;
                        gr[ 0 ] = val( o + Vec<int,3>( 1, 0, 0 ) ) - val( o - Vec<int,3>( 1, 0, 0 ) );
                        gr[ 1 ] = val( o + Vec<int,3>( 0, 1, 0 ) ) - val( o - Vec<int,3>( 0, 1, 0 ) );
                        gr[ 2 ] = val( o + Vec<int,3>( 0, 0, 1 ) ) - val( o - Vec<int,3>( 0, 0, 1 ) );
                        n = abs( dot( normalized( gr ), dir ) );
                    } else
                        n = abs( dot( rd, dir ) );
                    g = 255 * ( g - min_val ) / ( max_val - min_val ) * ( 0.1 + 0.9 * n );
                    p[ 0 ] = g;
                    p[ 1 ] = g;
                    p[ 2 ] = g;
                    p[ 3 ] = 255;
                    break;
                }
            }
        }
    }

    Pvec size;
    QString filename;
    Vec<unsigned char> data;
};

struct LoadedVolumes {
    LoadedVolumes( SodaClient *sc ) : sc( sc ) {
    }
    Volume *operator()( MP raw_volume, double time ) {
        Pvec size( raw_volume[ "img_size[0]" ], raw_volume[ "img_size[1]" ], raw_volume[ "img_size[2]" ] );
        if ( time >= 0 and int( time ) < raw_volume[ "_children" ].size() )
            return operator()( raw_volume[ "_children" ][ int( time ) ], size );
        return operator()( raw_volume[ "_children" ][ raw_volume[ "_children" ].size() - 1 ], size );
    }
    Volume *operator()( MP volume, Pvec size ) {
        MP data = sc->load_ptr( volume[ "_ptr" ] );
        QString filename = data;

        for( int i = 0; i < volumes.size(); ++i ) {
            if ( volumes[ i ]->filename == filename ) {
                if ( volumes[ i ]->size != size ) {
                    delete volumes[ i ];
                    volumes.erase_elem_nb( i-- );
                    continue;
                }
                volumes[ i ]->size = size;
                return volumes[ i ];
            }
        }

        Volume *res = new Volume;
        res->size = size;
        res->filename = filename;
        res->data.resize( product( size ), 0 );

        std::ifstream f( filename.toAscii().data() );
        f.read( (char *)res->data.ptr(), res->data.size() );

        volumes << res;
        return res;
    }
    Vec<Volume *> volumes;
    SodaClient *sc;
};


void _make_img_raw_volume( unsigned char *ptr, float *z, int w, int h, MP mp, MP view_item, double time, SodaClient *sc ) {
    if ( not mp[ "_children" ].size() )
        return;

    TransEye t( view_item[ "cam" ], w, h );
    double min_val = mp[ "min_val.val" ];
    double max_val = mp[ "max_val.val" ];

    static LoadedVolumes loaded_volumes( sc );
    Volume *v = loaded_volumes( mp, time );

    for( int y = 0, o = 0; y < h; ++y ) {
        for( int x = 0; x < w; ++x, ++o ) {
            unsigned char *p = ptr + 4 * o;
            p[ 0 ] = 0;
            p[ 1 ] = 0;
            p[ 2 ] = 0;
            p[ 3 ] = 0;

            v->update_pix( p, z + o, t.pos( x, y ), t.dir( x, y ), min_val, max_val );
        }
    }

}
