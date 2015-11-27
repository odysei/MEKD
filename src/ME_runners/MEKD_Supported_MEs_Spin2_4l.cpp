/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin2_4l_cpp
#define MEKD_Supported_MEs_Spin2_4l_cpp

#include "MEKD_Supported_MEs_Spin2_4l.h"

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
 * Spin-2 resonances
 */

/// ME_runner_gg_Spin2Pm_ZZ_4l
const process_description ME_runner_gg_Spin2Pm_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Pm_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Pm_ZZ_4l
const process_description ME_runner_qq_Spin2Pm_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Pm_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Pm_ZZ_4l
const process_description ME_runner_no_Spin2Pm_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Pm_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Pm_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph2_ZZ_4l
const process_description ME_runner_gg_Spin2Ph2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph2_ZZ_4l
const process_description ME_runner_qq_Spin2Ph2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph2_ZZ_4l
const process_description ME_runner_no_Spin2Ph2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph3_ZZ_4l
const process_description ME_runner_gg_Spin2Ph3_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph3_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph3_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph3_ZZ_4l
const process_description ME_runner_qq_Spin2Ph3_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph3_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph3_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph3_ZZ_4l
const process_description ME_runner_no_Spin2Ph3_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph3_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph3_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph4_ZZ_4l
const process_description ME_runner_gg_Spin2Ph4_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph4_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph4_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph4_ZZ_4l
const process_description ME_runner_qq_Spin2Ph4_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph4_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph4_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph4_ZZ_4l
const process_description ME_runner_no_Spin2Ph4_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph4_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph4_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph5_ZZ_4l
const process_description ME_runner_gg_Spin2Ph5_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph5_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph5_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph5_ZZ_4l
const process_description ME_runner_qq_Spin2Ph5_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph5_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph5_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph5_ZZ_4l
const process_description ME_runner_no_Spin2Ph5_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph5_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph5_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph6_ZZ_4l
const process_description ME_runner_gg_Spin2Ph6_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph6_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph6_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph6_ZZ_4l
const process_description ME_runner_qq_Spin2Ph6_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph6_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph6_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph6_ZZ_4l
const process_description ME_runner_no_Spin2Ph6_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph6_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph6_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph7_ZZ_4l
const process_description ME_runner_gg_Spin2Ph7_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph7_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph7_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph7_ZZ_4l
const process_description ME_runner_qq_Spin2Ph7_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph7_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph7_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph7_ZZ_4l
const process_description ME_runner_no_Spin2Ph7_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph7_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph7_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh8_ZZ_4l
const process_description ME_runner_gg_Spin2Mh8_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh8_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh8_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh8_ZZ_4l
const process_description ME_runner_qq_Spin2Mh8_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh8_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh8_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh8_ZZ_4l
const process_description ME_runner_no_Spin2Mh8_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh8_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh8_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh9_ZZ_4l
const process_description ME_runner_gg_Spin2Mh9_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh9_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh9_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh9_ZZ_4l
const process_description ME_runner_qq_Spin2Mh9_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh9_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh9_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh9_ZZ_4l
const process_description ME_runner_no_Spin2Mh9_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh9_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh9_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh10_ZZ_4l
const process_description ME_runner_gg_Spin2Mh10_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh10_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh10_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh10_ZZ_4l
const process_description ME_runner_qq_Spin2Mh10_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh10_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh10_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh10_ZZ_4l
const process_description ME_runner_no_Spin2Mh10_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh10_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh10_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2_ZZ_4l
const process_description ME_runner_gg_Spin2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2_ZZ_4l
const process_description ME_runner_qq_Spin2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2_ZZ_4l
const process_description ME_runner_no_Spin2_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin2Pm_ZZ_4lA
const process_description ME_runner_gg_Spin2Pm_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Pm_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Pm_ZZ_4lA
const process_description ME_runner_qq_Spin2Pm_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Pm_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Pm_ZZ_4lA
const process_description ME_runner_no_Spin2Pm_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Pm_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Pm_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph2_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph2_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph2_ZZ_4lA
const process_description ME_runner_no_Spin2Ph2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph2(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph3_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph3_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph3_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph3_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph3_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph3_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph3_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph3_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph3_ZZ_4lA
const process_description ME_runner_no_Spin2Ph3_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph3_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph3_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph3(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph4_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph4_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph4_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph4_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph4_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph4_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph4_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph4_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph4_ZZ_4lA
const process_description ME_runner_no_Spin2Ph4_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph4_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph4_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph5_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph5_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph5_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph5_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph5_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph5_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph5_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph5_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph5_ZZ_4lA
const process_description ME_runner_no_Spin2Ph5_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph5_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph5_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pb(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph6_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph6_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph6_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph6_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph6_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph6_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph6_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph6_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph6_ZZ_4lA
const process_description ME_runner_no_Spin2Ph6_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph6_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph6_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph6(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Ph7_ZZ_4lA
const process_description ME_runner_gg_Spin2Ph7_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Ph7_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Ph7_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Ph7_ZZ_4lA
const process_description ME_runner_qq_Spin2Ph7_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Ph7_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Ph7_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Ph7_ZZ_4lA
const process_description ME_runner_no_Spin2Ph7_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Ph7_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Ph7_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Ph7(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh8_ZZ_4lA
const process_description ME_runner_gg_Spin2Mh8_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh8_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh8_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh8_ZZ_4lA
const process_description ME_runner_qq_Spin2Mh8_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh8_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh8_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh8_ZZ_4lA
const process_description ME_runner_no_Spin2Mh8_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh8_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh8_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh9_ZZ_4lA
const process_description ME_runner_gg_Spin2Mh9_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh9_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh9_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh9_ZZ_4lA
const process_description ME_runner_qq_Spin2Mh9_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh9_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh9_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh9_ZZ_4lA
const process_description ME_runner_no_Spin2Mh9_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh9_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh9_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh9(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2Mh10_ZZ_4lA
const process_description ME_runner_gg_Spin2Mh10_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Mh10_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Mh10_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Mh10_ZZ_4lA
const process_description ME_runner_qq_Spin2Mh10_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Mh10_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Mh10_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Mh10_ZZ_4lA
const process_description ME_runner_no_Spin2Mh10_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Mh10_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Mh10_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Mh10(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2_ZZ_4lA
const process_description ME_runner_gg_Spin2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2_ZZ_4lA
const process_description ME_runner_qq_Spin2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2_ZZ_4lA
const process_description ME_runner_no_Spin2_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/*
 * Resonance to 2f decay modes.
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-2 resonances
 */

/// ME_runner_gg_Spin2Pm_2f_4l
const process_description ME_runner_gg_Spin2Pm_2f_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Pm_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Pm_2f_4l
const process_description ME_runner_qq_Spin2Pm_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Pm_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Pm_2f_4l
const process_description ME_runner_no_Spin2Pm_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Pm_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Pm_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2_2f_4l
const process_description ME_runner_gg_Spin2_2f_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2_2f_4l
const process_description ME_runner_qq_Spin2_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2_2f_4l
const process_description ME_runner_no_Spin2_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin2_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin2Pm_2f_4lA
const process_description ME_runner_gg_Spin2Pm_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2Pm_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2Pm_2f_4lA
const process_description ME_runner_qq_Spin2Pm_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2Pm_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2Pm_2f_4lA
const process_description ME_runner_no_Spin2Pm_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2Pm_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2Pm_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2Pm(me, in_MEKD.idata);
        return in_MEKD.Signal_ME;
}

/// ME_runner_gg_Spin2_2f_4lA
const process_description ME_runner_gg_Spin2_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin2_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Spin2_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_qq_Spin2_2f_4lA
const process_description ME_runner_qq_Spin2_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_Spin2_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_Spin2_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
        return in_MEKD.Signal_ME;
}

/// ME_runner_no_Spin2_2f_4lA
const process_description ME_runner_no_Spin2_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin2_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_no_Spin2_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
        in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.idata, in_MEKD.params_MG);
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