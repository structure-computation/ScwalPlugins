#
class ContactItem extends TreeItem
    constructor: ( name = "function(x,y)", id = 0 ) ->
        super()

        @_name.set name
#         @_ico.set "img/plot3D.png"
        @_viewable.set false
        
        @add_attr
          _id : id
          FirstName : name
          LastName : ""
          Title : ""
          email : ""
          phone_1 : ""
          phone_2 : ""
          Web_site : ""        

    accept_child: ( ch ) ->
        
        

