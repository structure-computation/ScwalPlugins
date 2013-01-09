#
class TemporalParameterSetItem extends TreeItem
    constructor: ( ) ->
        super()
        
        # default values
        @_name.set "Temporal parameter collection"
        @_ico.set "img/temporal_step_collection.png"
        @_viewable.set false
        
        # attributes
                
    accept_child: ( ch ) ->
        #ch instanceof TemporalParameterItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    