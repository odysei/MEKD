//
//  hggeffective.cpp
//
//
//  Created by Myeonghun Park on 9/2/12.
//
//  Modified by Aurelijus Rinkevicius on 2013-05-06
//
#ifndef hggeffective_cpp
#define hggeffective_cpp

#include "hggeffective.h"

using namespace std;

/// Variables
const double EE = 3.123E-1;
const double SW = 4.808E-1;
const double Me = 5.109989E-4;
const double Mm = 1.056584E-1;
const double Mcp = 1.4E+0;
const double Mtp = 1.775E+2;
const double MZ = 9.11876E+1;
const double wZ = 2.4952E+0;
const double Mbp = 4.891E+0;
const double CW = sqrt(1 - SW * SW);
const double MW = MZ * sqrt(1 - SW * SW);
const double alphaQh = 0.1184;
const double nfh = 5.0;

/// Functions
double LmbdGG(const double Mh)
{
    const double FFeven =
        1 + alphaQh / PI * (95.0 / 4.0 - 7.0 / 6.0 * nfh) +
        alphaQh * alphaQh / pow(PI, 2) *
            (370.0 - 47.0 * nfh + 0.9 * pow(nfh, 2) -
             (19.0 / 8.0 + 2.0 * nfh / 3.0) * 2.0 * log(Mtp / Mh));

    const complex<double> loops = HggF(pow(Mh / 2.0 / Mcp, 2)) +
                                  HggF(pow(Mh / 2.0 / Mbp, 2)) +
                                  HggF(pow(Mh / 2.0 / Mtp, 2));

    return (alphaQh / (8 * PI) * 1 / 2 * (-EE) / (2 * MW * SW) * abs(loops) *
            sqrt(FFeven));
}

inline double fiRe(const double tau)
{
    if (tau < 1) {
        const double x = asin(sqrt(tau));

        return x * x;
    }
    if (tau == 1)
        return 0;

    const double x = sqrt(1 - 1 / tau);
    const double y = log((1 + x) / (1 - x));

    return -0.25 * (y * y - PI * PI);
}

inline double fiIm(const double tau)
{
    if (tau <= 1)
        return 0;

    const double x = sqrt(1 - 1 / tau);
    const double y = log((1 + x) / (1 - x));

    return (0.5 * y * PI);
}

inline double HggFr(const double tau)
{
    return 2.0 * (tau + (tau - 1) * fiRe(tau)) / (tau * tau);
}

inline double HggFi(double const tau)
{
    return 2.0 * (tau - 1) * fiIm(tau) / (tau * tau);
}

inline complex<double> HggF(const double tau)
{
    return complex<double>(HggFr(tau), HggFi(tau));
}

#endif
