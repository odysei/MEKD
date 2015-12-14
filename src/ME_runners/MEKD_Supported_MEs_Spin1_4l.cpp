/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin1_4l_cpp
#define MEKD_Supported_MEs_Spin1_4l_cpp

#include "Supported_MEs_Spin1_4l.h"

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
 * Spin-1 resonances
 */

/// ME_runner_qq_Spin1M_ZZ_4l
const process_description ME_runner_qq_Spin1M_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1M_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1M_ZZ_4l
const process_description ME_runner_no_Spin1M_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1M_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1M_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1P_ZZ_4l
const process_description ME_runner_qq_Spin1P_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1P_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1P_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1P_ZZ_4l
const process_description ME_runner_no_Spin1P_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1P_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1P_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1_ZZ_4l
const process_description ME_runner_qq_Spin1_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1_ZZ_4l
const process_description ME_runner_no_Spin1_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_qq_Spin1M_ZZ_4lA
const process_description ME_runner_qq_Spin1M_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1M_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1M_ZZ_4lA
const process_description ME_runner_no_Spin1M_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1M_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1M_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1P_ZZ_4lA
const process_description ME_runner_qq_Spin1P_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1P_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1P_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1P_ZZ_4lA
const process_description ME_runner_no_Spin1P_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1P_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1P_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1_ZZ_4lA
const process_description ME_runner_qq_Spin1_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1_ZZ_4lA
const process_description ME_runner_no_Spin1_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/*
 * Resonance to 2f decay modes.
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-1 resonances
 */

/// ME_runner_qq_Spin1M_2f_4l
const process_description ME_runner_qq_Spin1M_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1M_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1M_2f_4l
const process_description ME_runner_no_Spin1M_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1M_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1M_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1P_2f_4l
const process_description ME_runner_qq_Spin1P_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1P_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1P_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1P_2f_4l
const process_description ME_runner_no_Spin1P_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1P_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1P_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1_2f_4l
const process_description ME_runner_qq_Spin1_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1_2f_4l
const process_description ME_runner_no_Spin1_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin1_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_qq_Spin1M_2f_4lA
const process_description ME_runner_qq_Spin1M_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1M_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1M_2f_4lA
const process_description ME_runner_no_Spin1M_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1M_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1M_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1M(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1P_2f_4lA
const process_description ME_runner_qq_Spin1P_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1P_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1P_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1P_2f_4lA
const process_description ME_runner_no_Spin1P_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1P_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1P_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1P(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin1_2f_4lA
const process_description ME_runner_qq_Spin1_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin1_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin1_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
    return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin1_2f_4lA
const process_description ME_runner_no_Spin1_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin1_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin1_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Spin1(me, in_MEKD.idata, in_MEKD.params_MG);
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