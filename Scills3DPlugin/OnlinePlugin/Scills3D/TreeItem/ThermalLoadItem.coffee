#
class ThermalLoadItem extends TreeItem
    constructor: (name = "ThermalLoad" ) ->
        super()
        
        # default values
        @_name.set name
        @_ico.set "img/thermal_load.png"
        @_viewable.set false

        # attributes
        @add_attr
            name: "name"
            thermal_function: "0"
    
    accept_child: ( ch ) ->
        false
        
