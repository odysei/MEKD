/*
 *
 * Defined models, i.e., predefined mixing coefficients that correspond to a
 * specific model.
 *
 *
 */
#ifndef Defined_models_Spin0_h
#define Defined_models_Spin0_h

#include <complex>

using namespace std;

namespace MG5_HEF_MEKD
{

// for decay_ZZ, decay_2f
const complex<double> definition_Spin0Pm[4] = {
    complex<double>(1, 0), complex<double>(0, 0), complex<double>(0, 0),
    complex<double>(0, 0)};

// for decay_ZZ
const complex<double> definition_Spin0Ph[4] = {
    complex<double>(0, 0), complex<double>(1, 0), complex<double>(0, 0),
    complex<double>(0, 0)};

// for decay_ZZ
const complex<double> definition_Spin0M[4] = {
    complex<double>(0, 0), complex<double>(0, 0), complex<double>(0, 0),
    complex<double>(1, 0)};

// for decay_2f
const complex<double> definition_Spin0M_2f[4] = {
    complex<double>(0, 0), complex<double>(1, 0),
    complex<double>(0, 0),  // placeholder
    complex<double>(0, 0)}; // placeholder
} // namespace MG5_HEF_MEKD

namespace MG5_HiggsPO_UFO
{
// XZZ[3], XZA[2], XAA[2], Zll[4]
const couplings definition_Spin0Pm = {1, 0, 0, // XZZ[3]
                                      1, 0,    // XZA[2]
                                      1, 0,    // XAA[2]
                                      0, 0, 0, 0};
} // namespace MG5_HiggsPO_UFO

#endif
