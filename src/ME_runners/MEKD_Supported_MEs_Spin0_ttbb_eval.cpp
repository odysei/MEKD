/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_eval_cpp
#define MEKD_Supported_MEs_Spin0_ttbb_eval_cpp

#include "Supported_MEs_Spin0_ttbb.h"
#include "Parameters_configurators.h"
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

template <class Parameters,
          class cME_ddx, class cME_uux, class cME_ssx,
          class cME_ccx, class cME_bbx, class cME_gg>
double evaluate_all_Spin0_ttbb(MEKD &in_MEKD, Parameters *pa,
                               cME_ddx *ddx, cME_uux *uux, cME_ssx *ssx,
                               cME_ccx *ccx, cME_bbx *bbx, cME_gg *gg)
{
    Configurator_Spin0(in_MEKD.idata,
                       in_MEKD.param, in_MEKD.flag,
                       pa);
    double ME2 = 0;
    
    if (in_MEKD.flag.use_prod_ddx)
        ME2 += ME_Evaluator_IS_ddx(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                   ddx);
    if (in_MEKD.flag.use_prod_uux)
        ME2 += ME_Evaluator_IS_uux(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                   uux);
    if (in_MEKD.flag.use_prod_ssx)
        ME2 += ME_Evaluator_IS_ssx(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                   ssx);
    if (in_MEKD.flag.use_prod_ccx)
        ME2 += ME_Evaluator_IS_ccx(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                   ccx);
    if (in_MEKD.flag.use_prod_bbx)
        ME2 += ME_Evaluator_IS_bbx(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                   bbx);
    if (in_MEKD.flag.use_prod_gg)
        ME2 += ME_Evaluator_IS_gg(in_MEKD.flag.Use_PDF_w_pT0, in_MEKD.idata,
                                  gg);
    
    return ME2;
}

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb_1
double ME_runner_all_bkg_Spin0Pm_2f_ttbb_1::evaluate(MEKD &in_MEKD,
                                                     const input &in)
{
    return evaluate_all_Spin0_ttbb(in_MEKD, in_MEKD.params_sm_full,
                                   ME_ddx, ME_uux, ME_ssx,
                                   ME_ccx, ME_bbx, ME_gg);
}

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb_2
double ME_runner_all_bkg_Spin0Pm_2f_ttbb_2::evaluate(MEKD &in_MEKD,
                                                     const input &in)
{
    return evaluate_all_Spin0_ttbb(in_MEKD, in_MEKD.params_HEFTU,
                                   ME_ddx, ME_uux, ME_ssx,
                                   ME_ccx, ME_bbx, ME_gg);
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