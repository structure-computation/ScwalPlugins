#
class Basic1DFunctionItem extends TreeItem
    constructor: ( name = "function(x)", name_var, bound0=-10, bound1=10 ) ->
        super()

        @_name.set name
        @_ico.set "img/plot2D.png"
        @_viewable.set true
        
        @add_attr
            v_name  : name_var
            your_function : name_var
            bound       : [ bound0, bound1 ]
          
        
                
    

