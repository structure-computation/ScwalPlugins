#include "formulation_elasticity_dep_Triangle.h"
#include "formulation.laplacian.Triangle.h"
#include "CorreliUpdater_3D.h"
#include "CorreliUpdater_nD.h"

bool correli_updater_2D( CorreliUpdater *updater, MP mp ) {
    correliUpdater_nD( updater, mp, LMT::Number<2>() );
}
