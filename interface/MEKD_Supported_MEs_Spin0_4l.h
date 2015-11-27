/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_h
#define MEKD_Supported_MEs_Spin0_4l_h

#include "MEKD.h"

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
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0Ph_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Ph_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0Ph_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Ph_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Ph, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

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
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin0Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_gg,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,  // process
        reson_Spin0M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin0_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin0_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin0, // resonance
        prod_no,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

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