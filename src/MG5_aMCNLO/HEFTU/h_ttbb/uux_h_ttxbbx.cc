//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "uux_h_ttxbbx.h"
#include "HelAmps_heft_updated_full.h"

namespace MG5_heft_updated_full
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u u~ > t t~ b b~ HIW=1 QED=2 HIG=1 @1

//--------------------------------------------------------------------------
// Initialize process.

void uux_h_ttxbbx::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    ntry = 0, sum_hel = 0, ngood = 0;
    pars = Parameters_HEFTU::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    //   pars->printIndependentParameters();
    //   pars->printIndependentCouplings();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MU);
    mME.push_back(pars->mdl_MU);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[6];
    for (int i = 0; i < namplitudes; ++i)
        amp[i] = 0;
}

void uux_h_ttxbbx::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_HEFTU::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MU);
    mME.push_back(pars->mdl_MU);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[6];
}

//--------------------------------------------------------------------------
// Update process.

void uux_h_ttxbbx::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MU);
    mME[1] = (pars->mdl_MU);
    mME[2] = (pars->mdl_MT);
    mME[3] = (pars->mdl_MT);
    mME[4] = (pars->mdl_MB);
    mME[5] = (pars->mdl_MB);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void uux_h_ttxbbx::sigmaKin()
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
    for (int i = 0; i < 6; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 64;
    static bool goodhel[ncomb] = {ncomb * false};
    //   static int ntry = 0, sum_hel = 0, ngood = 0;
    static int igood[ncomb];
    static int jhel;
    //   std::complex<double> * * wfs;
    double t[nprocesses];
    // Helicities for the process
    static const int helicities[ncomb][nexternal] = {
        {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 1},
        {-1, -1, -1, -1, 1, -1},  {-1, -1, -1, -1, 1, 1},
        {-1, -1, -1, 1, -1, -1},  {-1, -1, -1, 1, -1, 1},
        {-1, -1, -1, 1, 1, -1},   {-1, -1, -1, 1, 1, 1},
        {-1, -1, 1, -1, -1, -1},  {-1, -1, 1, -1, -1, 1},
        {-1, -1, 1, -1, 1, -1},   {-1, -1, 1, -1, 1, 1},
        {-1, -1, 1, 1, -1, -1},   {-1, -1, 1, 1, -1, 1},
        {-1, -1, 1, 1, 1, -1},    {-1, -1, 1, 1, 1, 1},
        {-1, 1, -1, -1, -1, -1},  {-1, 1, -1, -1, -1, 1},
        {-1, 1, -1, -1, 1, -1},   {-1, 1, -1, -1, 1, 1},
        {-1, 1, -1, 1, -1, -1},   {-1, 1, -1, 1, -1, 1},
        {-1, 1, -1, 1, 1, -1},    {-1, 1, -1, 1, 1, 1},
        {-1, 1, 1, -1, -1, -1},   {-1, 1, 1, -1, -1, 1},
        {-1, 1, 1, -1, 1, -1},    {-1, 1, 1, -1, 1, 1},
        {-1, 1, 1, 1, -1, -1},    {-1, 1, 1, 1, -1, 1},
        {-1, 1, 1, 1, 1, -1},     {-1, 1, 1, 1, 1, 1},
        {1, -1, -1, -1, -1, -1},  {1, -1, -1, -1, -1, 1},
        {1, -1, -1, -1, 1, -1},   {1, -1, -1, -1, 1, 1},
        {1, -1, -1, 1, -1, -1},   {1, -1, -1, 1, -1, 1},
        {1, -1, -1, 1, 1, -1},    {1, -1, -1, 1, 1, 1},
        {1, -1, 1, -1, -1, -1},   {1, -1, 1, -1, -1, 1},
        {1, -1, 1, -1, 1, -1},    {1, -1, 1, -1, 1, 1},
        {1, -1, 1, 1, -1, -1},    {1, -1, 1, 1, -1, 1},
        {1, -1, 1, 1, 1, -1},     {1, -1, 1, 1, 1, 1},
        {1, 1, -1, -1, -1, -1},   {1, 1, -1, -1, -1, 1},
        {1, 1, -1, -1, 1, -1},    {1, 1, -1, -1, 1, 1},
        {1, 1, -1, 1, -1, -1},    {1, 1, -1, 1, -1, 1},
        {1, 1, -1, 1, 1, -1},     {1, 1, -1, 1, 1, 1},
        {1, 1, 1, -1, -1, -1},    {1, 1, 1, -1, -1, 1},
        {1, 1, 1, -1, 1, -1},     {1, 1, 1, -1, 1, 1},
        {1, 1, 1, 1, -1, -1},     {1, 1, 1, 1, -1, 1},
        {1, 1, 1, 1, 1, -1},      {1, 1, 1, 1, 1, 1}};
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
                t[0] = matrix_1_uux_h_ttxbbx();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_1_uux_h_ttxbbx();
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
            t[0] = matrix_1_uux_h_ttxbbx();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_1_uux_h_ttxbbx();
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

double uux_h_ttxbbx::sigmaHat()
{
    // Select between the different processes
    if (id1 == 2 && id2 == -2) {
        // Add matrix elements for processes with beams (2, -2)
        return matrix_element[0];
    } else if (id1 == -2 && id2 == 2) {
        // Add matrix elements for processes with beams (-2, 2)
        return matrix_element[1];
    } else {
        // Return 0 if not correct initial state assignment
        return 0.;
    }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void uux_h_ttxbbx::calculate_wavefunctions(const int perm[], const int hel[])
{
    // Calculate wavefunctions for all processes
    //   int i, j;

    // Calculate all wavefunctions
    ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]);
    oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
    oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
    ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
    oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
    ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]);
