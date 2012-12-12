class TreeAppModule_Scult3D extends TreeAppModule
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Scult3D'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
                
        @actions.push
            ico: "img/scult3D.png"
            siz: 1
            txt: "Scult 3d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, Scult3DItem
                
        
