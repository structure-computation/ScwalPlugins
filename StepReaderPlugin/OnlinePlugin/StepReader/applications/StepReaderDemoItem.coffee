class StepReaderDemoItem extends TreeItem
    constructor: (name = 'ipol ACE')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'OpenCascade'
            stamp: "img/StepReader_demo.png"
            txt: "Step Reader"
            demo_app : "StepReaderDemoItem"
            directory : "StepReader"
            video_link : undefined
            publication_link : undefined
            

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_StepReader
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        a = app.add_item_depending_selected_tree app_data, StepReaderItem
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
