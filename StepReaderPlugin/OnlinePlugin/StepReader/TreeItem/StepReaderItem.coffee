#
class StepReaderItem extends TreeItem_Computable
    constructor: ( name = "StepReader" ) ->
        super()

        @_name.set name
#         @_ico.set "img/mesher.png"
        @_viewable.set false
        
        @_computation_mode.set false
        
        @add_output new MeshItem
        
        
    accept_child: ( ch ) ->
        ch instanceof FileItem
        
    sub_canvas_items: ->
        [  ]
