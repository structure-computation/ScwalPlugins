#
class ParametricParamItem extends TreeItem
    constructor: (name = "Parametric" ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/time.png"
        @_viewable.set false

        # attributes
        @add_attr
            type: new Choice( 0, [ "off", "function" ] )
            nb_resolutions: 0
            nb_paramaters: 0
            _incr_id_param: 1
        
        @bind =>
            if  @type.has_been_modified() or @nb_paramaters.has_been_modified()
                @change_parameters()
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    ask_for_id_param: ->
        id_param = parseInt(@_incr_id_param)
        @_incr_id_param.set (parseInt(@_incr_id_param) + 1)
        return id_param
    
    change_parameters: ->
        #alert @type
        if @type.toString()=="off"
            @nb_resolutions.set 0
            @nb_paramaters.set 0
 
        #modification du nombre de paramètres
        size_splice = 0
        if @_children.length > @nb_paramaters
            size_splice = @_children.length - @nb_paramaters
            @_children.splice @nb_paramaters, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_paramaters ]
                id_param = @ask_for_id_param()
                name_temp = "PM_" + id_param.toString()
                @add_child  (new Basic1DFunctionItem name_temp, id_param, "n", 0, @nb_resolutions)
                