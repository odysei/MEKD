/*
 *
 * Configurators for Parameters classes.
 *
 *
 */
#ifndef Parameters_configurators_h
#define Parameters_configurators_h

#include "MEKD.h"

namespace mekd
{

template <class Parameters>
inline void Configurator_lep_m(const data &da, Parameters *update);
inline void Configurator_lep_m(const data &da, double &m_e, double &m_mu);

/*
 * HEF_MEKD (HEF_UFO, HZZ_Unitary) configuration block
 */

/// A ZZ background configurators for Parameters_MEKD
void Configurator_ZZ_ddx(const data &da, Parameters_MEKD *update);
void Configurator_ZZ_uux(const data &da, Parameters_MEKD *update);
void Configurator_ZZ_ssx(const data &da, Parameters_MEKD *update);
void Configurator_ZZ_ccx(const data &da, Parameters_MEKD *update);
void Configurator_ZZ_bbx(const data &da, Parameters_MEKD *update);

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const complex<double> *c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_MEKD *update);
inline void Configurator_Spin0_produ(const complex<double> *c,
                                     const bool fixed_prod, const double lgg,
                                     Parameters_MEKD *update);
inline void Configurator_Spin0_decay(const complex<double> *c, const double mZ,
                                     const double Mi, const double hZZ,
                                     Parameters_MEKD *update);

/*
 * HiggsPO_UFO configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const MG5_HiggsPO_UFO::couplings &c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_HiggsPO_UFO *update);
inline void Configurator_Spin0_produ(const double lgg,
                                     Parameters_HiggsPO_UFO *update);
inline void Configurator_Spin0_decay(const MG5_HiggsPO_UFO::couplings &c,
                                     const MG5_HiggsPO_UFO::couplings_ex &ci,
                                     const final_state_types_ fs,
                                     Parameters_HiggsPO_UFO *update);

/*
 * sm-full configuration block
 */

void Configurator_Spin0(const data &da, const parameters &param,
                        const flags &flag, Parameters_sm_full *update);

/*
 * HEFTU (heft_updated-full) configuration block
 */

void Configurator_Spin0(const data &da, const parameters &param,
                        const flags &flag, Parameters_HEFTU *update);

/*
 * Leptophilic_UFO configuration block
 */

/// Spin-1 configurators for Parameters_Leptophilic_UFO
void Configurator_Spin1_ddx(const data &da, Parameters_Leptophilic_UFO *update);
void Configurator_Spin1_uux(const data &da, Parameters_Leptophilic_UFO *update);
void Configurator_Spin1_ssx(const data &da, Parameters_Leptophilic_UFO *update);
void Configurator_Spin1_ccx(const data &da, Parameters_Leptophilic_UFO *update);
void Configurator_Spin1_bbx(const data &da, Parameters_Leptophilic_UFO *update);

/// end of namespace
} // namespace mekd

#endif