//     FFV1P0_3(w[0], w[1], pars->GC_3, pars->ZERO, pars->ZERO, w[6]);
    FFV1P0_3(w[3], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[7]);
//     FFV1_1(w[4], w[6], pars->GC_2, pars->mdl_MB, pars->ZERO, w[8]);
//     FFV1_2(w[5], w[6], pars->GC_2, pars->mdl_MB, pars->ZERO, w[9]);
    FFV1P0_3(w[0], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[10]);
//     FFV1P0_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[11]);
    FFV1_1(w[4], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[12]);
    FFV1_2(w[5], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[13]);
    FFS2_3(w[3], w[2], pars->GC_80, pars->mdl_MH, pars->mdl_WH, w[14]);
//     FFV2_5_3(w[3], w[2], pars->GC_41, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
//              w[15]);
//     FFV2_5_3(w[0], w[1], pars->GC_41, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
//              w[16]);
//     FFV2_3_1(w[4], w[16], pars->GC_40, pars->GC_53, pars->mdl_MB, pars->ZERO,
//              w[17]);
//     FFV2_3_2(w[5], w[16], pars->GC_40, pars->GC_53, pars->mdl_MB, pars->ZERO,
//              w[18]);
    FFV1P0_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[19]);
    FFS2_3(w[5], w[4], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[20]);
//     FFV2_3(w[5], w[2], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[21]);
    FFV1_2(w[3], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[22]);
//     FFV2_3(w[3], w[4], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[23]);
    FFV1_1(w[2], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[24]);
//     FFV1_1(w[2], w[6], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[25]);
//     FFV1_2(w[3], w[6], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[26]);
//     FFV1P0_3(w[5], w[4], pars->GC_2, pars->ZERO, pars->ZERO, w[27]);
//     FFV2_3_3(w[5], w[4], pars->GC_40, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
//              w[28]);
//     FFV2_5_1(w[2], w[16], pars->GC_41, pars->GC_53, pars->mdl_MT, pars->mdl_WT,
//              w[29]);
//     FFV2_5_2(w[3], w[16], pars->GC_41, pars->GC_53, pars->mdl_MT, pars->mdl_WT,
//              w[30]);
//     FFV2_3(w[0], w[4], pars->GC_90, pars->mdl_MW, pars->mdl_WW, w[31]);
//     FFV2_1(w[1], w[31], pars->GC_33, pars->mdl_MB, pars->ZERO, w[32]);
//     FFV2_2(w[5], w[31], pars->GC_33, pars->mdl_MU, pars->ZERO, w[33]);
//     FFV2_3(w[5], w[1], pars->GC_33, pars->mdl_MW, pars->mdl_WW, w[34]);
//     FFV2_2(w[0], w[34], pars->GC_90, pars->mdl_MB, pars->ZERO, w[35]);
//     FFV1_2(w[0], w[7], pars->GC_11, pars->mdl_MU, pars->ZERO, w[36]);
//     FFV1_2(w[0], w[11], pars->GC_3, pars->mdl_MU, pars->ZERO, w[37]);
//     FFV1_2(w[0], w[19], pars->GC_11, pars->mdl_MU, pars->ZERO, w[38]);
//     FFV1_2(w[0], w[27], pars->GC_3, pars->mdl_MU, pars->ZERO, w[39]);
//     FFV2_5_2(w[0], w[28], pars->GC_41, pars->GC_53, pars->mdl_MU, pars->ZERO,
//              w[40]);
//     FFV2_5_2(w[0], w[15], pars->GC_41, pars->GC_53, pars->mdl_MU, pars->ZERO,
//              w[41]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
//     FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]);
//     FFV1_0(w[9], w[4], w[7], pars->GC_11, amp[1]);
//     FFV1_0(w[5], w[12], w[11], pars->GC_2, amp[2]);
//     FFV1_0(w[13], w[4], w[11], pars->GC_2, amp[3]);
//     FFV1_0(w[5], w[12], w[7], pars->GC_11, amp[4]);
//     FFV1_0(w[13], w[4], w[7], pars->GC_11, amp[5]);
    FFS2_0(w[5], w[12], w[14], pars->GC_74, amp[6]);
    FFS2_0(w[13], w[4], w[14], pars->GC_74, amp[7]);
