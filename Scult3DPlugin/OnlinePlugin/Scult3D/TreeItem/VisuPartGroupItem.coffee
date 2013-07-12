#
class VisuPartGroupItem extends TreeItem
    constructor: (name = "Visu_part_group" ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/material.png"
        @_viewable.set false

        # attributes
        @add_attr
            _nb_part_filters: 1
            _info_ok: parseInt(0)
            _incr_id_group_part:0
            
        @add_attr
            nb_part_filters: @_nb_part_filters
        
         
        @add_context_actions
            txt: "add part filter"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                #alert "add material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_part_filters.set(item._nb_part_filters.get() + 1)
                    
        @add_context_actions
            txt: "remove part filter"
            ico: "img/remove.png"
            fun: ( evt, app ) =>
                #alert "remove material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_part_filters.set(item._nb_part_filters.get() - 1) if item._nb_part_filters.get() > 0
            
        @bind =>
            if  @_nb_part_filters.has_been_modified()
                @change_collection()
    
    
    accept_child: ( ch ) ->
        ch instanceof ScillsPartFilterItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
   
    set_filter_part: (part_filter)->
        if @_parents[0]? and @_parents[0]._parents[0]?
            @_parents[0]._parents[0].set_filter_part(part_filter,-1)
    
    ask_for_id_group: ->
        id_group = parseInt(@_incr_id_group_part)
        @_incr_id_group_part.set (parseInt(@_incr_id_group_part) + 1)
        return id_group
        
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @_nb_part_filters
            size_splice = @_children.length - @_nb_part_filters
            @_children.splice @_nb_part_filters, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @_nb_part_filters ]
                id_group = @ask_for_id_group()
                name_temp = "Part_Group_" + id_group.toString()
                @add_child  (new ScillsPartFilterItem name_temp, id_group)
        
        
    