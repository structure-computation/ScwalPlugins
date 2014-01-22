#
class FieldsComparatorItem extends TreeItem_Computable
    constructor: (name = "FieldsComparator" ) ->
        super()

        @_name.set name
        #@_ico.set "img/scills3D.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            field_1 :
                time_step : 0
            field_2 :
                time_step : 0
            
        
        @add_output new FieldSetSetItem "Error fields"
        @_output[0]._collection_size.set(2)
        @_output[0].change_collection()
        @_output[0]._children[0]._name.set "Absolute error"
        @_output[0]._children[1]._name.set "Relative error"
    
    accept_child: ( ch ) ->
        ch instanceof FieldSetCorreliItem or
        ch instanceof FieldSetItem #and @__children.length < 2
    