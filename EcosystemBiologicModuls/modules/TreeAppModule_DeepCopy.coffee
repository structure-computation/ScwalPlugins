class TreeAppModule_DeepCopy extends TreeAppModule
    constructor: ->
        super()
         
        @name = 'deep_copy'
        
        @actions.push
            ico: "img/scills3D.png"
            txt: "deep_copy"
            siz: 1
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                #@add_ass app.data
                m = @add_item_depending_selected_tree app.data, DeepCopyItem
        