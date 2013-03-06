#
class ListParameterItem extends TreeItem
constructor: (name = "ListParameter", values = [] ) ->
        # TreeItem initialization
        super()
        @_name.set name
        #@_ico.set "img/.png"
        @_viewable.set true

        # attributes
        @add_attr
            _values: values

    accept_child: ( ch ) ->
        #
    
    z_index: ->
        #

    sub_canvas_items: ->
        []

