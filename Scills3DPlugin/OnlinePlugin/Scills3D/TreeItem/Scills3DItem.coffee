#
class Scills3DItem extends TreeItem_Computable
    constructor: (name = "Scills3D" ) ->
        super()

        @_name.set name
        @_ico.set "img/scills3D.png"
        @_viewable.set false
        #@add_child new ScultMeshItem "Assembly"
        @add_child new ScillsStructureItem
        @add_child new ComputationParametersItem
        @add_child new MaterialSetItem
        @add_child new LinkSetItem
        @add_child new BoundaryConditionSetItem 
        @add_child new ThermalLoadItem
        @add_child new VolumicForceSetItem
        
        
        # attributes
        @add_attr
            compute_scills: false
            nb_proc: 1
            estimated_time: 0
            nb_tokens: 0
            _compute_edges: false
            _compute_scills: false
    
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
        @_computation_mode.set true
        
    set_compute_scills: ()->
        @_compute_edges.set false
        @_compute_scills.set true
        @_computation_mode.set true
        
        
        
        
        
        