//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.6.4, 2018-11-09
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "qq_z_zp_UP_OF.h"
#include "HelAmps_Leptophilic_UFO.h"

namespace MG5_Leptophilic_UFO
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: c c~ > e- e+ mu- mu+ WEIGHTED<=8 / h @1

//--------------------------------------------------------------------------
// Initialize process.

void qq_z_zp_UP_OF::initProc(string param_card_name)
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
    mME.push_back(pars->mdl_MC);
    mME.push_back(pars->mdl_MC);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    jamp2[0] = new double[1];
}

void qq_z_zp_UP_OF::initProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_Leptophilic_UFO::getInstance();
    // Set external particle masses for this matrix element
    mME.push_back(pars->mdl_MC);
    mME.push_back(pars->mdl_MC);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MMU);
    mME.push_back(pars->mdl_MMU);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.

void qq_z_zp_UP_OF::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0;
    // Set external particle masses for this matrix element
    mME[0] = (pars->mdl_MC);
    mME[1] = (pars->mdl_MC);
    mME[2] = (pars->mdl_Me);
    mME[3] = (pars->mdl_Me);
    mME[4] = (pars->mdl_MMU);
    mME[5] = (pars->mdl_MMU);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_z_zp_UP_OF::sigmaKin()
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
                t[0] = matrix_1_ccx_emepmummup_no_h();
                // Mirror initial state momenta for mirror process
                perm[0] = 1;
                perm[1] = 0;
                // Calculate wavefunctions
                calculate_wavefunctions(perm, helicities[ihel]);
                // Mirror back
                perm[0] = 0;
                perm[1] = 1;
                // Calculate matrix elements
                t[1] = matrix_1_ccx_emepmummup_no_h();
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
            t[0] = matrix_1_ccx_emepmummup_no_h();
            // Mirror initial state momenta for mirror process
            perm[0] = 1;
            perm[1] = 0;
            // Calculate wavefunctions
            calculate_wavefunctions(perm, helicities[ihel]);
            // Mirror back
            perm[0] = 0;
            perm[1] = 1;
            // Calculate matrix elements
            t[1] = matrix_1_ccx_emepmummup_no_h();
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

