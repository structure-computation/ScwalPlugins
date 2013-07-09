#
class ScillsInterfaceSetItem extends TreeItem
    constructor: ( @app_data, @panel_id ) ->
        super()
        
        # default values
        @_name.set "Interface collection"
        @_ico.set "img/interface_collection.png"
        @_viewable.set false
        #@add_child new ScillsInterfaceItem
        
        # attributes
        @add_attr
            _interface_profile: new ScillsInterfaceItem 
                
    accept_child: ( ch ) ->
        ch instanceof ScillsInterfaceItem

    z_index: ->
        #
        
    sub_canvas_items: ->
        [ ]
    
    get_interface: (id_inter)->
        for inter in @_children
            if parseInt(inter.id) == parseInt(id_inter)
                return inter
                break
    
    clear_link_id: ->
        for inter in @_children
            inter.link_id.set parseInt(-1)
            inter.group_id.set parseInt(-1)
            
    filter_interface: (interface_filter, link_id, part_set)->
        if interface_filter._children.lenght != 0 
            for inter in interface_filter._children
                inter.link_id.set parseInt(-1)
                inter.group_id.set parseInt(-1)
            interface_filter._children.clear()
       
            
        #alert  interface_filter.type
        #alert  (interface_filter.type.toString() == "by id")
        if interface_filter.type.toString() == "by id"  
            group = interface_filter.filter.toString().split(",")
            
            #alert group.length
            for group_id in group
                group_modulo = group_id.split("%")
                #alert group_modulo.length
                if group_modulo.length==2
                    range = group_modulo[0].split("-")
                    modulo_id = parseInt(group_modulo[1])
                    modulo = 0
                    out = true
                    while out
                        piece_id = []
                        if range.length==2
                            piece_id[0] = parseFloat(range[0]) + modulo
                            piece_id[1] = parseFloat(range[1]) + modulo
                            for inter in @_children
                                if inter.id >= piece_id[0] and inter.id <= piece_id[1]
                                    if parseInt(inter.link_id) == -1 or parseInt(inter.link_id) == parseInt(link_id) # test if part is already assigned
                                        interface_filter.add_child  inter
                                        inter.link_id.set parseInt(link_id)
                                        inter.group_id.set parseInt(interface_filter._id)
                        else if range.length==1
                            piece_id[0] = parseFloat(range[0]) + modulo
                            for inter in @_children
                                if inter.id == piece_id[0]
                                    if parseInt(inter.link_id) == -1 or parseInt(inter.link_id) == parseInt(link_id) # test if part is already assigned
                                        interface_filter.add_child  inter
                                        inter.link_id.set parseInt(link_id)
                                        inter.group_id.set parseInt(interface_filter._id)
                        modulo += modulo_id
                        if (parseFloat(range[0]) + modulo) > @_children.length
                            #alert modulo
                            #alert parseFloat(piece_id[0]) + modulo
                            #alert @pieceViews.length
                            out = false
                            break
                            
                else if group_modulo.length==1
                    range = group_modulo[0].split("-")
                    piece_id = []
                    if range.length==2
                        piece_id[0] = parseFloat(range[0])
                        piece_id[1] = parseFloat(range[1])
                        for inter in @_children
                            if inter.id >= piece_id[0] and inter.id <= piece_id[1]
                                if parseInt(inter.link_id) == -1  or parseInt(inter.link_id) == parseInt(link_id)# test if part is already assigned
                                    interface_filter.add_child  inter
                                    inter.link_id.set parseInt(link_id)
                                    inter.group_id.set parseInt(interface_filter._id)
                    else if range.length==1
                        piece_id[0] = parseFloat(range[0])
                        for inter in @_children
                            if parseInt(inter.id) == piece_id[0]
                                if parseInt(inter.link_id) == -1 or parseInt(inter.link_id) == parseInt(link_id)# test if part is already assigned
                                    interface_filter.add_child  inter
                                    inter.link_id.set parseInt(link_id)
                                    inter.group_id.set parseInt(interface_filter._id)
                                    
                                    
        if interface_filter.type.toString() == "between materials"  
            group = interface_filter.filter.toString().split(",")
            
            if group.length==2
                for inter in @_children
                    #ids = inter.adj_num_group.split(' ')
                    piece1 = part_set.get_part(inter.group_elements_id[0])
                    piece2 = part_set.get_part(inter.group_elements_id[1])
                    materialIDs = [parseInt(piece1.material_id), parseInt(piece2.material_id)]
                    
                    if materialIDs.indexOf(parseInt(group[0])) != -1 and materialIDs.indexOf(parseInt(group[1])) != -1
                        # If firstID and secondID are the same (searching between an interface in contact with the same material)
                        # Then materialIDs have to be the same
                        if group[0] != group[1] or (materialIDs[0] == materialIDs[1])
                            interface_filter.add_child inter 
                            inter.link_id.set parseInt(link_id)
                            inter.group_id.set parseInt(interface_filter._id)
                            
        if interface_filter.type.toString() == "between groups"  
            group = interface_filter.filter.toString().split(",")
            
            if group.length==2
                for inter in @_children
                    #ids = inter.adj_num_group.split(' ')
                    piece1 = part_set.get_part(inter.group_elements_id[0])
                    piece2 = part_set.get_part(inter.group_elements_id[1])
                    materialIDs = [parseInt(piece1.group_id), parseInt(piece2.group_id)]
                    
                    if materialIDs.indexOf(parseInt(group[0])) != -1 and materialIDs.indexOf(parseInt(group[1])) != -1
                        # If firstID and secondID are the same (searching between an interface in contact with the same material)
                        # Then materialIDs have to be the same
                        if group[0] != group[1] or (materialIDs[0] == materialIDs[1])
                            interface_filter.add_child inter 
                            inter.group_id.set parseInt(interface_filter._id)
                            inter.link_id.set parseInt(link_id)