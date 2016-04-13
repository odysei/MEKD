/*
 *
 * Load_ME_runners_try functions
 *
 *
 */
#ifndef MEKD_Load_ME_runners_Spin0_4l_cpp
#define MEKD_Load_ME_runners_Spin0_4l_cpp

#include "MEKD.h"
#include "Supported_MEs_Spin0_4l.h"

namespace mekd
{

bool MEKD::Load_ME_runners_try_Spin0_4l(const process_description &d,
                                        vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Pm_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Pm_ZZ_4l_2(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Pm_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Ph_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Ph_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0M_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0M_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0_ZZ_4l_2(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0_ZZ_4l(), v))
        return true;

    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Pm_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Pm_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0M_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0M_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0_2f_4l(), v))
        return true;

    return false;
}

bool MEKD::Load_ME_runners_try_Spin0_4lA(const process_description &d,
                                         vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Pm_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Pm_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Ph_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Ph_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0M_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0M_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0_ZZ_4lA(), v))
        return true;

    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0Pm_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0Pm_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0M_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0M_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_gg_Spin0_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin0_2f_4lA(), v))
        return true;

    return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners_Spin0_4l_cpp
 */