#
class AcqDataViewItem extends TreeItem
	constructor: ( name = "Grandeur" ) ->
		super()

		# default values
		@_name.set name
# 		@_ico.set "img/results_16.png"
		@_viewable.set true
				
		@add_attr
			line_color       : new Color 0, 0, 0
			line_width       : new ConstrainedVal( 1, { min: 0, max: 20 } )
			shadow           : false
			show_marker      : true
			marker           : new Choice( 0, [ "dot", "square", "cross", "diamond", "bar" ] )
			marker_size      : new ConstrainedVal( 5, { min: 0, max: 40 } )
			marker_color     : new Color 0, 0, 0
			curv           : new Choice( 0, [ "cos", "sin" ] )
			_graph : new Graph 
				marker: 'dot',
				marker_color: "#f00"
				line_width  : 3,
				line_color: "#f00"
				marker_size: 10,
				font_size : 24,
				legend_x_division: 10,
				legend_y_division: 10,
				x_axis: 'temps (s)',
				y_axis: 'val'
		
		@_graph.marker = @marker
		@_graph.marker_color = @marker_color
		@_graph.line_width = @line_width
		@_graph.line_color = @line_color
		@_graph.marker_size = @marker_size
		
		@choose_curv()
		
	z_index: ->
		#could call z_index() of child
	
	sub_canvas_items: ->
		[ @_graph ]
	
	draw: ( info ) ->
		draw_point = info.sel_item[ @model_id ]
		if @_graph.points.length && draw_point
			for pm in @_graph.points
					pm.draw info

	choose_curv : ()->
		if  @curv is "cos"
				@curv_sinus 0.5,10
		else
				@curv_cosinus 0.5,10
		
					
	update: (item) ->
		@_name.set item.real_name.get()
		@line_color.set(item.line_color)
		@line_width.set(item.line_width.get())
		@shadow.set(item.shadow.get())
		@show_marker.set(item.show_marker.get())
		@marker.set(item.marker.get())
		@marker_size.set(item.marker_size.get())
		@marker_color.set(item.marker_color)

	curv_sinus: (omega = 1.0 ,ampl=1.0 ) ->
		nb_points=100
		Tmax=10.0
		@_graph.points.clear()
		for num in [0 .. nb_points-1]
			time=Tmax*(num/nb_points)
			@_graph.points.push [ time  , ampl*Math.sin(time*omega), 0 ]
					
	curv_cosinus: (omega = 1.0 ,ampl = 1.0) ->
		nb_points=100
		Tmax=10.0
		@_graph.points.clear()
		for num in [0 .. nb_points-1]
			time=Tmax*(num/nb_points)
			@_graph.points.push [ time  , ampl*Math.cos(time*omega), 0 ]
	