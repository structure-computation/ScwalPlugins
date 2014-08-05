#
class Scult3DItem extends TreeItem_Computable
    constructor: ( name = "Scult_3D" ) ->
        super()

        @_name.set name
#         @_ico.set "img/scult3D.png"
        @_viewable.set false
        @add_attr
            run_type            : new Choice( 0, [ "load unv","visualize group" ] )
            hdf_output_name     : "output3D"
          
        @add_output new ScillsAssemblyItem
        #@_computation_mode.set true
        @add_output new VisuPartGroupItem
        @add_output new VisuInterfaceGroupItem
        
    accept_child: ( ch ) ->
        ch instanceof FileItem or
        ch instanceof MeshItem
        
    sub_canvas_items: ->
        []
    
    # filtre des parts -------------------------------------------------------------------
    set_filter_part: (part_filter, mat_id)->
        if @_output[0]?
            @_output[0].filter_part(part_filter, mat_id)
            @_output[0].clear_material_id()
    
    # filtre des interfaces -------------------------------------------------------------------
    set_filter_interface: (interface_filter, link_id)->
        if @_output[0]?
            @_output[0].filter_interface(interface_filter, link_id)
            @_output[0].clear_link_id()
            
    # filtre des edges -------------------------------------------------------------------
    set_filter_edge: (edge_filter, edge_id)->
        if @_output[0]?
            @_output[0].filter_edge(edge_filter, edge_id)
            @_output[0].clear_edge_id()
    
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

