#ifndef LMT_IMG_INTERP_H
#define LMT_IMG_INTERP_H

#ifdef METIL_COMP_DIRECTIVE
#pragma fra_name QtGui
#pragma fra_name QtCore
#pragma cpp_path /usr/include/qt4
#pragma inc_path /usr/include/qt4
#pragma cpp_path /opt/local/libexec/qt4-mac/include
#pragma inc_path /opt/local/libexec/qt4-mac/include
#endif

#include <containers/mat.h>
#include <QtGui/QImage>
#include <assert.h>
#include <fstream>
#include <sstream>
#include <util/rectilinear_iterator.h>

#ifndef DONT_WANT_TIFF
#include <tiffio.h>
#endif // DONT_WANT_TIFF

#ifdef METIL_COMP_DIRECTIVE
#ifndef DONT_WANT_TIFF
#pragma lib_name tiff
#endif // DONT_WANT_TIFF
#endif

namespace LMT {

/*! kernel exemple for ImgInterp */
struct ImgInterpBilinearKernel {
    static std::string name() { return "ImgInterpBilinearKernel"; }

    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return f.tex_int( xi + 0, yi + 0 ) * T( 1 - xf ) * T( 1 - yf ) +
               f.tex_int( xi + 1, yi + 0 ) * T( 0 + xf ) * T( 1 - yf ) +
               f.tex_int( xi + 0, yi + 1 ) * T( 1 - xf ) * T( 0 + yf ) +
               f.tex_int( xi + 1, yi + 1 ) * T( 0 + xf ) * T( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        int xi = int( x );
        int yi = int( y );
        int zi = int( z );
        PT xf = x - xi;
        PT yf = y - yi;
        PT zf = z - zi;
        return f.tex_int( xi + 0, yi + 0, zi + 0 ) * T( 1 - xf ) * T( 1 - yf ) * T( 1 - zf ) +
               f.tex_int( xi + 1, yi + 0, zi + 0 ) * T( 0 + xf ) * T( 1 - yf ) * T( 1 - zf ) +
               f.tex_int( xi + 0, yi + 1, zi + 0 ) * T( 1 - xf ) * T( 0 + yf ) * T( 1 - zf ) +
               f.tex_int( xi + 1, yi + 1, zi + 0 ) * T( 0 + xf ) * T( 0 + yf ) * T( 1 - zf ) +
               f.tex_int( xi + 0, yi + 0, zi + 1 ) * T( 1 - xf ) * T( 1 - yf ) * T( 0 + zf ) +
               f.tex_int( xi + 1, yi + 0, zi + 1 ) * T( 0 + xf ) * T( 1 - yf ) * T( 0 + zf ) +
               f.tex_int( xi + 0, yi + 1, zi + 1 ) * T( 1 - xf ) * T( 0 + yf ) * T( 0 + zf ) +
               f.tex_int( xi + 1, yi + 1, zi + 1 ) * T( 0 + xf ) * T( 0 + yf ) * T( 0 + zf );
    }

    //     template<class T,class Img,class PT>
    //     Vec<T,2> grad( StructForType<T>, const Img &f, Vec<PT,2> p ) const {
    //         int xi = int( p[0] );
    //         int yi = int( p[1] );
    //         PT xf = p[0] - xi;
    //         PT yf = p[1] - yi;
    //         return Vec<T,2>(
    //             ( f.tex_int( xi + 1, yi + 0 ) - f.tex_int( xi + 0, yi + 0 ) ) * ( 1 - yf ) +
    //             ( f.tex_int( xi + 1, yi + 1 ) - f.tex_int( xi + 0, yi + 1 ) ) * ( 0 + yf ),
    //             ( f.tex_int( xi + 0, yi + 1 ) - f.tex_int( xi + 0, yi + 0 ) ) * ( 1 - xf ) +
    //             ( f.tex_int( xi + 1, yi + 1 ) - f.tex_int( xi + 1, yi + 0 ) ) * ( 0 + xf )
    //         );
    //     }

    template<class T,class Img,class PT,int dim>
    Vec<T,dim> grad( StructForType<T>, const Img &f, Vec<PT,dim> p ) const {
        Vec<T,dim> res;
        const double d = 1; // 0.05;
        for(int i=0;i<dim;++i)
            //res[ i ] = ( f( Vec<PT,dim>( p + static_dirac_vec<dim>( d, i ) ) ) - f( p ) ) / d;
            res[ i ] = ( f( Vec<PT,dim>( p + static_dirac_vec<dim>( d, i ) ) ) - f( p - static_dirac_vec<dim>( d, i ) ) ) / ( 2 * d );
        return res;
    }
};

/*! kernel exemple for ImgInterp */
struct ImgInterpOrder3_Kernel {
    static std::string name() { return "ImgInterpOrder3_Kernel"; }

    template<class T>
    T interp( T vm, T v0, T v1, T v2, T xf ) const {
        return
            vm * ( 0 - xf ) * ( 1 - xf ) * ( 2 - xf ) / 6 +
            v0 * ( 1 + xf ) * ( 1 - xf ) * ( 2 - xf ) / 2 +
            v1 * ( 1 + xf ) * ( 0 + xf ) * ( 2 - xf ) / 2 +
            v2 * ( 1 + xf ) * ( 0 + xf ) * ( xf - 1 ) / 6;
    }

