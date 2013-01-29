#
class ScillsMaterialItem extends TreeItem
    constructor: (name = "Material", id_mat = 0, dim = 3 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/material.png"
        @_viewable.set false

        # attributes
        @add_attr
            nb_part_filters: 0
            alias: name
            _id: id_mat
            _info_ok: parseInt(0)
            _dim: dim
        
        @add_attr
            type: new Choice
        
        elastic_isotrop_mat = new ElasticIsotropMaterial
        elastic_orthotrop_mat = new ElasticOrthotropMaterial @_dim
        plastic_isotrop_mat = new PlasticIsotropMaterial
        dammage_isotrop_mat = new DammageIsotropMaterial
        mesomodel_mat = new MesomodelMaterial @_dim
       
        @type.lst.push elastic_isotrop_mat
        @type.lst.push elastic_orthotrop_mat
        @type.lst.push plastic_isotrop_mat
        @type.lst.push dammage_isotrop_mat
        @type.lst.push mesomodel_mat
            
            
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
                
            if  @nb_part_filters.has_been_modified()
                @change_collection()
    
    get_model_editor_parameters: ( res ) ->
       res.model_editor[ "type" ] = ModelEditorItem_ChoiceWithEditableItems
    
    accept_child: ( ch ) ->
        ch instanceof ScillsPartFilterItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
   
    set_filter_part: (part_filter)->
        @_parents[0]._parents[0].set_filter_part(part_filter,@_id)
    
    ask_for_id_group: ->
        return @_parents[0]._parents[0].ask_for_id_group()
    
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @nb_part_filters
            size_splice = @_children.length - @nb_part_filters
            @_children.splice @nb_part_filters, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_part_filters ]
                id_group = @ask_for_id_group()
                name_temp = "Part_Group_" + id_group.toString()
                @add_child  (new ScillsPartFilterItem name_temp, id_group)
        
    information: ( div ) ->
        if @_info_ok < 2
            @txt = new_dom_element
                  parentNode: div
            @txt.innerHTML = "
                  id : #{@_id} <br>
              "
            @_info_ok.set (parseInt(@_info_ok) + 1)
        
    