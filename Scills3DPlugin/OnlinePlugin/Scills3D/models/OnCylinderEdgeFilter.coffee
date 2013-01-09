#
class OnCylinderEdgeFilter extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "on_cylinder"
            point: [0,0,0]
            direction: [0,0,0]
            radius: 0
     
              
    toString: ->
        @_name.get()
    
    #cosmetic_attribute: ( name ) ->
    #    name in [ "elasticity" ]
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
        
    