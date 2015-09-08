#
class SurfaceFunctionItem extends TreeItem
    constructor: ( name = "function(x,y)" ) ->
        super()

        @_name.set name
#         @_ico.set "img/plot3D.png"
        @_viewable.set true
        
        @add_attr
            f_z           : "x*y"
            x_bound       : [ -10, 10 ]
            y_bound       : [ -10, 10 ]
            nb_values     : new ConstrainedVal( 20, { min: 2, max: 50, div: 48 } )
            x_axe_bound   : [ -10, 10 ]
            y_axe_bound   : [ -10, 10 ]
            z_axe_bound   : [ -10, 10 ]
            x_axe_scale   : new ConstrainedVal( 30, { min: 1, max: 100, div: 99 } )
            y_axe_scale   : new ConstrainedVal( 30, { min: 1, max: 100, div: 99 } )
            z_axe_scale   : new ConstrainedVal( 1, { min: 1, max: 100, div: 99 } )
            
            _v1           : new Vec
            _v2           : new Vec
            _v3           : new Vec
            _v1_scale     : new Vec
            _v2_scale     : new Vec
            _v3_scale     : new Vec
            _mesh         : new Mesh( not_editable: true )
            _box          : new Mesh( not_editable: true )
             
          
        @add_attr  
            _visualization : @_mesh.visualization
            _field        : new NodalField @_mesh
          
        @add_attr
            _np           : new NamedParametrizedDrawable( "z_field", new InterpolatedField )
            field_set     : new FieldSet
          
        @field_set.color_by.lst.push @_np
        @field_set.warp_by.lst.push new NamedParametrizedDrawable "dep", new VectorialField "dep", [ @_np, @_np, @_np ] 
          
          
        @_visualization.display_style.num.set 1
        
        @bind =>
            if @f_z.has_been_modified() or @z_axe_scale.has_been_modified() or @z_axe_bound.has_been_modified() or @y_bound.has_been_modified() or @x_bound.has_been_modified() or @nb_values.has_been_modified() or @x_axe_bound.has_been_modified() or @y_axe_bound.has_been_modified() or @x_axe_scale.has_been_modified() or @y_axe_scale.has_been_modified()
              @make_mesh()
              @make_box()
                
    
    fill_v1_v2_v3: () ->
        @_v1.clear()
        @_v2.clear()
        @_v3.clear()
        @_v1_scale.clear()
        @_v2_scale.clear()
        @_v3_scale.clear()
        #alert @_f_t + " " + @_tmin + " " + @_tmax + " " + @nb_values
        
        for i in [ 0 ... @nb_values.get() ]
            @_v1.push 0
            @_v2.push 0
            @_v1_scale.push 0
            @_v2_scale.push 0
            @_v1[ i ].set (@x_bound[0].get() + i * (@x_bound[1].get() - @x_bound[0].get())/(@nb_values.get()-1))
            @_v2[ i ].set (@y_bound[0].get() + i * (@y_bound[1].get() - @y_bound[0].get())/(@nb_values.get()-1))
            for j in [ 0 ... @nb_values.get() ]
                @_v3.push 0
                @_v3_scale.push 0
                
         
        #alert @_v3
        for i in [ 0 ... @nb_values.get() ]
            for j in [ 0 ... @nb_values.get() ]
                x = @_v1[ i ]
                y = @_v2[ j ]
                str = "x=" + x + "; y=" + y + "; val_z = " + @f_z + ";"
                #alert str
                val_f = eval(str)
                #alert val_f
                #alert val_z
                #alert @_v3[ (i * @nb_values.get() + j) ]
                @_v3[ (i * @nb_values.get() + j) ].set val_z
        
        for i in [ 0 ... @nb_values.get() ]
            @_v1_scale[ i ].set (@_v1[ i ].get() * @x_axe_scale.get())
            @_v2_scale[ i ].set (@_v2[ i ].get() * @y_axe_scale.get())
            for j in [ 0 ... @nb_values.get() ]
                @_v3_scale[ (i * @nb_values.get() + j) ].set (@_v3[ (i * @nb_values.get() + j) ].get() * @z_axe_scale.get())
            
        #alert @_v3_scale
        
    make_box: ()->
        @_box.points.clear()
        @_box._elements.clear()
        
        if @x_axe_bound[0].get() > @x_bound[0].get()
          @x_axe_bound[0].set @x_bound[0].get()
        if @x_axe_bound[1].get() > @x_bound[1].get()
          @x_axe_bound[1].set @x_bound[1].get()
          
        if @y_axe_bound[0].get() > @y_bound[0].get()
          @y_axe_bound[0].set @y_bound[0].get()
        if @y_axe_bound[1].get() > @y_bound[1].get()
          @y_axe_bound[1].set @y_bound[1].get()
          
        for val in @_v3
          if @z_axe_bound[0].get() > val.get()
            @z_axe_bound[0].set val.get()
          if @z_axe_bound[1].get() < val.get()
            @z_axe_bound[1].set val.get()
            
        
        #bounding box
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), @z_axe_bound[ 0 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), @z_axe_bound[ 0 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), @z_axe_bound[ 0 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), @z_axe_bound[ 0 ].get()*@z_axe_scale.get() ]
        
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), @z_axe_bound[ 1 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), @z_axe_bound[ 1 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), @z_axe_bound[ 1 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), @z_axe_bound[ 1 ].get()*@z_axe_scale.get() ]
        
        @_box.add_element new Element_Line([0,1])
        @_box.add_element new Element_Line([1,2])
        @_box.add_element new Element_Line([2,3])
        @_box.add_element new Element_Line([3,0])
        
        @_box.add_element new Element_Line([4,5])
        @_box.add_element new Element_Line([5,6])
        @_box.add_element new Element_Line([6,7])
        @_box.add_element new Element_Line([7,4])
        
        @_box.add_element new Element_Line([0,4])
        @_box.add_element new Element_Line([1,5])
        @_box.add_element new Element_Line([2,6])
        @_box.add_element new Element_Line([3,7])
        
        #axes
        @_box.add_point [ @x_axe_bound[ 0 ].get()*@x_axe_scale.get(), 0, 0 ]
        @_box.add_point [ @x_axe_bound[ 1 ].get()*@x_axe_scale.get(), 0, 0 ]
        @_box.add_point [ 0, @y_axe_bound[ 0 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ 0, @y_axe_bound[ 1 ].get()*@y_axe_scale.get(), 0 ]
        @_box.add_point [ 0, 0, @z_axe_bound[ 0 ].get()*@z_axe_scale.get() ]
        @_box.add_point [ 0, 0, @z_axe_bound[ 1 ].get()*@z_axe_scale.get() ]
        
        @_box.add_element new Element_Line([8,9])
        @_box.add_element new Element_Line([10,11])
        @_box.add_element new Element_Line([12,13])
        
        
                
    make_mesh: ()->
        @fill_v1_v2_v3()
        @_mesh.points.clear()
        @_mesh._elements.clear()
        
        for i in [ 0 ... @nb_values.get() ]
            for j in [ 0 ... @nb_values.get() ]
                @_mesh.add_point [ @_v1_scale[ i ], @_v2_scale[ j ], @_v3_scale[ (i * @nb_values.get() + j) ] ]
        
        el = new Element_TriangleList
        el.indices.resize [ 3, (2*(@nb_values.get()-1)*(@nb_values.get()-1)) ]
        num_element = 0
        for i in [ 0 ... (@nb_values.get()-1) ]
            for j in [ 0 ... @nb_values.get()-1 ]
                pt_1 = i * @nb_values.get() + j
                pt_2 = i * @nb_values.get() + (j+1)
                pt_3 = (i+1) * @nb_values.get() + j
                pt_4 = (i+1) * @nb_values.get() + (j+1)
                
                el.indices.set_val [ 0, num_element ], pt_1
                el.indices.set_val [ 1, num_element ], pt_3
                el.indices.set_val [ 2, num_element ], pt_2
                
                num_element += 1
                
                el.indices.set_val [ 0, num_element ], pt_4
                el.indices.set_val [ 1, num_element ], pt_2
                el.indices.set_val [ 2, num_element ], pt_3
                
                num_element += 1

        #@_mesh._elements.set el.indices
        @_mesh.add_element el
        
        delete @_field
        @_field = new NodalField @_mesh
        
        pos = new Lst
        pos_v = { axe_name: "time", axe_value: 0 }
        pos.push pos_v
        
        @_np.data._data.clear()
        @_np.data._data.push 
            pos : pos
            field : @_field
        
#         @_np.data = @_field
        
        for i in [ 0 ... @_mesh.nb_points() ]
            @_field._data.set_val i, @_mesh.points[i].pos[2].get()
            
#         console.log @_np.drawing_parameters
    
    
    cosmetic_attribute: ( name ) ->
        super( name ) or ( name in [ "_mesh", "_field", "_np", "_visualization" ] )
    
    accept_child: ( ch ) ->
        
        
    sub_canvas_items: ->
        [ @_box, @field_set]
    #    if @nothing_to_do()
    #        [ @_mesh ]
    #    else
    #        []
    
    
    z_index: ->
        @_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

