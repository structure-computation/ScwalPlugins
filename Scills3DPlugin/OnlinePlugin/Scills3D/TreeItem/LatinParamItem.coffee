#
class LatinParamItem extends TreeItem
    constructor: (name = "Latin" ) ->
        super()
        
        # default values
        @_name.set name
#         @_ico.set "img/latin_parameters.png"
        @_viewable.set false
        #@add_child new VariableParameterSetItem
        #@add_child new TemporalStepSetItem

        # attributes
        @add_attr
            max_iteration: new ConstrainedVal( 100, { min: 50, max: 300, div: 250 } )
            convergence_rate: new ConstrainedVal( 0.00001, { min: 0.00001, max: 0.001, div: 99 } )
            multiscale: new Bool true
    