class TestAllItem extends TreeItem_Computable
    constructor: (name = "test") ->
        super()
        
        # default values
        @_name.set name
        @_viewable.set false

        # attributes
        @add_attr
            
        @add_child new ImgDirectorySetItem