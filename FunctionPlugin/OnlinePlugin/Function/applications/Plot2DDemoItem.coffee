class Plot2DDemoItem extends TreeItem
    constructor: (name = 'plot 3D')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'Structure Computation'
            stamp: "img/Plot.png"
            txt: "Plot2D"
            demo_app : "Plot2DDemoItem"
            demo_directory : "__demo_plot2D__"
            archive_directory : "__archive_plot2D__"
            

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_Plot3D
        apps.push new TreeAppApplication_Plot2D
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        a = app.add_item_depending_selected_tree app_data, TFunctionItem
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
