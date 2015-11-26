/*
 * 
 * ME_runners. See defined processes below.
 * 
 * 
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_cpp
#define MEKD_Supported_MEs_Spin0_ttbb_cpp

#include "MEKD_Supported_MEs_Spin0_ttbb.h"
#include "MEKD_Evaluators.h"

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

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb
const process_description ME_runner_all_bkg_Spin0Pm_2f_ttbb::my_type()
{
    return me;
}
	
bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::is_my_type(const process_description
                                                            &in)
{
    return compare_types(in, me);
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::initialize(const string &param_f)
{
    ME = new MG5_sm_full::cc_ttbb;
    if (ME->nprocesses != 2) {
        cerr << "Problem in ME class detected.\n";
        return false;
    }
    ME->initProc(param_f);
    return true;
}

void ME_runner_all_bkg_Spin0Pm_2f_ttbb::deinitialize()
{
    delete ME;
}

double ME_runner_all_bkg_Spin0Pm_2f_ttbb::evaluate(MEKD &in_MEKD,
                                                   const input &in)
{
    double ME2 = 0;
    if (in_MEKD.flag.use_prod_u)
        ME2 += ME_Evaluator_IS_u(in_MEKD.flag.Use_PDF_w_pT0,
                                 in_MEKD.idata,
                                 ME);
    return ME2;
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