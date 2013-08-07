#
class AcquisitionItem extends TreeItem_Computable
    constructor: ( ) ->
        super()
        
        # default values
        @_name.set "Acquisition"
        #@_ico.set "img/imgAcq.png"
        @_viewable.set false
        
        # attributes
        @add_attr
            _nb_measures:1
            _incr_nb_measures:1
            _incr_id_group_part:0
            nb_measures: @_nb_measures
            _lst_AcqData: new Lst
                
        @add_child new AcqConfigItem
        @add_child new MeasureItem "Mesure_",1



    accept_child: ( ch ) ->
        ch instanceof AcqConfigItem or
        ch instanceof MeasureItem

    z_index: ->
        #
            
    sub_canvas_items: ->
        [ ]
        
        
    update_AcqDataViewItems: ->
        #mise a jour de la liste des AcqDataViewItems a partir de la config
        @_lst_AcqData.clear()
        for child in @_children
            if child instanceof AcqConfigItem
                for child_child in child._children
                    AcqDataView = new AcqDataViewItem 
                    AcqDataView.update(child_child)
                    @_lst_AcqData.push AcqDataView
        
        #copy des AcqDataViewItem a partir de la liste mise a jour
        for child in @_children
            if child instanceof MeasureItem
                #effacement des Items pour copie ensuite
                if child._children.length > 0
                    child._children.splice 0, child._children.length
                #copie des items
                for el in @_lst_AcqData
                    child.add_child el
                child._nb_curvs = @_lst_AcqData.length
                child.init()
                    
