class TreeAppApplication_TestA extends TreeAppApplication
    constructor: ->
        super()
        
        @name = 'TestA application'
        @powered_with    = 'SC'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
            
        @actions.push
            ico: "img/test_bouton.png"
            siz: 1
            txt: "Tests"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                mesher = @add_item_depending_selected_tree app.data, TestAllItem
        
            key: [ "Shift+M" ]

        
            
