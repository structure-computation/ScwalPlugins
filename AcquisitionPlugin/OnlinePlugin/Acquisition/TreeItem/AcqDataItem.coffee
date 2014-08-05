#
class AcqDataItem extends TreeItem
	constructor: ( name = "Q1" ) ->
		super()

		# default values
		@_name.set name
# 		@_ico.set "img/results_16.png"
		@_viewable.set false
				
		@add_attr
			real_name: "Grandeur"
			unity : "m"
			min: 0
			max:1024
			offset:0
			gain:1
			line_color       : new Color 0, 0, 0
			line_width       : new ConstrainedVal( 1, { min: 0, max: 20 } )
			shadow           : false
			show_marker      : true
			marker           : new Choice( 0, [ "dot", "square", "cross", "diamond", "bar" ] )
			marker_size      : new ConstrainedVal( 5, { min: 0, max: 40 } )
			marker_color     : new Color 0, 0, 0


				


	display_suppl_context_actions: ( context_action )  ->
            context_action.push 
                txt: "Nouvelle grandeur"
                ico: "img/add.png"
                fun: ( evt, app ) =>
                        #alert "add material"
                        for path in app.data.selected_tree_items
                                if path.length > 1
                                        m = path[ path.length - 1 ]
                                        if m instanceof AcqDataItem
                                                copyItem = new AcqDataItem
                                                incr_AcqData=parseInt(@_parents[0]._parents[0]._incr_AcqData)+1
                                                nb_AcqData=parseInt(@_parents[0]._parents[0]._nb_AcqData)+1
                                                
                                                copyItem._name.set("Q"+incr_AcqData.toString())
                                                @_parents[0]._parents[0].add_child copyItem
                                                @_parents[0]._parents[0]._nb_AcqData.set(nb_AcqData.toString())
                                                @_parents[0]._parents[0]._incr_AcqData.set(incr_AcqData.toString())
            
            context_action.push 
                txt: "Suppression de la grandeur"
                ico: "img/remove.png"
                fun: ( evt, app ) =>
                        #alert "add material"
                        for path in app.data.selected_tree_items
                                if path.length > 1
                                        m = path[ path.length - 1 ]
                                        if m instanceof AcqDataItem 
                                                nb_AcqData=parseInt(@_parents[0]._parents[0]._nb_AcqData)
                                                if nb_AcqData isnt 1
                                                        app.undo_manager.snapshot()
                                                        path[ path.length - 2 ].rem_child m
                                                        app.data.delete_from_tree m
                                                        #app.data.selected_tree_items.clear()
                                                        nb_AcqData=nb_AcqData-1
                                                        @_parents[0]._parents[0]._nb_AcqData.set(nb_AcqData.toString())
                                                        app.data.selected_tree_items path[ path.length - 1 ]
                                                        
                                                        
	z_index: ->
		#could call z_index() of child
	
	sub_canvas_items: ->
		[  ]
	