    /*
        vm := symbol("vm")
        v0 := symbol("v0")
        v1 := symbol("v1")
        v2 := symbol("v2")
        xf := symbol("xf")

        d := vm * ( xf * ( 1 - xf ) - ( 2 - xf ) * ( 1 - 2 * xf ) ) / 6 +
                    v0 * ( - ( 1 - xf ) * ( 1 + xf ) - 2 * xf * ( 2 - xf ) ) / 2 +
                    v1 * ( ( 2 - xf ) * ( 1 + 2 * xf ) - xf * ( 1 + xf ) ) / 2 +
                    v2 * ( xf * ( 1 + xf ) + ( xf - 1 ) * ( 1 + 2 * xf ) ) / 6
    */
    template<class T>
    T grad( T vm, T v0, T v1, T v2, T xf ) const {
        return
            vm * ( xf * ( 1 - xf ) - ( 2 - xf ) * ( 1 - 2 * xf ) ) / 6 +
            v0 * ( - ( 1 - xf ) * ( 1 + xf ) - 2 * xf * ( 2 - xf ) ) / 2 +
            v1 * ( ( 2 - xf ) * ( 1 + 2 * xf ) - xf * ( 1 + xf ) ) / 2 +
            v2 * ( xf * ( 1 + xf ) + ( xf - 1 ) * ( 1 + 2 * xf ) ) / 6;
    }

    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return interp(
            interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 2, yi - 1 ), xf ),
            interp( f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 2, yi + 0 ), xf ),
            interp( f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 2, yi + 1 ), xf ),
            interp( f.tex_int( xi - 1, yi + 2 ), f.tex_int( xi + 0, yi + 2 ), f.tex_int( xi + 1, yi + 2 ), f.tex_int( xi + 2, yi + 2 ), xf ),
            yf
        );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        int xi = int( x );
        int yi = int( y );
        int zi = int( z );
        PT xf = x - xi;
        PT yf = y - yi;
        PT zf = z - zi;
        return interp(
                   interp(
                        interp( f.tex_int( xi - 1, yi - 1, zi - 1 ), f.tex_int( xi + 0, yi - 1, zi - 1 ), f.tex_int( xi + 1, yi - 1, zi - 1 ), f.tex_int( xi + 2, yi - 1, zi - 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 0, zi - 1 ), f.tex_int( xi + 0, yi + 0, zi - 1 ), f.tex_int( xi + 1, yi + 0, zi - 1 ), f.tex_int( xi + 2, yi + 0, zi - 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 1, zi - 1 ), f.tex_int( xi + 0, yi + 1, zi - 1 ), f.tex_int( xi + 1, yi + 1, zi - 1 ), f.tex_int( xi + 2, yi + 1, zi - 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 2, zi - 1 ), f.tex_int( xi + 0, yi + 2, zi - 1 ), f.tex_int( xi + 1, yi + 2, zi - 1 ), f.tex_int( xi + 2, yi + 2, zi - 1 ), xf ),
                        yf
                   ),
                   interp(
                        interp( f.tex_int( xi - 1, yi - 1, zi - 0 ), f.tex_int( xi + 0, yi - 1, zi - 0 ), f.tex_int( xi + 1, yi - 1, zi - 0 ), f.tex_int( xi + 2, yi - 1, zi - 0 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 0, zi - 0 ), f.tex_int( xi + 0, yi + 0, zi - 0 ), f.tex_int( xi + 1, yi + 0, zi - 0 ), f.tex_int( xi + 2, yi + 0, zi - 0 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 1, zi - 0 ), f.tex_int( xi + 0, yi + 1, zi - 0 ), f.tex_int( xi + 1, yi + 1, zi - 0 ), f.tex_int( xi + 2, yi + 1, zi - 0 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 2, zi - 0 ), f.tex_int( xi + 0, yi + 2, zi - 0 ), f.tex_int( xi + 1, yi + 2, zi - 0 ), f.tex_int( xi + 2, yi + 2, zi - 0 ), xf ),
                        yf
                   ),
                   interp(
                        interp( f.tex_int( xi - 1, yi - 1, zi + 1 ), f.tex_int( xi + 0, yi - 1, zi + 1 ), f.tex_int( xi + 1, yi - 1, zi + 1 ), f.tex_int( xi + 2, yi - 1, zi + 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 0, zi + 1 ), f.tex_int( xi + 0, yi + 0, zi + 1 ), f.tex_int( xi + 1, yi + 0, zi + 1 ), f.tex_int( xi + 2, yi + 0, zi + 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 1, zi + 1 ), f.tex_int( xi + 0, yi + 1, zi + 1 ), f.tex_int( xi + 1, yi + 1, zi + 1 ), f.tex_int( xi + 2, yi + 1, zi + 1 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 2, zi + 1 ), f.tex_int( xi + 0, yi + 2, zi + 1 ), f.tex_int( xi + 1, yi + 2, zi + 1 ), f.tex_int( xi + 2, yi + 2, zi + 1 ), xf ),
                        yf
                   ),
                   interp(
                        interp( f.tex_int( xi - 1, yi - 1, zi + 2 ), f.tex_int( xi + 0, yi - 1, zi + 2 ), f.tex_int( xi + 1, yi - 1, zi + 2 ), f.tex_int( xi + 2, yi - 1, zi + 2 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 0, zi + 2 ), f.tex_int( xi + 0, yi + 0, zi + 2 ), f.tex_int( xi + 1, yi + 0, zi + 2 ), f.tex_int( xi + 2, yi + 0, zi + 2 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 1, zi + 2 ), f.tex_int( xi + 0, yi + 1, zi + 2 ), f.tex_int( xi + 1, yi + 1, zi + 2 ), f.tex_int( xi + 2, yi + 1, zi + 2 ), xf ),
                        interp( f.tex_int( xi - 1, yi + 2, zi + 2 ), f.tex_int( xi + 0, yi + 2, zi + 2 ), f.tex_int( xi + 1, yi + 2, zi + 2 ), f.tex_int( xi + 2, yi + 2, zi + 2 ), xf ),
                        yf
                   ),
                   zf
               );
    }

    template<class T,class Img,class PT,int dim>
    Vec<T,dim> grad( StructForType<T>, const Img &f, Vec<PT,dim> p ) const {
        Vec<T,dim> res;
        const double d = 0.05;
        for(int i=0;i<dim;++i)
            res[ i ] = ( f( Vec<PT,dim>( p + static_dirac_vec<dim>( d, i ) ) ) - f( p - static_dirac_vec<dim>( d, i ) ) ) / ( 2 * d );
        return res;
        //         int xi = int( p[0] );
        //         int yi = int( p[1] );
        //         PT xf = p[0] - xi;
        //         PT yf = p[1] - yi;
        //         return Vec<T,dim>(
        //             grad(
        //                 interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi - 1, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 0, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 1, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 2, yi - 1 ), f.tex_int( xi + 2, yi + 0 ), f.tex_int( xi + 2, yi + 1 ), f.tex_int( xi + 2, yi + 2 ), yf ),
        //                 xf
        //             ),
        //             grad(
        //                 interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 2, yi - 1 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 2, yi + 0 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 2, yi + 1 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 2 ), f.tex_int( xi + 0, yi + 2 ), f.tex_int( xi + 1, yi + 2 ), f.tex_int( xi + 2, yi + 2 ), xf ),
        //                 yf
        //             )
        //         );
    }
};

/*! kernel exemple for ImgInterp */
struct ImgInterpIntegralKernel {
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return f.tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) +
               f.tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) +
               f.tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) +
               f.tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        assert( 0 /*TODO*/ );
        return 0;
    }
};

/*! kernel exemple for ImgInterp */
template<unsigned nb_div>
struct ImgInterpDivKernel {
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        int xfi = int( xf * 20 );
        int yfi = int( yf * 20 );
        PT xff = xf * 20 - xfi;
        PT yff = yf * 20 - yfi;
        return f.tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) +
               f.tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) +
               f.tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) +
               f.tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        assert( 0 /*TODO*/ );
        return 0;
    }
    Vec<double,nb_div> interp;
};


