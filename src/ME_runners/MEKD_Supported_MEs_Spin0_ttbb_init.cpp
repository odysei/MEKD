/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_init_cpp
#define MEKD_Supported_MEs_Spin0_ttbb_init_cpp

#include "MEKD_Supported_MEs_Spin0_ttbb.h"
#include "MEKD_Initiators.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to 2f decay modes.
 *
 * Final states: t tbar b bbar
 */

/*
 * Spin-0 resonances
 */

/// ME_runner_all_bkg_Spin0Pm_2f_ttbbTEST
bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_ccx", 2, new MG5_sm_full::ccx_ttxbbx(),
                      ME_ccx))
        return false;
    if (!ME_Initiator(param_f, "ME_gg", 1, new MG5_sm_full::gg_ttxbbx(),
                      ME_gg))
        return false;
    
    return true;
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::initialize()
{
    return initialize("");
}

void ME_runner_all_bkg_Spin0Pm_2f_ttbb::deinitialize()
{
    delete ME_ccx;
}

/*
 * End of ME_runner classes
 */

/// end of namespace
}

#endif

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////