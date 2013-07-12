#
class VisuInterfaceGroupItem extends TreeItem
    constructor: (name = "Visu_inter_group") ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/link.png"
        @_viewable.set false

        # attributes
        @add_attr
            _nb_link_filters: 1
            _info_ok: parseInt(0)
            _incr_id_group_inter: 0
            
        @add_attr
            nb_link_filters: @_nb_link_filters
        
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
            if  @_nb_link_filters.has_been_modified()
                @change_collection()
    
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    set_filter_interface: (interface_filter)->
        if @_parents[0]? and @_parents[0]._parents[0]?
            @_parents[0]._parents[0].set_filter_interface(interface_filter,-1)
        
    ask_for_id_group: ->
        id_group = parseInt(@_incr_id_group_inter)
        @_incr_id_group_inter.set (parseInt(@_incr_id_group_inter) + 1)
        return id_group
    
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
                
            
            