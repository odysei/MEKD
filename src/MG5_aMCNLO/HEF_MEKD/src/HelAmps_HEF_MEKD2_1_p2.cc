//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "HelAmps_HEF_MEKD2_1.h"
#include <cmath>
#include <complex>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace MG5_HEF_MEKD2_1
{

void VVT10_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
             double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P3[4];
    complex<double> TMP47;
    complex<double> TMP9;
    complex<double> TMP25;
    complex<double> TMP37;
    double P2[4];
    complex<double> TMP46;
    double OM3;
    complex<double> TMP49;
    complex<double> TMP12;
    double P1[4];
    complex<double> TMP30;
    complex<double> TMP16;
    complex<double> denom;
    complex<double> TMP48;
    complex<double> TMP38;
    complex<double> TMP26;
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
    TMP25 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP26 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP30 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP46 = (P1[0] * P1[0] - P1[1] * P1[1] - P1[2] * P1[2] - P1[3] * P1[3]);
    TMP47 = (P2[0] * P2[0] - P2[1] * P2[1] - P2[2] * P2[2] - P2[3] * P2[3]);
    TMP48 = (P1[0] * V1[2] - P1[1] * V1[3] - P1[2] * V1[4] - P1[3] * V1[5]);
    TMP49 = (P2[0] * V2[2] - P2[1] * V2[3] - P2[2] * V2[4] - P2[3] * V2[5]);
    TMP38 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP9 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP16 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP37 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP12 = (P2[0] * P3[0] - P2[1] * P3[1] - P2[2] * P3[2] - P2[3] * P3[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 1. / 3. *
        (OM3 *
             (P3[0] *
                  (P3[0] *
                       (OM3 * (TMP12 * (TMP9 * (TMP25 * -2. *
                                                    (-2. * cI * (TMP16) +
                                                     cI * (TMP9 + TMP12)) +
                                                (TMP26 * 2. *
                                                     (-2. * cI * (TMP30) +
                                                      cI * (TMP37)) +
                                                 2. * cI * (TMP30 * TMP38))) +
                                        (TMP12 * (TMP26 * 2. *
                                                      (+cI * (TMP30 + TMP37)) -
                                                  2. * cI * (TMP16 * TMP25)) -
                                         2. * cI * (TMP16 * TMP37 * TMP38))) +
                               TMP9 * (TMP9 * (TMP30 * 2. *
                                                   (+cI * (TMP26 + TMP38)) -
                                               2. * cI * (TMP16 * TMP25)) -
                                       2. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. * cI * (TMP26 * TMP30) -
                               cI * (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * (+cI * (TMP46 + TMP47)) +
                                   (+cI * (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           TMP30 * (+cI * (TMP38 * TMP46 + TMP9 * TMP49)))))) +
                   (TMP12 *
                        (TMP26 *
                             (P1[0] * 3. * (-cI * (TMP37) + 2. * cI * (TMP30)) +
                              (P2[0] * -6. * (+cI * (TMP30 + TMP37)) -
                               3. * cI * (TMP9 * V1[2]))) +
                         (TMP25 * (P1[0] * 6. * (-cI * (TMP16) + cI * (TMP9)) +
                                   6. * (P2[0] * (+cI * (TMP16 + TMP9)))) +
                          3. * (V2[2] * (-cI * (TMP9 * TMP30) +
                                         cI * (TMP16 * TMP37))))) +
                    (TMP9 *
                         (TMP30 * (P1[0] * -6. * (+cI * (TMP26 + TMP38)) +
                                   3. * (P2[0] *
                                         (-cI * (TMP38) + 2. * cI * (TMP26)))) +
                          TMP16 * (TMP25 * 6. * (-cI * (P2[0]) + cI * (P1[0])) +
                                   3. * cI * (V1[2] * TMP38))) +
                     3. * (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0])))))) +
              (TMP12 * (TMP9 * (TMP25 * -1. *
                                    (-2. * cI * (TMP16) + cI * (TMP9 + TMP12)) +
                                (TMP26 * (-2. * cI * (TMP30) + cI * (TMP37)) +
                                 cI * (TMP30 * TMP38))) +
                        (TMP12 * (TMP26 * (+cI * (TMP30 + TMP37)) -
                                  cI * (TMP16 * TMP25)) -
                         cI * (TMP16 * TMP37 * TMP38))) +
               TMP9 * (TMP9 * (TMP30 * (+cI * (TMP26 + TMP38)) -
                               cI * (TMP16 * TMP25)) -
                       cI * (TMP16 * TMP37 * TMP38)))) +
         (TMP16 *
              (TMP25 * (P1[0] * 3. * (-cI * (P1[0]) + 2. * cI * (P2[0])) +
                        (+1. / 1. * cI * (TMP46 + TMP47) -
                         2. / 1. * cI * (TMP16)-3. * cI * (P2[0] * P2[0]))) +
               (TMP37 * 1. / 1. *
                    (+cI * (TMP49)-3. / 1. * cI * (P2[0] * V2[2])) +
                (+2. / 1. * cI * (TMP26 * TMP30) +
                 TMP38 * 1. / 1. *
                     (+cI * (TMP48)-3. / 1. * cI * (P1[0] * V1[2]))))) +
          (TMP26 * (TMP30 * (P1[0] * 3. * (-2. * cI * (P2[0]) + cI * (P1[0])) +
                             (-1. / 1. * cI * (TMP46 + TMP47) +
                              3. * cI * (P2[0] * P2[0]))) +
                    (+1. / 1. *
                         (TMP12 *
                          (-cI * (TMP48) + 3. / 1. * cI * (P1[0] * V1[2]))) +
                     TMP37 * 1. / 1. *
                         (-cI * (TMP47) + 3. / 1. * cI * (P2[0] * P2[0])))) +
           (TMP9 * 1. / 1. *
                (TMP30 * (-cI * (TMP49) + 3. / 1. * cI * (P2[0] * V2[2])) +
                 1. / 1. *
                     (TMP25 * 1. / 1. *
                      (+cI * (TMP47)-3. / 1. * cI * (P2[0] * P2[0])))) +
            (+1. / 1. *
                 (TMP30 * TMP38 *
                  (-cI * (TMP46) + 3. / 1. * cI * (P1[0] * P1[0]))) +
             TMP12 * 1. / 1. * TMP25 *
                 (+cI * (TMP46)-3. / 1. * cI * (P1[0] * P1[0])))))));
    T3[6] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[1] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[3]) +
                                       P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[3] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[1] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                               cI * (V1[3] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[1] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[1] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[1] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[3] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[1] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[1] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[3] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[1] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[1] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[1] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[10] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[2] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[4]) +
                                       P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[4] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[2] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                               cI * (V1[4] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[2] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[2] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[4] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[4] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[2] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[2] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[14] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[3] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[1] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[3]) +
                                       P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[3] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[1] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                               cI * (V1[3] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[1] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[1] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[1] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[3] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[1] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[1] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[3] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[1] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[1] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[1] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[7] =
        denom * 1. / 3. *
        (OM3 *
             (P3[1] *
                  (P3[1] *
                       (OM3 * (TMP12 * (TMP9 * (TMP25 * -2. *
                                                    (-2. * cI * (TMP16) +
                                                     cI * (TMP9 + TMP12)) +
                                                (TMP26 * 2. *
                                                     (-2. * cI * (TMP30) +
                                                      cI * (TMP37)) +
                                                 2. * cI * (TMP30 * TMP38))) +
                                        (TMP12 * (TMP26 * 2. *
                                                      (+cI * (TMP30 + TMP37)) -
                                                  2. * cI * (TMP16 * TMP25)) -
                                         2. * cI * (TMP16 * TMP37 * TMP38))) +
                               TMP9 * (TMP9 * (TMP30 * 2. *
                                                   (+cI * (TMP26 + TMP38)) -
                                               2. * cI * (TMP16 * TMP25)) -
                                       2. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. * cI * (TMP26 * TMP30) -
                               cI * (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * (+cI * (TMP46 + TMP47)) +
                                   (+cI * (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           TMP30 * (+cI * (TMP38 * TMP46 + TMP9 * TMP49)))))) +
                   (TMP12 *
                        (TMP26 *
                             (P1[1] * 3. * (-cI * (TMP37) + 2. * cI * (TMP30)) +
                              (P2[1] * -6. * (+cI * (TMP30 + TMP37)) -
                               3. * cI * (TMP9 * V1[3]))) +
                         (TMP25 * (P1[1] * 6. * (-cI * (TMP16) + cI * (TMP9)) +
                                   6. * (P2[1] * (+cI * (TMP16 + TMP9)))) +
                          3. * (V2[3] * (-cI * (TMP9 * TMP30) +
                                         cI * (TMP16 * TMP37))))) +
                    (TMP9 *
                         (TMP30 * (P1[1] * -6. * (+cI * (TMP26 + TMP38)) +
                                   3. * (P2[1] *
                                         (-cI * (TMP38) + 2. * cI * (TMP26)))) +
                          TMP16 * (TMP25 * 6. * (-cI * (P2[1]) + cI * (P1[1])) +
                                   3. * cI * (V1[3] * TMP38))) +
                     3. * (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1])))))) +
              (TMP12 *
                   (TMP9 * (TMP25 * (-2. * cI * (TMP16) + cI * (TMP9 + TMP12)) +
                            (TMP26 * (-cI * (TMP37) + 2. * cI * (TMP30)) -
                             cI * (TMP30 * TMP38))) +
                    (TMP12 * (TMP26 * -1. * (+cI * (TMP30 + TMP37)) +
                              cI * (TMP16 * TMP25)) +
                     cI * (TMP16 * TMP37 * TMP38))) +
               TMP9 * (TMP9 * (TMP30 * -1. * (+cI * (TMP26 + TMP38)) +
                               cI * (TMP16 * TMP25)) +
                       cI * (TMP16 * TMP37 * TMP38)))) +
         (TMP16 *
              (TMP25 * (P1[1] * 3. * (-cI * (P1[1]) + 2. * cI * (P2[1])) +
                        (-1. / 1. * cI * (TMP46 + TMP47) +
                         2. / 1. * cI * (TMP16)-3. * cI * (P2[1] * P2[1]))) +
               (TMP37 * -1. / 1. *
                    (+cI * (TMP49) + 3. / 1. * cI * (P2[1] * V2[3])) +
                (-2. / 1. * cI * (TMP26 * TMP30) +
                 TMP38 * -1. / 1. *
                     (+cI * (TMP48) + 3. / 1. * cI * (P1[1] * V1[3]))))) +
          (TMP26 * (TMP30 * (P1[1] * 3. * (-2. * cI * (P2[1]) + cI * (P1[1])) +
                             (+1. / 1. * cI * (TMP46 + TMP47) +
                              3. * cI * (P2[1] * P2[1]))) +
                    (+1. / 1. *
                         (TMP12 *
                          (+cI * (TMP48) + 3. / 1. * cI * (P1[1] * V1[3]))) +
                     TMP37 * 1. / 1. *
                         (+cI * (TMP47) + 3. / 1. * cI * (P2[1] * P2[1])))) +
           (TMP9 * 1. / 1. *
                (TMP30 * (+cI * (TMP49) + 3. / 1. * cI * (P2[1] * V2[3])) +
                 1. / 1. *
                     (TMP25 * -1. / 1. *
                      (+cI * (TMP47) + 3. / 1. * cI * (P2[1] * P2[1])))) +
            (+1. / 1. *
                 (TMP30 * TMP38 *
                  (+cI * (TMP46) + 3. / 1. * cI * (P1[1] * P1[1]))) +
             TMP12 * -1. / 1. * TMP25 *
                 (+cI * (TMP46) + 3. / 1. * cI * (P1[1] * P1[1])))))));
    T3[11] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[2] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[4]) +
                                       P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[4] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[2] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                               cI * (V1[4] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[2] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[2] *
                  (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[3]) +
                                      P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[3] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[1] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                              cI * (V1[3] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[1] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[1] *
              (P1[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[4] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[1] *
               (P2[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[4] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[2] * V2[3] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[2] * 1. / 2. * V1[3] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[15] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[3]) +
                                      P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[3] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[1] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                              cI * (V1[3] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[1] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[1] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[1] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[3] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[3] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[4] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[2] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[4]) +
                                       P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[4] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[2] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                               cI * (V1[4] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[2] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[2] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[4] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[4] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[2] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[2] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[8] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[2] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[4]) +
                                       P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[4] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[2] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                               cI * (V1[4] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[2] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[2] *
                  (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[3]) +
                                      P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[3] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[1] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                              cI * (V1[3] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[1] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[1] *
              (P1[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[4] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[1] *
               (P2[2] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[4] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[2] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[2] * V2[3] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[2] * 1. / 2. * V1[3] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[12] =
        denom * 1. / 3. *
        (OM3 *
             (P3[2] *
                  (P3[2] *
                       (OM3 * (TMP12 * (TMP9 * (TMP25 * -2. *
                                                    (-2. * cI * (TMP16) +
                                                     cI * (TMP9 + TMP12)) +
                                                (TMP26 * 2. *
                                                     (-2. * cI * (TMP30) +
                                                      cI * (TMP37)) +
                                                 2. * cI * (TMP30 * TMP38))) +
                                        (TMP12 * (TMP26 * 2. *
                                                      (+cI * (TMP30 + TMP37)) -
                                                  2. * cI * (TMP16 * TMP25)) -
                                         2. * cI * (TMP16 * TMP37 * TMP38))) +
                               TMP9 * (TMP9 * (TMP30 * 2. *
                                                   (+cI * (TMP26 + TMP38)) -
                                               2. * cI * (TMP16 * TMP25)) -
                                       2. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. * cI * (TMP26 * TMP30) -
                               cI * (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * (+cI * (TMP46 + TMP47)) +
                                   (+cI * (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           TMP30 * (+cI * (TMP38 * TMP46 + TMP9 * TMP49)))))) +
                   (TMP12 *
                        (TMP26 *
                             (P1[2] * 3. * (-cI * (TMP37) + 2. * cI * (TMP30)) +
                              (P2[2] * -6. * (+cI * (TMP30 + TMP37)) -
                               3. * cI * (TMP9 * V1[4]))) +
                         (TMP25 * (P1[2] * 6. * (-cI * (TMP16) + cI * (TMP9)) +
                                   6. * (P2[2] * (+cI * (TMP16 + TMP9)))) +
                          3. * (V2[4] * (-cI * (TMP9 * TMP30) +
                                         cI * (TMP16 * TMP37))))) +
                    (TMP9 *
                         (TMP30 * (P1[2] * -6. * (+cI * (TMP26 + TMP38)) +
                                   3. * (P2[2] *
                                         (-cI * (TMP38) + 2. * cI * (TMP26)))) +
                          TMP16 * (TMP25 * 6. * (-cI * (P2[2]) + cI * (P1[2])) +
                                   3. * cI * (V1[4] * TMP38))) +
                     3. * (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2])))))) +
              (TMP12 *
                   (TMP9 * (TMP25 * (-2. * cI * (TMP16) + cI * (TMP9 + TMP12)) +
                            (TMP26 * (-cI * (TMP37) + 2. * cI * (TMP30)) -
                             cI * (TMP30 * TMP38))) +
                    (TMP12 * (TMP26 * -1. * (+cI * (TMP30 + TMP37)) +
                              cI * (TMP16 * TMP25)) +
                     cI * (TMP16 * TMP37 * TMP38))) +
               TMP9 * (TMP9 * (TMP30 * -1. * (+cI * (TMP26 + TMP38)) +
                               cI * (TMP16 * TMP25)) +
                       cI * (TMP16 * TMP37 * TMP38)))) +
         (TMP16 *
              (TMP25 * (P1[2] * 3. * (-cI * (P1[2]) + 2. * cI * (P2[2])) +
                        (-1. / 1. * cI * (TMP46 + TMP47) +
                         2. / 1. * cI * (TMP16)-3. * cI * (P2[2] * P2[2]))) +
               (TMP37 * -1. / 1. *
                    (+cI * (TMP49) + 3. / 1. * cI * (P2[2] * V2[4])) +
                (-2. / 1. * cI * (TMP26 * TMP30) +
                 TMP38 * -1. / 1. *
                     (+cI * (TMP48) + 3. / 1. * cI * (P1[2] * V1[4]))))) +
          (TMP26 * (TMP30 * (P1[2] * 3. * (-2. * cI * (P2[2]) + cI * (P1[2])) +
                             (+1. / 1. * cI * (TMP46 + TMP47) +
                              3. * cI * (P2[2] * P2[2]))) +
                    (+1. / 1. *
                         (TMP12 *
                          (+cI * (TMP48) + 3. / 1. * cI * (P1[2] * V1[4]))) +
                     TMP37 * 1. / 1. *
                         (+cI * (TMP47) + 3. / 1. * cI * (P2[2] * P2[2])))) +
           (TMP9 * 1. / 1. *
                (TMP30 * (+cI * (TMP49) + 3. / 1. * cI * (P2[2] * V2[4])) +
                 1. / 1. *
                     (TMP25 * -1. / 1. *
                      (+cI * (TMP47) + 3. / 1. * cI * (P2[2] * P2[2])))) +
            (+1. / 1. *
                 (TMP30 * TMP38 *
                  (+cI * (TMP46) + 3. / 1. * cI * (P1[2] * P1[2]))) +
             TMP12 * -1. / 1. * TMP25 *
                 (+cI * (TMP46) + 3. / 1. * cI * (P1[2] * P1[2])))))));
    T3[16] =
        denom *
        (OM3 *
             (P3[2] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[4]) +
                                      P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[4] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[2] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                              cI * (V1[4] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[2] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[2] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[2] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[4] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[4] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[5] =
        denom *
        (OM3 *
             (P3[0] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[0] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[2]) +
                                      P2[0] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[2] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[0] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[0] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[0] + P2[0]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[0]) + cI * (P1[0]))) +
                              cI * (V1[2] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[0] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[0] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[0] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[0] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[2] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[2] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[9] =
        denom *
        (OM3 *
             (P3[1] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[1] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[3]) +
                                      P2[1] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[3] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[1] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[1] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[1] + P2[1]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[1]) + cI * (P1[1]))) +
                              cI * (V1[3] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[1] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[1] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[1] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[1] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[3] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[3] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[13] =
        denom *
        (OM3 *
             (P3[2] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 *
                                            (TMP25 * -2. / 3. *
                                                 (-2. * cI * (TMP16) +
                                                  cI * (TMP9 + TMP12)) +
                                             (TMP26 * 4. / 3. *
                                                  (+1. / 2. * cI * (TMP37)-cI *
                                                   (TMP30)) +
                                              2. / 3. * cI * (TMP30 * TMP38))) +
                                        (TMP12 *
                                             (TMP26 * 2. / 3. *
                                                  (+cI * (TMP30 + TMP37)) -
                                              2. / 3. * cI * (TMP16 * TMP25)) -
                                         2. / 3. * cI *
                                             (TMP16 * TMP37 * TMP38))) +
                               TMP9 *
                                   (TMP9 * (TMP30 * 2. / 3. *
                                                (+cI * (TMP26 + TMP38)) -
                                            2. / 3. * cI * (TMP16 * TMP25)) -
                                    2. / 3. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. / 3. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. / 3. * cI * (TMP26 * TMP30) -
                               1. / 3. * cI *
                                   (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * 1. / 3. * (+cI * (TMP46 + TMP47)) +
                                   (+1. / 3. * cI *
                                    (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. / 3. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           1. / 3. *
                               (TMP30 *
                                (+cI * (TMP38 * TMP46 + TMP9 * TMP49))))))) +
                   (TMP12 * (TMP26 * (P1[3] * 1. / 2. *
                                          (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                      (-1. / 2. * cI * (TMP9 * V1[5]) +
                                       P2[3] * -1. * (+cI * (TMP30 + TMP37)))) +
                             (+1. / 2. *
                                  (V2[5] * (-cI * (TMP9 * TMP30) +
                                            cI * (TMP16 * TMP37))) +
                              TMP25 * (P1[3] * (-cI * (TMP16) + cI * (TMP9)) +
                                       P2[3] * (+cI * (TMP16 + TMP9))))) +
                    (+1. / 2. *
                         (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3]))) +
                     TMP9 * 1. / 2. *
                         (TMP16 *
                              (+2. * (TMP25 * (-cI * (P2[3]) + cI * (P1[3]))) +
                               cI * (V1[5] * TMP38)) +
                          2. * (TMP30 * 1. / 2. *
                                (P2[3] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                 2. * (P1[3] * -1. *
                                       (+cI * (TMP26 + TMP38))))))))) +
              P3[3] *
                  (TMP12 * (TMP26 * (P1[2] * 1. / 2. *
                                         (-cI * (TMP37) + 2. * cI * (TMP30)) +
                                     (-1. / 2. * cI * (TMP9 * V1[4]) +
                                      P2[2] * -1. * (+cI * (TMP30 + TMP37)))) +
                            (+1. / 2. *
                                 (V2[4] * (-cI * (TMP9 * TMP30) +
                                           cI * (TMP16 * TMP37))) +
                             TMP25 * (P1[2] * (-cI * (TMP16) + cI * (TMP9)) +
                                      P2[2] * (+cI * (TMP16 + TMP9))))) +
                   (+1. / 2. *
                        (TMP16 * TMP37 * TMP38 * (+cI * (P1[2] + P2[2]))) +
                    TMP9 * 1. / 2. *
                        (TMP16 *
                             (+2. * (TMP25 * (-cI * (P2[2]) + cI * (P1[2]))) +
                              cI * (V1[4] * TMP38)) +
                         2. * (TMP30 * 1. / 2. *
                               (P2[2] * (-cI * (TMP38) + 2. * cI * (TMP26)) +
                                2. * (P1[2] * -1. *
                                      (+cI * (TMP26 + TMP38))))))))) +
         (P1[2] *
              (P1[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP12)) +
                        TMP30 * (+cI * (TMP26 + TMP38))) +
               (+1. / 2. *
                    (V1[5] * (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))) +
                P2[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
          (P2[2] *
               (P2[3] * (TMP25 * -1. * (+cI * (TMP16 + TMP9)) +
                         TMP26 * (+cI * (TMP30 + TMP37))) +
                (+1. / 2. *
                     (V2[5] * (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
                 P1[3] * (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
           (+1. / 2. *
                (P2[3] * V2[4] *
                 (-cI * (TMP16 * TMP37) + cI * (TMP9 * TMP30))) +
            P1[3] * 1. / 2. * V1[4] *
                (-cI * (TMP16 * TMP38) + cI * (TMP12 * TMP26))))));
    T3[17] =
        denom * 1. / 3. *
        (OM3 *
             (P3[3] *
                  (P3[3] *
                       (OM3 * (TMP12 * (TMP9 * (TMP25 * -2. *
                                                    (-2. * cI * (TMP16) +
                                                     cI * (TMP9 + TMP12)) +
                                                (TMP26 * 2. *
                                                     (-2. * cI * (TMP30) +
                                                      cI * (TMP37)) +
                                                 2. * cI * (TMP30 * TMP38))) +
                                        (TMP12 * (TMP26 * 2. *
                                                      (+cI * (TMP30 + TMP37)) -
                                                  2. * cI * (TMP16 * TMP25)) -
                                         2. * cI * (TMP16 * TMP37 * TMP38))) +
                               TMP9 * (TMP9 * (TMP30 * 2. *
                                                   (+cI * (TMP26 + TMP38)) -
                                               2. * cI * (TMP16 * TMP25)) -
                                       2. * cI * (TMP16 * TMP37 * TMP38))) +
                        (TMP16 *
                             (TMP25 * -1. *
                                  (-2. * cI * (TMP16) + cI * (TMP46 + TMP47)) +
                              (-2. * cI * (TMP26 * TMP30) -
                               cI * (TMP38 * TMP48 + TMP37 * TMP49))) +
                         (TMP26 * (TMP30 * (+cI * (TMP46 + TMP47)) +
                                   (+cI * (TMP37 * TMP47 + TMP12 * TMP48))) +
                          (TMP25 * -1. *
                               (+cI * (TMP12 * TMP46 + TMP9 * TMP47)) +
                           TMP30 * (+cI * (TMP38 * TMP46 + TMP9 * TMP49)))))) +
                   (TMP12 *
                        (TMP26 *
                             (P1[3] * 3. * (-cI * (TMP37) + 2. * cI * (TMP30)) +
                              (P2[3] * -6. * (+cI * (TMP30 + TMP37)) -
                               3. * cI * (TMP9 * V1[5]))) +
                         (TMP25 * (P1[3] * 6. * (-cI * (TMP16) + cI * (TMP9)) +
                                   6. * (P2[3] * (+cI * (TMP16 + TMP9)))) +
                          3. * (V2[5] * (-cI * (TMP9 * TMP30) +
                                         cI * (TMP16 * TMP37))))) +
                    (TMP9 *
                         (TMP30 * (P1[3] * -6. * (+cI * (TMP26 + TMP38)) +
                                   3. * (P2[3] *
                                         (-cI * (TMP38) + 2. * cI * (TMP26)))) +
                          TMP16 * (TMP25 * 6. * (-cI * (P2[3]) + cI * (P1[3])) +
                                   3. * cI * (V1[5] * TMP38))) +
                     3. * (TMP16 * TMP37 * TMP38 * (+cI * (P1[3] + P2[3])))))) +
              (TMP12 *
                   (TMP9 * (TMP25 * (-2. * cI * (TMP16) + cI * (TMP9 + TMP12)) +
                            (TMP26 * (-cI * (TMP37) + 2. * cI * (TMP30)) -
                             cI * (TMP30 * TMP38))) +
                    (TMP12 * (TMP26 * -1. * (+cI * (TMP30 + TMP37)) +
                              cI * (TMP16 * TMP25)) +
                     cI * (TMP16 * TMP37 * TMP38))) +
               TMP9 * (TMP9 * (TMP30 * -1. * (+cI * (TMP26 + TMP38)) +
                               cI * (TMP16 * TMP25)) +
                       cI * (TMP16 * TMP37 * TMP38)))) +
         (TMP16 *
              (TMP25 * (P1[3] * 3. * (-cI * (P1[3]) + 2. * cI * (P2[3])) +
                        (-1. / 1. * cI * (TMP46 + TMP47) +
                         2. / 1. * cI * (TMP16)-3. * cI * (P2[3] * P2[3]))) +
               (TMP37 * -1. / 1. *
                    (+cI * (TMP49) + 3. / 1. * cI * (P2[3] * V2[5])) +
                (-2. / 1. * cI * (TMP26 * TMP30) +
                 TMP38 * -1. / 1. *
                     (+cI * (TMP48) + 3. / 1. * cI * (P1[3] * V1[5]))))) +
          (TMP26 * (TMP30 * (P1[3] * 3. * (-2. * cI * (P2[3]) + cI * (P1[3])) +
                             (+1. / 1. * cI * (TMP46 + TMP47) +
                              3. * cI * (P2[3] * P2[3]))) +
                    (+1. / 1. *
                         (TMP12 *
                          (+cI * (TMP48) + 3. / 1. * cI * (P1[3] * V1[5]))) +
                     TMP37 * 1. / 1. *
                         (+cI * (TMP47) + 3. / 1. * cI * (P2[3] * P2[3])))) +
           (TMP9 * 1. / 1. *
                (TMP30 * (+cI * (TMP49) + 3. / 1. * cI * (P2[3] * V2[5])) +
                 1. / 1. *
                     (TMP25 * -1. / 1. *
                      (+cI * (TMP47) + 3. / 1. * cI * (P2[3] * P2[3])))) +
            (+1. / 1. *
                 (TMP30 * TMP38 *
                  (+cI * (TMP46) + 3. / 1. * cI * (P1[3] * P1[3]))) +
             TMP12 * -1. / 1. * TMP25 *
                 (+cI * (TMP46) + 3. / 1. * cI * (P1[3] * P1[3])))))));
}

void VVT10_11_12_13_2_3_6_7_8_9_3(complex<double> V1[], complex<double> V2[],
                                  complex<double> COUP1, complex<double> COUP2,
                                  complex<double> COUP3, complex<double> COUP4,
                                  complex<double> COUP5, complex<double> COUP6,
                                  complex<double> COUP7, complex<double> COUP8,
                                  complex<double> COUP9, complex<double> COUP10,
                                  double M3, double W3, complex<double> T3[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    //   double P3[4];
    //   double P2[4];
    //   double OM3;
    //   double P1[4];
    complex<double> Ttmp[18];
    complex<double> denom;
    int i;
    VVT10_3(V1, V2, COUP1, M3, W3, T3);
    VVT11_3(V1, V2, COUP2, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT12_3(V1, V2, COUP3, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT13_3(V1, V2, COUP4, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT2_3(V1, V2, COUP5, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT3_3(V1, V2, COUP6, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT6_3(V1, V2, COUP7, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT7_3(V1, V2, COUP8, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT8_3(V1, V2, COUP9, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
    VVT9_3(V1, V2, COUP10, M3, W3, Ttmp);
    i = 2;
    while (i < 18) {
        T3[i] = T3[i] + Ttmp[i];
        i++;
    }
}

void FFV6_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
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
          M2 * (F1[4] * 2. * (V3[5] - V3[2]) +
                2. * (F1[5] * (V3[3] - cI * (V3[4]))))));
    F2[3] = denom * cI *
            (F1[2] * (P2[0] * (V3[3] + cI * (V3[4])) +
                      (P2[1] * -1. * (V3[2] + V3[5]) +
                       (P2[2] * -1. * (+cI * (V3[2] + V3[5])) +
                        P2[3] * (V3[3] + cI * (V3[4]))))) +
             (F1[3] * (P2[0] * (V3[2] - V3[5]) +
                       (P2[1] * (+cI * (V3[4]) - V3[3]) +
                        (P2[2] * -1. * (V3[4] + cI * (V3[3])) +
                         P2[3] * (V3[2] - V3[5])))) +
              M2 * (F1[4] * 2. * (V3[3] + cI * (V3[4])) -
                    2. * (F1[5] * (V3[2] + V3[5])))));
    F2[4] =
        denom * 2. * cI *
        (F1[4] * (P2[0] * (V3[5] - V3[2]) + (P2[1] * (V3[3] + cI * (V3[4])) +
                                             (P2[2] * (V3[4] - cI * (V3[3])) +
                                              P2[3] * (V3[5] - V3[2])))) +
         (+1. / 2. *
              (M2 * (F1[3] * (V3[3] - cI * (V3[4])) +
                     2. * (F1[2] * 1. / 2. * (V3[2] + V3[5])))) +
          F1[5] * (P2[0] * (V3[3] - cI * (V3[4])) +
                   (P2[1] * -1. * (V3[2] + V3[5]) +
                    (P2[2] * (+cI * (V3[2] + V3[5])) +
                     P2[3] * (V3[3] - cI * (V3[4])))))));
    F2[5] =
        denom * 2. * cI *
        (F1[4] * (P2[0] * (V3[3] + cI * (V3[4])) +
                  (P2[1] * (V3[5] - V3[2]) +
                   (P2[2] * (-cI * (V3[2]) + cI * (V3[5])) -
                    P2[3] * (V3[3] + cI * (V3[4]))))) +
         (+1. / 2. *
              (M2 * (F1[3] * (V3[2] - V3[5]) +
                     2. * (F1[2] * 1. / 2. * (V3[3] + cI * (V3[4]))))) +
          F1[5] *
              (P2[0] * -1. * (V3[2] + V3[5]) +
               (P2[1] * (V3[3] - cI * (V3[4])) +
                (P2[2] * (V3[4] + cI * (V3[3])) + P2[3] * (V3[2] + V3[5]))))));
}

void VVT12_1(complex<double> V2[], complex<double> T3[], complex<double> COUP,
             double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP34;
    double P1[4];
    complex<double> TMP36;
    double P2[4];
    complex<double> TMP16;
    complex<double> TMP15;
    complex<double> TMP26;
    complex<double> TMP32;
    complex<double> denom;
    complex<double> TMP13;
    complex<double> TMP29;
    double OM1;
    complex<double> TMP35;
    OM1 = 0.;
    if (M1 != 0.)
        OM1 = 1. / pow(M1, 2);
    P2[0] = V2[0].real();
    P2[1] = V2[1].real();
    P2[2] = V2[1].imag();
    P2[3] = V2[0].imag();
    V1[0] = +V2[0] + T3[0];
    V1[1] = +V2[1] + T3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP26 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP29 =
        (P1[0] * -1. *
             (T3[6] * V2[3] + T3[10] * V2[4] + T3[14] * V2[5] - T3[2] * V2[2]) +
         (P1[1] * (T3[7] * V2[3] + T3[11] * V2[4] + T3[15] * V2[5] -
                   T3[3] * V2[2]) +
          (P1[2] * (T3[8] * V2[3] + T3[12] * V2[4] + T3[16] * V2[5] -
                    T3[4] * V2[2]) +
           P1[3] * (T3[9] * V2[3] + T3[13] * V2[4] + T3[17] * V2[5] -
                    T3[5] * V2[2]))));
    TMP35 =
        (P1[0] * -1. *
             (T3[6] * V2[3] + T3[10] * V2[4] + T3[14] * V2[5] - T3[2] * V2[2]) +
         (P1[1] * (T3[7] * V2[3] + T3[11] * V2[4] + T3[15] * V2[5] -
                   T3[3] * V2[2]) +
          (P1[2] * (T3[8] * V2[3] + T3[12] * V2[4] + T3[16] * V2[5] -
                    T3[4] * V2[2]) +
           P1[3] * (T3[9] * V2[3] + T3[13] * V2[4] + T3[17] * V2[5] -
                    T3[5] * V2[2]))));
    TMP15 =
        (P1[0] * -1. *
             (P2[1] * T3[3] + P2[2] * T3[4] + P2[3] * T3[5] - P2[0] * T3[2]) +
         (P1[1] *
              (P2[1] * T3[7] + P2[2] * T3[8] + P2[3] * T3[9] - P2[0] * T3[6]) +
          (P1[2] * (P2[1] * T3[11] + P2[2] * T3[12] + P2[3] * T3[13] -
                    P2[0] * T3[10]) +
           P1[3] * (P2[1] * T3[15] + P2[2] * T3[16] + P2[3] * T3[17] -
                    P2[0] * T3[14]))));
    TMP32 =
        (P1[0] * -1. *
             (T3[3] * V2[3] + T3[4] * V2[4] + T3[5] * V2[5] - T3[2] * V2[2]) +
         (P1[1] *
              (T3[7] * V2[3] + T3[8] * V2[4] + T3[9] * V2[5] - T3[6] * V2[2]) +
          (P1[2] * (T3[11] * V2[3] + T3[12] * V2[4] + T3[13] * V2[5] -
                    T3[10] * V2[2]) +
           P1[3] * (T3[15] * V2[3] + T3[16] * V2[4] + T3[17] * V2[5] -
                    T3[14] * V2[2]))));
    TMP16 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP36 =
        (P1[0] * -1. *
             (T3[3] * V2[3] + T3[4] * V2[4] + T3[5] * V2[5] - T3[2] * V2[2]) +
         (P1[1] *
              (T3[7] * V2[3] + T3[8] * V2[4] + T3[9] * V2[5] - T3[6] * V2[2]) +
          (P1[2] * (T3[11] * V2[3] + T3[12] * V2[4] + T3[13] * V2[5] -
                    T3[10] * V2[2]) +
           P1[3] * (T3[15] * V2[3] + T3[16] * V2[4] + T3[17] * V2[5] -
                    T3[14] * V2[2]))));
    TMP13 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    TMP34 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] =
        denom *
        (TMP16 * (OM1 * P1[0] * (-cI * (TMP29 + TMP32) + cI * (TMP35 + TMP36)) +
                  (V2[3] * (+cI * (T3[6] + T3[3])) +
                   (V2[4] * (+cI * (T3[10] + T3[4])) +
                    (V2[5] * (+cI * (T3[14] + T3[5])) -
                     2. * cI * (T3[2] * V2[2]))))) +
         (TMP26 * (OM1 * P1[0] * (-cI * (TMP34) + cI * (TMP13)) +
                   (P2[1] * -1. * (+cI * (T3[3] + T3[6])) +
                    (P2[2] * -1. * (+cI * (T3[4] + T3[10])) +
                     (P2[3] * -1. * (+cI * (T3[5] + T3[14])) +
                      2. * cI * (P2[0] * T3[2]))))) +
          (P2[0] * (+cI * (TMP29 + TMP32)) - V2[2] * (+cI * (TMP13 + TMP15)))));
    V1[3] =
        denom *
        (TMP16 * (OM1 * P1[1] * (-cI * (TMP29 + TMP32) + cI * (TMP35 + TMP36)) +
                  (V2[2] * -1. * (+cI * (T3[3] + T3[6])) +
                   (V2[4] * (+cI * (T3[11] + T3[8])) +
                    (V2[5] * (+cI * (T3[15] + T3[9])) +
                     2. * cI * (T3[7] * V2[3]))))) +
         (TMP26 * (OM1 * P1[1] * (-cI * (TMP34) + cI * (TMP13)) +
                   (P2[0] * (+cI * (T3[6] + T3[3])) +
                    (P2[2] * -1. * (+cI * (T3[8] + T3[11])) +
                     (P2[3] * -1. * (+cI * (T3[9] + T3[15])) -
                      2. * cI * (P2[1] * T3[7]))))) +
          (P2[1] * (+cI * (TMP29 + TMP32)) - V2[3] * (+cI * (TMP13 + TMP15)))));
    V1[4] =
        denom *
        (TMP16 * (OM1 * P1[2] * (-cI * (TMP29 + TMP32) + cI * (TMP35 + TMP36)) +
                  (V2[2] * -1. * (+cI * (T3[4] + T3[10])) +
                   (V2[3] * (+cI * (T3[8] + T3[11])) +
                    (V2[5] * (+cI * (T3[16] + T3[13])) +
                     2. * cI * (T3[12] * V2[4]))))) +
         (TMP26 * (OM1 * P1[2] * (-cI * (TMP34) + cI * (TMP13)) +
                   (P2[0] * (+cI * (T3[10] + T3[4])) +
                    (P2[1] * -1. * (+cI * (T3[11] + T3[8])) +
                     (P2[3] * -1. * (+cI * (T3[13] + T3[16])) -
                      2. * cI * (P2[2] * T3[12]))))) +
          (P2[2] * (+cI * (TMP29 + TMP32)) - V2[4] * (+cI * (TMP13 + TMP15)))));
    V1[5] =
        denom *
        (TMP16 * (OM1 * P1[3] * (-cI * (TMP29 + TMP32) + cI * (TMP35 + TMP36)) +
                  (V2[2] * -1. * (+cI * (T3[5] + T3[14])) +
                   (V2[3] * (+cI * (T3[9] + T3[15])) +
                    (V2[4] * (+cI * (T3[13] + T3[16])) +
                     2. * cI * (T3[17] * V2[5]))))) +
         (TMP26 * (OM1 * P1[3] * (-cI * (TMP34) + cI * (TMP13)) +
                   (P2[0] * (+cI * (T3[14] + T3[5])) +
                    (P2[1] * -1. * (+cI * (T3[15] + T3[9])) +
                     (P2[2] * -1. * (+cI * (T3[16] + T3[13])) -
                      2. * cI * (P2[3] * T3[17]))))) +
          (P2[3] * (+cI * (TMP29 + TMP32)) - V2[5] * (+cI * (TMP13 + TMP15)))));
}

void FFV5_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
            complex<double> COUP, complex<double> &vertex)
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP0;
    TMP0 = (F1[2] * (F2[4] * (V3[2] + V3[5]) + F2[5] * (V3[3] + cI * (V3[4]))) +
            F1[3] * (F2[4] * (V3[3] - cI * (V3[4])) + F2[5] * (V3[2] - V3[5])));
    vertex = COUP * -cI * TMP0;
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
void FFV5_6_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex)
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> tmp;
    FFV5_0(F1, F2, V3, COUP1, vertex);
    FFV6_0(F1, F2, V3, COUP2, tmp);
    vertex = vertex + tmp;
}
void FFV5_8_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
              complex<double> COUP1, complex<double> COUP2,
              complex<double> &vertex)
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> tmp;
    FFV5_0(F1, F2, V3, COUP1, vertex);
    FFV8_0(F1, F2, V3, COUP2, tmp);
    vertex = vertex + tmp;
}

void VVT7_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    double P1[4];
    double P2[4];
    double P3[4];
    complex<double> TMP16;
    complex<double> denom;
    double OM3;
    complex<double> TMP25;
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
    TMP25 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP16 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP9 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP12 = (P2[0] * P3[0] - P2[1] * P3[1] - P2[2] * P3[2] - P2[3] * P3[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. * TMP25 *
        (OM3 * (P3[0] * (P3[0] * 1. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[0] * TMP9 + P1[0] * TMP12))) +
                1. / 3. * cI * (TMP9 * TMP12)) +
         (-1. / 3. * cI * (TMP16) + cI * (P1[0] * P2[0])));
    T3[6] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[1] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[1] * TMP9 + P1[1] * TMP12))) -
                P3[1] * (+cI * (P1[0] * TMP12 + P2[0] * TMP9))) +
         (+cI * (P1[0] * P2[1] + P1[1] * P2[0])));
    T3[10] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[2] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[2] * TMP9 + P1[2] * TMP12))) -
                P3[2] * (+cI * (P1[0] * TMP12 + P2[0] * TMP9))) +
         (+cI * (P1[0] * P2[2] + P1[2] * P2[0])));
    T3[14] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[3] * TMP9 + P1[3] * TMP12))) -
                P3[3] * (+cI * (P1[0] * TMP12 + P2[0] * TMP9))) +
         (+cI * (P1[0] * P2[3] + P1[3] * P2[0])));
    T3[3] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[1] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[1] * TMP12 + P2[1] * TMP9))) -
                P3[1] * (+cI * (P2[0] * TMP9 + P1[0] * TMP12))) +
         (+cI * (P1[1] * P2[0] + P1[0] * P2[1])));
    T3[7] =
        denom * 2. * TMP25 *
        (OM3 * (P3[1] * (P3[1] * 1. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[1] * TMP9 + P1[1] * TMP12))) -
                1. / 3. * cI * (TMP9 * TMP12)) +
         (+cI * (P1[1] * P2[1]) + 1. / 3. * cI * (TMP16)));
    T3[11] =
        denom * TMP25 *
        (OM3 * (P3[1] * (P3[2] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[2] * TMP9 + P1[2] * TMP12))) -
                P3[2] * (+cI * (P1[1] * TMP12 + P2[1] * TMP9))) +
         (+cI * (P1[1] * P2[2] + P1[2] * P2[1])));
    T3[15] =
        denom * TMP25 *
        (OM3 * (P3[1] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[3] * TMP9 + P1[3] * TMP12))) -
                P3[3] * (+cI * (P1[1] * TMP12 + P2[1] * TMP9))) +
         (+cI * (P1[1] * P2[3] + P1[3] * P2[1])));
    T3[4] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[2] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[2] * TMP12 + P2[2] * TMP9))) -
                P3[2] * (+cI * (P2[0] * TMP9 + P1[0] * TMP12))) +
         (+cI * (P1[2] * P2[0] + P1[0] * P2[2])));
    T3[8] =
        denom * TMP25 *
        (OM3 * (P3[1] * (P3[2] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[2] * TMP12 + P2[2] * TMP9))) -
                P3[2] * (+cI * (P2[1] * TMP9 + P1[1] * TMP12))) +
         (+cI * (P1[2] * P2[1] + P1[1] * P2[2])));
    T3[12] =
        denom * 2. * TMP25 *
        (OM3 * (P3[2] * (P3[2] * 1. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[2] * TMP9 + P1[2] * TMP12))) -
                1. / 3. * cI * (TMP9 * TMP12)) +
         (+cI * (P1[2] * P2[2]) + 1. / 3. * cI * (TMP16)));
    T3[16] =
        denom * TMP25 *
        (OM3 * (P3[2] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[3] * TMP9 + P1[3] * TMP12))) -
                P3[3] * (+cI * (P1[2] * TMP12 + P2[2] * TMP9))) +
         (+cI * (P1[2] * P2[3] + P1[3] * P2[2])));
    T3[5] =
        denom * TMP25 *
        (OM3 * (P3[0] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[3] * TMP12 + P2[3] * TMP9))) -
                P3[3] * (+cI * (P2[0] * TMP9 + P1[0] * TMP12))) +
         (+cI * (P1[3] * P2[0] + P1[0] * P2[3])));
    T3[9] =
        denom * TMP25 *
        (OM3 * (P3[1] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[3] * TMP12 + P2[3] * TMP9))) -
                P3[3] * (+cI * (P2[1] * TMP9 + P1[1] * TMP12))) +
         (+cI * (P1[3] * P2[1] + P1[1] * P2[3])));
    T3[13] =
        denom * TMP25 *
        (OM3 * (P3[2] * (P3[3] * 2. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P1[3] * TMP12 + P2[3] * TMP9))) -
                P3[3] * (+cI * (P2[2] * TMP9 + P1[2] * TMP12))) +
         (+cI * (P1[3] * P2[2] + P1[2] * P2[3])));
    T3[17] =
        denom * 2. * TMP25 *
        (OM3 * (P3[3] * (P3[3] * 1. / 3. *
                             (+cI * (TMP16) + 2. * cI * (OM3 * TMP9 * TMP12)) +
                         (-cI * (P2[3] * TMP9 + P1[3] * TMP12))) -
                1. / 3. * cI * (TMP9 * TMP12)) +
         (+cI * (P1[3] * P2[3]) + 1. / 3. * cI * (TMP16)));
}

