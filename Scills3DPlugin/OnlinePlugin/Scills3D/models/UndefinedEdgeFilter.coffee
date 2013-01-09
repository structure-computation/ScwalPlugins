#
class UndefinedEdgeFilter extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "undefined"
     
              
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
    
        
    