#include "make_fields.h"

MP make_field( MP mp, QString name ) {
    for( int i = 0; ; ++i ) {
        if ( i == mp[ "visualization.color_by.lst" ].size() ) {
            MP disp = MP::new_obj( "InterpolatedField" );
            disp[ "_data" ] = MP::new_lst();

            MP pd = MP::new_obj( "NamedParametrizedDrawable" );
            pd[ "name" ] = name;
            pd[ "data" ] = disp;
            mp[ "visualization.color_by.lst" ] << pd;
            return disp;
        }
        MP l = mp[ "visualization.color_by.lst" ][ i ];
        if ( QString( l[ "name" ] ) == name ) {
            l[ "data._data" ].clear();
            return l[ "data" ];
        }
    }
}

QVector<MP> make_field( MP mp, int dim, QString base ) {
    QVector<QString> l;
    l << "x" << "y" << "z";
    return make_field( mp, dim, base, l );
}

QVector<MP> make_field( MP mp, int dim, QString base, QVector<QString> letters ) {
    // Displacement_[xyz]
    QVector<MP> displacements;
    for( int d = 0; d < dim; ++d )
        displacements << make_field( mp, QString( base + "_%1" ).arg( letters[d] ) );

    // Displacement (vectorial)
    for( int i = 0; ; ++i ) {
        if ( i == mp[ "visualization.color_by.lst" ].size() ) {
            MP disp = MP::new_obj( "VectorialField" );
            disp[ "_vector" ] = MP::new_lst();
            for( int d = 0; d < dim; ++d )
                disp[ "_vector" ] << displacements[ d ];
            MP pd = MP::new_obj( "NamedParametrizedDrawable" );
            pd[ "name" ] = base;
            pd[ "data" ] = disp;
            mp[ "visualization.color_by.lst" ] << pd;
            mp[ "visualization.warp_by.lst" ] << pd;
            break;
        }
        MP l = mp[ "visualization.color_by.lst" ][ i ];
        if ( QString( l[ "name" ] ) == base ) {
            break;
        }
    }

    return displacements;
}

void add_field_in_Interpolated( MP interpolated_field, MP mesh, MP data, double time, QString type_field ) {
    MP field = MP::new_obj( type_field );
    field[ "_mesh" ] = mesh;
    field[ "_data" ] = data;

    // Interpolated field fill-in
    MP disp = MP::new_obj();
    disp[ "field" ] = field;
    disp[ "pos" ] = MP::new_lst();
    MP pos_v = MP::new_obj();
    pos_v[ "axe_value" ] = time;
    pos_v[ "axe_name" ] = "time";
    disp[ "pos" ] << pos_v;

    interpolated_field[ "_data" ] << disp;
}
