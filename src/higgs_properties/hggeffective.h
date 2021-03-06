//
//  hggeffective.cpp
//
//
//  Created by Myeonghun Park on 9/2/12.
//
//  Modified by Aurelijus Rinkevicius on 2013-05-06
//
#ifndef hggeffective_h
#define hggeffective_h

#include <cmath>
#include <complex>
#include <cstdio>

/// Definition
#define PI acos(-1.0)

/// Functions
double LmbdGG(const double Mh);

inline double fiRe(const double tau);
inline double fiIm(const double tau);
inline double HggFr(const double tau);
inline double HggFi(const double tau);

inline std::complex<double> HggF(const double tau);

#endif
