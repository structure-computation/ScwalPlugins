#
class BoundaryConditionSetItem extends TreeItem
    constructor: ( dim = 3 ) ->
        super()
        
        # default values
        @_name.set "BoundaryCondition collection"
        @_ico.set "img/boundary_condition_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            nb_bcs:0
            _incr_id_bc:0
            _incr_id_group_edge:0
            _dim: dim
            
        @bind =>
            if  @nb_bcs.has_been_modified()
                @change_collection()
                
    accept_child: ( ch ) ->
        false

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    ask_for_id_group: ->
        id_group = parseInt(@_incr_id_group_edge)
        @_incr_id_group_edge.set (parseInt(@_incr_id_group_edge) + 1)
        return id_group
        
    ask_for_id_bc: ->
        id_link = parseInt(@_incr_id_bc)
        @_incr_id_bc.set (parseInt(@_incr_id_bc) + 1)
        return id_link
    
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @nb_bcs
            size_splice = @_children.length - @nb_bcs
            for num_c in [ @nb_bcs ... @_children.length ]
                @_children[num_c].clear()
            @_children.splice @nb_bcs, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_bcs ]
                id_bc = @ask_for_id_bc()
                name_temp = "BC_" + id_bc.toString()
                @add_child  (new BoundaryConditionItem name_temp, id_bc, @_dim)
                
                
    set_filter_edge: (edge_filter,bc_id)->
        @_parents[0]._parents[0].set_filter_edge(edge_filter, bc_id)
        @assign_edges_to_bcs()
        
    assign_edges_to_bcs: ->
        for bc in @_children
            for edge_filter in bc._children
                for edge in edge_filter._children
                    if parseInt(edge.bc_id) == -1
                        edge.bc_id.set bc._id