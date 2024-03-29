#
class GmshItem extends TreeItem_Computable
    constructor: ( name = "Gmsh" ) ->
        super()
        
        @add_attr
            cell_type    : new Choice( 0, [ "Triangle 3", "Triangle 6", "Quad 4",  "Quad 8" ] )
            base_size    : 100
            p_mesher     : new Lst

        @_name.set name
#         @_ico.set "img/mesher.png"
        @_viewable.set false
        
        @_computation_mode.set false
        
        @add_output new MeshItem
        
    
    display_suppl_context_actions: ( context_action )  ->
        context_action.push  new TreeAppModule_Mesher
        context_action.push  new TreeAppModule_Sketch
        #context_action.push  new TreeAppModule_Transform
    
        
    add_point: ( p = new PointMesher ) ->
        if p instanceof PointMesher
            @p_mesher.push p            
    
    remove_point: ( p ) ->
        if p instanceof PointMesher
            ind = @p_mesher.indexOf p
            if ind != -1
                @p_mesher.splice ind, 1
            
        else if p isnt NaN # p is an indice
            @p_mesher.splice p, 1
        
    accept_child: ( ch ) ->
        ch instanceof MaskItem or 
        ch instanceof MesherItem or
        ch instanceof MeshItem or
        ch instanceof SketchItem or 
        ch instanceof ImgItem or
        ch instanceof TransformItem or
        ch instanceof FileItem
        
    sub_canvas_items: ->
        [  ]
#         if @nothing_to_do()
#             [ @_mesh ]
#         else
#             []
    
    draw: ( info ) ->
        draw_point = info.sel_item[ @model_id ]
        if @p_mesher.length && draw_point
            for pm in @p_mesher
                pm.draw info
        #we may need to add @_mesh.draw info and remove it from sub_canvas_items
    
#     z_index: ->
#         @_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

    get_movable_entities: ( res, info, pos, phase ) ->
        for pm in @p_mesher
            pm.get_movable_entities res, info, pos, phase
            
    on_mouse_down: ( cm, evt, pos, b ) ->
        for pm in @p_mesher
            pm.on_mouse_down cm, evt, pos, b
        return false
            
    on_mouse_move: ( cm, evt, pos, b, old ) ->
        for pm in @p_mesher
            pm.on_mouse_move cm, evt, pos, b, old
        return false
