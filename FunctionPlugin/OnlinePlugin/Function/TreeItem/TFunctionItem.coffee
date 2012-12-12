#
class TFunctionItem extends TreeItem
    constructor: ( name = "function(x)" ) ->
        super()

        @_name.set name
        @_ico.set "img/plot2D.png"
        @_viewable.set true
        
        @add_attr
            f_x           : "x*x"
            x_bound       : [ -10, 10 ]
            nb_values     : new ConstrainedVal( 20, { min: 2, max: 100, div: 98 } )
            x_axe_bound   : [ -10, 10 ]
            y_axe_bound   : [ -10, 10 ]
            x_axe_scale   : new ConstrainedVal( 1, { min: 1, max: 100, div: 99 } )
            y_axe_scale   : new ConstrainedVal( 1, { min: 1, max: 100, div: 99 } )
            
            _v1           : new Vec
            _v2           : new Vec
            _v1_scale     : new Vec
            _v2_scale     : new Vec
            _mesh         : new Mesh( not_editable: true )
            _box          : new Mesh( not_editable: true )
          
          
        @add_attr  
          visualization : @_mesh.visualization
          
        @visualization.display_style.num.set 1
        
        @bind =>
            if @f_x.has_been_modified() or @x_bound.has_been_modified() or @nb_values.has_been_modified() or @x_axe_bound.has_been_modified() or @y_axe_bound.has_been_modified() or @x_axe_scale.has_been_modified() or @y_axe_scale.has_been_modified()
              @make_mesh()
              @make_box()
                
    
    fill_v1_v2: () ->
        @_v1.clear()
        @_v2.clear()
        @_v1_scale.clear()
        @_v2_scale.clear()
        #alert @_f_x + " " + @_tmin + " " + @_tmax + " " + @nb_values
        
        for i in [ 0 ... @nb_values.get() ]
            @_v1.push 0
            @_v2.push 0
            @_v1_scale.push 0
            @_v2_scale.push 0
            @_v1[ i ].set (@x_bound[0].get() + i * (@x_bound[1].get() - @x_bound[0].get())/(@nb_values.get()-1))
         
        #alert @_v1
        for i in [ 0 ... @nb_values.get() ]
            x = @_v1[ i ]
            str = "x=" + x + "; val_y = " + @f_x + ";"
            val_f = eval(str)
            @_v2[ i ].set val_y
        #alert @_v2
        
        for i in [ 0 ... @nb_values.get() ]
            @_v1_scale[ i ].set (@_v1[ i ].get() * @x_axe_scale.get())
            @_v2_scale[ i ].set (@_v2[ i ].get() * @y_axe_scale.get())
            
        #alert @_v2_scale
        
    make_box: ()->
        @_box.points.clear()
        @_box._elements.clear()
        
        if @x_axe_bound[0].get() > @x_bound[0].get()
          @x_axe_bound[0].set @x_bound[0].get()
        if @x_axe_bound[1].get() > @x_bound[1].get()
          @x_axe_bound[1].set @x_bound[1].get()
          
        for val in @_v2
          if @y_axe_bound[0].get() > val.get()
            @y_axe_bound[0].set val.get()
          if @y_axe_bound[1].get() < val.get()
            @y_axe_bound[1].set val.get()
        
        #bounding box
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), 0 ]
        
        @_box.add_element new Element_Line([0,1])
        @_box.add_element new Element_Line([1,2])
        @_box.add_element new Element_Line([2,3])
        @_box.add_element new Element_Line([3,0])
        
        #axes
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), 0, 0 ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), 0, 0 ]
        @_box.add_point [ 0, @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ 0, @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), 0 ]
        
        @_box.add_element new Element_Line([4,5])
        @_box.add_element new Element_Line([6,7])
        
        
                
    make_mesh: ()->
        @fill_v1_v2()
        @_mesh.points.clear()
        @_mesh._elements.clear()
        
        for i in [ 0 ... @nb_values.get() ]
            @_mesh.add_point [ @_v1_scale[ i ], @_v2_scale[ i ], 0 ]
        
        for i in [ 0 ... (@nb_values.get()-1) ]
            liste = [i, i+1]
            bar = new Element_Line(liste)
            @_mesh.add_element bar
    
    
    
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "_mesh", "visualization" ] )
    
    accept_child: ( ch ) ->
        
        
    sub_canvas_items: ->
        [ @_mesh,  @_box]
    #    if @nothing_to_do()
    #        [ @_mesh ]
    #    else
    #        []
    
    #     draw: ( info ) ->
    #         draw_point = info.sel_item[ @model_id ]
    #         if @p_mesher.length && draw_point
    #             for pm in @p_mesher
    #                 pm.draw info
        #we may need to add @_mesh.draw info and remove it from sub_canvas_items
    
    z_index: ->
        @_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

