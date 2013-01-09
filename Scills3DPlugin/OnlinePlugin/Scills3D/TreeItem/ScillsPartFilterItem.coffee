#
class ScillsPartFilterItem extends TreeItem
    constructor: ( name = "part_filter", id_group=0 ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/fleche_output.png"
        @_viewable.set false
         
        # attributes
        @add_attr
            type: new Choice( 0, [ "void","by id", "by name" ] )
            filter: ""
            _id:id_group
                  
        @bind =>
            if  @type.has_been_modified() or @filter.has_been_modified()
                @set_filter_part()
     
    
    set_filter_part: ()->
        @_parents[0]._parents[0].set_filter_part(this)     
     
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "filter"] )  
                
    accept_child: ( ch ) ->
        ch instanceof ScillsPartItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        