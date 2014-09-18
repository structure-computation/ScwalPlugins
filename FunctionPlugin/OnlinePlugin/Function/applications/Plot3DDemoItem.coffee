class Plot3DDemoItem extends TreeItem
    constructor: (name = 'plot 3D')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'Structure Computation'
            stamp: "img/Plot.png"
            txt: "Plot3D"
            demo_app : "Plot3DDemoItem"
            directory : "plot3D"
            video_link : undefined
            publication_link : undefined

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_Plot3D
        apps.push new TreeAppApplication_Plot2D
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        a = app.add_item_depending_selected_tree app_data, SurfaceFunctionItem
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
