/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_h
#define MEKD_Supported_MEs_Spin0_ttbb_h

#include "MEKD.h"

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

class ME_runner_all_bkg_Spin0Pm_2f_ttbb : public ME_runner
{
  public:
    const process_description me = {
        proc_ttX,          // process
        bkg_reson_Spin0Pm, // resonance
        prod_all,          // production
        decay_2f,          // decay
        final_ttbb         // final_state
    };

    // Actual MEs
    MG5_sm_full::cc_ttbb *ME;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * End of ME_runner classes
 */

/// end of namespace
}

#endif

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////