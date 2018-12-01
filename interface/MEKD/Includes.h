#ifndef MEKD__Includes_h
#define MEKD__Includes_h

/// C++ libraries
#include <complex>
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
#include "PDF_tables/pdt.h"
}

/// MEs.
/// ME parameters
#include "MG5_aMCNLO/Commons/Parameters_MEKD.h"
#include "MG5_aMCNLO/HEFTU/src/Parameters_heft_updated_full.h"
#include "MG5_aMCNLO/HiggsPO_UFO/src/Parameters_HiggsPO_UFO.h"
#include "MG5_aMCNLO/Leptophilic_UFO/src/Parameters_Leptophilic_UFO.h"
#include "MG5_aMCNLO/sm-full/src/Parameters_sm_full.h"

#include "MG5_aMCNLO/HEF_UFO_Unitary/Z4l/MEKD_MEs.h"

#include "MG5_aMCNLO/HEF_MEKD/DY/MEKD_MEs.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin1/MEKD_MEs.h"
#include "MG5_aMCNLO/HEF_MEKD/Spin2/MEKD_MEs.h"

/// RAW MG5_aMC ME. For testing purposes only.
// #include "MG5_aMCNLO/RAW/CPPProcess.h"   // ME_RAW

#endif
