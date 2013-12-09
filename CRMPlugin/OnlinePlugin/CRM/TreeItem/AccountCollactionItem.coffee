#
class AccountCollectionItem extends CollectionTreeItem
    constructor: ( name = "Contact_list" ) ->
        super()

        @_name.set name + "_list"
        #@_ico.set "img/plot2D.png"
        @_viewable.set false
        
        @add_attr
            _name : name
            
    accept_child: ( ch ) ->
        ch instanceof ContactItem
        
    add_collection_item: ->
        # function to overload 
        id_child = @ask_for_id_collection_child()
        name_temp = @_name + "_" + id_child.toString()
        @add_child  (new AccountItem name_temp, id_child)