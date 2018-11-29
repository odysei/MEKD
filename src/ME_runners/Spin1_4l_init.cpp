/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD__ME_runners__Spin1_4l_init_cpp
#define MEKD__ME_runners__Spin1_4l_init_cpp

#include "Supported_MEs_Spin1_4l.h"
#include "MEKD_Initiators.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to 2f decay modes.
 * Cascade resonances, like q qbar -> Z -> Zp + ll -> 4l
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-1 resonances
 */

/// ME_runner_qq_Z_Zp_Spin1M_2f_4l
bool ME_runner_qq_Z_Zp_Spin1M_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_ssx_OF", 1,
                      new MG5_Leptophilic_UFO::qq_z_zp_DN_OF(), ME_ssx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ssx_SF", 1,
                      new MG5_Leptophilic_UFO::qq_z_zp_DN_SF(), ME_ssx_SF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_OF", 1,
                      new MG5_Leptophilic_UFO::qq_z_zp_UP_OF(), ME_ccx_OF))
        return false;

    if (!ME_Initiator(param_f, "ME_ccx_SF", 1,
                      new MG5_Leptophilic_UFO::qq_z_zp_UP_SF(), ME_ccx_SF))
        return false;

    return true;
}

bool ME_runner_qq_Z_Zp_Spin1M_2f_4l::initialize() { return initialize(""); }

void ME_runner_qq_Z_Zp_Spin1M_2f_4l::deinitialize()
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
