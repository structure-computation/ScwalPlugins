#
class ScillsEdgeFilterItem extends TreeItem
    constructor: ( name = "edge_filter", id_group=0, dim = 3 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/fleche_output.png"
        @_viewable.set false
         
        # attributes
        @add_attr
            _id:id_group
            _dim: dim
            compute: false
            type: new Choice
           
           
        undefined_filter = new UndefinedEdgeFilter
        parametrized_filter = new ParametrizedEdgeFilter
        in_box_filter = new InBoxEdgeFilter  @_dim
        in_cylinder_filter = new InCylinderEdgeFilter @_dim
        in_sphere_filter = new InSphereEdgeFilter @_dim
        on_plan_filter = new OnPlanEdgeFilter @_dim
        on_disc_filter = new OnDiscEdgeFilter @_dim
        on_cylinder_filter = new OnCylinderEdgeFilter @_dim
        on_sphere_filter = new OnSphereEdgeFilter @_dim
        
        @type.lst.push undefined_filter
        @type.lst.push parametrized_filter
        @type.lst.push in_box_filter
        @type.lst.push in_cylinder_filter
        @type.lst.push in_sphere_filter
        @type.lst.push on_plan_filter
        @type.lst.push on_disc_filter
        @type.lst.push on_cylinder_filter
        @type.lst.push on_sphere_filter
        
        
        
        @bind =>
            if  @compute.has_been_modified()
                #if @compute.get() == true
                @set_filter_edge()
     
    get_model_editor_parameters: ( res ) ->
       res.model_editor[ "type" ] = ModelEditorItem_ChoiceWithEditableItems
       
       
    set_filter_edge: ()->
        @_parents[0]._parents[0].set_filter_edge(this) 
        #alert @type
        #alert @type.toString()
        #alert @type.item().filter
        #alert @type.lst[@type.num].filter
     
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "filter"] )  
                
    accept_child: ( ch ) ->
        ch instanceof ScillsEdgeItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
    clear: ->
        ch.clear() for ch in @_children
        @_children.clear()