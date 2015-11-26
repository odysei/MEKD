#ifndef MEKD_CalcHEP_Extra_CPP
#define MEKD_CalcHEP_Extra_CPP

#include "MEKD_CalcHEP_Extra_functions.h"

namespace MEKD_CalcHEP_Extra
{

/// Parameters for Higgs width polynomial fit
// <Higgs width>_<polynomial fit>_<fit zone>_<coefficient>
long double wH_poly_z1_c0 = -1.450308902710193E+03;
long double wH_poly_z1_c1 = 1.129291251156317E+02;
long double wH_poly_z1_c2 = -3.893063071316150E+00;
long double wH_poly_z1_c3 = 7.798666884832531E-02;
long double wH_poly_z1_c4 = -1.000455877406390E-03;
long double wH_poly_z1_c5 = 8.523735379647125E-06;
long double wH_poly_z1_c6 = -4.823164754652171E-08;
long double wH_poly_z1_c7 = 1.747954506786346E-10;
long double wH_poly_z1_c8 = -3.681723572169337E-13;
long double wH_poly_z1_c9 = 3.434207075968898E-16;

long double wH_poly_z2_c0 = 2.563291882845993E+02;
long double wH_poly_z2_c1 = -1.037082025855304E+01;
long double wH_poly_z2_c2 = 1.780260502696301E-01;
long double wH_poly_z2_c3 = -1.720311784419889E-03;
long double wH_poly_z2_c4 = 1.038418605369741E-05;
long double wH_poly_z2_c5 = -4.092496883922424E-08;
long double wH_poly_z2_c6 = 1.067667966800388E-10;
long double wH_poly_z2_c7 = -1.823343280081685E-13;
long double wH_poly_z2_c8 = 1.955637395597351E-16;
long double wH_poly_z2_c9 = -1.193287048560413E-19;
long double wH_poly_z2_c10 = 3.156196649452213E-23;

long double wH_poly_z12_c0 = -5.255605465437446E+02;
long double wH_poly_z12_c1 = 1.036972988796150E+01;
long double wH_poly_z12_c2 = -6.817022987365029E-02;
long double wH_poly_z12_c3 = 1.493275723660056E-04;

/// Functions

void Flip_1_and_2_Six_Fourmomenta(double *input)
{
    const double in0 = input[0];
    const double in1 = input[1];
    const double in2 = input[2];
    const double in3 = input[3];

    const double in4 = input[4];
    const double in5 = input[5];
    const double in6 = input[6];
    const double in7 = input[7];

    input[0] = in4;
    input[1] = in5;
    input[2] = in6;
    input[3] = in7;

    input[4] = in0;
    input[5] = in1;
    input[6] = in2;
    input[7] = in3;
}

void Reorder_for_4e_4m(double *input)
{
    double pvecNEW[24];

    /// Initial state particles are in the same order
    unsigned int count = 0;
    for (; count < 4; count++) {
        pvecNEW[count] =
            input[count]; /// Initial state particles are in the same order
        pvecNEW[count + 4] =
            input[count + 4]; /// Initial state particles are in the same order
        pvecNEW[count + 8] = input[count + 8];   /// The first particle e1/m1
        pvecNEW[count + 12] = input[count + 16]; /// The second particle e2/m2
        pvecNEW[count + 16] = input[count + 12]; /// The third particle E1/M1
        pvecNEW[count + 20] = input[count + 20]; /// The fourth particle E2/E2
    }

    count = 0;
    for (; count < 24; count++)
        input[count] = pvecNEW[count];
}

long double Higgs_width(double input_mass)
{
    return Higgs_width_Poly_Fit_Estm(input_mass);
}

long double Higgs_width_Poly_Fit_Estm(double mass)
{
    /*
     * ~0.57% value and error phase jump at 156.5 transition point
     * ~2.1% value and error phase jump at 162 transition point
     */
    if (mass < 90)
        return (static_cast<long double>(
            0.00215708)); // a lower cut-off value of m_H = 90 GeV
    if (mass < 156.5)
        return (wH_poly_z1_c0 + wH_poly_z1_c1 * mass +
                wH_poly_z1_c2 * mass * mass +
                wH_poly_z1_c3 * mass * mass * mass +
                wH_poly_z1_c4 * mass * mass * mass * mass +
                wH_poly_z1_c5 * mass * mass * mass * mass * mass +
                wH_poly_z1_c6 * mass * mass * mass * mass * mass * mass +
                wH_poly_z1_c7 * mass * mass * mass * mass * mass * mass * mass +
                wH_poly_z1_c8 * mass * mass * mass * mass * mass * mass * mass *
                    mass +
                wH_poly_z1_c9 * mass * mass * mass * mass * mass * mass * mass *
                    mass * mass);
    if (mass >= 156.5 && mass <= 162)
        return (wH_poly_z12_c0 + wH_poly_z12_c1 * mass +
                wH_poly_z12_c2 * mass * mass +
                wH_poly_z12_c3 * mass * mass * mass);
    else
        return (wH_poly_z2_c0 + wH_poly_z2_c1 * mass +
                wH_poly_z2_c2 * mass * mass +
                wH_poly_z2_c3 * mass * mass * mass +
                wH_poly_z2_c4 * mass * mass * mass * mass +
                wH_poly_z2_c5 * mass * mass * mass * mass * mass +
                wH_poly_z2_c6 * mass * mass * mass * mass * mass * mass +
                wH_poly_z2_c7 * mass * mass * mass * mass * mass * mass * mass +
                wH_poly_z2_c8 * mass * mass * mass * mass * mass * mass * mass *
                    mass +
                wH_poly_z2_c9 * mass * mass * mass * mass * mass * mass * mass *
                    mass * mass +
                wH_poly_z2_c10 * mass * mass * mass * mass * mass * mass *
                    mass * mass * mass * mass);
}

double Higgs_width_Poly_Fit_Estm_Old(double mass)
{
    if (mass < 155.4)
        return (-0.0003982887 + 2.8839818619E-5 * mass);
    else
        return (-64.1762988603 + 1.5505064883 * mass -
                0.0155128711 * mass * mass +
                8.0920712725E-005 * mass * mass * mass -
                2.2908364933E-007 * mass * mass * mass * mass +
                3.369668895869E-010 * mass * mass * mass * mass * mass -
                1.98226166939E-013 * mass * mass * mass * mass * mass * mass);
}
}

#endif