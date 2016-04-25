/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_h
#define MEKD_Supported_MEs_Spin0_4l_h

#include "MEKD.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin0/MEKD_MEs.h"
#include "MG5_aMCNLO/HiggsPO_UFO/Spin0_4l/MEKD_MEs.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
 *
 * Final states: 4 leptons (+photon) also 2 muons (+photon)
 */

/*
 * Spin-0 resonances
 */

class ME_runner_gg_Spin0Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    gg_Spin0_OF *ME_gg_OF;
    gg_Spin0_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0Pm_ZZ_4l_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HiggsPO, // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_VV,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    MG5_HiggsPO_UFO::gg_Spin0_OF *ME_gg_OF;
    MG5_HiggsPO_UFO::gg_Spin0_SF *ME_gg_SF;

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

class ME_runner_no_Spin0Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    Spin0_OF *ME_OF;
    Spin0_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_ZZ_4l_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HiggsPO, // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_VV,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    MG5_HiggsPO_UFO::Spin0_OF *ME_OF;
    MG5_HiggsPO_UFO::Spin0_SF *ME_SF;

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

class ME_runner_gg_Spin0Ph_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    gg_Spin0_OF *ME_gg_OF;
    gg_Spin0_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Ph_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    Spin0_OF *ME_OF;
    Spin0_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs
    gg_Spin0_OF *ME_gg_OF;
    gg_Spin0_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs
    Spin0_OF *ME_OF;
    Spin0_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs
    gg_Spin0_OF *ME_gg_OF;
    gg_Spin0_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_ZZ_4l_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HiggsPO, // model
        proc_simple,   // process
        reson_Spin0,   // resonance
        prod_gg,       // production
        decay_VV,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    MG5_HiggsPO_UFO::gg_Spin0_OF *ME_gg_OF;
    MG5_HiggsPO_UFO::gg_Spin0_SF *ME_gg_SF;

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

class ME_runner_no_Spin0_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs
    Spin0_OF *ME_OF;
    Spin0_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_ZZ_4l_2 : public ME_runner
{
  public:
    const process_description me = {
        model_HiggsPO, // model
        proc_simple,   // process
        reson_Spin0,   // resonance
        prod_no,       // production
        decay_VV,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    MG5_HiggsPO_UFO::Spin0_OF *ME_OF;
    MG5_HiggsPO_UFO::Spin0_SF *ME_SF;

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
 * with photons
 */

class ME_runner_gg_Spin0Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    gg_Spin0_OFpA *ME_gg_OF;
    gg_Spin0_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    Spin0_OFpA *ME_OF;
    Spin0_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0Ph_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    gg_Spin0_OFpA *ME_gg_OF;
    gg_Spin0_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Ph_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    Spin0_OFpA *ME_OF;
    Spin0_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs
    gg_Spin0_OFpA *ME_gg_OF;
    gg_Spin0_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs
    Spin0_OFpA *ME_OF;
    Spin0_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs
    gg_Spin0_OFpA *ME_gg_OF;
    gg_Spin0_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs
    Spin0_OFpA *ME_OF;
    Spin0_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * Resonance to 2f decay modes.
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-0 resonances
 */

class ME_runner_gg_Spin0Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OF *ME_gg_OF;
    gg_Spin0_2f_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    Spin0_2f_OF *ME_OF;
    Spin0_2f_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OF *ME_gg_OF;
    gg_Spin0_2f_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs
    Spin0_2f_OF *ME_OF;
    Spin0_2f_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OF *ME_gg_OF;
    gg_Spin0_2f_SF *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs
    Spin0_2f_OF *ME_OF;
    Spin0_2f_SF *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OFpA *ME_gg_OF;
    gg_Spin0_2f_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,    // model
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs
    Spin0_2f_OFpA *ME_OF;
    Spin0_2f_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OFpA *ME_gg_OF;
    gg_Spin0_2f_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs
    Spin0_2f_OFpA *ME_OF;
    Spin0_2f_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs
    gg_Spin0_2f_OFpA *ME_gg_OF;
    gg_Spin0_2f_SFpA *ME_gg_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs
    Spin0_2f_OFpA *ME_OF;
    Spin0_2f_SFpA *ME_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
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