#
class InBoxEdgeFilter extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "in_box"
            point_1: [0,0,0]
            point_2: [0,0,0]
     
              
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
    
        
    