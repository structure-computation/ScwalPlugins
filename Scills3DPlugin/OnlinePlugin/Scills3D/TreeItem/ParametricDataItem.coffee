#
class ParametricDataItem extends TreeItem
    constructor: (name = "Parametric data" ) ->
        super()
        
        # default values
        @_name.set name
        #@_ico.set "img/time.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            type: new Choice( 0, [ "off", "sequential" ] )
            nb_resolutions: new ConstrainedVal 0
            nb_parameters: 0
            _incr_id_param: 1
            _old_children: []
            _max_resolutions: 100
        
        @add_context_actions
            txt: "Add List"
            ico: "img/addlist.png"
            key: [ "" ]
            loc: true
            fun: ( evt, app ) =>
                for path_item in app.data.selected_tree_items
                    item = path_item[ path_item.length - 1 ]
                    #alert "calling #{item._name}.new_list_parameter()"
                    item.new_list_parameter()
                    
        @add_context_actions
            txt: "Add Function"
            ico: "img/addfunction.png"
            key: [ "" ]
            loc: true
            fun: ( evt, app ) =>
                for path_item in app.data.selected_tree_items
                    item = path_item[ path_item.length - 1 ]
                    #alert "calling #{item._name}.new_func_parameter()"
                    item.new_function_parameter()
        
        @bind =>
            if  @type.has_been_modified() or @nb_parameters.has_been_modified()
                @update_parameters()
            if @_children.has_been_modified()
                @check_child()
                @update_parameters()

    accept_child: ( ch ) ->
        ch instanceof ParametricListItem or
        #ch instanceof ParametricFunctionItem or
        ch instanceof ListParameterItem or
        ch instanceof ListParameterSetItem or
        ch instanceof Basic1DFunctionItem
    
    check_child: ->
        # Find last added child
        child
        #dbg = "_old_children :"
        #for ch in @_old_children
        #    dbg += " #{ch._name}"
        #dbg += "\n_children :"
        for ch in @_children
            #dbg += " #{ch._name}"
            if not (ch in @_old_children)
                child = ch
                break
        #if not child?
        #    alert "Last child added not found or already old one"
        #    alert dbg
        # Manage according to type
        if child instanceof TreeItem
            @_old_children.push child   # Mandatory
            #alert "using new_child on #{child._name}"
        if child instanceof ListParameterSetItem
            for sub_child in child._children
                @new_list_parameter(sub_child._name.get(),sub_child._values)
            @rem_this_child(child)
        else if child instanceof ListParameterItem
            @new_list_parameter(child._name.get(),child._values)
            @rem_this_child(child)
        #else if child instanceof ParametricListItem
        #
        #else if (child instanceof Basic1DFunctionItem) #or (child instanceof ParametricFunctionItem)
        #
    
    # remove 'child' (instance of TreeItem or index) from both _children and _old_children
    rem_this_child: ( child ) ->
        @rem_child(child)
        if child instanceof TreeItem
            for num_c in [ 0 ... @_old_children.length ]
                if @_old_children[ num_c ] == child
                    @_old_children.splice num_c, 1
                    return
        else
            @_old_children.splice child, 1

    z_index: ->
        #

    sub_canvas_items: ->
        [ ]

    ask_for_id_param: ->
        id_param = parseInt(@_incr_id_param)
        @_incr_id_param.set (parseInt(@_incr_id_param) + 1)
        return id_param

    update_parameters: ->
        @nb_parameters.set(@_children.length)
        #@update_max_resolutions()
        #alert @type
        if @type.toString()=="off"
            @nb_resolutions._min.set(0)
            @nb_resolutions._max.set(0)
            @nb_resolutions.val.set(0)
        else if @type.toString()=="sequential"
            @_max_resolutions.set(100)
            for child in @_children
                if child._name_class.get() == "ParametricListItem"
                    if child._size.get() < @_max_resolutions.get()
                        @_max_resolutions.set(child._values.length)
            @nb_resolutions._min.set(1)
            @nb_resolutions._max.set(@_max_resolutions.get())
            @nb_resolutions._div.set(@_max_resolutions.get() - 1)
            if @nb_resolutions.val.get() < @nb_resolutions._min.get()
                @nb_resolutions.val.set(@nb_resolutions._min.get())
            else if @nb_resolutions.val.get() > @nb_resolutions._max.get()
                @nb_resolutions.val.set(@nb_resolutions._max.get())
        else
            # Error management
            alert "Not implemented type : #{ @type.toString() }"
            if @_children.length() > 0
                @type.num.set(1)    # Return to "sequential" to prevent children erasement
            else
                @type.num.set(0)    # Return to "off" otherwise
    
    new_function_parameter: (name = "") ->
        id_param = @ask_for_id_param()
        if name == ""
            name = "PM_" + id_param.toString()
        param = new Basic1DFunctionItem name, id_param, "n", 0, @nb_resolutions.val.get()-1
        param._name_class.set("Basic1DFunctionItem")
        @add_child  param
        #@add_child new ParametricFunctionItem(name_temp, id_param, "n", 0, @nb_resolutions)
        
    
    new_list_parameter: (name = "",values = []) ->
        id_param = @ask_for_id_param()
        if name == ""
            name = "PM_" + id_param.toString()
        param = new ParametricListItem name, id_param, values
        param._name_class.set("ParametricListItem")
        @add_child param
        if param.length() < @_max_resolutions.get()
            alert "WARNING!\nParametric parameter #{param._name.get()} has only #{param.length()} values!\nMaximum number of resolutions will be constrained."
        
    update_max_resolutions: ->
        @_max_resolutions.set(100)
        for child in @_children
            if child._name_class.get() == "ParametricListItem"
                if child._size.get() < @_max_resolutions.get()
                    @_max_resolutions.set(child._values.length)
        #alert "min = #{@nb_resolutions._min.get()}\nmax = #{@nb_resolutions._max.get()}\ndiv = #{@nb_resolutions._div.get()}"
