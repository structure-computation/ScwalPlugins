#
class VolumicForceItem extends TreeItem
    constructor: (name = "VolumicForce" ) ->
        super()
        
        # default values 
        @_name.set name
        @_ico.set "img/volumic_force.png"
        @_viewable.set false

        # attributes
        @add_attr
            alias: name
            gamma: "2"
            space_function: ["0","0","-1"]
        
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
        
            
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
