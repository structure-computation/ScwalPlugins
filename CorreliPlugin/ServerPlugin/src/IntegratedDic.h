#ifndef INTEGRATEDDIC_H
#define INTEGRATEDDIC_H

#include "Soca/Model/TypedArray.h"
#include <containers/eig_lapack.h>
#include <mesh/calculate_normals.h>
#include "correlation/DicCPU.h"
#include "make_fields.h"
#include "Soca/MP.h"

void _save_img( MP mp, const QImage &res, int j );

struct StepDer {
    int nb_steps() const {
        return 2; // * want_mat_prop + dim * num_nodes.size();
    }

    template<class TM> void operator()( TM &m, int num_step ) const {
        m.poisson_ratio_sens = ( num_step == 0 );
        m.me_sens = ( num_step == 1 );
        //        if ( want_mat_prop ) {
        //            m.sens_poisson_ratio = ( num_step == 0 );
        //            num_step -= 1;
        //        }
        //        for( int i = 0; i < num_nodes.size(); ++i )
        //            for( int d = 0; d < dim; ++d )
        //                m.node_list[ num_nodes[ i ] ].sen_dep_imp[ d ] = num_step / dim == i and num_step % dim == d;
    }

    template<class TM> void add_delta_derivatives( TM &m, int num_step, double val ) const {
        m.poisson_ratio += ( num_step == 0 ) * val;
        m.me += ( num_step == 1 ) * val;
        //        if ( want_mat_prop ) {
        //            m.poisson_ratio += ( num_step == 0 ) * val;
        //            num_step -= 1;
        //        }
        //        for( int i = 0; i < num_nodes.size(); ++i )
        //            for( int d = 0; d < dim; ++d )
        //                m.node_list[ num_nodes[ i ] ].val_dep_imp[ d ] += val * ( num_step / dim == i and num_step % dim == d );
    }

    //bool want_mat_prop;
    //Vec<int> num_nodes;
};

template<class TM,class CL>
void get_constrained_nodes( Vec<int> &constrained_nodes, TM &m, const CL &constrained_lines, double e = 2 ) {
    //#warning ...
    //    m.update_skin();
    //    for( int i = 0; i < m.skin.node_list.size(); ++i )
    //        constrained_nodes << m.skin.node_list[ i ].number;
    //    return;

    using namespace LMT;
    typedef typename TM::Pvec Pvec;
    for( int n = 0; n < m.node_list.size(); ++n ) {
        Pvec P = m.node_list[ n ].pos;
        for( int i = 0; i < constrained_lines.size(); ++i ) {
            Pvec P0 = constrained_lines[ i ][ 0 ];
            Pvec P1 = constrained_lines[ i ][ 1 ];

            if ( length( P - P0 ) < e ) {
                constrained_nodes << n;
                break;
            }

            double l = length( P1 - P0 );
            Pvec   D = ( P1 - P0 ) / l;
            double m = dot( D, P - P0 );
            if ( m < 0 - e or m > l + e )
                continue;

            Pvec Pr = P0 + m * D;
            if ( length( P - Pr ) > e )
                continue;

            constrained_nodes << n;
            break;
        }
    }

    // HUM -> hard coding of surfaces
    if ( m.dim == 3 ) {
        m.update_skin();
        PRINT( m.skin.node_list.size() );
        calculate_normals( m.skin );
        for( int n = 0; n < m.skin.node_list.size(); ++n ) {
            Pvec N = m.skin.node_list[ n ].normal;
            if ( abs( dot( N, Pvec( 0, 0, 1 ) ) ) > 0.8 )
                constrained_nodes << m.skin.node_list[ n ].number;
        }
    }

}


