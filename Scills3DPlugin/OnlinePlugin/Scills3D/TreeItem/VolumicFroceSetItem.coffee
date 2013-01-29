#
class VolumicForceSetItem extends TreeItem
    constructor: ( dim = 3 ) ->
        super()
        
        # default values
        @_name.set "VolumicForce collection"
        @_ico.set "img/volumic_force_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            nb_loads: 0
            _dim: dim
            
        @bind =>
            if  @nb_loads.has_been_modified()
                @change_parameters()
                
    accept_child: ( ch ) ->
        ch instanceof VolumicForceItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    change_parameters: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @nb_loads
            size_splice = @_children.length - @nb_loads
            @_children.splice @nb_loads, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_loads ]
                name_temp = "F_" + num_c.toString()
                @add_child  (new VolumicForceItem name_temp, @_dim)