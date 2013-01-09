#
class TimeParamItem extends TreeItem
    constructor: (name = "Time" ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/time.png"
        @_viewable.set false

        # attributes
        @add_attr
            type: new Choice( 0, [ "static", "quasistatic" ] )
            nb_steps: 0
            nb_paramaters: 1
            _incr_id_param:0
            
        @add_child new TemporalStepSetItem
        @add_child new TemporalParameterSetItem
        
        @bind =>
            if  @type.has_been_modified() or @nb_steps.has_been_modified() or @nb_paramaters.has_been_modified()
                @change_parameters()
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
    ask_for_id_param: ->
        id_param = parseInt(@_incr_id_param)
        @_incr_id_param.set (parseInt(@_incr_id_param) + 1)
        return id_param
    
    
    change_step_bounds: ->
        @_children[0].change_step_bounds()
        
    
    change_parameters: ->
        #alert @type
        if @type.toString()=="static"
            @nb_steps.set 0
            @nb_paramaters.set 0
 
        #modification du nombre de step
        size_splice = 0
        if @_children[0]._children.length > @nb_steps
            size_splice = @_children[0]._children.length - @nb_steps
            @_children[0]._children.splice @nb_steps, size_splice
            
        else 
            size_child0_child = @_children[0]._children.length
            for num_c in [ size_child0_child ... @nb_steps ]
                name_temp = "step_" + num_c.toString()
                @_children[0].add_child  (new TemporalStepItem name_temp, num_c)
                
        #mise à jour de bornes des step    
        @change_step_bounds()
        
        #modification du nombre de paramètre
        size_splice = 0
        if @_children[1]._children.length > @nb_paramaters
            size_splice = @_children[1]._children.length - @nb_paramaters
            @_children[1]._children.splice @nb_paramaters, size_splice
            
        else 
            size_child0_child = @_children[1]._children.length
            for num_c in [ size_child0_child ... @nb_paramaters ]
                id_param = @ask_for_id_param()
                name_temp = "PT_" + id_param.toString()
                @_children[1].add_child  (new TemporalParameterItem name_temp, id_param)
            
            # on remet à jour le nombre de fonction temporels en fonction du nombre de step   
            for num_param in [ 0 ... @nb_paramaters ] 
                size_splice_1 = 0
                if @_children[1]._children[num_param]._children.length > @nb_steps
                    size_splice_1 = @_children[1]._children[num_param]._children.length - @nb_steps
                    @_children[1]._children[num_param]._children.splice @nb_steps, size_splice_1
                    
                else 
                    size_child = @_children[0]._children[num_param]._children.length
                    for num_step in [ size_child ... @nb_steps ]
                        name_temp = "step_" + num_step.toString() + "_function"
                        bound0 = @_children[0]._children[num_step].initial_time
                        bound1 = @_children[0]._children[num_step].final_time
                        @_children[1]._children[num_param].add_child  (new Basic1DFunctionItem name_temp, num_step, "t", bound0, bound1)
                
            
        
