#
class PdbReaderItem extends TreeItem_Computable
    constructor: ( name = "reader_pdb" ) ->
        super()
        @_name.set name
        @_ico.set "img/unv2D.png"
        @_viewable.set false
        
        @add_output new SketchItem
        
    accept_child: ( ch ) ->
        ch instanceof FileItem
        
    sub_canvas_items: ->
        []
    
    z_index: ->
        #@_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

