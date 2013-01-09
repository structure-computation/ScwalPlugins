#
class ScillsStructureItem extends TreeItem
    constructor: (name = "Structure" ) ->
        super()

        @_name.set name
        @_ico.set "img/scills3D.png"
        @_viewable.set false
        #@add_child new ScultMeshItem "Assembly"
    
    accept_child: ( ch ) ->
        ch instanceof ScillsAssemblyItem
    
    # filtre des parts -------------------------------------------------------------------
    set_filter_part: (part_filter, mat_id)->
        if @_children[0]?
            @_children[0].filter_part(part_filter, mat_id)
            @_children[0].clear_material_id()
            
          
    # filtre des interfaces -------------------------------------------------------------------
    set_filter_interface: (interface_filter, link_id)->
        if @_children[0]?
            @_children[0].filter_interface(interface_filter, link_id)
            @_children[0].clear_link_id()
        
          