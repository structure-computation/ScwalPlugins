# Generate a check function to test file extension
# 'extensions' must be a list of strings (for multiple extensions as mesh files: ["unv","msh",...])
# Both standard and Soja types are accepted
# The generated function takes a FileItem as argument
check_file_extension = (extensions) ->
    check_function = (file) =>
        filename = file._name.get()
        i_sep = filename.lastIndexOf(".")
        if i_sep == -1
            return true # No extension found, assuming user knows what he is doing. May be a mistake ^^
        ext = filename.substring(i_sep+1).toLowerCase()
        test = false
        for e in extensions
            if ext == e
                test = true
                break
        if not test
            s = "Bad file extension : " + ext + " (#{extensions} expected)"
            i = s.lastIndexOf(",")
            if i != -1
                s = s.substring(0,i) + " or " + s.substring(i+1)
            alert s
        return test
    return check_function

# A test process, created in Scills2DItem
class TestProcess extends ProcessTreeItem
    
    constructor: (name = "TestProcess") ->
        super(name)
        
        # Inputs definition
        @addInput FileItem, "InputMeshFile", check_file_extension(["unv","msh","pdb"])
        
        # Output definition
        @addOutput FileItem, "OutputFile"
    
    # Reimplementation of 'ProcessTreeItem.compute'
    compute: () ->
        alert "Computing"
        @_outputs[0]._val = @_inputs[0].getValue()
        return true
