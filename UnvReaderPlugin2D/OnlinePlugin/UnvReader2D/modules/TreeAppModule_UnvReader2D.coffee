class TreeAppModule_UnvReader2D extends TreeAppModule
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Unv2D'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
            
        @actions.push
            ico: "img/unvReader.png"
            siz: 1
            txt: "unv reader 2d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, UnvReaderItem2D
                
        
