#
class ListParameterSetItem extends TreeItem
    constructor: (name = "ListParameterSet") ->
        # TreeItem initialization
        super()
        @_name.set name
        #@_ico.set "img/.png"
        @_viewable.set true

    accept_child: ( ch ) ->
        ch instanceof ListParameterItem

    z_index: ->
        #

    sub_canvas_items: ->
        []

