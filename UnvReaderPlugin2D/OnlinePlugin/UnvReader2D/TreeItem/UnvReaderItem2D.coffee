#
class UnvReaderItem2D extends TreeItem_Computable
    constructor: ( name = "UnvReader_2D" ) ->
        super()
        @add_attr
            _mesh        : new Mesh( not_editable: true )

        @add_attr
            visualization: @_mesh.visualization
            cell_type    : new Choice( 0, [ "Triangle 3", "Triangle 6", "Quad 4",  "Quad 8" ] )
            compute    : 0
            id_model   : -1

        @_name.set name
        @_ico.set "img/unvReader.png"
        @_viewable.set true
        
        #@add_output new Mesh
        @visualization.display_style.num.set 1
        @_computation_mode.set true
        
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "_mesh", "visualization" ] )
        
    accept_child: ( ch ) ->
        ch instanceof FileItem
        
    sub_canvas_items: ->
        if @nothing_to_do()
            [ @_mesh ]
        else
            []
    
    #     draw: ( info ) ->
    #         draw_point = info.sel_item[ @model_id ]
    #         if @p_mesher.length && draw_point
    #             for pm in @p_mesher
    #                 pm.draw info
        #we may need to add @_mesh.draw info and remove it from sub_canvas_items
    
    z_index: ->
        @_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

