#
class PerfectLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "perfect"
            _type_num: 0
            thickness: "0"
     
              
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
    
        
    