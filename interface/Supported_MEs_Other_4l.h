/*
 *
 * ME_runners. See defined processes below.
 *
 * Mostly: ZZ, Z backgrounds, Z s/t channels, some custom
 *
 *
 */
#ifndef MEKD_Supported_MEs_Other_4l_h
#define MEKD_Supported_MEs_Other_4l_h

#include "MEKD.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

class ME_runner_gg_Custom_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Custom, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4l      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

// class ME_runner_gg_CPPProcess_4l: public ME_runner
// {
// public:
//     const process_description me =
//     {
//         model_HEF_UFO,  // model
//         proc_RAW,       // process
//         reson_Custom,   // resonance
//         prod_gg,        // production
//         decay_ZZ,       // decay
//         final_4l        // final_state
//     };
//
//     // Actual MEs
//
//     const process_description my_type();
//     bool is_my_type(const process_description &in);
//
//     double evaluate(MEKD &in_MEKD, const input &in);
// };

/*
 * with photons
 */

class ME_runner_gg_Custom_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_MEKD,   // model
        proc_simple,  // process
        reson_Custom, // resonance
        prod_gg,      // production
        decay_ZZ,     // decay
        final_4lA     // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

class ME_runner_qq_bkg_Z_ZZ_4l : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Z,         // resonance
        prod_qq,       // production
        decay_ZZ,      // decay
        final_4l       // final_state
    };

    // Actual MEs
    MG5_HEF_UFO_bkg::qq_ZZ_DN_OF *ME_ssx_OF;
    MG5_HEF_UFO_bkg::qq_ZZ_DN_SF *ME_ssx_SF;
    MG5_HEF_UFO_bkg::qq_ZZ_UP_OF *ME_ccx_OF;
    MG5_HEF_UFO_bkg::qq_ZZ_UP_SF *ME_ccx_SF;

    const process_description my_type();
    bool is_my_type(const process_description &in);

    // init
    bool initialize();
    bool initialize(const string &param_f);
    void deinitialize();

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Z_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Z,         // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Zs_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Zs,        // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Zt_2f_4l : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Zt,        // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4l       // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

/*
 * with photons
 */

class ME_runner_qq_bkg_Z_ZZ_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Z,         // resonance
        prod_qq,       // production
        decay_ZZ,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Z_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Z,         // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Zs_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Zs,        // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4lA      // final_state
    };

    // Actual MEs

    const process_description my_type();
    bool is_my_type(const process_description &in);

    double evaluate(MEKD &in_MEKD, const input &in);
};

class ME_runner_qq_bkg_Zt_2f_4lA : public ME_runner
{
  public:
    const process_description me = {
        model_HEF_UFO, // model
        proc_simple,   // process
        bkg_Zt,        // resonance
        prod_qq,       // production
        decay_2f,      // decay
        final_4lA      // final_state
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
