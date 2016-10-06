/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD__ME_runners__Other_4l_eval_cpp
#define MEKD__ME_runners__Other_4l_eval_cpp

#include "Supported_MEs_Other_4l.h"
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

template <class Parameters, class cME_ssx_OF, class cME_ssx_SF,
          class cME_ccx_OF, class cME_ccx_SF>
double evaluate_qqx_Spin0_4l(MEKD &in_MEKD, Parameters *pa,
                             cME_ssx_OF *ssx_OF, cME_ssx_SF *ssx_SF,
                             cME_ccx_OF *ccx_OF, cME_ccx_SF *ccx_SF)
{
    double ME2 = 0;
    
    const auto fs = in_MEKD.idata.fs;
    const bool use_PDF = in_MEKD.flag.Use_PDF_w_pT0;
    const bool convention_2013 = in_MEKD.flag.use_prod_2013_convetion_for_4l;
    if (fs == final_2e2mu || fs == final_2e2muA) {
        if (in_MEKD.flag.use_prod_ddx && !convention_2013) {
            Configurator_ZZ_ddx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ddx(use_PDF, in_MEKD.idata, ssx_OF);
        }
        if (in_MEKD.flag.use_prod_uux || convention_2013) {
            Configurator_ZZ_uux(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_uux(use_PDF, in_MEKD.idata, ccx_OF);
        }
        if (in_MEKD.flag.use_prod_ssx && !convention_2013) {
            Configurator_ZZ_ssx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ssx(use_PDF, in_MEKD.idata, ssx_OF);
        }
        if (in_MEKD.flag.use_prod_ccx && !convention_2013) {
            Configurator_ZZ_ccx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ccx(use_PDF, in_MEKD.idata, ccx_OF);
        }
        if (in_MEKD.flag.use_prod_bbx && !convention_2013) {
            Configurator_ZZ_bbx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_bbx(use_PDF, in_MEKD.idata, ccx_OF);
        }
        
        return ME2;
    }
    
    if (fs == final_4mu || fs == final_4muA || fs == final_4e ||
        fs == final_4eA) {
        if (in_MEKD.flag.use_prod_ddx && !convention_2013) {
            Configurator_ZZ_ddx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ddx(use_PDF, in_MEKD.idata, ssx_SF);
        }
        if (in_MEKD.flag.use_prod_uux || convention_2013) {
            Configurator_ZZ_uux(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_uux(use_PDF, in_MEKD.idata, ccx_SF);
        }
        if (in_MEKD.flag.use_prod_ssx && !convention_2013) {
            Configurator_ZZ_ssx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ssx(use_PDF, in_MEKD.idata, ssx_SF);
        }
        if (in_MEKD.flag.use_prod_ccx && !convention_2013) {
            Configurator_ZZ_ccx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_ccx(use_PDF, in_MEKD.idata, ccx_SF);
        }
        if (in_MEKD.flag.use_prod_bbx && !convention_2013) {
            Configurator_ZZ_bbx(in_MEKD.idata, pa);
            ME2 += ME_Evaluator_IS_bbx(use_PDF, in_MEKD.idata, ccx_SF);
        }
        
        return ME2;
    }
    
    return ME2;
}

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb_1
double ME_runner_qq_bkg_Z_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_qqx_Spin0_4l(in_MEKD, in_MEKD.params_MEKD, ME_ssx_OF,
                                 ME_ssx_SF, ME_ccx_OF, ME_ccx_SF);
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
