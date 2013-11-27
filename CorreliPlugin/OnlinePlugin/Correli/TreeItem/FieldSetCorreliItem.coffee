#
class FieldSetCorreliItem extends TreeItem
    constructor: ( name = "Field", id_c = 0 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/part_collection.png"
        @_viewable.set true
        
        # attributes
        @add_attr
            id : id_c
            visualization: new FieldSet
            # results
            _norm_i_history       : []
            _norm_2_history       : []
            _residual_history     : []
            
            _residual_adv         : new NamedParametrizedDrawable( "Residual adv"    , new InterpolatedField )
            _residual             : new NamedParametrizedDrawable( "Residual"        , new InterpolatedField )
            _residual_int_adv     : new NamedParametrizedDrawable( "Residual int adv", new InterpolatedField )
            _residual_int         : new NamedParametrizedDrawable( "Residual int"    , new InterpolatedField )
        
   
    accept_child: ( ch ) ->
        false
    
    sub_canvas_items: ->
        res = [@visualization]
        return res
        
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "visualization", "_residual", "_residual_adv", "_residual_int", "_residual_int_adv", "_norm_i_history", "_norm_2_history", "_residual_history" ] )
   
    information: ( div ) ->
        if not @txt?
            @txt = new_dom_element
                parentNode: div
                
        @txt.innerHTML = @_norm_2_history.get()
   
   