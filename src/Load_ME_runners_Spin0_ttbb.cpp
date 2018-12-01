/*
 *
 * Load_ME_runners_try functions
 *
 *
 */
#ifndef MEKD__Load_ME_runners_Spin0_ttbb_cpp
#define MEKD__Load_ME_runners_Spin0_ttbb_cpp

#include "MEKD.h"
#include "MEKD/Supported_MEs_Spin0_ttbb.h"

using namespace std;

namespace mekd
{

bool MEKD::Load_ME_runners_try_Spin0_ttbb(const process_description &d,
                                          vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_all_bkg_Spin0Pm_2f_ttbb_1(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_all_bkg_Spin0Pm_2f_ttbb_2(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_all_Spin0Pm_2f_ttbb_2(), v))
        return true;

    return false;
}

/// end of namespace
} // namespace mekd

#endif
/*
 * End of MEKD__Load_ME_runners_Spin0_ttbb_cpp
 */
