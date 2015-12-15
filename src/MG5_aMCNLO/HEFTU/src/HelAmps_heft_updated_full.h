//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef HelAmps_heft_updated_full_H
#define HelAmps_heft_updated_full_H

#include <cmath>
#include <complex>

using namespace std;

namespace MG5_heft_updated_full
{
void vxxxxx(double p[4], double vmass, int nhel, int nsv,
            std::complex<double> v[6]);

double Sgn(double e, double f);

void ixxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fi[6]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]);

void txxxxx(double p[4], double tmass, int nhel, int nst,
            std::complex<double> fi[18]);

void oxxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fo[6]);

void FFS2_0(complex<double> F1[], complex<double> F2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);

void FFV1P0_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
              double M3, double W3, complex<double> V3[]);

void FFV3_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[]);

void FFV5_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[]);

void FFV1_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[]);

void FFV2_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex);
void FFV2_5_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex);
void FFV2_3_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex);

void VVS3_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);

void VVVV4_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
             complex<double> V4[], complex<double> COUP,
             complex<double> &vertex);

void FFV5_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[]);

void VVV1_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex);

void FFV1_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[]);

void VVVV3_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
             complex<double> V4[], complex<double> COUP,
             complex<double> &vertex);

void FFS2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[]);

void FFV2_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[]);
void FFV2_5_2(complex<double> F1[], complex<double> V3[], complex<double> COUP1,
              complex<double> COUP2, double M2, double W2,
              complex<double> F2[]);
void FFV2_3_2(complex<double> F1[], complex<double> V3[], complex<double> COUP1,
              complex<double> COUP2, double M2, double W2,
              complex<double> F2[]);

void FFV1_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex);

void FFV3_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex);

void FFS2_1(complex<double> F2[], complex<double> S3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[]);

void FFV2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[]);
void FFV2_5_3(complex<double> F1[], complex<double> F2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3,
              complex<double> V3[]);
void FFV2_3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3,
              complex<double> V3[]);

void FFV5_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[]);

void FFV3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[]);

void VVVV1_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
             complex<double> V4[], complex<double> COUP,
             complex<double> &vertex);

void FFV2_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[]);
void FFV2_5_1(complex<double> F2[], complex<double> V3[], complex<double> COUP1,
              complex<double> COUP2, double M1, double W1,
              complex<double> F1[]);
void FFV2_3_1(complex<double> F2[], complex<double> V3[], complex<double> COUP1,
              complex<double> COUP2, double M1, double W1,
              complex<double> F1[]);

void VVS3_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex);

void FFV5_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex);

void FFV3_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[]);

void VVVS2_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
             complex<double> S4[], complex<double> COUP,
             complex<double> &vertex);

void VVS3P0_1(complex<double> V2[], complex<double> S3[], complex<double> COUP,
              double M1, double W1, complex<double> V1[]);

void FFS2_2(complex<double> F1[], complex<double> S3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[]);

void VVV1P0_1(complex<double> V2[], complex<double> V3[], complex<double> COUP,
              double M1, double W1, complex<double> V1[]);

} // end namespace MG5_heft_updated_full

#endif // HelAmps_heft_updated_full_H