//     FFV2_3_0(w[5], w[12], w[15], pars->GC_40, pars->GC_53, amp[8]);
//     FFV2_3_0(w[13], w[4], w[15], pars->GC_40, pars->GC_53, amp[9]);
//     FFV1_0(w[5], w[17], w[7], pars->GC_11, amp[10]);
//     FFV1_0(w[18], w[4], w[7], pars->GC_11, amp[11]);
//     VVV1_0(w[10], w[7], w[19], pars->GC_10, amp[12]);
    VVS3_0(w[10], w[7], w[20], pars->GC_13, amp[13]);
    VVS3_0(w[10], w[19], w[14], pars->GC_13, amp[14]);
//     FFV2_0(w[22], w[4], w[21], pars->GC_100, amp[15]);
//     FFV2_0(w[3], w[12], w[21], pars->GC_100, amp[16]);
//     FFV2_0(w[5], w[24], w[23], pars->GC_39, amp[17]);
//     FFV2_0(w[13], w[2], w[23], pars->GC_39, amp[18]);
//     FFV1_0(w[3], w[25], w[19], pars->GC_11, amp[19]);
//     FFV1_0(w[26], w[2], w[19], pars->GC_11, amp[20]);
//     FFV1_0(w[3], w[24], w[27], pars->GC_3, amp[21]);
//     FFV1_0(w[22], w[2], w[27], pars->GC_3, amp[22]);
//     FFV1_0(w[3], w[24], w[19], pars->GC_11, amp[23]);
//     FFV1_0(w[22], w[2], w[19], pars->GC_11, amp[24]);
    FFS2_0(w[3], w[24], w[20], pars->GC_80, amp[25]);
    FFS2_0(w[22], w[2], w[20], pars->GC_80, amp[26]);
