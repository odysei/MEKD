//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.6.4, 2018-11-09
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "qq_z_zp_DN_SFpA.h"
#include "HelAmps_Leptophilic_UFO.h"

using namespace std;

namespace MG5_Leptophilic_UFO
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: s s~ > mu- mu+ mu- mu+ a WEIGHTED<=10 / h @4

//--------------------------------------------------------------------------
// Initialize process.

void qq_z_zp_DN_SFpA::initProc(string param_card_name)
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
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

void qq_z_zp_DN_SFpA::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_Leptophilic_UFO::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MS);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.

void qq_z_zp_DN_SFpA::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MS);
    mME[1] = (pars->mdl_MS);
    mME[2] = (pars->mdl_MMU);
    mME[3] = (pars->mdl_MMU);
    mME[4] = (pars->mdl_MMU);
    mME[5] = (pars->mdl_MMU);
    mME[6] = (pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_z_zp_DN_SFpA::sigmaKin()
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
    const int denominators[nprocesses] = {144, 144};

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
                t[0] = matrix_4_ssx_mummupmummupa_no_h();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_4_ssx_mummupmummupa_no_h();
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
            t[0] = matrix_4_ssx_mummupmummupa_no_h();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_4_ssx_mummupmummupa_no_h();
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

double qq_z_zp_DN_SFpA::sigmaHat()
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

void qq_z_zp_DN_SFpA::calculate_wavefunctions(const int perm[], const int hel[])
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
    FFV2_3_3(w[3], w[2], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
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
    FFV2_3_3(w[5], w[2], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
             w[28]);
    FFV1_2(w[3], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[29]);
    FFV2_3_1(w[4], w[28], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[30]);
    FFV2_3_2(w[3], w[28], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[31]);
    FFV1P0_3(w[5], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[32]);
    FFV1_1(w[4], w[32], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[33]);
    FFV1_2(w[3], w[32], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[34]);
    FFV2_5_3(w[5], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[35]);
    FFV2_5_1(w[4], w[35], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[36]);
    FFV2_5_2(w[3], w[35], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[37]);
    FFV2_5_2(w[3], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[38]);
    FFV1_2(w[3], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[39]);
    FFV1_2(w[39], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[40]);
    FFV2_5_2(w[39], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[41]);
    FFV1_1(w[2], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[42]);
    FFV2_3_3(w[5], w[42], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[43]);
    FFV1P0_3(w[5], w[42], pars->GC_3, pars->ZERO, pars->ZERO, w[44]);
    FFV2_5_3(w[5], w[42], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[45]);
    FFV2_3_3(w[3], w[42], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[46]);
    FFV1P0_3(w[3], w[42], pars->GC_3, pars->ZERO, pars->ZERO, w[47]);
    FFV2_5_3(w[3], w[42], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[48]);
    FFV2_3_3(w[3], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
             w[49]);
    FFV1_1(w[42], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[50]);
    FFV1P0_3(w[3], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[51]);
    FFV2_5_3(w[3], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[52]);
    FFV2_5_1(w[42], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[53]);
    FFV2_3_3(w[5], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
             w[54]);
    FFV1P0_3(w[5], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[55]);
    FFV2_5_3(w[5], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[56]);
    FFV1_1(w[2], w[7], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[57]);
    FFV2_3_2(w[5], w[49], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[58]);
    FFV2_3_1(w[2], w[49], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[59]);
    FFV1_2(w[5], w[51], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[60]);
    FFV1_1(w[2], w[51], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[61]);
    FFV2_5_2(w[5], w[52], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[62]);
    FFV2_5_1(w[2], w[52], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[63]);
    FFV2_5_1(w[2], w[19], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[64]);
    FFV2_3_3(w[39], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[65]);
    FFV1P0_3(w[39], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[66]);
    FFV2_5_3(w[39], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[67]);
    FFV2_3_3(w[39], w[2], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[68]);
    FFV1P0_3(w[39], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[69]);
    FFV2_5_3(w[39], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[70]);
    FFV2_3_2(w[3], w[54], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[71]);
    FFV2_3_1(w[2], w[54], pars->GC_11, pars->GC_12, pars->mdl_MMU, pars->ZERO,
             w[72]);
    FFV1_2(w[3], w[55], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[73]);
    FFV1_1(w[2], w[55], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[74]);
    FFV2_5_2(w[3], w[56], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[75]);
    FFV2_5_1(w[2], w[56], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[76]);
    FFV2_3_3(w[3], w[22], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[77]);
    FFV1P0_3(w[3], w[22], pars->GC_3, pars->ZERO, pars->ZERO, w[78]);
    FFV2_5_3(w[3], w[22], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[79]);
    FFV2_3_3(w[5], w[22], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[80]);
    FFV1P0_3(w[5], w[22], pars->GC_3, pars->ZERO, pars->ZERO, w[81]);
    FFV2_5_3(w[5], w[22], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[82]);
    FFV2_3_3(w[25], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[83]);
    FFV1P0_3(w[25], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[84]);
    FFV2_5_3(w[25], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[85]);
    FFV2_3_3(w[25], w[2], pars->GC_11, pars->GC_12, pars->mdl_ZpM,
             pars->mdl_ZpW, w[86]);
    FFV1P0_3(w[25], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[87]);
    FFV2_5_3(w[25], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[88]);
    FFV1_2(w[0], w[6], pars->GC_1, pars->mdl_MS, pars->ZERO, w[89]);
    FFV1P0_3(w[89], w[1], pars->GC_1, pars->ZERO, pars->ZERO, w[90]);
    FFV2_4_3(w[89], w[1], pars->GC_29, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[91]);
    FFV1_2(w[89], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[92]);
    FFV1_2(w[89], w[55], pars->GC_1, pars->mdl_MS, pars->ZERO, w[93]);
    FFV2_4_2(w[89], w[56], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[94]);
    FFV2_4_2(w[89], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[95]);
    FFV1_2(w[89], w[32], pars->GC_1, pars->mdl_MS, pars->ZERO, w[96]);
    FFV1_2(w[89], w[51], pars->GC_1, pars->mdl_MS, pars->ZERO, w[97]);
    FFV2_4_2(w[89], w[52], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[98]);
    FFV2_4_2(w[89], w[35], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[99]);
    FFV1_1(w[1], w[6], pars->GC_1, pars->mdl_MS, pars->ZERO, w[100]);
    FFV1P0_3(w[0], w[100], pars->GC_1, pars->ZERO, pars->ZERO, w[101]);
    FFV2_4_3(w[0], w[100], pars->GC_29, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[102]);
    FFV1_2(w[0], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[103]);
    FFV1_2(w[0], w[55], pars->GC_1, pars->mdl_MS, pars->ZERO, w[104]);
    FFV2_4_2(w[0], w[56], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[105]);
    FFV2_4_2(w[0], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[106]);
    FFV1_2(w[0], w[32], pars->GC_1, pars->mdl_MS, pars->ZERO, w[107]);
    FFV1_2(w[0], w[51], pars->GC_1, pars->mdl_MS, pars->ZERO, w[108]);
    FFV2_4_2(w[0], w[52], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[109]);
    FFV2_4_2(w[0], w[35], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[110]);
    FFV1_1(w[1], w[55], pars->GC_1, pars->mdl_MS, pars->ZERO, w[111]);
    FFV1_1(w[1], w[13], pars->GC_1, pars->mdl_MS, pars->ZERO, w[112]);
    FFV2_4_1(w[1], w[56], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[113]);
    FFV2_4_1(w[1], w[16], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[114]);
    FFV1_1(w[1], w[51], pars->GC_1, pars->mdl_MS, pars->ZERO, w[115]);
    FFV1_1(w[1], w[32], pars->GC_1, pars->mdl_MS, pars->ZERO, w[116]);
    FFV2_4_1(w[1], w[52], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[117]);
    FFV2_4_1(w[1], w[35], pars->GC_29, pars->GC_33, pars->mdl_MS, pars->ZERO,
             w[118]);

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
    FFV1_0(w[29], w[30], w[6], pars->GC_3, amp[36]);
    FFV1_0(w[31], w[9], w[6], pars->GC_3, amp[37]);
    FFV1_0(w[29], w[33], w[6], pars->GC_3, amp[38]);
    FFV1_0(w[34], w[9], w[6], pars->GC_3, amp[39]);
    FFV1_0(w[29], w[36], w[6], pars->GC_3, amp[40]);
    FFV1_0(w[37], w[9], w[6], pars->GC_3, amp[41]);
    FFV1_0(w[38], w[30], w[6], pars->GC_3, amp[42]);
    FFV1_0(w[31], w[20], w[6], pars->GC_3, amp[43]);
    FFV1_0(w[38], w[33], w[6], pars->GC_3, amp[44]);
    FFV1_0(w[34], w[20], w[6], pars->GC_3, amp[45]);
    FFV1_0(w[38], w[36], w[6], pars->GC_3, amp[46]);
    FFV1_0(w[37], w[20], w[6], pars->GC_3, amp[47]);
    FFV2_3_0(w[40], w[4], w[28], pars->GC_11, pars->GC_12, amp[48]);
    FFV2_3_0(w[39], w[9], w[28], pars->GC_11, pars->GC_12, amp[49]);
    FFV1_0(w[40], w[4], w[32], pars->GC_3, amp[50]);
    FFV1_0(w[39], w[9], w[32], pars->GC_3, amp[51]);
    FFV2_5_0(w[40], w[4], w[35], pars->GC_29, pars->GC_34, amp[52]);
    FFV2_5_0(w[39], w[9], w[35], pars->GC_29, pars->GC_34, amp[53]);
    FFV2_3_0(w[41], w[4], w[28], pars->GC_11, pars->GC_12, amp[54]);
    FFV2_3_0(w[39], w[20], w[28], pars->GC_11, pars->GC_12, amp[55]);
    FFV1_0(w[41], w[4], w[32], pars->GC_3, amp[56]);
    FFV1_0(w[39], w[20], w[32], pars->GC_3, amp[57]);
    FFV2_5_0(w[41], w[4], w[35], pars->GC_29, pars->GC_34, amp[58]);
    FFV2_5_0(w[39], w[20], w[35], pars->GC_29, pars->GC_34, amp[59]);
    FFV2_3_0(w[29], w[22], w[28], pars->GC_11, pars->GC_12, amp[60]);
    FFV2_3_0(w[3], w[23], w[28], pars->GC_11, pars->GC_12, amp[61]);
    FFV1_0(w[29], w[22], w[32], pars->GC_3, amp[62]);
    FFV1_0(w[3], w[23], w[32], pars->GC_3, amp[63]);
    FFV2_5_0(w[29], w[22], w[35], pars->GC_29, pars->GC_34, amp[64]);
    FFV2_5_0(w[3], w[23], w[35], pars->GC_29, pars->GC_34, amp[65]);
    FFV2_3_0(w[38], w[22], w[28], pars->GC_11, pars->GC_12, amp[66]);
    FFV2_3_0(w[3], w[24], w[28], pars->GC_11, pars->GC_12, amp[67]);
    FFV1_0(w[38], w[22], w[32], pars->GC_3, amp[68]);
    FFV1_0(w[3], w[24], w[32], pars->GC_3, amp[69]);
    FFV2_5_0(w[38], w[22], w[35], pars->GC_29, pars->GC_34, amp[70]);
    FFV2_5_0(w[3], w[24], w[35], pars->GC_29, pars->GC_34, amp[71]);
    FFV2_3_0(w[29], w[4], w[43], pars->GC_11, pars->GC_12, amp[72]);
    FFV1_0(w[29], w[4], w[44], pars->GC_3, amp[73]);
    FFV2_5_0(w[29], w[4], w[45], pars->GC_29, pars->GC_34, amp[74]);
    FFV2_3_0(w[5], w[9], w[46], pars->GC_11, pars->GC_12, amp[75]);
    FFV1_0(w[5], w[9], w[47], pars->GC_3, amp[76]);
    FFV2_5_0(w[5], w[9], w[48], pars->GC_29, pars->GC_34, amp[77]);
    FFV2_3_0(w[3], w[9], w[43], pars->GC_11, pars->GC_12, amp[78]);
    FFV1_0(w[3], w[9], w[44], pars->GC_3, amp[79]);
    FFV2_5_0(w[3], w[9], w[45], pars->GC_29, pars->GC_34, amp[80]);
    FFV2_3_0(w[11], w[4], w[46], pars->GC_11, pars->GC_12, amp[81]);
    FFV1_0(w[11], w[4], w[47], pars->GC_3, amp[82]);
    FFV2_5_0(w[11], w[4], w[48], pars->GC_29, pars->GC_34, amp[83]);
    FFV2_3_0(w[38], w[4], w[43], pars->GC_11, pars->GC_12, amp[84]);
    FFV1_0(w[38], w[4], w[44], pars->GC_3, amp[85]);
    FFV2_5_0(w[38], w[4], w[45], pars->GC_29, pars->GC_34, amp[86]);
    FFV2_3_0(w[5], w[20], w[46], pars->GC_11, pars->GC_12, amp[87]);
    FFV1_0(w[5], w[20], w[47], pars->GC_3, amp[88]);
    FFV2_5_0(w[5], w[20], w[48], pars->GC_29, pars->GC_34, amp[89]);
    FFV2_3_0(w[3], w[20], w[43], pars->GC_11, pars->GC_12, amp[90]);
    FFV1_0(w[3], w[20], w[44], pars->GC_3, amp[91]);
    FFV2_5_0(w[3], w[20], w[45], pars->GC_29, pars->GC_34, amp[92]);
    FFV2_3_0(w[21], w[4], w[46], pars->GC_11, pars->GC_12, amp[93]);
    FFV1_0(w[21], w[4], w[47], pars->GC_3, amp[94]);
    FFV2_5_0(w[21], w[4], w[48], pars->GC_29, pars->GC_34, amp[95]);
    FFV2_3_0(w[5], w[50], w[49], pars->GC_11, pars->GC_12, amp[96]);
    FFV2_3_0(w[11], w[42], w[49], pars->GC_11, pars->GC_12, amp[97]);
    FFV1_0(w[5], w[50], w[51], pars->GC_3, amp[98]);
    FFV1_0(w[11], w[42], w[51], pars->GC_3, amp[99]);
    FFV2_5_0(w[5], w[50], w[52], pars->GC_29, pars->GC_34, amp[100]);
    FFV2_5_0(w[11], w[42], w[52], pars->GC_29, pars->GC_34, amp[101]);
    FFV2_3_0(w[5], w[53], w[49], pars->GC_11, pars->GC_12, amp[102]);
    FFV2_3_0(w[21], w[42], w[49], pars->GC_11, pars->GC_12, amp[103]);
    FFV1_0(w[5], w[53], w[51], pars->GC_3, amp[104]);
    FFV1_0(w[21], w[42], w[51], pars->GC_3, amp[105]);
    FFV2_5_0(w[5], w[53], w[52], pars->GC_29, pars->GC_34, amp[106]);
    FFV2_5_0(w[21], w[42], w[52], pars->GC_29, pars->GC_34, amp[107]);
    FFV2_3_0(w[3], w[50], w[54], pars->GC_11, pars->GC_12, amp[108]);
    FFV2_3_0(w[29], w[42], w[54], pars->GC_11, pars->GC_12, amp[109]);
    FFV1_0(w[3], w[50], w[55], pars->GC_3, amp[110]);
    FFV1_0(w[29], w[42], w[55], pars->GC_3, amp[111]);
    FFV2_5_0(w[3], w[50], w[56], pars->GC_29, pars->GC_34, amp[112]);
    FFV2_5_0(w[29], w[42], w[56], pars->GC_29, pars->GC_34, amp[113]);
    FFV2_3_0(w[3], w[53], w[54], pars->GC_11, pars->GC_12, amp[114]);
    FFV2_3_0(w[38], w[42], w[54], pars->GC_11, pars->GC_12, amp[115]);
    FFV1_0(w[3], w[53], w[55], pars->GC_3, amp[116]);
    FFV1_0(w[38], w[42], w[55], pars->GC_3, amp[117]);
    FFV2_5_0(w[3], w[53], w[56], pars->GC_29, pars->GC_34, amp[118]);
    FFV2_5_0(w[38], w[42], w[56], pars->GC_29, pars->GC_34, amp[119]);
    FFV1_0(w[58], w[57], w[6], pars->GC_3, amp[120]);
    FFV1_0(w[11], w[59], w[6], pars->GC_3, amp[121]);
    FFV1_0(w[60], w[57], w[6], pars->GC_3, amp[122]);
    FFV1_0(w[11], w[61], w[6], pars->GC_3, amp[123]);
    FFV1_0(w[62], w[57], w[6], pars->GC_3, amp[124]);
    FFV1_0(w[11], w[63], w[6], pars->GC_3, amp[125]);
    FFV1_0(w[58], w[64], w[6], pars->GC_3, amp[126]);
    FFV1_0(w[21], w[59], w[6], pars->GC_3, amp[127]);
    FFV1_0(w[60], w[64], w[6], pars->GC_3, amp[128]);
    FFV1_0(w[21], w[61], w[6], pars->GC_3, amp[129]);
    FFV1_0(w[62], w[64], w[6], pars->GC_3, amp[130]);
    FFV1_0(w[21], w[63], w[6], pars->GC_3, amp[131]);
    FFV2_3_0(w[25], w[57], w[49], pars->GC_11, pars->GC_12, amp[132]);
    FFV2_3_0(w[26], w[2], w[49], pars->GC_11, pars->GC_12, amp[133]);
    FFV1_0(w[25], w[57], w[51], pars->GC_3, amp[134]);
    FFV1_0(w[26], w[2], w[51], pars->GC_3, amp[135]);
    FFV2_5_0(w[25], w[57], w[52], pars->GC_29, pars->GC_34, amp[136]);
    FFV2_5_0(w[26], w[2], w[52], pars->GC_29, pars->GC_34, amp[137]);
    FFV2_3_0(w[25], w[64], w[49], pars->GC_11, pars->GC_12, amp[138]);
    FFV2_3_0(w[27], w[2], w[49], pars->GC_11, pars->GC_12, amp[139]);
    FFV1_0(w[25], w[64], w[51], pars->GC_3, amp[140]);
    FFV1_0(w[27], w[2], w[51], pars->GC_3, amp[141]);
    FFV2_5_0(w[25], w[64], w[52], pars->GC_29, pars->GC_34, amp[142]);
    FFV2_5_0(w[27], w[2], w[52], pars->GC_29, pars->GC_34, amp[143]);
    FFV2_3_0(w[5], w[57], w[65], pars->GC_11, pars->GC_12, amp[144]);
    FFV1_0(w[5], w[57], w[66], pars->GC_3, amp[145]);
    FFV2_5_0(w[5], w[57], w[67], pars->GC_29, pars->GC_34, amp[146]);
    FFV2_3_0(w[5], w[9], w[68], pars->GC_11, pars->GC_12, amp[147]);
    FFV1_0(w[5], w[9], w[69], pars->GC_3, amp[148]);
    FFV2_5_0(w[5], w[9], w[70], pars->GC_29, pars->GC_34, amp[149]);
    FFV2_3_0(w[11], w[4], w[68], pars->GC_11, pars->GC_12, amp[150]);
    FFV1_0(w[11], w[4], w[69], pars->GC_3, amp[151]);
    FFV2_5_0(w[11], w[4], w[70], pars->GC_29, pars->GC_34, amp[152]);
    FFV2_3_0(w[11], w[2], w[65], pars->GC_11, pars->GC_12, amp[153]);
    FFV1_0(w[11], w[2], w[66], pars->GC_3, amp[154]);
    FFV2_5_0(w[11], w[2], w[67], pars->GC_29, pars->GC_34, amp[155]);
    FFV2_3_0(w[5], w[64], w[65], pars->GC_11, pars->GC_12, amp[156]);
    FFV1_0(w[5], w[64], w[66], pars->GC_3, amp[157]);
    FFV2_5_0(w[5], w[64], w[67], pars->GC_29, pars->GC_34, amp[158]);
    FFV2_3_0(w[5], w[20], w[68], pars->GC_11, pars->GC_12, amp[159]);
    FFV1_0(w[5], w[20], w[69], pars->GC_3, amp[160]);
    FFV2_5_0(w[5], w[20], w[70], pars->GC_29, pars->GC_34, amp[161]);
    FFV2_3_0(w[21], w[4], w[68], pars->GC_11, pars->GC_12, amp[162]);
    FFV1_0(w[21], w[4], w[69], pars->GC_3, amp[163]);
    FFV2_5_0(w[21], w[4], w[70], pars->GC_29, pars->GC_34, amp[164]);
    FFV2_3_0(w[21], w[2], w[65], pars->GC_11, pars->GC_12, amp[165]);
    FFV1_0(w[21], w[2], w[66], pars->GC_3, amp[166]);
    FFV2_5_0(w[21], w[2], w[67], pars->GC_29, pars->GC_34, amp[167]);
    FFV2_3_0(w[39], w[57], w[54], pars->GC_11, pars->GC_12, amp[168]);
    FFV2_3_0(w[40], w[2], w[54], pars->GC_11, pars->GC_12, amp[169]);
    FFV1_0(w[39], w[57], w[55], pars->GC_3, amp[170]);
    FFV1_0(w[40], w[2], w[55], pars->GC_3, amp[171]);
    FFV2_5_0(w[39], w[57], w[56], pars->GC_29, pars->GC_34, amp[172]);
    FFV2_5_0(w[40], w[2], w[56], pars->GC_29, pars->GC_34, amp[173]);
    FFV2_3_0(w[39], w[64], w[54], pars->GC_11, pars->GC_12, amp[174]);
    FFV2_3_0(w[41], w[2], w[54], pars->GC_11, pars->GC_12, amp[175]);
    FFV1_0(w[39], w[64], w[55], pars->GC_3, amp[176]);
    FFV1_0(w[41], w[2], w[55], pars->GC_3, amp[177]);
    FFV2_5_0(w[39], w[64], w[56], pars->GC_29, pars->GC_34, amp[178]);
    FFV2_5_0(w[41], w[2], w[56], pars->GC_29, pars->GC_34, amp[179]);
    FFV1_0(w[71], w[57], w[6], pars->GC_3, amp[180]);
    FFV1_0(w[29], w[72], w[6], pars->GC_3, amp[181]);
    FFV1_0(w[73], w[57], w[6], pars->GC_3, amp[182]);
    FFV1_0(w[29], w[74], w[6], pars->GC_3, amp[183]);
    FFV1_0(w[75], w[57], w[6], pars->GC_3, amp[184]);
    FFV1_0(w[29], w[76], w[6], pars->GC_3, amp[185]);
    FFV1_0(w[71], w[64], w[6], pars->GC_3, amp[186]);
    FFV1_0(w[38], w[72], w[6], pars->GC_3, amp[187]);
    FFV1_0(w[73], w[64], w[6], pars->GC_3, amp[188]);
    FFV1_0(w[38], w[74], w[6], pars->GC_3, amp[189]);
    FFV1_0(w[75], w[64], w[6], pars->GC_3, amp[190]);
    FFV1_0(w[38], w[76], w[6], pars->GC_3, amp[191]);
    FFV2_3_0(w[5], w[57], w[77], pars->GC_11, pars->GC_12, amp[192]);
    FFV1_0(w[5], w[57], w[78], pars->GC_3, amp[193]);
    FFV2_5_0(w[5], w[57], w[79], pars->GC_29, pars->GC_34, amp[194]);
    FFV2_3_0(w[3], w[57], w[80], pars->GC_11, pars->GC_12, amp[195]);
    FFV1_0(w[3], w[57], w[81], pars->GC_3, amp[196]);
    FFV2_5_0(w[3], w[57], w[82], pars->GC_29, pars->GC_34, amp[197]);
    FFV2_3_0(w[29], w[2], w[80], pars->GC_11, pars->GC_12, amp[198]);
    FFV1_0(w[29], w[2], w[81], pars->GC_3, amp[199]);
    FFV2_5_0(w[29], w[2], w[82], pars->GC_29, pars->GC_34, amp[200]);
    FFV2_3_0(w[11], w[2], w[77], pars->GC_11, pars->GC_12, amp[201]);
    FFV1_0(w[11], w[2], w[78], pars->GC_3, amp[202]);
    FFV2_5_0(w[11], w[2], w[79], pars->GC_29, pars->GC_34, amp[203]);
    FFV2_3_0(w[5], w[64], w[77], pars->GC_11, pars->GC_12, amp[204]);
    FFV1_0(w[5], w[64], w[78], pars->GC_3, amp[205]);
    FFV2_5_0(w[5], w[64], w[79], pars->GC_29, pars->GC_34, amp[206]);
    FFV2_3_0(w[3], w[64], w[80], pars->GC_11, pars->GC_12, amp[207]);
    FFV1_0(w[3], w[64], w[81], pars->GC_3, amp[208]);
    FFV2_5_0(w[3], w[64], w[82], pars->GC_29, pars->GC_34, amp[209]);
    FFV2_3_0(w[38], w[2], w[80], pars->GC_11, pars->GC_12, amp[210]);
    FFV1_0(w[38], w[2], w[81], pars->GC_3, amp[211]);
    FFV2_5_0(w[38], w[2], w[82], pars->GC_29, pars->GC_34, amp[212]);
    FFV2_3_0(w[21], w[2], w[77], pars->GC_11, pars->GC_12, amp[213]);
    FFV1_0(w[21], w[2], w[78], pars->GC_3, amp[214]);
    FFV2_5_0(w[21], w[2], w[79], pars->GC_29, pars->GC_34, amp[215]);
    FFV2_3_0(w[3], w[57], w[83], pars->GC_11, pars->GC_12, amp[216]);
    FFV1_0(w[3], w[57], w[84], pars->GC_3, amp[217]);
    FFV2_5_0(w[3], w[57], w[85], pars->GC_29, pars->GC_34, amp[218]);
    FFV2_3_0(w[29], w[4], w[86], pars->GC_11, pars->GC_12, amp[219]);
    FFV1_0(w[29], w[4], w[87], pars->GC_3, amp[220]);
    FFV2_5_0(w[29], w[4], w[88], pars->GC_29, pars->GC_34, amp[221]);
    FFV2_3_0(w[29], w[2], w[83], pars->GC_11, pars->GC_12, amp[222]);
    FFV1_0(w[29], w[2], w[84], pars->GC_3, amp[223]);
    FFV2_5_0(w[29], w[2], w[85], pars->GC_29, pars->GC_34, amp[224]);
    FFV2_3_0(w[3], w[9], w[86], pars->GC_11, pars->GC_12, amp[225]);
    FFV1_0(w[3], w[9], w[87], pars->GC_3, amp[226]);
    FFV2_5_0(w[3], w[9], w[88], pars->GC_29, pars->GC_34, amp[227]);
    FFV2_3_0(w[3], w[64], w[83], pars->GC_11, pars->GC_12, amp[228]);
    FFV1_0(w[3], w[64], w[84], pars->GC_3, amp[229]);
    FFV2_5_0(w[3], w[64], w[85], pars->GC_29, pars->GC_34, amp[230]);
    FFV2_3_0(w[38], w[4], w[86], pars->GC_11, pars->GC_12, amp[231]);
    FFV1_0(w[38], w[4], w[87], pars->GC_3, amp[232]);
    FFV2_5_0(w[38], w[4], w[88], pars->GC_29, pars->GC_34, amp[233]);
    FFV2_3_0(w[38], w[2], w[83], pars->GC_11, pars->GC_12, amp[234]);
    FFV1_0(w[38], w[2], w[84], pars->GC_3, amp[235]);
    FFV2_5_0(w[38], w[2], w[85], pars->GC_29, pars->GC_34, amp[236]);
    FFV2_3_0(w[3], w[20], w[86], pars->GC_11, pars->GC_12, amp[237]);
    FFV1_0(w[3], w[20], w[87], pars->GC_3, amp[238]);
    FFV2_5_0(w[3], w[20], w[88], pars->GC_29, pars->GC_34, amp[239]);
    FFV1_0(w[5], w[12], w[90], pars->GC_3, amp[240]);
    FFV2_5_0(w[5], w[12], w[91], pars->GC_29, pars->GC_34, amp[241]);
    FFV1_0(w[10], w[4], w[90], pars->GC_3, amp[242]);
    FFV2_5_0(w[10], w[4], w[91], pars->GC_29, pars->GC_34, amp[243]);
    FFV1_0(w[5], w[15], w[90], pars->GC_3, amp[244]);
    FFV2_5_0(w[5], w[15], w[91], pars->GC_29, pars->GC_34, amp[245]);
    FFV1_0(w[14], w[4], w[90], pars->GC_3, amp[246]);
    FFV2_5_0(w[14], w[4], w[91], pars->GC_29, pars->GC_34, amp[247]);
    FFV1_0(w[5], w[18], w[90], pars->GC_3, amp[248]);
    FFV2_5_0(w[5], w[18], w[91], pars->GC_29, pars->GC_34, amp[249]);
    FFV1_0(w[17], w[4], w[90], pars->GC_3, amp[250]);
    FFV2_5_0(w[17], w[4], w[91], pars->GC_29, pars->GC_34, amp[251]);
    FFV1_0(w[92], w[1], w[55], pars->GC_1, amp[252]);
    FFV1_0(w[93], w[1], w[13], pars->GC_1, amp[253]);
    FFV2_4_0(w[92], w[1], w[56], pars->GC_29, pars->GC_33, amp[254]);
    FFV1_0(w[94], w[1], w[13], pars->GC_1, amp[255]);
    FFV1_0(w[95], w[1], w[55], pars->GC_1, amp[256]);
    FFV2_4_0(w[93], w[1], w[16], pars->GC_29, pars->GC_33, amp[257]);
    FFV2_4_0(w[95], w[1], w[56], pars->GC_29, pars->GC_33, amp[258]);
    FFV2_4_0(w[94], w[1], w[16], pars->GC_29, pars->GC_33, amp[259]);
    FFV1_0(w[31], w[4], w[90], pars->GC_3, amp[260]);
    FFV2_5_0(w[31], w[4], w[91], pars->GC_29, pars->GC_34, amp[261]);
    FFV1_0(w[3], w[30], w[90], pars->GC_3, amp[262]);
    FFV2_5_0(w[3], w[30], w[91], pars->GC_29, pars->GC_34, amp[263]);
    FFV1_0(w[34], w[4], w[90], pars->GC_3, amp[264]);
    FFV2_5_0(w[34], w[4], w[91], pars->GC_29, pars->GC_34, amp[265]);
    FFV1_0(w[3], w[33], w[90], pars->GC_3, amp[266]);
    FFV2_5_0(w[3], w[33], w[91], pars->GC_29, pars->GC_34, amp[267]);
    FFV1_0(w[37], w[4], w[90], pars->GC_3, amp[268]);
    FFV2_5_0(w[37], w[4], w[91], pars->GC_29, pars->GC_34, amp[269]);
    FFV1_0(w[3], w[36], w[90], pars->GC_3, amp[270]);
    FFV2_5_0(w[3], w[36], w[91], pars->GC_29, pars->GC_34, amp[271]);
    FFV1_0(w[96], w[1], w[51], pars->GC_1, amp[272]);
    FFV1_0(w[97], w[1], w[32], pars->GC_1, amp[273]);
    FFV2_4_0(w[96], w[1], w[52], pars->GC_29, pars->GC_33, amp[274]);
    FFV1_0(w[98], w[1], w[32], pars->GC_1, amp[275]);
    FFV1_0(w[99], w[1], w[51], pars->GC_1, amp[276]);
    FFV2_4_0(w[97], w[1], w[35], pars->GC_29, pars->GC_33, amp[277]);
    FFV2_4_0(w[99], w[1], w[52], pars->GC_29, pars->GC_33, amp[278]);
    FFV2_4_0(w[98], w[1], w[35], pars->GC_29, pars->GC_33, amp[279]);
    FFV1_0(w[5], w[59], w[90], pars->GC_3, amp[280]);
    FFV2_5_0(w[5], w[59], w[91], pars->GC_29, pars->GC_34, amp[281]);
    FFV1_0(w[58], w[2], w[90], pars->GC_3, amp[282]);
    FFV2_5_0(w[58], w[2], w[91], pars->GC_29, pars->GC_34, amp[283]);
    FFV1_0(w[5], w[61], w[90], pars->GC_3, amp[284]);
    FFV2_5_0(w[5], w[61], w[91], pars->GC_29, pars->GC_34, amp[285]);
    FFV1_0(w[60], w[2], w[90], pars->GC_3, amp[286]);
    FFV2_5_0(w[60], w[2], w[91], pars->GC_29, pars->GC_34, amp[287]);
    FFV1_0(w[5], w[63], w[90], pars->GC_3, amp[288]);
    FFV2_5_0(w[5], w[63], w[91], pars->GC_29, pars->GC_34, amp[289]);
    FFV1_0(w[62], w[2], w[90], pars->GC_3, amp[290]);
    FFV2_5_0(w[62], w[2], w[91], pars->GC_29, pars->GC_34, amp[291]);
    FFV1_0(w[3], w[72], w[90], pars->GC_3, amp[292]);
    FFV2_5_0(w[3], w[72], w[91], pars->GC_29, pars->GC_34, amp[293]);
    FFV1_0(w[71], w[2], w[90], pars->GC_3, amp[294]);
    FFV2_5_0(w[71], w[2], w[91], pars->GC_29, pars->GC_34, amp[295]);
    FFV1_0(w[3], w[74], w[90], pars->GC_3, amp[296]);
    FFV2_5_0(w[3], w[74], w[91], pars->GC_29, pars->GC_34, amp[297]);
    FFV1_0(w[73], w[2], w[90], pars->GC_3, amp[298]);
    FFV2_5_0(w[73], w[2], w[91], pars->GC_29, pars->GC_34, amp[299]);
    FFV1_0(w[3], w[76], w[90], pars->GC_3, amp[300]);
    FFV2_5_0(w[3], w[76], w[91], pars->GC_29, pars->GC_34, amp[301]);
    FFV1_0(w[75], w[2], w[90], pars->GC_3, amp[302]);
    FFV2_5_0(w[75], w[2], w[91], pars->GC_29, pars->GC_34, amp[303]);
    FFV1_0(w[5], w[12], w[101], pars->GC_3, amp[304]);
    FFV2_5_0(w[5], w[12], w[102], pars->GC_29, pars->GC_34, amp[305]);
    FFV1_0(w[10], w[4], w[101], pars->GC_3, amp[306]);
    FFV2_5_0(w[10], w[4], w[102], pars->GC_29, pars->GC_34, amp[307]);
    FFV1_0(w[5], w[15], w[101], pars->GC_3, amp[308]);
    FFV2_5_0(w[5], w[15], w[102], pars->GC_29, pars->GC_34, amp[309]);
    FFV1_0(w[14], w[4], w[101], pars->GC_3, amp[310]);
    FFV2_5_0(w[14], w[4], w[102], pars->GC_29, pars->GC_34, amp[311]);
    FFV1_0(w[5], w[18], w[101], pars->GC_3, amp[312]);
    FFV2_5_0(w[5], w[18], w[102], pars->GC_29, pars->GC_34, amp[313]);
    FFV1_0(w[17], w[4], w[101], pars->GC_3, amp[314]);
    FFV2_5_0(w[17], w[4], w[102], pars->GC_29, pars->GC_34, amp[315]);
    FFV1_0(w[103], w[100], w[55], pars->GC_1, amp[316]);
    FFV1_0(w[104], w[100], w[13], pars->GC_1, amp[317]);
    FFV2_4_0(w[103], w[100], w[56], pars->GC_29, pars->GC_33, amp[318]);
    FFV1_0(w[105], w[100], w[13], pars->GC_1, amp[319]);
    FFV1_0(w[106], w[100], w[55], pars->GC_1, amp[320]);
    FFV2_4_0(w[104], w[100], w[16], pars->GC_29, pars->GC_33, amp[321]);
    FFV2_4_0(w[106], w[100], w[56], pars->GC_29, pars->GC_33, amp[322]);
    FFV2_4_0(w[105], w[100], w[16], pars->GC_29, pars->GC_33, amp[323]);
    FFV1_0(w[31], w[4], w[101], pars->GC_3, amp[324]);
    FFV2_5_0(w[31], w[4], w[102], pars->GC_29, pars->GC_34, amp[325]);
    FFV1_0(w[3], w[30], w[101], pars->GC_3, amp[326]);
    FFV2_5_0(w[3], w[30], w[102], pars->GC_29, pars->GC_34, amp[327]);
    FFV1_0(w[34], w[4], w[101], pars->GC_3, amp[328]);
    FFV2_5_0(w[34], w[4], w[102], pars->GC_29, pars->GC_34, amp[329]);
    FFV1_0(w[3], w[33], w[101], pars->GC_3, amp[330]);
    FFV2_5_0(w[3], w[33], w[102], pars->GC_29, pars->GC_34, amp[331]);
    FFV1_0(w[37], w[4], w[101], pars->GC_3, amp[332]);
    FFV2_5_0(w[37], w[4], w[102], pars->GC_29, pars->GC_34, amp[333]);
    FFV1_0(w[3], w[36], w[101], pars->GC_3, amp[334]);
    FFV2_5_0(w[3], w[36], w[102], pars->GC_29, pars->GC_34, amp[335]);
    FFV1_0(w[107], w[100], w[51], pars->GC_1, amp[336]);
    FFV1_0(w[108], w[100], w[32], pars->GC_1, amp[337]);
    FFV2_4_0(w[107], w[100], w[52], pars->GC_29, pars->GC_33, amp[338]);
    FFV1_0(w[109], w[100], w[32], pars->GC_1, amp[339]);
    FFV1_0(w[110], w[100], w[51], pars->GC_1, amp[340]);
    FFV2_4_0(w[108], w[100], w[35], pars->GC_29, pars->GC_33, amp[341]);
    FFV2_4_0(w[110], w[100], w[52], pars->GC_29, pars->GC_33, amp[342]);
    FFV2_4_0(w[109], w[100], w[35], pars->GC_29, pars->GC_33, amp[343]);
    FFV1_0(w[5], w[59], w[101], pars->GC_3, amp[344]);
    FFV2_5_0(w[5], w[59], w[102], pars->GC_29, pars->GC_34, amp[345]);
    FFV1_0(w[58], w[2], w[101], pars->GC_3, amp[346]);
    FFV2_5_0(w[58], w[2], w[102], pars->GC_29, pars->GC_34, amp[347]);
    FFV1_0(w[5], w[61], w[101], pars->GC_3, amp[348]);
    FFV2_5_0(w[5], w[61], w[102], pars->GC_29, pars->GC_34, amp[349]);
    FFV1_0(w[60], w[2], w[101], pars->GC_3, amp[350]);
    FFV2_5_0(w[60], w[2], w[102], pars->GC_29, pars->GC_34, amp[351]);
    FFV1_0(w[5], w[63], w[101], pars->GC_3, amp[352]);
    FFV2_5_0(w[5], w[63], w[102], pars->GC_29, pars->GC_34, amp[353]);
    FFV1_0(w[62], w[2], w[101], pars->GC_3, amp[354]);
    FFV2_5_0(w[62], w[2], w[102], pars->GC_29, pars->GC_34, amp[355]);
    FFV1_0(w[3], w[72], w[101], pars->GC_3, amp[356]);
    FFV2_5_0(w[3], w[72], w[102], pars->GC_29, pars->GC_34, amp[357]);
    FFV1_0(w[71], w[2], w[101], pars->GC_3, amp[358]);
    FFV2_5_0(w[71], w[2], w[102], pars->GC_29, pars->GC_34, amp[359]);
    FFV1_0(w[3], w[74], w[101], pars->GC_3, amp[360]);
    FFV2_5_0(w[3], w[74], w[102], pars->GC_29, pars->GC_34, amp[361]);
    FFV1_0(w[73], w[2], w[101], pars->GC_3, amp[362]);
    FFV2_5_0(w[73], w[2], w[102], pars->GC_29, pars->GC_34, amp[363]);
    FFV1_0(w[3], w[76], w[101], pars->GC_3, amp[364]);
    FFV2_5_0(w[3], w[76], w[102], pars->GC_29, pars->GC_34, amp[365]);
    FFV1_0(w[75], w[2], w[101], pars->GC_3, amp[366]);
    FFV2_5_0(w[75], w[2], w[102], pars->GC_29, pars->GC_34, amp[367]);
    FFV1_0(w[103], w[111], w[6], pars->GC_1, amp[368]);
    FFV1_0(w[104], w[112], w[6], pars->GC_1, amp[369]);
    FFV1_0(w[103], w[113], w[6], pars->GC_1, amp[370]);
    FFV1_0(w[105], w[112], w[6], pars->GC_1, amp[371]);
    FFV1_0(w[106], w[111], w[6], pars->GC_1, amp[372]);
    FFV1_0(w[104], w[114], w[6], pars->GC_1, amp[373]);
    FFV1_0(w[106], w[113], w[6], pars->GC_1, amp[374]);
    FFV1_0(w[105], w[114], w[6], pars->GC_1, amp[375]);
    FFV1_0(w[103], w[1], w[81], pars->GC_1, amp[376]);
    FFV2_4_0(w[103], w[1], w[82], pars->GC_29, pars->GC_33, amp[377]);
    FFV1_0(w[0], w[112], w[81], pars->GC_1, amp[378]);
    FFV2_4_0(w[0], w[112], w[82], pars->GC_29, pars->GC_33, amp[379]);
    FFV1_0(w[106], w[1], w[81], pars->GC_1, amp[380]);
    FFV2_4_0(w[106], w[1], w[82], pars->GC_29, pars->GC_33, amp[381]);
    FFV1_0(w[0], w[114], w[81], pars->GC_1, amp[382]);
    FFV2_4_0(w[0], w[114], w[82], pars->GC_29, pars->GC_33, amp[383]);
    FFV1_0(w[103], w[1], w[84], pars->GC_1, amp[384]);
    FFV2_4_0(w[103], w[1], w[85], pars->GC_29, pars->GC_33, amp[385]);
    FFV1_0(w[0], w[112], w[84], pars->GC_1, amp[386]);
    FFV2_4_0(w[0], w[112], w[85], pars->GC_29, pars->GC_33, amp[387]);
    FFV1_0(w[106], w[1], w[84], pars->GC_1, amp[388]);
    FFV2_4_0(w[106], w[1], w[85], pars->GC_29, pars->GC_33, amp[389]);
    FFV1_0(w[0], w[114], w[84], pars->GC_1, amp[390]);
    FFV2_4_0(w[0], w[114], w[85], pars->GC_29, pars->GC_33, amp[391]);
    FFV1_0(w[107], w[115], w[6], pars->GC_1, amp[392]);
    FFV1_0(w[108], w[116], w[6], pars->GC_1, amp[393]);
    FFV1_0(w[107], w[117], w[6], pars->GC_1, amp[394]);
    FFV1_0(w[109], w[116], w[6], pars->GC_1, amp[395]);
    FFV1_0(w[110], w[115], w[6], pars->GC_1, amp[396]);
    FFV1_0(w[108], w[118], w[6], pars->GC_1, amp[397]);
    FFV1_0(w[110], w[117], w[6], pars->GC_1, amp[398]);
    FFV1_0(w[109], w[118], w[6], pars->GC_1, amp[399]);
    FFV1_0(w[107], w[1], w[66], pars->GC_1, amp[400]);
    FFV2_4_0(w[107], w[1], w[67], pars->GC_29, pars->GC_33, amp[401]);
    FFV1_0(w[0], w[116], w[66], pars->GC_1, amp[402]);
    FFV2_4_0(w[0], w[116], w[67], pars->GC_29, pars->GC_33, amp[403]);
    FFV1_0(w[110], w[1], w[66], pars->GC_1, amp[404]);
    FFV2_4_0(w[110], w[1], w[67], pars->GC_29, pars->GC_33, amp[405]);
    FFV1_0(w[0], w[118], w[66], pars->GC_1, amp[406]);
    FFV2_4_0(w[0], w[118], w[67], pars->GC_29, pars->GC_33, amp[407]);
    FFV1_0(w[107], w[1], w[78], pars->GC_1, amp[408]);
    FFV2_4_0(w[107], w[1], w[79], pars->GC_29, pars->GC_33, amp[409]);
    FFV1_0(w[0], w[116], w[78], pars->GC_1, amp[410]);
    FFV2_4_0(w[0], w[116], w[79], pars->GC_29, pars->GC_33, amp[411]);
    FFV1_0(w[110], w[1], w[78], pars->GC_1, amp[412]);
    FFV2_4_0(w[110], w[1], w[79], pars->GC_29, pars->GC_33, amp[413]);
    FFV1_0(w[0], w[118], w[78], pars->GC_1, amp[414]);
    FFV2_4_0(w[0], w[118], w[79], pars->GC_29, pars->GC_33, amp[415]);
    FFV1_0(w[108], w[1], w[44], pars->GC_1, amp[416]);
    FFV2_4_0(w[108], w[1], w[45], pars->GC_29, pars->GC_33, amp[417]);
    FFV1_0(w[0], w[115], w[44], pars->GC_1, amp[418]);
    FFV2_4_0(w[0], w[115], w[45], pars->GC_29, pars->GC_33, amp[419]);
    FFV1_0(w[109], w[1], w[44], pars->GC_1, amp[420]);
    FFV2_4_0(w[109], w[1], w[45], pars->GC_29, pars->GC_33, amp[421]);
    FFV1_0(w[0], w[117], w[44], pars->GC_1, amp[422]);
    FFV2_4_0(w[0], w[117], w[45], pars->GC_29, pars->GC_33, amp[423]);
    FFV1_0(w[104], w[1], w[47], pars->GC_1, amp[424]);
    FFV2_4_0(w[104], w[1], w[48], pars->GC_29, pars->GC_33, amp[425]);
    FFV1_0(w[0], w[111], w[47], pars->GC_1, amp[426]);
    FFV2_4_0(w[0], w[111], w[48], pars->GC_29, pars->GC_33, amp[427]);
    FFV1_0(w[105], w[1], w[47], pars->GC_1, amp[428]);
    FFV2_4_0(w[105], w[1], w[48], pars->GC_29, pars->GC_33, amp[429]);
    FFV1_0(w[0], w[113], w[47], pars->GC_1, amp[430]);
    FFV2_4_0(w[0], w[113], w[48], pars->GC_29, pars->GC_33, amp[431]);
    FFV1_0(w[108], w[1], w[87], pars->GC_1, amp[432]);
    FFV2_4_0(w[108], w[1], w[88], pars->GC_29, pars->GC_33, amp[433]);
    FFV1_0(w[0], w[115], w[87], pars->GC_1, amp[434]);
    FFV2_4_0(w[0], w[115], w[88], pars->GC_29, pars->GC_33, amp[435]);
    FFV1_0(w[109], w[1], w[87], pars->GC_1, amp[436]);
    FFV2_4_0(w[109], w[1], w[88], pars->GC_29, pars->GC_33, amp[437]);
    FFV1_0(w[0], w[117], w[87], pars->GC_1, amp[438]);
    FFV2_4_0(w[0], w[117], w[88], pars->GC_29, pars->GC_33, amp[439]);
    FFV1_0(w[104], w[1], w[69], pars->GC_1, amp[440]);
    FFV2_4_0(w[104], w[1], w[70], pars->GC_29, pars->GC_33, amp[441]);
    FFV1_0(w[0], w[111], w[69], pars->GC_1, amp[442]);
    FFV2_4_0(w[0], w[111], w[70], pars->GC_29, pars->GC_33, amp[443]);
    FFV1_0(w[105], w[1], w[69], pars->GC_1, amp[444]);
    FFV2_4_0(w[105], w[1], w[70], pars->GC_29, pars->GC_33, amp[445]);
    FFV1_0(w[0], w[113], w[69], pars->GC_1, amp[446]);
    FFV2_4_0(w[0], w[113], w[70], pars->GC_29, pars->GC_33, amp[447]);
}
double qq_z_zp_DN_SFpA::matrix_4_ssx_mummupmummupa_no_h()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 448;
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
        amp[29] + amp[30] + amp[31] + amp[32] + amp[33] + amp[34] + amp[35] -
        amp[36] - amp[37] - amp[38] - amp[39] - amp[40] - amp[41] - amp[42] -
        amp[43] - amp[44] - amp[45] - amp[46] - amp[47] - amp[48] - amp[49] -
        amp[50] - amp[51] - amp[52] - amp[53] - amp[54] - amp[55] - amp[56] -
        amp[57] - amp[58] - amp[59] - amp[60] - amp[61] - amp[62] - amp[63] -
        amp[64] - amp[65] - amp[66] - amp[67] - amp[68] - amp[69] - amp[70] -
        amp[71] - amp[72] - amp[73] - amp[74] + amp[75] + amp[76] + amp[77] -
        amp[78] - amp[79] - amp[80] + amp[81] + amp[82] + amp[83] - amp[84] -
        amp[85] - amp[86] + amp[87] + amp[88] + amp[89] - amp[90] - amp[91] -
        amp[92] + amp[93] + amp[94] + amp[95] - amp[96] - amp[97] - amp[98] -
        amp[99] - amp[100] - amp[101] - amp[102] - amp[103] - amp[104] -
        amp[105] - amp[106] - amp[107] + amp[108] + amp[109] + amp[110] +
        amp[111] + amp[112] + amp[113] + amp[114] + amp[115] + amp[116] +
        amp[117] + amp[118] + amp[119] - amp[120] - amp[121] - amp[122] -
        amp[123] - amp[124] - amp[125] - amp[126] - amp[127] - amp[128] -
        amp[129] - amp[130] - amp[131] - amp[132] - amp[133] - amp[134] -
        amp[135] - amp[136] - amp[137] - amp[138] - amp[139] - amp[140] -
        amp[141] - amp[142] - amp[143] - amp[144] - amp[145] - amp[146] +
        amp[147] + amp[148] + amp[149] + amp[150] + amp[151] + amp[152] -
        amp[153] - amp[154] - amp[155] - amp[156] - amp[157] - amp[158] +
        amp[159] + amp[160] + amp[161] + amp[162] + amp[163] + amp[164] -
        amp[165] - amp[166] - amp[167] + amp[168] + amp[169] + amp[170] +
        amp[171] + amp[172] + amp[173] + amp[174] + amp[175] + amp[176] +
        amp[177] + amp[178] + amp[179] + amp[180] + amp[181] + amp[182] +
        amp[183] + amp[184] + amp[185] + amp[186] + amp[187] + amp[188] +
        amp[189] + amp[190] + amp[191] - amp[192] - amp[193] - amp[194] +
        amp[195] + amp[196] + amp[197] + amp[198] + amp[199] + amp[200] -
        amp[201] - amp[202] - amp[203] - amp[204] - amp[205] - amp[206] +
        amp[207] + amp[208] + amp[209] + amp[210] + amp[211] + amp[212] -
        amp[213] - amp[214] - amp[215] + amp[216] + amp[217] + amp[218] -
        amp[219] - amp[220] - amp[221] + amp[222] + amp[223] + amp[224] -
        amp[225] - amp[226] - amp[227] + amp[228] + amp[229] + amp[230] -
        amp[231] - amp[232] - amp[233] + amp[234] + amp[235] + amp[236] -
        amp[237] - amp[238] - amp[239] + amp[240] + amp[241] + amp[242] +
        amp[243] + amp[244] + amp[245] + amp[246] + amp[247] + amp[248] +
        amp[249] + amp[250] + amp[251] + amp[252] + amp[253] + amp[254] +
        amp[255] + amp[256] + amp[257] + amp[258] + amp[259] - amp[260] -
        amp[261] - amp[262] - amp[263] - amp[264] - amp[265] - amp[266] -
        amp[267] - amp[268] - amp[269] - amp[270] - amp[271] - amp[272] -
        amp[273] - amp[274] - amp[275] - amp[276] - amp[277] - amp[278] -
        amp[279] - amp[280] - amp[281] - amp[282] - amp[283] - amp[284] -
        amp[285] - amp[286] - amp[287] - amp[288] - amp[289] - amp[290] -
        amp[291] + amp[292] + amp[293] + amp[294] + amp[295] + amp[296] +
        amp[297] + amp[298] + amp[299] + amp[300] + amp[301] + amp[302] +
        amp[303] + amp[304] + amp[305] + amp[306] + amp[307] + amp[308] +
        amp[309] + amp[310] + amp[311] + amp[312] + amp[313] + amp[314] +
        amp[315] + amp[316] + amp[317] + amp[318] + amp[319] + amp[320] +
        amp[321] + amp[322] + amp[323] - amp[324] - amp[325] - amp[326] -
        amp[327] - amp[328] - amp[329] - amp[330] - amp[331] - amp[332] -
        amp[333] - amp[334] - amp[335] - amp[336] - amp[337] - amp[338] -
        amp[339] - amp[340] - amp[341] - amp[342] - amp[343] - amp[344] -
        amp[345] - amp[346] - amp[347] - amp[348] - amp[349] - amp[350] -
        amp[351] - amp[352] - amp[353] - amp[354] - amp[355] + amp[356] +
        amp[357] + amp[358] + amp[359] + amp[360] + amp[361] + amp[362] +
        amp[363] + amp[364] + amp[365] + amp[366] + amp[367] + amp[368] +
        amp[369] + amp[370] + amp[371] + amp[372] + amp[373] + amp[374] +
        amp[375] + amp[376] + amp[377] + amp[378] + amp[379] + amp[380] +
        amp[381] + amp[382] + amp[383] + amp[384] + amp[385] + amp[386] +
        amp[387] + amp[388] + amp[389] + amp[390] + amp[391] - amp[392] -
        amp[393] - amp[394] - amp[395] - amp[396] - amp[397] - amp[398] -
        amp[399] - amp[400] - amp[401] - amp[402] - amp[403] - amp[404] -
        amp[405] - amp[406] - amp[407] - amp[408] - amp[409] - amp[410] -
        amp[411] - amp[412] - amp[413] - amp[414] - amp[415] - amp[416] -
        amp[417] - amp[418] - amp[419] - amp[420] - amp[421] - amp[422] -
        amp[423] + amp[424] + amp[425] + amp[426] + amp[427] + amp[428] +
        amp[429] + amp[430] + amp[431] - amp[432] - amp[433] - amp[434] -
        amp[435] - amp[436] - amp[437] - amp[438] - amp[439] + amp[440] +
        amp[441] + amp[442] + amp[443] + amp[444] + amp[445] + amp[446] +
        amp[447];

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
