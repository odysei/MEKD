//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_sm_full_ccx_ttxbbx_H
#define MG5_Sigma_sm_full_ccx_ttxbbx_H

#include <complex>
#include <vector>

#include "Parameters_sm_full.h"

using namespace std;
namespace MG5_sm_full
{

//==========================================================================
// A class for calculating the matrix elements for
// Process: c c~ > t t~ b b~ QED=2 @1
//--------------------------------------------------------------------------

class cc_ttbb
{
  public:
    // Constructor.
    cc_ttbb() {}

    // Initialize process.
    virtual void initProc(string param_card_name);

    virtual void updateProc();

    // Calculate flavour-independent parts of cross section.
    virtual void sigmaKin();

    // Evaluate sigmaHat(sHat).
    virtual double sigmaHat();

    // Info on the subprocess.
    virtual string name() const { return "c c~ > t t~ b b~ (sm_full)"; }

    virtual int code() const { return 1; }

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
    static const int nwavefuncs = 49;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 51;
    std::complex<double> amp[namplitudes];
    double matrix_1_ccx_ttxbbx();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_sm_full *pars;

    // vector with external particle masses
    vector<double> mME;

    // vector with momenta (to be changed each event)
    vector<double *> p;
    // Initial particle ids
    int id1, id2;
};
}

#endif // MG5_Sigma_sm_full_ccx_ttxbbx_H
