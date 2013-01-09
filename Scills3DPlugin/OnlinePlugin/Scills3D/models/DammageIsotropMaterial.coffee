#
class DammageIsotropMaterial extends Model
    constructor: ( ) ->
        super()
        
        # default values
        #@_name.set "isotropic plastic"
        #@_ico.set "img/material.png"
        #@_viewable.set false

        # attributes
        @add_attr  
            _name: "isotropic damageable"
            _type_num: 3
            _type_plast: 0
            _type_endo: 1
            generic:
              alpha: 1e-6
              density: 2000
            elasticity:
              E: 200000
              nu: 0.3
            dammage:
              Yo: 0
              dmax: 0
              bc: 0
              
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
    
        
    