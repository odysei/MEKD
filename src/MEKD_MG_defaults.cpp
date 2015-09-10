///////////////////////////////////
///  Helper functions useful for///
///  debugging                  ///
///////////////////////////////////
#ifndef MEKD_MG_DEFAULTS_cpp
#define MEKD_MG_DEFAULTS_cpp

#include "../interface/MEKD_MG.h"

namespace mekd
{

/// 6 4-momenta printout


void MEKD_MG::Set_Default_MEKD_MG_Parameters()
{
	Boost_To_CM = true;			  // for a boosted data
	Debug_Mode = false;			  // Enable debugging mode
	Fix_Spin0_Production = true;  // use the SM Higgs production mechanism
	Fix_Spin1_Production = false; // use the a hybrid production mechanism
	// 	Force_g3_running = false;	// unused. At some point was included for
	// alpha_QCD
	Overwrite_e_and_mu_masses = false; // switch for manual m_e, m_mu masses
	Use_mh_eq_m4l = true;			   // Set mh to m4l for every event
	Use_mZ4l_eq_m4l = true;			   // Set m_Z to m4l for Z4l events
	Use_Higgs_width = true;			   //	if false, width is fixed to =1
	Use_PDF_w_pT0 =
		false; // Use PDFs in the pT=0 frame. If true, Boost_To_CM is ignored
	Vary_resonance_width = true;  // Allow width to be varied with mass
	Vary_signal_couplings = true; // Allow couplings to change with mass
	Warning_Mode = true;		  // Print warnings

	// Values have no effect if PDF is used but variables are always used
	ContributionCoeff_d = 0;
	ContributionCoeff_u = 1;
	ContributionCoeff_s = 0;
	ContributionCoeff_c = 0;
	// 	GG = 0;	// Assign QCD coupling, force g3 running if needed
	Sqrt_s = 8000; // Max energy, collision energy

	Mixing_Coefficients_Spin0[0] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin0[1] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin0[2] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin0[3] = complex<double>(1 / sqrt(4), 0);

	Mixing_Coefficients_Spin1[0] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin1[1] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin1[2] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin1[3] = complex<double>(1 / sqrt(4), 0);
	Mixing_Coefficients_Spin1[4] = complex<double>(1 / sqrt(2), 0);
	Mixing_Coefficients_Spin1[5] = complex<double>(1 / sqrt(2), 0);

	Electron_mass = 0; // 0.0005109989, for enabled overwriting
	Higgs_mass = 125.6;  // Works only if Use_mh_eq_m4l=false
	Higgs_width = 5.753088e-03; // Practically not used; for future
	Muon_mass = 0;	// 0.10565837, for enabled overwriting
	Proton_mass = 0.93827205; // Always used if needed

	Final_state = "2e2m";		 // Final state, for the moment: 4e, 4mu, 2e2mu
	Resonance_decay_mode = "ZZ"; // default: ZZ. Alternatives: 2l, 2l_s
	Test_Model = "ggSpin0Pm";	// Models: ZZ, DY, Custom, ggSpin0Pm, ggSpin0M,
								 // ggSpin0Ph, qqSpin1P, qqSpin1M, ggSpin2Pm,
								 // ggSpin2Ph, ggSpin2Mh, ggSpin2Pb, qqSpin2Pm,
								 // qqSpin2Ph, qqSpin2Mh, qqSpin2Pb, Spin0Pm,
								 // Spin0M, Spin0Ph, Spin1P, Spin1M, Spin2Pm,
								 // Spin2Ph, Spin2Mh, Spin2Pb

#ifndef MEKD_STANDALONE
	// Relative location where a parameter card is stored:
	string rel_param_path = "ZZMatrixElement/MEKD/src/Cards/param_card.dat";
	// PDF/PDT table file:
	string rel_pdf_path = "ZZMatrixElement/MEKD/src/PDF_tables/cteq6l.pdt";
	edm::FileInPath parameterFileWithFullPath(rel_param_path);
	edm::FileInPath pdfFileWithFullPath(rel_pdf_path);
	
	Parameter_file = parameterFileWithFullPath.fullPath();
	PDF_file = pdfFileWithFullPath.fullPath();
#else	
	// parameter card, try standard locations:
	Parameter_file = Find_local_file(static_cast<string>("param_card.dat"));
	// PDF/PDT table file:
	PDF_file = Find_local_file(static_cast<string>("cteq6l.pdt"));
#endif
}

string MEKD_MG::Find_local_file(string input_f)
{
	vector<string> lookup;
	lookup.reserve(9);
	lookup.push_back("./");
	lookup.push_back("Cards/");
	lookup.push_back("PDF_tables/");
	lookup.push_back("../Cards/");
	lookup.push_back("../PDF_tables/");	// [4]
	lookup.push_back("../src/Cards/");
	lookup.push_back("../src/PDF_tables/");
	lookup.push_back("../../src/Cards/");
	lookup.push_back("../../src/PDF_tables/");
	
	for (auto path: lookup) {
		string file_in_path = path + input_f;
		ifstream ifile(file_in_path.c_str());
		if (ifile) {
			ifile.close();
			return file_in_path;
		}
	}
	
	return "MEKD_MG::Find_local_file__file_not_found";
}

/// end of namespace
}

#endif
//////////////////////////////////
/// END OF MEKD_MG_debug.cpp   ///
//////////////////////////////////