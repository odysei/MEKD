/*
 *
 * ME_runners. See defined processes below.
 *
 * Mostly backgrounds for ttbb resonance processes
 *
 *
 */
#ifndef MEKD_Supported_MEs_Other_ttbb_h
#define MEKD_Supported_MEs_Other_ttbb_h

#include "MEKD.h"
#include "MG5_aMCNLO/HEFTU/noh_ttbb/MEKD_MEs.h"

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

class ME_runner_all_bkg_2f_ttbb_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HEFTU, // model
        proc_ttX,    // process
        bkg_tt,      // resonance
        prod_all,    // production
        decay_2f,    // decay
        final_ttbb   // final_state
    };

    // Actual MEs
    MG5_heft_updated_full::ddx_noh_ttxbbx *ME_ddx;
    MG5_heft_updated_full::uux_noh_ttxbbx *ME_uux;
    MG5_heft_updated_full::ssx_noh_ttxbbx *ME_ssx;
    MG5_heft_updated_full::ccx_noh_ttxbbx *ME_ccx;
    MG5_heft_updated_full::bbx_noh_ttxbbx *ME_bbx;
    MG5_heft_updated_full::gg_noh_ttxbbx *ME_gg;

    // basic
    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    // eval
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