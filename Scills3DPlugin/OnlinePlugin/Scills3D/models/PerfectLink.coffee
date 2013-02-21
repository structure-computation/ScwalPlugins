#
class PerfectLink extends Model
    constructor: ( ) ->
        super()

        # attributes
        @add_attr 
            _name: "perfect"
            _type_num: 0
            thickness: "0"
        
#         @add_attr
#             type_preload: new Choice
#         
#         link_thickness_attribute = new LinkThicknessAttribute
#         link_preload_attribute = new LinkPreloadAttribute
#         
#         @type_preload.lst.push link_thickness_attribute
#         @type_preload.lst.push link_preload_attribute
#     
#     get_model_editor_parameters: ( res ) ->
#        res.model_editor[ "type_preload" ] = ModelEditorItem_ChoiceWithEditableItems
    
    toString: ->
        @_name.get()
    
    
    #cosmetic_attribute: ( name ) ->
    #    name in [ "elasticity" ]
    
    accept_child: ( ch ) ->
        #

    z_index: ->
        #
         
    sub_canvas_items: ->
        [ ]
    
        
    