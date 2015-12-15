/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin1_4l_h
#define MEKD_Supported_MEs_Spin1_4l_h

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
 * Spin-1 resonances
 */

class ME_runner_qq_Spin1M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_qq,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1M_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1P_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_qq,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1P_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
        prod_qq,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
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

class ME_runner_qq_Spin1M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_qq,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1M_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1P_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_qq,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1P_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_no,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
        prod_qq,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
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
 * Spin-1 resonances
 */

class ME_runner_qq_Spin1M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_qq,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1M_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1P_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_qq,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1P_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
        prod_qq,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
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

class ME_runner_qq_Spin1M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_qq,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1M_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1M, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1P_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_qq,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1P_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Spin1P, // resonance
        prod_no,      // production
        decay_2f,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin1_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
        prod_qq,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin1_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,  // model
        proc_simple, // process
        reson_Spin1, // resonance
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