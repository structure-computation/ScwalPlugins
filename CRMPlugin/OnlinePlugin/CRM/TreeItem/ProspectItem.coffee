#
class ProspectItem extends TreeItem
    constructor: ( name = "Prospect" ) ->
        super()

        @_name.set name
        #@_ico.set "img/plot2D.png"
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
          
        
                
    

