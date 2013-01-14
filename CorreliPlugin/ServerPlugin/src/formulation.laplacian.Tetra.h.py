import formal_lf
formal_lf.write_pb(
    name = 'laplacian',
    formulations = ['laplacian'],
    elements = ['Tetra'],
    incpaths = ['.','/home/leclerc/Demo/LMT/formulations'],
    name_der_vars=[],
)
