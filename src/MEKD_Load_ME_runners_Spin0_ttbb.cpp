/*
 *
 * Load_ME_runners_try functions
 *
 *
 */
#ifndef MEKD_Load_ME_runners_Spin0_ttbb_cpp
#define MEKD_Load_ME_runners_Spin0_ttbb_cpp

#include "MEKD.h"
#include "Supported_MEs_Spin0_ttbb.h"

namespace mekd
{

bool MEKD::Load_ME_runners_try_Spin0_ttbb(const process_description &d,
                                          vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_all_bkg_Spin0Pm_2f_ttbb_1(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_all_bkg_Spin0Pm_2f_ttbb_2(), v))
        return true;

    return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners_Spin0_ttbb_cpp
 */