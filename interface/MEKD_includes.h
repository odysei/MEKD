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

/// MEKD tools
#include "../src/Extra_code/MEKD_CalcHEP_Extra_functions.h"
#include "../src/Extra_code/MEKD_MG_Boosts.h"
#include "../src/higgs_properties/hggeffective.h"
#include "../src/MG5_aMCNLO/read_slha.h"

/// CMSSW includes
#ifndef MEKD_STANDALONE
#include "FWCore/ParameterSet/interface/FileInPath.h"
#endif

extern "C" {
#include "../src/Extra_code/MEKD_CalcHEP_PDF.h"
#include "../src/PDF_tables/pdt.h"
}

/// MEs.
#include "../src/MG5_aMCNLO/DY/MEKD_MEs_DY.h"
#include "../src/MG5_aMCNLO/Z4l/MEKD_MEs_Z4l.h"
#include "../src/MG5_aMCNLO/ZZ/MEKD_MEs_ZZ.h"

#include "../src/MG5_aMCNLO/Spin0/MEKD_MEs_Spin0.h"
#include "../src/MG5_aMCNLO/Spin1/MEKD_MEs_Spin1.h"
#include "../src/MG5_aMCNLO/Spin2/MEKD_MEs_Spin2.h"

/// RAW MG5_aMC ME. For testing purposes only.
// #include "../src/MG5_aMCNLO/RAW/CPPProcess.h"	// ME_RAW

#endif