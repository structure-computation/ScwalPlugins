class TreeAppModule_Scills3D extends TreeAppModule
    constructor: ->
        super()
         
        @name = 'Scills3D'
        
        @actions.push
            ico: "img/scills3D.png"
            txt: "Scills3D"
            siz: 1
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                #@add_ass app.data
                m = @add_item_depending_selected_tree app.data, Scills3DItem
        