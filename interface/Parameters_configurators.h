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

/*
 * HEF_MEKD configuration block
 */

/// A generic spin-0 resonance configurator for Parameters_MEKD
void Configurator_Spin0(const complex<double> *c, const data &da,
                        const parameters &param, const flags &flag,
                        Parameters_MEKD *update);
void Configurator_Spin0_produ(const complex<double> *c, const bool fixed_prod,
                              const double lgg, Parameters_MEKD *update);
void Configurator_Spin0_decay(const complex<double> *c, const double mZ,
                              const double Mi, const double hZZ,
                              Parameters_MEKD *update);

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

/// end of namespace
}

#endif