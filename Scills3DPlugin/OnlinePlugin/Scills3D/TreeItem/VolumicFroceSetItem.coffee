#
class VolumicForceSetItem extends TreeItem
    constructor: ( dim = 3 ) ->
        super()
        
        # default values
        @_name.set "VolumicForce collection"
#         @_ico.set "img/volumic_force_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            _nb_loads: 0
            _dim: dim
        
        @add_attr
            nb_loads: @_nb_loads
        
        @add_context_actions
            txt: "add force"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                #alert "add material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_loads.set(item._nb_loads.get() + 1)
                    
        @add_context_actions
            txt: "remove force"
            ico: "img/remove.png"
            fun: ( evt, app ) =>
                #alert "remove material"
                items = app.data.selected_tree_items
                for path_item in items
                    item = path_item[ path_item.length - 1 ]
                    item._nb_loads.set(item._nb_loads.get() - 1) if item._nb_loads.get() > 0
        
        @bind =>
            if  @_nb_loads.has_been_modified()
                @change_parameters()
                
    accept_child: ( ch ) ->
        ch instanceof VolumicForceItem
    
    change_parameters: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @_nb_loads
            size_splice = @_children.length - @_nb_loads
            @_children.splice @_nb_loads, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @_nb_loads ]
                name_temp = "F_" + num_c.toString()
                @add_child  (new VolumicForceItem name_temp, @_dim)