#
class Scills2DItem extends TreeItem_Computable
    constructor: (name = "Scills2D" ) ->
        super()

        @_name.set name
        @_ico.set "img/scills2D.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            compute_scills: false
            nb_proc: 1
            estimated_time: 0
            nb_tokens: 0
            _compute_edges: false
            _compute_scills: false
            _dim: 2
            path_result: " "
        
        #@add_output new FieldItem
        
        @add_child new ScillsStructureItem
        @add_child new ComputationParametersItem
        @add_child new MaterialSetItem  @_dim
        @add_child new LinkSetItem
        @add_child new BoundaryConditionSetItem @_dim
        @add_child new ThermalLoadItem
        @add_child new VolumicForceSetItem @_dim
        
        
        
    
        @bind =>
            if  @compute_scills.has_been_modified()
                @set_compute_scills()
    
    accept_child: ( ch ) ->
        false
    
    set_filter_part: (part_filter, mat_id)->
        @_children[0].set_filter_part(part_filter, mat_id) 
        
    set_filter_interface: (interface_filter, link_id)->
        @_children[0].set_filter_interface(interface_filter, link_id) 
        
    set_filter_edge: (edge_filter,bc_id)->
        @_compute_scills.set false
        @_compute_edges.set true
        @do_it()
        
    set_compute_scills: ()->
        @_compute_edges.set false
        @_compute_scills.set true
        @do_it()
        
        
        
        
        
        