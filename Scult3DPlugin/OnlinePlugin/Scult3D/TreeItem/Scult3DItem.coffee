#
class Scult3DItem extends TreeItem_Computable
    constructor: ( name = "Scult_3D" ) ->
        super()

        @_name.set name
        @_ico.set "img/scult3D.png"
        @_viewable.set true
        @add_attr
            hdf_output_name     : "output3D"
            _model_id           : SC_MODEL_ID
          
        @add_output new ScillsAssemblyItem
        #@_computation_mode.set true
        
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

