#
class MesomodelMaterial extends Model
    constructor: ( ) ->
        super()
        
        # default values
        #@_name.set "mesomodel"
        #@_ico.set "img/material.png"
        #@_viewable.set false

        # attributes
        @add_attr  
            _name: "mesomodel"
            _type_num: 4
            _type_plast: "0"
            _type_endo: "0"
            main_directions:
              direction_1: [1, 0, 0]
              direction_2: [0, 1, 0]
              direction_3: [0, 0, 1]
            generic:
              alpha: ["1e-6", "1e-6", "1e-6"]
              density: "2000"
            elasticity:
              E: ["200000", "200000", "200000"]
              nu: ["0.3", "0.3", "0.3"]
              G: ["0", "0", "0"]
            dammage:
              Yo: "0"
              Yc: "0"
              Ycf: "0"
              dmax: "0"
              bc: "0"
              a: "0"
              tau: "0"
              
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
    
        
    