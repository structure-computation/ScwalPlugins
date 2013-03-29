class LinkBreakableAttribute extends Model
    constructor: () ->
        super()
        
        @add_attr
            Fc_n: "0"
            Fc_t: "0"

#
class PerfectBreakableLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "perfect breakable"
            _type_num: 3
            thickness: "0"
            Fc_n: "0"
            Fc_t: "0"
            #breakable: new LinkBreakableAttribute # Test en cours pour factorisation
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
    
        
    