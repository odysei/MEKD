/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD__ME_runners__Spin1_4l_basic_cpp
#define MEKD__ME_runners__Spin1_4l_basic_cpp

#include "Supported_MEs_Spin1_4l.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to 2f decay modes.
 * Cascade resonances, like q qbar -> Z -> Zp + ll -> 4l
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-1 resonances
 */

/// ME_runner_qq_Z_Zp_Spin1_2f_4l
const process_description ME_runner_qq_Z_Zp_Spin1_2f_4l::my_type() { return me; }

bool ME_runner_qq_Z_Zp_Spin1_2f_4l::is_my_type(const process_description &in)
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
/// END OF MEKD__ME_runners__h   ///
/////////////////////////////////////
