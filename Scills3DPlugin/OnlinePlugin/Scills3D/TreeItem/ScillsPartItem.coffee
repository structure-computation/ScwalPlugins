#
class ScillsPartItem extends TreeItem
    constructor: (name = "Part" ) ->
        super()
        
        # default values
        @_name.set name
#         @_ico.set "img/part.png"
        @_viewable.set true
        
        # attributes    
        @add_attr
            _mesh        : new Mesh( not_editable: true )
            name        : @_name
            
        @add_attr
            visualization: @_mesh.visualization
            id: -1 
            material_id: -1
            group_id: -1
         
    
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "_mesh", "visualization" ] )    
        
    accept_child: ( ch ) ->
      #

    z_index: ->
        @_mesh.z_index()
         
    sub_canvas_items: ->
        [@_mesh]
        
