class TreeAppApplication_Pie extends TreeAppApplication
    constructor: ->
        super()
        
        @unvreader = ''
        @name = 'Pie'

        _ina = ( app ) =>
            app.data.focus.get() != app.selected_canvas_inst()?[ 0 ]?.cm.view_id
            
        @actions.push
            ico: "img/pie_bouton.png"
            siz: 1
            txt: "répartition camenbert"
            ina: _ina
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @unvreader = @add_item_depending_selected_tree app.data, PieFunctionItem