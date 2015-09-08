#
class PieFunctionItem extends TreeItem
    constructor: ( name = "function(x)" ) ->
        super()

        @_name.set name
#         @_ico.set "img/plot2D.png"
        @_viewable.set true
        
        @add_attr
            val1   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
            val2   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
            val3   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
            val4   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
            val5   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
            val6   : new ConstrainedVal( 5, { min: 1, max: 100, div: 99 } )
         
                
    display_suppl_context_actions: ( context_action )  ->
        instance = this               
        context_action.push
            txt: "link"
            ico: "img/graph_icon.png"
            fun: ( evt, app ) =>
                container_global = new_dom_element
                    id        : "id_graph_container"
                    style     :
                        #height     : 30
                        #width      : "100%"
                        #border     : "1px solid blue"
                        #background : "#ffffff"
                        position: "absolute"
                        left    : 10
                        right   : 10
                        top     : 40
                        bottom  : 10
                        
                inst = undefined
                for inst_i in app.selected_canvas_inst()
                    inst = inst_i
                
                
                if (inst.divCanvas)?
                  Ptop   = @getTop( inst.div )  
                  Pleft  = @getLeft( inst.div )  
                  Pwidth = inst.divCanvas.offsetWidth
                  Pheight = inst.divCanvas.offsetHeight
                  Pheight = Pheight + 22
                
                else
                  Ptop   = 100
                  Pleft  = 100
                  Pwidth = 800 
                  Pheight = 500 
                
#                 
                p = new_popup "My graph", event: evt, no_popup_closer: true, child: container_global, background:"#ffffff", top_x: Pleft, top_y: Ptop, width: Pwidth, height: Pheight, onclose: =>
                    @onPopupClose( app )
                app.active_key.set false
                
                data = new Lst 
                data.push instance.val1
                data.push instance.val2
                data.push instance.val3
                data.push instance.val4
                data.push instance.val5
                data.push instance.val6
                
                data_name = new Lst 
                data_name.push "val1"
                data_name.push "val2"
                data_name.push "val3"
                data_name.push "val4"
                data_name.push "val5"
                data_name.push "val6"
                
                
                graph_view = new GooglePieChartView container_global, data, data_name
    
    # obtenir la position réelle dans le canvas
    getLeft: ( l ) ->
      if l.offsetParent?
          return l.offsetLeft + @getLeft( l.offsetParent )
      else
          return l.offsetLeft

    # obtenir la position réelle dans le canvas
    getTop: ( l ) ->
        if l.offsetParent?
            return l.offsetTop + @getTop( l.offsetParent )
        else
            return l.offsetTop
          
    # fermer la popup    
    onPopupClose: ( app ) =>
        document.onkeydown = undefined
        app.active_key.set true
        
    
    accept_child: ( ch ) ->
        
        
    disp_only_in_model_editor: ->
#         @mesh

