#
class OnSphereEdgeFilter extends Model
    constructor: (dim = 3 ) ->
        super()

        # attributes
        @add_attr 
            _name: "on_sphere"
            _dim: dim
            radius: 0
            epsilon: new ConstrainedVal( 10, { min: 1, max: 100, div: 99 } )
            
        if (parseInt(@_dim) == 3)
            @add_attr 
                point: [0,0,0]
        else
            @add_attr 
                point: [0,0]
     
              
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
    
        
    