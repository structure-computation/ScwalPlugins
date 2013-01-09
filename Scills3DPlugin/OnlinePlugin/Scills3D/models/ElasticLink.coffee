#
class ElasticLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "elastic"
            _type_num: 1
            thickness: "0"
            normal_rigidity : "2000"
            tangent_rigidity : "2000"
            compression_rigidity : "2000"
     
              
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
    
        
    