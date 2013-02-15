#
class LinkPreloadAttribute extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr
            _name: "preload"
            _type_num: 2
            preload: "0"

              
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
    
        
    