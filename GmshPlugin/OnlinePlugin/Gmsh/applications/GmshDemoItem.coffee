class GmshDemoItem extends TreeItem
    constructor: (name = 'Image correlation')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'GMSH'
            stamp: "img/gmsh.png"
            txt: "Gmsh"
            demo_app : "GmshDemoItem"
            directory : "Gmsh"
            video_link : undefined
            publication_link : undefined

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_Mesher
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        b = app.add_item_depending_selected_tree app_data, GmshItem
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
