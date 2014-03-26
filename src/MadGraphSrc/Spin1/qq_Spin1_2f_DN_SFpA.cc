//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "qq_Spin1_2f_DN_SFpA.h"
#include "../HelAmps_HEF_MEKD2_1.h"	// Changed by Convert_source 0.2

using namespace MG5_HEF_MEKD2_1;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: s s~ > zp > mu- mu+ mu- mu+ a S1VV=1 QED=3 S1QQ=2 / h xg

//--------------------------------------------------------------------------
// Initialize process.

void qq_Spin1_2f_DN_SFpA::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_MEKD::getInstance();	// Changed by Convert_source 0.2 
  SLHAReader_MEKD slha(param_card_name);
  pars->setIndependentParameters(slha);
  pars->setIndependentCouplings();
	ntry = 0, sum_hel = 0, ngood = 0;	// Moved here by Convert_source 0.2
  // Set external particle masses for this matrix element
  mME.push_back(pars->MS);
  mME.push_back(pars->MS);
  mME.push_back(pars->MM);
  mME.push_back(pars->MM);
  mME.push_back(pars->MM);
  mME.push_back(pars->MM);
  mME.push_back(pars->ZERO);
  jamp2[0] = new double[1];
}

//--------------------------------------------------------------------------
// Update process.	// Created here by Convert_source 0.2

void qq_Spin1_2f_DN_SFpA::updateProc(SLHAReader_MEKD &slha)
{
	pars->setIndependentParameters(slha);
	pars->setIndependentCouplings();
	ntry = 0, sum_hel = 0, ngood = 0;	// needed when altering couplings
	
	// Set external particle masses for this matrix element
	// Should correspond to initProc
	mME[0]=(pars->MS);
	mME[1]=(pars->MS);
	mME[2]=(pars->MM);
	mME[3]=(pars->MM);
	mME[4]=(pars->MM);
	mME[5]=(pars->MM);
	mME[6]=(pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_Spin1_2f_DN_SFpA::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters();
  pars->setDependentCouplings();
	// Deleted by Convert_source 0.2
	
  // Reset color flows
  for(int i = 0;i < 1;i++ )
    jamp2[0][i] = 0.;

  // Local variables and constants
  const int ncomb = 128;
  static bool goodhel[ncomb] = {ncomb * false};
//	static int ntry = 0, sum_hel = 0, ngood = 0;	// Moved by Convert_source 0.2
  static int igood[ncomb];
  static int jhel;
//	std::complex<double> * * wfs;	// Changed by Convert_source 0.2
  double t[nprocesses];
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1,
      -1}, {-1, -1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, -1, 1, -1}, {-1, -1,
      -1, -1, -1, 1, 1}, {-1, -1, -1, -1, 1, -1, -1}, {-1, -1, -1, -1, 1, -1,
      1}, {-1, -1, -1, -1, 1, 1, -1}, {-1, -1, -1, -1, 1, 1, 1}, {-1, -1, -1,
      1, -1, -1, -1}, {-1, -1, -1, 1, -1, -1, 1}, {-1, -1, -1, 1, -1, 1, -1},
      {-1, -1, -1, 1, -1, 1, 1}, {-1, -1, -1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1,
      -1, 1}, {-1, -1, -1, 1, 1, 1, -1}, {-1, -1, -1, 1, 1, 1, 1}, {-1, -1, 1,
      -1, -1, -1, -1}, {-1, -1, 1, -1, -1, -1, 1}, {-1, -1, 1, -1, -1, 1, -1},
      {-1, -1, 1, -1, -1, 1, 1}, {-1, -1, 1, -1, 1, -1, -1}, {-1, -1, 1, -1, 1,
      -1, 1}, {-1, -1, 1, -1, 1, 1, -1}, {-1, -1, 1, -1, 1, 1, 1}, {-1, -1, 1,
      1, -1, -1, -1}, {-1, -1, 1, 1, -1, -1, 1}, {-1, -1, 1, 1, -1, 1, -1},
      {-1, -1, 1, 1, -1, 1, 1}, {-1, -1, 1, 1, 1, -1, -1}, {-1, -1, 1, 1, 1,
      -1, 1}, {-1, -1, 1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1, 1}, {-1, 1, -1,
      -1, -1, -1, -1}, {-1, 1, -1, -1, -1, -1, 1}, {-1, 1, -1, -1, -1, 1, -1},
      {-1, 1, -1, -1, -1, 1, 1}, {-1, 1, -1, -1, 1, -1, -1}, {-1, 1, -1, -1, 1,
      -1, 1}, {-1, 1, -1, -1, 1, 1, -1}, {-1, 1, -1, -1, 1, 1, 1}, {-1, 1, -1,
      1, -1, -1, -1}, {-1, 1, -1, 1, -1, -1, 1}, {-1, 1, -1, 1, -1, 1, -1},
      {-1, 1, -1, 1, -1, 1, 1}, {-1, 1, -1, 1, 1, -1, -1}, {-1, 1, -1, 1, 1,
      -1, 1}, {-1, 1, -1, 1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1, 1}, {-1, 1, 1, -1,
      -1, -1, -1}, {-1, 1, 1, -1, -1, -1, 1}, {-1, 1, 1, -1, -1, 1, -1}, {-1,
      1, 1, -1, -1, 1, 1}, {-1, 1, 1, -1, 1, -1, -1}, {-1, 1, 1, -1, 1, -1, 1},
      {-1, 1, 1, -1, 1, 1, -1}, {-1, 1, 1, -1, 1, 1, 1}, {-1, 1, 1, 1, -1, -1,
      -1}, {-1, 1, 1, 1, -1, -1, 1}, {-1, 1, 1, 1, -1, 1, -1}, {-1, 1, 1, 1,
      -1, 1, 1}, {-1, 1, 1, 1, 1, -1, -1}, {-1, 1, 1, 1, 1, -1, 1}, {-1, 1, 1,
      1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1, -1}, {1,
      -1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, -1,
      1, 1}, {1, -1, -1, -1, 1, -1, -1}, {1, -1, -1, -1, 1, -1, 1}, {1, -1, -1,
      -1, 1, 1, -1}, {1, -1, -1, -1, 1, 1, 1}, {1, -1, -1, 1, -1, -1, -1}, {1,
      -1, -1, 1, -1, -1, 1}, {1, -1, -1, 1, -1, 1, -1}, {1, -1, -1, 1, -1, 1,
      1}, {1, -1, -1, 1, 1, -1, -1}, {1, -1, -1, 1, 1, -1, 1}, {1, -1, -1, 1,
      1, 1, -1}, {1, -1, -1, 1, 1, 1, 1}, {1, -1, 1, -1, -1, -1, -1}, {1, -1,
      1, -1, -1, -1, 1}, {1, -1, 1, -1, -1, 1, -1}, {1, -1, 1, -1, -1, 1, 1},
      {1, -1, 1, -1, 1, -1, -1}, {1, -1, 1, -1, 1, -1, 1}, {1, -1, 1, -1, 1, 1,
      -1}, {1, -1, 1, -1, 1, 1, 1}, {1, -1, 1, 1, -1, -1, -1}, {1, -1, 1, 1,
      -1, -1, 1}, {1, -1, 1, 1, -1, 1, -1}, {1, -1, 1, 1, -1, 1, 1}, {1, -1, 1,
      1, 1, -1, -1}, {1, -1, 1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, 1, -1}, {1, -1,
      1, 1, 1, 1, 1}, {1, 1, -1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, -1, 1},
      {1, 1, -1, -1, -1, 1, -1}, {1, 1, -1, -1, -1, 1, 1}, {1, 1, -1, -1, 1,
      -1, -1}, {1, 1, -1, -1, 1, -1, 1}, {1, 1, -1, -1, 1, 1, -1}, {1, 1, -1,
      -1, 1, 1, 1}, {1, 1, -1, 1, -1, -1, -1}, {1, 1, -1, 1, -1, -1, 1}, {1, 1,
      -1, 1, -1, 1, -1}, {1, 1, -1, 1, -1, 1, 1}, {1, 1, -1, 1, 1, -1, -1}, {1,
      1, -1, 1, 1, -1, 1}, {1, 1, -1, 1, 1, 1, -1}, {1, 1, -1, 1, 1, 1, 1}, {1,
      1, 1, -1, -1, -1, -1}, {1, 1, 1, -1, -1, -1, 1}, {1, 1, 1, -1, -1, 1,
      -1}, {1, 1, 1, -1, -1, 1, 1}, {1, 1, 1, -1, 1, -1, -1}, {1, 1, 1, -1, 1,
      -1, 1}, {1, 1, 1, -1, 1, 1, -1}, {1, 1, 1, -1, 1, 1, 1}, {1, 1, 1, 1, -1,
      -1, -1}, {1, 1, 1, 1, -1, -1, 1}, {1, 1, 1, 1, -1, 1, -1}, {1, 1, 1, 1,
      -1, 1, 1}, {1, 1, 1, 1, 1, -1, -1}, {1, 1, 1, 1, 1, -1, 1}, {1, 1, 1, 1,
      1, 1, -1}, {1, 1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {144, 144};

  ntry = ntry + 1;

  // Reset the matrix elements
  for(int i = 0;i < nprocesses;i++ )
  {
    matrix_element[i] = 0.;
  }
  // Define permutation
  int perm[nexternal];
  for(int i = 0;i < nexternal;i++ )
  {
    perm[i] = i;
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0;ihel < ncomb;ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]);
        t[0] = matrix_ssx_zp_mummupmummupa_no_hxg();
        // Mirror initial state momenta for mirror process
        perm[0] = 1;
        perm[1] = 0;
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]);
        // Mirror back
        perm[0] = 0;
        perm[1] = 1;
        // Calculate matrix elements
        t[1] = matrix_ssx_zp_mummupmummupa_no_hxg();
        double tsum = 0;
        for(int iproc = 0;iproc < nprocesses;iproc++ )
        {
          matrix_element[iproc] += t[iproc];
          tsum += t[iproc];
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true;
          ngood++;
          igood[ngood] = ihel;
        }
      }
    }
    jhel = 0;
    sum_hel = min(sum_hel, ngood);
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0;j < sum_hel;j++ )
    {
      jhel++;
      if (jhel >= ngood)
        jhel = 0;
      double hwgt = double(ngood)/double(sum_hel);
      int ihel = igood[jhel];
      calculate_wavefunctions(perm, helicities[ihel]);
      t[0] = matrix_ssx_zp_mummupmummupa_no_hxg();
      // Mirror initial state momenta for mirror process
      perm[0] = 1;
      perm[1] = 0;
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]);
      // Mirror back
      perm[0] = 0;
      perm[1] = 1;
      // Calculate matrix elements
      t[1] = matrix_ssx_zp_mummupmummupa_no_hxg();
      for(int iproc = 0;iproc < nprocesses;iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt;
      }
    }
  }

  for (int i = 0;i < nprocesses;i++ )
    matrix_element[i] /= denominators[i];



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double qq_Spin1_2f_DN_SFpA::sigmaHat() 
{
  // Select between the different processes
  if(id1 == -3 && id2 == 3)
  {
    // Add matrix elements for processes with beams (-3, 3)
    return matrix_element[1];
  }
  else if(id1 == 3 && id2 == -3)
  {
    // Add matrix elements for processes with beams (3, -3)
    return matrix_element[0];
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.;
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void qq_Spin1_2f_DN_SFpA::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
//	int i, j;	// Changed by Convert_source 0.2

  // Calculate all wavefunctions
  ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]);
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
  oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
  ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
  oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]);
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]);
  vxxxxx(p[perm[6]], mME[6], hel[6], +1, w[6]);
  FFV1_2_3_4_3(w[0], w[1], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MZp, pars->WZp, w[7]);
  FFV2P0_3(w[3], w[2], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[8]);
  FFV1_2_3_4_1(w[4], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[9]);
  FFV2_2(w[5], w[8], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[10]);
  FFV1_2_3_4_2(w[5], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[11]);
  FFV2_1(w[4], w[8], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[12]);
  FFV5_7_3(w[3], w[2], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[13]);
  FFV5_7_2(w[5], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[14]);
  FFV5_7_1(w[4], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[15]);
  FFV2P0_3(w[0], w[1], pars->HEF_MEKD2_1_GC_3, pars->ZERO, pars->ZERO, w[16]);
  FFV1_2_3_4_3(w[3], w[2], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[17]);
  FFV2_1(w[4], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[18]);
  FFV1_2_3_4_2(w[5], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[19]);
  FFV2_2(w[5], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[20]);
  FFV1_2_3_4_1(w[4], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[21]);
  FFV5_6_3(w[0], w[1], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MZ, pars->WZ, w[22]);
  FFV5_7_1(w[4], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[23]);
  FFV5_7_2(w[5], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[24]);
  FFV2_1(w[4], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[25]);
  FFV1_2_3_4_1(w[25], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[26]);
  VVV1_2_1(w[13], w[7], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[27]);
  FFV2_1(w[25], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[28]);
  VVV1_2_1(w[22], w[17], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[29]);
  FFV5_7_1(w[25], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[30]);
  VVV1_2_3(w[22], w[13], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZp, pars->WZp, w[31]);
  FFV2_2(w[5], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[32]);
  FFV1_2_3_4_2(w[32], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[33]);
  FFV2_2(w[32], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[34]);
  FFV5_7_2(w[32], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[35]);
  FFV2P0_3(w[5], w[2], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[36]);
  FFV1_2_3_4_2(w[3], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[37]);
  FFV2_1(w[4], w[36], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[38]);
  FFV2_2(w[3], w[36], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[39]);
  FFV5_7_3(w[5], w[2], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[40]);
  FFV5_7_1(w[4], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[41]);
  FFV5_7_2(w[3], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[42]);
  FFV1_2_3_4_3(w[5], w[2], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[43]);
  FFV2_2(w[3], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[44]);
  FFV1_2_3_4_1(w[4], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[45]);
  FFV1_2_3_4_2(w[3], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[46]);
  FFV5_7_2(w[3], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[47]);
  FFV2_2(w[3], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[48]);
  FFV1_2_3_4_2(w[48], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[49]);
  VVV1_2_1(w[40], w[7], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[50]);
  FFV2_2(w[48], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[51]);
  VVV1_2_1(w[22], w[43], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[52]);
  FFV5_7_2(w[48], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[53]);
  VVV1_2_3(w[22], w[40], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZp, pars->WZp, w[54]);
  FFV2_1(w[2], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[55]);
  FFV2P0_3(w[5], w[55], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[56]);
  FFV5_7_3(w[5], w[55], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[57]);
  FFV2P0_3(w[3], w[55], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[58]);
  FFV5_7_3(w[3], w[55], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[59]);
  FFV1_2_3_4_3(w[5], w[55], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[60]);
  FFV1_2_3_4_3(w[3], w[55], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[61]);
  FFV2P0_3(w[3], w[4], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[62]);
  FFV1_2_3_4_1(w[55], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[63]);
  FFV5_7_3(w[3], w[4], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[64]);
  VVV1_2_1(w[64], w[7], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[65]);
  FFV1_2_3_4_3(w[3], w[4], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[66]);
  FFV2_1(w[55], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[67]);
  FFV5_7_1(w[55], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[68]);
  VVV1_2_1(w[22], w[66], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[69]);
  VVV1_2_3(w[22], w[64], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZp, pars->WZp, w[70]);
  FFV2P0_3(w[5], w[4], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[71]);
  FFV5_7_3(w[5], w[4], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[72]);
  VVV1_2_1(w[72], w[7], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[73]);
  FFV1_2_3_4_3(w[5], w[4], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[74]);
  VVV1_2_1(w[22], w[74], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZ, pars->WZ, w[75]);
  VVV1_2_3(w[22], w[72], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, pars->MZp, pars->WZp, w[76]);
  FFV1_2_3_4_1(w[2], w[7], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[77]);
  FFV2_2(w[5], w[62], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[78]);
  FFV2_1(w[2], w[62], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[79]);
  FFV5_7_2(w[5], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[80]);
  FFV5_7_1(w[2], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[81]);
  FFV2_1(w[2], w[16], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[82]);
  FFV1_2_3_4_2(w[5], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[83]);
  FFV1_2_3_4_1(w[2], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[84]);
  FFV5_7_1(w[2], w[22], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[85]);
  FFV2P0_3(w[48], w[4], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[86]);
  FFV5_7_3(w[48], w[4], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[87]);
  FFV2P0_3(w[48], w[2], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[88]);
  FFV5_7_3(w[48], w[2], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[89]);
  FFV1_2_3_4_3(w[48], w[4], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[90]);
  FFV1_2_3_4_3(w[48], w[2], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[91]);
  FFV2_2(w[3], w[71], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[92]);
  FFV2_1(w[2], w[71], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[93]);
  FFV5_7_2(w[3], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[94]);
  FFV5_7_1(w[2], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[95]);
  FFV1_2_3_4_2(w[3], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[96]);
  FFV1_2_3_4_1(w[2], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MM, pars->ZERO, w[97]);
  FFV2P0_3(w[3], w[25], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[98]);
  FFV5_7_3(w[3], w[25], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[99]);
  FFV2P0_3(w[5], w[25], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[100]);
  FFV5_7_3(w[5], w[25], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ,
      w[101]);
  FFV1_2_3_4_3(w[3], w[25], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[102]);
  FFV1_2_3_4_3(w[5], w[25], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[103]);
  FFV2P0_3(w[32], w[4], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[104]);
  FFV5_7_3(w[32], w[4], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ,
      w[105]);
  FFV2P0_3(w[32], w[2], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[106]);
  FFV5_7_3(w[32], w[2], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ,
      w[107]);
  FFV1_2_3_4_3(w[32], w[4], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[108]);
  FFV1_2_3_4_3(w[32], w[2], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, pars->MZp, pars->WZp, w[109]);
  FFV2_2(w[0], w[6], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[110]);
  FFV2P0_3(w[110], w[1], pars->HEF_MEKD2_1_GC_3, pars->ZERO, pars->ZERO, w[111]);
  FFV5_6_3(w[110], w[1], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MZ, pars->WZ,
      w[112]);
  FFV1_2_3_4_3(w[110], w[1], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MZp, pars->WZp, w[113]);
  FFV1_2_3_4_2(w[110], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[114]);
  FFV2_2(w[110], w[71], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[115]);
  FFV5_6_2(w[110], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[116]);
  FFV2_2(w[110], w[8], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[117]);
  FFV1_2_3_4_2(w[110], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[118]);
  FFV5_6_2(w[110], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[119]);
  FFV1_2_3_4_2(w[110], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[120]);
  FFV2_2(w[110], w[62], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[121]);
  FFV5_6_2(w[110], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[122]);
  FFV2_2(w[110], w[36], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[123]);
  FFV1_2_3_4_2(w[110], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[124]);
  FFV5_6_2(w[110], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[125]);
  FFV2_1(w[1], w[6], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[126]);
  FFV2P0_3(w[0], w[126], pars->HEF_MEKD2_1_GC_3, pars->ZERO, pars->ZERO, w[127]);
  FFV5_6_3(w[0], w[126], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MZ, pars->WZ,
      w[128]);
  FFV1_2_3_4_3(w[0], w[126], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MZp, pars->WZp, w[129]);
  FFV1_2_3_4_2(w[0], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[130]);
  FFV2_2(w[0], w[71], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[131]);
  FFV5_6_2(w[0], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[132]);
  FFV2_2(w[0], w[8], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[133]);
  FFV1_2_3_4_2(w[0], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[134]);
  FFV5_6_2(w[0], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[135]);
  FFV1_2_3_4_2(w[0], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[136]);
  FFV2_2(w[0], w[62], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[137]);
  FFV5_6_2(w[0], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[138]);
  FFV2_2(w[0], w[36], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[139]);
  FFV1_2_3_4_2(w[0], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[140]);
  FFV5_6_2(w[0], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[141]);
  FFV2_1(w[1], w[71], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[142]);
  FFV1_2_3_4_1(w[1], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[143]);
  FFV5_6_1(w[1], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[144]);
  FFV1_2_3_4_1(w[1], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[145]);
  FFV2_1(w[1], w[8], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[146]);
  FFV5_6_1(w[1], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[147]);
  FFV2_1(w[1], w[62], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[148]);
  FFV1_2_3_4_1(w[1], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[149]);
  FFV5_6_1(w[1], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[150]);
  FFV1_2_3_4_1(w[1], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, pars->MS, pars->ZERO, w[151]);
  FFV2_1(w[1], w[36], pars->HEF_MEKD2_1_GC_3, pars->MS, pars->ZERO, w[152]);
  FFV5_6_1(w[1], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, pars->MS, pars->ZERO,
      w[153]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV2_0(w[10], w[9], w[6], pars->HEF_MEKD2_1_GC_5, amp[0]);
  FFV2_0(w[11], w[12], w[6], pars->HEF_MEKD2_1_GC_5, amp[1]);
  FFV2_0(w[14], w[9], w[6], pars->HEF_MEKD2_1_GC_5, amp[2]);
  FFV2_0(w[11], w[15], w[6], pars->HEF_MEKD2_1_GC_5, amp[3]);
  FFV2_0(w[19], w[18], w[6], pars->HEF_MEKD2_1_GC_5, amp[4]);
  FFV2_0(w[20], w[21], w[6], pars->HEF_MEKD2_1_GC_5, amp[5]);
  FFV2_0(w[19], w[23], w[6], pars->HEF_MEKD2_1_GC_5, amp[6]);
  FFV2_0(w[24], w[21], w[6], pars->HEF_MEKD2_1_GC_5, amp[7]);
  FFV2_0(w[5], w[26], w[8], pars->HEF_MEKD2_1_GC_5, amp[8]);
  FFV2_0(w[11], w[25], w[8], pars->HEF_MEKD2_1_GC_5, amp[9]);
  FFV5_7_0(w[5], w[25], w[27], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[10]);
  FFV5_7_0(w[5], w[26], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[11]);
  FFV5_7_0(w[11], w[25], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[12]);
  FFV1_2_3_4_0(w[5], w[28], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[13]);
  FFV1_2_3_4_0(w[20], w[25], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[14]);
  FFV5_7_0(w[5], w[25], w[29], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[15]);
  FFV1_2_3_4_0(w[5], w[30], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[16]);
  FFV1_2_3_4_0(w[24], w[25], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[17]);
  FFV1_2_3_4_0(w[5], w[25], w[31], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[18]);
  FFV2_0(w[32], w[9], w[8], pars->HEF_MEKD2_1_GC_5, amp[19]);
  FFV2_0(w[33], w[4], w[8], pars->HEF_MEKD2_1_GC_5, amp[20]);
  FFV5_7_0(w[32], w[4], w[27], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[21]);
  FFV5_7_0(w[32], w[9], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[22]);
  FFV5_7_0(w[33], w[4], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[23]);
  FFV1_2_3_4_0(w[32], w[18], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[24]);
  FFV1_2_3_4_0(w[34], w[4], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[25]);
  FFV5_7_0(w[32], w[4], w[29], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[26]);
  FFV1_2_3_4_0(w[32], w[23], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[27]);
  FFV1_2_3_4_0(w[35], w[4], w[17], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[28]);
  FFV1_2_3_4_0(w[32], w[4], w[31], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[29]);
  FFV2_0(w[37], w[38], w[6], pars->HEF_MEKD2_1_GC_5, amp[30]);
  FFV2_0(w[39], w[9], w[6], pars->HEF_MEKD2_1_GC_5, amp[31]);
  FFV2_0(w[37], w[41], w[6], pars->HEF_MEKD2_1_GC_5, amp[32]);
  FFV2_0(w[42], w[9], w[6], pars->HEF_MEKD2_1_GC_5, amp[33]);
  FFV2_0(w[44], w[45], w[6], pars->HEF_MEKD2_1_GC_5, amp[34]);
  FFV2_0(w[46], w[18], w[6], pars->HEF_MEKD2_1_GC_5, amp[35]);
  FFV2_0(w[47], w[45], w[6], pars->HEF_MEKD2_1_GC_5, amp[36]);
  FFV2_0(w[46], w[23], w[6], pars->HEF_MEKD2_1_GC_5, amp[37]);
  FFV2_0(w[49], w[4], w[36], pars->HEF_MEKD2_1_GC_5, amp[38]);
  FFV2_0(w[48], w[9], w[36], pars->HEF_MEKD2_1_GC_5, amp[39]);
  FFV5_7_0(w[48], w[4], w[50], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[40]);
  FFV5_7_0(w[49], w[4], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[41]);
  FFV5_7_0(w[48], w[9], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[42]);
  FFV1_2_3_4_0(w[51], w[4], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[43]);
  FFV1_2_3_4_0(w[48], w[18], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[44]);
  FFV5_7_0(w[48], w[4], w[52], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[45]);
  FFV1_2_3_4_0(w[53], w[4], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[46]);
  FFV1_2_3_4_0(w[48], w[23], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[47]);
  FFV1_2_3_4_0(w[48], w[4], w[54], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[48]);
  FFV2_0(w[37], w[25], w[36], pars->HEF_MEKD2_1_GC_5, amp[49]);
  FFV2_0(w[3], w[26], w[36], pars->HEF_MEKD2_1_GC_5, amp[50]);
  FFV5_7_0(w[3], w[25], w[50], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[51]);
  FFV5_7_0(w[37], w[25], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[52]);
  FFV5_7_0(w[3], w[26], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[53]);
  FFV1_2_3_4_0(w[44], w[25], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[54]);
  FFV1_2_3_4_0(w[3], w[28], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[55]);
  FFV5_7_0(w[3], w[25], w[52], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[56]);
  FFV1_2_3_4_0(w[47], w[25], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[57]);
  FFV1_2_3_4_0(w[3], w[30], w[43], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[58]);
  FFV1_2_3_4_0(w[3], w[25], w[54], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[59]);
  FFV2_0(w[37], w[4], w[56], pars->HEF_MEKD2_1_GC_5, amp[60]);
  FFV5_7_0(w[37], w[4], w[57], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[61]);
  FFV2_0(w[5], w[9], w[58], pars->HEF_MEKD2_1_GC_5, amp[62]);
  FFV5_7_0(w[5], w[9], w[59], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[63]);
  FFV2_0(w[3], w[9], w[56], pars->HEF_MEKD2_1_GC_5, amp[64]);
  FFV5_7_0(w[3], w[9], w[57], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[65]);
  FFV2_0(w[11], w[4], w[58], pars->HEF_MEKD2_1_GC_5, amp[66]);
  FFV5_7_0(w[11], w[4], w[59], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[67]);
  FFV1_2_3_4_0(w[44], w[4], w[60], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[68]);
  FFV1_2_3_4_0(w[5], w[18], w[61], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[69]);
  FFV1_2_3_4_0(w[3], w[18], w[60], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[70]);
  FFV1_2_3_4_0(w[20], w[4], w[61], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[71]);
  FFV1_2_3_4_0(w[47], w[4], w[60], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[72]);
  FFV1_2_3_4_0(w[5], w[23], w[61], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[73]);
  FFV1_2_3_4_0(w[3], w[23], w[60], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[74]);
  FFV1_2_3_4_0(w[24], w[4], w[61], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[75]);
  FFV2_0(w[5], w[63], w[62], pars->HEF_MEKD2_1_GC_5, amp[76]);
  FFV2_0(w[11], w[55], w[62], pars->HEF_MEKD2_1_GC_5, amp[77]);
  FFV5_7_0(w[5], w[63], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[78]);
  FFV5_7_0(w[5], w[55], w[65], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[79]);
  FFV5_7_0(w[11], w[55], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[80]);
  FFV1_2_3_4_0(w[5], w[67], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[81]);
  FFV1_2_3_4_0(w[20], w[55], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[82]);
  FFV1_2_3_4_0(w[5], w[68], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[83]);
  FFV5_7_0(w[5], w[55], w[69], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[84]);
  FFV1_2_3_4_0(w[24], w[55], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[85]);
  FFV1_2_3_4_0(w[5], w[55], w[70], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[86]);
  FFV2_0(w[3], w[63], w[71], pars->HEF_MEKD2_1_GC_5, amp[87]);
  FFV2_0(w[37], w[55], w[71], pars->HEF_MEKD2_1_GC_5, amp[88]);
  FFV5_7_0(w[3], w[63], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[89]);
  FFV5_7_0(w[37], w[55], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[90]);
  FFV5_7_0(w[3], w[55], w[73], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[91]);
  FFV1_2_3_4_0(w[3], w[67], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[92]);
  FFV1_2_3_4_0(w[44], w[55], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[93]);
  FFV1_2_3_4_0(w[3], w[68], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[94]);
  FFV1_2_3_4_0(w[47], w[55], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[95]);
  FFV5_7_0(w[3], w[55], w[75], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[96]);
  FFV1_2_3_4_0(w[3], w[55], w[76], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[97]);
  FFV2_0(w[78], w[77], w[6], pars->HEF_MEKD2_1_GC_5, amp[98]);
  FFV2_0(w[11], w[79], w[6], pars->HEF_MEKD2_1_GC_5, amp[99]);
  FFV2_0(w[80], w[77], w[6], pars->HEF_MEKD2_1_GC_5, amp[100]);
  FFV2_0(w[11], w[81], w[6], pars->HEF_MEKD2_1_GC_5, amp[101]);
  FFV2_0(w[83], w[82], w[6], pars->HEF_MEKD2_1_GC_5, amp[102]);
  FFV2_0(w[20], w[84], w[6], pars->HEF_MEKD2_1_GC_5, amp[103]);
  FFV2_0(w[83], w[85], w[6], pars->HEF_MEKD2_1_GC_5, amp[104]);
  FFV2_0(w[24], w[84], w[6], pars->HEF_MEKD2_1_GC_5, amp[105]);
  FFV2_0(w[32], w[77], w[62], pars->HEF_MEKD2_1_GC_5, amp[106]);
  FFV2_0(w[33], w[2], w[62], pars->HEF_MEKD2_1_GC_5, amp[107]);
  FFV5_7_0(w[32], w[77], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[108]);
  FFV5_7_0(w[32], w[2], w[65], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[109]);
  FFV5_7_0(w[33], w[2], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[110]);
  FFV1_2_3_4_0(w[32], w[82], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[111]);
  FFV1_2_3_4_0(w[34], w[2], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[112]);
  FFV1_2_3_4_0(w[32], w[85], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[113]);
  FFV5_7_0(w[32], w[2], w[69], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[114]);
  FFV1_2_3_4_0(w[35], w[2], w[66], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[115]);
  FFV1_2_3_4_0(w[32], w[2], w[70], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[116]);
  FFV2_0(w[5], w[77], w[86], pars->HEF_MEKD2_1_GC_5, amp[117]);
  FFV5_7_0(w[5], w[77], w[87], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[118]);
  FFV2_0(w[5], w[9], w[88], pars->HEF_MEKD2_1_GC_5, amp[119]);
  FFV5_7_0(w[5], w[9], w[89], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[120]);
  FFV2_0(w[11], w[4], w[88], pars->HEF_MEKD2_1_GC_5, amp[121]);
  FFV5_7_0(w[11], w[4], w[89], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[122]);
  FFV2_0(w[11], w[2], w[86], pars->HEF_MEKD2_1_GC_5, amp[123]);
  FFV5_7_0(w[11], w[2], w[87], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[124]);
  FFV1_2_3_4_0(w[5], w[82], w[90], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[125]);
  FFV1_2_3_4_0(w[5], w[18], w[91], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[126]);
  FFV1_2_3_4_0(w[20], w[4], w[91], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[127]);
  FFV1_2_3_4_0(w[20], w[2], w[90], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[128]);
  FFV1_2_3_4_0(w[5], w[85], w[90], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[129]);
  FFV1_2_3_4_0(w[5], w[23], w[91], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[130]);
  FFV1_2_3_4_0(w[24], w[4], w[91], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[131]);
  FFV1_2_3_4_0(w[24], w[2], w[90], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[132]);
  FFV2_0(w[48], w[77], w[71], pars->HEF_MEKD2_1_GC_5, amp[133]);
  FFV2_0(w[49], w[2], w[71], pars->HEF_MEKD2_1_GC_5, amp[134]);
  FFV5_7_0(w[48], w[77], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[135]);
  FFV5_7_0(w[49], w[2], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[136]);
  FFV5_7_0(w[48], w[2], w[73], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[137]);
  FFV1_2_3_4_0(w[48], w[82], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[138]);
  FFV1_2_3_4_0(w[51], w[2], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[139]);
  FFV1_2_3_4_0(w[48], w[85], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[140]);
  FFV1_2_3_4_0(w[53], w[2], w[74], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[141]);
  FFV5_7_0(w[48], w[2], w[75], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[142]);
  FFV1_2_3_4_0(w[48], w[2], w[76], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[143]);
  FFV2_0(w[92], w[77], w[6], pars->HEF_MEKD2_1_GC_5, amp[144]);
  FFV2_0(w[37], w[93], w[6], pars->HEF_MEKD2_1_GC_5, amp[145]);
  FFV2_0(w[94], w[77], w[6], pars->HEF_MEKD2_1_GC_5, amp[146]);
  FFV2_0(w[37], w[95], w[6], pars->HEF_MEKD2_1_GC_5, amp[147]);
  FFV2_0(w[96], w[82], w[6], pars->HEF_MEKD2_1_GC_5, amp[148]);
  FFV2_0(w[44], w[97], w[6], pars->HEF_MEKD2_1_GC_5, amp[149]);
  FFV2_0(w[96], w[85], w[6], pars->HEF_MEKD2_1_GC_5, amp[150]);
  FFV2_0(w[47], w[97], w[6], pars->HEF_MEKD2_1_GC_5, amp[151]);
  FFV2_0(w[5], w[77], w[98], pars->HEF_MEKD2_1_GC_5, amp[152]);
  FFV5_7_0(w[5], w[77], w[99], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[153]);
  FFV2_0(w[3], w[77], w[100], pars->HEF_MEKD2_1_GC_5, amp[154]);
  FFV5_7_0(w[3], w[77], w[101], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[155]);
  FFV2_0(w[37], w[2], w[100], pars->HEF_MEKD2_1_GC_5, amp[156]);
  FFV5_7_0(w[37], w[2], w[101], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[157]);
  FFV2_0(w[11], w[2], w[98], pars->HEF_MEKD2_1_GC_5, amp[158]);
  FFV5_7_0(w[11], w[2], w[99], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[159]);
  FFV1_2_3_4_0(w[5], w[82], w[102], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[160]);
  FFV1_2_3_4_0(w[3], w[82], w[103], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[161]);
  FFV1_2_3_4_0(w[44], w[2], w[103], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[162]);
  FFV1_2_3_4_0(w[20], w[2], w[102], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[163]);
  FFV1_2_3_4_0(w[5], w[85], w[102], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[164]);
  FFV1_2_3_4_0(w[3], w[85], w[103], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[165]);
  FFV1_2_3_4_0(w[47], w[2], w[103], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[166]);
  FFV1_2_3_4_0(w[24], w[2], w[102], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[167]);
  FFV2_0(w[3], w[77], w[104], pars->HEF_MEKD2_1_GC_5, amp[168]);
  FFV5_7_0(w[3], w[77], w[105], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[169]);
  FFV2_0(w[37], w[4], w[106], pars->HEF_MEKD2_1_GC_5, amp[170]);
  FFV5_7_0(w[37], w[4], w[107], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[171]);
  FFV2_0(w[37], w[2], w[104], pars->HEF_MEKD2_1_GC_5, amp[172]);
  FFV5_7_0(w[37], w[2], w[105], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[173]);
  FFV2_0(w[3], w[9], w[106], pars->HEF_MEKD2_1_GC_5, amp[174]);
  FFV5_7_0(w[3], w[9], w[107], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[175]);
  FFV1_2_3_4_0(w[3], w[82], w[108], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[176]);
  FFV1_2_3_4_0(w[44], w[4], w[109], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[177]);
  FFV1_2_3_4_0(w[44], w[2], w[108], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[178]);
  FFV1_2_3_4_0(w[3], w[18], w[109], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[179]);
  FFV1_2_3_4_0(w[3], w[85], w[108], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[180]);
  FFV1_2_3_4_0(w[47], w[4], w[109], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[181]);
  FFV1_2_3_4_0(w[47], w[2], w[108], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[182]);
  FFV1_2_3_4_0(w[3], w[23], w[109], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[183]);
  FFV2_0(w[5], w[21], w[111], pars->HEF_MEKD2_1_GC_5, amp[184]);
  FFV5_7_0(w[5], w[21], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[185]);
  FFV2_0(w[19], w[4], w[111], pars->HEF_MEKD2_1_GC_5, amp[186]);
  FFV5_7_0(w[19], w[4], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[187]);
  FFV1_2_3_4_0(w[5], w[12], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[188]);
  FFV1_2_3_4_0(w[10], w[4], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[189]);
  FFV1_2_3_4_0(w[5], w[15], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[190]);
  FFV1_2_3_4_0(w[14], w[4], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[191]);
  FFV2_0(w[114], w[1], w[71], pars->HEF_MEKD2_1_GC_3, amp[192]);
  FFV1_2_3_4_0(w[115], w[1], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[193]);
  VVV1_2_0(w[72], w[112], w[17], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[194]);
  FFV5_6_0(w[114], w[1], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[195]);
  FFV1_2_3_4_0(w[116], w[1], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[196]);
  FFV1_2_3_4_0(w[117], w[1], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[197]);
  FFV2_0(w[118], w[1], w[8], pars->HEF_MEKD2_1_GC_3, amp[198]);
  VVV1_2_0(w[13], w[112], w[74], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[199]);
  FFV1_2_3_4_0(w[119], w[1], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[200]);
  FFV5_6_0(w[118], w[1], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[201]);
  VVV1_2_0(w[13], w[72], w[113], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[202]);
  FFV2_0(w[46], w[4], w[111], pars->HEF_MEKD2_1_GC_5, amp[203]);
  FFV5_7_0(w[46], w[4], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[204]);
  FFV2_0(w[3], w[45], w[111], pars->HEF_MEKD2_1_GC_5, amp[205]);
  FFV5_7_0(w[3], w[45], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[206]);
  FFV1_2_3_4_0(w[39], w[4], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[207]);
  FFV1_2_3_4_0(w[3], w[38], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[208]);
  FFV1_2_3_4_0(w[42], w[4], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[209]);
  FFV1_2_3_4_0(w[3], w[41], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[210]);
  FFV2_0(w[120], w[1], w[62], pars->HEF_MEKD2_1_GC_3, amp[211]);
  FFV1_2_3_4_0(w[121], w[1], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[212]);
  VVV1_2_0(w[64], w[112], w[43], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[213]);
  FFV5_6_0(w[120], w[1], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[214]);
  FFV1_2_3_4_0(w[122], w[1], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[215]);
  FFV1_2_3_4_0(w[123], w[1], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[216]);
  FFV2_0(w[124], w[1], w[36], pars->HEF_MEKD2_1_GC_3, amp[217]);
  VVV1_2_0(w[40], w[112], w[66], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[218]);
  FFV1_2_3_4_0(w[125], w[1], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[219]);
  FFV5_6_0(w[124], w[1], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[220]);
  VVV1_2_0(w[40], w[64], w[113], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[221]);
  FFV2_0(w[5], w[84], w[111], pars->HEF_MEKD2_1_GC_5, amp[222]);
  FFV5_7_0(w[5], w[84], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[223]);
  FFV2_0(w[83], w[2], w[111], pars->HEF_MEKD2_1_GC_5, amp[224]);
  FFV5_7_0(w[83], w[2], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[225]);
  FFV1_2_3_4_0(w[5], w[79], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[226]);
  FFV1_2_3_4_0(w[78], w[2], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[227]);
  FFV1_2_3_4_0(w[5], w[81], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[228]);
  FFV1_2_3_4_0(w[80], w[2], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[229]);
  FFV2_0(w[3], w[97], w[111], pars->HEF_MEKD2_1_GC_5, amp[230]);
  FFV5_7_0(w[3], w[97], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[231]);
  FFV2_0(w[96], w[2], w[111], pars->HEF_MEKD2_1_GC_5, amp[232]);
  FFV5_7_0(w[96], w[2], w[112], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[233]);
  FFV1_2_3_4_0(w[3], w[93], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[234]);
  FFV1_2_3_4_0(w[92], w[2], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[235]);
  FFV1_2_3_4_0(w[3], w[95], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[236]);
  FFV1_2_3_4_0(w[94], w[2], w[113], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[237]);
  FFV2_0(w[5], w[21], w[127], pars->HEF_MEKD2_1_GC_5, amp[238]);
  FFV5_7_0(w[5], w[21], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[239]);
  FFV2_0(w[19], w[4], w[127], pars->HEF_MEKD2_1_GC_5, amp[240]);
  FFV5_7_0(w[19], w[4], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[241]);
  FFV1_2_3_4_0(w[5], w[12], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[242]);
  FFV1_2_3_4_0(w[10], w[4], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[243]);
  FFV1_2_3_4_0(w[5], w[15], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[244]);
  FFV1_2_3_4_0(w[14], w[4], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[245]);
  FFV2_0(w[130], w[126], w[71], pars->HEF_MEKD2_1_GC_3, amp[246]);
  FFV1_2_3_4_0(w[131], w[126], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[247]);
  VVV1_2_0(w[72], w[128], w[17], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[248]);
  FFV5_6_0(w[130], w[126], w[72], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[249]);
  FFV1_2_3_4_0(w[132], w[126], w[17], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[250]);
  FFV1_2_3_4_0(w[133], w[126], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[251]);
  FFV2_0(w[134], w[126], w[8], pars->HEF_MEKD2_1_GC_3, amp[252]);
  VVV1_2_0(w[13], w[128], w[74], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[253]);
  FFV1_2_3_4_0(w[135], w[126], w[74], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[254]);
  FFV5_6_0(w[134], w[126], w[13], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[255]);
  VVV1_2_0(w[13], w[72], w[129], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[256]);
  FFV2_0(w[46], w[4], w[127], pars->HEF_MEKD2_1_GC_5, amp[257]);
  FFV5_7_0(w[46], w[4], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[258]);
  FFV2_0(w[3], w[45], w[127], pars->HEF_MEKD2_1_GC_5, amp[259]);
  FFV5_7_0(w[3], w[45], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[260]);
  FFV1_2_3_4_0(w[39], w[4], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[261]);
  FFV1_2_3_4_0(w[3], w[38], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[262]);
  FFV1_2_3_4_0(w[42], w[4], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[263]);
  FFV1_2_3_4_0(w[3], w[41], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[264]);
  FFV2_0(w[136], w[126], w[62], pars->HEF_MEKD2_1_GC_3, amp[265]);
  FFV1_2_3_4_0(w[137], w[126], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[266]);
  VVV1_2_0(w[64], w[128], w[43], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[267]);
  FFV5_6_0(w[136], w[126], w[64], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[268]);
  FFV1_2_3_4_0(w[138], w[126], w[43], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[269]);
  FFV1_2_3_4_0(w[139], w[126], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[270]);
  FFV2_0(w[140], w[126], w[36], pars->HEF_MEKD2_1_GC_3, amp[271]);
  VVV1_2_0(w[40], w[128], w[66], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[272]);
  FFV1_2_3_4_0(w[141], w[126], w[66], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[273]);
  FFV5_6_0(w[140], w[126], w[40], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[274]);
  VVV1_2_0(w[40], w[64], w[129], pars->HEF_MEKD2_1_GC_2, pars->HEF_MEKD2_1_GC_1, amp[275]);
  FFV2_0(w[5], w[84], w[127], pars->HEF_MEKD2_1_GC_5, amp[276]);
  FFV5_7_0(w[5], w[84], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[277]);
  FFV2_0(w[83], w[2], w[127], pars->HEF_MEKD2_1_GC_5, amp[278]);
  FFV5_7_0(w[83], w[2], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[279]);
  FFV1_2_3_4_0(w[5], w[79], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[280]);
  FFV1_2_3_4_0(w[78], w[2], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[281]);
  FFV1_2_3_4_0(w[5], w[81], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[282]);
  FFV1_2_3_4_0(w[80], w[2], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[283]);
  FFV2_0(w[3], w[97], w[127], pars->HEF_MEKD2_1_GC_5, amp[284]);
  FFV5_7_0(w[3], w[97], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[285]);
  FFV2_0(w[96], w[2], w[127], pars->HEF_MEKD2_1_GC_5, amp[286]);
  FFV5_7_0(w[96], w[2], w[128], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, amp[287]);
  FFV1_2_3_4_0(w[3], w[93], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[288]);
  FFV1_2_3_4_0(w[92], w[2], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[289]);
  FFV1_2_3_4_0(w[3], w[95], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[290]);
  FFV1_2_3_4_0(w[94], w[2], w[129], pars->HEF_MEKD2_1_GC_141, pars->HEF_MEKD2_1_GC_138, pars->HEF_MEKD2_1_GC_139,
      pars->HEF_MEKD2_1_GC_140, amp[291]);
  FFV2_0(w[130], w[142], w[6], pars->HEF_MEKD2_1_GC_3, amp[292]);
  FFV2_0(w[131], w[143], w[6], pars->HEF_MEKD2_1_GC_3, amp[293]);
  FFV2_0(w[130], w[144], w[6], pars->HEF_MEKD2_1_GC_3, amp[294]);
  FFV2_0(w[132], w[143], w[6], pars->HEF_MEKD2_1_GC_3, amp[295]);
  FFV2_0(w[133], w[145], w[6], pars->HEF_MEKD2_1_GC_3, amp[296]);
  FFV2_0(w[134], w[146], w[6], pars->HEF_MEKD2_1_GC_3, amp[297]);
  FFV2_0(w[135], w[145], w[6], pars->HEF_MEKD2_1_GC_3, amp[298]);
  FFV2_0(w[134], w[147], w[6], pars->HEF_MEKD2_1_GC_3, amp[299]);
  FFV2_0(w[130], w[1], w[100], pars->HEF_MEKD2_1_GC_3, amp[300]);
  FFV5_6_0(w[130], w[1], w[101], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[301]);
  FFV2_0(w[0], w[143], w[100], pars->HEF_MEKD2_1_GC_3, amp[302]);
  FFV5_6_0(w[0], w[143], w[101], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[303]);
  FFV1_2_3_4_0(w[133], w[1], w[103], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[304]);
  FFV1_2_3_4_0(w[0], w[146], w[103], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[305]);
  FFV1_2_3_4_0(w[135], w[1], w[103], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[306]);
  FFV1_2_3_4_0(w[0], w[147], w[103], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[307]);
  FFV2_0(w[130], w[1], w[104], pars->HEF_MEKD2_1_GC_3, amp[308]);
  FFV5_6_0(w[130], w[1], w[105], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[309]);
  FFV2_0(w[0], w[143], w[104], pars->HEF_MEKD2_1_GC_3, amp[310]);
  FFV5_6_0(w[0], w[143], w[105], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[311]);
  FFV1_2_3_4_0(w[133], w[1], w[108], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[312]);
  FFV1_2_3_4_0(w[0], w[146], w[108], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[313]);
  FFV1_2_3_4_0(w[135], w[1], w[108], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[314]);
  FFV1_2_3_4_0(w[0], w[147], w[108], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[315]);
  FFV2_0(w[136], w[148], w[6], pars->HEF_MEKD2_1_GC_3, amp[316]);
  FFV2_0(w[137], w[149], w[6], pars->HEF_MEKD2_1_GC_3, amp[317]);
  FFV2_0(w[136], w[150], w[6], pars->HEF_MEKD2_1_GC_3, amp[318]);
  FFV2_0(w[138], w[149], w[6], pars->HEF_MEKD2_1_GC_3, amp[319]);
  FFV2_0(w[139], w[151], w[6], pars->HEF_MEKD2_1_GC_3, amp[320]);
  FFV2_0(w[140], w[152], w[6], pars->HEF_MEKD2_1_GC_3, amp[321]);
  FFV2_0(w[141], w[151], w[6], pars->HEF_MEKD2_1_GC_3, amp[322]);
  FFV2_0(w[140], w[153], w[6], pars->HEF_MEKD2_1_GC_3, amp[323]);
  FFV2_0(w[136], w[1], w[86], pars->HEF_MEKD2_1_GC_3, amp[324]);
  FFV5_6_0(w[136], w[1], w[87], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[325]);
  FFV2_0(w[0], w[149], w[86], pars->HEF_MEKD2_1_GC_3, amp[326]);
  FFV5_6_0(w[0], w[149], w[87], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[327]);
  FFV1_2_3_4_0(w[139], w[1], w[90], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[328]);
  FFV1_2_3_4_0(w[0], w[152], w[90], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[329]);
  FFV1_2_3_4_0(w[141], w[1], w[90], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[330]);
  FFV1_2_3_4_0(w[0], w[153], w[90], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[331]);
  FFV2_0(w[136], w[1], w[98], pars->HEF_MEKD2_1_GC_3, amp[332]);
  FFV5_6_0(w[136], w[1], w[99], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[333]);
  FFV2_0(w[0], w[149], w[98], pars->HEF_MEKD2_1_GC_3, amp[334]);
  FFV5_6_0(w[0], w[149], w[99], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[335]);
  FFV1_2_3_4_0(w[139], w[1], w[102], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[336]);
  FFV1_2_3_4_0(w[0], w[152], w[102], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[337]);
  FFV1_2_3_4_0(w[141], w[1], w[102], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[338]);
  FFV1_2_3_4_0(w[0], w[153], w[102], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[339]);
  FFV2_0(w[140], w[1], w[56], pars->HEF_MEKD2_1_GC_3, amp[340]);
  FFV5_6_0(w[140], w[1], w[57], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[341]);
  FFV2_0(w[0], w[151], w[56], pars->HEF_MEKD2_1_GC_3, amp[342]);
  FFV5_6_0(w[0], w[151], w[57], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[343]);
  FFV1_2_3_4_0(w[137], w[1], w[60], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[344]);
  FFV1_2_3_4_0(w[0], w[148], w[60], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[345]);
  FFV1_2_3_4_0(w[138], w[1], w[60], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[346]);
  FFV1_2_3_4_0(w[0], w[150], w[60], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[347]);
  FFV2_0(w[134], w[1], w[58], pars->HEF_MEKD2_1_GC_3, amp[348]);
  FFV5_6_0(w[134], w[1], w[59], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[349]);
  FFV2_0(w[0], w[145], w[58], pars->HEF_MEKD2_1_GC_3, amp[350]);
  FFV5_6_0(w[0], w[145], w[59], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[351]);
  FFV1_2_3_4_0(w[131], w[1], w[61], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[352]);
  FFV1_2_3_4_0(w[0], w[142], w[61], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[353]);
  FFV1_2_3_4_0(w[132], w[1], w[61], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[354]);
  FFV1_2_3_4_0(w[0], w[144], w[61], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[355]);
  FFV2_0(w[140], w[1], w[106], pars->HEF_MEKD2_1_GC_3, amp[356]);
  FFV5_6_0(w[140], w[1], w[107], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[357]);
  FFV2_0(w[0], w[151], w[106], pars->HEF_MEKD2_1_GC_3, amp[358]);
  FFV5_6_0(w[0], w[151], w[107], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[359]);
  FFV1_2_3_4_0(w[137], w[1], w[109], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[360]);
  FFV1_2_3_4_0(w[0], w[148], w[109], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[361]);
  FFV1_2_3_4_0(w[138], w[1], w[109], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[362]);
  FFV1_2_3_4_0(w[0], w[150], w[109], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[363]);
  FFV2_0(w[134], w[1], w[88], pars->HEF_MEKD2_1_GC_3, amp[364]);
  FFV5_6_0(w[134], w[1], w[89], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[365]);
  FFV2_0(w[0], w[145], w[88], pars->HEF_MEKD2_1_GC_3, amp[366]);
  FFV5_6_0(w[0], w[145], w[89], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_187, amp[367]);
  FFV1_2_3_4_0(w[131], w[1], w[91], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[368]);
  FFV1_2_3_4_0(w[0], w[142], w[91], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[369]);
  FFV1_2_3_4_0(w[132], w[1], w[91], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[370]);
  FFV1_2_3_4_0(w[0], w[144], w[91], pars->HEF_MEKD2_1_GC_151, pars->HEF_MEKD2_1_GC_148, pars->HEF_MEKD2_1_GC_149,
      pars->HEF_MEKD2_1_GC_150, amp[371]);

}
double qq_Spin1_2f_DN_SFpA::matrix_ssx_zp_mummupmummupa_no_hxg() 
{
  int i, j;
  // Local variables
	// Commented out by Convert_source 0.2
//  const int ngraphs = 372;
  const int ncolor = 1;
  std::complex<double> ztemp;
  std::complex<double> jamp[ncolor];
  // The color matrix;
  static const double denom[ncolor] = {1};
  static const double cf[ncolor][ncolor] = {{3}};

  // Calculate color flows
  jamp[0] = +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] + amp[6] +
      amp[7] + amp[8] + amp[9] + amp[10] + amp[11] + amp[12] + amp[13] +
      amp[14] + amp[15] + amp[16] + amp[17] + amp[18] + amp[19] + amp[20] +
      amp[21] + amp[22] + amp[23] + amp[24] + amp[25] + amp[26] + amp[27] +
      amp[28] + amp[29] - amp[30] - amp[31] - amp[32] - amp[33] - amp[34] -
      amp[35] - amp[36] - amp[37] - amp[38] - amp[39] - amp[40] - amp[41] -
      amp[42] - amp[43] - amp[44] - amp[45] - amp[46] - amp[47] - amp[48] -
      amp[49] - amp[50] - amp[51] - amp[52] - amp[53] - amp[54] - amp[55] -
      amp[56] - amp[57] - amp[58] - amp[59] - amp[60] - amp[61] + amp[62] +
      amp[63] - amp[64] - amp[65] + amp[66] + amp[67] - amp[68] + amp[69] -
      amp[70] + amp[71] - amp[72] + amp[73] - amp[74] + amp[75] - amp[76] -
      amp[77] - amp[78] - amp[79] - amp[80] - amp[81] - amp[82] - amp[83] -
      amp[84] - amp[85] - amp[86] + amp[87] + amp[88] + amp[89] + amp[90] +
      amp[91] + amp[92] + amp[93] + amp[94] + amp[95] + amp[96] + amp[97] -
      amp[98] - amp[99] - amp[100] - amp[101] - amp[102] - amp[103] - amp[104]
      - amp[105] - amp[106] - amp[107] - amp[108] - amp[109] - amp[110] -
      amp[111] - amp[112] - amp[113] - amp[114] - amp[115] - amp[116] -
      amp[117] - amp[118] + amp[119] + amp[120] + amp[121] + amp[122] -
      amp[123] - amp[124] - amp[125] + amp[126] + amp[127] - amp[128] -
      amp[129] + amp[130] + amp[131] - amp[132] + amp[133] + amp[134] +
      amp[135] + amp[136] + amp[137] + amp[138] + amp[139] + amp[140] +
      amp[141] + amp[142] + amp[143] + amp[144] + amp[145] + amp[146] +
      amp[147] + amp[148] + amp[149] + amp[150] + amp[151] - amp[152] -
      amp[153] + amp[154] + amp[155] + amp[156] + amp[157] - amp[158] -
      amp[159] - amp[160] + amp[161] + amp[162] - amp[163] - amp[164] +
      amp[165] + amp[166] - amp[167] + amp[168] + amp[169] - amp[170] -
      amp[171] + amp[172] + amp[173] - amp[174] - amp[175] + amp[176] -
      amp[177] + amp[178] - amp[179] + amp[180] - amp[181] + amp[182] -
      amp[183] + amp[184] + amp[185] + amp[186] + amp[187] + amp[188] +
      amp[189] + amp[190] + amp[191] + amp[192] + amp[193] + amp[194] +
      amp[195] + amp[196] + amp[197] + amp[198] + amp[199] + amp[200] +
      amp[201] + amp[202] - amp[203] - amp[204] - amp[205] - amp[206] -
      amp[207] - amp[208] - amp[209] - amp[210] - amp[211] - amp[212] -
      amp[213] - amp[214] - amp[215] - amp[216] - amp[217] - amp[218] -
      amp[219] - amp[220] - amp[221] - amp[222] - amp[223] - amp[224] -
      amp[225] - amp[226] - amp[227] - amp[228] - amp[229] + amp[230] +
      amp[231] + amp[232] + amp[233] + amp[234] + amp[235] + amp[236] +
      amp[237] + amp[238] + amp[239] + amp[240] + amp[241] + amp[242] +
      amp[243] + amp[244] + amp[245] + amp[246] + amp[247] + amp[248] +
      amp[249] + amp[250] + amp[251] + amp[252] + amp[253] + amp[254] +
      amp[255] + amp[256] - amp[257] - amp[258] - amp[259] - amp[260] -
      amp[261] - amp[262] - amp[263] - amp[264] - amp[265] - amp[266] -
      amp[267] - amp[268] - amp[269] - amp[270] - amp[271] - amp[272] -
      amp[273] - amp[274] - amp[275] - amp[276] - amp[277] - amp[278] -
      amp[279] - amp[280] - amp[281] - amp[282] - amp[283] + amp[284] +
      amp[285] + amp[286] + amp[287] + amp[288] + amp[289] + amp[290] +
      amp[291] + amp[292] + amp[293] + amp[294] + amp[295] + amp[296] +
      amp[297] + amp[298] + amp[299] + amp[300] + amp[301] + amp[302] +
      amp[303] + amp[304] + amp[305] + amp[306] + amp[307] + amp[308] +
      amp[309] + amp[310] + amp[311] + amp[312] + amp[313] + amp[314] +
      amp[315] - amp[316] - amp[317] - amp[318] - amp[319] - amp[320] -
      amp[321] - amp[322] - amp[323] - amp[324] - amp[325] - amp[326] -
      amp[327] - amp[328] - amp[329] - amp[330] - amp[331] - amp[332] -
      amp[333] - amp[334] - amp[335] - amp[336] - amp[337] - amp[338] -
      amp[339] - amp[340] - amp[341] - amp[342] - amp[343] - amp[344] -
      amp[345] - amp[346] - amp[347] + amp[348] + amp[349] + amp[350] +
      amp[351] + amp[352] + amp[353] + amp[354] + amp[355] - amp[356] -
      amp[357] - amp[358] - amp[359] - amp[360] - amp[361] - amp[362] -
      amp[363] + amp[364] + amp[365] + amp[366] + amp[367] + amp[368] +
      amp[369] + amp[370] + amp[371];

  // Sum and square the color flows to get the matrix element
  double matrix = 0;
  for(i = 0;i < ncolor;i++ )
  {
    ztemp = 0.;
    for(j = 0;j < ncolor;j++ )
      ztemp = ztemp + cf[i][j] * jamp[j];
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i];
  }

  // Store the leading color flows for choice of color
  for(i = 0;i < ncolor;i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i]));

  return matrix;
}



