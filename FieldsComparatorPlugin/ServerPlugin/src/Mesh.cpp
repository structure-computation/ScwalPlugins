#include "Mesh.h"
#include <Soca/Model/TypedArray.h>

void Mesh::operator=(MP mesh_data)
{
    load(mesh_data);
}

void Mesh::load(MP mesh)
{
    /// Recuperation des noeuds
    PRINT("Recuperation des noeuds");
    const unsigned nb_nodes = mesh["points"].size();
    qDebug() << nb_nodes;
    nodes.reserve(nb_nodes);
    for(int n = 0; n < nb_nodes; n++)
    {
        LMT::Vec<double> pos;
        MP point = mesh["points"][n]["pos"];
        for(int d = 0; d < 3; d++)
        {
            pos.push_back( point[d] );
        }
        nodes.push_back( pos );
    }
    
    /// Recuperation des elements
    PRINT("Recuperation des elements");
//     qDebug() << mesh[ "_elements[0].indices" ];
//     qDebug() << mesh[ "_elements[1].indices" ];
    TypedArray<int> *indices_elem = dynamic_cast<TypedArray<int> *>( mesh[ "_elements[0].indices" ].model() );
    const int nodes_by_elem = indices_elem->size(0);
    const unsigned nb_elems = indices_elem->size(1);
    qDebug() << nodes_by_elem << "," << nb_elems;
    elements.resize(nb_elems);
    for(unsigned e = 0, cpt = 0; e < nb_elems; e++)
    {
        for(int n = 0; n < nodes_by_elem; n++, cpt++)
        {
            elements[e].push_back( indices_elem->operator[](cpt) );
        }
    }
    
//     /// Recuperation de la peau
//     PRINT("Recuperation de la peau");
//     TypedArray<int> *indices_skin = dynamic_cast<TypedArray<int> *>( mesh[ "_elements[0].indices" ].model() );
//     const int nodes_by_skin = indices_skin->size(0);
//     const unsigned nb_skins = indices_skin->size(1);
//     qDebug() << nodes_by_skin << "," << nb_skins;
//     skin_elements.resize(nb_skins);
//     for(unsigned s = 0, cpt = 0; s < nb_skins; s++)
//     {
//         for(int n = 0; n < nodes_by_skin; n++, cpt++)
//         {
//             skin_elements[s].push_back( indices_skin->operator[](cpt) );
//         }
//     }
}

MP Mesh::save() const
{
    MP mesh = MP::new_obj("Mesh");
    mesh[ "points" ]        = MP::new_lst();
    mesh[ "_elements" ]     = MP::new_lst();
    mesh[ "visualization" ] = MP::new_obj();
    mesh[ "visualization.display_style" ] = MP::new_obj( "Choice" );
    mesh[ "visualization.display_style.num" ] = 1;
    mesh[ "visualization.display_style.lst" ] = MP::new_lst();
    mesh[ "visualization.display_style.lst" ] << "Points";
    mesh[ "visualization.display_style.lst" ] << "Wireframe";
    mesh[ "visualization.display_style.lst" ] << "Surface";
    mesh[ "visualization.display_style.lst" ] << "Surface with Edges";
    mesh[ "visualization.point_edition" ] = false;
    mesh[ "_selected_points" ]   = MP::new_lst();
    mesh[ "_pelected_points" ]   = MP::new_lst();
    mesh[ "_selected_elements" ] = MP::new_lst();
    mesh[ "_pelected_elements" ] = MP::new_lst();
    
    // nodes
    for( int i = 0; i < nodes.size(); ++i ) {
        MP pos = MP::new_lst( "Vec_3" );
        for( int d = 0; d < 3; ++d )
            pos << nodes[ i ][ d ];
        
        MP pnt = MP::new_obj( "Point" );
        pnt[ "pos" ] = pos;
        mesh[ "points" ] << pnt;
    }
    
    // elements
    TypedArray<int> *tr_con = new TypedArray<int>;
    TypedArray<int> *te_con = new TypedArray<int>;
    for( int n = 0; n < elements.size(); ++n ) {
        if ( elements[ n ].size() == 3 )
            for( int i = 0; i < elements[ n ].size(); ++i )
                tr_con->_data << elements[n][i];
        else if ( elements[ n ].size() == 4 )
            for( int i = 0; i < elements[ n ].size(); ++i )
                te_con->_data << elements[n][i];
    }
    
    for( int n = 0; n < skin_elements.size(); ++n )
        if ( skin_elements[ n ].size() == 3 )
            for( int i = 0; i < skin_elements[ n ].size(); ++i )
                tr_con->_data << skin_elements[ n ][i];
    
    // triangle
    tr_con->_size.resize( 2 );
    tr_con->_size[ 0 ] = 3;
    tr_con->_size[ 1 ] = tr_con->_data.size() / 3;
    
    MP triangles = MP::new_obj( "Element_TriangleList" );
    triangles[ "indices" ] = tr_con;
    mesh[ "_elements" ] << triangles;
    
    // tetra
    te_con->_size.resize( 2 );
    te_con->_size[ 0 ] = 4;
    te_con->_size[ 1 ] = te_con->_data.size() / 4;
    
    MP tetrahedra = MP::new_obj( "Element_TetrahedraList" );
    tetrahedra[ "indices" ] = te_con;
    mesh[ "_elements" ] << tetrahedra;
    
    return mesh;
}
