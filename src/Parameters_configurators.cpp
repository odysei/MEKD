/*
 *
 * Configurators for Parameters classes.
 *
 *
 */
#ifndef Parameters_configurators_cpp
#define Parameters_configurators_cpp

#include "MEKD.h"

namespace mekd
{

/*
 * HEF_MEKD configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const complex<double> *c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_MEKD *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double mZ = da.m.Z;
    const double M = da.m.sys; // system's invariant mass
    double wH;
    const double hZZ = param.hZZ_coupling;
    double lgg;         // lambda hgg

    if (flag.use_mX_eq_Mdec) {
        update->mdl_MH = M;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));

        lgg = LmbdGG(M);
    } else {
        update->mdl_MH = mH;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));

        lgg = LmbdGG(mH);
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    } else
        wH = 1;
    update->mdl_WH = wH;

    if (flag.Vary_signal_couplings) {
        Configurator_Spin0_produ(c, flag.Fix_Spin0_Production, lgg, update);

        if (flag.use_mX_eq_Mdec)
            Configurator_Spin0_decay(c, mZ, M, hZZ, update);
        else
            Configurator_Spin0_decay(c, mZ, mH, hZZ, update);
    }
}

void Configurator_Spin0_produ(const complex<double> *c, const bool fixed_prod,
                              const double lgg,
                              Parameters_MEKD *update)
{
    // gg
    const complex<double> common_coupl = complex<double>(4 * lgg, 0);
    if (fixed_prod) {
        update->g1g = complex<double>(0, 0);
        update->g2g = common_coupl; // Spin0Pm
        update->g3g = complex<double>(0, 0);
        update->g4g = complex<double>(0, 0);    // Spin0M
    } else {
        update->g1g = complex<double>(0, 0);
        update->g2g = (c[0] + c[1] + c[2]) * common_coupl; // Spin0Pm
        update->g3g = complex<double>(0, 0);
        update->g4g = c[3] * common_coupl;    // Spin0M
    }
}

void Configurator_Spin0_decay(const complex<double> *c,
                              const double mZ, const double Mi,
                              const double hZZ,
                              Parameters_MEKD *update)
{
    // Decay to ZZ
    const complex<double> chZZ = complex<double>(hZZ, 0);
    const complex<double> chZZ_o2 = complex<double>(hZZ / mZ / mZ, 0);
    const complex<double> chZZ_o4k = chZZ_o2 / Mi / Mi;
    
    update->g1z = c[0] * chZZ;     // Spin0Pm
    update->g2z = c[1] * chZZ_o2;  // Spin0Ph
    update->g3z = c[2] * chZZ_o4k; // Spin0Ph+
    update->g4z = c[3] * chZZ_o2;  // Spin0M

    // Decay to 2l (or 2mu in 2f)
    const complex<double> hmumu = complex<double>(4.291210e-04, 0);
    update->rhomu01 = c[0] * hmumu;
    update->rhomu02 = c[1] * hmumu;

    // Decay to 2e (2f)
    // for Hee should be 2.075371e-06
    update->rhoe01 = c[0] * hmumu;
    update->rhoe02 = c[1] * hmumu;
}

/*
 * sm-full configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_sm_full
void Configurator_Spin0(const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_sm_full *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double M = da.m.bbx;  // subsystem's invariant mass
    double wH;

    if (flag.use_mX_eq_Mdec) {
        update->mdl_MH = M;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));
    } else {
        update->mdl_MH = mH;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    } else
        wH = 1;
    update->mdl_WH = wH;
}

/*
 * HEFTU (heft_updated-full) configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_sm_full
void Configurator_Spin0(const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_HEFTU *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double M = da.m.bbx;  // subsystem's invariant mass
    double wH;

    if (flag.use_mX_eq_Mdec) {
        update->mdl_MH = M;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));
    } else {
        update->mdl_MH = mH;

        if (flag.Use_Higgs_width && flag.Vary_resonance_width)
            wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));
    }

    if (flag.Use_Higgs_width) {
        if (!flag.Vary_resonance_width)
            wH = param.Higgs_width;
    } else
        wH = 1;
    update->mdl_WH = wH;
}

/// end of namespace
}

#endif