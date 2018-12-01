//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 1.5.7, 2013-01-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "HelAmps_HEF_MEKD.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace MG5_HEF_MEKD
{

inline double Sgn(double a, double b) { return (b < 0) ? -abs(a) : abs(a); }

void oxxxxx(double p[4], double fmass, int nhel, int nsf, complex<double> fo[6])
{
    complex<double> chi[2];
    double sf[2], sfomeg[2], omega[2], pp, pp3, sqp0p3, sqm[2];
    int nh, ip, im;
    fo[0] = complex<double>(p[0] * nsf, p[3] * nsf);
    fo[1] = complex<double>(p[1] * nsf, p[2] * nsf);
    nh = nhel * nsf;
    if (fmass != 0.000) {
        pp = min(p[0], pow(pow(p[1], 2) + pow(p[2], 2) + pow(p[3], 2), 0.5));
        if (pp == 0.000) {
            sqm[0] = pow(abs(fmass), 0.5);
            sqm[1] = Sgn(sqm[0], fmass);
            ip = -((1 - nh) / 2) * nhel;
            im = (1 + nh) / 2 * nhel;
            fo[2] = im * sqm[im];
            fo[3] = ip * nsf * sqm[im];
            fo[4] = im * nsf * sqm[-ip];
            fo[5] = ip * sqm[-ip];
        } else {
            pp =
                min(p[0], pow(pow(p[1], 2) + pow(p[2], 2) + pow(p[3], 2), 0.5));
            sf[0] = double(1 + nsf + (1 - nsf) * nh) * 0.5;
            sf[1] = double(1 + nsf - (1 - nsf) * nh) * 0.5;
            omega[0] = pow(p[0] + pp, 0.5);
            omega[1] = fmass / omega[0];
            ip = (1 + nh) / 2;
            im = (1 - nh) / 2;
            sfomeg[0] = sf[0] * omega[ip];
            sfomeg[1] = sf[1] * omega[im];
            pp3 = max(pp + p[3], 0.00);
            chi[0] = complex<double>(pow(pp3 * 0.5 / pp, 0.5), 0.00);
            if (pp3 == 0.00) {
                chi[1] = complex<double>(-nh, 0.00);
            } else {
                chi[1] = complex<double>(nh * p[1], -p[2]) /
                         pow(2.0 * pp * pp3, 0.5);
            }
            fo[2] = sfomeg[1] * chi[im];
            fo[3] = sfomeg[1] * chi[ip];
            fo[4] = sfomeg[0] * chi[im];
            fo[5] = sfomeg[0] * chi[ip];
        }
    } else {
        if ((p[1] == 0.00) and (p[2] == 0.00) and (p[3] < 0.00)) {
            sqp0p3 = 0.00;
        } else {
            sqp0p3 = pow(max(p[0] + p[3], 0.00), 0.5) * nsf;
        }
        chi[0] = complex<double>(sqp0p3, 0.00);
        if (sqp0p3 == 0.000) {
            chi[1] = complex<double>(-nhel, 0.00) * pow(2.0 * p[0], 0.5);
        } else {
            chi[1] = complex<double>(nh * p[1], -p[2]) / sqp0p3;
        }
        if (nh == 1) {
            fo[2] = chi[0];
            fo[3] = chi[1];
            fo[4] = complex<double>(0.00, 0.00);
            fo[5] = complex<double>(0.00, 0.00);
        } else {
            fo[2] = complex<double>(0.00, 0.00);
            fo[3] = complex<double>(0.00, 0.00);
            fo[4] = chi[1];
            fo[5] = chi[0];
        }
    }
    return;
}

void ixxxxx(double p[4], double fmass, int nhel, int nsf, complex<double> fi[6])
{
    complex<double> chi[2];
    double sf[2], sfomega[2], omega[2], pp, pp3, sqp0p3, sqm[2];
    int ip, im, nh;
    fi[0] = complex<double>(-p[0] * nsf, -p[3] * nsf);
    fi[1] = complex<double>(-p[1] * nsf, -p[2] * nsf);
    nh = nhel * nsf;
    if (fmass != 0.0) {
        pp = min(p[0], pow((pow(p[1], 2) + pow(p[2], 2) + pow(p[3], 2)), 0.5));
        if (pp == 0.0) {
            sqm[0] = pow(abs(fmass), 0.5);
            sqm[1] = Sgn(sqm[0], fmass);
            ip = (1 + nh) / 2;
            im = (1 - nh) / 2;
            fi[2] = ip * sqm[ip];
            fi[3] = im * nsf * sqm[ip];
            fi[4] = ip * nsf * sqm[im];
            fi[5] = im * sqm[im];
        } else {
            sf[0] = (1 + nsf + (1 - nsf) * nh) * 0.5;
            sf[1] = (1 + nsf - (1 - nsf) * nh) * 0.5;
            omega[0] = pow(p[0] + pp, 0.5);
            omega[1] = fmass / omega[0];
            ip = (1 + nh) / 2;
            im = (1 - nh) / 2;
            sfomega[0] = sf[0] * omega[ip];
            sfomega[1] = sf[1] * omega[im];
            pp3 = max(pp + p[3], 0.0);
            chi[0] = complex<double>(pow(pp3 * 0.5 / pp, 0.5), 0);
            if (pp3 == 0.0) {
                chi[1] = complex<double>(-nh, 0);
            } else {
                chi[1] =
                    complex<double>(nh * p[1], p[2]) / pow(2.0 * pp * pp3, 0.5);
            }
            fi[2] = sfomega[0] * chi[im];
            fi[3] = sfomega[0] * chi[ip];
            fi[4] = sfomega[1] * chi[im];
            fi[5] = sfomega[1] * chi[ip];
        }
    } else {
        if (p[1] == 0.0 and p[2] == 0.0 and p[3] < 0.0) {
            sqp0p3 = 0.0;
        } else {
            sqp0p3 = pow(max(p[0] + p[3], 0.0), 0.5) * nsf;
        }
        chi[0] = complex<double>(sqp0p3, 0.0);
        if (sqp0p3 == 0.0) {
            chi[1] = complex<double>(-nhel * pow(2.0 * p[0], 0.5), 0.0);
        } else {
            chi[1] = complex<double>(nh * p[1], p[2]) / sqp0p3;
        }
        if (nh == 1) {
            fi[2] = complex<double>(0.0, 0.0);
            fi[3] = complex<double>(0.0, 0.0);
            fi[4] = chi[0];
            fi[5] = chi[1];
        } else {
            fi[2] = chi[1];
            fi[3] = chi[0];
            fi[4] = complex<double>(0.0, 0.0);
            fi[5] = complex<double>(0.0, 0.0);
        }
    }
    return;
}

void sxxxxx(double p[4], int nss, complex<double> sc[3])
{
    sc[2] = complex<double>(1.00, 0.00);
    sc[0] = complex<double>(p[0] * nss, p[3] * nss);
    sc[1] = complex<double>(p[1] * nss, p[2] * nss);
    return;
}

void vxxxxx(double p[4], double vmass, int nhel, int nsv, complex<double> vc[6])
{
    double hel, hel0, pt, pt2, pp, pzpt, emp, sqh;
    int nsvahl;
    sqh = pow(0.5, 0.5);
    hel = double(nhel);
    nsvahl = nsv * abs(hel);
    pt2 = pow(p[1], 2) + pow(p[2], 2);
    pp = min(p[0], pow(pt2 + pow(p[3], 2), 0.5));
    pt = min(pp, pow(pt2, 0.5));
    vc[0] = complex<double>(p[0] * nsv, p[3] * nsv);
    vc[1] = complex<double>(p[1] * nsv, p[2] * nsv);
    if (vmass != 0.0) {
        hel0 = 1.0 - abs(hel);
        if (pp == 0.0) {
            vc[2] = complex<double>(0.0, 0.0);
            vc[3] = complex<double>(-hel * sqh, 0.0);
            vc[4] = complex<double>(0.0, nsvahl * sqh);
            vc[5] = complex<double>(hel0, 0.0);
        } else {
            emp = p[0] / (vmass * pp);
            vc[2] = complex<double>(hel0 * pp / vmass, 0.0);
            vc[5] =
                complex<double>(hel0 * p[3] * emp + hel * pt / pp * sqh, 0.0);
            if (pt != 0.0) {
                pzpt = p[3] / (pp * pt) * sqh * hel;
                vc[3] = complex<double>(hel0 * p[1] * emp - p[1] * pzpt,
                                        -nsvahl * p[2] / pt * sqh);
                vc[4] = complex<double>(hel0 * p[2] * emp - p[2] * pzpt,
                                        nsvahl * p[1] / pt * sqh);
            } else {
                vc[3] = complex<double>(-hel * sqh, 0.0);
                vc[4] = complex<double>(0.0, nsvahl * Sgn(sqh, p[3]));
            }
        }
    } else {
        pp = p[0];
        pt = pow(pow(p[1], 2) + pow(p[2], 2), 0.5);
        vc[2] = complex<double>(0.0, 0.0);
        vc[5] = complex<double>(hel * pt / pp * sqh, 0.0);
        if (pt != 0.0) {
            pzpt = p[3] / (pp * pt) * sqh * hel;
            vc[3] = complex<double>(-p[1] * pzpt, -nsv * p[2] / pt * sqh);
            vc[4] = complex<double>(-p[2] * pzpt, nsv * p[1] / pt * sqh);
        } else {
            vc[3] = complex<double>(-hel * sqh, 0.0);
            vc[4] = complex<double>(0.0, nsv * Sgn(sqh, p[3]));
        }
    }
    return;
}

void txxxxx(double p[4], double tmass, int nhel, int nst,
            complex<double> tc[18])
{
    complex<double> ft[6][4], ep[4], em[4], e0[4];
    double pt, pt2, pp, pzpt, emp, sqh, sqs;
    int i, j;

    sqh = pow(0.5, 0.5);
    sqs = pow(0.5 / 3, 0.5);

    pt2 = p[1] * p[1] + p[2] * p[2];
    pp = min(p[0], pow(pt2 + p[3] * p[3], 0.5));
    pt = min(pp, pow(pt2, 0.5));

    ft[4][0] = complex<double>(p[0] * nst, p[3] * nst);
    ft[5][0] = complex<double>(p[1] * nst, p[2] * nst);

    // construct eps+
    if (nhel >= 0) {
        if (pp == 0) {
            ep[0] = complex<double>(0, 0);
            ep[1] = complex<double>(-sqh, 0);
            ep[2] = complex<double>(0, nst * sqh);
            ep[3] = complex<double>(0, 0);
        } else {
            ep[0] = complex<double>(0, 0);
            ep[3] = complex<double>(pt / pp * sqh, 0);

            if (pt != 0) {
                pzpt = p[3] / (pp * pt) * sqh;
                ep[1] = complex<double>(-p[1] * pzpt, -nst * p[2] / pt * sqh);
                ep[2] = complex<double>(-p[2] * pzpt, nst * p[1] / pt * sqh);
            } else {
                ep[1] = complex<double>(-sqh, 0);
                ep[2] = complex<double>(0, nst * Sgn(sqh, p[3]));
            }
        }
    }

    // construct eps-
    if (nhel <= 0) {
        if (pp == 0) {
            em[0] = complex<double>(0, 0);
            em[1] = complex<double>(sqh, 0);
            em[2] = complex<double>(0, nst * sqh);
            em[3] = complex<double>(0, 0);
        } else {
            em[0] = complex<double>(0, 0);
            em[3] = complex<double>(-pt / pp * sqh, 0);

            if (pt != 0) {
                pzpt = -p[3] / (pp * pt) * sqh;
                em[1] = complex<double>(-p[1] * pzpt, -nst * p[2] / pt * sqh);
                em[2] = complex<double>(-p[2] * pzpt, nst * p[1] / pt * sqh);
            } else {
                em[1] = complex<double>(sqh, 0);
                em[2] = complex<double>(0, nst * Sgn(sqh, p[3]));
            }
        }
    }

    // construct eps0
    if (fabs(nhel) <= 1) {
        if (pp == 0) {
            e0[0] = complex<double>(0, 0);
            e0[1] = complex<double>(0, 0);
            e0[2] = complex<double>(0, 0);
            e0[3] = complex<double>(1, 0);
        } else {
            emp = p[0] / (tmass * pp);
            e0[0] = complex<double>(pp / tmass, 0);
            e0[3] = complex<double>(p[3] * emp, 0);

            if (pt != 0) {
                e0[1] = complex<double>(p[1] * emp, 0);
                e0[2] = complex<double>(p[2] * emp, 0);
            } else {
                e0[1] = complex<double>(0, 0);
                e0[2] = complex<double>(0, 0);
            }
        }
    }

    if (nhel == 2) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++)
                ft[i][j] = ep[i] * ep[j];
        }
    } else if (nhel == -2) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++)
                ft[i][j] = em[i] * em[j];
        }
    } else if (tmass == 0) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++)
                ft[i][j] = 0;
        }
    } else if (tmass != 0) {
        if (nhel == 1) {
            for (j = 0; j < 4; j++) {
                for (i = 0; i < 4; i++)
                    ft[i][j] = sqh * (ep[i] * e0[j] + e0[i] * ep[j]);
            }
        } else if (nhel == 0) {
            for (j = 0; j < 4; j++) {
                for (i = 0; i < 4; i++)
                    ft[i][j] = sqs * (ep[i] * em[j] + em[i] * ep[j] +
                                      2.0 * e0[i] * e0[j]);
            }
        } else if (nhel == -1) {
            for (j = 0; j < 4; j++) {
                for (i = 0; i < 4; i++)
                    ft[i][j] = sqh * (em[i] * e0[j] + e0[i] * em[j]);
            }
        } else {
            std::cerr << "Invalid helicity in txxxxx.\n";
            std::exit(1);
        }
    }

    tc[0] = ft[4][0];
    tc[1] = ft[5][0];

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++)
            tc[j * 4 + i + 2] = ft[j][i];
    }
}

