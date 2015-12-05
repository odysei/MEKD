/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_eval_cpp
#define MEKD_Supported_MEs_Spin0_4l_eval_cpp

#include "MEKD_Supported_MEs_Spin0_4l.h"
#include "MEKD_Evaluators.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
 *
 * Final states: 4 leptons (+photon) also 2 muons (+photon)
 */

/*
 * Spin-0 resonances
 */

template <class cME_OF, class cME_SF>
double evaluate_gg_Spin0_4l(const complex<double> *c, MEKD &in_MEKD,
                            cME_OF *OF, cME_SF *SF)
{
    Configurator_Spin0(c, in_MEKD.idata,
                       in_MEKD.param, in_MEKD.flag,
                       in_MEKD.params_MEKD);
    
    if (in_MEKD.idata.fs == final_4e || in_MEKD.idata.fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.e;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_gg(in_MEKD.flag.Use_PDF_w_pT0,
                                      in_MEKD.idata,
                                      SF);
    }
    
    if (in_MEKD.idata.fs == final_4mu || in_MEKD.idata.fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.mu;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_gg(in_MEKD.flag.Use_PDF_w_pT0,
                                      in_MEKD.idata,
                                      SF);
    }
    
    if (in_MEKD.idata.fs == final_2e2mu || in_MEKD.idata.fs == final_2e2muA) {
        /// Masses for the opposite-flavor leptons
        in_MEKD.params_MEKD->mdl_Me = in_MEKD.idata.m.e;
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.mu;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_gg(in_MEKD.flag.Use_PDF_w_pT0,
                                      in_MEKD.idata,
                                      OF);
    }
    
    return 0;
}

template <class cME_OF, class cME_SF>
double evaluate_no_Spin0_4l(const complex<double> *c, MEKD &in_MEKD,
                            cME_OF *OF, cME_SF *SF)
{
    Configurator_Spin0(c, in_MEKD.idata,
                       in_MEKD.param, in_MEKD.flag,
                       in_MEKD.params_MEKD);
    
    if (in_MEKD.idata.fs == final_4e || in_MEKD.idata.fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.e;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_no(in_MEKD.idata,
                                      SF);
    }
    
    if (in_MEKD.idata.fs == final_4mu || in_MEKD.idata.fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.mu;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_no(in_MEKD.idata,
                                      SF);
    }
    
    if (in_MEKD.idata.fs == final_2e2mu || in_MEKD.idata.fs == final_2e2muA) {
        /// Masses for the opposite-flavor leptons
        in_MEKD.params_MEKD->mdl_Me = in_MEKD.idata.m.e;
        in_MEKD.params_MEKD->mdl_MM = in_MEKD.idata.m.mu;
        
        if (in_MEKD.flag.use_prod_gg)
            return ME_Evaluator_IS_no(in_MEKD.idata,
                                      OF);
    }
    
    return 0;
}

/// ME_runner_gg_Spin0Pm_ZZ_4l
double ME_runner_gg_Spin0Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Pm_ZZ_4l
double ME_runner_no_Spin0Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0Ph_ZZ_4l
double ME_runner_gg_Spin0Ph_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Ph,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Ph_ZZ_4l
double ME_runner_no_Spin0Ph_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Ph,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0M_ZZ_4l
double ME_runner_gg_Spin0M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0M_ZZ_4l
double ME_runner_no_Spin0M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0_ZZ_4l
double ME_runner_gg_Spin0_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0_ZZ_4l
double ME_runner_no_Spin0_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_OF, ME_SF);
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_ZZ_4lA
double ME_runner_gg_Spin0Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Pm_ZZ_4lA
double ME_runner_no_Spin0Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0Ph_ZZ_4lA
double ME_runner_gg_Spin0Ph_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Ph,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Ph_ZZ_4lA
double ME_runner_no_Spin0Ph_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Ph,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0M_ZZ_4lA
double ME_runner_gg_Spin0M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0M_ZZ_4lA
double ME_runner_no_Spin0M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0_ZZ_4lA
double ME_runner_gg_Spin0_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0_ZZ_4lA
double ME_runner_no_Spin0_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_OF, ME_SF);
}

/*
 * Resonance to 2f decay modes.
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-0 resonances
 */

/// ME_runner_gg_Spin0Pm_2f_4l
double ME_runner_gg_Spin0Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Pm_2f_4l
double ME_runner_no_Spin0Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0M_2f_4l
double ME_runner_gg_Spin0M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M_2f,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0M_2f_4l
double ME_runner_no_Spin0M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M_2f,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0_2f_4l
double ME_runner_gg_Spin0_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0_2f_4l
double ME_runner_no_Spin0_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_OF, ME_SF);
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_2f_4lA
double ME_runner_gg_Spin0Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0Pm_2f_4lA
double ME_runner_no_Spin0Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0Pm,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0M_2f_4lA
double ME_runner_gg_Spin0M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M_2f,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0M_2f_4lA
double ME_runner_no_Spin0M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(MG5_HEF_MEKD::definition_Spin0M_2f,
                                in_MEKD, ME_OF, ME_SF);
}

/// ME_runner_gg_Spin0_2f_4lA
double ME_runner_gg_Spin0_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_gg_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_gg_OF, ME_gg_SF);
}

/// ME_runner_no_Spin0_2f_4lA
double ME_runner_no_Spin0_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    return evaluate_no_Spin0_4l(in_MEKD.idata.mix_coeffs_Spin0,
                                in_MEKD, ME_OF, ME_SF);
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