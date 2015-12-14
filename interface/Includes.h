#ifndef MEKD_Includes_h
#define MEKD_Includes_h

/// C++ libraries
#include <cstdlib>      // needed?
#include <algorithm>    // for sorting
#include <cmath>
#include <complex>
#include <fstream>      // for checking file location
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/// ROOT includes
#if (defined MEKD_STANDALONE && defined MEKD_with_ROOT) ||                     \
    !defined MEKD_STANDALONE
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TROOT.h"
#include "TString.h"
#include "TTree.h"
#include "TTreeIndex.h"
#endif

/// CMSSW includes
#ifndef MEKD_STANDALONE
#include "FWCore/ParameterSet/interface/FileInPath.h"
#endif

/// MEKD core definitions
#include "Definitions.h"
#include "Inputs.h"

/// MEKD tools
#include "Extra_code/MEKD_CalcHEP_Extra_functions.h"
#include "Extra_code/MEKD_Boosts.h"
#include "higgs_properties/hggeffective.h"
#include "MG5_aMCNLO/Commons/Parameters_MEKD.h"

extern "C" {
#include "Extra_code/MEKD_CalcHEP_PDF.h"
#include "PDF_tables/pdt.h"
}

/// MEs.
#include "MG5_aMCNLO/HEF_UFO_Unitary/Z4l/MEKD_MEs_Z4l.h"
#include "MG5_aMCNLO/HEF_UFO_Unitary/ZZ/MEKD_MEs_ZZ.h"

#include "MG5_aMCNLO/HEF_MEKD/DY/MEKD_MEs_DY.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin0/MEKD_MEs_Spin0.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin1/MEKD_MEs_Spin1.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin2/MEKD_MEs_Spin2.h"

#include "ttbb_all/MEKD_MEs_ttbb_all.h"
#include "ttbb_all/MEKD_MEs_ttbb_all_2.h"

/// RAW MG5_aMC ME. For testing purposes only.
// #include "MG5_aMCNLO/RAW/CPPProcess.h"   // ME_RAW

/// Predefined mixings, i.e., models
#include "Defined_models_Spin0.h"

#endif