void VVS2_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> TMP4;
    complex<double> TMP3;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP4 = -1. * (P1[0] * (P2[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                           (P2[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                            P2[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                  (P1[1] * (P2[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                            (P2[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                             P2[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                   (P1[2] * (P2[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                             (P2[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                              P2[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                    P1[3] * (P2[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                             (P2[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                              P2[2] * (V2[2] * V1[3] - V2[3] * V1[2]))))));
    TMP3 = -1. * (P1[0] * (P2[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                           (P2[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                            P2[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                  (P1[1] * (P2[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                            (P2[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                             P2[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                   (P1[2] * (P2[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                             (P2[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                              P2[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                    P1[3] * (P2[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                             (P2[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                              P2[2] * (V2[3] * V1[2] - V2[2] * V1[3]))))));
    vertex = COUP * S3[2] * (-cI * (TMP4) + cI * (TMP3));
}

void FFV7_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP1;
    double P3[4];
    double OM3;
    complex<double> denom;
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP1 = (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
            F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])));
    TMP2 =
        (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
         F1[5] * (F2[2] * (+cI * (P3[2]) - P3[1]) + F2[3] * (P3[0] + P3[3])));
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * -2. * cI *
            (OM3 * -0.500000000 * P3[0] * (TMP1 + 2. * (TMP2)) +
             (+0.500000000 * (F2[4] * F1[2] + F2[5] * F1[3]) + F2[2] * F1[4] +
              F2[3] * F1[5]));
    V3[3] = denom * -2. * cI *
            (OM3 * -0.500000000 * P3[1] * (TMP1 + 2. * (TMP2)) +
             (-0.500000000 * (F2[5] * F1[2] + F2[4] * F1[3]) + F2[3] * F1[4] +
              F2[2] * F1[5]));
    V3[4] = denom * 2. * cI *
            (OM3 * 0.500000000 * P3[2] * (TMP1 + 2. * (TMP2)) +
             (+0.500000000 * cI * (F2[5] * F1[2]) -
              0.500000000 * cI * (F2[4] * F1[3]) - cI * (F2[3] * F1[4]) +
              cI * (F2[2] * F1[5])));
    V3[5] = denom * 2. * cI *
            (OM3 * 0.500000000 * P3[3] * (TMP1 + 2. * (TMP2)) +
             (+0.500000000 * (F2[4] * F1[2]) - 0.500000000 * (F2[5] * F1[3]) -
              F2[2] * F1[4] + F2[3] * F1[5]));
}

void FFV5_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    complex<double> TMP1;
    double P3[4];
    double OM3;
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP1 = (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
            F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])));
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * -cI * (F2[4] * F1[2] + F2[5] * F1[3] - P3[0] * OM3 * TMP1);
    V3[3] = denom * -cI * (-F2[5] * F1[2] - F2[4] * F1[3] - P3[1] * OM3 * TMP1);
    V3[4] = denom * -cI *
            (-cI * (F2[5] * F1[2]) + cI * (F2[4] * F1[3]) - P3[2] * OM3 * TMP1);
    V3[5] = denom * -cI * (F2[5] * F1[3] - F2[4] * F1[2] - P3[3] * OM3 * TMP1);
}

void FFV5_7_3(complex<double> F1[], complex<double> F2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3, complex<double> V3[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> denom;
    //   double P3[4];
    //   double OM3;
    int i;
    complex<double> Vtmp[6];
    FFV5_3(F1, F2, COUP1, M3, W3, V3);
    FFV7_3(F1, F2, COUP2, M3, W3, Vtmp);
    i = 2;
    while (i < 6) {
        V3[i] = V3[i] + Vtmp[i];
        i++;
    }
}

void VVS4_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP11;
    double P1[4];
    double P2[4];
    complex<double> TMP7;
    double P3[4];
    complex<double> TMP6;
    complex<double> denom;
    complex<double> TMP13;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    S3[0] = +V1[0] + V2[0];
    S3[1] = +V1[1] + V2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP11 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * (-cI * (TMP6 * TMP13) + cI * (TMP7 * TMP11));
}

void VVS3_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P3[4];
    complex<double> TMP6;
    complex<double> denom;
    S3[0] = +V1[0] + V2[0];
    S3[1] = +V1[1] + V2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * cI * TMP6;
}

void VVS3_4_5_3(complex<double> V1[], complex<double> V2[],
                complex<double> COUP1, complex<double> COUP2,
                complex<double> COUP3, double M3, double W3,
                complex<double> S3[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> Stmp[3];
    //   double P3[4];
    complex<double> denom;
    int i;
    VVS3_3(V1, V2, COUP1, M3, W3, S3);
    VVS4_3(V1, V2, COUP2, M3, W3, Stmp);
    i = 2;
    while (i < 3) {
        S3[i] = S3[i] + Stmp[i];
        i++;
    }
    VVS5_3(V1, V2, COUP3, M3, W3, Stmp);
    i = 2;
    while (i < 3) {
        S3[i] = S3[i] + Stmp[i];
        i++;
    }
}

void VVS1_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    double P3[4];
    complex<double> denom;
    complex<double> TMP4;
    complex<double> TMP3;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    S3[0] = +V1[0] + V2[0];
    S3[1] = +V1[1] + V2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP4 = -1. * (P1[0] * (P2[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                           (P2[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                            P2[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                  (P1[1] * (P2[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                            (P2[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                             P2[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                   (P1[2] * (P2[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                             (P2[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                              P2[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                    P1[3] * (P2[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                             (P2[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                              P2[2] * (V2[2] * V1[3] - V2[3] * V1[2]))))));
    TMP3 = -1. * (P1[0] * (P2[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                           (P2[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                            P2[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                  (P1[1] * (P2[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                            (P2[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                             P2[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                   (P1[2] * (P2[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                             (P2[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                              P2[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                    P1[3] * (P2[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                             (P2[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                              P2[2] * (V2[3] * V1[2] - V2[2] * V1[3]))))));
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * 4. * (-cI * (TMP3) + cI * (TMP4));
}

void VVS5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    complex<double> TMP11;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP7;
    double P3[4];
    complex<double> TMP6;
    complex<double> denom;
    complex<double> TMP9;
    complex<double> TMP13;
    complex<double> TMP8;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    S3[0] = +V1[0] + V2[0];
    S3[1] = +V1[1] + V2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP9 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    TMP8 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP11 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP10 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    TMP12 = (P3[0] * P1[0] - P3[1] * P1[1] - P3[2] * P1[2] - P3[3] * P1[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * (TMP10 * (-cI * (TMP11 * TMP12) + cI * (TMP8 * TMP13)) +
                     TMP9 * (-cI * (TMP7 * TMP8) + cI * (TMP6 * TMP12)));
}

void FFS2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    complex<double> TMP0;
    double P3[4];
    S3[0] = +F1[0] + F2[0];
    S3[1] = +F1[1] + F2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP0 = (F2[2] * F1[2] + F2[3] * F1[3] + F2[4] * F1[4] + F2[5] * F1[5]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * cI * TMP0;
}

void FFS1_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> S3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP5;
    double P3[4];
    complex<double> denom;
    S3[0] = +F1[0] + F2[0];
    S3[1] = +F1[1] + F2[1];
    P3[0] = -S3[0].real();
    P3[1] = -S3[1].real();
    P3[2] = -S3[1].imag();
    P3[3] = -S3[0].imag();
    TMP5 = (F2[4] * F1[4] + F2[5] * F1[5] - F2[2] * F1[2] - F2[3] * F1[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    S3[2] = denom * cI * TMP5;
}

void FFS1_2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP1,
              complex<double> COUP2, double M3, double W3, complex<double> S3[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> Stmp[3];
    //   double P3[4];
    int i;
    complex<double> denom;
    FFS1_3(F1, F2, COUP1, M3, W3, S3);
    FFS2_3(F1, F2, COUP2, M3, W3, Stmp);
    i = 2;
    while (i < 3) {
        S3[i] = S3[i] + Stmp[i];
        i++;
    }
}

void VVS4_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP11;
    double P1[4];
    double P2[4];
    complex<double> TMP7;
    complex<double> TMP6;
    complex<double> TMP13;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP11 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    vertex = COUP * S3[2] * (-cI * (TMP7 * TMP11) + cI * (TMP6 * TMP13));
}

void VVS5_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    complex<double> TMP11;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP7;
    double P3[4];
    complex<double> TMP6;
    complex<double> TMP9;
    complex<double> TMP13;
    complex<double> TMP8;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    P3[0] = S3[0].real();
    P3[1] = S3[1].real();
    P3[2] = S3[1].imag();
    P3[3] = S3[0].imag();
    TMP9 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    TMP8 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP11 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP10 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    TMP12 = (P3[0] * P1[0] - P3[1] * P1[1] - P3[2] * P1[2] - P3[3] * P1[3]);
    vertex = COUP * S3[2] *
             (TMP10 * (-cI * (TMP8 * TMP13) + cI * (TMP11 * TMP12)) +
              TMP9 * (-cI * (TMP6 * TMP12) + cI * (TMP7 * TMP8)));
}

void VVS3_0(complex<double> V1[], complex<double> V2[], complex<double> S3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP6;
    TMP6 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    vertex = COUP * -cI * TMP6 * S3[2];
}

void VVS3_4_5_0(complex<double> V1[], complex<double> V2[],
                complex<double> S3[], complex<double> COUP1,
                complex<double> COUP2, complex<double> COUP3,
                complex<double> &vertex)
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> tmp;
    VVS3_0(V1, V2, S3, COUP1, vertex);
    VVS4_0(V1, V2, S3, COUP2, tmp);
    vertex = vertex + tmp;
    VVS5_0(V1, V2, S3, COUP3, tmp);
    vertex = vertex + tmp;
}

void FFV2_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P2[4];
    complex<double> denom;
    F2[0] = +F1[0] + V3[0];
    F2[1] = +F1[1] + V3[1];
    P2[0] = -F2[0].real();
    P2[1] = -F2[1].real();
    P2[2] = -F2[1].imag();
    P2[3] = -F2[0].imag();
    denom = COUP / (pow(P2[0], 2) - pow(P2[1], 2) - pow(P2[2], 2) -
                    pow(P2[3], 2) - M2 * (M2 - cI * W2));
    F2[2] =
        denom * cI *
        (F1[2] *
             (P2[0] * (V3[2] + V3[5]) +
              (P2[1] * -1. * (V3[3] + cI * (V3[4])) +
               (P2[2] * (+cI * (V3[3]) - V3[4]) - P2[3] * (V3[2] + V3[5])))) +
         (F1[3] * (P2[0] * (V3[3] - cI * (V3[4])) +
                   (P2[1] * (V3[5] - V3[2]) +
                    (P2[2] * (-cI * (V3[5]) + cI * (V3[2])) +
                     P2[3] * (+cI * (V3[4]) - V3[3])))) +
          M2 * (F1[4] * (V3[2] - V3[5]) + F1[5] * (+cI * (V3[4]) - V3[3]))));
    F2[3] =
        denom * -cI *
        (F1[2] *
             (P2[0] * -1. * (V3[3] + cI * (V3[4])) +
              (P2[1] * (V3[2] + V3[5]) + (P2[2] * (+cI * (V3[2] + V3[5])) -
                                          P2[3] * (V3[3] + cI * (V3[4]))))) +
         (F1[3] * (P2[0] * (V3[5] - V3[2]) + (P2[1] * (V3[3] - cI * (V3[4])) +
                                              (P2[2] * (V3[4] + cI * (V3[3])) +
                                               P2[3] * (V3[5] - V3[2])))) +
          M2 * (F1[4] * (V3[3] + cI * (V3[4])) - F1[5] * (V3[2] + V3[5]))));
    F2[4] =
        denom * -cI *
        (F1[4] * (P2[0] * (V3[5] - V3[2]) + (P2[1] * (V3[3] + cI * (V3[4])) +
                                             (P2[2] * (V3[4] - cI * (V3[3])) +
                                              P2[3] * (V3[5] - V3[2])))) +
         (F1[5] * (P2[0] * (V3[3] - cI * (V3[4])) +
                   (P2[1] * -1. * (V3[2] + V3[5]) +
                    (P2[2] * (+cI * (V3[2] + V3[5])) +
                     P2[3] * (V3[3] - cI * (V3[4]))))) +
          M2 * (F1[2] * -1. * (V3[2] + V3[5]) +
                F1[3] * (+cI * (V3[4]) - V3[3]))));
    F2[5] = denom * cI *
            (F1[4] * (P2[0] * -1. * (V3[3] + cI * (V3[4])) +
                      (P2[1] * (V3[2] - V3[5]) +
                       (P2[2] * (-cI * (V3[5]) + cI * (V3[2])) +
                        P2[3] * (V3[3] + cI * (V3[4]))))) +
             (F1[5] * (P2[0] * (V3[2] + V3[5]) +
                       (P2[1] * (+cI * (V3[4]) - V3[3]) +
                        (P2[2] * -1. * (V3[4] + cI * (V3[3])) -
                         P2[3] * (V3[2] + V3[5])))) +
              M2 * (F1[2] * (V3[3] + cI * (V3[4])) + F1[3] * (V3[2] - V3[5]))));
}

void VVS3_1(complex<double> V2[], complex<double> S3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> TMP7;
    complex<double> denom;
    double OM1;
    OM1 = 0.;
    if (M1 != 0.)
        OM1 = 1. / pow(M1, 2);
    V1[0] = +V2[0] + S3[0];
    V1[1] = +V2[1] + S3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * S3[2] * (-cI * (V2[2]) + cI * (P1[0] * TMP7 * OM1));
    V1[3] = denom * S3[2] * (-cI * (V2[3]) + cI * (P1[1] * TMP7 * OM1));
    V1[4] = denom * S3[2] * (-cI * (V2[4]) + cI * (P1[2] * TMP7 * OM1));
    V1[5] = denom * S3[2] * (-cI * (V2[5]) + cI * (P1[3] * TMP7 * OM1));
}

void VVS3_4_5_1(complex<double> V2[], complex<double> S3[],
                complex<double> COUP1, complex<double> COUP2,
                complex<double> COUP3, double M1, double W1,
                complex<double> V1[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    //   double P1[4];
    complex<double> denom;
    complex<double> Vtmp[6];
    //   double OM1;
    int i;
    VVS3_1(V2, S3, COUP1, M1, W1, V1);
    VVS4_1(V2, S3, COUP2, M1, W1, Vtmp);
    i = 2;
    while (i < 6) {
        V1[i] = V1[i] + Vtmp[i];
        i++;
    }
    VVS5_1(V2, S3, COUP3, M1, W1, Vtmp);
    i = 2;
    while (i < 6) {
        V1[i] = V1[i] + Vtmp[i];
        i++;
    }
}

void VVS4_1(complex<double> V2[], complex<double> S3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> TMP7;
    complex<double> denom;
    complex<double> TMP13;
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    V1[0] = +V2[0] + S3[0];
    V1[1] = +V2[1] + S3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * S3[2] * (-cI * (P2[0] * TMP7) + cI * (V2[2] * TMP13));
    V1[3] = denom * S3[2] * (-cI * (P2[1] * TMP7) + cI * (V2[3] * TMP13));
    V1[4] = denom * S3[2] * (-cI * (P2[2] * TMP7) + cI * (V2[4] * TMP13));
    V1[5] = denom * S3[2] * (-cI * (P2[3] * TMP7) + cI * (V2[5] * TMP13));
}

void VVS2_1(complex<double> V2[], complex<double> S3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> denom;
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    V1[0] = +V2[0] + S3[0];
    V1[1] = +V2[1] + S3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * -2. * cI * S3[2] *
            (P1[1] * (V2[4] * P2[3] - V2[5] * P2[2]) +
             (P1[2] * (V2[5] * P2[1] - V2[3] * P2[3]) +
              P1[3] * (V2[3] * P2[2] - V2[4] * P2[1])));
    V1[3] = denom * 2. * cI * S3[2] *
            (P1[0] * (V2[5] * P2[2] - V2[4] * P2[3]) +
             (P1[2] * (V2[2] * P2[3] - V2[5] * P2[0]) +
              P1[3] * (V2[4] * P2[0] - V2[2] * P2[2])));
    V1[4] = denom * 2. * cI * S3[2] *
            (P1[0] * (V2[3] * P2[3] - V2[5] * P2[1]) +
             (P1[1] * (V2[5] * P2[0] - V2[2] * P2[3]) +
              P1[3] * (V2[2] * P2[1] - V2[3] * P2[0])));
    V1[5] = denom * 2. * cI * S3[2] *
            (P1[0] * (V2[4] * P2[1] - V2[3] * P2[2]) +
             (P1[1] * (V2[2] * P2[2] - V2[4] * P2[0]) +
              P1[2] * (V2[3] * P2[0] - V2[2] * P2[1])));
}

void FFV2_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> denom;
    F1[0] = +F2[0] + V3[0];
    F1[1] = +F2[1] + V3[1];
    P1[0] = -F1[0].real();
    P1[1] = -F1[1].real();
    P1[2] = -F1[1].imag();
    P1[3] = -F1[0].imag();
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    F1[2] =
        denom * cI *
        (F2[2] * (P1[0] * (V3[5] - V3[2]) + (P1[1] * (V3[3] - cI * (V3[4])) +
                                             (P1[2] * (V3[4] + cI * (V3[3])) +
                                              P1[3] * (V3[5] - V3[2])))) +
         (F2[3] * (P1[0] * (V3[3] + cI * (V3[4])) +
                   (P1[1] * -1. * (V3[2] + V3[5]) +
                    (P1[2] * -1. * (+cI * (V3[2] + V3[5])) +
                     P1[3] * (V3[3] + cI * (V3[4]))))) +
          M1 * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4])))));
    F1[3] =
        denom * -cI *
        (F2[2] * (P1[0] * (+cI * (V3[4]) - V3[3]) +
                  (P1[1] * (V3[2] - V3[5]) +
                   (P1[2] * (-cI * (V3[2]) + cI * (V3[5])) +
                    P1[3] * (V3[3] - cI * (V3[4]))))) +
         (F2[3] *
              (P1[0] * (V3[2] + V3[5]) +
               (P1[1] * -1. * (V3[3] + cI * (V3[4])) +
                (P1[2] * (+cI * (V3[3]) - V3[4]) - P1[3] * (V3[2] + V3[5])))) +
          M1 * (F2[4] * (+cI * (V3[4]) - V3[3]) + F2[5] * (V3[5] - V3[2]))));
    F1[4] = denom * -cI *
            (F2[4] * (P1[0] * (V3[2] + V3[5]) +
                      (P1[1] * (+cI * (V3[4]) - V3[3]) +
                       (P1[2] * -1. * (V3[4] + cI * (V3[3])) -
                        P1[3] * (V3[2] + V3[5])))) +
             (F2[5] * (P1[0] * (V3[3] + cI * (V3[4])) +
                       (P1[1] * (V3[5] - V3[2]) +
                        (P1[2] * (-cI * (V3[2]) + cI * (V3[5])) -
                         P1[3] * (V3[3] + cI * (V3[4]))))) +
              M1 * (F2[2] * (V3[5] - V3[2]) + F2[3] * (V3[3] + cI * (V3[4])))));
    F1[5] =
        denom * cI *
        (F2[4] * (P1[0] * (+cI * (V3[4]) - V3[3]) +
                  (P1[1] * (V3[2] + V3[5]) +
                   (P1[2] * -1. * (+cI * (V3[2] + V3[5])) +
                    P1[3] * (+cI * (V3[4]) - V3[3])))) +
         (F2[5] * (P1[0] * (V3[5] - V3[2]) + (P1[1] * (V3[3] + cI * (V3[4])) +
                                              (P1[2] * (V3[4] - cI * (V3[3])) +
                                               P1[3] * (V3[5] - V3[2])))) +
          M1 * (F2[2] * (+cI * (V3[4]) - V3[3]) + F2[3] * (V3[2] + V3[5]))));
}

void FFV5_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP14;
    TMP14 =
        (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
         F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    vertex = COUP * -cI * TMP14;
}

void FFV5_7_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex)
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> tmp;
    FFV5_0(F1, F2, V3, COUP1, vertex);
    FFV7_0(F1, F2, V3, COUP2, tmp);
    vertex = vertex + tmp;
}

void VVS5_1(complex<double> V2[], complex<double> S3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP7;
    double P3[4];
    complex<double> denom;
    complex<double> TMP9;
    complex<double> TMP13;
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    P3[0] = S3[0].real();
    P3[1] = S3[1].real();
    P3[2] = S3[1].imag();
    P3[3] = S3[0].imag();
    V1[0] = +V2[0] + S3[0];
    V1[1] = +V2[1] + S3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP7 = (V2[2] * P1[0] - V2[3] * P1[1] - V2[4] * P1[2] - V2[5] * P1[3]);
    TMP9 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    TMP10 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP13 = (P2[0] * P1[0] - P2[1] * P1[1] - P2[2] * P1[2] - P2[3] * P1[3]);
    TMP12 = (P3[0] * P1[0] - P3[1] * P1[1] - P3[2] * P1[2] - P3[3] * P1[3]);
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * S3[2] *
            (P3[0] * (-cI * (TMP10 * TMP13) + cI * (TMP7 * TMP9)) +
             TMP12 * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP10)));
    V1[3] = denom * S3[2] *
            (P3[1] * (-cI * (TMP10 * TMP13) + cI * (TMP7 * TMP9)) +
             TMP12 * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP10)));
    V1[4] = denom * S3[2] *
            (P3[2] * (-cI * (TMP10 * TMP13) + cI * (TMP7 * TMP9)) +
             TMP12 * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP10)));
    V1[5] = denom * S3[2] *
            (P3[3] * (-cI * (TMP10 * TMP13) + cI * (TMP7 * TMP9)) +
             TMP12 * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP10)));
}

void FFV7_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP15;
    complex<double> TMP14;
    TMP15 =
        (F1[4] * (F2[2] * (V3[2] - V3[5]) - F2[3] * (V3[3] + cI * (V3[4]))) +
         F1[5] * (F2[2] * (+cI * (V3[4]) - V3[3]) + F2[3] * (V3[2] + V3[5])));
    TMP14 =
        (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
         F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    vertex = COUP * -1. * (+cI * (TMP14) + 2. * cI * (TMP15));
}

void FFV2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    double P3[4];
    complex<double> TMP16;
    double OM3;
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP16 =
        (F1[2] * (F2[4] * (P3[0] + P3[3]) + F2[5] * (P3[1] + cI * (P3[2]))) +
         (F1[3] * (F2[4] * (P3[1] - cI * (P3[2])) + F2[5] * (P3[0] - P3[3])) +
          (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
           F1[5] *
               (F2[2] * (+cI * (P3[2]) - P3[1]) + F2[3] * (P3[0] + P3[3])))));
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * -cI *
            (F2[4] * F1[2] + F2[5] * F1[3] + F2[2] * F1[4] + F2[3] * F1[5] -
             P3[0] * OM3 * TMP16);
    V3[3] = denom * -cI *
            (F2[3] * F1[4] + F2[2] * F1[5] - F2[5] * F1[2] - F2[4] * F1[3] -
             P3[1] * OM3 * TMP16);
    V3[4] = denom * -cI *
            (-cI * (F2[5] * F1[2] + F2[2] * F1[5]) +
             cI * (F2[4] * F1[3] + F2[3] * F1[4]) - P3[2] * OM3 * TMP16);
    V3[5] = denom * -cI *
            (F2[5] * F1[3] + F2[2] * F1[4] - F2[4] * F1[2] - F2[3] * F1[5] -
             P3[3] * OM3 * TMP16);
}

void VVV2_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> TMP7;
    complex<double> TMP6;
    complex<double> TMP5;
    complex<double> TMP4;
    complex<double> TMP9;
    complex<double> TMP3;
    complex<double> TMP8;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP9 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP8 = (V3[2] * V2[2] - V3[3] * V2[3] - V3[4] * V2[4] - V3[5] * V2[5]);
    TMP5 = (P2[0] * V3[2] - P2[1] * V3[3] - P2[2] * V3[4] - P2[3] * V3[5]);
    TMP4 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP7 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP6 = (V3[2] * V1[2] - V3[3] * V1[3] - V3[4] * V1[4] - V3[5] * V1[5]);
    TMP3 = (P1[0] * V3[2] - P1[1] * V3[3] - P1[2] * V3[4] - P1[3] * V3[5]);
    vertex = COUP * (TMP4 * -1. * (+cI * (TMP3 + TMP5)) +
                     (+cI * (TMP6 * TMP7 + TMP8 * TMP9)));
}

void FFV3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    complex<double> TMP10;
    double P3[4];
    double OM3;
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP10 =
        (F1[2] *
             (F2[4] * -1. * (P3[0] + P3[3]) - F2[5] * (P3[1] + cI * (P3[2]))) +
         (F1[3] * (F2[4] * (+cI * (P3[2]) - P3[1]) + F2[5] * (P3[3] - P3[0])) +
          (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
           F1[5] *
               (F2[2] * (+cI * (P3[2]) - P3[1]) + F2[3] * (P3[0] + P3[3])))));
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * -cI *
            (F2[2] * F1[4] + F2[3] * F1[5] - F2[4] * F1[2] - F2[5] * F1[3] -
             P3[0] * OM3 * TMP10);
    V3[3] = denom * -cI *
            (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] + F2[2] * F1[5] -
             P3[1] * OM3 * TMP10);
    V3[4] = denom * -cI *
            (-cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
             cI * (F2[5] * F1[2] + F2[3] * F1[4]) - P3[2] * OM3 * TMP10);
    V3[5] = denom * -cI *
            (F2[4] * F1[2] + F2[2] * F1[4] - F2[5] * F1[3] - F2[3] * F1[5] -
             P3[3] * OM3 * TMP10);
}

void FFV1_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP1;
    double P1[4];
    complex<double> TMP0;
    double P2[4];
    double P3[4];
    double OM3;
    complex<double> denom;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    P2[0] = F2[0].real();
    P2[1] = F2[1].real();
    P2[2] = F2[1].imag();
    P2[3] = F2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP0 = (F2[4] * F1[4] + F2[5] * F1[5] - F2[2] * F1[2] - F2[3] * F1[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * TMP0 *
            (OM3 * P3[0] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[0]) + cI * (P2[0])));
    V3[3] = denom * TMP0 *
            (OM3 * P3[1] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[1]) + cI * (P2[1])));
    V3[4] = denom * TMP0 *
            (OM3 * P3[2] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[2]) + cI * (P2[2])));
    V3[5] = denom * TMP0 *
            (OM3 * P3[3] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[3]) + cI * (P2[3])));
}

void FFV1_2_3_4_3(complex<double> F1[], complex<double> F2[],
                  complex<double> COUP1, complex<double> COUP2,
                  complex<double> COUP3, complex<double> COUP4, double M3,
                  double W3, complex<double> V3[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    //   double P1[4];
    //   double P2[4];
    //   double P3[4];
    //   double OM3;
    complex<double> denom;
    complex<double> Vtmp[6];
    int i;
    FFV1_3(F1, F2, COUP1, M3, W3, V3);
    FFV2_3(F1, F2, COUP2, M3, W3, Vtmp);
    i = 2;
    while (i < 6) {
        V3[i] = V3[i] + Vtmp[i];
        i++;
    }
    FFV3_3(F1, F2, COUP3, M3, W3, Vtmp);
    i = 2;
    while (i < 6) {
        V3[i] = V3[i] + Vtmp[i];
        i++;
    }
    FFV4_3(F1, F2, COUP4, M3, W3, Vtmp);
    i = 2;
    while (i < 6) {
        V3[i] = V3[i] + Vtmp[i];
        i++;
    }
}

void VVV1_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    complex<double> TMP11;
    double P1[4];
    double P2[4];
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP11 = -1. * (P1[0] * (V1[3] * (V3[5] * V2[4] - V3[4] * V2[5]) +
                            (V1[4] * (V3[3] * V2[5] - V3[5] * V2[3]) +
                             V1[5] * (V3[4] * V2[3] - V3[3] * V2[4]))) +
                   (P1[1] * (V1[2] * (V3[4] * V2[5] - V3[5] * V2[4]) +
                             (V1[4] * (V3[5] * V2[2] - V3[2] * V2[5]) +
                              V1[5] * (V3[2] * V2[4] - V3[4] * V2[2]))) +
                    (P1[2] * (V1[2] * (V3[5] * V2[3] - V3[3] * V2[5]) +
                              (V1[3] * (V3[2] * V2[5] - V3[5] * V2[2]) +
                               V1[5] * (V3[3] * V2[2] - V3[2] * V2[3]))) +
                     P1[3] * (V1[2] * (V3[3] * V2[4] - V3[4] * V2[3]) +
                              (V1[3] * (V3[4] * V2[2] - V3[2] * V2[4]) +
                               V1[4] * (V3[2] * V2[3] - V3[3] * V2[2]))))));
    TMP12 = -1. * (P2[0] * (V1[3] * (V3[5] * V2[4] - V3[4] * V2[5]) +
                            (V1[4] * (V3[3] * V2[5] - V3[5] * V2[3]) +
                             V1[5] * (V3[4] * V2[3] - V3[3] * V2[4]))) +
                   (P2[1] * (V1[2] * (V3[4] * V2[5] - V3[5] * V2[4]) +
                             (V1[4] * (V3[5] * V2[2] - V3[2] * V2[5]) +
                              V1[5] * (V3[2] * V2[4] - V3[4] * V2[2]))) +
                    (P2[2] * (V1[2] * (V3[5] * V2[3] - V3[3] * V2[5]) +
                              (V1[3] * (V3[2] * V2[5] - V3[5] * V2[2]) +
                               V1[5] * (V3[3] * V2[2] - V3[2] * V2[3]))) +
                     P2[3] * (V1[2] * (V3[3] * V2[4] - V3[4] * V2[3]) +
                              (V1[3] * (V3[4] * V2[2] - V3[2] * V2[4]) +
                               V1[4] * (V3[2] * V2[3] - V3[3] * V2[2]))))));
    vertex = COUP * (-cI * (TMP11) + cI * (TMP12));
}

void VVV1_2_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex)
{
    //   complex<double> cI = complex<double> (0., 1.);
    //   double P1[4];
    //   double P2[4];
    complex<double> tmp;
    VVV1_0(V1, V2, V3, COUP1, vertex);
    VVV2_0(V1, V2, V3, COUP2, tmp);
    vertex = vertex + tmp;
}

void FFV4_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> V3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP15;
    complex<double> TMP1;
    double P1[4];
    complex<double> TMP2;
    double P2[4];
    double P3[4];
    double OM3;
    complex<double> denom;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    P2[0] = F2[0].real();
    P2[1] = F2[1].real();
    P2[2] = F2[1].imag();
    P2[3] = F2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    V3[0] = +F1[0] + F2[0];
    V3[1] = +F1[1] + F2[1];
    P3[0] = -V3[0].real();
    P3[1] = -V3[1].real();
    P3[2] = -V3[1].imag();
    P3[3] = -V3[0].imag();
    TMP15 = (F2[2] * F1[2] + F2[3] * F1[3] + F2[4] * F1[4] + F2[5] * F1[5]);
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    V3[2] = denom * TMP15 *
            (OM3 * P3[0] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[0]) + cI * (P2[0])));
    V3[3] = denom * TMP15 *
            (OM3 * P3[1] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[1]) + cI * (P2[1])));
    V3[4] = denom * TMP15 *
            (OM3 * P3[2] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[2]) + cI * (P2[2])));
    V3[5] = denom * TMP15 *
            (OM3 * P3[3] * (-cI * (TMP2) + cI * (TMP1)) +
             (-cI * (P1[3]) + cI * (P2[3])));
}

void VVV2_1(complex<double> V2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP7;
    complex<double> TMP5;
    double OM1;
    complex<double> TMP3;
    complex<double> TMP8;
    OM1 = 0.;
    if (M1 != 0.)
        OM1 = 1. / pow(M1, 2);
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    V1[0] = +V2[0] + V3[0];
    V1[1] = +V2[1] + V3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP5 = (P2[0] * V3[2] - P2[1] * V3[3] - P2[2] * V3[4] - P2[3] * V3[5]);
    TMP7 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP10 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP3 = (P1[0] * V3[2] - P1[1] * V3[3] - P1[2] * V3[4] - P1[3] * V3[5]);
    TMP8 = (V3[2] * V2[2] - V3[3] * V2[3] - V3[4] * V2[4] - V3[5] * V2[5]);
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * (OM1 * P1[0] * (-cI * (TMP8 * TMP10) + cI * (TMP5 * TMP7)) +
                     (V2[2] * -1. * (+cI * (TMP3 + TMP5)) +
                      (+cI * (V3[2] * TMP7 + P2[0] * TMP8))));
    V1[3] = denom * (OM1 * P1[1] * (-cI * (TMP8 * TMP10) + cI * (TMP5 * TMP7)) +
                     (V2[3] * -1. * (+cI * (TMP3 + TMP5)) +
                      (+cI * (V3[3] * TMP7 + P2[1] * TMP8))));
    V1[4] = denom * (OM1 * P1[2] * (-cI * (TMP8 * TMP10) + cI * (TMP5 * TMP7)) +
                     (V2[4] * -1. * (+cI * (TMP3 + TMP5)) +
                      (+cI * (V3[4] * TMP7 + P2[2] * TMP8))));
    V1[5] = denom * (OM1 * P1[3] * (-cI * (TMP8 * TMP10) + cI * (TMP5 * TMP7)) +
                     (V2[5] * -1. * (+cI * (TMP3 + TMP5)) +
                      (+cI * (V3[5] * TMP7 + P2[3] * TMP8))));
}

void VVV1_1(complex<double> V2[], complex<double> V3[], complex<double> COUP,
            double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> denom;
    complex<double> TMP14;
    double OM1;
    OM1 = 0.;
    if (M1 != 0.)
        OM1 = 1. / pow(M1, 2);
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    V1[0] = +V2[0] + V3[0];
    V1[1] = +V2[1] + V3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP14 = -1. * (P1[0] * (P2[1] * (V3[4] * V2[5] - V3[5] * V2[4]) +
                            (P2[2] * (V3[5] * V2[3] - V3[3] * V2[5]) +
                             P2[3] * (V3[3] * V2[4] - V3[4] * V2[3]))) +
                   (P1[1] * (P2[0] * (V3[5] * V2[4] - V3[4] * V2[5]) +
                             (P2[2] * (V3[2] * V2[5] - V3[5] * V2[2]) +
                              P2[3] * (V3[4] * V2[2] - V3[2] * V2[4]))) +
                    (P1[2] * (P2[0] * (V3[3] * V2[5] - V3[5] * V2[3]) +
                              (P2[1] * (V3[5] * V2[2] - V3[2] * V2[5]) +
                               P2[3] * (V3[2] * V2[3] - V3[3] * V2[2]))) +
                     P1[3] * (P2[0] * (V3[4] * V2[3] - V3[3] * V2[4]) +
                              (P2[1] * (V3[2] * V2[4] - V3[4] * V2[2]) +
                               P2[2] * (V3[3] * V2[2] - V3[2] * V2[3]))))));
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * cI *
            (V2[3] * (V3[4] * (P2[3] - P1[3]) + V3[5] * (P1[2] - P2[2])) +
             (V2[4] * (V3[3] * (P1[3] - P2[3]) + V3[5] * (P2[1] - P1[1])) +
              (V2[5] * (V3[3] * (P2[2] - P1[2]) + V3[4] * (P1[1] - P2[1])) -
               P1[0] * OM1 * TMP14)));
    V1[3] = denom * -cI *
            (V2[2] * (V3[4] * (P1[3] - P2[3]) + V3[5] * (P2[2] - P1[2])) +
             (V2[4] * (V3[2] * (P2[3] - P1[3]) + V3[5] * (P1[0] - P2[0])) +
              (V2[5] * (V3[2] * (P1[2] - P2[2]) + V3[4] * (P2[0] - P1[0])) +
               P1[1] * OM1 * TMP14)));
    V1[4] = denom * -cI *
            (V2[2] * (V3[3] * (P2[3] - P1[3]) + V3[5] * (P1[1] - P2[1])) +
             (V2[3] * (V3[2] * (P1[3] - P2[3]) + V3[5] * (P2[0] - P1[0])) +
              (V2[5] * (V3[2] * (P2[1] - P1[1]) + V3[3] * (P1[0] - P2[0])) +
               P1[2] * OM1 * TMP14)));
    V1[5] = denom * -cI *
            (V2[2] * (V3[3] * (P1[2] - P2[2]) + V3[4] * (P2[1] - P1[1])) +
             (V2[3] * (V3[2] * (P2[2] - P1[2]) + V3[4] * (P1[0] - P2[0])) +
              (V2[4] * (V3[2] * (P1[1] - P2[1]) + V3[3] * (P2[0] - P1[0])) +
               P1[3] * OM1 * TMP14)));
}

void VVV1_2_1(complex<double> V2[], complex<double> V3[], complex<double> COUP1,
              complex<double> COUP2, double M1, double W1, complex<double> V1[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    //   double P1[4];
    //   double P2[4];
    complex<double> denom;
    complex<double> Vtmp[6];
    //   double OM1;
    int i;
    VVV1_1(V2, V3, COUP1, M1, W1, V1);
    VVV2_1(V2, V3, COUP2, M1, W1, Vtmp);
    i = 2;
    while (i < 6) {
        V1[i] = V1[i] + Vtmp[i];
        i++;
    }
}

void VVT12_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
             double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP1;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP23;
    complex<double> TMP7;
    double P3[4];
    double OM3;
    complex<double> denom;
    complex<double> TMP26;
    complex<double> TMP4;
    complex<double> TMP9;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    T3[0] = +V1[0] + V2[0];
    T3[1] = +V1[1] + V2[1];
    P3[0] = -T3[0].real();
    P3[1] = -T3[1].real();
    P3[2] = -T3[1].imag();
    P3[3] = -T3[0].imag();
    TMP26 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP23 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP9 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP4 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP7 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP10 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. *
        (OM3 *
             (P3[0] *
                  (P3[0] *
                       (OM3 * (TMP1 * 0.666666667 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               0.666666667 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-0.666666667 * cI * (TMP7 * TMP9) +
                         0.666666667 * cI * (TMP4 * TMP10))) +
                   (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[2] * TMP26 + V1[2] * TMP23)) +
                      (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
              (TMP1 * 0.333333333 *
                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
               0.333333333 *
                   (TMP26 * (-cI * (TMP2 * TMP7) + cI * (TMP10 * TMP23))))) +
         (TMP10 * (-0.666666667 * cI * (TMP4) + cI * (V2[2] * V1[2])) +
          (TMP7 * (-cI * (P2[0] * V1[2]) + 0.666666667 * cI * (TMP9)) +
           P1[0] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)))));
    T3[3] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[1] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[3] * TMP23 + V2[3] * TMP26)) +
                      (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
              P3[1] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[2] * TMP26 + V1[2] * TMP23)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
          (P1[1] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[2] * V1[3] + V2[3] * V1[2])) -
            TMP7 * (+cI * (P2[1] * V1[2] + P2[0] * V1[3]))))));
    T3[4] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[2] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[4] * TMP23 + V2[4] * TMP26)) +
                      (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
              P3[2] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[2] * TMP26 + V1[2] * TMP23)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
          (P1[2] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[2] * V1[4] + V2[4] * V1[2])) -
            TMP7 * (+cI * (P2[2] * V1[2] + P2[0] * V1[4]))))));
    T3[5] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[5] * TMP23 + V2[5] * TMP26)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[2] * TMP26 + V1[2] * TMP23)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[2] * V1[5] + V2[5] * V1[2])) -
            TMP7 * (+cI * (P2[3] * V1[2] + P2[0] * V1[5]))))));
    T3[6] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[1] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[3] * TMP26 + V1[3] * TMP23)) +
                      (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
              P3[1] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[2] * TMP23 + V2[2] * TMP26)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
          (P1[1] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[3] * V1[2] + V2[2] * V1[3])) -
            TMP7 * (+cI * (P2[0] * V1[3] + P2[1] * V1[2]))))));
    T3[7] =
        denom * 2. *
        (OM3 *
             (P3[1] *
                  (P3[1] *
                       (OM3 * (TMP1 * 0.666666667 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               0.666666667 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-0.666666667 * cI * (TMP7 * TMP9) +
                         0.666666667 * cI * (TMP4 * TMP10))) +
                   (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[3] * TMP26 + V1[3] * TMP23)) +
                      (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
              (TMP1 * 0.333333333 *
                   (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
               0.333333333 *
                   (TMP26 * (-cI * (TMP10 * TMP23) + cI * (TMP2 * TMP7))))) +
         (TMP10 * (+cI * (V2[3] * V1[3]) + 0.666666667 * cI * (TMP4)) +
          (TMP7 * -1. * (+cI * (P2[1] * V1[3]) + 0.666666667 * cI * (TMP9)) +
           P1[1] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)))));
    T3[8] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[2] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[4] * TMP23 + V2[4] * TMP26)) +
                      (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
              P3[2] *
                  (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[3] * TMP26 + V1[3] * TMP23)) +
                     (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
         (P1[1] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
          (P1[2] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
           (TMP10 * (+cI * (V2[3] * V1[4] + V2[4] * V1[3])) -
            TMP7 * (+cI * (P2[2] * V1[3] + P2[1] * V1[4]))))));
    T3[9] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[5] * TMP23 + V2[5] * TMP26)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[3] * TMP26 + V1[3] * TMP23)) +
                     (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
         (P1[1] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
           (TMP10 * (+cI * (V2[3] * V1[5] + V2[5] * V1[3])) -
            TMP7 * (+cI * (P2[3] * V1[3] + P2[1] * V1[5]))))));
    T3[10] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[2] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[4] * TMP26 + V1[4] * TMP23)) +
                      (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
              P3[2] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[2] * TMP23 + V2[2] * TMP26)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
          (P1[2] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[4] * V1[2] + V2[2] * V1[4])) -
            TMP7 * (+cI * (P2[0] * V1[4] + P2[2] * V1[2]))))));
    T3[11] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[2] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[4] * TMP26 + V1[4] * TMP23)) +
                      (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
              P3[2] *
                  (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[3] * TMP23 + V2[3] * TMP26)) +
                     (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
         (P1[1] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
          (P1[2] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
           (TMP10 * (+cI * (V2[4] * V1[3] + V2[3] * V1[4])) -
            TMP7 * (+cI * (P2[1] * V1[4] + P2[2] * V1[3]))))));
    T3[12] =
        denom * 2. *
        (OM3 *
             (P3[2] *
                  (P3[2] *
                       (OM3 * (TMP1 * 0.666666667 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               0.666666667 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-0.666666667 * cI * (TMP7 * TMP9) +
                         0.666666667 * cI * (TMP4 * TMP10))) +
                   (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[4] * TMP26 + V1[4] * TMP23)) +
                      (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
              (TMP1 * 0.333333333 *
                   (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
               0.333333333 *
                   (TMP26 * (-cI * (TMP10 * TMP23) + cI * (TMP2 * TMP7))))) +
         (TMP10 * (+cI * (V2[4] * V1[4]) + 0.666666667 * cI * (TMP4)) +
          (TMP7 * -1. * (+cI * (P2[2] * V1[4]) + 0.666666667 * cI * (TMP9)) +
           P1[2] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)))));
    T3[13] =
        denom *
        (OM3 *
             (P3[2] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V1[5] * TMP23 + V2[5] * TMP26)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V2[4] * TMP26 + V1[4] * TMP23)) +
                     (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
         (P1[2] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
           (TMP10 * (+cI * (V2[4] * V1[5] + V2[5] * V1[4])) -
            TMP7 * (+cI * (P2[3] * V1[4] + P2[2] * V1[5]))))));
    T3[14] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[5] * TMP26 + V1[5] * TMP23)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[0] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[0] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[2] * TMP23 + V2[2] * TMP26)) +
                     (+cI * (TMP2 * V1[2] * TMP7 + TMP1 * V2[2] * TMP9)))))) +
         (P1[0] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[2] * TMP9) + cI * (P2[0] * TMP4)) +
           (TMP10 * (+cI * (V2[5] * V1[2] + V2[2] * V1[5])) -
            TMP7 * (+cI * (P2[0] * V1[5] + P2[3] * V1[2]))))));
    T3[15] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[5] * TMP26 + V1[5] * TMP23)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[1] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[1] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[3] * TMP23 + V2[3] * TMP26)) +
                     (+cI * (TMP2 * V1[3] * TMP7 + TMP1 * V2[3] * TMP9)))))) +
         (P1[1] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[3] * TMP9) + cI * (P2[1] * TMP4)) +
           (TMP10 * (+cI * (V2[5] * V1[3] + V2[3] * V1[5])) -
            TMP7 * (+cI * (P2[1] * V1[5] + P2[3] * V1[3]))))));
    T3[16] =
        denom *
        (OM3 *
             (P3[2] *
                  (P3[3] *
                       (OM3 * (TMP1 * 1.333333333 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               1.333333333 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-1.333333333 * cI * (TMP7 * TMP9) +
                         1.333333333 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[5] * TMP26 + V1[5] * TMP23)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              P3[3] *
                  (P1[2] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                   (P2[2] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                    (TMP10 * -1. * (+cI * (V1[4] * TMP23 + V2[4] * TMP26)) +
                     (+cI * (TMP2 * V1[4] * TMP7 + TMP1 * V2[4] * TMP9)))))) +
         (P1[2] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)) +
          (P1[3] * (-cI * (V2[4] * TMP9) + cI * (P2[2] * TMP4)) +
           (TMP10 * (+cI * (V2[5] * V1[4] + V2[4] * V1[5])) -
            TMP7 * (+cI * (P2[2] * V1[5] + P2[3] * V1[4]))))));
    T3[17] =
        denom * 2. *
        (OM3 *
             (P3[3] *
                  (P3[3] *
                       (OM3 * (TMP1 * 0.666666667 *
                                   (-cI * (TMP9 * TMP23) + cI * (TMP2 * TMP4)) +
                               0.666666667 * (TMP26 * (-cI * (TMP2 * TMP7) +
                                                       cI * (TMP10 * TMP23)))) +
                        (-0.666666667 * cI * (TMP7 * TMP9) +
                         0.666666667 * cI * (TMP4 * TMP10))) +
                   (P1[3] * (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
                    (P2[3] * (-cI * (TMP1 * TMP4) + cI * (TMP7 * TMP26)) +
                     (TMP10 * -1. * (+cI * (V2[5] * TMP26 + V1[5] * TMP23)) +
                      (+cI * (TMP2 * V1[5] * TMP7 + TMP1 * V2[5] * TMP9)))))) +
              (TMP1 * 0.333333333 *
                   (-cI * (TMP2 * TMP4) + cI * (TMP9 * TMP23)) +
               0.333333333 *
                   (TMP26 * (-cI * (TMP10 * TMP23) + cI * (TMP2 * TMP7))))) +
         (TMP10 * (+cI * (V2[5] * V1[5]) + 0.666666667 * cI * (TMP4)) +
          (TMP7 * -1. * (+cI * (P2[3] * V1[5]) + 0.666666667 * cI * (TMP9)) +
           P1[3] * (-cI * (V2[5] * TMP9) + cI * (P2[3] * TMP4)))));
}

