/*
 *
 * ME_runners. See defined processes below.
 * 
 * Mostly backgrounds for ttbb resonance processes
 *
 *
 */
#ifndef MEKD_Supported_MEs_Other_ttbb_basic_cpp
#define MEKD_Supported_MEs_Other_ttbb_basic_cpp

#include "Supported_MEs_Other_ttbb.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * For resonances to 2f decay modes.
 *
 * Final states: t tbar b bbar
 */

/*
 * t tbar b bbar standard processes AKA backgrounds
 */

/// ME_runner_all_bkg_2f_ttbb_2
const process_description ME_runner_all_bkg_2f_ttbb_2::my_type()
{
    return me;
}

bool ME_runner_all_bkg_2f_ttbb_2::is_my_type(
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