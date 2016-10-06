//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 1.5.3, 2012-11-01
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef MG5_Sigma_HEF_MEKD_ssx_emepmummup_H
#define MG5_Sigma_HEF_MEKD_ssx_emepmummup_H

#include <complex>
#include <vector>

#include "Commons/Parameters_MEKD.h"

using namespace std;
namespace MG5_HEF_UFO_bkg
{

//==========================================================================
// A class for calculating the matrix elements for
// Process: s s~ > e- e+ mu- mu+ / h xg WEIGHTED=8
//--------------------------------------------------------------------------

class qq_ZZ_DN_OF
{
  public:
    // Constructor.
    qq_ZZ_DN_OF() {}

    // Initialize process.
    void initProc(string param_card_name);
    void initProc();

    // Update process.
    void updateProc();

    // Calculate flavour-independent parts of cross section.
    void sigmaKin();

    // Evaluate sigmaHat(sHat).
    double sigmaHat();

    // Info on the subprocess.
    string name() const { return "s s~ > e- e+ mu- mu+ (HEF_MEKD)"; }

    int code() const { return 0; }

    const vector<double> &getMasses() const { return mME; }

    // Get and set momenta for matrix element evaluation
    vector<double *> getMomenta() { return p; }
    void setMomenta(vector<double *> &momenta) { p = momenta; }
    void setInitial(int inid1, int inid2)
    {
        id1 = inid1;
        id2 = inid2;
    }

    // Get matrix element vector
    const double *getMatrixElements() const { return matrix_element; }

    // Constants for array limits
    static const int ninitial = 2;
    static const int nexternal = 6;
    static const int nprocesses = 2;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 24;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 24;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood; // moved here by Ghost remover v. 0.1
    double matrix_ssx_emepmummup_no_hxg();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_MEKD *pars;

    // vector with external particle masses
    vector<double> mME;

    // vector with momenta (to be changed each event)
    vector<double *> p;
    // Initial particle ids
    int id1, id2;
};
}

#endif // MG5_Sigma_HEF_MEKD_ssx_emepmummup_H
