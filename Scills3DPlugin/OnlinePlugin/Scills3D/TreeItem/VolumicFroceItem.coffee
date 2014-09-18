#
class VolumicForceItem extends TreeItem
    constructor: (name = "VolumicForce", dim = 3 ) ->
        super()
        
        # default values 
        @_name.set name
#         @_ico.set "img/volumic_force.png"
        @_viewable.set false

        # attributes
        @add_attr
            alias: name
            gamma: "2"
            _dim: dim
        
        if (parseInt(@_dim) == 3)
            @add_attr 
                space_function: ["0","0","-1"]
        else 
            @add_attr 
                space_function: ["0","-1"]
        
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
        
            
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
