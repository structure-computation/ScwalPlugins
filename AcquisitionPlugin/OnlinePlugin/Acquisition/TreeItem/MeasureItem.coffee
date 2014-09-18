#
class MeasureItem extends TreeItem
	constructor: ( name = "Mesure_" , nb_curvs = 1) ->
		super()

		# default values
		@_name.set name+@gethms()
# 		@_ico.set "img/results_16.png"
		@_viewable.set true
				
		@add_attr
			visualization: new FieldSet
			time : new TimeAcqItem
			#measured_data: new ViewDataAcq
			_incr_nb_measures:1
			_nb_curvs:nb_curvs
			_points: new Lst

		@add_context_actions
			txt: "Suppression de la mesure"
			ico: "img/remove.png"
			fun: ( evt, app ) =>
				#alert "add material"
				for path in app.data.selected_tree_items
					if path.length > 1
						m = path[ path.length - 1 ]
						nb_measures=@_parents[0]._parents[0]._nb_measures
						if m instanceof MeasureItem and nb_measures isnt 1
							app.undo_manager.snapshot()
							path[ path.length - 2 ].rem_child m
							app.data.delete_from_tree m
							@_parents[0]._parents[0]._nb_measures=@_parents[0]._parents[0]._nb_measures-1
							#app.data.selected_tree_items.clear()
							app.data.selected_tree_items path[ path.length - 1 ]
							
		@add_context_actions
			txt: "Nouvelle mesure"
			ico: "img/add.png"
			fun: ( evt, app ) =>
				#alert "add material"
				for path in app.data.selected_tree_items
					if path.length > 1
						m = path[ path.length - 1 ]
						if m instanceof MeasureItem
							copyItem = new MeasureItem "Mesure_", @_parents[0]._parents[0]._lst_AcqData.length
							@_parents[0]._parents[0].add_child copyItem
							@_parents[0]._parents[0]._nb_measures=@_parents[0]._parents[0]._nb_measures+1
							@_parents[0]._parents[0].update_AcqDataViewItems()
							@init()

				
	accept_child: ( ch ) ->
		ch instanceof AcqDataViewItem


	z_index: ->
		#could call z_index() of child
	
	sub_canvas_items: ->
		[  ]

	draw: ( info ) ->
		draw_point = info.sel_item[ @model_id ]
		if draw_point
			for pm in @_children
					@_children.draw info
 		
	gethms: ->
		cur_time = new Date
		h=cur_time.getHours()
		min=cur_time.getMinutes()
		sec=cur_time.getSeconds()
		if h<10
			h = "0" + h
		if min<10
			min = "0" + min
		if sec<10
			sec = "0" + sec
		hms=h+":"+min+":"+sec
		return hms

	init: ->
		@_points.clear()
		for num in [0 .. @_nb_curvs-1]
			lst_points = new Lst_Point
			@_points.push lst_points