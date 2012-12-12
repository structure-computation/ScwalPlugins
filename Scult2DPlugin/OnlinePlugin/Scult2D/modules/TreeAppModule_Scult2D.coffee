class TreeAppModule_Scult2D extends TreeAppModule
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Scult2D'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
                
        @actions.push
            ico: "img/scult2D.png"
            siz: 1
            txt: "SCult 2d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, Scult2DItem
                
        