template<class Dic,class TM,class VI,class TV,class CL>
void integrated_dic( const MP &mp, MP mesh, Dic &dic, Vec<TM> &m, const VI &images, const TV &dep, const CL &constrained_lines, double e = 2 ) {
    using namespace LMT;
    typedef typename TM::Pvec Pvec;
    typedef Formulation<TM,elasticity_dep> TF;

    // get the constrained_nodes
    Vec<int> constrained_nodes;
    get_constrained_nodes( constrained_nodes, m[ 0 ], constrained_lines, e );
    PRINT( constrained_nodes.size() );

    //for( int j = 0; j < constrained_nodes.size(); ++j )
    //    m[ 0 ].node_list[ constrained_nodes[ j ] ].temperature = 1;
    // display( m[ 0 ] );

    // output preparation
    QVector<MP> displacements = make_field( mp, m[ 0 ].dim, "Displacement_int" );
    MP poisson = make_field( mp, "poisson" );

    // integrated dic
    StepDer step_der;
    for( int cpt_iter = 0; cpt_iter < 5; ++cpt_iter ) {
        PRINT( cpt_iter );

        Mat<double,Sym<>,SparseLine<> > M_red( step_der.nb_steps() );
        Vec<double> F_red; F_red.resize( step_der.nb_steps(), 0 );
        for( int num_mesh = 0; num_mesh < m.size(); ++num_mesh ) {
            TF form( m[ num_mesh ] );
            form.levenberg_marquadt = 1e-10; // for gmsh
            form.want_amd = true;

            for( int j = 0; j < constrained_nodes.size(); ++j )
                for( int d = 0; d < m[ 0 ].dim; ++d )
                    form.add_constraint( "node[" + to_string( constrained_nodes[ j ] ) + "].dep[" + to_string( d ) + "] - " +
                                      to_string( m[ num_mesh ].node_list[ constrained_nodes[ j ] ].dep[ d ] ), 1e5 );



            // assemble
            Vec<Vec<double> > der;
            form.solve_and_get_derivatives( der, step_der, true );
            dic.ass_red( images[ 0 ], images[ num_mesh + 1 ], m[ num_mesh ], dep_DM(), lum_DM(), der );


            //for( int n = 0, o = 0; n < m[ 0 ].node_list.size(); ++n )
            //    for( int d = 0; d < 3; ++d, ++o )
            //        m[ 0 ].node_list[ n ].dep_sv[ d ] = der[ 0 ][ o ];
            //display( m[ 0 ] );

            M_red += dic.M_red;
            F_red += dic.F_red;
        }

        // solve
        Vec<double> d = solve_using_eig_sym( M_red, F_red, 1e-3 );
        d /= 10;
        //Vec<double> d = inv( M_red ) * F_red;


        // update
        for( int num_mesh = 0; num_mesh < m.size(); ++num_mesh )
            for( int i = 0; i < d.size(); ++i )
                step_der.add_delta_derivatives( m[ num_mesh ], i, d[ i ] );

        std::cout
                << " d=" << std::setw( 13 ) << d
                << " residual=" << std::setw( 13 ) << dic.dimensionless_residual
                << std::endl;

        for( int num_mesh = 0; num_mesh < m.size(); ++num_mesh )
            m[ num_mesh ].poisson_ratio = min( 0.49, max( 0.01, m[ num_mesh ].poisson_ratio ) );
        PRINT( m[ 0 ].poisson_ratio );
        PRINT( m[ 0 ].me );

        if ( norm_inf( d ) < 1e-2 )
            break;
    }


    // computation
    //    for( int i = 0; i < images.size() - 1; ++i ) {
    //        for( int n = 0; n < m.node_list.size(); ++n )
    //            m.node_list[ n ].dep = dep[ i ][ n ];

    //        TF f( m );
    //        for( int j = 0; j < constrained_nodes.size(); ++j )
    //            for( int d = 0; d < m.dim; ++d )
    //                f.add_constraint( "node[" + to_string( constrained_nodes[ j ] ) + "].dep[" + to_string( d ) + "] - " +
    //                                  to_string( m.node_list[ constrained_nodes[ j ] ].dep[ d ] ), 1e5 );

    //        f.levenberg_marquadt = 1e-10; // for gmsh
    //        f.solve();
    //        // display( m );
    //        // PRINT( "solve" );

    // output
    for( int num_mesh = 0; num_mesh < m.size(); ++num_mesh ) {
        ImgInterp<double,2> residual_img, residual_adv_img;
        dic.get_residual_adv_img( images[ 0 ], images[ num_mesh ], m[ num_mesh ], dep_DM(), lum_DM(), residual_adv_img );
        dic.get_residual_img    ( images[ 0 ], images[ num_mesh ], m[ num_mesh ], dep_DM(), lum_DM(), residual_img     );


        // displacement
        for( int d = 0; d < m[ 0 ].dim; ++d ) {
            QVector<int> s; s << m[ num_mesh ].node_list.size();
            TypedArray<double> *data = new TypedArray<double>( s );

            for( int j = 0; j < m[ num_mesh ].node_list.size(); ++j )
                data->operator[]( j ) = m[ num_mesh ].node_list[ j ].dep[ d ];

            // NodalField
            add_field_in_Interpolated( displacements[ d ], mesh, data, num_mesh );
        }

        // poisson
        QVector<int> s; s << m[ num_mesh ].node_list.size();
        TypedArray<double> *data = new TypedArray<double>( s );

        for( int j = 0; j < m[ num_mesh ].node_list.size(); ++j )
            data->operator[]( j ) = m[ num_mesh ].poisson_ratio;

        add_field_in_Interpolated( poisson, mesh, data, num_mesh );

        _save_img( mp[ "_residual_int"     ], residual_img    .to_QImage( true ), num_mesh );
        _save_img( mp[ "_residual_int_adv" ], residual_adv_img.to_QImage( true ), num_mesh );

    }
}

#endif // INTEGRATEDDIC_H


