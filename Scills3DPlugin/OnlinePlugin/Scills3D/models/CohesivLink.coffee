#
class CohesivLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "cohesiv"
            _type_num: 5
            thickness: "0"
            normal_rigidity : "2000"
            tangent_rigidity : "2000"
            compression_rigidity : "2000"
            Fc_n : "1000"
            Fc_t : "1000"
            friction : "0.3"
            Yo:"0"
            Yc:"0"
            alpha:"0"
            gamma:"0"
            n:"0"
     
              
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
    
        
    