double qq_z_zp_UP_OF::sigmaHat()
{
    // Select between the different processes
    if (id1 == -4 && id2 == 4) {
        // Add matrix elements for processes with beams (-4, 4)
        return matrix_element[1];
    } else if (id1 == 4 && id2 == -4) {
        // Add matrix elements for processes with beams (4, -4)
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

void qq_z_zp_UP_OF::calculate_wavefunctions(const int perm[], const int hel[])
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
    FFV1P0_3(w[0], w[1], pars->GC_2, pars->ZERO, pars->ZERO, w[6]);
    FFV2_3_3(w[3], w[2], pars->GC_9, pars->GC_10, pars->mdl_ZpM, pars->mdl_ZpW,
             w[7]);
    FFV1_1(w[4], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[8]);
    FFV1_2(w[5], w[6], pars->GC_3, pars->mdl_MMU, pars->ZERO, w[9]);
    FFV1P0_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[10]);
    FFV2_5_3(w[3], w[2], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[11]);
    FFV2_6_3(w[0], w[1], pars->GC_30, pars->GC_33, pars->mdl_MZ, pars->mdl_WZ,
             w[12]);
    FFV2_5_1(w[4], w[12], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[13]);
    FFV2_5_2(w[5], w[12], pars->GC_29, pars->GC_34, pars->mdl_MMU, pars->ZERO,
             w[14]);
    FFV2_3_3(w[5], w[4], pars->GC_11, pars->GC_12, pars->mdl_ZpM, pars->mdl_ZpW,
             w[15]);
    FFV1_1(w[2], w[6], pars->GC_3, pars->mdl_Me, pars->ZERO, w[16]);
    FFV1_2(w[3], w[6], pars->GC_3, pars->mdl_Me, pars->ZERO, w[17]);
    FFV1P0_3(w[5], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[18]);
    FFV2_5_3(w[5], w[4], pars->GC_29, pars->GC_34, pars->mdl_MZ, pars->mdl_WZ,
             w[19]);
    FFV2_5_1(w[2], w[12], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[20]);
    FFV2_5_2(w[3], w[12], pars->GC_29, pars->GC_34, pars->mdl_Me, pars->ZERO,
             w[21]);
    FFV1_2(w[0], w[10], pars->GC_2, pars->mdl_MC, pars->ZERO, w[22]);
    FFV1_2(w[0], w[18], pars->GC_2, pars->mdl_MC, pars->ZERO, w[23]);
    FFV2_6_2(w[0], w[19], pars->GC_30, pars->GC_33, pars->mdl_MC, pars->ZERO,
             w[24]);
    FFV2_6_2(w[0], w[11], pars->GC_30, pars->GC_33, pars->mdl_MC, pars->ZERO,
             w[25]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV2_3_0(w[5], w[8], w[7], pars->GC_11, pars->GC_12, amp[0]);
    FFV2_3_0(w[9], w[4], w[7], pars->GC_11, pars->GC_12, amp[1]);
    FFV1_0(w[5], w[8], w[10], pars->GC_3, amp[2]);
    FFV1_0(w[9], w[4], w[10], pars->GC_3, amp[3]);
    FFV2_5_0(w[5], w[8], w[11], pars->GC_29, pars->GC_34, amp[4]);
    FFV2_5_0(w[9], w[4], w[11], pars->GC_29, pars->GC_34, amp[5]);
    FFV2_3_0(w[5], w[13], w[7], pars->GC_11, pars->GC_12, amp[6]);
    FFV2_3_0(w[14], w[4], w[7], pars->GC_11, pars->GC_12, amp[7]);
    FFV1_0(w[5], w[13], w[10], pars->GC_3, amp[8]);
    FFV1_0(w[14], w[4], w[10], pars->GC_3, amp[9]);
    FFV2_5_0(w[5], w[13], w[11], pars->GC_29, pars->GC_34, amp[10]);
    FFV2_5_0(w[14], w[4], w[11], pars->GC_29, pars->GC_34, amp[11]);
    FFV2_3_0(w[3], w[16], w[15], pars->GC_9, pars->GC_10, amp[12]);
    FFV2_3_0(w[17], w[2], w[15], pars->GC_9, pars->GC_10, amp[13]);
    FFV1_0(w[3], w[16], w[18], pars->GC_3, amp[14]);
    FFV1_0(w[17], w[2], w[18], pars->GC_3, amp[15]);
    FFV2_5_0(w[3], w[16], w[19], pars->GC_29, pars->GC_34, amp[16]);
    FFV2_5_0(w[17], w[2], w[19], pars->GC_29, pars->GC_34, amp[17]);
    FFV2_3_0(w[3], w[20], w[15], pars->GC_9, pars->GC_10, amp[18]);
    FFV2_3_0(w[21], w[2], w[15], pars->GC_9, pars->GC_10, amp[19]);
    FFV1_0(w[3], w[20], w[18], pars->GC_3, amp[20]);
    FFV1_0(w[21], w[2], w[18], pars->GC_3, amp[21]);
    FFV2_5_0(w[3], w[20], w[19], pars->GC_29, pars->GC_34, amp[22]);
    FFV2_5_0(w[21], w[2], w[19], pars->GC_29, pars->GC_34, amp[23]);
    FFV1_0(w[22], w[1], w[18], pars->GC_2, amp[24]);
    FFV1_0(w[23], w[1], w[10], pars->GC_2, amp[25]);
    FFV2_6_0(w[22], w[1], w[19], pars->GC_30, pars->GC_33, amp[26]);
    FFV1_0(w[24], w[1], w[10], pars->GC_2, amp[27]);
    FFV1_0(w[25], w[1], w[18], pars->GC_2, amp[28]);
    FFV2_6_0(w[23], w[1], w[11], pars->GC_30, pars->GC_33, amp[29]);
    FFV2_6_0(w[25], w[1], w[19], pars->GC_30, pars->GC_33, amp[30]);
    FFV2_6_0(w[24], w[1], w[11], pars->GC_30, pars->GC_33, amp[31]);
}
double qq_z_zp_UP_OF::matrix_1_ccx_emepmummup_no_h()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 32;
    const int ncolor = 1;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1};
    static const double cf[ncolor][ncolor] = {{3}};

    // Calculate color flows
    jamp[0] = +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] + amp[6] +
              amp[7] + amp[8] + amp[9] + amp[10] + amp[11] + amp[12] + amp[13] +
              amp[14] + amp[15] + amp[16] + amp[17] + amp[18] + amp[19] +
              amp[20] + amp[21] + amp[22] + amp[23] + amp[24] + amp[25] +
              amp[26] + amp[27] + amp[28] + amp[29] + amp[30] + amp[31];

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
