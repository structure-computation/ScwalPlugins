class ScillsDemoItem extends TreeItem
    constructor: (name = 'Scills demo')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'Structure Computation'
            stamp: "img/Scills3D.png"
            txt: "Scills"
            demo_app : "ScillsDemoItem"
            directory : "Scills"
            video_link : undefined
            publication_link : undefined

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_Mesher
        apps.push new TreeAppApplication_Scult2D
        apps.push new TreeAppApplication_Scult3D
        apps.push new TreeAppApplication_Scills2D
        apps.push new TreeAppApplication_Scills3D
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        b = app.add_item_depending_selected_tree app_data, Scult3DItem
        b = app.add_item_depending_selected_tree app_data, Scills3DItem
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
