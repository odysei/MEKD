/*
 *
 * Load_ME_runners_try functions
 *
 *
 */
#ifndef MEKD__Load_ME_runners_Other_ttbb_cpp
#define MEKD__Load_ME_runners_Other_ttbb_cpp

#include "MEKD.h"
#include "Supported_MEs_Other_ttbb.h"

using namespace std;

namespace mekd
{

bool MEKD::Load_ME_runners_try_Other_ttbb(const process_description &d,
                                          vector<ME_runner *> &v)
{
    if (Load_ME_runners_try(d, new ME_runner_all_bkg_2f_ttbb_2(), v))
        return true;

    return false;
}

/// end of namespace
} // namespace mekd

#endif
