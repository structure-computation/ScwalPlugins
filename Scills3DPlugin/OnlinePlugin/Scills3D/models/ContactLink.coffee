#
class ContactLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "contact"
            _type_num: 2
            thickness: "0"
            friction : "0.3"
     
              
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
    
        
    