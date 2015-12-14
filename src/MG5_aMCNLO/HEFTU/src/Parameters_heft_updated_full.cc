//==========================================================================
// This file has been automatically generated for C++ by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include <iostream>
#include <iomanip>
#include "Parameters_heft_updated_full.h"

// Initialize static instance
Parameters_HEFTU * Parameters_HEFTU::instance = NULL;

// Function to get static instance - only one instance per program
Parameters_HEFTU * Parameters_HEFTU::getInstance()
{
    if (instance == NULL)
        instance = new Parameters_HEFTU();

    return instance;
}

void Parameters_HEFTU::setIndependentParameters(SLHAReader_MEKD &slha)
{
    // Define "zero"
    zero = 0;
    ZERO = 0;
    // Prepare a vector for indices
    vector<int> indices(2, 0);
    mdl_WH1 = slha.get_block_entry("decay", 9000006, 5.753088e-03).real();
    mdl_WH = slha.get_block_entry("decay", 25, 6.382339e-03).real();
    mdl_WW = slha.get_block_entry("decay", 24, 2.047600e+00).real();
    mdl_WZ = slha.get_block_entry("decay", 23, 2.441404e+00).real();
    mdl_WTau = slha.get_block_entry("decay", 15, 2.270000e-12).real();
    mdl_WT = slha.get_block_entry("decay", 6, 1.508336e+00).real();
    mdl_ymtau = slha.get_block_entry("yukawa", 15, 1.777000e+00).real();
    mdl_ymm = slha.get_block_entry("yukawa", 13, 1.056600e-01).real();
    mdl_yme = slha.get_block_entry("yukawa", 11, 5.110000e-04).real();
    mdl_ymt = slha.get_block_entry("yukawa", 6, 1.645000e+02).real();
    mdl_ymb = slha.get_block_entry("yukawa", 5, 4.200000e+00).real();
    mdl_ymc = slha.get_block_entry("yukawa", 4, 1.270000e+00).real();
    mdl_etaWS = slha.get_block_entry("wolfenstein", 4, 3.410000e-01).real();
    mdl_rhoWS = slha.get_block_entry("wolfenstein", 3, 1.320000e-01).real();
    mdl_AWS = slha.get_block_entry("wolfenstein", 2, 8.080000e-01).real();
    mdl_lamWS = slha.get_block_entry("wolfenstein", 1, 2.253000e-01).real();
    aS = slha.get_block_entry("sminputs", 3, 1.180000e-01).real();
    mdl_Gf = slha.get_block_entry("sminputs", 2, 1.166390e-05).real();
    aEWM1 = slha.get_block_entry("sminputs", 1, 1.325070e+02).real();
    mdl_MH = slha.get_block_entry("mass", 25, 1.250000e+02).real();
    mdl_MZ = slha.get_block_entry("mass", 23, 9.118800e+01).real();
    mdl_MTA = slha.get_block_entry("mass", 15, 1.777000e+00).real();
    mdl_MM = slha.get_block_entry("mass", 13, 1.056600e-01).real();
    mdl_Me = slha.get_block_entry("mass", 11, 5.110000e-04).real();
    mdl_MT = slha.get_block_entry("mass", 6, 1.720000e+02).real();
    mdl_MB = slha.get_block_entry("mass", 5, 4.700000e+00).real();
    mdl_MC = slha.get_block_entry("mass", 4, 1.270000e+00).real();
    mdl_MS = slha.get_block_entry("mass", 3, 9.350000e-02).real();
    mdl_MU = slha.get_block_entry("mass", 2, 2.150000e-03).real();
    mdl_MD = slha.get_block_entry("mass", 1, 4.700000e-03).real();
    mdl_lamWS__exp__2 = pow(mdl_lamWS, 2.);
    mdl_CKM1x1 = 1. - mdl_lamWS__exp__2/2.;
    mdl_CKM1x2 = mdl_lamWS;
    mdl_complexi = std::complex<double> (0., 1.);
    mdl_lamWS__exp__3 = pow(mdl_lamWS, 3.);
    mdl_CKM1x3 = mdl_AWS * mdl_lamWS__exp__3 * (-(mdl_etaWS * mdl_complexi) +
            mdl_rhoWS);
    mdl_CKM2x1 = -mdl_lamWS;
    mdl_CKM2x2 = 1. - mdl_lamWS__exp__2/2.;
    mdl_CKM2x3 = mdl_AWS * mdl_lamWS__exp__2;
    mdl_CKM3x1 = mdl_AWS * mdl_lamWS__exp__3 * (1. - mdl_etaWS * mdl_complexi -
            mdl_rhoWS);
    mdl_CKM3x2 = -(mdl_AWS * mdl_lamWS__exp__2);
    mdl_CKM3x3 = 1.;
    mdl_MZ__exp__2 = pow(mdl_MZ, 2.);
    mdl_MZ__exp__4 = pow(mdl_MZ, 4.);
    mdl_sqrt__2 = sqrt(2.);
    mdl_MT__exp__4 = pow(mdl_MT, 4.);
    mdl_MT__exp__2 = pow(mdl_MT, 2.);
    mdl_MT__exp__6 = pow(mdl_MT, 6.);
    mdl_conjg__CKM1x1 = conj(mdl_CKM1x1);
    mdl_conjg__CKM1x2 = conj(mdl_CKM1x2);
    mdl_conjg__CKM1x3 = conj(mdl_CKM1x3);
    mdl_conjg__CKM2x1 = conj(mdl_CKM2x1);
    mdl_conjg__CKM2x2 = conj(mdl_CKM2x2);
    mdl_conjg__CKM2x3 = conj(mdl_CKM2x3);
    mdl_conjg__CKM3x1 = conj(mdl_CKM3x1);
    mdl_conjg__CKM3x2 = conj(mdl_CKM3x2);
    mdl_conjg__CKM3x3 = conj(mdl_CKM3x3);
    mdl_aEW = 1./aEWM1;
    mdl_MW = sqrt(mdl_MZ__exp__2/2. + sqrt(mdl_MZ__exp__4/4. - (mdl_aEW * M_PI *
            mdl_MZ__exp__2)/(mdl_Gf * mdl_sqrt__2)));
    mdl_sqrt__aEW = sqrt(mdl_aEW);
    mdl_ee = 2. * mdl_sqrt__aEW * sqrt(M_PI);
    mdl_MW__exp__2 = pow(mdl_MW, 2.);
    mdl_sw2 = 1. - mdl_MW__exp__2/mdl_MZ__exp__2;
    mdl_cw = sqrt(1. - mdl_sw2);
    mdl_sqrt__sw2 = sqrt(mdl_sw2);
    mdl_sw = mdl_sqrt__sw2;
    mdl_g1 = mdl_ee/mdl_cw;
    mdl_gw = mdl_ee/mdl_sw;
    mdl_v = (2. * mdl_MW * mdl_sw)/mdl_ee;
    mdl_ee__exp__2 = pow(mdl_ee, 2.);
    mdl_MW__exp__12 = pow(mdl_MW, 12.);
    mdl_MW__exp__10 = pow(mdl_MW, 10.);
    mdl_MW__exp__8 = pow(mdl_MW, 8.);
    mdl_MW__exp__6 = pow(mdl_MW, 6.);
    mdl_MW__exp__4 = pow(mdl_MW, 4.);
    mdl_v__exp__2 = pow(mdl_v, 2.);
    mdl_yb = (mdl_ymb * mdl_sqrt__2)/mdl_v;
    mdl_yt = (mdl_ymt * mdl_sqrt__2)/mdl_v;
    mdl_ytau = (mdl_ymtau * mdl_sqrt__2)/mdl_v;
    mdl_gw__exp__2 = pow(mdl_gw, 2.);
    mdl_cw__exp__2 = pow(mdl_cw, 2.);
    mdl_sw__exp__2 = pow(mdl_sw, 2.);
}
void Parameters_HEFTU::setIndependentCouplings()
{
    GC_2 = -(mdl_ee * mdl_complexi)/3.;
    GC_3 = (2. * mdl_ee * mdl_complexi)/3.;
    GC_33 = (mdl_CKM1x3 * mdl_ee * mdl_complexi)/(mdl_sw * mdl_sqrt__2);
    GC_36 = (mdl_CKM2x3 * mdl_ee * mdl_complexi)/(mdl_sw * mdl_sqrt__2);
    GC_37 = (mdl_CKM3x1 * mdl_ee * mdl_complexi)/(mdl_sw * mdl_sqrt__2);
    GC_38 = (mdl_CKM3x2 * mdl_ee * mdl_complexi)/(mdl_sw * mdl_sqrt__2);
    GC_39 = (mdl_CKM3x3 * mdl_ee * mdl_complexi)/(mdl_sw * mdl_sqrt__2);
    GC_40 = -(mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    GC_41 = (mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    GC_53 = -(mdl_ee * mdl_complexi * mdl_sw)/(6. * mdl_cw);
    GC_74 = -((mdl_complexi * mdl_yb)/mdl_sqrt__2);
    GC_80 = -((mdl_complexi * mdl_yt)/mdl_sqrt__2);
    GC_90 = (mdl_ee * mdl_complexi * mdl_conjg__CKM1x3)/(mdl_sw * mdl_sqrt__2);
    GC_94 = (mdl_ee * mdl_complexi * mdl_conjg__CKM2x3)/(mdl_sw * mdl_sqrt__2);
    GC_96 = (mdl_ee * mdl_complexi * mdl_conjg__CKM3x1)/(mdl_sw * mdl_sqrt__2);
    GC_98 = (mdl_ee * mdl_complexi * mdl_conjg__CKM3x2)/(mdl_sw * mdl_sqrt__2);
    GC_100 = (mdl_ee * mdl_complexi * mdl_conjg__CKM3x3)/(mdl_sw * mdl_sqrt__2);
}
void Parameters_HEFTU::setDependentParameters()
{
    // changes because variations in couplings and particles
    mdl_MH__exp__2 = pow(mdl_MH, 2.);
    mdl_MH__exp__4 = pow(mdl_MH, 4.);
    mdl_MH__exp__6 = pow(mdl_MH, 6.);
    mdl_MH__exp__8 = pow(mdl_MH, 8.);
    mdl_MH__exp__10 = pow(mdl_MH, 10.);
    mdl_MH__exp__12 = pow(mdl_MH, 12.);
    
    mdl_AH = (47. * mdl_ee__exp__2 * (1. - (2. * mdl_MH__exp__4)/(987. *
            mdl_MT__exp__4) - (14. * mdl_MH__exp__2)/(705. * mdl_MT__exp__2) + (213.
            * mdl_MH__exp__12)/(2.634632e7 * mdl_MW__exp__12) + (5. *
            mdl_MH__exp__10)/(119756. * mdl_MW__exp__10) + (41. *
            mdl_MH__exp__8)/(180950. * mdl_MW__exp__8) + (87. *
            mdl_MH__exp__6)/(65800. * mdl_MW__exp__6) + (57. * mdl_MH__exp__4)/(6580.
            * mdl_MW__exp__4) + (33. * mdl_MH__exp__2)/(470. * mdl_MW__exp__2)))/(72.
            * pow(M_PI, 2.) * mdl_v);
    mdl_lam = mdl_MH__exp__2/(2. * mdl_v__exp__2);
    mdl_muH = sqrt(mdl_lam * mdl_v__exp__2);
    
    mdl_sqrt__aS = sqrt(aS);
    G = 2. * mdl_sqrt__aS * sqrt(M_PI);
    mdl_G__exp__2 = pow(G, 2.);
    mdl_GH = -(mdl_G__exp__2 * (1. + (13. * mdl_MH__exp__6)/(16800. *
            mdl_MT__exp__6) + mdl_MH__exp__4/(168. * mdl_MT__exp__4) + (7. *
            mdl_MH__exp__2)/(120. * mdl_MT__exp__2)))/(12. * pow(M_PI, 2.) * mdl_v);
    mdl_Gphi = -(mdl_G__exp__2 * (1. + mdl_MH__exp__6/(560. * mdl_MT__exp__6) +
            mdl_MH__exp__4/(90. * mdl_MT__exp__4) + mdl_MH__exp__2/(12. *
            mdl_MT__exp__2)))/(8. * pow(M_PI, 2.) * mdl_v);
}
void Parameters_HEFTU::setDependentCouplings()
{
    GC_14 = -(G * mdl_GH);
    GC_13 = -(mdl_complexi * mdl_GH);
    GC_12 = mdl_complexi * mdl_G__exp__2;
    GC_11 = mdl_complexi * G;
    GC_10 = -G;
    
    GC_1 = -(mdl_AH * mdl_complexi);
}

// Routines for printing out parameters
void Parameters_HEFTU::printIndependentParameters()
{
    cout <<    "heft_updated_full model parameters independent of event kinematics:" <<
            endl;
    cout << setw(20) <<    "mdl_WH1 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WH1 << endl;
    cout << setw(20) <<    "mdl_WH " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WH << endl;
    cout << setw(20) <<    "mdl_WW " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WW << endl;
    cout << setw(20) <<    "mdl_WZ " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WZ << endl;
    cout << setw(20) <<    "mdl_WTau " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WTau << endl;
    cout << setw(20) <<    "mdl_WT " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_WT << endl;
    cout << setw(20) <<    "mdl_ymtau " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_ymtau << endl;
    cout << setw(20) <<    "mdl_ymt " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_ymt << endl;
    cout << setw(20) <<    "mdl_ymb " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_ymb << endl;
    cout << setw(20) <<    "mdl_etaWS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_etaWS << endl;
    cout << setw(20) <<    "mdl_rhoWS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_rhoWS << endl;
    cout << setw(20) <<    "mdl_AWS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_AWS << endl;
    cout << setw(20) <<    "mdl_lamWS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_lamWS << endl;
    cout << setw(20) <<    "aS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << aS << endl;
    cout << setw(20) <<    "mdl_Gf " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_Gf << endl;
    cout << setw(20) <<    "aEWM1 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << aEWM1 << endl;
    cout << setw(20) <<    "mdl_MP " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MP << endl;
    cout << setw(20) <<    "mdl_MH " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MH << endl;
    cout << setw(20) <<    "mdl_MZ " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MZ << endl;
    cout << setw(20) <<    "mdl_MTA " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MTA << endl;
    cout << setw(20) <<    "mdl_MM " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MM << endl;
    cout << setw(20) <<    "mdl_Me " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_Me << endl;
    cout << setw(20) <<    "mdl_MT " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MT << endl;
    cout << setw(20) <<    "mdl_MB " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MB << endl;
    cout << setw(20) <<    "mdl_MC " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MC << endl;
    cout << setw(20) <<    "mdl_MS " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MS << endl;
    cout << setw(20) <<    "mdl_MU " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MU << endl;
    cout << setw(20) <<    "mdl_MD " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MD << endl;
    cout << setw(20) <<    "mdl_lamWS__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_lamWS__exp__2 << endl;
    cout << setw(20) <<    "mdl_CKM1x1 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM1x1 << endl;
    cout << setw(20) <<    "mdl_CKM1x2 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM1x2 << endl;
    cout << setw(20) <<    "mdl_complexi " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_complexi << endl;
    cout << setw(20) <<    "mdl_lamWS__exp__3 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_lamWS__exp__3 << endl;
    cout << setw(20) <<    "mdl_CKM1x3 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM1x3 << endl;
    cout << setw(20) <<    "mdl_CKM2x1 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM2x1 << endl;
    cout << setw(20) <<    "mdl_CKM2x2 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM2x2 << endl;
    cout << setw(20) <<    "mdl_CKM2x3 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM2x3 << endl;
    cout << setw(20) <<    "mdl_CKM3x1 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM3x1 << endl;
    cout << setw(20) <<    "mdl_CKM3x2 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM3x2 << endl;
    cout << setw(20) <<    "mdl_CKM3x3 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_CKM3x3 << endl;
    cout << setw(20) <<    "mdl_MZ__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MZ__exp__2 << endl;
    cout << setw(20) <<    "mdl_MZ__exp__4 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MZ__exp__4 << endl;
    cout << setw(20) <<    "mdl_sqrt__2 " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_sqrt__2 << endl;
    cout << setw(20) <<    "mdl_MH__exp__4 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__4 << endl;
    cout << setw(20) <<    "mdl_MT__exp__4 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MT__exp__4 << endl;
    cout << setw(20) <<    "mdl_MH__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__2 << endl;
    cout << setw(20) <<    "mdl_MT__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MT__exp__2 << endl;
    cout << setw(20) <<    "mdl_MH__exp__12 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__12 << endl;
    cout << setw(20) <<    "mdl_MH__exp__10 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__10 << endl;
    cout << setw(20) <<    "mdl_MH__exp__8 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__8 << endl;
    cout << setw(20) <<    "mdl_MH__exp__6 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MH__exp__6 << endl;
    cout << setw(20) <<    "mdl_MT__exp__6 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MT__exp__6 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM1x1 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM1x1 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM1x2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM1x2 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM1x3 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM1x3 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM2x1 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM2x1 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM2x2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM2x2 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM2x3 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM2x3 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM3x1 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM3x1 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM3x2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM3x2 << endl;
    cout << setw(20) <<    "mdl_conjg__CKM3x3 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_conjg__CKM3x3 << endl;
    cout << setw(20) <<    "mdl_aEW " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_aEW << endl;
    cout << setw(20) <<    "mdl_MW " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_MW << endl;
    cout << setw(20) <<    "mdl_sqrt__aEW " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_sqrt__aEW << endl;
    cout << setw(20) <<    "mdl_ee " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_ee << endl;
    cout << setw(20) <<    "mdl_MW__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__2 << endl;
    cout << setw(20) <<    "mdl_sw2 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_sw2 << endl;
    cout << setw(20) <<    "mdl_cw " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_cw << endl;
    cout << setw(20) <<    "mdl_sqrt__sw2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_sqrt__sw2 << endl;
    cout << setw(20) <<    "mdl_sw " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_sw << endl;
    cout << setw(20) <<    "mdl_g1 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_g1 << endl;
    cout << setw(20) <<    "mdl_gw " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_gw << endl;
    cout << setw(20) <<    "mdl_v " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_v << endl;
    cout << setw(20) <<    "mdl_ee__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_ee__exp__2 << endl;
    cout << setw(20) <<    "mdl_MW__exp__12 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__12 << endl;
    cout << setw(20) <<    "mdl_MW__exp__10 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__10 << endl;
    cout << setw(20) <<    "mdl_MW__exp__8 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__8 << endl;
    cout << setw(20) <<    "mdl_MW__exp__6 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__6 << endl;
    cout << setw(20) <<    "mdl_MW__exp__4 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__4 << endl;
    cout << setw(20) <<    "mdl_AH " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_AH << endl;
    cout << setw(20) <<    "mdl_v__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_v__exp__2 << endl;
    cout << setw(20) <<    "mdl_lam " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_lam << endl;
    cout << setw(20) <<    "mdl_yb " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_yb << endl;
    cout << setw(20) <<    "mdl_yt " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_yt << endl;
    cout << setw(20) <<    "mdl_ytau " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_ytau << endl;
    cout << setw(20) <<    "mdl_muH " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_muH << endl;
    cout << setw(20) <<    "mdl_gw__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_gw__exp__2 << endl;
    cout << setw(20) <<    "mdl_cw__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_cw__exp__2 << endl;
    cout << setw(20) <<    "mdl_sw__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_sw__exp__2 << endl;
}
void Parameters_HEFTU::printIndependentCouplings()
{
    cout <<    "heft_updated_full model couplings independent of event kinematics:"
            << endl;
    cout << setw(20) <<    "GC_1 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_1 << endl;
    cout << setw(20) <<    "GC_2 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_2 << endl;
    cout << setw(20) <<    "GC_3 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_3 << endl;
    cout << setw(20) <<    "GC_33 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_33 << endl;
    cout << setw(20) <<    "GC_36 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_36 << endl;
    cout << setw(20) <<    "GC_37 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_37 << endl;
    cout << setw(20) <<    "GC_38 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_38 << endl;
    cout << setw(20) <<    "GC_39 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_39 << endl;
    cout << setw(20) <<    "GC_40 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_40 << endl;
    cout << setw(20) <<    "GC_41 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_41 << endl;
    cout << setw(20) <<    "GC_53 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_53 << endl;
    cout << setw(20) <<    "GC_74 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_74 << endl;
    cout << setw(20) <<    "GC_80 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_80 << endl;
    cout << setw(20) <<    "GC_90 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_90 << endl;
    cout << setw(20) <<    "GC_94 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_94 << endl;
    cout << setw(20) <<    "GC_96 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_96 << endl;
    cout << setw(20) <<    "GC_98 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_98 << endl;
    cout << setw(20) <<    "GC_100 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_100 << endl;
}
void Parameters_HEFTU::printDependentParameters()
{
    cout <<    "heft_updated_full model parameters dependent on event kinematics:"
            << endl;
    cout << setw(20) <<    "mdl_sqrt__aS " <<    "= " << setiosflags(ios::scientific)
            << setw(10) << mdl_sqrt__aS << endl;
    cout << setw(20) <<    "G " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << G << endl;
    cout << setw(20) <<    "mdl_G__exp__2 " <<    "= " <<
            setiosflags(ios::scientific) << setw(10) << mdl_G__exp__2 << endl;
    cout << setw(20) <<    "mdl_GH " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_GH << endl;
    cout << setw(20) <<    "mdl_Gphi " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << mdl_Gphi << endl;
}
void Parameters_HEFTU::printDependentCouplings()
{
    cout <<    "heft_updated_full model couplings dependent on event kinematics:"
            << endl;
    cout << setw(20) <<    "GC_14 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_14 << endl;
    cout << setw(20) <<    "GC_13 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_13 << endl;
    cout << setw(20) <<    "GC_12 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_12 << endl;
    cout << setw(20) <<    "GC_11 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_11 << endl;
    cout << setw(20) <<    "GC_10 " <<    "= " << setiosflags(ios::scientific) <<
            setw(10) << GC_10 << endl;
}


