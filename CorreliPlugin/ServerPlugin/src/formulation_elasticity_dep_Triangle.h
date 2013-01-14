#ifndef PROBLEM_elasticity_dep
#define PROBLEM_elasticity_dep

#ifndef Mesh_carac_elasticity_dep_HEADER
#define Mesh_carac_elasticity_dep_HEADER
#include "mesh/displayparaview.h"
#include "mesh/triangle.h"
namespace LMT {

template<class TP,unsigned dim> struct Mesh_carac_elasticity_dep {};
#ifndef IFNDEF_dep_sv_DM
#define IFNDEF_dep_sv_DM
    struct dep_sv_DM { static std::string name() { return "dep_sv"; } };
#endif // IFNDEF_dep_sv_DM

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM { static std::string name() { return "pos"; } };
#endif // IFNDEF_pos_DM

#ifndef IFNDEF_poisson_ratio_sens_DM
#define IFNDEF_poisson_ratio_sens_DM
    struct poisson_ratio_sens_DM { static std::string name() { return "poisson_ratio_sens"; } };
#endif // IFNDEF_poisson_ratio_sens_DM

#ifndef IFNDEF_f_nodal_DM
#define IFNDEF_f_nodal_DM
    struct f_nodal_DM { static std::string name() { return "f_nodal"; } };
#endif // IFNDEF_f_nodal_DM

#ifndef IFNDEF_f_vol_DM
#define IFNDEF_f_vol_DM
    struct f_vol_DM { static std::string name() { return "f_vol"; } };
#endif // IFNDEF_f_vol_DM

#ifndef IFNDEF_temperature_DM
#define IFNDEF_temperature_DM
    struct temperature_DM { static std::string name() { return "temperature"; } };
#endif // IFNDEF_temperature_DM

#ifndef IFNDEF_tr_epsilon_DM
#define IFNDEF_tr_epsilon_DM
    struct tr_epsilon_DM { static std::string name() { return "tr_epsilon"; } };
#endif // IFNDEF_tr_epsilon_DM

#ifndef IFNDEF_dep_imp_val_0_0_DM
#define IFNDEF_dep_imp_val_0_0_DM
    struct dep_imp_val_0_0_DM { static std::string name() { return "dep_imp_val_0_0"; } };
#endif // IFNDEF_dep_imp_val_0_0_DM

#ifndef IFNDEF_param_DM
#define IFNDEF_param_DM
    struct param_DM { static std::string name() { return "param"; } };
#endif // IFNDEF_param_DM

#ifndef IFNDEF_lum_DM
#define IFNDEF_lum_DM
    struct lum_DM { static std::string name() { return "lum"; } };
#endif // IFNDEF_lum_DM

#ifndef IFNDEF_elastic_modulus_DM
#define IFNDEF_elastic_modulus_DM
    struct elastic_modulus_DM { static std::string name() { return "elastic_modulus"; } };
#endif // IFNDEF_elastic_modulus_DM

#ifndef IFNDEF_dep_imp_val_0_1_DM
#define IFNDEF_dep_imp_val_0_1_DM
    struct dep_imp_val_0_1_DM { static std::string name() { return "dep_imp_val_0_1"; } };
#endif // IFNDEF_dep_imp_val_0_1_DM

#ifndef IFNDEF_normal_DM
#define IFNDEF_normal_DM
    struct normal_DM { static std::string name() { return "normal"; } };
#endif // IFNDEF_normal_DM

#ifndef IFNDEF_epsilon_DM
#define IFNDEF_epsilon_DM
    struct epsilon_DM { static std::string name() { return "epsilon"; } };
#endif // IFNDEF_epsilon_DM

#ifndef IFNDEF_me_sens_DM
#define IFNDEF_me_sens_DM
    struct me_sens_DM { static std::string name() { return "me_sens"; } };
#endif // IFNDEF_me_sens_DM

#ifndef IFNDEF_lim_cond_0_DM
#define IFNDEF_lim_cond_0_DM
    struct lim_cond_0_DM { static std::string name() { return "lim_cond_0"; } };
#endif // IFNDEF_lim_cond_0_DM

#ifndef IFNDEF_lim_cond_1_DM
#define IFNDEF_lim_cond_1_DM
    struct lim_cond_1_DM { static std::string name() { return "lim_cond_1"; } };
#endif // IFNDEF_lim_cond_1_DM

#ifndef IFNDEF_poisson_ratio_DM
#define IFNDEF_poisson_ratio_DM
    struct poisson_ratio_DM { static std::string name() { return "poisson_ratio"; } };
#endif // IFNDEF_poisson_ratio_DM

#ifndef IFNDEF_dep_imp_coef_0_DM
#define IFNDEF_dep_imp_coef_0_DM
    struct dep_imp_coef_0_DM { static std::string name() { return "dep_imp_coef_0"; } };
#endif // IFNDEF_dep_imp_coef_0_DM

#ifndef IFNDEF_eps_11_DM
#define IFNDEF_eps_11_DM
    struct eps_11_DM { static std::string name() { return "eps_11"; } };
#endif // IFNDEF_eps_11_DM

#ifndef IFNDEF_me_DM
#define IFNDEF_me_DM
    struct me_DM { static std::string name() { return "me"; } };
#endif // IFNDEF_me_DM

#ifndef IFNDEF_dep_DM
#define IFNDEF_dep_DM
    struct dep_DM { static std::string name() { return "dep"; } };
#endif // IFNDEF_dep_DM

#ifndef IFNDEF_density_DM
#define IFNDEF_density_DM
    struct density_DM { static std::string name() { return "density"; } };
#endif // IFNDEF_density_DM

#ifndef IFNDEF_p_DM
#define IFNDEF_p_DM
    struct p_DM { static std::string name() { return "p"; } };
#endif // IFNDEF_p_DM

#ifndef IFNDEF_is_on_skin_DM
#define IFNDEF_is_on_skin_DM
    struct is_on_skin_DM { static std::string name() { return "is_on_skin"; } };
#endif // IFNDEF_is_on_skin_DM

#ifndef IFNDEF_f_surf_DM
#define IFNDEF_f_surf_DM
    struct f_surf_DM { static std::string name() { return "f_surf"; } };
#endif // IFNDEF_f_surf_DM

#ifndef IFNDEF_sigma_DM
#define IFNDEF_sigma_DM
    struct sigma_DM { static std::string name() { return "sigma"; } };
#endif // IFNDEF_sigma_DM

template<class TP>
struct Mesh_carac_elasticity_dep<TP,2> {
    typedef TP Tpos;
    static const unsigned dim = 2;
    typedef Vec<TP,2> Pvec;
    struct NodalStaticData {
        typedef Tpos T1;
        typedef Vec<Tpos,2> T0;
        NodalStaticData():dep_sv(0.0),f_nodal(0.0,0.0),temperature(0.0),dep_imp_val_0_0(0),lum(1.0),dep_imp_val_0_1(0),normal(0.0),dep_imp_coef_0(0),dep(0.0),is_on_skin(0) {}
        CARACDMEXTNAME( 0, T0, dep_sv, "m" );
        CARACDMEXTNAME( 1, T0, pos, "m" );
        CARACDMEXTNAME( 2, T0, f_nodal, "N" );
        CARACDMEXTNAME( 3, T1, temperature, "K" );
        CARACDMEXTNAME( 4, T0, dep_imp_val_0_0, "1" );
        CARACDMEXTNAME( 5, T1, lum, "1" );
        CARACDMEXTNAME( 6, T0, dep_imp_val_0_1, "1" );
        CARACDMEXTNAME( 7, T0, normal, "1" );
        CARACDMEXTNAME( 8, T1, dep_imp_coef_0, "1" );
        CARACDMEXTNAME( 9, T0, dep, "m" );
        CARACDMEXTNAME( 10, T1, is_on_skin, "" );
        static const unsigned nb_params = 11;
        void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
            if ( field_name == "dep_sv" ) { dep_sv = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( field_name == "f_nodal" ) { f_nodal = value; return; }
            if ( field_name == "temperature" ) { temperature = value; return; }
            if ( field_name == "dep_imp_val_0_0" ) { dep_imp_val_0_0 = value; return; }
            if ( field_name == "lum" ) { lum = value; return; }
            if ( field_name == "dep_imp_val_0_1" ) { dep_imp_val_0_1 = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "dep_imp_coef_0" ) { dep_imp_coef_0 = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "is_on_skin" ) { is_on_skin = value; return; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
            if ( field_name == "dep_sv" ) { dep_sv = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( field_name == "f_nodal" ) { f_nodal = value; return; }
            if ( field_name == "dep_imp_val_0_0" ) { dep_imp_val_0_0 = value; return; }
            if ( field_name == "dep_imp_val_0_1" ) { dep_imp_val_0_1 = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
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
            if ( field_name == "temperature" ) { return temperature; }
            if ( field_name == "lum" ) { return lum; }
            if ( field_name == "dep_imp_coef_0" ) { return dep_imp_coef_0; }
            if ( field_name == "is_on_skin" ) { return is_on_skin; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
            if ( field_name == "dep_sv" ) { return dep_sv; }
            if ( field_name == "pos" ) { return pos; }
            if ( field_name == "f_nodal" ) { return f_nodal; }
            if ( field_name == "dep_imp_val_0_0" ) { return dep_imp_val_0_0; }
            if ( field_name == "dep_imp_val_0_1" ) { return dep_imp_val_0_1; }
            if ( field_name == "normal" ) { return normal; }
            if ( field_name == "dep" ) { return dep; }
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
    struct GlobalStaticData {
        typedef Tpos T0;
        typedef Vec<Tpos,2> T1;
        GlobalStaticData():poisson_ratio_sens(0),f_vol(0.0,0.0),param(0),elastic_modulus(1),me_sens(0),lim_cond_0(1),lim_cond_1(0),poisson_ratio(0.33),me(0),density(7800) {}
        CARACDMEXTNAME( 0, T0, poisson_ratio_sens, "1" );
        CARACDMEXTNAME( 1, T1, f_vol, "N/m^3" );
        CARACDMEXTNAME( 2, T0, param, "1" );
        CARACDMEXTNAME( 3, T0, elastic_modulus, "N/m^2" );
        CARACDMEXTNAME( 4, T0, me_sens, "1" );
        CARACDMEXTNAME( 5, T0, lim_cond_0, "1" );
        CARACDMEXTNAME( 6, T0, lim_cond_1, "1" );
        CARACDMEXTNAME( 7, T0, poisson_ratio, "1" );
        CARACDMEXTNAME( 8, T0, me, "1" );
        CARACDMEXTNAME( 9, T0, density, "kg/m^3" );
        static const unsigned nb_params = 10;
        void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
            if ( field_name == "poisson_ratio_sens" ) { poisson_ratio_sens = value; return; }
            if ( field_name == "f_vol" ) { f_vol = value; return; }
            if ( field_name == "param" ) { param = value; return; }
            if ( field_name == "elastic_modulus" ) { elastic_modulus = value; return; }
            if ( field_name == "me_sens" ) { me_sens = value; return; }
            if ( field_name == "lim_cond_0" ) { lim_cond_0 = value; return; }
            if ( field_name == "lim_cond_1" ) { lim_cond_1 = value; return; }
            if ( field_name == "poisson_ratio" ) { poisson_ratio = value; return; }
            if ( field_name == "me" ) { me = value; return; }
            if ( field_name == "density" ) { density = value; return; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
            if ( field_name == "f_vol" ) { f_vol = value; return; }
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
            if ( field_name == "poisson_ratio_sens" ) { return poisson_ratio_sens; }
            if ( field_name == "param" ) { return param; }
            if ( field_name == "elastic_modulus" ) { return elastic_modulus; }
            if ( field_name == "me_sens" ) { return me_sens; }
            if ( field_name == "lim_cond_0" ) { return lim_cond_0; }
            if ( field_name == "lim_cond_1" ) { return lim_cond_1; }
            if ( field_name == "poisson_ratio" ) { return poisson_ratio; }
            if ( field_name == "me" ) { return me; }
            if ( field_name == "density" ) { return density; }
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
            if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
            if ( field_name == "f_vol" ) { return f_vol; }
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
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> { typedef Triangle NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Tpos,1> T0;
            typedef Vec<Vec<Tpos,3>,1> T1;
            TData():tr_epsilon(0),epsilon(0),eps_11(0),sigma(0) {}
            CARACDMEXTNAME( 0, T0, tr_epsilon, "1" );
            CARACDMEXTNAME( 1, T1, epsilon, "1" );
            CARACDMEXTNAME( 2, T0, eps_11, "1" );
            CARACDMEXTNAME( 3, T1, sigma, "N/m^2" );
            static const unsigned nb_params = 4;
            void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
                if ( field_name == "tr_epsilon" ) { tr_epsilon[0] = value; } // hum
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                if ( field_name == "eps_11" ) { eps_11[0] = value; } // hum
                if ( field_name == "sigma" ) { sigma[0] = value; } // hum
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value, bool disp = true ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                if ( field_name == "sigma" ) { sigma[0] = value; } // hum
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
                if ( field_name == "tr_epsilon" ) { return tr_epsilon[0]; } // hum
                if ( field_name == "eps_11" ) { return eps_11[0]; } // hum
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
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                if ( field_name == "sigma" ) { return sigma[0]; } // hum
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
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,0,inner> { typedef Bar NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Tpos T0;
            typedef Vec<Tpos,2> T1;
            TData():p(0.0),f_surf(0.0,0.0) {}
            CARACDMEXTNAME( 0, T0, p, "N/m^2" );
            CARACDMEXTNAME( 1, T1, f_surf, "N/m^2" );
            static const unsigned nb_params = 2;
            void dm_data_set_field( const std::string field_name, Tpos value, bool disp = true ) {
                if ( field_name == "p" ) { p = value; return; }
                if ( field_name == "f_surf" ) { f_surf = value; return; }
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value, bool disp = true ) {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value, bool disp = true ) {
                if ( field_name == "f_surf" ) { f_surf = value; return; }
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
                if ( field_name == "p" ) { return p; }
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> >, bool disp = true ) const {
                if ( disp == true ) { std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl; }
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> >, bool disp = true ) const {
                if ( field_name == "f_surf" ) { return f_surf; }
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
    template<unsigned skin,unsigned inner> struct ElementChoice<2,skin,0,inner> { typedef NodalElement NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
};
} // namespace LMT
#endif // Mesh_carac_elasticity_dep_HEADER

#include "formulation/formulation.h"
namespace LMT {
#ifndef ELASTICITY_DEP_2_NUM_0_CARAC_H
#define ELASTICITY_DEP_2_NUM_0_CARAC_H
#ifndef STRUCT_ELASTICITY_DEP
#define STRUCT_ELASTICITY_DEP
struct elasticity_dep {
  static const char *name() { return "elasticity_dep"; }
};
#endif // ELASTICITY_DEP

template<class P_T>
class CaracFormulation<elasticity_dep,2,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "elasticity_dep"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = true;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 4;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 1;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
      (*f.m).param += v[ 0 ];
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
    node.dep[0]=vecs[0][indice+0]; node.dep[1]=vecs[0][indice+1];
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
#endif // ELASTICITY_DEP_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_elasticity_dep_Triangle_0( double * );
extern "C" void apply_on_elements_after_solve_1_elasticity_dep_Triangle_1( double * );
extern "C" void apply_on_elements_after_solve_2_elasticity_dep_Triangle_2( double * );
extern "C" void apply_on_elements_after_solve_3_elasticity_dep_Triangle_3( double * );
extern "C" void apply_on_elements_after_solve_4_elasticity_dep_Triangle_4( double * );
extern "C" void apply_on_elements_after_solve_5_elasticity_dep_Triangle_5( double * );
extern "C" void apply_on_elements_after_solve_6_elasticity_dep_Triangle_6( double * );
extern "C" void apply_on_elements_after_solve_7_elasticity_dep_Triangle_7( double * );
extern "C" void apply_on_elements_after_solve_8_elasticity_dep_Triangle_8( double * );
extern "C" void apply_on_elements_after_solve_9_elasticity_dep_Triangle_9( double * );
extern "C" void apply_on_elements_after_solve_10_elasticity_dep_Triangle_10( double * );
extern "C" void apply_on_elements_after_solve_11_elasticity_dep_Triangle_11( double * );
extern "C" void apply_on_elements_after_solve_12_elasticity_dep_Triangle_12( double * );
extern "C" void apply_on_elements_after_solve_13_elasticity_dep_Triangle_13( double * );
extern "C" void apply_on_elements_after_solve_14_elasticity_dep_Triangle_14( double * );
class Triangle;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<elasticity_dep,Element<Triangle,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 0;
    static const bool has_elementary_matrix = true;
    static const bool has_skin_elementary_matrix = true;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=1+(*f.m).poisson_ratio; reg0=reg0/(*f.m).elastic_modulus; T reg1=pow(reg0,2); T reg2=(*f.m).poisson_ratio/(*f.m).elastic_modulus; reg0=reg0*reg1;
    T reg3=1.0/(*f.m).elastic_modulus; T reg4=reg2*reg0; reg0=reg3*reg0; T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0];
    T reg7=elem.pos(1)[1]-elem.pos(0)[1]; T reg8=elem.pos(1)[0]-elem.pos(0)[0]; T reg9=reg3*reg0; T reg10=reg8*reg5; T reg11=reg2*reg1;
    T reg12=reg2*reg4; reg0=reg2*reg0; reg1=reg3*reg1; T reg13=reg7*reg6; reg9=reg9-reg12;
    reg0=reg12+reg0; reg4=reg3*reg4; T reg14=reg2*reg1; T reg15=reg2*reg11; reg1=reg3*reg1;
    reg13=reg10-reg13; reg10=reg2*reg0; reg11=reg3*reg11; reg4=reg12+reg4; reg1=reg1-reg15;
    reg14=reg14+reg15; reg12=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; reg8=reg8/reg13; reg6=reg6/reg13; reg5=reg5/reg13;
    reg13=reg7/reg13; reg7=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg16=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg17=reg3*reg9; T reg18=vectors[0][indices[1]+0]-vectors[0][indices[0]+0];
    reg1=reg3*reg1; reg4=reg2*reg4; reg14=reg2*reg14; T reg19=reg8*reg7; reg10=reg17-reg10;
    reg17=reg13*reg12; T reg20=reg6*reg18; T reg21=reg15+reg11; T reg22=reg5*reg16; reg18=reg5*reg18;
    reg16=reg6*reg16; reg7=reg13*reg7; reg12=reg8*reg12; reg20=reg19-reg20; reg21=reg2*reg21;
    reg14=reg1-reg14; reg4=reg10-reg4; reg17=reg22-reg17; reg17=reg20+reg17; reg9=reg9/reg4;
    reg7=reg18-reg7; elem.epsilon[0][0]=reg7; reg16=reg12-reg16; elem.epsilon[0][1]=reg16; reg21=reg14-reg21;
    reg0=reg0/reg4; reg1=reg9*reg7; reg2=reg0*reg7; reg9=reg9*reg16; reg0=reg0*reg16;
    reg4=reg21/reg4; reg17=0.5*reg17; elem.epsilon[0][2]=reg17; elem.sigma[0][0]=reg0+reg1; elem.sigma[0][1]=reg2+reg9;
    elem.tr_epsilon=reg16+reg7; elem.sigma[0][2]=reg4*reg17;
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
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(1)[0]-elem.pos(0)[0];
    T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(2)[0]-elem.pos(0)[0]; T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=pow(reg1,2); T reg7=reg3*reg4;
    T reg8=1.0/(*f.m).elastic_modulus; reg0=reg0/(*f.m).elastic_modulus; T reg9=reg2*reg5; reg1=reg1*reg6; T reg10=reg0*reg6;
    T reg11=reg0*reg1; reg7=reg9-reg7; reg1=reg8*reg1; reg6=reg8*reg6; reg9=vectors[0][indices[2]+1]-vectors[0][indices[0]+1];
    T reg12=reg8*reg1; T reg13=reg0*reg11; T reg14=reg8*reg6; T reg15=reg0*reg10; reg6=reg0*reg6;
    reg1=reg0*reg1; T reg16=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg17=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg18=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg19=reg3/reg7;
    T reg20=reg2/reg7; reg5=reg5/reg7; reg4=reg4/reg7; reg12=reg12-reg13; reg14=reg14-reg15;
    T reg21=reg4*reg16; reg11=reg8*reg11; T reg22=reg19*reg17; T reg23=reg20*reg9; reg1=reg13+reg1;
    reg10=reg8*reg10; T reg24=reg5*reg18; reg6=reg6+reg15; reg6=reg0*reg6; reg16=reg5*reg16;
    reg22=reg24-reg22; reg24=reg15+reg10; reg14=reg8*reg14; reg9=reg19*reg9; reg11=reg13+reg11;
    reg18=reg4*reg18; reg17=reg20*reg17; reg13=reg8*reg12; reg21=reg23-reg21; reg23=reg0*reg1;
    T reg25=(*f.m).param*(*f.m).me_sens; reg24=reg0*reg24; reg6=reg14-reg6; reg11=reg0*reg11; reg23=reg13-reg23;
    reg0=reg22+reg21; reg18=reg17-reg18; reg9=reg16-reg9; reg13=reg19-reg5; reg0=reg0/2;
    reg9=reg18+reg9; reg24=reg6-reg24; reg11=reg23-reg11; reg25=(*f.m).me+reg25; reg9=0.5*reg9;
    reg24=reg24/reg11; reg1=reg1/reg11; reg11=reg12/reg11; reg6=reg13/2; reg0=reg25*reg0;
    reg12=reg4-reg20; reg14=0.5*reg12; reg9=reg24*reg9; reg16=reg12/2; reg6=reg25*reg6;
    reg17=reg11*reg21; reg18=reg1*reg22; reg0=1+reg0; reg21=reg1*reg21; reg22=reg11*reg22;
    reg17=reg18+reg17; reg18=reg5/2; reg23=reg24*reg14; reg21=reg22+reg21; reg16=reg25*reg16;
    reg22=0.5*reg13; T reg26=reg9*reg6; T reg27=pow(reg0,2); T reg28=reg23/reg0; T reg29=reg24*reg22;
    reg26=reg26/reg27; T reg30=reg9*reg16; reg18=reg25*reg18; T reg31=reg21*reg6; T reg32=reg4/2;
    T reg33=reg1*reg13; reg6=reg17*reg6; T reg34=reg11*reg13; T reg35=0.5*reg4; T reg36=reg34/reg0;
    reg31=reg31/reg27; reg6=reg6/reg27; T reg37=0.5*reg5; reg26=reg28-reg26; reg28=reg1*reg12;
    T reg38=reg21*reg16; reg30=reg30/reg27; T reg39=reg29/reg0; T reg40=reg24*reg35; T reg41=reg9*reg18;
    T reg42=reg25*reg32; T reg43=reg19/2; T reg44=reg33/reg0; T reg45=reg11*reg12; reg16=reg17*reg16;
    reg16=reg16/reg27; T reg46=reg21*reg18; reg31=reg36-reg31; reg36=reg5*reg11; T reg47=reg20/2;
    reg6=reg44-reg6; reg26=2*reg26; reg44=0.5*reg19; T reg48=reg24*reg37; T reg49=reg9*reg42;
    T reg50=reg45/reg0; T reg51=0.5*reg20; T reg52=1-var_inter[0]; reg41=reg41/reg27; T reg53=reg9/reg0;
    T reg54=reg25*reg43; T reg55=reg28/reg0; reg38=reg38/reg27; reg30=reg39-reg30; reg18=reg17*reg18;
    reg39=reg5*reg1; T reg56=reg40/reg0; T reg57=reg24*reg51; T reg58=reg14*reg26; reg49=reg49/reg27;
    T reg59=reg48/reg0; T reg60=reg4*reg6; T reg61=reg5*reg31; T reg62=reg9*reg54; reg38=reg55-reg38;
    reg47=reg25*reg47; reg30=2*reg30; reg55=reg13*reg31; T reg63=reg17/reg0; T reg64=reg21/reg0;
    reg53=2*reg53; T reg65=reg4*reg1; reg56=reg41+reg56; reg41=reg17*reg42; T reg66=reg4*reg11;
    T reg67=reg51*reg26; T reg68=reg39/reg0; reg18=reg18/reg27; T reg69=reg37*reg26; T reg70=reg20*reg6;
    reg16=reg50-reg16; reg50=reg21*reg42; T reg71=reg35*reg26; T reg72=reg44*reg26; reg26=reg22*reg26;
    reg6=reg12*reg6; T reg73=reg52-var_inter[1]; reg31=reg19*reg31; T reg74=reg36/reg0; reg46=reg46/reg27;
    T reg75=reg65/reg0; T reg76=reg44*reg30; reg50=reg50/reg27; reg9=reg9*reg47; reg41=reg41/reg27;
    T reg77=reg20*reg16; reg18=reg68-reg18; reg68=reg51*reg30; T reg78=reg22*reg30; T reg79=reg12*reg16;
    reg26=reg6+reg26; reg31=reg67-reg31; reg60=reg69-reg60; reg6=reg19*reg1; reg59=reg49+reg59;
    reg49=reg24*reg44; reg67=reg17*reg54; reg69=reg66/reg0; T reg80=reg37*reg30; T reg81=reg19*reg38;
    T reg82=reg57/reg0; reg62=reg62/reg27; reg16=reg4*reg16; T reg83=reg21*reg54; T reg84=reg19*reg11;
    T reg85=(*f.m).f_vol[1]*var_inter[1]; T reg86=(*f.m).f_vol[0]*var_inter[1]; T reg87=reg35*reg30; T reg88=reg64*reg13; T reg89=reg53*reg14;
    T reg90=reg5*reg38; T reg91=reg20*reg63; T reg92=(*f.m).f_vol[0]*reg73; T reg93=reg53*reg44; reg38=reg13*reg38;
    reg58=reg55+reg58; reg55=reg5*reg64; reg71=reg61-reg71; reg61=reg63*reg12; reg72=reg70-reg72;
    reg70=reg53*reg22; T reg94=(*f.m).f_vol[1]*reg73; reg30=reg14*reg30; T reg95=reg4*reg63; T reg96=reg53*reg35;
    T reg97=reg53*reg37; T reg98=2*reg56; T reg99=(*f.m).f_vol[1]*var_inter[0]; reg46=reg74-reg46; reg74=(*f.m).f_vol[0]*var_inter[0];
    T reg100=reg19*reg64; T reg101=reg53*reg51; reg71=reg7*reg71; reg86=(*f.m).density*reg86; reg9=reg9/reg27;
    T reg102=reg49/reg0; reg60=reg7*reg60; reg101=reg101-reg100; T reg103=reg22*reg98; reg97=reg97-reg95;
    reg26=reg7*reg26; T reg104=reg51*reg98; reg87=reg90-reg87; reg99=(*f.m).density*reg99; reg90=reg35*reg98;
    reg69=reg41-reg69; reg85=(*f.m).density*reg85; reg21=reg21*reg47; reg91=reg91-reg93; reg41=reg12*reg18;
    reg78=reg79+reg78; reg74=(*f.m).density*reg74; reg94=(*f.m).density*reg94; reg16=reg80-reg16; reg81=reg68-reg81;
    reg68=reg20*reg18; reg79=reg5*reg46; reg59=2*reg59; reg30=reg38+reg30; reg38=reg20*reg11;
    reg89=reg88+reg89; reg75=reg50-reg75; reg47=reg17*reg47; reg17=reg13*reg46; reg50=reg44*reg98;
    reg18=reg4*reg18; reg80=reg14*reg98; reg88=reg37*reg98; reg83=reg83/reg27; reg31=reg7*reg31;
    reg70=reg61+reg70; reg67=reg67/reg27; reg72=reg7*reg72; reg61=reg20*reg1; T reg105=reg6/reg0;
    reg82=reg62+reg82; reg58=reg7*reg58; reg76=reg77-reg76; reg46=reg19*reg46; reg55=reg55-reg96;
    reg92=(*f.m).density*reg92; reg62=reg84/reg0; reg77=reg12*reg69; T reg106=reg35*reg59; T reg107=reg5*reg75;
    T reg108=reg38/reg0; reg87=reg7*reg87; reg46=reg104+reg46; reg71=ponderation*reg71; T tmp_2_0=reg71;
    reg68=reg68+reg50; T reg109=reg51*reg59; reg105=reg67-reg105; reg76=reg7*reg76; reg67=reg20*reg69;
    T reg110=reg44*reg59; reg47=reg47/reg27; reg81=reg7*reg81; T reg111=reg19*reg75; reg86=reg101-reg86;
    reg85=reg91-reg85; reg69=reg4*reg69; reg91=reg37*reg59; reg94=reg70-reg94; reg99=reg97-reg99;
    reg92=reg89-reg92; reg58=ponderation*reg58; T tmp_0_0=reg58; reg30=reg7*reg30; reg18=reg88+reg18;
    reg79=reg79+reg90; reg17=reg17-reg80; reg75=reg13*reg75; reg31=ponderation*reg31; T tmp_4_0=reg31;
    reg72=ponderation*reg72; T tmp_5_0=reg72; reg41=reg41-reg103; reg78=reg7*reg78; reg26=ponderation*reg26;
    T tmp_1_0=reg26; reg102=reg9+reg102; reg60=ponderation*reg60; T tmp_3_0=reg60; reg0=reg61/reg0;
    reg27=reg21/reg27; reg9=reg14*reg59; reg82=2*reg82; reg62=reg83-reg62; reg16=reg7*reg16;
    reg59=reg22*reg59; reg74=reg55-reg74; reg106=reg107-reg106; reg21=reg4*reg105; reg68=reg7*reg68;
    reg111=reg109-reg111; reg55=reg37*reg82; reg69=reg91-reg69; reg70=reg7*reg18; reg83=reg5*reg62;
    reg89=reg35*reg82; reg16=ponderation*reg16; T tmp_3_1=reg16; reg76=ponderation*reg76; T tmp_5_1=reg76;
    reg81=ponderation*reg81; T tmp_4_1=reg81; reg91=reg13*reg62; reg60=vectors[0][indices[0]+0]*reg60; reg9=reg75+reg9;
    reg17=reg7*reg17; reg75=reg14*reg82; reg30=ponderation*reg30; T tmp_0_1=reg30; reg92=reg7*reg92;
    reg79=reg7*reg79; reg94=reg7*reg94; reg31=vectors[0][indices[0]+0]*reg31; reg85=reg7*reg85; reg62=reg19*reg62;
    reg86=reg7*reg86; reg72=vectors[0][indices[0]+0]*reg72; reg99=reg7*reg99; reg74=reg7*reg74; reg71=vectors[0][indices[0]+0]*reg71;
    reg87=ponderation*reg87; T tmp_2_1=reg87; reg97=reg51*reg82; reg110=reg67-reg110; reg47=reg108-reg47;
    reg67=reg20*reg105; reg101=reg44*reg82; reg107=reg7*reg46; reg105=reg12*reg105; reg82=reg22*reg82;
    reg77=reg59+reg77; reg41=reg7*reg41; reg78=ponderation*reg78; T tmp_1_1=reg78; reg58=vectors[0][indices[0]+0]*reg58;
    reg26=vectors[0][indices[0]+0]*reg26; reg59=2*reg102; reg27=reg0-reg27; reg78=vectors[0][indices[0]+1]*reg78; reg111=reg7*reg111;
    reg0=ponderation*reg107; reg79=ponderation*reg79; T tmp_2_2=reg79; reg72=f.premul_KUn_in_sollicitation*reg72; reg76=vectors[0][indices[0]+1]*reg76;
    reg31=f.premul_KUn_in_sollicitation*reg31; reg81=vectors[0][indices[0]+1]*reg81; reg60=f.premul_KUn_in_sollicitation*reg60; reg16=vectors[0][indices[0]+1]*reg16; reg71=f.premul_KUn_in_sollicitation*reg71;
    reg87=vectors[0][indices[0]+1]*reg87; reg26=f.premul_KUn_in_sollicitation*reg26; reg62=reg97-reg62; reg58=f.premul_KUn_in_sollicitation*reg58; reg30=vectors[0][indices[0]+1]*reg30;
    reg97=reg44*reg59; reg108=reg20*reg47; reg101=reg67-reg101; reg110=reg7*reg110; reg68=ponderation*reg68;
    T tmp_5_2=reg68; reg67=reg19*reg27; reg109=reg51*reg59; reg92=ponderation*reg92; reg106=reg7*reg106;
    reg74=ponderation*reg74; reg89=reg83-reg89; reg83=reg14*reg59; T reg112=reg13*reg27; reg27=reg5*reg27;
    T reg113=reg35*reg59; T reg114=reg22*reg59; T reg115=ponderation*reg70; T reg116=reg12*reg47; reg69=reg7*reg69;
    reg85=ponderation*reg85; reg94=ponderation*reg94; reg77=reg7*reg77; reg91=reg75+reg91; reg21=reg55-reg21;
    reg9=reg7*reg9; reg86=ponderation*reg86; reg105=reg82+reg105; reg41=ponderation*reg41; T tmp_1_2=reg41;
    reg17=ponderation*reg17; T tmp_0_2=reg17; reg99=ponderation*reg99; reg55=reg37*reg59; reg47=reg4*reg47;
    reg75=vectors[0][indices[1]+0]*reg0; reg108=reg108+reg97; reg81=f.premul_KUn_in_sollicitation*reg81; reg17=vectors[0][indices[1]+0]*reg17; reg30=f.premul_KUn_in_sollicitation*reg30;
    reg78=f.premul_KUn_in_sollicitation*reg78; reg112=reg112-reg83; reg94=reg26-reg94; reg92=reg58-reg92; reg41=vectors[0][indices[1]+0]*reg41;
    reg86=reg31-reg86; reg91=reg7*reg91; reg74=reg71-reg74; reg87=f.premul_KUn_in_sollicitation*reg87; reg79=vectors[0][indices[1]+0]*reg79;
    reg26=vectors[0][indices[1]+0]*reg115; reg16=f.premul_KUn_in_sollicitation*reg16; reg99=reg60-reg99; reg9=ponderation*reg9; T tmp_0_3=reg9;
    reg68=vectors[0][indices[1]+0]*reg68; reg106=ponderation*reg106; T tmp_2_3=reg106; reg89=reg7*reg89; reg116=reg116-reg114;
    reg67=reg109+reg67; reg69=ponderation*reg69; T tmp_3_3=reg69; reg62=reg7*reg62; reg27=reg27+reg113;
    reg21=reg7*reg21; reg110=ponderation*reg110; T tmp_5_3=reg110; reg111=ponderation*reg111; T tmp_4_3=reg111;
    reg85=reg72-reg85; reg77=ponderation*reg77; T tmp_1_3=reg77; reg47=reg55+reg47; reg105=reg7*reg105;
    reg101=reg7*reg101; reg76=f.premul_KUn_in_sollicitation*reg76; reg62=ponderation*reg62; T tmp_4_4=reg62; reg31=reg7*reg67;
    reg69=vectors[0][indices[1]+1]*reg69; reg76=reg85+reg76; reg26=f.premul_KUn_in_sollicitation*reg26; reg91=ponderation*reg91; T tmp_0_4=reg91;
    reg41=f.premul_KUn_in_sollicitation*reg41; reg87=reg74+reg87; reg79=f.premul_KUn_in_sollicitation*reg79; reg106=vectors[0][indices[1]+1]*reg106; reg16=reg99+reg16;
    reg21=ponderation*reg21; T tmp_3_4=reg21; reg68=f.premul_KUn_in_sollicitation*reg68; reg58=reg7*reg47; reg112=reg7*reg112;
    reg17=f.premul_KUn_in_sollicitation*reg17; reg30=reg92+reg30; reg110=vectors[0][indices[1]+1]*reg110; reg9=vectors[0][indices[1]+1]*reg9; reg105=ponderation*reg105;
    T tmp_1_4=reg105; reg111=vectors[0][indices[1]+1]*reg111; reg75=f.premul_KUn_in_sollicitation*reg75; reg81=reg86+reg81; reg116=reg7*reg116;
    reg89=ponderation*reg89; T tmp_2_4=reg89; reg101=ponderation*reg101; T tmp_5_4=reg101; reg108=reg7*reg108;
    reg77=vectors[0][indices[1]+1]*reg77; reg27=reg7*reg27; reg78=reg94+reg78; reg68=reg76+reg68; reg41=reg78+reg41;
    reg26=reg16-reg26; reg62=vectors[0][indices[2]+0]*reg62; reg111=f.premul_KUn_in_sollicitation*reg111; reg75=reg81-reg75; reg69=f.premul_KUn_in_sollicitation*reg69;
    reg21=vectors[0][indices[2]+0]*reg21; reg110=f.premul_KUn_in_sollicitation*reg110; reg79=reg87+reg79; reg91=vectors[0][indices[2]+0]*reg91; reg105=vectors[0][indices[2]+0]*reg105;
    reg9=f.premul_KUn_in_sollicitation*reg9; reg77=f.premul_KUn_in_sollicitation*reg77; reg17=reg30+reg17; reg112=ponderation*reg112; T tmp_0_5=reg112;
    reg101=vectors[0][indices[2]+0]*reg101; reg106=f.premul_KUn_in_sollicitation*reg106; reg108=ponderation*reg108; T tmp_5_5=reg108; reg89=vectors[0][indices[2]+0]*reg89;
    reg116=ponderation*reg116; T tmp_1_5=reg116; reg27=ponderation*reg27; T tmp_2_5=reg27; reg16=ponderation*reg31;
    reg30=ponderation*reg58; reg101=f.premul_KUn_in_sollicitation*reg101; reg112=vectors[0][indices[2]+1]*reg112; reg110=reg68+reg110; reg91=f.premul_KUn_in_sollicitation*reg91;
    reg9=reg17+reg9; reg111=reg75+reg111; reg62=f.premul_KUn_in_sollicitation*reg62; reg17=vectors[0][indices[2]+1]*reg16; reg108=vectors[0][indices[2]+1]*reg108;
    reg27=vectors[0][indices[2]+1]*reg27; reg77=reg41+reg77; reg105=f.premul_KUn_in_sollicitation*reg105; reg41=vectors[0][indices[2]+1]*reg30; reg21=f.premul_KUn_in_sollicitation*reg21;
    reg89=f.premul_KUn_in_sollicitation*reg89; reg106=reg79+reg106; reg69=reg26+reg69; reg116=vectors[0][indices[2]+1]*reg116; reg27=f.premul_KUn_in_sollicitation*reg27;
    reg108=f.premul_KUn_in_sollicitation*reg108; reg89=reg106+reg89; reg101=reg110+reg101; reg116=f.premul_KUn_in_sollicitation*reg116; reg17=f.premul_KUn_in_sollicitation*reg17;
    reg62=reg111+reg62; reg105=reg77+reg105; reg21=reg69+reg21; reg41=f.premul_KUn_in_sollicitation*reg41; reg91=reg9+reg91;
    reg112=f.premul_KUn_in_sollicitation*reg112; T tmp_3_5=-reg30; T vec_5=reg101+reg108; T vec_4=reg62-reg17; T vec_3=reg21-reg41;
    T vec_2=reg89+reg27; T vec_1=reg105+reg116; T vec_0=reg91+reg112; T tmp_3_2=-reg115; T tmp_4_5=-reg16;
    T tmp_4_2=-reg0;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[0]+1) += tmp_0_1;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[1]+1) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+0,indices[2]+1) += tmp_0_5;
    matrix(indices[0]+1,indices[0]+0) += tmp_1_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+0) += tmp_1_2;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+0) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[0]+1) += tmp_2_1;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[1]+1) += tmp_2_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+0,indices[2]+1) += tmp_2_5;
    matrix(indices[1]+1,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+0) += tmp_3_2;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+0) += tmp_3_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[0]+1) += tmp_4_1;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[1]+1) += tmp_4_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+0,indices[2]+1) += tmp_4_5;
    matrix(indices[2]+1,indices[0]+0) += tmp_5_0;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+0) += tmp_5_2;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+0) += tmp_5_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(2)[1]-elem.pos(0)[1];
    T reg3=pow(reg1,2); T reg4=elem.pos(1)[0]-elem.pos(0)[0]; T reg5=elem.pos(1)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=reg4*reg2;
    reg0=reg0/(*f.m).elastic_modulus; T reg8=1.0/(*f.m).elastic_modulus; T reg9=reg5*reg6; reg1=reg1*reg3; reg9=reg7-reg9;
    reg7=reg0*reg1; reg1=reg8*reg1; T reg10=reg8*reg3; reg3=reg0*reg3; reg6=reg6/reg9;
    T reg11=reg0*reg1; T reg12=reg0*reg7; T reg13=reg8*reg10; T reg14=reg0*reg3; reg1=reg8*reg1;
    reg10=reg0*reg10; T reg15=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg16=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg17=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg18=vectors[0][indices[2]+0]-vectors[0][indices[0]+0];
    T reg19=reg5/reg9; T reg20=reg4/reg9; reg2=reg2/reg9; reg10=reg10+reg14; reg7=reg8*reg7;
    reg11=reg12+reg11; reg3=reg8*reg3; reg13=reg13-reg14; reg1=reg1-reg12; T reg21=reg2*reg16;
    T reg22=reg19*reg18; T reg23=reg20*reg17; T reg24=reg6*reg15; T reg25=reg14+reg3; reg22=reg21-reg22;
    reg24=reg23-reg24; reg17=reg19*reg17; reg10=reg0*reg10; reg15=reg2*reg15; reg18=reg20*reg18;
    reg16=reg6*reg16; reg7=reg12+reg7; reg13=reg8*reg13; reg12=reg8*reg1; reg21=reg0*reg11;
    reg10=reg13-reg10; reg25=reg0*reg25; reg7=reg0*reg7; reg16=reg18-reg16; reg0=reg22+reg24;
    reg21=reg12-reg21; reg17=reg15-reg17; reg12=(*f.m).param*(*f.m).me_sens; reg13=reg19-reg2; reg12=(*f.m).me+reg12;
    reg17=reg16+reg17; reg7=reg21-reg7; reg0=reg0/2; reg25=reg10-reg25; reg0=reg12*reg0;
    reg10=reg13/2; reg15=reg6-reg20; reg1=reg1/reg7; reg17=0.5*reg17; reg11=reg11/reg7;
    reg7=reg25/reg7; reg16=reg1*reg24; reg18=0.5*reg15; reg21=reg11*reg22; reg17=reg7*reg17;
    reg0=1+reg0; reg24=reg11*reg24; reg10=reg12*reg10; reg22=reg1*reg22; reg23=reg15/2;
    reg25=pow(reg0,2); T reg26=0.5*reg13; reg16=reg21+reg16; reg21=reg17*reg10; reg24=reg22+reg24;
    reg22=reg7*reg18; reg23=reg12*reg23; T reg27=reg2/2; T reg28=reg16*reg10; T reg29=0.5*reg6;
    T reg30=reg1*reg13; T reg31=reg11*reg13; T reg32=reg6/2; reg27=reg12*reg27; T reg33=reg17*reg23;
    T reg34=reg7*reg26; reg10=reg24*reg10; T reg35=reg22/reg0; reg21=reg21/reg25; reg28=reg28/reg25;
    T reg36=reg7*reg29; T reg37=reg31/reg0; reg33=reg33/reg25; T reg38=reg34/reg0; T reg39=reg12*reg32;
    T reg40=reg1*reg15; reg21=reg35-reg21; reg35=reg16*reg23; T reg41=reg17*reg27; T reg42=reg19/2;
    T reg43=0.5*reg2; T reg44=reg11*reg15; T reg45=reg30/reg0; reg10=reg10/reg25; reg23=reg24*reg23;
    reg21=2*reg21; T reg46=0.5*reg20; T reg47=1-var_inter[0]; T reg48=reg7*reg43; reg23=reg23/reg25;
    T reg49=0.5*reg19; reg41=reg41/reg25; reg10=reg45-reg10; reg45=reg20/2; T reg50=reg17/reg0;
    T reg51=reg36/reg0; T reg52=reg44/reg0; T reg53=reg17*reg39; T reg54=reg24*reg27; reg28=reg37-reg28;
    reg33=reg38-reg33; reg37=reg2*reg11; reg38=reg2*reg1; reg27=reg16*reg27; reg35=reg35/reg25;
    T reg55=reg12*reg42; T reg56=reg40/reg0; reg54=reg54/reg25; T reg57=reg43*reg21; T reg58=reg38/reg0;
    T reg59=reg13*reg10; T reg60=reg16/reg0; T reg61=reg24/reg0; reg33=2*reg33; T reg62=reg18*reg21;
    T reg63=reg47-var_inter[1]; T reg64=reg29*reg21; reg23=reg52-reg23; reg52=reg2*reg10; reg50=2*reg50;
    T reg65=reg17*reg55; T reg66=reg7*reg46; T reg67=reg49*reg21; reg27=reg27/reg25; T reg68=reg37/reg0;
    T reg69=reg48/reg0; reg53=reg53/reg25; reg10=reg19*reg10; reg35=reg56-reg35; reg56=reg46*reg21;
    T reg70=reg6*reg1; T reg71=reg15*reg28; reg21=reg26*reg21; T reg72=reg24*reg39; reg45=reg12*reg45;
    T reg73=reg6*reg11; T reg74=reg16*reg39; reg51=reg41+reg51; reg41=reg6*reg28; reg28=reg20*reg28;
    reg69=reg53+reg69; reg53=reg26*reg33; T reg75=2*reg51; T reg76=reg15*reg35; T reg77=reg66/reg0;
    T reg78=reg24*reg55; T reg79=reg19*reg1; reg54=reg58-reg54; reg62=reg59+reg62; reg58=reg70/reg0;
    reg59=reg73/reg0; reg27=reg68-reg27; reg74=reg74/reg25; reg68=reg19*reg11; reg65=reg65/reg25;
    reg72=reg72/reg25; reg17=reg17*reg45; T reg80=reg46*reg33; T reg81=(*f.m).f_vol[1]*var_inter[0]; T reg82=reg50*reg43;
    T reg83=reg6*reg60; reg10=reg56-reg10; reg56=reg19*reg23; T reg84=(*f.m).f_vol[0]*var_inter[0]; T reg85=reg7*reg49;
    T reg86=reg50*reg29; T reg87=reg16*reg55; T reg88=reg2*reg61; reg67=reg28-reg67; reg28=reg20*reg35;
    T reg89=(*f.m).f_vol[1]*reg63; T reg90=reg49*reg33; T reg91=reg50*reg26; T reg92=(*f.m).f_vol[0]*reg63; T reg93=reg60*reg15;
    T reg94=reg19*reg61; T reg95=reg18*reg33; T reg96=reg13*reg23; reg64=reg52-reg64; reg23=reg2*reg23;
    reg52=reg61*reg13; T reg97=reg50*reg18; T reg98=reg29*reg33; T reg99=(*f.m).f_vol[1]*var_inter[1]; T reg100=reg50*reg49;
    T reg101=reg20*reg60; reg41=reg57-reg41; reg33=reg43*reg33; reg35=reg6*reg35; reg57=(*f.m).f_vol[0]*var_inter[1];
    reg21=reg71+reg21; reg71=reg50*reg46; reg21=reg9*reg21; reg16=reg16*reg45; T reg102=reg29*reg75;
    reg35=reg33-reg35; reg33=reg49*reg75; T reg103=reg20*reg27; reg90=reg28-reg90; reg67=reg9*reg67;
    reg28=reg19*reg54; T reg104=reg46*reg75; reg56=reg80-reg56; reg10=reg9*reg10; reg80=reg6*reg27;
    T reg105=reg43*reg75; reg53=reg76+reg53; reg41=reg9*reg41; reg98=reg23-reg98; reg64=reg9*reg64;
    reg92=(*f.m).density*reg92; reg23=reg20*reg1; reg76=reg68/reg0; reg87=reg87/reg25; reg58=reg74-reg58;
    reg74=reg26*reg75; reg27=reg15*reg27; T reg106=reg20*reg11; reg82=reg82-reg83; reg78=reg78/reg25;
    reg81=(*f.m).density*reg81; reg99=(*f.m).density*reg99; T reg107=reg79/reg0; reg91=reg93+reg91; reg71=reg71-reg94;
    reg57=(*f.m).density*reg57; reg77=reg65+reg77; reg69=2*reg69; reg95=reg96+reg95; reg84=(*f.m).density*reg84;
    reg89=(*f.m).density*reg89; reg45=reg24*reg45; reg62=reg9*reg62; reg24=reg13*reg54; reg65=reg18*reg75;
    reg17=reg17/reg25; reg93=reg85/reg0; reg88=reg88-reg86; reg54=reg2*reg54; reg59=reg72-reg59;
    reg97=reg52+reg97; reg101=reg101-reg100; reg95=reg9*reg95; reg52=reg43*reg69; reg76=reg87-reg76;
    reg72=reg6*reg58; reg67=ponderation*reg67; reg89=reg91-reg89; reg80=reg105+reg80; reg16=reg16/reg25;
    reg87=reg23/reg0; reg99=reg101-reg99; reg35=reg9*reg35; reg57=reg71-reg57; reg41=ponderation*reg41;
    reg62=ponderation*reg62; T tmp_0_0=reg62; reg98=reg9*reg98; reg54=reg54+reg102; reg64=ponderation*reg64;
    reg90=reg9*reg90; reg71=reg46*reg69; reg28=reg104+reg28; reg91=reg49*reg69; reg93=reg17+reg93;
    reg17=reg20*reg58; reg56=reg9*reg56; reg0=reg106/reg0; reg25=reg45/reg25; reg21=ponderation*reg21;
    reg84=reg88-reg84; reg10=ponderation*reg10; reg77=2*reg77; reg107=reg78-reg107; reg53=reg9*reg53;
    reg45=reg2*reg59; reg81=reg82-reg81; reg78=reg18*reg69; reg27=reg27-reg74; reg82=reg19*reg59;
    reg103=reg103+reg33; reg59=reg13*reg59; reg92=reg97-reg92; reg88=reg29*reg69; reg69=reg26*reg69;
    reg24=reg24-reg65; reg58=reg15*reg58; reg103=reg9*reg103; reg90=ponderation*reg90; reg96=reg43*reg77;
    reg92=reg9*reg92; reg57=reg9*reg57; reg35=ponderation*reg35; reg81=reg9*reg81; reg97=reg9*reg80;
    reg72=reg52-reg72; reg52=reg9*reg28; reg101=reg6*reg76; reg89=reg9*reg89; reg82=reg71-reg82;
    reg84=reg9*reg84; reg56=ponderation*reg56; reg71=reg19*reg107; T reg108=reg13*reg107; reg62=vectors[0][indices[0]+0]*reg62;
    reg16=reg87-reg16; reg10=vectors[0][indices[0]+0]*reg10; reg21=vectors[0][indices[0]+0]*reg21; reg87=reg15*reg76; T reg109=reg26*reg77;
    reg95=ponderation*reg95; T tmp_0_1=reg95; reg25=reg0-reg25; reg24=reg9*reg24; reg58=reg69+reg58;
    reg64=vectors[0][indices[0]+0]*reg64; reg53=ponderation*reg53; T tmp_1_1=reg53; reg41=vectors[0][indices[0]+0]*reg41; reg78=reg59+reg78;
    reg27=reg9*reg27; reg107=reg2*reg107; reg0=2*reg93; reg59=reg29*reg77; reg67=vectors[0][indices[0]+0]*reg67;
    reg69=reg46*reg77; T reg110=reg18*reg77; reg77=reg49*reg77; reg99=reg9*reg99; reg91=reg17-reg91;
    reg98=ponderation*reg98; reg54=reg9*reg54; reg76=reg20*reg76; reg88=reg45-reg88; reg41=f.premul_KUn_in_sollicitation*reg41;
    reg35=vectors[0][indices[0]+1]*reg35; reg67=f.premul_KUn_in_sollicitation*reg67; reg10=f.premul_KUn_in_sollicitation*reg10; reg56=vectors[0][indices[0]+1]*reg56; reg90=vectors[0][indices[0]+1]*reg90;
    reg17=reg18*reg0; reg53=vectors[0][indices[0]+1]*reg53; reg103=ponderation*reg103; reg91=reg9*reg91; reg77=reg76-reg77;
    reg45=reg20*reg16; reg76=reg49*reg0; reg95=vectors[0][indices[0]+1]*reg95; reg92=ponderation*reg92; reg62=f.premul_KUn_in_sollicitation*reg62;
    reg64=f.premul_KUn_in_sollicitation*reg64; reg21=f.premul_KUn_in_sollicitation*reg21; reg98=vectors[0][indices[0]+1]*reg98; reg89=ponderation*reg89; T reg111=reg19*reg25;
    T reg112=reg46*reg0; reg71=reg69-reg71; reg82=reg9*reg82; reg69=ponderation*reg97; reg27=ponderation*reg27;
    T tmp_1_2=reg27; reg24=ponderation*reg24; T tmp_0_2=reg24; reg99=ponderation*reg99; reg54=ponderation*reg54;
    T tmp_2_2=reg54; T reg113=reg26*reg0; reg88=reg9*reg88; T reg114=reg15*reg16; reg59=reg107-reg59;
    reg58=reg9*reg58; reg107=reg2*reg25; T reg115=reg29*reg0; reg57=ponderation*reg57; reg81=ponderation*reg81;
    reg72=reg9*reg72; reg101=reg96-reg101; reg96=ponderation*reg52; reg84=ponderation*reg84; reg25=reg13*reg25;
    reg78=reg9*reg78; reg87=reg109+reg87; reg109=reg43*reg0; reg16=reg6*reg16; reg108=reg110+reg108;
    reg92=reg62-reg92; reg45=reg45+reg76; reg87=reg9*reg87; reg62=vectors[0][indices[1]+0]*reg96; reg90=f.premul_KUn_in_sollicitation*reg90;
    reg99=reg67-reg99; reg25=reg25-reg17; reg108=reg9*reg108; reg67=vectors[0][indices[1]+0]*reg69; reg95=f.premul_KUn_in_sollicitation*reg95;
    reg89=reg21-reg89; reg24=vectors[0][indices[1]+0]*reg24; reg57=reg10-reg57; reg88=ponderation*reg88; T tmp_2_3=reg88;
    reg56=f.premul_KUn_in_sollicitation*reg56; reg58=ponderation*reg58; T tmp_1_3=reg58; reg72=ponderation*reg72; T tmp_3_3=reg72;
    reg103=vectors[0][indices[1]+0]*reg103; reg78=ponderation*reg78; T tmp_0_3=reg78; reg82=ponderation*reg82; reg16=reg109+reg16;
    reg71=reg9*reg71; reg111=reg112+reg111; reg81=reg41-reg81; reg27=vectors[0][indices[1]+0]*reg27; reg35=f.premul_KUn_in_sollicitation*reg35;
    reg101=reg9*reg101; reg114=reg114-reg113; reg54=vectors[0][indices[1]+0]*reg54; reg107=reg107+reg115; reg53=f.premul_KUn_in_sollicitation*reg53;
    reg59=reg9*reg59; reg91=ponderation*reg91; reg98=f.premul_KUn_in_sollicitation*reg98; reg77=reg9*reg77; reg84=reg64-reg84;
    reg72=vectors[0][indices[1]+1]*reg72; reg103=f.premul_KUn_in_sollicitation*reg103; reg58=vectors[0][indices[1]+1]*reg58; reg67=f.premul_KUn_in_sollicitation*reg67; reg35=reg81+reg35;
    reg91=vectors[0][indices[1]+1]*reg91; reg98=reg84+reg98; reg54=f.premul_KUn_in_sollicitation*reg54; reg88=vectors[0][indices[1]+1]*reg88; reg90=reg99+reg90;
    reg45=reg9*reg45; reg71=ponderation*reg71; T tmp_4_4=reg71; reg10=reg9*reg111; reg21=reg9*reg16;
    reg82=vectors[0][indices[1]+1]*reg82; reg101=ponderation*reg101; T tmp_3_4=reg101; reg62=f.premul_KUn_in_sollicitation*reg62; reg107=reg9*reg107;
    reg59=ponderation*reg59; T tmp_2_4=reg59; reg77=ponderation*reg77; reg114=reg9*reg114; reg87=ponderation*reg87;
    T tmp_1_4=reg87; reg95=reg92+reg95; reg24=f.premul_KUn_in_sollicitation*reg24; reg56=reg57+reg56; reg78=vectors[0][indices[1]+1]*reg78;
    reg25=reg9*reg25; reg108=ponderation*reg108; T tmp_0_4=reg108; reg53=reg89+reg53; reg27=f.premul_KUn_in_sollicitation*reg27;
    reg25=ponderation*reg25; T tmp_0_5=reg25; reg71=vectors[0][indices[2]+0]*reg71; reg101=vectors[0][indices[2]+0]*reg101; reg82=f.premul_KUn_in_sollicitation*reg82;
    reg62=reg56-reg62; reg67=reg35-reg67; reg72=f.premul_KUn_in_sollicitation*reg72; reg35=ponderation*reg10; reg108=vectors[0][indices[2]+0]*reg108;
    reg78=f.premul_KUn_in_sollicitation*reg78; reg24=reg95+reg24; reg77=vectors[0][indices[2]+0]*reg77; reg45=ponderation*reg45; T tmp_5_5=reg45;
    reg114=ponderation*reg114; T tmp_1_5=reg114; reg107=ponderation*reg107; T tmp_2_5=reg107; reg27=reg53+reg27;
    reg58=f.premul_KUn_in_sollicitation*reg58; reg87=vectors[0][indices[2]+0]*reg87; reg41=ponderation*reg21; reg91=f.premul_KUn_in_sollicitation*reg91; reg54=reg98+reg54;
    reg88=f.premul_KUn_in_sollicitation*reg88; reg59=vectors[0][indices[2]+0]*reg59; reg103=reg90+reg103; reg107=vectors[0][indices[2]+1]*reg107; reg82=reg62+reg82;
    reg45=vectors[0][indices[2]+1]*reg45; reg71=f.premul_KUn_in_sollicitation*reg71; reg53=vectors[0][indices[2]+1]*reg35; reg78=reg24+reg78; reg108=f.premul_KUn_in_sollicitation*reg108;
    reg77=f.premul_KUn_in_sollicitation*reg77; reg25=vectors[0][indices[2]+1]*reg25; reg24=vectors[0][indices[2]+1]*reg41; reg91=reg103+reg91; reg101=f.premul_KUn_in_sollicitation*reg101;
    reg72=reg67+reg72; reg58=reg27+reg58; reg87=f.premul_KUn_in_sollicitation*reg87; reg114=vectors[0][indices[2]+1]*reg114; reg88=reg54+reg88;
    reg59=f.premul_KUn_in_sollicitation*reg59; reg45=f.premul_KUn_in_sollicitation*reg45; reg87=reg58+reg87; reg53=f.premul_KUn_in_sollicitation*reg53; reg108=reg78+reg108;
    reg25=f.premul_KUn_in_sollicitation*reg25; reg114=f.premul_KUn_in_sollicitation*reg114; reg59=reg88+reg59; reg107=f.premul_KUn_in_sollicitation*reg107; reg77=reg91+reg77;
    reg101=reg72+reg101; reg24=f.premul_KUn_in_sollicitation*reg24; reg71=reg82+reg71; T vec_2=reg59+reg107; T vec_3=reg101-reg24;
    T vec_1=reg87+reg114; T vec_0=reg108+reg25; T vec_4=reg71-reg53; T tmp_4_5=-reg35; T tmp_3_5=-reg41;
    T vec_5=reg77+reg45;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[0]+1) += tmp_0_1;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[1]+1) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+0,indices[2]+1) += tmp_0_5;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+0) += tmp_1_2;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+0) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[1]+1) += tmp_2_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+0,indices[2]+1) += tmp_2_5;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+0) += tmp_3_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+0,indices[2]+1) += tmp_4_5;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
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
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(1)[0]-elem.pos(0)[0];
    T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(2)[0]-elem.pos(0)[0]; T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=pow(reg1,2); T reg7=reg2*reg5;
    T reg8=reg3*reg4; reg1=reg1*reg6; reg0=reg0/(*f.m).elastic_modulus; T reg9=1.0/(*f.m).elastic_modulus; T reg10=reg0*reg6;
    T reg11=reg9*reg1; reg1=reg0*reg1; reg6=reg9*reg6; reg8=reg7-reg8; reg7=vectors[0][indices[2]+1]-vectors[0][indices[0]+1];
    reg5=reg5/reg8; T reg12=reg0*reg11; T reg13=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg14=reg9*reg6; reg6=reg0*reg6;
    T reg15=reg0*reg10; T reg16=reg0*reg1; reg11=reg9*reg11; T reg17=reg3/reg8; T reg18=reg2/reg8;
    reg4=reg4/reg8; T reg19=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg20=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg21=reg17*reg19; reg6=reg6+reg15;
    T reg22=reg18*reg7; reg14=reg14-reg15; reg10=reg9*reg10; T reg23=reg5*reg20; reg1=reg9*reg1;
    T reg24=reg4*reg13; reg12=reg16+reg12; reg11=reg11-reg16; reg14=reg9*reg14; reg19=reg18*reg19;
    reg20=reg4*reg20; reg13=reg5*reg13; T reg25=reg0*reg12; T reg26=reg9*reg11; reg21=reg23-reg21;
    reg23=reg15+reg10; reg7=reg17*reg7; reg24=reg22-reg24; reg6=reg0*reg6; reg1=reg16+reg1;
    reg7=reg13-reg7; reg13=reg21+reg24; reg20=reg19-reg20; reg25=reg26-reg25; reg23=reg0*reg23;
    reg6=reg14-reg6; reg1=reg0*reg1; reg0=(*f.m).param*(*f.m).me_sens; reg7=reg20+reg7; reg23=reg6-reg23;
    reg1=reg25-reg1; reg0=(*f.m).me+reg0; reg13=reg13/2; reg7=0.5*reg7; reg6=reg17-reg5;
    reg14=reg4-reg18; reg16=reg18/2; reg19=reg5/2; reg13=reg0*reg13; reg11=reg11/reg1;
    reg12=reg12/reg1; reg1=reg23/reg1; reg20=reg11*reg24; reg22=reg6/2; reg16=reg0*reg16;
    reg23=0.5*reg17; reg25=reg14/2; reg26=0.5*reg4; reg19=reg0*reg19; T reg27=reg4/2;
    reg7=reg1*reg7; T reg28=reg17/2; T reg29=reg11*reg21; reg24=reg12*reg24; reg13=1+reg13;
    reg21=reg12*reg21; reg25=reg0*reg25; T reg30=reg0*reg27; T reg31=reg0*reg28; T reg32=reg1*reg26;
    T reg33=reg7*reg19; T reg34=pow(reg13,2); reg22=reg0*reg22; T reg35=0.5*reg18; T reg36=0.5*reg5;
    T reg37=0.5*reg6; T reg38=0.5*reg14; reg20=reg21+reg20; reg24=reg29+reg24; reg21=reg1*reg23;
    reg29=reg7*reg16; T reg39=reg5*reg12; reg33=reg33/reg34; T reg40=reg24*reg19; T reg41=reg5*reg11;
    T reg42=reg21/reg13; T reg43=reg32/reg13; T reg44=reg1*reg36; T reg45=reg18*reg11; T reg46=reg7*reg30;
    T reg47=reg1*reg35; T reg48=reg7*reg31; T reg49=reg20*reg16; T reg50=reg18*reg12; reg16=reg24*reg16;
    reg29=reg29/reg34; T reg51=reg1*reg37; T reg52=reg7*reg22; T reg53=reg7*reg25; reg19=reg20*reg19;
    T reg54=reg1*reg38; T reg55=reg20*reg25; reg48=reg48/reg34; T reg56=reg11*reg14; reg49=reg49/reg34;
    T reg57=reg4*reg12; T reg58=reg20*reg31; T reg59=reg17*reg12; T reg60=reg24*reg30; T reg61=reg20*reg30;
    reg16=reg16/reg34; T reg62=reg50/reg13; T reg63=reg54/reg13; reg46=reg46/reg34; T reg64=reg24*reg31;
    T reg65=reg44/reg13; reg52=reg52/reg34; T reg66=reg20*reg22; T reg67=reg12*reg6; T reg68=reg17*reg11;
    reg43=reg33+reg43; reg33=reg45/reg13; T reg69=reg47/reg13; T reg70=reg39/reg13; T reg71=reg12*reg14;
    reg25=reg24*reg25; reg53=reg53/reg34; T reg72=reg51/reg13; T reg73=reg4*reg11; T reg74=reg41/reg13;
    T reg75=reg11*reg6; reg40=reg40/reg34; reg22=reg24*reg22; reg42=reg29+reg42; reg19=reg19/reg34;
    reg64=reg64/reg34; reg22=reg22/reg34; reg49=reg33-reg49; reg29=reg57/reg13; reg33=reg68/reg13;
    T reg76=reg75/reg13; reg69=reg48+reg69; reg48=2*reg43; reg53=reg72-reg53; reg58=reg58/reg34;
    reg72=reg59/reg13; T reg77=reg73/reg13; T reg78=reg71/reg13; reg25=reg25/reg34; reg40=reg74-reg40;
    reg74=reg56/reg13; reg19=reg70-reg19; reg66=reg66/reg34; reg55=reg55/reg34; reg61=reg61/reg34;
    reg34=reg60/reg34; reg60=2*reg42; reg52=reg63-reg52; reg16=reg62-reg16; reg62=reg67/reg13;
    reg65=reg46+reg65; reg52=2*reg52; reg46=reg17*reg40; reg77=reg61-reg77; reg66=reg62-reg66;
    reg61=reg17*reg16; reg62=reg35*reg48; reg63=reg35*reg60; reg55=reg74-reg55; reg72=reg58-reg72;
    reg22=reg76-reg22; reg58=reg4*reg19; reg70=reg36*reg48; reg74=reg36*reg60; reg29=reg34-reg29;
    reg34=reg4*reg49; reg65=2*reg65; reg25=reg78-reg25; reg33=reg64-reg33; reg69=2*reg69;
    reg53=2*reg53; reg64=reg37*reg69; reg76=reg5*reg33; reg58=reg70+reg58; reg78=reg26*reg69;
    T reg79=reg36*reg65; T reg80=reg4*reg77; T reg81=reg4*reg66; T reg82=reg5*reg16; T reg83=reg26*reg60;
    T reg84=reg4*reg55; T reg85=reg14*reg77; T reg86=reg36*reg53; T reg87=reg36*reg52; T reg88=reg5*reg25;
    T reg89=reg35*reg52; T reg90=reg14*reg49; T reg91=reg35*reg53; T reg92=reg35*reg69; T reg93=reg5*reg22;
    T reg94=reg26*reg52; reg34=reg74+reg34; T reg95=reg17*reg22; T reg96=reg26*reg65; T reg97=reg17*reg25;
    T reg98=reg26*reg53; T reg99=reg4*reg72; T reg100=reg36*reg69; T reg101=reg18*reg66; T reg102=reg37*reg60;
    T reg103=reg5*reg29; T reg104=reg14*reg72; T reg105=reg23*reg65; T reg106=reg18*reg55; T reg107=reg6*reg33;
    T reg108=reg23*reg53; T reg109=reg18*reg19; T reg110=reg38*reg65; T reg111=reg6*reg29; T reg112=reg23*reg48;
    reg77=reg18*reg77; T reg113=reg38*reg48; T reg114=reg6*reg40; T reg115=reg37*reg65; reg72=reg18*reg72;
    T reg116=reg38*reg53; reg25=reg6*reg25; T reg117=reg23*reg69; reg49=reg18*reg49; T reg118=reg38*reg52;
    reg22=reg6*reg22; reg40=reg5*reg40; T reg119=reg23*reg60; reg69=reg38*reg69; reg46=reg62+reg46;
    reg65=reg35*reg65; reg29=reg17*reg29; reg19=reg14*reg19; reg53=reg37*reg53; T reg120=reg37*reg48;
    reg55=reg14*reg55; T reg121=reg37*reg52; reg33=reg17*reg33; reg66=reg14*reg66; T reg122=reg26*reg48;
    reg61=reg63+reg61; reg52=reg23*reg52; T reg123=reg38*reg60; reg16=reg6*reg16; reg105=reg77-reg105;
    reg77=reg8*reg46; reg97=reg91-reg97; reg84=reg86-reg84; reg81=reg87-reg81; reg49=reg49+reg119;
    reg117=reg72-reg117; reg107=reg69+reg107; reg69=reg8*reg58; reg29=reg65-reg29; reg52=reg101-reg52;
    reg80=reg79-reg80; reg33=reg92-reg33; reg95=reg89-reg95; reg99=reg100-reg99; reg109=reg109+reg112;
    reg65=reg8*reg61; reg108=reg106-reg108; reg72=reg8*reg34; reg110=reg111+reg110; reg104=reg64+reg104;
    reg114=reg114-reg113; reg90=reg90-reg102; reg85=reg115+reg85; reg94=reg93-reg94; reg19=reg19-reg120;
    reg116=reg25+reg116; reg98=reg88-reg98; reg53=reg55+reg53; reg96=reg103-reg96; reg118=reg22+reg118;
    reg121=reg66+reg121; reg40=reg40+reg122; reg16=reg16-reg123; reg78=reg76-reg78; reg82=reg82+reg83;
    reg22=ponderation*reg77; reg52=reg8*reg52; reg107=reg8*reg107; reg97=reg8*reg97; reg85=reg8*reg85;
    reg109=reg8*reg109; reg19=reg8*reg19; reg25=ponderation*reg65; reg16=reg8*reg16; reg121=reg8*reg121;
    reg114=reg8*reg114; reg110=reg8*reg110; reg53=reg8*reg53; reg29=reg8*reg29; reg116=reg8*reg116;
    reg33=reg8*reg33; reg108=reg8*reg108; reg118=reg8*reg118; reg81=reg8*reg81; reg82=reg8*reg82;
    reg49=reg8*reg49; reg84=reg8*reg84; reg78=reg8*reg78; reg96=reg8*reg96; reg55=ponderation*reg69;
    reg40=reg8*reg40; reg80=reg8*reg80; reg117=reg8*reg117; reg98=reg8*reg98; reg64=ponderation*reg72;
    reg95=reg8*reg95; reg104=reg8*reg104; reg90=reg8*reg90; reg105=reg8*reg105; reg94=reg8*reg94;
    reg99=reg8*reg99; reg108=ponderation*reg108; T tmp_5_1=reg108; reg105=ponderation*reg105; T tmp_5_3=reg105;
    reg117=ponderation*reg117; T tmp_5_4=reg117; reg114=ponderation*reg114; T tmp_0_2=reg114; reg118=ponderation*reg118;
    T tmp_0_0=reg118; reg109=ponderation*reg109; T tmp_5_2=reg109; reg49=ponderation*reg49; T tmp_5_5=reg49;
    reg110=ponderation*reg110; T tmp_0_3=reg110; reg116=ponderation*reg116; T tmp_0_1=reg116; reg82=ponderation*reg82;
    T tmp_2_5=reg82; reg104=ponderation*reg104; T tmp_1_4=reg104; reg81=ponderation*reg81; T tmp_3_0=reg81;
    reg78=ponderation*reg78; T tmp_2_4=reg78; reg84=ponderation*reg84; T tmp_3_1=reg84; reg96=ponderation*reg96;
    T tmp_2_3=reg96; T tmp_3_2=-reg55; reg40=ponderation*reg40; T tmp_2_2=reg40; reg80=ponderation*reg80;
    T tmp_3_3=reg80; reg98=ponderation*reg98; T tmp_2_1=reg98; reg99=ponderation*reg99; T tmp_3_4=reg99;
    reg94=ponderation*reg94; T tmp_2_0=reg94; reg90=ponderation*reg90; T tmp_1_5=reg90; T tmp_3_5=-reg64;
    reg52=ponderation*reg52; T tmp_5_0=reg52; reg95=ponderation*reg95; T tmp_4_0=reg95; reg85=ponderation*reg85;
    T tmp_1_3=reg85; reg97=ponderation*reg97; T tmp_4_1=reg97; reg19=ponderation*reg19; T tmp_1_2=reg19;
    T tmp_4_2=-reg22; reg53=ponderation*reg53; T tmp_1_1=reg53; reg29=ponderation*reg29; T tmp_4_3=reg29;
    reg121=ponderation*reg121; T tmp_1_0=reg121; reg33=ponderation*reg33; T tmp_4_4=reg33; reg16=ponderation*reg16;
    T tmp_0_5=reg16; T tmp_4_5=-reg25; reg107=ponderation*reg107; T tmp_0_4=reg107;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[0]+1) += tmp_0_1;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[1]+1) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+0,indices[2]+1) += tmp_0_5;
    matrix(indices[0]+1,indices[0]+0) += tmp_1_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+0) += tmp_1_2;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+0) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[0]+0) += tmp_2_0;
    matrix(indices[1]+0,indices[0]+1) += tmp_2_1;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[1]+1) += tmp_2_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+0,indices[2]+1) += tmp_2_5;
    matrix(indices[1]+1,indices[0]+0) += tmp_3_0;
    matrix(indices[1]+1,indices[0]+1) += tmp_3_1;
    matrix(indices[1]+1,indices[1]+0) += tmp_3_2;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+0) += tmp_3_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[0]+0) += tmp_4_0;
    matrix(indices[2]+0,indices[0]+1) += tmp_4_1;
    matrix(indices[2]+0,indices[1]+0) += tmp_4_2;
    matrix(indices[2]+0,indices[1]+1) += tmp_4_3;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+0,indices[2]+1) += tmp_4_5;
    matrix(indices[2]+1,indices[0]+0) += tmp_5_0;
    matrix(indices[2]+1,indices[0]+1) += tmp_5_1;
    matrix(indices[2]+1,indices[1]+0) += tmp_5_2;
    matrix(indices[2]+1,indices[1]+1) += tmp_5_3;
    matrix(indices[2]+1,indices[2]+0) += tmp_5_4;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(1)[0]-elem.pos(0)[0];
    T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(2)[0]-elem.pos(0)[0]; T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=pow(reg1,2); T reg7=reg2*reg5;
    T reg8=reg3*reg4; reg1=reg1*reg6; reg0=reg0/(*f.m).elastic_modulus; T reg9=1.0/(*f.m).elastic_modulus; T reg10=reg0*reg6;
    T reg11=reg9*reg1; reg1=reg0*reg1; reg6=reg9*reg6; reg8=reg7-reg8; reg7=vectors[0][indices[2]+1]-vectors[0][indices[0]+1];
    reg5=reg5/reg8; T reg12=reg0*reg11; T reg13=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg14=reg9*reg6; reg6=reg0*reg6;
    T reg15=reg0*reg10; T reg16=reg0*reg1; reg11=reg9*reg11; T reg17=reg3/reg8; T reg18=reg2/reg8;
    reg4=reg4/reg8; T reg19=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg20=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg21=reg17*reg19; T reg22=reg18*reg7;
    reg6=reg6+reg15; reg14=reg14-reg15; reg10=reg9*reg10; T reg23=reg5*reg20; reg1=reg9*reg1;
    T reg24=reg4*reg13; reg12=reg16+reg12; reg11=reg11-reg16; reg14=reg9*reg14; reg7=reg17*reg7;
    reg13=reg5*reg13; reg20=reg4*reg20; T reg25=reg0*reg12; reg19=reg18*reg19; T reg26=reg9*reg11;
    reg21=reg23-reg21; reg23=reg15+reg10; reg24=reg22-reg24; reg6=reg0*reg6; reg1=reg16+reg1;
    reg16=reg21+reg24; reg20=reg19-reg20; reg7=reg13-reg7; reg1=reg0*reg1; reg13=(*f.m).param*(*f.m).me_sens;
    reg23=reg0*reg23; reg6=reg14-reg6; reg25=reg26-reg25; reg16=reg16/2; reg13=(*f.m).me+reg13;
    reg7=reg20+reg7; reg1=reg25-reg1; reg23=reg6-reg23; reg0=reg17-reg5; reg6=reg4-reg18;
    reg16=reg13*reg16; reg7=0.5*reg7; reg12=reg12/reg1; reg11=reg11/reg1; reg1=reg23/reg1;
    reg14=reg18/2; reg14=reg13*reg14; reg7=reg1*reg7; reg19=reg0/2; reg20=0.5*reg17;
    reg22=reg6/2; reg23=reg11*reg24; reg25=reg12*reg21; reg16=1+reg16; reg24=reg12*reg24;
    reg21=reg11*reg21; reg26=reg5/2; T reg27=reg17/2; T reg28=reg4/2; reg26=reg13*reg26;
    T reg29=reg13*reg27; T reg30=reg1*reg20; T reg31=pow(reg16,2); reg19=reg13*reg19; T reg32=reg13*reg28;
    T reg33=reg7*reg14; T reg34=0.5*reg18; T reg35=0.5*reg5; T reg36=0.5*reg4; T reg37=0.5*reg0;
    T reg38=0.5*reg6; reg22=reg13*reg22; reg23=reg25+reg23; reg24=reg21+reg24; reg21=reg1*reg36;
    reg25=reg7*reg22; T reg39=reg1*reg37; T reg40=reg18*reg11; T reg41=reg1*reg35; T reg42=reg7*reg32;
    T reg43=reg1*reg34; T reg44=reg7*reg29; T reg45=reg18*reg12; T reg46=reg24*reg14; reg33=reg33/reg31;
    T reg47=reg30/reg16; T reg48=reg7*reg26; reg14=reg23*reg14; T reg49=reg7*reg19; T reg50=reg1*reg38;
    T reg51=reg4*reg12; reg48=reg48/reg31; T reg52=reg21/reg16; T reg53=reg24*reg29; reg49=reg49/reg31;
    T reg54=reg50/reg16; T reg55=reg23*reg22; T reg56=reg11*reg6; T reg57=reg4*reg11; T reg58=reg11*reg0;
    T reg59=reg17*reg11; reg47=reg33+reg47; reg33=reg24*reg32; T reg60=reg24*reg19; T reg61=reg17*reg12;
    T reg62=reg23*reg32; T reg63=reg41/reg16; T reg64=reg23*reg29; reg42=reg42/reg31; reg14=reg14/reg31;
    reg25=reg25/reg31; T reg65=reg39/reg16; T reg66=reg43/reg16; T reg67=reg23*reg26; reg46=reg46/reg31;
    T reg68=reg40/reg16; reg44=reg44/reg31; T reg69=reg5*reg11; reg22=reg24*reg22; T reg70=reg12*reg6;
    reg26=reg24*reg26; T reg71=reg45/reg16; T reg72=reg5*reg12; T reg73=reg61/reg16; reg60=reg60/reg31;
    reg66=reg44+reg66; reg53=reg53/reg31; reg63=reg42+reg63; reg62=reg62/reg31; reg46=reg71-reg46;
    reg42=reg59/reg16; reg44=reg57/reg16; reg71=reg70/reg16; reg22=reg22/reg31; reg25=reg65-reg25;
    reg14=reg68-reg14; reg67=reg67/reg31; reg26=reg26/reg31; reg65=reg69/reg16; reg68=reg72/reg16;
    reg49=reg54-reg49; reg54=reg58/reg16; T reg74=reg56/reg16; reg52=reg48+reg52; reg55=reg55/reg31;
    reg48=2*reg47; reg33=reg33/reg31; T reg75=reg51/reg16; reg64=reg64/reg31; T reg76=reg4*reg14;
    reg60=reg54-reg60; reg55=reg74-reg55; reg67=reg68-reg67; reg22=reg71-reg22; reg26=reg65-reg26;
    reg54=reg34*reg48; reg65=reg17*reg46; reg73=reg64-reg73; reg64=2*reg52; reg49=2*reg49;
    reg75=reg33-reg75; reg63=2*reg63; reg25=2*reg25; reg44=reg62-reg44; reg42=reg53-reg42;
    reg66=2*reg66; reg33=reg35*reg48; reg53=reg37*reg48; reg62=reg36*reg66; reg68=reg38*reg66;
    reg71=reg34*reg66; reg74=reg5*reg75; T reg77=reg6*reg14; T reg78=reg6*reg67; T reg79=reg37*reg64;
    T reg80=reg5*reg46; T reg81=reg37*reg63; T reg82=reg6*reg73; T reg83=reg37*reg66; T reg84=reg5*reg42;
    T reg85=reg36*reg63; T reg86=reg0*reg60; T reg87=reg6*reg44; T reg88=reg36*reg48; T reg89=reg0*reg22;
    T reg90=reg38*reg25; T reg91=reg20*reg48; reg14=reg18*reg14; T reg92=reg0*reg26; reg65=reg54+reg65;
    T reg93=reg38*reg64; T reg94=reg17*reg42; T reg95=reg38*reg49; T reg96=reg0*reg75; T reg97=reg38*reg63;
    reg76=reg33+reg76; reg42=reg0*reg42; T reg98=reg4*reg73; T reg99=reg37*reg25; reg46=reg0*reg46;
    T reg100=reg6*reg55; T reg101=reg5*reg26; T reg102=reg35*reg66; T reg103=reg38*reg48; T reg104=reg36*reg64;
    T reg105=reg35*reg63; T reg106=reg4*reg44; reg80=reg80+reg88; reg14=reg14+reg91; reg77=reg77-reg53;
    T reg107=reg8*reg65; reg62=reg84-reg62; reg94=reg71-reg94; reg106=reg105-reg106; reg71=reg8*reg76;
    reg85=reg74-reg85; reg99=reg100+reg99; reg98=reg102-reg98; reg95=reg86+reg95; reg97=reg96+reg97;
    reg92=reg92-reg93; reg90=reg89+reg90; reg82=reg83+reg82; reg42=reg68+reg42; reg78=reg78-reg79;
    reg46=reg46-reg103; reg87=reg81+reg87; reg101=reg101+reg104; reg98=reg8*reg98; reg95=reg8*reg95;
    reg46=reg8*reg46; reg106=reg8*reg106; reg92=reg8*reg92; reg42=reg8*reg42; reg99=reg8*reg99;
    reg94=reg8*reg94; reg97=reg8*reg97; reg68=ponderation*reg71; reg80=reg8*reg80; reg77=reg8*reg77;
    reg14=reg8*reg14; reg82=reg8*reg82; reg101=reg8*reg101; reg90=reg8*reg90; reg87=reg8*reg87;
    reg85=reg8*reg85; reg78=reg8*reg78; reg62=reg8*reg62; reg74=ponderation*reg107; reg90=ponderation*reg90;
    T tmp_0_1=reg90; reg94=ponderation*reg94; T tmp_4_4=reg94; T tmp_4_5=-reg74; reg92=ponderation*reg92;
    T tmp_0_2=reg92; reg95=ponderation*reg95; T tmp_0_0=reg95; reg14=ponderation*reg14; T tmp_5_5=reg14;
    T tmp_3_5=-reg68; reg97=ponderation*reg97; T tmp_0_3=reg97; reg98=ponderation*reg98; T tmp_3_4=reg98;
    reg42=ponderation*reg42; T tmp_0_4=reg42; reg106=ponderation*reg106; T tmp_3_3=reg106; reg46=ponderation*reg46;
    T tmp_0_5=reg46; reg80=ponderation*reg80; T tmp_2_5=reg80; reg99=ponderation*reg99; T tmp_1_1=reg99;
    reg62=ponderation*reg62; T tmp_2_4=reg62; reg78=ponderation*reg78; T tmp_1_2=reg78; reg85=ponderation*reg85;
    T tmp_2_3=reg85; reg87=ponderation*reg87; T tmp_1_3=reg87; reg101=ponderation*reg101; T tmp_2_2=reg101;
    reg77=ponderation*reg77; T tmp_1_5=reg77; reg82=ponderation*reg82; T tmp_1_4=reg82;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+0,indices[0]+1) += tmp_0_1;
    matrix(indices[0]+0,indices[1]+0) += tmp_0_2;
    matrix(indices[0]+0,indices[1]+1) += tmp_0_3;
    matrix(indices[0]+0,indices[2]+0) += tmp_0_4;
    matrix(indices[0]+0,indices[2]+1) += tmp_0_5;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    matrix(indices[0]+1,indices[1]+0) += tmp_1_2;
    matrix(indices[0]+1,indices[1]+1) += tmp_1_3;
    matrix(indices[0]+1,indices[2]+0) += tmp_1_4;
    matrix(indices[0]+1,indices[2]+1) += tmp_1_5;
    matrix(indices[1]+0,indices[1]+0) += tmp_2_2;
    matrix(indices[1]+0,indices[1]+1) += tmp_2_3;
    matrix(indices[1]+0,indices[2]+0) += tmp_2_4;
    matrix(indices[1]+0,indices[2]+1) += tmp_2_5;
    matrix(indices[1]+1,indices[1]+1) += tmp_3_3;
    matrix(indices[1]+1,indices[2]+0) += tmp_3_4;
    matrix(indices[1]+1,indices[2]+1) += tmp_3_5;
    matrix(indices[2]+0,indices[2]+0) += tmp_4_4;
    matrix(indices[2]+0,indices[2]+1) += tmp_4_5;
    matrix(indices[2]+1,indices[2]+1) += tmp_5_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(2)[1]-elem.pos(0)[1];
    T reg3=pow(reg1,2); T reg4=elem.pos(1)[0]-elem.pos(0)[0]; T reg5=elem.pos(1)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[0]-elem.pos(0)[0]; T reg7=reg4*reg2;
    reg0=reg0/(*f.m).elastic_modulus; T reg8=1.0/(*f.m).elastic_modulus; T reg9=reg5*reg6; reg1=reg1*reg3; reg9=reg7-reg9;
    reg7=reg0*reg1; reg1=reg8*reg1; T reg10=reg8*reg3; reg3=reg0*reg3; reg6=reg6/reg9;
    T reg11=reg0*reg1; T reg12=reg0*reg7; T reg13=reg8*reg10; T reg14=reg0*reg3; reg1=reg8*reg1;
    reg10=reg0*reg10; T reg15=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; T reg16=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg17=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg18=vectors[0][indices[2]+0]-vectors[0][indices[0]+0];
    T reg19=reg5/reg9; T reg20=reg4/reg9; reg2=reg2/reg9; reg10=reg10+reg14; reg7=reg8*reg7;
    reg11=reg12+reg11; reg3=reg8*reg3; reg13=reg13-reg14; reg1=reg1-reg12; T reg21=reg2*reg16;
    T reg22=reg19*reg18; T reg23=reg20*reg17; T reg24=reg6*reg15; T reg25=reg14+reg3; reg22=reg21-reg22;
    reg24=reg23-reg24; reg17=reg19*reg17; reg10=reg0*reg10; reg15=reg2*reg15; reg18=reg20*reg18;
    reg16=reg6*reg16; reg7=reg12+reg7; reg13=reg8*reg13; reg12=reg8*reg1; reg21=reg0*reg11;
    reg10=reg13-reg10; reg25=reg0*reg25; reg7=reg0*reg7; reg16=reg18-reg16; reg0=reg22+reg24;
    reg21=reg12-reg21; reg17=reg15-reg17; reg12=(*f.m).param*(*f.m).me_sens; reg13=reg19-reg2; reg12=(*f.m).me+reg12;
    reg17=reg16+reg17; reg7=reg21-reg7; reg0=reg0/2; reg25=reg10-reg25; reg0=reg12*reg0;
    reg10=reg13/2; reg15=reg6-reg20; reg1=reg1/reg7; reg17=0.5*reg17; reg11=reg11/reg7;
    reg7=reg25/reg7; reg16=reg1*reg24; reg18=0.5*reg15; reg21=reg11*reg22; reg17=reg7*reg17;
    reg0=1+reg0; reg24=reg11*reg24; reg10=reg12*reg10; reg22=reg1*reg22; reg23=reg15/2;
    reg25=pow(reg0,2); T reg26=0.5*reg13; reg16=reg21+reg16; reg21=reg17*reg10; reg24=reg22+reg24;
    reg22=reg7*reg18; reg23=reg12*reg23; T reg27=reg2/2; T reg28=reg11*reg13; T reg29=0.5*reg6;
    T reg30=reg1*reg13; T reg31=reg16*reg10; T reg32=reg6/2; reg27=reg12*reg27; T reg33=reg17*reg23;
    T reg34=reg7*reg26; reg10=reg24*reg10; T reg35=reg22/reg0; reg21=reg21/reg25; reg31=reg31/reg25;
    T reg36=reg7*reg29; T reg37=reg28/reg0; reg33=reg33/reg25; T reg38=reg34/reg0; T reg39=reg12*reg32;
    T reg40=reg1*reg15; reg21=reg35-reg21; reg35=reg16*reg23; T reg41=reg17*reg27; T reg42=reg19/2;
    T reg43=0.5*reg2; T reg44=reg11*reg15; T reg45=reg30/reg0; reg10=reg10/reg25; reg23=reg24*reg23;
    reg21=2*reg21; T reg46=0.5*reg20; T reg47=1-var_inter[0]; T reg48=reg7*reg43; reg23=reg23/reg25;
    T reg49=0.5*reg19; reg41=reg41/reg25; reg10=reg45-reg10; reg45=reg20/2; T reg50=reg17/reg0;
    T reg51=reg36/reg0; T reg52=reg44/reg0; T reg53=reg17*reg39; T reg54=reg24*reg27; reg31=reg37-reg31;
    reg33=reg38-reg33; reg37=reg2*reg11; reg38=reg2*reg1; reg27=reg16*reg27; reg35=reg35/reg25;
    T reg55=reg12*reg42; T reg56=reg40/reg0; reg54=reg54/reg25; T reg57=reg43*reg21; T reg58=reg38/reg0;
    T reg59=reg13*reg10; T reg60=reg16/reg0; T reg61=reg24/reg0; reg33=2*reg33; T reg62=reg18*reg21;
    T reg63=reg47-var_inter[1]; T reg64=reg29*reg21; reg23=reg52-reg23; reg52=reg2*reg10; reg50=2*reg50;
    T reg65=reg17*reg55; T reg66=reg7*reg46; T reg67=reg49*reg21; reg27=reg27/reg25; T reg68=reg37/reg0;
    T reg69=reg48/reg0; reg53=reg53/reg25; reg10=reg19*reg10; reg35=reg56-reg35; reg56=reg46*reg21;
    T reg70=reg6*reg1; T reg71=reg15*reg31; reg21=reg26*reg21; T reg72=reg24*reg39; reg45=reg12*reg45;
    T reg73=reg6*reg11; T reg74=reg16*reg39; reg51=reg41+reg51; reg41=reg6*reg31; reg31=reg20*reg31;
    reg69=reg53+reg69; reg53=reg26*reg33; T reg75=2*reg51; T reg76=reg15*reg35; T reg77=reg66/reg0;
    T reg78=reg24*reg55; T reg79=reg19*reg1; reg54=reg58-reg54; reg62=reg59+reg62; reg58=reg70/reg0;
    reg59=reg73/reg0; reg27=reg68-reg27; reg74=reg74/reg25; reg68=reg19*reg11; reg65=reg65/reg25;
    reg72=reg72/reg25; reg17=reg17*reg45; T reg80=reg46*reg33; T reg81=(*f.m).f_vol[1]*var_inter[0]; T reg82=reg50*reg43;
    T reg83=reg6*reg60; reg10=reg56-reg10; reg56=reg19*reg23; T reg84=(*f.m).f_vol[0]*var_inter[0]; T reg85=reg7*reg49;
    T reg86=reg50*reg29; T reg87=reg16*reg55; T reg88=reg2*reg61; reg67=reg31-reg67; reg31=reg20*reg35;
    T reg89=(*f.m).f_vol[1]*reg63; T reg90=reg49*reg33; T reg91=reg50*reg26; T reg92=(*f.m).f_vol[0]*reg63; T reg93=reg60*reg15;
    T reg94=reg19*reg61; T reg95=reg18*reg33; T reg96=reg13*reg23; reg64=reg52-reg64; reg23=reg2*reg23;
    reg52=reg61*reg13; T reg97=reg50*reg18; T reg98=reg29*reg33; T reg99=(*f.m).f_vol[1]*var_inter[1]; T reg100=reg50*reg49;
    T reg101=reg20*reg60; reg41=reg57-reg41; reg33=reg43*reg33; reg35=reg6*reg35; reg57=(*f.m).f_vol[0]*var_inter[1];
    reg21=reg71+reg21; reg71=reg50*reg46; reg21=reg9*reg21; reg16=reg16*reg45; T reg102=reg29*reg75;
    reg35=reg33-reg35; reg33=reg49*reg75; T reg103=reg20*reg27; reg90=reg31-reg90; reg67=reg9*reg67;
    reg31=reg19*reg54; T reg104=reg46*reg75; reg56=reg80-reg56; reg10=reg9*reg10; reg80=reg6*reg27;
    T reg105=reg43*reg75; reg53=reg76+reg53; reg41=reg9*reg41; reg98=reg23-reg98; reg64=reg9*reg64;
    reg92=(*f.m).density*reg92; reg23=reg20*reg1; reg76=reg68/reg0; reg87=reg87/reg25; reg58=reg74-reg58;
    reg74=reg26*reg75; reg27=reg15*reg27; reg81=(*f.m).density*reg81; reg57=(*f.m).density*reg57; reg69=2*reg69;
    reg71=reg71-reg94; T reg106=reg18*reg75; reg59=reg72-reg59; reg78=reg78/reg25; reg91=reg93+reg91;
    reg72=reg79/reg0; reg93=reg13*reg54; reg89=(*f.m).density*reg89; reg77=reg65+reg77; reg54=reg2*reg54;
    reg84=(*f.m).density*reg84; reg95=reg96+reg95; reg97=reg52+reg97; reg88=reg88-reg86; reg99=(*f.m).density*reg99;
    reg52=reg85/reg0; reg17=reg17/reg25; reg82=reg82-reg83; reg101=reg101-reg100; reg62=reg9*reg62;
    reg45=reg24*reg45; reg24=reg20*reg11; reg65=reg29*reg69; reg96=reg20*reg58; T reg107=reg49*reg69;
    reg35=reg9*reg35; reg103=reg103+reg33; T reg108=reg2*reg59; reg99=reg101-reg99; reg98=reg9*reg98;
    reg54=reg54+reg102; reg62=ponderation*reg62; reg101=reg23/reg0; reg16=reg16/reg25; reg67=ponderation*reg67;
    T reg109=reg46*reg69; reg31=reg104+reg31; reg56=reg9*reg56; reg84=reg88-reg84; reg10=ponderation*reg10;
    reg88=reg19*reg59; reg81=reg82-reg81; reg89=reg91-reg89; reg92=reg97-reg92; reg82=reg6*reg58;
    reg91=reg43*reg69; reg80=reg105+reg80; reg64=ponderation*reg64; reg57=reg71-reg57; reg41=ponderation*reg41;
    reg90=reg9*reg90; reg76=reg87-reg76; reg27=reg27-reg74; reg71=reg18*reg69; reg58=reg15*reg58;
    reg25=reg45/reg25; reg0=reg24/reg0; reg52=reg17+reg52; reg95=reg9*reg95; reg59=reg13*reg59;
    reg53=reg9*reg53; reg93=reg93-reg106; reg72=reg78-reg72; reg77=2*reg77; reg69=reg26*reg69;
    reg21=ponderation*reg21; reg90=ponderation*reg90; reg93=reg9*reg93; reg64=vectors[0][indices[0]+0]*reg64; reg92=reg9*reg92;
    reg58=reg69+reg58; reg57=reg9*reg57; reg27=reg9*reg27; reg10=vectors[0][indices[0]+0]*reg10; reg71=reg59+reg71;
    reg84=reg9*reg84; reg35=ponderation*reg35; reg81=reg9*reg81; reg41=vectors[0][indices[0]+0]*reg41; reg17=reg9*reg80;
    reg53=ponderation*reg53; reg45=reg13*reg72; reg82=reg91-reg82; reg59=reg43*reg77; reg69=reg6*reg76;
    reg89=reg9*reg89; reg103=reg9*reg103; reg21=vectors[0][indices[0]+0]*reg21; reg16=reg101-reg16; reg62=vectors[0][indices[0]+0]*reg62;
    reg78=reg9*reg31; reg67=vectors[0][indices[0]+0]*reg67; reg88=reg109-reg88; reg87=reg19*reg72; reg91=reg46*reg77;
    reg97=reg15*reg76; reg101=reg18*reg77; reg109=reg26*reg77; T reg110=reg49*reg77; reg99=reg9*reg99;
    reg95=ponderation*reg95; reg98=ponderation*reg98; reg56=ponderation*reg56; reg54=reg9*reg54; reg76=reg20*reg76;
    T reg111=2*reg52; reg65=reg108-reg65; reg107=reg96-reg107; reg72=reg2*reg72; reg77=reg29*reg77;
    reg25=reg0-reg25; reg56=vectors[0][indices[0]+1]*reg56; reg67=f.premul_KUn_in_sollicitation*reg67; reg88=reg9*reg88; reg10=f.premul_KUn_in_sollicitation*reg10;
    reg90=vectors[0][indices[0]+1]*reg90; reg62=f.premul_KUn_in_sollicitation*reg62; reg107=reg9*reg107; reg53=vectors[0][indices[0]+1]*reg53; reg95=vectors[0][indices[0]+1]*reg95;
    reg0=reg49*reg111; reg96=reg20*reg16; reg110=reg76-reg110; reg76=reg18*reg111; reg21=f.premul_KUn_in_sollicitation*reg21;
    reg98=vectors[0][indices[0]+1]*reg98; reg87=reg91-reg87; reg103=ponderation*reg103; reg64=f.premul_KUn_in_sollicitation*reg64; reg35=vectors[0][indices[0]+1]*reg35;
    reg92=ponderation*reg92; reg41=f.premul_KUn_in_sollicitation*reg41; reg89=ponderation*reg89; reg91=reg19*reg25; reg108=reg46*reg111;
    reg93=ponderation*reg93; reg77=reg72-reg77; reg71=reg9*reg71; reg72=reg2*reg25; T reg112=reg29*reg111;
    reg65=reg9*reg65; T reg113=ponderation*reg78; reg57=ponderation*reg57; reg81=ponderation*reg81; T reg114=ponderation*reg17;
    reg82=reg9*reg82; reg54=ponderation*reg54; reg69=reg59-reg69; reg99=ponderation*reg99; reg45=reg101+reg45;
    reg59=reg15*reg16; reg101=reg43*reg111; reg16=reg6*reg16; reg25=reg13*reg25; reg58=reg9*reg58;
    reg27=ponderation*reg27; T reg115=reg26*reg111; reg97=reg109+reg97; reg84=ponderation*reg84; reg81=reg41-reg81;
    reg92=reg62-reg92; reg95=f.premul_KUn_in_sollicitation*reg95; reg107=ponderation*reg107; reg71=ponderation*reg71; reg93=vectors[0][indices[1]+0]*reg93;
    reg27=vectors[0][indices[1]+0]*reg27; reg25=reg25-reg76; reg99=reg67-reg99; reg53=f.premul_KUn_in_sollicitation*reg53; reg54=vectors[0][indices[1]+0]*reg54;
    reg89=reg21-reg89; reg98=f.premul_KUn_in_sollicitation*reg98; reg84=reg64-reg84; reg97=reg9*reg97; reg58=ponderation*reg58;
    reg103=vectors[0][indices[1]+0]*reg103; reg56=f.premul_KUn_in_sollicitation*reg56; reg57=reg10-reg57; reg88=ponderation*reg88; reg16=reg101+reg16;
    reg87=reg9*reg87; reg91=reg108+reg91; reg45=reg9*reg45; reg10=vectors[0][indices[1]+0]*reg113; reg69=reg9*reg69;
    reg82=ponderation*reg82; reg35=f.premul_KUn_in_sollicitation*reg35; reg72=reg72+reg112; reg77=reg9*reg77; reg65=ponderation*reg65;
    reg90=f.premul_KUn_in_sollicitation*reg90; reg110=reg9*reg110; reg21=vectors[0][indices[1]+0]*reg114; reg59=reg59-reg115; reg96=reg96+reg0;
    reg90=reg99+reg90; reg56=reg57+reg56; reg103=f.premul_KUn_in_sollicitation*reg103; reg98=reg84+reg98; reg54=f.premul_KUn_in_sollicitation*reg54;
    reg65=vectors[0][indices[1]+1]*reg65; reg25=reg9*reg25; reg35=reg81+reg35; reg21=f.premul_KUn_in_sollicitation*reg21; reg82=vectors[0][indices[1]+1]*reg82;
    reg88=vectors[0][indices[1]+1]*reg88; reg10=f.premul_KUn_in_sollicitation*reg10; reg45=ponderation*reg45; reg72=reg9*reg72; reg96=reg9*reg96;
    reg97=ponderation*reg97; reg95=reg92+reg95; reg93=f.premul_KUn_in_sollicitation*reg93; reg59=reg9*reg59; reg110=ponderation*reg110;
    reg71=vectors[0][indices[1]+1]*reg71; reg77=ponderation*reg77; reg69=ponderation*reg69; reg41=reg9*reg16; reg58=vectors[0][indices[1]+1]*reg58;
    reg87=ponderation*reg87; reg27=f.premul_KUn_in_sollicitation*reg27; reg53=reg89+reg53; reg57=reg9*reg91; reg107=vectors[0][indices[1]+1]*reg107;
    reg62=ponderation*reg41; reg64=ponderation*reg57; reg21=reg35-reg21; reg59=ponderation*reg59; reg82=f.premul_KUn_in_sollicitation*reg82;
    reg69=vectors[0][indices[2]+0]*reg69; reg88=f.premul_KUn_in_sollicitation*reg88; reg97=vectors[0][indices[2]+0]*reg97; reg72=ponderation*reg72; reg10=reg56-reg10;
    reg87=vectors[0][indices[2]+0]*reg87; reg96=ponderation*reg96; reg103=reg90+reg103; reg25=ponderation*reg25; reg93=reg95+reg93;
    reg77=vectors[0][indices[2]+0]*reg77; reg71=f.premul_KUn_in_sollicitation*reg71; reg58=f.premul_KUn_in_sollicitation*reg58; reg65=f.premul_KUn_in_sollicitation*reg65; reg27=reg53+reg27;
    reg54=reg98+reg54; reg45=vectors[0][indices[2]+0]*reg45; reg107=f.premul_KUn_in_sollicitation*reg107; reg110=vectors[0][indices[2]+0]*reg110; reg59=vectors[0][indices[2]+1]*reg59;
    reg107=reg103+reg107; reg110=f.premul_KUn_in_sollicitation*reg110; reg96=vectors[0][indices[2]+1]*reg96; reg88=reg10+reg88; reg10=vectors[0][indices[2]+1]*reg64;
    reg87=f.premul_KUn_in_sollicitation*reg87; reg35=vectors[0][indices[2]+1]*reg62; reg71=reg93+reg71; reg69=f.premul_KUn_in_sollicitation*reg69; reg82=reg21+reg82;
    reg45=f.premul_KUn_in_sollicitation*reg45; reg65=reg54+reg65; reg25=vectors[0][indices[2]+1]*reg25; reg77=f.premul_KUn_in_sollicitation*reg77; reg58=reg27+reg58;
    reg97=f.premul_KUn_in_sollicitation*reg97; reg72=vectors[0][indices[2]+1]*reg72; reg59=f.premul_KUn_in_sollicitation*reg59; reg35=f.premul_KUn_in_sollicitation*reg35; reg97=reg58+reg97;
    reg25=f.premul_KUn_in_sollicitation*reg25; reg45=reg71+reg45; reg96=f.premul_KUn_in_sollicitation*reg96; reg77=reg65+reg77; reg10=f.premul_KUn_in_sollicitation*reg10;
    reg72=f.premul_KUn_in_sollicitation*reg72; reg87=reg88+reg87; reg110=reg107+reg110; reg69=reg82+reg69; T vec_1=reg97+reg59;
    T vec_4=reg87-reg10; T vec_0=reg45+reg25; T vec_2=reg77+reg72; T vec_3=reg69-reg35; T vec_5=reg110+reg96;
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
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_local_elem_matrix(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
template<class TD,class T,class TM,bool wont_add_nz,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_residual( TD ponderation, const TD *var_inter,
      const Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices ) { 
  #define PNODE(N) (*elem.node(N))
    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=1+reg0; reg1=reg1/(*f.m).elastic_modulus; T reg2=elem.pos(2)[0]-elem.pos(0)[0];
    T reg3=pow(reg1,2); T reg4=elem.pos(1)[1]-elem.pos(0)[1]; T reg5=elem.pos(2)[1]-elem.pos(0)[1]; T reg6=elem.pos(1)[0]-elem.pos(0)[0]; reg0=reg0/(*f.m).elastic_modulus;
    T reg7=reg6*reg5; T reg8=1.0/(*f.m).elastic_modulus; T reg9=reg4*reg2; reg1=reg1*reg3; reg9=reg7-reg9;
    reg7=reg0*reg1; reg1=reg8*reg1; T reg10=reg0*reg3; reg3=reg8*reg3; T reg11=reg8*reg1;
    T reg12=reg0*reg7; reg1=reg0*reg1; T reg13=reg8*reg3; T reg14=reg0*reg10; reg3=reg0*reg3;
    reg2=reg2/reg9; T reg15=reg4/reg9; T reg16=reg6/reg9; reg5=reg5/reg9; T reg17=vectors[0][indices[1]+0]-vectors[0][indices[0]+0];
    T reg18=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg19=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg20=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; reg3=reg3+reg14; T reg21=reg15*reg18;
    reg13=reg13-reg14; T reg22=reg5*reg17; reg10=reg8*reg10; T reg23=reg16*reg19; T reg24=reg2*reg20;
    reg1=reg12+reg1; reg11=reg11-reg12; reg7=reg8*reg7; reg18=reg16*reg18; reg17=reg2*reg17;
    reg20=reg5*reg20; reg19=reg15*reg19; reg24=reg23-reg24; reg21=reg22-reg21; reg22=reg0*reg1;
    reg23=reg14+reg10; reg3=reg0*reg3; reg7=reg12+reg7; reg12=reg8*reg11; reg13=reg8*reg13;
    reg23=reg0*reg23; reg3=reg13-reg3; reg7=reg0*reg7; reg19=reg20-reg19; reg0=(*f.m).param*(*f.m).me_sens;
    reg17=reg18-reg17; reg13=reg21+reg24; reg22=reg12-reg22; reg7=reg22-reg7; reg19=reg17+reg19;
    reg13=reg13/2; reg0=(*f.m).me+reg0; reg23=reg3-reg23; reg13=reg0*reg13; reg1=reg1/reg7;
    reg11=reg11/reg7; reg19=0.5*reg19; reg7=reg23/reg7; reg3=reg1*reg24; reg12=reg11*reg21;
    reg19=reg7*reg19; reg13=1+reg13; reg21=reg1*reg21; reg24=reg11*reg24; reg17=reg19/reg13;
    reg18=reg2-reg16; reg20=reg15-reg5; reg24=reg21+reg24; reg3=reg12+reg3; reg12=1-var_inter[0];
    reg21=reg12-var_inter[1]; reg22=0.5*reg15; reg23=0.5*reg2; T reg25=reg24/reg13; T reg26=0.5*reg20;
    T reg27=0.5*reg16; T reg28=0.5*reg18; reg17=2*reg17; T reg29=0.5*reg5; T reg30=reg3/reg13;
    T reg31=reg17*reg27; T reg32=(*f.m).f_vol[0]*var_inter[1]; T reg33=reg5*reg30; T reg34=reg25*reg18; T reg35=reg17*reg23;
    T reg36=(*f.m).f_vol[0]*var_inter[0]; T reg37=reg15*reg30; T reg38=(*f.m).f_vol[1]*var_inter[0]; T reg39=reg2*reg25; T reg40=reg17*reg29;
    T reg41=(*f.m).f_vol[1]*reg21; T reg42=reg17*reg26; T reg43=reg16*reg25; T reg44=reg17*reg22; T reg45=(*f.m).f_vol[0]*reg21;
    T reg46=(*f.m).f_vol[1]*var_inter[1]; T reg47=reg17*reg28; T reg48=reg30*reg20; reg31=reg31-reg37; reg32=(*f.m).density*reg32;
    reg33=reg33-reg35; reg43=reg43-reg44; reg38=(*f.m).density*reg38; reg40=reg40-reg39; reg46=(*f.m).density*reg46;
    reg41=(*f.m).density*reg41; reg47=reg48+reg47; reg45=(*f.m).density*reg45; reg42=reg34+reg42; reg36=(*f.m).density*reg36;
    reg41=reg42-reg41; reg38=reg40-reg38; reg32=reg31-reg32; reg46=reg43-reg46; reg45=reg47-reg45;
    reg36=reg33-reg36; reg38=reg9*reg38; reg46=reg9*reg46; reg41=reg9*reg41; reg32=reg9*reg32;
    reg45=reg9*reg45; reg36=reg9*reg36; reg36=ponderation*reg36; T vec_2=reg36; reg46=ponderation*reg46;
    T vec_5=reg46; reg45=ponderation*reg45; T vec_0=reg45; reg32=ponderation*reg32; T vec_4=reg32;
    reg41=ponderation*reg41; T vec_1=reg41; reg38=ponderation*reg38; T vec_3=reg38;
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
#ifndef ADD_NODAL_MATRIX_elasticity_dep_false_true_true
#define ADD_NODAL_MATRIX_elasticity_dep_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    T reg0=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[0]; T reg1=PNODE(0).dep_imp_val_0_0[1]*(*f.m).lim_cond_0; T reg2=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[1]; T reg3=PNODE(0).dep_imp_val_0_0[0]*(*f.m).lim_cond_0; T tmp_0_0=PNODE(0).dep_imp_coef_0;
    T tmp_1_1=PNODE(0).dep_imp_coef_0; T reg4=reg0+reg3; T reg5=reg2+reg1; T reg6=PNODE(0).dep_imp_coef_0*reg4; T reg7=PNODE(0).dep_imp_coef_0*reg5;
    T reg8=PNODE(0).f_nodal[0]+reg6; T vec_0=reg8; T reg9=PNODE(0).f_nodal[1]+reg7; T vec_1=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_elasticity_dep_true_true_true
#define ADD_NODAL_MATRIX_elasticity_dep_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    T reg0=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[0]; T reg1=PNODE(0).dep_imp_val_0_0[1]*(*f.m).lim_cond_0; T reg2=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[1]; T reg3=PNODE(0).dep_imp_val_0_0[0]*(*f.m).lim_cond_0; T tmp_0_0=PNODE(0).dep_imp_coef_0;
    T tmp_1_1=PNODE(0).dep_imp_coef_0; T reg4=reg0+reg3; T reg5=reg2+reg1; T reg6=PNODE(0).dep_imp_coef_0*reg4; T reg7=PNODE(0).dep_imp_coef_0*reg5;
    T reg8=PNODE(0).f_nodal[0]+reg6; T vec_0=reg8; T reg9=PNODE(0).f_nodal[1]+reg7; T vec_1=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_elasticity_dep_false_true_false
#define ADD_NODAL_MATRIX_elasticity_dep_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    T tmp_0_0=PNODE(0).dep_imp_coef_0; T tmp_1_1=PNODE(0).dep_imp_coef_0;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_elasticity_dep_true_true_false
#define ADD_NODAL_MATRIX_elasticity_dep_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    T tmp_0_0=PNODE(0).dep_imp_coef_0; T tmp_1_1=PNODE(0).dep_imp_coef_0;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    matrix(indices[0]+0,indices[0]+0) += tmp_0_0;
    matrix(indices[0]+1,indices[0]+1) += tmp_1_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_elasticity_dep_symmetric_version_false_true
#define ADD_NODAL_MATRIX_elasticity_dep_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
    T reg0=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[0]; T reg1=PNODE(0).dep_imp_val_0_0[1]*(*f.m).lim_cond_0; T reg2=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[1]; T reg3=PNODE(0).dep_imp_val_0_0[0]*(*f.m).lim_cond_0; T reg4=reg0+reg3;
    T reg5=reg2+reg1; T reg6=PNODE(0).dep_imp_coef_0*reg4; T reg7=PNODE(0).dep_imp_coef_0*reg5; T reg8=PNODE(0).f_nodal[0]+reg6; T vec_0=reg8;
    T reg9=PNODE(0).f_nodal[1]+reg7; T vec_1=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_elasticity_dep_symmetric_version_false_false
#define ADD_NODAL_MATRIX_elasticity_dep_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
#ifndef ADD_NODAL_RESIDUAL_elasticity_dep
#define ADD_NODAL_RESIDUAL_elasticity_dep
template<class TM,class T,bool wont_add_nz,class TVE,class TVEVE>
void add_nodal_residual(
      const Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const typename TM::TNode &node,
      const unsigned *indices ) { 
  #define PNODE(N) node
    T reg0=PNODE(0).dep_imp_val_0_0[1]*(*f.m).lim_cond_0; T reg1=PNODE(0).dep_imp_val_0_0[0]*(*f.m).lim_cond_0; T reg2=vectors[0][indices[0]+0]-reg1; T reg3=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[0]; T reg4=(*f.m).lim_cond_1*PNODE(0).dep_imp_val_0_1[1];
    T reg5=vectors[0][indices[0]+1]-reg0; reg5=reg5-reg4; reg2=reg2-reg3; T reg6=PNODE(0).dep_imp_coef_0*reg2; T reg7=PNODE(0).dep_imp_coef_0*reg5;
    T vec_0=reg6-PNODE(0).f_nodal[0]; T vec_1=reg7-PNODE(0).f_nodal[1];
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg0/reg3; reg3=reg1/reg3; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    reg2=reg0*reg2; reg3=reg1*reg3; T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; T reg8=0.5*skin_elem.f_surf[1];
    T reg9=0.5*reg4; reg3=reg2+reg3; reg2=reg6-reg7; reg9=reg8+reg9; reg2=reg3*reg2;
    T vec_0=reg2; T vec_2=reg2; reg9=reg3*reg9; T vec_1=reg9; T vec_3=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg0/reg3; reg3=reg1/reg3; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    reg2=reg0*reg2; reg3=reg1*reg3; T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; T reg8=0.5*skin_elem.f_surf[1];
    T reg9=0.5*reg4; reg3=reg2+reg3; reg2=reg6-reg7; reg9=reg8+reg9; reg2=reg3*reg2;
    T vec_0=reg2; T vec_2=reg2; reg9=reg3*reg9; T vec_1=reg9; T vec_3=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg0/reg3; reg3=reg1/reg3; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    reg2=reg0*reg2; reg3=reg1*reg3; T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; T reg8=0.5*skin_elem.f_surf[1];
    T reg9=0.5*reg4; reg3=reg2+reg3; reg2=reg6-reg7; reg9=reg8+reg9; reg2=reg3*reg2;
    T vec_0=reg2; T vec_2=reg2; reg9=reg3*reg9; T vec_1=reg9; T vec_3=reg9;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
      const Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg1/reg3; reg3=reg0/reg3; T reg4=skin_elem.p*reg3; T reg5=skin_elem.p*reg2;
    reg3=reg0*reg3; T reg6=0.5*reg5; T reg7=0.5*skin_elem.f_surf[1]; T reg8=0.5*reg4; T reg9=0.5*skin_elem.f_surf[0];
    reg2=reg1*reg2; T reg10=reg9-reg6; reg2=reg3+reg2; reg8=reg7+reg8; reg10=reg2*reg10;
    reg8=reg2*reg8; T vec_0=-reg10; T vec_2=-reg10; T vec_1=-reg8; T vec_3=-reg8;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(2)[1]-elem.pos(1)[1]; T reg1=elem.pos(2)[0]-elem.pos(1)[0]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg2=reg3+reg2;
    reg2=pow(reg2,0.5); reg3=reg1/reg2; reg2=reg0/reg2; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg2=reg0*reg2; reg3=reg1*reg3; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg2=reg3+reg2; reg3=reg6-reg0; reg7=reg1+reg7; reg3=reg2*reg3;
    T vec_2=reg3; T vec_4=reg3; reg7=reg2*reg7; T vec_3=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
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
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(2)[1]-elem.pos(1)[1]; T reg1=elem.pos(2)[0]-elem.pos(1)[0]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg2=reg3+reg2;
    reg2=pow(reg2,0.5); reg3=reg1/reg2; reg2=reg0/reg2; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg2=reg0*reg2; reg3=reg1*reg3; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg2=reg3+reg2; reg3=reg6-reg0; reg7=reg1+reg7; reg3=reg2*reg3;
    T vec_2=reg3; T vec_4=reg3; reg7=reg2*reg7; T vec_3=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
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
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(2)[1]-elem.pos(1)[1]; T reg1=elem.pos(2)[0]-elem.pos(1)[0]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg2=reg3+reg2;
    reg2=pow(reg2,0.5); reg3=reg1/reg2; reg2=reg0/reg2; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg2=reg0*reg2; reg3=reg1*reg3; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg2=reg3+reg2; reg3=reg6-reg0; reg7=reg1+reg7; reg3=reg2*reg3;
    T vec_2=reg3; T vec_4=reg3; reg7=reg2*reg7; T vec_3=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[1]+0] += vec_2;
sollicitation[indices[1]+1] += vec_3;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
      const Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(1)[1]; T reg1=elem.pos(2)[0]-elem.pos(1)[0]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg2=reg3+reg2;
    reg2=pow(reg2,0.5); reg3=reg1/reg2; reg2=reg0/reg2; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    T reg6=0.5*skin_elem.f_surf[1]; T reg7=0.5*reg5; reg2=reg0*reg2; reg3=reg1*reg3; reg0=0.5*skin_elem.f_surf[0];
    reg1=0.5*reg4; reg2=reg3+reg2; reg3=reg0-reg1; reg7=reg6+reg7; reg3=reg2*reg3;
    reg7=reg2*reg7; T vec_2=-reg3; T vec_4=-reg3; T vec_3=-reg7; T vec_5=-reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
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
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(0)[1]-elem.pos(2)[1]; T reg1=elem.pos(0)[0]-elem.pos(2)[0]; T reg2=pow(reg1,2); T reg3=pow(reg0,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg1/reg3; reg3=reg0/reg3; T reg4=skin_elem.p*reg3; T reg5=skin_elem.p*reg2;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg3=reg0*reg3; reg2=reg1*reg2; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg3=reg2+reg3; reg2=reg6-reg0; reg7=reg1+reg7; reg2=reg2*reg3;
    T vec_0=reg2; T vec_4=reg2; reg7=reg3*reg7; T vec_1=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(0)[1]-elem.pos(2)[1]; T reg1=elem.pos(0)[0]-elem.pos(2)[0]; T reg2=pow(reg1,2); T reg3=pow(reg0,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg1/reg3; reg3=reg0/reg3; T reg4=skin_elem.p*reg3; T reg5=skin_elem.p*reg2;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg3=reg0*reg3; reg2=reg1*reg2; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg3=reg2+reg3; reg2=reg6-reg0; reg7=reg1+reg7; reg2=reg2*reg3;
    T vec_0=reg2; T vec_4=reg2; reg7=reg3*reg7; T vec_1=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
    T reg0=elem.pos(0)[1]-elem.pos(2)[1]; T reg1=elem.pos(0)[0]-elem.pos(2)[0]; T reg2=pow(reg1,2); T reg3=pow(reg0,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg1/reg3; reg3=reg0/reg3; T reg4=skin_elem.p*reg3; T reg5=skin_elem.p*reg2;
    T reg6=0.5*skin_elem.f_surf[0]; T reg7=0.5*reg5; reg3=reg0*reg3; reg2=reg1*reg2; reg0=0.5*reg4;
    reg1=0.5*skin_elem.f_surf[1]; reg3=reg2+reg3; reg2=reg6-reg0; reg7=reg1+reg7; reg2=reg2*reg3;
    T vec_0=reg2; T vec_4=reg2; reg7=reg3*reg7; T vec_1=reg7; T vec_5=reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
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
      const Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[1]-elem.pos(2)[1]; T reg1=elem.pos(0)[0]-elem.pos(2)[0]; T reg2=pow(reg1,2); T reg3=pow(reg0,2); reg3=reg2+reg3;
    reg3=pow(reg3,0.5); reg2=reg0/reg3; reg3=reg1/reg3; T reg4=skin_elem.p*reg2; T reg5=skin_elem.p*reg3;
    reg3=reg1*reg3; reg1=0.5*reg4; reg2=reg0*reg2; reg0=0.5*skin_elem.f_surf[1]; T reg6=0.5*skin_elem.f_surf[0];
    T reg7=0.5*reg5; T reg8=reg6-reg1; reg2=reg3+reg2; reg7=reg0+reg7; reg8=reg8*reg2;
    reg7=reg2*reg7; T vec_0=-reg8; T vec_4=-reg8; T vec_1=-reg7; T vec_5=-reg7;
    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
sollicitation[indices[0]+0] += vec_0;
sollicitation[indices[0]+1] += vec_1;
sollicitation[indices[2]+0] += vec_4;
sollicitation[indices[2]+1] += vec_5;
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TD,class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_local_elem_vector_der_var(TD ponderation,const TD *var_inter,
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices, Number<0> num_der_var ) {
  #define PNODE(N) (*elem.node(N))
  /* (*f.m).param */    T reg0=(*f.m).param*(*f.m).poisson_ratio_sens; reg0=(*f.m).poisson_ratio+reg0; T reg1=(*f.m).poisson_ratio_sens/(*f.m).elastic_modulus; T reg2=1+reg0; reg2=reg2/(*f.m).elastic_modulus;
    T reg3=2*reg1; T reg4=pow(reg2,2); reg3=reg3*reg2; T reg5=reg2*reg3; T reg6=reg1*reg4;
    reg2=reg2*reg4; reg5=reg6+reg5; reg0=reg0/(*f.m).elastic_modulus; T reg7=reg0*reg5; T reg8=reg1*reg2;
    T reg9=1.0/(*f.m).elastic_modulus; T reg10=reg0*reg3; reg8=reg7+reg8; reg5=reg9*reg5; reg7=reg9*reg2;
    reg2=reg0*reg2; reg6=reg10+reg6; reg10=reg9*reg4; reg3=reg9*reg3; reg4=reg0*reg4;
    T reg11=reg0*reg8; T reg12=reg1*reg7; T reg13=reg1*reg2; T reg14=reg0*reg5; T reg15=reg0*reg6;
    T reg16=reg0*reg7; T reg17=reg1*reg10; T reg18=reg0*reg3; T reg19=reg0*reg2; reg13=reg11+reg13;
    reg11=reg1*reg4; reg14=reg12+reg14; reg12=elem.pos(1)[0]-elem.pos(0)[0]; T reg20=elem.pos(1)[1]-elem.pos(0)[1]; T reg21=elem.pos(2)[0]-elem.pos(0)[0];
    T reg22=elem.pos(2)[1]-elem.pos(0)[1]; reg7=reg9*reg7; reg14=reg14+reg13; reg5=reg9*reg5; reg17=reg18+reg17;
    reg18=reg9*reg10; reg8=reg9*reg8; T reg23=reg0*reg4; reg10=reg0*reg10; T reg24=reg12*reg22;
    T reg25=reg20*reg21; reg2=reg9*reg2; reg16=reg19+reg16; reg11=reg15+reg11; reg17=reg11+reg17;
    reg8=reg13+reg8; reg13=reg5-reg13; reg6=reg9*reg6; reg3=reg9*reg3; reg5=reg1*reg16;
    reg15=reg0*reg14; reg10=reg10+reg23; reg18=reg18-reg23; reg25=reg24-reg25; reg4=reg9*reg4;
    reg2=reg19+reg2; reg19=reg7-reg19; reg7=reg0*reg16; reg24=reg0*reg10; T reg26=reg9*reg13;
    reg10=reg1*reg10; reg18=reg9*reg18; T reg27=reg9*reg19; reg6=reg11+reg6; reg5=reg15+reg5;
    reg11=reg3-reg11; reg3=reg20/reg25; reg15=reg12/reg25; reg22=reg22/reg25; reg21=reg21/reg25;
    T reg28=reg1*reg2; reg17=reg0*reg17; T reg29=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; T reg30=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg31=vectors[0][indices[1]+1]-vectors[0][indices[0]+1];
    reg8=reg0*reg8; T reg32=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg33=reg23+reg4; reg1=reg1*reg33; reg7=reg27-reg7;
    reg5=reg26-reg5; reg6=reg0*reg6; reg26=reg21*reg31; reg17=reg10+reg17; reg8=reg28+reg8;
    reg10=reg15*reg32; reg11=reg9*reg11; reg33=reg0*reg33; reg24=reg18-reg24; reg2=reg0*reg2;
    reg0=reg3*reg30; reg18=reg22*reg29; reg30=reg15*reg30; reg2=reg7-reg2; reg1=reg6+reg1;
    reg26=reg10-reg26; reg0=reg18-reg0; reg17=reg11-reg17; reg29=reg21*reg29; reg33=reg24-reg33;
    reg31=reg22*reg31; reg32=reg3*reg32; reg8=reg5-reg8; reg5=pow(reg2,2); reg29=reg30-reg29;
    reg32=reg31-reg32; reg6=(*f.m).param*(*f.m).me_sens; reg1=reg17-reg1; reg7=reg0+reg26; reg10=reg16*reg8;
    reg11=reg19*reg8; reg8=reg33*reg8; reg14=reg14/reg2; reg7=reg7/2; reg11=reg11/reg5;
    reg6=(*f.m).me+reg6; reg17=reg3-reg22; reg32=reg29+reg32; reg1=reg1/reg2; reg8=reg8/reg5;
    reg13=reg13/reg2; reg5=reg10/reg5; reg11=reg13-reg11; reg5=reg14-reg5; reg10=(*f.m).me_sens*reg7;
    reg13=reg21-reg15; reg19=reg19/reg2; reg32=0.5*reg32; reg16=reg16/reg2; reg8=reg1-reg8;
    reg2=reg33/reg2; reg7=reg6*reg7; reg1=reg17/2; reg14=reg2*reg32; reg18=0.5*reg13;
    reg24=(*f.m).me_sens*reg1; reg27=reg26*reg5; reg28=reg19*reg26; reg29=reg16*reg0; reg7=1+reg7;
    reg30=reg0*reg11; reg32=reg32*reg8; reg31=reg16*reg26; reg33=reg19*reg0; T reg34=2*reg10;
    T reg35=reg13/2; reg0=reg0*reg5; reg26=reg26*reg11; reg1=reg6*reg1; T reg36=0.5*reg17;
    T reg37=reg6*reg35; T reg38=reg14*reg1; T reg39=reg2*reg18; T reg40=reg22/2; T reg41=pow(reg7,2);
    reg28=reg29+reg28; reg27=reg30+reg27; reg31=reg33+reg31; reg29=reg14*reg24; reg30=reg1*reg32;
    reg34=reg7*reg34; reg35=(*f.m).me_sens*reg35; reg26=reg0+reg26; reg0=0.5*reg21; reg33=reg19*reg17;
    T reg42=(*f.m).me_sens*reg40; T reg43=reg28*reg1; T reg44=reg18*reg8; T reg45=reg28*reg24; T reg46=reg16*reg17;
    T reg47=reg1*reg26; T reg48=reg37*reg32; reg30=reg29+reg30; reg29=pow(reg41,2); T reg49=reg14*reg35;
    T reg50=reg39*reg10; T reg51=reg31*reg1; T reg52=reg21/2; reg24=reg31*reg24; reg1=reg1*reg27;
    T reg53=reg38*reg34; reg40=reg6*reg40; T reg54=reg14*reg37; T reg55=reg2*reg36; reg50=reg50/reg41;
    reg44=reg44/reg7; T reg56=(*f.m).me_sens*reg52; T reg57=reg55*reg10; T reg58=reg36*reg8; T reg59=reg6*reg52;
    T reg60=reg28*reg37; T reg61=reg19*reg13; reg47=reg45+reg47; reg45=reg43*reg34; T reg62=reg37*reg27;
    T reg63=reg40*reg32; T reg64=reg54*reg34; T reg65=reg3/2; reg48=reg49+reg48; reg49=reg14*reg40;
    T reg66=reg2*reg0; T reg67=reg31*reg37; T reg68=reg16*reg13; T reg69=0.5*reg22; T reg70=reg28*reg35;
    reg37=reg37*reg26; reg35=reg31*reg35; T reg71=reg46*reg10; T reg72=reg51*reg34; T reg73=reg33*reg10;
    reg1=reg24+reg1; reg24=reg17*reg5; reg53=reg53/reg29; T reg74=reg14*reg42; reg30=reg30/reg41;
    T reg75=reg17*reg11; T reg76=reg60*reg34; reg37=reg70+reg37; reg70=reg13*reg11; reg73=reg73/reg41;
    T reg77=reg61*reg10; T reg78=reg0*reg8; T reg79=reg40*reg26; reg75=reg75/reg7; T reg80=reg28*reg42;
    T reg81=reg66*reg10; reg24=reg24/reg7; T reg82=reg49*reg34; reg63=reg74+reg63; reg74=reg14*reg56;
    T reg83=reg59*reg32; reg47=reg47/reg41; reg45=reg45/reg29; reg71=reg71/reg41; T reg84=reg6*reg65;
    T reg85=reg67*reg34; reg62=reg35+reg62; reg35=reg2*reg69; reg48=reg48/reg41; T reg86=reg68*reg10;
    T reg87=reg13*reg5; T reg88=0.5*reg15; reg64=reg64/reg29; T reg89=reg14*reg59; T reg90=reg15/2;
    T reg91=reg22*reg19; T reg92=reg22*reg16; T reg93=reg28*reg40; reg53=reg30-reg53; reg1=reg1/reg41;
    reg72=reg72/reg29; reg50=reg44-reg50; reg42=reg31*reg42; reg57=reg57/reg41; reg58=reg58/reg7;
    reg30=(*f.m).me_sens*reg65; reg44=reg31*reg40; reg40=reg40*reg27; T reg94=reg14*reg84; reg76=reg76/reg29;
    T reg95=reg28*reg59; reg71=reg24-reg71; reg37=reg37/reg41; reg24=reg21*reg19; reg72=reg1-reg72;
    reg1=reg31*reg56; T reg96=reg22*reg11; T reg97=reg6*reg90; T reg98=reg59*reg27; reg63=reg63/reg41;
    reg45=reg47-reg45; reg47=reg2*reg88; reg78=reg78/reg7; T reg99=reg21*reg16; T reg100=reg31*reg59;
    T reg101=reg69*reg8; reg82=reg82/reg29; reg81=reg81/reg41; T reg102=reg91*reg10; reg64=reg48-reg64;
    reg48=reg44*reg34; reg40=reg42+reg40; reg42=reg84*reg32; T reg103=reg14*reg30; reg57=reg58-reg57;
    reg90=(*f.m).me_sens*reg90; reg62=reg62/reg41; reg85=reg85/reg29; reg87=reg87/reg7; reg86=reg86/reg41;
    reg58=reg93*reg34; reg79=reg80+reg79; reg73=reg75-reg73; reg75=reg14*reg10; reg56=reg28*reg56;
    reg80=reg59*reg26; reg70=reg70/reg7; reg53=reg50-reg53; reg77=reg77/reg41; reg50=0.5*reg3;
    T reg104=reg35*reg10; T reg105=reg92*reg10; T reg106=reg22*reg5; T reg107=reg89*reg34; reg83=reg74+reg83;
    reg64=reg57-reg64; reg79=reg79/reg41; reg76=reg37-reg76; reg82=reg63-reg82; reg72=reg73-reg72;
    reg105=reg105/reg41; reg106=reg106/reg7; reg102=reg102/reg41; reg96=reg96/reg7; reg58=reg58/reg29;
    reg48=reg48/reg29; reg40=reg40/reg41; reg37=reg95*reg34; reg57=reg31*reg30; reg63=reg47*reg10;
    reg73=reg88*reg8; reg74=reg94*reg34; reg42=reg103+reg42; reg85=reg62-reg85; reg86=reg87-reg86;
    reg62=reg32/reg7; reg75=reg75/reg41; reg80=reg56+reg80; reg56=reg31*reg10; reg77=reg70-reg77;
    reg70=reg21*reg11; reg87=reg24*reg10; reg53=2*reg53; reg30=reg28*reg30; reg103=reg84*reg26;
    T reg108=reg28*reg84; T reg109=reg3*reg16; T reg110=reg14*reg97; T reg111=reg2*reg50; T reg112=reg31*reg84;
    T reg113=reg3*reg19; T reg114=reg84*reg27; reg81=reg78-reg81; reg98=reg1+reg98; reg1=reg100*reg34;
    reg78=reg28*reg10; T reg115=reg21*reg5; T reg116=reg99*reg10; reg45=reg71-reg45; reg107=reg107/reg29;
    reg83=reg83/reg41; reg104=reg104/reg41; reg101=reg101/reg7; reg71=reg14*reg90; reg32=reg97*reg32;
    T reg117=reg3*reg72; T reg118=reg97*reg26; T reg119=reg69*reg53; reg1=reg1/reg29; reg115=reg115/reg7;
    T reg120=reg21*reg45; T reg121=reg0*reg53; T reg122=reg88*reg53; T reg123=reg109*reg10; reg81=reg82+reg81;
    reg82=reg15*reg45; T reg124=reg50*reg53; reg102=reg96-reg102; reg96=reg28*reg90; reg107=reg83-reg107;
    reg83=reg3*reg5; T reg125=reg108*reg34; reg103=reg30+reg103; reg98=reg98/reg41; reg104=reg101-reg104;
    reg70=reg70/reg7; reg48=reg40-reg48; reg87=reg87/reg41; reg116=reg116/reg41; reg30=reg22*reg72;
    reg80=reg80/reg41; reg37=reg37/reg29; reg40=reg27/reg7; reg76=reg77-reg76; reg64=2*reg64;
    reg26=reg26/reg7; reg78=reg78/reg41; reg77=reg15*reg19; reg101=reg28*reg97; T reg126=reg36*reg53;
    reg53=reg18*reg53; T reg127=reg111*reg10; reg8=reg50*reg8; T reg128=reg110*reg34; reg32=reg71+reg32;
    reg56=reg56/reg41; reg45=reg13*reg45; reg75=reg62-reg75; reg27=reg97*reg27; reg90=reg31*reg90;
    reg85=reg86-reg85; reg74=reg74/reg29; reg42=reg42/reg41; reg63=reg63/reg41; reg73=reg73/reg7;
    reg114=reg57+reg114; reg57=reg112*reg34; reg62=reg113*reg10; reg71=reg3*reg11; reg105=reg106-reg105;
    reg58=reg79-reg58; reg72=reg17*reg72; reg97=reg31*reg97; reg79=reg15*reg16; reg103=reg103/reg41;
    reg87=reg70-reg87; reg70=reg79*reg10; reg104=reg107+reg104; reg125=reg125/reg29; reg72=reg53+reg72;
    reg5=reg15*reg5; reg123=reg123/reg41; reg83=reg83/reg7; reg74=reg42-reg74; reg11=reg15*reg11;
    reg10=reg77*reg10; reg42=reg15*reg76; reg53=reg17*reg85; reg8=reg8/reg7; reg127=reg127/reg41;
    reg58=reg105-reg58; reg124=reg82-reg124; reg37=reg80-reg37; reg32=reg32/reg41; reg128=reg128/reg29;
    reg80=reg88*reg64; reg82=reg3*reg85; reg75=2*reg75; reg56=reg40-reg56; reg40=reg97*reg34;
    reg27=reg90+reg27; reg57=reg57/reg29; reg86=reg18*reg64; reg90=reg36*reg64; reg105=reg13*reg76;
    reg76=reg21*reg76; reg106=reg69*reg64; reg62=reg62/reg41; reg71=reg71/reg7; reg81=2*reg81;
    reg121=reg30-reg121; reg120=reg119-reg120; reg114=reg114/reg41; reg30=reg50*reg64; reg64=reg0*reg64;
    reg85=reg22*reg85; reg78=reg26-reg78; reg117=reg122-reg117; reg63=reg73-reg63; reg34=reg101*reg34;
    reg1=reg98-reg1; reg118=reg96+reg118; reg48=reg102-reg48; reg126=reg45+reg126; reg116=reg115-reg116;
    reg63=reg74+reg63; reg87=reg37-reg87; reg26=reg3*reg48; reg37=reg50*reg81; reg45=reg18*reg75;
    reg73=reg15*reg58; reg124=reg25*reg124; reg57=reg114-reg57; reg30=reg42-reg30; reg42=reg0*reg81;
    reg76=reg106-reg76; reg74=reg21*reg58; reg96=reg21*reg78; reg98=reg69*reg75; reg120=reg25*reg120;
    reg62=reg71-reg62; reg71=reg22*reg48; reg64=reg85-reg64; reg118=reg118/reg41; reg34=reg34/reg29;
    reg117=reg25*reg117; reg11=reg11/reg7; reg85=reg88*reg81; reg10=reg10/reg41; reg123=reg83-reg123;
    reg125=reg103-reg125; reg83=reg15*reg78; reg102=reg50*reg75; reg103=reg69*reg81; reg72=reg25*reg72;
    reg106=reg88*reg75; reg107=reg3*reg56; reg82=reg80-reg82; reg80=reg17*reg56; reg126=reg25*reg126;
    reg29=reg40/reg29; reg27=reg27/reg41; reg48=reg17*reg48; reg40=reg36*reg75; reg58=reg13*reg58;
    reg114=reg36*reg81; reg5=reg5/reg7; reg78=reg13*reg78; reg70=reg70/reg41; reg116=reg1-reg116;
    reg75=reg0*reg75; reg121=reg25*reg121; reg90=reg105+reg90; reg104=2*reg104; reg86=reg53+reg86;
    reg56=reg22*reg56; reg127=reg8-reg127; reg128=reg32-reg128; reg81=reg18*reg81; reg34=reg118-reg34;
    reg114=reg58-reg114; reg1=reg0*reg104; reg81=reg48-reg81; reg8=reg22*reg116; reg42=reg71+reg42;
    reg64=reg25*reg64; reg127=reg128+reg127; reg126=ponderation*reg126; reg10=reg11-reg10; reg11=reg17*reg116;
    reg123=reg125-reg123; reg62=reg57-reg62; reg82=reg25*reg82; reg32=reg50*reg104; reg48=reg15*reg87;
    reg37=reg73+reg37; reg86=reg25*reg86; reg30=reg25*reg30; reg124=ponderation*reg124; reg116=reg3*reg116;
    reg53=reg88*reg104; reg26=reg85+reg26; reg120=ponderation*reg120; reg107=reg106-reg107; reg117=ponderation*reg117;
    reg57=reg21*reg87; reg58=reg69*reg104; reg74=reg103+reg74; reg90=reg25*reg90; reg76=reg25*reg76;
    reg96=reg98-reg96; reg40=reg78+reg40; reg71=reg36*reg104; reg63=2*reg63; reg102=reg83-reg102;
    reg70=reg5-reg70; reg45=reg80+reg45; reg75=reg56-reg75; reg29=reg27-reg29; reg104=reg18*reg104;
    reg72=ponderation*reg72; reg121=ponderation*reg121; reg87=reg13*reg87; reg82=ponderation*reg82; reg114=reg25*reg114;
    reg5=reg22*reg62; reg104=reg11+reg104; reg42=reg25*reg42; reg107=reg25*reg107; reg26=reg25*reg26;
    reg117=vectors[0][indices[0]+0]*reg117; reg1=reg8-reg1; reg116=reg53-reg116; reg45=reg25*reg45; reg8=reg21*reg123;
    reg64=ponderation*reg64; reg11=reg69*reg63; reg57=reg58-reg57; reg75=reg25*reg75; reg74=reg25*reg74;
    reg90=ponderation*reg90; reg76=ponderation*reg76; reg29=reg70-reg29; reg81=reg25*reg81; reg72=vectors[0][indices[0]+0]*reg72;
    reg120=vectors[0][indices[0]+0]*reg120; reg96=reg25*reg96; reg40=reg25*reg40; reg102=reg25*reg102; reg37=reg25*reg37;
    reg27=reg18*reg63; reg30=ponderation*reg30; reg53=reg36*reg63; reg56=reg17*reg62; reg121=vectors[0][indices[0]+0]*reg121;
    reg32=reg48-reg32; reg86=ponderation*reg86; reg48=reg13*reg123; reg58=reg50*reg63; reg126=vectors[0][indices[0]+0]*reg126;
    reg87=reg71+reg87; reg70=reg0*reg63; reg63=reg88*reg63; reg127=2*reg127; reg62=reg3*reg62;
    reg34=reg10-reg34; reg124=vectors[0][indices[0]+0]*reg124; reg123=reg15*reg123; reg96=ponderation*reg96; reg58=reg123-reg58;
    reg76=vectors[0][indices[0]+1]*reg76; reg10=reg15*reg34; reg32=reg25*reg32; reg71=reg50*reg127; reg73=reg17*reg29;
    reg78=reg69*reg127; reg37=ponderation*reg37; reg74=ponderation*reg74; reg40=ponderation*reg40; reg80=f.premul_KUn_in_sollicitation*reg117;
    reg26=ponderation*reg26; reg83=reg88*reg127; reg85=reg3*reg29; reg62=reg63-reg62; reg82=vectors[0][indices[0]+1]*reg82;
    reg63=f.premul_KUn_in_sollicitation*reg121; reg114=ponderation*reg114; reg107=ponderation*reg107; reg98=f.premul_KUn_in_sollicitation*reg124; reg56=reg27+reg56;
    reg102=ponderation*reg102; reg45=ponderation*reg45; reg86=vectors[0][indices[0]+1]*reg86; reg90=vectors[0][indices[0]+1]*reg90; reg27=reg21*reg34;
    reg116=reg25*reg116; reg30=vectors[0][indices[0]+1]*reg30; reg57=reg25*reg57; reg1=reg25*reg1; reg34=reg13*reg34;
    reg87=reg25*reg87; reg42=ponderation*reg42; reg81=ponderation*reg81; reg104=reg25*reg104; reg8=reg11-reg8;
    reg11=reg18*reg127; reg70=reg5-reg70; reg48=reg53+reg48; reg29=reg22*reg29; reg5=reg0*reg127;
    reg127=reg36*reg127; reg64=vectors[0][indices[0]+1]*reg64; reg53=f.premul_KUn_in_sollicitation*reg126; reg103=f.premul_KUn_in_sollicitation*reg72; reg75=ponderation*reg75;
    reg105=f.premul_KUn_in_sollicitation*reg120; reg106=f.premul_KUn_in_sollicitation*reg30; reg115=f.premul_KUn_in_sollicitation*reg90; reg1=ponderation*reg1; reg87=ponderation*reg87;
    reg102=reg98-reg102; reg98=f.premul_KUn_in_sollicitation*reg86; reg27=reg78+reg27; reg45=reg103-reg45; reg42=vectors[0][indices[1]+0]*reg42;
    reg107=reg80-reg107; reg81=vectors[0][indices[1]+0]*reg81; reg114=vectors[0][indices[1]+0]*reg114; reg78=f.premul_KUn_in_sollicitation*reg64; reg80=f.premul_KUn_in_sollicitation*reg82;
    reg127=reg34-reg127; reg85=reg83+reg85; reg75=reg63-reg75; reg34=vectors[0][indices[1]+0]*reg26; reg62=reg25*reg62;
    reg116=ponderation*reg116; reg57=ponderation*reg57; reg63=f.premul_KUn_in_sollicitation*reg76; reg5=reg29+reg5; reg71=reg10+reg71;
    reg10=vectors[0][indices[1]+0]*reg74; reg58=reg25*reg58; reg11=reg73-reg11; reg70=reg25*reg70; reg40=reg53-reg40;
    reg32=ponderation*reg32; reg8=reg25*reg8; reg48=reg25*reg48; reg104=ponderation*reg104; reg37=vectors[0][indices[1]+0]*reg37;
    reg56=reg25*reg56; reg96=reg105-reg96; reg82=reg117+reg82; reg30=reg124+reg30; reg62=ponderation*reg62;
    reg116=vectors[0][indices[1]+1]*reg116; reg127=reg25*reg127; reg76=reg120+reg76; reg64=reg121+reg64; reg90=reg126+reg90;
    reg85=reg25*reg85; reg86=reg72+reg86; reg71=reg25*reg71; reg98=reg45+reg98; reg58=ponderation*reg58;
    reg56=ponderation*reg56; reg11=reg25*reg11; reg32=vectors[0][indices[1]+1]*reg32; reg48=ponderation*reg48; reg29=f.premul_KUn_in_sollicitation*reg37;
    reg106=reg102+reg106; reg87=vectors[0][indices[1]+1]*reg87; reg115=reg40+reg115; reg70=ponderation*reg70; reg57=vectors[0][indices[1]+1]*reg57;
    reg8=ponderation*reg8; reg40=f.premul_KUn_in_sollicitation*reg10; reg5=reg25*reg5; reg1=vectors[0][indices[1]+1]*reg1; reg27=reg25*reg27;
    reg63=reg96+reg63; reg45=f.premul_KUn_in_sollicitation*reg42; reg78=reg75+reg78; reg80=reg107+reg80; reg53=f.premul_KUn_in_sollicitation*reg114;
    reg72=f.premul_KUn_in_sollicitation*reg81; reg73=f.premul_KUn_in_sollicitation*reg34; reg104=vectors[0][indices[1]+1]*reg104; reg29=reg106+reg29; reg86=reg81+reg86;
    reg34=reg82-reg34; reg71=ponderation*reg71; reg75=f.premul_KUn_in_sollicitation*reg1; reg81=f.premul_KUn_in_sollicitation*reg116; reg48=vectors[0][indices[2]+0]*reg48;
    reg40=reg63-reg40; reg127=ponderation*reg127; reg8=vectors[0][indices[2]+0]*reg8; reg73=reg80-reg73; reg58=vectors[0][indices[2]+0]*reg58;
    reg11=ponderation*reg11; reg63=f.premul_KUn_in_sollicitation*reg57; reg80=f.premul_KUn_in_sollicitation*reg32; reg70=vectors[0][indices[2]+0]*reg70; reg30=reg37+reg30;
    reg45=reg78+reg45; reg64=reg42+reg64; reg10=reg76-reg10; reg56=vectors[0][indices[2]+0]*reg56; reg62=vectors[0][indices[2]+0]*reg62;
    reg37=f.premul_KUn_in_sollicitation*reg104; reg72=reg98+reg72; reg85=ponderation*reg85; reg90=reg114+reg90; reg5=ponderation*reg5;
    reg53=reg115+reg53; reg42=f.premul_KUn_in_sollicitation*reg87; reg27=ponderation*reg27; reg30=reg32+reg30; reg10=reg57+reg10;
    reg64=reg1+reg64; reg1=f.premul_KUn_in_sollicitation*reg70; reg5=vectors[0][indices[2]+1]*reg5; reg90=reg87+reg90; reg32=f.premul_KUn_in_sollicitation*reg58;
    reg57=f.premul_KUn_in_sollicitation*reg56; reg34=reg116+reg34; reg71=vectors[0][indices[2]+1]*reg71; reg86=reg104+reg86; reg63=reg40+reg63;
    reg75=reg45+reg75; reg40=f.premul_KUn_in_sollicitation*reg8; reg127=vectors[0][indices[2]+1]*reg127; reg72=reg37+reg72; reg37=f.premul_KUn_in_sollicitation*reg48;
    reg45=f.premul_KUn_in_sollicitation*reg62; reg11=vectors[0][indices[2]+1]*reg11; reg81=reg73+reg81; reg80=reg29+reg80; reg29=vectors[0][indices[2]+1]*reg27;
    reg73=vectors[0][indices[2]+1]*reg85; reg42=reg53+reg42; reg53=f.premul_KUn_in_sollicitation*reg5; reg90=reg48+reg90; reg48=f.premul_KUn_in_sollicitation*reg73;
    reg64=reg70+reg64; reg34=reg62+reg34; reg86=reg56+reg86; reg45=reg81+reg45; reg10=reg8+reg10;
    reg8=f.premul_KUn_in_sollicitation*reg127; reg56=f.premul_KUn_in_sollicitation*reg29; reg57=reg72+reg57; reg30=reg58+reg30; reg58=f.premul_KUn_in_sollicitation*reg71;
    reg62=f.premul_KUn_in_sollicitation*reg11; reg37=reg42+reg37; reg1=reg75+reg1; reg40=reg63+reg40; reg32=reg80+reg32;
    reg73=reg34-reg73; reg48=reg45-reg48; reg8=reg37+reg8; reg30=reg71+reg30; reg29=reg10-reg29;
    reg53=reg1+reg53; reg64=reg5+reg64; reg90=reg127+reg90; reg56=reg40-reg56; reg86=reg11+reg86;
    reg62=reg57+reg62; reg58=reg32+reg58; T vec_0=reg62-reg86; T vec_1=reg8-reg90; T vec_2=reg53-reg64;
    T vec_3=reg56-reg29; T vec_4=reg48-reg73; T vec_5=reg58-reg30;
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
#ifndef ADD_NODAL_VEC_DER_VAR_elasticity_dep_0
#define ADD_NODAL_VEC_DER_VAR_elasticity_dep_0
template<class TM,class TMA,class TVE,class TVEVE,class T,bool wont_add_nz>
void add_nodal_vector_der_var(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const typename TM::TNode &node,
      const unsigned *indices, Number<0> num_der_var ) {
  #define PNODE(N) node
  /* (*f.m).param */    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
#endif
// 
template<class TM,class TMA,class TVE,class TVEVE,class T,bool wont_add_nz,class T_pos,class ND,class ED,unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_vector_der_var(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices, Number<0> num_der_var ) {
  #define PNODE(N) (*elem.node(N))
  /* (*f.m).param */    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class TMA,class TVE,class TVEVE,class T,bool wont_add_nz,class T_pos,class ND,class ED,unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_vector_der_var(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices, Number<0> num_der_var ) {
  #define PNODE(N) (*elem.node(N))
  /* (*f.m).param */    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}
// 
template<class TM,class TMA,class TVE,class TVEVE,class T,bool wont_add_nz,class T_pos,class ND,class ED,unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_vector_der_var(
      Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices, Number<0> num_der_var ) {
  #define PNODE(N) (*elem.node(N))
  /* (*f.m).param */    pthread_mutex_lock( &( f.mutex_assemble_matrix ) );
    pthread_mutex_unlock( &( f.mutex_assemble_matrix ) );
  #undef PNODE
}

#ifndef elasticity_dep_read_material_to_mesh
#define elasticity_dep_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,elasticity_dep,DefaultBehavior,T,wont_add_nz> &f){ 
    if(n.has_attribute("poisson_ratio_sens"))  
        n.get_attribute("poisson_ratio_sens", f.m->poisson_ratio_sens ); 
    else  
        std::cerr << "Warning using default value of poisson_ratio_sens : " << f.m->poisson_ratio_sens << std::endl; 

    if(n.has_attribute("f_vol"))  
        n.get_attribute("f_vol", f.m->f_vol ); 
    else  
        std::cerr << "Warning using default value of f_vol : " << f.m->f_vol << std::endl; 

    if(n.has_attribute("param"))  
        n.get_attribute("param", f.m->param ); 
    else  
        std::cerr << "Warning using default value of param : " << f.m->param << std::endl; 

    if(n.has_attribute("elastic_modulus"))  
        n.get_attribute("elastic_modulus", f.m->elastic_modulus ); 
    else  
        std::cerr << "Warning using default value of elastic_modulus : " << f.m->elastic_modulus << std::endl; 

    if(n.has_attribute("me_sens"))  
        n.get_attribute("me_sens", f.m->me_sens ); 
    else  
        std::cerr << "Warning using default value of me_sens : " << f.m->me_sens << std::endl; 

    if(n.has_attribute("lim_cond_0"))  
        n.get_attribute("lim_cond_0", f.m->lim_cond_0 ); 
    else  
        std::cerr << "Warning using default value of lim_cond_0 : " << f.m->lim_cond_0 << std::endl; 

    if(n.has_attribute("lim_cond_1"))  
        n.get_attribute("lim_cond_1", f.m->lim_cond_1 ); 
    else  
        std::cerr << "Warning using default value of lim_cond_1 : " << f.m->lim_cond_1 << std::endl; 

    if(n.has_attribute("poisson_ratio"))  
        n.get_attribute("poisson_ratio", f.m->poisson_ratio ); 
    else  
        std::cerr << "Warning using default value of poisson_ratio : " << f.m->poisson_ratio << std::endl; 

    if(n.has_attribute("me"))  
        n.get_attribute("me", f.m->me ); 
    else  
        std::cerr << "Warning using default value of me : " << f.m->me << std::endl; 

    if(n.has_attribute("density"))  
        n.get_attribute("density", f.m->density ); 
    else  
        std::cerr << "Warning using default value of density : " << f.m->density << std::endl; 

  };
#endif // elasticity_dep_read_material_to_mesh
} // namespace LMT



#endif // PROBLEM_elasticity_dep
