//==========================================================================
// This file has been automatically generated for C++ by
// MadGraph 5 v. 1.5.2, 2012-10-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//
// Updated to MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// by Aurelijus Rinkevicius (odysei)
//==========================================================================

#ifndef Parameters_MEKD_CC
#define Parameters_MEKD_CC

#include "Parameters_MEKD.h"

// Initialize static instance
Parameters_MEKD *Parameters_MEKD::instance = nullptr;

// Function to get static instance - only one instance per program
Parameters_MEKD *Parameters_MEKD::getInstance()
{
    if (instance == nullptr)
        instance = new Parameters_MEKD();

    return instance;
}

void Parameters_MEKD::setIndependentParameters(SLHAReader_MEKD &slha)
{
    // Define "zero"
    zero = 0;
    ZERO = 0;
    // Prepare a vector for indices
    vector<int> indices(2, 0);
    aS = slha.get_block_entry("sminputs", 3, 1.180000e-01).real();
    mdl_Gf = slha.get_block_entry("sminputs", 2, 1.166390e-05).real();
    aEWM1 = slha.get_block_entry("sminputs", 1, 1.325070e+02).real();
    mdl_MXG = slha.get_block_entry("mass", 9000007, 1.250000e+02).real();
    mdl_MH = slha.get_block_entry("mass", 9000006, 1.250000e+02).real();
    mdl_MZp = slha.get_block_entry("mass", 300, 1.250000e+02).real();
    mdl_MZ = slha.get_block_entry("mass", 23, 9.118760e+01).real();
    mdl_MTA = slha.get_block_entry("mass", 15, 1.777000e+00).real();
    mdl_MM = slha.get_block_entry("mass", 13, 1.056600e-01).real();
    mdl_Me = slha.get_block_entry("mass", 11, 5.110000e-04).real();
    mdl_MT = slha.get_block_entry("mass", 6, 1.733400e+02).real();
    mdl_MB = slha.get_block_entry("mass", 5, 4.700000e+00).real();
    mdl_MC = slha.get_block_entry("mass", 4, 1.270000e+00).real();
    mdl_MS = slha.get_block_entry("mass", 3, 1.010000e-01).real();
    mdl_MU = slha.get_block_entry("mass", 2, 2.550000e-03).real();
    mdl_MD = slha.get_block_entry("mass", 1, 5.040000e-03).real();
    mdl_WXG = slha.get_block_entry("decay", 9000007, 5.753088e-03).real();
    mdl_WH = slha.get_block_entry("decay", 9000006, 5.753088e-03).real();
    mdl_WZp = slha.get_block_entry("decay", 300, 5.753088e-03).real();
    mdl_WW = slha.get_block_entry("decay", 24, 2.085000e+00).real();
    mdl_WZ = slha.get_block_entry("decay", 23, 2.495200e+00).real();
    mdl_WT = slha.get_block_entry("decay", 6, 1.508336e+00).real();
    mdl_ymtau = slha.get_block_entry("yukawa", 15, 1.777000e+00).real();
    mdl_ymm = slha.get_block_entry("yukawa", 13, 1.056600e-01).real();
    mdl_yme = slha.get_block_entry("yukawa", 11, 5.110000e-04).real();
    mdl_ymt = slha.get_block_entry("yukawa", 6, 1.720000e+02).real();
    mdl_ymb = slha.get_block_entry("yukawa", 5, 4.700000e+00).real();
    mdl_ymc = slha.get_block_entry("yukawa", 4, 1.270000e+00).real();
    mdl_yms = slha.get_block_entry("yukawa", 3, 1.010000e-01).real();
    mdl_ymup = slha.get_block_entry("yukawa", 2, 2.550000e-03).real();
    mdl_ymdo = slha.get_block_entry("yukawa", 1, 5.040000e-03).real();
    // cabi = slha.get_block_entry("ckmblock", 1, 2.277360e-01).real();
    mdl_etaWS = slha.get_block_entry("wolfenstein", 4, 3.410000e-01).real();
    mdl_rhoWS = slha.get_block_entry("wolfenstein", 3, 1.320000e-01).real();
    mdl_AWS = slha.get_block_entry("wolfenstein", 2, 8.080000e-01).real();
    mdl_lamWS = slha.get_block_entry("wolfenstein", 1, 2.253000e-01).real();
    rhoe02 = slha.get_block_entry("heff", 22, 0.000000e+00);
    rhoe01 = slha.get_block_entry("heff", 21, 2.075371e-06);
    rhomu02 = slha.get_block_entry("heff", 20, 0.000000e+00);
    rhomu01 = slha.get_block_entry("heff", 19, 4.291210e-04);
    rhob02 = slha.get_block_entry("heff", 18, 1.000000e-01);
    rhob01 = slha.get_block_entry("heff", 17, 1.000000e-01);
    rhos02 = slha.get_block_entry("heff", 16, 1.000000e-01);
    rhos01 = slha.get_block_entry("heff", 15, 1.000000e-01);
    rhod02 = slha.get_block_entry("heff", 14, 1.000000e-01);
    rhod01 = slha.get_block_entry("heff", 13, 1.000000e-01);
    rhoc02 = slha.get_block_entry("heff", 12, 1.000000e-01);
    rhoc01 = slha.get_block_entry("heff", 11, 1.000000e-01);
    rhou02 = slha.get_block_entry("heff", 10, 1.000000e-01);
    rhou01 = slha.get_block_entry("heff", 9, 1.000000e-01);
    g4z = slha.get_block_entry("heff", 8, 1.000000e-01);
    g3z = slha.get_block_entry("heff", 7, 1.000000e-01);
    g2z = slha.get_block_entry("heff", 6, 1.000000e-01);
    g1z = slha.get_block_entry("heff", 5, 1.000000e-01);
    g4g = slha.get_block_entry("heff", 4, 1.000000e-01);
    g3g = slha.get_block_entry("heff", 3, 1.000000e-01);
    g2g = slha.get_block_entry("heff", 2, 1.000000e-01);
    g1g = slha.get_block_entry("heff", 1, 1.000000e-01);
    rhoe14 = slha.get_block_entry("vec", 30, 0.000000e+00);
    rhoe13 = slha.get_block_entry("vec", 29, 0.000000e+00);
    rhoe12 = slha.get_block_entry("vec", 28, 0.000000e+00);
    rhoe11 = slha.get_block_entry("vec", 27, 2.075371e-06);
    rhomu14 = slha.get_block_entry("vec", 26, 0.000000e+00);
    rhomu13 = slha.get_block_entry("vec", 25, 0.000000e+00);
    rhomu12 = slha.get_block_entry("vec", 24, 0.000000e+00);
    rhomu11 = slha.get_block_entry("vec", 23, 4.291210e-04);
    rhob14 = slha.get_block_entry("vec", 22, 1.000000e-01);
    rhob13 = slha.get_block_entry("vec", 21, 1.000000e-01);
    rhob12 = slha.get_block_entry("vec", 20, 1.000000e-01);
    rhob11 = slha.get_block_entry("vec", 19, 1.000000e-01);
    rhos14 = slha.get_block_entry("vec", 18, 1.000000e-01);
    rhos13 = slha.get_block_entry("vec", 17, 1.000000e-01);
    rhos12 = slha.get_block_entry("vec", 16, 1.000000e-01);
    rhos11 = slha.get_block_entry("vec", 15, 1.000000e-01);
    rhod14 = slha.get_block_entry("vec", 14, 1.000000e-01);
    rhod13 = slha.get_block_entry("vec", 13, 1.000000e-01);
    rhod12 = slha.get_block_entry("vec", 12, 1.000000e-01);
    rhod11 = slha.get_block_entry("vec", 11, 1.000000e-01);
    rhoc14 = slha.get_block_entry("vec", 10, 1.000000e-01);
    rhoc13 = slha.get_block_entry("vec", 9, 1.000000e-01);
    rhoc12 = slha.get_block_entry("vec", 8, 1.000000e-01);
    rhoc11 = slha.get_block_entry("vec", 7, 1.000000e-01);
    rhou14 = slha.get_block_entry("vec", 6, 1.000000e-01);
    rhou13 = slha.get_block_entry("vec", 5, 1.000000e-01);
    rhou12 = slha.get_block_entry("vec", 4, 1.000000e-01);
    rhou11 = slha.get_block_entry("vec", 3, 1.000000e-01);
    b2z = slha.get_block_entry("vec", 2, 1.000000e-01);
    b1z = slha.get_block_entry("vec", 1, 1.000000e-01);
    rhoe24 = slha.get_block_entry("gravity", 48, 0.000000e+00);
    rhoe23 = slha.get_block_entry("gravity", 47, 0.000000e+00);
    rhoe22 = slha.get_block_entry("gravity", 46, 0.000000e+00);
    rhoe21 = slha.get_block_entry("gravity", 45, 2.075371e-06);
    rhomu24 = slha.get_block_entry("gravity", 44, 0.000000e+00);
    rhomu23 = slha.get_block_entry("gravity", 43, 0.000000e+00);
    rhomu22 = slha.get_block_entry("gravity", 42, 0.000000e+00);
    rhomu21 = slha.get_block_entry("gravity", 41, 4.291210e-04);
    rhob24 = slha.get_block_entry("gravity", 40, 1.000000e-01);
    rhob23 = slha.get_block_entry("gravity", 39, 1.000000e-01);
    rhob22 = slha.get_block_entry("gravity", 38, 1.000000e-01);
    rhob21 = slha.get_block_entry("gravity", 37, 1.000000e-01);
    rhos24 = slha.get_block_entry("gravity", 36, 1.000000e-01);
    rhos23 = slha.get_block_entry("gravity", 35, 1.000000e-01);
    rhos22 = slha.get_block_entry("gravity", 34, 1.000000e-01);
    rhos21 = slha.get_block_entry("gravity", 33, 1.000000e-01);
    rhod24 = slha.get_block_entry("gravity", 32, 1.000000e-01);
    rhod23 = slha.get_block_entry("gravity", 31, 1.000000e-01);
    rhod22 = slha.get_block_entry("gravity", 30, 1.000000e-01);
    rhod21 = slha.get_block_entry("gravity", 29, 1.000000e-01);
    rhoc24 = slha.get_block_entry("gravity", 28, 1.000000e-01);
    rhoc23 = slha.get_block_entry("gravity", 27, 1.000000e-01);
    rhoc22 = slha.get_block_entry("gravity", 26, 1.000000e-01);
    rhoc21 = slha.get_block_entry("gravity", 25, 1.000000e-01);
    rhou24 = slha.get_block_entry("gravity", 24, 1.000000e-01);
    rhou23 = slha.get_block_entry("gravity", 23, 1.000000e-01);
    rhou22 = slha.get_block_entry("gravity", 22, 1.000000e-01);
    rhou21 = slha.get_block_entry("gravity", 21, 1.000000e-01);
    k10z = slha.get_block_entry("gravity", 20, 1.000000e-01);
    k9z = slha.get_block_entry("gravity", 19, 1.000000e-01);
    k8z = slha.get_block_entry("gravity", 18, 1.000000e-01);
    k7z = slha.get_block_entry("gravity", 17, 1.000000e-01);
    k6z = slha.get_block_entry("gravity", 16, 1.000000e-01);
    k5z = slha.get_block_entry("gravity", 15, 1.000000e-01);
    k4z = slha.get_block_entry("gravity", 14, 1.000000e-01);
    k3z = slha.get_block_entry("gravity", 13, 1.000000e-01);
    k2z = slha.get_block_entry("gravity", 12, 1.000000e-01);
    k1z = slha.get_block_entry("gravity", 11, 1.000000e-01);
    k10g = slha.get_block_entry("gravity", 10, 1.000000e-01);
    k9g = slha.get_block_entry("gravity", 9, 1.000000e-01);
    k8g = slha.get_block_entry("gravity", 8, 1.000000e-01);
    k7g = slha.get_block_entry("gravity", 7, 1.000000e-01);
    k6g = slha.get_block_entry("gravity", 6, 1.000000e-01);
    k5g = slha.get_block_entry("gravity", 5, 1.000000e-01);
    k4g = slha.get_block_entry("gravity", 4, 1.000000e-01);
    k3g = slha.get_block_entry("gravity", 3, 1.000000e-01);
    k2g = slha.get_block_entry("gravity", 2, 1.000000e-01);
    k1g = slha.get_block_entry("gravity", 1, 1.000000e-01);
    // 	mdl_gw = 1.;
    // 	mdl_g1 = 1.;
    mdl_complexi = std::complex<double>(0., 1.);
    // 	cos__cabi = cos(cabi);
    // 	mdl_CKM1x1 = cos__cabi;
    // 	sin__cabi = sin(cabi);
    // 	mdl_CKM1x2 = sin__cabi;
    // 	mdl_CKM1x3 = 0.;
    // 	mdl_CKM2x1 = -sin__cabi;
    // 	mdl_CKM2x2 = cos__cabi;
    // 	mdl_CKM2x3 = 0.;
    // 	mdl_CKM3x1 = 0.;
    // 	mdl_CKM3x2 = 0.;
    // 	mdl_CKM3x3 = 1.;
    mdl_lamWS__exp__2 = pow(mdl_lamWS, 2.);
    mdl_lamWS__exp__3 = pow(mdl_lamWS, 3.);
    mdl_CKM1x1 = 1. - mdl_lamWS__exp__2 / 2.;
    mdl_CKM1x2 = mdl_lamWS;
    mdl_CKM1x3 =
        mdl_AWS * mdl_lamWS__exp__3 * (-(mdl_etaWS * mdl_complexi) + mdl_rhoWS);
    mdl_CKM2x1 = -mdl_lamWS;
    mdl_CKM2x2 = 1. - mdl_lamWS__exp__2 / 2.;
    mdl_CKM2x3 = mdl_AWS * mdl_lamWS__exp__2;
    mdl_CKM3x1 = mdl_AWS * mdl_lamWS__exp__3 *
                 (1. - mdl_etaWS * mdl_complexi - mdl_rhoWS);
    mdl_CKM3x2 = -(mdl_AWS * mdl_lamWS__exp__2);
    mdl_CKM3x3 = 1.;
    mdl_conjg__CKM1x1 = conj(mdl_CKM1x1);
    mdl_conjg__CKM2x1 = conj(mdl_CKM2x1);
    mdl_conjg__CKM3x1 = conj(mdl_CKM3x1);
    mdl_conjg__CKM1x2 = conj(mdl_CKM1x2);
    mdl_conjg__CKM2x2 = conj(mdl_CKM2x2);
    mdl_conjg__CKM3x2 = conj(mdl_CKM3x2);
    mdl_conjg__CKM1x3 = conj(mdl_CKM1x3);
    mdl_conjg__CKM2x3 = conj(mdl_CKM2x3);
    mdl_conjg__CKM3x3 = conj(mdl_CKM3x3);
    mdl_MZ__exp__2 = pow(mdl_MZ, 2.);
    mdl_MZ__exp__4 = pow(mdl_MZ, 4.);
    mdl_sqrt__2 = sqrt(2.);
    mdl_MH__exp__2 = pow(mdl_MH, 2.); // dependent
    mdl_aEW = 1. / aEWM1;
    mdl_MW = sqrt(mdl_MZ__exp__2 / 2. + sqrt(mdl_MZ__exp__4 / 4. -
                                             (mdl_aEW * M_PI * mdl_MZ__exp__2) /
                                                 (mdl_Gf * mdl_sqrt__2)));
    mdl_sqrt__aEW = sqrt(mdl_aEW);
    mdl_ee = 2. * mdl_sqrt__aEW * sqrt(M_PI);
    mdl_MW__exp__2 = pow(mdl_MW, 2.);
    mdl_sw2 = 1. - mdl_MW__exp__2 / mdl_MZ__exp__2;
    mdl_cw = sqrt(1. - mdl_sw2);
    mdl_sqrt__sw2 = sqrt(mdl_sw2);
    mdl_sw = mdl_sqrt__sw2;
    mdl_g1 = mdl_ee / mdl_cw;
    mdl_gw = mdl_ee / mdl_sw;
    mdl_vev = (2. * mdl_MW * mdl_sw) / mdl_ee;
    mdl_vev__exp__2 = pow(mdl_vev, 2.);
    mdl_lam = mdl_MH__exp__2 / (2. * mdl_vev__exp__2); // dependent
    mdl_yb = (mdl_ymb * mdl_sqrt__2) / mdl_vev;
    mdl_yc = (mdl_ymc * mdl_sqrt__2) / mdl_vev;
    mdl_ydo = (mdl_ymdo * mdl_sqrt__2) / mdl_vev;
    mdl_ye = (mdl_yme * mdl_sqrt__2) / mdl_vev;
    mdl_ym = (mdl_ymm * mdl_sqrt__2) / mdl_vev;
    mdl_ys = (mdl_yms * mdl_sqrt__2) / mdl_vev;
    mdl_yt = (mdl_ymt * mdl_sqrt__2) / mdl_vev;
    mdl_ytau = (mdl_ymtau * mdl_sqrt__2) / mdl_vev;
    mdl_yup = (mdl_ymup * mdl_sqrt__2) / mdl_vev;
    mdl_muH = sqrt(mdl_lam * mdl_vev__exp__2); // dependent
    mdl_I1x11 = mdl_ydo * mdl_conjg__CKM1x1;
    mdl_I1x12 = mdl_ydo * mdl_conjg__CKM2x1;
    mdl_I1x13 = mdl_ydo * mdl_conjg__CKM3x1;
    mdl_I1x21 = mdl_ys * mdl_conjg__CKM1x2;
    mdl_I1x22 = mdl_ys * mdl_conjg__CKM2x2;
    mdl_I1x23 = mdl_ys * mdl_conjg__CKM3x2;
    mdl_I1x31 = mdl_yb * mdl_conjg__CKM1x3;
    mdl_I1x32 = mdl_yb * mdl_conjg__CKM2x3;
    mdl_I1x33 = mdl_yb * mdl_conjg__CKM3x3;
    mdl_I2x11 = mdl_yup * mdl_conjg__CKM1x1;
    mdl_I2x12 = mdl_yc * mdl_conjg__CKM2x1;
    mdl_I2x13 = mdl_yt * mdl_conjg__CKM3x1;
    mdl_I2x21 = mdl_yup * mdl_conjg__CKM1x2;
    mdl_I2x22 = mdl_yc * mdl_conjg__CKM2x2;
    mdl_I2x23 = mdl_yt * mdl_conjg__CKM3x2;
    mdl_I2x31 = mdl_yup * mdl_conjg__CKM1x3;
    mdl_I2x32 = mdl_yc * mdl_conjg__CKM2x3;
    mdl_I2x33 = mdl_yt * mdl_conjg__CKM3x3;
    mdl_I3x11 = mdl_CKM1x1 * mdl_yup;
    mdl_I3x12 = mdl_CKM2x1 * mdl_yc;
    mdl_I3x13 = mdl_CKM3x1 * mdl_yt;
    mdl_I3x21 = mdl_CKM1x2 * mdl_yup;
    mdl_I3x22 = mdl_CKM2x2 * mdl_yc;
    mdl_I3x23 = mdl_CKM3x2 * mdl_yt;
    mdl_I3x31 = mdl_CKM1x3 * mdl_yup;
    mdl_I3x32 = mdl_CKM2x3 * mdl_yc;
    mdl_I3x33 = mdl_CKM3x3 * mdl_yt;
    mdl_I4x11 = mdl_CKM1x1 * mdl_ydo;
    mdl_I4x12 = mdl_CKM2x1 * mdl_ydo;
    mdl_I4x13 = mdl_CKM3x1 * mdl_ydo;
    mdl_I4x21 = mdl_CKM1x2 * mdl_ys;
    mdl_I4x22 = mdl_CKM2x2 * mdl_ys;
    mdl_I4x23 = mdl_CKM3x2 * mdl_ys;
    mdl_I4x31 = mdl_CKM1x3 * mdl_yb;
    mdl_I4x32 = mdl_CKM2x3 * mdl_yb;
    mdl_I4x33 = mdl_CKM3x3 * mdl_yb;
    mdl_ee__exp__2 = pow(mdl_ee, 2.);
    mdl_sw__exp__2 = pow(mdl_sw, 2.);
    mdl_cw__exp__2 = pow(mdl_cw, 2.);
}

