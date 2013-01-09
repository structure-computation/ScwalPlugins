#
class SymetrytBC extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "symetry"
            _num_type: 2
            #space_function: 0
     
              
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
    
        
    