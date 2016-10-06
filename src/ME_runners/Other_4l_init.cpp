/*
 *
 * ME_runners. See defined processes below.
 *
 * Mostly: ZZ, Z backgrounds, Z s/t channels, some custom
 *
 *
 */
#ifndef MEKD__ME_runners__Other_4l_init_cpp
#define MEKD__ME_runners__Other_4l_init_cpp

#include "Supported_MEs_Other_4l.h"
#include "MEKD_Initiators.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

/// ME_runner_qq_bkg_Z_ZZ_4l
bool ME_runner_qq_bkg_Z_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_ssx_OF", 2,
                      new MG5_HEF_UFO_bkg::qq_ZZ_DN_OF(), ME_ssx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ssx_SF", 2,
                      new MG5_HEF_UFO_bkg::qq_ZZ_DN_SF(), ME_ssx_SF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_OF", 2,
                      new MG5_HEF_UFO_bkg::qq_ZZ_UP_OF(), ME_ccx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_SF", 2,
                      new MG5_HEF_UFO_bkg::qq_ZZ_UP_SF(), ME_ccx_SF))
        return false;

    return true;
}

bool ME_runner_qq_bkg_Z_ZZ_4l::initialize() { return initialize(""); }

void ME_runner_qq_bkg_Z_ZZ_4l::deinitialize()
{
    delete ME_ssx_OF;
    delete ME_ssx_SF;
    delete ME_ccx_OF;
    delete ME_ccx_SF;
}

/*
 * with photons
 */

/// ME_runner_qq_bkg_Z_ZZ_4lA
bool ME_runner_qq_bkg_Z_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_ssx_OF", 2,
                      new MG5_HZZ_Unitary_bkgpA::qq_ZZ_DN_OFpA(), ME_ssx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ssx_SF", 2,
                      new MG5_HZZ_Unitary_bkgpA::qq_ZZ_DN_SFpA(), ME_ssx_SF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_OF", 2,
                      new MG5_HZZ_Unitary_bkgpA::qq_ZZ_UP_OFpA(), ME_ccx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_SF", 2,
                      new MG5_HZZ_Unitary_bkgpA::qq_ZZ_UP_SFpA(), ME_ccx_SF))
        return false;

    return true;
}

bool ME_runner_qq_bkg_Z_ZZ_4lA::initialize() { return initialize(""); }

void ME_runner_qq_bkg_Z_ZZ_4lA::deinitialize()
{
    delete ME_ssx_OF;
    delete ME_ssx_SF;
    delete ME_ccx_OF;
    delete ME_ccx_SF;
}

/*
 * End of ME_runner classes
 */

/// end of namespace
}

#endif

/////////////////////////////////////
/// END OF MEKD__ME_runners__h   ///
/////////////////////////////////////
