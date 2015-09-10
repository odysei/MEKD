#ifndef MEKD_MG_cpp
#define MEKD_MG_cpp

#include "../interface/MEKD_MG.h"

using namespace std;

namespace mekd
{

// p_set(7, new double[4]), => some problems ???
MEKD_MG::MEKD_MG()
{
	Mixing_Coefficients_Spin0 = new complex<double>[4];
	Mixing_Coefficients_Spin0_internal = new complex<double>[4];
	Mixing_Coefficients_Spin1 = new complex<double>[8];
	Mixing_Coefficients_Spin1_internal = new complex<double>[8];
	Mixing_Coefficients_Spin2 = new complex<double>[20];
	Mixing_Coefficients_Spin2_internal = new complex<double>[20];

	Set_Default_MEKD_MG_Parameters();

	Check_MEs();

	p_set.reserve(7);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]);
	p_set.push_back(new double[4]); // a photon comes here, otherwise, unused

	p1 = new double[4];
	p2 = new double[4];
	p3 = new double[4];
	p4 = new double[4];
	p5 = new double[4];

	id1 = 10000;
	id2 = 10000;
	id3 = 10000;
	id4 = 10000;
	id5 = 10000;

	id_set.reserve(5);
	id_set.push_back(id1);
	id_set.push_back(id2);
	id_set.push_back(id3);
	id_set.push_back(id4);
	id_set.push_back(id5);

	pl1_internal = NULL;
	pl2_internal = NULL;
	pl3_internal = NULL;
	pl4_internal = NULL;
	pA1_internal = NULL;

	Parameters_Are_Loaded = false;
	Predefined_Model = false;
}

MEKD_MG::~MEKD_MG()
{
	delete Mixing_Coefficients_Spin0;
	delete Mixing_Coefficients_Spin0_internal;
	delete Mixing_Coefficients_Spin1;
	delete Mixing_Coefficients_Spin1_internal;
	delete Mixing_Coefficients_Spin2;
	delete Mixing_Coefficients_Spin2_internal;

	if (Parameters_Are_Loaded)
		Unload_pdfreader();

	p_set.clear();
	id_set.clear();
}

int MEKD_MG::Load_Parameters()
{
	Set_Of_Model_Parameters.read_slha_file(static_cast<string>(Parameter_file));
	
	/// Initializing parameters
	if (!Parameters_Are_Loaded)
		Load_Parameters_MEs();	// init MEs
	Load_Parameters_extract_params(Set_Of_Model_Parameters);
	Load_Parameters_eval_params();
	
	if (Parameters_Are_Loaded)
		Unload_pdfreader();
	Load_pdfreader(const_cast<char *>(PDF_file.c_str()));

	Parameters_Are_Loaded = true;
	return 0;
}

int MEKD_MG::Reload_Parameters()
{
	if (!Parameters_Are_Loaded)
		return 1;

	return Load_Parameters();
}

