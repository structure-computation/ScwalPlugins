#
class Scult2DItem extends TreeItem_Computable
    constructor: ( name = "Scult_2D" ) ->
        super()
        
        @_name.set name
        @_ico.set "img/scult2D.png"
        @_viewable.set true
        @add_attr
            hdf_output_name     : "output2D"
            _model_id           : model_id
        
        @add_output new ScillsAssemblyItem
        
       
    accept_child: ( ch ) ->
        ch instanceof FileItem
        
    sub_canvas_items: ->
        []
    
    #     draw: ( info ) ->
    #         draw_point = info.sel_item[ @model_id ]
    #         if @p_mesher.length && draw_point
    #             for pm in @p_mesher
    #                 pm.draw info
        #we may need to add @_mesh.draw info and remove it from sub_canvas_items
    
#     z_index: ->
#         @_mesh.z_index()
#         
#     disp_only_in_model_editor: ->
#         @mesh

