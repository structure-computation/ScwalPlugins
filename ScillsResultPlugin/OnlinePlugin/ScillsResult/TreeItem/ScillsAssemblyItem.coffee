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
            compute_interfaces: true
            compute_edges: false
            _path: new Path
            _path_loaded: false
    
    accept_child: ( ch ) ->
        #false
        ch instanceof ScillsPartSetItem or 
        ch instanceof ScillsInterfaceSetItem or
        ch instanceof ScillsEdgeSetItem or
        ch instanceof FileItem
    
    #cosmetic_attribute: ( name ) ->
    #    super( name ) or ( name in [ "_mesh", "visualization" ] )    
    
    sub_canvas_items: ->
         []
    
    #z_index: ->
    #    @_mesh.z_index()
     