/*!
    \a ImgInterp est un type qui représente une fonction définie sur une partie du réseau carré/cubique unitaire.
    Plus précisément soit S le réseau du plan (resp. de l'espace) défini par les points/noeuds de coordonnées s = k1*e1+k2*e2+...+kn*en où (e1,e2,...,en) est la base canonique de IR^n et k1, k2, ..., kn sont des entiers relatifs quelconques et variables. ImgInterp représente une fonction f définie sur une partie de S de la forme {(k1,k2,...,kn), où k1 varie dans [[0..sizes[0]-1]], k2 dans [[0..sizes[1]-1]] etc...}, à valeur dans une ensemble dont les éléments sont du type T_.

    Remarque : f peut être vue comme la restriction d'une fonction g définie sur le pavé [0..sizes[0]-1] x ... x [0..sizes[n-1]-1].
    Remarque : une image peut être vue comme une fonction définie sur une partie de S : la valeur d'un pixel est la valeur en un noeud du réseau.

    Entrées :
        * T_ est le type de retour de la fonction,
        * dim_ est la dimension du réseau ( e.g. 2 pour une image classique (i.e. du plan)),
        * Kernel_ est l'algorithme d'interpolation entre les points du réseau,
        * PT_ est le type scalaire des coordonnées (e.g. si le type des coordonnées est Vec<int,2> alors PT_ = int).
            WARNING : si vous envisager de faire de la multirésoltion, ne prenez pas PT_ = int ou un autre format entier car la méthode pyramidal_filter() ne calculera pas la moyenne des pixels adjacents. Prenez PT_ = double ou float.
*/
template<class T_,unsigned dim_,class Kernel_=ImgInterpBilinearKernel,class PT_=T_>
struct ImgInterp {
    typedef T_ T;
    static const unsigned dim = dim_;
    typedef Kernel_ Kernel;
    typedef PT_ PT;
    typedef ImgInterp T_NewImg;
    typedef Vec<int,dim> PV;

    ///
    ImgInterp() : sizes( 0 ), div_2( NULL ) {}

    ///
    ImgInterp( const std::string &s ) : sizes( 0 ), div_2( NULL ) {
        load( s );
    }
    
    template< class T_2, class Kernel_2, class PT_2 >
    ImgInterp( const ImgInterp< T_2, dim, Kernel_2, PT_2 > & source ) {
        resize( source.sizes );
        data = source.data;    
    }

    ///
    void resize( const Vec<int,dim> s ) {
        sizes = s;
        data.resize( product( s ) );
    }

    ///
    void resize( const Vec<int,dim> s, T_ val ) {
        sizes = s;
        data.resize( product( s ), val );
    }

    ///
    void set( T default_val ) {
        data.set( default_val );
    }

    const char *_dat_format( StructForType<unsigned char > ) { return "UCHAR" ; }
    const char *_dat_format( StructForType<unsigned short> ) { return "USHORT"; }
    const char *_dat_format( StructForType<         float> ) { return "FLOAT" ; }
    const char *_dat_format( StructForType<        double> ) { return "DOUBLE"; }
    
    // write dat file for voreenve
    void write_dat( std::string base_filename ) {
        // .raw
        save_binary( base_filename + ".raw" );
        
        // .dat
        std::ofstream f( ( base_filename + ".dat" ).c_str() );
        f << "ObjectFileName: " << base_filename << ".raw\n";
        f << "Resolution:     " << size() << "\n";
        f << "SliceThickness: 1 1 1\n";
        f << "Format:         " << _dat_format( StructForType<T>() ) << "\n";
        f << "ObjectModel:    I\n";
        f << "Modality:       unknown\n";
    }
    
    /// copie une partie de l'image. Le sommet à gauche en haut est start et la taille est s
    T_NewImg copy( Vec< int, dim> start, Vec< int, dim > s ) {
        T_NewImg res;
        res. resize( s );
        Vec< int, dim > end = start + s;
        if ( dim == 3 ) {
            for(int z=start[2];z<end[2];++z)
                for(int y=start[1];y<end[1];++y)
                    for(int x=start[0];x<end[0];++x)
                        res.tex_int( x - start[0], y - start[1], z - start[2] ) = tex_int( x, y, z );
        } else if ( dim == 2 ) {
            for(int y=start[1];y<end[1];++y)
                for(int x=start[0];x<end[0];++x)
                    res.tex_int( x - start[0], y - start[1] ) = tex_int( x, y );
        }
        return res;
    }

    ///
    ImgInterp &pyramidal_filter() const {
        if ( div_2 )
            return *div_2;
        div_2 = new ImgInterp;
        div_2->resize( sizes / 2 );
        for( Rectilinear_iterator<int,dim> p( 0, Vec<int,dim>(sizes-1), 2 ); p; ++p )
            div_2->tex_int( p.pos / 2 ) = operator()( p.pos + 0.5  );
        return *div_2;
    }

    Vec<int,dim> size() const { return sizes; }

    ///
    void load( const std::string &s ) {
        #ifndef DONT_WANT_TIFF
        if ( s.substr( s.size() - 4 ) == ".tif" )
            load_tiff( s );
        else
        #endif // DONT_WANT_TIFF
            load_qimg( s );
    }

    /// symetry / x axis
    void reverse_y() {
        ImgInterp tmp = *this;
        for( Rectilinear_iterator<int,dim> p( 0, sizes ); p; ++p ) {
            Vec<int,dim> i_pos = p.pos;
            i_pos[ 1 ] = sizes[ 1 ] - 1 - i_pos[ 1 ];
            tex_int( p.pos ) = tmp.tex_int( i_pos );
        }
    }

    ///
    #ifndef DONT_WANT_TIFF
    void load_tiff( const std::string &s ) {
        TIFF *tif = TIFFOpen( s.c_str(), "r" );
        if ( not tif )
            throw "impossible to read " + s + " using libtiff";

        unsigned w, h, bps = 0, spp = 1;
        TIFFGetField( tif, TIFFTAG_IMAGEWIDTH     , &w   );
        TIFFGetField( tif, TIFFTAG_IMAGELENGTH    , &h   );
        TIFFGetField( tif, TIFFTAG_BITSPERSAMPLE  , &bps );
        TIFFGetField( tif, TIFFTAG_SAMPLESPERPIXEL, &spp );

        sizes[ 0 ] = w;
        sizes[ 1 ] = h;
        data.resize( sizes[ 0 ] * sizes[ 1 ] );

        Vec<float> tmp; tmp.resize( sizes[ 0 ], 0 );

        tdata_t buf = _TIFFmalloc( TIFFScanlineSize( tif ) );
        if ( bps == 16 ) {
            for( unsigned y = 0; y < h; ++y ) {
                TIFFReadScanline( tif, buf, y );
                for( unsigned x = 0; x < w; ++x ) {
                    int v = reinterpret_cast<const unsigned short *>( buf )[ spp * x ];
                    data[ w * y + x ] = v;
                }
            }
        } else {
            for( unsigned y = 0; y < h; ++y ) {
                TIFFReadScanline( tif, buf, y );
                for( unsigned x = 0; x < w; ++x )
                    data[ w * y + x ] = reinterpret_cast<const unsigned char *>( buf )[ spp * x ];
            }
        }
        _TIFFfree( buf );

        TIFFClose( tif );
    }
    #endif // DONT_WANT_TIFF

