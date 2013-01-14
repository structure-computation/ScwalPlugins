class TreeAppModule_Scills3D extends TreeAppModule
    constructor: ->
        super()
         
        @name = 'Scills apps'
        
        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
        
        #scills application 3D
        @actions.push
            ico: "img/scills3D.png"
            txt: "Scills3D"
            ina: _ina
            siz: 1
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                #@add_ass app.data
                m = @add_item_depending_selected_tree app.data, Scills3DItem
    
        #scult application 2D
        @actions.push
            ico: "img/scult2D.png"
            siz: 1
            txt: "SCult 2d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, Scult2DItem
        
        #scult application 3D
        @actions.push
            ico: "img/scult3D.png"
            siz: 1
            txt: "Scult 3d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, Scult3DItem
                
        #unv reader application 2D        
        @actions.push
            ico: "img/unv2D.png"
            siz: 1
            txt: "unv reader 2d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, UnvReaderItem2D
        
        #unv reader application 3D   
        @actions.push
            ico: "img/unv3D.png"
            siz: 1
            txt: "unv reader 3d"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, UnvReaderItem3D
        