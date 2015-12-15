//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_HEF_MEKD2_1_zp_emepmummupa_H
#define MG5_Sigma_HEF_MEKD2_1_zp_emepmummupa_H

#include <complex>
#include <vector>

#include "Commons/Parameters_MEKD.h" // Changed by Convert_source 0.2

using namespace std;

//==========================================================================
// A class for calculating the matrix elements for
// Process: zp > e- e+ mu- mu+ a S1QQ=1 / h xg
//--------------------------------------------------------------------------

class Spin1_2f_OFpA
{
  public:
    // Constructor.
    Spin1_2f_OFpA() {}

    // Initialize process.
    void initProc(string param_card_name);

    // Update process.
    void updateProc(SLHAReader_MEKD &slha);

    // Calculate flavour-independent parts of cross section.
    void sigmaKin();

    // Evaluate sigmaHat(sHat).
    double sigmaHat();

    // Info on the subprocess.
    string name() const { return "zp > e- e+ mu- mu+ a (HEF_MEKD2_1)"; }

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
    static const int ninitial = 1;
    static const int nexternal = 6;
    static const int nprocesses = 1;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 62;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 44;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood; // Moved here by Convert_source 0.2
    double matrix_zp_emepmummupa_no_hxg();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_MEKD *pars; // Changed by Convert_source 0.2

    // vector with external particle masses
    vector<double> mME;

    // vector with momenta (to be changed each event)
    vector<double *> p;
    // Initial particle ids
    int id1, id2;
};

#endif // MG5_Sigma_HEF_MEKD2_1_zp_emepmummupa_H