    ///
    void load_qimg( const std::string &s ) {
        //
        QImage img( QString( s.c_str() ) );
        if ( img.depth() == 0 )
            throw "Failed to load img" + s;
        
        // sizes.set( 1 );
        assert( dim >= 2 );
        sizes[ 0 ] = img.width();
        sizes[ 1 ] = img.height();

        data.resize( img.bytesPerLine() * sizes[ 1 ] );
        const uchar *ptr = img.bits();
        if ( img.depth() == 8 ) {
            for( int y = 0; y < sizes[ 1 ]; ++y )
                for( int x = 0; x < sizes[ 0 ]; ++x )
                    data[ y * sizes[ 0 ] + x ] = ptr[ y * img.bytesPerLine() + x ];
        } else if ( img.depth() == 32 ) {
            for( int y = 0; y < sizes[ 1 ]; ++y )
                for( int x = 0; x < sizes[ 0 ]; ++x )
                    data[ y * sizes[ 0 ] + x ] = 0.333333333333333 * ( 
                        ptr[ y * img.bytesPerLine() + 4 * x + 0 ] +
                        ptr[ y * img.bytesPerLine() + 4 * x + 1 ] +
                        ptr[ y * img.bytesPerLine() + 4 * x + 2 ]
                    );
        } else {
            PRINT( sizes );
            PRINT( img.depth() );
            throw "img.depth() not supported " + to_string( img.depth() );
        }
    }
    
    template<class TYPE, class STO, class X>
    void load( Mat< T, TYPE, STO, X > &mat ) {
        sizes.set( 1 );
        assert( dim == 2 );
        sizes[0] = mat.nb_cols();
        sizes[1] = mat.nb_rows();
        data.resize( product( sizes ) );
        unsigned k = 0;
        for(unsigned i=0;i<mat.nb_rows();++i)
            for(unsigned j=0;j<mat.nb_cols();++j) {
                data[ k ] = mat( i, j );
                k++; 
            }
    }

    void corr_endianness( Vec<unsigned short> &tmp, bool big_endian ) {
        if ( not big_endian )
            return;
        for( int i = 0; i < tmp.size(); ++i ) {
            unsigned short val = tmp[ i ];
            tmp[ i ] = ( val << 8 ) | ( val >> 8 );
        }
    }

    template<class TB>
    void corr_endianness( Vec<TB> &tmp, bool big_endian ) {
    }

    template<class TB>
    void load_binary( const std::string &filename, Vec<int,dim> S, Vec<int,dim> X0 = 0, Vec<int,dim> X1 = -1, bool big_endian = true ) {
        assert( dim >= 2 );

        for(unsigned i=0;i<dim;++i)
            if ( X1[i] < 0 )
                X1[i] = S[i];

        sizes = X1 - X0;

        // data in tmp
        data.resize( product( sizes ) );
        std::ifstream f( filename.c_str() );
        Vec<TB> tmp;
        tmp.resize( sizes[0] );
        if ( dim == 2 ) {
            f.seekg( S[0] * X0[1] * sizeof(TB), std::ios::beg );
            for(int y=0,od=0;y<sizes[1];++y) {
                f.seekg( X0[0] * sizeof(TB), std::ios::cur );
                f.read( (char *)tmp.ptr(), sizes[0] * sizeof(TB) );
                corr_endianness( tmp, big_endian );
                for(int x=0;x<sizes[0];++x,++od)
                    data[ od ] = tmp[ x ];
                f.seekg( ( S[0] - X1[0] ) * sizeof(TB), std::ios::cur );
            }
        } else if ( dim == 3 ) {
            f.seekg( S[0] * S[1] * X0[2] * sizeof(TB), std::ios::beg );
            for(int z=0,od=0;z<sizes[2];++z) {
                f.seekg( S[0] * X0[1] * sizeof(TB), std::ios::cur );
                for(int y=0;y<sizes[1];++y) {
                    f.seekg( X0[0] * sizeof(TB), std::ios::cur );
                    f.read( (char *)tmp.ptr(), sizes[0] * sizeof(TB) );
                    corr_endianness( tmp, big_endian );
                    for(int x=0;x<sizes[0];++x,++od)
                        data[ od ] = tmp[ x ];
                    f.seekg( ( S[0] - X1[0] ) * sizeof(TB), std::ios::cur );
                }
                f.seekg( S[0] * ( S[1] - X1[1] ) * sizeof(TB), std::ios::cur );
            }
        } else
            assert( 0 /* TODO */ );
    }

    ///
    QImage to_QImage( bool normalize = false, bool transp_if_neg = true ) const {
        float o = 0.0, m = 1.0;
        int total_size = sizes[0] * sizes[1];
        /// Le type T n'est pas forcément ordonné ni facilement convertible en entier 8 bits (e.g. complex<TT>).
        /// on affiche par défaut sa "norme" (en espérant qu'elle existe).
        Vec<float> v = abs( data );
        if ( normalize ) {
            float mi = transp_if_neg ? min( v + 1e40 * ( data < 0 ) ) : min( v );
            float ma = transp_if_neg ? max( v - 1e40 * ( data < 0 ) ) : max( v );
            o = mi;
            if (ma != mi)
                m = 255 / ( ma - mi );
        }
        QImage img( sizes[0], sizes[1], QImage::Format_ARGB32 );
        uchar *ptr = img.bits();
        for( int i = 0; i < total_size; ++i, ptr += 4 ) {
            ptr[ 0 ] = m * ( v[ i ] - o );
            ptr[ 1 ] = m * ( v[ i ] - o );
            ptr[ 2 ] = m * ( v[ i ] - o );
            ptr[ 3 ] = transp_if_neg ? 255 * ( data[ i ] >= 0 ) : 255;
        }
        return img;
    }

    template<class T2, class Kernel2, class PT2>
    QImage to_QImage( const ImgInterp<T2,dim,Kernel2,PT2>& canal_alpha, bool normalize = false ) const {
        assert((canal_alpha.sizes[0] == sizes[0]) and (canal_alpha.sizes[1] == sizes[1]));
        float o = 0.0, mini = std::numeric_limits<float>::max(), maxi = std::numeric_limits<float>::min(), m = 1.0, t, b;
        int total_size = sizes[0] * sizes[1];
        if ( normalize ) {
            for(int i=0;i<total_size;++i)
                if (canal_alpha.data[ i ] >= 1) {
                    t = abs(data[i]);
                    if (t < mini)
                        mini = t;
                    if (t > maxi)
                        maxi = t;
                }
            o = mini;
            if (maxi != mini)
                m = 255 / ( maxi - mini );
        }

        //
        QImage img( sizes[0], sizes[1], QImage::Format_ARGB32 );
        uchar *ptr = img.bits();
        for(int i=0;i<total_size;++i,ptr+=4) {
            t = abs(data[i]);
            b = (canal_alpha.data[ i ] >= 1) * m * ( t - o );
            ptr[ 0 ] = b;
            ptr[ 1 ] = b;
            ptr[ 2 ] = b;
            ptr[ 3 ] = canal_alpha.data[ i ]*255;
        }
        return img;
    }

