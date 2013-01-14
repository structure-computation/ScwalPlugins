#ifndef MODELMESHFROMLMTMESH_H
#define MODELMESHFROMLMTMESH_H

struct GetModElement {
    template<class TE>
    void operator()( const TE &elem, const MP &om ) const {
        MP rs = MP::new_lst();
        for( int i = 0; i < TE::nb_nodes; ++i )
            rs << elem.node( i )->number_in_original_mesh();

        if ( TE::nb_nodes == 3 ) // HUM !!
            om[ "triangles" ] << rs;
        if ( TE::nb_nodes == 2 ) // HUM !!
            om[ "lines" ] << rs;
    }
};

template<class TM>
void model_mesh_from_lmt_mesh( const MP &mod_mesh, const TM &lmt_mesh ) {
    mod_mesh[ "visualisation.display_field.lst" ].clear();
    mod_mesh[ "triangles" ].clear();
    mod_mesh[ "polygons" ].clear();
    mod_mesh[ "points" ].clear();
    mod_mesh[ "lines" ].clear();

    // nodes
    for( int i = 0; i < lmt_mesh.node_list.size(); ++i ) {
        MP pos = MP::new_lst( "Vec_3" );
        for( int d = 0; d < TM::dim; ++d ) pos << lmt_mesh.node_list[ i ].pos[ d ];
        for( int d = TM::dim; d < 3; ++d ) pos << 0;

        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;

        mod_mesh[ "points" ] << pnt;
    }

    // elements
    apply( lmt_mesh.elem_list, GetModElement(), mod_mesh );
    apply( lmt_mesh.sub_mesh( Number<1>() ).elem_list, GetModElement(), mod_mesh );

//    MP field = MP::new_obj( "VectorialField" );
//    field[ "_vector" ] = MP::new_lst();
//    field[ "name" ] = "Displacement";

//    for( int d = 0; d < TM::dim; ++d ) {
//        MP data = MP::new_lst();
//        field[ "_vector" ] << data;

//        // _xyz
//        MP field = MP::new_obj( "NodalField" );
//        field_data << field;
//        field[ "name" ] = QString( "Displacement_%1" ).arg( "xyz"[d] );
//        field[ "_data" ] = data;
//        mod_mesh[ "visualisation.display_field.lst" ] << field;
//    }

//    mod_mesh[ "visualisation.display_field.lst" ] << field;
}

#endif // MODELMESHFROMLMTMESH_H
