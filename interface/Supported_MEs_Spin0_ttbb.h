/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_ttbb_h
#define MEKD_Supported_MEs_Spin0_ttbb_h

#include "MEKD.h"
#include "MG5_aMCNLO/HEFTU/h_ttbb/MEKD_MEs.h"
#include "MG5_aMCNLO/HEFTU/ttbb_all/MEKD_MEs.h"
#include "MG5_aMCNLO/sm-full/ttbb_all/MEKD_MEs.h"

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
 * Spin-0 resonances with background
 */

class ME_runner_all_bkg_Spin0Pm_2f_ttbb_1 : public ME_runner
{
  public:
    const process_description me = {
        model_SM,          // model
        proc_ttX,          // process
        bkg_reson_Spin0Pm, // resonance
        prod_all,          // production
        decay_2f,          // decay
        final_ttbb         // final_state
    };

    // Actual MEs
    MG5_sm_full::ddx_ttxbbx *ME_ddx;
    MG5_sm_full::uux_ttxbbx *ME_uux;
    MG5_sm_full::ssx_ttxbbx *ME_ssx;
    MG5_sm_full::ccx_ttxbbx *ME_ccx;
    MG5_sm_full::bbx_ttxbbx *ME_bbx;
    MG5_sm_full::gg_ttxbbx *ME_gg;

    // basic
    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const std::string &param_f);
    void deinitialize();

    // eval
    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_all_bkg_Spin0Pm_2f_ttbb_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HEFTU,       // model
        proc_ttX,          // process
        bkg_reson_Spin0Pm, // resonance
        prod_all,          // production
        decay_2f,          // decay
        final_ttbb         // final_state
    };

    // Actual MEs
    MG5_heft_updated_full::ddx_ttxbbx *ME_ddx;
    MG5_heft_updated_full::uux_ttxbbx *ME_uux;
    MG5_heft_updated_full::ssx_ttxbbx *ME_ssx;
    MG5_heft_updated_full::ccx_ttxbbx *ME_ccx;
    MG5_heft_updated_full::bbx_ttxbbx *ME_bbx;
    MG5_heft_updated_full::gg_ttxbbx *ME_gg;

    // basic
    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const std::string &param_f);
    void deinitialize();

    // eval
    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * Spin-0 resonances
 */

class ME_runner_all_Spin0Pm_2f_ttbb_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HEFTU,   // model
        proc_ttX,      // process
        reson_Spin0Pm, // resonance
        prod_all,      // production
        decay_2f,      // decay
        final_ttbb     // final_state
    };

    // Actual MEs
    MG5_heft_updated_full::ddx_h_ttxbbx *ME_ddx;
    MG5_heft_updated_full::uux_h_ttxbbx *ME_uux;
    MG5_heft_updated_full::ssx_h_ttxbbx *ME_ssx;
    MG5_heft_updated_full::ccx_h_ttxbbx *ME_ccx;
    MG5_heft_updated_full::bbx_h_ttxbbx *ME_bbx;
    MG5_heft_updated_full::gg_h_ttxbbx *ME_gg;

    // basic
    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const std::string &param_f);
    void deinitialize();

    // eval
    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * End of ME_runner classes
 */

/// end of namespace
} // namespace mekd

#endif

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////
