//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_HEF_MEKD2_1_h_emepmummupa_H
#define MG5_Sigma_HEF_MEKD2_1_h_emepmummupa_H

#include <complex>
#include <vector>

#include "Parameters_MEKD.h"

//==========================================================================
// A class for calculating the matrix elements for
// Process: h > e- e+ mu- mu+ a S0QQ=1 / zp xg
//--------------------------------------------------------------------------

class Spin0_2f_OFpA
{
  public:
    // Constructor.
    Spin0_2f_OFpA() {}

    // Initialize process.
    void initProc(std::string param_card_name);
    void initProc();

    // Update process.
    void updateProc();

    // Calculate flavour-independent parts of cross section.
    void sigmaKin();

    // Evaluate sigmaHat(sHat).
    double sigmaHat();

    // Info on the subprocess.
    std::string name() const { return "h > e- e+ mu- mu+ a (HEF_MEKD2_1)"; }

    int code() const { return 0; }

    const std::vector<double> &getMasses() const { return mME; }

    // Get and set momenta for matrix element evaluation
    std::vector<double *> getMomenta() { return p; }
    void setMomenta(std::vector<double *> &momenta) { p = momenta; }
    void setInitial(int inid1, int inid2)
    {
        id1 = inid1;
        id2 = inid2;
    }

    // Get matrix element vector
    const double *getMatrixElements() const { return matrix_element; }

    // Constants for array limits
    static const int ninitial = 1;
    static const int nexternal = 6;
    static const int nprocesses = 1;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 62;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 48;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood; // Moved here by Convert_source 0.2
    double matrix_h_emepmummupa_no_zpxg();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_MEKD *pars; // Changed by Convert_source 0.2

    // vector with external particle masses
    std::vector<double> mME;

    // vector with momenta (to be changed each event)
    std::vector<double *> p;
    // Initial particle ids
    int id1, id2;
};

#endif // MG5_Sigma_HEF_MEKD2_1_h_emepmummupa_H
