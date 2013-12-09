#
class CRMItem extends TreeItem
    constructor: ( name = "Contact_list" ) ->
        super()

        @_name.set name
        #@_ico.set "img/plot2D.png"
        @_viewable.set false
        
            
        @add_child new ContactCollectionItem "Prospect"
        @add_child new AccountCollectionItem "Account"
        @add_child new ContactCollectionItem "Contacs"
        @add_child new ContactCollectionItem "Acivity"
            
    accept_child: ( ch ) ->
        false