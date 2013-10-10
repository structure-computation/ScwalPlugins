#
class FieldSetSetItem extends CollectionTreeItem
    constructor: ( ) ->
        super()
        
        # default values
        @_name.set "Field collection"
        @_ico.set "img/part_collection.png"
        @_viewable.set false
        
        # attributes
           
   
    accept_child: ( ch ) ->
        ch instanceof FieldSetItem
    
    display_context_actions: ->
        contex_action = new Lst
        contex_action.push  new TreeAppAction_Save
        return contex_action
    
    add_collection_item: ->
        # function to overload 
        #alert "test"
        id_child = @ask_for_id_collection_child()
        name_temp = "field_" + id_child.toString()
        @add_child  (new FieldSetItem name_temp, id_child)
    