import formal_lf
formal_lf.write_pb(
    name = 'elasticity_dep',
    formulations = ['elasticity_dep'],
    elements = ['Tetra'],
    incpaths = ['.','/home/leclerc/Code/Dic/../LMT/formulations'],
    name_der_vars=["param"],
)
