#
class ScillsPartSetItem extends TreeItem
    constructor: ( @app_data, @panel_id ) ->
        super()
        
        # default values
        @_name.set "Part collection"
        @_ico.set "img/part_collection.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            _part_profile: new ScillsPartItem 
            _mesh_profile: new Mesh
            
        @add_attr
            visualization: @_mesh_profile.visualization
        
        @bind =>
           if  @visualization.has_been_modified()
               @visualisation_part_set()
           
        #@add_output new ScillsSetFilterItem
        #@_output[0].add_child new ScillsSetItem @_name, @_ico
        
        #@bind =>
        #    if  @_output[0].filter? and @_output[0].filter.has_been_modified()
        #        @filter_part_set()
        
    accept_child: ( ch ) ->
        ch instanceof ScillsPartItem 

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    visualisation_part_set: ()->
        for part in @_children
            part.visualization.display_style.num.set @visualization.display_style.num.get()
    
    get_part: (id_part)->
        for part in @_children
            if parseInt(part.id) == parseInt(id_part)
                return part
                break
    
    clear_material_id: ->
        for part in @_children
            part.material_id.set parseInt(-1)
            part.group_id.set parseInt(-1)
    
    filter_part: (part_filter, mat_id)->
        if part_filter._children.lenght != 0 
            for part in part_filter._children
                part.material_id.set parseInt(-1)
                part.group_id.set parseInt(-1)
            part_filter._children.clear() 
            
        #alert  part_filter.type
        #alert  (part_filter.type.toString() == "by id")
        if part_filter.type.toString() == "all"  
            for part in @_children
                if parseInt(part.material_id) == -1 or parseInt(part.material_id) == parseInt(mat_id) # test if part is already assigned
                    part_filter.add_child  part
                    part.material_id.set parseInt(mat_id)
                    part.group_id.set parseInt(part_filter._id)
   
        else if part_filter.type.toString() == "by name" 
            if part_filter.filter.toString().match('[\*]') 
                filter = part_filter.filter.toString().substring(0, part_filter.filter.toString().length-1)
                for part in @_children
                    if part._name.toString().match(filter.toString())
                        part_filter.add_child  part
                        part.material_id.set parseInt(mat_id)
                        part.group_id.set parseInt(part_filter._id)     
            else
                filter = part_filter.filter.toString()
                for part in @_children
                    if part._name.toString() == filter.toString()
                        part_filter.add_child  part
                        part.material_id.set parseInt(mat_id)
                        part.group_id.set parseInt(part_filter._id)   
       
   
        else if part_filter.type.toString() == "by id"  
            group = part_filter.filter.toString().split(",")
            
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
                            for part in @_children
                                if part.id >= piece_id[0] and part.id <= piece_id[1]
                                    if parseInt(part.material_id) == -1 or parseInt(part.material_id) == parseInt(mat_id) # test if part is already assigned
                                        part_filter.add_child  part
                                        part.material_id.set parseInt(mat_id)
                                        part.group_id.set parseInt(part_filter._id)
                        else if range.length==1
                            piece_id[0] = parseFloat(range[0]) + modulo
                            for part in @_children
                                if part.id == piece_id[0]
                                    if parseInt(part.material_id) == -1 or parseInt(part.material_id) == parseInt(mat_id) # test if part is already assigned
                                        part_filter.add_child  part
                                        part.material_id.set parseInt(mat_id)
                                        part.group_id.set parseInt(part_filter._id)
                        modulo += modulo_id
                        if (parseFloat(range[0]) + modulo) > @_children.length
                            out = false
                            break
                            
                else if group_modulo.length==1
                    range = group_modulo[0].split("-")
                    piece_id = []
                    if range.length==2
                        piece_id[0] = parseFloat(range[0])
                        piece_id[1] = parseFloat(range[1])
                        for part in @_children
                            if part.id >= piece_id[0] and part.id <= piece_id[1]
                                if parseInt(part.material_id) == -1  or parseInt(part.material_id) == parseInt(mat_id)# test if part is already assigned
                                    part_filter.add_child  part
                                    part.material_id.set parseInt(mat_id)
                                    part.group_id.set parseInt(part_filter._id)
                    else if range.length==1
                        piece_id[0] = parseFloat(range[0])
                        for part in @_children
                            if parseInt(part.id) == piece_id[0]
                                if parseInt(part.material_id) == -1 or parseInt(part.material_id) == parseInt(mat_id)# test if part is already assigned
                                    part_filter.add_child  part
                                    part.material_id.set parseInt(mat_id)
                                    part.group_id.set parseInt(part_filter._id)
    
    