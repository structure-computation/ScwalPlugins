#
class ComputationParametersItem extends TreeItem
    constructor: (name = "ComputationParameters" ) ->
        super()
        
        # default values
        @_name.set name
#         @_ico.set "img/computation_parameters.png"
        @_viewable.set false
        @add_child new LatinParamItem
        @add_child new TimeParamItem
        @add_child new ParametricDataItem
        #@add_child new ParametricParamItem

        # attributes
    