void VVT9_0(complex<double> V1[], complex<double> V2[], complex<double> T3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> TMP23;
    double P3[4];
    complex<double> TMP26;
    complex<double> TMP28;
    complex<double> TMP27;
    complex<double> TMP24;
    complex<double> TMP25;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    P3[0] = T3[0].real();
    P3[1] = T3[1].real();
    P3[2] = T3[1].imag();
    P3[3] = T3[0].imag();
    TMP24 =
        (P2[0] * -1. *
             (V1[3] * T3[6] + V1[4] * T3[10] + V1[5] * T3[14] - V1[2] * T3[2]) +
         (P2[1] * (V1[3] * T3[7] + V1[4] * T3[11] + V1[5] * T3[15] -
                   V1[2] * T3[3]) +
          (P2[2] * (V1[3] * T3[8] + V1[4] * T3[12] + V1[5] * T3[16] -
                    V1[2] * T3[4]) +
           P2[3] * (V1[3] * T3[9] + V1[4] * T3[13] + V1[5] * T3[17] -
                    V1[2] * T3[5]))));
    TMP25 =
        (P2[0] * -1. *
             (V1[3] * T3[3] + V1[4] * T3[4] + V1[5] * T3[5] - V1[2] * T3[2]) +
         (P2[1] *
              (V1[3] * T3[7] + V1[4] * T3[8] + V1[5] * T3[9] - V1[2] * T3[6]) +
          (P2[2] * (V1[3] * T3[11] + V1[4] * T3[12] + V1[5] * T3[13] -
                    V1[2] * T3[10]) +
           P2[3] * (V1[3] * T3[15] + V1[4] * T3[16] + V1[5] * T3[17] -
                    V1[2] * T3[14]))));
    TMP26 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP27 =
        (P1[0] * -1. *
             (V2[3] * T3[6] + V2[4] * T3[10] + V2[5] * T3[14] - V2[2] * T3[2]) +
         (P1[1] * (V2[3] * T3[7] + V2[4] * T3[11] + V2[5] * T3[15] -
                   V2[2] * T3[3]) +
          (P1[2] * (V2[3] * T3[8] + V2[4] * T3[12] + V2[5] * T3[16] -
                    V2[2] * T3[4]) +
           P1[3] * (V2[3] * T3[9] + V2[4] * T3[13] + V2[5] * T3[17] -
                    V2[2] * T3[5]))));
    TMP23 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP28 =
        (P1[0] * -1. *
             (V2[3] * T3[3] + V2[4] * T3[4] + V2[5] * T3[5] - V2[2] * T3[2]) +
         (P1[1] *
              (V2[3] * T3[7] + V2[4] * T3[8] + V2[5] * T3[9] - V2[2] * T3[6]) +
          (P1[2] * (V2[3] * T3[11] + V2[4] * T3[12] + V2[5] * T3[13] -
                    V2[2] * T3[10]) +
           P1[3] * (V2[3] * T3[15] + V2[4] * T3[16] + V2[5] * T3[17] -
                    V2[2] * T3[14]))));
    vertex =
        COUP * -1. *
        (TMP23 * (+cI * (TMP24 + TMP25)) + TMP26 * (+cI * (TMP27 + TMP28)));
}

