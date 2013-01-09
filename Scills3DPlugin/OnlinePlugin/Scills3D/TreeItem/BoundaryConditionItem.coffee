#
class BoundaryConditionItem extends TreeItem
    constructor: (name = "Boundary_condition", id_bc = 0) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/boundary_condition.png"
        @_viewable.set false

        # attributes
        @add_attr
            nb_edge_filters: 1
            alias: name
            _id: id_bc
            _info_ok: parseInt(0)
        
        @add_attr
            type: new Choice
            
        displacement_bc = new DisplacementBC
        normal_displacement_bc = new NormalDisplacementBC
        symetry_bc = new SymetrytBC
        speed_bc = new SpeedBC
        normal_speed_bc = new NormalSpeedBC
        stress_density_bc = new StressDensityBC
        normal_stress_density_bc = new NormalStressDensityBC
        
        @type.lst.push displacement_bc
        @type.lst.push normal_displacement_bc
        @type.lst.push symetry_bc
        @type.lst.push speed_bc
        @type.lst.push normal_speed_bc
        @type.lst.push stress_density_bc
        @type.lst.push normal_stress_density_bc
        
            
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
                
            if  @nb_edge_filters.has_been_modified()
                @change_collection()
    
    get_model_editor_parameters: ( res ) ->
       res.model_editor[ "type" ] = ModelEditorItem_ChoiceWithEditableItems
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    set_filter_edge: (edge_filter)->
        @_parents[0]._parents[0].set_filter_edge(edge_filter,@_id)
    
    ask_for_id_group: ->
        return @_parents[0]._parents[0].ask_for_id_group()
    
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @nb_edge_filters
            size_splice = @_children.length - @nb_edge_filters
            for num_c in [ @nb_edge_filters ... @_children.length ]
                @_children[num_c].clear()
            @_children.splice @nb_edge_filters, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_edge_filters ]
                id_group = @ask_for_id_group()
                name_temp = "Edge_Group_" + id_group.toString()
                @add_child  (new ScillsEdgeFilterItem name_temp, id_group)
    
    clear: ->
        @nb_edge_filters.set 0
    
    
    information: ( div ) ->
        if @_info_ok < 2
            @txt = new_dom_element
                  parentNode: div
            @txt.innerHTML = "
                  id : #{@_id} <br>
              "
            @_info_ok.set (parseInt(@_info_ok) + 1)