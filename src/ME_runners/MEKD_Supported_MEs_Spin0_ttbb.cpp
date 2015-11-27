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

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::is_my_type(
    const process_description &in)
{
    return compare_types(in, me);
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::initialize(const string &param_f)
{
    ME_c = new MG5_sm_full::cc_ttbb;
    if (ME_c->nprocesses != 2) {
        cerr << "Problem in ME_c class detected.\n";
        return false;
    }
    if (param_f == "")
        ME_c->initProc();
    else
        ME_c->initProc(param_f);
    
    ME_g = new MG5_sm_full::gg_ttbb;
    if (ME_g->nprocesses != 1) {
        cerr << "Problem in ME_g class detected.\n";
        return false;
    }
    if (param_f == "")
        ME_g->initProc();
    else
        ME_g->initProc(param_f);
    
    return true;
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb::initialize()
{
    return initialize("");
}

void ME_runner_all_bkg_Spin0Pm_2f_ttbb::deinitialize()
{
    delete ME_c;
    delete ME_g;
}

double ME_runner_all_bkg_Spin0Pm_2f_ttbb::evaluate(MEKD &in_MEKD,
                                                   const input &in)
{
//     in_MEKD.params_sm_full->mdl_MH = 160;
    double ME2 = 0;
    if (in_MEKD.flag.use_prod_c)
        ME2 += ME_Evaluator_IS_c(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                 ME_c);
    if (in_MEKD.flag.use_prod_g)
        ME2 += ME_Evaluator_IS_g(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                 ME_g);
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