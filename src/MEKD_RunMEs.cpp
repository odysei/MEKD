///////////////////////////////////
///  Part responsible for ME    ///
///  calculations               ///
///////////////////////////////////
#ifndef MEKD_RunMEs_cpp
#define MEKD_RunMEs_cpp

#include "MEKD.h"

namespace mekd
{

/// ZZ and DY processes
int MEKD::Run_ME_Configurator_BKG_ZZ(const process_description &d, data &da)
{
    return Run_ME_Dispatcher_BKG_ZZ(d, da);
}

/// Z4l Background processes (t channel)
int MEKD::Run_ME_Configurator_Z4l_BKG(const process_description &d, data &da)
{
    if (flag.Use_mZ4l_eq_m4l)
        params_MG.set_block_entry("mass", 23, da.m.sys);
    return Run_ME_Dispatcher_Z4l_BKG(d, da);
}

/// Z4l Signal processes (s channel)
int MEKD::Run_ME_Configurator_Z4l_SIG(const process_description &d, data &da)
{
    if (flag.Use_mZ4l_eq_m4l)
        params_MG.set_block_entry("mass", 23, da.m.sys);
    return Run_ME_Dispatcher_Z4l_SIG(d, da);
}

int MEKD::Run_ME_Configurator_Custom(data &da)
{
    cerr << "FIX ME!\n";
    process_description d;
    int error_value;

    d.production = prod_gg;
    if ((error_value = Run_ME_Dispatcher_SIG_Spin0(d, da)) != 0)
        return error_value;
    double custom_run_result = Signal_ME;

    d.production = prod_qq;
    if ((error_value = Run_ME_Dispatcher_SIG_Spin1(d, da)) != 0)
        return error_value;
    custom_run_result += Signal_ME;

    d.production = prod_gg;
    if ((error_value = Run_ME_Dispatcher_SIG_Spin2(d, da)) != 0)
        return error_value;
    custom_run_result += Signal_ME;

    d.production = prod_qq;
    if ((error_value = Run_ME_Dispatcher_SIG_Spin2(d, da)) != 0)
        return error_value;
    Signal_ME += custom_run_result;

    return 0;
}

int MEKD::Run_ME_Configurator_CPPProcess(const process_description &d, data &da)
{
    return Run_ME_Dispatcher_CPPProcess(d, da);
}

////////////////////////////////////
/// Spin-0 resonances start here ///
////////////////////////////////////

/// A SM Higgs
int MEKD::Run_ME_Configurator_Spin0Pm(const process_description &d, data &da)
{
    da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0); // same 2l
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0); // same 2l
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
        da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    }

    return Run_ME_Configurator_Spin0(d, da, params_MG);
}

/// A pseudoscalar
int MEKD::Run_ME_Configurator_Spin0M(const process_description &d, data &da)
{
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(1, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    }

    return Run_ME_Configurator_Spin0(d, da, params_MG);
}

/// A scalar with higher-order couplings
int MEKD::Run_ME_Configurator_Spin0Ph(const process_description &d, data &da)
{
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    }

    return Run_ME_Configurator_Spin0(d, da, params_MG);
}

////////////////////////////////////
/// Spin-1 resonances start here ///
////////////////////////////////////

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1M(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0); // same 2l
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[4] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    }

    return Run_ME_Configurator_Spin1(d, da, params_MG);
}

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1P(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0); // same 2l
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(1, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    }

    return Run_ME_Configurator_Spin1(d, da, params_MG);
}

////////////////////////////////////
/// Spin-2 resonances start here ///
////////////////////////////////////

/// A minimal-coupling KK graviton
int MEKD::Run_ME_Configurator_Spin2Pm(const process_description &d, data &da)
{
    // Production
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(-1, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(1, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[3] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Pb(const process_description &d, data &da)
{
    // Production
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph2(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph3(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[2] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph6(const process_description &d, data &da)
{
    // Production
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph7(const process_description &d, data &da)
{
    // Production
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh9(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(0, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh10(const process_description &d, data &da)
{
    // Production
    da.mix_coeffs_SpinX_pred[0] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[1] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[2] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[3] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[4] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[5] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[6] = complex<double>(0, 0);
    if (d.production == prod_gg)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(1, 0);
    da.mix_coeffs_SpinX_pred[8] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[9] = complex<double>(0, 0);
    // Decay
    da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[14] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[15] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[16] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[17] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[18] = complex<double>(0, 0);
    da.mix_coeffs_SpinX_pred[19] = complex<double>(1, 0);

    if (da.fs == final_2mu || da.fs == final_2muA || d.decay == decay_2f) {
        da.mix_coeffs_SpinX_pred[10] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[11] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[12] = complex<double>(0, 0);
        da.mix_coeffs_SpinX_pred[13] = complex<double>(0, 0);
    }

    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[0] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[1] = complex<double>(1, 0);
    if (d.production == prod_qq)
        da.mix_coeffs_SpinX_pred[7] = complex<double>(0, 0);

    return Run_ME_Configurator_Spin2(d, da, params_MG);
}

/// A generic spin-0 resonance handler
int MEKD::Run_ME_Configurator_Spin0(const process_description &d, data &da,
                                    SLHAReader_MEKD &par_MG)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double mZ = da.m.Z;
    const double M = da.m.sys; // system's invariant mass
    double wH = 1;
    const double hZZ = param.hZZ_coupling;
    double lgg;         // lambda hgg
    complex<double> *c; // mixing coefficients

    if (d.resonance == reson_Spin0) {
        if (da.mix_coeffs_Spin0 == NULL)
            throw(EXIT_ERROR_CONFIG);
        c = da.mix_coeffs_Spin0;
    } else
        c = da.mix_coeffs_SpinX_pred;

    if (flag.use_mX_eq_Mdec) {
        par_MG.set_block_entry("mass", 9000006, M);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));

        lgg = LmbdGG(M);
    } else {
        par_MG.set_block_entry("mass", 9000006, mH);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));

        lgg = LmbdGG(mH);
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    }
    par_MG.set_block_entry("decay", 9000006, wH);

    if (flag.Vary_signal_couplings) {
        Run_ME_Configurator_Spin0_produ(c, lgg, da, par_MG);

        if (flag.use_mX_eq_Mdec)
            Run_ME_Configurator_Spin0_decay(c, mZ, M, hZZ, par_MG);
        else
            Run_ME_Configurator_Spin0_decay(c, mZ, mH, hZZ, par_MG);
    }

    return Run_ME_Dispatcher_SIG_Spin0(d, da);
}

void MEKD::Run_ME_Configurator_Spin0_produ(const complex<double> *c,
                                           const double lgg, data &da,
                                           SLHAReader_MEKD &par_MG)
{
    // gg
    const complex<double> common_coupl = complex<double>(4 * lgg, 0);
    if (flag.Fix_Spin0_Production) {
        par_MG.set_block_entry("heff", 1, complex<double>(0, 0));
        par_MG.set_block_entry("heff", 2, common_coupl); // Spin0Pm
        par_MG.set_block_entry("heff", 3, complex<double>(0, 0));
        par_MG.set_block_entry("heff", 4, complex<double>(0, 0)); // Spin0M
    } else {
        par_MG.set_block_entry("heff", 1, complex<double>(0, 0));
        // Spin0Pm
        par_MG.set_block_entry("heff", 2, (c[0] + c[1] + c[2]) * common_coupl);
        par_MG.set_block_entry("heff", 3, complex<double>(0, 0));
        par_MG.set_block_entry("heff", 4, c[3] * common_coupl); // Spin0M
    }

    // qq
    da.c.rhou01 = complex<double>(0, 0);
    da.c.rhou02 = complex<double>(0, 0);
    da.c.rhoc01 = complex<double>(0, 0);
    da.c.rhoc02 = complex<double>(0, 0);
    da.c.rhod01 = complex<double>(0, 0);
    da.c.rhod02 = complex<double>(0, 0);
    da.c.rhos01 = complex<double>(0, 0);
    da.c.rhos02 = complex<double>(0, 0);
    da.c.rhob01 = complex<double>(0, 0);
    da.c.rhob02 = complex<double>(0, 0);
}

void MEKD::Run_ME_Configurator_Spin0_decay(const complex<double> *c,
                                           const double mZ, const double Mi,
                                           const double hZZ,
                                           SLHAReader_MEKD &par_MG)
{
    // Decay to ZZ
    const complex<double> chZZ = complex<double>(hZZ, 0);
    const complex<double> chZZ_o2 = complex<double>(hZZ / mZ / mZ, 0);
    const complex<double> chZZ_o4k = chZZ_o2 / Mi / Mi;
    par_MG.set_block_entry("heff", 5, c[0] * chZZ);     // Spin0Pm
    par_MG.set_block_entry("heff", 6, c[1] * chZZ_o2);  // Spin0Ph
    par_MG.set_block_entry("heff", 7, c[2] * chZZ_o4k); // Spin0Ph+
    par_MG.set_block_entry("heff", 8, c[3] * chZZ_o2);  // Spin0M

    // Decay to 2l (or 2mu in 2f)
    const complex<double> hmumu = complex<double>(4.291210e-04, 0);
    par_MG.set_block_entry("heff", 19, c[0] * hmumu);
    par_MG.set_block_entry("heff", 20, c[1] * hmumu);

    // Decay to 2e (2f)
    // for Hee should be 2.075371e-06
    par_MG.set_block_entry("heff", 21, c[0] * hmumu);
    par_MG.set_block_entry("heff", 22, c[1] * hmumu);
}

/// A generic spin-1 resonance handler
int MEKD::Run_ME_Configurator_Spin1(const process_description &d, data &da,
                                    SLHAReader_MEKD &par_MG)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double mZ = da.m.Z;
    const double M = da.m.sys; // system's invariant mass
    double wH = 1;
    const double hZZ = param.hZZ_coupling;
    const double vev = param.vev;
    double lgg;         // lambda hgg
    complex<double> *c; // mixing coefficients

    if (d.resonance == reson_Spin1) {
        if (da.mix_coeffs_Spin1 == NULL)
            throw(EXIT_ERROR_CONFIG);
        c = da.mix_coeffs_Spin1;
    } else
        c = da.mix_coeffs_SpinX_pred;

    if (flag.use_mX_eq_Mdec) {
        par_MG.set_block_entry("mass", 300, M);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));

        lgg = LmbdGG(M);
    } else {
        par_MG.set_block_entry("mass", 300, mH);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));

        lgg = LmbdGG(mH);
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    }
    par_MG.set_block_entry("decay", 300, wH);

    if (flag.Vary_signal_couplings) {
        Run_ME_Configurator_Spin1_produ(c, lgg, vev, da, par_MG);
        Run_ME_Configurator_Spin1_decay(c, mZ, hZZ, par_MG);
    }

    return Run_ME_Dispatcher_SIG_Spin1(d, da);
}

