//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.6.4, 2018-11-09
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "qq_z_zp_DN_OFpA.h"
#include "HelAmps_Leptophilic_UFO.h"

using namespace std;

namespace MG5_Leptophilic_UFO
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: s s~ > e- e+ mu- mu+ a WEIGHTED<=10 / h @3

//--------------------------------------------------------------------------
// Initialize process.

void qq_z_zp_DN_OFpA::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    ntry = 0, sum_hel = 0, ngood = 0;
    pars = Parameters_Leptophilic_UFO::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    //   pars->printIndependentParameters();
    //   pars->printIndependentCouplings();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

void qq_z_zp_DN_OFpA::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_Leptophilic_UFO::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.

void qq_z_zp_DN_OFpA::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MS);
    mME[1] = (pars->mdl_MS);
    mME[2] = (pars->mdl_Me);
    mME[3] = (pars->mdl_Me);
    mME[4] = (pars->mdl_MMU);
    mME[5] = (pars->mdl_MMU);
    mME[6] = (pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_z_zp_DN_OFpA::sigmaKin()
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
    const int ncomb = 128;
    static bool goodhel[ncomb] = {ncomb * false};
    //   static int ntry = 0, sum_hel = 0, ngood = 0;
    static int igood[ncomb];
    static int jhel;
    //   std::complex<double> * * wfs;
    double t[nprocesses];
    // Helicities for the process
    static const int helicities[ncomb][nexternal] = {
        {-1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 1},
        {-1, -1, -1, -1, -1, 1, -1},  {-1, -1, -1, -1, -1, 1, 1},
        {-1, -1, -1, -1, 1, -1, -1},  {-1, -1, -1, -1, 1, -1, 1},
        {-1, -1, -1, -1, 1, 1, -1},   {-1, -1, -1, -1, 1, 1, 1},
        {-1, -1, -1, 1, -1, -1, -1},  {-1, -1, -1, 1, -1, -1, 1},
        {-1, -1, -1, 1, -1, 1, -1},   {-1, -1, -1, 1, -1, 1, 1},
        {-1, -1, -1, 1, 1, -1, -1},   {-1, -1, -1, 1, 1, -1, 1},
        {-1, -1, -1, 1, 1, 1, -1},    {-1, -1, -1, 1, 1, 1, 1},
        {-1, -1, 1, -1, -1, -1, -1},  {-1, -1, 1, -1, -1, -1, 1},
        {-1, -1, 1, -1, -1, 1, -1},   {-1, -1, 1, -1, -1, 1, 1},
        {-1, -1, 1, -1, 1, -1, -1},   {-1, -1, 1, -1, 1, -1, 1},
        {-1, -1, 1, -1, 1, 1, -1},    {-1, -1, 1, -1, 1, 1, 1},
        {-1, -1, 1, 1, -1, -1, -1},   {-1, -1, 1, 1, -1, -1, 1},
        {-1, -1, 1, 1, -1, 1, -1},    {-1, -1, 1, 1, -1, 1, 1},
        {-1, -1, 1, 1, 1, -1, -1},    {-1, -1, 1, 1, 1, -1, 1},
        {-1, -1, 1, 1, 1, 1, -1},     {-1, -1, 1, 1, 1, 1, 1},
        {-1, 1, -1, -1, -1, -1, -1},  {-1, 1, -1, -1, -1, -1, 1},
        {-1, 1, -1, -1, -1, 1, -1},   {-1, 1, -1, -1, -1, 1, 1},
        {-1, 1, -1, -1, 1, -1, -1},   {-1, 1, -1, -1, 1, -1, 1},
        {-1, 1, -1, -1, 1, 1, -1},    {-1, 1, -1, -1, 1, 1, 1},
        {-1, 1, -1, 1, -1, -1, -1},   {-1, 1, -1, 1, -1, -1, 1},
        {-1, 1, -1, 1, -1, 1, -1},    {-1, 1, -1, 1, -1, 1, 1},
        {-1, 1, -1, 1, 1, -1, -1},    {-1, 1, -1, 1, 1, -1, 1},
        {-1, 1, -1, 1, 1, 1, -1},     {-1, 1, -1, 1, 1, 1, 1},
        {-1, 1, 1, -1, -1, -1, -1},   {-1, 1, 1, -1, -1, -1, 1},
        {-1, 1, 1, -1, -1, 1, -1},    {-1, 1, 1, -1, -1, 1, 1},
        {-1, 1, 1, -1, 1, -1, -1},    {-1, 1, 1, -1, 1, -1, 1},
        {-1, 1, 1, -1, 1, 1, -1},     {-1, 1, 1, -1, 1, 1, 1},
        {-1, 1, 1, 1, -1, -1, -1},    {-1, 1, 1, 1, -1, -1, 1},
        {-1, 1, 1, 1, -1, 1, -1},     {-1, 1, 1, 1, -1, 1, 1},
        {-1, 1, 1, 1, 1, -1, -1},     {-1, 1, 1, 1, 1, -1, 1},
        {-1, 1, 1, 1, 1, 1, -1},      {-1, 1, 1, 1, 1, 1, 1},
        {1, -1, -1, -1, -1, -1, -1},  {1, -1, -1, -1, -1, -1, 1},
        {1, -1, -1, -1, -1, 1, -1},   {1, -1, -1, -1, -1, 1, 1},
        {1, -1, -1, -1, 1, -1, -1},   {1, -1, -1, -1, 1, -1, 1},
        {1, -1, -1, -1, 1, 1, -1},    {1, -1, -1, -1, 1, 1, 1},
        {1, -1, -1, 1, -1, -1, -1},   {1, -1, -1, 1, -1, -1, 1},
        {1, -1, -1, 1, -1, 1, -1},    {1, -1, -1, 1, -1, 1, 1},
        {1, -1, -1, 1, 1, -1, -1},    {1, -1, -1, 1, 1, -1, 1},
        {1, -1, -1, 1, 1, 1, -1},     {1, -1, -1, 1, 1, 1, 1},
        {1, -1, 1, -1, -1, -1, -1},   {1, -1, 1, -1, -1, -1, 1},
        {1, -1, 1, -1, -1, 1, -1},    {1, -1, 1, -1, -1, 1, 1},
        {1, -1, 1, -1, 1, -1, -1},    {1, -1, 1, -1, 1, -1, 1},
        {1, -1, 1, -1, 1, 1, -1},     {1, -1, 1, -1, 1, 1, 1},
        {1, -1, 1, 1, -1, -1, -1},    {1, -1, 1, 1, -1, -1, 1},
        {1, -1, 1, 1, -1, 1, -1},     {1, -1, 1, 1, -1, 1, 1},
        {1, -1, 1, 1, 1, -1, -1},     {1, -1, 1, 1, 1, -1, 1},
        {1, -1, 1, 1, 1, 1, -1},      {1, -1, 1, 1, 1, 1, 1},
        {1, 1, -1, -1, -1, -1, -1},   {1, 1, -1, -1, -1, -1, 1},
        {1, 1, -1, -1, -1, 1, -1},    {1, 1, -1, -1, -1, 1, 1},
        {1, 1, -1, -1, 1, -1, -1},    {1, 1, -1, -1, 1, -1, 1},
        {1, 1, -1, -1, 1, 1, -1},     {1, 1, -1, -1, 1, 1, 1},
        {1, 1, -1, 1, -1, -1, -1},    {1, 1, -1, 1, -1, -1, 1},
        {1, 1, -1, 1, -1, 1, -1},     {1, 1, -1, 1, -1, 1, 1},
        {1, 1, -1, 1, 1, -1, -1},     {1, 1, -1, 1, 1, -1, 1},
        {1, 1, -1, 1, 1, 1, -1},      {1, 1, -1, 1, 1, 1, 1},
        {1, 1, 1, -1, -1, -1, -1},    {1, 1, 1, -1, -1, -1, 1},
        {1, 1, 1, -1, -1, 1, -1},     {1, 1, 1, -1, -1, 1, 1},
        {1, 1, 1, -1, 1, -1, -1},     {1, 1, 1, -1, 1, -1, 1},
        {1, 1, 1, -1, 1, 1, -1},      {1, 1, 1, -1, 1, 1, 1},
        {1, 1, 1, 1, -1, -1, -1},     {1, 1, 1, 1, -1, -1, 1},
        {1, 1, 1, 1, -1, 1, -1},      {1, 1, 1, 1, -1, 1, 1},
        {1, 1, 1, 1, 1, -1, -1},      {1, 1, 1, 1, 1, -1, 1},
        {1, 1, 1, 1, 1, 1, -1},       {1, 1, 1, 1, 1, 1, 1}};
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
                t[0] = matrix_3_ssx_emepmummupa_no_h();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_3_ssx_emepmummupa_no_h();
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
            t[0] = matrix_3_ssx_emepmummupa_no_h();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_3_ssx_emepmummupa_no_h();
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

double qq_z_zp_DN_OFpA::sigmaHat()
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

void qq_z_zp_DN_OFpA::calculate_wavefunctions(const int perm[], const int hel[])
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
    vxxxxx(p[perm[6]], mME[6], hel[6], +1, w[6]);
    FFV1P0_3(w[0], w[1], pars->GC_1, pars->ZERO, pars->ZERO, w[7]);
    FFV2_3_3(w[3], w[2], pars->GC_9, pars->GC_10, pars->mdl_ZpM, pars->mdl_ZpW,
             w[8]);
    FFV1_1(w[4], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[9]);
    FFV2_3_2(w[5], w[8], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[10]);
    FFV1_2(w[5], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[11]);
    FFV2_3_1(w[4], w[8], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[12]);
    FFV1P0_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[13]);
    FFV1_2(w[5], w[13], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[14]);
    FFV1_1(w[4], w[13], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[15]);
    FFV2_5_3(w[3], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[16]);
    FFV2_5_2(w[5], w[16], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[17]);
    FFV2_5_1(w[4], w[16], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[18]);
    FFV2_4_3(w[0], w[1], pars->GC_29, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[19]);
    FFV2_5_1(w[4], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[20]);
    FFV2_5_2(w[5], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[21]);
    FFV1_1(w[4], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[22]);
    FFV1_1(w[22], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[23]);
    FFV2_5_1(w[22], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[24]);
    FFV1_2(w[5], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[25]);
    FFV1_2(w[25], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[26]);
    FFV2_5_2(w[25], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[27]);
    FFV1_1(w[2], w[6], pars->GC_3, pars->mdl_Me, pars->ZERO, w[28]);
    FFV2_3_3(w[3], w[28], pars->GC_9, pars->GC_10, pars->mdl_ZpM, pars->mdl_ZpW,
             w[29]);
    FFV1P0_3(w[3], w[28], pars->GC_3, pars->ZERO, pars->ZERO, w[30]);
    FFV2_5_3(w[3], w[28], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[31]);
    FFV2_3_3(w[5], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
             w[32]);
    FFV1_1(w[28], w[7], pars->GC_3, pars->mdl_Me, pars->ZERO, w[33]);
    FFV1_2(w[3], w[7], pars->GC_3, pars->mdl_Me, pars->ZERO, w[34]);
    FFV1P0_3(w[5], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[35]);
    FFV2_5_3(w[5], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[36]);
    FFV2_5_1(w[28], w[19], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[37]);
    FFV2_5_2(w[3], w[19], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[38]);
    FFV1_2(w[3], w[6], pars->GC_3, pars->mdl_Me, pars->ZERO, w[39]);
    FFV2_3_3(w[39], w[2], pars->GC_9, pars->GC_10, pars->mdl_ZpM, pars->mdl_ZpW,
             w[40]);
    FFV1P0_3(w[39], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[41]);
    FFV2_5_3(w[39], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[42]);
    FFV1_1(w[2], w[7], pars->GC_3, pars->mdl_Me, pars->ZERO, w[43]);
    FFV1_2(w[39], w[7], pars->GC_3, pars->mdl_Me, pars->ZERO, w[44]);
    FFV2_5_1(w[2], w[19], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[45]);
    FFV2_5_2(w[39], w[19], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[46]);
    FFV2_3_2(w[3], w[32], pars->GC_9, pars->GC_10, pars->mdl_Me, pars->ZERO,
             w[47]);
    FFV2_3_1(w[2], w[32], pars->GC_9, pars->GC_10, pars->mdl_Me, pars->ZERO,
             w[48]);
    FFV1_2(w[3], w[35], pars->GC_3, pars->mdl_Me, pars->ZERO, w[49]);
    FFV1_1(w[2], w[35], pars->GC_3, pars->mdl_Me, pars->ZERO, w[50]);
    FFV2_5_2(w[3], w[36], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[51]);
    FFV2_5_1(w[2], w[36], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[52]);
    FFV2_3_3(w[5], w[22], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[53]);
    FFV1P0_3(w[5], w[22], pars->GC_3, pars->ZERO, pars->ZERO, w[54]);
    FFV2_5_3(w[5], w[22], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[55]);
    FFV2_3_3(w[25], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[56]);
    FFV1P0_3(w[25], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[57]);
    FFV2_5_3(w[25], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[58]);
    FFV1_2(w[0], w[6], pars->GC_1, pars->mdl_MS, pars->ZERO, w[59]);
    FFV1P0_3(w[59], w[1], pars->GC_1, pars->ZERO, pars->ZERO, w[60]);
    FFV2_4_3(w[59], w[1], pars->GC_29, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[61]);
    FFV1_2(w[59], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[62]);
    FFV1_2(w[59], w[35], pars->GC_1, pars->mdl_MS, pars->ZERO, w[63]);
    FFV2_4_2(w[59], w[36], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[64]);
    FFV2_4_2(w[59], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[65]);
    FFV1_1(w[1], w[6], pars->GC_1, pars->mdl_MS, pars->ZERO, w[66]);
    FFV1P0_3(w[0], w[66], pars->GC_1, pars->ZERO, pars->ZERO, w[67]);
    FFV2_4_3(w[0], w[66], pars->GC_29, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[68]);
    FFV1_2(w[0], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[69]);
    FFV1_2(w[0], w[35], pars->GC_1, pars->mdl_MS, pars->ZERO, w[70]);
    FFV2_4_2(w[0], w[36], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[71]);
    FFV2_4_2(w[0], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[72]);
    FFV1_1(w[1], w[35], pars->GC_1, pars->mdl_MS, pars->ZERO, w[73]);
    FFV1_1(w[1], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[74]);
    FFV2_4_1(w[1], w[36], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[75]);
    FFV2_4_1(w[1], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[76]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV1_0(w[10], w[9], w[6], pars->GC_3, amp[0]);
    FFV1_0(w[11], w[12], w[6], pars->GC_3, amp[1]);
    FFV1_0(w[14], w[9], w[6], pars->GC_3, amp[2]);
    FFV1_0(w[11], w[15], w[6], pars->GC_3, amp[3]);
    FFV1_0(w[17], w[9], w[6], pars->GC_3, amp[4]);
    FFV1_0(w[11], w[18], w[6], pars->GC_3, amp[5]);
    FFV1_0(w[10], w[20], w[6], pars->GC_3, amp[6]);
    FFV1_0(w[21], w[12], w[6], pars->GC_3, amp[7]);
    FFV1_0(w[14], w[20], w[6], pars->GC_3, amp[8]);
    FFV1_0(w[21], w[15], w[6], pars->GC_3, amp[9]);
    FFV1_0(w[17], w[20], w[6], pars->GC_3, amp[10]);
    FFV1_0(w[21], w[18], w[6], pars->GC_3, amp[11]);
    FFV2_3_0(w[5], w[23], w[8], pars->GC_11, pars->GC_12, amp[12]);
    FFV2_3_0(w[11], w[22], w[8], pars->GC_11, pars->GC_12, amp[13]);
    FFV1_0(w[5], w[23], w[13], pars->GC_3, amp[14]);
    FFV1_0(w[11], w[22], w[13], pars->GC_3, amp[15]);
    FFV2_5_0(w[5], w[23], w[16], pars->GC_29, pars->GC_34, amp[16]);
    FFV2_5_0(w[11], w[22], w[16], pars->GC_29, pars->GC_34, amp[17]);
    FFV2_3_0(w[5], w[24], w[8], pars->GC_11, pars->GC_12, amp[18]);
    FFV2_3_0(w[21], w[22], w[8], pars->GC_11, pars->GC_12, amp[19]);
    FFV1_0(w[5], w[24], w[13], pars->GC_3, amp[20]);
    FFV1_0(w[21], w[22], w[13], pars->GC_3, amp[21]);
    FFV2_5_0(w[5], w[24], w[16], pars->GC_29, pars->GC_34, amp[22]);
    FFV2_5_0(w[21], w[22], w[16], pars->GC_29, pars->GC_34, amp[23]);
    FFV2_3_0(w[25], w[9], w[8], pars->GC_11, pars->GC_12, amp[24]);
    FFV2_3_0(w[26], w[4], w[8], pars->GC_11, pars->GC_12, amp[25]);
    FFV1_0(w[25], w[9], w[13], pars->GC_3, amp[26]);
    FFV1_0(w[26], w[4], w[13], pars->GC_3, amp[27]);
    FFV2_5_0(w[25], w[9], w[16], pars->GC_29, pars->GC_34, amp[28]);
    FFV2_5_0(w[26], w[4], w[16], pars->GC_29, pars->GC_34, amp[29]);
    FFV2_3_0(w[25], w[20], w[8], pars->GC_11, pars->GC_12, amp[30]);
    FFV2_3_0(w[27], w[4], w[8], pars->GC_11, pars->GC_12, amp[31]);
    FFV1_0(w[25], w[20], w[13], pars->GC_3, amp[32]);
    FFV1_0(w[27], w[4], w[13], pars->GC_3, amp[33]);
    FFV2_5_0(w[25], w[20], w[16], pars->GC_29, pars->GC_34, amp[34]);
    FFV2_5_0(w[27], w[4], w[16], pars->GC_29, pars->GC_34, amp[35]);
    FFV2_3_0(w[5], w[9], w[29], pars->GC_11, pars->GC_12, amp[36]);
    FFV1_0(w[5], w[9], w[30], pars->GC_3, amp[37]);
    FFV2_5_0(w[5], w[9], w[31], pars->GC_29, pars->GC_34, amp[38]);
    FFV2_3_0(w[11], w[4], w[29], pars->GC_11, pars->GC_12, amp[39]);
    FFV1_0(w[11], w[4], w[30], pars->GC_3, amp[40]);
    FFV2_5_0(w[11], w[4], w[31], pars->GC_29, pars->GC_34, amp[41]);
    FFV2_3_0(w[5], w[20], w[29], pars->GC_11, pars->GC_12, amp[42]);
    FFV1_0(w[5], w[20], w[30], pars->GC_3, amp[43]);
    FFV2_5_0(w[5], w[20], w[31], pars->GC_29, pars->GC_34, amp[44]);
    FFV2_3_0(w[21], w[4], w[29], pars->GC_11, pars->GC_12, amp[45]);
    FFV1_0(w[21], w[4], w[30], pars->GC_3, amp[46]);
    FFV2_5_0(w[21], w[4], w[31], pars->GC_29, pars->GC_34, amp[47]);
    FFV2_3_0(w[3], w[33], w[32], pars->GC_9, pars->GC_10, amp[48]);
    FFV2_3_0(w[34], w[28], w[32], pars->GC_9, pars->GC_10, amp[49]);
    FFV1_0(w[3], w[33], w[35], pars->GC_3, amp[50]);
    FFV1_0(w[34], w[28], w[35], pars->GC_3, amp[51]);
    FFV2_5_0(w[3], w[33], w[36], pars->GC_29, pars->GC_34, amp[52]);
    FFV2_5_0(w[34], w[28], w[36], pars->GC_29, pars->GC_34, amp[53]);
    FFV2_3_0(w[3], w[37], w[32], pars->GC_9, pars->GC_10, amp[54]);
    FFV2_3_0(w[38], w[28], w[32], pars->GC_9, pars->GC_10, amp[55]);
    FFV1_0(w[3], w[37], w[35], pars->GC_3, amp[56]);
    FFV1_0(w[38], w[28], w[35], pars->GC_3, amp[57]);
    FFV2_5_0(w[3], w[37], w[36], pars->GC_29, pars->GC_34, amp[58]);
    FFV2_5_0(w[38], w[28], w[36], pars->GC_29, pars->GC_34, amp[59]);
    FFV2_3_0(w[5], w[9], w[40], pars->GC_11, pars->GC_12, amp[60]);
    FFV1_0(w[5], w[9], w[41], pars->GC_3, amp[61]);
    FFV2_5_0(w[5], w[9], w[42], pars->GC_29, pars->GC_34, amp[62]);
    FFV2_3_0(w[11], w[4], w[40], pars->GC_11, pars->GC_12, amp[63]);
    FFV1_0(w[11], w[4], w[41], pars->GC_3, amp[64]);
    FFV2_5_0(w[11], w[4], w[42], pars->GC_29, pars->GC_34, amp[65]);
    FFV2_3_0(w[5], w[20], w[40], pars->GC_11, pars->GC_12, amp[66]);
    FFV1_0(w[5], w[20], w[41], pars->GC_3, amp[67]);
    FFV2_5_0(w[5], w[20], w[42], pars->GC_29, pars->GC_34, amp[68]);
    FFV2_3_0(w[21], w[4], w[40], pars->GC_11, pars->GC_12, amp[69]);
    FFV1_0(w[21], w[4], w[41], pars->GC_3, amp[70]);
    FFV2_5_0(w[21], w[4], w[42], pars->GC_29, pars->GC_34, amp[71]);
    FFV2_3_0(w[39], w[43], w[32], pars->GC_9, pars->GC_10, amp[72]);
    FFV2_3_0(w[44], w[2], w[32], pars->GC_9, pars->GC_10, amp[73]);
    FFV1_0(w[39], w[43], w[35], pars->GC_3, amp[74]);
    FFV1_0(w[44], w[2], w[35], pars->GC_3, amp[75]);
    FFV2_5_0(w[39], w[43], w[36], pars->GC_29, pars->GC_34, amp[76]);
    FFV2_5_0(w[44], w[2], w[36], pars->GC_29, pars->GC_34, amp[77]);
    FFV2_3_0(w[39], w[45], w[32], pars->GC_9, pars->GC_10, amp[78]);
    FFV2_3_0(w[46], w[2], w[32], pars->GC_9, pars->GC_10, amp[79]);
    FFV1_0(w[39], w[45], w[35], pars->GC_3, amp[80]);
    FFV1_0(w[46], w[2], w[35], pars->GC_3, amp[81]);
    FFV2_5_0(w[39], w[45], w[36], pars->GC_29, pars->GC_34, amp[82]);
    FFV2_5_0(w[46], w[2], w[36], pars->GC_29, pars->GC_34, amp[83]);
    FFV1_0(w[47], w[43], w[6], pars->GC_3, amp[84]);
    FFV1_0(w[34], w[48], w[6], pars->GC_3, amp[85]);
    FFV1_0(w[49], w[43], w[6], pars->GC_3, amp[86]);
    FFV1_0(w[34], w[50], w[6], pars->GC_3, amp[87]);
    FFV1_0(w[51], w[43], w[6], pars->GC_3, amp[88]);
    FFV1_0(w[34], w[52], w[6], pars->GC_3, amp[89]);
    FFV1_0(w[47], w[45], w[6], pars->GC_3, amp[90]);
    FFV1_0(w[38], w[48], w[6], pars->GC_3, amp[91]);
    FFV1_0(w[49], w[45], w[6], pars->GC_3, amp[92]);
    FFV1_0(w[38], w[50], w[6], pars->GC_3, amp[93]);
    FFV1_0(w[51], w[45], w[6], pars->GC_3, amp[94]);
    FFV1_0(w[38], w[52], w[6], pars->GC_3, amp[95]);
    FFV2_3_0(w[3], w[43], w[53], pars->GC_9, pars->GC_10, amp[96]);
    FFV1_0(w[3], w[43], w[54], pars->GC_3, amp[97]);
    FFV2_5_0(w[3], w[43], w[55], pars->GC_29, pars->GC_34, amp[98]);
    FFV2_3_0(w[34], w[2], w[53], pars->GC_9, pars->GC_10, amp[99]);
    FFV1_0(w[34], w[2], w[54], pars->GC_3, amp[100]);
    FFV2_5_0(w[34], w[2], w[55], pars->GC_29, pars->GC_34, amp[101]);
    FFV2_3_0(w[3], w[45], w[53], pars->GC_9, pars->GC_10, amp[102]);
    FFV1_0(w[3], w[45], w[54], pars->GC_3, amp[103]);
    FFV2_5_0(w[3], w[45], w[55], pars->GC_29, pars->GC_34, amp[104]);
    FFV2_3_0(w[38], w[2], w[53], pars->GC_9, pars->GC_10, amp[105]);
    FFV1_0(w[38], w[2], w[54], pars->GC_3, amp[106]);
    FFV2_5_0(w[38], w[2], w[55], pars->GC_29, pars->GC_34, amp[107]);
    FFV2_3_0(w[3], w[43], w[56], pars->GC_9, pars->GC_10, amp[108]);
    FFV1_0(w[3], w[43], w[57], pars->GC_3, amp[109]);
    FFV2_5_0(w[3], w[43], w[58], pars->GC_29, pars->GC_34, amp[110]);
    FFV2_3_0(w[34], w[2], w[56], pars->GC_9, pars->GC_10, amp[111]);
    FFV1_0(w[34], w[2], w[57], pars->GC_3, amp[112]);
    FFV2_5_0(w[34], w[2], w[58], pars->GC_29, pars->GC_34, amp[113]);
    FFV2_3_0(w[3], w[45], w[56], pars->GC_9, pars->GC_10, amp[114]);
    FFV1_0(w[3], w[45], w[57], pars->GC_3, amp[115]);
    FFV2_5_0(w[3], w[45], w[58], pars->GC_29, pars->GC_34, amp[116]);
    FFV2_3_0(w[38], w[2], w[56], pars->GC_9, pars->GC_10, amp[117]);
    FFV1_0(w[38], w[2], w[57], pars->GC_3, amp[118]);
    FFV2_5_0(w[38], w[2], w[58], pars->GC_29, pars->GC_34, amp[119]);
    FFV1_0(w[5], w[12], w[60], pars->GC_3, amp[120]);
    FFV2_5_0(w[5], w[12], w[61], pars->GC_29, pars->GC_34, amp[121]);
    FFV1_0(w[10], w[4], w[60], pars->GC_3, amp[122]);
    FFV2_5_0(w[10], w[4], w[61], pars->GC_29, pars->GC_34, amp[123]);
    FFV1_0(w[5], w[15], w[60], pars->GC_3, amp[124]);
    FFV2_5_0(w[5], w[15], w[61], pars->GC_29, pars->GC_34, amp[125]);
    FFV1_0(w[14], w[4], w[60], pars->GC_3, amp[126]);
    FFV2_5_0(w[14], w[4], w[61], pars->GC_29, pars->GC_34, amp[127]);
    FFV1_0(w[5], w[18], w[60], pars->GC_3, amp[128]);
    FFV2_5_0(w[5], w[18], w[61], pars->GC_29, pars->GC_34, amp[129]);
    FFV1_0(w[17], w[4], w[60], pars->GC_3, amp[130]);
    FFV2_5_0(w[17], w[4], w[61], pars->GC_29, pars->GC_34, amp[131]);
    FFV1_0(w[62], w[1], w[35], pars->GC_1, amp[132]);
    FFV1_0(w[63], w[1], w[13], pars->GC_1, amp[133]);
    FFV2_4_0(w[62], w[1], w[36], pars->GC_29, pars->GC_33, amp[134]);
    FFV1_0(w[64], w[1], w[13], pars->GC_1, amp[135]);
    FFV1_0(w[65], w[1], w[35], pars->GC_1, amp[136]);
    FFV2_4_0(w[63], w[1], w[16], pars->GC_29, pars->GC_33, amp[137]);
    FFV2_4_0(w[65], w[1], w[36], pars->GC_29, pars->GC_33, amp[138]);
    FFV2_4_0(w[64], w[1], w[16], pars->GC_29, pars->GC_33, amp[139]);
    FFV1_0(w[3], w[48], w[60], pars->GC_3, amp[140]);
    FFV2_5_0(w[3], w[48], w[61], pars->GC_29, pars->GC_34, amp[141]);
    FFV1_0(w[47], w[2], w[60], pars->GC_3, amp[142]);
    FFV2_5_0(w[47], w[2], w[61], pars->GC_29, pars->GC_34, amp[143]);
    FFV1_0(w[3], w[50], w[60], pars->GC_3, amp[144]);
    FFV2_5_0(w[3], w[50], w[61], pars->GC_29, pars->GC_34, amp[145]);
    FFV1_0(w[49], w[2], w[60], pars->GC_3, amp[146]);
    FFV2_5_0(w[49], w[2], w[61], pars->GC_29, pars->GC_34, amp[147]);
    FFV1_0(w[3], w[52], w[60], pars->GC_3, amp[148]);
    FFV2_5_0(w[3], w[52], w[61], pars->GC_29, pars->GC_34, amp[149]);
    FFV1_0(w[51], w[2], w[60], pars->GC_3, amp[150]);
    FFV2_5_0(w[51], w[2], w[61], pars->GC_29, pars->GC_34, amp[151]);
    FFV1_0(w[5], w[12], w[67], pars->GC_3, amp[152]);
    FFV2_5_0(w[5], w[12], w[68], pars->GC_29, pars->GC_34, amp[153]);
    FFV1_0(w[10], w[4], w[67], pars->GC_3, amp[154]);
    FFV2_5_0(w[10], w[4], w[68], pars->GC_29, pars->GC_34, amp[155]);
    FFV1_0(w[5], w[15], w[67], pars->GC_3, amp[156]);
    FFV2_5_0(w[5], w[15], w[68], pars->GC_29, pars->GC_34, amp[157]);
    FFV1_0(w[14], w[4], w[67], pars->GC_3, amp[158]);
    FFV2_5_0(w[14], w[4], w[68], pars->GC_29, pars->GC_34, amp[159]);
    FFV1_0(w[5], w[18], w[67], pars->GC_3, amp[160]);
    FFV2_5_0(w[5], w[18], w[68], pars->GC_29, pars->GC_34, amp[161]);
    FFV1_0(w[17], w[4], w[67], pars->GC_3, amp[162]);
    FFV2_5_0(w[17], w[4], w[68], pars->GC_29, pars->GC_34, amp[163]);
    FFV1_0(w[69], w[66], w[35], pars->GC_1, amp[164]);
    FFV1_0(w[70], w[66], w[13], pars->GC_1, amp[165]);
    FFV2_4_0(w[69], w[66], w[36], pars->GC_29, pars->GC_33, amp[166]);
    FFV1_0(w[71], w[66], w[13], pars->GC_1, amp[167]);
    FFV1_0(w[72], w[66], w[35], pars->GC_1, amp[168]);
    FFV2_4_0(w[70], w[66], w[16], pars->GC_29, pars->GC_33, amp[169]);
    FFV2_4_0(w[72], w[66], w[36], pars->GC_29, pars->GC_33, amp[170]);
    FFV2_4_0(w[71], w[66], w[16], pars->GC_29, pars->GC_33, amp[171]);
    FFV1_0(w[3], w[48], w[67], pars->GC_3, amp[172]);
    FFV2_5_0(w[3], w[48], w[68], pars->GC_29, pars->GC_34, amp[173]);
    FFV1_0(w[47], w[2], w[67], pars->GC_3, amp[174]);
    FFV2_5_0(w[47], w[2], w[68], pars->GC_29, pars->GC_34, amp[175]);
    FFV1_0(w[3], w[50], w[67], pars->GC_3, amp[176]);
    FFV2_5_0(w[3], w[50], w[68], pars->GC_29, pars->GC_34, amp[177]);
    FFV1_0(w[49], w[2], w[67], pars->GC_3, amp[178]);
    FFV2_5_0(w[49], w[2], w[68], pars->GC_29, pars->GC_34, amp[179]);
    FFV1_0(w[3], w[52], w[67], pars->GC_3, amp[180]);
    FFV2_5_0(w[3], w[52], w[68], pars->GC_29, pars->GC_34, amp[181]);
    FFV1_0(w[51], w[2], w[67], pars->GC_3, amp[182]);
    FFV2_5_0(w[51], w[2], w[68], pars->GC_29, pars->GC_34, amp[183]);
    FFV1_0(w[69], w[73], w[6], pars->GC_1, amp[184]);
    FFV1_0(w[70], w[74], w[6], pars->GC_1, amp[185]);
    FFV1_0(w[69], w[75], w[6], pars->GC_1, amp[186]);
    FFV1_0(w[71], w[74], w[6], pars->GC_1, amp[187]);
    FFV1_0(w[72], w[73], w[6], pars->GC_1, amp[188]);
    FFV1_0(w[70], w[76], w[6], pars->GC_1, amp[189]);
    FFV1_0(w[72], w[75], w[6], pars->GC_1, amp[190]);
    FFV1_0(w[71], w[76], w[6], pars->GC_1, amp[191]);
    FFV1_0(w[69], w[1], w[54], pars->GC_1, amp[192]);
    FFV2_4_0(w[69], w[1], w[55], pars->GC_29, pars->GC_33, amp[193]);
    FFV1_0(w[0], w[74], w[54], pars->GC_1, amp[194]);
    FFV2_4_0(w[0], w[74], w[55], pars->GC_29, pars->GC_33, amp[195]);
    FFV1_0(w[72], w[1], w[54], pars->GC_1, amp[196]);
    FFV2_4_0(w[72], w[1], w[55], pars->GC_29, pars->GC_33, amp[197]);
    FFV1_0(w[0], w[76], w[54], pars->GC_1, amp[198]);
    FFV2_4_0(w[0], w[76], w[55], pars->GC_29, pars->GC_33, amp[199]);
    FFV1_0(w[69], w[1], w[57], pars->GC_1, amp[200]);
    FFV2_4_0(w[69], w[1], w[58], pars->GC_29, pars->GC_33, amp[201]);
    FFV1_0(w[0], w[74], w[57], pars->GC_1, amp[202]);
    FFV2_4_0(w[0], w[74], w[58], pars->GC_29, pars->GC_33, amp[203]);
    FFV1_0(w[72], w[1], w[57], pars->GC_1, amp[204]);
    FFV2_4_0(w[72], w[1], w[58], pars->GC_29, pars->GC_33, amp[205]);
    FFV1_0(w[0], w[76], w[57], pars->GC_1, amp[206]);
    FFV2_4_0(w[0], w[76], w[58], pars->GC_29, pars->GC_33, amp[207]);
    FFV1_0(w[70], w[1], w[30], pars->GC_1, amp[208]);
    FFV2_4_0(w[70], w[1], w[31], pars->GC_29, pars->GC_33, amp[209]);
    FFV1_0(w[0], w[73], w[30], pars->GC_1, amp[210]);
    FFV2_4_0(w[0], w[73], w[31], pars->GC_29, pars->GC_33, amp[211]);
    FFV1_0(w[71], w[1], w[30], pars->GC_1, amp[212]);
    FFV2_4_0(w[71], w[1], w[31], pars->GC_29, pars->GC_33, amp[213]);
    FFV1_0(w[0], w[75], w[30], pars->GC_1, amp[214]);
    FFV2_4_0(w[0], w[75], w[31], pars->GC_29, pars->GC_33, amp[215]);
    FFV1_0(w[70], w[1], w[41], pars->GC_1, amp[216]);
    FFV2_4_0(w[70], w[1], w[42], pars->GC_29, pars->GC_33, amp[217]);
    FFV1_0(w[0], w[73], w[41], pars->GC_1, amp[218]);
    FFV2_4_0(w[0], w[73], w[42], pars->GC_29, pars->GC_33, amp[219]);
    FFV1_0(w[71], w[1], w[41], pars->GC_1, amp[220]);
    FFV2_4_0(w[71], w[1], w[42], pars->GC_29, pars->GC_33, amp[221]);
    FFV1_0(w[0], w[75], w[41], pars->GC_1, amp[222]);
    FFV2_4_0(w[0], w[75], w[42], pars->GC_29, pars->GC_33, amp[223]);
}
double qq_z_zp_DN_OFpA::matrix_3_ssx_emepmummupa_no_h()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 224;
    const int ncolor = 1;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1};
    static const double cf[ncolor][ncolor] = {{3}};

    // Calculate color flows
    jamp[0] =
        +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] + amp[6] + amp[7] +
        amp[8] + amp[9] + amp[10] + amp[11] + amp[12] + amp[13] + amp[14] +
        amp[15] + amp[16] + amp[17] + amp[18] + amp[19] + amp[20] + amp[21] +
        amp[22] + amp[23] + amp[24] + amp[25] + amp[26] + amp[27] + amp[28] +
        amp[29] + amp[30] + amp[31] + amp[32] + amp[33] + amp[34] + amp[35] +
        amp[36] + amp[37] + amp[38] + amp[39] + amp[40] + amp[41] + amp[42] +
        amp[43] + amp[44] + amp[45] + amp[46] + amp[47] + amp[48] + amp[49] +
        amp[50] + amp[51] + amp[52] + amp[53] + amp[54] + amp[55] + amp[56] +
        amp[57] + amp[58] + amp[59] + amp[60] + amp[61] + amp[62] + amp[63] +
        amp[64] + amp[65] + amp[66] + amp[67] + amp[68] + amp[69] + amp[70] +
        amp[71] + amp[72] + amp[73] + amp[74] + amp[75] + amp[76] + amp[77] +
        amp[78] + amp[79] + amp[80] + amp[81] + amp[82] + amp[83] + amp[84] +
        amp[85] + amp[86] + amp[87] + amp[88] + amp[89] + amp[90] + amp[91] +
        amp[92] + amp[93] + amp[94] + amp[95] + amp[96] + amp[97] + amp[98] +
        amp[99] + amp[100] + amp[101] + amp[102] + amp[103] + amp[104] +
        amp[105] + amp[106] + amp[107] + amp[108] + amp[109] + amp[110] +
        amp[111] + amp[112] + amp[113] + amp[114] + amp[115] + amp[116] +
        amp[117] + amp[118] + amp[119] + amp[120] + amp[121] + amp[122] +
        amp[123] + amp[124] + amp[125] + amp[126] + amp[127] + amp[128] +
        amp[129] + amp[130] + amp[131] + amp[132] + amp[133] + amp[134] +
        amp[135] + amp[136] + amp[137] + amp[138] + amp[139] + amp[140] +
        amp[141] + amp[142] + amp[143] + amp[144] + amp[145] + amp[146] +
        amp[147] + amp[148] + amp[149] + amp[150] + amp[151] + amp[152] +
        amp[153] + amp[154] + amp[155] + amp[156] + amp[157] + amp[158] +
        amp[159] + amp[160] + amp[161] + amp[162] + amp[163] + amp[164] +
        amp[165] + amp[166] + amp[167] + amp[168] + amp[169] + amp[170] +
        amp[171] + amp[172] + amp[173] + amp[174] + amp[175] + amp[176] +
        amp[177] + amp[178] + amp[179] + amp[180] + amp[181] + amp[182] +
        amp[183] + amp[184] + amp[185] + amp[186] + amp[187] + amp[188] +
        amp[189] + amp[190] + amp[191] + amp[192] + amp[193] + amp[194] +
        amp[195] + amp[196] + amp[197] + amp[198] + amp[199] + amp[200] +
        amp[201] + amp[202] + amp[203] + amp[204] + amp[205] + amp[206] +
        amp[207] + amp[208] + amp[209] + amp[210] + amp[211] + amp[212] +
        amp[213] + amp[214] + amp[215] + amp[216] + amp[217] + amp[218] +
        amp[219] + amp[220] + amp[221] + amp[222] + amp[223];

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

} // namespace MG5_Leptophilic_UFO
