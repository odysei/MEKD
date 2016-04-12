//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef HelAmps_HiggsPO_UFO_H
#define HelAmps_HiggsPO_UFO_H

#include <cmath>
#include <complex>

using namespace std;

namespace MG5_HiggsPO_UFO
{
double Sgn(double e, double f);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv,
            std::complex<double> v[6]);

void txxxxx(double p[4], double tmass, int nhel, int nst,
            std::complex<double> fi[18]);

void ixxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fi[6]);

void oxxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fo[6]);

void FFV2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[]);
void FFV2_3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3,
              complex<double> V3[]);

void FFV1P0_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
              double M3, double W3, complex<double> V3[]);

void FFVS2_4(complex<double> F1[], complex<double> F2[], complex<double> V3[],
             complex<double> COUP, double M4, double W4, complex<double> S4[]);

void FFVS1_4(complex<double> F1[], complex<double> F2[], complex<double> V3[],
             complex<double> COUP, double M4, double W4, complex<double> S4[]);
void FFVS1_2_4(complex<double> F1[], complex<double> F2[], complex<double> V3[],
               complex<double> COUP1, complex<double> COUP2, double M4,
               double W4, complex<double> S4[]);

void FFV3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[]);

void VVS3_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);
void VVS3_5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3,
              complex<double> S3[]);
void VVS3_4_5_3(complex<double> V1[], complex<double> V2[],
                complex<double> COUP1, complex<double> COUP2,
                complex<double> COUP3, double M3, double W3,
                complex<double> S3[]);

void VVS5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);

void VVS1_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);
void VVS1_5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3,
              complex<double> S3[]);

void VVS5_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);

void VVS4_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);

void VVS3_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);
void VVS3_4_5_0(complex<double> V1[], complex<double> V2[],
                complex<double> S3[], complex<double> COUP1,
                complex<double> COUP2, complex<double> COUP3,
                complex<double> &vertex);
void VVS3_5_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex);

void VVS4_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);

void FFVS2_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
             complex<double> S4[], complex<double> COUP,
             complex<double> &vertex);

void FFVS1_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
             complex<double> S4[], complex<double> COUP,
             complex<double> &vertex);
void FFVS1_2_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
               complex<double> S4[], complex<double> COUP1,
               complex<double> COUP2, complex<double> &vertex);

void VVS1_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);
void VVS1_5_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex);

} // end namespace MG5_HiggsPO_UFO

#endif // HelAmps_HiggsPO_UFO_H
