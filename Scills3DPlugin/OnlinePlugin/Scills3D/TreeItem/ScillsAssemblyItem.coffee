#
class ScillsAssemblyItem extends TreeItem
    constructor: (name = "Assembly" ) ->
        super()

            
        # default values
        @_name.set name
        @_ico.set "img/assembly_15.png"
        @_viewable.set true
        @add_child new ScillsPartSetItem
        @add_child new ScillsInterfaceSetItem
        @add_child new ScillsEdgeSetItem
        
        # attributes
        @add_attr
            nb_parts: 0
            nb_interfaces: 0
            nb_edges: 0
            compute_parts: false
            compute_interfaces: false
            compute_edges: false
            _path: new Path
            _path_loaded: false
    
    accept_child: ( ch ) ->
        #false
        ch instanceof ScillsPartSetItem or 
        ch instanceof ScillsInterfaceSetItem or
        ch instanceof ScillsEdgeSetItem
    
    #cosmetic_attribute: ( name ) ->
    #    super( name ) or ( name in [ "_mesh", "visualization" ] )    
    
    sub_canvas_items: ->
         []
    
    #z_index: ->
    #    @_mesh.z_index()
     
    
    #work on parts--------------------------------------------------
    filter_part: (part_filter, mat_id)->
        if @_children[0]?
            @_children[0].filter_part(part_filter, mat_id)
        
    clear_material_id: ->
        if @_children[0]?
            @_children[0].clear_material_id()
            
    #work on interfaces--------------------------------------------------
    filter_interface: (inter_filter, link_id)->
        if @_children[1]?
            @_children[1].filter_interface(inter_filter, link_id, @_children[0])
        
    clear_link_id: ->
        if @_children[1]?
            @_children[1].clear_link_id()
            
    