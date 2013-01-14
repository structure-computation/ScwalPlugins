#include "formulation_elasticity_dep_Tetra.h"
#include "formulation.laplacian.Tetra.h"
#include "CorreliUpdater_3D.h"
#include "CorreliUpdater_nD.h"

bool correli_updater_3D( CorreliUpdater *updater, MP mp ) {
    correliUpdater_nD( updater, mp, LMT::Number<3>() );
}
