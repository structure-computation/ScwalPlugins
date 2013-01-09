#
class NormalSpeedBC extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "normal speed"
            _num_type: 4
            space_function: "0"
     
              
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
    
        
    