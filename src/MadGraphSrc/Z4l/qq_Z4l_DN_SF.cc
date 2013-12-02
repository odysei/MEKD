//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 1.5.3, 2012-11-01
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "qq_Z4l_DN_SF.h"
#include "../HelAmps_HEF_UFO_bkg.h"
#include "../read_slha.h"

using namespace MG5_HEF_UFO_bkg;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: s s~ > mu- mu+ mu- mu+ / h xg WEIGHTED=8

//--------------------------------------------------------------------------
// Initialize process.

void qq_Z4l_DN_SF::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_HEF_MEKD::getInstance(); 
  SLHAReader slha(param_card_name); 
  pars->setIndependentParameters(slha); 
  pars->setIndependentCouplings(); 
  // Set external particle masses for this matrix element
  mME.push_back(pars->MS); 
  mME.push_back(pars->MS); 
  mME.push_back(pars->MM); 
  mME.push_back(pars->MM); 
  mME.push_back(pars->MM); 
  mME.push_back(pars->MM); 
  jamp2[0] = new double[1]; 
}

//--------------------------------------------------------------------------
// Update process.

void qq_Z4l_DN_SF::updateProc(SLHAReader slha) 
{
  pars->setIndependentParameters(slha); 
  pars->setIndependentCouplings(); 
  
  // Set external particle masses for this matrix element
  mME[0]=(pars->MS);
  mME[1]=(pars->MS);
  mME[2]=(pars->MM);
  mME[3]=(pars->MM);
  mME[4]=(pars->MM);
  mME[5]=(pars->MM);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void qq_Z4l_DN_SF::sigmaKin_BKG() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(); 
  pars->setDependentCouplings();
    
  // Reset color flows
  for(int i = 0; i < 1; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 64; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
//   std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1, -1}, {-1, -1, -1, -1, 1, 1},
      {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1, 1}, {-1, -1, -1, 1, 1, -1},
      {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, -1, 1},
      {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, 1}, {-1, -1, 1, 1, -1, -1},
      {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1}, {-1,
      1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1, 1}, {-1, 1,
      -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1, 1, -1, 1, 1}, {-1, 1, 1, 1,
      -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1},
      {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, 1, -1},
      {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1}, {1,
      -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, -1, -1}, {1, -1,
      1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, 1}, {1, -1, 1, 1,
      -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1},
      {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, 1}, {1, 1, -1, -1, 1, -1}, {1,
      1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1}, {1, 1, -1,
      1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1, 1, -1, -1, -1}, {1, 1, 1, -1, -1,
      1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, 1}, {1, 1, 1, 1, -1, -1}, {1,
      1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1}, {1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {144, 144}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
  }
  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions_BKG(perm, helicities[ihel]); 
        t[0] = matrix_ssx_mummupmummup_no_hxg(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions_BKG(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_ssx_mummupmummup_no_hxg(); 
        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
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
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions_BKG(perm, helicities[ihel]); 
      t[0] = matrix_ssx_mummupmummup_no_hxg(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions_BKG(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_ssx_mummupmummup_no_hxg(); 
      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 

}

void qq_Z4l_DN_SF::sigmaKin_SIG() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(); 
  pars->setDependentCouplings();
    
  // Reset color flows
  for(int i = 0; i < 1; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 64; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
//   std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1, -1}, {-1, -1, -1, -1, 1, 1},
      {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1, 1}, {-1, -1, -1, 1, 1, -1},
      {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, -1, 1},
      {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, 1}, {-1, -1, 1, 1, -1, -1},
      {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1}, {-1,
      1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1, 1}, {-1, 1,
      -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1, 1, -1, 1, 1}, {-1, 1, 1, 1,
      -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1},
      {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, 1, -1},
      {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1}, {1,
      -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, -1, -1}, {1, -1,
      1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, 1}, {1, -1, 1, 1,
      -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1},
      {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, 1}, {1, 1, -1, -1, 1, -1}, {1,
      1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1}, {1, 1, -1,
      1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1, 1, -1, -1, -1}, {1, 1, 1, -1, -1,
      1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, 1}, {1, 1, 1, 1, -1, -1}, {1,
      1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1}, {1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {144, 144}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
  }
  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions_SIG(perm, helicities[ihel]); 
        t[0] = matrix_ssx_mummupmummup_no_hxg(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions_SIG(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_ssx_mummupmummup_no_hxg(); 
        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
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
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions_SIG(perm, helicities[ihel]); 
      t[0] = matrix_ssx_mummupmummup_no_hxg(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions_SIG(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_ssx_mummupmummup_no_hxg(); 
      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 

}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double qq_Z4l_DN_SF::sigmaHat() 
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

void qq_Z4l_DN_SF::calculate_wavefunctions_BKG(const int perm[], const int hel[])
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
  FFV41_3(w[0], w[1], pars->GC_1, pars->ZERO, pars->ZERO, w[6]); 
  FFV41_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[7]); 
  FFV41_1(w[4], w[6], pars->GC_3, pars->MM, pars->ZERO, w[8]); 
  FFV41_2(w[5], w[6], pars->GC_3, pars->MM, pars->ZERO, w[9]); 
  FFV42_44_3(w[3], w[2], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[10]);
//   FFV42_43_3(w[0], w[1], pars->GC_109, pars->GC_115, pars->MZ, pars->WZ,
//       w[11]);
//   FFV42_44_1(w[4], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
//       w[12]);
//   FFV42_44_2(w[5], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
//       w[13]);
  FFV41_3(w[5], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[14]); 
  FFV41_2(w[3], w[6], pars->GC_3, pars->MM, pars->ZERO, w[15]); 
  FFV42_44_3(w[5], w[2], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[16]);
//   FFV42_44_2(w[3], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
//       w[17]);
  FFV41_3(w[3], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[18]); 
  FFV41_1(w[2], w[6], pars->GC_3, pars->MM, pars->ZERO, w[19]); 
  FFV42_44_3(w[3], w[4], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[20]);
//   FFV42_44_1(w[2], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
//       w[21]);
  FFV41_3(w[5], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[22]); 
  FFV42_44_3(w[5], w[4], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[23]);
  FFV41_2(w[0], w[7], pars->GC_1, pars->MS, pars->ZERO, w[24]); 
  FFV41_2(w[0], w[22], pars->GC_1, pars->MS, pars->ZERO, w[25]); 
  FFV42_43_2(w[0], w[23], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
      w[26]);
  FFV42_43_2(w[0], w[10], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
      w[27]);
  FFV41_2(w[0], w[14], pars->GC_1, pars->MS, pars->ZERO, w[28]); 
  FFV41_2(w[0], w[18], pars->GC_1, pars->MS, pars->ZERO, w[29]); 
  FFV42_43_2(w[0], w[20], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
      w[30]);
  FFV42_43_2(w[0], w[16], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
      w[31]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
	for( unsigned int count=0; count<47; count++ ) amp[count] = 0;
  FFV41_0(w[5], w[8], w[7], pars->GC_3, amp[0]); 
  FFV41_0(w[9], w[4], w[7], pars->GC_3, amp[1]); 
  FFV42_44_0(w[5], w[8], w[10], pars->GC_109, pars->GC_116, amp[2]); 
  FFV42_44_0(w[9], w[4], w[10], pars->GC_109, pars->GC_116, amp[3]); 
//   FFV41_0(w[5], w[12], w[7], pars->GC_3, amp[4]); 
//   FFV41_0(w[13], w[4], w[7], pars->GC_3, amp[5]); 
//   FFV42_44_0(w[5], w[12], w[10], pars->GC_109, pars->GC_116, amp[6]); 
//   FFV42_44_0(w[13], w[4], w[10], pars->GC_109, pars->GC_116, amp[7]); 
  FFV41_0(w[15], w[4], w[14], pars->GC_3, amp[8]); 
  FFV41_0(w[3], w[8], w[14], pars->GC_3, amp[9]); 
  FFV42_44_0(w[15], w[4], w[16], pars->GC_109, pars->GC_116, amp[10]); 
  FFV42_44_0(w[3], w[8], w[16], pars->GC_109, pars->GC_116, amp[11]); 
//   FFV41_0(w[17], w[4], w[14], pars->GC_3, amp[12]); 
//   FFV41_0(w[3], w[12], w[14], pars->GC_3, amp[13]); 
//   FFV42_44_0(w[17], w[4], w[16], pars->GC_109, pars->GC_116, amp[14]); 
//   FFV42_44_0(w[3], w[12], w[16], pars->GC_109, pars->GC_116, amp[15]); 
  FFV41_0(w[5], w[19], w[18], pars->GC_3, amp[16]); 
  FFV41_0(w[9], w[2], w[18], pars->GC_3, amp[17]); 
  FFV42_44_0(w[5], w[19], w[20], pars->GC_109, pars->GC_116, amp[18]); 
  FFV42_44_0(w[9], w[2], w[20], pars->GC_109, pars->GC_116, amp[19]); 
//   FFV41_0(w[5], w[21], w[18], pars->GC_3, amp[20]); 
//   FFV41_0(w[13], w[2], w[18], pars->GC_3, amp[21]); 
//   FFV42_44_0(w[5], w[21], w[20], pars->GC_109, pars->GC_116, amp[22]); 
//   FFV42_44_0(w[13], w[2], w[20], pars->GC_109, pars->GC_116, amp[23]); 
  FFV41_0(w[3], w[19], w[22], pars->GC_3, amp[24]); 
  FFV41_0(w[15], w[2], w[22], pars->GC_3, amp[25]); 
  FFV42_44_0(w[3], w[19], w[23], pars->GC_109, pars->GC_116, amp[26]); 
  FFV42_44_0(w[15], w[2], w[23], pars->GC_109, pars->GC_116, amp[27]); 
//   FFV41_0(w[3], w[21], w[22], pars->GC_3, amp[28]); 
//   FFV41_0(w[17], w[2], w[22], pars->GC_3, amp[29]); 
//   FFV42_44_0(w[3], w[21], w[23], pars->GC_109, pars->GC_116, amp[30]); 
//   FFV42_44_0(w[17], w[2], w[23], pars->GC_109, pars->GC_116, amp[31]); 
  FFV41_0(w[24], w[1], w[22], pars->GC_1, amp[32]); 
  FFV41_0(w[25], w[1], w[7], pars->GC_1, amp[33]); 
  FFV42_43_0(w[24], w[1], w[23], pars->GC_109, pars->GC_115, amp[34]); 
  FFV41_0(w[26], w[1], w[7], pars->GC_1, amp[35]); 
  FFV41_0(w[27], w[1], w[22], pars->GC_1, amp[36]); 
  FFV42_43_0(w[25], w[1], w[10], pars->GC_109, pars->GC_115, amp[37]); 
  FFV42_43_0(w[27], w[1], w[23], pars->GC_109, pars->GC_115, amp[38]); 
  FFV42_43_0(w[26], w[1], w[10], pars->GC_109, pars->GC_115, amp[39]); 
  FFV41_0(w[28], w[1], w[18], pars->GC_1, amp[40]); 
  FFV41_0(w[29], w[1], w[14], pars->GC_1, amp[41]); 
  FFV42_43_0(w[28], w[1], w[20], pars->GC_109, pars->GC_115, amp[42]); 
  FFV41_0(w[30], w[1], w[14], pars->GC_1, amp[43]); 
  FFV41_0(w[31], w[1], w[18], pars->GC_1, amp[44]); 
  FFV42_43_0(w[29], w[1], w[16], pars->GC_109, pars->GC_115, amp[45]); 
  FFV42_43_0(w[31], w[1], w[20], pars->GC_109, pars->GC_115, amp[46]); 
  FFV42_43_0(w[30], w[1], w[16], pars->GC_109, pars->GC_115, amp[47]); 

}

void qq_Z4l_DN_SF::calculate_wavefunctions_SIG(const int perm[], const int hel[])
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
//   FFV41_3(w[0], w[1], pars->GC_1, pars->ZERO, pars->ZERO, w[6]); 
  FFV41_3(w[3], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[7]); 
//   FFV41_1(w[4], w[6], pars->GC_3, pars->MM, pars->ZERO, w[8]); 
//   FFV41_2(w[5], w[6], pars->GC_3, pars->MM, pars->ZERO, w[9]); 
  FFV42_44_3(w[3], w[2], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[10]);
  FFV42_43_3(w[0], w[1], pars->GC_109, pars->GC_115, pars->MZ, pars->WZ,
      w[11]);
  FFV42_44_1(w[4], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
      w[12]);
  FFV42_44_2(w[5], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
      w[13]);
  FFV41_3(w[5], w[2], pars->GC_3, pars->ZERO, pars->ZERO, w[14]); 
//   FFV41_2(w[3], w[6], pars->GC_3, pars->MM, pars->ZERO, w[15]); 
  FFV42_44_3(w[5], w[2], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[16]);
  FFV42_44_2(w[3], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
      w[17]);
  FFV41_3(w[3], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[18]); 
  FFV41_1(w[2], w[6], pars->GC_3, pars->MM, pars->ZERO, w[19]); 
  FFV42_44_3(w[3], w[4], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[20]);
  FFV42_44_1(w[2], w[11], pars->GC_109, pars->GC_116, pars->MM, pars->ZERO,
      w[21]);
  FFV41_3(w[5], w[4], pars->GC_3, pars->ZERO, pars->ZERO, w[22]); 
  FFV42_44_3(w[5], w[4], pars->GC_109, pars->GC_116, pars->MZ, pars->WZ,
      w[23]);
//   FFV41_2(w[0], w[7], pars->GC_1, pars->MS, pars->ZERO, w[24]); 
//   FFV41_2(w[0], w[22], pars->GC_1, pars->MS, pars->ZERO, w[25]); 
//   FFV42_43_2(w[0], w[23], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
//       w[26]);
//   FFV42_43_2(w[0], w[10], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
//       w[27]);
//   FFV41_2(w[0], w[14], pars->GC_1, pars->MS, pars->ZERO, w[28]); 
//   FFV41_2(w[0], w[18], pars->GC_1, pars->MS, pars->ZERO, w[29]); 
//   FFV42_43_2(w[0], w[20], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
//       w[30]);
//   FFV42_43_2(w[0], w[16], pars->GC_109, pars->GC_115, pars->MS, pars->ZERO,
//       w[31]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
	for( unsigned int count=0; count<47; count++ ) amp[count] = 0;
//   FFV41_0(w[5], w[8], w[7], pars->GC_3, amp[0]); 
//   FFV41_0(w[9], w[4], w[7], pars->GC_3, amp[1]); 
//   FFV42_44_0(w[5], w[8], w[10], pars->GC_109, pars->GC_116, amp[2]); 
//   FFV42_44_0(w[9], w[4], w[10], pars->GC_109, pars->GC_116, amp[3]); 
  FFV41_0(w[5], w[12], w[7], pars->GC_3, amp[4]); 
  FFV41_0(w[13], w[4], w[7], pars->GC_3, amp[5]); 
  FFV42_44_0(w[5], w[12], w[10], pars->GC_109, pars->GC_116, amp[6]); 
  FFV42_44_0(w[13], w[4], w[10], pars->GC_109, pars->GC_116, amp[7]); 
//   FFV41_0(w[15], w[4], w[14], pars->GC_3, amp[8]); 
//   FFV41_0(w[3], w[8], w[14], pars->GC_3, amp[9]); 
//   FFV42_44_0(w[15], w[4], w[16], pars->GC_109, pars->GC_116, amp[10]); 
//   FFV42_44_0(w[3], w[8], w[16], pars->GC_109, pars->GC_116, amp[11]); 
  FFV41_0(w[17], w[4], w[14], pars->GC_3, amp[12]); 
  FFV41_0(w[3], w[12], w[14], pars->GC_3, amp[13]); 
  FFV42_44_0(w[17], w[4], w[16], pars->GC_109, pars->GC_116, amp[14]); 
  FFV42_44_0(w[3], w[12], w[16], pars->GC_109, pars->GC_116, amp[15]); 
//   FFV41_0(w[5], w[19], w[18], pars->GC_3, amp[16]); 
//   FFV41_0(w[9], w[2], w[18], pars->GC_3, amp[17]); 
//   FFV42_44_0(w[5], w[19], w[20], pars->GC_109, pars->GC_116, amp[18]); 
//   FFV42_44_0(w[9], w[2], w[20], pars->GC_109, pars->GC_116, amp[19]); 
  FFV41_0(w[5], w[21], w[18], pars->GC_3, amp[20]); 
  FFV41_0(w[13], w[2], w[18], pars->GC_3, amp[21]); 
  FFV42_44_0(w[5], w[21], w[20], pars->GC_109, pars->GC_116, amp[22]); 
  FFV42_44_0(w[13], w[2], w[20], pars->GC_109, pars->GC_116, amp[23]); 
//   FFV41_0(w[3], w[19], w[22], pars->GC_3, amp[24]); 
//   FFV41_0(w[15], w[2], w[22], pars->GC_3, amp[25]); 
//   FFV42_44_0(w[3], w[19], w[23], pars->GC_109, pars->GC_116, amp[26]); 
//   FFV42_44_0(w[15], w[2], w[23], pars->GC_109, pars->GC_116, amp[27]); 
  FFV41_0(w[3], w[21], w[22], pars->GC_3, amp[28]); 
  FFV41_0(w[17], w[2], w[22], pars->GC_3, amp[29]); 
  FFV42_44_0(w[3], w[21], w[23], pars->GC_109, pars->GC_116, amp[30]); 
  FFV42_44_0(w[17], w[2], w[23], pars->GC_109, pars->GC_116, amp[31]); 
//   FFV41_0(w[24], w[1], w[22], pars->GC_1, amp[32]); 
//   FFV41_0(w[25], w[1], w[7], pars->GC_1, amp[33]); 
//   FFV42_43_0(w[24], w[1], w[23], pars->GC_109, pars->GC_115, amp[34]); 
//   FFV41_0(w[26], w[1], w[7], pars->GC_1, amp[35]); 
//   FFV41_0(w[27], w[1], w[22], pars->GC_1, amp[36]); 
//   FFV42_43_0(w[25], w[1], w[10], pars->GC_109, pars->GC_115, amp[37]); 
//   FFV42_43_0(w[27], w[1], w[23], pars->GC_109, pars->GC_115, amp[38]); 
//   FFV42_43_0(w[26], w[1], w[10], pars->GC_109, pars->GC_115, amp[39]); 
//   FFV41_0(w[28], w[1], w[18], pars->GC_1, amp[40]); 
//   FFV41_0(w[29], w[1], w[14], pars->GC_1, amp[41]); 
//   FFV42_43_0(w[28], w[1], w[20], pars->GC_109, pars->GC_115, amp[42]); 
//   FFV41_0(w[30], w[1], w[14], pars->GC_1, amp[43]); 
//   FFV41_0(w[31], w[1], w[18], pars->GC_1, amp[44]); 
//   FFV42_43_0(w[29], w[1], w[16], pars->GC_109, pars->GC_115, amp[45]); 
//   FFV42_43_0(w[31], w[1], w[20], pars->GC_109, pars->GC_115, amp[46]); 
//   FFV42_43_0(w[30], w[1], w[16], pars->GC_109, pars->GC_115, amp[47]); 

}

double qq_Z4l_DN_SF::matrix_ssx_mummupmummup_no_hxg() 
{
  int i, j; 
  // Local variables
//   const int ngraphs = 48; 
  const int ncolor = 1; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {1}; 
  static const double cf[ncolor][ncolor] = {{3}}; 

  // Calculate color flows
  jamp[0] = +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] + amp[6] +
      amp[7] - amp[8] - amp[9] - amp[10] - amp[11] - amp[12] - amp[13] -
      amp[14] - amp[15] - amp[16] - amp[17] - amp[18] - amp[19] - amp[20] -
      amp[21] - amp[22] - amp[23] + amp[24] + amp[25] + amp[26] + amp[27] +
      amp[28] + amp[29] + amp[30] + amp[31] + amp[32] + amp[33] + amp[34] +
      amp[35] + amp[36] + amp[37] + amp[38] + amp[39] - amp[40] - amp[41] -
      amp[42] - amp[43] - amp[44] - amp[45] - amp[46] - amp[47];

  // Sum and square the color flows to get the matrix element
  double matrix = 0; 
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.; 
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j]; 
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i]; 
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i])); 

  return matrix; 
}