int MEKD_MG::Run_MEKD_MG()
{
	if (!Parameters_Are_Loaded)
		Load_Parameters();
	if (Arrange_Internal_pls() == 1) {	// loads&arranges plX_internal
		cerr << "Particle id error. Exiting.\n";
		exit(1);
	}

	double CollisionE;

	PDFx1 = 0;
	PDFx2 = 0;
	Background_ME = 0;
	Signal_ME = 0;

	if (Overwrite_e_and_mu_masses) {
		Set_Of_Model_Parameters.set_block_entry("mass", 11, Electron_mass);
		Set_Of_Model_Parameters.set_block_entry("mass", 13, Muon_mass);
		params_m_e = Electron_mass;
		params_m_mu = Muon_mass;
	}

	if (Final_state == "4e" || Final_state == "4eA") {
		ml1 = Set_Of_Model_Parameters.get_block_entry("mass", 11, Electron_mass)
				  .real();
		ml2 = ml1;
		ml3 = ml1;
		ml4 = ml1;
	}
	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		ml1 = Set_Of_Model_Parameters.get_block_entry("mass", 13, Muon_mass)
				  .real();
		ml2 = ml1;
		ml3 = ml1;
		ml4 = ml1;
	}
	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		ml1 = Set_Of_Model_Parameters.get_block_entry("mass", 11, Electron_mass)
				  .real();
		ml2 = ml1;
		ml3 = Set_Of_Model_Parameters.get_block_entry("mass", 13, Muon_mass)
				  .real();
		ml4 = ml3;
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		ml1 = Set_Of_Model_Parameters.get_block_entry("mass", 13, Muon_mass)
				  .real();
		ml2 = ml1;
		ml3 = 0;
		ml4 = 0;
	}

	Load_p_set();
	
	/// Calculate values needed for the PDF in the pT=0 frame
	if (Use_PDF_w_pT0) {
		Boost_5p_2_pT0(ml1, p_set[2], ml2, p_set[3], ml3, p_set[4], ml4,
					   p_set[5], 0, p_set[6]);
	}
	
	PDFx1 = Get_PDF_x1(p_set);
	PDFx2 = Get_PDF_x2(p_set);
	if (Debug_Mode) {
		printf("Coefficients for PDF (x1, x2): (%.10E, %.10E)\n",
			   PDFx1, PDFx2);
	}

	/// If flag is true, boost to CM frame iff PDF is NOT included.
	if (Boost_To_CM && !Use_PDF_w_pT0) {
		Boost2CM(ml1, p_set[2], ml2, p_set[3], ml3, p_set[4], ml4, p_set[5], 0,
				 p_set[6]);
		CollisionE =
			p_set[2][0] + p_set[3][0] + p_set[4][0] + p_set[5][0] + p_set[6][0];
		p_set[0][0] = CollisionE / 2;
		p_set[1][0] = CollisionE / 2;
	} else {
		Approx_neg_z_parton(p_set[0], PDFx1 * Sqrt_s);
		Approx_pos_z_parton(p_set[1], PDFx2 * Sqrt_s);
	}

	int range[2] = {2, 6}; 
	invariant_m = Get_invariant_m(p_set, range);
	Mass_4l = invariant_m;

	/// Pick quark flavors to use if PDFs are not set. Normalizing coefficients
	/// here.
	if (!Use_PDF_w_pT0) {
		double buffer_ = (ContributionCoeff_d + ContributionCoeff_u +
						  ContributionCoeff_s + ContributionCoeff_c);
		ContributionCoeff_d = ContributionCoeff_d / buffer_;
		ContributionCoeff_u = ContributionCoeff_u / buffer_;
		ContributionCoeff_c = ContributionCoeff_c / buffer_;
		ContributionCoeff_s = ContributionCoeff_s / buffer_;
	}
	
	if (Debug_Mode) {
		cout << "4-momenta entering ME(E px py px):\n";
		Print_4momenta(p_set);
	}

	/// Background is interesting in any case, except for the Signal Runs or '!'
	/// is indicated in the first model to save CPU
	if (Test_Model[0] != '!' && Test_Models.size() == 0) {
		Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
		Background_ME = Signal_ME;
	} else if (Test_Models.size() > 0) {
		if (Test_Models[0][0] != '!') {
			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
			Background_ME = Signal_ME;
		}
	}

	/// Signal ME(s) is(are) chosen here
	if (Test_Models.size() > 0 && Test_Model[0] != '!') {
		Signal_MEs.clear();
		Test_Model_buffer = &(Test_Models[0]); // Should be NULL or undefined
											   // before this point; works as
											   // counter=0
	} else
		Test_Model_buffer =
			&Test_Model; // Should be NULL or undefined before this point

	counter = 1;
	while (Test_Model_buffer != NULL) {
		// Is it a parameter card defined?
		if ((*Test_Model_buffer) == "Custom" ||
			(*Test_Model_buffer) == "!Custom")
			Run_MEKD_MG_ME_Configurator_Custom();

		// Is it a "background"?
		else if ((*Test_Model_buffer) == "qqZZ" ||
				 (*Test_Model_buffer) == "!qqZZ")
			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
		else if ((*Test_Model_buffer) == "ZZ" || (*Test_Model_buffer) == "!ZZ")
			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");

		else if ((*Test_Model_buffer) == "qqDY" ||
				 (*Test_Model_buffer) == "!qqDY")
			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
		else if ((*Test_Model_buffer) == "DY" || (*Test_Model_buffer) == "!DY")
			Run_MEKD_MG_ME_Configurator_BKG_ZZ("NO");

		// Is it a Z boson resonance?
		else if ((*Test_Model_buffer) == "qqZ4l_Background" ||
				 (*Test_Model_buffer) == "!qqZ4l_Background")
			Run_MEKD_MG_ME_Configurator_Z4l_BKG("qq");
		else if ((*Test_Model_buffer) == "qqZ4l_Signal" ||
				 (*Test_Model_buffer) == "!qqZ4l_Signal")
			Run_MEKD_MG_ME_Configurator_Z4l_SIG("qq");

		/// Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
		/// Final states: 4 leptons (+photon) also 2 muons (+photon)
		Resonance_decay_mode = "ZZ";

		// Is it a spin-0 resonance?
		if ((*Test_Model_buffer) == "ggSpin0Pm" ||
			(*Test_Model_buffer) == "!ggSpin0Pm") // SM Higgs
			Run_MEKD_MG_ME_Configurator_Spin0Pm("gg");
		else if ((*Test_Model_buffer) == "Spin0Pm" ||
				 (*Test_Model_buffer) == "!Spin0Pm")
			Run_MEKD_MG_ME_Configurator_Spin0Pm("NO");

		else if ((*Test_Model_buffer) == "ggSpin0M" ||
				 (*Test_Model_buffer) == "!ggSpin0M")
			Run_MEKD_MG_ME_Configurator_Spin0M("gg");
		else if ((*Test_Model_buffer) == "Spin0M" ||
				 (*Test_Model_buffer) == "!Spin0M")
			Run_MEKD_MG_ME_Configurator_Spin0M("NO");

		else if ((*Test_Model_buffer) == "ggSpin0Ph" ||
				 (*Test_Model_buffer) == "!ggSpin0Ph")
			Run_MEKD_MG_ME_Configurator_Spin0Ph("gg");
		else if ((*Test_Model_buffer) == "Spin0Ph" ||
				 (*Test_Model_buffer) == "!Spin0Ph")
			Run_MEKD_MG_ME_Configurator_Spin0Ph("NO");

		else if ((*Test_Model_buffer) == "ggSpin0" ||
				 (*Test_Model_buffer) == "!ggSpin0")
			Run_MEKD_MG_ME_Configurator_Spin0("gg");
		else if ((*Test_Model_buffer) == "Spin0" ||
				 (*Test_Model_buffer) == "!Spin0")
			Run_MEKD_MG_ME_Configurator_Spin0("NO");

		// Is it a spin-1 resonance?
		else if ((*Test_Model_buffer) == "qqSpin1M" ||
				 (*Test_Model_buffer) == "!qqSpin1M")
			Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		else if ((*Test_Model_buffer) == "Spin1M" ||
				 (*Test_Model_buffer) == "!Spin1M")
			Run_MEKD_MG_ME_Configurator_Spin1M("NO");

		else if ((*Test_Model_buffer) == "qqSpin1P" ||
				 (*Test_Model_buffer) == "!qqSpin1P")
			Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		else if ((*Test_Model_buffer) == "Spin1P" ||
				 (*Test_Model_buffer) == "!Spin1P")
			Run_MEKD_MG_ME_Configurator_Spin1P("NO");

		else if ((*Test_Model_buffer) == "qqSpin1" ||
				 (*Test_Model_buffer) == "!qqSpin1")
			Run_MEKD_MG_ME_Configurator_Spin1("qq");
		else if ((*Test_Model_buffer) == "Spin1" ||
				 (*Test_Model_buffer) == "!Spin1")
			Run_MEKD_MG_ME_Configurator_Spin1("NO");

		// Is it a spin-2 resonance?
		else if ((*Test_Model_buffer) == "ggSpin2Pm" ||
				 (*Test_Model_buffer) == "!ggSpin2Pm")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Pm" ||
				 (*Test_Model_buffer) == "!qqSpin2Pm")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		else if ((*Test_Model_buffer) == "Spin2Pm" ||
				 (*Test_Model_buffer) == "!Spin2Pm")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Ph" ||
				 (*Test_Model_buffer) == "!ggSpin2Ph")
			Run_MEKD_MG_ME_Configurator_Spin2Ph("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Ph" ||
				 (*Test_Model_buffer) == "!qqSpin2Ph")
			Run_MEKD_MG_ME_Configurator_Spin2Ph("qq");
		else if ((*Test_Model_buffer) == "Spin2Ph" ||
				 (*Test_Model_buffer) == "!Spin2Ph")
			Run_MEKD_MG_ME_Configurator_Spin2Ph("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Mh" ||
				 (*Test_Model_buffer) == "!ggSpin2Mh")
			Run_MEKD_MG_ME_Configurator_Spin2Mh("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Mh" ||
				 (*Test_Model_buffer) == "!qqSpin2Mh")
			Run_MEKD_MG_ME_Configurator_Spin2Mh("qq");
		else if ((*Test_Model_buffer) == "Spin2Mh" ||
				 (*Test_Model_buffer) == "!Spin2Mh")
			Run_MEKD_MG_ME_Configurator_Spin2Mh("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Pb" ||
				 (*Test_Model_buffer) == "!ggSpin2Pb")
			Run_MEKD_MG_ME_Configurator_Spin2Pb("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Pb" ||
				 (*Test_Model_buffer) == "!qqSpin2Pb")
			Run_MEKD_MG_ME_Configurator_Spin2Pb("qq");
		else if ((*Test_Model_buffer) == "Spin2Pb" ||
				 (*Test_Model_buffer) == "!Spin2Pb")
			Run_MEKD_MG_ME_Configurator_Spin2Pb("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Ph2" ||
				 (*Test_Model_buffer) == "!ggSpin2Ph2")
			Run_MEKD_MG_ME_Configurator_Spin2Ph2("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Ph2" ||
				 (*Test_Model_buffer) == "!qqSpin2Ph2")
			Run_MEKD_MG_ME_Configurator_Spin2Ph2("qq");
		else if ((*Test_Model_buffer) == "Spin2Ph2" ||
				 (*Test_Model_buffer) == "!Spin2Ph2")
			Run_MEKD_MG_ME_Configurator_Spin2Ph2("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Ph3" ||
				 (*Test_Model_buffer) == "!ggSpin2Ph3")
			Run_MEKD_MG_ME_Configurator_Spin2Ph3("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Ph3" ||
				 (*Test_Model_buffer) == "!qqSpin2Ph3")
			Run_MEKD_MG_ME_Configurator_Spin2Ph3("qq");
		else if ((*Test_Model_buffer) == "Spin2Ph3" ||
				 (*Test_Model_buffer) == "!Spin2Ph3")
			Run_MEKD_MG_ME_Configurator_Spin2Ph3("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Ph6" ||
				 (*Test_Model_buffer) == "!ggSpin2Ph6")
			Run_MEKD_MG_ME_Configurator_Spin2Ph6("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Ph6" ||
				 (*Test_Model_buffer) == "!qqSpin2Ph6")
			Run_MEKD_MG_ME_Configurator_Spin2Ph6("qq");
		else if ((*Test_Model_buffer) == "Spin2Ph6" ||
				 (*Test_Model_buffer) == "!Spin2Ph6")
			Run_MEKD_MG_ME_Configurator_Spin2Ph6("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Ph7" ||
				 (*Test_Model_buffer) == "!ggSpin2Ph7")
			Run_MEKD_MG_ME_Configurator_Spin2Ph7("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Ph7" ||
				 (*Test_Model_buffer) == "!qqSpin2Ph7")
			Run_MEKD_MG_ME_Configurator_Spin2Ph7("qq");
		else if ((*Test_Model_buffer) == "Spin2Ph7" ||
				 (*Test_Model_buffer) == "!Spin2Ph7")
			Run_MEKD_MG_ME_Configurator_Spin2Ph7("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Mh9" ||
				 (*Test_Model_buffer) == "!ggSpin2Mh9")
			Run_MEKD_MG_ME_Configurator_Spin2Mh9("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Mh9" ||
				 (*Test_Model_buffer) == "!qqSpin2Mh9")
			Run_MEKD_MG_ME_Configurator_Spin2Mh9("qq");
		else if ((*Test_Model_buffer) == "Spin2Mh9" ||
				 (*Test_Model_buffer) == "!Spin2Mh9")
			Run_MEKD_MG_ME_Configurator_Spin2Mh9("NO");

		else if ((*Test_Model_buffer) == "ggSpin2Mh10" ||
				 (*Test_Model_buffer) == "!ggSpin2Mh10")
			Run_MEKD_MG_ME_Configurator_Spin2Mh10("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Mh10" ||
				 (*Test_Model_buffer) == "!qqSpin2Mh10")
			Run_MEKD_MG_ME_Configurator_Spin2Mh10("qq");
		else if ((*Test_Model_buffer) == "Spin2Mh10" ||
				 (*Test_Model_buffer) == "!Spin2Mh10")
			Run_MEKD_MG_ME_Configurator_Spin2Mh10("NO");

		else if ((*Test_Model_buffer) == "ggSpin2" ||
				 (*Test_Model_buffer) == "!ggSpin2")
			Run_MEKD_MG_ME_Configurator_Spin2("gg");
		else if ((*Test_Model_buffer) == "qqSpin2" ||
				 (*Test_Model_buffer) == "!qqSpin2")
			Run_MEKD_MG_ME_Configurator_Spin2("qq");
		else if ((*Test_Model_buffer) == "Spin2" ||
				 (*Test_Model_buffer) == "!Spin2")
			Run_MEKD_MG_ME_Configurator_Spin2("NO");

		/// Resonance to 2l decay modes. Final states: 4 leptons (+photon)
		Resonance_decay_mode = "2l";

		// Is it a spin-0 resonance?
		if ((*Test_Model_buffer) == "ggSpin0Pm_2f" ||
			(*Test_Model_buffer) == "!ggSpin0Pm_2f") // SM Higgs
			Run_MEKD_MG_ME_Configurator_Spin0Pm("gg");
		else if ((*Test_Model_buffer) == "Spin0Pm_2f" ||
				 (*Test_Model_buffer) == "!Spin0Pm_2f")
			Run_MEKD_MG_ME_Configurator_Spin0Pm("NO");

		else if ((*Test_Model_buffer) == "ggSpin0M_2f" ||
				 (*Test_Model_buffer) == "!ggSpin0M_2f")
			Run_MEKD_MG_ME_Configurator_Spin0M("gg");
		else if ((*Test_Model_buffer) == "Spin0M_2f" ||
				 (*Test_Model_buffer) == "!Spin0M_2f")
			Run_MEKD_MG_ME_Configurator_Spin0M("NO");

		else if ((*Test_Model_buffer) == "ggSpin0_2f" ||
				 (*Test_Model_buffer) == "!ggSpin0_2f")
			Run_MEKD_MG_ME_Configurator_Spin0("gg");
		else if ((*Test_Model_buffer) == "Spin0_2f" ||
				 (*Test_Model_buffer) == "!Spin0_2f")
			Run_MEKD_MG_ME_Configurator_Spin0("NO");

		// Is it a spin-1 resonance?
		else if ((*Test_Model_buffer) == "qqSpin1M_2f" ||
				 (*Test_Model_buffer) == "!qqSpin1M_2f")
			Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		else if ((*Test_Model_buffer) == "Spin1M" ||
				 (*Test_Model_buffer) == "!Spin1M_2f")
			Run_MEKD_MG_ME_Configurator_Spin1M("NO");

		else if ((*Test_Model_buffer) == "qqSpin1P_2f" ||
				 (*Test_Model_buffer) == "!qqSpin1P_2f")
			Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		else if ((*Test_Model_buffer) == "Spin1P_2f" ||
				 (*Test_Model_buffer) == "!Spin1P_2f")
			Run_MEKD_MG_ME_Configurator_Spin1P("NO");

		else if ((*Test_Model_buffer) == "qqSpin1_2f" ||
				 (*Test_Model_buffer) == "!qqSpin1_2f")
			Run_MEKD_MG_ME_Configurator_Spin1("qq");
		else if ((*Test_Model_buffer) == "Spin1_2f" ||
				 (*Test_Model_buffer) == "!Spin1_2f")
			Run_MEKD_MG_ME_Configurator_Spin1("NO");

		// Is it a spin-2 resonance?
		else if ((*Test_Model_buffer) == "ggSpin2Pm_2f" ||
				 (*Test_Model_buffer) == "!ggSpin2Pm_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		else if ((*Test_Model_buffer) == "qqSpin2Pm_2f" ||
				 (*Test_Model_buffer) == "!qqSpin2Pm_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		else if ((*Test_Model_buffer) == "Spin2Pm_2f" ||
				 (*Test_Model_buffer) == "!Spin2Pm_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");

		else if ((*Test_Model_buffer) == "ggSpin2_2f" ||
				 (*Test_Model_buffer) == "!ggSpin2_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		else if ((*Test_Model_buffer) == "qqSpin2_2f" ||
				 (*Test_Model_buffer) == "!qqSpin2_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		else if ((*Test_Model_buffer) == "Spin2_2f" ||
				 (*Test_Model_buffer) == "!Spin2_2f")
			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");

		// Is it a RAW MG5_aMC ME?
		if ((*Test_Model_buffer) == "ggCPPProcess" ||
			(*Test_Model_buffer) == "!ggCPPProcess") // ME_RAW
			Run_MEKD_MG_ME_Configurator_CPPProcess("gg");
		else if ((*Test_Model_buffer) == "qqCPPProcess" ||
				 (*Test_Model_buffer) == "!qqCPPProcess")
			Run_MEKD_MG_ME_Configurator_CPPProcess("qq");
		else if ((*Test_Model_buffer) == "CPPProcess" ||
				 (*Test_Model_buffer) == "!CPPProcess")
			Run_MEKD_MG_ME_Configurator_CPPProcess("NO");

		if (Debug_Mode)
			cout << "Evaluated model: " << (*Test_Model_buffer)
				 << "; calculated ME: " << Signal_ME << endl;

		if (Test_Models.size() > 0 && Test_Model[0] != '!') {
			Signal_MEs.push_back(Signal_ME);

			if (counter < Test_Models.size())
				Test_Model_buffer = &(Test_Models[counter]);
			else
				Test_Model_buffer = NULL;
		} else
			Test_Model_buffer = NULL;

		counter++;
	}
	
	if (Debug_Mode) {
		cout << "4-momenta after ME(E px py px) calculations:\n";
		Print_4momenta(p_set);
	}

	if (Test_Model[0] != '!')
		KD = log(Signal_ME / Background_ME);

	return 0;
}

