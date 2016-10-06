/*
 *
 * ME_runners. See defined processes below.
 *
 * Mostly: ZZ, Z backgrounds, Z s/t channels, some custom
 *
 *
 */
#ifndef MEKD__ME_runners__Other_4l_basic_cpp
#define MEKD__ME_runners__Other_4l_basic_cpp

#include "Supported_MEs_Other_4l.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

/// ME_runner_qq_bkg_Z_ZZ_4l
const process_description ME_runner_qq_bkg_Z_ZZ_4l::my_type() { return me; }

bool ME_runner_qq_bkg_Z_ZZ_4l::is_my_type(const process_description &in)
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
