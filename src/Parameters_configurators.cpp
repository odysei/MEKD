/*
 *
 * Configurators for Parameters classes.
 *
 *
 */
#ifndef Parameters_configurators_cpp
#define Parameters_configurators_cpp

#include "MEKD/Parameters_configurators.h"
#include "MEKD.h"
/// MEKD tools
#include "MEKD_CalcHEP_Extra_functions.h"
#include "higgs_properties/hggeffective.h"

using namespace std;

namespace mekd
{

template <class Parameters>
inline void Configurator_lep_m(const data &da, Parameters *update)
{
    const auto fs = da.fs;
    if (fs == final_4e || fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        update->mdl_MM = da.m.e;
        return;
    }

    if (fs == final_4mu || fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        update->mdl_MM = da.m.mu;
        return;
    }

    if (fs == final_2e2mu || fs == final_2e2muA) {
        /// Masses for the opposite-flavor leptons
        update->mdl_Me = da.m.e;
        update->mdl_MM = da.m.mu;
        return;
    }
}

inline void Configurator_lep_m(const data &da, double &m_e, double &m_mu)
{
    const auto fs = da.fs;
    if (fs == final_4e || fs == final_4eA) {
        /// Common mass for the same-flavor leptons
        m_mu = da.m.e;
        return;
    }

    if (fs == final_4mu || fs == final_4muA) {
        /// Common mass for the same-flavor leptons
        m_mu = da.m.mu;
        return;
    }

    if (fs == final_2e2mu || fs == final_2e2muA) {
        /// Masses for the opposite-flavor leptons
        m_e = da.m.e;
        m_mu = da.m.mu;
        return;
    }
}

/*
 * HEF_MEKD (HEF_UFO, HZZ_Unitary) configuration block
 */

/// A ZZ background configurators for Parameters_MEKD
void Configurator_ZZ_ddx(const data &da, Parameters_MEKD *update)
{
    Configurator_lep_m(da, update);
    update->mdl_MS = da.m.s;
}

void Configurator_ZZ_uux(const data &da, Parameters_MEKD *update)
{
    Configurator_lep_m(da, update);
    update->mdl_MC = da.m.u;
}

void Configurator_ZZ_ssx(const data &da, Parameters_MEKD *update)
{
    Configurator_lep_m(da, update);
    update->mdl_MS = da.m.s;
}

void Configurator_ZZ_ccx(const data &da, Parameters_MEKD *update)
{
    Configurator_lep_m(da, update);
    update->mdl_MC = da.m.c;
}

void Configurator_ZZ_bbx(const data &da, Parameters_MEKD *update)
{
    Configurator_lep_m(da, update);
    update->mdl_MS = da.m.b;
}

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const complex<double> *c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_MEKD *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double mZ = da.m.Z;
    const double M = da.m.sys; // system's invariant mass
    double wH = 1;
    const double hZZ = param.hZZ_coupling;
    double lgg; // lambda hgg

    Configurator_lep_m(da, update);

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
    }
    update->mdl_WH = wH;

    if (flag.Vary_signal_couplings) {
        Configurator_Spin0_produ(c, flag.Fix_Spin0_Production, lgg, update);

        if (flag.use_mX_eq_Mdec)
            Configurator_Spin0_decay(c, mZ, M, hZZ, update);
        else
            Configurator_Spin0_decay(c, mZ, mH, hZZ, update);
    }
}

inline void Configurator_Spin0_produ(const complex<double> *c,
                                     const bool fixed_prod, const double lgg,
                                     Parameters_MEKD *update)
{
    // gg
    const complex<double> common_coupl = complex<double>(4 * lgg, 0);
    if (fixed_prod) {
        update->g1g = complex<double>(0, 0);
        update->g2g = common_coupl; // Spin0Pm
        update->g3g = complex<double>(0, 0);
        update->g4g = complex<double>(0, 0); // Spin0M
    } else {
        update->g1g = complex<double>(0, 0);
        update->g2g = (c[0] + c[1] + c[2]) * common_coupl; // Spin0Pm
        update->g3g = complex<double>(0, 0);
        update->g4g = c[3] * common_coupl; // Spin0M
    }
}

