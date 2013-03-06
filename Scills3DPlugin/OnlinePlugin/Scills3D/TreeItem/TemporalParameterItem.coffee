#
class TemporalParameterItem extends TreeItem
    constructor: ( name_param = "Temporal parameter", id_param=-1 ) ->
        super()
        
        # default values
        @_name.set name_param
        @_ico.set "img/temporal_step_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            name: name_param
            id: id_param
        
        @bind =>
            if @name.has_been_modified()
                @_name.set @name.get()
    
    accept_child: ( ch ) ->
        ch instanceof Basic1DFunctionItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    