//     FFV2_5_0(w[3], w[24], w[28], pars->GC_41, pars->GC_53, amp[27]);
//     FFV2_5_0(w[22], w[2], w[28], pars->GC_41, pars->GC_53, amp[28]);
//     FFV1_0(w[3], w[29], w[19], pars->GC_11, amp[29]);
//     FFV1_0(w[30], w[2], w[19], pars->GC_11, amp[30]);
//     FFV1_0(w[5], w[32], w[7], pars->GC_11, amp[31]);
//     FFV1_0(w[33], w[1], w[7], pars->GC_11, amp[32]);
//     FFV1_0(w[35], w[4], w[7], pars->GC_11, amp[33]);
//     FFV2_0(w[36], w[4], w[34], pars->GC_90, amp[34]);
//     FFV1_0(w[37], w[1], w[19], pars->GC_11, amp[35]);
//     FFV1_0(w[38], w[1], w[11], pars->GC_3, amp[36]);
//     FFV1_0(w[36], w[1], w[27], pars->GC_3, amp[37]);
//     FFV1_0(w[39], w[1], w[7], pars->GC_11, amp[38]);
//     FFV1_0(w[36], w[1], w[19], pars->GC_11, amp[39]);
//     FFV1_0(w[38], w[1], w[7], pars->GC_11, amp[40]);
//     FFV2_5_0(w[36], w[1], w[28], pars->GC_41, pars->GC_53, amp[41]);
//     FFV1_0(w[40], w[1], w[7], pars->GC_11, amp[42]);
//     FFV1_0(w[41], w[1], w[19], pars->GC_11, amp[43]);
//     FFV2_5_0(w[38], w[1], w[15], pars->GC_41, pars->GC_53, amp[44]);
}
double uux_h_ttxbbx::matrix_1_uux_h_ttxbbx()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 45;
    const int ncolor = 6;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1, 1, 1, 1, 1, 1};
    static const double cf[ncolor][ncolor] = {
        {27, 9, 9, 3, 3, 9}, {9, 27, 3, 9, 9, 3}, {9, 3, 27, 9, 9, 3},
        {3, 9, 9, 27, 3, 9}, {3, 9, 9, 3, 27, 9}, {9, 3, 3, 9, 9, 27}};

    // Calculate color flows
    jamp[0] = -1. / 6. * amp[0] - 1. / 6. * amp[1] - 1. / 6. * amp[2] -
              1. / 6. * amp[3] + 1. / 36. * amp[4] + 1. / 36. * amp[5] -
              1. / 6. * amp[6] - 1. / 6. * amp[7] - 1. / 6. * amp[8] -
              1. / 6. * amp[9] - 1. / 6. * amp[10] - 1. / 6. * amp[11] -
              1. / 6. * amp[13] - 1. / 6. * amp[14] - 1. / 6. * amp[19] -
              1. / 6. * amp[20] - 1. / 6. * amp[21] - 1. / 6. * amp[22] +
              1. / 36. * amp[23] + 1. / 36. * amp[24] - 1. / 6. * amp[25] -
              1. / 6. * amp[26] - 1. / 6. * amp[27] - 1. / 6. * amp[28] -
              1. / 6. * amp[29] - 1. / 6. * amp[30] - 1. / 6. * amp[35] -
              1. / 6. * amp[36] - 1. / 6. * amp[37] - 1. / 6. * amp[38] +
              1. / 36. * amp[39] + 1. / 36. * amp[40] - 1. / 6. * amp[41] -
              1. / 6. * amp[42] - 1. / 6. * amp[43] - 1. / 6. * amp[44];
    jamp[1] = +1. / 2. * amp[0] + 1. / 2. * amp[1] - 1. / 12. * amp[4] -
              1. / 12. * amp[5] + 1. / 2. * amp[10] + 1. / 2. * amp[11] +
              1. / 6. * amp[15] + 1. / 6. * amp[16] + 1. / 6. * amp[17] +
              1. / 6. * amp[18] + 1. / 2. * amp[19] + 1. / 2. * amp[20] -
              1. / 12. * amp[23] - 1. / 12. * amp[24] + 1. / 2. * amp[29] +
              1. / 2. * amp[30];
    jamp[2] = +1. / 2. * amp[13] + 1. / 2. * amp[21] + 1. / 2. * amp[22] -
              1. / 12. * amp[23] - 1. / 12. * amp[24] + 1. / 2. * amp[25] +
              1. / 2. * amp[26] + 1. / 2. * amp[27] + 1. / 2. * amp[28] +
              1. / 2. * amp[37] + 1. / 2. * amp[38] - 1. / 12. * amp[39] -
              1. / 12. * amp[40] + 1. / 2. * amp[41] + 1. / 2. * amp[42];
    jamp[3] = +1. / 4. * amp[4] -
              1. / 4. * std::complex<double>(0, 1) * amp[12] -
              1. / 2. * amp[15] - 1. / 2. * amp[16] + 1. / 4. * amp[24] -
              1. / 2. * amp[31] - 1. / 2. * amp[32] + 1. / 4. * amp[40];
    jamp[4] = +1. / 4. * amp[5] +
              1. / 4. * std::complex<double>(0, 1) * amp[12] -
              1. / 2. * amp[17] - 1. / 2. * amp[18] + 1. / 4. * amp[23] -
              1. / 2. * amp[33] - 1. / 2. * amp[34] + 1. / 4. * amp[39];
    jamp[5] = +1. / 2. * amp[2] + 1. / 2. * amp[3] - 1. / 12. * amp[4] -
              1. / 12. * amp[5] + 1. / 2. * amp[6] + 1. / 2. * amp[7] +
              1. / 2. * amp[8] + 1. / 2. * amp[9] + 1. / 2. * amp[14] +
              1. / 6. * amp[31] + 1. / 6. * amp[32] + 1. / 6. * amp[33] +
              1. / 6. * amp[34] + 1. / 2. * amp[35] + 1. / 2. * amp[36] -
              1. / 12. * amp[39] - 1. / 12. * amp[40] + 1. / 2. * amp[43] +
              1. / 2. * amp[44];

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
}
