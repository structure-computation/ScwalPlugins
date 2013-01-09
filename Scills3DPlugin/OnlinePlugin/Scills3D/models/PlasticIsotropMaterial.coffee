#
class PlasticIsotropMaterial extends Model
    constructor: ( ) ->
        super()
        
        # default values
        #@_name.set "isotropic plastic"
        #@_ico.set "img/material.png"
        #@_viewable.set false

        # attributes
        @add_attr  
            _name: "isotropic plastic"
            _type_num: 2
            _type_plast: "1"
            _type_endo: "0"
            generic:
              alpha: "1e-6"
              density: "2000"
            elasticity:
              E: "200000"
              nu: "0.3"
            plasticity:
              R0: "0"
              Kp: "0"
              Mp: "0"
              C: "0"
              
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
    
        
    