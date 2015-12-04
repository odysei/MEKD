/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_eval_cpp
#define MEKD_Supported_MEs_Spin0_ttbb_eval_cpp

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
double ME_runner_all_bkg_Spin0Pm_2f_ttbb::evaluate(MEKD &in_MEKD,
                                                   const input &in)
{
//     in_MEKD.params_sm_full->mdl_MH = 160;
    double ME2 = 0;
    if (in_MEKD.flag.use_prod_ccx)
        ME2 += ME_Evaluator_IS_ccx(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                 ME_ccx);
    if (in_MEKD.flag.use_prod_gg)
        ME2 += ME_Evaluator_IS_gg(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                 ME_gg); 
    
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