int MEKD_MG::Run_MEKD_MG(string Input_Model)
{
	buffer_string = Test_Model;
	Test_Model = "!";
	Test_Model += Input_Model;

	error_value = Run_MEKD_MG();

	Test_Model = buffer_string;
	return error_value;
}

void MEKD_MG::Load_p_set()
{
	for (int i = 0; i < 4; ++i) {
		p_set[0][i] = 0;
		p_set[1][i] = 0;

		if (pl1_internal == NULL)
			p_set[2][i] = 0;
		else
			p_set[2][i] = pl1_internal[i];
		if (pl2_internal == NULL)
			p_set[3][i] = 0;
		else
			p_set[3][i] = pl2_internal[i];
		if (pl3_internal == NULL)
			p_set[4][i] = 0;
		else
			p_set[4][i] = pl3_internal[i];
		if (pl4_internal == NULL)
			p_set[5][i] = 0;
		else
			p_set[5][i] = pl4_internal[i];

		// Adaptive photon handling
		if (pA1_internal == NULL)
			p_set[6][i] = 0;
		else {
			if (Final_state == "2mA" || Final_state == "2muA") {
				p_set[4][i] = pA1_internal[i];
				p_set[6][i] = 0;
			} else
				p_set[6][i] = pA1_internal[i];
		}
	}
}

