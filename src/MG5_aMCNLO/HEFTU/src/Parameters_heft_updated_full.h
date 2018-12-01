//==========================================================================
// This file has been automatically generated for C++
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef Parameters_heft_updated_full_H
#define Parameters_heft_updated_full_H

#include <complex>

#include "MG5_aMCNLO/Commons/read_slha_MEKD.h"

class Parameters_HEFTU
{
  public:
    static Parameters_HEFTU *getInstance();

    // Define "zero"
    double zero, ZERO;
    // Model parameters independent of aS
    double mdl_WH1, mdl_WH, mdl_WW, mdl_WZ, mdl_WTau, mdl_WT, mdl_ymtau,
        mdl_ymt, mdl_ymb, mdl_etaWS, mdl_rhoWS, mdl_AWS, mdl_lamWS, aS, mdl_Gf,
        aEWM1, mdl_MP, mdl_MH, mdl_MZ, mdl_MTA, mdl_MM, mdl_Me, mdl_MT, mdl_MB,
        mdl_MC, mdl_MS, mdl_MU, mdl_MD, mdl_lamWS__exp__2, mdl_lamWS__exp__3,
        mdl_MZ__exp__2, mdl_MZ__exp__4, mdl_sqrt__2, mdl_MH__exp__4,
        mdl_MT__exp__4, mdl_MH__exp__2, mdl_MT__exp__2, mdl_MH__exp__12,
        mdl_MH__exp__10, mdl_MH__exp__8, mdl_MH__exp__6, mdl_MT__exp__6,
        mdl_aEW, mdl_MW, mdl_sqrt__aEW, mdl_ee, mdl_MW__exp__2, mdl_sw2, mdl_cw,
        mdl_sqrt__sw2, mdl_sw, mdl_g1, mdl_gw, mdl_v, mdl_ee__exp__2,
        mdl_MW__exp__12, mdl_MW__exp__10, mdl_MW__exp__8, mdl_MW__exp__6,
        mdl_MW__exp__4, mdl_AH, mdl_v__exp__2, mdl_lam, mdl_yb, mdl_yt,
        mdl_ytau, mdl_muH, mdl_gw__exp__2, mdl_cw__exp__2, mdl_sw__exp__2,
        mdl_ymm, mdl_yme, mdl_ymc;
    std::complex<double> mdl_CKM1x1, mdl_CKM1x2, mdl_complexi, mdl_CKM1x3,
        mdl_CKM2x1, mdl_CKM2x2, mdl_CKM2x3, mdl_CKM3x1, mdl_CKM3x2, mdl_CKM3x3,
        mdl_conjg__CKM1x1, mdl_conjg__CKM1x2, mdl_conjg__CKM1x3,
        mdl_conjg__CKM2x1, mdl_conjg__CKM2x2, mdl_conjg__CKM2x3,
        mdl_conjg__CKM3x1, mdl_conjg__CKM3x2, mdl_conjg__CKM3x3;
    // Model parameters dependent on aS
    double mdl_sqrt__aS, G, mdl_G__exp__2, mdl_GH, mdl_Gphi;
    // Model couplings independent of aS
    std::complex<double> GC_1, GC_2, GC_3, GC_33, GC_36, GC_37, GC_38, GC_39,
        GC_40, GC_41, GC_53, GC_74, GC_80, GC_90, GC_94, GC_96, GC_98, GC_100;
    // Model couplings dependent on aS
    std::complex<double> GC_14, GC_13, GC_12, GC_11, GC_10;

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
    static Parameters_HEFTU *instance;
};

#endif // Parameters_heft_updated_full_H