void VVT11_1(complex<double> V2[], complex<double> T3[], complex<double> COUP,
             double M1, double W1, complex<double> V1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    complex<double> TMP36;
    complex<double> denom;
    double OM1;
    complex<double> TMP35;
    OM1 = 0.;
    if (M1 != 0.)
        OM1 = 1. / pow(M1, 2);
    V1[0] = +V2[0] + T3[0];
    V1[1] = +V2[1] + T3[1];
    P1[0] = -V1[0].real();
    P1[1] = -V1[1].real();
    P1[2] = -V1[1].imag();
    P1[3] = -V1[0].imag();
    TMP36 =
        (P1[0] * -1. *
             (T3[3] * V2[3] + T3[4] * V2[4] + T3[5] * V2[5] - T3[2] * V2[2]) +
         (P1[1] *
              (T3[7] * V2[3] + T3[8] * V2[4] + T3[9] * V2[5] - T3[6] * V2[2]) +
          (P1[2] * (T3[11] * V2[3] + T3[12] * V2[4] + T3[13] * V2[5] -
                    T3[10] * V2[2]) +
           P1[3] * (T3[15] * V2[3] + T3[16] * V2[4] + T3[17] * V2[5] -
                    T3[14] * V2[2]))));
    TMP35 =
        (P1[0] * -1. *
             (T3[6] * V2[3] + T3[10] * V2[4] + T3[14] * V2[5] - T3[2] * V2[2]) +
         (P1[1] * (T3[7] * V2[3] + T3[11] * V2[4] + T3[15] * V2[5] -
                   T3[3] * V2[2]) +
          (P1[2] * (T3[8] * V2[3] + T3[12] * V2[4] + T3[16] * V2[5] -
                    T3[4] * V2[2]) +
           P1[3] * (T3[9] * V2[3] + T3[13] * V2[4] + T3[17] * V2[5] -
                    T3[5] * V2[2]))));
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    V1[2] = denom * -cI *
            (OM1 * -P1[0] * (TMP35 + TMP36) +
             (V2[3] * -1. * (T3[6] + T3[3]) +
              (V2[4] * -1. * (T3[10] + T3[4]) +
               (V2[5] * -1. * (T3[14] + T3[5]) + 2. * (T3[2] * V2[2])))));
    V1[3] = denom * cI *
            (OM1 * P1[1] * (TMP35 + TMP36) +
             (V2[2] * -1. * (T3[3] + T3[6]) +
              (V2[4] * (T3[11] + T3[8]) +
               (V2[5] * (T3[15] + T3[9]) + 2. * (T3[7] * V2[3])))));
    V1[4] = denom * cI *
            (OM1 * P1[2] * (TMP35 + TMP36) +
             (V2[2] * -1. * (T3[4] + T3[10]) +
              (V2[3] * (T3[8] + T3[11]) +
               (V2[5] * (T3[16] + T3[13]) + 2. * (T3[12] * V2[4])))));
    V1[5] = denom * cI *
            (OM1 * P1[3] * (TMP35 + TMP36) +
             (V2[2] * -1. * (T3[5] + T3[14]) +
              (V2[3] * (T3[9] + T3[15]) +
               (V2[4] * (T3[13] + T3[16]) + 2. * (T3[17] * V2[5])))));
}