inline void Configurator_Spin0_decay(const complex<double> *c, const double mZ,
                                     const double Mi, const double hZZ,
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
 * HiggsPO_UFO configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const MG5_HiggsPO_UFO::couplings &c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_HiggsPO_UFO *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double M = da.m.sys; // system's invariant mass
    double wH = 1;
    double lgg; // lambda hgg

    Configurator_lep_m(da, update);

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
    }
    update->mdl_WH = wH;

    if (flag.Vary_signal_couplings) {
        Configurator_Spin0_produ(lgg, update);
        Configurator_Spin0_decay(c, da.c_HPO, da.fs, update);
    }
}

inline void Configurator_Spin0_produ(const double lgg,
                                     Parameters_HiggsPO_UFO *update)
{
    // gg. * -i WRT HEF_MEKD
    update->GC_9 = complex<double>(0, -4 * lgg);
}

inline void Configurator_Spin0_decay(const MG5_HiggsPO_UFO::couplings &c,
                                     const MG5_HiggsPO_UFO::couplings_ex &ci,
                                     const final_state_types_ fs,
                                     Parameters_HiggsPO_UFO *update)
{
    // XZZ
    update->mdl_kZZ = c.kZZ;
    update->mdl_eZZ = c.eZZ;
    update->mdl_eZZCP = c.eZZCP;

    // XZA
    update->mdl_kZA = c.kZA;
    update->mdl_lZACP = c.lZACP;

    // XAA
    update->mdl_kAA = c.kAA;
    update->mdl_lAACP = c.lAACP;

    // Z'll
    update->mdl_eZeL = c.eZeL;
    update->mdl_eZeR = c.eZeR;
    if (fs == final_4e || fs == final_4eA) {
        update->mdl_eZmuL = c.eZeL;
        update->mdl_eZmuR = c.eZeR;
    } else {
        update->mdl_eZmuL = c.eZmuL;
        update->mdl_eZmuR = c.eZmuR;
    }

    // 'SM' Z
    update->mdl_gZeL = ci.gZeL;
    update->mdl_gZeR = ci.gZeR;
    if (fs == final_4e || fs == final_4eA) {
        update->mdl_gZmuL = ci.gZeL;
        update->mdl_gZmuR = ci.gZeR;
    } else {
        update->mdl_gZmuL = ci.gZmuL;
        update->mdl_gZmuR = ci.gZmuR;
    }
}

/*
 * sm-full configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_sm_full
void Configurator_Spin0(const data &da, const parameters &param,
                        const flags &flag, Parameters_sm_full *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double M = da.m.bbx; // subsystem's invariant mass
    double wH = 1;

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
    }
    update->mdl_WH = wH;
}

/*
 * HEFTU (heft_updated-full) configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_sm_full
void Configurator_Spin0(const data &da, const parameters &param,
                        const flags &flag, Parameters_HEFTU *update)
{
    // local copy for stack
    const double mH = param.Higgs_mass;
    const double M = da.m.bbx; // subsystem's invariant mass
    double wH = 1;

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
    }
    update->mdl_WH = wH;
}

/*
 * Leptophilic_UFO configuration block
 */

/// Spin-1 configurators for Parameters_Leptophilic_UFO
void Configurator_Spin1_ddx(const data &da, Parameters_Leptophilic_UFO *update)
{
    Configurator_lep_m(da, update->mdl_Me, update->mdl_MMU);
    update->mdl_MS = da.m.s;
}

void Configurator_Spin1_uux(const data &da, Parameters_Leptophilic_UFO *update)
{
    Configurator_lep_m(da, update->mdl_Me, update->mdl_MMU);
    update->mdl_MC = da.m.u;
}

void Configurator_Spin1_ssx(const data &da, Parameters_Leptophilic_UFO *update)
{
    Configurator_lep_m(da, update->mdl_Me, update->mdl_MMU);
    update->mdl_MS = da.m.s;
}

void Configurator_Spin1_ccx(const data &da, Parameters_Leptophilic_UFO *update)
{
    Configurator_lep_m(da, update->mdl_Me, update->mdl_MMU);
    update->mdl_MC = da.m.c;
}

void Configurator_Spin1_bbx(const data &da, Parameters_Leptophilic_UFO *update)
{
    Configurator_lep_m(da, update->mdl_Me, update->mdl_MMU);
    update->mdl_MS = da.m.b;
}

/// end of namespace
} // namespace mekd

#endif