void VVT12_0(complex<double> V1[], complex<double> V2[], complex<double> T3[],
             complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> TMP22;
    complex<double> TMP10;
    double P2[4];
    complex<double> TMP7;
    complex<double> TMP36;
    complex<double> TMP21;
    complex<double> TMP4;
    complex<double> TMP28;
    complex<double> TMP27;
    complex<double> TMP24;
    complex<double> TMP25;
    complex<double> TMP9;
    complex<double> TMP35;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP24 =
        (P2[0] * -1. *
             (V1[3] * T3[6] + V1[4] * T3[10] + V1[5] * T3[14] - V1[2] * T3[2]) +
         (P2[1] * (V1[3] * T3[7] + V1[4] * T3[11] + V1[5] * T3[15] -
                   V1[2] * T3[3]) +
          (P2[2] * (V1[3] * T3[8] + V1[4] * T3[12] + V1[5] * T3[16] -
                    V1[2] * T3[4]) +
           P2[3] * (V1[3] * T3[9] + V1[4] * T3[13] + V1[5] * T3[17] -
                    V1[2] * T3[5]))));
    TMP25 =
        (P2[0] * -1. *
             (V1[3] * T3[3] + V1[4] * T3[4] + V1[5] * T3[5] - V1[2] * T3[2]) +
         (P2[1] *
              (V1[3] * T3[7] + V1[4] * T3[8] + V1[5] * T3[9] - V1[2] * T3[6]) +
          (P2[2] * (V1[3] * T3[11] + V1[4] * T3[12] + V1[5] * T3[13] -
                    V1[2] * T3[10]) +
           P2[3] * (V1[3] * T3[15] + V1[4] * T3[16] + V1[5] * T3[17] -
                    V1[2] * T3[14]))));
    TMP27 =
        (P1[0] * -1. *
             (V2[3] * T3[6] + V2[4] * T3[10] + V2[5] * T3[14] - V2[2] * T3[2]) +
         (P1[1] * (V2[3] * T3[7] + V2[4] * T3[11] + V2[5] * T3[15] -
                   V2[2] * T3[3]) +
          (P1[2] * (V2[3] * T3[8] + V2[4] * T3[12] + V2[5] * T3[16] -
                    V2[2] * T3[4]) +
           P1[3] * (V2[3] * T3[9] + V2[4] * T3[13] + V2[5] * T3[17] -
                    V2[2] * T3[5]))));
    TMP21 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    TMP22 =
        (P1[0] * -1. *
             (P2[1] * T3[3] + P2[2] * T3[4] + P2[3] * T3[5] - P2[0] * T3[2]) +
         (P1[1] *
              (P2[1] * T3[7] + P2[2] * T3[8] + P2[3] * T3[9] - P2[0] * T3[6]) +
          (P1[2] * (P2[1] * T3[11] + P2[2] * T3[12] + P2[3] * T3[13] -
                    P2[0] * T3[10]) +
           P1[3] * (P2[1] * T3[15] + P2[2] * T3[16] + P2[3] * T3[17] -
                    P2[0] * T3[14]))));
    TMP28 =
        (P1[0] * -1. *
             (V2[3] * T3[3] + V2[4] * T3[4] + V2[5] * T3[5] - V2[2] * T3[2]) +
         (P1[1] *
              (V2[3] * T3[7] + V2[4] * T3[8] + V2[5] * T3[9] - V2[2] * T3[6]) +
          (P1[2] * (V2[3] * T3[11] + V2[4] * T3[12] + V2[5] * T3[13] -
                    V2[2] * T3[10]) +
           P1[3] * (V2[3] * T3[15] + V2[4] * T3[16] + V2[5] * T3[17] -
                    V2[2] * T3[14]))));
    TMP10 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP9 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP4 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP7 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP36 =
        (V1[2] * -1. *
             (V2[3] * T3[3] + V2[4] * T3[4] + V2[5] * T3[5] - V2[2] * T3[2]) +
         (V1[3] *
              (V2[3] * T3[7] + V2[4] * T3[8] + V2[5] * T3[9] - V2[2] * T3[6]) +
          (V1[4] * (V2[3] * T3[11] + V2[4] * T3[12] + V2[5] * T3[13] -
                    V2[2] * T3[10]) +
           V1[5] * (V2[3] * T3[15] + V2[4] * T3[16] + V2[5] * T3[17] -
                    V2[2] * T3[14]))));
    TMP35 =
        (V1[2] * -1. *
             (V2[3] * T3[6] + V2[4] * T3[10] + V2[5] * T3[14] - V2[2] * T3[2]) +
         (V1[3] * (V2[3] * T3[7] + V2[4] * T3[11] + V2[5] * T3[15] -
                   V2[2] * T3[3]) +
          (V1[4] * (V2[3] * T3[8] + V2[4] * T3[12] + V2[5] * T3[16] -
                    V2[2] * T3[4]) +
           V1[5] * (V2[3] * T3[9] + V2[4] * T3[13] + V2[5] * T3[17] -
                    V2[2] * T3[5]))));
    vertex =
        COUP *
        (TMP10 * -1. * (+cI * (TMP35 + TMP36)) +
         (TMP4 * -1. * (+cI * (TMP21 + TMP22)) +
          (TMP7 * (+cI * (TMP24 + TMP25)) + TMP9 * (+cI * (TMP27 + TMP28)))));
}

