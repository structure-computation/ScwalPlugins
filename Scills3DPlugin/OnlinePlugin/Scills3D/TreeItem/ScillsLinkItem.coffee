#
class ScillsLinkItem extends TreeItem
    constructor: (name = "Link", id_link = 0) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/link.png"
        @_viewable.set false

        # attributes
        @add_attr
            _nb_link_filters: 1
            alias: name
            _id: id_link
            _info_ok: parseInt(0)
         
        @add_attr
            type: new Choice
        
        perfect_link = new PerfectLink
        perfect_breakable_link = new PerfectBreakableLink
        contact_link = new ContactLink
        elastic_link = new ElasticLink
        elastic_breakable_link = new ElasticBreakableLink
        cohesive_link = new CohesivLink
       
        @type.lst.push perfect_link
        @type.lst.push perfect_breakable_link
        @type.lst.push contact_link
        @type.lst.push elastic_link
        @type.lst.push elastic_breakable_link
        @type.lst.push cohesive_link
        
        @add_context_actions
            txt: "add link filter"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                #alert "add material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_link_filters.set(item._nb_link_filters.get() + 1)
                    
        @add_context_actions
            txt: "remove link filter"
            ico: "img/remove.png"
            fun: ( evt, app ) =>
                #alert "remove material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_link_filters.set(item._nb_link_filters.get() - 1) if item._nb_link_filters.get() > 0
            
        @bind =>
            if  @alias.has_been_modified()
                @_name.set @alias
                
            if  @_nb_link_filters.has_been_modified()
                @change_collection()
    
    get_model_editor_parameters: ( res ) ->
       res.model_editor[ "type" ] = ModelEditorItem_ChoiceWithEditableItems
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    set_filter_interface: (interface_filter)->
        @_parents[0]._parents[0].set_filter_interface(interface_filter,@_id)
        
    ask_for_id_group: ->
        return @_parents[0]._parents[0].ask_for_id_group()
    
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @_nb_link_filters
            size_splice = @_children.length - @_nb_link_filters
            @_children.splice @_nb_link_filters, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @_nb_link_filters ]
                id_group = @ask_for_id_group()
                name_temp = "Inter_Group_" + id_group.toString()
                @add_child  (new ScillsInterFilterItem name_temp, id_group)
                
    information: ( div ) ->
        if @_info_ok < 2
            @txt = new_dom_element
                  parentNode: div
            @txt.innerHTML = "
                  id : #{@_id} <br>
              "
            @_info_ok.set (parseInt(@_info_ok) + 1)
            
            