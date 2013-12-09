#
class AccountItem extends TreeItem
    constructor: ( name = "Account_test", id = 0 ) ->
        super()

        @_name.set name
        #@_ico.set "img/plot2D.png"
        @_viewable.set false
        
        @add_attr
          name : "new account"
          description : "new account"
          
          
    
    accept_child: ( ch ) ->
        
    get_model_editor_parameters: ( res ) ->
       res.model_editor[ "description" ] = ModelEditorItem_TextArea   

