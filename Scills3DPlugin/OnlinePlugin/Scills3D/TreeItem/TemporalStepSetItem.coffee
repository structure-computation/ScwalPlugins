#
class TemporalStepSetItem extends TreeItem
    constructor: ( ) ->
        super()
        
        # default values
        @_name.set "Temporal step collection"
        @_ico.set "img/temporal_step_collection.png"
        @_viewable.set false
        
    
    change_step_bounds: ->
        bound = 0
        for num_step in [ 0 ... @_children.length ]
            @_children[num_step].initial_time.set(  bound )
            initial_time = @_children[num_step].initial_time
            time_step = @_children[num_step].time_step
            nb_steps = @_children[num_step].nb_steps
            bound = initial_time.get() + time_step.get() * nb_steps.get()
            @_children[num_step].final_time.set(  bound )
            
        #@_parents[0]._parents[0].change_step_bounds()
    
    accept_child: ( ch ) ->
        ch instanceof TemporalStepItem

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    