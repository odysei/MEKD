///////////////////////////////////
///  Helper functions useful for///
///  debugging                  ///
///////////////////////////////////
#ifndef MEKD_defaults_cpp
#define MEKD_defaults_cpp

#include "../interface/MEKD.h"

namespace mekd
{

/// 6 4-momenta printout


void MEKD::Set_default_params()
{
	flag.Boost_To_CM = true;
	flag.Debug_Mode = false;
	flag.Fix_Spin0_Production = true;
	flag.Fix_Spin1_Production = false;
// flag.Force_g3_running = false;
	flag.Overwrite_e_and_mu_masses = false;
	flag.per_event_parton_coeffs = false;
	flag.Use_mh_eq_m4l = true;
	flag.Use_mZ4l_eq_m4l = true;
	flag.Use_Higgs_width = true;
	flag.Use_PDF_w_pT0 = false;
	flag.Vary_resonance_width = true;
	flag.Vary_signal_couplings = true;
	flag.Warning_Mode = true;

	// Values have no effect if PDF is used but variables are always used
	// Parton multipliers.
	param.parton_coeff_d = 0;
	param.parton_coeff_u = 1;
	param.parton_coeff_s = 0;
	param.parton_coeff_c = 0;
	param.parton_coeff_b = 0;
	// 	param.GG = 0;	// Assign QCD coupling, force g3 running if needed
	param.sqrt_s = 8000;	// Max energy, collision energy
	
	param.Electron_mass = 0;		// 0.0005109989, for enabled overwriting
	param.Higgs_mass = 125.6;		// Works only if flag.Use_mh_eq_m4l=false
	param.Higgs_width = 5.753088e-03; // Practically not used; for future
	param.Muon_mass = 0;			// 0.10565837, for enabled overwriting
	param.Proton_mass = 0.93827205;	// Always used if needed

	m_Mixing_Coefficients_Spin0[0] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin0[1] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin0[2] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin0[3] = complex<double>(1 / sqrt(4), 0);

	m_Mixing_Coefficients_Spin1[0] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin1[1] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin1[2] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin1[3] = complex<double>(1 / sqrt(4), 0);
	m_Mixing_Coefficients_Spin1[4] = complex<double>(1 / sqrt(2), 0);
	m_Mixing_Coefficients_Spin1[5] = complex<double>(1 / sqrt(2), 0);

	idata.fs = final_2e2mu;
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
	
	param.params_MG_file = parameterFileWithFullPath.fullPath();
	param.PDF_file = pdfFileWithFullPath.fullPath();
#else	
	// parameter card, try standard locations:
	param.params_MG_file = Find_local_file(static_cast<string>("param_card.dat"));
	// PDF/PDT table file:
	param.PDF_file = Find_local_file(static_cast<string>("cteq6l.pdt"));
#endif
}

string MEKD::Find_local_file(const string &input_f)
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
	
	return "MEKD::Find_local_file__file_not_found";
}

/// end of namespace
}

#endif
///////////////////////////////
/// END OF MEKD_debug.cpp   ///
///////////////////////////////