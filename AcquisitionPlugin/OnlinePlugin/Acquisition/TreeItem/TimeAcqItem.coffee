# Copyright 2013 Structure Computation  www.structure-computation.com
# Copyright 2013 David Violeau
class TimeAcqItem extends TreeItem
    constructor: ( ) ->
        super()
        
        # attributes
        @add_attr
            time_length: new ConstrainedVal( 5, { min: 0, max: 100, div: 100 } )
            description : "description du systeme optionnelle"
          
        
        # default values
        @_name.set "Time"
#         @_ico.set "img/view-presentation.png"
        
        
    accept_child: ( ch ) ->
        #

    z_index: ->
        1
        
    sub_canvas_items: ->
        [ ]

    #     has_nothing_to_draw: ->
    #         true