void FFT2_1(complex<double> F2[], complex<double> T3[], complex<double> COUP,
            double M1, double W1, complex<double> F1[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> denom;
    P2[0] = F2[0].real();
    P2[1] = F2[1].real();
    P2[2] = F2[1].imag();
    P2[3] = F2[0].imag();
    F1[0] = +F2[0] + T3[0];
    F1[1] = +F2[1] + T3[1];
    P1[0] = -F1[0].real();
    P1[1] = -F1[1].real();
    P1[2] = -F1[1].imag();
    P1[3] = -F1[0].imag();
    denom = COUP / (pow(P1[0], 2) - pow(P1[1], 2) - pow(P1[2], 2) -
                    pow(P1[3], 2) - M1 * (M1 - cI * W1));
    F1[2] =
        denom * -cI *
        (F2[3] *
             (P1[0] *
                  (P1[3] * (T3[9] + T3[15] - cI * (T3[10] + T3[4]) +
                            cI * (T3[13] + T3[16]) - T3[6] - T3[3]) +
                   (P1[1] * (T3[14] + T3[5] + 2. * (T3[7] + T3[2]) +
                             cI * (T3[11] + T3[8])) +
                    (P1[2] * (T3[8] + T3[11] + cI * (T3[14] + T3[5]) +
                              2. * cI * (T3[12] + T3[2])) +
                     (P1[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                       (P2[3] * -1. *
                            (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                        (P2[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                         P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
              (P1[1] * (P1[2] * -1. *
                            (T3[4] + T3[16] + T3[10] + T3[13] +
                             cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                        (P1[3] * (+2. * (T3[7]) + cI * (T3[11] + T3[8]) -
                                  2. * (T3[17]) - T3[5] - T3[14]) +
                         (P1[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P2[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                             P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
               (P1[2] *
                    (P1[3] * (T3[8] + T3[11] - cI * (T3[5] + T3[14]) -
                              2. * cI * (T3[17]) + 2. * cI * (T3[12])) +
                     (P1[2] * -1. * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                      (P2[1] * (+cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                       (P2[2] * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                        (P2[0] * -1. *
                             (+cI * (T3[14] + T3[5]) + 2. * cI * (T3[2])) +
                         P2[3] * (+cI * (T3[5] + T3[14]) +
                                  2. * cI * (T3[17]))))))) +
                P1[3] *
                    (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                        P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
         (F2[2] *
              (P1[0] * (P1[1] * (T3[15] + T3[9] + cI * (T3[10] + T3[4]) -
                                 2. * (T3[3] + T3[6])) +
                        (P1[2] * -1. *
                             (+2. * (T3[4] + T3[10]) + cI * (T3[6] + T3[3]) -
                              T3[16] - T3[13]) +
                         (P1[3] * 2. * (T3[17] + T3[2] - T3[5] - T3[14]) +
                          (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                           (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P2[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17]))))))))) +
               (P1[3] * (P1[1] * -1. *
                             (T3[3] + T3[6] + cI * (T3[13] + T3[16]) -
                              2. * (T3[9] + T3[15])) +
                         (P1[2] * (+2. * (T3[13] + T3[16]) +
                                   cI * (T3[9] + T3[15]) - T3[4] - T3[10]) +
                          (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                           (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                            (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                             (P2[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
                (P1[1] *
                     (P1[2] * 2. *
                          (T3[8] + T3[11] - cI * (T3[12]) + cI * (T3[7])) +
                      (P2[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                       (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                        (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P2[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) -
                          P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))) +
                 P1[2] *
                     (P2[0] * (T3[10] + T3[4] + cI * (T3[6] + T3[3])) +
                      (P2[3] * -1. * (T3[13] + T3[16] + cI * (T3[9] + T3[15])) +
                       (P1[2] * (+2. * (T3[12]) + cI * (T3[8] + T3[11])) +
                        (P2[1] * -1. * (T3[11] + T3[8] + 2. * cI * (T3[7])) -
                         P2[2] *
                             (+2. * (T3[12]) + cI * (T3[8] + T3[11]))))))))) +
          M1 *
              (F2[4] * (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                        (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                         (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (T3[14] * (P2[0] + P1[3] - P1[0] - P2[3]) +
                            (T3[5] * (P1[3] + P2[0] - P2[3] - P1[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))) +
               F2[5] *
                   (P1[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                    (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (T3[11] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
                        (T3[8] * (P1[2] - cI * (P2[1]) + cI * (P1[1]) - P2[2]) +
                         (T3[12] * 2. * (-cI * (P2[2]) + cI * (P1[2])) +
                          2. * (T3[7] * (P1[1] - P2[1]))))))))))));
    F1[3] =
        denom * cI *
        (F2[2] *
             (P1[0] *
                  (P1[3] * (+cI * (T3[13] + T3[10] + T3[16] + T3[4]) - T3[9] -
                            T3[6] - T3[15] - T3[3]) +
                   (P1[1] * (T3[14] + T3[5] + cI * (T3[11] + T3[8]) -
                             2. * (T3[7] + T3[2])) +
                    (P1[2] * -1. *
                         (T3[8] + T3[11] - 2. * cI * (T3[12] + T3[2]) +
                          cI * (T3[14] + T3[5])) +
                     (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                       (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                        (P2[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
              (P1[1] * (P1[2] * (T3[4] + T3[10] - cI * (T3[3] + T3[6]) +
                                 cI * (T3[15] + T3[9]) - T3[16] - T3[13]) +
                        (P1[3] * (T3[5] + T3[14] + 2. * (T3[7]) -
                                  cI * (T3[11] + T3[8]) - 2. * (T3[17])) +
                         (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                           (P2[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                            (P2[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) -
                             P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
               (P1[2] *
                    (P1[3] * (T3[8] + T3[11] - cI * (T3[5] + T3[14]) -
                              2. * cI * (T3[12]) + 2. * cI * (T3[17])) +
                     (P1[2] *
                          (-cI * (T3[4] + T3[10]) + cI * (T3[16] + T3[13])) +
                      (P2[1] * (-cI * (T3[15] + T3[9]) + cI * (T3[3] + T3[6])) +
                       (P2[2] *
                            (-cI * (T3[16] + T3[13]) + cI * (T3[4] + T3[10])) +
                        (P2[0] * (-2. * cI * (T3[2]) + cI * (T3[14] + T3[5])) +
                         P2[3] * (-2. * cI * (T3[17]) +
                                  cI * (T3[5] + T3[14]))))))) +
                P1[3] *
                    (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                     (P2[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (P2[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) -
                        P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
         (F2[3] *
              (P1[0] * (P1[1] * (T3[15] + T3[9] + 2. * (T3[3] + T3[6]) +
                                 cI * (T3[10] + T3[4])) +
                        (P1[2] * (T3[16] + T3[13] + 2. * (T3[4] + T3[10]) -
                                  cI * (T3[6] + T3[3])) +
                         (P1[3] * 2. * (T3[5] + T3[17] + T3[2] + T3[14]) +
                          (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P2[0] * (T3[14] + T3[5] + 2. * (T3[2])) -
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17]))))))))) +
               (P1[3] * (P1[1] * -1. *
                             (T3[3] + T3[6] + 2. * (T3[9] + T3[15]) +
                              cI * (T3[13] + T3[16])) +
                         (P1[2] * -1. *
                              (T3[4] + T3[10] - cI * (T3[9] + T3[15]) +
                               2. * (T3[13] + T3[16])) +
                          (P2[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[3] * -1. * (T3[5] + T3[14] + 2. * (T3[17])) +
                             (P2[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
                (P1[1] *
                     (P1[2] * -2. *
                          (T3[8] + T3[11] - cI * (T3[7]) + cI * (T3[12])) +
                      (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                       (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                        (P1[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                         (P2[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                          P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))) +
                 P1[2] * (P2[0] * (+cI * (T3[6] + T3[3]) - T3[10] - T3[4]) +
                          (P2[3] * (T3[13] + T3[16] - cI * (T3[9] + T3[15])) +
                           (P1[2] * (+cI * (T3[8] + T3[11]) - 2. * (T3[12])) +
                            (P2[1] * (T3[11] + T3[8] - 2. * cI * (T3[7])) -
                             P2[2] * (+cI * (T3[8] + T3[11]) -
                                      2. * (T3[12]))))))))) +
          M1 *
              (F2[4] *
                   (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                    (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                     (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P2[2]) + cI * (P1[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))) +
               F2[5] * (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                        (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                         (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                           (T3[14] * (P2[0] + P2[3] - P1[0] - P1[3]) +
                            (T3[5] * (P2[3] + P2[0] - P1[3] - P1[0]) +
                             (T3[2] * 2. * (P1[0] - P2[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))))));
    F1[4] =
        denom * -cI *
        (F2[5] *
             (P1[0] *
                  (P1[3] * -1. *
                       (T3[9] + T3[6] + T3[15] + T3[3] +
                        cI * (T3[13] + T3[10] + T3[16] + T3[4])) +
                   (P1[1] * -1. *
                        (+2. * (T3[7] + T3[2]) + cI * (T3[11] + T3[8]) -
                         T3[14] - T3[5]) +
                    (P1[2] * -1. *
                         (T3[8] + T3[11] - cI * (T3[14] + T3[5]) +
                          2. * cI * (T3[12] + T3[2])) +
                     (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                       (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                        (P2[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                         P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
              (P1[1] * (P1[2] * (T3[4] + T3[10] - cI * (T3[15] + T3[9]) +
                                 cI * (T3[3] + T3[6]) - T3[16] - T3[13]) +
                        (P1[3] * (T3[5] + T3[14] + 2. * (T3[7]) +
                                  cI * (T3[11] + T3[8]) - 2. * (T3[17])) +
                         (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                           (P2[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                            (P2[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) -
                             P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
               (P1[2] *
                    (P1[3] * (T3[8] + T3[11] - 2. * cI * (T3[17]) +
                              cI * (T3[5] + T3[14]) + 2. * cI * (T3[12])) +
                     (P1[2] *
                          (-cI * (T3[16] + T3[13]) + cI * (T3[4] + T3[10])) +
                      (P2[1] * (-cI * (T3[3] + T3[6]) + cI * (T3[15] + T3[9])) +
                       (P2[2] *
                            (-cI * (T3[4] + T3[10]) + cI * (T3[16] + T3[13])) +
                        (P2[0] * -1. *
                             (-2. * cI * (T3[2]) + cI * (T3[14] + T3[5])) -
                         P2[3] * (-2. * cI * (T3[17]) +
                                  cI * (T3[5] + T3[14]))))))) +
                P1[3] *
                    (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                        P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
         (F2[4] *
              (P1[0] * (P1[1] * -1. *
                            (T3[15] + T3[9] + 2. * (T3[3] + T3[6]) -
                             cI * (T3[10] + T3[4])) +
                        (P1[2] * -1. *
                             (T3[16] + T3[13] + 2. * (T3[4] + T3[10]) +
                              cI * (T3[6] + T3[3])) +
                         (P1[3] * -2. * (T3[5] + T3[17] + T3[2] + T3[14]) +
                          (P2[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[0] * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P2[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17]))))))))) +
               (P1[3] * (P1[1] * (T3[3] + T3[6] + 2. * (T3[9] + T3[15]) -
                                  cI * (T3[13] + T3[16])) +
                         (P1[2] * (T3[4] + T3[10] + 2. * (T3[13] + T3[16]) +
                                   cI * (T3[9] + T3[15])) +
                          (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[3] * (T3[5] + T3[14] + 2. * (T3[17])) +
                             (P2[0] * (T3[14] + T3[5] + 2. * (T3[2])) -
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
                (P1[1] *
                     (P1[2] * 2. *
                          (T3[8] + T3[11] - cI * (T3[12]) + cI * (T3[7])) +
                      (P2[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                       (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                        (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P2[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) -
                          P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))) +
                 P1[2] *
                     (P2[0] * (T3[10] + T3[4] + cI * (T3[6] + T3[3])) +
                      (P2[3] * -1. * (T3[13] + T3[16] + cI * (T3[9] + T3[15])) +
                       (P1[2] * (+2. * (T3[12]) + cI * (T3[8] + T3[11])) +
                        (P2[1] * -1. * (T3[11] + T3[8] + 2. * cI * (T3[7])) -
                         P2[2] *
                             (+2. * (T3[12]) + cI * (T3[8] + T3[11]))))))))) +
          M1 *
              (F2[2] * (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                        (P1[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                         (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                          (P2[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                           (T3[14] * (P1[0] + P1[3] - P2[0] - P2[3]) +
                            (T3[5] * (P1[3] + P1[0] - P2[3] - P2[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P2[3] - P1[3]))))))))) +
               F2[3] *
                   (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                    (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P1[2]) + cI * (P2[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))))));
    F1[5] =
        denom * -cI *
        (F2[4] *
             (P1[0] *
                  (P1[3] * (T3[6] + T3[3] - cI * (T3[10] + T3[4]) +
                            cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                   (P1[1] * -1. *
                        (T3[14] + T3[5] + 2. * (T3[7] + T3[2]) -
                         cI * (T3[11] + T3[8])) +
                    (P1[2] * (+cI * (T3[14] + T3[5]) +
                              2. * cI * (T3[12] + T3[2]) - T3[8] - T3[11]) +
                     (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                       (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                        (P2[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
              (P1[1] * (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13] -
                                 cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                        (P1[3] * (T3[5] + T3[14] + 2. * (T3[17]) +
                                  cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P2[0] * (T3[14] + T3[5] + 2. * (T3[2])) -
                             P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
               (P1[2] *
                    (P1[3] * -1. *
                         (T3[8] + T3[11] - 2. * cI * (T3[12]) +
                          cI * (T3[5] + T3[14]) + 2. * cI * (T3[17])) +
                     (P1[2] * -1. * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                      (P2[1] * (+cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                       (P2[2] * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                        (P2[0] * -1. *
                             (+cI * (T3[14] + T3[5]) + 2. * cI * (T3[2])) +
                         P2[3] * (+cI * (T3[5] + T3[14]) +
                                  2. * cI * (T3[17]))))))) +
                P1[3] *
                    (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                     (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (P2[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                        P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
         (F2[5] *
              (P1[0] * (P1[1] * -1. *
                            (+2. * (T3[3] + T3[6]) + cI * (T3[10] + T3[4]) -
                             T3[15] - T3[9]) +
                        (P1[2] * (T3[16] + T3[13] + cI * (T3[6] + T3[3]) -
                                  2. * (T3[4] + T3[10])) +
                         (P1[3] * 2. * (T3[17] + T3[2] - T3[5] - T3[14]) +
                          (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                           (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P2[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17]))))))))) +
               (P1[3] * (P1[1] * (+2. * (T3[9] + T3[15]) +
                                  cI * (T3[13] + T3[16]) - T3[3] - T3[6]) +
                         (P1[2] * -1. *
                              (T3[4] + T3[10] + cI * (T3[9] + T3[15]) -
                               2. * (T3[13] + T3[16])) +
                          (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                           (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                            (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                             (P2[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
                (P1[1] *
                     (P1[2] * 2. *
                          (T3[8] + T3[11] - cI * (T3[7]) + cI * (T3[12])) +
                      (P2[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                       (P2[3] * -1. *
                            (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                        (P1[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                         (P2[1] * -1. *
                              (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                          P2[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))) +
                 P1[2] *
                     (P2[0] * (T3[10] + T3[4] - cI * (T3[6] + T3[3])) +
                      (P2[3] * (+cI * (T3[9] + T3[15]) - T3[13] - T3[16]) +
                       (P1[2] * -1. * (+cI * (T3[8] + T3[11]) - 2. * (T3[12])) +
                        (P2[1] * -1. * (T3[11] + T3[8] - 2. * cI * (T3[7])) +
                         P2[2] *
                             (+cI * (T3[8] + T3[11]) - 2. * (T3[12]))))))))) +
          M1 *
              (F2[2] *
                   (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                    (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                     (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P2[2]) + cI * (P1[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))) +
               F2[3] * (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                        (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                         (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (T3[14] * (P2[0] + P1[3] - P1[0] - P2[3]) +
                            (T3[5] * (P1[3] + P2[0] - P2[3] - P1[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))))));
}

void VVT8_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    double P1[4];
    double P2[4];
    double P3[4];
    complex<double> TMP16;
    complex<double> TMP30;
    complex<double> denom;
    complex<double> TMP26;
    complex<double> TMP25;
    complex<double> TMP9;
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
    TMP25 = (V2[2] * V1[2] - V2[3] * V1[3] - V2[4] * V1[4] - V2[5] * V1[5]);
    TMP26 = (P1[0] * V2[2] - P1[1] * V2[3] - P1[2] * V2[4] - P1[3] * V2[5]);
    TMP16 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP9 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP30 = (P2[0] * V1[2] - P2[1] * V1[3] - P2[2] * V1[4] - P2[3] * V1[5]);
    TMP12 = (P2[0] * P3[0] - P2[1] * P3[1] - P2[2] * P3[2] - P2[3] * P3[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[0] * -1. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[0] * TMP9 + P1[0] * TMP12))) +
                              1. / 3. * cI * (P3[0] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[0]) +
                                   2. / 3. * cI * (P3[0] * OM3 * TMP9)) -
                          cI * (P2[0] * TMP9))) +
                1. / 3. *
                    (TMP12 * TMP9 *
                     (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)))) +
         (TMP16 * (TMP25 * (-cI * (P1[0] * P2[0]) + 1. / 3. * cI * (TMP16)) -
                   1. / 3. * cI * (TMP26 * TMP30)) +
          cI * (P1[0] * P2[0] * TMP26 * TMP30)));
    T3[6] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[1] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[1] * TMP9 + P1[1] * TMP12))) +
                              2. / 3. * cI * (P3[1] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[1]) +
                                   4. / 3. * cI * (P3[1] * OM3 * TMP9)) -
                          cI * (P2[1] * TMP9))) +
                P3[1] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[1] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[10] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[2] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[2] * TMP9 + P1[2] * TMP12))) +
                              2. / 3. * cI * (P3[2] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[2]) +
                                   4. / 3. * cI * (P3[2] * OM3 * TMP9)) -
                          cI * (P2[2] * TMP9))) +
                P3[2] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[2] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[14] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[3] * TMP9 + P1[3] * TMP12))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[3] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[1] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[1] * TMP12 + P2[1] * TMP9))) +
                              2. / 3. * cI * (P3[1] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[1]) +
                                   4. / 3. * cI * (P3[1] * OM3 * TMP9)) -
                          cI * (P2[1] * TMP9))) +
                P3[1] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[1] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[7] =
        denom * 2. *
        (OM3 * (P3[1] *
                    (TMP16 * (TMP25 * (P3[1] * -1. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[1] * TMP9 + P1[1] * TMP12))) +
                              1. / 3. * cI * (P3[1] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[1]) +
                                   2. / 3. * cI * (P3[1] * OM3 * TMP9)) -
                          cI * (P2[1] * TMP9))) +
                1. / 3. *
                    (TMP12 * TMP9 *
                     (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (TMP16 *
              (TMP25 * -1. * (+cI * (P1[1] * P2[1]) + 1. / 3. * cI * (TMP16)) +
               1. / 3. * cI * (TMP26 * TMP30)) +
          cI * (P1[1] * P2[1] * TMP26 * TMP30)));
    T3[11] =
        denom *
        (OM3 * (P3[1] *
                    (TMP16 * (TMP25 * (P3[2] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[2] * TMP9 + P1[2] * TMP12))) +
                              2. / 3. * cI * (P3[2] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[2]) +
                                   4. / 3. * cI * (P3[2] * OM3 * TMP9)) -
                          cI * (P2[2] * TMP9))) +
                P3[2] * (P1[1] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[1] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[1] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[2] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[15] =
        denom *
        (OM3 * (P3[1] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[3] * TMP9 + P1[3] * TMP12))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[1] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[1] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[1] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[4] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[2] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[2] * TMP12 + P2[2] * TMP9))) +
                              2. / 3. * cI * (P3[2] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[2]) +
                                   4. / 3. * cI * (P3[2] * OM3 * TMP9)) -
                          cI * (P2[2] * TMP9))) +
                P3[2] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[2] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[8] =
        denom *
        (OM3 * (P3[1] *
                    (TMP16 * (TMP25 * (P3[2] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[2] * TMP12 + P2[2] * TMP9))) +
                              2. / 3. * cI * (P3[2] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[2]) +
                                   4. / 3. * cI * (P3[2] * OM3 * TMP9)) -
                          cI * (P2[2] * TMP9))) +
                P3[2] * (P1[1] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[1] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[1] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[2] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[12] =
        denom * 2. *
        (OM3 * (P3[2] *
                    (TMP16 * (TMP25 * (P3[2] * -1. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[2] * TMP9 + P1[2] * TMP12))) +
                              1. / 3. * cI * (P3[2] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[2]) +
                                   2. / 3. * cI * (P3[2] * OM3 * TMP9)) -
                          cI * (P2[2] * TMP9))) +
                1. / 3. *
                    (TMP12 * TMP9 *
                     (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (TMP16 *
              (TMP25 * -1. * (+cI * (P1[2] * P2[2]) + 1. / 3. * cI * (TMP16)) +
               1. / 3. * cI * (TMP26 * TMP30)) +
          cI * (P1[2] * P2[2] * TMP26 * TMP30)));
    T3[16] =
        denom *
        (OM3 * (P3[2] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[3] * TMP9 + P1[3] * TMP12))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[2] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[2] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[2] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[5] =
        denom *
        (OM3 * (P3[0] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[3] * TMP12 + P2[3] * TMP9))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[0] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[0] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[0] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[0] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[9] =
        denom *
        (OM3 * (P3[1] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[3] * TMP12 + P2[3] * TMP9))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[1] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[1] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[1] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[1] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[13] =
        denom *
        (OM3 * (P3[2] *
                    (TMP16 * (TMP25 * (P3[3] * -2. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P1[3] * TMP12 + P2[3] * TMP9))) +
                              2. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   4. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                P3[3] * (P1[2] * TMP12 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)) +
                         P2[2] * TMP9 *
                             (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (P1[2] * P2[3] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30)) +
          P1[3] * P2[2] * (-cI * (TMP16 * TMP25) + cI * (TMP26 * TMP30))));
    T3[17] =
        denom * 2. *
        (OM3 * (P3[3] *
                    (TMP16 * (TMP25 * (P3[3] * -1. / 3. *
                                           (+cI * (TMP16) +
                                            2. * cI * (OM3 * TMP9 * TMP12)) +
                                       (+cI * (P2[3] * TMP9 + P1[3] * TMP12))) +
                              1. / 3. * cI * (P3[3] * TMP26 * TMP30)) +
                     TMP26 * TMP30 *
                         (TMP12 * (-cI * (P1[3]) +
                                   2. / 3. * cI * (P3[3] * OM3 * TMP9)) -
                          cI * (P2[3] * TMP9))) +
                1. / 3. *
                    (TMP12 * TMP9 *
                     (-cI * (TMP26 * TMP30) + cI * (TMP16 * TMP25)))) +
         (TMP16 *
              (TMP25 * -1. * (+cI * (P1[3] * P2[3]) + 1. / 3. * cI * (TMP16)) +
               1. / 3. * cI * (TMP26 * TMP30)) +
          cI * (P1[3] * P2[3] * TMP26 * TMP30)));
}

void FFV8_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
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
          M2 * (F1[4] * 4. * (V3[2] - V3[5]) +
                4. * (F1[5] * (+cI * (V3[4]) - V3[3])))));
    F2[3] = denom * cI *
            (F1[2] * (P2[0] * (V3[3] + cI * (V3[4])) +
                      (P2[1] * -1. * (V3[2] + V3[5]) +
                       (P2[2] * -1. * (+cI * (V3[2] + V3[5])) +
                        P2[3] * (V3[3] + cI * (V3[4]))))) +
             (F1[3] * (P2[0] * (V3[2] - V3[5]) +
                       (P2[1] * (+cI * (V3[4]) - V3[3]) +
                        (P2[2] * -1. * (V3[4] + cI * (V3[3])) +
                         P2[3] * (V3[2] - V3[5])))) +
              M2 * (F1[4] * -4. * (V3[3] + cI * (V3[4])) +
                    4. * (F1[5] * (V3[2] + V3[5])))));
    F2[4] =
        denom * -4. * cI *
        (F1[4] * (P2[0] * (V3[5] - V3[2]) + (P2[1] * (V3[3] + cI * (V3[4])) +
                                             (P2[2] * (V3[4] - cI * (V3[3])) +
                                              P2[3] * (V3[5] - V3[2])))) +
         (+1. / 4. *
              (M2 * (F1[3] * (+cI * (V3[4]) - V3[3]) +
                     4. * (F1[2] * -1. / 4. * (V3[2] + V3[5])))) +
          F1[5] * (P2[0] * (V3[3] - cI * (V3[4])) +
                   (P2[1] * -1. * (V3[2] + V3[5]) +
                    (P2[2] * (+cI * (V3[2] + V3[5])) +
                     P2[3] * (V3[3] - cI * (V3[4])))))));
    F2[5] =
        denom * -4. * cI *
        (F1[4] * (P2[0] * (V3[3] + cI * (V3[4])) +
                  (P2[1] * (V3[5] - V3[2]) +
                   (P2[2] * (-cI * (V3[2]) + cI * (V3[5])) -
                    P2[3] * (V3[3] + cI * (V3[4]))))) +
         (+1. / 4. *
              (M2 * (F1[3] * (V3[5] - V3[2]) +
                     4. * (F1[2] * -1. / 4. * (V3[3] + cI * (V3[4]))))) +
          F1[5] *
              (P2[0] * -1. * (V3[2] + V3[5]) +
               (P2[1] * (V3[3] - cI * (V3[4])) +
                (P2[2] * (V3[4] + cI * (V3[3])) + P2[3] * (V3[2] + V3[5]))))));
}

void VVT2_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    double P1[4];
    double P2[4];
    double P3[4];
    complex<double> TMP16;
    complex<double> TMP66;
    complex<double> denom;
    double OM3;
    complex<double> TMP65;
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
    TMP16 = (P1[0] * P2[0] - P1[1] * P2[1] - P1[2] * P2[2] - P1[3] * P2[3]);
    TMP9 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP65 = -1. * (P1[0] * (P2[1] * (V2[4] * V1[5] - V2[5] * V1[4]) +
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
    TMP66 = -1. * (P1[0] * (P2[1] * (V2[5] * V1[4] - V2[4] * V1[5]) +
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
    TMP12 = (P2[0] * P3[0] - P2[1] * P3[1] - P2[2] * P3[2] - P2[3] * P3[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] =
        denom * 2. *
        (OM3 *
             (P3[0] * (P3[0] * (OM3 * 2. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                1. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              1. / 3. * (TMP12 * TMP9 * (-cI * (TMP65) + cI * (TMP66)))) +
         (P1[0] * P2[0] * (-cI * (TMP65) + cI * (TMP66)) +
          1. / 3. * (TMP16 * (-cI * (TMP66) + cI * (TMP65)))));
    T3[6] =
        denom *
        (OM3 *
             (P3[0] * (P3[1] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[1] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[1] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[1] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[10] =
        denom *
        (OM3 *
             (P3[0] * (P3[2] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[2] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[2] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[2] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[14] =
        denom *
        (OM3 *
             (P3[0] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[3] =
        denom *
        (OM3 *
             (P3[0] * (P3[1] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[1] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[1] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[1] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[7] =
        denom * 2. *
        (OM3 *
             (P3[1] * (P3[1] * (OM3 * 2. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                1. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              1. / 3. * (TMP12 * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[1] * P2[1] * (-cI * (TMP65) + cI * (TMP66)) +
          1. / 3. * (TMP16 * (-cI * (TMP65) + cI * (TMP66)))));
    T3[11] =
        denom *
        (OM3 *
             (P3[1] * (P3[2] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[2] * (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[1] * P2[2] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[2] * P2[1] * (-cI * (TMP65) + cI * (TMP66))));
    T3[15] =
        denom *
        (OM3 *
             (P3[1] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[1] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[1] * (-cI * (TMP65) + cI * (TMP66))));
    T3[4] =
        denom *
        (OM3 *
             (P3[0] * (P3[2] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[2] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[2] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[2] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[8] =
        denom *
        (OM3 *
             (P3[1] * (P3[2] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[2] * (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[1] * P2[2] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[2] * P2[1] * (-cI * (TMP65) + cI * (TMP66))));
    T3[12] =
        denom * 2. *
        (OM3 *
             (P3[2] * (P3[2] * (OM3 * 2. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                1. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              1. / 3. * (TMP12 * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[2] * P2[2] * (-cI * (TMP65) + cI * (TMP66)) +
          1. / 3. * (TMP16 * (-cI * (TMP65) + cI * (TMP66)))));
    T3[16] =
        denom *
        (OM3 *
             (P3[2] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[2] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[2] * (-cI * (TMP65) + cI * (TMP66))));
    T3[5] =
        denom *
        (OM3 *
             (P3[0] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[0] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[0] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[0] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[0] * (-cI * (TMP65) + cI * (TMP66))));
    T3[9] =
        denom *
        (OM3 *
             (P3[1] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[1] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[1] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[1] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[1] * (-cI * (TMP65) + cI * (TMP66))));
    T3[13] =
        denom *
        (OM3 *
             (P3[2] * (P3[3] * (OM3 * 4. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                2. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              P3[3] * (P1[2] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                       P2[2] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[2] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          P1[3] * P2[2] * (-cI * (TMP65) + cI * (TMP66))));
    T3[17] =
        denom * 2. *
        (OM3 *
             (P3[3] * (P3[3] * (OM3 * 2. / 3. * TMP12 * TMP9 *
                                    (-cI * (TMP65) + cI * (TMP66)) +
                                1. / 3. *
                                    (TMP16 * (-cI * (TMP65) + cI * (TMP66)))) +
                       (P1[3] * TMP12 * (-cI * (TMP66) + cI * (TMP65)) +
                        P2[3] * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
              1. / 3. * (TMP12 * TMP9 * (-cI * (TMP66) + cI * (TMP65)))) +
         (P1[3] * P2[3] * (-cI * (TMP65) + cI * (TMP66)) +
          1. / 3. * (TMP16 * (-cI * (TMP65) + cI * (TMP66)))));
}

void VVT5_3(complex<double> V1[], complex<double> V2[], complex<double> COUP,
            double M3, double W3, complex<double> T3[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> TMP12;
    complex<double> TMP37;
    double P1[4];
    double P2[4];
    double P3[4];
    double OM3;
    complex<double> TMP54;
    complex<double> denom;
    complex<double> TMP53;
    complex<double> TMP9;
    complex<double> TMP38;
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
    TMP53 = -1. * (P1[0] * (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
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
    TMP54 = -1. * (P1[0] * (P2[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
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
    TMP38 = (P3[0] * V2[2] - P3[1] * V2[3] - P3[2] * V2[4] - P3[3] * V2[5]);
    TMP9 = (P1[0] * P3[0] - P1[1] * P3[1] - P1[2] * P3[2] - P1[3] * P3[3]);
    TMP37 = (P3[0] * V1[2] - P3[1] * V1[3] - P3[2] * V1[4] - P3[3] * V1[5]);
    TMP12 = (P2[0] * P3[0] - P2[1] * P3[1] - P2[2] * P3[2] - P2[3] * P3[3]);
    denom = COUP / (pow(P3[0], 2) - pow(P3[1], 2) - pow(P3[2], 2) -
                    pow(P3[3], 2) - M3 * (M3 - cI * W3));
    T3[2] = denom * -2. * cI *
            (TMP37 * (OM3 * P3[0] *
                          (TMP12 * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                                    (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                                     P1[3] * (P3[1] * V2[4] - P3[2] * V2[3]))) -
                           1. / 3. * (P3[0] * TMP54)) +
                      (P2[0] * (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       1. / 3. * (TMP54))) +
             TMP38 * (OM3 * P3[0] *
                          (TMP9 * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                                   (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                                    P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))) -
                           1. / 3. * (P3[0] * TMP53)) +
                      (P1[0] * (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                 P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))) +
                       1. / 3. * (TMP53))));
    T3[3] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                 (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                  P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                        2. / 3. * (P3[1] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                    (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                     P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                            2. / 3. * (P3[1] * TMP53))) +
              P3[1] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                   P2[1] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                   P1[1] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[4] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                  P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                        2. / 3. * (P3[2] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            2. / 3. * (P3[2] * TMP53))) +
              P3[2] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[5] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[6] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                 (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                  P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                        2. / 3. * (P3[1] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                    (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                     P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                            2. / 3. * (P3[1] * TMP53))) +
              P3[1] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                   P2[1] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                   P1[1] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[7] = denom * 2. * cI *
            (TMP37 * (OM3 * P3[1] *
                          (TMP12 * (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                                    (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                                     P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                           1. / 3. * (P3[1] * TMP54)) +
                      (P2[1] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                                (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                 P1[3] * (P3[0] * V2[4] - P3[2] * V2[2]))) +
                       1. / 3. * (TMP54))) +
             TMP38 * (OM3 * P3[1] *
                          (TMP9 * (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                                   (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                                    P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))) +
                           1. / 3. * (P3[1] * TMP53)) +
                      (P1[1] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                                (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                 P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))) +
                       1. / 3. * (TMP53))));
    T3[8] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                  P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                        2. / 3. * (P3[2] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            2. / 3. * (P3[2] * TMP53))) +
              P3[2] * (TMP12 * TMP37 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))))) +
         (TMP37 * (P2[1] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2])))) +
          TMP38 * (P1[1] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))))));
    T3[9] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))))) +
         (TMP37 * (P2[1] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2])))) +
          TMP38 * (P1[1] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))))));
    T3[10] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                  P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                        2. / 3. * (P3[2] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            2. / 3. * (P3[2] * TMP53))) +
              P3[2] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[11] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                 (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                  P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                        2. / 3. * (P3[2] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                                    (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                     P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                            2. / 3. * (P3[2] * TMP53))) +
              P3[2] * (TMP12 * TMP37 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))))) +
         (TMP37 * (P2[1] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   P2[2] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2])))) +
          TMP38 * (P1[1] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   P1[2] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))))));
    T3[12] =
        denom * 2. * cI *
        (TMP37 * (OM3 * P3[2] *
                      (TMP12 * (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                                (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                                 P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                       1. / 3. * (P3[2] * TMP54)) +
                  (P2[2] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                   1. / 3. * (TMP54))) +
         TMP38 * (OM3 * P3[2] *
                      (TMP9 * (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                               (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                                P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                       1. / 3. * (P3[2] * TMP53)) +
                  (P1[2] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                   1. / 3. * (TMP53))));
    T3[13] =
        denom * cI *
        (OM3 *
             (P3[2] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                            (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                            (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))))) +
         (TMP37 * (P2[2] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3])))) +
          TMP38 * (P1[2] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))))));
    T3[14] =
        denom * cI *
        (OM3 *
             (P3[0] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[1] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                             P1[3] * (P3[2] * V2[3] - P3[1] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[1] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                             P2[3] * (P3[2] * V1[3] - P3[1] * V1[4]))))) +
         (TMP37 * (P2[0] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[1] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                             P1[3] * (P3[1] * V2[4] - P3[2] * V2[3])))) +
          TMP38 * (P1[0] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[1] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                             P2[3] * (P3[1] * V1[4] - P3[2] * V1[3]))))));
    T3[15] =
        denom * cI *
        (OM3 *
             (P3[1] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[0] * (P3[3] * V2[4] - P3[2] * V2[5]) +
                            (P1[2] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[2] * V2[2] - P3[0] * V2[4]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[3] * V1[4] - P3[2] * V1[5]) +
                            (P2[2] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[2] * V1[2] - P3[0] * V1[4]))))) +
         (TMP37 * (P2[1] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[2] * V2[5] - P3[3] * V2[4]) +
                            (P1[2] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[4] - P3[2] * V2[2])))) +
          TMP38 * (P1[1] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[2] * V1[5] - P3[3] * V1[4]) +
                            (P2[2] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[4] - P3[2] * V1[2]))))));
    T3[16] =
        denom * cI *
        (OM3 *
             (P3[2] *
                  (TMP37 *
                       (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                 (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                  P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                        2. / 3. * (P3[3] * TMP54)) +
                   TMP38 * (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                                    (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                     P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                            2. / 3. * (P3[3] * TMP53))) +
              P3[3] * (TMP12 * TMP37 *
                           (P1[0] * (P3[1] * V2[5] - P3[3] * V2[3]) +
                            (P1[1] * (P3[3] * V2[2] - P3[0] * V2[5]) +
                             P1[3] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                       TMP38 * TMP9 *
                           (P2[0] * (P3[1] * V1[5] - P3[3] * V1[3]) +
                            (P2[1] * (P3[3] * V1[2] - P3[0] * V1[5]) +
                             P2[3] * (P3[0] * V1[3] - P3[1] * V1[2]))))) +
         (TMP37 * (P2[2] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   P2[3] * (P1[0] * (P3[3] * V2[3] - P3[1] * V2[5]) +
                            (P1[1] * (P3[0] * V2[5] - P3[3] * V2[2]) +
                             P1[3] * (P3[1] * V2[2] - P3[0] * V2[3])))) +
          TMP38 * (P1[2] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   P1[3] * (P2[0] * (P3[3] * V1[3] - P3[1] * V1[5]) +
                            (P2[1] * (P3[0] * V1[5] - P3[3] * V1[2]) +
                             P2[3] * (P3[1] * V1[2] - P3[0] * V1[3]))))));
    T3[17] =
        denom * 2. * cI *
        (TMP37 * (OM3 * P3[3] *
                      (TMP12 * (P1[0] * (P3[2] * V2[3] - P3[1] * V2[4]) +
                                (P1[1] * (P3[0] * V2[4] - P3[2] * V2[2]) +
                                 P1[2] * (P3[1] * V2[2] - P3[0] * V2[3]))) +
                       1. / 3. * (P3[3] * TMP54)) +
                  (P2[3] * (P1[0] * (P3[1] * V2[4] - P3[2] * V2[3]) +
                            (P1[1] * (P3[2] * V2[2] - P3[0] * V2[4]) +
                             P1[2] * (P3[0] * V2[3] - P3[1] * V2[2]))) +
                   1. / 3. * (TMP54))) +
         TMP38 * (OM3 * P3[3] *
                      (TMP9 * (P2[0] * (P3[2] * V1[3] - P3[1] * V1[4]) +
                               (P2[1] * (P3[0] * V1[4] - P3[2] * V1[2]) +
                                P2[2] * (P3[1] * V1[2] - P3[0] * V1[3]))) +
                       1. / 3. * (P3[3] * TMP53)) +
                  (P1[3] * (P2[0] * (P3[1] * V1[4] - P3[2] * V1[3]) +
                            (P2[1] * (P3[2] * V1[2] - P3[0] * V1[4]) +
                             P2[2] * (P3[0] * V1[3] - P3[1] * V1[2]))) +
                   1. / 3. * (TMP53))));
}

void FFT1_2(complex<double> F1[], complex<double> T3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[])
{
    complex<double> cI = complex<double>(0., 1.);
    complex<double> denom;
    double P1[4];
    double P2[4];
    complex<double> TMP15;
    complex<double> TMP13;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    F2[0] = +F1[0] + T3[0];
    F2[1] = +F1[1] + T3[1];
    P2[0] = -F2[0].real();
    P2[1] = -F2[1].real();
    P2[2] = -F2[1].imag();
    P2[3] = -F2[0].imag();
    TMP15 =
        (P1[0] * -1. *
             (P2[1] * T3[3] + P2[2] * T3[4] + P2[3] * T3[5] - P2[0] * T3[2]) +
         (P1[1] *
              (P2[1] * T3[7] + P2[2] * T3[8] + P2[3] * T3[9] - P2[0] * T3[6]) +
          (P1[2] * (P2[1] * T3[11] + P2[2] * T3[12] + P2[3] * T3[13] -
                    P2[0] * T3[10]) +
           P1[3] * (P2[1] * T3[15] + P2[2] * T3[16] + P2[3] * T3[17] -
                    P2[0] * T3[14]))));
    TMP13 =
        (P1[0] * -1. *
             (P2[1] * T3[6] + P2[2] * T3[10] + P2[3] * T3[14] - P2[0] * T3[2]) +
         (P1[1] * (P2[1] * T3[7] + P2[2] * T3[11] + P2[3] * T3[15] -
                   P2[0] * T3[3]) +
          (P1[2] * (P2[1] * T3[8] + P2[2] * T3[12] + P2[3] * T3[16] -
                    P2[0] * T3[4]) +
           P1[3] * (P2[1] * T3[9] + P2[2] * T3[13] + P2[3] * T3[17] -
                    P2[0] * T3[5]))));
    denom = COUP / (pow(P2[0], 2) - pow(P2[1], 2) - pow(P2[2], 2) -
                    pow(P2[3], 2) - M2 * (M2 - cI * W2));
    F2[2] = denom * cI *
            (TMP13 * (F1[4] * (P2[0] - P2[3]) +
                      (F1[5] * (+cI * (P2[2]) - P2[1]) - F1[2] * M2)) +
             TMP15 * (F1[4] * (P2[0] - P2[3]) +
                      (F1[5] * (+cI * (P2[2]) - P2[1]) - F1[2] * M2)));
    F2[3] = denom * -cI *
            (TMP13 * (F1[4] * (P2[1] + cI * (P2[2])) +
                      (F1[5] * -1. * (P2[0] + P2[3]) + F1[3] * M2)) +
             TMP15 * (F1[4] * (P2[1] + cI * (P2[2])) +
                      (F1[5] * -1. * (P2[0] + P2[3]) + F1[3] * M2)));
    F2[4] = denom * cI *
            (TMP13 * (F1[2] * -1. * (P2[0] + P2[3]) +
                      (F1[3] * (+cI * (P2[2]) - P2[1]) + F1[4] * M2)) +
             TMP15 * (F1[2] * -1. * (P2[0] + P2[3]) +
                      (F1[3] * (+cI * (P2[2]) - P2[1]) + F1[4] * M2)));
    F2[5] = denom * -cI *
            (TMP13 * (F1[2] * (P2[1] + cI * (P2[2])) +
                      (F1[3] * (P2[0] - P2[3]) - F1[5] * M2)) +
             TMP15 * (F1[2] * (P2[1] + cI * (P2[2])) +
                      (F1[3] * (P2[0] - P2[3]) - F1[5] * M2)));
}

void FFT1_2_3_5_2(complex<double> F1[], complex<double> T3[],
                  complex<double> COUP1, complex<double> COUP2,
                  complex<double> COUP3, complex<double> COUP4, double M2,
                  double W2, complex<double> F2[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> denom;
    //   double P1[4];
    //   double P2[4];
    int i;
    complex<double> Ftmp[6];
    FFT1_2(F1, T3, COUP1, M2, W2, F2);
    FFT2_2(F1, T3, COUP2, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
    FFT3_2(F1, T3, COUP3, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
    FFT5_2(F1, T3, COUP4, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
}
void FFT1_2_4_5_2(complex<double> F1[], complex<double> T3[],
                  complex<double> COUP1, complex<double> COUP2,
                  complex<double> COUP3, complex<double> COUP4, double M2,
                  double W2, complex<double> F2[])
{
    //   complex<double> cI = complex<double> (0., 1.);
    complex<double> denom;
    //   double P1[4];
    //   double P2[4];
    int i;
    complex<double> Ftmp[6];
    FFT1_2(F1, T3, COUP1, M2, W2, F2);
    FFT2_2(F1, T3, COUP2, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
    FFT4_2(F1, T3, COUP3, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
    FFT5_2(F1, T3, COUP4, M2, W2, Ftmp);
    i = 2;
    while (i < 6) {
        F2[i] = F2[i] + Ftmp[i];
        i++;
    }
}

void FFT4_2(complex<double> F1[], complex<double> T3[], complex<double> COUP,
            double M2, double W2, complex<double> F2[])
{
    complex<double> cI = complex<double>(0., 1.);
    double P1[4];
    double P2[4];
    complex<double> denom;
    P1[0] = F1[0].real();
    P1[1] = F1[1].real();
    P1[2] = F1[1].imag();
    P1[3] = F1[0].imag();
    F2[0] = +F1[0] + T3[0];
    F2[1] = +F1[1] + T3[1];
    P2[0] = -F2[0].real();
    P2[1] = -F2[1].real();
    P2[2] = -F2[1].imag();
    P2[3] = -F2[0].imag();
    denom = COUP / (pow(P2[0], 2) - pow(P2[1], 2) - pow(P2[2], 2) -
                    pow(P2[3], 2) - M2 * (M2 - cI * W2));
    F2[2] =
        denom * cI *
        (F1[3] *
             (P2[0] *
                  (P2[3] * (T3[9] + T3[6] + T3[15] + T3[3] -
                            cI * (T3[13] + T3[10] + T3[16] + T3[4])) +
                   (P2[1] * -1. *
                        (T3[14] + T3[5] + cI * (T3[11] + T3[8]) -
                         2. * (T3[7] + T3[2])) +
                    (P2[2] * (T3[8] + T3[11] - 2. * cI * (T3[12] + T3[2]) +
                              cI * (T3[14] + T3[5])) +
                     (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                        (P1[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) -
                         P1[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
              (P2[1] * (P2[2] * (T3[16] + T3[13] - cI * (T3[15] + T3[9]) +
                                 cI * (T3[3] + T3[6]) - T3[4] - T3[10]) +
                        (P2[3] * (+2. * (T3[17]) + cI * (T3[11] + T3[8]) -
                                  2. * (T3[7]) - T3[5] - T3[14]) +
                         (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P1[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                           (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                            (P1[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                             P1[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
               (P2[2] *
                    (P2[3] * (-2. * cI * (T3[17]) + cI * (T3[5] + T3[14]) +
                              2. * cI * (T3[12]) - T3[8] - T3[11]) +
                     (P1[1] * (-cI * (T3[3] + T3[6]) + cI * (T3[15] + T3[9])) +
                      (P1[2] *
                           (-cI * (T3[4] + T3[10]) + cI * (T3[16] + T3[13])) +
                       (P2[2] *
                            (-cI * (T3[16] + T3[13]) + cI * (T3[4] + T3[10])) +
                        (P1[0] * -1. *
                             (-2. * cI * (T3[2]) + cI * (T3[14] + T3[5])) -
                         P1[3] * (-2. * cI * (T3[17]) +
                                  cI * (T3[5] + T3[14]))))))) +
                P2[3] *
                    (P1[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                     (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                      (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                        P1[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
         (F1[2] *
              (P2[0] * (P2[1] * (T3[15] + T3[9] + 2. * (T3[3] + T3[6]) +
                                 cI * (T3[10] + T3[4])) +
                        (P2[2] * (T3[16] + T3[13] + 2. * (T3[4] + T3[10]) -
                                  cI * (T3[6] + T3[3])) +
                         (P1[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P1[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (P2[3] * 2. * (T3[5] + T3[17] + T3[2] + T3[14]) +
                            (P1[0] * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] + 2. * (T3[17])) -
                              P2[0] * (T3[14] + T3[5] + 2. * (T3[2]))))))))) +
               (P2[3] * (P2[1] * -1. *
                             (T3[3] + T3[6] + 2. * (T3[9] + T3[15]) +
                              cI * (T3[13] + T3[16])) +
                         (P2[2] * -1. *
                              (T3[4] + T3[10] - cI * (T3[9] + T3[15]) +
                               2. * (T3[13] + T3[16])) +
                          (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P1[3] * (T3[5] + T3[14] + 2. * (T3[17])) -
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
                (P2[1] *
                     (P1[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[2] * -2. *
                            (T3[8] + T3[11] - cI * (T3[7]) + cI * (T3[12])) +
                        (P1[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                         (P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12])) -
                          P2[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8]))))))) +
                 P2[2] * (P1[0] * (+cI * (T3[6] + T3[3]) - T3[10] - T3[4]) +
                          (P1[3] * (T3[13] + T3[16] - cI * (T3[9] + T3[15])) +
                           (P1[1] * (T3[11] + T3[8] - 2. * cI * (T3[7])) +
                            (P1[2] * -1. *
                                 (+cI * (T3[8] + T3[11]) - 2. * (T3[12])) +
                             P2[2] * (+cI * (T3[8] + T3[11]) -
                                      2. * (T3[12]))))))))) +
          M2 *
              (F1[4] * (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                        (P1[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                         (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                          (P2[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                           (T3[14] * (P1[0] + P1[3] - P2[0] - P2[3]) +
                            (T3[5] * (P1[3] + P1[0] - P2[3] - P2[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P2[3] - P1[3]))))))))) +
               F1[5] *
                   (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                    (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                     (P2[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P2[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P2[1]) + cI * (P1[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P2[2]) + cI * (P1[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))))));
    F2[3] =
        denom * cI *
        (F1[2] *
             (P2[0] *
                  (P2[3] * (T3[9] + T3[15] - cI * (T3[10] + T3[4]) +
                            cI * (T3[13] + T3[16]) - T3[6] - T3[3]) +
                   (P2[1] * (T3[14] + T3[5] + 2. * (T3[7] + T3[2]) +
                             cI * (T3[11] + T3[8])) +
                    (P2[2] * (T3[8] + T3[11] + cI * (T3[14] + T3[5]) +
                              2. * cI * (T3[12] + T3[2])) +
                     (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                        (P1[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                         P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
              (P2[1] * (P2[2] * -1. *
                            (T3[4] + T3[16] + T3[10] + T3[13] +
                             cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                        (P2[3] * (+2. * (T3[7]) + cI * (T3[11] + T3[8]) -
                                  2. * (T3[17]) - T3[5] - T3[14]) +
                         (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                            (P1[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                             P1[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
               (P2[2] * (P2[3] * (T3[8] + T3[11] - cI * (T3[5] + T3[14]) -
                                  2. * cI * (T3[17]) + 2. * cI * (T3[12])) +
                         (P1[1] * (+cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                          (P1[2] * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                           (P2[2] * -1. *
                                (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                            (P1[0] * -1. *
                                 (+cI * (T3[14] + T3[5]) + 2. * cI * (T3[2])) +
                             P1[3] * (+cI * (T3[5] + T3[14]) +
                                      2. * cI * (T3[17]))))))) +
                P2[3] *
                    (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                     (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                      (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P1[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                        P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
         (F1[3] *
              (P2[0] * (P2[1] * -1. *
                            (T3[15] + T3[9] + cI * (T3[10] + T3[4]) -
                             2. * (T3[3] + T3[6])) +
                        (P2[2] * (+2. * (T3[4] + T3[10]) +
                                  cI * (T3[6] + T3[3]) - T3[16] - T3[13]) +
                         (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                          (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                           (P2[3] * 2. * (T3[5] + T3[14] - T3[17] - T3[2]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                              P2[0] * (T3[14] + T3[5] - 2. * (T3[2]))))))))) +
               (P2[3] * (P2[1] * (T3[3] + T3[6] + cI * (T3[13] + T3[16]) -
                                  2. * (T3[9] + T3[15])) +
                         (P2[2] * -1. *
                              (+2. * (T3[13] + T3[16]) + cI * (T3[9] + T3[15]) -
                               T3[4] - T3[10]) +
                          (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                           (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
                (P2[1] *
                     (P1[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (P2[2] * -2. *
                            (T3[8] + T3[11] - cI * (T3[12]) + cI * (T3[7])) +
                        (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P1[2] * (T3[8] + T3[11] - 2. * cI * (T3[12])) +
                          P2[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7]))))))) +
                 P2[2] *
                     (P1[0] * -1. * (T3[10] + T3[4] + cI * (T3[6] + T3[3])) +
                      (P1[3] * (T3[13] + T3[16] + cI * (T3[9] + T3[15])) +
                       (P1[1] * (T3[11] + T3[8] + 2. * cI * (T3[7])) +
                        (P1[2] * (+2. * (T3[12]) + cI * (T3[8] + T3[11])) -
                         P2[2] *
                             (+2. * (T3[12]) + cI * (T3[8] + T3[11]))))))))) +
          M2 *
              (F1[4] *
                   (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                    (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P1[2]) + cI * (P2[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))) +
               F1[5] * (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                        (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                         (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (T3[14] * (P2[0] + P1[3] - P1[0] - P2[3]) +
                            (T3[5] * (P1[3] + P2[0] - P2[3] - P1[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))))));
    F2[4] =
        denom * -cI *
        (F1[5] *
             (P2[0] *
                  (P2[3] * (T3[6] + T3[3] - cI * (T3[10] + T3[4]) +
                            cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                   (P2[1] * -1. *
                        (T3[14] + T3[5] + 2. * (T3[7] + T3[2]) -
                         cI * (T3[11] + T3[8])) +
                    (P2[2] * (+cI * (T3[14] + T3[5]) +
                              2. * cI * (T3[12] + T3[2]) - T3[8] - T3[11]) +
                     (P1[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                      (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                       (P2[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                        (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         P1[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
              (P2[1] * (P2[2] * (T3[4] + T3[16] + T3[10] + T3[13] -
                                 cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                        (P2[3] * (T3[5] + T3[14] + 2. * (T3[17]) +
                                  cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P1[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P1[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (P2[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                            (P1[0] * (T3[14] + T3[5] + 2. * (T3[2])) -
                             P1[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
               (P2[2] * (P2[3] * -1. *
                             (T3[8] + T3[11] - 2. * cI * (T3[12]) +
                              cI * (T3[5] + T3[14]) + 2. * cI * (T3[17])) +
                         (P1[1] * (+cI * (T3[3] + T3[15] + T3[6] + T3[9])) +
                          (P1[2] * (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                           (P2[2] * -1. *
                                (+cI * (T3[4] + T3[16] + T3[10] + T3[13])) +
                            (P1[0] * -1. *
                                 (+cI * (T3[14] + T3[5]) + 2. * cI * (T3[2])) +
                             P1[3] * (+cI * (T3[5] + T3[14]) +
                                      2. * cI * (T3[17]))))))) +
                P2[3] *
                    (P1[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                     (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                      (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (P1[1] * -1. * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                        P1[2] * (T3[8] + T3[11] - 2. * cI * (T3[12]))))))))) +
         (F1[4] *
              (P2[0] * (P2[1] * (+2. * (T3[3] + T3[6]) + cI * (T3[10] + T3[4]) -
                                 T3[15] - T3[9]) +
                        (P2[2] * -1. *
                             (T3[16] + T3[13] + cI * (T3[6] + T3[3]) -
                              2. * (T3[4] + T3[10])) +
                         (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                          (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                           (P2[3] * 2. * (T3[5] + T3[14] - T3[17] - T3[2]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                              P2[0] * (T3[14] + T3[5] - 2. * (T3[2]))))))))) +
               (P2[3] * (P2[1] * -1. *
                             (+2. * (T3[9] + T3[15]) + cI * (T3[13] + T3[16]) -
                              T3[3] - T3[6]) +
                         (P2[2] * (T3[4] + T3[10] + cI * (T3[9] + T3[15]) -
                                   2. * (T3[13] + T3[16])) +
                          (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                           (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                            (P1[0] * -1. * (T3[14] + T3[5] - 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] - 2. * (T3[17])) +
                              P2[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
                (P2[1] *
                     (P1[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[2] * -2. *
                            (T3[8] + T3[11] - cI * (T3[7]) + cI * (T3[12])) +
                        (P1[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                         (P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12])) -
                          P2[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8]))))))) +
                 P2[2] * (P1[0] * (+cI * (T3[6] + T3[3]) - T3[10] - T3[4]) +
                          (P1[3] * (T3[13] + T3[16] - cI * (T3[9] + T3[15])) +
                           (P1[1] * (T3[11] + T3[8] - 2. * cI * (T3[7])) +
                            (P1[2] * -1. *
                                 (+cI * (T3[8] + T3[11]) - 2. * (T3[12])) +
                             P2[2] * (+cI * (T3[8] + T3[11]) -
                                      2. * (T3[12]))))))))) +
          M2 *
              (F1[2] * (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                        (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                         (P2[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P2[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (T3[14] * (P2[0] + P1[3] - P1[0] - P2[3]) +
                            (T3[5] * (P1[3] + P2[0] - P2[3] - P1[0]) +
                             (T3[2] * 2. * (P2[0] - P1[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))) +
               F1[3] *
                   (P1[0] * (+cI * (T3[10] + T3[4]) - T3[6] - T3[3]) +
                    (P1[3] * (T3[9] + T3[15] - cI * (T3[13] + T3[16])) +
                     (P2[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P2[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (T3[11] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2]) +
                        (T3[8] * (P1[2] - cI * (P1[1]) + cI * (P2[1]) - P2[2]) +
                         (T3[12] * 2. * (-cI * (P1[2]) + cI * (P2[2])) +
                          2. * (T3[7] * (P1[1] - P2[1]))))))))))));
    F2[5] =
        denom * cI *
        (F1[4] *
             (P2[0] *
                  (P2[3] * (T3[9] + T3[6] + T3[15] + T3[3] +
                            cI * (T3[13] + T3[10] + T3[16] + T3[4])) +
                   (P2[1] * (+2. * (T3[7] + T3[2]) + cI * (T3[11] + T3[8]) -
                             T3[14] - T3[5]) +
                    (P2[2] * (T3[8] + T3[11] - cI * (T3[14] + T3[5]) +
                              2. * cI * (T3[12] + T3[2])) +
                     (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                        (P1[1] * -1. * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) -
                         P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
              (P2[1] * (P2[2] * (T3[16] + T3[13] - cI * (T3[3] + T3[6]) +
                                 cI * (T3[15] + T3[9]) - T3[4] - T3[10]) +
                        (P2[3] * -1. *
                             (T3[5] + T3[14] + 2. * (T3[7]) +
                              cI * (T3[11] + T3[8]) - 2. * (T3[17])) +
                         (P1[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P1[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                           (P2[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                            (P1[0] * (T3[14] + T3[5] - 2. * (T3[2])) +
                             P1[3] * (T3[5] + T3[14] - 2. * (T3[17])))))))) +
               (P2[2] *
                    (P2[3] * -1. *
                         (T3[8] + T3[11] - 2. * cI * (T3[17]) +
                          cI * (T3[5] + T3[14]) + 2. * cI * (T3[12])) +
                     (P1[1] * (-cI * (T3[15] + T3[9]) + cI * (T3[3] + T3[6])) +
                      (P1[2] *
                           (-cI * (T3[16] + T3[13]) + cI * (T3[4] + T3[10])) +
                       (P2[2] *
                            (-cI * (T3[4] + T3[10]) + cI * (T3[16] + T3[13])) +
                        (P1[0] * (-2. * cI * (T3[2]) + cI * (T3[14] + T3[5])) +
                         P1[3] * (-2. * cI * (T3[17]) +
                                  cI * (T3[5] + T3[14]))))))) +
                P2[3] *
                    (P1[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                     (P1[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                      (P2[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (P1[1] * (+2. * (T3[7]) + cI * (T3[11] + T3[8])) +
                        P1[2] * (T3[8] + T3[11] + 2. * cI * (T3[12]))))))))) +
         (F1[5] *
              (P2[0] * (P2[1] * -1. *
                            (T3[15] + T3[9] + 2. * (T3[3] + T3[6]) -
                             cI * (T3[10] + T3[4])) +
                        (P2[2] * -1. *
                             (T3[16] + T3[13] + 2. * (T3[4] + T3[10]) +
                              cI * (T3[6] + T3[3])) +
                         (P1[1] * (T3[3] + T3[15] + T3[6] + T3[9]) +
                          (P1[2] * (T3[4] + T3[16] + T3[10] + T3[13]) +
                           (P2[3] * -2. * (T3[5] + T3[17] + T3[2] + T3[14]) +
                            (P1[0] * -1. * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P1[3] * (T3[5] + T3[14] + 2. * (T3[17])) +
                              P2[0] * (T3[14] + T3[5] + 2. * (T3[2]))))))))) +
               (P2[3] * (P2[1] * (T3[3] + T3[6] + 2. * (T3[9] + T3[15]) -
                                  cI * (T3[13] + T3[16])) +
                         (P2[2] * (T3[4] + T3[10] + 2. * (T3[13] + T3[16]) +
                                   cI * (T3[9] + T3[15])) +
                          (P1[1] * -1. * (T3[3] + T3[15] + T3[6] + T3[9]) +
                           (P1[2] * -1. * (T3[4] + T3[16] + T3[10] + T3[13]) +
                            (P1[0] * (T3[14] + T3[5] + 2. * (T3[2])) +
                             (P1[3] * -1. * (T3[5] + T3[14] + 2. * (T3[17])) +
                              P2[3] * (T3[5] + T3[14] + 2. * (T3[17])))))))) +
                (P2[1] *
                     (P1[0] * (T3[6] + T3[3] - cI * (T3[10] + T3[4])) +
                      (P1[3] * (+cI * (T3[13] + T3[16]) - T3[9] - T3[15]) +
                       (P2[2] * 2. *
                            (T3[8] + T3[11] - cI * (T3[12]) + cI * (T3[7])) +
                        (P1[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7])) +
                         (P1[2] * -1. * (T3[8] + T3[11] - 2. * cI * (T3[12])) -
                          P2[1] * (+cI * (T3[11] + T3[8]) - 2. * (T3[7]))))))) +
                 P2[2] *
                     (P1[0] * (T3[10] + T3[4] + cI * (T3[6] + T3[3])) +
                      (P1[3] * -1. * (T3[13] + T3[16] + cI * (T3[9] + T3[15])) +
                       (P1[1] * -1. * (T3[11] + T3[8] + 2. * cI * (T3[7])) +
                        (P1[2] * -1. *
                             (+2. * (T3[12]) + cI * (T3[8] + T3[11])) +
                         P2[2] *
                             (+2. * (T3[12]) + cI * (T3[8] + T3[11]))))))))) +
          M2 *
              (F1[2] *
                   (P1[0] * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                    (P1[3] * -1. * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                     (P2[0] * -1. * (T3[6] + T3[3] + cI * (T3[10] + T3[4])) +
                      (P2[3] * (T3[9] + T3[15] + cI * (T3[13] + T3[16])) +
                       (T3[11] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                        (T3[8] * (P2[2] - cI * (P1[1]) + cI * (P2[1]) - P1[2]) +
                         (T3[12] * 2. * (-cI * (P1[2]) + cI * (P2[2])) +
                          2. * (T3[7] * (P2[1] - P1[1]))))))))) +
               F1[3] * (P1[1] * (T3[15] + T3[9] - T3[3] - T3[6]) +
                        (P1[2] * (T3[16] + T3[13] - T3[4] - T3[10]) +
                         (P2[1] * (T3[3] + T3[6] - T3[15] - T3[9]) +
                          (P2[2] * (T3[4] + T3[10] - T3[16] - T3[13]) +
                           (T3[14] * (P2[0] + P2[3] - P1[0] - P1[3]) +
                            (T3[5] * (P2[3] + P2[0] - P1[3] - P1[0]) +
                             (T3[2] * 2. * (P1[0] - P2[0]) +
                              2. * (T3[17] * (P1[3] - P2[3]))))))))))));
}

} // namespace MG5_HEF_MEKD2_1
