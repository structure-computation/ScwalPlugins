#
class VariableParameterItem extends TreeItem
    constructor: (name = "VariableParameter" ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/variable_parameter.png"
        @_viewable.set false

        # attributes
        @add_attr
            nominal_value: 0
            min_value: 0
            max_value: 1
            nb_values: 1
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