void MEKD::Run_ME_Configurator_Spin1_produ(const complex<double> *c,
                                           const double lgg, const double vev,
                                           data &da, SLHAReader_MEKD &par_MG)
{
    // qq
    if (flag.Fix_Spin1_Production) {
        const complex<double> common_coupl =
            complex<double>(sqrt(1 / 2) * lgg * vev, 0);
        da.c.rhod11 = common_coupl;
        da.c.rhos11 = common_coupl;
        da.c.rhob11 = common_coupl;
        da.c.rhou11 = common_coupl;
        da.c.rhoc11 = common_coupl;
        da.c.rhod12 = complex<double>(0, 0);
        da.c.rhos12 = complex<double>(0, 0);
        da.c.rhob12 = complex<double>(0, 0);
        da.c.rhou12 = complex<double>(0, 0);
        da.c.rhoc12 = complex<double>(0, 0);
        da.c.rhod13 = complex<double>(0, 0);
        da.c.rhos13 = complex<double>(0, 0);
        da.c.rhob13 = complex<double>(0, 0);
        da.c.rhou13 = complex<double>(0, 0);
        da.c.rhoc13 = complex<double>(0, 0);
        da.c.rhod14 = complex<double>(0, 0);
        da.c.rhos14 = complex<double>(0, 0);
        da.c.rhob14 = complex<double>(0, 0);
        da.c.rhou14 = complex<double>(0, 0);
        da.c.rhoc14 = complex<double>(0, 0);
    } else {
        const complex<double> common_coupl = complex<double>(lgg * vev, 0);
        da.c.rhod11 = c[0] * common_coupl;
        da.c.rhos11 = c[0] * common_coupl;
        da.c.rhob11 = c[0] * common_coupl;
        da.c.rhou11 = c[0] * common_coupl;
        da.c.rhoc11 = c[0] * common_coupl;
        da.c.rhod12 = c[1] * common_coupl;
        da.c.rhos12 = c[1] * common_coupl;
        da.c.rhob12 = c[1] * common_coupl;
        da.c.rhou12 = c[1] * common_coupl;
        da.c.rhoc12 = c[1] * common_coupl;
        da.c.rhod13 = c[2] * common_coupl;
        da.c.rhos13 = c[2] * common_coupl;
        da.c.rhob13 = c[2] * common_coupl;
        da.c.rhou13 = c[2] * common_coupl;
        da.c.rhoc13 = c[2] * common_coupl;
        da.c.rhod14 = c[3] * common_coupl;
        da.c.rhos14 = c[3] * common_coupl;
        da.c.rhob14 = c[3] * common_coupl;
        da.c.rhou14 = c[3] * common_coupl;
        da.c.rhoc14 = c[3] * common_coupl;
    }
}

void MEKD::Run_ME_Configurator_Spin1_decay(const complex<double> *c,
                                           const double mZ, const double hZZ,
                                           SLHAReader_MEKD &par_MG)
{
    // Decay to ZZ
    const complex<double> c1 = complex<double>(hZZ / 2 / mZ, 0);
    par_MG.set_block_entry("vec", 1, c[4] * c1);
    par_MG.set_block_entry("vec", 2, c[5] * c1 * 0.5);

    // Decay to 2l (or 2mu in 2f)
    const complex<double> hmumu = complex<double>(4.291210e-04, 0);
    par_MG.set_block_entry("vec", 23, c[4] * hmumu);
    par_MG.set_block_entry("vec", 24, c[5] * hmumu);
    par_MG.set_block_entry("vec", 25, c[6] * hmumu);
    par_MG.set_block_entry("vec", 26, c[7] * hmumu);

    // Decay to 2e (2f)
    // for Hee should be 2.075371e-06
    par_MG.set_block_entry("vec", 27, c[4] * hmumu);
    par_MG.set_block_entry("vec", 28, c[5] * hmumu);
    par_MG.set_block_entry("vec", 29, c[6] * hmumu);
    par_MG.set_block_entry("vec", 30, c[7] * hmumu);
}

/// A generic spin-2 resonance handler
int MEKD::Run_ME_Configurator_Spin2(const process_description &d, data &da,
                                    SLHAReader_MEKD &par_MG)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double mZ = da.m.Z;
    const double M = da.m.sys; // system's invariant mass
    double wH = 1;
    const double hZZ = param.hZZ_coupling;
    double lgg;         // lambda hgg
    complex<double> *c; // mixing coefficients

    if (d.resonance == reson_Spin2) {
        if (da.mix_coeffs_Spin2 == NULL)
            throw(EXIT_ERROR_CONFIG);
        c = da.mix_coeffs_Spin2;
    } else
        c = da.mix_coeffs_SpinX_pred;

    if (flag.use_mX_eq_Mdec) {
        par_MG.set_block_entry("mass", 9000007, M);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));

        lgg = LmbdGG(M);
    } else {
        par_MG.set_block_entry("mass", 9000007, mH);

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));

        lgg = LmbdGG(mH);
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    }
    par_MG.set_block_entry("decay", 9000007, wH);

    if (flag.Vary_signal_couplings) {
        if (flag.use_mX_eq_Mdec) {
            Run_ME_Configurator_Spin2_produ(c, M, lgg, da, par_MG);
            Run_ME_Configurator_Spin2_decay(c, mZ, M, hZZ, par_MG);
        } else {
            Run_ME_Configurator_Spin2_produ(c, mH, lgg, da, par_MG);
            Run_ME_Configurator_Spin2_decay(c, mZ, mH, hZZ, par_MG);
        }
    }

    return Run_ME_Dispatcher_SIG_Spin2(d, da);
}

