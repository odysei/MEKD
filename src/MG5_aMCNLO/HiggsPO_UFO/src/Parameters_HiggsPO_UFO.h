//==========================================================================
// This file has been automatically generated for C++
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef Parameters_HiggsPO_UFO_H
#define Parameters_HiggsPO_UFO_H

#include <complex>

#include "MG5_aMCNLO/Commons/read_slha_MEKD.h"

class Parameters_HiggsPO_UFO
{
  public:
    static Parameters_HiggsPO_UFO *getInstance();

    // Define "zero"
    double zero, ZERO;
    // Model parameters independent of aS
    double mdl_WH, mdl_WW, mdl_WZ, mdl_WT, mdl_gWtau, mdl_gWmu, mdl_gWe,
        mdl_gZv, mdl_gZtauR, mdl_gZmuR, mdl_gZeR, mdl_gZtauL, mdl_gZmuL,
        mdl_gZeL, aS, mdl_Gf, aEWM1, mdl_MH, mdl_MW, mdl_MZ, mdl_MTA, mdl_MM,
        mdl_Me, mdl_MT, mdl_MB, mdl_MC, mdl_ymueff, mdl_ytaueff, mdl_yceff,
        mdl_ybeff, mdl_eZASM, mdl_eAASM, mdl_phiWtau, mdl_phiWmu, mdl_phiWe,
        mdl_eWtau, mdl_eWmu, mdl_eWe, mdl_eZv, mdl_eZtauR, mdl_eZmuR, mdl_eZeR,
        mdl_eZtauL, mdl_eZmuL, mdl_eZeL, mdl_eWWCP, mdl_eZZCP, mdl_lZACP,
        mdl_lAACP, mdl_eWW, mdl_eZZ, mdl_kZA, mdl_kAA, mdl_kWW, mdl_kZZ,
        mdl_lmu, mdl_ltau, mdl_lc, mdl_lb, mdl_kmu, mdl_ktau, mdl_kc, mdl_kb,
        mdl_eggSM, mdl_noise, mdl_MW__exp__2, mdl_MZ__exp__2, mdl_sqrt__2,
        mdl_cos__phiWe, mdl_sin__phiWe, mdl_cos__phiWmu, mdl_sin__phiWmu,
        mdl_cos__phiWtau, mdl_sin__phiWtau, mdl_aEW, mdl_sqrt__aEW, mdl_ee,
        mdl_vev;
    std::complex<double> mdl_complexi;
    // Model parameters dependent on aS
    double mdl_sqrt__aS, G, mdl_G__exp__2;
    // Model couplings independent of aS
    std::complex<double> GC_3, GC_8, GC_9, GC_12, GC_13, GC_14, GC_15, GC_19,
        GC_20, GC_23, GC_24, GC_25, GC_26, GC_30, GC_31, GC_32, GC_33;
    // Model couplings dependent on aS

    // Set parameters that are unchanged during the run
    void setIndependentParameters(SLHAReader_MEKD &slha);
    // Set couplings that are unchanged during the run
    void setIndependentCouplings();
    // Set parameters that are changed event by event
    void setDependentParameters();
    // Set couplings that are changed event by event
    void setDependentCouplings();

    // Print parameters that are unchanged during the run
    void printIndependentParameters();
    // Print couplings that are unchanged during the run
    void printIndependentCouplings();
    // Print parameters that are changed event by event
    void printDependentParameters();
    // Print couplings that are changed event by event
    void printDependentCouplings();

  private:
    static Parameters_HiggsPO_UFO *instance;
};

#endif // Parameters_HiggsPO_UFO_H
