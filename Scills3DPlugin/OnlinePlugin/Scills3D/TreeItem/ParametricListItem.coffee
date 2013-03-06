# A list of values defining a "parametric" parameters
class ParametricListItem extends TreeItem
    constructor: (name_param = "Parametric List", id_param = -1, values = [] ) ->
        # TreeItem initialization
        super()
        @_name.set     name_param
        #@_ico.set     "img/time.png"
        @_viewable.set false

        # attributes
        @add_attr
            _values: values
            _size: 0
            name: name_param
            id: id_param
        
        @bind =>
            if  @_values.has_been_modified()
                @_size.set(@length())
                #alert(@_size.get())
            if @name.has_been_modified()
                @_name.set @name.get()

    accept_child: ( ch ) ->
        #

    z_index: ->
        #

    sub_canvas_items: ->
        [ ]
    
    length: ->
        @_values.length