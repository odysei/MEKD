//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.6.4, 2018-11-09
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_Leptophilic_UFO_ccx_mummupmummup_H
#define MG5_Sigma_Leptophilic_UFO_ccx_mummupmummup_H

#include <complex>
#include <vector>

#include "Parameters_Leptophilic_UFO.h"

namespace MG5_Leptophilic_UFO
{

//==========================================================================
// A class for calculating the matrix elements for
// Process: c c~ > mu- mu+ mu- mu+ WEIGHTED<=8 / h @2
//--------------------------------------------------------------------------

class qq_z_zp_UP_SF
{
  public:
    // Constructor.
    qq_z_zp_UP_SF() {}

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
    std::string name() const
    {
        return "c c~ > mu- mu+ mu- mu+ (Leptophilic_UFO)";
    }

    int code() const { return 2; }

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
    static const int nprocesses = 2;

  private:
    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]);
    static const int nwavefuncs = 36;
    std::complex<double> w[nwavefuncs][18];
    static const int namplitudes = 64;
    std::complex<double> amp[namplitudes];
    int ntry, sum_hel, ngood;
    double matrix_2_ccx_mummupmummup_no_h();

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses];

    // Color flows, used when selecting color
    double *jamp2[nprocesses];

    // Pointer to the model parameters
    Parameters_Leptophilic_UFO *pars;

    // vector with external particle masses
    std::vector<double> mME;

    // vector with momenta (to be changed each event)
    std::vector<double *> p;
    // Initial particle ids
    int id1, id2;
};

} // namespace MG5_Leptophilic_UFO

#endif // MG5_Sigma_Leptophilic_UFO_ccx_mummupmummup_H
