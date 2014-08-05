# Copyright 2013 Structure Computation  www.structure-computation.com
# Copyright 2013 David Violeau
class ViewDataAcq extends TreeItem
    constructor: () ->
        super()
        
        # attributes
        @add_attr
            position	: true
            speed       : true
            acceleration      : true
            
        # default values
        @_name.set "Grandeurs visualisables"
#         @_ico.set "img/view-presentation.png"
        
        
    accept_child: ( ch ) ->
        #

    z_index: ->
        1
        

    sub_canvas_items: ->
        []

    #     has_nothing_to_draw: ->
    #         true
