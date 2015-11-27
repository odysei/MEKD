//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "gg_ttbb.h"
#include "HelAmps_sm_full.h"

namespace MG5_sm_full
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > t t~ b b~ QED=2 @1

//--------------------------------------------------------------------------
// Initialize process.

void gg_ttbb::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_sm_full::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    //   pars->printIndependentParameters();
    //   pars->printIndependentCouplings();
    // Set external particle masses for this matrix element
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[12];
}

void gg_ttbb::initProc()
{
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_sm_full::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[12];
}

//--------------------------------------------------------------------------
// Update process.

void gg_ttbb::updateProc()
{
    // Set external particle masses for this matrix element
    // Should correspond to initProc
    // 	mME[0] = (pars->mdl_MC);
    // 	mME[1] = (pars->mdl_MC);
    // 	mME[2] = (pars->mdl_MT);
    // 	mME[3] = (pars->mdl_MT);
    // 	mME[4] = (pars->mdl_MB);
    // 	mME[5] = (pars->mdl_MB);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void gg_ttbb::sigmaKin()
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
    for (int i = 0; i < 12; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 64;
    static bool goodhel[ncomb] = {ncomb * false};
    static int ntry = 0, sum_hel = 0, ngood = 0;
    static int igood[ncomb];
    static int jhel;
    std::complex<double> **wfs;
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
    const int denominators[nprocesses] = {256};

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
                t[0] = matrix_1_gg_ttxbbx();

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
            t[0] = matrix_1_gg_ttxbbx();

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

double gg_ttbb::sigmaHat()
{
    // Select between the different processes
    if (id1 == 21 && id2 == 21) {
        // Add matrix elements for processes with beams (21, 21)
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

void gg_ttbb::calculate_wavefunctions(const int perm[], const int hel[])
{
    // Calculate wavefunctions for all processes
    int i, j;

    // Calculate all wavefunctions
    vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]);
    vxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
    oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
    ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
    oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
    ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]);
    VVV1P0_1(w[0], w[1], pars->GC_10, pars->ZERO, pars->ZERO, w[6]);
    FFV1P0_3(w[3], w[2], pars->GC_2, pars->ZERO, pars->ZERO, w[7]);
    FFV1_1(w[4], w[6], pars->GC_11, pars->mdl_MB, pars->ZERO, w[8]);
    FFV1_2(w[5], w[6], pars->GC_11, pars->mdl_MB, pars->ZERO, w[9]);
    FFV1P0_3(w[3], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[10]);
    FFS4_3(w[3], w[2], pars->GC_94, pars->mdl_MH, pars->mdl_WH, w[11]);
    FFV2_5_3(w[3], w[2], pars->GC_51, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[12]);
    FFV1P0_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[13]);
    FFV2_3(w[5], w[2], pars->GC_49, pars->mdl_MW, pars->mdl_WW, w[14]);
    FFV1_2(w[3], w[6], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[15]);
    FFV2_3(w[3], w[4], pars->GC_108, pars->mdl_MW, pars->mdl_WW, w[16]);
    FFV1_1(w[2], w[6], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[17]);
    FFV1P0_3(w[5], w[4], pars->GC_1, pars->ZERO, pars->ZERO, w[18]);
    FFS4_3(w[5], w[4], pars->GC_83, pars->mdl_MH, pars->mdl_WH, w[19]);
    FFV2_3_3(w[5], w[4], pars->GC_50, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[20]);
    FFV1_1(w[2], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[21]);
    FFV1_2(w[3], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[22]);
    FFV2_3(w[5], w[21], pars->GC_49, pars->mdl_MW, pars->mdl_WW, w[23]);
    FFV1_1(w[4], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[24]);
    FFV1P0_3(w[3], w[21], pars->GC_2, pars->ZERO, pars->ZERO, w[25]);
    FFV1P0_3(w[3], w[21], pars->GC_11, pars->ZERO, pars->ZERO, w[26]);
    FFS4_3(w[3], w[21], pars->GC_94, pars->mdl_MH, pars->mdl_WH, w[27]);
    FFV2_5_3(w[3], w[21], pars->GC_51, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[28]);
    FFV1_2(w[5], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[29]);
    FFV1_1(w[21], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[30]);
    FFV1_2(w[3], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[31]);
    FFV1_1(w[2], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[32]);
    FFV2_3(w[31], w[4], pars->GC_108, pars->mdl_MW, pars->mdl_WW, w[33]);
    FFV1P0_3(w[31], w[2], pars->GC_2, pars->ZERO, pars->ZERO, w[34]);
    FFV1P0_3(w[31], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[35]);
    FFS4_3(w[31], w[2], pars->GC_94, pars->mdl_MH, pars->mdl_WH, w[36]);
    FFV2_5_3(w[31], w[2], pars->GC_51, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[37]);
    FFV1_2(w[31], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[38]);
    FFV1_1(w[4], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[39]);
    FFV2_3(w[3], w[39], pars->GC_108, pars->mdl_MW, pars->mdl_WW, w[40]);
    FFV1P0_3(w[5], w[39], pars->GC_1, pars->ZERO, pars->ZERO, w[41]);
    FFV1P0_3(w[5], w[39], pars->GC_11, pars->ZERO, pars->ZERO, w[42]);
    FFS4_3(w[5], w[39], pars->GC_83, pars->mdl_MH, pars->mdl_WH, w[43]);
    FFV2_3_3(w[5], w[39], pars->GC_50, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[44]);
    FFV1_1(w[39], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[45]);
    FFV1_2(w[5], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[46]);
    FFV1P0_3(w[46], w[4], pars->GC_1, pars->ZERO, pars->ZERO, w[47]);
    FFV1P0_3(w[46], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[48]);
    FFS4_3(w[46], w[4], pars->GC_83, pars->mdl_MH, pars->mdl_WH, w[49]);
    FFV2_3_3(w[46], w[4], pars->GC_50, pars->GC_58, pars->mdl_MZ, pars->mdl_WZ,
             w[50]);
    FFV2_3(w[46], w[2], pars->GC_49, pars->mdl_MW, pars->mdl_WW, w[51]);
    FFV1_2(w[46], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[52]);
    FFV1_1(w[32], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[53]);
    VVV1P0_1(w[0], w[13], pars->GC_10, pars->ZERO, pars->ZERO, w[54]);
    FFV1_2(w[22], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[55]);
    FFV1_1(w[24], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[56]);
    VVV1P0_1(w[0], w[10], pars->GC_10, pars->ZERO, pars->ZERO, w[57]);
    FFV1_2(w[29], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[58]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV1_0(w[5], w[8], w[7], pars->GC_1, amp[0]);
    FFV1_0(w[9], w[4], w[7], pars->GC_1, amp[1]);
    FFV1_0(w[5], w[8], w[10], pars->GC_11, amp[2]);
    FFV1_0(w[9], w[4], w[10], pars->GC_11, amp[3]);
    FFS4_0(w[5], w[8], w[11], pars->GC_83, amp[4]);
    FFS4_0(w[9], w[4], w[11], pars->GC_83, amp[5]);
    FFV2_3_0(w[5], w[8], w[12], pars->GC_50, pars->GC_58, amp[6]);
    FFV2_3_0(w[9], w[4], w[12], pars->GC_50, pars->GC_58, amp[7]);
    VVV1_0(w[6], w[10], w[13], pars->GC_10, amp[8]);
    FFV2_0(w[15], w[4], w[14], pars->GC_108, amp[9]);
    FFV2_0(w[3], w[8], w[14], pars->GC_108, amp[10]);
    FFV2_0(w[5], w[17], w[16], pars->GC_49, amp[11]);
    FFV2_0(w[9], w[2], w[16], pars->GC_49, amp[12]);
    FFV1_0(w[3], w[17], w[18], pars->GC_2, amp[13]);
    FFV1_0(w[15], w[2], w[18], pars->GC_2, amp[14]);
    FFV1_0(w[3], w[17], w[13], pars->GC_11, amp[15]);
    FFV1_0(w[15], w[2], w[13], pars->GC_11, amp[16]);
    FFS4_0(w[3], w[17], w[19], pars->GC_94, amp[17]);
    FFS4_0(w[15], w[2], w[19], pars->GC_94, amp[18]);
    FFV2_5_0(w[3], w[17], w[20], pars->GC_51, pars->GC_58, amp[19]);
    FFV2_5_0(w[15], w[2], w[20], pars->GC_51, pars->GC_58, amp[20]);
    FFV2_0(w[22], w[4], w[23], pars->GC_108, amp[21]);
    FFV1_0(w[22], w[21], w[18], pars->GC_2, amp[22]);
    FFV1_0(w[22], w[21], w[13], pars->GC_11, amp[23]);
    FFS4_0(w[22], w[21], w[19], pars->GC_94, amp[24]);
    FFV2_5_0(w[22], w[21], w[20], pars->GC_51, pars->GC_58, amp[25]);
    FFV1_0(w[5], w[24], w[25], pars->GC_1, amp[26]);
    FFV1_0(w[5], w[24], w[26], pars->GC_11, amp[27]);
    FFS4_0(w[5], w[24], w[27], pars->GC_83, amp[28]);
    FFV2_3_0(w[5], w[24], w[28], pars->GC_50, pars->GC_58, amp[29]);
    FFV2_0(w[3], w[24], w[23], pars->GC_108, amp[30]);
    FFV1_0(w[29], w[4], w[25], pars->GC_1, amp[31]);
    FFV1_0(w[29], w[4], w[26], pars->GC_11, amp[32]);
    FFS4_0(w[29], w[4], w[27], pars->GC_83, amp[33]);
    FFV2_3_0(w[29], w[4], w[28], pars->GC_50, pars->GC_58, amp[34]);
    FFV2_0(w[29], w[21], w[16], pars->GC_49, amp[35]);
    FFV2_0(w[5], w[30], w[16], pars->GC_49, amp[36]);
    FFV1_0(w[3], w[30], w[18], pars->GC_2, amp[37]);
    FFV1_0(w[3], w[30], w[13], pars->GC_11, amp[38]);
    VVV1_0(w[1], w[13], w[26], pars->GC_10, amp[39]);
    FFS4_0(w[3], w[30], w[19], pars->GC_94, amp[40]);
    FFV2_5_0(w[3], w[30], w[20], pars->GC_51, pars->GC_58, amp[41]);
    FFV2_0(w[5], w[32], w[33], pars->GC_49, amp[42]);
    FFV1_0(w[31], w[32], w[18], pars->GC_2, amp[43]);
    FFV1_0(w[31], w[32], w[13], pars->GC_11, amp[44]);
    FFS4_0(w[31], w[32], w[19], pars->GC_94, amp[45]);
    FFV2_5_0(w[31], w[32], w[20], pars->GC_51, pars->GC_58, amp[46]);
    FFV1_0(w[5], w[24], w[34], pars->GC_1, amp[47]);
    FFV1_0(w[5], w[24], w[35], pars->GC_11, amp[48]);
    FFS4_0(w[5], w[24], w[36], pars->GC_83, amp[49]);
    FFV2_3_0(w[5], w[24], w[37], pars->GC_50, pars->GC_58, amp[50]);
    FFV2_0(w[31], w[24], w[14], pars->GC_108, amp[51]);
    FFV1_0(w[29], w[4], w[34], pars->GC_1, amp[52]);
    FFV1_0(w[29], w[4], w[35], pars->GC_11, amp[53]);
    FFS4_0(w[29], w[4], w[36], pars->GC_83, amp[54]);
    FFV2_3_0(w[29], w[4], w[37], pars->GC_50, pars->GC_58, amp[55]);
    FFV2_0(w[29], w[2], w[33], pars->GC_49, amp[56]);
    FFV2_0(w[38], w[4], w[14], pars->GC_108, amp[57]);
    FFV1_0(w[38], w[2], w[18], pars->GC_2, amp[58]);
    FFV1_0(w[38], w[2], w[13], pars->GC_11, amp[59]);
    VVV1_0(w[1], w[13], w[35], pars->GC_10, amp[60]);
    FFS4_0(w[38], w[2], w[19], pars->GC_94, amp[61]);
    FFV2_5_0(w[38], w[2], w[20], pars->GC_51, pars->GC_58, amp[62]);
    FFV2_0(w[5], w[32], w[40], pars->GC_49, amp[63]);
    FFV1_0(w[3], w[32], w[41], pars->GC_2, amp[64]);
    FFV1_0(w[3], w[32], w[42], pars->GC_11, amp[65]);
    FFS4_0(w[3], w[32], w[43], pars->GC_94, amp[66]);
    FFV2_5_0(w[3], w[32], w[44], pars->GC_51, pars->GC_58, amp[67]);
    FFV1_0(w[22], w[2], w[41], pars->GC_2, amp[68]);
    FFV1_0(w[22], w[2], w[42], pars->GC_11, amp[69]);
    FFS4_0(w[22], w[2], w[43], pars->GC_94, amp[70]);
    FFV2_5_0(w[22], w[2], w[44], pars->GC_51, pars->GC_58, amp[71]);
    FFV2_0(w[22], w[39], w[14], pars->GC_108, amp[72]);
    FFV2_0(w[29], w[2], w[40], pars->GC_49, amp[73]);
    FFV1_0(w[29], w[39], w[7], pars->GC_1, amp[74]);
    FFV1_0(w[29], w[39], w[10], pars->GC_11, amp[75]);
    FFS4_0(w[29], w[39], w[11], pars->GC_83, amp[76]);
    FFV2_3_0(w[29], w[39], w[12], pars->GC_50, pars->GC_58, amp[77]);
    FFV1_0(w[5], w[45], w[7], pars->GC_1, amp[78]);
    FFV1_0(w[5], w[45], w[10], pars->GC_11, amp[79]);
    VVV1_0(w[1], w[10], w[42], pars->GC_10, amp[80]);
    FFS4_0(w[5], w[45], w[11], pars->GC_83, amp[81]);
    FFV2_3_0(w[5], w[45], w[12], pars->GC_50, pars->GC_58, amp[82]);
    FFV2_0(w[3], w[45], w[14], pars->GC_108, amp[83]);
    FFV1_0(w[3], w[32], w[47], pars->GC_2, amp[84]);
    FFV1_0(w[3], w[32], w[48], pars->GC_11, amp[85]);
    FFS4_0(w[3], w[32], w[49], pars->GC_94, amp[86]);
    FFV2_5_0(w[3], w[32], w[50], pars->GC_51, pars->GC_58, amp[87]);
    FFV2_0(w[46], w[32], w[16], pars->GC_49, amp[88]);
    FFV2_0(w[22], w[4], w[51], pars->GC_108, amp[89]);
    FFV1_0(w[22], w[2], w[47], pars->GC_2, amp[90]);
    FFV1_0(w[22], w[2], w[48], pars->GC_11, amp[91]);
    FFS4_0(w[22], w[2], w[49], pars->GC_94, amp[92]);
    FFV2_5_0(w[22], w[2], w[50], pars->GC_51, pars->GC_58, amp[93]);
    FFV2_0(w[3], w[24], w[51], pars->GC_108, amp[94]);
    FFV1_0(w[46], w[24], w[7], pars->GC_1, amp[95]);
    FFV1_0(w[46], w[24], w[10], pars->GC_11, amp[96]);
    FFS4_0(w[46], w[24], w[11], pars->GC_83, amp[97]);
    FFV2_3_0(w[46], w[24], w[12], pars->GC_50, pars->GC_58, amp[98]);
    FFV1_0(w[52], w[4], w[7], pars->GC_1, amp[99]);
    FFV1_0(w[52], w[4], w[10], pars->GC_11, amp[100]);
    VVV1_0(w[1], w[10], w[48], pars->GC_10, amp[101]);
    FFS4_0(w[52], w[4], w[11], pars->GC_83, amp[102]);
    FFV2_3_0(w[52], w[4], w[12], pars->GC_50, pars->GC_58, amp[103]);
    FFV2_0(w[52], w[2], w[16], pars->GC_49, amp[104]);
    FFV2_0(w[5], w[53], w[16], pars->GC_49, amp[105]);
    FFV1_0(w[3], w[53], w[18], pars->GC_2, amp[106]);
    FFV1_0(w[3], w[53], w[13], pars->GC_11, amp[107]);
    FFV1_0(w[3], w[32], w[54], pars->GC_11, amp[108]);
    FFS4_0(w[3], w[53], w[19], pars->GC_94, amp[109]);
    FFV2_5_0(w[3], w[53], w[20], pars->GC_51, pars->GC_58, amp[110]);
    FFV2_0(w[55], w[4], w[14], pars->GC_108, amp[111]);
    FFV1_0(w[55], w[2], w[18], pars->GC_2, amp[112]);
    FFV1_0(w[55], w[2], w[13], pars->GC_11, amp[113]);
    FFV1_0(w[22], w[2], w[54], pars->GC_11, amp[114]);
    FFS4_0(w[55], w[2], w[19], pars->GC_94, amp[115]);
    FFV2_5_0(w[55], w[2], w[20], pars->GC_51, pars->GC_58, amp[116]);
    FFV1_0(w[5], w[56], w[7], pars->GC_1, amp[117]);
    FFV1_0(w[5], w[56], w[10], pars->GC_11, amp[118]);
    FFV1_0(w[5], w[24], w[57], pars->GC_11, amp[119]);
    FFS4_0(w[5], w[56], w[11], pars->GC_83, amp[120]);
    FFV2_3_0(w[5], w[56], w[12], pars->GC_50, pars->GC_58, amp[121]);
    FFV2_0(w[3], w[56], w[14], pars->GC_108, amp[122]);
    FFV1_0(w[58], w[4], w[7], pars->GC_1, amp[123]);
    FFV1_0(w[58], w[4], w[10], pars->GC_11, amp[124]);
    FFV1_0(w[29], w[4], w[57], pars->GC_11, amp[125]);
    FFS4_0(w[58], w[4], w[11], pars->GC_83, amp[126]);
    FFV2_3_0(w[58], w[4], w[12], pars->GC_50, pars->GC_58, amp[127]);
    FFV2_0(w[58], w[2], w[16], pars->GC_49, amp[128]);
    VVVV1_0(w[0], w[1], w[10], w[13], pars->GC_12, amp[129]);
    VVVV3_0(w[0], w[1], w[10], w[13], pars->GC_12, amp[130]);
    VVVV4_0(w[0], w[1], w[10], w[13], pars->GC_12, amp[131]);
    VVV1_0(w[1], w[13], w[57], pars->GC_10, amp[132]);
    VVV1_0(w[1], w[10], w[54], pars->GC_10, amp[133]);
}
double gg_ttbb::matrix_1_gg_ttxbbx()
{
    int i, j;
    // Local variables
    const int ngraphs = 134;
    const int ncolor = 12;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    static const double cf[ncolor][ncolor] = {
        {48, 16, 16, 6, 0, 16, -2, 0, -6, -2, -2, 6},
        {16, 48, 6, 16, 16, 0, 0, -2, -2, -6, 6, -2},
        {16, 6, 48, 16, -2, 0, 0, 16, -2, 6, -6, -2},
        {6, 16, 16, 48, 0, -2, 16, 0, 6, -2, -2, -6},
        {0, 16, -2, 0, 48, 16, 16, 6, 0, -2, 16, 0},
        {16, 0, 0, -2, 16, 48, 6, 16, -2, 0, 0, 16},
        {-2, 0, 0, 16, 16, 6, 48, 16, 16, 0, 0, -2},
        {0, -2, 16, 0, 6, 16, 16, 48, 0, 16, -2, 0},
        {-6, -2, -2, 6, 0, -2, 16, 0, 48, 16, 16, 6},
        {-2, -6, 6, -2, -2, 0, 0, 16, 16, 48, 6, 16},
        {-2, 6, -6, -2, 16, 0, 0, -2, 16, 6, 48, 16},
        {6, -2, -2, -6, 0, 16, -2, 0, 6, 16, 16, 48}};

    // Calculate color flows
    jamp[0] = -std::complex<double>(0, 1) * amp[13] -
              std::complex<double>(0, 1) * amp[14] +
              1. / 6. * std::complex<double>(0, 1) * amp[15] +
              1. / 6. * std::complex<double>(0, 1) * amp[16] -
              std::complex<double>(0, 1) * amp[17] -
              std::complex<double>(0, 1) * amp[18] -
              std::complex<double>(0, 1) * amp[19] -
              std::complex<double>(0, 1) * amp[20] + amp[22] -
              1. / 6. * amp[23] + amp[24] + amp[25] + amp[37] -
              1. / 6. * amp[38] + amp[40] + amp[41] + amp[112] -
              1. / 6. * amp[113] + amp[115] + amp[116];
    jamp[1] = -1. / 2. * std::complex<double>(0, 1) * amp[3] +
              1. / 2. * amp[8] + std::complex<double>(0, 1) * amp[11] +
              std::complex<double>(0, 1) * amp[12] -
              1. / 2. * std::complex<double>(0, 1) * amp[15] +
              1. / 2. * amp[32] - amp[35] - amp[36] + 1. / 2. * amp[38] -
              1. / 2. * std::complex<double>(0, 1) * amp[39] +
              1. / 2. * amp[124] +
              1. / 2. * std::complex<double>(0, 1) * amp[125] - amp[128] +
              1. / 2. * amp[129] + 1. / 2. * amp[130] + 1. / 2. * amp[132];
    jamp[2] = -1. / 2. * std::complex<double>(0, 1) * amp[2] -
              1. / 2. * amp[8] + std::complex<double>(0, 1) * amp[9] +
              std::complex<double>(0, 1) * amp[10] -
              1. / 2. * std::complex<double>(0, 1) * amp[16] +
              1. / 2. * amp[69] - amp[72] + 1. / 2. * amp[79] -
              1. / 2. * std::complex<double>(0, 1) * amp[80] - amp[83] -
              amp[111] + 1. / 2. * amp[113] +
              1. / 2. * std::complex<double>(0, 1) * amp[114] -
              1. / 2. * amp[129] + 1. / 2. * amp[131] + 1. / 2. * amp[133];
    jamp[3] = -std::complex<double>(0, 1) * amp[0] -
              std::complex<double>(0, 1) * amp[1] +
              1. / 6. * std::complex<double>(0, 1) * amp[2] +
              1. / 6. * std::complex<double>(0, 1) * amp[3] -
              std::complex<double>(0, 1) * amp[4] -
              std::complex<double>(0, 1) * amp[5] -
              std::complex<double>(0, 1) * amp[6] -
              std::complex<double>(0, 1) * amp[7] + amp[74] -
              1. / 6. * amp[75] + amp[76] + amp[77] + amp[78] -
              1. / 6. * amp[79] + amp[81] + amp[82] + amp[123] -
              1. / 6. * amp[124] + amp[126] + amp[127];
    jamp[4] = +amp[26] - 1. / 6. * amp[27] + amp[28] + amp[29] + amp[31] -
              1. / 6. * amp[32] + amp[33] + amp[34] + amp[47] -
              1. / 6. * amp[48] + amp[49] + amp[50] + amp[52] -
              1. / 6. * amp[53] + amp[54] + amp[55];
    jamp[5] = -amp[21] + 1. / 2. * amp[23] + 1. / 2. * amp[27] - amp[30] +
              1. / 2. * std::complex<double>(0, 1) * amp[39] - amp[89] +
              1. / 2. * amp[91] - amp[94] + 1. / 2. * amp[96] -
              1. / 2. * std::complex<double>(0, 1) * amp[101] -
              1. / 2. * std::complex<double>(0, 1) * amp[114] +
              1. / 2. * std::complex<double>(0, 1) * amp[119] -
              1. / 2. * amp[130] - 1. / 2. * amp[131] - 1. / 2. * amp[132] -
              1. / 2. * amp[133];
    jamp[6] = -amp[42] + 1. / 2. * amp[44] + 1. / 2. * amp[53] - amp[56] -
              1. / 2. * std::complex<double>(0, 1) * amp[60] - amp[63] +
              1. / 2. * amp[65] - amp[73] + 1. / 2. * amp[75] +
              1. / 2. * std::complex<double>(0, 1) * amp[80] +
              1. / 2. * std::complex<double>(0, 1) * amp[108] -
              1. / 2. * std::complex<double>(0, 1) * amp[125] -
              1. / 2. * amp[130] - 1. / 2. * amp[131] - 1. / 2. * amp[132] -
              1. / 2. * amp[133];
    jamp[7] = +amp[64] - 1. / 6. * amp[65] + amp[66] + amp[67] + amp[68] -
              1. / 6. * amp[69] + amp[70] + amp[71] + amp[84] -
              1. / 6. * amp[85] + amp[86] + amp[87] + amp[90] -
              1. / 6. * amp[91] + amp[92] + amp[93];
    jamp[8] = +std::complex<double>(0, 1) * amp[13] +
              std::complex<double>(0, 1) * amp[14] -
              1. / 6. * std::complex<double>(0, 1) * amp[15] -
              1. / 6. * std::complex<double>(0, 1) * amp[16] +
              std::complex<double>(0, 1) * amp[17] +
              std::complex<double>(0, 1) * amp[18] +
              std::complex<double>(0, 1) * amp[19] +
              std::complex<double>(0, 1) * amp[20] + amp[43] -
              1. / 6. * amp[44] + amp[45] + amp[46] + amp[58] -
              1. / 6. * amp[59] + amp[61] + amp[62] + amp[106] -
              1. / 6. * amp[107] + amp[109] + amp[110];
    jamp[9] = +1. / 2. * std::complex<double>(0, 1) * amp[3] -
              1. / 2. * amp[8] - std::complex<double>(0, 1) * amp[11] -
              std::complex<double>(0, 1) * amp[12] +
              1. / 2. * std::complex<double>(0, 1) * amp[15] +
              1. / 2. * amp[85] - amp[88] + 1. / 2. * amp[100] +
              1. / 2. * std::complex<double>(0, 1) * amp[101] - amp[104] -
              amp[105] + 1. / 2. * amp[107] -
              1. / 2. * std::complex<double>(0, 1) * amp[108] -
              1. / 2. * amp[129] + 1. / 2. * amp[131] + 1. / 2. * amp[133];
    jamp[10] = +1. / 2. * std::complex<double>(0, 1) * amp[2] +
               1. / 2. * amp[8] - std::complex<double>(0, 1) * amp[9] -
               std::complex<double>(0, 1) * amp[10] +
               1. / 2. * std::complex<double>(0, 1) * amp[16] +
               1. / 2. * amp[48] - amp[51] - amp[57] + 1. / 2. * amp[59] +
               1. / 2. * std::complex<double>(0, 1) * amp[60] +
               1. / 2. * amp[118] -
               1. / 2. * std::complex<double>(0, 1) * amp[119] - amp[122] +
               1. / 2. * amp[129] + 1. / 2. * amp[130] + 1. / 2. * amp[132];
    jamp[11] = +std::complex<double>(0, 1) * amp[0] +
               std::complex<double>(0, 1) * amp[1] -
               1. / 6. * std::complex<double>(0, 1) * amp[2] -
               1. / 6. * std::complex<double>(0, 1) * amp[3] +
               std::complex<double>(0, 1) * amp[4] +
               std::complex<double>(0, 1) * amp[5] +
               std::complex<double>(0, 1) * amp[6] +
               std::complex<double>(0, 1) * amp[7] + amp[95] -
               1. / 6. * amp[96] + amp[97] + amp[98] + amp[99] -
               1. / 6. * amp[100] + amp[102] + amp[103] + amp[117] -
               1. / 6. * amp[118] + amp[120] + amp[121];

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