    template<class T2, class Kernel2, class PT2>
    T mean( const ImgInterp<T2,dim,Kernel2,PT2>& mask) const {
        assert((mask.sizes[0] == sizes[0]) and (mask.sizes[1] == sizes[1]));
        T sum = 0;
        int total_size = sizes[0] * sizes[1];
        int nb = 0;
        for(int i=0;i<total_size;++i)
            if (mask.data[ i ] >= 1) {
                sum += data[i];
                nb++;
            }
        if (not(nb)) {
            nb++;
            std::cerr << "warning : mask empty" << std::endl;
        }
        sum /= nb;
        return sum ;/// total_size;
    }

    template<class T2, class Kernel2, class PT2>
    T variance( const ImgInterp<T2,dim,Kernel2,PT2>& mask) const {
        assert((mask.sizes[0] == sizes[0]) and (mask.sizes[1] == sizes[1]));
        T sum = 0;
        int nb = 0;
        int total_size = sizes[0] * sizes[1];
        for(int i=0;i<total_size;++i)
            if (mask.data[ i ] >= 1) {
                sum += data[i]*data[i];
                nb++;
            }
        if (not(nb)) {
            nb++;
            std::cerr << "warning : mask empty" << std::endl;
        }
        sum /= nb;
        return sum - pow(mean(mask),2);
    }
    /// matlab compatible
    void load_ascii_mat_file( std::string filename ) {
        using namespace std;

        // sizes
        sizes = 0;
        ifstream f( filename.c_str() );
        string line;
        if ( getline( f, line ) ) {
            istringstream is( line );
            T val;
            while ( is >> val )
                sizes[0]++;
            sizes[1] = 1;
            while ( getline( f, line ) )
                sizes[1]++;
        }

        // data
        data.resize( product( sizes ) );
        f.clear();
        f.seekg( 0, ios::beg );
        for(unsigned i=0;i<data.size();++i)
            f >> data[ i ];
    }

    ///
    ImgInterp<T,dim> simple_blur() {
        ImgInterp<T,dim> res;
        res.resize( sizes - 2 );
        if ( dim == 3 ) {
            for(int z=1;z<sizes[2]-1;++z)
                for(int y=1;y<sizes[1]-1;++y)
                    for(int x=1;x<sizes[0]-1;++x)
                        res.tex_int( x-1, y-1, z-1 ) = ( tex_int( x, y, z ) + tex_int( x+1, y, z ) + tex_int( x-1, y, z ) + tex_int( x, y+1, z ) + tex_int( x, y-1, z ) + tex_int( x, y, z+1 ) + tex_int( x, y, z-1 ) ) / 7.0;
        } else if ( dim == 2 ) {
            for(int y=1;y<sizes[1]-1;++y)
                for(int x=1;x<sizes[0]-1;++x)
                    res.tex_int( x-1, y-1 ) = ( tex_int( x, y ) + tex_int( x+1, y ) + tex_int( x-1, y ) + tex_int( x, y+1 ) + tex_int( x, y-1 ) ) / 5.0;
        }
        return res;
    }

    ///
    void save( const std::string filename, bool normalize = false ) const {
        QImage img = to_QImage( normalize );
        img.save( filename.c_str() );
    }

    ///
    void save_binary( std::string filename ) const {
        std::ofstream f( filename.c_str() );
        f.write( (char *)data.ptr(), sizeof(T) * data.size() );
    }

    ///
    int display( bool normalize = false, const std::string namefile = "pouet.png" ) const {
        save( namefile.c_str(), normalize );
        std::string tmp = "display " + namefile + " &";
        return system( tmp.c_str() );
    }

    /*!
    canal_alpha est une image qui doit contenir les valeurs du niveau alpha (valeurs entre 0 et 1, 1 pour opaque et 0 pour transparent)
    */
    template<class T2, class Kernel2, class PT2>
    void save( const ImgInterp<T2,dim,Kernel2,PT2>& canal_alpha, const std::string filename, bool normalize = false ) const {
        QImage img = to_QImage(canal_alpha, normalize );
        img.save( filename.c_str() );
    }

    /*!
    canal_alpha est une image qui doit contenir les valeurs du niveau alpha (valeurs entre 0 et 1, 1 pour opaque et 0 pour transparent)
     */
    template<class T2, class Kernel2, class PT2>
    int display( const ImgInterp<T,dim,Kernel2,PT2>& canal_alpha, bool normalize = false, const std::string namefile = "pouet.png" ) {
        save( canal_alpha, namefile.c_str(), normalize );
        std::string tmp = "display " + namefile + " &";
        return system( tmp.c_str() );
    }

    /// pour lire ou changer les valeurs par pixel
    inline T &tex_int( int x, int y ) {
        x = max( 0, min( x, sizes[ 0 ] - 1 ) );
        y = max( 0, min( y, sizes[ 1 ] - 1 ) );
        return data[ sizes[ 0 ] * y + x ];
    }

    /// pour lire ou changer les valeurs par pixel
    inline T tex_int( int x, int y ) const {
        x = max( 0, min( x, sizes[ 0 ] - 1 ) );
        y = max( 0, min( y, sizes[ 1 ] - 1 ) );
        return data[ sizes[ 0 ] * y + x ];
    }

    /// pour lire ou changer les valeurs par pixel
    inline T &tex_int( int x, int y, int z ) {
        x = max( 0, min( x, sizes[ 0 ] - 1 ) );
        y = max( 0, min( y, sizes[ 1 ] - 1 ) );
        z = max( 0, min( z, sizes[ 2 ] - 1 ) );
        return data[ sizes[ 1 ] * sizes[ 0 ] * z + sizes[ 0 ] * y + x ];
    }

    /// pour lire ou changer les valeurs par pixel
    inline T tex_int( int x, int y, int z ) const {
        x = max( 0, min( x, sizes[ 0 ] - 1 ) );
        y = max( 0, min( y, sizes[ 1 ] - 1 ) );
        z = max( 0, min( z, sizes[ 2 ] - 1 ) );
        return data[ sizes[ 1 ] * sizes[ 0 ] * z + sizes[ 0 ] * y + x ];
    }

    /// pour lire ou changer les valeurs par pixel
    inline T &tex_int( Vec<int,dim> p ) {
        int o = max( 0, min( p[ 0 ], sizes[ 0 ] - 1 ) );
        for(unsigned i = 1, m = sizes[ 0 ]; i < dim; m *= sizes[i], ++i )
            o += m * max( 0, min( p[ i ], sizes[ i ] - 1 ) );
        return data[ o ];
    }

    /// pour lire ou changer les valeurs par pixel
    inline T tex_int( Vec<int,dim> p ) const {
        int o = max( 0, min( p[ 0 ], sizes[ 0 ] - 1 ) );
        for(unsigned i = 1, m = sizes[0]; i < dim; m *= sizes[i], ++i )
            o += m * max( 0, min( p[ i ], sizes[ i ] - 1 ) );
        return data[ o ];
    }

    /// pour lire ou les valeurs par pixel, valeur eventuellement sub-pixel
    inline T operator()( PT x, PT y ) const {
        return kernel( StructForType<T>(), *this, x, y );
    }

    /// pour lire ou les valeurs par pixel, valeur eventuellement sub-pixel
    inline T operator()( PT x, PT y, PT z ) const {
        return kernel( StructForType<T>(), *this, x, y, z );
    }


