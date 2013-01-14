class TreeAppModule_PdbReader extends TreeAppModule
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Pdb'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
            
        @actions.push
            ico: "img/unv2D.png"
            siz: 1
            txt: "pdb reader"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, PdbReaderItem
                
                
        
