//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "qq_Spin1_DN_2lpA.h"
#include "HelAmps_HEF_MEKD2_1.h" // Changed by Convert_source 0.2

using namespace std;

using namespace MG5_HEF_MEKD2_1;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: s s~ > zp > mu- mu+ a WEIGHTED=4 / h xg

//--------------------------------------------------------------------------
// Initialize process.

void qq_Spin1_DN_2lpA::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_MEKD::getInstance(); // Changed by Convert_source 0.2
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    ntry = 0, sum_hel = 0, ngood = 0; // Moved here by Convert_source 0.2
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.	// Created here by Convert_source 0.2

void qq_Spin1_DN_2lpA::updateProc(SLHAReader_MEKD &slha)
{
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    ntry = 0, sum_hel = 0, ngood = 0; // needed when altering couplings

    // Set external particle masses for this matrix element
    // Should correspond to initProc
    mME[0] = (pars->mdl_MS);
    mME[1] = (pars->mdl_MS);
    mME[2] = (pars->mdl_MM);
    mME[3] = (pars->mdl_MM);
    mME[4] = (pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_Spin1_DN_2lpA::sigmaKin()
{
    // Set the parameters which change event by event
    pars->setDependentParameters();
    pars->setDependentCouplings();
    // Deleted by Convert_source 0.2

    // Reset color flows
    for (int i = 0; i < 1; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 32;
    static bool goodhel[ncomb] = {ncomb * false};
    //	static int ntry = 0, sum_hel = 0, ngood = 0;	// Moved by
    // Convert_source
    // 0.2
    static int igood[ncomb];
    static int jhel;
    //	std::complex<double> * * wfs;	// Changed by Convert_source 0.2
    double t[nprocesses];
    // Helicities for the process
    static const int helicities[ncomb][nexternal] = {
        {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, 1}, {-1, -1, -1, 1, -1},
        {-1, -1, -1, 1, 1},   {-1, -1, 1, -1, -1}, {-1, -1, 1, -1, 1},
        {-1, -1, 1, 1, -1},   {-1, -1, 1, 1, 1},   {-1, 1, -1, -1, -1},
        {-1, 1, -1, -1, 1},   {-1, 1, -1, 1, -1},  {-1, 1, -1, 1, 1},
        {-1, 1, 1, -1, -1},   {-1, 1, 1, -1, 1},   {-1, 1, 1, 1, -1},
        {-1, 1, 1, 1, 1},     {1, -1, -1, -1, -1}, {1, -1, -1, -1, 1},
        {1, -1, -1, 1, -1},   {1, -1, -1, 1, 1},   {1, -1, 1, -1, -1},
        {1, -1, 1, -1, 1},    {1, -1, 1, 1, -1},   {1, -1, 1, 1, 1},
        {1, 1, -1, -1, -1},   {1, 1, -1, -1, 1},   {1, 1, -1, 1, -1},
        {1, 1, -1, 1, 1},     {1, 1, 1, -1, -1},   {1, 1, 1, -1, 1},
        {1, 1, 1, 1, -1},     {1, 1, 1, 1, 1}};
    // Denominators: spins, colors and identical particles
    const int denominators[nprocesses] = {36, 36};

    ntry = ntry + 1;

    // Reset the matrix elements
    for (int i = 0; i < nprocesses; i++) {
        matrix_element[i] = 0.;
    }
    // Define permutation
    int perm[nexternal];
    for (int i = 0; i < nexternal; i++) {
        perm[i] = i;
    }

    if (sum_hel == 0 || ntry < 10) {
        // Calculate the matrix element for all helicities
        for (int ihel = 0; ihel < ncomb; ihel++) {
            if (goodhel[ihel] || ntry < 2) {
                calculate_wavefunctions(perm, helicities[ihel]);
                t[0] = matrix_ssx_zp_mummupa_no_hxg();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_ssx_zp_mummupa_no_hxg();
                double tsum = 0;
                for (int iproc = 0; iproc < nprocesses; iproc++) {
                    matrix_element[iproc] += t[iproc];
                    tsum += t[iproc];
                }
                // Store which helicities give non-zero result
                if (tsum != 0. && !goodhel[ihel]) {
                    goodhel[ihel] = true;
                    ngood++;
                    igood[ngood] = ihel;
                }
            }
        }
        jhel = 0;
        sum_hel = min(sum_hel, ngood);
    } else {
        // Only use the "good" helicities
        for (int j = 0; j < sum_hel; j++) {
            jhel++;
            if (jhel >= ngood)
                jhel = 0;
            double hwgt = double(ngood) / double(sum_hel);
            int ihel = igood[jhel];
            calculate_wavefunctions(perm, helicities[ihel]);
            t[0] = matrix_ssx_zp_mummupa_no_hxg();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_ssx_zp_mummupa_no_hxg();
            for (int iproc = 0; iproc < nprocesses; iproc++) {
                matrix_element[iproc] += t[iproc] * hwgt;
            }
        }
    }

    for (int i = 0; i < nprocesses; i++)
        matrix_element[i] /= denominators[i];
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double qq_Spin1_DN_2lpA::sigmaHat()
{
    // Select between the different processes
    if (id1 == -3 && id2 == 3) {
        // Add matrix elements for processes with beams (-3, 3)
        return matrix_element[1];
    } else if (id1 == 3 && id2 == -3) {
        // Add matrix elements for processes with beams (3, -3)
        return matrix_element[0];
    } else {
        // Return 0 if not correct initial state assignment
        return 0.;
    }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void qq_Spin1_DN_2lpA::calculate_wavefunctions(const int perm[],
                                               const int hel[])
{
    // Calculate wavefunctions for all processes
    //	int i, j;	// Changed by Convert_source 0.2

    // Calculate all wavefunctions
    ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]);
    oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
    oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
    ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
    vxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
    FFV1_2_3_4_3(w[0], w[1], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148,
                 pars->HEF_MEKD2_1_GC_149, pars->HEF_MEKD2_1_GC_150,
                 pars->mdl_MZp, pars->mdl_WZp, w[5]);
    FFV2_1(w[2], w[4], pars->HEF_MEKD2_1_GC_5, pars->mdl_MM, pars->ZERO, w[6]);
    FFV2_2(w[3], w[4], pars->HEF_MEKD2_1_GC_5, pars->mdl_MM, pars->ZERO, w[7]);
    FFV2_2(w[0], w[4], pars->HEF_MEKD2_1_GC_3, pars->mdl_MS, pars->ZERO, w[8]);
    FFV1_2_3_4_3(w[3], w[2], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138,
                 pars->HEF_MEKD2_1_GC_139, pars->HEF_MEKD2_1_GC_140,
                 pars->mdl_MZp, pars->mdl_WZp, w[9]);
    FFV2_1(w[1], w[4], pars->HEF_MEKD2_1_GC_3, pars->mdl_MS, pars->ZERO, w[10]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV1_2_3_4_0(w[3], w[6], w[5], pars->HEF_MEKD2_1_GC_141,
                 pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
                 pars->HEF_MEKD2_1_GC_140, amp[0]);
    FFV1_2_3_4_0(w[7], w[2], w[5], pars->HEF_MEKD2_1_GC_141,
                 pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
                 pars->HEF_MEKD2_1_GC_140, amp[1]);
    FFV1_2_3_4_0(w[8], w[1], w[9], pars->HEF_MEKD2_1_GC_151,
                 pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
                 pars->HEF_MEKD2_1_GC_150, amp[2]);
    FFV1_2_3_4_0(w[0], w[10], w[9], pars->HEF_MEKD2_1_GC_151,
                 pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
                 pars->HEF_MEKD2_1_GC_150, amp[3]);
}
double qq_Spin1_DN_2lpA::matrix_ssx_zp_mummupa_no_hxg()
{
    int i, j;
    // Local variables
    // Commented out by Convert_source 0.2
    //  const int ngraphs = 4;
    const int ncolor = 1;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1};
    static const double cf[ncolor][ncolor] = {{3}};

    // Calculate color flows
    jamp[0] = -amp[0] - amp[1] - amp[2] - amp[3];

    // Sum and square the color flows to get the matrix element
    double matrix = 0;
    for (i = 0; i < ncolor; i++) {
        ztemp = 0.;
        for (j = 0; j < ncolor; j++)
            ztemp = ztemp + cf[i][j] * jamp[j];
        matrix = matrix + real(ztemp * conj(jamp[i])) / denom[i];
    }

    // Store the leading color flows for choice of color
    for (i = 0; i < ncolor; i++)
        jamp2[0][i] += real(jamp[i] * conj(jamp[i]));

    return matrix;
}