void VVT3_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP1;
    double P1[4];
    double P2[4];
    complex<double> TMP56;
    double P3[4];
    complex<double> TMP55;
    complex<double> denom;
    double OM3;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    T3[0] = +V1[0] + V2[0];
    T3[1] = +V1[1] + V2[1];
    P3[0] = -T3[0].real();
    P3[1] = -T3[1].real();
    P3[2] = -T3[1].imag();
    P3[3] = -T3[0].imag();
    TMP55 = -1. * (P1[0] * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                            (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                             P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                   (P1[1] * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                             (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                              P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                    (P1[2] * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                              (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                               P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                     P1[3] * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                              (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                               P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))))));
    TMP56 = -1. * (P2[0] * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                            (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                             P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                   (P2[1] * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                             (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                              P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                    (P2[2] * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                              (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                               P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                     P2[3] * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                              (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                               P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))))));
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] = denom * -2. * cI *
            (OM3 * P3[0] *
                 (TMP1 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                          (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                           P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                  (TMP2 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                           (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                            P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                   0.333333333 * (P3[0] * (TMP56 - TMP55)))) +
             (P1[0] * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                       (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                        P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
              (P2[0] * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                        (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                         P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
               (-0.333333333 * (TMP56) + 0.333333333 * (TMP55)))));
    T3[3] =
        denom * cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                  (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                   P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                          0.666666667 * (P3[1] * (TMP55 - TMP56)))) +
                P3[1] * (TMP1 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                         TMP2 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))))) +
         (P3[2] *
              (V1[5] * (V2[2] * (P1[0] - P2[0]) + V2[3] * (P1[1] - P2[1])) +
               V2[5] * (V1[2] * (P2[0] - P1[0]) + V1[3] * (P2[1] - P1[1]))) +
          (P3[3] *
               (V1[4] * (V2[2] * (P2[0] - P1[0]) + V2[3] * (P2[1] - P1[1])) +
                V2[4] * (V1[2] * (P1[0] - P2[0]) + V1[3] * (P1[1] - P2[1]))) +
           (P3[0] * (V1[4] * V2[5] * (P1[0] - P2[0]) +
                     V1[5] * V2[4] * (P2[0] - P1[0])) +
            P3[1] * (V1[4] * V2[5] * (P1[1] - P2[1]) +
                     V1[5] * V2[4] * (P2[1] - P1[1]))))));
    T3[4] =
        denom * cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                 (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         (TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                   P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                          0.666666667 * (P3[2] * (TMP55 - TMP56)))) +
                P3[2] * (TMP1 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                         TMP2 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))))) +
         (P3[1] *
              (V1[5] * (V2[2] * (P2[0] - P1[0]) + V2[4] * (P2[2] - P1[2])) +
               V2[5] * (V1[2] * (P1[0] - P2[0]) + V1[4] * (P1[2] - P2[2]))) +
          (P3[3] *
               (V1[3] * (V2[2] * (P1[0] - P2[0]) + V2[4] * (P1[2] - P2[2])) +
                V2[3] * (V1[2] * (P2[0] - P1[0]) + V1[4] * (P2[2] - P1[2]))) +
           (P3[0] * (V1[3] * V2[5] * (P2[0] - P1[0]) +
                     V1[5] * V2[3] * (P1[0] - P2[0])) +
            P3[2] * (V1[3] * V2[5] * (P2[2] - P1[2]) +
                     V1[5] * V2[3] * (P1[2] - P2[2]))))));
    T3[5] =
        denom * cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                 (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                  P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                  (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                   P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[3] * (TMP55 - TMP56)))) +
                P3[3] * (TMP1 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                         TMP2 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))))) +
         (P3[1] *
              (V1[4] * (V2[2] * (P1[0] - P2[0]) + V2[5] * (P1[3] - P2[3])) +
               V2[4] * (V1[2] * (P2[0] - P1[0]) + V1[5] * (P2[3] - P1[3]))) +
          (P3[2] *
               (V1[3] * (V2[2] * (P2[0] - P1[0]) + V2[5] * (P2[3] - P1[3])) +
                V2[3] * (V1[2] * (P1[0] - P2[0]) + V1[5] * (P1[3] - P2[3]))) +
           (P3[0] * (V1[3] * V2[4] * (P1[0] - P2[0]) +
                     V1[4] * V2[3] * (P2[0] - P1[0])) +
            P3[3] * (V1[3] * V2[4] * (P1[3] - P2[3]) +
                     V1[4] * V2[3] * (P2[3] - P1[3]))))));
    T3[6] =
        denom * -cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                  (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                   P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                          0.666666667 * (P3[1] * (TMP56 - TMP55)))) +
                P3[1] * (TMP1 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                         TMP2 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))))) +
         (P3[2] *
              (V1[5] * (V2[2] * (P2[0] - P1[0]) + V2[3] * (P2[1] - P1[1])) +
               V2[5] * (V1[2] * (P1[0] - P2[0]) + V1[3] * (P1[1] - P2[1]))) +
          (P3[3] *
               (V1[4] * (V2[2] * (P1[0] - P2[0]) + V2[3] * (P1[1] - P2[1])) +
                V2[4] * (V1[2] * (P2[0] - P1[0]) + V1[3] * (P2[1] - P1[1]))) +
           (P3[0] * (V1[4] * V2[5] * (P2[0] - P1[0]) +
                     V1[5] * V2[4] * (P1[0] - P2[0])) +
            P3[1] * (V1[4] * V2[5] * (P2[1] - P1[1]) +
                     V1[5] * V2[4] * (P1[1] - P2[1]))))));
    T3[7] = denom * 2. * cI *
            (OM3 * P3[1] *
                 (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                          (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                           P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                  (TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                           (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                            P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                   0.333333333 * (P3[1] * (TMP55 - TMP56)))) +
             (P1[1] * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                       (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                        P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
              (P2[1] * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                        (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                         P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
               (-0.333333333 * (TMP56) + 0.333333333 * (TMP55)))));
    T3[8] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                 (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         (TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                   P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                          0.666666667 * (P3[2] * (TMP55 - TMP56)))) +
                P3[2] * (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                         TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))))) +
         (P3[0] *
              (V1[5] * (V2[3] * (P1[1] - P2[1]) + V2[4] * (P2[2] - P1[2])) +
               V2[5] * (V1[3] * (P2[1] - P1[1]) + V1[4] * (P1[2] - P2[2]))) +
          (P3[3] *
               (V1[2] * (V2[3] * (P2[1] - P1[1]) + V2[4] * (P1[2] - P2[2])) +
                V2[2] * (V1[3] * (P1[1] - P2[1]) + V1[4] * (P2[2] - P1[2]))) +
           (P3[1] * (V1[2] * V2[5] * (P1[1] - P2[1]) +
                     V1[5] * V2[2] * (P2[1] - P1[1])) +
            P3[2] * (V1[2] * V2[5] * (P2[2] - P1[2]) +
                     V1[5] * V2[2] * (P1[2] - P2[2]))))));
    T3[9] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                 (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                  P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                  (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                   P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[3] * (TMP55 - TMP56)))) +
                P3[3] * (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                         TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))))) +
         (P3[0] *
              (V1[4] * (V2[3] * (P2[1] - P1[1]) + V2[5] * (P1[3] - P2[3])) +
               V2[4] * (V1[3] * (P1[1] - P2[1]) + V1[5] * (P2[3] - P1[3]))) +
          (P3[2] *
               (V1[2] * (V2[3] * (P1[1] - P2[1]) + V2[5] * (P2[3] - P1[3])) +
                V2[2] * (V1[3] * (P2[1] - P1[1]) + V1[5] * (P1[3] - P2[3]))) +
           (P3[1] * (V1[2] * V2[4] * (P2[1] - P1[1]) +
                     V1[4] * V2[2] * (P1[1] - P2[1])) +
            P3[3] * (V1[2] * V2[4] * (P1[3] - P2[3]) +
                     V1[4] * V2[2] * (P2[3] - P1[3]))))));
    T3[10] =
        denom * -cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                 (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                   P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[2] * (TMP56 - TMP55)))) +
                P3[2] * (TMP1 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                         TMP2 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))))) +
         (P3[1] *
              (V1[5] * (V2[2] * (P1[0] - P2[0]) + V2[4] * (P1[2] - P2[2])) +
               V2[5] * (V1[2] * (P2[0] - P1[0]) + V1[4] * (P2[2] - P1[2]))) +
          (P3[3] *
               (V1[3] * (V2[2] * (P2[0] - P1[0]) + V2[4] * (P2[2] - P1[2])) +
                V2[3] * (V1[2] * (P1[0] - P2[0]) + V1[4] * (P1[2] - P2[2]))) +
           (P3[0] * (V1[3] * V2[5] * (P1[0] - P2[0]) +
                     V1[5] * V2[3] * (P2[0] - P1[0])) +
            P3[2] * (V1[3] * V2[5] * (P1[2] - P2[2]) +
                     V1[5] * V2[3] * (P2[2] - P1[2]))))));
    T3[11] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                 (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         (TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                   P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                          0.666666667 * (P3[2] * (TMP55 - TMP56)))) +
                P3[2] * (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                         TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))))) +
         (P3[0] *
              (V1[5] * (V2[3] * (P1[1] - P2[1]) + V2[4] * (P2[2] - P1[2])) +
               V2[5] * (V1[3] * (P2[1] - P1[1]) + V1[4] * (P1[2] - P2[2]))) +
          (P3[3] *
               (V1[2] * (V2[3] * (P2[1] - P1[1]) + V2[4] * (P1[2] - P2[2])) +
                V2[2] * (V1[3] * (P1[1] - P2[1]) + V1[4] * (P2[2] - P1[2]))) +
           (P3[1] * (V1[2] * V2[5] * (P1[1] - P2[1]) +
                     V1[5] * V2[2] * (P2[1] - P1[1])) +
            P3[2] * (V1[2] * V2[5] * (P2[2] - P1[2]) +
                     V1[5] * V2[2] * (P1[2] - P2[2]))))));
    T3[12] = denom * 2. * cI *
             (OM3 * P3[2] *
                  (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                           (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                            P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                   (TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                            (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                             P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                    0.333333333 * (P3[2] * (TMP55 - TMP56)))) +
              (P1[2] * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                        (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                         P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
               (P2[2] * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                         (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                          P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                (-0.333333333 * (TMP56) + 0.333333333 * (TMP55)))));
    T3[13] =
        denom * cI *
        (OM3 * (P3[2] * (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                 (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                  P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                  (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                   P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[3] * (TMP55 - TMP56)))) +
                P3[3] * (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                 (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                 (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))))) +
         (P3[0] *
              (V1[3] * (V2[4] * (P1[2] - P2[2]) + V2[5] * (P2[3] - P1[3])) +
               V2[3] * (V1[4] * (P2[2] - P1[2]) + V1[5] * (P1[3] - P2[3]))) +
          (P3[1] *
               (V1[2] * (V2[4] * (P2[2] - P1[2]) + V2[5] * (P1[3] - P2[3])) +
                V2[2] * (V1[4] * (P1[2] - P2[2]) + V1[5] * (P2[3] - P1[3]))) +
           (P3[2] * (V1[2] * V2[3] * (P1[2] - P2[2]) +
                     V1[3] * V2[2] * (P2[2] - P1[2])) +
            P3[3] * (V1[2] * V2[3] * (P2[3] - P1[3]) +
                     V1[3] * V2[2] * (P1[3] - P2[3]))))));
    T3[14] =
        denom * -cI *
        (OM3 * (P3[0] * (TMP1 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                 (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                  P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         (TMP2 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                  (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                   P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                          0.666666667 * (P3[3] * (TMP56 - TMP55)))) +
                P3[3] * (TMP1 * (P3[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                  P3[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                         TMP2 * (P3[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                  P3[3] * (V2[3] * V1[4] - V2[4] * V1[3]))))) +
         (P3[1] *
              (V1[4] * (V2[2] * (P2[0] - P1[0]) + V2[5] * (P2[3] - P1[3])) +
               V2[4] * (V1[2] * (P1[0] - P2[0]) + V1[5] * (P1[3] - P2[3]))) +
          (P3[2] *
               (V1[3] * (V2[2] * (P1[0] - P2[0]) + V2[5] * (P1[3] - P2[3])) +
                V2[3] * (V1[2] * (P2[0] - P1[0]) + V1[5] * (P2[3] - P1[3]))) +
           (P3[0] * (V1[3] * V2[4] * (P2[0] - P1[0]) +
                     V1[4] * V2[3] * (P1[0] - P2[0])) +
            P3[3] * (V1[3] * V2[4] * (P2[3] - P1[3]) +
                     V1[4] * V2[3] * (P1[3] - P2[3]))))));
    T3[15] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                 (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                  P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                  (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                   P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[3] * (TMP55 - TMP56)))) +
                P3[3] * (TMP1 * (P3[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                                 (P3[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                         TMP2 * (P3[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                                 (P3[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[4] * V1[2] - V2[2] * V1[4]))))) +
         (P3[0] *
              (V1[4] * (V2[3] * (P2[1] - P1[1]) + V2[5] * (P1[3] - P2[3])) +
               V2[4] * (V1[3] * (P1[1] - P2[1]) + V1[5] * (P2[3] - P1[3]))) +
          (P3[2] *
               (V1[2] * (V2[3] * (P1[1] - P2[1]) + V2[5] * (P2[3] - P1[3])) +
                V2[2] * (V1[3] * (P2[1] - P1[1]) + V1[5] * (P1[3] - P2[3]))) +
           (P3[1] * (V1[2] * V2[4] * (P2[1] - P1[1]) +
                     V1[4] * V2[2] * (P1[1] - P2[1])) +
            P3[3] * (V1[2] * V2[4] * (P1[3] - P2[3]) +
                     V1[4] * V2[2] * (P2[3] - P1[3]))))));
    T3[16] =
        denom * cI *
        (OM3 * (P3[2] * (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                                 (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                                  P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                         (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                                  (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                                   P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                          0.666666667 * (P3[3] * (TMP55 - TMP56)))) +
                P3[3] * (TMP1 * (P3[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                                 (P3[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                                  P3[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                         TMP2 * (P3[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                                 (P3[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                                  P3[3] * (V2[2] * V1[3] - V2[3] * V1[2]))))) +
         (P3[0] *
              (V1[3] * (V2[4] * (P1[2] - P2[2]) + V2[5] * (P2[3] - P1[3])) +
               V2[3] * (V1[4] * (P2[2] - P1[2]) + V1[5] * (P1[3] - P2[3]))) +
          (P3[1] *
               (V1[2] * (V2[4] * (P2[2] - P1[2]) + V2[5] * (P1[3] - P2[3])) +
                V2[2] * (V1[4] * (P1[2] - P2[2]) + V1[5] * (P2[3] - P1[3]))) +
           (P3[2] * (V1[2] * V2[3] * (P1[2] - P2[2]) +
                     V1[3] * V2[2] * (P2[2] - P1[2])) +
            P3[3] * (V1[2] * V2[3] * (P2[3] - P1[3]) +
                     V1[3] * V2[2] * (P1[3] - P2[3]))))));
    T3[17] = denom * 2. * cI *
             (OM3 * P3[3] *
                  (TMP1 * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                           (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                            P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                   (TMP2 * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                            (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                             P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                    0.333333333 * (P3[3] * (TMP55 - TMP56)))) +
              (P1[3] * (P3[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                        (P3[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                         P3[2] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
               (P2[3] * (P3[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                         (P3[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                          P3[2] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                (-0.333333333 * (TMP56) + 0.333333333 * (TMP55)))));
}

void VVT5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP34;
    complex<double> TMP1;
    double P1[4];
    complex<double> TMP2;
    double P2[4];
    complex<double> TMP23;
    double P3[4];
    double OM3;
    complex<double> TMP33;
    complex<double> TMP26;
    complex<double> denom;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    T3[0] = +V1[0] + V2[0];
    T3[1] = +V1[1] + V2[1];
    P3[0] = -T3[0].real();
    P3[1] = -T3[1].real();
    P3[2] = -T3[1].imag();
    P3[3] = -T3[0].imag();
    TMP26 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP23 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP33 = -1. * (P1[0] * (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                   (P1[1] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                             (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                              P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                    (P1[2] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                              (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                               P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                     P1[3] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                              (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                               P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))))));
    TMP34 = -1. * (P1[0] * (P2[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P2[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P2[3] * (P3[1] * V2[4] - P3[2] * V2[3]))) +
                   (P1[1] * (P2[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                             (P2[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                              P2[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                    (P1[2] * (P2[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                              (P2[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                               P2[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                     P1[3] * (P2[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                              (P2[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                               P2[2] * (P3[1] * V2[2] - P3[0] * V2[3]))))));
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] = denom * -2. * cI *
            (TMP23 * (OM3 * P3[0] *
                          (TMP1 * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                                   (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                                    P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))) -
                           0.333333333 * (P3[0] * TMP33)) +
                      (P1[0] * (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                 P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       0.333333333 * (TMP33))) +
             TMP26 * (OM3 * P3[0] *
                          (TMP2 * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                                   (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                                    P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))) -
                           0.333333333 * (P3[0] * TMP34)) +
                      (P2[0] * (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       0.333333333 * (TMP34))));
    T3[3] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                    (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                     P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                            0.666666667 * (P3[1] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                    (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                     P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                            0.666666667 * (P3[1] * TMP34))) +
              P3[1] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                   P1[1] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                   P2[1] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[4] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            0.666666667 * (P3[2] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                    (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                     P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                            0.666666667 * (P3[2] * TMP34))) +
              P3[2] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[5] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[6] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                    (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                     P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                            0.666666667 * (P3[1] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                    (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                     P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                            0.666666667 * (P3[1] * TMP34))) +
              P3[1] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                   P1[1] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                   P2[1] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[7] = denom * 2. * cI *
            (TMP23 * (OM3 * P3[1] *
                          (TMP1 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                   (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                    P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                           0.333333333 * (P3[1] * TMP33)) +
                      (P1[1] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                                (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                 P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                       0.333333333 * (TMP33))) +
             TMP26 * (OM3 * P3[1] *
                          (TMP2 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                   (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                    P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                           0.333333333 * (P3[1] * TMP34)) +
                      (P2[1] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                                (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                 P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                       0.333333333 * (TMP34))));
    T3[8] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            0.666666667 * (P3[2] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                    (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                     P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                            0.666666667 * (P3[2] * TMP34))) +
              P3[2] * (TMP1 * TMP23 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))))) +
         (TMP23 * (P1[1] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2])))) +
          TMP26 * (P2[1] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))))));
    T3[9] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))))) +
         (TMP23 * (P1[1] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2])))) +
          TMP26 * (P2[1] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))))));
    T3[10] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            0.666666667 * (P3[2] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                    (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                     P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                            0.666666667 * (P3[2] * TMP34))) +
              P3[2] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[11] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            0.666666667 * (P3[2] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                    (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                     P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                            0.666666667 * (P3[2] * TMP34))) +
              P3[2] * (TMP1 * TMP23 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))))) +
         (TMP23 * (P1[1] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2])))) +
          TMP26 * (P2[1] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))))));
    T3[12] = denom * 2. * cI *
             (TMP23 * (OM3 * P3[2] *
                           (TMP1 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            0.333333333 * (P3[2] * TMP33)) +
                       (P1[2] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                                 (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                  P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                        0.333333333 * (TMP33))) +
              TMP26 * (OM3 * P3[2] *
                           (TMP2 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                    (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                     P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                            0.333333333 * (P3[2] * TMP34)) +
                       (P2[2] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                                 (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                  P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        0.333333333 * (TMP34))));
    T3[13] =
        denom * cI *
        (OM3 *
             (P3[2] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                            (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                            (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))))) +
         (TMP23 * (P1[2] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3])))) +
          TMP26 * (P2[2] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))))));
    T3[14] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))))) +
         (TMP23 * (P1[0] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3])))) +
          TMP26 * (P2[0] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))))));
    T3[15] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))))) +
         (TMP23 * (P1[1] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2])))) +
          TMP26 * (P2[1] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))))));
    T3[16] =
        denom * cI *
        (OM3 *
             (P3[2] *
                  (TMP23 * (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.666666667 * (P3[3] * TMP33)) +
                   TMP26 * (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.666666667 * (P3[3] * TMP34))) +
              P3[3] * (TMP1 * TMP23 *
                           (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                            (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                       TMP2 * TMP26 *
                           (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                            (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))))) +
         (TMP23 * (P1[2] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3])))) +
          TMP26 * (P2[2] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))))));
    T3[17] = denom * 2. * cI *
             (TMP23 * (OM3 * P3[3] *
                           (TMP1 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            0.333333333 * (P3[3] * TMP33)) +
                       (P1[3] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                                 (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                                  P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                        0.333333333 * (TMP33))) +
              TMP26 * (OM3 * P3[3] *
                           (TMP2 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                    (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                     P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                            0.333333333 * (P3[3] * TMP34)) +
                       (P2[3] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                                 (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                                  P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                        0.333333333 * (TMP34))));
}

void VVT11_0(complex<double> V1[], complex<double> V2[], complex<double> T3[],
             complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP36;
    complex<double> TMP35;
    TMP36 =
        (V1[2] * -1. *
             (V2[3] * T3[3] + V2[4] * T3[4] + V2[5] * T3[5] - V2[2] * T3[2]) +
         (V1[3] *
              (V2[3] * T3[7] + V2[4] * T3[8] + V2[5] * T3[9] - V2[2] * T3[6]) +
          (V1[4] * (V2[3] * T3[11] + V2[4] * T3[12] + V2[5] * T3[13] -
                    V2[2] * T3[10]) +
           V1[5] * (V2[3] * T3[15] + V2[4] * T3[16] + V2[5] * T3[17] -
                    V2[2] * T3[14]))));
    TMP35 =
        (V1[2] * -1. *
             (V2[3] * T3[6] + V2[4] * T3[10] + V2[5] * T3[14] - V2[2] * T3[2]) +
         (V1[3] * (V2[3] * T3[7] + V2[4] * T3[11] + V2[5] * T3[15] -
                   V2[2] * T3[3]) +
          (V1[4] * (V2[3] * T3[8] + V2[4] * T3[12] + V2[5] * T3[16] -
                    V2[2] * T3[4]) +
           V1[5] * (V2[3] * T3[9] + V2[4] * T3[13] + V2[5] * T3[17] -
                    V2[2] * T3[5]))));
    vertex = COUP * -1. * (+cI * (TMP35 + TMP36));
}

void FFT4_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP1;
    double P1[4];
    complex<double> TMP10;
    double P2[4];
    double P3[4];
    double OM3;
    complex<double> denom;
    complex<double> TMP19;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    P2[0] = F2[0].real();
    P2[1] = F2[1].real();
    P2[2] = F2[1].imag();
    P2[3] = F2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    T3[0] = +F1[0] + F2[0];
    T3[1] = +F1[1] + F2[1];
    P3[0] = -T3[0].real();
    P3[1] = -T3[1].real();
    P3[2] = -T3[1].imag();
    P3[3] = -T3[0].imag();
    TMP19 = (F2[2] * F1[2] + F2[3] * F1[3] + F2[4] * F1[4] + F2[5] * F1[5]);
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP10 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. * TMP19 *
        (OM3 * (P3[0] * (P3[0] * 0.333333333 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[0] + P1[0] * TMP2))) +
                0.333333333 * cI * (TMP1 * TMP2)) +
         (-0.333333333 * cI * (TMP10) + cI * (P1[0] * P2[0])));
    T3[3] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[1] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[1] * TMP2 + TMP1 * P2[1]))) -
                P3[1] * (+cI * (TMP1 * P2[0] + P1[0] * TMP2))) +
         (+cI * (P1[1] * P2[0] + P1[0] * P2[1])));
    T3[4] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[2] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[2] * TMP2 + TMP1 * P2[2]))) -
                P3[2] * (+cI * (TMP1 * P2[0] + P1[0] * TMP2))) +
         (+cI * (P1[2] * P2[0] + P1[0] * P2[2])));
    T3[5] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[3] * TMP2 + TMP1 * P2[3]))) -
                P3[3] * (+cI * (TMP1 * P2[0] + P1[0] * TMP2))) +
         (+cI * (P1[3] * P2[0] + P1[0] * P2[3])));
    T3[6] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[1] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[1] + P1[1] * TMP2))) -
                P3[1] * (+cI * (P1[0] * TMP2 + TMP1 * P2[0]))) +
         (+cI * (P1[0] * P2[1] + P1[1] * P2[0])));
    T3[7] =
        denom * 2. * TMP19 *
        (OM3 * (P3[1] * (P3[1] * 0.333333333 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[1] + P1[1] * TMP2))) -
                0.333333333 * cI * (TMP1 * TMP2)) +
         (+cI * (P1[1] * P2[1]) + 0.333333333 * cI * (TMP10)));
    T3[8] =
        denom * TMP19 *
        (OM3 * (P3[1] * (P3[2] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[2] * TMP2 + TMP1 * P2[2]))) -
                P3[2] * (+cI * (TMP1 * P2[1] + P1[1] * TMP2))) +
         (+cI * (P1[2] * P2[1] + P1[1] * P2[2])));
    T3[9] =
        denom * TMP19 *
        (OM3 * (P3[1] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[3] * TMP2 + TMP1 * P2[3]))) -
                P3[3] * (+cI * (TMP1 * P2[1] + P1[1] * TMP2))) +
         (+cI * (P1[3] * P2[1] + P1[1] * P2[3])));
    T3[10] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[2] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[2] + P1[2] * TMP2))) -
                P3[2] * (+cI * (P1[0] * TMP2 + TMP1 * P2[0]))) +
         (+cI * (P1[0] * P2[2] + P1[2] * P2[0])));
    T3[11] =
        denom * TMP19 *
        (OM3 * (P3[1] * (P3[2] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[2] + P1[2] * TMP2))) -
                P3[2] * (+cI * (P1[1] * TMP2 + TMP1 * P2[1]))) +
         (+cI * (P1[1] * P2[2] + P1[2] * P2[1])));
    T3[12] =
        denom * 2. * TMP19 *
        (OM3 * (P3[2] * (P3[2] * 0.333333333 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[2] + P1[2] * TMP2))) -
                0.333333333 * cI * (TMP1 * TMP2)) +
         (+cI * (P1[2] * P2[2]) + 0.333333333 * cI * (TMP10)));
    T3[13] =
        denom * TMP19 *
        (OM3 * (P3[2] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (P1[3] * TMP2 + TMP1 * P2[3]))) -
                P3[3] * (+cI * (TMP1 * P2[2] + P1[2] * TMP2))) +
         (+cI * (P1[3] * P2[2] + P1[2] * P2[3])));
    T3[14] =
        denom * TMP19 *
        (OM3 * (P3[0] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[3] + P1[3] * TMP2))) -
                P3[3] * (+cI * (P1[0] * TMP2 + TMP1 * P2[0]))) +
         (+cI * (P1[0] * P2[3] + P1[3] * P2[0])));
    T3[15] =
        denom * TMP19 *
        (OM3 * (P3[1] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[3] + P1[3] * TMP2))) -
                P3[3] * (+cI * (P1[1] * TMP2 + TMP1 * P2[1]))) +
         (+cI * (P1[1] * P2[3] + P1[3] * P2[1])));
    T3[16] =
        denom * TMP19 *
        (OM3 * (P3[2] * (P3[3] * 0.666666667 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[3] + P1[3] * TMP2))) -
                P3[3] * (+cI * (P1[2] * TMP2 + TMP1 * P2[2]))) +
         (+cI * (P1[2] * P2[3] + P1[3] * P2[2])));
    T3[17] =
        denom * 2. * TMP19 *
        (OM3 * (P3[3] * (P3[3] * 0.333333333 *
                             (+cI * (TMP10) + 2. * cI * (OM3 * TMP1 * TMP2)) +
                         (-cI * (TMP1 * P2[3] + P1[3] * TMP2))) -
                0.333333333 * cI * (TMP1 * TMP2)) +
         (+cI * (P1[3] * P2[3]) + 0.333333333 * cI * (TMP10)));
}

