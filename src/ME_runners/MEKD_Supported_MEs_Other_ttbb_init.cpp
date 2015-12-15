/*
 *
 * ME_runners. See defined processes below.
 * 
 * Mostly backgrounds for ttbb resonance processes
 *
 *
 */
#ifndef MEKD_Supported_MEs_Other_ttbb_init_cpp
#define MEKD_Supported_MEs_Other_ttbb_init_cpp

#include "Supported_MEs_Other_ttbb.h"
#include "MEKD_Initiators.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * For resonances to 2f decay modes.
 *
 * Final states: t tbar b bbar
 */

/*
 * t tbar b bbar standard processes AKA backgrounds
 */

/// ME_runner_all_bkg_2f_ttbb_2
bool ME_runner_all_bkg_2f_ttbb_2::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_ddx", 2,
                      new MG5_heft_updated_full::ddx_noh_ttxbbx(), ME_ddx))
        return false;
    if (!ME_Initiator(param_f, "ME_uux", 2,
                      new MG5_heft_updated_full::uux_noh_ttxbbx(), ME_uux))
        return false;
    if (!ME_Initiator(param_f, "ME_ssx", 2,
                      new MG5_heft_updated_full::ssx_noh_ttxbbx(), ME_ssx))
        return false;
    if (!ME_Initiator(param_f, "ME_ccx", 2,
                      new MG5_heft_updated_full::ccx_noh_ttxbbx(), ME_ccx))
        return false;
    if (!ME_Initiator(param_f, "ME_bbx", 2,
                      new MG5_heft_updated_full::bbx_noh_ttxbbx(), ME_bbx))
        return false;
    if (!ME_Initiator(param_f, "ME_gg", 1,
                      new MG5_heft_updated_full::gg_noh_ttxbbx(), ME_gg))
        return false;
    
    return true;
}

bool ME_runner_all_bkg_2f_ttbb_2::initialize()
{
    return initialize("");
}

void ME_runner_all_bkg_2f_ttbb_2::deinitialize()
{
    delete ME_ddx;
    delete ME_uux;
    delete ME_ssx;
    delete ME_ccx;
    delete ME_bbx;
    delete ME_gg;
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