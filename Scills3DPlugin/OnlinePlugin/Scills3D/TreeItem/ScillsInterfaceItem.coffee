#
class ScillsInterfaceItem extends TreeItem
    constructor: (name = "Interface" ) ->
        super()
        
        # default values
        @_name.set name
#         @_ico.set "img/interface.png"
        @_viewable.set true
        
        # attributes
        @add_attr
            _mesh        : new Mesh( not_editable: true )
            name        : @_name
            
        @add_attr
            visualization: @_mesh.visualization
            id: -1
            link_id: -1
            group_id: -1
 
       
    accept_child: ( ch ) ->
        #
        
    z_index: ->
        @_mesh.z_index()
    
    sub_canvas_items: ->
        [ @_mesh ]
