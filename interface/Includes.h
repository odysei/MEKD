#ifndef MEKD_Includes_h
#define MEKD_Includes_h

/// C++ libraries
#include <cstdlib>   // needed?
#include <algorithm> // for sorting
#include <cmath>
#include <complex>
#include <fstream> // for checking file location
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
extern "C" {
#include "Extra_code/MEKD_CalcHEP_PDF.h"
#include "PDF_tables/pdt.h"
}

/// MEs.
/// ME parameters
#include "MG5_aMCNLO/Commons/Parameters_MEKD.h"
#include "MG5_aMCNLO/HEFTU/src/Parameters_heft_updated_full.h"
#include "MG5_aMCNLO/HiggsPO_UFO/src/Parameters_HiggsPO_UFO.h"
#include "MG5_aMCNLO/sm-full/src/Parameters_sm_full.h"

#include "MG5_aMCNLO/HEF_UFO_Unitary/Z4l/MEKD_MEs.h"
#include "MG5_aMCNLO/HEF_UFO_Unitary/ZZ/MEKD_MEs.h"

#include "MG5_aMCNLO/HEF_MEKD/DY/MEKD_MEs.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin1/MEKD_MEs.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin2/MEKD_MEs.h"

/// RAW MG5_aMC ME. For testing purposes only.
// #include "MG5_aMCNLO/RAW/CPPProcess.h"   // ME_RAW

/// Predefined mixings, i.e., models
#include "Defined_models_Spin0.h"

#endif