void Parameters_MEKD::setIndependentCouplings()
{
    GC_1 = -(mdl_ee * mdl_complexi) / 3.;
    GC_2 = (2. * mdl_ee * mdl_complexi) / 3.;
    GC_3 = -(mdl_ee * mdl_complexi);
    GC_109 = -(mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    GC_110 = (mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    GC_115 = -(mdl_ee * mdl_complexi * mdl_sw) / (6. * mdl_cw);
    GC_116 = (mdl_ee * mdl_complexi * mdl_sw) / (2. * mdl_cw);

    Unitary_GC_5 = -(mdl_ee * mdl_complexi) / 3.;
    Unitary_GC_6 = (2. * mdl_ee * mdl_complexi) / 3.;
    Unitary_GC_7 = -(mdl_ee * mdl_complexi);
    Unitary_GC_70 = -(mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    Unitary_GC_71 = (mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    Unitary_GC_74 = -(mdl_ee * mdl_complexi * mdl_sw) / (6. * mdl_cw);
    Unitary_GC_75 = (mdl_ee * mdl_complexi * mdl_sw) / (2. * mdl_cw);

    // Coming from spin 0
    HEF_MEKD_GC_3 = -(mdl_ee * mdl_complexi) / 3.;
    HEF_MEKD_GC_4 = (2. * mdl_ee * mdl_complexi) / 3.;
    HEF_MEKD_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD_GC_13 = -(mdl_complexi * g1g);     // dependent
    HEF_MEKD_GC_14 = -(mdl_complexi * g1z);     // dependent
    HEF_MEKD_GC_15 = -(mdl_complexi * g2g);     // dependent
    HEF_MEKD_GC_18 = -(mdl_complexi * g2z);     // dependent
    HEF_MEKD_GC_19 = -(mdl_complexi * g3g);     // dependent
    HEF_MEKD_GC_22 = -(mdl_complexi * g3z);     // dependent
    HEF_MEKD_GC_23 = (mdl_complexi * g4g) / 8.; // dependent
    HEF_MEKD_GC_25 = (mdl_complexi * g4z) / 2.; // dependent
    HEF_MEKD_GC_106 = mdl_complexi * rhoc01;    // dependent
    HEF_MEKD_GC_107 = -rhoc02;                  // dependent
    HEF_MEKD_GC_116 = mdl_complexi * rhod01;    // dependent
    HEF_MEKD_GC_117 = -rhod02;                  // dependent
    HEF_MEKD_GC_126 = mdl_complexi * rhos01;    // dependent
    HEF_MEKD_GC_127 = -rhos02;                  // dependent
    HEF_MEKD_GC_136 = mdl_complexi * rhou01;    // dependent
    HEF_MEKD_GC_137 = -rhou02;                  // dependent
    HEF_MEKD_GC_161 = -(mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    HEF_MEKD_GC_168 = (mdl_ee * mdl_complexi * mdl_sw) / (2. * mdl_cw);

    // Coming extra from spin 1
    HEF_MEKD_GC_1 = -b1z;
    HEF_MEKD_GC_2 = -2. * b2z;
    // 	HEF_MEKD_GC_3 = -(mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD_GC_4 = (2. * mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD_GC_108 = mdl_complexi * rhoc11;
    HEF_MEKD_GC_109 = mdl_complexi * rhoc12;
    HEF_MEKD_GC_110 = mdl_complexi * rhoc13;
    HEF_MEKD_GC_111 = rhoc14;
    HEF_MEKD_GC_118 = mdl_complexi * rhod11;
    HEF_MEKD_GC_119 = mdl_complexi * rhod12;
    HEF_MEKD_GC_120 = mdl_complexi * rhod13;
    HEF_MEKD_GC_121 = rhod14;
    HEF_MEKD_GC_128 = mdl_complexi * rhos11;
    HEF_MEKD_GC_129 = mdl_complexi * rhos12;
    HEF_MEKD_GC_130 = mdl_complexi * rhos13;
    HEF_MEKD_GC_131 = rhos14;
    HEF_MEKD_GC_138 = mdl_complexi * rhou11;
    HEF_MEKD_GC_139 = mdl_complexi * rhou12;
    HEF_MEKD_GC_140 = mdl_complexi * rhou13;
    HEF_MEKD_GC_141 = rhou14;
    // 	HEF_MEKD_GC_161 = -(mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    // 	HEF_MEKD_GC_168 = (mdl_ee * mdl_complexi * mdl_sw)/(2. * mdl_cw);

    // Coming extra from spin 2
    // 	HEF_MEKD_GC_3 = -(mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD_GC_4 = (2. * mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD_GC_62 = -(mdl_complexi * k10g) / 2.;
    HEF_MEKD_GC_63 = -(mdl_complexi * k10z) / 2.;
    HEF_MEKD_GC_64 = -(mdl_complexi * k1g);
    HEF_MEKD_GC_67 = -(mdl_complexi * k1z);
    HEF_MEKD_GC_68 = mdl_complexi * k2g;
    HEF_MEKD_GC_71 = mdl_complexi * k2z;
    HEF_MEKD_GC_72 = mdl_complexi * k3g;
    HEF_MEKD_GC_75 = mdl_complexi * k3z;
    HEF_MEKD_GC_76 = -2. * mdl_complexi * k4g;
    HEF_MEKD_GC_79 = -2. * mdl_complexi * k4z;
    HEF_MEKD_GC_80 = mdl_complexi * k5g;
    HEF_MEKD_GC_81 = mdl_complexi * k5z;
    HEF_MEKD_GC_82 = -(mdl_complexi * k6g) / 2.;
    HEF_MEKD_GC_83 = -(mdl_complexi * k6z) / 2.;
    HEF_MEKD_GC_84 = -(mdl_complexi * k7g);
    HEF_MEKD_GC_85 = -(mdl_complexi * k7z);
    HEF_MEKD_GC_86 = (mdl_complexi * k8g) / 4.;
    HEF_MEKD_GC_90 = mdl_complexi * k8z;
    HEF_MEKD_GC_91 = -(mdl_complexi * k9g) / 2.;
    HEF_MEKD_GC_92 = -(mdl_complexi * k9z) / 2.;
    HEF_MEKD_GC_112 = (mdl_complexi * rhoc21) / 2.;
    HEF_MEKD_GC_113 = (mdl_complexi * rhoc22) / 2.;
    HEF_MEKD_GC_114 = -(mdl_complexi * rhoc23) / 2.;
    HEF_MEKD_GC_115 = rhoc24 / 2.;
    HEF_MEKD_GC_122 = (mdl_complexi * rhod21) / 2.;
    HEF_MEKD_GC_123 = (mdl_complexi * rhod22) / 2.;
    HEF_MEKD_GC_124 = -(mdl_complexi * rhod23) / 2.;
    HEF_MEKD_GC_125 = rhod24 / 2.;
    HEF_MEKD_GC_132 = (mdl_complexi * rhos21) / 2.;
    HEF_MEKD_GC_133 = (mdl_complexi * rhos22) / 2.;
    HEF_MEKD_GC_134 = -(mdl_complexi * rhos23) / 2.;
    HEF_MEKD_GC_135 = rhos24 / 2.;
    HEF_MEKD_GC_142 = (mdl_complexi * rhou21) / 2.;
    HEF_MEKD_GC_143 = (mdl_complexi * rhou22) / 2.;
    HEF_MEKD_GC_144 = -(mdl_complexi * rhou23) / 2.;
    HEF_MEKD_GC_145 = rhou24 / 2.;
    // 	HEF_MEKD_GC_161 = -(mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    // 	HEF_MEKD_GC_168 = (mdl_ee * mdl_complexi * mdl_sw)/(2. * mdl_cw);

    /// Model HEF_MEKD2_1 with 2l couplings
    // Coming extra from DY
    HEF_MEKD2_1_GC_3 = -(mdl_ee * mdl_complexi) / 3.;
    HEF_MEKD2_1_GC_4 = (2. * mdl_ee * mdl_complexi) / 3.;
    HEF_MEKD2_1_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD2_1_GC_181 = -(mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    HEF_MEKD2_1_GC_182 = (mdl_cw * mdl_ee * mdl_complexi) / (2. * mdl_sw);
    HEF_MEKD2_1_GC_187 = -(mdl_ee * mdl_complexi * mdl_sw) / (6. * mdl_cw);
    HEF_MEKD2_1_GC_188 = (mdl_ee * mdl_complexi * mdl_sw) / (2. * mdl_cw);

    // Coming extra from spin 0
    // 	HEF_MEKD2_1_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD2_1_GC_13 = -(mdl_complexi * g1g);     // dependent
    HEF_MEKD2_1_GC_14 = -(mdl_complexi * g1z);     // dependent
    HEF_MEKD2_1_GC_15 = -(mdl_complexi * g2g);     // dependent
    HEF_MEKD2_1_GC_18 = -(mdl_complexi * g2z);     // dependent
    HEF_MEKD2_1_GC_19 = -(mdl_complexi * g3g);     // dependent
    HEF_MEKD2_1_GC_22 = -(mdl_complexi * g3z);     // dependent
    HEF_MEKD2_1_GC_23 = (mdl_complexi * g4g) / 8.; // dependent
    HEF_MEKD2_1_GC_25 = (mdl_complexi * g4z) / 2.; // dependent
    HEF_MEKD2_1_GC_126 = mdl_complexi * rhoe01;    // dependent
    HEF_MEKD2_1_GC_127 = -rhoe02;                  // dependent
    HEF_MEKD2_1_GC_136 = mdl_complexi * rhomu01;   // dependent
    HEF_MEKD2_1_GC_137 = -rhomu02;                 // dependent
    // 	HEF_MEKD2_1_GC_181 = -(mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    // 	HEF_MEKD2_1_GC_188 = (mdl_ee * mdl_complexi * mdl_sw)/(2. * mdl_cw);

    // Coming extra from spin 1
    HEF_MEKD2_1_GC_1 = -b1z;
    HEF_MEKD2_1_GC_2 = -2. * b2z;
    // 	HEF_MEKD2_1_GC_3 = -(mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD2_1_GC_4 = (2. * mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD2_1_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD2_1_GC_108 = mdl_complexi * rhoc11;
    HEF_MEKD2_1_GC_109 = mdl_complexi * rhoc12;
    HEF_MEKD2_1_GC_110 = mdl_complexi * rhoc13;
    HEF_MEKD2_1_GC_111 = rhoc14;
    HEF_MEKD2_1_GC_128 = mdl_complexi * rhoe11;
    HEF_MEKD2_1_GC_129 = mdl_complexi * rhoe12;
    HEF_MEKD2_1_GC_130 = mdl_complexi * rhoe13;
    HEF_MEKD2_1_GC_131 = rhoe14;
    HEF_MEKD2_1_GC_138 = mdl_complexi * rhomu11;
    HEF_MEKD2_1_GC_139 = mdl_complexi * rhomu12;
    HEF_MEKD2_1_GC_140 = mdl_complexi * rhomu13;
    HEF_MEKD2_1_GC_141 = rhomu14;
    HEF_MEKD2_1_GC_148 = mdl_complexi * rhos11;
    HEF_MEKD2_1_GC_149 = mdl_complexi * rhos12;
    HEF_MEKD2_1_GC_150 = mdl_complexi * rhos13;
    HEF_MEKD2_1_GC_151 = rhos14;

    // Coming extra from spin 2
    // 	HEF_MEKD2_1_GC_3 = -(mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD2_1_GC_4 = (2. * mdl_ee * mdl_complexi)/3.;
    // 	HEF_MEKD2_1_GC_5 = -(mdl_ee * mdl_complexi);
    HEF_MEKD2_1_GC_62 = -(mdl_complexi * k10g) / 2.;
    HEF_MEKD2_1_GC_63 = -(mdl_complexi * k10z) / 2.;
    HEF_MEKD2_1_GC_64 = -(mdl_complexi * k1g);
    HEF_MEKD2_1_GC_67 = -(mdl_complexi * k1z);
    HEF_MEKD2_1_GC_68 = mdl_complexi * k2g;
    HEF_MEKD2_1_GC_71 = mdl_complexi * k2z;
    HEF_MEKD2_1_GC_72 = mdl_complexi * k3g;
    HEF_MEKD2_1_GC_75 = mdl_complexi * k3z;
    HEF_MEKD2_1_GC_76 = -2. * mdl_complexi * k4g;
    HEF_MEKD2_1_GC_79 = -2. * mdl_complexi * k4z;
    HEF_MEKD2_1_GC_80 = mdl_complexi * k5g;
    HEF_MEKD2_1_GC_81 = mdl_complexi * k5z;
    HEF_MEKD2_1_GC_82 = -(mdl_complexi * k6g) / 2.;
    HEF_MEKD2_1_GC_83 = -(mdl_complexi * k6z) / 2.;
    HEF_MEKD2_1_GC_84 = -(mdl_complexi * k7g);
    HEF_MEKD2_1_GC_85 = -(mdl_complexi * k7z);
    HEF_MEKD2_1_GC_86 = (mdl_complexi * k8g) / 4.;
    HEF_MEKD2_1_GC_90 = mdl_complexi * k8z;
    HEF_MEKD2_1_GC_91 = -(mdl_complexi * k9g) / 2.;
    HEF_MEKD2_1_GC_92 = -(mdl_complexi * k9z) / 2.;
    HEF_MEKD2_1_GC_112 = (mdl_complexi * rhoc21) / 2.;
    HEF_MEKD2_1_GC_113 = (mdl_complexi * rhoc22) / 2.;
    HEF_MEKD2_1_GC_114 = -(mdl_complexi * rhoc23) / 2.;
    HEF_MEKD2_1_GC_115 = rhoc24 / 2.;
    HEF_MEKD2_1_GC_132 = (mdl_complexi * rhoe21) / 2.;
    HEF_MEKD2_1_GC_133 = (mdl_complexi * rhoe22) / 2.;
    HEF_MEKD2_1_GC_134 = -(mdl_complexi * rhoe23) / 2.;
    HEF_MEKD2_1_GC_135 = rhoe24 / 2.;
    HEF_MEKD2_1_GC_142 = (mdl_complexi * rhomu21) / 2.;
    HEF_MEKD2_1_GC_143 = (mdl_complexi * rhomu22) / 2.;
    HEF_MEKD2_1_GC_144 = -(mdl_complexi * rhomu23) / 2.;
    HEF_MEKD2_1_GC_145 = rhomu24 / 2.;
    HEF_MEKD2_1_GC_152 = (mdl_complexi * rhos21) / 2.;
    HEF_MEKD2_1_GC_153 = (mdl_complexi * rhos22) / 2.;
    HEF_MEKD2_1_GC_154 = -(mdl_complexi * rhos23) / 2.;
    HEF_MEKD2_1_GC_155 = rhos24 / 2.;
    // 	HEF_MEKD2_1_GC_181 = -(mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    // 	HEF_MEKD2_1_GC_182 = (mdl_cw * mdl_ee * mdl_complexi)/(2. * mdl_sw);
    // 	HEF_MEKD2_1_GC_187 = -(mdl_ee * mdl_complexi * mdl_sw)/(6. * mdl_cw);
    // 	HEF_MEKD2_1_GC_188 = (mdl_ee * mdl_complexi * mdl_sw)/(2. * mdl_cw);
}

void Parameters_MEKD::setDependentParameters()
{
    mdl_sqrt__aS = sqrt(aS);
    G = 2. * mdl_sqrt__aS * sqrt(M_PI);
    mdl_G__exp__2 = pow(G, 2.);

    // changes because variations in couplings and particles
    mdl_MH__exp__2 = pow(mdl_MH, 2.);
    mdl_lam = mdl_MH__exp__2 / (2. * mdl_vev__exp__2);
    mdl_muH = sqrt(mdl_lam * mdl_vev__exp__2);
}

void Parameters_MEKD::setDependentCouplings()
{
    // Coming from spin 0
    HEF_MEKD_GC_13 = -(mdl_complexi * g1g);
    HEF_MEKD_GC_14 = -(mdl_complexi * g1z);
    HEF_MEKD_GC_15 = -(mdl_complexi * g2g);
    HEF_MEKD_GC_18 = -(mdl_complexi * g2z);
    HEF_MEKD_GC_19 = -(mdl_complexi * g3g);
    HEF_MEKD_GC_22 = -(mdl_complexi * g3z);
    HEF_MEKD_GC_23 = (mdl_complexi * g4g) / 8.;
    HEF_MEKD_GC_25 = (mdl_complexi * g4z) / 2.;
    HEF_MEKD_GC_106 = mdl_complexi * rhoc01;
    HEF_MEKD_GC_107 = -rhoc02;
    HEF_MEKD_GC_116 = mdl_complexi * rhod01;
    HEF_MEKD_GC_117 = -rhod02;
    HEF_MEKD_GC_126 = mdl_complexi * rhos01;
    HEF_MEKD_GC_127 = -rhos02;
    HEF_MEKD_GC_136 = mdl_complexi * rhou01;
    HEF_MEKD_GC_137 = -rhou02;

    /// Model HEF_MEKD2_1 with 2l couplings
    // Coming extra from spin 0
    HEF_MEKD2_1_GC_13 = -(mdl_complexi * g1g);
    HEF_MEKD2_1_GC_14 = -(mdl_complexi * g1z);
    HEF_MEKD2_1_GC_15 = -(mdl_complexi * g2g);
    HEF_MEKD2_1_GC_18 = -(mdl_complexi * g2z);
    HEF_MEKD2_1_GC_19 = -(mdl_complexi * g3g);
    HEF_MEKD2_1_GC_22 = -(mdl_complexi * g3z);
    HEF_MEKD2_1_GC_23 = (mdl_complexi * g4g) / 8.;
    HEF_MEKD2_1_GC_25 = (mdl_complexi * g4z) / 2.;
    HEF_MEKD2_1_GC_126 = mdl_complexi * rhoe01;
    HEF_MEKD2_1_GC_127 = -rhoe02;
    HEF_MEKD2_1_GC_136 = mdl_complexi * rhomu01;
    HEF_MEKD2_1_GC_137 = -rhomu02;
}

#endif
