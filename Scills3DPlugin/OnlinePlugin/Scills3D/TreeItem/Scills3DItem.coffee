#
class Scills3DItem extends TreeItem_Computable
    constructor: (name = "Scills3D" ) ->
        super()

        @_name.set name
        @_ico.set "img/scills3D.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            compute_scills: false
            nb_proc: 1
            estimated_time: 0
            nb_tokens: 0
            _compute_edges: false
            _compute_scills: false
            _dim: 3
            path_result: " "
            _path: new Path
            _path_zip: new Path
        
        #@add_output new FieldItem
        
        @add_child new ScillsStructureItem
        @add_child new ComputationParametersItem
        @add_child new MaterialSetItem  @_dim
        @add_child new LinkSetItem
        @add_child new BoundaryConditionSetItem @_dim
        @add_child new ThermalLoadItem
        @add_child new VolumicForceSetItem @_dim
        
        @add_context_actions
            txt: "load result"
            ico: "img/upload-icone-4401-48.png"
            fun: ( evt, app ) =>
                #alert "add material"
                @download_result()
        
        @bind =>
            if  @compute_scills.has_been_modified()
                @set_compute_scills()
    
    accept_child: ( ch ) ->
        false
    
    set_filter_part: (part_filter, mat_id)->
        @_children[0].set_filter_part(part_filter, mat_id) 
        
    set_filter_interface: (interface_filter, link_id)->
        @_children[0].set_filter_interface(interface_filter, link_id) 
        
    set_filter_edge: (edge_filter,bc_id)->
        @_compute_scills.set false
        @_compute_edges.set true
        @do_it()
        
    set_compute_scills: ()->
        @_compute_edges.set false
        @_compute_scills.set true
        @do_it()
        
    download_result: ()-> 
#         window.open "/sceen/_?u=" + "/home/jbellec/code_dev_scwal/EcosystemScience/data.db/result_211037856"
        myWindow = window.open '',''
        myWindow.document.write "<a href='/sceen/_?u=" + @_path._server_id + "'> Right click to save as </a>"
        myWindow.focus()    
        
        
        
        