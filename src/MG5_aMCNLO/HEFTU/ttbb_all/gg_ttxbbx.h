//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_heft_updated_full_gg_ttxbbx_H
#define MG5_Sigma_heft_updated_full_gg_ttxbbx_H

#include <complex>
#include <vector>

#include "Parameters_heft_updated_full.h"

namespace MG5_heft_updated_full
{

//==========================================================================
// A class for calculating the matrix elements for
// Process: g g > t t~ b b~ HIW=1 QED=2 HIG=1 @1
//--------------------------------------------------------------------------

class gg_ttxbbx
{
  public:
    // Constructor.
    gg_ttxbbx() {}

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
    std::string name() const { return "g g > t t~ b b~ (heft_updated_full)"; }

    int code() const { return 1; }

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
    static const int nexternal = 6;
    static const int nprocesses = 1;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 68;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 163;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood;
    double matrix_1_gg_ttxbbx();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_HEFTU *pars;

    // vector with external particle masses
    std::vector<double> mME;

    // vector with momenta (to be changed each event)
    std::vector<double *> p;
    // Initial particle ids
    int id1, id2;
};
} // namespace MG5_heft_updated_full

#endif // MG5_Sigma_heft_updated_full_gg_ttxbbx_H
