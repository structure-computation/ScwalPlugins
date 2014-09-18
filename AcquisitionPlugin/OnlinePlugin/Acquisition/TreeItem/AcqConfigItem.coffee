#
class AcqConfigItem extends TreeItem
    constructor: ( name = "Configuration" ) ->
        super()

        # default values
        @_name.set name
#         @_ico.set "img/results_16.png"
        @_viewable.set false
                
        @add_attr
            _incr_AcqData:1
            _nb_AcqData:1

        @add_child new AcqDataItem

        
#         @bind =>
#             if  @_nb_AcqData.has_been_modified() or @_children.has_been_modified()
#                 @_parents[0]._parents[0].update_AcqDataViewItems()
    
    display_suppl_context_actions: ( context_action )  ->
        context_action.push 
            txt: "Mise à jour des grandeurs"
            ico: "img/update.png"
            fun: ( evt, app ) =>
                #alert "add material"
                for path in app.data.selected_tree_items
                    if path.length > 1
                        m = path[ path.length - 1 ]
                        if m instanceof AcqConfigItem
                            @_parents[0]._parents[0].update_AcqDataViewItems()
    
    accept_child: ( ch ) ->
        ch instanceof AcqDataItem
        

    z_index: ->
        #could call z_index() of child
    
    sub_canvas_items: ->
        [  ]
    