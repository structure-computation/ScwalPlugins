# Copyright 2012 Structure Computation  www.structure-computation.com
# Copyright 2015 Jérémie Bellec



#
class GoogleChartView extends View
    constructor: ( @el, @mydata, @mydata_name, params = {} ) ->  
        super @mydata
        
        @nb_try = 0
        @is_loaded = false
        @icon_container = new_dom_element
            nodeName  : "div"
            parentNode: @el
            

    drawChart: ()->
        if google.visualization?
#             console.log "drawChart"

            if @mydata.has_been_directly_modified  
                data = new google.visualization.DataTable()
                for i in [ 0 ... @mydata.length ]
                    data.addColumn 'number', @mydata_name[i].get()
                

                data_rows = []
                for j in  [ 0 ... @mydata[0].length ]
                    data_rows_line = []
                    for i in [ 0 ... @mydata.length ]
                        data_rows_line.push @mydata[i][j].get()
                    data_rows.push  data_rows_line
                    
                data.addRows(data_rows )  

                #area chart
#                 options =
#                     legend: 'none'
#                     curveType: 'function'
#                     pointSize: 7
#                     width: @el.offsetWidth
#                     height: @el.offsetHeight
#                 
#                 
#                 chart = new google.visualization.AreaChart @el #document.getElementById('id_graph_container')
#                 chart.draw data, options
                
                # point, scatter chart
#                 options =
#                     legend: 'none'
#                     curveType: 'function'
#                     pointSize: 7
#                     width: @el.offsetWidth
#                     height: @el.offsetHeight
#                 
#                 
#                 chart = new google.visualization.ScatterChart @el #document.getElementById('id_graph_container')
#                 chart.draw data, options
                
                
                #smooth line chart
                options =
                    legend: 'none'
                    curveType: 'function'
                    pointSize: 7
                    width: @el.offsetWidth
                    height: @el.offsetHeight
                
                
                chart = new google.visualization.LineChart @el #document.getElementById('id_graph_container')
                chart.draw data, options

                #column or histogram chart
#                 options = 
#                     title: "Density of Precious Metals, in g/cm^3"
#                     width: @el.offsetWidth
#                     height: @el.offsetHeight
#                     bar: {groupWidth: "95%"}
#                     legend: { position: "none" }
# 
#                 chart = new google.visualization.ColumnChart  @el #(document.getElementById("columnchart_values"));
#                 chart.draw data, options
#                 
                
     

    onchange: ->
          options = 
              packages: ['corechart','line']
              callback : @myCallback
          google.load('visualization', '1', options);
#         google.load('visualization', '1.1', {packages: ['line']})
#         console.log google.visualization
#           google.setOnLoadCallback @drawChart()
        
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
        

    
            
            
            
            