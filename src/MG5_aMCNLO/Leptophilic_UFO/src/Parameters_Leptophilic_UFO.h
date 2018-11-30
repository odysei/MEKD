//==========================================================================
// This file has been automatically generated for C++
// MadGraph5_aMC@NLO v. 2.6.3.2, 2018-06-22
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef Parameters_Leptophilic_UFO_H
#define Parameters_Leptophilic_UFO_H

#include <complex>

#include "MG5_aMCNLO/Commons/read_slha_MEKD.h"

class Parameters_Leptophilic_UFO
{
  public:
    static Parameters_Leptophilic_UFO *getInstance();

    // Define "zero"
    double zero, ZERO;
    // Model parameters independent of aS
    double mdl_ZpW, mdl_WH, mdl_WW, mdl_WZ, mdl_WT, mdl_GZptaR, mdl_GZptaL,
        mdl_GZpmuR, mdl_GZpmuL, mdl_GZpeR, mdl_GZpeL, mdl_ymtau, mdl_ymm,
        mdl_yme, mdl_ymt, mdl_ymb, mdl_ymc, mdl_yms, mdl_ymup, mdl_ymdo, aS,
        mdl_Gf, aEWM1, mdl_ZpM, mdl_MH, mdl_MZ, mdl_MTA, mdl_MMU, mdl_Me,
        mdl_MT, mdl_MB, mdl_MC, mdl_MS, mdl_MU, mdl_MD, mdl_MZ__exp__2,
        mdl_MZ__exp__4, mdl_sqrt__2, mdl_MH__exp__2, mdl_aEW, mdl_MW,
        mdl_sqrt__aEW, mdl_ee, mdl_MW__exp__2, mdl_sw2, mdl_cw, mdl_sqrt__sw2,
        mdl_sw;
    //         mdl_g1, mdl_gw, mdl_vev, mdl_cabi, mdl_sin__cabi, mdl_cos__cabi
    //         mdl_vev__exp__2, mdl_lam, mdl_yb, mdl_yc, mdl_ydo, mdl_ye,
    //         mdl_ym, mdl_ys, mdl_yt, mdl_ytau, mdl_yup, mdl_muH,
    //         mdl_ee__exp__2, mdl_sw__exp__2, mdl_cw__exp__2;
    std::complex<double> mdl_complexi;
    //     mdl_CKM1x1, mdl_CKM1x2, mdl_CKM1x3, mdl_CKM2x1,
    //         mdl_CKM2x2, mdl_CKM2x3, mdl_CKM3x1, mdl_CKM3x2, mdl_CKM3x3,
    //         mdl_conjg__CKM1x1, mdl_conjg__CKM1x2, mdl_conjg__CKM1x3,
    //         mdl_conjg__CKM2x1, mdl_conjg__CKM2x2, mdl_conjg__CKM2x3,
    //         mdl_conjg__CKM3x1, mdl_conjg__CKM3x2, mdl_conjg__CKM3x3;
    // Model parameters dependent on aS
    double mdl_sqrt__aS, G, mdl_G__exp__2;
    // Model couplings independent of aS
    std::complex<double> GC_1, GC_2, GC_3, GC_29, GC_30, GC_33, GC_34, GC_9,
        GC_10, GC_11, GC_12;
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
    static Parameters_Leptophilic_UFO *instance;
};

#endif // Parameters_Leptophilic_UFO_H
