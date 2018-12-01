//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "Spin0_SF.h"
#include "HelAmps_HiggsPO_UFO.h"

using namespace std;

namespace MG5_HiggsPO_UFO
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: h > mu- mu+ mu- mu+ YUK=0 @2

//--------------------------------------------------------------------------
// Initialize process.

void Spin0_SF::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    ntry = 0, sum_hel = 0, ngood = 0;
    pars = Parameters_HiggsPO_UFO::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    //   pars->printIndependentParameters();
    //   pars->printIndependentCouplings();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MH);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    jamp2[0] = new double[1];
}

void Spin0_SF::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_HiggsPO_UFO::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MH);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.

void Spin0_SF::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MH);
    mME[1] = (pars->mdl_MM);
    mME[2] = (pars->mdl_MM);
    mME[3] = (pars->mdl_MM);
    mME[4] = (pars->mdl_MM);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void Spin0_SF::sigmaKin()
{
    // Set the parameters which change event by event
    pars->setDependentParameters();
    pars->setDependentCouplings();
    //   static bool firsttime = true;
    //   if (firsttime)
    //   {
    //     pars->printDependentParameters();
    //     pars->printDependentCouplings();
    //     firsttime = false;
    //   }

    // Reset color flows
    for (int i = 0; i < 1; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 16;
    static bool goodhel[ncomb] = {ncomb * false};
    //   static int ntry = 0, sum_hel = 0, ngood = 0;
    static int igood[ncomb];
    static int jhel;
    //   std::complex<double> * * wfs;
    double t[nprocesses];
    // Helicities for the process
    static const int helicities[ncomb][nexternal] = {
        {0, -1, -1, -1, -1}, {0, -1, -1, -1, 1}, {0, -1, -1, 1, -1},
        {0, -1, -1, 1, 1},   {0, -1, 1, -1, -1}, {0, -1, 1, -1, 1},
        {0, -1, 1, 1, -1},   {0, -1, 1, 1, 1},   {0, 1, -1, -1, -1},
        {0, 1, -1, -1, 1},   {0, 1, -1, 1, -1},  {0, 1, -1, 1, 1},
        {0, 1, 1, -1, -1},   {0, 1, 1, -1, 1},   {0, 1, 1, 1, -1},
        {0, 1, 1, 1, 1}};
    // Denominators: spins, colors and identical particles
    const int denominators[nprocesses] = {4};

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
                t[0] = matrix_2_h_mummupmummup();

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
            t[0] = matrix_2_h_mummupmummup();

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

double Spin0_SF::sigmaHat()
{
    // Select between the different processes
    if (id1 == 25 && id2 == 13) {
        // Add matrix elements for processes with beams (25, 13)
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

void Spin0_SF::calculate_wavefunctions(const int perm[], const int hel[])
{
    // Calculate wavefunctions for all processes
    //   int i, j;

    // Calculate all wavefunctions
    sxxxxx(p[perm[0]], -1, w[0]);
    oxxxxx(p[perm[1]], mME[1], hel[1], +1, w[1]);
    ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]);
    oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]);
    ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]);
    FFV2_3_3(w[2], w[1], pars->GC_32, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[5]);
    FFV1P0_3(w[2], w[1], pars->GC_3, pars->ZERO, pars->ZERO, w[6]);
    FFV1P0_3(w[4], w[3], pars->GC_3, pars->ZERO, pars->ZERO, w[7]);
    FFV2_3_3(w[4], w[3], pars->GC_32, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[8]);
    FFV2_3_3(w[4], w[1], pars->GC_32, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[9]);
    FFV1P0_3(w[4], w[1], pars->GC_3, pars->ZERO, pars->ZERO, w[10]);
    FFV1P0_3(w[2], w[3], pars->GC_3, pars->ZERO, pars->ZERO, w[11]);
    FFV2_3_3(w[2], w[3], pars->GC_32, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[12]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFVS1_2_0(w[4], w[3], w[5], w[0], pars->GC_14, pars->GC_15, amp[0]);
    VVS3_5_0(w[6], w[7], w[0], pars->GC_25, pars->GC_23, amp[1]);
    VVS1_5_0(w[6], w[8], w[0], pars->GC_26, pars->GC_24, amp[2]);
    VVS1_5_0(w[7], w[5], w[0], pars->GC_26, pars->GC_24, amp[3]);
    VVS3_4_5_0(w[5], w[8], w[0], pars->GC_20, pars->GC_8, pars->GC_19, amp[4]);
    FFVS1_2_0(w[2], w[3], w[9], w[0], pars->GC_14, pars->GC_15, amp[5]);
    VVS3_5_0(w[10], w[11], w[0], pars->GC_25, pars->GC_23, amp[6]);
    VVS1_5_0(w[10], w[12], w[0], pars->GC_26, pars->GC_24, amp[7]);
    VVS1_5_0(w[11], w[9], w[0], pars->GC_26, pars->GC_24, amp[8]);
    VVS3_4_5_0(w[9], w[12], w[0], pars->GC_20, pars->GC_8, pars->GC_19, amp[9]);
    FFVS1_2_0(w[4], w[1], w[12], w[0], pars->GC_14, pars->GC_15, amp[10]);
    FFVS1_2_0(w[2], w[1], w[8], w[0], pars->GC_14, pars->GC_15, amp[11]);
}
double Spin0_SF::matrix_2_h_mummupmummup()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 12;
    const int ncolor = 1;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1};
    static const double cf[ncolor][ncolor] = {{1}};

    // Calculate color flows
    jamp[0] = +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] - amp[5] - amp[6] -
              amp[7] - amp[8] - amp[9] - amp[10] + amp[11];

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
} // namespace MG5_HiggsPO_UFO
