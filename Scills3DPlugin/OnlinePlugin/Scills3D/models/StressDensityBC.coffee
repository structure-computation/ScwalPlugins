#
class StressDensityBC extends Model
    constructor: ( dim = 3 ) ->
        super()

        # attributes
        @add_attr 
            _name: "Stress density"
            _num_type: 5
            _dim: dim
            
        if (parseInt(@_dim) == 3)
            @add_attr 
                space_function: ["0","0","0"]
        else
            @add_attr 
                space_function: ["0","0"]
     
              
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
    
        
    