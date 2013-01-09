#
class LinkSetItem extends TreeItem
    constructor: ( ) ->
        super()
        
        # default values
        @_name.set "Link collection"
        @_ico.set "img/link_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            nb_links:0
            _incr_id_link:0
            _incr_id_group_inter:0
            
        @bind =>
            if  @nb_links.has_been_modified()
                @change_collection()
                
    accept_child: ( ch ) ->
        false

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    ask_for_id_group: ->
        id_group = parseInt(@_incr_id_group_inter)
        @_incr_id_group_inter.set (parseInt(@_incr_id_group_inter) + 1)
        return id_group
        
    ask_for_id_link: ->
        id_link = parseInt(@_incr_id_link)
        @_incr_id_link.set (parseInt(@_incr_id_link) + 1)
        return id_link
    
    change_collection: ->
        #modification du nombre de chargements
        size_splice = 0
        if @_children.length > @nb_links
            size_splice = @_children.length - @nb_links
            @_children.splice @nb_links, size_splice
            
        else 
            size_child0_child = @_children.length
            for num_c in [ size_child0_child ... @nb_links ]
                id_link = @ask_for_id_link()
                name_temp = "Link_" + id_link.toString()
                @add_child  (new ScillsLinkItem name_temp, id_link)
                
                
    set_filter_interface: (interface_filter,link_id)->
        @_parents[0]._parents[0].set_filter_interface(interface_filter, link_id)
        @assign_interfaces_to_links()
        
    assign_interfaces_to_links: ->
        for link in @_children
            for inter_filter in link._children
                for inter in inter_filter._children
                    if parseInt(inter.link_id) == -1
                        inter.link_id.set link._id
            