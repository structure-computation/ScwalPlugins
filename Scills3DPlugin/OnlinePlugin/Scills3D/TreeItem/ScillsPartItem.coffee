#
class ScillsPartItem extends TreeItem
    constructor: (name = "Part" ) ->
        super()
        
        # attributes    
        @add_attr
            _mesh        : new Mesh( not_editable: true )
            alias        : name
            
        @add_attr
            visualization: @_mesh.visualization
            id: -1 
            material_id: -1
         
        
        # default values
        @_name.set name
        @_ico.set "img/part.png"
        @_viewable.set true
        
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
    
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "_mesh", "visualization" ] )    
        
    accept_child: ( ch ) ->
      #

    z_index: ->
        @_mesh.z_index()
         
    sub_canvas_items: ->
        [@_mesh]
        
