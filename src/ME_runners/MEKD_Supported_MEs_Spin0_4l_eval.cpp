/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_eval_cpp
#define MEKD_Supported_MEs_Spin0_4l_eval_cpp

#include "MEKD_Supported_MEs_Spin0_4l.h"

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

/// ME_runner_gg_Spin0Pm_ZZ_4l
double ME_runner_gg_Spin0Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Pm_ZZ_4l
double ME_runner_no_Spin0Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0Ph_ZZ_4l
double ME_runner_gg_Spin0Ph_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Ph(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Ph_ZZ_4l
double ME_runner_no_Spin0Ph_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Ph(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0M_ZZ_4l
double ME_runner_gg_Spin0M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0M_ZZ_4l
double ME_runner_no_Spin0M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0_ZZ_4l
double ME_runner_gg_Spin0_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0_ZZ_4l
double ME_runner_no_Spin0_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_ZZ_4lA
double ME_runner_gg_Spin0Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Pm_ZZ_4lA
double ME_runner_no_Spin0Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0Ph_ZZ_4lA
double ME_runner_gg_Spin0Ph_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Ph(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Ph_ZZ_4lA
double ME_runner_no_Spin0Ph_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Ph(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0M_ZZ_4lA
double ME_runner_gg_Spin0M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0M_ZZ_4lA
double ME_runner_no_Spin0M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0_ZZ_4lA
double ME_runner_gg_Spin0_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0_ZZ_4lA
double ME_runner_no_Spin0_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
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
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Pm_2f_4l
double ME_runner_no_Spin0Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0M_2f_4l
double ME_runner_gg_Spin0M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0M_2f_4l
double ME_runner_no_Spin0M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0_2f_4l
double ME_runner_gg_Spin0_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0_2f_4l
double ME_runner_no_Spin0_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_2f_4lA
double ME_runner_gg_Spin0Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0Pm_2f_4lA
double ME_runner_no_Spin0Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0Pm(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0M_2f_4lA
double ME_runner_gg_Spin0M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0M_2f_4lA
double ME_runner_no_Spin0M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin0_2f_4lA
double ME_runner_gg_Spin0_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin0_2f_4lA
double ME_runner_no_Spin0_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
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