void VVT7_0(complex<double> V1[], complex<double> V2[], complex<double> T3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> TMP22;
    double P2[4];
    complex<double> TMP21;
    complex<double> TMP4;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP4 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP21 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    TMP22 =
        (P1[0] * -1. *
             (P2[1] * T3[3] + P2[2] * T3[4] + P2[3] * T3[5] - P2[0] * T3[2]) +
         (P1[1] *
              (P2[1] * T3[7] + P2[2] * T3[8] + P2[3] * T3[9] - P2[0] * T3[6]) +
          (P1[2] * (P2[1] * T3[11] + P2[2] * T3[12] + P2[3] * T3[13] -
                    P2[0] * T3[10]) +
           P1[3] * (P2[1] * T3[15] + P2[2] * T3[16] + P2[3] * T3[17] -
                    P2[0] * T3[14]))));
    vertex = COUP * -TMP4 * (+cI * (TMP21 + TMP22));
}

void VVT2_0(complex<double> V1[], complex<double> V2[], complex<double> T3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> TMP22;
    double P2[4];
    complex<double> TMP30;
    complex<double> TMP21;
    complex<double> TMP29;
    P1[0] = V1[0].real();
    P1[1] = V1[1].real();
    P1[2] = V1[1].imag();
    P1[3] = V1[0].imag();
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    TMP30 = -1. * (P1[0] * (P2[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                            (P2[2] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                             P2[3] * (V2[4] * V1[3] - V2[3] * V1[4]))) +
                   (P1[1] * (P2[0] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                             (P2[2] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                              P2[3] * (V2[2] * V1[4] - V2[4] * V1[2]))) +
                    (P1[2] * (P2[0] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                              (P2[1] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                               P2[3] * (V2[3] * V1[2] - V2[2] * V1[3]))) +
                     P1[3] * (P2[0] * (V2[3] * V1[4] - V2[4] * V1[3]) +
                              (P2[1] * (V2[4] * V1[2] - V2[2] * V1[4]) +
                               P2[2] * (V2[2] * V1[3] - V2[3] * V1[2]))))));
    TMP21 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    TMP22 =
        (P1[0] * -1. *
             (P2[1] * T3[3] + P2[2] * T3[4] + P2[3] * T3[5] - P2[0] * T3[2]) +
         (P1[1] *
              (P2[1] * T3[7] + P2[2] * T3[8] + P2[3] * T3[9] - P2[0] * T3[6]) +
          (P1[2] * (P2[1] * T3[11] + P2[2] * T3[12] + P2[3] * T3[13] -
                    P2[0] * T3[10]) +
           P1[3] * (P2[1] * T3[15] + P2[2] * T3[16] + P2[3] * T3[17] -
                    P2[0] * T3[14]))));
    TMP29 = -1. * (P1[0] * (P2[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
                            (P2[2] * (V2[5] * V1[3] - V2[3] * V1[5]) +
                             P2[3] * (V2[3] * V1[4] - V2[4] * V1[3]))) +
                   (P1[1] * (P2[0] * (V2[5] * V1[4] - V2[4] * V1[5]) +
                             (P2[2] * (V2[2] * V1[5] - V2[5] * V1[2]) +
                              P2[3] * (V2[4] * V1[2] - V2[2] * V1[4]))) +
                    (P1[2] * (P2[0] * (V2[3] * V1[5] - V2[5] * V1[3]) +
                              (P2[1] * (V2[5] * V1[2] - V2[2] * V1[5]) +
                               P2[3] * (V2[2] * V1[3] - V2[3] * V1[2]))) +
                     P1[3] * (P2[0] * (V2[4] * V1[3] - V2[3] * V1[4]) +
                              (P2[1] * (V2[2] * V1[4] - V2[4] * V1[2]) +
                               P2[2] * (V2[3] * V1[2] - V2[2] * V1[3]))))));
    vertex = COUP * (TMP21 * (-cI * (TMP30) + cI * (TMP29)) +
                     TMP22 * (-cI * (TMP30) + cI * (TMP29)));
}

void FFT3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP2;
    complex<double> TMP39;
    complex<double> TMP1;
    double P1[4];
    double P2[4];
    double P3[4];
    complex<double> TMP40;
    complex<double> denom;
    complex<double> TMP11;
    double OM3;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    P2[0] = F2[0].real();
    P2[1] = F2[1].real();
    P2[2] = F2[1].imag();
    P2[3] = F2[0].imag();
    OM3 = 0.;
    if (M3 != 0.)
        OM3 = 1. / pow(M3, 2);
    T3[0] = +F1[0] + F2[0];
    T3[1] = +F1[1] + F2[1];
    P3[0] = -T3[0].real();
    P3[1] = -T3[1].real();
    P3[2] = -T3[1].imag();
    P3[3] = -T3[0].imag();
    TMP1 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP39 =
        (F1[2] *
             (F2[4] * -1. * (P1[0] + P1[3]) - F2[5] * (P1[1] + cI * (P1[2]))) +
         (F1[3] * (F2[4] * (+cI * (P1[2]) - P1[1]) + F2[5] * (P1[3] - P1[0])) +
          (F1[4] * (F2[2] * (P1[0] - P1[3]) - F2[3] * (P1[1] + cI * (P1[2]))) +
           F1[5] *
               (F2[2] * (+cI * (P1[2]) - P1[1]) + F2[3] * (P1[0] + P1[3])))));
    TMP11 =
        (F1[2] *
             (F2[4] * -1. * (P3[0] + P3[3]) - F2[5] * (P3[1] + cI * (P3[2]))) +
         (F1[3] * (F2[4] * (+cI * (P3[2]) - P3[1]) + F2[5] * (P3[3] - P3[0])) +
          (F1[4] * (F2[2] * (P3[0] - P3[3]) - F2[3] * (P3[1] + cI * (P3[2]))) +
           F1[5] *
               (F2[2] * (+cI * (P3[2]) - P3[1]) + F2[3] * (P3[0] + P3[3])))));
    TMP40 =
        (F1[2] *
             (F2[4] * -1. * (P2[0] + P2[3]) - F2[5] * (P2[1] + cI * (P2[2]))) +
         (F1[3] * (F2[4] * (+cI * (P2[2]) - P2[1]) + F2[5] * (P2[3] - P2[0])) +
          (F1[4] * (F2[2] * (P2[0] - P2[3]) - F2[3] * (P2[1] + cI * (P2[2]))) +
           F1[5] *
               (F2[2] * (+cI * (P2[2]) - P2[1]) + F2[3] * (P2[0] + P2[3])))));
    TMP2 = (P3[0] * P2[0] - P3[1] * P2[1] - P3[2] * P2[2] - P3[3] * P2[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. * cI *
        (OM3 * (P3[0] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] +
                                 0.666666667 * (P3[0] * OM3 * TMP11) -
                                 F2[2] * F1[4] - F2[3] * F1[5]) +
                         (TMP2 * -1. *
                              (F2[4] * F1[2] + F2[5] * F1[3] +
                               0.666666667 * (P3[0] * OM3 * TMP11) -
                               F2[2] * F1[4] - F2[3] * F1[5]) +
                          (P3[0] * 0.333333333 * (TMP39 - TMP40) +
                           TMP11 * (P2[0] - P1[0])))) +
                0.333333333 * (TMP11 * (TMP1 - TMP2))) +
         (P1[0] *
              (F2[2] * F1[4] + F2[3] * F1[5] - F2[4] * F1[2] - F2[5] * F1[3]) +
          (P2[0] *
               (F2[4] * F1[2] + F2[5] * F1[3] - F2[2] * F1[4] - F2[3] * F1[5]) +
           (-0.333333333 * (TMP39) + 0.333333333 * (TMP40)))));
    T3[6] = denom * cI *
            (OM3 * (P3[0] * (TMP1 * -1. *
                                 (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5] -
                                  1.333333333 * (P3[1] * OM3 * TMP11)) +
                             (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                      F2[3] * F1[4] + F2[2] * F1[5] -
                                      1.333333333 * (P3[1] * OM3 * TMP11)) +
                              (P3[1] * 0.666666667 * (TMP39 - TMP40) +
                               TMP11 * (P2[1] - P1[1])))) +
                    P3[1] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                     F2[2] * F1[4] - F2[3] * F1[5]) +
                             (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                      F2[4] * F1[2] - F2[5] * F1[3]) +
                              TMP11 * (P2[0] - P1[0])))) +
             (F1[2] * (F2[4] * (P2[1] - P1[1]) + F2[5] * (P1[0] - P2[0])) +
              (F1[3] * (F2[4] * (P1[0] - P2[0]) + F2[5] * (P2[1] - P1[1])) +
               (F1[4] * (F2[2] * (P1[1] - P2[1]) + F2[3] * (P1[0] - P2[0])) +
                F1[5] * (F2[2] * (P1[0] - P2[0]) + F2[3] * (P1[1] - P2[1]))))));
    T3[10] = denom * cI *
             (OM3 * (P3[0] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                      cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                      1.333333333 * (P3[2] * OM3 * TMP11)) +
                              (TMP2 * -1. *
                                   (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                    cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                    1.333333333 * (P3[2] * OM3 * TMP11)) +
                               (P3[2] * 0.666666667 * (TMP39 - TMP40) +
                                TMP11 * (P2[2] - P1[2])))) +
                     P3[2] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                      F2[2] * F1[4] - F2[3] * F1[5]) +
                              (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                       F2[4] * F1[2] - F2[5] * F1[3]) +
                               TMP11 * (P2[0] - P1[0])))) +
              (F1[2] * (F2[4] * (P2[2] - P1[2]) +
                        F2[5] * (-cI * (P2[0]) + cI * (P1[0]))) +
               (F1[3] * (F2[4] * (-cI * (P1[0]) + cI * (P2[0])) +
                         F2[5] * (P2[2] - P1[2])) +
                (F1[4] * (F2[2] * (P1[2] - P2[2]) +
                          F2[3] * (-cI * (P2[0]) + cI * (P1[0]))) +
                 F1[5] * (F2[2] * (-cI * (P1[0]) + cI * (P2[0])) +
                          F2[3] * (P1[2] - P2[2]))))));
    T3[14] = denom * cI *
             (OM3 * (P3[0] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                      1.333333333 * (P3[3] * OM3 * TMP11) -
                                      F2[4] * F1[2] - F2[2] * F1[4]) +
                              (TMP2 * -1. *
                                   (F2[5] * F1[3] + F2[3] * F1[5] +
                                    1.333333333 * (P3[3] * OM3 * TMP11) -
                                    F2[4] * F1[2] - F2[2] * F1[4]) +
                               (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                                TMP11 * (P2[3] - P1[3])))) +
                     P3[3] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                      F2[2] * F1[4] - F2[3] * F1[5]) +
                              (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                       F2[4] * F1[2] - F2[5] * F1[3]) +
                               TMP11 * (P2[0] - P1[0])))) +
              (F1[2] * F2[4] * (P1[0] + P2[3] - P1[3] - P2[0]) +
               (F1[3] * F2[5] * (P2[0] + P2[3] - P1[0] - P1[3]) +
                (F1[4] * F2[2] * (P1[0] + P1[3] - P2[0] - P2[3]) +
                 F1[5] * F2[3] * (P1[3] + P2[0] - P1[0] - P2[3])))));
    T3[3] = denom * cI *
            (OM3 * (P3[0] * (TMP1 * -1. *
                                 (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5] -
                                  1.333333333 * (P3[1] * OM3 * TMP11)) +
                             (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                      F2[3] * F1[4] + F2[2] * F1[5] -
                                      1.333333333 * (P3[1] * OM3 * TMP11)) +
                              (P3[1] * 0.666666667 * (TMP39 - TMP40) +
                               TMP11 * (P2[1] - P1[1])))) +
                    P3[1] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                     F2[2] * F1[4] - F2[3] * F1[5]) +
                             (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                      F2[4] * F1[2] - F2[5] * F1[3]) +
                              TMP11 * (P2[0] - P1[0])))) +
             (F1[2] * (F2[4] * (P2[1] - P1[1]) + F2[5] * (P1[0] - P2[0])) +
              (F1[3] * (F2[4] * (P1[0] - P2[0]) + F2[5] * (P2[1] - P1[1])) +
               (F1[4] * (F2[2] * (P1[1] - P2[1]) + F2[3] * (P1[0] - P2[0])) +
                F1[5] * (F2[2] * (P1[0] - P2[0]) + F2[3] * (P1[1] - P2[1]))))));
    T3[7] =
        denom * 2. * cI *
        (OM3 * (P3[1] *
                    (TMP1 * -1. *
                         (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] +
                          F2[2] * F1[5] - 0.666666667 * (P3[1] * OM3 * TMP11)) +
                     (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] +
                              F2[2] * F1[5] -
                              0.666666667 * (P3[1] * OM3 * TMP11)) +
                      (P3[1] * 0.333333333 * (TMP39 - TMP40) +
                       TMP11 * (P2[1] - P1[1])))) +
                0.333333333 * (TMP11 * (TMP2 - TMP1))) +
         (P1[1] *
              (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] + F2[2] * F1[5]) +
          (P2[1] * -1. *
               (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] + F2[2] * F1[5]) +
           (-0.333333333 * (TMP40) + 0.333333333 * (TMP39)))));
    T3[11] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                 cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                 1.333333333 * (P3[2] * OM3 * TMP11)) +
                         (TMP2 * -1. *
                              (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                               cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                               1.333333333 * (P3[2] * OM3 * TMP11)) +
                          (P3[2] * 0.666666667 * (TMP39 - TMP40) +
                           TMP11 * (P2[2] - P1[2])))) +
                P3[2] * (TMP1 * -1. *
                             (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] +
                              F2[2] * F1[5]) +
                         (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5]) +
                          TMP11 * (P2[1] - P1[1])))) +
         (F1[2] * F2[5] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
          (F1[3] * F2[4] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2]) +
           (F1[4] * F2[3] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
            F1[5] * F2[2] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2])))));
    T3[15] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                 1.333333333 * (P3[3] * OM3 * TMP11) -
                                 F2[4] * F1[2] - F2[2] * F1[4]) +
                         (TMP2 * -1. *
                              (F2[5] * F1[3] + F2[3] * F1[5] +
                               1.333333333 * (P3[3] * OM3 * TMP11) -
                               F2[4] * F1[2] - F2[2] * F1[4]) +
                          (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                           TMP11 * (P2[3] - P1[3])))) +
                P3[3] * (TMP1 * -1. *
                             (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] +
                              F2[2] * F1[5]) +
                         (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5]) +
                          TMP11 * (P2[1] - P1[1])))) +
         (F1[2] * (F2[4] * (P1[1] - P2[1]) + F2[5] * (P1[3] - P2[3])) +
          (F1[3] * (F2[4] * (P1[3] - P2[3]) + F2[5] * (P2[1] - P1[1])) +
           (F1[4] * (F2[2] * (P1[1] - P2[1]) + F2[3] * (P1[3] - P2[3])) +
            F1[5] * (F2[2] * (P1[3] - P2[3]) + F2[3] * (P2[1] - P1[1]))))));
    T3[4] = denom * cI *
            (OM3 * (P3[0] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                     cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                     1.333333333 * (P3[2] * OM3 * TMP11)) +
                             (TMP2 * -1. *
                                  (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                   cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                   1.333333333 * (P3[2] * OM3 * TMP11)) +
                              (P3[2] * 0.666666667 * (TMP39 - TMP40) +
                               TMP11 * (P2[2] - P1[2])))) +
                    P3[2] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                     F2[2] * F1[4] - F2[3] * F1[5]) +
                             (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                      F2[4] * F1[2] - F2[5] * F1[3]) +
                              TMP11 * (P2[0] - P1[0])))) +
             (F1[2] * (F2[4] * (P2[2] - P1[2]) +
                       F2[5] * (-cI * (P2[0]) + cI * (P1[0]))) +
              (F1[3] * (F2[4] * (-cI * (P1[0]) + cI * (P2[0])) +
                        F2[5] * (P2[2] - P1[2])) +
               (F1[4] * (F2[2] * (P1[2] - P2[2]) +
                         F2[3] * (-cI * (P2[0]) + cI * (P1[0]))) +
                F1[5] * (F2[2] * (-cI * (P1[0]) + cI * (P2[0])) +
                         F2[3] * (P1[2] - P2[2]))))));
    T3[8] =
        denom * cI *
        (OM3 * (P3[1] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                 cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                 1.333333333 * (P3[2] * OM3 * TMP11)) +
                         (TMP2 * -1. *
                              (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                               cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                               1.333333333 * (P3[2] * OM3 * TMP11)) +
                          (P3[2] * 0.666666667 * (TMP39 - TMP40) +
                           TMP11 * (P2[2] - P1[2])))) +
                P3[2] * (TMP1 * -1. *
                             (F2[5] * F1[2] + F2[4] * F1[3] + F2[3] * F1[4] +
                              F2[2] * F1[5]) +
                         (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5]) +
                          TMP11 * (P2[1] - P1[1])))) +
         (F1[2] * F2[5] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
          (F1[3] * F2[4] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2]) +
           (F1[4] * F2[3] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
            F1[5] * F2[2] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2])))));
    T3[12] = denom * 2. * cI *
             (OM3 * (P3[2] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                      cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                      0.666666667 * (P3[2] * OM3 * TMP11)) +
                              (TMP2 * -1. *
                                   (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                    cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                    0.666666667 * (P3[2] * OM3 * TMP11)) +
                               (P3[2] * 0.333333333 * (TMP39 - TMP40) +
                                TMP11 * (P2[2] - P1[2])))) +
                     0.333333333 * (TMP11 * (TMP2 - TMP1))) +
              (P1[2] * (-cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                        cI * (F2[5] * F1[2] + F2[3] * F1[4])) +
               (P2[2] * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                         cI * (F2[4] * F1[3] + F2[2] * F1[5])) +
                (-0.333333333 * (TMP40) + 0.333333333 * (TMP39)))));
    T3[16] = denom * cI *
             (OM3 * (P3[2] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                      1.333333333 * (P3[3] * OM3 * TMP11) -
                                      F2[4] * F1[2] - F2[2] * F1[4]) +
                              (TMP2 * -1. *
                                   (F2[5] * F1[3] + F2[3] * F1[5] +
                                    1.333333333 * (P3[3] * OM3 * TMP11) -
                                    F2[4] * F1[2] - F2[2] * F1[4]) +
                               (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                                TMP11 * (P2[3] - P1[3])))) +
                     P3[3] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                      cI * (F2[4] * F1[3] + F2[2] * F1[5])) +
                              (TMP2 * (-cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                       cI * (F2[5] * F1[2] + F2[3] * F1[4])) +
                               TMP11 * (P2[2] - P1[2])))) +
              (F1[2] * (F2[4] * (P1[2] - P2[2]) +
                        F2[5] * (-cI * (P2[3]) + cI * (P1[3]))) +
               (F1[3] * (F2[4] * (-cI * (P1[3]) + cI * (P2[3])) +
                         F2[5] * (P2[2] - P1[2])) +
                (F1[4] * (F2[2] * (P1[2] - P2[2]) +
                          F2[3] * (-cI * (P2[3]) + cI * (P1[3]))) +
                 F1[5] * (F2[2] * (-cI * (P1[3]) + cI * (P2[3])) +
                          F2[3] * (P2[2] - P1[2]))))));
    T3[5] = denom * cI *
            (OM3 * (P3[0] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                     1.333333333 * (P3[3] * OM3 * TMP11) -
                                     F2[4] * F1[2] - F2[2] * F1[4]) +
                             (TMP2 * -1. *
                                  (F2[5] * F1[3] + F2[3] * F1[5] +
                                   1.333333333 * (P3[3] * OM3 * TMP11) -
                                   F2[4] * F1[2] - F2[2] * F1[4]) +
                              (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                               TMP11 * (P2[3] - P1[3])))) +
                    P3[3] * (TMP1 * (F2[4] * F1[2] + F2[5] * F1[3] -
                                     F2[2] * F1[4] - F2[3] * F1[5]) +
                             (TMP2 * (F2[2] * F1[4] + F2[3] * F1[5] -
                                      F2[4] * F1[2] - F2[5] * F1[3]) +
                              TMP11 * (P2[0] - P1[0])))) +
             (F1[2] * F2[4] * (P1[0] + P2[3] - P1[3] - P2[0]) +
              (F1[3] * F2[5] * (P2[3] + P2[0] - P1[3] - P1[0]) +
               (F1[4] * F2[2] * (P1[3] + P1[0] - P2[3] - P2[0]) +
                F1[5] * F2[3] * (P1[3] + P2[0] - P1[0] - P2[3])))));
    T3[9] = denom * cI *
            (OM3 * (P3[1] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                     1.333333333 * (P3[3] * OM3 * TMP11) -
                                     F2[4] * F1[2] - F2[2] * F1[4]) +
                             (TMP2 * -1. *
                                  (F2[5] * F1[3] + F2[3] * F1[5] +
                                   1.333333333 * (P3[3] * OM3 * TMP11) -
                                   F2[4] * F1[2] - F2[2] * F1[4]) +
                              (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                               TMP11 * (P2[3] - P1[3])))) +
                    P3[3] * (TMP1 * -1. *
                                 (F2[5] * F1[2] + F2[4] * F1[3] +
                                  F2[3] * F1[4] + F2[2] * F1[5]) +
                             (TMP2 * (F2[5] * F1[2] + F2[4] * F1[3] +
                                      F2[3] * F1[4] + F2[2] * F1[5]) +
                              TMP11 * (P2[1] - P1[1])))) +
             (F1[2] * (F2[4] * (P1[1] - P2[1]) + F2[5] * (P1[3] - P2[3])) +
              (F1[3] * (F2[4] * (P1[3] - P2[3]) + F2[5] * (P2[1] - P1[1])) +
               (F1[4] * (F2[2] * (P1[1] - P2[1]) + F2[3] * (P1[3] - P2[3])) +
                F1[5] * (F2[2] * (P1[3] - P2[3]) + F2[3] * (P2[1] - P1[1]))))));
    T3[13] = denom * cI *
             (OM3 * (P3[2] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                      1.333333333 * (P3[3] * OM3 * TMP11) -
                                      F2[4] * F1[2] - F2[2] * F1[4]) +
                              (TMP2 * -1. *
                                   (F2[5] * F1[3] + F2[3] * F1[5] +
                                    1.333333333 * (P3[3] * OM3 * TMP11) -
                                    F2[4] * F1[2] - F2[2] * F1[4]) +
                               (P3[3] * 0.666666667 * (TMP39 - TMP40) +
                                TMP11 * (P2[3] - P1[3])))) +
                     P3[3] * (TMP1 * (-cI * (F2[5] * F1[2] + F2[3] * F1[4]) +
                                      cI * (F2[4] * F1[3] + F2[2] * F1[5])) +
                              (TMP2 * (-cI * (F2[4] * F1[3] + F2[2] * F1[5]) +
                                       cI * (F2[5] * F1[2] + F2[3] * F1[4])) +
                               TMP11 * (P2[2] - P1[2])))) +
              (F1[2] * (F2[4] * (P1[2] - P2[2]) +
                        F2[5] * (-cI * (P2[3]) + cI * (P1[3]))) +
               (F1[3] * (F2[4] * (-cI * (P1[3]) + cI * (P2[3])) +
                         F2[5] * (P2[2] - P1[2])) +
                (F1[4] * (F2[2] * (P1[2] - P2[2]) +
                          F2[3] * (-cI * (P2[3]) + cI * (P1[3]))) +
                 F1[5] * (F2[2] * (-cI * (P1[3]) + cI * (P2[3])) +
                          F2[3] * (P2[2] - P1[2]))))));
    T3[17] =
        denom * 2. * cI *
        (OM3 * (P3[3] * (TMP1 * (F2[5] * F1[3] + F2[3] * F1[5] +
                                 0.666666667 * (P3[3] * OM3 * TMP11) -
                                 F2[4] * F1[2] - F2[2] * F1[4]) +
                         (TMP2 * -1. *
                              (F2[5] * F1[3] + F2[3] * F1[5] +
                               0.666666667 * (P3[3] * OM3 * TMP11) -
                               F2[4] * F1[2] - F2[2] * F1[4]) +
                          (P3[3] * 0.333333333 * (TMP39 - TMP40) +
                           TMP11 * (P2[3] - P1[3])))) +
                0.333333333 * (TMP11 * (TMP2 - TMP1))) +
         (P1[3] *
              (F2[4] * F1[2] + F2[2] * F1[4] - F2[5] * F1[3] - F2[3] * F1[5]) +
          (P2[3] *
               (F2[5] * F1[3] + F2[3] * F1[5] - F2[4] * F1[2] - F2[2] * F1[4]) +
           (-0.333333333 * (TMP40) + 0.333333333 * (TMP39)))));
}

} // namespace MG5_HEF_MEKD
