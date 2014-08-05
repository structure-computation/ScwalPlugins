#
class LatinComputationItem extends TreeItem
    constructor: (name = "LatinComputation" ) ->
        super()
        
        # default values
        @_name.set name
#         @_ico.set "img/latin_computation.png"
        @_viewable.set false
        @add_child new LatinParametersItem "Computation parameters"
        @add_child new MaterialAssignationItem
        @add_child new LinkAssignationItem
        @add_child new BoundaryConditionAssignationItem 

        # attributes
        @add_attr
            name: name 
            description: "description"
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
        
    sub_canvas_items: ->
        [ ]