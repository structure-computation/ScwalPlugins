#
class CsvReaderItem extends TreeItem_Computable
    constructor: (name = "CsvReader" ) ->
        # TreeItem_Computable initialization
        super()
        @_name.set name
        @_ico.set "img/csvReader.png"
        @_viewable.set false

        # attributes
        @add_attr
            orientation: new Choice(1,["byRow","byColumn"])
            values_separator: new Choice(1,[",",";"])
            has_headers: true
            _parameters: new ListParameterSetItem
            
        # outputs
        @add_output this._parameters
        
        #alert "New CsvReaderItem created"
        
    
    accept_child: ( ch ) ->
        ch instanceof FileItem
    
    z_index: ->
        #
    
    sub_canvas_items: ->
        []
    