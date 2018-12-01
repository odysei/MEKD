//==========================================================================
// This file has been automatically generated for C++ by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "Parameters_HiggsPO_UFO.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Initialize static instance
Parameters_HiggsPO_UFO *Parameters_HiggsPO_UFO::instance = nullptr;

// Function to get static instance - only one instance per program
Parameters_HiggsPO_UFO *Parameters_HiggsPO_UFO::getInstance()
{
    if (instance == nullptr)
        instance = new Parameters_HiggsPO_UFO();

    return instance;
}

void Parameters_HiggsPO_UFO::setIndependentParameters(SLHAReader_MEKD &slha)
{
    // Define "zero"
    zero = 0;
    ZERO = 0;
    // Prepare a vector for indices
    vector<int> indices(2, 0);
    mdl_WH = slha.get_block_entry("decay", 25, 5.753088e-03).real();
    mdl_WW = slha.get_block_entry("decay", 24, 2.085000e+00).real();
    mdl_WZ = slha.get_block_entry("decay", 23, 2.495200e+00).real();
    mdl_WT = slha.get_block_entry("decay", 6, 1.508336e+00).real();
    mdl_gWtau = slha.get_block_entry("wzpole", 10, 1.025000e+00).real();
    mdl_gWmu = slha.get_block_entry("wzpole", 9, 9.910000e-01).real();
    mdl_gWe = slha.get_block_entry("wzpole", 8, 9.940000e-01).real();
    mdl_gZv = slha.get_block_entry("wzpole", 7, 5.000000e-01).real();
    mdl_gZtauR = slha.get_block_entry("wzpole", 6, 2.327000e-01).real();
    mdl_gZmuR = slha.get_block_entry("wzpole", 5, 2.320000e-01).real();
    mdl_gZeR = slha.get_block_entry("wzpole", 4, 2.315000e-01).real();
    mdl_gZtauL = slha.get_block_entry("wzpole", 3, -2.693000e-01).real();
    mdl_gZmuL = slha.get_block_entry("wzpole", 2, -2.690000e-01).real();
    mdl_gZeL = slha.get_block_entry("wzpole", 1, -2.696000e-01).real();
    aS = slha.get_block_entry("sminputs", 3, 1.180000e-01).real();
    mdl_Gf = slha.get_block_entry("sminputs", 2, 1.166390e-05).real();
    aEWM1 = slha.get_block_entry("sminputs", 1, 1.325070e+02).real();
    mdl_MH = slha.get_block_entry("mass", 25, 1.250000e+02).real();
    mdl_MW = slha.get_block_entry("mass", 24, 8.038500e+01).real();
    mdl_MZ = slha.get_block_entry("mass", 23, 9.118760e+01).real();
    mdl_MTA = slha.get_block_entry("mass", 15, 1.777000e+00).real();
    mdl_MM = slha.get_block_entry("mass", 13, 1.056600e-01).real();
    mdl_Me = slha.get_block_entry("mass", 11, 5.110000e-04).real();
    mdl_MT = slha.get_block_entry("mass", 6, 1.720000e+02).real();
    mdl_MB = slha.get_block_entry("mass", 5, 4.700000e+00).real();
    mdl_MC = slha.get_block_entry("mass", 4, 1.270000e+00).real();
    // mdl_MS = slha.get_block_entry("mass", 3, 9.350000e-02).real();
    // mdl_MU = slha.get_block_entry("mass", 2, 2.150000e-03).real();
    // mdl_MD = slha.get_block_entry("mass", 1, 4.700000e-03).real();
    mdl_ymueff = slha.get_block_entry("hposm", 6, 5.990000e-04).real();
    mdl_ytaueff = slha.get_block_entry("hposm", 5, 1.020000e-02).real();
    mdl_yceff = slha.get_block_entry("hposm", 4, 3.980000e-03).real();
    mdl_ybeff = slha.get_block_entry("hposm", 3, 1.770000e-02).real();
    mdl_eZASM = slha.get_block_entry("hposm", 2, 6.900000e-03).real();
    mdl_eAASM = slha.get_block_entry("hposm", 1, 3.800000e-03).real();
    mdl_noise = slha.get_block_entry("hpo4f", 24, 9.96300008259327e-11).real();
    mdl_phiWtau = slha.get_block_entry("hpo4f", 23, 0.000000e+00).real();
    mdl_phiWmu = slha.get_block_entry("hpo4f", 22, 0.000000e+00).real();
    mdl_phiWe = slha.get_block_entry("hpo4f", 21, 0.000000e+00).real();
    mdl_eWtau = slha.get_block_entry("hpo4f", 20, 0.000000e+00).real();
    mdl_eWmu = slha.get_block_entry("hpo4f", 19, 0.000000e+00).real();
    mdl_eWe = slha.get_block_entry("hpo4f", 18, 0.000000e+00).real();
    mdl_eZv = slha.get_block_entry("hpo4f", 17, 0.000000e+00).real();
    mdl_eZtauR = slha.get_block_entry("hpo4f", 16, 0.000000e+00).real();
    mdl_eZmuR = slha.get_block_entry("hpo4f", 15, 0.000000e+00).real();
    mdl_eZeR = slha.get_block_entry("hpo4f", 14, 0.000000e+00).real();
    mdl_eZtauL = slha.get_block_entry("hpo4f", 13, 0.000000e+00).real();
    mdl_eZmuL = slha.get_block_entry("hpo4f", 12, 0.000000e+00).real();
    mdl_eZeL = slha.get_block_entry("hpo4f", 11, 0.000000e+00).real();
    mdl_eWWCP = slha.get_block_entry("hpo4f", 10, 0.000000e+00).real();
    mdl_eZZCP = slha.get_block_entry("hpo4f", 9, 0.000000e+00).real();
    mdl_lZACP = slha.get_block_entry("hpo4f", 8, 0.000000e+00).real();
    mdl_lAACP = slha.get_block_entry("hpo4f", 7, 0.000000e+00).real();
    mdl_eWW = slha.get_block_entry("hpo4f", 6, 0.000000e+00).real();
    mdl_eZZ = slha.get_block_entry("hpo4f", 5, 0.000000e+00).real();
    mdl_kZA = slha.get_block_entry("hpo4f", 4, 1.000000e+00).real();
    mdl_kAA = slha.get_block_entry("hpo4f", 3, 1.000000e+00).real();
    mdl_kWW = slha.get_block_entry("hpo4f", 2, 1.000000e+00).real();
    mdl_kZZ = slha.get_block_entry("hpo4f", 1, 1.000000e+00).real();
    mdl_lmu = slha.get_block_entry("hpo2f", 14, 0.000000e+00).real();
    mdl_ltau = slha.get_block_entry("hpo2f", 13, 0.000000e+00).real();
    mdl_lc = slha.get_block_entry("hpo2f", 12, 0.000000e+00).real();
    mdl_lb = slha.get_block_entry("hpo2f", 11, 0.000000e+00).real();
    mdl_kmu = slha.get_block_entry("hpo2f", 4, 1.000000e+00).real();
    mdl_ktau = slha.get_block_entry("hpo2f", 3, 1.000000e+00).real();
    mdl_kc = slha.get_block_entry("hpo2f", 2, 1.000000e+00).real();
    mdl_kb = slha.get_block_entry("hpo2f", 1, 1.000000e+00).real();
    mdl_eggSM = -0.0065;
    mdl_complexi = std::complex<double>(0., 1.);
    mdl_MZ__exp__2 = pow(mdl_MZ, 2.);
    const double mdl_MZ__exp__4 = pow(mdl_MZ, 4.);
    mdl_sqrt__2 = sqrt(2.);
    mdl_cos__phiWe = cos(mdl_phiWe);
    mdl_sin__phiWe = sin(mdl_phiWe);
    mdl_cos__phiWmu = cos(mdl_phiWmu);
    mdl_sin__phiWmu = sin(mdl_phiWmu);
    mdl_cos__phiWtau = cos(mdl_phiWtau);
    mdl_sin__phiWtau = sin(mdl_phiWtau);
    mdl_aEW = 1. / aEWM1;
    mdl_sqrt__aEW = sqrt(mdl_aEW);
    mdl_ee = 2. * mdl_sqrt__aEW * sqrt(M_PI);

    mdl_MW = sqrt(mdl_MZ__exp__2 / 2. +
                  sqrt(mdl_MZ__exp__4 / 4. - (mdl_aEW * M_PI * mdl_MZ__exp__2) /
                                                 (mdl_Gf * mdl_sqrt__2)));
    const double mdl_MW__exp__2 = pow(mdl_MW, 2.);
    const double mdl_sw2 = 1. - mdl_MW__exp__2 / mdl_MZ__exp__2;
    const double mdl_sqrt__sw2 = sqrt(mdl_sw2);
    const double mdl_sw = mdl_sqrt__sw2;
    mdl_vev = (2. * mdl_MW * mdl_sw) / mdl_ee;
}
void Parameters_HiggsPO_UFO::setIndependentCouplings()
{
    GC_3 = -(mdl_ee * mdl_complexi);
    GC_9 = (-2. * mdl_eggSM * mdl_complexi) / mdl_vev;
}
void Parameters_HiggsPO_UFO::setDependentParameters()
{
    mdl_sqrt__aS = sqrt(aS);
    G = 2. * mdl_sqrt__aS * sqrt(M_PI);
    mdl_G__exp__2 = pow(G, 2.);

    GC_8 = (2. * mdl_complexi * mdl_kZZ * mdl_MZ__exp__2) / mdl_vev +
           (2. * mdl_complexi * mdl_MZ__exp__2 * mdl_noise) / mdl_vev;
    GC_12 = (2. * mdl_eZeL * mdl_complexi) / mdl_vev;
    GC_13 = (2. * mdl_eZeR * mdl_complexi) / mdl_vev;
    GC_14 = (2. * mdl_eZmuL * mdl_complexi) / mdl_vev;
    GC_15 = (2. * mdl_eZmuR * mdl_complexi) / mdl_vev;
    GC_19 = (-2. * mdl_eZZ * mdl_complexi) / mdl_vev;
    GC_20 = -((mdl_eZZCP * mdl_complexi) / mdl_vev);
    GC_23 = (-2. * mdl_eAASM * mdl_complexi * mdl_kAA) / mdl_vev;
    GC_24 = (-2. * mdl_eZASM * mdl_complexi * mdl_kZA) / mdl_vev;
    GC_25 = -((mdl_eAASM * mdl_complexi * mdl_lAACP) / mdl_vev);
    GC_26 = (-2. * mdl_eZASM * mdl_complexi * mdl_lZACP) / mdl_vev;
    GC_30 = (2. * mdl_complexi * mdl_gZeL * mdl_MZ) / mdl_vev;
    GC_31 = (2. * mdl_complexi * mdl_gZeR * mdl_MZ) / mdl_vev;
    GC_32 = (2. * mdl_complexi * mdl_gZmuL * mdl_MZ) / mdl_vev;
    GC_33 = (2. * mdl_complexi * mdl_gZmuR * mdl_MZ) / mdl_vev;
}
void Parameters_HiggsPO_UFO::setDependentCouplings() {}

