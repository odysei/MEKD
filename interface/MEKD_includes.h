#ifndef MEKD_INCLUDES_h
#define MEKD_INCLUDES_h

/// C++ libraries
#include <algorithm> // for sorting
#include <cmath>
#include <complex>
#include <fstream>	// for checking file location
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/// MEKD core definitions
#include "MEKD_defs.h"
#include "MEKD_inputs.h"

/// MEKD tools
#include "../src/Extra_code/MEKD_CalcHEP_Extra_functions.h"
#include "../src/Extra_code/MEKD_Boosts.h"
#include "../src/higgs_properties/hggeffective.h"
#include "../src/MG5_aMCNLO/Commons/Parameters_MEKD.h"

/// CMSSW includes
#ifndef MEKD_STANDALONE
#include "FWCore/ParameterSet/interface/FileInPath.h"
#endif

extern "C" {
#include "../src/Extra_code/MEKD_CalcHEP_PDF.h"
#include "../src/PDF_tables/pdt.h"
}

/// MEs.
#include "../src/MG5_aMCNLO/HEF_UFO_Unitary/Z4l/MEKD_MEs_Z4l.h"
#include "../src/MG5_aMCNLO/HEF_UFO_Unitary/ZZ/MEKD_MEs_ZZ.h"

#include "../src/MG5_aMCNLO/HEF_MEKD/DY/MEKD_MEs_DY.h"
#include "../src/MG5_aMCNLO/HEF_MEKD/Spin0/MEKD_MEs_Spin0.h"
#include "../src/MG5_aMCNLO/HEF_MEKD/Spin1/MEKD_MEs_Spin1.h"
#include "../src/MG5_aMCNLO/HEF_MEKD/Spin2/MEKD_MEs_Spin2.h"

#include "ttbb_all/MEKD_MEs_ttbb_all.h"

/// RAW MG5_aMC ME. For testing purposes only.
// #include "../src/MG5_aMCNLO/RAW/CPPProcess.h"	// ME_RAW

#endif
