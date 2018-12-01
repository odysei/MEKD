//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef HelAmps_HEF_MEKD2_1_H
#define HelAmps_HEF_MEKD2_1_H

#include <cmath>
#include <complex>

namespace MG5_HEF_MEKD2_1
{
double Sgn(double e, double f);

void oxxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fo[6]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv,
            std::complex<double> v[6]);

void txxxxx(double p[4], double tmass, int nhel, int nst,
            std::complex<double> fi[18]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]);

void ixxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fi[6]);

void FFV7_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFV2_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void VVT12_0(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> T3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV5_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);
void FFV5_7_3(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M3,
              double W3, std::complex<double> V3[]);

void VVT11_0(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> T3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV5_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);
void FFV5_7_1(std::complex<double> F2[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M1,
              double W1, std::complex<double> F1[]);

void VVT7_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFT2_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT13_0(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> T3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void VVT8_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT3_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV7_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFT5_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV5_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);
void FFV5_7_2(std::complex<double> F1[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M2,
              double W2, std::complex<double> F2[]);

void FFV7_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void FFV2_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFT3_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT10_0(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> T3[], std::complex<double> COUP,
             std::complex<double> &vertex);
void VVT10_11_12_13_2_3_6_7_8_9_0(
    std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> T3[], std::complex<double> COUP1,
    std::complex<double> COUP2, std::complex<double> COUP3,
    std::complex<double> COUP4, std::complex<double> COUP5,
    std::complex<double> COUP6, std::complex<double> COUP7,
    std::complex<double> COUP8, std::complex<double> COUP9,
    std::complex<double> COUP10, std::complex<double> &vertex);

void VVT9_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT6_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV2P0_3(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> COUP, double M3, double W3,
              std::complex<double> V3[]);

void FFT1_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);
void FFT1_2_3_5_0(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> T3[], std::complex<double> COUP1,
                  std::complex<double> COUP2, std::complex<double> COUP3,
                  std::complex<double> COUP4, std::complex<double> &vertex);

void VVT2_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT13_1(std::complex<double> V2[], std::complex<double> T3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> V1[]);

void FFT4_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> T3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV8_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFT3_1(std::complex<double> F2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void VVT6_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVT10_3(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> T3[]);
void VVT10_11_12_13_2_3_6_7_8_9_3(
    std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP1, std::complex<double> COUP2,
    std::complex<double> COUP3, std::complex<double> COUP4,
    std::complex<double> COUP5, std::complex<double> COUP6,
    std::complex<double> COUP7, std::complex<double> COUP8,
    std::complex<double> COUP9, std::complex<double> COUP10, double M3,
    double W3, std::complex<double> T3[]);

void FFV6_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void VVT12_1(std::complex<double> V2[], std::complex<double> T3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> V1[]);

void FFV5_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);
void FFV5_7_0(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> V3[], std::complex<double> COUP1,
              std::complex<double> COUP2, std::complex<double> &vertex);
void FFV5_6_0(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> V3[], std::complex<double> COUP1,
              std::complex<double> COUP2, std::complex<double> &vertex);
void FFV5_8_0(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> V3[], std::complex<double> COUP1,
              std::complex<double> COUP2, std::complex<double> &vertex);

void VVT7_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void VVT11_1(std::complex<double> V2[], std::complex<double> T3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> V1[]);

void FFT2_1(std::complex<double> F2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void VVT8_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFV8_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void VVT2_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void VVT5_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFT1_2(std::complex<double> F1[], std::complex<double> T3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);
void FFT1_2_3_5_2(std::complex<double> F1[], std::complex<double> T3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M2, double W2, std::complex<double> F2[]);
void FFT1_2_4_5_2(std::complex<double> F1[], std::complex<double> T3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M2, double W2, std::complex<double> F2[]);

void FFT4_2(std::complex<double> F1[], std::complex<double> T3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFT3_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFT5_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void VVT3_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVT10_1(std::complex<double> V2[], std::complex<double> T3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> V1[]);
void VVT10_11_12_13_2_3_6_7_8_9_1(
    std::complex<double> V2[], std::complex<double> T3[],
    std::complex<double> COUP1, std::complex<double> COUP2,
    std::complex<double> COUP3, std::complex<double> COUP4,
    std::complex<double> COUP5, std::complex<double> COUP6,
    std::complex<double> COUP7, std::complex<double> COUP8,
    std::complex<double> COUP9, std::complex<double> COUP10, double M1,
    double W1, std::complex<double> V1[]);

void FFT2_2(std::complex<double> F1[], std::complex<double> T3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void VVT12_3(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> T3[]);

void FFV5_6_2(std::complex<double> F1[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M2,
              double W2, std::complex<double> F2[]);
void FFV5_8_2(std::complex<double> F1[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M2,
              double W2, std::complex<double> F2[]);

void VVT11_3(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> T3[]);

void VVT1_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);
void VVT1_10_11_12_13_3_5_7_8_9_3(
    std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP1, std::complex<double> COUP2,
    std::complex<double> COUP3, std::complex<double> COUP4,
    std::complex<double> COUP5, std::complex<double> COUP6,
    std::complex<double> COUP7, std::complex<double> COUP8,
    std::complex<double> COUP9, std::complex<double> COUP10, double M3,
    double W3, std::complex<double> T3[]);

void FFV8_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVT2_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void FFT1_2_4_5_0(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> T3[], std::complex<double> COUP1,
                  std::complex<double> COUP2, std::complex<double> COUP3,
                  std::complex<double> COUP4, std::complex<double> &vertex);

void FFV6_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFT5_1(std::complex<double> F2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void VVT3_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFV2_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV5_6_1(std::complex<double> F2[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M1,
              double W1, std::complex<double> F1[]);

void FFV5_8_1(std::complex<double> F2[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M1,
              double W1, std::complex<double> F1[]);

void VVT9_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFT1_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);
void FFT1_2_4_5_3(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M3, double W3, std::complex<double> T3[]);
void FFT1_2_3_5_3(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M3, double W3, std::complex<double> T3[]);

void FFT4_1(std::complex<double> F2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFV6_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void VVT13_3(std::complex<double> V1[], std::complex<double> V2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> T3[]);

void FFV5_6_3(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M3,
              double W3, std::complex<double> V3[]);

void FFV5_8_3(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M3,
              double W3, std::complex<double> V3[]);

void VVT4_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFV8_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void VVT9_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVT6_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFT1_1(std::complex<double> F2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);
void FFT1_2_3_5_1(std::complex<double> F2[], std::complex<double> T3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M1, double W1, std::complex<double> F1[]);
void FFT1_2_4_5_1(std::complex<double> F2[], std::complex<double> T3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M1, double W1, std::complex<double> F1[]);

void FFT4_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void FFT3_2(std::complex<double> F1[], std::complex<double> T3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFV6_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFT5_2(std::complex<double> F1[], std::complex<double> T3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void VVT7_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void FFT2_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> T3[]);

void VVT8_1(std::complex<double> V2[], std::complex<double> T3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void FFV7_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV3_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVV2_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVV1_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);
void VVV1_2_0(std::complex<double> V1[], std::complex<double> V2[],
              std::complex<double> V3[], std::complex<double> COUP1,
              std::complex<double> COUP2, std::complex<double> &vertex);

void FFV4_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV1_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> V3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFV1_2_3_4_0(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> V3[], std::complex<double> COUP1,
                  std::complex<double> COUP2, std::complex<double> COUP3,
                  std::complex<double> COUP4, std::complex<double> &vertex);

void FFV3_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFV1_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);
void FFV1_2_3_4_2(std::complex<double> F1[], std::complex<double> V3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M2, double W2, std::complex<double> F2[]);

void VVV2_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void VVV1_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);
void VVV1_2_3(std::complex<double> V1[], std::complex<double> V2[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M3,
              double W3, std::complex<double> V3[]);

void FFV4_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFV1_1(std::complex<double> F2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);
void FFV1_2_3_4_1(std::complex<double> F2[], std::complex<double> V3[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M1, double W1, std::complex<double> F1[]);

void FFV3_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void FFV4_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFV2_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void FFV3_2(std::complex<double> F1[], std::complex<double> V3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFV1_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);
void FFV1_2_3_4_3(std::complex<double> F1[], std::complex<double> F2[],
                  std::complex<double> COUP1, std::complex<double> COUP2,
                  std::complex<double> COUP3, std::complex<double> COUP4,
                  double M3, double W3, std::complex<double> V3[]);

void VVV2_1(std::complex<double> V2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVV1_1(std::complex<double> V2[], std::complex<double> V3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);
void VVV1_2_1(std::complex<double> V2[], std::complex<double> V3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M1,
              double W1, std::complex<double> V1[]);

void FFV4_3(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> V3[]);

void VVS3_4_5_0(std::complex<double> V1[], std::complex<double> V2[],
                std::complex<double> S3[], std::complex<double> COUP1,
                std::complex<double> COUP2, std::complex<double> COUP3,
                std::complex<double> &vertex);

void VVS3_4_5_3(std::complex<double> V1[], std::complex<double> V2[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                std::complex<double> COUP3, double M3, double W3,
                std::complex<double> S3[]);

void VVS1_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> S3[]);

void VVS2_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVS2_1(std::complex<double> V2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVS3_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVS3_1(std::complex<double> V2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVS3_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> S3[]);

void VVS3_4_5_1(std::complex<double> V2[], std::complex<double> S3[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                std::complex<double> COUP3, double M1, double W1,
                std::complex<double> V1[]);

void VVS4_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVS4_1(std::complex<double> V2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVS4_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> S3[]);

void VVS5_0(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void VVS5_1(std::complex<double> V2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> V1[]);

void VVS5_3(std::complex<double> V1[], std::complex<double> V2[],
            std::complex<double> COUP, double M3, double W3,
            std::complex<double> S3[]);

void FFS1_2_0(std::complex<double> F1[], std::complex<double> F2[],
              std::complex<double> S3[], std::complex<double> COUP1,
              std::complex<double> COUP2, std::complex<double> &vertex);

void FFS1_2_1(std::complex<double> F2[], std::complex<double> S3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M1,
              double W1, std::complex<double> F1[]);

void FFS1_2_2(std::complex<double> F1[], std::complex<double> S3[],
              std::complex<double> COUP1, std::complex<double> COUP2, double M2,
              double W2, std::complex<double> F2[]);

void FFS1_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFS1_1(std::complex<double> F2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFS1_2(std::complex<double> F1[], std::complex<double> S3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

void FFS2_0(std::complex<double> F1[], std::complex<double> F2[],
            std::complex<double> S3[], std::complex<double> COUP,
            std::complex<double> &vertex);

void FFS2_1(std::complex<double> F2[], std::complex<double> S3[],
            std::complex<double> COUP, double M1, double W1,
            std::complex<double> F1[]);

void FFS2_2(std::complex<double> F1[], std::complex<double> S3[],
            std::complex<double> COUP, double M2, double W2,
            std::complex<double> F2[]);

} // end namespace MG5_HEF_MEKD2_1

#endif // HelAmps_HEF_MEKD2_1_H
