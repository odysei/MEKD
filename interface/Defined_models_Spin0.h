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
                                    complex<double>(1, 0),
                                    complex<double>(0, 0),
                                    complex<double>(0, 0),
                                    complex<double>(0, 0)};

// for decay_ZZ
const complex<double> definition_Spin0Ph[4] = {
                                    complex<double>(0, 0),
                                    complex<double>(1, 0),
                                    complex<double>(0, 0),
                                    complex<double>(0, 0)};

// for decay_ZZ
const complex<double> definition_Spin0M[4] = {
                                    complex<double>(0, 0),
                                    complex<double>(0, 0),
                                    complex<double>(0, 0),
                                    complex<double>(1, 0)};

// for decay_2f
const complex<double> definition_Spin0M_2f[4] = {
                                    complex<double>(0, 0),
                                    complex<double>(1, 0),
                                    complex<double>(0, 0),  // placeholder
                                    complex<double>(0, 0)}; // placeholder

}

#endif
