#ifndef PROBLEM_laplacian
#define PROBLEM_laplacian

#ifndef Mesh_carac_laplacian_HEADER
#define Mesh_carac_laplacian_HEADER
#include "mesh/displayparaview.h"
#include "mesh/tetra.h"
namespace LMT {

template<class TP,unsigned dim> struct Mesh_carac_laplacian {};
#ifndef IFNDEF_dep_DM
#define IFNDEF_dep_DM
    struct dep_DM { static std::string name() { return "dep"; } };
#endif // IFNDEF_dep_DM

#ifndef IFNDEF_is_on_skin_DM
#define IFNDEF_is_on_skin_DM
    struct is_on_skin_DM { static std::string name() { return "is_on_skin"; } };
#endif // IFNDEF_is_on_skin_DM

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM { static std::string name() { return "pos"; } };
#endif // IFNDEF_pos_DM

template<class TP>
struct Mesh_carac_laplacian<TP,3> {
    typedef TP Tpos;
    static const unsigned dim = 3;
    typedef Vec<TP,3> Pvec;
    struct NodalStaticData {
        typedef Vec<Tpos,3> T0;
        typedef Tpos T1;
        NodalStaticData():dep(0.0),is_on_skin(0) {}
        CARACDMEXTNAME( 0, T0, dep, "m" );
        CARACDMEXTNAME( 1, T1, is_on_skin, "" );
        CARACDMEXTNAME( 2, T0, pos, "m" );
        static const unsigned nb_params = 3;
        void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "is_on_skin" ) { is_on_skin = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value, bool disp = true ) {
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos>, bool disp = true ) const {
            if ( field_name == "is_on_skin" ) { return is_on_skin; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> >, bool disp = true ) const {
            if ( field_name == "dep" ) { return dep; }
            if ( field_name == "pos" ) { return pos; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    struct GlobalStaticData {
        GlobalStaticData() {}
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos>, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > >, bool disp = true ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    typedef Node<dim,Tpos,NodalStaticData> TNode;
    typedef ElementAncestor<TNode> EA;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice { typedef void NE; typedef DefaultBehavior BE; typedef VoidDMSet TData; };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> { typedef Tetra NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos>, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,0,inner> { typedef Triangle NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos>, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > >, bool disp = true ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<2,skin,0,inner> { typedef Bar NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
    template<unsigned skin,unsigned inner> struct ElementChoice<3,skin,0,inner> { typedef NodalElement NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
};
} // namespace LMT
#endif // Mesh_carac_laplacian_HEADER

#include "formulation/formulation.h"
namespace LMT {
#ifndef LAPLACIAN_3_NUM_0_CARAC_H
#define LAPLACIAN_3_NUM_0_CARAC_H
#ifndef STRUCT_LAPLACIAN
#define STRUCT_LAPLACIAN
struct laplacian {
  static const char *name() { return "laplacian"; }
};
#endif // LAPLACIAN

template<class P_T>
class CaracFormulation<laplacian,3,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "laplacian"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 4;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 3;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0]; node.dep[2]=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.dep[2]=vecs[0][indice+2]; node.dep[1]=vecs[0][indice+1];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
    vecs[0][indice+2]=node.dep[2]; vecs[1][indice+2]=node.dep[2]; vecs[2][indice+2]=node.dep[2]; vecs[3][indice+2]=node.dep[2]; vecs[4][indice+2]=node.dep[2];
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+1]-vecs[0][indice+1]; T reg1=vecs[1][indice+0]-vecs[0][indice+0]; reg0=abs(reg0); reg1=abs(reg1); T reg2=vecs[1][indice+2]-vecs[0][indice+2];
    reg2=abs(reg2); reg1=max(reg0,reg1); return max(reg2,reg1);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+2]=vecs[1][indice+2]; old_vec[indice+1]=vecs[1][indice+1];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // LAPLACIAN_3_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_laplacian_Tetra_0( double * );
extern "C" void apply_on_elements_after_solve_1_laplacian_Tetra_1( double * );
extern "C" void apply_on_elements_after_solve_2_laplacian_Tetra_2( double * );
extern "C" void apply_on_elements_after_solve_3_laplacian_Tetra_3( double * );
extern "C" void apply_on_elements_after_solve_4_laplacian_Tetra_4( double * );
extern "C" void apply_on_elements_after_solve_5_laplacian_Tetra_5( double * );
extern "C" void apply_on_elements_after_solve_6_laplacian_Tetra_6( double * );
extern "C" void apply_on_elements_after_solve_7_laplacian_Tetra_7( double * );
extern "C" void apply_on_elements_after_solve_8_laplacian_Tetra_8( double * );
extern "C" void apply_on_elements_after_solve_9_laplacian_Tetra_9( double * );
extern "C" void apply_on_elements_after_solve_10_laplacian_Tetra_10( double * );
extern "C" void apply_on_elements_after_solve_11_laplacian_Tetra_11( double * );
extern "C" void apply_on_elements_after_solve_12_laplacian_Tetra_12( double * );
extern "C" void apply_on_elements_after_solve_13_laplacian_Tetra_13( double * );
extern "C" void apply_on_elements_after_solve_14_laplacian_Tetra_14( double * );
class Tetra;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<laplacian,Element<Tetra,DefaultBehavior,Node<3,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 0;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = true;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_7(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_8(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_9(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_10(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_11(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_12(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_13(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_14(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_15(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices ) { 
  #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_laplacian_false_true_true
#define ADD_NODAL_MATRIX_laplacian_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_laplacian_true_true_true
#define ADD_NODAL_MATRIX_laplacian_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_laplacian_false_true_false
#define ADD_NODAL_MATRIX_laplacian_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_laplacian_true_true_false
#define ADD_NODAL_MATRIX_laplacian_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_laplacian_symmetric_version_false_true
#define ADD_NODAL_MATRIX_laplacian_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_laplacian_symmetric_version_false_false
#define ADD_NODAL_MATRIX_laplacian_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_RESIDUAL_laplacian
#define ADD_NODAL_RESIDUAL_laplacian
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE>
void add_nodal_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const typename TM::TNode &node,
      const unsigned *indices ) { 
  #define PNODE(N) node
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=pow(reg2,2); reg3=reg4+reg3; reg5=reg3+reg5; reg5=pow(reg5,0.5); reg3=elem.pos(1)[1]-elem.pos(0)[1];
    reg4=reg0/reg5; T reg6=reg1/reg5; T reg7=elem.pos(1)[0]-elem.pos(0)[0]; T reg8=reg6*reg7; T reg9=elem.pos(1)[2]-elem.pos(0)[2];
    T reg10=reg4*reg3; reg5=reg2/reg5; reg10=reg8+reg10; reg8=reg5*reg9; reg8=reg10+reg8;
    reg10=reg6*reg8; T reg11=reg4*reg8; reg11=reg3-reg11; T reg12=elem.pos(3)[2]-elem.pos(0)[2]; T reg13=reg5*reg8;
    T reg14=elem.pos(3)[1]-elem.pos(0)[1]; reg10=reg7-reg10; T reg15=pow(reg10,2); T reg16=reg0*reg12; T reg17=reg9*reg14;
    T reg18=pow(reg11,2); T reg19=reg3*reg12; T reg20=reg2*reg14; reg13=reg9-reg13; reg20=reg16-reg20;
    reg17=reg19-reg17; reg16=pow(reg13,2); reg18=reg15+reg18; reg15=reg3*reg2; reg19=reg9*reg0;
    reg19=reg15-reg19; reg15=reg7*reg20; reg16=reg18+reg16; reg18=elem.pos(3)[0]-elem.pos(0)[0]; T reg21=reg1*reg17;
    reg16=pow(reg16,0.5); T reg22=reg2*reg18; T reg23=reg7*reg12; T reg24=reg1*reg12; T reg25=reg18*reg19;
    reg21=reg15-reg21; reg15=reg9*reg18; T reg26=reg7*reg14; reg25=reg21+reg25; reg21=reg7*reg2;
    T reg27=reg0*reg18; reg22=reg24-reg22; reg24=reg1*reg14; T reg28=reg3*reg18; reg15=reg23-reg15;
    reg23=reg9*reg1; reg10=reg10/reg16; reg11=reg11/reg16; T reg29=reg7*reg0; T reg30=reg11*reg3;
    T reg31=reg10*reg7; T reg32=reg3*reg1; reg4=reg4*reg0; reg6=reg6*reg1; reg23=reg21-reg23;
    reg16=reg13/reg16; reg28=reg26-reg28; reg10=reg10*reg1; reg11=reg11*reg0; reg20=reg20/reg25;
    reg22=reg22/reg25; reg15=reg15/reg25; reg27=reg24-reg27; reg17=reg17/reg25; reg19=reg19/reg25;
    reg28=reg28/reg25; reg32=reg29-reg32; reg23=reg23/reg25; reg27=reg27/reg25; reg13=reg17-reg20;
    reg21=reg22-reg15; reg4=reg6+reg4; reg5=reg5*reg2; reg6=reg16*reg2; reg30=reg31+reg30;
    reg16=reg16*reg9; reg11=reg10+reg11; reg10=reg15*reg23; reg24=reg17*reg19; reg26=reg28-reg27;
    reg21=reg21+reg23; reg6=reg11+reg6; reg16=reg30+reg16; reg5=reg4+reg5; reg4=reg22*reg15;
    reg11=reg20*reg17; reg13=reg13-reg19; reg25=reg32/reg25; reg29=pow(reg23,2); reg30=reg13*reg19;
    reg31=reg21*reg15; reg32=reg21*reg23; T reg33=pow(reg20,2); T reg34=pow(reg22,2); T reg35=reg13*reg17;
    T reg36=reg21*reg22; T reg37=pow(reg21,2); T reg38=reg13*reg20; T reg39=pow(reg13,2); reg26=reg26-reg25;
    reg6=reg8*reg6; reg16=reg5*reg16; reg5=reg11+reg4; reg8=reg28*reg25; T reg40=reg20*reg19;
    T reg41=reg27*reg28; T reg42=reg22*reg23; T reg43=reg24+reg10; T reg44=pow(reg19,2); T reg45=pow(reg15,2);
    T reg46=pow(reg17,2); T reg47=reg27*reg25; T reg48=reg26*reg27; T reg49=reg43+reg8; T reg50=pow(reg28,2);
    T reg51=pow(reg26,2); reg37=reg39+reg37; reg45=reg45+reg46; reg6=reg16-reg6; reg38=reg38-reg36;
    reg40=reg40+reg42; reg16=reg5+reg41; reg33=reg33+reg34; reg39=pow(reg27,2); reg31=reg31-reg35;
    reg44=reg44+reg29; T reg52=pow(reg25,2); T reg53=reg26*reg28; T reg54=reg26*reg25; reg30=reg30-reg32;
    T reg55=reg6*reg49; reg33=reg39+reg33; reg52=reg44+reg52; reg39=reg6*reg16; reg47=reg40+reg47;
    reg54=reg30+reg54; reg51=reg37+reg51; reg48=reg38+reg48; reg45=reg45+reg50; reg31=reg31-reg53;
    reg30=reg6*reg54; reg37=reg6*reg48; reg38=0.5*reg39; reg40=reg6*reg52; reg44=0.5*reg55;
    T reg56=reg6*reg31; T reg57=reg6*reg47; T reg58=reg6*reg33; T reg59=reg6*reg51; T reg60=reg6*reg45;
    T tmp_3_3=0.5*reg58; T tmp_4_4=0.5*reg58; T tmp_5_5=0.5*reg58; T tmp_3_6=-reg38; T tmp_4_7=-reg38;
    T tmp_5_8=-reg38; T tmp_6_3=-reg38; T tmp_7_4=-reg38; T tmp_8_5=-reg38; T tmp_6_9=-reg44;
    T tmp_7_10=-reg44; T tmp_8_11=-reg44; T tmp_9_6=-reg44; T tmp_10_7=-reg44; T tmp_11_8=-reg44;
    T tmp_0_3=0.5*reg37; T tmp_1_4=0.5*reg37; T tmp_2_5=0.5*reg37; T tmp_3_0=0.5*reg37; T tmp_4_1=0.5*reg37;
    T tmp_5_2=0.5*reg37; T tmp_0_6=0.5*reg56; T tmp_1_7=0.5*reg56; T tmp_2_8=0.5*reg56; T tmp_6_0=0.5*reg56;
    T tmp_7_1=0.5*reg56; T tmp_8_2=0.5*reg56; T tmp_9_9=0.5*reg40; T tmp_10_10=0.5*reg40; T tmp_11_11=0.5*reg40;
    T tmp_0_9=0.5*reg30; T tmp_1_10=0.5*reg30; T tmp_2_11=0.5*reg30; T tmp_9_0=0.5*reg30; T tmp_10_1=0.5*reg30;
    T tmp_11_2=0.5*reg30; T tmp_3_9=0.5*reg57; T tmp_4_10=0.5*reg57; T tmp_5_11=0.5*reg57; T tmp_9_3=0.5*reg57;
    T tmp_10_4=0.5*reg57; T tmp_11_5=0.5*reg57; T tmp_0_0=0.5*reg59; T tmp_1_1=0.5*reg59; T tmp_2_2=0.5*reg59;
    T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=pow(reg2,2); reg3=reg4+reg3; reg5=reg3+reg5; reg5=pow(reg5,0.5); reg3=elem.pos(1)[1]-elem.pos(0)[1];
    reg4=reg0/reg5; T reg6=reg1/reg5; T reg7=elem.pos(1)[0]-elem.pos(0)[0]; T reg8=reg6*reg7; T reg9=elem.pos(1)[2]-elem.pos(0)[2];
    T reg10=reg4*reg3; reg5=reg2/reg5; reg10=reg8+reg10; reg8=reg5*reg9; reg8=reg10+reg8;
    reg10=reg6*reg8; T reg11=reg4*reg8; reg11=reg3-reg11; T reg12=elem.pos(3)[2]-elem.pos(0)[2]; T reg13=reg5*reg8;
    T reg14=elem.pos(3)[1]-elem.pos(0)[1]; reg10=reg7-reg10; T reg15=pow(reg10,2); T reg16=reg0*reg12; T reg17=reg9*reg14;
    T reg18=pow(reg11,2); T reg19=reg3*reg12; T reg20=reg2*reg14; reg13=reg9-reg13; reg20=reg16-reg20;
    reg17=reg19-reg17; reg16=pow(reg13,2); reg18=reg15+reg18; reg15=reg3*reg2; reg19=reg9*reg0;
    reg19=reg15-reg19; reg15=reg7*reg20; reg16=reg18+reg16; reg18=elem.pos(3)[0]-elem.pos(0)[0]; T reg21=reg1*reg17;
    reg16=pow(reg16,0.5); T reg22=reg2*reg18; T reg23=reg7*reg12; T reg24=reg1*reg12; T reg25=reg18*reg19;
    reg21=reg15-reg21; reg15=reg9*reg18; T reg26=reg7*reg14; reg25=reg21+reg25; reg21=reg7*reg2;
    T reg27=reg0*reg18; reg22=reg24-reg22; reg24=reg1*reg14; T reg28=reg3*reg18; reg15=reg23-reg15;
    reg23=reg9*reg1; reg10=reg10/reg16; reg11=reg11/reg16; T reg29=reg7*reg0; T reg30=reg11*reg3;
    T reg31=reg10*reg7; T reg32=reg3*reg1; reg4=reg4*reg0; reg6=reg6*reg1; reg23=reg21-reg23;
    reg16=reg13/reg16; reg28=reg26-reg28; reg10=reg10*reg1; reg11=reg11*reg0; reg20=reg20/reg25;
    reg22=reg22/reg25; reg15=reg15/reg25; reg27=reg24-reg27; reg17=reg17/reg25; reg19=reg19/reg25;
    reg28=reg28/reg25; reg32=reg29-reg32; reg23=reg23/reg25; reg27=reg27/reg25; reg13=reg17-reg20;
    reg21=reg22-reg15; reg4=reg6+reg4; reg5=reg5*reg2; reg6=reg16*reg2; reg30=reg31+reg30;
    reg16=reg16*reg9; reg11=reg10+reg11; reg10=reg15*reg23; reg24=reg17*reg19; reg26=reg28-reg27;
    reg21=reg21+reg23; reg6=reg11+reg6; reg16=reg30+reg16; reg5=reg4+reg5; reg4=reg22*reg15;
    reg11=reg20*reg17; reg13=reg13-reg19; reg25=reg32/reg25; reg29=pow(reg23,2); reg30=reg13*reg19;
    reg31=reg21*reg15; reg32=reg21*reg23; T reg33=pow(reg20,2); T reg34=pow(reg22,2); T reg35=reg13*reg17;
    T reg36=reg21*reg22; T reg37=pow(reg21,2); T reg38=reg13*reg20; T reg39=pow(reg13,2); reg26=reg26-reg25;
    reg6=reg8*reg6; reg16=reg5*reg16; reg5=reg11+reg4; reg8=reg28*reg25; T reg40=reg20*reg19;
    T reg41=reg27*reg28; T reg42=reg22*reg23; T reg43=reg24+reg10; T reg44=pow(reg19,2); T reg45=pow(reg15,2);
    T reg46=pow(reg17,2); T reg47=reg27*reg25; T reg48=reg26*reg27; T reg49=reg43+reg8; T reg50=pow(reg28,2);
    T reg51=pow(reg26,2); reg37=reg39+reg37; reg45=reg45+reg46; reg6=reg16-reg6; reg38=reg38-reg36;
    reg40=reg40+reg42; reg16=reg5+reg41; reg33=reg33+reg34; reg39=pow(reg27,2); reg31=reg31-reg35;
    reg44=reg44+reg29; T reg52=pow(reg25,2); T reg53=reg26*reg28; T reg54=reg26*reg25; reg30=reg30-reg32;
    T reg55=reg6*reg49; reg33=reg39+reg33; reg52=reg44+reg52; reg39=reg6*reg16; reg47=reg40+reg47;
    reg54=reg30+reg54; reg51=reg37+reg51; reg48=reg38+reg48; reg45=reg45+reg50; reg31=reg31-reg53;
    reg30=reg6*reg54; reg37=reg6*reg48; reg38=0.5*reg39; reg40=reg6*reg52; reg44=0.5*reg55;
    T reg56=reg6*reg31; T reg57=reg6*reg47; T reg58=reg6*reg33; T reg59=reg6*reg51; T reg60=reg6*reg45;
    T tmp_3_3=0.5*reg58; T tmp_4_4=0.5*reg58; T tmp_5_5=0.5*reg58; T tmp_3_6=-reg38; T tmp_4_7=-reg38;
    T tmp_5_8=-reg38; T tmp_6_9=-reg44; T tmp_7_10=-reg44; T tmp_8_11=-reg44; T tmp_0_3=0.5*reg37;
    T tmp_1_4=0.5*reg37; T tmp_2_5=0.5*reg37; T tmp_0_6=0.5*reg56; T tmp_1_7=0.5*reg56; T tmp_2_8=0.5*reg56;
    T tmp_9_9=0.5*reg40; T tmp_10_10=0.5*reg40; T tmp_11_11=0.5*reg40; T tmp_0_9=0.5*reg30; T tmp_1_10=0.5*reg30;
    T tmp_2_11=0.5*reg30; T tmp_3_9=0.5*reg57; T tmp_4_10=0.5*reg57; T tmp_5_11=0.5*reg57; T tmp_0_0=0.5*reg59;
    T tmp_1_1=0.5*reg59; T tmp_2_2=0.5*reg59; T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=pow(reg2,2); reg3=reg4+reg3; reg5=reg3+reg5; reg5=pow(reg5,0.5); reg3=elem.pos(1)[1]-elem.pos(0)[1];
    reg4=reg0/reg5; T reg6=reg1/reg5; T reg7=elem.pos(1)[0]-elem.pos(0)[0]; T reg8=reg6*reg7; T reg9=elem.pos(1)[2]-elem.pos(0)[2];
    T reg10=reg4*reg3; reg5=reg2/reg5; reg10=reg8+reg10; reg8=reg5*reg9; reg8=reg10+reg8;
    reg10=reg6*reg8; T reg11=reg4*reg8; reg11=reg3-reg11; T reg12=elem.pos(3)[2]-elem.pos(0)[2]; T reg13=reg5*reg8;
    T reg14=elem.pos(3)[1]-elem.pos(0)[1]; reg10=reg7-reg10; T reg15=pow(reg10,2); T reg16=reg0*reg12; T reg17=reg9*reg14;
    T reg18=pow(reg11,2); T reg19=reg3*reg12; T reg20=reg2*reg14; reg13=reg9-reg13; reg20=reg16-reg20;
    reg17=reg19-reg17; reg16=pow(reg13,2); reg18=reg15+reg18; reg15=reg3*reg2; reg19=reg9*reg0;
    reg19=reg15-reg19; reg15=reg7*reg20; reg16=reg18+reg16; reg18=elem.pos(3)[0]-elem.pos(0)[0]; T reg21=reg1*reg17;
    reg16=pow(reg16,0.5); T reg22=reg2*reg18; T reg23=reg7*reg12; T reg24=reg1*reg12; T reg25=reg18*reg19;
    reg21=reg15-reg21; reg15=reg9*reg18; T reg26=reg7*reg14; reg25=reg21+reg25; reg21=reg7*reg2;
    T reg27=reg0*reg18; reg22=reg24-reg22; reg24=reg1*reg14; T reg28=reg3*reg18; reg15=reg23-reg15;
    reg23=reg9*reg1; reg10=reg10/reg16; reg11=reg11/reg16; T reg29=reg7*reg0; T reg30=reg11*reg3;
    T reg31=reg10*reg7; T reg32=reg3*reg1; reg4=reg4*reg0; reg6=reg6*reg1; reg23=reg21-reg23;
    reg16=reg13/reg16; reg28=reg26-reg28; reg10=reg10*reg1; reg11=reg11*reg0; reg20=reg20/reg25;
    reg22=reg22/reg25; reg15=reg15/reg25; reg27=reg24-reg27; reg17=reg17/reg25; reg19=reg19/reg25;
    reg28=reg28/reg25; reg32=reg29-reg32; reg23=reg23/reg25; reg27=reg27/reg25; reg13=reg17-reg20;
    reg21=reg22-reg15; reg4=reg6+reg4; reg5=reg5*reg2; reg6=reg16*reg2; reg30=reg31+reg30;
    reg16=reg16*reg9; reg11=reg10+reg11; reg10=reg15*reg23; reg24=reg17*reg19; reg26=reg28-reg27;
    reg21=reg21+reg23; reg6=reg11+reg6; reg16=reg30+reg16; reg5=reg4+reg5; reg4=reg22*reg15;
    reg11=reg20*reg17; reg13=reg13-reg19; reg25=reg32/reg25; reg29=pow(reg23,2); reg30=reg13*reg19;
    reg31=reg21*reg15; reg32=reg21*reg23; T reg33=pow(reg20,2); T reg34=pow(reg22,2); T reg35=reg13*reg17;
    T reg36=reg21*reg22; T reg37=pow(reg21,2); T reg38=reg13*reg20; T reg39=pow(reg13,2); reg26=reg26-reg25;
    reg6=reg8*reg6; reg16=reg5*reg16; reg5=reg11+reg4; reg8=reg28*reg25; T reg40=reg20*reg19;
    T reg41=reg27*reg28; T reg42=reg22*reg23; T reg43=reg24+reg10; T reg44=pow(reg19,2); T reg45=pow(reg15,2);
    T reg46=pow(reg17,2); T reg47=reg27*reg25; T reg48=reg26*reg27; T reg49=reg43+reg8; T reg50=pow(reg28,2);
    T reg51=pow(reg26,2); reg37=reg39+reg37; reg45=reg45+reg46; reg6=reg16-reg6; reg38=reg38-reg36;
    reg40=reg40+reg42; reg16=reg5+reg41; reg33=reg33+reg34; reg39=pow(reg27,2); reg31=reg31-reg35;
    reg44=reg44+reg29; T reg52=pow(reg25,2); T reg53=reg26*reg28; T reg54=reg26*reg25; reg30=reg30-reg32;
    T reg55=reg6*reg49; reg33=reg39+reg33; reg52=reg44+reg52; reg39=reg6*reg16; reg47=reg40+reg47;
    reg54=reg30+reg54; reg51=reg37+reg51; reg48=reg38+reg48; reg45=reg45+reg50; reg31=reg31-reg53;
    reg30=reg6*reg54; reg37=reg6*reg48; reg38=0.5*reg39; reg40=reg6*reg52; reg44=0.5*reg55;
    T reg56=reg6*reg31; T reg57=reg6*reg47; T reg58=reg6*reg33; T reg59=reg6*reg51; T reg60=reg6*reg45;
    T tmp_3_3=0.5*reg58; T tmp_4_4=0.5*reg58; T tmp_5_5=0.5*reg58; T tmp_3_6=-reg38; T tmp_4_7=-reg38;
    T tmp_5_8=-reg38; T tmp_6_3=-reg38; T tmp_7_4=-reg38; T tmp_8_5=-reg38; T tmp_6_9=-reg44;
    T tmp_7_10=-reg44; T tmp_8_11=-reg44; T tmp_9_6=-reg44; T tmp_10_7=-reg44; T tmp_11_8=-reg44;
    T tmp_0_3=0.5*reg37; T tmp_1_4=0.5*reg37; T tmp_2_5=0.5*reg37; T tmp_3_0=0.5*reg37; T tmp_4_1=0.5*reg37;
    T tmp_5_2=0.5*reg37; T tmp_0_6=0.5*reg56; T tmp_1_7=0.5*reg56; T tmp_2_8=0.5*reg56; T tmp_6_0=0.5*reg56;
    T tmp_7_1=0.5*reg56; T tmp_8_2=0.5*reg56; T tmp_9_9=0.5*reg40; T tmp_10_10=0.5*reg40; T tmp_11_11=0.5*reg40;
    T tmp_0_9=0.5*reg30; T tmp_1_10=0.5*reg30; T tmp_2_11=0.5*reg30; T tmp_9_0=0.5*reg30; T tmp_10_1=0.5*reg30;
    T tmp_11_2=0.5*reg30; T tmp_3_9=0.5*reg57; T tmp_4_10=0.5*reg57; T tmp_5_11=0.5*reg57; T tmp_9_3=0.5*reg57;
    T tmp_10_4=0.5*reg57; T tmp_11_5=0.5*reg57; T tmp_0_0=0.5*reg59; T tmp_1_1=0.5*reg59; T tmp_2_2=0.5*reg59;
    T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=pow(reg2,2); reg3=reg4+reg3; reg5=reg3+reg5; reg5=pow(reg5,0.5); reg3=elem.pos(1)[1]-elem.pos(0)[1];
    reg4=reg0/reg5; T reg6=reg1/reg5; T reg7=elem.pos(1)[0]-elem.pos(0)[0]; T reg8=reg6*reg7; T reg9=elem.pos(1)[2]-elem.pos(0)[2];
    T reg10=reg4*reg3; reg5=reg2/reg5; reg10=reg8+reg10; reg8=reg5*reg9; reg8=reg10+reg8;
    reg10=reg6*reg8; T reg11=reg4*reg8; reg11=reg3-reg11; T reg12=elem.pos(3)[2]-elem.pos(0)[2]; T reg13=reg5*reg8;
    T reg14=elem.pos(3)[1]-elem.pos(0)[1]; reg10=reg7-reg10; T reg15=pow(reg10,2); T reg16=reg0*reg12; T reg17=reg9*reg14;
    T reg18=pow(reg11,2); T reg19=reg3*reg12; T reg20=reg2*reg14; reg13=reg9-reg13; reg20=reg16-reg20;
    reg17=reg19-reg17; reg16=pow(reg13,2); reg18=reg15+reg18; reg15=reg3*reg2; reg19=reg9*reg0;
    reg19=reg15-reg19; reg15=reg7*reg20; reg16=reg18+reg16; reg18=elem.pos(3)[0]-elem.pos(0)[0]; T reg21=reg1*reg17;
    reg16=pow(reg16,0.5); T reg22=reg2*reg18; T reg23=reg7*reg12; T reg24=reg1*reg12; T reg25=reg18*reg19;
    reg21=reg15-reg21; reg15=reg9*reg18; T reg26=reg7*reg14; reg25=reg21+reg25; reg21=reg7*reg2;
    T reg27=reg0*reg18; reg22=reg24-reg22; reg24=reg1*reg14; T reg28=reg3*reg18; reg15=reg23-reg15;
    reg23=reg9*reg1; reg10=reg10/reg16; reg11=reg11/reg16; T reg29=reg7*reg0; T reg30=reg11*reg3;
    T reg31=reg10*reg7; T reg32=reg3*reg1; reg4=reg4*reg0; reg6=reg6*reg1; reg23=reg21-reg23;
    reg16=reg13/reg16; reg28=reg26-reg28; reg10=reg10*reg1; reg11=reg11*reg0; reg20=reg20/reg25;
    reg22=reg22/reg25; reg15=reg15/reg25; reg27=reg24-reg27; reg17=reg17/reg25; reg19=reg19/reg25;
    reg28=reg28/reg25; reg32=reg29-reg32; reg23=reg23/reg25; reg27=reg27/reg25; reg13=reg17-reg20;
    reg21=reg22-reg15; reg4=reg6+reg4; reg5=reg5*reg2; reg6=reg16*reg2; reg30=reg31+reg30;
    reg16=reg16*reg9; reg11=reg10+reg11; reg10=reg15*reg23; reg24=reg17*reg19; reg26=reg28-reg27;
    reg21=reg21+reg23; reg6=reg11+reg6; reg16=reg30+reg16; reg5=reg4+reg5; reg4=reg22*reg15;
    reg11=reg20*reg17; reg13=reg13-reg19; reg25=reg32/reg25; reg29=pow(reg23,2); reg30=reg13*reg19;
    reg31=reg21*reg15; reg32=reg21*reg23; T reg33=pow(reg20,2); T reg34=pow(reg22,2); T reg35=reg13*reg17;
    T reg36=reg21*reg22; T reg37=pow(reg21,2); T reg38=reg13*reg20; T reg39=pow(reg13,2); reg26=reg26-reg25;
    reg6=reg8*reg6; reg16=reg5*reg16; reg5=reg11+reg4; reg8=reg28*reg25; T reg40=reg20*reg19;
    T reg41=reg27*reg28; T reg42=reg22*reg23; T reg43=reg24+reg10; T reg44=pow(reg19,2); T reg45=pow(reg15,2);
    T reg46=pow(reg17,2); T reg47=reg27*reg25; T reg48=reg26*reg27; T reg49=reg43+reg8; T reg50=pow(reg28,2);
    T reg51=pow(reg26,2); reg37=reg39+reg37; reg45=reg45+reg46; reg6=reg16-reg6; reg38=reg38-reg36;
    reg40=reg40+reg42; reg16=reg5+reg41; reg33=reg33+reg34; reg39=pow(reg27,2); reg31=reg31-reg35;
    reg44=reg44+reg29; T reg52=pow(reg25,2); T reg53=reg26*reg28; T reg54=reg26*reg25; reg30=reg30-reg32;
    T reg55=reg6*reg49; reg33=reg39+reg33; reg52=reg44+reg52; reg39=reg6*reg16; reg47=reg40+reg47;
    reg54=reg30+reg54; reg51=reg37+reg51; reg48=reg38+reg48; reg45=reg45+reg50; reg31=reg31-reg53;
    reg30=reg6*reg54; reg37=reg6*reg48; reg38=0.5*reg39; reg40=reg6*reg52; reg44=0.5*reg55;
    T reg56=reg6*reg31; T reg57=reg6*reg47; T reg58=reg6*reg33; T reg59=reg6*reg51; T reg60=reg6*reg45;
    T tmp_3_3=0.5*reg58; T tmp_4_4=0.5*reg58; T tmp_5_5=0.5*reg58; T tmp_3_6=-reg38; T tmp_4_7=-reg38;
    T tmp_5_8=-reg38; T tmp_6_9=-reg44; T tmp_7_10=-reg44; T tmp_8_11=-reg44; T tmp_0_3=0.5*reg37;
    T tmp_1_4=0.5*reg37; T tmp_2_5=0.5*reg37; T tmp_0_6=0.5*reg56; T tmp_1_7=0.5*reg56; T tmp_2_8=0.5*reg56;
    T tmp_9_9=0.5*reg40; T tmp_10_10=0.5*reg40; T tmp_11_11=0.5*reg40; T tmp_0_9=0.5*reg30; T tmp_1_10=0.5*reg30;
    T tmp_2_11=0.5*reg30; T tmp_3_9=0.5*reg57; T tmp_4_10=0.5*reg57; T tmp_5_11=0.5*reg57; T tmp_0_0=0.5*reg59;
    T tmp_1_1=0.5*reg59; T tmp_2_2=0.5*reg59; T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg5=reg4+reg5; reg5=pow(reg5,0.5); reg3=reg1/reg5;
    reg4=elem.pos(1)[0]-elem.pos(0)[0]; T reg6=elem.pos(1)[1]-elem.pos(0)[1]; T reg7=reg0/reg5; T reg8=reg3*reg4; T reg9=reg7*reg6;
    T reg10=elem.pos(1)[2]-elem.pos(0)[2]; reg5=reg2/reg5; T reg11=reg5*reg10; reg9=reg8+reg9; reg8=elem.pos(3)[2]-elem.pos(0)[2];
    T reg12=elem.pos(3)[1]-elem.pos(0)[1]; reg11=reg9+reg11; reg9=reg2*reg12; T reg13=reg6*reg8; T reg14=reg0*reg8;
    T reg15=reg3*reg11; T reg16=reg7*reg11; T reg17=reg10*reg12; reg9=reg14-reg9; reg14=reg10*reg0;
    T reg18=reg6*reg2; T reg19=reg5*reg11; reg17=reg13-reg17; reg16=reg6-reg16; reg15=reg4-reg15;
    reg13=pow(reg16,2); reg19=reg10-reg19; T reg20=reg4*reg9; T reg21=reg1*reg17; reg14=reg18-reg14;
    reg18=pow(reg15,2); T reg22=elem.pos(3)[0]-elem.pos(0)[0]; T reg23=reg10*reg22; reg21=reg20-reg21; reg20=reg22*reg14;
    T reg24=reg1*reg8; T reg25=reg2*reg22; T reg26=pow(reg19,2); T reg27=reg4*reg8; reg13=reg18+reg13;
    reg20=reg21+reg20; reg26=reg13+reg26; reg13=reg1*reg12; reg18=reg10*reg1; reg21=reg4*reg2;
    T reg28=reg6*reg22; reg23=reg27-reg23; reg27=reg4*reg12; T reg29=reg0*reg22; reg25=reg24-reg25;
    reg26=pow(reg26,0.5); reg24=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; reg29=reg13-reg29; reg13=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg30=vectors[0][indices[2]+1]-vectors[0][indices[0]+1];
    T reg31=reg4*reg0; reg28=reg27-reg28; reg18=reg21-reg18; reg21=reg6*reg1; reg23=reg23/reg20;
    reg17=reg17/reg20; reg27=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; reg25=reg25/reg20; reg9=reg9/reg20; T reg32=vectors[0][indices[1]+2]-vectors[0][indices[0]+2];
    T reg33=vectors[0][indices[2]+2]-vectors[0][indices[0]+2]; reg28=reg28/reg20; reg18=reg18/reg20; reg14=reg14/reg20; reg15=reg15/reg26;
    reg29=reg29/reg20; reg21=reg31-reg21; reg16=reg16/reg26; reg31=reg27*reg25; T reg34=vectors[0][indices[3]+1]-vectors[0][indices[0]+1];
    T reg35=reg30*reg23; T reg36=reg13*reg25; T reg37=reg30*reg17; T reg38=reg13*reg9; T reg39=reg27*reg9;
    T reg40=reg24*reg17; T reg41=vectors[0][indices[3]+0]-vectors[0][indices[0]+0]; T reg42=reg24*reg23; T reg43=reg32*reg25; T reg44=reg33*reg23;
    T reg45=reg32*reg9; T reg46=reg33*reg17; T reg47=vectors[0][indices[3]+2]-vectors[0][indices[0]+2]; reg46=reg45-reg46; reg45=reg47*reg18;
    reg43=reg44-reg43; reg44=reg34*reg18; T reg48=reg47*reg14; reg13=reg13*reg29; reg30=reg30*reg28;
    reg24=reg24*reg28; reg40=reg39-reg40; reg39=reg41*reg14; reg36=reg35-reg36; reg31=reg42-reg31;
    reg35=reg41*reg18; reg27=reg27*reg29; reg42=reg34*reg14; reg37=reg38-reg37; reg7=reg7*reg0;
    reg3=reg3*reg1; reg26=reg19/reg26; reg19=reg25-reg23; reg38=reg17-reg9; T reg49=reg16*reg6;
    reg33=reg33*reg28; reg32=reg32*reg29; T reg50=reg15*reg4; reg20=reg21/reg20; reg16=reg16*reg0;
    reg15=reg15*reg1; reg47=reg47*reg20; reg41=reg41*reg20; reg5=reg5*reg2; reg24=reg27-reg24;
    reg45=reg43-reg45; reg33=reg32-reg33; reg48=reg46+reg48; reg7=reg3+reg7; reg35=reg31-reg35;
    reg49=reg50+reg49; reg3=reg26*reg10; reg39=reg40+reg39; reg38=reg38-reg14; reg16=reg15+reg16;
    reg26=reg26*reg2; reg34=reg34*reg20; reg30=reg13-reg30; reg44=reg36-reg44; reg19=reg19+reg18;
    reg13=reg28-reg29; reg42=reg37+reg42; reg15=reg35*reg18; reg21=reg48*reg17; reg27=reg42*reg14;
    reg31=reg39*reg14; reg32=reg45*reg23; reg5=reg7+reg5; reg7=reg44*reg18; reg36=reg48*reg14;
    reg37=reg45*reg18; reg24=reg41+reg24; reg34=reg30+reg34; reg30=reg38*reg39; reg40=reg45*reg19;
    reg41=reg35*reg23; reg43=reg39*reg17; reg46=reg45*reg25; reg50=reg48*reg9; T reg51=reg44*reg25;
    T reg52=reg42*reg9; T reg53=reg35*reg25; T reg54=reg39*reg9; T reg55=reg44*reg23; T reg56=reg38*reg48;
    T reg57=reg44*reg19; T reg58=reg38*reg42; reg13=reg13-reg20; T reg59=reg35*reg19; reg26=reg16+reg26;
    reg3=reg49+reg3; reg33=reg47+reg33; reg16=reg42*reg17; reg57=reg58+reg57; reg47=reg24*reg29;
    reg54=reg54-reg53; reg49=reg33*reg13; reg40=reg56+reg40; reg52=reg52-reg51; reg56=reg34*reg29;
    reg58=reg33*reg28; reg32=reg32-reg21; T reg60=reg34*reg13; reg31=reg31-reg15; T reg61=reg24*reg20;
    reg50=reg50-reg46; T reg62=reg33*reg29; T reg63=reg24*reg13; reg55=reg55-reg16; reg59=reg30+reg59;
    reg30=reg33*reg20; reg36=reg36-reg37; T reg64=reg24*reg28; reg26=reg11*reg26; reg3=reg5*reg3;
    reg5=reg34*reg28; reg11=reg34*reg20; reg27=reg27-reg7; reg41=reg41-reg43; reg55=reg55-reg5;
    reg32=reg32-reg58; reg49=reg40+reg49; reg63=reg59+reg63; reg60=reg57+reg60; reg26=reg3-reg26;
    reg47=reg54+reg47; reg30=reg36+reg30; reg11=reg27+reg11; reg62=reg50+reg62; reg41=reg41-reg64;
    reg56=reg52+reg56; reg61=reg31+reg61; reg3=reg26*reg56; reg27=reg26*reg63; reg31=reg26*reg55;
    reg36=reg26*reg62; reg40=reg26*reg60; reg50=reg26*reg30; reg52=reg26*reg41; reg54=reg26*reg11;
    reg57=reg26*reg49; reg59=reg26*reg61; T reg65=reg26*reg47; T reg66=reg26*reg32; T vec_10=0.5*reg54;
    T vec_5=0.5*reg36; T vec_9=0.5*reg59; T vec_7=0.5*reg31; T vec_11=0.5*reg50; T vec_0=0.5*reg27;
    T vec_6=0.5*reg52; T vec_4=0.5*reg3; T vec_1=0.5*reg40; T vec_8=0.5*reg66; T vec_3=0.5*reg65;
    T vec_2=0.5*reg57;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[0]+2] += vec_2;
sollicitation[indices[1]+0] += vec_3;
sollicitation[indices[1]+1] += vec_4;
sollicitation[indices[1]+2] += vec_5;
sollicitation[indices[2]+0] += vec_6;
sollicitation[indices[2]+1] += vec_7;
sollicitation[indices[2]+2] += vec_8;
sollicitation[indices[3]+0] += vec_9;
sollicitation[indices[3]+1] += vec_10;
sollicitation[indices[3]+2] += vec_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg4=reg5+reg4; reg4=pow(reg4,0.5); reg3=reg0/reg4;
    reg5=elem.pos(3)[0]-elem.pos(0)[0]; T reg6=elem.pos(3)[1]-elem.pos(0)[1]; T reg7=reg1/reg4; T reg8=reg7*reg5; T reg9=reg3*reg6;
    reg4=reg2/reg4; T reg10=elem.pos(3)[2]-elem.pos(0)[2]; reg8=reg9+reg8; reg9=reg4*reg10; reg9=reg8+reg9;
    reg8=reg9*reg7; T reg11=reg9*reg3; reg8=reg5-reg8; reg11=reg6-reg11; T reg12=elem.pos(2)[1]-elem.pos(0)[1];
    T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=reg9*reg4; reg14=reg10-reg14; T reg15=reg13*reg6; T reg16=pow(reg11,2);
    T reg17=pow(reg8,2); T reg18=reg12*reg10; T reg19=reg0*reg10; T reg20=reg2*reg6; T reg21=elem.pos(2)[0]-elem.pos(0)[0];
    T reg22=pow(reg14,2); reg15=reg18-reg15; reg20=reg19-reg20; reg18=reg0*reg13; reg16=reg17+reg16;
    reg17=reg2*reg12; reg17=reg18-reg17; reg22=reg16+reg22; reg16=reg1*reg15; reg18=reg21*reg20;
    reg19=reg13*reg5; T reg23=reg21*reg10; T reg24=reg5*reg17; reg22=pow(reg22,0.5); reg18=reg16-reg18;
    reg16=reg2*reg5; T reg25=reg1*reg10; T reg26=reg0*reg5; T reg27=reg12*reg5; reg16=reg25-reg16;
    reg25=reg21*reg6; reg19=reg23-reg19; reg23=reg1*reg6; reg24=reg18+reg24; reg18=reg1*reg13;
    T reg28=reg2*reg21; reg8=reg8/reg22; reg11=reg11/reg22; reg15=reg15/reg24; reg19=reg19/reg24;
    reg22=reg14/reg22; reg14=reg8*reg5; T reg29=reg11*reg6; reg20=reg20/reg24; reg27=reg25-reg27;
    reg25=reg0*reg21; reg28=reg18-reg28; reg16=reg16/reg24; reg18=reg1*reg12; reg8=reg8*reg1;
    reg11=reg11*reg0; reg26=reg23-reg26; reg7=reg7*reg1; reg3=reg3*reg0; reg25=reg18-reg25;
    reg18=reg19-reg16; reg29=reg14+reg29; reg28=reg28/reg24; reg14=reg22*reg10; reg23=reg20-reg15;
    reg3=reg7+reg3; reg4=reg4*reg2; reg22=reg22*reg2; reg8=reg11+reg8; reg17=reg17/reg24;
    reg26=reg26/reg24; reg27=reg27/reg24; reg18=reg18+reg28; reg14=reg29+reg14; reg7=reg26-reg27;
    reg22=reg8+reg22; reg8=reg16*reg28; reg11=reg20*reg17; reg23=reg23-reg17; reg29=reg19*reg16;
    T reg30=reg15*reg20; reg4=reg3+reg4; reg24=reg25/reg24; reg3=reg18*reg16; reg25=pow(reg23,2);
    reg7=reg7-reg24; T reg31=reg23*reg20; T reg32=reg23*reg15; T reg33=pow(reg18,2); T reg34=pow(reg16,2);
    T reg35=pow(reg20,2); T reg36=reg19*reg28; T reg37=reg18*reg19; T reg38=reg27*reg26; T reg39=reg15*reg17;
    T reg40=reg30+reg29; reg22=reg9*reg22; reg9=pow(reg28,2); T reg41=pow(reg19,2); T reg42=pow(reg15,2);
    reg4=reg14*reg4; reg14=pow(reg17,2); T reg43=reg26*reg24; T reg44=reg18*reg28; T reg45=reg23*reg17;
    T reg46=reg11+reg8; T reg47=pow(reg26,2); reg34=reg34+reg35; reg39=reg39+reg36; T reg48=pow(reg7,2);
    reg32=reg32-reg37; T reg49=reg7*reg27; T reg50=reg27*reg24; reg3=reg3-reg31; T reg51=reg40+reg38;
    reg42=reg42+reg41; T reg52=pow(reg27,2); T reg53=reg7*reg24; reg45=reg45-reg44; T reg54=reg7*reg26;
    reg14=reg14+reg9; T reg55=pow(reg24,2); reg33=reg25+reg33; reg22=reg4-reg22; reg4=reg46+reg43;
    reg53=reg45+reg53; reg25=reg4*reg22; reg3=reg3-reg54; reg42=reg52+reg42; reg45=reg51*reg22;
    reg50=reg39+reg50; reg49=reg32+reg49; reg48=reg33+reg48; reg55=reg14+reg55; reg34=reg34+reg47;
    reg14=0.5*reg45; reg32=reg53*reg22; reg33=reg42*reg22; reg39=reg34*reg22; reg52=reg3*reg22;
    T reg56=reg50*reg22; T reg57=reg49*reg22; T reg58=0.5*reg25; T reg59=reg55*reg22; T reg60=reg48*reg22;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_3_0=0.5*reg57; T tmp_4_1=0.5*reg57;
    T tmp_5_2=0.5*reg57; T tmp_0_0=0.5*reg60; T tmp_1_1=0.5*reg60; T tmp_2_2=0.5*reg60; T tmp_0_6=0.5*reg52;
    T tmp_1_7=0.5*reg52; T tmp_2_8=0.5*reg52; T tmp_6_0=0.5*reg52; T tmp_7_1=0.5*reg52; T tmp_8_2=0.5*reg52;
    T tmp_0_9=0.5*reg32; T tmp_1_10=0.5*reg32; T tmp_2_11=0.5*reg32; T tmp_9_0=0.5*reg32; T tmp_10_1=0.5*reg32;
    T tmp_11_2=0.5*reg32; T tmp_3_3=0.5*reg33; T tmp_4_4=0.5*reg33; T tmp_5_5=0.5*reg33; T tmp_3_6=-reg14;
    T tmp_4_7=-reg14; T tmp_5_8=-reg14; T tmp_6_3=-reg14; T tmp_7_4=-reg14; T tmp_8_5=-reg14;
    T tmp_3_9=0.5*reg56; T tmp_4_10=0.5*reg56; T tmp_5_11=0.5*reg56; T tmp_9_3=0.5*reg56; T tmp_10_4=0.5*reg56;
    T tmp_11_5=0.5*reg56; T tmp_6_6=0.5*reg39; T tmp_7_7=0.5*reg39; T tmp_8_8=0.5*reg39; T tmp_6_9=-reg58;
    T tmp_7_10=-reg58; T tmp_8_11=-reg58; T tmp_9_6=-reg58; T tmp_10_7=-reg58; T tmp_11_8=-reg58;
    T tmp_9_9=0.5*reg59; T tmp_10_10=0.5*reg59; T tmp_11_11=0.5*reg59;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg4=reg5+reg4; reg4=pow(reg4,0.5); reg3=reg0/reg4;
    reg5=elem.pos(3)[0]-elem.pos(0)[0]; T reg6=elem.pos(3)[1]-elem.pos(0)[1]; T reg7=reg1/reg4; T reg8=reg7*reg5; T reg9=reg3*reg6;
    reg4=reg2/reg4; T reg10=elem.pos(3)[2]-elem.pos(0)[2]; reg8=reg9+reg8; reg9=reg4*reg10; reg9=reg8+reg9;
    reg8=reg9*reg7; T reg11=reg9*reg3; reg8=reg5-reg8; reg11=reg6-reg11; T reg12=elem.pos(2)[1]-elem.pos(0)[1];
    T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=reg9*reg4; reg14=reg10-reg14; T reg15=reg13*reg6; T reg16=pow(reg11,2);
    T reg17=pow(reg8,2); T reg18=reg12*reg10; T reg19=reg0*reg10; T reg20=reg2*reg6; T reg21=elem.pos(2)[0]-elem.pos(0)[0];
    T reg22=pow(reg14,2); reg15=reg18-reg15; reg20=reg19-reg20; reg18=reg0*reg13; reg16=reg17+reg16;
    reg17=reg2*reg12; reg17=reg18-reg17; reg22=reg16+reg22; reg16=reg1*reg15; reg18=reg21*reg20;
    reg19=reg13*reg5; T reg23=reg21*reg10; T reg24=reg5*reg17; reg22=pow(reg22,0.5); reg18=reg16-reg18;
    reg16=reg2*reg5; T reg25=reg1*reg10; T reg26=reg0*reg5; T reg27=reg12*reg5; reg16=reg25-reg16;
    reg25=reg21*reg6; reg19=reg23-reg19; reg23=reg1*reg6; reg24=reg18+reg24; reg18=reg1*reg13;
    T reg28=reg2*reg21; reg8=reg8/reg22; reg11=reg11/reg22; reg15=reg15/reg24; reg19=reg19/reg24;
    reg22=reg14/reg22; reg14=reg8*reg5; T reg29=reg11*reg6; reg20=reg20/reg24; reg27=reg25-reg27;
    reg25=reg0*reg21; reg28=reg18-reg28; reg16=reg16/reg24; reg18=reg1*reg12; reg8=reg8*reg1;
    reg11=reg11*reg0; reg26=reg23-reg26; reg7=reg7*reg1; reg3=reg3*reg0; reg25=reg18-reg25;
    reg18=reg19-reg16; reg29=reg14+reg29; reg28=reg28/reg24; reg14=reg22*reg10; reg23=reg20-reg15;
    reg3=reg7+reg3; reg4=reg4*reg2; reg22=reg22*reg2; reg8=reg11+reg8; reg17=reg17/reg24;
    reg26=reg26/reg24; reg27=reg27/reg24; reg18=reg18+reg28; reg14=reg29+reg14; reg7=reg26-reg27;
    reg22=reg8+reg22; reg8=reg16*reg28; reg11=reg20*reg17; reg23=reg23-reg17; reg29=reg19*reg16;
    T reg30=reg15*reg20; reg4=reg3+reg4; reg24=reg25/reg24; reg3=reg18*reg16; reg25=pow(reg23,2);
    reg7=reg7-reg24; T reg31=reg23*reg20; T reg32=reg23*reg15; T reg33=pow(reg18,2); T reg34=pow(reg16,2);
    T reg35=pow(reg20,2); T reg36=reg19*reg28; T reg37=reg18*reg19; T reg38=reg27*reg26; T reg39=reg15*reg17;
    T reg40=reg30+reg29; reg22=reg9*reg22; reg9=pow(reg28,2); T reg41=pow(reg19,2); T reg42=pow(reg15,2);
    reg4=reg14*reg4; reg14=pow(reg17,2); T reg43=reg26*reg24; T reg44=reg18*reg28; T reg45=reg23*reg17;
    T reg46=reg11+reg8; T reg47=pow(reg26,2); reg34=reg34+reg35; reg39=reg39+reg36; T reg48=pow(reg7,2);
    reg32=reg32-reg37; T reg49=reg7*reg27; T reg50=reg27*reg24; reg3=reg3-reg31; T reg51=reg40+reg38;
    reg42=reg42+reg41; T reg52=pow(reg27,2); T reg53=reg7*reg24; reg45=reg45-reg44; T reg54=reg7*reg26;
    reg14=reg14+reg9; T reg55=pow(reg24,2); reg33=reg25+reg33; reg22=reg4-reg22; reg4=reg46+reg43;
    reg53=reg45+reg53; reg25=reg4*reg22; reg3=reg3-reg54; reg42=reg52+reg42; reg45=reg51*reg22;
    reg50=reg39+reg50; reg49=reg32+reg49; reg48=reg33+reg48; reg55=reg14+reg55; reg34=reg34+reg47;
    reg14=0.5*reg45; reg32=reg53*reg22; reg33=reg42*reg22; reg39=reg34*reg22; reg52=reg3*reg22;
    T reg56=reg50*reg22; T reg57=reg49*reg22; T reg58=0.5*reg25; T reg59=reg55*reg22; T reg60=reg48*reg22;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_0_0=0.5*reg60; T tmp_1_1=0.5*reg60;
    T tmp_2_2=0.5*reg60; T tmp_0_6=0.5*reg52; T tmp_1_7=0.5*reg52; T tmp_2_8=0.5*reg52; T tmp_0_9=0.5*reg32;
    T tmp_1_10=0.5*reg32; T tmp_2_11=0.5*reg32; T tmp_3_3=0.5*reg33; T tmp_4_4=0.5*reg33; T tmp_5_5=0.5*reg33;
    T tmp_3_6=-reg14; T tmp_4_7=-reg14; T tmp_5_8=-reg14; T tmp_3_9=0.5*reg56; T tmp_4_10=0.5*reg56;
    T tmp_5_11=0.5*reg56; T tmp_6_6=0.5*reg39; T tmp_7_7=0.5*reg39; T tmp_8_8=0.5*reg39; T tmp_6_9=-reg58;
    T tmp_7_10=-reg58; T tmp_8_11=-reg58; T tmp_9_9=0.5*reg59; T tmp_10_10=0.5*reg59; T tmp_11_11=0.5*reg59;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg4=reg5+reg4; reg4=pow(reg4,0.5); reg3=reg0/reg4;
    reg5=elem.pos(3)[0]-elem.pos(0)[0]; T reg6=elem.pos(3)[1]-elem.pos(0)[1]; T reg7=reg1/reg4; T reg8=reg7*reg5; T reg9=reg3*reg6;
    reg4=reg2/reg4; T reg10=elem.pos(3)[2]-elem.pos(0)[2]; reg8=reg9+reg8; reg9=reg4*reg10; reg9=reg8+reg9;
    reg8=reg9*reg7; T reg11=reg9*reg3; reg8=reg5-reg8; reg11=reg6-reg11; T reg12=elem.pos(2)[1]-elem.pos(0)[1];
    T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=reg9*reg4; reg14=reg10-reg14; T reg15=reg13*reg6; T reg16=pow(reg11,2);
    T reg17=pow(reg8,2); T reg18=reg12*reg10; T reg19=reg0*reg10; T reg20=reg2*reg6; T reg21=elem.pos(2)[0]-elem.pos(0)[0];
    T reg22=pow(reg14,2); reg15=reg18-reg15; reg20=reg19-reg20; reg18=reg0*reg13; reg16=reg17+reg16;
    reg17=reg2*reg12; reg17=reg18-reg17; reg22=reg16+reg22; reg16=reg1*reg15; reg18=reg21*reg20;
    reg19=reg13*reg5; T reg23=reg21*reg10; T reg24=reg5*reg17; reg22=pow(reg22,0.5); reg18=reg16-reg18;
    reg16=reg2*reg5; T reg25=reg1*reg10; T reg26=reg0*reg5; T reg27=reg12*reg5; reg16=reg25-reg16;
    reg25=reg21*reg6; reg19=reg23-reg19; reg23=reg1*reg6; reg24=reg18+reg24; reg18=reg1*reg13;
    T reg28=reg2*reg21; reg8=reg8/reg22; reg11=reg11/reg22; reg15=reg15/reg24; reg19=reg19/reg24;
    reg22=reg14/reg22; reg14=reg8*reg5; T reg29=reg11*reg6; reg20=reg20/reg24; reg27=reg25-reg27;
    reg25=reg0*reg21; reg28=reg18-reg28; reg16=reg16/reg24; reg18=reg1*reg12; reg8=reg8*reg1;
    reg11=reg11*reg0; reg26=reg23-reg26; reg7=reg7*reg1; reg3=reg3*reg0; reg25=reg18-reg25;
    reg18=reg19-reg16; reg29=reg14+reg29; reg28=reg28/reg24; reg14=reg22*reg10; reg23=reg20-reg15;
    reg3=reg7+reg3; reg4=reg4*reg2; reg22=reg22*reg2; reg8=reg11+reg8; reg17=reg17/reg24;
    reg26=reg26/reg24; reg27=reg27/reg24; reg18=reg18+reg28; reg14=reg29+reg14; reg7=reg26-reg27;
    reg22=reg8+reg22; reg8=reg16*reg28; reg11=reg20*reg17; reg23=reg23-reg17; reg29=reg19*reg16;
    T reg30=reg15*reg20; reg4=reg3+reg4; reg24=reg25/reg24; reg3=reg18*reg16; reg25=pow(reg23,2);
    reg7=reg7-reg24; T reg31=reg23*reg20; T reg32=reg23*reg15; T reg33=pow(reg18,2); T reg34=pow(reg16,2);
    T reg35=pow(reg20,2); T reg36=reg19*reg28; T reg37=reg18*reg19; T reg38=reg27*reg26; T reg39=reg15*reg17;
    T reg40=reg30+reg29; reg22=reg9*reg22; reg9=pow(reg28,2); T reg41=pow(reg19,2); T reg42=pow(reg15,2);
    reg4=reg14*reg4; reg14=pow(reg17,2); T reg43=reg26*reg24; T reg44=reg18*reg28; T reg45=reg23*reg17;
    T reg46=reg11+reg8; T reg47=pow(reg26,2); reg34=reg34+reg35; reg39=reg39+reg36; T reg48=pow(reg7,2);
    reg32=reg32-reg37; T reg49=reg7*reg27; T reg50=reg27*reg24; reg3=reg3-reg31; T reg51=reg40+reg38;
    reg42=reg42+reg41; T reg52=pow(reg27,2); T reg53=reg7*reg24; reg45=reg45-reg44; T reg54=reg7*reg26;
    reg14=reg14+reg9; T reg55=pow(reg24,2); reg33=reg25+reg33; reg22=reg4-reg22; reg4=reg46+reg43;
    reg53=reg45+reg53; reg25=reg4*reg22; reg3=reg3-reg54; reg42=reg52+reg42; reg45=reg51*reg22;
    reg50=reg39+reg50; reg49=reg32+reg49; reg48=reg33+reg48; reg55=reg14+reg55; reg34=reg34+reg47;
    reg14=0.5*reg45; reg32=reg53*reg22; reg33=reg42*reg22; reg39=reg34*reg22; reg52=reg3*reg22;
    T reg56=reg50*reg22; T reg57=reg49*reg22; T reg58=0.5*reg25; T reg59=reg55*reg22; T reg60=reg48*reg22;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_3_0=0.5*reg57; T tmp_4_1=0.5*reg57;
    T tmp_5_2=0.5*reg57; T tmp_0_0=0.5*reg60; T tmp_1_1=0.5*reg60; T tmp_2_2=0.5*reg60; T tmp_0_6=0.5*reg52;
    T tmp_1_7=0.5*reg52; T tmp_2_8=0.5*reg52; T tmp_6_0=0.5*reg52; T tmp_7_1=0.5*reg52; T tmp_8_2=0.5*reg52;
    T tmp_0_9=0.5*reg32; T tmp_1_10=0.5*reg32; T tmp_2_11=0.5*reg32; T tmp_9_0=0.5*reg32; T tmp_10_1=0.5*reg32;
    T tmp_11_2=0.5*reg32; T tmp_3_3=0.5*reg33; T tmp_4_4=0.5*reg33; T tmp_5_5=0.5*reg33; T tmp_3_6=-reg14;
    T tmp_4_7=-reg14; T tmp_5_8=-reg14; T tmp_6_3=-reg14; T tmp_7_4=-reg14; T tmp_8_5=-reg14;
    T tmp_3_9=0.5*reg56; T tmp_4_10=0.5*reg56; T tmp_5_11=0.5*reg56; T tmp_9_3=0.5*reg56; T tmp_10_4=0.5*reg56;
    T tmp_11_5=0.5*reg56; T tmp_6_6=0.5*reg39; T tmp_7_7=0.5*reg39; T tmp_8_8=0.5*reg39; T tmp_6_9=-reg58;
    T tmp_7_10=-reg58; T tmp_8_11=-reg58; T tmp_9_6=-reg58; T tmp_10_7=-reg58; T tmp_11_8=-reg58;
    T tmp_9_9=0.5*reg59; T tmp_10_10=0.5*reg59; T tmp_11_11=0.5*reg59;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg4=reg5+reg4; reg4=pow(reg4,0.5); reg3=reg0/reg4;
    reg5=elem.pos(3)[0]-elem.pos(0)[0]; T reg6=elem.pos(3)[1]-elem.pos(0)[1]; T reg7=reg1/reg4; T reg8=reg7*reg5; T reg9=reg3*reg6;
    reg4=reg2/reg4; T reg10=elem.pos(3)[2]-elem.pos(0)[2]; reg8=reg9+reg8; reg9=reg4*reg10; reg9=reg8+reg9;
    reg8=reg9*reg7; T reg11=reg9*reg3; reg8=reg5-reg8; reg11=reg6-reg11; T reg12=elem.pos(2)[1]-elem.pos(0)[1];
    T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=reg9*reg4; reg14=reg10-reg14; T reg15=reg13*reg6; T reg16=pow(reg11,2);
    T reg17=pow(reg8,2); T reg18=reg12*reg10; T reg19=reg0*reg10; T reg20=reg2*reg6; T reg21=elem.pos(2)[0]-elem.pos(0)[0];
    T reg22=pow(reg14,2); reg15=reg18-reg15; reg20=reg19-reg20; reg18=reg0*reg13; reg16=reg17+reg16;
    reg17=reg2*reg12; reg17=reg18-reg17; reg22=reg16+reg22; reg16=reg1*reg15; reg18=reg21*reg20;
    reg19=reg13*reg5; T reg23=reg21*reg10; T reg24=reg5*reg17; reg22=pow(reg22,0.5); reg18=reg16-reg18;
    reg16=reg2*reg5; T reg25=reg1*reg10; T reg26=reg0*reg5; T reg27=reg12*reg5; reg16=reg25-reg16;
    reg25=reg21*reg6; reg19=reg23-reg19; reg23=reg1*reg6; reg24=reg18+reg24; reg18=reg1*reg13;
    T reg28=reg2*reg21; reg8=reg8/reg22; reg11=reg11/reg22; reg15=reg15/reg24; reg19=reg19/reg24;
    reg22=reg14/reg22; reg14=reg8*reg5; T reg29=reg11*reg6; reg20=reg20/reg24; reg27=reg25-reg27;
    reg25=reg0*reg21; reg28=reg18-reg28; reg16=reg16/reg24; reg18=reg1*reg12; reg8=reg8*reg1;
    reg11=reg11*reg0; reg26=reg23-reg26; reg7=reg7*reg1; reg3=reg3*reg0; reg25=reg18-reg25;
    reg18=reg19-reg16; reg29=reg14+reg29; reg28=reg28/reg24; reg14=reg22*reg10; reg23=reg20-reg15;
    reg3=reg7+reg3; reg4=reg4*reg2; reg22=reg22*reg2; reg8=reg11+reg8; reg17=reg17/reg24;
    reg26=reg26/reg24; reg27=reg27/reg24; reg18=reg18+reg28; reg14=reg29+reg14; reg7=reg26-reg27;
    reg22=reg8+reg22; reg8=reg16*reg28; reg11=reg20*reg17; reg23=reg23-reg17; reg29=reg19*reg16;
    T reg30=reg15*reg20; reg4=reg3+reg4; reg24=reg25/reg24; reg3=reg18*reg16; reg25=pow(reg23,2);
    reg7=reg7-reg24; T reg31=reg23*reg20; T reg32=reg23*reg15; T reg33=pow(reg18,2); T reg34=pow(reg16,2);
    T reg35=pow(reg20,2); T reg36=reg19*reg28; T reg37=reg18*reg19; T reg38=reg27*reg26; T reg39=reg15*reg17;
    T reg40=reg30+reg29; reg22=reg9*reg22; reg9=pow(reg28,2); T reg41=pow(reg19,2); T reg42=pow(reg15,2);
    reg4=reg14*reg4; reg14=pow(reg17,2); T reg43=reg26*reg24; T reg44=reg18*reg28; T reg45=reg23*reg17;
    T reg46=reg11+reg8; T reg47=pow(reg26,2); reg34=reg34+reg35; reg39=reg39+reg36; T reg48=pow(reg7,2);
    reg32=reg32-reg37; T reg49=reg7*reg27; T reg50=reg27*reg24; reg3=reg3-reg31; T reg51=reg40+reg38;
    reg42=reg42+reg41; T reg52=pow(reg27,2); T reg53=reg7*reg24; reg45=reg45-reg44; T reg54=reg7*reg26;
    reg14=reg14+reg9; T reg55=pow(reg24,2); reg33=reg25+reg33; reg22=reg4-reg22; reg4=reg46+reg43;
    reg53=reg45+reg53; reg25=reg4*reg22; reg3=reg3-reg54; reg42=reg52+reg42; reg45=reg51*reg22;
    reg50=reg39+reg50; reg49=reg32+reg49; reg48=reg33+reg48; reg55=reg14+reg55; reg34=reg34+reg47;
    reg14=0.5*reg45; reg32=reg53*reg22; reg33=reg42*reg22; reg39=reg34*reg22; reg52=reg3*reg22;
    T reg56=reg50*reg22; T reg57=reg49*reg22; T reg58=0.5*reg25; T reg59=reg55*reg22; T reg60=reg48*reg22;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_0_0=0.5*reg60; T tmp_1_1=0.5*reg60;
    T tmp_2_2=0.5*reg60; T tmp_0_6=0.5*reg52; T tmp_1_7=0.5*reg52; T tmp_2_8=0.5*reg52; T tmp_0_9=0.5*reg32;
    T tmp_1_10=0.5*reg32; T tmp_2_11=0.5*reg32; T tmp_3_3=0.5*reg33; T tmp_4_4=0.5*reg33; T tmp_5_5=0.5*reg33;
    T tmp_3_6=-reg14; T tmp_4_7=-reg14; T tmp_5_8=-reg14; T tmp_3_9=0.5*reg56; T tmp_4_10=0.5*reg56;
    T tmp_5_11=0.5*reg56; T tmp_6_6=0.5*reg39; T tmp_7_7=0.5*reg39; T tmp_8_8=0.5*reg39; T tmp_6_9=-reg58;
    T tmp_7_10=-reg58; T tmp_8_11=-reg58; T tmp_9_9=0.5*reg59; T tmp_10_10=0.5*reg59; T tmp_11_11=0.5*reg59;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg4=reg3+reg4; reg4=pow(reg4,0.5); reg3=elem.pos(3)[1]-elem.pos(0)[1];
    T reg5=reg1/reg4; T reg6=elem.pos(3)[0]-elem.pos(0)[0]; T reg7=reg0/reg4; T reg8=elem.pos(3)[2]-elem.pos(0)[2]; reg4=reg2/reg4;
    T reg9=reg7*reg3; T reg10=reg5*reg6; T reg11=reg4*reg8; reg10=reg9+reg10; reg9=elem.pos(2)[1]-elem.pos(0)[1];
    T reg12=elem.pos(2)[2]-elem.pos(0)[2]; reg11=reg10+reg11; reg10=reg9*reg8; T reg13=reg0*reg8; T reg14=reg12*reg3;
    T reg15=reg2*reg3; T reg16=reg11*reg7; T reg17=reg11*reg5; T reg18=elem.pos(2)[0]-elem.pos(0)[0]; T reg19=reg11*reg4;
    reg14=reg10-reg14; reg15=reg13-reg15; reg16=reg3-reg16; reg17=reg6-reg17; reg10=reg0*reg12;
    reg13=reg2*reg9; T reg20=reg1*reg14; reg13=reg10-reg13; reg19=reg8-reg19; reg10=pow(reg16,2);
    T reg21=pow(reg17,2); T reg22=reg18*reg15; T reg23=pow(reg19,2); reg10=reg21+reg10; reg22=reg20-reg22;
    reg20=reg6*reg13; reg21=reg1*reg8; T reg24=reg18*reg8; T reg25=reg12*reg6; T reg26=reg2*reg6;
    T reg27=reg2*reg18; reg23=reg10+reg23; reg10=reg1*reg12; T reg28=reg0*reg6; reg26=reg21-reg26;
    reg21=reg1*reg3; reg25=reg24-reg25; reg24=reg18*reg3; reg20=reg22+reg20; reg22=reg9*reg6;
    T reg29=reg0*reg18; reg28=reg21-reg28; reg27=reg10-reg27; reg10=reg1*reg9; reg21=vectors[0][indices[1]+1]-vectors[0][indices[0]+1];
    reg23=pow(reg23,0.5); T reg30=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; reg14=reg14/reg20; reg26=reg26/reg20; reg15=reg15/reg20;
    reg22=reg24-reg22; reg24=vectors[0][indices[2]+2]-vectors[0][indices[0]+2]; T reg31=vectors[0][indices[1]+2]-vectors[0][indices[0]+2]; T reg32=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg33=vectors[0][indices[2]+0]-vectors[0][indices[0]+0];
    reg25=reg25/reg20; reg27=reg27/reg20; reg13=reg13/reg20; reg28=reg28/reg20; reg22=reg22/reg20;
    reg29=reg10-reg29; reg10=reg21*reg25; T reg34=reg33*reg26; T reg35=vectors[0][indices[3]+0]-vectors[0][indices[0]+0]; T reg36=reg32*reg25;
    T reg37=reg33*reg15; T reg38=reg32*reg14; reg17=reg17/reg23; T reg39=reg31*reg25; reg16=reg16/reg23;
    T reg40=reg30*reg26; T reg41=reg24*reg26; T reg42=vectors[0][indices[3]+1]-vectors[0][indices[0]+1]; T reg43=reg30*reg15; T reg44=reg21*reg14;
    T reg45=reg31*reg14; T reg46=reg24*reg15; T reg47=vectors[0][indices[3]+2]-vectors[0][indices[0]+2]; reg24=reg24*reg28; T reg48=reg47*reg13;
    reg39=reg41-reg39; reg41=reg47*reg27; reg31=reg31*reg22; reg36=reg34-reg36; reg34=reg17*reg6;
    T reg49=reg16*reg3; reg17=reg17*reg1; reg16=reg16*reg0; reg7=reg7*reg0; reg5=reg5*reg1;
    reg46=reg45-reg46; reg33=reg33*reg28; reg32=reg32*reg22; reg45=reg35*reg27; reg23=reg19/reg23;
    reg19=reg35*reg13; reg37=reg38-reg37; reg30=reg30*reg28; reg21=reg21*reg22; reg38=reg42*reg27;
    reg10=reg40-reg10; reg40=reg42*reg13; reg43=reg44-reg43; reg44=reg25-reg26; reg20=reg29/reg20;
    reg29=reg15-reg14; reg4=reg4*reg2; reg49=reg34+reg49; reg24=reg31-reg24; reg47=reg47*reg20;
    reg31=reg23*reg2; reg23=reg23*reg8; reg41=reg39-reg41; reg48=reg46+reg48; reg17=reg16+reg17;
    reg33=reg32-reg33; reg35=reg35*reg20; reg45=reg36-reg45; reg7=reg5+reg7; reg19=reg37+reg19;
    reg42=reg42*reg20; reg44=reg44+reg27; reg29=reg29-reg13; reg5=reg28-reg22; reg40=reg43+reg40;
    reg38=reg10-reg38; reg30=reg21-reg30; reg10=reg29*reg40; reg42=reg30+reg42; reg16=reg38*reg26;
    reg21=reg40*reg15; reg24=reg47+reg24; reg30=reg45*reg44; reg32=reg19*reg14; reg34=reg29*reg19;
    reg36=reg45*reg25; reg5=reg5-reg20; reg37=reg45*reg26; reg39=reg41*reg44; reg43=reg19*reg15;
    reg46=reg41*reg25; reg47=reg48*reg14; reg33=reg35+reg33; reg35=reg38*reg44; T reg50=reg38*reg25;
    T reg51=reg40*reg14; T reg52=reg29*reg48; reg31=reg17+reg31; reg17=reg38*reg27; T reg53=reg40*reg13;
    T reg54=reg19*reg13; T reg55=reg45*reg27; T reg56=reg48*reg15; T reg57=reg41*reg27; T reg58=reg48*reg13;
    reg4=reg7+reg4; reg23=reg49+reg23; reg7=reg41*reg26; reg47=reg47-reg46; reg49=reg42*reg5;
    reg53=reg53-reg17; T reg59=reg42*reg20; T reg60=reg24*reg22; reg51=reg51-reg50; reg58=reg58-reg57;
    reg39=reg52+reg39; reg4=reg23*reg4; reg23=reg42*reg22; reg52=reg24*reg5; T reg61=reg42*reg28;
    reg35=reg10+reg35; reg10=reg24*reg28; T reg62=reg24*reg20; reg16=reg16-reg21; reg30=reg34+reg30;
    reg54=reg54-reg55; reg34=reg33*reg20; T reg63=reg33*reg5; T reg64=reg33*reg28; reg37=reg37-reg43;
    reg7=reg7-reg56; reg31=reg11*reg31; reg32=reg32-reg36; reg11=reg33*reg22; reg62=reg58+reg62;
    reg11=reg32+reg11; reg52=reg39+reg52; reg16=reg16-reg61; reg23=reg51+reg23; reg60=reg47+reg60;
    reg59=reg53+reg59; reg49=reg35+reg49; reg34=reg54+reg34; reg31=reg4-reg31; reg63=reg30+reg63;
    reg37=reg37-reg64; reg7=reg7-reg10; reg4=reg52*reg31; reg30=reg11*reg31; reg32=reg49*reg31;
    reg35=reg16*reg31; reg39=reg23*reg31; reg47=reg60*reg31; reg51=reg62*reg31; reg53=reg63*reg31;
    reg54=reg59*reg31; reg58=reg34*reg31; T reg65=reg37*reg31; T reg66=reg7*reg31; T vec_9=0.5*reg58;
    T vec_4=0.5*reg39; T vec_0=0.5*reg53; T vec_1=0.5*reg32; T vec_7=0.5*reg35; T vec_8=0.5*reg66;
    T vec_3=0.5*reg30; T vec_10=0.5*reg54; T vec_11=0.5*reg51; T vec_6=0.5*reg65; T vec_5=0.5*reg47;
    T vec_2=0.5*reg4;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[0]+2] += vec_2;
sollicitation[indices[1]+0] += vec_3;
sollicitation[indices[1]+1] += vec_4;
sollicitation[indices[1]+2] += vec_5;
sollicitation[indices[2]+0] += vec_6;
sollicitation[indices[2]+1] += vec_7;
sollicitation[indices[2]+2] += vec_8;
sollicitation[indices[3]+0] += vec_9;
sollicitation[indices[3]+1] += vec_10;
sollicitation[indices[3]+2] += vec_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(3)[0]-elem.pos(0)[0]; T reg1=elem.pos(3)[1]-elem.pos(0)[1]; T reg2=elem.pos(3)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg3=reg4+reg3; reg3=pow(reg3,0.5); reg4=reg0/reg3;
    T reg5=reg1/reg3; T reg6=elem.pos(2)[1]-elem.pos(0)[1]; T reg7=elem.pos(2)[0]-elem.pos(0)[0]; reg3=reg2/reg3; T reg8=elem.pos(2)[2]-elem.pos(0)[2];
    T reg9=reg4*reg7; T reg10=reg5*reg6; T reg11=reg3*reg8; reg10=reg9+reg10; reg10=reg11+reg10;
    reg9=reg5*reg10; reg11=reg4*reg10; reg11=reg7-reg11; reg9=reg6-reg9; T reg12=elem.pos(1)[1]-elem.pos(0)[1];
    T reg13=elem.pos(1)[2]-elem.pos(0)[2]; T reg14=reg10*reg3; T reg15=reg13*reg1; T reg16=reg6*reg2; T reg17=reg12*reg2;
    T reg18=pow(reg9,2); T reg19=reg8*reg1; T reg20=pow(reg11,2); reg14=reg8-reg14; T reg21=reg13*reg6;
    T reg22=reg12*reg8; reg20=reg18+reg20; reg15=reg17-reg15; reg19=reg16-reg19; reg16=pow(reg14,2);
    reg17=elem.pos(1)[0]-elem.pos(0)[0]; reg21=reg22-reg21; reg18=reg17*reg19; reg16=reg20+reg16; reg20=reg7*reg15;
    reg22=reg7*reg2; T reg23=reg0*reg21; T reg24=reg8*reg0; T reg25=reg13*reg0; reg20=reg18-reg20;
    reg18=reg17*reg2; reg16=pow(reg16,0.5); reg24=reg22-reg24; reg23=reg20+reg23; reg20=reg7*reg1;
    reg22=reg6*reg0; T reg26=reg17*reg1; reg25=reg18-reg25; reg18=reg12*reg0; T reg27=reg17*reg8;
    T reg28=reg13*reg7; reg11=reg11/reg16; reg9=reg9/reg16; T reg29=reg9*reg1; T reg30=reg11*reg0;
    reg16=reg14/reg16; reg4=reg4*reg0; reg11=reg11*reg7; reg9=reg9*reg6; reg19=reg19/reg23;
    reg24=reg24/reg23; reg5=reg5*reg1; reg14=reg12*reg7; reg22=reg20-reg22; reg15=reg15/reg23;
    reg28=reg27-reg28; reg25=reg25/reg23; reg20=reg17*reg6; reg18=reg26-reg18; reg29=reg30+reg29;
    reg26=reg15-reg19; reg14=reg20-reg14; reg28=reg28/reg23; reg21=reg21/reg23; reg18=reg18/reg23;
    reg20=reg16*reg8; reg4=reg5+reg4; reg22=reg22/reg23; reg16=reg16*reg2; reg5=reg24-reg25;
    reg9=reg11+reg9; reg3=reg3*reg2; reg20=reg9+reg20; reg23=reg14/reg23; reg9=reg18-reg22;
    reg5=reg5+reg28; reg11=reg19*reg15; reg14=reg24*reg25; reg26=reg26-reg21; reg27=reg25*reg28;
    reg30=reg15*reg21; reg16=reg29+reg16; reg4=reg3+reg4; reg3=reg18*reg23; reg29=pow(reg15,2);
    T reg31=pow(reg28,2); T reg32=reg5*reg25; T reg33=reg26*reg15; T reg34=reg5*reg24; T reg35=reg30+reg27;
    T reg36=pow(reg21,2); T reg37=reg26*reg21; T reg38=pow(reg25,2); T reg39=reg24*reg28; T reg40=reg22*reg18;
    T reg41=reg19*reg21; T reg42=reg11+reg14; T reg43=pow(reg24,2); T reg44=pow(reg19,2); T reg45=reg5*reg28;
    T reg46=reg26*reg19; T reg47=pow(reg26,2); T reg48=pow(reg5,2); reg9=reg9-reg23; reg20=reg4*reg20;
    reg16=reg10*reg16; reg16=reg20-reg16; reg4=pow(reg23,2); reg36=reg36+reg31; reg10=reg35+reg3;
    reg20=reg42+reg40; reg41=reg41+reg39; T reg49=reg22*reg23; T reg50=pow(reg9,2); T reg51=pow(reg18,2);
    reg38=reg38+reg29; T reg52=reg9*reg18; reg32=reg32-reg33; reg48=reg47+reg48; reg44=reg44+reg43;
    reg47=reg9*reg22; reg46=reg46-reg34; T reg53=pow(reg22,2); T reg54=reg9*reg23; reg37=reg37-reg45;
    reg32=reg32-reg52; reg38=reg38+reg51; reg50=reg48+reg50; reg44=reg53+reg44; reg49=reg41+reg49;
    reg54=reg37+reg54; reg4=reg36+reg4; reg36=reg10*reg16; reg47=reg46+reg47; reg37=reg20*reg16;
    reg41=reg50*reg16; reg46=0.5*reg36; reg48=reg4*reg16; reg53=reg49*reg16; T reg55=0.5*reg37;
    T reg56=reg44*reg16; T reg57=reg54*reg16; T reg58=reg32*reg16; T reg59=reg47*reg16; T reg60=reg38*reg16;
    T tmp_0_9=0.5*reg57; T tmp_1_10=0.5*reg57; T tmp_2_11=0.5*reg57; T tmp_9_0=0.5*reg57; T tmp_10_1=0.5*reg57;
    T tmp_11_2=0.5*reg57; T tmp_3_3=0.5*reg56; T tmp_4_4=0.5*reg56; T tmp_5_5=0.5*reg56; T tmp_0_6=0.5*reg58;
    T tmp_1_7=0.5*reg58; T tmp_2_8=0.5*reg58; T tmp_6_0=0.5*reg58; T tmp_7_1=0.5*reg58; T tmp_8_2=0.5*reg58;
    T tmp_3_6=-reg55; T tmp_4_7=-reg55; T tmp_5_8=-reg55; T tmp_6_3=-reg55; T tmp_7_4=-reg55;
    T tmp_8_5=-reg55; T tmp_0_3=0.5*reg59; T tmp_1_4=0.5*reg59; T tmp_2_5=0.5*reg59; T tmp_3_0=0.5*reg59;
    T tmp_4_1=0.5*reg59; T tmp_5_2=0.5*reg59; T tmp_3_9=0.5*reg53; T tmp_4_10=0.5*reg53; T tmp_5_11=0.5*reg53;
    T tmp_9_3=0.5*reg53; T tmp_10_4=0.5*reg53; T tmp_11_5=0.5*reg53; T tmp_9_9=0.5*reg48; T tmp_10_10=0.5*reg48;
    T tmp_11_11=0.5*reg48; T tmp_6_9=-reg46; T tmp_7_10=-reg46; T tmp_8_11=-reg46; T tmp_9_6=-reg46;
    T tmp_10_7=-reg46; T tmp_11_8=-reg46; T tmp_0_0=0.5*reg41; T tmp_1_1=0.5*reg41; T tmp_2_2=0.5*reg41;
    T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(3)[0]-elem.pos(0)[0]; T reg1=elem.pos(3)[1]-elem.pos(0)[1]; T reg2=elem.pos(3)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg3=reg4+reg3; reg3=pow(reg3,0.5); reg4=reg0/reg3;
    T reg5=reg1/reg3; T reg6=elem.pos(2)[1]-elem.pos(0)[1]; T reg7=elem.pos(2)[0]-elem.pos(0)[0]; reg3=reg2/reg3; T reg8=elem.pos(2)[2]-elem.pos(0)[2];
    T reg9=reg4*reg7; T reg10=reg5*reg6; T reg11=reg3*reg8; reg10=reg9+reg10; reg10=reg11+reg10;
    reg9=reg5*reg10; reg11=reg4*reg10; reg11=reg7-reg11; reg9=reg6-reg9; T reg12=elem.pos(1)[1]-elem.pos(0)[1];
    T reg13=elem.pos(1)[2]-elem.pos(0)[2]; T reg14=reg10*reg3; T reg15=reg13*reg1; T reg16=reg6*reg2; T reg17=reg12*reg2;
    T reg18=pow(reg9,2); T reg19=reg8*reg1; T reg20=pow(reg11,2); reg14=reg8-reg14; T reg21=reg13*reg6;
    T reg22=reg12*reg8; reg20=reg18+reg20; reg15=reg17-reg15; reg19=reg16-reg19; reg16=pow(reg14,2);
    reg17=elem.pos(1)[0]-elem.pos(0)[0]; reg21=reg22-reg21; reg18=reg17*reg19; reg16=reg20+reg16; reg20=reg7*reg15;
    reg22=reg7*reg2; T reg23=reg0*reg21; T reg24=reg8*reg0; T reg25=reg13*reg0; reg20=reg18-reg20;
    reg18=reg17*reg2; reg16=pow(reg16,0.5); reg24=reg22-reg24; reg23=reg20+reg23; reg20=reg7*reg1;
    reg22=reg6*reg0; T reg26=reg17*reg1; reg25=reg18-reg25; reg18=reg12*reg0; T reg27=reg17*reg8;
    T reg28=reg13*reg7; reg11=reg11/reg16; reg9=reg9/reg16; T reg29=reg9*reg1; T reg30=reg11*reg0;
    reg16=reg14/reg16; reg4=reg4*reg0; reg11=reg11*reg7; reg9=reg9*reg6; reg19=reg19/reg23;
    reg24=reg24/reg23; reg5=reg5*reg1; reg14=reg12*reg7; reg22=reg20-reg22; reg15=reg15/reg23;
    reg28=reg27-reg28; reg25=reg25/reg23; reg20=reg17*reg6; reg18=reg26-reg18; reg29=reg30+reg29;
    reg26=reg15-reg19; reg14=reg20-reg14; reg28=reg28/reg23; reg21=reg21/reg23; reg18=reg18/reg23;
    reg20=reg16*reg8; reg4=reg5+reg4; reg22=reg22/reg23; reg16=reg16*reg2; reg5=reg24-reg25;
    reg9=reg11+reg9; reg3=reg3*reg2; reg20=reg9+reg20; reg23=reg14/reg23; reg9=reg18-reg22;
    reg5=reg5+reg28; reg11=reg19*reg15; reg14=reg24*reg25; reg26=reg26-reg21; reg27=reg25*reg28;
    reg30=reg15*reg21; reg16=reg29+reg16; reg4=reg3+reg4; reg3=reg18*reg23; reg29=pow(reg15,2);
    T reg31=pow(reg28,2); T reg32=reg5*reg25; T reg33=reg26*reg15; T reg34=reg5*reg24; T reg35=reg30+reg27;
    T reg36=pow(reg21,2); T reg37=reg26*reg21; T reg38=pow(reg25,2); T reg39=reg24*reg28; T reg40=reg22*reg18;
    T reg41=reg19*reg21; T reg42=reg11+reg14; T reg43=pow(reg24,2); T reg44=pow(reg19,2); T reg45=reg5*reg28;
    T reg46=reg26*reg19; T reg47=pow(reg26,2); T reg48=pow(reg5,2); reg9=reg9-reg23; reg20=reg4*reg20;
    reg16=reg10*reg16; reg16=reg20-reg16; reg4=pow(reg23,2); reg36=reg36+reg31; reg10=reg35+reg3;
    reg20=reg42+reg40; reg41=reg41+reg39; T reg49=reg22*reg23; T reg50=pow(reg9,2); T reg51=pow(reg18,2);
    reg38=reg38+reg29; T reg52=reg9*reg18; reg32=reg32-reg33; reg48=reg47+reg48; reg44=reg44+reg43;
    reg47=reg9*reg22; reg46=reg46-reg34; T reg53=pow(reg22,2); T reg54=reg9*reg23; reg37=reg37-reg45;
    reg32=reg32-reg52; reg38=reg38+reg51; reg50=reg48+reg50; reg44=reg53+reg44; reg49=reg41+reg49;
    reg54=reg37+reg54; reg4=reg36+reg4; reg36=reg10*reg16; reg47=reg46+reg47; reg37=reg20*reg16;
    reg41=reg50*reg16; reg46=0.5*reg36; reg48=reg4*reg16; reg53=reg49*reg16; T reg55=0.5*reg37;
    T reg56=reg44*reg16; T reg57=reg54*reg16; T reg58=reg32*reg16; T reg59=reg47*reg16; T reg60=reg38*reg16;
    T tmp_0_9=0.5*reg57; T tmp_1_10=0.5*reg57; T tmp_2_11=0.5*reg57; T tmp_3_3=0.5*reg56; T tmp_4_4=0.5*reg56;
    T tmp_5_5=0.5*reg56; T tmp_0_6=0.5*reg58; T tmp_1_7=0.5*reg58; T tmp_2_8=0.5*reg58; T tmp_3_6=-reg55;
    T tmp_4_7=-reg55; T tmp_5_8=-reg55; T tmp_0_3=0.5*reg59; T tmp_1_4=0.5*reg59; T tmp_2_5=0.5*reg59;
    T tmp_3_9=0.5*reg53; T tmp_4_10=0.5*reg53; T tmp_5_11=0.5*reg53; T tmp_9_9=0.5*reg48; T tmp_10_10=0.5*reg48;
    T tmp_11_11=0.5*reg48; T tmp_6_9=-reg46; T tmp_7_10=-reg46; T tmp_8_11=-reg46; T tmp_0_0=0.5*reg41;
    T tmp_1_1=0.5*reg41; T tmp_2_2=0.5*reg41; T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(3)[0]-elem.pos(0)[0]; T reg1=elem.pos(3)[1]-elem.pos(0)[1]; T reg2=elem.pos(3)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg3=reg4+reg3; reg3=pow(reg3,0.5); reg4=reg0/reg3;
    T reg5=reg1/reg3; T reg6=elem.pos(2)[1]-elem.pos(0)[1]; T reg7=elem.pos(2)[0]-elem.pos(0)[0]; reg3=reg2/reg3; T reg8=elem.pos(2)[2]-elem.pos(0)[2];
    T reg9=reg4*reg7; T reg10=reg5*reg6; T reg11=reg3*reg8; reg10=reg9+reg10; reg10=reg11+reg10;
    reg9=reg5*reg10; reg11=reg4*reg10; reg11=reg7-reg11; reg9=reg6-reg9; T reg12=elem.pos(1)[1]-elem.pos(0)[1];
    T reg13=elem.pos(1)[2]-elem.pos(0)[2]; T reg14=reg10*reg3; T reg15=reg13*reg1; T reg16=reg6*reg2; T reg17=reg12*reg2;
    T reg18=pow(reg9,2); T reg19=reg8*reg1; T reg20=pow(reg11,2); reg14=reg8-reg14; T reg21=reg13*reg6;
    T reg22=reg12*reg8; reg20=reg18+reg20; reg15=reg17-reg15; reg19=reg16-reg19; reg16=pow(reg14,2);
    reg17=elem.pos(1)[0]-elem.pos(0)[0]; reg21=reg22-reg21; reg18=reg17*reg19; reg16=reg20+reg16; reg20=reg7*reg15;
    reg22=reg7*reg2; T reg23=reg0*reg21; T reg24=reg8*reg0; T reg25=reg13*reg0; reg20=reg18-reg20;
    reg18=reg17*reg2; reg16=pow(reg16,0.5); reg24=reg22-reg24; reg23=reg20+reg23; reg20=reg7*reg1;
    reg22=reg6*reg0; T reg26=reg17*reg1; reg25=reg18-reg25; reg18=reg12*reg0; T reg27=reg17*reg8;
    T reg28=reg13*reg7; reg11=reg11/reg16; reg9=reg9/reg16; T reg29=reg9*reg1; T reg30=reg11*reg0;
    reg16=reg14/reg16; reg4=reg4*reg0; reg11=reg11*reg7; reg9=reg9*reg6; reg19=reg19/reg23;
    reg24=reg24/reg23; reg5=reg5*reg1; reg14=reg12*reg7; reg22=reg20-reg22; reg15=reg15/reg23;
    reg28=reg27-reg28; reg25=reg25/reg23; reg20=reg17*reg6; reg18=reg26-reg18; reg29=reg30+reg29;
    reg26=reg15-reg19; reg14=reg20-reg14; reg28=reg28/reg23; reg21=reg21/reg23; reg18=reg18/reg23;
    reg20=reg16*reg8; reg4=reg5+reg4; reg22=reg22/reg23; reg16=reg16*reg2; reg5=reg24-reg25;
    reg9=reg11+reg9; reg3=reg3*reg2; reg20=reg9+reg20; reg23=reg14/reg23; reg9=reg18-reg22;
    reg5=reg5+reg28; reg11=reg19*reg15; reg14=reg24*reg25; reg26=reg26-reg21; reg27=reg25*reg28;
    reg30=reg15*reg21; reg16=reg29+reg16; reg4=reg3+reg4; reg3=reg18*reg23; reg29=pow(reg15,2);
    T reg31=pow(reg28,2); T reg32=reg5*reg25; T reg33=reg26*reg15; T reg34=reg5*reg24; T reg35=reg30+reg27;
    T reg36=pow(reg21,2); T reg37=reg26*reg21; T reg38=pow(reg25,2); T reg39=reg24*reg28; T reg40=reg22*reg18;
    T reg41=reg19*reg21; T reg42=reg11+reg14; T reg43=pow(reg24,2); T reg44=pow(reg19,2); T reg45=reg5*reg28;
    T reg46=reg26*reg19; T reg47=pow(reg26,2); T reg48=pow(reg5,2); reg9=reg9-reg23; reg20=reg4*reg20;
    reg16=reg10*reg16; reg16=reg20-reg16; reg4=pow(reg23,2); reg36=reg36+reg31; reg10=reg35+reg3;
    reg20=reg42+reg40; reg41=reg41+reg39; T reg49=reg22*reg23; T reg50=pow(reg9,2); T reg51=pow(reg18,2);
    reg38=reg38+reg29; T reg52=reg9*reg18; reg32=reg32-reg33; reg48=reg47+reg48; reg44=reg44+reg43;
    reg47=reg9*reg22; reg46=reg46-reg34; T reg53=pow(reg22,2); T reg54=reg9*reg23; reg37=reg37-reg45;
    reg32=reg32-reg52; reg38=reg38+reg51; reg50=reg48+reg50; reg44=reg53+reg44; reg49=reg41+reg49;
    reg54=reg37+reg54; reg4=reg36+reg4; reg36=reg10*reg16; reg47=reg46+reg47; reg37=reg20*reg16;
    reg41=reg50*reg16; reg46=0.5*reg36; reg48=reg4*reg16; reg53=reg49*reg16; T reg55=0.5*reg37;
    T reg56=reg44*reg16; T reg57=reg54*reg16; T reg58=reg32*reg16; T reg59=reg47*reg16; T reg60=reg38*reg16;
    T tmp_0_9=0.5*reg57; T tmp_1_10=0.5*reg57; T tmp_2_11=0.5*reg57; T tmp_9_0=0.5*reg57; T tmp_10_1=0.5*reg57;
    T tmp_11_2=0.5*reg57; T tmp_3_3=0.5*reg56; T tmp_4_4=0.5*reg56; T tmp_5_5=0.5*reg56; T tmp_0_6=0.5*reg58;
    T tmp_1_7=0.5*reg58; T tmp_2_8=0.5*reg58; T tmp_6_0=0.5*reg58; T tmp_7_1=0.5*reg58; T tmp_8_2=0.5*reg58;
    T tmp_3_6=-reg55; T tmp_4_7=-reg55; T tmp_5_8=-reg55; T tmp_6_3=-reg55; T tmp_7_4=-reg55;
    T tmp_8_5=-reg55; T tmp_0_3=0.5*reg59; T tmp_1_4=0.5*reg59; T tmp_2_5=0.5*reg59; T tmp_3_0=0.5*reg59;
    T tmp_4_1=0.5*reg59; T tmp_5_2=0.5*reg59; T tmp_3_9=0.5*reg53; T tmp_4_10=0.5*reg53; T tmp_5_11=0.5*reg53;
    T tmp_9_3=0.5*reg53; T tmp_10_4=0.5*reg53; T tmp_11_5=0.5*reg53; T tmp_9_9=0.5*reg48; T tmp_10_10=0.5*reg48;
    T tmp_11_11=0.5*reg48; T tmp_6_9=-reg46; T tmp_7_10=-reg46; T tmp_8_11=-reg46; T tmp_9_6=-reg46;
    T tmp_10_7=-reg46; T tmp_11_8=-reg46; T tmp_0_0=0.5*reg41; T tmp_1_1=0.5*reg41; T tmp_2_2=0.5*reg41;
    T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(3)[0]-elem.pos(0)[0]; T reg1=elem.pos(3)[1]-elem.pos(0)[1]; T reg2=elem.pos(3)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg3=reg4+reg3; reg3=pow(reg3,0.5); reg4=reg0/reg3;
    T reg5=reg1/reg3; T reg6=elem.pos(2)[1]-elem.pos(0)[1]; T reg7=elem.pos(2)[0]-elem.pos(0)[0]; reg3=reg2/reg3; T reg8=elem.pos(2)[2]-elem.pos(0)[2];
    T reg9=reg4*reg7; T reg10=reg5*reg6; T reg11=reg3*reg8; reg10=reg9+reg10; reg10=reg11+reg10;
    reg9=reg5*reg10; reg11=reg4*reg10; reg11=reg7-reg11; reg9=reg6-reg9; T reg12=elem.pos(1)[1]-elem.pos(0)[1];
    T reg13=elem.pos(1)[2]-elem.pos(0)[2]; T reg14=reg10*reg3; T reg15=reg13*reg1; T reg16=reg6*reg2; T reg17=reg12*reg2;
    T reg18=pow(reg9,2); T reg19=reg8*reg1; T reg20=pow(reg11,2); reg14=reg8-reg14; T reg21=reg13*reg6;
    T reg22=reg12*reg8; reg20=reg18+reg20; reg15=reg17-reg15; reg19=reg16-reg19; reg16=pow(reg14,2);
    reg17=elem.pos(1)[0]-elem.pos(0)[0]; reg21=reg22-reg21; reg18=reg17*reg19; reg16=reg20+reg16; reg20=reg7*reg15;
    reg22=reg7*reg2; T reg23=reg0*reg21; T reg24=reg8*reg0; T reg25=reg13*reg0; reg20=reg18-reg20;
    reg18=reg17*reg2; reg16=pow(reg16,0.5); reg24=reg22-reg24; reg23=reg20+reg23; reg20=reg7*reg1;
    reg22=reg6*reg0; T reg26=reg17*reg1; reg25=reg18-reg25; reg18=reg12*reg0; T reg27=reg17*reg8;
    T reg28=reg13*reg7; reg11=reg11/reg16; reg9=reg9/reg16; T reg29=reg9*reg1; T reg30=reg11*reg0;
    reg16=reg14/reg16; reg4=reg4*reg0; reg11=reg11*reg7; reg9=reg9*reg6; reg19=reg19/reg23;
    reg24=reg24/reg23; reg5=reg5*reg1; reg14=reg12*reg7; reg22=reg20-reg22; reg15=reg15/reg23;
    reg28=reg27-reg28; reg25=reg25/reg23; reg20=reg17*reg6; reg18=reg26-reg18; reg29=reg30+reg29;
    reg26=reg15-reg19; reg14=reg20-reg14; reg28=reg28/reg23; reg21=reg21/reg23; reg18=reg18/reg23;
    reg20=reg16*reg8; reg4=reg5+reg4; reg22=reg22/reg23; reg16=reg16*reg2; reg5=reg24-reg25;
    reg9=reg11+reg9; reg3=reg3*reg2; reg20=reg9+reg20; reg23=reg14/reg23; reg9=reg18-reg22;
    reg5=reg5+reg28; reg11=reg19*reg15; reg14=reg24*reg25; reg26=reg26-reg21; reg27=reg25*reg28;
    reg30=reg15*reg21; reg16=reg29+reg16; reg4=reg3+reg4; reg3=reg18*reg23; reg29=pow(reg15,2);
    T reg31=pow(reg28,2); T reg32=reg5*reg25; T reg33=reg26*reg15; T reg34=reg5*reg24; T reg35=reg30+reg27;
    T reg36=pow(reg21,2); T reg37=reg26*reg21; T reg38=pow(reg25,2); T reg39=reg24*reg28; T reg40=reg22*reg18;
    T reg41=reg19*reg21; T reg42=reg11+reg14; T reg43=pow(reg24,2); T reg44=pow(reg19,2); T reg45=reg5*reg28;
    T reg46=reg26*reg19; T reg47=pow(reg26,2); T reg48=pow(reg5,2); reg9=reg9-reg23; reg20=reg4*reg20;
    reg16=reg10*reg16; reg16=reg20-reg16; reg4=pow(reg23,2); reg36=reg36+reg31; reg10=reg35+reg3;
    reg20=reg42+reg40; reg41=reg41+reg39; T reg49=reg22*reg23; T reg50=pow(reg9,2); T reg51=pow(reg18,2);
    reg38=reg38+reg29; T reg52=reg9*reg18; reg32=reg32-reg33; reg48=reg47+reg48; reg44=reg44+reg43;
    reg47=reg9*reg22; reg46=reg46-reg34; T reg53=pow(reg22,2); T reg54=reg9*reg23; reg37=reg37-reg45;
    reg32=reg32-reg52; reg38=reg38+reg51; reg50=reg48+reg50; reg44=reg53+reg44; reg49=reg41+reg49;
    reg54=reg37+reg54; reg4=reg36+reg4; reg36=reg10*reg16; reg47=reg46+reg47; reg37=reg20*reg16;
    reg41=reg50*reg16; reg46=0.5*reg36; reg48=reg4*reg16; reg53=reg49*reg16; T reg55=0.5*reg37;
    T reg56=reg44*reg16; T reg57=reg54*reg16; T reg58=reg32*reg16; T reg59=reg47*reg16; T reg60=reg38*reg16;
    T tmp_0_9=0.5*reg57; T tmp_1_10=0.5*reg57; T tmp_2_11=0.5*reg57; T tmp_3_3=0.5*reg56; T tmp_4_4=0.5*reg56;
    T tmp_5_5=0.5*reg56; T tmp_0_6=0.5*reg58; T tmp_1_7=0.5*reg58; T tmp_2_8=0.5*reg58; T tmp_3_6=-reg55;
    T tmp_4_7=-reg55; T tmp_5_8=-reg55; T tmp_0_3=0.5*reg59; T tmp_1_4=0.5*reg59; T tmp_2_5=0.5*reg59;
    T tmp_3_9=0.5*reg53; T tmp_4_10=0.5*reg53; T tmp_5_11=0.5*reg53; T tmp_9_9=0.5*reg48; T tmp_10_10=0.5*reg48;
    T tmp_11_11=0.5*reg48; T tmp_6_9=-reg46; T tmp_7_10=-reg46; T tmp_8_11=-reg46; T tmp_0_0=0.5*reg41;
    T tmp_1_1=0.5*reg41; T tmp_2_2=0.5*reg41; T tmp_6_6=0.5*reg60; T tmp_7_7=0.5*reg60; T tmp_8_8=0.5*reg60;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(3)[0]-elem.pos(0)[0]; T reg1=elem.pos(3)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(3)[2]-elem.pos(0)[2];
    T reg5=pow(reg4,2); reg2=reg3+reg2; reg5=reg2+reg5; reg5=pow(reg5,0.5); reg2=reg1/reg5;
    reg3=reg0/reg5; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(2)[1]-elem.pos(0)[1]; T reg8=elem.pos(2)[2]-elem.pos(0)[2]; reg5=reg4/reg5;
    T reg9=reg2*reg7; T reg10=reg3*reg6; reg9=reg10+reg9; reg10=reg5*reg8; T reg11=elem.pos(1)[1]-elem.pos(0)[1];
    T reg12=elem.pos(1)[2]-elem.pos(0)[2]; reg9=reg10+reg9; reg10=reg7*reg4; T reg13=reg11*reg4; T reg14=reg8*reg1;
    T reg15=reg2*reg9; T reg16=reg3*reg9; T reg17=reg12*reg1; reg14=reg10-reg14; reg10=reg11*reg8;
    reg17=reg13-reg17; reg13=elem.pos(1)[0]-elem.pos(0)[0]; T reg18=reg9*reg5; T reg19=reg12*reg7; reg15=reg7-reg15;
    reg16=reg6-reg16; reg19=reg10-reg19; reg18=reg8-reg18; reg10=pow(reg16,2); T reg20=pow(reg15,2);
    T reg21=reg13*reg14; T reg22=reg6*reg17; reg10=reg20+reg10; reg22=reg21-reg22; reg20=pow(reg18,2);
    reg21=reg8*reg0; T reg23=reg0*reg19; T reg24=reg6*reg4; T reg25=reg12*reg0; T reg26=reg13*reg4;
    reg25=reg26-reg25; reg26=reg11*reg0; T reg27=reg13*reg8; reg20=reg10+reg20; reg10=reg12*reg6;
    T reg28=reg13*reg1; reg23=reg22+reg23; reg22=reg6*reg1; reg21=reg24-reg21; reg24=reg7*reg0;
    reg14=reg14/reg23; reg21=reg21/reg23; T reg29=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg30=vectors[0][indices[1]+2]-vectors[0][indices[0]+2]; T reg31=vectors[0][indices[2]+2]-vectors[0][indices[0]+2];
    T reg32=reg11*reg6; reg10=reg27-reg10; reg27=reg13*reg7; T reg33=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg34=vectors[0][indices[1]+0]-vectors[0][indices[0]+0];
    T reg35=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; reg26=reg28-reg26; reg20=pow(reg20,0.5); reg24=reg22-reg24; reg17=reg17/reg23;
    reg25=reg25/reg23; reg10=reg10/reg23; reg24=reg24/reg23; reg19=reg19/reg23; reg16=reg16/reg20;
    reg15=reg15/reg20; reg32=reg27-reg32; reg26=reg26/reg23; reg22=reg34*reg21; reg27=reg29*reg17;
    reg28=reg35*reg25; T reg36=vectors[0][indices[3]+0]-vectors[0][indices[0]+0]; T reg37=vectors[0][indices[3]+1]-vectors[0][indices[0]+1]; T reg38=reg33*reg21; T reg39=vectors[0][indices[3]+2]-vectors[0][indices[0]+2];
    T reg40=reg35*reg17; T reg41=reg33*reg14; T reg42=reg29*reg25; T reg43=reg34*reg14; T reg44=reg31*reg25;
    T reg45=reg30*reg21; T reg46=reg31*reg17; T reg47=reg30*reg14; T reg48=reg36*reg19; reg45=reg44-reg45;
    reg44=reg39*reg10; reg35=reg35*reg26; T reg49=reg39*reg19; reg27=reg43-reg27; reg33=reg33*reg24;
    reg22=reg42-reg22; reg46=reg47-reg46; reg42=reg36*reg10; reg2=reg2*reg1; reg29=reg29*reg26;
    reg34=reg34*reg24; reg43=reg37*reg19; reg47=reg17-reg14; reg23=reg32/reg23; reg3=reg3*reg0;
    reg32=reg16*reg0; reg30=reg30*reg24; T reg50=reg21-reg25; T reg51=reg15*reg1; reg20=reg18/reg20;
    reg40=reg41-reg40; reg15=reg15*reg7; reg31=reg31*reg26; reg16=reg16*reg6; reg38=reg28-reg38;
    reg18=reg37*reg10; reg49=reg46+reg49; reg28=reg26-reg24; reg15=reg16+reg15; reg16=reg20*reg8;
    reg31=reg30-reg31; reg50=reg50+reg10; reg51=reg32+reg51; reg44=reg45-reg44; reg3=reg2+reg3;
    reg29=reg34-reg29; reg39=reg39*reg23; reg20=reg20*reg4; reg48=reg27+reg48; reg18=reg38-reg18;
    reg36=reg36*reg23; reg35=reg33-reg35; reg37=reg37*reg23; reg43=reg40+reg43; reg42=reg22-reg42;
    reg47=reg47-reg19; reg5=reg5*reg4; reg2=reg43*reg14; reg22=reg42*reg50; reg27=reg18*reg21;
    reg30=reg44*reg25; reg31=reg39+reg31; reg32=reg49*reg17; reg33=reg18*reg25; reg34=reg43*reg17;
    reg38=reg47*reg48; reg20=reg51+reg20; reg39=reg42*reg25; reg40=reg48*reg17; reg41=reg44*reg21;
    reg16=reg15+reg16; reg15=reg49*reg14; reg45=reg48*reg19; reg3=reg5+reg3; reg5=reg44*reg50;
    reg46=reg47*reg49; reg29=reg36+reg29; reg36=reg18*reg50; reg51=reg47*reg43; T reg52=reg48*reg14;
    T reg53=reg42*reg21; reg28=reg28-reg23; T reg54=reg44*reg10; T reg55=reg49*reg19; reg37=reg35+reg37;
    reg35=reg18*reg10; T reg56=reg43*reg19; T reg57=reg42*reg10; reg20=reg9*reg20; reg22=reg38+reg22;
    reg9=reg31*reg26; reg36=reg51+reg36; reg38=reg37*reg28; reg5=reg46+reg5; reg46=reg31*reg28;
    reg51=reg31*reg23; reg55=reg55-reg54; T reg58=reg37*reg23; reg56=reg56-reg35; T reg59=reg29*reg23;
    reg45=reg45-reg57; reg16=reg3*reg16; reg30=reg30-reg32; reg3=reg37*reg26; reg33=reg33-reg34;
    T reg60=reg29*reg26; reg39=reg39-reg40; T reg61=reg31*reg24; reg15=reg15-reg41; T reg62=reg37*reg24;
    reg2=reg2-reg27; T reg63=reg29*reg24; T reg64=reg29*reg28; reg52=reg52-reg53; reg64=reg22+reg64;
    reg63=reg52+reg63; reg62=reg2+reg62; reg61=reg15+reg61; reg20=reg16-reg20; reg39=reg39-reg60;
    reg33=reg33-reg3; reg30=reg30-reg9; reg59=reg45+reg59; reg58=reg56+reg58; reg51=reg55+reg51;
    reg38=reg36+reg38; reg46=reg5+reg46; reg2=reg30*reg20; reg5=reg33*reg20; reg15=reg63*reg20;
    reg16=reg61*reg20; reg22=reg58*reg20; reg36=reg46*reg20; reg45=reg51*reg20; reg52=reg39*reg20;
    reg55=reg64*reg20; reg56=reg38*reg20; T reg65=reg59*reg20; T reg66=reg62*reg20; T vec_9=0.5*reg65;
    T vec_3=0.5*reg15; T vec_10=0.5*reg22; T vec_11=0.5*reg45; T vec_1=0.5*reg56; T vec_8=0.5*reg2;
    T vec_4=0.5*reg66; T vec_2=0.5*reg36; T vec_6=0.5*reg52; T vec_0=0.5*reg55; T vec_5=0.5*reg16;
    T vec_7=0.5*reg5;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[0]+2] += vec_2;
sollicitation[indices[1]+0] += vec_3;
sollicitation[indices[1]+1] += vec_4;
sollicitation[indices[1]+2] += vec_5;
sollicitation[indices[2]+0] += vec_6;
sollicitation[indices[2]+1] += vec_7;
sollicitation[indices[2]+2] += vec_8;
sollicitation[indices[3]+0] += vec_9;
sollicitation[indices[3]+1] += vec_10;
sollicitation[indices[3]+2] += vec_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(2)[2]-elem.pos(1)[2];
    T reg5=pow(reg4,2); reg3=reg2+reg3; reg3=reg5+reg3; reg3=pow(reg3,0.5); reg2=reg0/reg3;
    reg5=elem.pos(3)[1]-elem.pos(1)[1]; T reg6=reg1/reg3; T reg7=elem.pos(3)[0]-elem.pos(1)[0]; reg3=reg4/reg3; T reg8=reg7*reg2;
    T reg9=elem.pos(3)[2]-elem.pos(1)[2]; T reg10=reg5*reg6; reg8=reg10+reg8; reg10=reg9*reg3; reg8=reg10+reg8;
    reg10=reg8*reg6; T reg11=reg8*reg2; T reg12=elem.pos(2)[1]-elem.pos(0)[1]; T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=elem.pos(3)[1]-elem.pos(0)[1];
    reg10=reg5-reg10; T reg15=reg3*reg8; reg11=reg7-reg11; T reg16=elem.pos(3)[2]-elem.pos(0)[2]; T reg17=elem.pos(1)[2]-elem.pos(0)[2];
    T reg18=elem.pos(1)[1]-elem.pos(0)[1]; T reg19=reg13*reg14; T reg20=reg12*reg16; T reg21=reg18*reg16; T reg22=pow(reg10,2);
    reg15=reg9-reg15; T reg23=pow(reg11,2); T reg24=reg17*reg14; T reg25=elem.pos(2)[0]-elem.pos(0)[0]; T reg26=elem.pos(1)[0]-elem.pos(0)[0];
    reg19=reg20-reg19; reg24=reg21-reg24; reg20=reg18*reg13; reg21=reg17*reg12; reg22=reg23+reg22;
    reg23=pow(reg15,2); T reg27=reg26*reg19; T reg28=elem.pos(3)[0]-elem.pos(0)[0]; reg21=reg20-reg21; reg23=reg22+reg23;
    reg20=reg25*reg24; reg23=pow(reg23,0.5); reg22=reg28*reg21; reg20=reg27-reg20; reg27=reg25*reg16;
    T reg29=reg13*reg28; T reg30=reg17*reg28; T reg31=reg26*reg16; reg22=reg20+reg22; reg20=reg17*reg25;
    T reg32=reg26*reg13; T reg33=reg18*reg28; reg30=reg31-reg30; reg31=reg26*reg14; reg10=reg10/reg23;
    T reg34=reg12*reg28; reg29=reg27-reg29; reg27=reg25*reg14; reg11=reg11/reg23; reg5=reg10*reg5;
    reg23=reg15/reg23; reg7=reg7*reg11; reg2=reg0*reg2; reg10=reg1*reg10; reg6=reg1*reg6;
    reg11=reg0*reg11; reg19=reg19/reg22; reg29=reg29/reg22; reg34=reg27-reg34; reg24=reg24/reg22;
    reg30=reg30/reg22; reg33=reg31-reg33; reg0=reg26*reg12; reg20=reg32-reg20; reg1=reg18*reg25;
    reg11=reg10+reg11; reg34=reg34/reg22; reg33=reg33/reg22; reg21=reg21/reg22; reg20=reg20/reg22;
    reg1=reg0-reg1; reg9=reg9*reg23; reg6=reg2+reg6; reg3=reg4*reg3; reg5=reg7+reg5;
    reg23=reg4*reg23; reg0=reg29-reg30; reg2=reg24-reg19; reg4=reg24*reg21; reg7=reg29*reg30;
    reg10=reg19*reg24; reg15=reg33-reg34; reg11=reg23+reg11; reg23=reg30*reg20; reg2=reg2-reg21;
    reg22=reg1/reg22; reg9=reg5+reg9; reg6=reg3+reg6; reg0=reg0+reg20; reg15=reg15-reg22;
    reg1=reg29*reg20; reg3=reg0*reg30; reg5=reg2*reg24; reg27=reg34*reg33; reg31=reg19*reg21;
    reg32=reg10+reg7; T reg35=reg0*reg20; T reg36=pow(reg29,2); T reg37=pow(reg19,2); T reg38=reg2*reg21;
    T reg39=pow(reg30,2); reg6=reg9*reg6; reg9=pow(reg0,2); reg11=reg8*reg11; reg8=reg2*reg19;
    T reg40=reg0*reg29; T reg41=pow(reg20,2); T reg42=reg33*reg22; T reg43=reg4+reg23; T reg44=pow(reg21,2);
    T reg45=pow(reg2,2); T reg46=pow(reg24,2); reg8=reg8-reg40; T reg47=reg15*reg33; reg3=reg3-reg5;
    T reg48=reg15*reg34; T reg49=pow(reg15,2); reg9=reg45+reg9; reg31=reg31+reg1; reg38=reg38-reg35;
    reg45=reg15*reg22; T reg50=pow(reg34,2); reg37=reg37+reg36; T reg51=reg32+reg27; T reg52=reg34*reg22;
    reg39=reg39+reg46; T reg53=pow(reg33,2); T reg54=reg43+reg42; reg44=reg44+reg41; reg11=reg6-reg11;
    reg6=pow(reg22,2); reg45=reg38+reg45; reg38=reg51*reg11; T reg55=reg54*reg11; reg48=reg8+reg48;
    reg3=reg3-reg47; reg37=reg50+reg37; reg52=reg31+reg52; reg39=reg39+reg53; reg6=reg44+reg6;
    reg49=reg9+reg49; reg8=reg39*reg11; reg9=0.5*reg38; reg31=reg45*reg11; reg44=reg37*reg11;
    reg50=0.5*reg55; T reg56=reg6*reg11; T reg57=reg48*reg11; T reg58=reg49*reg11; T reg59=reg3*reg11;
    T reg60=reg52*reg11; T tmp_6_9=-reg50; T tmp_7_10=-reg50; T tmp_8_11=-reg50; T tmp_9_6=-reg50;
    T tmp_10_7=-reg50; T tmp_11_8=-reg50; T tmp_6_6=0.5*reg8; T tmp_7_7=0.5*reg8; T tmp_8_8=0.5*reg8;
    T tmp_9_9=0.5*reg56; T tmp_10_10=0.5*reg56; T tmp_11_11=0.5*reg56; T tmp_3_9=0.5*reg60; T tmp_4_10=0.5*reg60;
    T tmp_5_11=0.5*reg60; T tmp_9_3=0.5*reg60; T tmp_10_4=0.5*reg60; T tmp_11_5=0.5*reg60; T tmp_3_6=-reg9;
    T tmp_4_7=-reg9; T tmp_5_8=-reg9; T tmp_6_3=-reg9; T tmp_7_4=-reg9; T tmp_8_5=-reg9;
    T tmp_3_3=0.5*reg44; T tmp_4_4=0.5*reg44; T tmp_5_5=0.5*reg44; T tmp_0_9=0.5*reg31; T tmp_1_10=0.5*reg31;
    T tmp_2_11=0.5*reg31; T tmp_9_0=0.5*reg31; T tmp_10_1=0.5*reg31; T tmp_11_2=0.5*reg31; T tmp_0_6=0.5*reg59;
    T tmp_1_7=0.5*reg59; T tmp_2_8=0.5*reg59; T tmp_6_0=0.5*reg59; T tmp_7_1=0.5*reg59; T tmp_8_2=0.5*reg59;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_3_0=0.5*reg57; T tmp_4_1=0.5*reg57;
    T tmp_5_2=0.5*reg57; T tmp_0_0=0.5*reg58; T tmp_1_1=0.5*reg58; T tmp_2_2=0.5*reg58;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(2)[2]-elem.pos(1)[2];
    T reg5=pow(reg4,2); reg3=reg2+reg3; reg3=reg5+reg3; reg3=pow(reg3,0.5); reg2=reg0/reg3;
    reg5=elem.pos(3)[1]-elem.pos(1)[1]; T reg6=reg1/reg3; T reg7=elem.pos(3)[0]-elem.pos(1)[0]; reg3=reg4/reg3; T reg8=reg7*reg2;
    T reg9=elem.pos(3)[2]-elem.pos(1)[2]; T reg10=reg5*reg6; reg8=reg10+reg8; reg10=reg9*reg3; reg8=reg10+reg8;
    reg10=reg8*reg6; T reg11=reg8*reg2; T reg12=elem.pos(2)[1]-elem.pos(0)[1]; T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=elem.pos(3)[1]-elem.pos(0)[1];
    reg10=reg5-reg10; T reg15=reg3*reg8; reg11=reg7-reg11; T reg16=elem.pos(3)[2]-elem.pos(0)[2]; T reg17=elem.pos(1)[2]-elem.pos(0)[2];
    T reg18=elem.pos(1)[1]-elem.pos(0)[1]; T reg19=reg13*reg14; T reg20=reg12*reg16; T reg21=reg18*reg16; T reg22=pow(reg10,2);
    reg15=reg9-reg15; T reg23=pow(reg11,2); T reg24=reg17*reg14; T reg25=elem.pos(2)[0]-elem.pos(0)[0]; T reg26=elem.pos(1)[0]-elem.pos(0)[0];
    reg19=reg20-reg19; reg24=reg21-reg24; reg20=reg18*reg13; reg21=reg17*reg12; reg22=reg23+reg22;
    reg23=pow(reg15,2); T reg27=reg26*reg19; T reg28=elem.pos(3)[0]-elem.pos(0)[0]; reg21=reg20-reg21; reg23=reg22+reg23;
    reg20=reg25*reg24; reg23=pow(reg23,0.5); reg22=reg28*reg21; reg20=reg27-reg20; reg27=reg25*reg16;
    T reg29=reg13*reg28; T reg30=reg17*reg28; T reg31=reg26*reg16; reg22=reg20+reg22; reg20=reg17*reg25;
    T reg32=reg26*reg13; T reg33=reg18*reg28; reg30=reg31-reg30; reg31=reg26*reg14; reg10=reg10/reg23;
    T reg34=reg12*reg28; reg29=reg27-reg29; reg27=reg25*reg14; reg11=reg11/reg23; reg5=reg10*reg5;
    reg23=reg15/reg23; reg7=reg7*reg11; reg2=reg0*reg2; reg10=reg1*reg10; reg6=reg1*reg6;
    reg11=reg0*reg11; reg19=reg19/reg22; reg29=reg29/reg22; reg34=reg27-reg34; reg24=reg24/reg22;
    reg30=reg30/reg22; reg33=reg31-reg33; reg0=reg26*reg12; reg20=reg32-reg20; reg1=reg18*reg25;
    reg11=reg10+reg11; reg34=reg34/reg22; reg33=reg33/reg22; reg21=reg21/reg22; reg20=reg20/reg22;
    reg1=reg0-reg1; reg9=reg9*reg23; reg6=reg2+reg6; reg3=reg4*reg3; reg5=reg7+reg5;
    reg23=reg4*reg23; reg0=reg29-reg30; reg2=reg24-reg19; reg4=reg24*reg21; reg7=reg29*reg30;
    reg10=reg19*reg24; reg15=reg33-reg34; reg11=reg23+reg11; reg23=reg30*reg20; reg2=reg2-reg21;
    reg22=reg1/reg22; reg9=reg5+reg9; reg6=reg3+reg6; reg0=reg0+reg20; reg15=reg15-reg22;
    reg1=reg29*reg20; reg3=reg0*reg30; reg5=reg2*reg24; reg27=reg34*reg33; reg31=reg19*reg21;
    reg32=reg10+reg7; T reg35=reg0*reg20; T reg36=pow(reg29,2); T reg37=pow(reg19,2); T reg38=reg2*reg21;
    T reg39=pow(reg30,2); reg6=reg9*reg6; reg9=pow(reg0,2); reg11=reg8*reg11; reg8=reg2*reg19;
    T reg40=reg0*reg29; T reg41=pow(reg20,2); T reg42=reg33*reg22; T reg43=reg4+reg23; T reg44=pow(reg21,2);
    T reg45=pow(reg2,2); T reg46=pow(reg24,2); reg8=reg8-reg40; T reg47=reg15*reg33; reg3=reg3-reg5;
    T reg48=reg15*reg34; T reg49=pow(reg15,2); reg9=reg45+reg9; reg31=reg31+reg1; reg38=reg38-reg35;
    reg45=reg15*reg22; T reg50=pow(reg34,2); reg37=reg37+reg36; T reg51=reg32+reg27; T reg52=reg34*reg22;
    reg39=reg39+reg46; T reg53=pow(reg33,2); T reg54=reg43+reg42; reg44=reg44+reg41; reg11=reg6-reg11;
    reg6=pow(reg22,2); reg45=reg38+reg45; reg38=reg51*reg11; T reg55=reg54*reg11; reg48=reg8+reg48;
    reg3=reg3-reg47; reg37=reg50+reg37; reg52=reg31+reg52; reg39=reg39+reg53; reg6=reg44+reg6;
    reg49=reg9+reg49; reg8=reg39*reg11; reg9=0.5*reg38; reg31=reg45*reg11; reg44=reg37*reg11;
    reg50=0.5*reg55; T reg56=reg6*reg11; T reg57=reg48*reg11; T reg58=reg49*reg11; T reg59=reg3*reg11;
    T reg60=reg52*reg11; T tmp_6_9=-reg50; T tmp_7_10=-reg50; T tmp_8_11=-reg50; T tmp_6_6=0.5*reg8;
    T tmp_7_7=0.5*reg8; T tmp_8_8=0.5*reg8; T tmp_9_9=0.5*reg56; T tmp_10_10=0.5*reg56; T tmp_11_11=0.5*reg56;
    T tmp_3_9=0.5*reg60; T tmp_4_10=0.5*reg60; T tmp_5_11=0.5*reg60; T tmp_3_6=-reg9; T tmp_4_7=-reg9;
    T tmp_5_8=-reg9; T tmp_3_3=0.5*reg44; T tmp_4_4=0.5*reg44; T tmp_5_5=0.5*reg44; T tmp_0_9=0.5*reg31;
    T tmp_1_10=0.5*reg31; T tmp_2_11=0.5*reg31; T tmp_0_6=0.5*reg59; T tmp_1_7=0.5*reg59; T tmp_2_8=0.5*reg59;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_0_0=0.5*reg58; T tmp_1_1=0.5*reg58;
    T tmp_2_2=0.5*reg58;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(2)[2]-elem.pos(1)[2];
    T reg5=pow(reg4,2); reg3=reg2+reg3; reg3=reg5+reg3; reg3=pow(reg3,0.5); reg2=reg0/reg3;
    reg5=elem.pos(3)[1]-elem.pos(1)[1]; T reg6=reg1/reg3; T reg7=elem.pos(3)[0]-elem.pos(1)[0]; reg3=reg4/reg3; T reg8=reg7*reg2;
    T reg9=elem.pos(3)[2]-elem.pos(1)[2]; T reg10=reg5*reg6; reg8=reg10+reg8; reg10=reg9*reg3; reg8=reg10+reg8;
    reg10=reg8*reg6; T reg11=reg8*reg2; T reg12=elem.pos(2)[1]-elem.pos(0)[1]; T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=elem.pos(3)[1]-elem.pos(0)[1];
    reg10=reg5-reg10; T reg15=reg3*reg8; reg11=reg7-reg11; T reg16=elem.pos(3)[2]-elem.pos(0)[2]; T reg17=elem.pos(1)[2]-elem.pos(0)[2];
    T reg18=elem.pos(1)[1]-elem.pos(0)[1]; T reg19=reg13*reg14; T reg20=reg12*reg16; T reg21=reg18*reg16; T reg22=pow(reg10,2);
    reg15=reg9-reg15; T reg23=pow(reg11,2); T reg24=reg17*reg14; T reg25=elem.pos(2)[0]-elem.pos(0)[0]; T reg26=elem.pos(1)[0]-elem.pos(0)[0];
    reg19=reg20-reg19; reg24=reg21-reg24; reg20=reg18*reg13; reg21=reg17*reg12; reg22=reg23+reg22;
    reg23=pow(reg15,2); T reg27=reg26*reg19; T reg28=elem.pos(3)[0]-elem.pos(0)[0]; reg21=reg20-reg21; reg23=reg22+reg23;
    reg20=reg25*reg24; reg23=pow(reg23,0.5); reg22=reg28*reg21; reg20=reg27-reg20; reg27=reg25*reg16;
    T reg29=reg13*reg28; T reg30=reg17*reg28; T reg31=reg26*reg16; reg22=reg20+reg22; reg20=reg17*reg25;
    T reg32=reg26*reg13; T reg33=reg18*reg28; reg30=reg31-reg30; reg31=reg26*reg14; reg10=reg10/reg23;
    T reg34=reg12*reg28; reg29=reg27-reg29; reg27=reg25*reg14; reg11=reg11/reg23; reg5=reg10*reg5;
    reg23=reg15/reg23; reg7=reg7*reg11; reg2=reg0*reg2; reg10=reg1*reg10; reg6=reg1*reg6;
    reg11=reg0*reg11; reg19=reg19/reg22; reg29=reg29/reg22; reg34=reg27-reg34; reg24=reg24/reg22;
    reg30=reg30/reg22; reg33=reg31-reg33; reg0=reg26*reg12; reg20=reg32-reg20; reg1=reg18*reg25;
    reg11=reg10+reg11; reg34=reg34/reg22; reg33=reg33/reg22; reg21=reg21/reg22; reg20=reg20/reg22;
    reg1=reg0-reg1; reg9=reg9*reg23; reg6=reg2+reg6; reg3=reg4*reg3; reg5=reg7+reg5;
    reg23=reg4*reg23; reg0=reg29-reg30; reg2=reg24-reg19; reg4=reg24*reg21; reg7=reg29*reg30;
    reg10=reg19*reg24; reg15=reg33-reg34; reg11=reg23+reg11; reg23=reg30*reg20; reg2=reg2-reg21;
    reg22=reg1/reg22; reg9=reg5+reg9; reg6=reg3+reg6; reg0=reg0+reg20; reg15=reg15-reg22;
    reg1=reg29*reg20; reg3=reg0*reg30; reg5=reg2*reg24; reg27=reg34*reg33; reg31=reg19*reg21;
    reg32=reg10+reg7; T reg35=reg0*reg20; T reg36=pow(reg29,2); T reg37=pow(reg19,2); T reg38=reg2*reg21;
    T reg39=pow(reg30,2); reg6=reg9*reg6; reg9=pow(reg0,2); reg11=reg8*reg11; reg8=reg2*reg19;
    T reg40=reg0*reg29; T reg41=pow(reg20,2); T reg42=reg33*reg22; T reg43=reg4+reg23; T reg44=pow(reg21,2);
    T reg45=pow(reg2,2); T reg46=pow(reg24,2); reg8=reg8-reg40; T reg47=reg15*reg33; reg3=reg3-reg5;
    T reg48=reg15*reg34; T reg49=pow(reg15,2); reg9=reg45+reg9; reg31=reg31+reg1; reg38=reg38-reg35;
    reg45=reg15*reg22; T reg50=pow(reg34,2); reg37=reg37+reg36; T reg51=reg32+reg27; T reg52=reg34*reg22;
    reg39=reg39+reg46; T reg53=pow(reg33,2); T reg54=reg43+reg42; reg44=reg44+reg41; reg11=reg6-reg11;
    reg6=pow(reg22,2); reg45=reg38+reg45; reg38=reg51*reg11; T reg55=reg54*reg11; reg48=reg8+reg48;
    reg3=reg3-reg47; reg37=reg50+reg37; reg52=reg31+reg52; reg39=reg39+reg53; reg6=reg44+reg6;
    reg49=reg9+reg49; reg8=reg39*reg11; reg9=0.5*reg38; reg31=reg45*reg11; reg44=reg37*reg11;
    reg50=0.5*reg55; T reg56=reg6*reg11; T reg57=reg48*reg11; T reg58=reg49*reg11; T reg59=reg3*reg11;
    T reg60=reg52*reg11; T tmp_6_9=-reg50; T tmp_7_10=-reg50; T tmp_8_11=-reg50; T tmp_9_6=-reg50;
    T tmp_10_7=-reg50; T tmp_11_8=-reg50; T tmp_6_6=0.5*reg8; T tmp_7_7=0.5*reg8; T tmp_8_8=0.5*reg8;
    T tmp_9_9=0.5*reg56; T tmp_10_10=0.5*reg56; T tmp_11_11=0.5*reg56; T tmp_3_9=0.5*reg60; T tmp_4_10=0.5*reg60;
    T tmp_5_11=0.5*reg60; T tmp_9_3=0.5*reg60; T tmp_10_4=0.5*reg60; T tmp_11_5=0.5*reg60; T tmp_3_6=-reg9;
    T tmp_4_7=-reg9; T tmp_5_8=-reg9; T tmp_6_3=-reg9; T tmp_7_4=-reg9; T tmp_8_5=-reg9;
    T tmp_3_3=0.5*reg44; T tmp_4_4=0.5*reg44; T tmp_5_5=0.5*reg44; T tmp_0_9=0.5*reg31; T tmp_1_10=0.5*reg31;
    T tmp_2_11=0.5*reg31; T tmp_9_0=0.5*reg31; T tmp_10_1=0.5*reg31; T tmp_11_2=0.5*reg31; T tmp_0_6=0.5*reg59;
    T tmp_1_7=0.5*reg59; T tmp_2_8=0.5*reg59; T tmp_6_0=0.5*reg59; T tmp_7_1=0.5*reg59; T tmp_8_2=0.5*reg59;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_3_0=0.5*reg57; T tmp_4_1=0.5*reg57;
    T tmp_5_2=0.5*reg57; T tmp_0_0=0.5*reg58; T tmp_1_1=0.5*reg58; T tmp_2_2=0.5*reg58;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[0]+1) += tmp_4_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[0]+2) += tmp_5_2;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[0]+0) += tmp_6_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_6_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[0]+1) += tmp_7_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_7_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[0]+2) += tmp_8_2;
    matrix(indices[2]+2,indices[1]+2) += tmp_8_5;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[0]+0) += tmp_9_0;
    matrix(indices[3]+0,indices[1]+0) += tmp_9_3;
    matrix(indices[3]+0,indices[2]+0) += tmp_9_6;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[0]+1) += tmp_10_1;
    matrix(indices[3]+1,indices[1]+1) += tmp_10_4;
    matrix(indices[3]+1,indices[2]+1) += tmp_10_7;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[0]+2) += tmp_11_2;
    matrix(indices[3]+2,indices[1]+2) += tmp_11_5;
    matrix(indices[3]+2,indices[2]+2) += tmp_11_8;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(2)[2]-elem.pos(1)[2];
    T reg5=pow(reg4,2); reg3=reg2+reg3; reg3=reg5+reg3; reg3=pow(reg3,0.5); reg2=reg0/reg3;
    reg5=elem.pos(3)[1]-elem.pos(1)[1]; T reg6=reg1/reg3; T reg7=elem.pos(3)[0]-elem.pos(1)[0]; reg3=reg4/reg3; T reg8=reg7*reg2;
    T reg9=elem.pos(3)[2]-elem.pos(1)[2]; T reg10=reg5*reg6; reg8=reg10+reg8; reg10=reg9*reg3; reg8=reg10+reg8;
    reg10=reg8*reg6; T reg11=reg8*reg2; T reg12=elem.pos(2)[1]-elem.pos(0)[1]; T reg13=elem.pos(2)[2]-elem.pos(0)[2]; T reg14=elem.pos(3)[1]-elem.pos(0)[1];
    reg10=reg5-reg10; T reg15=reg3*reg8; reg11=reg7-reg11; T reg16=elem.pos(3)[2]-elem.pos(0)[2]; T reg17=elem.pos(1)[2]-elem.pos(0)[2];
    T reg18=elem.pos(1)[1]-elem.pos(0)[1]; T reg19=reg13*reg14; T reg20=reg12*reg16; T reg21=reg18*reg16; T reg22=pow(reg10,2);
    reg15=reg9-reg15; T reg23=pow(reg11,2); T reg24=reg17*reg14; T reg25=elem.pos(2)[0]-elem.pos(0)[0]; T reg26=elem.pos(1)[0]-elem.pos(0)[0];
    reg19=reg20-reg19; reg24=reg21-reg24; reg20=reg18*reg13; reg21=reg17*reg12; reg22=reg23+reg22;
    reg23=pow(reg15,2); T reg27=reg26*reg19; T reg28=elem.pos(3)[0]-elem.pos(0)[0]; reg21=reg20-reg21; reg23=reg22+reg23;
    reg20=reg25*reg24; reg23=pow(reg23,0.5); reg22=reg28*reg21; reg20=reg27-reg20; reg27=reg25*reg16;
    T reg29=reg13*reg28; T reg30=reg17*reg28; T reg31=reg26*reg16; reg22=reg20+reg22; reg20=reg17*reg25;
    T reg32=reg26*reg13; T reg33=reg18*reg28; reg30=reg31-reg30; reg31=reg26*reg14; reg10=reg10/reg23;
    T reg34=reg12*reg28; reg29=reg27-reg29; reg27=reg25*reg14; reg11=reg11/reg23; reg5=reg10*reg5;
    reg23=reg15/reg23; reg7=reg7*reg11; reg2=reg0*reg2; reg10=reg1*reg10; reg6=reg1*reg6;
    reg11=reg0*reg11; reg19=reg19/reg22; reg29=reg29/reg22; reg34=reg27-reg34; reg24=reg24/reg22;
    reg30=reg30/reg22; reg33=reg31-reg33; reg0=reg26*reg12; reg20=reg32-reg20; reg1=reg18*reg25;
    reg11=reg10+reg11; reg34=reg34/reg22; reg33=reg33/reg22; reg21=reg21/reg22; reg20=reg20/reg22;
    reg1=reg0-reg1; reg9=reg9*reg23; reg6=reg2+reg6; reg3=reg4*reg3; reg5=reg7+reg5;
    reg23=reg4*reg23; reg0=reg29-reg30; reg2=reg24-reg19; reg4=reg24*reg21; reg7=reg29*reg30;
    reg10=reg19*reg24; reg15=reg33-reg34; reg11=reg23+reg11; reg23=reg30*reg20; reg2=reg2-reg21;
    reg22=reg1/reg22; reg9=reg5+reg9; reg6=reg3+reg6; reg0=reg0+reg20; reg15=reg15-reg22;
    reg1=reg29*reg20; reg3=reg0*reg30; reg5=reg2*reg24; reg27=reg34*reg33; reg31=reg19*reg21;
    reg32=reg10+reg7; T reg35=reg0*reg20; T reg36=pow(reg29,2); T reg37=pow(reg19,2); T reg38=reg2*reg21;
    T reg39=pow(reg30,2); reg6=reg9*reg6; reg9=pow(reg0,2); reg11=reg8*reg11; reg8=reg2*reg19;
    T reg40=reg0*reg29; T reg41=pow(reg20,2); T reg42=reg33*reg22; T reg43=reg4+reg23; T reg44=pow(reg21,2);
    T reg45=pow(reg2,2); T reg46=pow(reg24,2); reg8=reg8-reg40; T reg47=reg15*reg33; reg3=reg3-reg5;
    T reg48=reg15*reg34; T reg49=pow(reg15,2); reg9=reg45+reg9; reg31=reg31+reg1; reg38=reg38-reg35;
    reg45=reg15*reg22; T reg50=pow(reg34,2); reg37=reg37+reg36; T reg51=reg32+reg27; T reg52=reg34*reg22;
    reg39=reg39+reg46; T reg53=pow(reg33,2); T reg54=reg43+reg42; reg44=reg44+reg41; reg11=reg6-reg11;
    reg6=pow(reg22,2); reg45=reg38+reg45; reg38=reg51*reg11; T reg55=reg54*reg11; reg48=reg8+reg48;
    reg3=reg3-reg47; reg37=reg50+reg37; reg52=reg31+reg52; reg39=reg39+reg53; reg6=reg44+reg6;
    reg49=reg9+reg49; reg8=reg39*reg11; reg9=0.5*reg38; reg31=reg45*reg11; reg44=reg37*reg11;
    reg50=0.5*reg55; T reg56=reg6*reg11; T reg57=reg48*reg11; T reg58=reg49*reg11; T reg59=reg3*reg11;
    T reg60=reg52*reg11; T tmp_6_9=-reg50; T tmp_7_10=-reg50; T tmp_8_11=-reg50; T tmp_6_6=0.5*reg8;
    T tmp_7_7=0.5*reg8; T tmp_8_8=0.5*reg8; T tmp_9_9=0.5*reg56; T tmp_10_10=0.5*reg56; T tmp_11_11=0.5*reg56;
    T tmp_3_9=0.5*reg60; T tmp_4_10=0.5*reg60; T tmp_5_11=0.5*reg60; T tmp_3_6=-reg9; T tmp_4_7=-reg9;
    T tmp_5_8=-reg9; T tmp_3_3=0.5*reg44; T tmp_4_4=0.5*reg44; T tmp_5_5=0.5*reg44; T tmp_0_9=0.5*reg31;
    T tmp_1_10=0.5*reg31; T tmp_2_11=0.5*reg31; T tmp_0_6=0.5*reg59; T tmp_1_7=0.5*reg59; T tmp_2_8=0.5*reg59;
    T tmp_0_3=0.5*reg57; T tmp_1_4=0.5*reg57; T tmp_2_5=0.5*reg57; T tmp_0_0=0.5*reg58; T tmp_1_1=0.5*reg58;
    T tmp_2_2=0.5*reg58;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_6;
    matrix(indices[0]+0,indices[3]+0) += tmp_0_9;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_7;
    matrix(indices[0]+1,indices[3]+1) += tmp_1_10;
    matrix(indices[0]+2,indices[0]+2) += tmp_2_2;
    matrix(indices[0]+2,indices[1]+2) += tmp_2_5;
    matrix(indices[0]+2,indices[2]+2) += tmp_2_8;
    matrix(indices[0]+2,indices[3]+2) += tmp_2_11;
    matrix(indices[1]+0,indices[1]+0) += tmp_3_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_3_6;
    matrix(indices[1]+0,indices[3]+0) += tmp_3_9;
    matrix(indices[1]+1,indices[1]+1) += tmp_4_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_4_7;
    matrix(indices[1]+1,indices[3]+1) += tmp_4_10;
    matrix(indices[1]+2,indices[1]+2) += tmp_5_5;
    matrix(indices[1]+2,indices[2]+2) += tmp_5_8;
    matrix(indices[1]+2,indices[3]+2) += tmp_5_11;
    matrix(indices[2]+0,indices[2]+0) += tmp_6_6;
    matrix(indices[2]+0,indices[3]+0) += tmp_6_9;
    matrix(indices[2]+1,indices[2]+1) += tmp_7_7;
    matrix(indices[2]+1,indices[3]+1) += tmp_7_10;
    matrix(indices[2]+2,indices[2]+2) += tmp_8_8;
    matrix(indices[2]+2,indices[3]+2) += tmp_8_11;
    matrix(indices[3]+0,indices[3]+0) += tmp_9_9;
    matrix(indices[3]+1,indices[3]+1) += tmp_10_10;
    matrix(indices[3]+2,indices[3]+2) += tmp_11_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_residual(
      const Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=elem.pos(2)[2]-elem.pos(1)[2]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=pow(reg2,2); reg4=reg3+reg4; reg4=reg5+reg4; reg4=pow(reg4,0.5); reg3=elem.pos(3)[0]-elem.pos(1)[0];
    reg5=reg1/reg4; T reg6=elem.pos(3)[1]-elem.pos(1)[1]; T reg7=reg0/reg4; reg4=reg2/reg4; T reg8=reg6*reg5;
    T reg9=reg3*reg7; T reg10=elem.pos(3)[2]-elem.pos(1)[2]; T reg11=reg10*reg4; reg9=reg8+reg9; reg8=elem.pos(3)[1]-elem.pos(0)[1];
    T reg12=elem.pos(2)[1]-elem.pos(0)[1]; T reg13=elem.pos(3)[2]-elem.pos(0)[2]; T reg14=elem.pos(1)[1]-elem.pos(0)[1]; T reg15=elem.pos(1)[2]-elem.pos(0)[2]; reg9=reg11+reg9;
    reg11=elem.pos(2)[2]-elem.pos(0)[2]; T reg16=reg9*reg5; T reg17=reg9*reg7; T reg18=reg12*reg13; T reg19=reg14*reg13;
    T reg20=reg15*reg8; T reg21=reg11*reg8; reg21=reg18-reg21; reg18=reg15*reg12; T reg22=elem.pos(1)[0]-elem.pos(0)[0];
    T reg23=elem.pos(2)[0]-elem.pos(0)[0]; T reg24=reg14*reg11; reg20=reg19-reg20; reg16=reg6-reg16; reg19=reg4*reg9;
    reg17=reg3-reg17; T reg25=reg22*reg21; T reg26=pow(reg17,2); T reg27=pow(reg16,2); T reg28=reg23*reg20;
    reg19=reg10-reg19; reg18=reg24-reg18; reg24=elem.pos(3)[0]-elem.pos(0)[0]; reg27=reg26+reg27; reg26=reg22*reg13;
    T reg29=reg11*reg24; T reg30=reg15*reg24; reg28=reg25-reg28; reg25=reg23*reg13; T reg31=pow(reg19,2);
    T reg32=reg24*reg18; reg30=reg26-reg30; reg26=reg14*reg24; T reg33=reg22*reg11; T reg34=reg22*reg8;
    T reg35=reg15*reg23; T reg36=reg12*reg24; reg31=reg27+reg31; reg29=reg25-reg29; reg25=reg23*reg8;
    reg32=reg28+reg32; reg26=reg34-reg26; reg36=reg25-reg36; reg20=reg20/reg32; reg30=reg30/reg32;
    reg29=reg29/reg32; reg21=reg21/reg32; reg31=pow(reg31,0.5); reg25=reg22*reg12; reg27=vectors[0][indices[1]+1]-vectors[0][indices[0]+1];
    reg35=reg33-reg35; reg28=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; reg33=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; reg34=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg37=reg14*reg23;
    T reg38=vectors[0][indices[1]+2]-vectors[0][indices[0]+2]; T reg39=vectors[0][indices[2]+2]-vectors[0][indices[0]+2]; reg16=reg16/reg31; reg36=reg36/reg32; reg37=reg25-reg37;
    reg25=reg27*reg21; T reg40=reg28*reg20; T reg41=vectors[0][indices[3]+1]-vectors[0][indices[0]+1]; T reg42=reg28*reg30; T reg43=reg27*reg29;
    T reg44=reg33*reg21; T reg45=reg34*reg20; T reg46=vectors[0][indices[3]+0]-vectors[0][indices[0]+0]; T reg47=reg34*reg30; T reg48=reg33*reg29;
    T reg49=reg38*reg21; T reg50=reg39*reg20; T reg51=vectors[0][indices[3]+2]-vectors[0][indices[0]+2]; T reg52=reg39*reg30; reg26=reg26/reg32;
    reg18=reg18/reg32; reg35=reg35/reg32; reg17=reg17/reg31; T reg53=reg38*reg29; T reg54=reg41*reg18;
    reg7=reg0*reg7; reg28=reg28*reg26; reg27=reg27*reg36; reg5=reg1*reg5; T reg55=reg41*reg35;
    reg43=reg42-reg43; reg38=reg38*reg36; reg39=reg39*reg26; reg32=reg37/reg32; reg40=reg25-reg40;
    reg25=reg29-reg30; reg1=reg1*reg16; reg37=reg20-reg21; reg42=reg51*reg18; reg3=reg3*reg17;
    reg50=reg49-reg50; reg45=reg44-reg45; reg44=reg51*reg35; reg49=reg46*reg18; reg17=reg0*reg17;
    reg53=reg52-reg53; reg6=reg16*reg6; reg48=reg47-reg48; reg0=reg46*reg35; reg31=reg19/reg31;
    reg33=reg33*reg36; reg34=reg34*reg26; reg5=reg7+reg5; reg6=reg3+reg6; reg10=reg10*reg31;
    reg4=reg2*reg4; reg31=reg2*reg31; reg17=reg1+reg17; reg37=reg37-reg18; reg54=reg40+reg54;
    reg55=reg43-reg55; reg28=reg27-reg28; reg41=reg41*reg32; reg49=reg45+reg49; reg0=reg48-reg0;
    reg46=reg46*reg32; reg34=reg33-reg34; reg42=reg50+reg42; reg44=reg53-reg44; reg51=reg51*reg32;
    reg39=reg38-reg39; reg25=reg25+reg35; reg1=reg26-reg36; reg17=reg31+reg17; reg2=reg0*reg35;
    reg3=reg37*reg54; reg7=reg0*reg30; reg16=reg37*reg42; reg19=reg54*reg20; reg27=reg55*reg30;
    reg31=reg49*reg20; reg33=reg42*reg20; reg38=reg44*reg30; reg40=reg44*reg29; reg43=reg42*reg21;
    reg45=reg49*reg18; reg47=reg55*reg25; reg48=reg54*reg18; reg50=reg55*reg35; reg52=reg55*reg29;
    reg53=reg54*reg21; T reg56=reg44*reg35; reg5=reg4+reg5; reg10=reg6+reg10; reg4=reg37*reg49;
    reg41=reg28+reg41; reg34=reg46+reg34; reg39=reg51+reg39; reg6=reg49*reg21; reg1=reg1-reg32;
    reg28=reg42*reg18; reg46=reg0*reg25; reg51=reg0*reg29; T reg57=reg44*reg25; reg5=reg10*reg5;
    reg10=reg41*reg36; reg53=reg53-reg52; reg57=reg16+reg57; reg43=reg43-reg40; reg16=reg39*reg36;
    reg6=reg6-reg51; T reg58=reg39*reg1; T reg59=reg34*reg36; reg7=reg7-reg31; T reg60=reg39*reg32;
    reg28=reg28-reg56; T reg61=reg41*reg32; reg48=reg48-reg50; reg17=reg9*reg17; reg46=reg4+reg46;
    reg4=reg34*reg1; reg9=reg34*reg32; reg45=reg45-reg2; reg47=reg3+reg47; reg3=reg39*reg26;
    reg38=reg38-reg33; T reg62=reg41*reg1; T reg63=reg41*reg26; reg27=reg27-reg19; T reg64=reg34*reg26;
    reg4=reg46+reg4; reg62=reg47+reg62; reg10=reg53+reg10; reg59=reg6+reg59; reg16=reg43+reg16;
    reg7=reg7-reg64; reg27=reg27-reg63; reg38=reg38-reg3; reg9=reg45+reg9; reg58=reg57+reg58;
    reg17=reg5-reg17; reg61=reg48+reg61; reg60=reg28+reg60; reg5=reg27*reg17; reg6=reg61*reg17;
    reg28=reg10*reg17; reg43=reg16*reg17; reg45=reg9*reg17; reg46=reg7*reg17; reg47=reg38*reg17;
    reg48=reg59*reg17; reg53=reg58*reg17; reg57=reg4*reg17; T reg65=reg60*reg17; T reg66=reg62*reg17;
    T vec_10=0.5*reg6; T vec_9=0.5*reg45; T vec_8=0.5*reg47; T vec_11=0.5*reg65; T vec_7=0.5*reg5;
    T vec_6=0.5*reg46; T vec_5=0.5*reg43; T vec_4=0.5*reg28; T vec_3=0.5*reg48; T vec_2=0.5*reg53;
    T vec_1=0.5*reg66; T vec_0=0.5*reg57;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[0]+2] += vec_2;
sollicitation[indices[1]+0] += vec_3;
sollicitation[indices[1]+1] += vec_4;
sollicitation[indices[1]+2] += vec_5;
sollicitation[indices[2]+0] += vec_6;
sollicitation[indices[2]+1] += vec_7;
sollicitation[indices[2]+2] += vec_8;
sollicitation[indices[3]+0] += vec_9;
sollicitation[indices[3]+1] += vec_10;
sollicitation[indices[3]+2] += vec_11;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}

#ifndef laplacian_read_material_to_mesh
#define laplacian_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,laplacian,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // laplacian_read_material_to_mesh
} // namespace LMT



#endif // PROBLEM_laplacian
