//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph 5 v. 1.5.3, 2012-11-01
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef HelAmps_HEF_UFO_bkg_H
#define HelAmps_HEF_UFO_bkg_H

#include <cmath>
#include <complex>

namespace MG5_HEF_UFO_bkg
{
double Sgn(double e, double f);

void ixxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fi[6]);

void oxxxxx(double p[4], double fmass, int nhel, int nsf,
            std::complex<double> fo[6]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv,
            std::complex<double> v[6]);

void FFV43_3(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> V3[]);

void FFV43_0(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> V3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV44_2(std::complex<double> F1[], std::complex<double> V3[],
             std::complex<double> COUP, double M2, double W2,
             std::complex<double> F2[]);

void FFV42_2(std::complex<double> F1[], std::complex<double> V3[],
             std::complex<double> COUP, double M2, double W2,
             std::complex<double> F2[]);
void FFV42_43_2(std::complex<double> F1[], std::complex<double> V3[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M2, double W2, std::complex<double> F2[]);
void FFV42_44_2(std::complex<double> F1[], std::complex<double> V3[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M2, double W2, std::complex<double> F2[]);
void FFV42_45_2(std::complex<double> F1[], std::complex<double> V3[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M2, double W2, std::complex<double> F2[]);

void FFV44_0(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> V3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV42_0(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> V3[], std::complex<double> COUP,
             std::complex<double> &vertex);
void FFV42_45_0(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> V3[], std::complex<double> COUP1,
                std::complex<double> COUP2, std::complex<double> &vertex);
void FFV42_43_0(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> V3[], std::complex<double> COUP1,
                std::complex<double> COUP2, std::complex<double> &vertex);
void FFV42_44_0(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> V3[], std::complex<double> COUP1,
                std::complex<double> COUP2, std::complex<double> &vertex);

void FFV45_3(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> V3[]);

void FFV41_0(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> V3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV41_2(std::complex<double> F1[], std::complex<double> V3[],
             std::complex<double> COUP, double M2, double W2,
             std::complex<double> F2[]);

void FFV43_2(std::complex<double> F1[], std::complex<double> V3[],
             std::complex<double> COUP, double M2, double W2,
             std::complex<double> F2[]);

void FFV44_3(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> V3[]);

void FFV42_3(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> V3[]);
void FFV42_43_3(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M3, double W3, std::complex<double> V3[]);
void FFV42_44_3(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M3, double W3, std::complex<double> V3[]);
void FFV42_45_3(std::complex<double> F1[], std::complex<double> F2[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M3, double W3, std::complex<double> V3[]);

void FFV44_1(std::complex<double> F2[], std::complex<double> V3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> F1[]);

void FFV45_0(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> V3[], std::complex<double> COUP,
             std::complex<double> &vertex);

void FFV41_1(std::complex<double> F2[], std::complex<double> V3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> F1[]);

void FFV42_1(std::complex<double> F2[], std::complex<double> V3[],
             std::complex<double> COUP, double M1, double W1,
             std::complex<double> F1[]);
void FFV42_44_1(std::complex<double> F2[], std::complex<double> V3[],
                std::complex<double> COUP1, std::complex<double> COUP2,
                double M1, double W1, std::complex<double> F1[]);

void FFV45_2(std::complex<double> F1[], std::complex<double> V3[],
             std::complex<double> COUP, double M2, double W2,
             std::complex<double> F2[]);

void FFV41_3(std::complex<double> F1[], std::complex<double> F2[],
             std::complex<double> COUP, double M3, double W3,
             std::complex<double> V3[]);

} // namespace MG5_HEF_UFO_bkg

#endif // HelAmps_HEF_UFO_bkg_H
