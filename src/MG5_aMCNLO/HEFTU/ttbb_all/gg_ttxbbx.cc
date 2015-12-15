//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "gg_ttxbbx.h"
#include "HelAmps_heft_updated_full.h"

namespace MG5_heft_updated_full
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > t t~ b b~ HIW=1 QED=2 HIG=1 @1

//--------------------------------------------------------------------------
// Initialize process.

void gg_ttxbbx::initProc(string param_card_name)
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
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[14];
}

void gg_ttxbbx::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_HEFTU::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[14];
}

//--------------------------------------------------------------------------
// Update process.

void gg_ttxbbx::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->ZERO);
    mME[1] = (pars->ZERO);
    mME[2] = (pars->mdl_MT);
    mME[3] = (pars->mdl_MT);
    mME[4] = (pars->mdl_MB);
    mME[5] = (pars->mdl_MB);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void gg_ttxbbx::sigmaKin()
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
    for (int i = 0; i < 14; i++)
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

double gg_ttxbbx::sigmaHat()
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

void gg_ttxbbx::calculate_wavefunctions(const int perm[], const int hel[])
{
    // Calculate wavefunctions for all processes
    //   int i, j;

    // Calculate all wavefunctions
    vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]);
    vxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
    oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
    ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
    oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
    ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]);
    VVS3_3(w[0], w[1], pars->GC_13, pars->mdl_MH, pars->mdl_WH, w[6]);
    FFV1P0_3(w[3], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[7]);
    FFS2_1(w[4], w[6], pars->GC_74, pars->mdl_MB, pars->ZERO, w[8]);
    FFS2_2(w[5], w[6], pars->GC_74, pars->mdl_MB, pars->ZERO, w[9]);
    VVV1P0_1(w[0], w[1], pars->GC_10, pars->ZERO, pars->ZERO, w[10]);
    FFV1P0_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[11]);
    FFV1_1(w[4], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[12]);
    FFV1_2(w[5], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[13]);
    FFS2_3(w[3], w[2], pars->GC_80, pars->mdl_MH, pars->mdl_WH, w[14]);
    FFV2_5_3(w[3], w[2], pars->GC_41, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[15]);
    FFV1P0_3(w[5], w[4], pars->GC_2, pars->ZERO, pars->ZERO, w[16]);
    FFV1P0_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[17]);
    FFS2_3(w[5], w[4], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[18]);
    FFV2_3(w[5], w[2], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[19]);
    FFV1_2(w[3], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[20]);
    FFV2_3(w[3], w[4], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[21]);
    FFV1_1(w[2], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[22]);
    FFS2_1(w[2], w[6], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[23]);
    FFS2_2(w[3], w[6], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[24]);
    FFV2_3_3(w[5], w[4], pars->GC_40, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[25]);
    FFV1_1(w[2], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[26]);
    FFV1_2(w[3], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[27]);
    FFV2_3(w[5], w[26], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[28]);
    FFV1_1(w[4], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[29]);
    FFV1P0_3(w[3], w[26], pars->GC_3, pars->ZERO, pars->ZERO, w[30]);
    FFV1P0_3(w[3], w[26], pars->GC_11, pars->ZERO, pars->ZERO, w[31]);
    FFS2_3(w[3], w[26], pars->GC_80, pars->mdl_MH, pars->mdl_WH, w[32]);
    FFV2_5_3(w[3], w[26], pars->GC_41, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[33]);
    FFV1_2(w[5], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[34]);
    FFV1_1(w[26], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[35]);
    FFV1_2(w[3], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[36]);
    FFV1_1(w[2], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[37]);
    FFV2_3(w[36], w[4], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[38]);
    FFV1P0_3(w[36], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[39]);
    FFV1P0_3(w[36], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[40]);
    FFS2_3(w[36], w[2], pars->GC_80, pars->mdl_MH, pars->mdl_WH, w[41]);
    FFV2_5_3(w[36], w[2], pars->GC_41, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[42]);
    FFV1_2(w[36], w[1], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[43]);
    FFV1_1(w[4], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[44]);
    FFV2_3(w[3], w[44], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[45]);
    FFV1P0_3(w[5], w[44], pars->GC_2, pars->ZERO, pars->ZERO, w[46]);
    FFV1P0_3(w[5], w[44], pars->GC_11, pars->ZERO, pars->ZERO, w[47]);
    FFS2_3(w[5], w[44], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[48]);
    FFV2_3_3(w[5], w[44], pars->GC_40, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[49]);
    FFV1_1(w[44], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[50]);
    FFV1_2(w[5], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[51]);
    FFV1P0_3(w[51], w[4], pars->GC_2, pars->ZERO, pars->ZERO, w[52]);
    FFV1P0_3(w[51], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[53]);
    FFS2_3(w[51], w[4], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[54]);
    FFV2_3_3(w[51], w[4], pars->GC_40, pars->GC_53, pars->mdl_MZ, pars->mdl_WZ,
             w[55]);
    FFV2_3(w[51], w[2], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[56]);
    FFV1_2(w[51], w[1], pars->GC_11, pars->mdl_MB, pars->ZERO, w[57]);
    FFV1_1(w[37], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[58]);
    VVS3_3(w[0], w[17], pars->GC_13, pars->mdl_MH, pars->mdl_WH, w[59]);
    VVV1P0_1(w[0], w[17], pars->GC_10, pars->ZERO, pars->ZERO, w[60]);
    VVS3P0_1(w[0], w[18], pars->GC_13, pars->ZERO, pars->ZERO, w[61]);
    FFV1_2(w[27], w[0], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[62]);
    FFV1_1(w[29], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[63]);
    VVS3_3(w[0], w[7], pars->GC_13, pars->mdl_MH, pars->mdl_WH, w[64]);
    VVV1P0_1(w[0], w[7], pars->GC_10, pars->ZERO, pars->ZERO, w[65]);
    VVS3P0_1(w[0], w[14], pars->GC_13, pars->ZERO, pars->ZERO, w[66]);
    FFV1_2(w[34], w[0], pars->GC_11, pars->mdl_MB, pars->ZERO, w[67]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]);
    FFV1_0(w[9], w[4], w[7], pars->GC_11, amp[1]);
    FFV1_0(w[5], w[12], w[11], pars->GC_2, amp[2]);
    FFV1_0(w[13], w[4], w[11], pars->GC_2, amp[3]);
    FFV1_0(w[5], w[12], w[7], pars->GC_11, amp[4]);
    FFV1_0(w[13], w[4], w[7], pars->GC_11, amp[5]);
    FFS2_0(w[5], w[12], w[14], pars->GC_74, amp[6]);
    FFS2_0(w[13], w[4], w[14], pars->GC_74, amp[7]);
    FFV2_3_0(w[5], w[12], w[15], pars->GC_40, pars->GC_53, amp[8]);
    FFV2_3_0(w[13], w[4], w[15], pars->GC_40, pars->GC_53, amp[9]);
    VVS3_0(w[11], w[16], w[6], pars->GC_1, amp[10]);
    VVV1_0(w[10], w[7], w[17], pars->GC_10, amp[11]);
    VVS3_0(w[10], w[7], w[18], pars->GC_13, amp[12]);
    VVS3_0(w[10], w[17], w[14], pars->GC_13, amp[13]);
    FFV2_0(w[20], w[4], w[19], pars->GC_100, amp[14]);
    FFV2_0(w[3], w[12], w[19], pars->GC_100, amp[15]);
    FFV2_0(w[5], w[22], w[21], pars->GC_39, amp[16]);
    FFV2_0(w[13], w[2], w[21], pars->GC_39, amp[17]);
    FFV1_0(w[3], w[23], w[17], pars->GC_11, amp[18]);
    FFV1_0(w[24], w[2], w[17], pars->GC_11, amp[19]);
    FFV1_0(w[3], w[22], w[16], pars->GC_3, amp[20]);
    FFV1_0(w[20], w[2], w[16], pars->GC_3, amp[21]);
    FFV1_0(w[3], w[22], w[17], pars->GC_11, amp[22]);
    FFV1_0(w[20], w[2], w[17], pars->GC_11, amp[23]);
    FFS2_0(w[3], w[22], w[18], pars->GC_80, amp[24]);
    FFS2_0(w[20], w[2], w[18], pars->GC_80, amp[25]);
    FFV2_5_0(w[3], w[22], w[25], pars->GC_41, pars->GC_53, amp[26]);
    FFV2_5_0(w[20], w[2], w[25], pars->GC_41, pars->GC_53, amp[27]);
    FFV2_0(w[27], w[4], w[28], pars->GC_100, amp[28]);
    FFV1_0(w[27], w[26], w[16], pars->GC_3, amp[29]);
    FFV1_0(w[27], w[26], w[17], pars->GC_11, amp[30]);
    FFS2_0(w[27], w[26], w[18], pars->GC_80, amp[31]);
    FFV2_5_0(w[27], w[26], w[25], pars->GC_41, pars->GC_53, amp[32]);
    FFV1_0(w[5], w[29], w[30], pars->GC_2, amp[33]);
    FFV1_0(w[5], w[29], w[31], pars->GC_11, amp[34]);
    FFS2_0(w[5], w[29], w[32], pars->GC_74, amp[35]);
    FFV2_3_0(w[5], w[29], w[33], pars->GC_40, pars->GC_53, amp[36]);
    FFV2_0(w[3], w[29], w[28], pars->GC_100, amp[37]);
    FFV1_0(w[34], w[4], w[30], pars->GC_2, amp[38]);
    FFV1_0(w[34], w[4], w[31], pars->GC_11, amp[39]);
    FFS2_0(w[34], w[4], w[32], pars->GC_74, amp[40]);
    FFV2_3_0(w[34], w[4], w[33], pars->GC_40, pars->GC_53, amp[41]);
    FFV2_0(w[34], w[26], w[21], pars->GC_39, amp[42]);
    FFV2_0(w[5], w[35], w[21], pars->GC_39, amp[43]);
    FFV1_0(w[3], w[35], w[16], pars->GC_3, amp[44]);
    FFV1_0(w[3], w[35], w[17], pars->GC_11, amp[45]);
    VVV1_0(w[1], w[17], w[31], pars->GC_10, amp[46]);
    VVS3_0(w[1], w[17], w[32], pars->GC_13, amp[47]);
    FFS2_0(w[3], w[35], w[18], pars->GC_80, amp[48]);
    VVS3_0(w[1], w[31], w[18], pars->GC_13, amp[49]);
    FFV2_5_0(w[3], w[35], w[25], pars->GC_41, pars->GC_53, amp[50]);
    FFV2_0(w[5], w[37], w[38], pars->GC_39, amp[51]);
    FFV1_0(w[36], w[37], w[16], pars->GC_3, amp[52]);
    FFV1_0(w[36], w[37], w[17], pars->GC_11, amp[53]);
    FFS2_0(w[36], w[37], w[18], pars->GC_80, amp[54]);
    FFV2_5_0(w[36], w[37], w[25], pars->GC_41, pars->GC_53, amp[55]);
    FFV1_0(w[5], w[29], w[39], pars->GC_2, amp[56]);
    FFV1_0(w[5], w[29], w[40], pars->GC_11, amp[57]);
    FFS2_0(w[5], w[29], w[41], pars->GC_74, amp[58]);
    FFV2_3_0(w[5], w[29], w[42], pars->GC_40, pars->GC_53, amp[59]);
    FFV2_0(w[36], w[29], w[19], pars->GC_100, amp[60]);
    FFV1_0(w[34], w[4], w[39], pars->GC_2, amp[61]);
    FFV1_0(w[34], w[4], w[40], pars->GC_11, amp[62]);
    FFS2_0(w[34], w[4], w[41], pars->GC_74, amp[63]);
    FFV2_3_0(w[34], w[4], w[42], pars->GC_40, pars->GC_53, amp[64]);
    FFV2_0(w[34], w[2], w[38], pars->GC_39, amp[65]);
    FFV2_0(w[43], w[4], w[19], pars->GC_100, amp[66]);
    FFV1_0(w[43], w[2], w[16], pars->GC_3, amp[67]);
    FFV1_0(w[43], w[2], w[17], pars->GC_11, amp[68]);
    VVV1_0(w[1], w[17], w[40], pars->GC_10, amp[69]);
    VVS3_0(w[1], w[17], w[41], pars->GC_13, amp[70]);
    FFS2_0(w[43], w[2], w[18], pars->GC_80, amp[71]);
    VVS3_0(w[1], w[40], w[18], pars->GC_13, amp[72]);
    FFV2_5_0(w[43], w[2], w[25], pars->GC_41, pars->GC_53, amp[73]);
    FFV2_0(w[5], w[37], w[45], pars->GC_39, amp[74]);
    FFV1_0(w[3], w[37], w[46], pars->GC_3, amp[75]);
    FFV1_0(w[3], w[37], w[47], pars->GC_11, amp[76]);
    FFS2_0(w[3], w[37], w[48], pars->GC_80, amp[77]);
    FFV2_5_0(w[3], w[37], w[49], pars->GC_41, pars->GC_53, amp[78]);
    FFV1_0(w[27], w[2], w[46], pars->GC_3, amp[79]);
    FFV1_0(w[27], w[2], w[47], pars->GC_11, amp[80]);
    FFS2_0(w[27], w[2], w[48], pars->GC_80, amp[81]);
    FFV2_5_0(w[27], w[2], w[49], pars->GC_41, pars->GC_53, amp[82]);
    FFV2_0(w[27], w[44], w[19], pars->GC_100, amp[83]);
    FFV2_0(w[34], w[2], w[45], pars->GC_39, amp[84]);
    FFV1_0(w[34], w[44], w[11], pars->GC_2, amp[85]);
    FFV1_0(w[34], w[44], w[7], pars->GC_11, amp[86]);
    FFS2_0(w[34], w[44], w[14], pars->GC_74, amp[87]);
    FFV2_3_0(w[34], w[44], w[15], pars->GC_40, pars->GC_53, amp[88]);
    FFV1_0(w[5], w[50], w[11], pars->GC_2, amp[89]);
    FFV1_0(w[5], w[50], w[7], pars->GC_11, amp[90]);
    VVV1_0(w[1], w[7], w[47], pars->GC_10, amp[91]);
    VVS3_0(w[1], w[7], w[48], pars->GC_13, amp[92]);
    FFS2_0(w[5], w[50], w[14], pars->GC_74, amp[93]);
    VVS3_0(w[1], w[47], w[14], pars->GC_13, amp[94]);
    FFV2_3_0(w[5], w[50], w[15], pars->GC_40, pars->GC_53, amp[95]);
    FFV2_0(w[3], w[50], w[19], pars->GC_100, amp[96]);
    FFV1_0(w[3], w[37], w[52], pars->GC_3, amp[97]);
    FFV1_0(w[3], w[37], w[53], pars->GC_11, amp[98]);
    FFS2_0(w[3], w[37], w[54], pars->GC_80, amp[99]);
    FFV2_5_0(w[3], w[37], w[55], pars->GC_41, pars->GC_53, amp[100]);
    FFV2_0(w[51], w[37], w[21], pars->GC_39, amp[101]);
    FFV2_0(w[27], w[4], w[56], pars->GC_100, amp[102]);
    FFV1_0(w[27], w[2], w[52], pars->GC_3, amp[103]);
    FFV1_0(w[27], w[2], w[53], pars->GC_11, amp[104]);
    FFS2_0(w[27], w[2], w[54], pars->GC_80, amp[105]);
    FFV2_5_0(w[27], w[2], w[55], pars->GC_41, pars->GC_53, amp[106]);
    FFV2_0(w[3], w[29], w[56], pars->GC_100, amp[107]);
    FFV1_0(w[51], w[29], w[11], pars->GC_2, amp[108]);
    FFV1_0(w[51], w[29], w[7], pars->GC_11, amp[109]);
    FFS2_0(w[51], w[29], w[14], pars->GC_74, amp[110]);
    FFV2_3_0(w[51], w[29], w[15], pars->GC_40, pars->GC_53, amp[111]);
    FFV1_0(w[57], w[4], w[11], pars->GC_2, amp[112]);
    FFV1_0(w[57], w[4], w[7], pars->GC_11, amp[113]);
    VVV1_0(w[1], w[7], w[53], pars->GC_10, amp[114]);
    VVS3_0(w[1], w[7], w[54], pars->GC_13, amp[115]);
    FFS2_0(w[57], w[4], w[14], pars->GC_74, amp[116]);
    VVS3_0(w[1], w[53], w[14], pars->GC_13, amp[117]);
    FFV2_3_0(w[57], w[4], w[15], pars->GC_40, pars->GC_53, amp[118]);
    FFV2_0(w[57], w[2], w[21], pars->GC_39, amp[119]);
    FFV2_0(w[5], w[58], w[21], pars->GC_39, amp[120]);
    FFV1_0(w[3], w[58], w[16], pars->GC_3, amp[121]);
    FFV1_0(w[3], w[58], w[17], pars->GC_11, amp[122]);
    FFS2_0(w[3], w[37], w[59], pars->GC_80, amp[123]);
    FFV1_0(w[3], w[37], w[60], pars->GC_11, amp[124]);
    FFS2_0(w[3], w[58], w[18], pars->GC_80, amp[125]);
    FFV1_0(w[3], w[37], w[61], pars->GC_11, amp[126]);
    FFV2_5_0(w[3], w[58], w[25], pars->GC_41, pars->GC_53, amp[127]);
    FFV2_0(w[62], w[4], w[19], pars->GC_100, amp[128]);
    FFV1_0(w[62], w[2], w[16], pars->GC_3, amp[129]);
    FFV1_0(w[62], w[2], w[17], pars->GC_11, amp[130]);
    FFS2_0(w[27], w[2], w[59], pars->GC_80, amp[131]);
    FFV1_0(w[27], w[2], w[60], pars->GC_11, amp[132]);
    FFS2_0(w[62], w[2], w[18], pars->GC_80, amp[133]);
    FFV1_0(w[27], w[2], w[61], pars->GC_11, amp[134]);
    FFV2_5_0(w[62], w[2], w[25], pars->GC_41, pars->GC_53, amp[135]);
    FFV1_0(w[5], w[63], w[11], pars->GC_2, amp[136]);
    FFV1_0(w[5], w[63], w[7], pars->GC_11, amp[137]);
    FFS2_0(w[5], w[29], w[64], pars->GC_74, amp[138]);
    FFV1_0(w[5], w[29], w[65], pars->GC_11, amp[139]);
    FFS2_0(w[5], w[63], w[14], pars->GC_74, amp[140]);
    FFV1_0(w[5], w[29], w[66], pars->GC_11, amp[141]);
    FFV2_3_0(w[5], w[63], w[15], pars->GC_40, pars->GC_53, amp[142]);
    FFV2_0(w[3], w[63], w[19], pars->GC_100, amp[143]);
    FFV1_0(w[67], w[4], w[11], pars->GC_2, amp[144]);
    FFV1_0(w[67], w[4], w[7], pars->GC_11, amp[145]);
    FFS2_0(w[34], w[4], w[64], pars->GC_74, amp[146]);
    FFV1_0(w[34], w[4], w[65], pars->GC_11, amp[147]);
    FFS2_0(w[67], w[4], w[14], pars->GC_74, amp[148]);
    FFV1_0(w[34], w[4], w[66], pars->GC_11, amp[149]);
    FFV2_3_0(w[67], w[4], w[15], pars->GC_40, pars->GC_53, amp[150]);
    FFV2_0(w[67], w[2], w[21], pars->GC_39, amp[151]);
    VVVV1_0(w[0], w[1], w[7], w[17], pars->GC_12, amp[152]);
    VVVV3_0(w[0], w[1], w[7], w[17], pars->GC_12, amp[153]);
    VVVV4_0(w[0], w[1], w[7], w[17], pars->GC_12, amp[154]);
    VVV1_0(w[1], w[17], w[65], pars->GC_10, amp[155]);
    VVV1_0(w[1], w[7], w[60], pars->GC_10, amp[156]);
    VVVS2_0(w[0], w[1], w[7], w[18], pars->GC_14, amp[157]);
    VVS3_0(w[1], w[65], w[18], pars->GC_13, amp[158]);
    VVV1_0(w[1], w[7], w[61], pars->GC_10, amp[159]);
    VVVS2_0(w[0], w[1], w[17], w[14], pars->GC_14, amp[160]);
    VVV1_0(w[1], w[17], w[66], pars->GC_10, amp[161]);
    VVS3_0(w[1], w[60], w[14], pars->GC_13, amp[162]);
}
double gg_ttxbbx::matrix_1_gg_ttxbbx()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 163;
    const int ncolor = 14;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {3, 3, 3, 3, 3, 3, 3,
                                         3, 3, 3, 3, 3, 1, 1};
    static const double cf[ncolor][ncolor] = {
        {48, 16, 16, 6, 0, 16, -2, 0, -6, -2, -2, 6, 18, 6},
        {16, 48, 6, 16, 16, 0, 0, -2, -2, -6, 6, -2, 6, 18},
        {16, 6, 48, 16, -2, 0, 0, 16, -2, 6, -6, -2, 6, 18},
        {6, 16, 16, 48, 0, -2, 16, 0, 6, -2, -2, -6, 18, 6},
        {0, 16, -2, 0, 48, 16, 16, 6, 0, -2, 16, 0, 0, 6},
        {16, 0, 0, -2, 16, 48, 6, 16, -2, 0, 0, 16, 6, 0},
        {-2, 0, 0, 16, 16, 6, 48, 16, 16, 0, 0, -2, 6, 0},
        {0, -2, 16, 0, 6, 16, 16, 48, 0, 16, -2, 0, 0, 6},
        {-6, -2, -2, 6, 0, -2, 16, 0, 48, 16, 16, 6, 18, 6},
        {-2, -6, 6, -2, -2, 0, 0, 16, 16, 48, 6, 16, 6, 18},
        {-2, 6, -6, -2, 16, 0, 0, -2, 16, 6, 48, 16, 6, 18},
        {6, -2, -2, -6, 0, 16, -2, 0, 6, 16, 16, 48, 18, 6},
        {6, 2, 2, 6, 0, 2, 2, 0, 6, 2, 2, 6, 18, 6},
        {2, 6, 6, 2, 2, 0, 0, 2, 2, 6, 6, 2, 6, 18}};

    // Calculate color flows
    jamp[0] = -std::complex<double>(0, 1) * amp[12] -
              std::complex<double>(0, 1) * amp[20] -
              std::complex<double>(0, 1) * amp[21] +
              1. / 6. * std::complex<double>(0, 1) * amp[22] +
              1. / 6. * std::complex<double>(0, 1) * amp[23] -
              std::complex<double>(0, 1) * amp[24] -
              std::complex<double>(0, 1) * amp[25] -
              std::complex<double>(0, 1) * amp[26] -
              std::complex<double>(0, 1) * amp[27] + amp[29] -
              1. / 6. * amp[30] + amp[31] + amp[32] + amp[44] -
              1. / 6. * amp[45] + amp[48] + amp[49] + amp[50] + amp[129] -
              1. / 6. * amp[130] + amp[133] + amp[134] + amp[135] -
              std::complex<double>(0, 1) * amp[157] +
              std::complex<double>(0, 1) * amp[158] -
              std::complex<double>(0, 1) * amp[159];
    jamp[1] = -1. / 2. * std::complex<double>(0, 1) * amp[5] +
              1. / 2. * amp[11] + std::complex<double>(0, 1) * amp[16] +
              std::complex<double>(0, 1) * amp[17] -
              1. / 2. * std::complex<double>(0, 1) * amp[22] +
              1. / 2. * amp[39] - amp[42] - amp[43] + 1. / 2. * amp[45] -
              1. / 2. * std::complex<double>(0, 1) * amp[46] +
              1. / 2. * amp[145] +
              1. / 2. * std::complex<double>(0, 1) * amp[147] - amp[151] +
              1. / 2. * amp[152] + 1. / 2. * amp[153] + 1. / 2. * amp[155];
    jamp[2] = -1. / 2. * std::complex<double>(0, 1) * amp[4] -
              1. / 2. * amp[11] + std::complex<double>(0, 1) * amp[14] +
              std::complex<double>(0, 1) * amp[15] -
              1. / 2. * std::complex<double>(0, 1) * amp[23] +
              1. / 2. * amp[80] - amp[83] + 1. / 2. * amp[90] -
              1. / 2. * std::complex<double>(0, 1) * amp[91] - amp[96] -
              amp[128] + 1. / 2. * amp[130] +
              1. / 2. * std::complex<double>(0, 1) * amp[132] -
              1. / 2. * amp[152] + 1. / 2. * amp[154] + 1. / 2. * amp[156];
    jamp[3] = -std::complex<double>(0, 1) * amp[2] -
              std::complex<double>(0, 1) * amp[3] +
              1. / 6. * std::complex<double>(0, 1) * amp[4] +
              1. / 6. * std::complex<double>(0, 1) * amp[5] -
              std::complex<double>(0, 1) * amp[6] -
              std::complex<double>(0, 1) * amp[7] -
              std::complex<double>(0, 1) * amp[8] -
              std::complex<double>(0, 1) * amp[9] -
              std::complex<double>(0, 1) * amp[13] + amp[85] -
              1. / 6. * amp[86] + amp[87] + amp[88] + amp[89] -
              1. / 6. * amp[90] + amp[93] + amp[94] + amp[95] + amp[144] -
              1. / 6. * amp[145] + amp[148] + amp[149] + amp[150] -
              std::complex<double>(0, 1) * amp[160] -
              std::complex<double>(0, 1) * amp[161] +
              std::complex<double>(0, 1) * amp[162];
    jamp[4] = +amp[33] - 1. / 6. * amp[34] + amp[35] + amp[36] + amp[38] -
              1. / 6. * amp[39] + amp[40] + amp[41] + amp[47] + amp[56] -
              1. / 6. * amp[57] + amp[58] + amp[59] + amp[61] -
              1. / 6. * amp[62] + amp[63] + amp[64] + amp[70] + amp[138] +
              amp[146];
    jamp[5] = -amp[28] + 1. / 2. * amp[30] + 1. / 2. * amp[34] - amp[37] +
              1. / 2. * std::complex<double>(0, 1) * amp[46] - amp[102] +
              1. / 2. * amp[104] - amp[107] + 1. / 2. * amp[109] -
              1. / 2. * std::complex<double>(0, 1) * amp[114] -
              1. / 2. * std::complex<double>(0, 1) * amp[132] +
              1. / 2. * std::complex<double>(0, 1) * amp[139] -
              1. / 2. * amp[153] - 1. / 2. * amp[154] - 1. / 2. * amp[155] -
              1. / 2. * amp[156];
    jamp[6] = -amp[51] + 1. / 2. * amp[53] + 1. / 2. * amp[62] - amp[65] -
              1. / 2. * std::complex<double>(0, 1) * amp[69] - amp[74] +
              1. / 2. * amp[76] - amp[84] + 1. / 2. * amp[86] +
              1. / 2. * std::complex<double>(0, 1) * amp[91] +
              1. / 2. * std::complex<double>(0, 1) * amp[124] -
              1. / 2. * std::complex<double>(0, 1) * amp[147] -
              1. / 2. * amp[153] - 1. / 2. * amp[154] - 1. / 2. * amp[155] -
              1. / 2. * amp[156];
    jamp[7] = +amp[75] - 1. / 6. * amp[76] + amp[77] + amp[78] + amp[79] -
              1. / 6. * amp[80] + amp[81] + amp[82] + amp[92] + amp[97] -
              1. / 6. * amp[98] + amp[99] + amp[100] + amp[103] -
              1. / 6. * amp[104] + amp[105] + amp[106] + amp[115] + amp[123] +
              amp[131];
    jamp[8] = +std::complex<double>(0, 1) * amp[12] +
              std::complex<double>(0, 1) * amp[20] +
              std::complex<double>(0, 1) * amp[21] -
              1. / 6. * std::complex<double>(0, 1) * amp[22] -
              1. / 6. * std::complex<double>(0, 1) * amp[23] +
              std::complex<double>(0, 1) * amp[24] +
              std::complex<double>(0, 1) * amp[25] +
              std::complex<double>(0, 1) * amp[26] +
              std::complex<double>(0, 1) * amp[27] + amp[52] -
              1. / 6. * amp[53] + amp[54] + amp[55] + amp[67] -
              1. / 6. * amp[68] + amp[71] + amp[72] + amp[73] + amp[121] -
              1. / 6. * amp[122] + amp[125] + amp[126] + amp[127] +
              std::complex<double>(0, 1) * amp[157] -
              std::complex<double>(0, 1) * amp[158] +
              std::complex<double>(0, 1) * amp[159];
    jamp[9] = +1. / 2. * std::complex<double>(0, 1) * amp[5] -
              1. / 2. * amp[11] - std::complex<double>(0, 1) * amp[16] -
              std::complex<double>(0, 1) * amp[17] +
              1. / 2. * std::complex<double>(0, 1) * amp[22] +
              1. / 2. * amp[98] - amp[101] + 1. / 2. * amp[113] +
              1. / 2. * std::complex<double>(0, 1) * amp[114] - amp[119] -
              amp[120] + 1. / 2. * amp[122] -
              1. / 2. * std::complex<double>(0, 1) * amp[124] -
              1. / 2. * amp[152] + 1. / 2. * amp[154] + 1. / 2. * amp[156];
    jamp[10] = +1. / 2. * std::complex<double>(0, 1) * amp[4] +
               1. / 2. * amp[11] - std::complex<double>(0, 1) * amp[14] -
               std::complex<double>(0, 1) * amp[15] +
               1. / 2. * std::complex<double>(0, 1) * amp[23] +
               1. / 2. * amp[57] - amp[60] - amp[66] + 1. / 2. * amp[68] +
               1. / 2. * std::complex<double>(0, 1) * amp[69] +
               1. / 2. * amp[137] -
               1. / 2. * std::complex<double>(0, 1) * amp[139] - amp[143] +
               1. / 2. * amp[152] + 1. / 2. * amp[153] + 1. / 2. * amp[155];
    jamp[11] = +std::complex<double>(0, 1) * amp[2] +
               std::complex<double>(0, 1) * amp[3] -
               1. / 6. * std::complex<double>(0, 1) * amp[4] -
               1. / 6. * std::complex<double>(0, 1) * amp[5] +
               std::complex<double>(0, 1) * amp[6] +
               std::complex<double>(0, 1) * amp[7] +
               std::complex<double>(0, 1) * amp[8] +
               std::complex<double>(0, 1) * amp[9] +
               std::complex<double>(0, 1) * amp[13] + amp[108] -
               1. / 6. * amp[109] + amp[110] + amp[111] + amp[112] -
               1. / 6. * amp[113] + amp[116] + amp[117] + amp[118] + amp[136] -
               1. / 6. * amp[137] + amp[140] + amp[141] + amp[142] +
               std::complex<double>(0, 1) * amp[160] +
               std::complex<double>(0, 1) * amp[161] -
               std::complex<double>(0, 1) * amp[162];
    jamp[12] = -1. / 3. * amp[0] - 1. / 3. * amp[1] + 2. * amp[10] -
               1. / 3. * amp[18] - 1. / 3. * amp[19];
    jamp[13] = +amp[0] + amp[1] + amp[18] + amp[19];

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
