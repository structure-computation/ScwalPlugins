#
class DeepCopyItem extends TreeItem
    constructor: (name = "deep_copy" ) ->
        super()

        @_name.set name
        @_ico.set "img/deepCopy.png"
        @_viewable.set false
        
        
        # attributes
        @add_attr
            compute_copy: false
    
        @bind =>
            if  @compute_copy.has_been_modified() and @_children[0]?
                @set_copy()
    
    accept_child: ( ch ) ->
        true
    
    set_copy: ()->
        copy = @_children[0].deep_copy()
        copy._name.set (@_children[0]._name + "_copy")
        @_children.push copy
        
        
        
        
        
        
        