    /// pour lire ou les valeurs par pixel, valeur eventuellement sub-pixel
    template<class PTT>
    inline T operator()( Vec<PTT,2> p ) const {
        return operator()( p[0], p[1] );
    }

    ///
    template<class PTT>
    inline T operator()( Vec<PTT,3> p ) const {
        return operator()( p[0], p[1], p[2] );
    }

    ///
    inline Vec<T,dim> grad( Vec<PT,dim> p ) const {
        return kernel.grad( StructForType<T>(), *this, p );
    }

    ///
    //     inline Vec<T,dim> grad( Vec<PT,dim> p, PT dec ) const {
    //         Vec<T,dim> res;
    //         for(int i=0;i<dim;++i)
    //             res[ i ] = ( operator()( Vec<PT,dim>( p + static_dirac_vec<dim>( dec / 2, i ) ) ) - operator()( p - static_dirac_vec<dim>( dec / 2, i ) ) ) / dec;
    //         return res;
    //     }

    ///
    void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {}

    template<class TT, unsigned dime, class K, class PTT, class OP> friend void apply_wi( ImgInterp< TT, dime, K, PTT >& img, OP& op );

    /// perform a "local RMS"
    ImgInterp<T,dim> loc_rms( int size ) const {
        Vec<T> d;
        ImgInterp<T,dim> res;
        res.resize( sizes );
        res.data.set( 0 );
        for( Rectilinear_iterator<int,dim> p( 0, sizes ); p; ++p ) {
            d.resize( 0 );
            for( Rectilinear_iterator<int,dim> o( PV( p.pos - size ), PV( p.pos + size + 1 ) ); o; ++o )
                if ( all( o.pos >= 0 ) and all( o.pos < sizes ) )
                    d << tex_int( o.pos );
            res.tex_int( p.pos ) = d.size() ? standard_deviation( d ) : 0;
        }
        return res;
    }

    ///
    Vec<T> data;
    Vec<int,dim> sizes;
    Kernel kernel;
    mutable ImgInterp<T,dim,Kernel,PT> *div_2;
};


/*! */
template<class T,unsigned dim,class PT=T>
struct ImgInterByBlock {
    typedef long long Int64;
    typedef ImgInterp<T,dim,PT> Img;

    ImgInterByBlock() {
        allowed_memory_size = 2 << 31;
        PRINT( allowed_memory_size );
    }

    void load( const std::string &filename ) {
        int n = 0;
        int m = 0;
        blocks.resize( n, m );
        blocks.set( (Img *)NULL );
    }

    ///
    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {}

    Mat<Img *> blocks;
    Int64 allowed_memory_size;
};

/**
*/
template<class TIMG>
struct ImgInterpDec {
    typedef typename TIMG::T T;
    static const unsigned dim = TIMG::dim;
    typedef typename TIMG::PT PT;
    typedef TIMG T_NewImg;

    ImgInterpDec( TIMG *orig, Vec<PT,dim> offset ) : orig( orig ), offset( offset ) {}

    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {
        orig->load_if_necessary( MI-offset, MA-offset, may_be_modified );
    }

    inline T &tex_int( int x, int y ) { return orig->tex_int( x - offset[0], y - offset[1] ); }
    inline T tex_int( int x, int y ) const { return orig->tex_int( x - offset[0], y - offset[1] ); }
    inline T &tex_int( int x, int y, int z ) { return orig->tex_int( x - offset[0], y - offset[1], z - offset[2] ); }
    inline T tex_int( int x, int y, int z ) const { return orig->tex_int( x - offset[0], y - offset[1], z - offset[2] ); }
    inline T &tex_int( Vec<int,dim> p ) { return orig->tex_int( p - offset ); }
    inline T tex_int( Vec<int,dim> p ) const { return orig->tex_int( p - offset ); }

    inline T operator()( PT x, PT y ) const { return orig->operator()( x - offset[0], y - offset[1] ); }
    inline T operator()( PT x, PT y, PT z ) const { return orig->operator()( x - offset[0], y - offset[1], z - offset[2] ); }
    template<class TV> inline T operator()( TV p ) const { return orig->operator()( p - offset ); }

    inline Vec<T,dim> grad( Vec<PT,dim> p ) const { return orig->grad( p - offset ); }


    TIMG *orig;
    Vec<PT,dim> offset;
};

/**
*/
template<class TIMG>
struct ImgInterpExtr {
    typedef typename TIMG::T T;
    static const unsigned dim = TIMG::dim + 1;
    typedef typename TIMG::PT PT;
    // typedef TIMG T_NewImg;

    ImgInterpExtr( TIMG *orig ) : orig( orig ) {
        div_2 = 0;
    }

    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {
        orig->load_if_necessary( MI[ range(dim-1) ], MA[ range(dim-1) ], may_be_modified );
    }

    inline T &tex_int( int x, int y ) { return orig->tex_int( x ); }
    inline T tex_int( int x, int y ) const { return orig->tex_int( x ); }
    inline T &tex_int( int x, int y, int z ) { return orig->tex_int( x, y ); }
    inline T tex_int( int x, int y, int z ) const { return orig->tex_int( x, y ); }
    inline T &tex_int( Vec<int,dim> p ) { return orig->tex_int( p[ range(dim-1) ] ); }
    inline T tex_int( Vec<int,dim> p ) const { return orig->tex_int( p[ range(dim-1) ] ); }

    inline T operator()( PT x, PT y ) const { return orig->operator()( x ); }
    inline T operator()( PT x, PT y, PT z ) const { return orig->operator()( x, y ); }
    template<class TV> inline T operator()( TV p ) const { return orig->operator()( Vec<PT,dim-1>( p[ range(dim-1) ] ) ); }

    inline Vec<T,dim> grad( Vec<PT,dim> p ) const {
        Vec<T,dim-1> p_grad = orig->grad( p[ range(dim-1) ] );
        Vec<T,dim> res;
        for(unsigned i=0;i<dim-1;++i)
            res[ i ] = p_grad[ i ];
        res[ dim - 1 ] = 0;
        return res;
    }

    ///
    ImgInterpExtr &pyramidal_filter() const {
        if ( div_2 )
            return *div_2;
        div_2 = new ImgInterpExtr( &orig->pyramidal_filter() );
        return *div_2;
    }

    TIMG *orig;
    mutable ImgInterpExtr *div_2;
};

/**
*/
template<class TIMG>
struct ImgInterpList {
    typedef typename TIMG::T T;
    static const unsigned dim = TIMG::dim + 1;
    typedef typename TIMG::PT PT;

    ImgInterpList( int size ) {
        orig.resize( size );
        div_2 = 0;
    }

    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {
        for(int t=MI[dim-1];t<MA[dim-1];++t)
            orig[ t ].load_if_necessary( MI[ range(dim-1) ], MA[ range(dim-1) ], may_be_modified );
    }

    inline int check_t( int v ) const { return max( min( v, (int)orig.size() - 1 ), 0 ); }

