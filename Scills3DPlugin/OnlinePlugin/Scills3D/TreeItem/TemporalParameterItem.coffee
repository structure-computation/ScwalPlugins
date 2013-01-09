#
class TemporalParameterItem extends TreeItem
    constructor: ( name = "Temporal parameter", id_param=-1 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/temporal_step_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            _id: id_param
           
           
    accept_child: ( ch ) ->
        ch instanceof Basic1DFunctionItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    