// Routines for printing out parameters
void Parameters_HiggsPO_UFO::printIndependentParameters()
{
    cout << "HiggsPO_UFO model parameters independent of event kinematics:"
         << endl;
    cout << setw(20) << "mdl_WH "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_WH << endl;
    cout << setw(20) << "mdl_WW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_WW << endl;
    cout << setw(20) << "mdl_WZ "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_WZ << endl;
    cout << setw(20) << "mdl_WT "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_WT << endl;
    cout << setw(20) << "mdl_gWtau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gWtau
         << endl;
    cout << setw(20) << "mdl_gWmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gWmu
         << endl;
    cout << setw(20) << "mdl_gWe "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gWe << endl;
    cout << setw(20) << "mdl_gZv "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZv << endl;
    cout << setw(20) << "mdl_gZtauR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZtauR
         << endl;
    cout << setw(20) << "mdl_gZmuR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZmuR
         << endl;
    cout << setw(20) << "mdl_gZeR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZeR
         << endl;
    cout << setw(20) << "mdl_gZtauL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZtauL
         << endl;
    cout << setw(20) << "mdl_gZmuL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZmuL
         << endl;
    cout << setw(20) << "mdl_gZeL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_gZeL
         << endl;
    cout << setw(20) << "aS "
         << "= " << setiosflags(ios::scientific) << setw(10) << aS << endl;
    cout << setw(20) << "mdl_vev "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_vev << endl;
    cout << setw(20) << "aEWM1 "
         << "= " << setiosflags(ios::scientific) << setw(10) << aEWM1 << endl;
    cout << setw(20) << "mdl_MH "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MH << endl;
    cout << setw(20) << "mdl_MW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MW << endl;
    cout << setw(20) << "mdl_MZ "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MZ << endl;
    cout << setw(20) << "mdl_MTA "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MTA << endl;
    cout << setw(20) << "mdl_MT "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MT << endl;
    cout << setw(20) << "mdl_MB "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MB << endl;
    cout << setw(20) << "mdl_MC "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MC << endl;
    cout << setw(20) << "mdl_ymueff "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ymueff
         << endl;
    cout << setw(20) << "mdl_ytaueff "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ytaueff
         << endl;
    cout << setw(20) << "mdl_yceff "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_yceff
         << endl;
    cout << setw(20) << "mdl_ybeff "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ybeff
         << endl;
    cout << setw(20) << "mdl_eZASM "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZASM
         << endl;
    cout << setw(20) << "mdl_eAASM "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eAASM
         << endl;
    cout << setw(20) << "mdl_phiWtau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_phiWtau
         << endl;
    cout << setw(20) << "mdl_phiWmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_phiWmu
         << endl;
    cout << setw(20) << "mdl_phiWe "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_phiWe
         << endl;
    cout << setw(20) << "mdl_eWtau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eWtau
         << endl;
    cout << setw(20) << "mdl_eWmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eWmu
         << endl;
    cout << setw(20) << "mdl_eWe "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eWe << endl;
    cout << setw(20) << "mdl_eZv "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZv << endl;
    cout << setw(20) << "mdl_eZtauR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZtauR
         << endl;
    cout << setw(20) << "mdl_eZmuR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZmuR
         << endl;
    cout << setw(20) << "mdl_eZeR "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZeR
         << endl;
    cout << setw(20) << "mdl_eZtauL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZtauL
         << endl;
    cout << setw(20) << "mdl_eZmuL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZmuL
         << endl;
    cout << setw(20) << "mdl_eZeL "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZeL
         << endl;
    cout << setw(20) << "mdl_eWWCP "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eWWCP
         << endl;
    cout << setw(20) << "mdl_eZZCP "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZZCP
         << endl;
    cout << setw(20) << "mdl_lZACP "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_lZACP
         << endl;
    cout << setw(20) << "mdl_lAACP "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_lAACP
         << endl;
    cout << setw(20) << "mdl_eWW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eWW << endl;
    cout << setw(20) << "mdl_eZZ "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eZZ << endl;
    cout << setw(20) << "mdl_kZA "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kZA << endl;
    cout << setw(20) << "mdl_kAA "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kAA << endl;
    cout << setw(20) << "mdl_kWW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kWW << endl;
    cout << setw(20) << "mdl_kZZ "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kZZ << endl;
    cout << setw(20) << "mdl_lmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_lmu << endl;
    cout << setw(20) << "mdl_ltau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ltau
         << endl;
    cout << setw(20) << "mdl_lc "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_lc << endl;
    cout << setw(20) << "mdl_lb "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_lb << endl;
    cout << setw(20) << "mdl_kmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kmu << endl;
    cout << setw(20) << "mdl_ktau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ktau
         << endl;
    cout << setw(20) << "mdl_kc "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kc << endl;
    cout << setw(20) << "mdl_kb "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_kb << endl;
    cout << setw(20) << "mdl_eggSM "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_eggSM
         << endl;
    cout << setw(20) << "mdl_noise "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_noise
         << endl;
    cout << setw(20) << "mdl_complexi "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_complexi
         << endl;
    cout << setw(20) << "mdl_MW__exp__2 "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MW__exp__2
         << endl;
    cout << setw(20) << "mdl_MZ__exp__2 "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_MZ__exp__2
         << endl;
    cout << setw(20) << "mdl_sqrt__2 "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sqrt__2
         << endl;
    cout << setw(20) << "mdl_cos__phiWe "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_cos__phiWe
         << endl;
    cout << setw(20) << "mdl_sin__phiWe "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sin__phiWe
         << endl;
    cout << setw(20) << "mdl_cos__phiWmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_cos__phiWmu
         << endl;
    cout << setw(20) << "mdl_sin__phiWmu "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sin__phiWmu
         << endl;
    cout << setw(20) << "mdl_cos__phiWtau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_cos__phiWtau
         << endl;
    cout << setw(20) << "mdl_sin__phiWtau "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sin__phiWtau
         << endl;
    cout << setw(20) << "mdl_aEW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_aEW << endl;
    cout << setw(20) << "mdl_sqrt__aEW "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sqrt__aEW
         << endl;
    cout << setw(20) << "mdl_ee "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_ee << endl;
}
void Parameters_HiggsPO_UFO::printIndependentCouplings()
{
    cout << "HiggsPO_UFO model couplings independent of event kinematics:"
         << endl;
    cout << setw(20) << "GC_3 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_3 << endl;
    cout << setw(20) << "GC_8 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_8 << endl;
    cout << setw(20) << "GC_9 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_9 << endl;
    cout << setw(20) << "GC_12 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_12 << endl;
    cout << setw(20) << "GC_13 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_13 << endl;
    cout << setw(20) << "GC_14 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_14 << endl;
    cout << setw(20) << "GC_15 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_15 << endl;
    cout << setw(20) << "GC_19 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_19 << endl;
    cout << setw(20) << "GC_20 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_20 << endl;
    cout << setw(20) << "GC_23 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_23 << endl;
    cout << setw(20) << "GC_24 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_24 << endl;
    cout << setw(20) << "GC_25 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_25 << endl;
    cout << setw(20) << "GC_26 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_26 << endl;
    cout << setw(20) << "GC_30 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_30 << endl;
    cout << setw(20) << "GC_31 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_31 << endl;
    cout << setw(20) << "GC_32 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_32 << endl;
    cout << setw(20) << "GC_33 "
         << "= " << setiosflags(ios::scientific) << setw(10) << GC_33 << endl;
}
void Parameters_HiggsPO_UFO::printDependentParameters()
{
    cout << "HiggsPO_UFO model parameters dependent on event kinematics:"
         << endl;
    cout << setw(20) << "mdl_sqrt__aS "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_sqrt__aS
         << endl;
    cout << setw(20) << "G "
         << "= " << setiosflags(ios::scientific) << setw(10) << G << endl;
    cout << setw(20) << "mdl_G__exp__2 "
         << "= " << setiosflags(ios::scientific) << setw(10) << mdl_G__exp__2
         << endl;
}
void Parameters_HiggsPO_UFO::printDependentCouplings()
{
    cout << "HiggsPO_UFO model couplings dependent on event kinematics:"
         << endl;
}