    inline T &tex_int( int x, int y ) { return orig[ check_t( y ) ].tex_int( x ); }
    inline T tex_int( int x, int y ) const { return orig[ check_t( y ) ].tex_int( x ); }
    inline T &tex_int( int x, int y, int z ) { return orig[ check_t( z ) ].tex_int( x, y ); }
    inline T tex_int( int x, int y, int z ) const { return orig[ check_t( z ) ].tex_int( x, y ); }
    inline T &tex_int( Vec<int,dim> p ) { return orig[ check_t( p[dim-1] ) ].tex_int( p( range( dim - 1 ) ) ); }
    inline T tex_int( Vec<int,dim> p ) const { return orig[ check_t( p[dim-1] ) ].tex_int( p( range( dim - 1 ) ) ); }

    inline T operator()( PT x, PT y ) const { return orig[ check_t( y ) ].operator()( x ); }
    inline T operator()( PT x, PT y, PT z ) const { return orig[ check_t( z ) ].operator()( x, y ); }
    template<class PTT> inline T operator()( Vec<PTT,dim> p ) const { return orig[ check_t( p[dim-1] ) ].operator()( Vec<PT,dim-1>( p[ range( dim - 1 ) ] ) ); }

    inline Vec<T,dim> grad( Vec<PT,dim> p ) const {
        int t = check_t( p[ dim - 1 ] );
        Vec<T,dim-1> p_grad = orig[t].grad( p[ range( dim - 1 ) ] );
        Vec<T,dim> res;
        for(unsigned i=0;i<dim-1;++i)
            res[ i ] = p_grad[ i ];
        res[ dim - 1 ] = 0;
        return res;
    }

    ///
    ImgInterpList &pyramidal_filter() const {
        if ( div_2 )
            return *div_2;
        div_2 = new ImgInterpList( orig.size() / 2 );
        for(unsigned t=0;t<orig.size()/2;++t)
            div_2->orig[ t ] = orig[ 2 * t ].pyramidal_filter();
        return *div_2;
    }

    Vec<TIMG> orig;
    mutable ImgInterpList *div_2;
};

/*!
    \keyword Traitement_dimages

*/
template<class TT>
ImgInterp<TT,3> img_dist_from_front( const ImgInterp<TT,3> &mat, int max_dist, double diff_pix ) {
    typedef TT T;
    typedef Vec<int,3> P;

    ImgInterp<TT,3> dist;
    dist.resize( mat.sizes );
    dist.set( max_dist );

    Vec<P> front;
    for(int z=1;z<mat.sizes[2];++z) {
        for(int y=1;y<mat.sizes[1];++y) {
            for(int x=1;x<mat.sizes[0];++x) {
                if ( mat.tex_int(x,y,z) >= diff_pix ) {
                    if ( mat.tex_int(x-1,y,z) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x-1,y,z ) = 0.0; }
                    if ( mat.tex_int(x,y-1,z) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y-1,z ) = 0.0; }
                    if ( mat.tex_int(x,y,z-1) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y,z-1 ) = 0.0; }
                } else {
                    if ( mat.tex_int(x-1,y,z) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x-1,y,z ) = 0.0; }
                    if ( mat.tex_int(x,y-1,z) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y-1,z ) = 0.0; }
                    if ( mat.tex_int(x,y,z-1) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y,z-1 ) = 0.0; }
                }
            }
        }
    }

    //
    unsigned of_front = 0;
    while ( of_front < front.size() ) {
        P p = front[ of_front++ ];
        int x = p[0];
        int y = p[1];
        int z = p[2];
        for(int oz=-1;oz<=1;++oz) {
            for(int oy=-1;oy<=1;++oy) {
                for(int ox=-1;ox<=1;++ox) {
                    if ( ox == 0 and oy == 0 and oz == 0 )
                        continue;
                    if ( x+ox >= 0 and y+oy >= 0 and z+oz >= 0 and x+ox < mat.sizes[0] and y+oy < mat.sizes[1] and z+oz < mat.sizes[2] ) {
                        T ndist = dist.tex_int( x, y, z ) + sqrt( ox * ox + oy * oy + oz * oz );
                        if ( ndist < dist.tex_int( x+ox, y+oy, z+oz ) ) {
                            front.push_back( P( x+ox, y+oy, z+oz ) );
                            dist.tex_int( x+ox, y+oy, z+oz ) = ndist;
                        }
                    }
                }
            }
        }
    }

    //
    for(int z=0;z<mat.sizes[2];++z)
        for(int y=0;y<mat.sizes[1];++y)
            for(int x=0;x<mat.sizes[0];++x)
                dist.tex_int( x, y, z ) *= ( mat.tex_int(x,y,z) >= diff_pix ? 1 : -1 );

    return dist;
}


/*!
    \keyword Traitement_dimages

*/
template<class TT>
ImgInterp<TT,2> img_dist_from_front( const ImgInterp<TT,2> &mat, int max_dist, TT diff_pix ) {
    typedef TT T;
    typedef Vec<int,2> P;

    ImgInterp<double,2> dist;
    dist.resize( mat.sizes );
    dist.set( max_dist );

    Vec<P> front;
    for(int y=1;y<mat.sizes[1];++y) {
        for(int x=1;x<mat.sizes[0];++x) {
            if ( mat.tex_int(x,y) >= diff_pix ) {
                if ( mat.tex_int(x-1,y) < diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x-1,y ) = 0.0; }
                if ( mat.tex_int(x,y-1) < diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x,y-1 ) = 0.0; }
            } else {
                if ( mat.tex_int(x-1,y) >= diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x-1,y ) = 0.0; }
                if ( mat.tex_int(x,y-1) >= diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x,y-1 ) = 0.0; }
            }
        }
    }

    //
    unsigned of_front = 0;
    while ( of_front < front.size() ) {
        P p = front[ of_front++ ];
        int x = p[0];
        int y = p[1];
        for(int oy=-1;oy<=1;++oy) {
            for(int ox=-1;ox<=1;++ox) {
                if ( ox == 0 and oy == 0 )
                    continue;
                if ( x+ox >= 0 and y+oy >= 0 and x+ox < mat.sizes[0] and y+oy < mat.sizes[1] ) {
                    T ndist = dist.tex_int( x, y ) + sqrt( ox * ox + oy * oy );
                    if ( ndist < dist.tex_int( x+ox, y+oy ) ) {
                        front.push_back( P( x+ox, y+oy ) );
                        dist.tex_int( x+ox, y+oy ) = ndist;
                    }
                }
            }
        }
    }

    //
    for(int y=0;y<mat.sizes[1];++y)
        for(int x=0;x<mat.sizes[0];++x)
            dist.tex_int( x, y ) *= ( mat.tex_int(x,y) >= diff_pix ? 1 : -1 );

    return dist;
}

