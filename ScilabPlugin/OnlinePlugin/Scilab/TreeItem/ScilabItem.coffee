#
class ScilabItem extends TreeItem_Computable
    constructor: ( name = "Scilab" ) ->
        super()

        @add_attr
           cell_type    : new Choice( 0, [ "detectfaces", "filter : sobel" ] )
           # base_size    : 100
           # p_mesher     : new Lst

        
            
            
        @_name.set name
#         @_ico.set "img/scilab.png"
        @_viewable.set false
        @_computation_mode.set false
        
        
        #@add_child new ImgSetItem
        @add_output new ImgItem

        
    accept_child: ( ch ) ->
        ch instanceof ImgItem or
        ch instanceof FileItem
        
    
    z_index: ->
        #@_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh


