//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 1.5.7, 2013-01-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "gg_Spin0_OFpA.h"
#include "HelAmps_HEF_MEKD.h"

using namespace MG5_HEF_MEKD;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > h > e- e+ mu- mu+ a / zp xg WEIGHTED=10

//--------------------------------------------------------------------------
// Initialize process.

void gg_Spin0_OFpA::initProc(string param_card_name)
{
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_MEKD::getInstance();
    SLHAReader_MEKD slha(param_card_name);
    pars->setIndependentParameters(slha);
    pars->setIndependentCouplings();
    ntry = 0, sum_hel = 0, ngood = 0; // moved here by Ghost remover v. 0.1
    // Set external particle masses for this matrix element
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

void gg_Spin0_OFpA::initProc()
{
    // Instantiate the model class and set parameters that stay fixed during run
    pars = Parameters_MEKD::getInstance();
    ntry = 0, sum_hel = 0, ngood = 0; // moved here by Ghost remover v. 0.1
    // Set external particle masses for this matrix element
    mME.push_back(pars->ZERO);
    mME.push_back(pars->ZERO);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_Me);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->mdl_MM);
    mME.push_back(pars->ZERO);
    jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.

void gg_Spin0_OFpA::updateProc()
{
    ntry = 0, sum_hel = 0, ngood = 0; // moved here by Ghost remover v. 0.1

    // Set external particle masses for this matrix element
    mME[0] = (pars->ZERO);
    mME[1] = (pars->ZERO);
    mME[2] = (pars->mdl_Me);
    mME[3] = (pars->mdl_Me);
    mME[4] = (pars->mdl_MM);
    mME[5] = (pars->mdl_MM);
    mME[6] = (pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void gg_Spin0_OFpA::sigmaKin()
{
    // Set the parameters which change event by event
    pars->setDependentParameters();
    pars->setDependentCouplings();

    // Reset color flows
    for (int i = 0; i < 1; i++)
        jamp2[0][i] = 0.;

    // Local variables and constants
    const int ncomb = 128;
    static bool goodhel[ncomb] = {ncomb * false};
    // static int ntry = 0, sum_hel = 0, ngood = 0;	// picked out by Ghost
    // remover v. 0.1
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
                t[0] = matrix_gg_h_emepmummupa_no_zpxg();

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
            t[0] = matrix_gg_h_emepmummupa_no_zpxg();

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

double gg_Spin0_OFpA::sigmaHat()
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

void gg_Spin0_OFpA::calculate_wavefunctions(const int perm[], const int hel[])
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
    vxxxxx(p[perm[6]], mME[6], hel[6], +1, w[6]);
    VVS3_4_5_3(w[0], w[1], pars->HEF_MEKD_GC_13, pars->HEF_MEKD_GC_15,
               pars->HEF_MEKD_GC_19, pars->mdl_MH, pars->mdl_WH, w[7]);
    FFV5_7_3(w[3], w[2], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             pars->mdl_MZ, pars->mdl_WZ, w[8]);
    FFV2_1(w[4], w[6], pars->HEF_MEKD_GC_5, pars->mdl_MM, pars->ZERO, w[9]);
    VVS3_4_5_1(w[8], w[7], pars->HEF_MEKD_GC_14, pars->HEF_MEKD_GC_18,
               pars->HEF_MEKD_GC_22, pars->mdl_MZ, pars->mdl_WZ, w[10]);
    VVS2_1(w[8], w[7], pars->HEF_MEKD_GC_25, pars->mdl_MZ, pars->mdl_WZ, w[11]);
    VVS1_3(w[0], w[1], pars->HEF_MEKD_GC_23, pars->mdl_MH, pars->mdl_WH, w[12]);
    VVS3_4_5_1(w[8], w[12], pars->HEF_MEKD_GC_14, pars->HEF_MEKD_GC_18,
               pars->HEF_MEKD_GC_22, pars->mdl_MZ, pars->mdl_WZ, w[13]);
    VVS2_1(w[8], w[12], pars->HEF_MEKD_GC_25, pars->mdl_MZ, pars->mdl_WZ,
           w[14]);
    FFV2_2(w[5], w[6], pars->HEF_MEKD_GC_5, pars->mdl_MM, pars->ZERO, w[15]);
    FFV2_1(w[2], w[6], pars->HEF_MEKD_GC_5, pars->mdl_Me, pars->ZERO, w[16]);
    FFV5_7_3(w[5], w[4], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             pars->mdl_MZ, pars->mdl_WZ, w[17]);
    VVS3_4_5_1(w[17], w[7], pars->HEF_MEKD_GC_14, pars->HEF_MEKD_GC_18,
               pars->HEF_MEKD_GC_22, pars->mdl_MZ, pars->mdl_WZ, w[18]);
    VVS2_1(w[17], w[7], pars->HEF_MEKD_GC_25, pars->mdl_MZ, pars->mdl_WZ,
           w[19]);
    VVS3_4_5_1(w[17], w[12], pars->HEF_MEKD_GC_14, pars->HEF_MEKD_GC_18,
               pars->HEF_MEKD_GC_22, pars->mdl_MZ, pars->mdl_WZ, w[20]);
    VVS2_1(w[17], w[12], pars->HEF_MEKD_GC_25, pars->mdl_MZ, pars->mdl_WZ,
           w[21]);
    FFV2_2(w[3], w[6], pars->HEF_MEKD_GC_5, pars->mdl_Me, pars->ZERO, w[22]);

    // Calculate all amplitudes
    // Amplitude(s) for diagram number 0
    FFV5_7_0(w[5], w[9], w[10], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[0]);
    FFV5_7_0(w[5], w[9], w[11], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[1]);
    FFV5_7_0(w[5], w[9], w[13], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[2]);
    FFV5_7_0(w[5], w[9], w[14], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[3]);
    FFV5_7_0(w[15], w[4], w[10], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[4]);
    FFV5_7_0(w[15], w[4], w[11], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[5]);
    FFV5_7_0(w[15], w[4], w[13], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[6]);
    FFV5_7_0(w[15], w[4], w[14], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[7]);
    FFV5_7_0(w[3], w[16], w[18], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[8]);
    FFV5_7_0(w[3], w[16], w[19], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[9]);
    FFV5_7_0(w[3], w[16], w[20], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[10]);
    FFV5_7_0(w[3], w[16], w[21], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[11]);
    FFV5_7_0(w[22], w[2], w[18], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[12]);
    FFV5_7_0(w[22], w[2], w[19], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[13]);
    FFV5_7_0(w[22], w[2], w[20], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[14]);
    FFV5_7_0(w[22], w[2], w[21], pars->HEF_MEKD_GC_161, pars->HEF_MEKD_GC_168,
             amp[15]);
}
double gg_Spin0_OFpA::matrix_gg_h_emepmummupa_no_zpxg()
{
    int i, j;
    // Local variables
    //   const int ngraphs = 16;
    const int ncolor = 1;
    std::complex<double> ztemp;
    std::complex<double> jamp[ncolor];
    // The color matrix;
    static const double denom[ncolor] = {1};
    static const double cf[ncolor][ncolor] = {{2}};

    // Calculate color flows
    jamp[0] = +2. * (+amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] +
                     amp[6] + amp[7] + amp[8] + amp[9] + amp[10] + amp[11] +
                     amp[12] + amp[13] + amp[14] + amp[15]);

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