template<class T_,unsigned dim_,class Kernel_,class PT_>
ImgInterp<T_,dim_,Kernel_,PT_> abs( const ImgInterp<T_,dim_,Kernel_,PT_> &i) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = abs(i.data);
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_>
ImgInterp<T_,dim_,Kernel_,PT_> arg( const ImgInterp<T_,dim_,Kernel_,PT_> &i) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = arg(i.data);
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_>
ImgInterp<T_,dim_,Kernel_,PT_> conj( const ImgInterp<T_,dim_,Kernel_,PT_> &i) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = conj(i.data);
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_>
ImgInterp<T_,dim_,Kernel_,PT_> operator*( const ImgInterp<T_,dim_,Kernel_,PT_> &i, const ImgInterp<T_,dim_,Kernel_,PT_> &i2) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = i.data * i2.data;
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_, class T2>
ImgInterp<T_,dim_,Kernel_,PT_> operator*( const ImgInterp<T_,dim_,Kernel_,PT_> &i, T2 t) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = t * i.data;
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_, class T2>
ImgInterp<T_,dim_,Kernel_,PT_> operator*( T2 t, const ImgInterp<T_,dim_,Kernel_,PT_> &i ) {
    ImgInterp<T_,dim_,Kernel_,PT_> res;
    res.resize(i.size());
    res.data = t * i.data;
    return res;
}

template<class T_,unsigned dim_,class Kernel_,class PT_, class OP>
void apply_wi( ImgInterp< T_, dim_, Kernel_, PT_ >& img, OP& op ) { assert(0); }

template<class T_,class Kernel_,class PT_, class OP>
void apply_wi( ImgInterp< T_, 2, Kernel_, PT_ >& img, OP& op ) {
    T_* pt = img.data.begin();
    for(int y=0;y<img.sizes[1];++y)
        for(int x=0;x<img.sizes[0];++x)
            op( pt++ , x, y );
}

template<class T_,class Kernel_,class PT_, class OP>
void apply_wi( ImgInterp< T_, 3, Kernel_, PT_ >& img, OP& op ) {
    T_* pt = img.data.begin();
    for(int z=0;z<img.sizes[2];++z)
        for(int y=0;y<img.sizes[1];++y)
            for(int x=0;x<img.sizes[0];++x)
                op( pt++, x, y, z );
}

/*!
  selection par "baguette magique" dans l'image de pixel à partir de start_point.
*/
template<class TI,class TJ,class PV,class I>
void baguette_magique( TI &res, const TJ &img, PV start_point, I max_dist ) {
    res.resize( img.size() );
    res.set( 0 );
    //
    double base_val = img( start_point ), min_val = base_val - max_dist, max_val = base_val + max_dist;
    Vec<PV> front;
    front.push_back( start_point );
    //
    while ( front.size() ) {
        PV p = front[ 0 ];
        front.erase_elem_nb( 0 );
        //
        res.tex_int( p ) = 255;
        for( Rectilinear_iterator<int,TI::dim> iter( PV( p - 1 ), PV( p + 2 ) ); iter; ++iter )
            if ( all( iter.pos >= 0 ) and all( iter.pos < img.size() ) and res( iter.pos ) == 0 and img( iter.pos ) >= min_val and img( iter.pos ) <= max_val )
                front.push_back( iter.pos );
    }
}

/*!
    Objectif:
        Cette simple classe sert à stocker une image et les aires minimales et maximales des triangles d'un maillage pour créer un maillage en fonction des niveaux de gris de l'image. Elle est utilisée avec le logiciel Triangle qui est encapsulé dans la classe Triangle_software. L'image spirale.jpg a été placé dans le répertoire Croix.
        
    Voici un exemple d'utilisation :
    \code C/C++
        #include "mesh/meshcaracstd.h"
        #include "mesh/make_rect.h"
        #include "mesh/displayparaview.h"
        #include "mesh/read_msh_2.h"
        #include "mesh/Triangle_software.h"
        
        #include "correlation/ImgInterp.h"
        
        using namespace std;
        
        int main( int argc, const char* argv[] ) {
            
            typedef Mesh< MeshCaracStd< 2, 2, 1, double, 1  > > TMS; /// Quad dans le plan
            
            typedef Mesh< MeshCaracStd< 2, 2, 0, double, 1  > > TM; /// Triangle dans le plan
            typedef TM::Pvec Pvec;
        
            TMS m_source;
            make_rect( m_source, Quad(), Pvec( 5, 5 ), Pvec( 795, 795 ), Pvec( 2, 2 ) );
        
            ImgInterp_for_mesh imm( "spirale.jpg" );
            imm.set_area_min( 10 );
            imm.set_area_max( 500 );
            
            Triangle_software tri( m_source, Triangle_software::Only_skin_mode );

            TM m;
            tri.get_triangulation( m, "q31", density_ImgInterp, reinterpret_cast<void*>( &imm ) );
            
            display_mesh( m );
            
            return 0;
        }
*/
struct ImgInterp_for_mesh {

    ImgInterp_for_mesh( const char* filename_image ) : area_min( 100 ), area_max( 10000 ), level_area_min( 0 ), level_area_max( 255 ) { 
        set_affine_function();
        image.load( std::string( filename_image ) );
    }
    
    void set_area_min( double a ) {
        area_min = a;
        set_affine_function();
    }

    void set_area_max( double a ) {
        area_max = a;
        set_affine_function();
    }

    void set_level_area_min( double l ) {
        level_area_min = l;
        set_affine_function();
    }

    void set_level_area_max( double l ) {
        level_area_max = l;
        set_affine_function();
    }

    void set_affine_function() {
        m = ( area_max - area_min ) / ( level_area_max - level_area_min );
        p = area_min - m * level_area_min;
    }

    double get_local_area( const Vec<double, 2> &pos ) {
        
        double l = image( pos );
        if ( level_area_min < level_area_max ) {
            if ( l <= level_area_min )
                l = level_area_min;
            else {
                if ( l >= level_area_max )
                    l = level_area_max;
            }
        } else {
            if ( l >= level_area_min )
                l = level_area_min;
            else {
                if ( l <= level_area_max )
                    l = level_area_max;
            }        
        }
        
        return l * m + p;
    }

    ImgInterp<double, 2> image;
    double area_min, area_max, level_area_min, level_area_max, m, p;
};

/*!
    Objectif:
        adapter la taille des triangles en fonction du niveau de gris d'une image au cours de la création d'un maillage avec le logiciel Triangle.
         
        Cette fonction est à utiliser avec la méthode Triangle_software.get_trianglation().
        
    \relates ImgInterp_for_mesh

*/
inline int density_ImgInterp( double *ori, double *dest, double *apex, double area, void* p ) {
    ImgInterp_for_mesh* pimage = reinterpret_cast<ImgInterp_for_mesh*>( p );
    Vec<double, 2> pos;

    pos[ 0 ] = (1./3) * ( ori[ 0 ] + dest[ 0 ] + apex[ 0 ] );
    pos[ 1 ] = (1./3) * ( ori[ 1 ] + dest[ 1 ] + apex[ 1 ] );
    
    if ( area > pimage->get_local_area( pos ) )
        return 1;
    else
        return 0;    
}

}


#endif // LMT_IMG_INTERP_H

