#
class ScillsInterFilterItem extends TreeItem
    constructor: ( name_group = "interface_filter", id_group=0 ) ->
        super()
        
        # default values
        @_name.set name_group
        @_ico.set "img/fleche_output.png"
        @_viewable.set false
         
        # attributes
        @add_attr
            name: @_name
            type: new Choice( 0, [ "by id", "between materials", "between groups" ] )
            filter: ""
            _id:id_group
            _info_ok: parseInt(0)
                  
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
        #1000
         
    sub_canvas_items: ->
        []#[child for child in @_children]
        
    information: ( div ) ->
        if @_info_ok < 2
            @txt = new_dom_element
                  parentNode: div
            @txt.innerHTML = "
                  id : #{@_id} <br>
              "
            @_info_ok.set (parseInt(@_info_ok) + 1)  