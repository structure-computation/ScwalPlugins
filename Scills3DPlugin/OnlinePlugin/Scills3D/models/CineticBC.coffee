#
class CineticBC extends Model
    constructor: (dim = 3) ->
        super()

        # attributes
        @add_attr 
            _point       : new Point
            _name: "cinetic torseur"
            _num_type: 0
            _dim: dim
            
        @add_attr
            point        : @_point
        
        if (parseInt(@_dim) == 3)
            @add_attr
                direction_0: [1,0,0]
                direction_1: [0,1,0]
                direction_2: [0,0,1]
                resultante: ["0","0","0"]
                moment: ["0","0","0"]
                imp_resultante: [0,0,0]
                imp_moment: [0,0,0]
        else 
            @add_attr 
                direction_0: [1,0]
                direction_1: [0,1]
                resultante: ["0","0"]
                moment: ["0","0"]
                imp_resultante: [0,0]
                imp_moment: [0,0]
     
              
    toString: ->
        @_name.get()
    
    #cosmetic_attribute: ( name ) ->
    #    name in [ "elasticity" ]
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        @_point.z_index()
         
    sub_canvas_items: ->
        [ @_point ]
    
        
    