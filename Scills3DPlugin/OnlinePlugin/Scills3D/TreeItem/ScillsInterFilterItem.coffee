#
class ScillsInterFilterItem extends TreeItem
    constructor: ( name = "interface_filter", id_group=0 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/fleche_output.png"
        @_viewable.set false
         
        # attributes
        @add_attr
            type: new Choice( 0, [ "by id", "between materials" ] )
            filter: ""
            _id:id_group
                  
        @bind =>
            if  @type.has_been_modified() or @filter.has_been_modified()
                @set_filter_interface()
     
    
    set_filter_interface: ()->
        @_parents[0]._parents[0].set_filter_interface(this)     
     
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "filter"] )  
                
    accept_child: ( ch ) ->
        ch instanceof ScillsInterfaceItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
    