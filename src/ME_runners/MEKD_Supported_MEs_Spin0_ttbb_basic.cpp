/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_basic_cpp
#define MEKD_Supported_MEs_Spin0_ttbb_basic_cpp

#include "Supported_MEs_Spin0_ttbb.h"

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

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb_1
const process_description ME_runner_all_bkg_Spin0Pm_2f_ttbb_1::my_type()
{
    return me;
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb_1::is_my_type(
    const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_all_bkg_Spin0Pm_2f_ttbb_2
const process_description ME_runner_all_bkg_Spin0Pm_2f_ttbb_2::my_type()
{
    return me;
}

bool ME_runner_all_bkg_Spin0Pm_2f_ttbb_2::is_my_type(
    const process_description &in)
{
    return compare_types(in, me);
}

/// ME_runner_all_Spin0Pm_2f_ttbb_2
const process_description ME_runner_all_Spin0Pm_2f_ttbb_2::my_type()
{
    return me;
}

bool ME_runner_all_Spin0Pm_2f_ttbb_2::is_my_type(
    const process_description &in)
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