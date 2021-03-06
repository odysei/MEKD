//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 1.5.7, 2013-01-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef MG5_Sigma_HEF_MEKD_ccx_Xspin1_mummupmummupa_H
#define MG5_Sigma_HEF_MEKD_ccx_Xspin1_mummupmummupa_H

#include <complex>
#include <vector>

#include "Commons/Parameters_MEKD.h"

//==========================================================================
// A class for calculating the matrix elements for
// Process: c c~ > zp > mu- mu+ mu- mu+ a WEIGHTED=10
//--------------------------------------------------------------------------

class qq_Spin1_UP_SFpA
{
  public:
    // Constructor.
    qq_Spin1_UP_SFpA() {}

    // Initialize process.
    void initProc(std::string param_card_name);

    // Update process.
    void updateProc(SLHAReader_MEKD &slha);

    // Calculate flavour-independent parts of cross section.
    void sigmaKin();

    // Evaluate sigmaHat(sHat).
    double sigmaHat();

    // Info on the subprocess.
    std::string name() const { return "c c~ > mu- mu+ mu- mu+ a (HEF_MEKD)"; }

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
    static const int ninitial = 2;
    static const int nexternal = 7;
    static const int nprocesses = 2;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 24;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 12;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood; // moved here by Ghost remover v. 0.1
    double matrix_ccx_zp_mummupmummupa();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_MEKD *pars;

    // vector with external particle masses
    std::vector<double> mME;

    // vector with momenta (to be changed each event)
    std::vector<double *> p;
    // Initial particle ids
    int id1, id2;
};

#endif // MG5_Sigma_HEF_MEKD_ccx_mummupmummupa_H
