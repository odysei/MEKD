/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin2_4l_h
#define MEKD_Supported_MEs_Spin2_4l_h

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
 * Spin-2 resonances
 */

class ME_runner_gg_Spin2Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_qq,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Pm_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph3_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph3_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph3_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph4_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph4_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph4_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph5_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph5_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph5_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph6_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph6_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph6_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph7_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph7_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph7_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh8_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh8_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh8_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh9_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh9_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh9_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4l        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh10_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_gg,         // production
        decay_ZZ,        // decay
        final_4l         // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh10_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_qq,         // production
        decay_ZZ,        // decay
        final_4l         // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh10_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_no,         // production
        decay_ZZ,        // decay
        final_4l         // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_qq,     // production
        decay_ZZ,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
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

class ME_runner_gg_Spin2Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_gg,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_qq,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Pm_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_no,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph2, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph3_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph3_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph3_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph3, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph4_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph4_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph4_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph4, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph5_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph5_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph5_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph5, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph6_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph6_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph6_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph6, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Ph7_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Ph7_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Ph7_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Ph7, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh8_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh8_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh8_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh8, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh9_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_gg,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh9_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_qq,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh9_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,    // process
        reson_Spin2Mh9, // resonance
        prod_no,        // production
        decay_ZZ,       // decay
        final_4lA       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2Mh10_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_gg,         // production
        decay_ZZ,        // decay
        final_4lA        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Mh10_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_qq,         // production
        decay_ZZ,        // decay
        final_4lA        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Mh10_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,     // process
        reson_Spin2Mh10, // resonance
        prod_no,         // production
        decay_ZZ,        // decay
        final_4lA        // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_gg,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_qq,     // production
        decay_ZZ,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
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
 * Spin-2 resonances
 */

class ME_runner_gg_Spin2Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Pm_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_qq,     // production
        decay_2f,    // decay
        final_4l     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
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

class ME_runner_gg_Spin2Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_gg,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2Pm_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple,   // process
        reson_Spin2Pm, // resonance
        prod_no,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_gg_Spin2_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_gg,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_Spin2_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
        prod_qq,     // production
        decay_2f,    // decay
        final_4lA    // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_no_Spin2_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        proc_simple, // process
        reson_Spin2, // resonance
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