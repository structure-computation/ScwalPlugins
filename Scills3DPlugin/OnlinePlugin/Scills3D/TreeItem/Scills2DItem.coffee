#
class Scills2DItem extends TreeItem_Computable
    constructor: (name = "Scills2D" ) ->
        super()

        @_name.set name
        @_ico.set "img/scills2D.png"
        @_viewable.set true
        
        # attributes
        @add_attr
            run_type  : new Choice( 0, [ "compute","check edge","check geometry" ] )
            nb_proc: 1
            estimated_time: 0
            nb_tokens: 0
            _compute_edges: false
            _compute_scills: false
            _dim: 2
            path_result: " "
            _path: new Path
            _path_zip: new Path
            visualization: new FieldSet
        
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
    
    accept_child: ( ch ) ->
        false
    
    set_filter_part: (part_filter, mat_id)->
        @_children[0].set_filter_part(part_filter, mat_id) 
        
    set_filter_interface: (interface_filter, link_id)->
        @_children[0].set_filter_interface(interface_filter, link_id) 
        
    download_result: ()-> 
#         window.open "/sceen/_?u=" + "/home/jbellec/code_dev_scwal/EcosystemScience/data.db/result_211037856"
        myWindow = window.open '',''
        myWindow.document.write "<a href='/sceen/_?u=" + @_path_zip._server_id + "'> Right click to save as </a>"
        myWindow.focus()
        
    sub_canvas_items: ->
        res = [@visualization]
        return res    
        
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "visualization" ] )    
        
        