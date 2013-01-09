#
class SpeedBC extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "Speed"
            _num_type: 3
            space_function: ["0","0","0"]
     
              
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
    
        
    