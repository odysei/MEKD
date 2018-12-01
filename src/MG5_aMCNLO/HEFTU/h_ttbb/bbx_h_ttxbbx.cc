//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "bbx_h_ttxbbx.h"
#include "HelAmps_heft_updated_full.h"

using namespace std;

namespace MG5_heft_updated_full
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: b b~ > t t~ b b~ HIW=1 QED=2 HIG=1 @1

//--------------------------------------------------------------------------
// Initialize process.

void bbx_h_ttxbbx::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    ntry = 0, sum_hel = 0, ngood = 0;
    pars = Parameters_HEFTU::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    //     pars->printIndependentParameters();
    //     pars->printIndependentCouplings();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[6];
    for (int i = 0; i < namplitudes; ++i)
        amp[i] = 0;
}

void bbx_h_ttxbbx::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_HEFTU::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MT);
    mME.push_back(pars->mdl_MB);
    mME.push_back(pars->mdl_MB);
    jamp2[0] = new double[6];
}

//--------------------------------------------------------------------------
// Update process.

void bbx_h_ttxbbx::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MB);
    mME[1] = (pars->mdl_MB);
    mME[2] = (pars->mdl_MT);
    mME[3] = (pars->mdl_MT);
    mME[4] = (pars->mdl_MB);
    mME[5] = (pars->mdl_MB);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void bbx_h_ttxbbx::sigmaKin()
{
    // Set the parameters which change event by event
    pars->setDependentParameters();
    pars->setDependentCouplings();
    //     static bool firsttime = true;
    //     if (firsttime)
    //     {
    //         pars->printDependentParameters();
    //         pars->printDependentCouplings();
    //         firsttime = false;
    //     }

    // Reset color flows
    for (int i = 0; i < 6; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 64;
    static bool goodhel[ncomb] = {ncomb * false};
    //     static int ntry = 0, sum_hel = 0, ngood = 0;
    static int igood[ncomb];
    static int jhel;
    //     std::complex<double> * * wfs;
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
                t[0] = matrix_1_bbx_h_ttxbbx();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_1_bbx_h_ttxbbx();
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
            t[0] = matrix_1_bbx_h_ttxbbx();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_1_bbx_h_ttxbbx();
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

double bbx_h_ttxbbx::sigmaHat()
{
    // Select between the different processes
    if (id1 == -5 && id2 == 5) {
        // Add matrix elements for processes with beams (-5, 5)
        return matrix_element[1];
    } else if (id1 == 5 && id2 == -5) {
        // Add matrix elements for processes with beams (5, -5)
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

void bbx_h_ttxbbx::calculate_wavefunctions(const int perm[], const int hel[])
{
    // Calculate wavefunctions for all processes
    //     int i, j;

    // Calculate all wavefunctions
    ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]);
    oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
    oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
    ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
    oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
    ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]);
    //     FFV1P0_3(w[0], w[1], pars->GC_2, pars->ZERO, pars->ZERO, w[6]);
    FFV1P0_3(w[3], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[7]);
    //     FFV1_1(w[4], w[6], pars->GC_2, pars->mdl_MB, pars->ZERO, w[8]);
    //     FFV1_2(w[5], w[6], pars->GC_2, pars->mdl_MB, pars->ZERO, w[9]);
    FFV1P0_3(w[0], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[10]);
    FFV1P0_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[11]);
    FFV1_1(w[4], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[12]);
    FFV1_2(w[5], w[10], pars->GC_11, pars->mdl_MB, pars->ZERO, w[13]);
    FFS2_3(w[3], w[2], pars->GC_80, pars->mdl_MH, pars->mdl_WH, w[14]);
    //     FFV2_5_3(w[3], w[2], pars->GC_41, pars->GC_53, pars->mdl_MZ,
    //     pars->mdl_WZ,
    //              w[15]);
    FFS2_3(w[0], w[1], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[16]);
    FFS2_1(w[4], w[16], pars->GC_74, pars->mdl_MB, pars->ZERO, w[17]);
    FFS2_2(w[5], w[16], pars->GC_74, pars->mdl_MB, pars->ZERO, w[18]);
    //     FFV2_3_3(w[0], w[1], pars->GC_40, pars->GC_53, pars->mdl_MZ,
    //     pars->mdl_WZ,
    //              w[19]);
    //     FFV2_3_1(w[4], w[19], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[20]);
    //     FFV2_3_2(w[5], w[19], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[21]);
    FFV1P0_3(w[5], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[22]);
    FFS2_3(w[5], w[4], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[23]);
    //     FFV2_3(w[5], w[2], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[24]);
    FFV1_2(w[3], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[25]);
    //     FFV2_3(w[3], w[4], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[26]);
    FFV1_1(w[2], w[10], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[27]);
    //     FFV1_1(w[2], w[6], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[28]);
    //     FFV1_2(w[3], w[6], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[29]);
    //     FFV1P0_3(w[5], w[4], pars->GC_2, pars->ZERO, pars->ZERO, w[30]);
    //     FFV2_3_3(w[5], w[4], pars->GC_40, pars->GC_53, pars->mdl_MZ,
    //     pars->mdl_WZ,
    //              w[31]);
    FFS2_1(w[2], w[16], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[32]);
    FFS2_2(w[3], w[16], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[33]);
    //     FFV2_5_1(w[2], w[19], pars->GC_41, pars->GC_53, pars->mdl_MT,
    //     pars->mdl_WT,
    //              w[34]);
    //     FFV2_5_2(w[3], w[19], pars->GC_41, pars->GC_53, pars->mdl_MT,
    //     pars->mdl_WT,
    //              w[35]);
    //     FFV2_3(w[0], w[2], pars->GC_39, pars->mdl_MW, pars->mdl_WW, w[36]);
    FFV1P0_3(w[5], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[37]);
    //     FFV2_2(w[3], w[36], pars->GC_100, pars->mdl_MB, pars->ZERO, w[38]);
    //     FFV2_1(w[4], w[36], pars->GC_100, pars->mdl_MT, pars->mdl_WT, w[39]);
    //     FFV2_1(w[1], w[36], pars->GC_100, pars->mdl_MT, pars->mdl_WT, w[40]);
    FFV1P0_3(w[0], w[4], pars->GC_11, pars->ZERO, pars->ZERO, w[41]);
    //     FFV2_3(w[3], w[1], pars->GC_100, pars->mdl_MW, pars->mdl_WW, w[42]);
    FFV1_1(w[2], w[41], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[43]);
    FFV1_2(w[5], w[41], pars->GC_11, pars->mdl_MB, pars->ZERO, w[44]);
    //     FFV1P0_3(w[0], w[4], pars->GC_2, pars->ZERO, pars->ZERO, w[45]);
    //     FFV1_1(w[2], w[45], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[46]);
    //     FFV1_2(w[3], w[45], pars->GC_3, pars->mdl_MT, pars->mdl_WT, w[47]);
    //     FFV1P0_3(w[5], w[1], pars->GC_2, pars->ZERO, pars->ZERO, w[48]);
    FFV1_2(w[3], w[41], pars->GC_11, pars->mdl_MT, pars->mdl_WT, w[49]);
    FFS2_3(w[5], w[1], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[50]);
    //     FFV2_3_3(w[5], w[1], pars->GC_40, pars->GC_53, pars->mdl_MZ,
    //     pars->mdl_WZ,
    //              w[51]);
    FFS2_3(w[0], w[4], pars->GC_74, pars->mdl_MH, pars->mdl_WH, w[52]);
    FFS2_1(w[2], w[52], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[53]);
    FFS2_2(w[3], w[52], pars->GC_80, pars->mdl_MT, pars->mdl_WT, w[54]);
    //     FFV2_3_3(w[0], w[4], pars->GC_40, pars->GC_53, pars->mdl_MZ,
    //     pars->mdl_WZ,
    //              w[55]);
    //     FFV2_5_1(w[2], w[55], pars->GC_41, pars->GC_53, pars->mdl_MT,
    //     pars->mdl_WT,
    //              w[56]);
    //     FFV2_5_2(w[3], w[55], pars->GC_41, pars->GC_53, pars->mdl_MT,
    //     pars->mdl_WT,
    //              w[57]);
    //     FFV1_1(w[1], w[45], pars->GC_2, pars->mdl_MB, pars->ZERO, w[58]);
    //     FFV1_2(w[5], w[45], pars->GC_2, pars->mdl_MB, pars->ZERO, w[59]);
    FFV1_1(w[1], w[41], pars->GC_11, pars->mdl_MB, pars->ZERO, w[60]);
    FFS2_1(w[1], w[52], pars->GC_74, pars->mdl_MB, pars->ZERO, w[61]);
    FFS2_2(w[5], w[52], pars->GC_74, pars->mdl_MB, pars->ZERO, w[62]);
    //     FFV2_3_1(w[1], w[55], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[63]);
    //     FFV2_3_2(w[5], w[55], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[64]);
    //     FFV2_2(w[0], w[42], pars->GC_39, pars->mdl_MT, pars->mdl_WT, w[65]);
    FFV1_2(w[0], w[22], pars->GC_11, pars->mdl_MB, pars->ZERO, w[66]);
    //     FFV1_2(w[0], w[48], pars->GC_2, pars->mdl_MB, pars->ZERO, w[67]);
    FFV1_2(w[0], w[7], pars->GC_11, pars->mdl_MB, pars->ZERO, w[68]);
    FFV1_2(w[0], w[37], pars->GC_11, pars->mdl_MB, pars->ZERO, w[69]);
    //     FFV1_2(w[0], w[11], pars->GC_2, pars->mdl_MB, pars->ZERO, w[70]);
    FFS2_2(w[0], w[14], pars->GC_74, pars->mdl_MB, pars->ZERO, w[71]);
    //     FFV2_3_2(w[0], w[15], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[72]);
    FFS2_2(w[0], w[50], pars->GC_74, pars->mdl_MB, pars->ZERO, w[73]);
    //     FFV2_3_2(w[0], w[51], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[74]);
    //     FFV2_2(w[0], w[26], pars->GC_39, pars->mdl_MT, pars->mdl_WT, w[75]);
    //     FFV1_2(w[0], w[30], pars->GC_2, pars->mdl_MB, pars->ZERO, w[76]);
    FFS2_2(w[0], w[23], pars->GC_74, pars->mdl_MB, pars->ZERO, w[77]);
    //     FFV2_3_2(w[0], w[31], pars->GC_40, pars->GC_53, pars->mdl_MB,
    //     pars->ZERO,
    //              w[78]);

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
    FFV1_0(w[5], w[17], w[7], pars->GC_11, amp[10]);
    FFV1_0(w[18], w[4], w[7], pars->GC_11, amp[11]);
    //     FFV1_0(w[5], w[20], w[7], pars->GC_11, amp[12]);
    //     FFV1_0(w[21], w[4], w[7], pars->GC_11, amp[13]);
    //     VVV1_0(w[10], w[7], w[22], pars->GC_10, amp[14]);
    VVS3_0(w[10], w[7], w[23], pars->GC_13, amp[15]);
    VVS3_0(w[10], w[22], w[14], pars->GC_13, amp[16]);
    VVS3_0(w[7], w[22], w[16], pars->GC_13, amp[17]);
    //     FFV2_0(w[25], w[4], w[24], pars->GC_100, amp[18]);
    //     FFV2_0(w[3], w[12], w[24], pars->GC_100, amp[19]);
    //     FFV2_0(w[5], w[27], w[26], pars->GC_39, amp[20]);
    //     FFV2_0(w[13], w[2], w[26], pars->GC_39, amp[21]);
    //     FFV1_0(w[3], w[28], w[22], pars->GC_11, amp[22]);
    //     FFV1_0(w[29], w[2], w[22], pars->GC_11, amp[23]);
    //     FFV1_0(w[3], w[27], w[30], pars->GC_3, amp[24]);
    //     FFV1_0(w[25], w[2], w[30], pars->GC_3, amp[25]);
    //     FFV1_0(w[3], w[27], w[22], pars->GC_11, amp[26]);
    //     FFV1_0(w[25], w[2], w[22], pars->GC_11, amp[27]);
    FFS2_0(w[3], w[27], w[23], pars->GC_80, amp[28]);
    FFS2_0(w[25], w[2], w[23], pars->GC_80, amp[29]);
    //     FFV2_5_0(w[3], w[27], w[31], pars->GC_41, pars->GC_53, amp[30]);
    //     FFV2_5_0(w[25], w[2], w[31], pars->GC_41, pars->GC_53, amp[31]);
    FFV1_0(w[3], w[32], w[22], pars->GC_11, amp[32]);
    FFV1_0(w[33], w[2], w[22], pars->GC_11, amp[33]);
    //     FFV1_0(w[3], w[34], w[22], pars->GC_11, amp[34]);
    //     FFV1_0(w[35], w[2], w[22], pars->GC_11, amp[35]);
    //     FFV1_0(w[38], w[4], w[37], pars->GC_11, amp[36]);
    //     FFV1_0(w[3], w[39], w[37], pars->GC_11, amp[37]);
    //     FFV1_0(w[3], w[40], w[22], pars->GC_11, amp[38]);
    //     FFV1_0(w[38], w[1], w[22], pars->GC_11, amp[39]);
    //     FFV2_0(w[5], w[43], w[42], pars->GC_39, amp[40]);
    //     FFV2_0(w[44], w[2], w[42], pars->GC_39, amp[41]);
    //     FFV1_0(w[3], w[46], w[37], pars->GC_11, amp[42]);
    //     FFV1_0(w[47], w[2], w[37], pars->GC_11, amp[43]);
    //     FFV1_0(w[3], w[43], w[48], pars->GC_3, amp[44]);
    //     FFV1_0(w[49], w[2], w[48], pars->GC_3, amp[45]);
    //     FFV1_0(w[3], w[43], w[37], pars->GC_11, amp[46]);
    //     FFV1_0(w[49], w[2], w[37], pars->GC_11, amp[47]);
    FFS2_0(w[3], w[43], w[50], pars->GC_80, amp[48]);
    FFS2_0(w[49], w[2], w[50], pars->GC_80, amp[49]);
    //     FFV2_5_0(w[3], w[43], w[51], pars->GC_41, pars->GC_53, amp[50]);
    //     FFV2_5_0(w[49], w[2], w[51], pars->GC_41, pars->GC_53, amp[51]);
    FFV1_0(w[3], w[53], w[37], pars->GC_11, amp[52]);
    FFV1_0(w[54], w[2], w[37], pars->GC_11, amp[53]);
    //     FFV1_0(w[3], w[56], w[37], pars->GC_11, amp[54]);
    //     FFV1_0(w[57], w[2], w[37], pars->GC_11, amp[55]);
    //     VVV1_0(w[41], w[37], w[7], pars->GC_10, amp[56]);
    VVS3_0(w[41], w[37], w[14], pars->GC_13, amp[57]);
    VVS3_0(w[41], w[7], w[50], pars->GC_13, amp[58]);
    VVS3_0(w[37], w[7], w[52], pars->GC_13, amp[59]);
    //     FFV1_0(w[5], w[58], w[7], pars->GC_11, amp[60]);
    //     FFV1_0(w[59], w[1], w[7], pars->GC_11, amp[61]);
    //     FFV1_0(w[5], w[60], w[11], pars->GC_2, amp[62]);
    //     FFV1_0(w[44], w[1], w[11], pars->GC_2, amp[63]);
    //     FFV1_0(w[5], w[60], w[7], pars->GC_11, amp[64]);
    //     FFV1_0(w[44], w[1], w[7], pars->GC_11, amp[65]);
    FFS2_0(w[5], w[60], w[14], pars->GC_74, amp[66]);
    FFS2_0(w[44], w[1], w[14], pars->GC_74, amp[67]);
    //     FFV2_3_0(w[5], w[60], w[15], pars->GC_40, pars->GC_53, amp[68]);
    //     FFV2_3_0(w[44], w[1], w[15], pars->GC_40, pars->GC_53, amp[69]);
    FFV1_0(w[5], w[61], w[7], pars->GC_11, amp[70]);
    FFV1_0(w[62], w[1], w[7], pars->GC_11, amp[71]);
    //     FFV1_0(w[5], w[63], w[7], pars->GC_11, amp[72]);
    //     FFV1_0(w[64], w[1], w[7], pars->GC_11, amp[73]);
    //     FFV2_0(w[3], w[60], w[24], pars->GC_100, amp[74]);
    //     FFV2_0(w[49], w[1], w[24], pars->GC_100, amp[75]);
    //     FFV1_0(w[65], w[2], w[22], pars->GC_11, amp[76]);
    //     FFV2_0(w[66], w[2], w[42], pars->GC_39, amp[77]);
    //     FFV1_0(w[67], w[4], w[7], pars->GC_11, amp[78]);
    //     FFV1_0(w[68], w[4], w[48], pars->GC_2, amp[79]);
    //     FFV1_0(w[69], w[4], w[11], pars->GC_2, amp[80]);
    //     FFV1_0(w[70], w[4], w[37], pars->GC_11, amp[81]);
    //     FFV1_0(w[69], w[4], w[7], pars->GC_11, amp[82]);
    //     FFV1_0(w[68], w[4], w[37], pars->GC_11, amp[83]);
    FFS2_0(w[69], w[4], w[14], pars->GC_74, amp[84]);
    FFV1_0(w[71], w[4], w[37], pars->GC_11, amp[85]);
    //     FFV2_3_0(w[69], w[4], w[15], pars->GC_40, pars->GC_53, amp[86]);
    //     FFV1_0(w[72], w[4], w[37], pars->GC_11, amp[87]);
    FFV1_0(w[73], w[4], w[7], pars->GC_11, amp[88]);
    FFS2_0(w[68], w[4], w[50], pars->GC_74, amp[89]);
    //     FFV1_0(w[74], w[4], w[7], pars->GC_11, amp[90]);
    //     FFV2_3_0(w[68], w[4], w[51], pars->GC_40, pars->GC_53, amp[91]);
    //     FFV2_0(w[69], w[2], w[26], pars->GC_39, amp[92]);
    //     FFV1_0(w[75], w[2], w[37], pars->GC_11, amp[93]);
    //     FFV1_0(w[70], w[1], w[22], pars->GC_11, amp[94]);
    //     FFV1_0(w[66], w[1], w[11], pars->GC_2, amp[95]);
    //     FFV1_0(w[68], w[1], w[30], pars->GC_2, amp[96]);
    //     FFV1_0(w[76], w[1], w[7], pars->GC_11, amp[97]);
    //     FFV1_0(w[68], w[1], w[22], pars->GC_11, amp[98]);
    //     FFV1_0(w[66], w[1], w[7], pars->GC_11, amp[99]);
    FFS2_0(w[68], w[1], w[23], pars->GC_74, amp[100]);
    FFV1_0(w[77], w[1], w[7], pars->GC_11, amp[101]);
    //     FFV2_3_0(w[68], w[1], w[31], pars->GC_40, pars->GC_53, amp[102]);
    //     FFV1_0(w[78], w[1], w[7], pars->GC_11, amp[103]);
    FFV1_0(w[71], w[1], w[22], pars->GC_11, amp[104]);
    FFS2_0(w[66], w[1], w[14], pars->GC_74, amp[105]);
    //     FFV1_0(w[72], w[1], w[22], pars->GC_11, amp[106]);
    //     FFV2_3_0(w[66], w[1], w[15], pars->GC_40, pars->GC_53, amp[107]);
}
double bbx_h_ttxbbx::matrix_1_bbx_h_ttxbbx()
{
    int i, j;
    // Local variables
    //     const int ngraphs = 108;
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
              1. / 6. * amp[12] - 1. / 6. * amp[13] - 1. / 6. * amp[15] -
              1. / 6. * amp[16] - 1. / 6. * amp[17] - 1. / 6. * amp[22] -
              1. / 6. * amp[23] - 1. / 6. * amp[24] - 1. / 6. * amp[25] +
              1. / 36. * amp[26] + 1. / 36. * amp[27] - 1. / 6. * amp[28] -
              1. / 6. * amp[29] - 1. / 6. * amp[30] - 1. / 6. * amp[31] -
              1. / 6. * amp[32] - 1. / 6. * amp[33] - 1. / 6. * amp[34] -
              1. / 6. * amp[35] - 1. / 2. * amp[57] - 1. / 2. * amp[62] -
              1. / 2. * amp[63] + 1. / 12. * amp[64] + 1. / 12. * amp[65] -
              1. / 2. * amp[66] - 1. / 2. * amp[67] - 1. / 2. * amp[68] -
              1. / 2. * amp[69] - 1. / 2. * amp[80] - 1. / 2. * amp[81] +
              1. / 12. * amp[82] + 1. / 12. * amp[83] - 1. / 2. * amp[84] -
              1. / 2. * amp[85] - 1. / 2. * amp[86] - 1. / 2. * amp[87] -
              1. / 6. * amp[94] - 1. / 6. * amp[95] - 1. / 6. * amp[96] -
              1. / 6. * amp[97] + 1. / 36. * amp[98] + 1. / 36. * amp[99] -
              1. / 6. * amp[100] - 1. / 6. * amp[101] - 1. / 6. * amp[102] -
              1. / 6. * amp[103] - 1. / 6. * amp[104] - 1. / 6. * amp[105] -
              1. / 6. * amp[106] - 1. / 6. * amp[107];
    jamp[1] = +1. / 2. * amp[0] + 1. / 2. * amp[1] - 1. / 12. * amp[4] -
              1. / 12. * amp[5] + 1. / 2. * amp[10] + 1. / 2. * amp[11] +
              1. / 2. * amp[12] + 1. / 2. * amp[13] + 1. / 2. * amp[17] +
              1. / 6. * amp[18] + 1. / 6. * amp[19] + 1. / 6. * amp[20] +
              1. / 6. * amp[21] + 1. / 2. * amp[22] + 1. / 2. * amp[23] -
              1. / 12. * amp[26] - 1. / 12. * amp[27] + 1. / 2. * amp[32] +
              1. / 2. * amp[33] + 1. / 2. * amp[34] + 1. / 2. * amp[35] -
              1. / 4. * amp[47] -
              1. / 4. * std::complex<double>(0, 1) * amp[56] -
              1. / 4. * amp[64] + 1. / 2. * amp[74] + 1. / 2. * amp[75] -
              1. / 4. * amp[82] + 1. / 2. * amp[92] + 1. / 2. * amp[93];
    jamp[2] = +1. / 2. * amp[15] + 1. / 2. * amp[24] + 1. / 2. * amp[25] -
              1. / 12. * amp[26] - 1. / 12. * amp[27] + 1. / 2. * amp[28] +
              1. / 2. * amp[29] + 1. / 2. * amp[30] + 1. / 2. * amp[31] +
              1. / 2. * amp[36] + 1. / 2. * amp[37] + 1. / 6. * amp[38] +
              1. / 6. * amp[39] + 1. / 2. * amp[40] + 1. / 2. * amp[41] -
              1. / 4. * amp[46] +
              1. / 4. * std::complex<double>(0, 1) * amp[56] -
              1. / 4. * amp[65] + 1. / 6. * amp[76] + 1. / 6. * amp[77] -
              1. / 4. * amp[83] + 1. / 2. * amp[96] + 1. / 2. * amp[97] -
              1. / 12. * amp[98] - 1. / 12. * amp[99] + 1. / 2. * amp[100] +
              1. / 2. * amp[101] + 1. / 2. * amp[102] + 1. / 2. * amp[103];
    jamp[3] = +1. / 4. * amp[4] -
              1. / 4. * std::complex<double>(0, 1) * amp[14] -
              1. / 2. * amp[18] - 1. / 2. * amp[19] + 1. / 4. * amp[27] -
              1. / 6. * amp[40] - 1. / 6. * amp[41] - 1. / 2. * amp[42] -
              1. / 2. * amp[43] + 1. / 12. * amp[46] + 1. / 12. * amp[47] -
              1. / 2. * amp[52] - 1. / 2. * amp[53] - 1. / 2. * amp[54] -
              1. / 2. * amp[55] - 1. / 2. * amp[59] - 1. / 2. * amp[60] -
              1. / 2. * amp[61] + 1. / 12. * amp[64] + 1. / 12. * amp[65] -
              1. / 2. * amp[70] - 1. / 2. * amp[71] - 1. / 2. * amp[72] -
              1. / 2. * amp[73] - 1. / 6. * amp[74] - 1. / 6. * amp[75] -
              1. / 2. * amp[76] - 1. / 2. * amp[77] + 1. / 4. * amp[99];
    jamp[4] = +1. / 4. * amp[5] +
              1. / 4. * std::complex<double>(0, 1) * amp[14] -
              1. / 2. * amp[20] - 1. / 2. * amp[21] + 1. / 4. * amp[26] -
              1. / 6. * amp[36] - 1. / 6. * amp[37] - 1. / 2. * amp[38] -
              1. / 2. * amp[39] - 1. / 2. * amp[44] - 1. / 2. * amp[45] +
              1. / 12. * amp[46] + 1. / 12. * amp[47] - 1. / 2. * amp[48] -
              1. / 2. * amp[49] - 1. / 2. * amp[50] - 1. / 2. * amp[51] -
              1. / 2. * amp[58] - 1. / 2. * amp[78] - 1. / 2. * amp[79] +
              1. / 12. * amp[82] + 1. / 12. * amp[83] - 1. / 2. * amp[88] -
              1. / 2. * amp[89] - 1. / 2. * amp[90] - 1. / 2. * amp[91] -
              1. / 6. * amp[92] - 1. / 6. * amp[93] + 1. / 4. * amp[98];
    jamp[5] = +1. / 2. * amp[2] + 1. / 2. * amp[3] - 1. / 12. * amp[4] -
              1. / 12. * amp[5] + 1. / 2. * amp[6] + 1. / 2. * amp[7] +
              1. / 2. * amp[8] + 1. / 2. * amp[9] + 1. / 2. * amp[16] +
              1. / 6. * amp[42] + 1. / 6. * amp[43] + 1. / 6. * amp[44] +
              1. / 6. * amp[45] - 1. / 36. * amp[46] - 1. / 36. * amp[47] +
              1. / 6. * amp[48] + 1. / 6. * amp[49] + 1. / 6. * amp[50] +
              1. / 6. * amp[51] + 1. / 6. * amp[52] + 1. / 6. * amp[53] +
              1. / 6. * amp[54] + 1. / 6. * amp[55] + 1. / 6. * amp[57] +
              1. / 6. * amp[58] + 1. / 6. * amp[59] + 1. / 6. * amp[60] +
              1. / 6. * amp[61] + 1. / 6. * amp[62] + 1. / 6. * amp[63] -
              1. / 36. * amp[64] - 1. / 36. * amp[65] + 1. / 6. * amp[66] +
              1. / 6. * amp[67] + 1. / 6. * amp[68] + 1. / 6. * amp[69] +
              1. / 6. * amp[70] + 1. / 6. * amp[71] + 1. / 6. * amp[72] +
              1. / 6. * amp[73] + 1. / 6. * amp[78] + 1. / 6. * amp[79] +
              1. / 6. * amp[80] + 1. / 6. * amp[81] - 1. / 36. * amp[82] -
              1. / 36. * amp[83] + 1. / 6. * amp[84] + 1. / 6. * amp[85] +
              1. / 6. * amp[86] + 1. / 6. * amp[87] + 1. / 6. * amp[88] +
              1. / 6. * amp[89] + 1. / 6. * amp[90] + 1. / 6. * amp[91] +
              1. / 2. * amp[94] + 1. / 2. * amp[95] - 1. / 12. * amp[98] -
              1. / 12. * amp[99] + 1. / 2. * amp[104] + 1. / 2. * amp[105] +
              1. / 2. * amp[106] + 1. / 2. * amp[107];

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
} // namespace MG5_heft_updated_full
