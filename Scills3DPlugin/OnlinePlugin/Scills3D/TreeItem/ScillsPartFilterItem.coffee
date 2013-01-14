#
class ScillsPartFilterItem extends TreeItem
    constructor: ( name_group = "part_filter", id_group=0 ) ->
        super()
        
        # default values
        @_name.set name_group
        @_ico.set "img/fleche_output.png"
        @_viewable.set false
         
        # attributes
        @add_attr
            name: name_group
            type: new Choice( 0, [ "void","by id", "by name", "all" ] )
            filter: ""
            _id:id_group
            _info_ok: parseInt(0)
                  
        @bind =>
            if  @type.has_been_modified() or @filter.has_been_modified()
                @set_filter_part()
                
            if  @name.has_been_modified()
                @_name.set @name
     
    
    set_filter_part: ()->
        @_parents[0]._parents[0].set_filter_part(this)     
     
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "filter"] )  
                
    accept_child: ( ch ) ->
        ch instanceof ScillsPartItem

    z_index: ->
        #  
    sub_canvas_items: ->
        []
        #[items for items in @_children]
        
    information: ( div ) ->
        if @_info_ok < 2
            @txt = new_dom_element
                  parentNode: div
            @txt.innerHTML = "
                  id : #{@_id} <br>
              "
            @_info_ok.set (parseInt(@_info_ok) + 1)   