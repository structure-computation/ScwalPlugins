#ifndef PROBLEM_laplacian
#define PROBLEM_laplacian

#ifndef Mesh_carac_laplacian_HEADER
#define Mesh_carac_laplacian_HEADER
#include "mesh/displayparaview.h"
#include "mesh/triangle.h"
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
struct Mesh_carac_laplacian<TP,2> {
    typedef TP Tpos;
    static const unsigned dim = 2;
    typedef Vec<TP,2> Pvec;
    struct NodalStaticData {
        typedef Tpos T1;
        typedef Vec<Tpos,2> T0;
        NodalStaticData():dep(0.0),is_on_skin(0) {}
        CARACDMEXTNAME( 0, T0, dep, "m" );
        CARACDMEXTNAME( 1, T1, is_on_skin, "" );
        CARACDMEXTNAME( 2, T0, pos, "m" );
        static const unsigned nb_params = 3;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "is_on_skin" ) { is_on_skin = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            if ( field_name == "is_on_skin" ) { return is_on_skin; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            if ( field_name == "dep" ) { return dep; }
            if ( field_name == "pos" ) { return pos; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    struct GlobalStaticData {
        GlobalStaticData() {}
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    typedef Node<dim,Tpos,NodalStaticData> TNode;
    typedef ElementAncestor<TNode> EA;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice { typedef void NE; typedef DefaultBehavior BE; typedef VoidDMSet TData; };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> { typedef Triangle NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,0,inner> { typedef Bar NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<2,skin,0,inner> { typedef NodalElement NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
};
} // namespace LMT
#endif // Mesh_carac_laplacian_HEADER

#include "formulation/formulation.h"
namespace LMT {
#ifndef LAPLACIAN_2_NUM_0_CARAC_H
#define LAPLACIAN_2_NUM_0_CARAC_H
#ifndef STRUCT_LAPLACIAN
#define STRUCT_LAPLACIAN
struct laplacian {
  static const char *name() { return "laplacian"; }
};
#endif // LAPLACIAN

template<class P_T>
class CaracFormulation<laplacian,2,P_T>  {
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
  
  static const unsigned nb_nodal_unknowns = 2;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+0]-vecs[0][indice+0]; T reg1=vecs[1][indice+1]-vecs[0][indice+1]; reg0=abs(reg0); reg1=abs(reg1); return max(reg1,reg0);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+1]=vecs[1][indice+1];
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
#endif // LAPLACIAN_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_laplacian_Triangle_0( double * );
extern "C" void apply_on_elements_after_solve_1_laplacian_Triangle_1( double * );
extern "C" void apply_on_elements_after_solve_2_laplacian_Triangle_2( double * );
extern "C" void apply_on_elements_after_solve_3_laplacian_Triangle_3( double * );
extern "C" void apply_on_elements_after_solve_4_laplacian_Triangle_4( double * );
extern "C" void apply_on_elements_after_solve_5_laplacian_Triangle_5( double * );
extern "C" void apply_on_elements_after_solve_6_laplacian_Triangle_6( double * );
extern "C" void apply_on_elements_after_solve_7_laplacian_Triangle_7( double * );
extern "C" void apply_on_elements_after_solve_8_laplacian_Triangle_8( double * );
extern "C" void apply_on_elements_after_solve_9_laplacian_Triangle_9( double * );
extern "C" void apply_on_elements_after_solve_10_laplacian_Triangle_10( double * );
extern "C" void apply_on_elements_after_solve_11_laplacian_Triangle_11( double * );
extern "C" void apply_on_elements_after_solve_12_laplacian_Triangle_12( double * );
extern "C" void apply_on_elements_after_solve_13_laplacian_Triangle_13( double * );
extern "C" void apply_on_elements_after_solve_14_laplacian_Triangle_14( double * );
class Triangle;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<laplacian,Element<Triangle,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=pow(reg1,2);
    T reg5=pow(reg0,2); T reg6=reg1*reg2; reg4=reg5+reg4; reg5=reg0*reg3; reg6=reg5-reg6;
    reg4=pow(reg4,0.5); reg5=reg0/reg6; reg2=reg2/reg6; T reg7=reg1/reg6; reg6=reg3/reg6;
    reg3=reg0/reg4; reg4=reg1/reg4; T reg8=reg6*reg7; T reg9=reg5*reg2; T reg10=reg2-reg5;
    T reg11=reg7-reg6; reg4=reg1*reg4; reg3=reg0*reg3; reg4=reg3+reg4; reg0=pow(reg6,2);
    reg1=pow(reg2,2); reg3=reg5*reg10; T reg12=reg8+reg9; T reg13=pow(reg5,2); T reg14=pow(reg7,2);
    T reg15=reg7*reg11; T reg16=pow(reg11,2); T reg17=pow(reg10,2); T reg18=reg6*reg11; T reg19=reg2*reg10;
    reg18=reg18-reg19; reg0=reg0+reg1; reg17=reg16+reg17; reg16=reg4*reg12; reg3=reg3-reg15;
    reg13=reg13+reg14; T tmp_2_2=reg4*reg0; T tmp_3_3=reg4*reg0; T tmp_0_4=reg4*reg3; T tmp_1_5=reg4*reg3;
    T tmp_4_0=reg4*reg3; T tmp_5_1=reg4*reg3; T tmp_0_0=reg4*reg17; T tmp_1_1=reg4*reg17; T tmp_2_4=-reg16;
    T tmp_3_5=-reg16; T tmp_4_2=-reg16; T tmp_5_3=-reg16; T tmp_0_2=reg4*reg18; T tmp_1_3=reg4*reg18;
    T tmp_2_0=reg4*reg18; T tmp_3_1=reg4*reg18; T tmp_4_4=reg4*reg13; T tmp_5_5=reg4*reg13;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=pow(reg1,2);
    T reg5=pow(reg0,2); T reg6=reg1*reg2; reg4=reg5+reg4; reg5=reg0*reg3; reg6=reg5-reg6;
    reg4=pow(reg4,0.5); reg5=reg0/reg6; reg2=reg2/reg6; T reg7=reg1/reg6; reg6=reg3/reg6;
    reg3=reg0/reg4; reg4=reg1/reg4; T reg8=reg6*reg7; T reg9=reg5*reg2; T reg10=reg2-reg5;
    T reg11=reg7-reg6; reg4=reg1*reg4; reg3=reg0*reg3; reg4=reg3+reg4; reg0=pow(reg6,2);
    reg1=pow(reg2,2); reg3=reg5*reg10; T reg12=reg8+reg9; T reg13=pow(reg5,2); T reg14=pow(reg7,2);
    T reg15=reg7*reg11; T reg16=pow(reg11,2); T reg17=pow(reg10,2); T reg18=reg6*reg11; T reg19=reg2*reg10;
    reg18=reg18-reg19; reg0=reg0+reg1; reg17=reg16+reg17; reg16=reg4*reg12; reg3=reg3-reg15;
    reg13=reg13+reg14; T tmp_2_2=reg4*reg0; T tmp_3_3=reg4*reg0; T tmp_0_4=reg4*reg3; T tmp_1_5=reg4*reg3;
    T tmp_0_0=reg4*reg17; T tmp_1_1=reg4*reg17; T tmp_2_4=-reg16; T tmp_3_5=-reg16; T tmp_0_2=reg4*reg18;
    T tmp_1_3=reg4*reg18; T tmp_4_4=reg4*reg13; T tmp_5_5=reg4*reg13;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=pow(reg1,2);
    T reg5=pow(reg0,2); T reg6=reg1*reg2; reg4=reg5+reg4; reg5=reg0*reg3; reg6=reg5-reg6;
    reg4=pow(reg4,0.5); reg5=reg0/reg6; reg2=reg2/reg6; T reg7=reg1/reg6; reg6=reg3/reg6;
    reg3=reg0/reg4; reg4=reg1/reg4; T reg8=reg6*reg7; T reg9=reg5*reg2; T reg10=reg2-reg5;
    T reg11=reg7-reg6; reg4=reg1*reg4; reg3=reg0*reg3; reg4=reg3+reg4; reg0=pow(reg6,2);
    reg1=pow(reg2,2); reg3=reg5*reg10; T reg12=reg8+reg9; T reg13=pow(reg5,2); T reg14=pow(reg7,2);
    T reg15=reg7*reg11; T reg16=pow(reg11,2); T reg17=pow(reg10,2); T reg18=reg6*reg11; T reg19=reg2*reg10;
    reg18=reg18-reg19; reg0=reg0+reg1; reg17=reg16+reg17; reg16=reg4*reg12; reg3=reg3-reg15;
    reg13=reg13+reg14; T tmp_2_2=reg4*reg0; T tmp_3_3=reg4*reg0; T tmp_0_4=reg4*reg3; T tmp_1_5=reg4*reg3;
    T tmp_4_0=reg4*reg3; T tmp_5_1=reg4*reg3; T tmp_0_0=reg4*reg17; T tmp_1_1=reg4*reg17; T tmp_2_4=-reg16;
    T tmp_3_5=-reg16; T tmp_4_2=-reg16; T tmp_5_3=-reg16; T tmp_0_2=reg4*reg18; T tmp_1_3=reg4*reg18;
    T tmp_2_0=reg4*reg18; T tmp_3_1=reg4*reg18; T tmp_4_4=reg4*reg13; T tmp_5_5=reg4*reg13;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=pow(reg1,2);
    T reg5=pow(reg0,2); T reg6=reg1*reg2; reg4=reg5+reg4; reg5=reg0*reg3; reg6=reg5-reg6;
    reg4=pow(reg4,0.5); reg5=reg0/reg6; reg2=reg2/reg6; T reg7=reg1/reg6; reg6=reg3/reg6;
    reg3=reg0/reg4; reg4=reg1/reg4; T reg8=reg6*reg7; T reg9=reg5*reg2; T reg10=reg2-reg5;
    T reg11=reg7-reg6; reg4=reg1*reg4; reg3=reg0*reg3; reg4=reg3+reg4; reg0=pow(reg6,2);
    reg1=pow(reg2,2); reg3=reg5*reg10; T reg12=reg8+reg9; T reg13=pow(reg5,2); T reg14=pow(reg7,2);
    T reg15=reg7*reg11; T reg16=pow(reg11,2); T reg17=pow(reg10,2); T reg18=reg6*reg11; T reg19=reg2*reg10;
    reg18=reg18-reg19; reg0=reg0+reg1; reg17=reg16+reg17; reg16=reg4*reg12; reg3=reg3-reg15;
    reg13=reg13+reg14; T tmp_2_2=reg4*reg0; T tmp_3_3=reg4*reg0; T tmp_0_4=reg4*reg3; T tmp_1_5=reg4*reg3;
    T tmp_0_0=reg4*reg17; T tmp_1_1=reg4*reg17; T tmp_2_4=-reg16; T tmp_3_5=-reg16; T tmp_0_2=reg4*reg18;
    T tmp_1_3=reg4*reg18; T tmp_4_4=reg4*reg13; T tmp_5_5=reg4*reg13;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=reg0*reg3;
    T reg5=reg1*reg2; T reg6=pow(reg0,2); reg5=reg4-reg5; reg4=pow(reg1,2); reg2=reg2/reg5;
    T reg7=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg8=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg9=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg10=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; reg4=reg6+reg4;
    reg6=reg1/reg5; T reg11=reg0/reg5; reg5=reg3/reg5; reg4=pow(reg4,0.5); reg3=reg6*reg9;
    T reg12=reg2*reg10; reg9=reg11*reg9; T reg13=reg6*reg7; T reg14=reg5*reg8; reg8=reg2*reg8;
    reg7=reg11*reg7; reg10=reg5*reg10; reg13=reg14-reg13; reg3=reg10-reg3; reg8=reg7-reg8;
    reg12=reg9-reg12; reg7=reg0/reg4; reg9=reg2-reg11; reg4=reg1/reg4; reg10=reg6-reg5;
    reg14=reg2*reg8; T reg15=reg11*reg8; T reg16=reg5*reg3; T reg17=reg2*reg12; T reg18=reg11*reg12;
    T reg19=reg6*reg3; T reg20=reg6*reg13; T reg21=reg5*reg13; T reg22=reg13*reg10; T reg23=reg12*reg9;
    T reg24=reg3*reg10; reg4=reg1*reg4; reg7=reg0*reg7; reg0=reg8*reg9; reg18=reg18-reg19;
    reg23=reg24+reg23; reg15=reg15-reg20; reg21=reg21-reg14; reg16=reg16-reg17; reg22=reg0+reg22;
    reg4=reg7+reg4; T vec_3=reg4*reg21; T vec_2=reg4*reg16; T vec_1=reg4*reg22; T vec_4=reg4*reg18;
    T vec_0=reg4*reg23; T vec_5=reg4*reg15;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_2_0=reg16*reg10; T tmp_3_1=reg16*reg10; T tmp_0_4=reg12*reg10;
    T tmp_1_5=reg12*reg10; T tmp_4_0=reg12*reg10; T tmp_5_1=reg12*reg10; T tmp_2_2=reg19*reg10; T tmp_3_3=reg19*reg10;
    T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_2=-reg14; T tmp_5_3=-reg14; T tmp_4_4=reg4*reg10;
    T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_0_4=reg12*reg10; T tmp_1_5=reg12*reg10; T tmp_2_2=reg19*reg10;
    T tmp_3_3=reg19*reg10; T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_4=reg4*reg10; T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_2_0=reg16*reg10; T tmp_3_1=reg16*reg10; T tmp_0_4=reg12*reg10;
    T tmp_1_5=reg12*reg10; T tmp_4_0=reg12*reg10; T tmp_5_1=reg12*reg10; T tmp_2_2=reg19*reg10; T tmp_3_3=reg19*reg10;
    T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_2=-reg14; T tmp_5_3=-reg14; T tmp_4_4=reg4*reg10;
    T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[0]-elem.pos(1)[0]; T reg1=elem.pos(2)[1]-elem.pos(1)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_0_4=reg12*reg10; T tmp_1_5=reg12*reg10; T tmp_2_2=reg19*reg10;
    T tmp_3_3=reg19*reg10; T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_4=reg4*reg10; T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=reg0*reg3;
    T reg5=elem.pos(2)[1]-elem.pos(1)[1]; T reg6=elem.pos(2)[0]-elem.pos(1)[0]; T reg7=reg1*reg2; T reg8=pow(reg5,2); reg7=reg4-reg7;
    reg4=pow(reg6,2); T reg9=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; reg2=reg2/reg7; T reg10=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg11=vectors[0][indices[2]+0]-vectors[0][indices[0]+0];
    reg8=reg4+reg8; reg4=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg12=reg1/reg7; T reg13=reg0/reg7; reg7=reg3/reg7;
    reg8=pow(reg8,0.5); reg3=reg13*reg11; T reg14=reg2*reg10; reg10=reg7*reg10; T reg15=reg13*reg4;
    T reg16=reg2*reg9; reg9=reg7*reg9; reg4=reg12*reg4; reg11=reg12*reg11; reg11=reg10-reg11;
    reg4=reg9-reg4; reg14=reg3-reg14; reg3=reg12-reg7; reg9=reg2-reg13; reg16=reg15-reg16;
    reg10=reg6/reg8; reg8=reg5/reg8; reg15=reg13*reg14; T reg17=reg2*reg16; T reg18=reg13*reg16;
    T reg19=reg12*reg4; T reg20=reg16*reg9; T reg21=reg12*reg11; reg10=reg6*reg10; reg6=reg7*reg4;
    T reg22=reg2*reg14; T reg23=reg7*reg11; reg8=reg5*reg8; reg5=reg4*reg3; T reg24=reg14*reg9;
    T reg25=reg11*reg3; reg15=reg15-reg21; reg8=reg10+reg8; reg18=reg18-reg19; reg6=reg6-reg17;
    reg23=reg23-reg22; reg5=reg20+reg5; reg24=reg25+reg24; T vec_0=reg24*reg8; T vec_1=reg5*reg8;
    T vec_2=reg23*reg8; T vec_3=reg6*reg8; T vec_4=reg15*reg8; T vec_5=reg18*reg8;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[0]-elem.pos(2)[0]; T reg1=elem.pos(0)[1]-elem.pos(2)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_2_0=reg16*reg10; T tmp_3_1=reg16*reg10; T tmp_0_4=reg12*reg10;
    T tmp_1_5=reg12*reg10; T tmp_4_0=reg12*reg10; T tmp_5_1=reg12*reg10; T tmp_2_2=reg19*reg10; T tmp_3_3=reg19*reg10;
    T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_2=-reg14; T tmp_5_3=-reg14; T tmp_4_4=reg4*reg10;
    T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[0]-elem.pos(2)[0]; T reg1=elem.pos(0)[1]-elem.pos(2)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_0_4=reg12*reg10; T tmp_1_5=reg12*reg10; T tmp_2_2=reg19*reg10;
    T tmp_3_3=reg19*reg10; T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_4=reg4*reg10; T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[0]-elem.pos(2)[0]; T reg1=elem.pos(0)[1]-elem.pos(2)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_2_0=reg16*reg10; T tmp_3_1=reg16*reg10; T tmp_0_4=reg12*reg10;
    T tmp_1_5=reg12*reg10; T tmp_4_0=reg12*reg10; T tmp_5_1=reg12*reg10; T tmp_2_2=reg19*reg10; T tmp_3_3=reg19*reg10;
    T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_2=-reg14; T tmp_5_3=-reg14; T tmp_4_4=reg4*reg10;
    T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[0]-elem.pos(2)[0]; T reg1=elem.pos(0)[1]-elem.pos(2)[1]; T reg2=elem.pos(1)[0]-elem.pos(0)[0]; T reg3=pow(reg0,2); T reg4=pow(reg1,2);
    T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=elem.pos(1)[1]-elem.pos(0)[1]; reg4=reg3+reg4; reg3=reg7*reg6;
    T reg8=reg2*reg5; reg3=reg8-reg3; reg4=pow(reg4,0.5); reg6=reg6/reg3; reg8=reg7/reg3;
    T reg9=reg2/reg3; T reg10=reg1/reg4; reg3=reg5/reg3; reg4=reg0/reg4; reg5=reg3*reg8;
    T reg11=reg9*reg6; reg4=reg0*reg4; reg10=reg1*reg10; reg0=reg6-reg9; reg1=reg8-reg3;
    T reg12=reg9*reg0; T reg13=pow(reg8,2); reg10=reg4+reg10; reg4=pow(reg9,2); T reg14=pow(reg1,2);
    T reg15=pow(reg0,2); T reg16=reg3*reg1; T reg17=reg6*reg0; T reg18=reg8*reg1; T reg19=pow(reg3,2);
    T reg20=pow(reg6,2); T reg21=reg5+reg11; reg12=reg12-reg18; reg16=reg16-reg17; reg19=reg19+reg20;
    reg15=reg14+reg15; reg4=reg4+reg13; reg14=reg21*reg10; T tmp_0_0=reg15*reg10; T tmp_1_1=reg15*reg10;
    T tmp_0_2=reg16*reg10; T tmp_1_3=reg16*reg10; T tmp_0_4=reg12*reg10; T tmp_1_5=reg12*reg10; T tmp_2_2=reg19*reg10;
    T tmp_3_3=reg19*reg10; T tmp_2_4=-reg14; T tmp_3_5=-reg14; T tmp_4_4=reg4*reg10; T tmp_5_5=reg4*reg10;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
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
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[0]-elem.pos(0)[0]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=reg0*reg3;
    T reg5=elem.pos(0)[1]-elem.pos(2)[1]; T reg6=elem.pos(0)[0]-elem.pos(2)[0]; T reg7=reg1*reg2; T reg8=pow(reg5,2); reg7=reg4-reg7;
    reg4=pow(reg6,2); T reg9=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; reg2=reg2/reg7; T reg10=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg11=vectors[0][indices[2]+0]-vectors[0][indices[0]+0];
    reg8=reg4+reg8; reg4=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg12=reg1/reg7; T reg13=reg0/reg7; reg7=reg3/reg7;
    reg8=pow(reg8,0.5); reg3=reg13*reg11; T reg14=reg2*reg10; reg10=reg7*reg10; T reg15=reg13*reg4;
    T reg16=reg2*reg9; reg9=reg7*reg9; reg4=reg12*reg4; reg11=reg12*reg11; reg11=reg10-reg11;
    reg4=reg9-reg4; reg14=reg3-reg14; reg3=reg12-reg7; reg9=reg2-reg13; reg16=reg15-reg16;
    reg10=reg6/reg8; reg8=reg5/reg8; reg15=reg13*reg14; T reg17=reg2*reg16; T reg18=reg13*reg16;
    T reg19=reg12*reg4; T reg20=reg16*reg9; T reg21=reg12*reg11; reg10=reg6*reg10; reg6=reg7*reg4;
    T reg22=reg2*reg14; T reg23=reg7*reg11; reg8=reg5*reg8; reg5=reg4*reg3; T reg24=reg14*reg9;
    T reg25=reg11*reg3; reg15=reg15-reg21; reg8=reg10+reg8; reg18=reg18-reg19; reg6=reg6-reg17;
    reg23=reg23-reg22; reg5=reg20+reg5; reg24=reg25+reg24; T vec_0=reg24*reg8; T vec_1=reg5*reg8;
    T vec_2=reg23*reg8; T vec_3=reg6*reg8; T vec_4=reg15*reg8; T vec_5=reg18*reg8;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
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