void MEKD::Run_ME_Configurator_Spin2_produ(const complex<double> *c,
                                           const double Mi, const double lgg,
                                           data &da, SLHAReader_MEKD &par_MG)
{
    // gg
    par_MG.set_block_entry("gravity", 1,
                           c[0] * complex<double>(8.0 * lgg, 0)); // 8 flavors
    par_MG.set_block_entry("gravity", 2,
                           c[1] * complex<double>(8.0 * lgg / Mi / Mi, 0));
    par_MG.set_block_entry("gravity", 3,
                           c[2] * complex<double>(8.0 * lgg / Mi / Mi, 0));
    par_MG.set_block_entry(
        "gravity", 4,
        c[3] * complex<double>(
                   8.0 * lgg / Mi / Mi,
                   0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
    par_MG.set_block_entry("gravity", 5,
                           c[4] * complex<double>(8.0 * lgg * Mi * Mi, 0));
    par_MG.set_block_entry("gravity", 6,
                           c[5] * complex<double>(8.0 * lgg / Mi / Mi, 0));
    par_MG.set_block_entry("gravity", 7, c[6] * complex<double>(8.0 * lgg, 0));
    par_MG.set_block_entry(
        "gravity", 8,
        c[7] * complex<double>(
                   8.0 * lgg / Mi / Mi,
                   0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
    par_MG.set_block_entry("gravity", 9, c[8] * complex<double>(8.0 * lgg, 0));
    par_MG.set_block_entry("gravity", 10,
                           c[9] * complex<double>(8.0 * lgg / Mi / Mi, 0));

    // qq
    da.c.rhod21 = c[0] * complex<double>(lgg, 0);
    da.c.rhos21 = c[0] * complex<double>(lgg, 0);
    da.c.rhob21 = c[0] * complex<double>(lgg, 0);
    da.c.rhou21 = c[0] * complex<double>(lgg, 0);
    da.c.rhoc21 = c[0] * complex<double>(lgg, 0);
    da.c.rhod22 = c[1] * complex<double>(lgg, 0);
    da.c.rhos22 = c[1] * complex<double>(lgg, 0);
    da.c.rhob22 = c[1] * complex<double>(lgg, 0);
    da.c.rhou22 = c[1] * complex<double>(lgg, 0);
    da.c.rhoc22 = c[1] * complex<double>(lgg, 0);
    da.c.rhod23 = c[2] * complex<double>(lgg, 0);
    da.c.rhos23 = c[2] * complex<double>(lgg, 0);
    da.c.rhob23 = c[2] * complex<double>(lgg, 0);
    da.c.rhou23 = c[2] * complex<double>(lgg, 0);
    da.c.rhoc23 = c[2] * complex<double>(lgg, 0);
    da.c.rhod24 = c[3] * complex<double>(lgg, 0);
    da.c.rhos24 = c[3] * complex<double>(lgg, 0);
    da.c.rhob24 = c[3] * complex<double>(lgg, 0);
    da.c.rhou24 = c[3] * complex<double>(lgg, 0);
    da.c.rhoc24 = c[3] * complex<double>(lgg, 0);
}

void MEKD::Run_ME_Configurator_Spin2_decay(const complex<double> *c,
                                           const double mZ, const double Mi,
                                           const double hZZ,
                                           SLHAReader_MEKD &par_MG)
{
    // Decay to ZZ
    par_MG.set_block_entry(
        "gravity", 11, c[10] * complex<double>(hZZ / 2 / mZ / mZ / sqrt(2), 0));
    par_MG.set_block_entry(
        "gravity", 12, c[11] * complex<double>(hZZ / 2 / mZ / mZ / Mi / Mi, 0));
    par_MG.set_block_entry(
        "gravity", 13,
        c[12] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
    par_MG.set_block_entry(
        "gravity", 14,
        c[13] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
    par_MG.set_block_entry("gravity", 15,
                           c[14] * complex<double>(hZZ / 2 / sqrt(2), 0));
    par_MG.set_block_entry("gravity", 16,
                           c[15] * complex<double>(hZZ / 2 / mZ / Mi, 0));
    par_MG.set_block_entry("gravity", 17,
                           c[16] * complex<double>(hZZ / 2 / mZ / mZ, 0));
    par_MG.set_block_entry(
        "gravity", 18,
        c[17] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
    par_MG.set_block_entry("gravity", 19,
                           c[18] * complex<double>(hZZ / 2 / mZ / Mi, 0));
    par_MG.set_block_entry(
        "gravity", 20, c[19] * complex<double>(hZZ / 2 / mZ / mZ / Mi / Mi, 0));

    // Decay to 2l (or 2mu in 2f)
    const complex<double> hmumu = complex<double>(4.291210e-04, 0);
    par_MG.set_block_entry("gravity", 41, c[10] * hmumu);
    par_MG.set_block_entry("gravity", 42, c[11] * hmumu);
    par_MG.set_block_entry("gravity", 43, c[12] * hmumu);
    par_MG.set_block_entry("gravity", 44, c[13] * hmumu);

    // Decay to 2e (2f)
    // for Hee should be 2.075371e-06
    par_MG.set_block_entry("gravity", 45, c[10] * hmumu);
    par_MG.set_block_entry("gravity", 46, c[11] * hmumu);
    par_MG.set_block_entry("gravity", 47, c[12] * hmumu);
    par_MG.set_block_entry("gravity", 48, c[13] * hmumu);
}

/// ME_RAW (RAW MG5_aMC ME) dispatcher
int MEKD::Run_ME_Dispatcher_CPPProcess(const process_description &d, data &da)
{
    /*
    if (d.decay == decay_ZZ) {
        if (da.fs == final_4e || da.fs == final_4eA) {
    // 		/// Common mass for the same-flavor leptons
    // 			params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }

        if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
    // 			/// Common mass for the opposite-flavor leptons
    // 			params_MG.set_block_entry("mass", 11, da.m.e);
    // 			params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_gg
                (da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }

        if (da.fs == final_4mu ||  da.fs == final_4muA) {
    // 			/// Common mass for the same-flavor leptons
    // 			params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }
    }

    if (d.decay == decay_2f) {
        if (da.fs == final_4e || da.fs == final_4eA) {
    // 			/// Common mass for the same-flavor leptons
    // 			params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }

        if (da.fs == final_2e2mu ||  da.fs == final_2e2muA) {
    // 			/// Common mass for the opposite-flavor leptons
    // 			params_MG.set_block_entry("mass", 11, da.m.e);
    // 			params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }

        if (da.fs == final_4mu ||  da.fs == final_4muA) {
    // 			/// Common mass for the same-flavor leptons
    // 			params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_RAW);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_RAW);

            if (d.production == prod_gg && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_RAW, ME_RAW);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_RAW, ME_RAW);
        }
    }

    if (da.fs == final_2mu || da.fs == final_2muA) {
    // 		/// Mass for the muons
    // 		params_MG.set_block_entry("mass", 13, da.m.mu);

        if (d.production == prod_no && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_NO(
                da, false, ME_RAW);

        if (d.production == prod_no && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_NO(
                da, true, ME_RAW);

        if (d.production == prod_gg && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_gg(
                da, false, ME_RAW);

        if (d.production == prod_gg && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_gg(
                da, true, ME_RAW);

        if (d.production == prod_qq && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_RAW, ME_RAW);

        if (d.production == prod_qq && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_RAW, ME_RAW);
    }
    */

    return 1;
}

/// ZZ and DY ME dispatcher
int MEKD::Run_ME_Dispatcher_BKG_ZZ(const process_description &d, data &da)
{
    if (d.production == prod_no &&
        !(da.fs == final_2mu || da.fs == final_2muA)) {
        cerr << "ZZ gg initial state is not supported.\n";
        return 1;
    }
    if (d.production == prod_gg) {
        cerr << "ZZ productionless state is not supported.\n";
        return 1;
    }

    if (da.fs == final_4e || da.fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.e);
        /*
        if (d.production == prod_no && da.fs == final_4e)
            return Run_MEs_Evaluator_Initial_State_NO(
                da, false, ME_ZZ_SF);

        if (d.production == prod_no && da.fs == final_4eA)
            return Run_MEs_Evaluator_Initial_State_NO(
                da, true, ME_ZZ_SFpA);

        if (d.production == prod_gg && da.fs == final_4e)
            return Run_MEs_Evaluator_Initial_State_gg(
                da, false, ME_gg_ZZ_SF);

        if (d.production == prod_gg && da.fs == final_4eA)
            return Run_MEs_Evaluator_Initial_State_gg(
                da, true, ME_gg_ZZ_SFpA);
        */

        if (d.production == prod_qq && da.fs == final_4e)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4eA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
    }

    if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
        /// Common mass for the opposite-flavor leptons
        params_MG.set_block_entry("mass", 11, da.m.e);
        params_MG.set_block_entry("mass", 13, da.m.mu);

        //         if (d.production == prod_no && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_ZZ_OF);
        //
        // 		if (d.production == prod_no && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_ZZ_OFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_ZZ_OF);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_ZZ_OFpA);

        if (d.production == prod_qq && da.fs == final_2e2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_ZZ_DownType_OF, ME_qq_ZZ_UpType_OF);

        if (d.production == prod_qq && da.fs == final_2e2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_ZZ_DownType_OFpA, ME_qq_ZZ_UpType_OFpA);
    }

    if (da.fs == final_4mu || da.fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        // 		if (d.production == prod_no && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_ZZ_SF);
        //
        // 		if (d.production == prod_no && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_ZZ_SFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_ZZ_SF);
        //
        // 		if (d.production == prod_gg && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_ZZ_SFpA);

        if (d.production == prod_qq && da.fs == final_4mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
    }

    if (da.fs == final_2mu || da.fs == final_2muA) {
        /// Mass for the muons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        if (d.production == prod_no && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_NO(da, false, ME_DY_2l);

        if (d.production == prod_no && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_NO(da, true, ME_DY_2lpA);

        //         if (d.production == prod_gg && da.fs == final_2mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_DY_2l);
        //
        // 		if (d.production == prod_gg && da.fs == final_2muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_DY_2lpA);

        if (d.production == prod_qq && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_DY_DownType_2l, ME_qq_DY_UpType_2l);

        if (d.production == prod_qq && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_DY_DownType_2lpA, ME_qq_DY_UpType_2lpA);
    }

    return 1;
}

/// Z4l Background ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_BKG(const process_description &d, data &da)
{
    if (d.production == prod_no) {
        cerr << "Z -> 4l gg initial state is not supported.\n";
        return 1;
    }
    if (d.production == prod_gg) {
        cerr << "Z -> 4l productionless state is not supported.\n";
        return 1;
    }
    if (da.fs == final_2mu || da.fs == final_2muA) {
        cerr << "Z -> 4l to 2 lepton is pointless. Run Drell-Yan (DY) instead "
                "(ZZ-based).\n";
        return 1;
    }

    if (da.fs == final_4e || da.fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.e);

        // 		if (d.production == prod_no && da.fs == final_4e)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_Z4l_BKG_SF);
        //
        // 		if (d.production == prod_no && da.fs == final_4eA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_BKG_SFpA);
        //
        //         if (d.production == prod_gg && da.fs == final_4e)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_BKG_SF);
        //
        // 		if (d.production == prod_gg && da.fs == final_4eA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_BKG_SFpA);

        if (d.production == prod_qq && da.fs == final_4e)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4eA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_BKG_DownType_SFpA,
                ME_qq_Z4l_BKG_UpType_SFpA);
    }

    if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
        /// Common mass for the opposite-flavor leptons
        params_MG.set_block_entry("mass", 11, da.m.e);
        params_MG.set_block_entry("mass", 13, da.m.mu);

        // 		if (d.production == prod_no && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_Z4l_BKG_OF);
        //
        // 		if (d.production == prod_no && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_BKG_OFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_BKG_OF);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_BKG_OFpA);

        if (d.production == prod_qq && da.fs == final_2e2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_BKG_DownType_OF, ME_qq_Z4l_BKG_UpType_OF);

        if (d.production == prod_qq && da.fs == final_2e2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_BKG_DownType_OFpA,
                ME_qq_Z4l_BKG_UpType_OFpA);
    }

    if (da.fs == final_4mu || da.fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        // 		if (d.production == prod_no && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_Z4l_BKG_SF);
        //
        // 		if (d.production == prod_no && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_BKG_SFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_BKG_SF);
        //
        // 		if (d.production == prod_gg && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_BKG_SFpA);

        if (d.production == prod_qq && da.fs == final_4mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_BKG_DownType_SFpA,
                ME_qq_Z4l_BKG_UpType_SFpA);
    }

    // 	if (da.fs == final_2mu || da.fs == final_2muA) {
    // 		/// Mass for the muons
    // 		params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    // 		if (d.production == prod_no && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_NO(
    //                 da, false, ME_Z4l_BKG_2l);
    //
    // 		if (d.production == prod_no && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_NO(
    //                 da, true, ME_Z4l_BKG_2lpA);
    //
    // 		if (d.production == prod_gg && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_gg(
    //                 da, false, ME_gg_Z4l_BKG__2l);
    //
    // 		if (d.production == prod_gg && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_gg(
    //                 da, true, ME_gg_Z4l_BKG__2lpA);
    //
    // 		if (d.production == prod_qq && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_qqbar(
    //                 da, false, ME_qq_Z4l_BKG_DownType_2l,
    //                 ME_qq_Z4l_BKG_UpType_2l);
    //
    // 		if (d.production == prod_qq && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_qqbar(
    //                 da, true, ME_qq_Z4l_BKG_DownType_2lpA,
    //                 ME_qq_Z4l_BKG_UpType_2lpA);
    // 	}

    return 1;
}

/// Z4l Signal ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_SIG(const process_description &d, data &da)
{
    if (d.production == prod_no) {
        cerr << "Z -> 4l gg initial state is not supported.\n";
        return 1;
    }
    if (d.production == prod_gg) {
        cerr << "Z -> 4l productionless state is not supported.\n";
        return 1;
    }
    if (da.fs == final_2mu || da.fs == final_2muA) {
        cerr << "Z -> 4l to 2 lepton is pointless. Run Drell-Yan (DY) instead "
                "(ZZ-based).\n";
        return 1;
    }

    if (da.fs == final_4e || da.fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.e);

        // 		if (d.production == prod_no && da.fs == final_4e)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_Z4l_SIG_SF);
        //
        // 		if (d.production == prod_no && da.fs == final_4eA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_SIG_SFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_4e)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_SIG_SF);
        //
        // 		if (d.production == prod_gg && da.fs == final_4eA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_SIG_SFpA);

        if (d.production == prod_qq && da.fs == final_4e)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4eA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_SIG_DownType_SFpA,
                ME_qq_Z4l_SIG_UpType_SFpA);
    }

    if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
        /// Common mass for the opposite-flavor leptons
        params_MG.set_block_entry("mass", 11, da.m.e);
        params_MG.set_block_entry("mass", 13, da.m.mu);

        // 		if (d.production == prod_no && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false ME_Z4l_SIG_OF);
        //
        // 		if (d.production == prod_no && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_SIG_OFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_SIG_OF);
        //
        // 		if (d.production == prod_gg && da.fs == final_2e2muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_SIG_OFpA);

        if (d.production == prod_qq && da.fs == final_2e2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_SIG_DownType_OF, ME_qq_Z4l_SIG_UpType_OF);

        if (d.production == prod_qq && da.fs == final_2e2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_SIG_DownType_OFpA,
                ME_qq_Z4l_SIG_UpType_OFpA);
    }

    if (da.fs == final_4mu || da.fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        // 		if (d.production == prod_no && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, false, ME_Z4l_SIG_SF);
        //
        // 		if (d.production == prod_no && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_NO(
        //                 da, true, ME_Z4l_SIG_SFpA);
        //
        // 		if (d.production == prod_gg && da.fs == final_4mu)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_gg_Z4l_SIG_SF);
        //
        // 		if (d.production == prod_gg && da.fs == final_4muA)
        // 			return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_gg_Z4l_SIG_SFpA);

        if (d.production == prod_qq && da.fs == final_4mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

        if (d.production == prod_qq && da.fs == final_4muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_qq_Z4l_SIG_DownType_SFpA,
                ME_qq_Z4l_SIG_UpType_SFpA);
    }

    // 	if (da.fs == final_2mu || da.fs == final_2muA) {
    // 		/// Mass for the muons
    // 		params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    // 		if (d.production == prod_no && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_NO(
    //                 da, false, ME_Z4l_SIG_2l);
    //
    // 		if (d.production == prod_no && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_NO(
    //                 da, true, ME_Z4l_SIG_2lpA);
    //
    // 		if (d.production == prod_gg && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_gg(
    //                 da, false, ME_gg_Z4l_SIG__2l);
    //
    // 		if (d.production == prod_gg && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_gg(
    //                 da, true, ME_gg_Z4l_SIG__2lpA);
    //
    // 		if (d.production == prod_qq && da.fs == final_2mu)
    // 			return Run_MEs_Evaluator_Initial_State_qqbar(
    //                 da, false, ME_qq_Z4l_SIG_DownType_2l,
    //                 ME_qq_Z4l_SIG_UpType_2l);
    //
    // 		if (d.production == prod_qq && da.fs == final_2muA)
    // 			return Run_MEs_Evaluator_Initial_State_qqbar(
    //                 da, true, ME_qq_Z4l_SIG_DownType_2lpA,
    //                 ME_qq_Z4l_SIG_UpType_2lpA);
    // 	}

    return 1;
}

/// Spin-0 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin0(const process_description &d, data &da)
{
    if (d.production == prod_qq) {
        cerr << "Spin-0 qqbar initial state is redundant, thus not provided.\n";
        return 1;
    }

    //     if (d.decay == decay_ZZ) {
    //         if (da.fs == final_4e || da.fs == final_4eA) {
    //             /// Common mass for the same-flavor leptons
    //             params_MG.set_block_entry("mass", 13, da.m.e);
    //
    //             if (d.production == prod_no && da.fs == final_4e)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, false,
    //                                                           ME_Signal_Spin0_SF);
    //
    //             if (d.production == prod_no && da.fs == final_4eA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, true,
    //                                                           ME_Signal_Spin0_SFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_4e)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_SF);
    //
    //             if (d.production == prod_gg && da.fs == final_4eA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_SFpA);
    //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4e)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, false,
    //             ME_Signal_qq_Spin0_DownType_SF,
    //             //                     ME_Signal_qq_Spin0_UpType_SF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4eA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, true,
    //             ME_Signal_qq_Spin0_DownType_SFpA,
    //             //                     ME_Signal_qq_Spin0_UpType_SFpA);
    //         }
    //
    //         if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
    //             /// Common mass for the opposite-flavor leptons
    //             params_MG.set_block_entry("mass", 11, da.m.e);
    //             params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    //             if (d.production == prod_no && da.fs == final_2e2mu)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, false,
    //                                                           ME_Signal_Spin0_OF);
    //
    //             if (d.production == prod_no && da.fs == final_2e2muA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, true,
    //                                                           ME_Signal_Spin0_OFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_2e2mu)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_OF);
    //
    //             if (d.production == prod_gg && da.fs == final_2e2muA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_OFpA);
    //
    //             //             if (d.production == prod_qq && da.fs ==
    //             final_2e2mu)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, false,
    //             ME_Signal_qq_Spin0_DownType_OF,
    //             //                     ME_Signal_qq_Spin0_UpType_OF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_2e2muA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, true,
    //             ME_Signal_qq_Spin0_DownType_OFpA,
    //             //                     ME_Signal_qq_Spin0_UpType_OFpA);
    //         }
    //
    //         if (da.fs == final_4mu || da.fs == final_4muA) {
    //             /// Common mass for the same-flavor leptons
    //             params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    //             if (d.production == prod_no && da.fs == final_4mu)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, false,
    //                                                           ME_Signal_Spin0_SF);
    //
    //             if (d.production == prod_no && da.fs == final_4muA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(da, true,
    //                                                           ME_Signal_Spin0_SFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_4mu)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_SF);
    //
    //             if (d.production == prod_gg && da.fs == final_4muA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_SFpA);
    //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4mu)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, false,
    //             ME_Signal_qq_Spin0_DownType_SF,
    //             //                     ME_Signal_qq_Spin0_UpType_SF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4muA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             //                     da, true,
    //             ME_Signal_qq_Spin0_DownType_SFpA,
    //             //                     ME_Signal_qq_Spin0_UpType_SFpA);
    //         }
    //     }
    //
    //     if (d.decay == decay_2f) {
    //         if (da.fs == final_4e || da.fs == final_4eA) {
    //             /// Common mass for the same-flavor leptons
    //             params_MG.set_block_entry("mass", 13, da.m.e);
    //
    //             if (d.production == prod_no && da.fs == final_4e)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, false, ME_Signal_Spin0_2f_SF);
    //
    //             if (d.production == prod_no && da.fs == final_4eA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, true, ME_Signal_Spin0_2f_SFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_4e)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_2f_SF);
    //
    //             if (d.production == prod_gg && da.fs == final_4eA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_2f_SFpA);
    //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4e)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, false,
    //             // ME_Signal_qq_Spin0_2f_DownType_SF,
    //             // ME_Signal_qq_Spin0_2f_UpType_SF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4eA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, true,
    //             // ME_Signal_qq_Spin0_2f_DownType_SFpA,
    //             // ME_Signal_qq_Spin0_2f_UpType_SFpA);
    //         }
    //
    //         if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
    //             /// Common mass for the opposite-flavor leptons
    //             params_MG.set_block_entry("mass", 11, da.m.e);
    //             params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    //             if (d.production == prod_no && da.fs == final_2e2mu)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, false, ME_Signal_Spin0_2f_OF);
    //
    //             if (d.production == prod_no && da.fs == final_2e2muA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, true, ME_Signal_Spin0_2f_OFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_2e2mu)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_2f_OF);
    //
    //             if (d.production == prod_gg && da.fs == final_2e2muA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_2f_OFpA);
    //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_2e2mu)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, false,
    //             // ME_Signal_qq_Spin0_2f_DownType_OF,
    //             // ME_Signal_qq_Spin0_2f_UpType_OF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_2e2muA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, true,
    //             // ME_Signal_qq_Spin0_2f_DownType_OFpA,
    //             // ME_Signal_qq_Spin0_2f_UpType_OFpA);
    //         }
    //
    //         if (da.fs == final_4mu || da.fs == final_4muA) {
    //             /// Common mass for the same-flavor leptons
    //             params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    //             if (d.production == prod_no && da.fs == final_4mu)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, false, ME_Signal_Spin0_2f_SF);
    //
    //             if (d.production == prod_no && da.fs == final_4muA)
    //                 return Run_MEs_Evaluator_Initial_State_NO(
    //                     da, true, ME_Signal_Spin0_2f_SFpA);
    //
    //             if (d.production == prod_gg && da.fs == final_4mu)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, false, ME_Signal_gg_Spin0_2f_SF);
    //
    //             if (d.production == prod_gg && da.fs == final_4muA)
    //                 return Run_MEs_Evaluator_Initial_State_gg(
    //                     da, true, ME_Signal_gg_Spin0_2f_SFpA);
    //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4mu)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, false,
    //             // ME_Signal_qq_Spin0_2f_DownType_SF,
    //             // ME_Signal_qq_Spin0_2f_UpType_SF);
    //             //
    //             // 			if (d.production == prod_qq && da.fs ==
    //             final_4muA)
    //             // 				return
    //             Run_MEs_Evaluator_Initial_State_qqbar(
    //             // da, true,
    //             // ME_Signal_qq_Spin0_2f_DownType_SFpA,
    //             // ME_Signal_qq_Spin0_2f_UpType_SFpA);
    //         }
    //     }
    //
    //     if (da.fs == final_2mu || da.fs == final_2muA) {
    //         /// Mass for the muons
    //         params_MG.set_block_entry("mass", 13, da.m.mu);
    //
    //         if (d.production == prod_no && da.fs == final_2mu)
    //             return Run_MEs_Evaluator_Initial_State_NO(da, false,
    //                                                       ME_Signal_Spin0_2l);
    //
    //         if (d.production == prod_no && da.fs == final_2muA)
    //             return Run_MEs_Evaluator_Initial_State_NO(da, true,
    //                                                       ME_Signal_Spin0_2lpA);
    //
    //         if (d.production == prod_gg && da.fs == final_2mu)
    //             return Run_MEs_Evaluator_Initial_State_gg(da, false,
    //                                                       ME_Signal_gg_Spin0_2l);
    //
    //         if (d.production == prod_gg && da.fs == final_2muA)
    //             return Run_MEs_Evaluator_Initial_State_gg(da, true,
    //                                                       ME_Signal_gg_Spin0_2lpA);
    //
    //         // 		if (d.production == prod_qq && da.fs == final_2mu)
    //         // 			return Run_MEs_Evaluator_Initial_State_qqbar(da,
    //         false,
    //         // ME_Signal_qq_Spin0_DownType_2l, ME_Signal_qq_Spin0_UpType_2l);
    //
    //         // 		if (d.production == prod_qq && da.fs == final_2muA)
    //         // 			return Run_MEs_Evaluator_Initial_State_qqbar(da,
    //         true,
    //         // ME_Signal_qq_Spin0_DownType_2lpA,
    //         ME_Signal_qq_Spin0_UpType_2lpA);
    //     }

    return 1;
}

/// Spin-1 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin1(const process_description &d, data &da)
{
    if (d.production == prod_gg) {
        cerr << "Spin-1 gg initial state is not possible, thus not provided.\n";
        return 1;
    }

    if (d.decay == decay_ZZ) {
        if (da.fs == final_4e || da.fs == final_4eA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin1_SF);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin1_SFpA);

            // 			if (d.production == prod_gg && da.fs == final_4e)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_SF);
            //
            // 			if (d.production == prod_gg && da.fs == final_4eA)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_SFpA);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_DownType_SF,
                    ME_Signal_qq_Spin1_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_DownType_SFpA,
                    ME_Signal_qq_Spin1_UpType_SFpA);
        }

        if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
            /// Common mass for the opposite-flavor leptons
            params_MG.set_block_entry("mass", 11, da.m.e);
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin1_OF);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin1_OFpA);

            //	 		if (d.production == prod_gg && da.fs == final_2e2mu)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_OF);
            //
            // 			if (d.production == prod_gg && da.fs == final_2e2muA)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_OFpA);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_DownType_OF,
                    ME_Signal_qq_Spin1_UpType_OF);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_DownType_OFpA,
                    ME_Signal_qq_Spin1_UpType_OFpA);
        }

        if (da.fs == final_4mu || da.fs == final_4muA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin1_SF);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin1_SFpA);

            // 			if (d.production == prod_gg && da.fs == final_4mu)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_SF);
            //
            // 			if (d.production == prod_gg && da.fs == final_4muA)
            //	 			return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_SFpA);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_DownType_SF,
                    ME_Signal_qq_Spin1_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_DownType_SFpA,
                    ME_Signal_qq_Spin1_UpType_SFpA);
        }
    }

    if (d.decay == decay_2f) {
        if (da.fs == final_4e || da.fs == final_4eA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin1_2f_SF);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin1_2f_SFpA);

            // 			if (d.production == prod_gg && da.fs == final_4e)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_2f_SF);
            //
            // 			if (d.production == prod_gg && da.fs == final_4eA)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_2f_SFpA);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_2f_DownType_SF,
                    ME_Signal_qq_Spin1_2f_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
                    ME_Signal_qq_Spin1_2f_UpType_SFpA);
        }

        if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
            /// Common mass for the opposite-flavor leptons
            params_MG.set_block_entry("mass", 11, da.m.e);
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin1_2f_OF);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin1_2f_OFpA);

            //	 		if (d.production == prod_gg && da.fs == final_2e2mu)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_2f_OF);
            //
            // 			if (d.production == prod_gg && da.fs == final_2e2muA)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_2f_OFpA);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_2f_DownType_OF,
                    ME_Signal_qq_Spin1_2f_UpType_OF);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_2f_DownType_OFpA,
                    ME_Signal_qq_Spin1_2f_UpType_OFpA);
        }

        if (da.fs == final_4mu || da.fs == final_4muA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin1_2f_SF);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin1_2f_SFpA);

            // 			if (d.production == prod_gg && da.fs == final_4mu)
            // 				return Run_MEs_Evaluator_Initial_State_gg(
            // da, false,
            // ME_Signal_gg_Spin1_2f_SF);
            //
            // 			if (d.production == prod_gg && da.fs == final_4muA)
            //	 			return Run_MEs_Evaluator_Initial_State_gg(
            // da, true,
            // ME_Signal_gg_Spin1_2f_SFpA);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin1_2f_DownType_SF,
                    ME_Signal_qq_Spin1_2f_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
                    ME_Signal_qq_Spin1_2f_UpType_SFpA);
        }
    }

    if (da.fs == final_2mu || da.fs == final_2muA) {
        /// Mass for the muons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        if (d.production == prod_no && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                      ME_Signal_Spin1_2l);

        if (d.production == prod_no && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                      ME_Signal_Spin1_2lpA);

        //         if (d.production == prod_gg && da.fs == final_2mu)
        //             return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, false, ME_Signal_gg_Spin1_2l);
        //
        //         if (d.production == prod_gg && da.fs == final_2muA)
        //             return Run_MEs_Evaluator_Initial_State_gg(
        //                 da, true, ME_Signal_gg_Spin1_2lpA);

        if (d.production == prod_qq && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_Signal_qq_Spin1_DownType_2l,
                ME_Signal_qq_Spin1_UpType_2l);

        if (d.production == prod_qq && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_Signal_qq_Spin1_DownType_2lpA,
                ME_Signal_qq_Spin1_UpType_2lpA);
    }

    return 1;
}

