# Copyright 2012 Structure Computation  www.structure-computation.com
# Copyright 2015 Jérémie Bellec



#
class GooglePieChartView extends View
    constructor: ( @el, @mydata, @mydata_name, params = {} ) ->  
        super @mydata
        
        @nb_try = 0
        @is_loaded = false
        @icon_container = new_dom_element
            nodeName  : "div"
            parentNode: @el
        
        options = 
            packages: ['corechart']
            callback : @myCallback
        google.load('visualization', '1', options)
        
            

    drawChart: ()->
        if google.visualization?
#             console.log "drawChart"

            if @mydata.has_been_directly_modified  
                data = new google.visualization.DataTable()
                data.addColumn 'string', 'Test'
                data.addColumn 'number', 'Partition'

                data_rows = []
                for j in  [ 0 ... @mydata.length ]
                    data_rows_line = [@mydata_name[j].get(), @mydata[j].get() ]
                    data_rows.push  data_rows_line
                    
                data.addRows(data_rows )  
                
                
                #Pie chart
                options =
                    title: "test camenbert"
                    width: @el.offsetWidth
                    height: @el.offsetHeight
                    pieHole: 0.4
#                     is3D: true
                   
                
                
                chart = new google.visualization.PieChart @el 
                chart.draw data, options
#                 
                
     

    onchange: ->
#           options = 
#               packages: ['corechart','line']
#               callback : @myCallback
#           google.load('visualization', '1', options)

          google.setOnLoadCallback @drawChart()
#           if google.visualization?
#               @is_loaded = true
#               console.log "onchange"
#               
#               setTimeout(@drawChart(), 3000);
              
              
    sleep:(milliSeconds) ->
        startTime = new Date().getTime()
        while (new Date().getTime() < startTime + milliSeconds)
            #do_nothing
            ""

    myCallback: ->
#         console.log "myCallback"
    
    drawChart_0: ()->
        @is_loaded = true
        console.log "is_loaded"
        setTimeout(@drawChart(), 3000);
        

    
            
            
            
            