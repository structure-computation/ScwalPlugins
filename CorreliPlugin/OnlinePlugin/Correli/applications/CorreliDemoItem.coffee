class CorreliDemoItem extends TreeItem
    constructor: (name = 'Image correlation')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'LMT Cachan'
            stamp: "img/Correli.png"
            txt: "Correli"
            demo_app : "CorreliDemoItem"
            directory : "Correli"
            video_link : undefined
            tutorial_link : '<iframe width="1100" height="1550" frameborder="0" style="border:0" id="pdfviewer" src="http://eikosim.com/PluginsManuals/CorreliPlugin_lmt.pdf">Preview not available in your browser.</iframe>'
            publication_link : undefined

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_Correlation
        apps.push new TreeAppApplication_Mesher
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        a = app.add_item_depending_selected_tree app_data, CorrelationItem
        b = app.add_item_depending_selected_tree app_data, GmshItem
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
                
    add_corr: ( app_data ) =>
        #
        m = @add_item_depending_selected_tree app_data, CorrelationItem
#         app_data.watch_item m
#         app_data.watch_item m._children[ 1 ]