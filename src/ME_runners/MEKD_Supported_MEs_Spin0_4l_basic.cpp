/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_cpp
#define MEKD_Supported_MEs_Spin0_4l_cpp

#include "Supported_MEs_Spin0_4l.h"

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
const process_description ME_runner_gg_Spin0Pm_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Pm_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Pm_ZZ_4l
const process_description ME_runner_no_Spin0Pm_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Pm_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}
/// ME_runner_gg_Spin0Ph_ZZ_4l
const process_description ME_runner_gg_Spin0Ph_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Ph_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Ph_ZZ_4l
const process_description ME_runner_no_Spin0Ph_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Ph_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0M_ZZ_4l
const process_description ME_runner_gg_Spin0M_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0M_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0M_ZZ_4l
const process_description ME_runner_no_Spin0M_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0M_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0_ZZ_4l
const process_description ME_runner_gg_Spin0_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0_ZZ_4l
const process_description ME_runner_no_Spin0_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0_ZZ_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_ZZ_4lA
const process_description ME_runner_gg_Spin0Pm_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Pm_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Pm_ZZ_4lA
const process_description ME_runner_no_Spin0Pm_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Pm_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0Ph_ZZ_4lA
const process_description ME_runner_gg_Spin0Ph_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Ph_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Ph_ZZ_4lA
const process_description ME_runner_no_Spin0Ph_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Ph_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0M_ZZ_4lA
const process_description ME_runner_gg_Spin0M_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0M_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0M_ZZ_4lA
const process_description ME_runner_no_Spin0M_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0M_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0_ZZ_4lA
const process_description ME_runner_gg_Spin0_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0_ZZ_4lA
const process_description ME_runner_no_Spin0_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
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
const process_description ME_runner_gg_Spin0Pm_2f_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Pm_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Pm_2f_4l
const process_description ME_runner_no_Spin0Pm_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Pm_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0M_2f_4l
const process_description ME_runner_gg_Spin0M_2f_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0M_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0M_2f_4l
const process_description ME_runner_no_Spin0M_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0M_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0_2f_4l
const process_description ME_runner_gg_Spin0_2f_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0_2f_4l
const process_description ME_runner_no_Spin0_2f_4l::my_type()
{
    return me;
}

bool ME_runner_no_Spin0_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_2f_4lA
const process_description ME_runner_gg_Spin0Pm_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0Pm_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0Pm_2f_4lA
const process_description ME_runner_no_Spin0Pm_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0Pm_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0M_2f_4lA
const process_description ME_runner_gg_Spin0M_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0M_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0M_2f_4lA
const process_description ME_runner_no_Spin0M_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0M_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_gg_Spin0_2f_4lA
const process_description ME_runner_gg_Spin0_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Spin0_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_no_Spin0_2f_4lA
const process_description ME_runner_no_Spin0_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_no_Spin0_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
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