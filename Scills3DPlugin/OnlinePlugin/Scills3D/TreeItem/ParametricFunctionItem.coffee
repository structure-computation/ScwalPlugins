# A function defining a "parametric" parameters
#class ParametricFunctionItem extends Basic1DFunctionItem
#    constructor: (name = "Parametric Function", id_func=-1, name_var = "n", bound0=-10, bound1=10 ) ->
#        # Basic1DFunctionItem initialization
#        super()
#        @_name.set         name
#        #@_ico.set         "img/time.png"
#        @_viewable.set     false
#        @_id.set           id_func
#        @v_name.set        name_var
#        @your_function.set name_var
#        @bound.set         [ bound0, bound1 ]
#
#        # attributes
#        @add_attr
#            _values: []
#
#    accept_child: ( ch ) ->
#        #
#
#    z_index: ->
#        #
#
#    sub_canvas_items: ->
#        [ ]