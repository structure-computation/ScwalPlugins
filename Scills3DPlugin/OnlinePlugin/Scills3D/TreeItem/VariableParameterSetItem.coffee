#
class VariableParameterSetItem extends TreeItem
    constructor: ( @app_data, @panel_id ) ->
        super()
        
        # default values
        @_name.set "Variable parameter collection"
        @_ico.set "img/variable_parameter_collection.png"
        @_viewable.set false
        @add_child new VariableParameterItem
        @add_child new VariableParameterItem
        
        # attributes
        @add_attr
            variable_parameter_collection: new Lst
                
    accept_child: ( ch ) ->
        ch instanceof VariableParameterItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    