double MEKD_MG::Get_PDF_x1(vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) +
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / Sqrt_s;
}

double MEKD_MG::Get_PDF_x2(vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) -
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / Sqrt_s;
}

double MEKD_MG::Get_invariant_m(vector<double *> &p, int p_range[2])
{
	double sum_E = 0;
	double sum_px = 0;
	double sum_py = 0;
	double sum_pz = 0;
	
	for (vector<double *>::const_iterator it = p.begin() + p_range[0];
		it != p.begin() + p_range[1] + 1; ++it) {
		sum_E += (*it)[0];
		sum_px += (*it)[1];
		sum_py += (*it)[2];
		sum_pz += (*it)[3];
	}
	
	return sqrt(sum_E * sum_E
				- sum_px * sum_px
				- sum_py * sum_py
				- sum_pz * sum_pz);
}

void MEKD_MG::Approx_neg_z_parton(double *p, double E)
{
	// 0-mass approximation
	p[0] = 0.5 * E;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0.5 * E; // to be recalculated
}

void MEKD_MG::Approx_pos_z_parton(double *p, double E)
{
	// 0-mass approximation
	p[0] = 0.5 * E;
	p[1] = 0;
	p[2] = 0;
	p[3] = -0.5 * E; // to be recalculated
}

///#include "MEKD_MG_2Model_Mixer.cpp"
/////////////////////////////////////////
/// INCLUDED MEKD_MG_2Model_Mixer.cpp ///
/// code follows below                ///
///                                   ///
/// Part responsible for              ///
/// holding mixed couplings           ///
/////////////////////////////////////////

///////////////////////////////////////
/// END OF MEKD_MG_2Model_Mixer.cpp ///
///////////////////////////////////////

/// end of namespace
}

#endif