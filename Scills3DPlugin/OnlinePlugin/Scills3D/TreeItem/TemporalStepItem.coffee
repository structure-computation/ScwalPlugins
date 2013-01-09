#
class TemporalStepItem extends TreeItem
    constructor: (name = "TemporalStep" ,id_step=-1) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/temporal_step.png"
        @_viewable.set false

        # attributes
        @add_attr
            _id: id_step
            initial_time: 0
            final_time: 1
            time_step: 1
            nb_steps: 1
            
        @bind =>
            if  @time_step.has_been_modified() or @nb_step.has_been_modified()
                @_parents[0]._parents[0].change_step_bounds()
    
    accept_child: ( ch ) ->
        false

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
        