/// Spin-2 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin2(const process_description &d, data &da)
{
    if (d.decay == decay_ZZ) {
        if (da.fs == final_4e || da.fs == final_4eA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin2_SF);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin2_SFpA);

            if (d.production == prod_gg && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_SF);

            if (d.production == prod_gg && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_SFpA);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_DownType_SF,
                    ME_Signal_qq_Spin2_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_DownType_SFpA,
                    ME_Signal_qq_Spin2_UpType_SFpA);
        }

        if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
            /// Common mass for the opposite-flavor leptons
            params_MG.set_block_entry("mass", 11, da.m.e);
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin2_OF);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin2_OFpA);

            if (d.production == prod_gg && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_OF);

            if (d.production == prod_gg && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_OFpA);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_DownType_OF,
                    ME_Signal_qq_Spin2_UpType_OF);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_DownType_OFpA,
                    ME_Signal_qq_Spin2_UpType_OFpA);
        }

        if (da.fs == final_4mu || da.fs == final_4muA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                          ME_Signal_Spin2_SF);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                          ME_Signal_Spin2_SFpA);

            if (d.production == prod_gg && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_SF);

            if (d.production == prod_gg && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_SFpA);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_DownType_SF,
                    ME_Signal_qq_Spin2_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_DownType_SFpA,
                    ME_Signal_qq_Spin2_UpType_SFpA);
        }
    }

    if (d.decay == decay_2f) {
        if (da.fs == final_4e || da.fs == final_4eA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.e);

            if (d.production == prod_no && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin2_2f_SF);

            if (d.production == prod_no && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin2_2f_SFpA);

            if (d.production == prod_gg && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_2f_SF);

            if (d.production == prod_gg && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_2f_SFpA);

            if (d.production == prod_qq && da.fs == final_4e)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_2f_DownType_SF,
                    ME_Signal_qq_Spin2_2f_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4eA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
                    ME_Signal_qq_Spin2_2f_UpType_SFpA);
        }

        if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
            /// Common mass for the opposite-flavor leptons
            params_MG.set_block_entry("mass", 11, da.m.e);
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin2_2f_OF);

            if (d.production == prod_no && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin2_2f_OFpA);

            if (d.production == prod_gg && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_2f_OF);

            if (d.production == prod_gg && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_2f_OFpA);

            if (d.production == prod_qq && da.fs == final_2e2mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_2f_DownType_OF,
                    ME_Signal_qq_Spin2_2f_UpType_OF);

            if (d.production == prod_qq && da.fs == final_2e2muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_2f_DownType_OFpA,
                    ME_Signal_qq_Spin2_2f_UpType_OFpA);
        }

        if (da.fs == final_4mu || da.fs == final_4muA) {
            /// Common mass for the same-flavor leptons
            params_MG.set_block_entry("mass", 13, da.m.mu);

            if (d.production == prod_no && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, false, ME_Signal_Spin2_2f_SF);

            if (d.production == prod_no && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_NO(
                    da, true, ME_Signal_Spin2_2f_SFpA);

            if (d.production == prod_gg && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, false, ME_Signal_gg_Spin2_2f_SF);

            if (d.production == prod_gg && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_gg(
                    da, true, ME_Signal_gg_Spin2_2f_SFpA);

            if (d.production == prod_qq && da.fs == final_4mu)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, false, ME_Signal_qq_Spin2_2f_DownType_SF,
                    ME_Signal_qq_Spin2_2f_UpType_SF);

            if (d.production == prod_qq && da.fs == final_4muA)
                return Run_MEs_Evaluator_Initial_State_qqbar(
                    da, true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
                    ME_Signal_qq_Spin2_2f_UpType_SFpA);
        }
    }

    if (da.fs == final_2mu || da.fs == final_2muA) {
        /// Mass for the muons
        params_MG.set_block_entry("mass", 13, da.m.mu);

        if (d.production == prod_no && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_NO(da, false,
                                                      ME_Signal_Spin2_2l);

        if (d.production == prod_no && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_NO(da, true,
                                                      ME_Signal_Spin2_2lpA);

        if (d.production == prod_gg && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_gg(da, false,
                                                      ME_Signal_gg_Spin2_2l);

        if (d.production == prod_gg && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_gg(da, true,
                                                      ME_Signal_gg_Spin2_2lpA);

        if (d.production == prod_qq && da.fs == final_2mu)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, false, ME_Signal_qq_Spin2_DownType_2l,
                ME_Signal_qq_Spin2_UpType_2l);

        if (d.production == prod_qq && da.fs == final_2muA)
            return Run_MEs_Evaluator_Initial_State_qqbar(
                da, true, ME_Signal_qq_Spin2_DownType_2lpA,
                ME_Signal_qq_Spin2_UpType_2lpA);
    }

    return 1;
}

template <class Generic_MEKD_ME>
int MEKD::Run_MEs_Evaluator_Initial_State_NO(data &da, const bool photon,
                                             Generic_MEKD_ME &Generic_ME)
{
    Signal_ME = 0;

    /// No initial state block
    double buffer_p[4];
    for (unsigned int count = 0; count < 4; ++count)
        buffer_p[count] = da.p[0][count];

    if (!photon) {
        da.p[0][0] = da.p[2][0] + da.p[3][0] + da.p[4][0] + da.p[5][0];
        da.p[0][1] = da.p[2][1] + da.p[3][1] + da.p[4][1] + da.p[5][1];
        da.p[0][2] = da.p[2][2] + da.p[3][2] + da.p[4][2] + da.p[5][2];
        da.p[0][3] = da.p[2][3] + da.p[3][3] + da.p[4][3] + da.p[5][3];

        double *buffer = da.p[1];
        for (unsigned int count = 0; count < 4; ++count)
            da.p[count + 1] = da.p[count + 2];
        da.p[5] = buffer;
    } else {
        da.p[0][0] =
            da.p[2][0] + da.p[3][0] + da.p[4][0] + da.p[5][0] + da.p[6][0];
        da.p[0][1] =
            da.p[2][1] + da.p[3][1] + da.p[4][1] + da.p[5][1] + da.p[6][1];
        da.p[0][2] =
            da.p[2][2] + da.p[3][2] + da.p[4][2] + da.p[5][2] + da.p[6][2];
        da.p[0][3] =
            da.p[2][3] + da.p[3][3] + da.p[4][3] + da.p[5][3] + da.p[6][3];

        double *buffer = da.p[1];
        for (unsigned int count = 0; count < 5; ++count)
            da.p[count + 1] = da.p[count + 2];
        da.p[6] = buffer;
    }

    Generic_ME.updateProc(params_MG);
    Generic_ME.setMomenta(da.p);
    Generic_ME.sigmaKin();
    const double *buffer = Generic_ME.getMatrixElements();

    Signal_ME = buffer[0];

    if (!photon) {
        double *buffer = da.p[5];
        for (unsigned int count = 4; count > 0; --count)
            da.p[count + 1] = da.p[count];
        da.p[1] = buffer;
    } else {
        double *buffer = da.p[6];
        for (unsigned int count = 5; count > 0; --count)
            da.p[count + 1] = da.p[count];
        da.p[1] = buffer;
    }

    for (unsigned int count = 0; count < 4; ++count)
        da.p[0][count] = buffer_p[count];

    return 0;
}

template <class Generic_MEKD_ME>
int MEKD::Run_MEs_Evaluator_Initial_State_gg(data &da, const bool photon,
                                             Generic_MEKD_ME &Generic_ME)
{
    Signal_ME = 0;

    /// gg block
    da.p[0][3] = da.p[0][0];
    da.p[1][3] = -da.p[1][0];

    Generic_ME.updateProc(params_MG);
    Generic_ME.setMomenta(da.p);
    Generic_ME.sigmaKin();
    const double *buffer = Generic_ME.getMatrixElements();

    if (flag.Use_PDF_w_pT0) {
        Signal_ME = pdfreader(21, da.PDFx1, da.m.sys) *
                    pdfreader(21, da.PDFx2, da.m.sys) * buffer[0];
    } else
        Signal_ME = buffer[0];

    return 0;
}

template <class Generic_MEKD_ME_s, class Generic_MEKD_ME_c>
int MEKD::Run_MEs_Evaluator_Initial_State_qqbar(data &da, const bool photon,
                                                Generic_MEKD_ME_s &Generic_ME_s,
                                                Generic_MEKD_ME_c &Generic_ME_c)
{
    Signal_ME = 0;

    /// Down quark block. Down type (s-like)
    if (flag.use_prod_ddx && !flag.use_prod_2013_convetion_for_4l) {
        params_MG.set_block_entry("mass", 3, da.m.d);
        // 		params_MG.set_block_entry("heff", 15, da.c.rhod01);
        // 		params_MG.set_block_entry("heff", 16, da.c.rhod02);
        params_MG.set_block_entry("vec", 15, da.c.rhod11);
        params_MG.set_block_entry("vec", 16, da.c.rhod12);
        params_MG.set_block_entry("vec", 17, da.c.rhod13);
        params_MG.set_block_entry("vec", 18, da.c.rhod14);
        params_MG.set_block_entry("gravity", 33, da.c.rhod21);
        params_MG.set_block_entry("gravity", 34, da.c.rhod22);
        params_MG.set_block_entry("gravity", 35, da.c.rhod23);
        params_MG.set_block_entry("gravity", 36, da.c.rhod24);
        da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - da.m.d * da.m.d);
        da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - da.m.d * da.m.d);

        Generic_ME_s.updateProc(params_MG);
        Generic_ME_s.setMomenta(da.p);
        Generic_ME_s.sigmaKin();
        const double *buffer = Generic_ME_s.getMatrixElements();

        if (flag.Use_PDF_w_pT0) {
            const double ME_value1 = buffer[0] *
                                     pdfreader(1, da.PDFx1, da.m.sys) *
                                     pdfreader(-1, da.PDFx2, da.m.sys);
            Signal_ME = (ME_value1 +
                         buffer[1] * pdfreader(-1, da.PDFx1, da.m.sys) *
                             pdfreader(1, da.PDFx2, da.m.sys));
        } else
            Signal_ME = (buffer[0] + buffer[1]);
    }

    /// Strange quark block. Down type (s-like)
    if (flag.use_prod_ssx && !flag.use_prod_2013_convetion_for_4l) {
        params_MG.set_block_entry("mass", 3, da.m.s);
        // 		params_MG.set_block_entry("heff", 15, da.c.rhos01);
        // 		params_MG.set_block_entry("heff", 16, da.c.rhos02);
        params_MG.set_block_entry("vec", 15, da.c.rhos11);
        params_MG.set_block_entry("vec", 16, da.c.rhos12);
        params_MG.set_block_entry("vec", 17, da.c.rhos13);
        params_MG.set_block_entry("vec", 18, da.c.rhos14);
        params_MG.set_block_entry("gravity", 33, da.c.rhos21);
        params_MG.set_block_entry("gravity", 34, da.c.rhos22);
        params_MG.set_block_entry("gravity", 35, da.c.rhos23);
        params_MG.set_block_entry("gravity", 36, da.c.rhos24);
        da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - da.m.s * da.m.s);
        da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - da.m.s * da.m.s);

        Generic_ME_s.updateProc(params_MG);
        Generic_ME_s.setMomenta(da.p);
        Generic_ME_s.sigmaKin();
        const double *buffer = Generic_ME_s.getMatrixElements();

        if (flag.Use_PDF_w_pT0) {
            const double ME_value1 = buffer[0] *
                                     pdfreader(3, da.PDFx1, da.m.sys) *
                                     pdfreader(-3, da.PDFx2, da.m.sys);
            Signal_ME += (ME_value1 +
                          buffer[1] * pdfreader(-3, da.PDFx1, da.m.sys) *
                              pdfreader(3, da.PDFx2, da.m.sys));
        } else
            Signal_ME += (buffer[0] + buffer[1]);
    }

    /// Up quark block. Up type (c-like)
    if (flag.use_prod_uux || flag.use_prod_2013_convetion_for_4l) {
        params_MG.set_block_entry("mass", 4, da.m.u);
        // 		params_MG.set_block_entry("heff", 11, da.c.rhou01);
        // 		params_MG.set_block_entry("heff", 12, da.c.rhou02);
        params_MG.set_block_entry("vec", 7, da.c.rhou11);
        params_MG.set_block_entry("vec", 8, da.c.rhou12);
        params_MG.set_block_entry("vec", 9, da.c.rhou13);
        params_MG.set_block_entry("vec", 10, da.c.rhou14);
        params_MG.set_block_entry("gravity", 25, da.c.rhou21);
        params_MG.set_block_entry("gravity", 26, da.c.rhou22);
        params_MG.set_block_entry("gravity", 27, da.c.rhou23);
        params_MG.set_block_entry("gravity", 28, da.c.rhou24);
        da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - da.m.u * da.m.u);
        da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - da.m.u * da.m.u);

        Generic_ME_c.updateProc(params_MG);
        Generic_ME_c.setMomenta(da.p);
        Generic_ME_c.sigmaKin();
        const double *buffer = Generic_ME_c.getMatrixElements();

        if (flag.Use_PDF_w_pT0) {
            const double ME_value1 = buffer[0] *
                                     pdfreader(2, da.PDFx1, da.m.sys) *
                                     pdfreader(-2, da.PDFx2, da.m.sys);
            Signal_ME += (ME_value1 +
                          buffer[1] * pdfreader(-2, da.PDFx1, da.m.sys) *
                              pdfreader(2, da.PDFx2, da.m.sys));
        } else
            Signal_ME += (buffer[0] + buffer[1]);
    }

    /// Charm quark block. Up type (c-like)
    if (flag.use_prod_ccx && !flag.use_prod_2013_convetion_for_4l) {
        params_MG.set_block_entry("mass", 4, da.m.c);
        // 		params_MG.set_block_entry("heff", 11, da.c.rhoc01);
        // 		params_MG.set_block_entry("heff", 12, da.c.rhoc02);
        params_MG.set_block_entry("vec", 7, da.c.rhoc11);
        params_MG.set_block_entry("vec", 8, da.c.rhoc12);
        params_MG.set_block_entry("vec", 9, da.c.rhoc13);
        params_MG.set_block_entry("vec", 10, da.c.rhoc14);
        params_MG.set_block_entry("gravity", 25, da.c.rhoc21);
        params_MG.set_block_entry("gravity", 26, da.c.rhoc22);
        params_MG.set_block_entry("gravity", 27, da.c.rhoc23);
        params_MG.set_block_entry("gravity", 28, da.c.rhoc24);
        da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - da.m.c * da.m.c);
        da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - da.m.c * da.m.c);

        Generic_ME_c.updateProc(params_MG);
        Generic_ME_c.setMomenta(da.p);
        Generic_ME_c.sigmaKin();
        const double *buffer = Generic_ME_c.getMatrixElements();

        if (flag.Use_PDF_w_pT0) {
            const double ME_value1 = buffer[0] *
                                     pdfreader(4, da.PDFx1, da.m.sys) *
                                     pdfreader(-4, da.PDFx2, da.m.sys);
            Signal_ME += (ME_value1 +
                          buffer[1] * pdfreader(-4, da.PDFx1, da.m.sys) *
                              pdfreader(4, da.PDFx2, da.m.sys));
        } else
            Signal_ME += (buffer[0] + buffer[1]);
    }

    // return to real mass. Used in Z -> 4l
    if (flag.Use_mZ4l_eq_m4l)
        params_MG.set_block_entry("mass", 23, da.m.Z);

    return 0;
}

/// end of namespace
}

#endif
////////////////////////////////
/// END OF MEKD_RunMEs.cpp   ///
////////////////////////////////