#
class ScilabItem extends TreeItem_Computable
    constructor: ( name = "Scilab" ) ->
        super()
        @add_attr
            _mesh        : new Mesh( not_editable: true )

        @add_attr
           cell_type    : new Choice( 0, [ "detectfaces", "filter : sobel" ] )
           visualization: @_mesh.visualization
           # base_size    : 100
           # p_mesher     : new Lst

        
            
            
        @_name.set name
        @_ico.set "img/scilab.png"
        @_viewable.set true
        
        @visualization.display_style.num.set 1
        @_computation_mode.set false
        
        
        @add_child new ImgSetItem
        
        
      

        
    accept_child: ( ch ) ->
        ch instanceof ImgItem or
        ch instanceof FileItem
        
    
    z_index: ->
        #@_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh


