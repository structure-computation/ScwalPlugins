class TreeAppModule_UnvReader3D extends TreeAppModule
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Unv3D'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
                
        @actions.push
            ico: "img/unv3D.png"
            siz: 1
            txt: "unv reader 3d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, UnvReaderItem3D
        
