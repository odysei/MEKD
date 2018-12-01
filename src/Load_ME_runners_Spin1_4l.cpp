/*
 *
 * Load_ME_runners_try functions
 *
 *
 */
#ifndef MEKD__Load_ME_runners_Spin1_4l_cpp
#define MEKD__Load_ME_runners_Spin1_4l_cpp

#include "MEKD.h"
#include "Supported_MEs_Spin1_4l.h"

using namespace std;

namespace mekd
{

bool MEKD::Load_ME_runners_try_Spin1_4l(const process_description &d,
                                        vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_ZZ_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1_ZZ_4l(), v))
        return true;

    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_2f_4l(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1_2f_4l(), v))
        return true;

    if (Load_ME_runners_try(d, new ME_runner_qq_Z_Zp_Spin1_2f_4l(), v))
        return true;

    return false;
}

bool MEKD::Load_ME_runners_try_Spin1_4lA(const process_description &d,
                                         vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_ZZ_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1_ZZ_4lA(), v))
        return true;

    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_2f_4lA(), v))
        return true;
    if (Load_ME_runners_try(d, new ME_runner_no_Spin1_2f_4lA(), v))
        return true;

    return false;
}

/// end of namespace
} // namespace mekd

#endif
/*
 * End of MEKD__Load_ME_runners_Spin1_4l_cpp
 */
