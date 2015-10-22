/*************************************************************************
*  Authors:   MEKD fans
*  More info: http://mekd.ihepa.ufl.edu
*  Contact:   odysei@cern.ch, mekd@phys.ufl.edu
*************************************************************************/
#ifndef MEKD_cpp
#define MEKD_cpp

/// MEKD header
#include "../interface/MEKD.h"

using namespace std;

namespace mekd
{
	
/* 
 * 
 * MEKD class member implementation
 * 
 * Provides an interface to MadGraph_aMC@NLO-derived MEs and MEKD models behind
 * them.
 * 
 */

// p_set(7, new double[4]), => some problems ???
MEKD::MEKD()
{
	Mixing_Coefficients_Spin0 = new complex<double>[4];
	Mixing_Coefficients_Spin0_internal = new complex<double>[4];
	Mixing_Coefficients_Spin1 = new complex<double>[8];
	Mixing_Coefficients_Spin1_internal = new complex<double>[8];
	Mixing_Coefficients_Spin2 = new complex<double>[20];
	Mixing_Coefficients_Spin2_internal = new complex<double>[20];

	Set_default_params();

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

/*
 * MEKD::MEKD - Version 2 or earlier constructor
 */
MEKD::MEKD(const double &collision_energy, const string &PDF_name): MEKD()
{
	param.sqrt_s = collision_energy * 1000;	// translate TeV to GeV
	m_PDFName = PDF_name;

	m_Mixing_Coefficients_Spin0 = Mixing_Coefficients_Spin0;
	m_Mixing_Coefficients_Spin1 = Mixing_Coefficients_Spin1;
	m_Mixing_Coefficients_Spin2 = Mixing_Coefficients_Spin2;

	ME_ZZ = 0;
	ME_Spin0PSMH = 0;
	ME_Spin0Ph = 0;
	ME_Spin0M = 0;
	ME_Spin1P = 0;
	ME_Spin1M = 0;
	ME_ggSpin2Pm = 0;
	ME_qqSpin2Pm = 0;

	four_particle_IDs_i.resize(4, 0);
	four_particle_Ps_i.resize(4, NULL);
}

MEKD::~MEKD()
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
	
	for (auto runner: ME_runners)
		delete runner;
	ME_runners.clear();
}

int MEKD::Load_Parameters()
{
	params_MG.read_slha_file(static_cast<string>(Parameter_file));
	
	/// Initializing parameters
	if (!Parameters_Are_Loaded)
		Load_Parameters_MEs();	// init MEs
	Load_Parameters_extract_params(params_MG);
	Load_Parameters_eval_params();
	Normalize_parton_coeffs();
	
	if (Parameters_Are_Loaded)
		Unload_pdfreader();
	Load_pdfreader(const_cast<char *>(PDF_file.c_str()));

	Parameters_Are_Loaded = true;
	return 0;
}

int MEKD::Reload_params()
{
	if (!Parameters_Are_Loaded)
		return 1;

	return Load_Parameters();
}

void MEKD::eval_MEs(const input &in, vector<double> &ME2)
{
	if (ME2.size() != ME_runners.size())
		ME2.resize(ME_runners.size(), 0);
	cerr << "FIX ME!\n";
	/* Added block */
	p1 = (*in.p)[0];
	p2 = (*in.p)[1];
	p3 = (*in.p)[2];
	p4 = (*in.p)[3];
	
	id1 = (*in.id)[0];
	id2 = (*in.id)[1];
	id3 = (*in.id)[2];
	id4 = (*in.id)[3];
	if ((*in.p).size() > 4) {
		p5 = (*in.p)[4];
		id5 = (*in.id)[4];
	}
	/* End of added block */
	
	if (!Parameters_Are_Loaded)
		Load_Parameters();
	if (Arrange_Internal_pls() == 1) {	// loads&arranges plX_internal
		cerr << "Particle id error. Exiting.\n";
		exit(1);
	}
	
	PDFx1 = 0;
	PDFx2 = 0;
	Background_ME = 0;
	Signal_ME = 0;
	
	Run_make_p();

	int range[2] = {2, 6}; 
	invariant_m = Get_invariant_m(p_set, range);
	
	if (flag.per_event_parton_coeffs && !flag.Use_PDF_w_pT0)
		Normalize_parton_coeffs();
	
	if (flag.Debug_Mode) {
		cout << "4-momenta entering ME(E px py px):\n";
		Print_4momenta(p_set);
	}
	
	for (unsigned int i = 0; i < ME_runners.size(); ++i) {
		if (ME_runners[i] != NULL) {
			Signal_ME = ME_runners[i]->evaluate(*this, in);
			ME2[i] = Signal_ME;
		} else
			ME2[i] = 0;
	}
	
	if (flag.Debug_Mode) {
		cout << "4-momenta after ME(E px py px) calculations:\n";
		Print_4momenta(p_set);
	}
}

int MEKD::Run()
{
	if (!Parameters_Are_Loaded)
		Load_Parameters();
	if (Arrange_Internal_pls() == 1) {	// loads&arranges plX_internal
		cerr << "Particle id error. Exiting.\n";
		exit(1);
	}

	PDFx1 = 0;
	PDFx2 = 0;
	Background_ME = 0;
	Signal_ME = 0;
	
	Run_make_p();

	int range[2] = {2, 6}; 
	invariant_m = Get_invariant_m(p_set, range);
	
	if (flag.per_event_parton_coeffs && !flag.Use_PDF_w_pT0)
		Normalize_parton_coeffs();
	
	if (flag.Debug_Mode) {
		cout << "4-momenta entering ME(E px py px):\n";
		Print_4momenta(p_set);
	}
	
	Run_calculate();
	
	if (flag.Debug_Mode) {
		cout << "4-momenta after ME(E px py px) calculations:\n";
		Print_4momenta(p_set);
	}

	if (Test_Model[0] != '!')
		KD = log(Signal_ME / Background_ME);

	return 0;
}

int MEKD::Run(string Input_Model)
{
	const string buff = Test_Model;
	Test_Model = "!";
	Test_Model += Input_Model;

	error_value = Run();

	Test_Model = buff;
	return error_value;
}

void MEKD::Run_make_p()
{
	if (flag.Overwrite_e_and_mu_masses) {
		params_MG.set_block_entry("mass", 11, param.Electron_mass);
		params_MG.set_block_entry("mass", 13, param.Muon_mass);
		params_m_e = param.Electron_mass;
		params_m_mu = param.Muon_mass;
	}

	Load_p_set();	// load 4-momenta from plX_internal
	Prepare_ml_s();	// fill ml values; used in boosts only
	
	/// Calculate values needed for the PDF in the pT=0 frame
	if (flag.Use_PDF_w_pT0) {
		Boost_5p_2_pT0(ml1, p_set[2], ml2, p_set[3], ml3, p_set[4], ml4,
					   p_set[5], 0, p_set[6]);
	}
	
	PDFx1 = Get_PDF_x1(p_set);
	PDFx2 = Get_PDF_x2(p_set);
	if (flag.Debug_Mode) {
		printf("Coefficients for PDF (x1, x2): (%.10E, %.10E)\n",
			   PDFx1, PDFx2);
	}

	/// If flag is true, boost to CM frame iff PDF is NOT included.
	if (flag.Boost_To_CM && !flag.Use_PDF_w_pT0) {
		Boost2CM(ml1, p_set[2], ml2, p_set[3], ml3, p_set[4], ml4, p_set[5], 0,
				 p_set[6]);
		double CollisionE = p_set[2][0] + p_set[3][0] + p_set[4][0] +
							p_set[5][0] + p_set[6][0];
		p_set[0][0] = 0.5 * CollisionE;
		p_set[1][0] = 0.5 * CollisionE;
	} else {
		Approx_neg_z_parton(p_set[0], PDFx1 * param.sqrt_s);
		Approx_pos_z_parton(p_set[1], PDFx2 * param.sqrt_s);
	}
}

void MEKD::Run_calculate()
{
	/// Background is interesting in any case, except for the Signal Runs or '!'
	/// is indicated in the first model to save CPU
	process_description d;
	if (Test_Model[0] != '!' && Test_Models.size() == 0) {
		d.production = prod_qq;
		Run_ME_Configurator_BKG_ZZ(d);
		Background_ME = Signal_ME;
	} else if (Test_Models.size() > 0) {
		if (Test_Models[0][0] != '!') {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d);
			Background_ME = Signal_ME;
		}
	}

	string *model = NULL;
	/// Signal ME(s) is(are) chosen here
	if (Test_Models.size() > 0 && Test_Model[0] != '!') {
		Signal_MEs.resize(Test_Models.size());
		fill(Signal_MEs.begin(), Signal_MEs.end(), 0);
		model = &(Test_Models[0]); // Should be NULL or undefined
											   // before this point; works as
											   // counter=0
	} else
		model = &Test_Model;	// Should be NULL or undefined
											// before this point

	unsigned int counter = 1;
	while (model != NULL) {
		// Is it a parameter card defined?
		if ((*model) == "Custom" ||
			(*model) == "!Custom")
			Run_ME_Configurator_Custom();

		// Is it a "background"?
		else if ((*model) == "qqZZ" ||
				 (*model) == "!qqZZ") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d);
		} else if ((*model) == "ZZ" ||
			(*model) == "!ZZ") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d);
		}

		else if ((*model) == "qqDY" ||
				 (*model) == "!qqDY") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d);
		}
		else if ((*model) == "DY" ||
			(*model) == "!DY") {
			d.production = prod_no;
			Run_ME_Configurator_BKG_ZZ(d);
		}

		// Is it a Z boson resonance?
		else if ((*model) == "qqZ4l_Background" ||
				 (*model) == "!qqZ4l_Background") {
			d.production = prod_qq;
			Run_ME_Configurator_Z4l_BKG(d);
		} else if ((*model) == "qqZ4l_Signal" ||
				 (*model) == "!qqZ4l_Signal") {
			d.production = prod_qq;
			Run_ME_Configurator_Z4l_SIG(d);
		}

		/// Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
		/// Final states: 4 leptons (+photon) also 2 muons (+photon)
		d.decay = decay_ZZ;

		// Is it a spin-0 resonance?
		if ((*model) == "ggSpin0Pm" ||
			(*model) == "!ggSpin0Pm") { // SM Higgs
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Pm(d);
		} else if ((*model) == "Spin0Pm" ||
				 (*model) == "!Spin0Pm") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Pm(d);
		}

		else if ((*model) == "ggSpin0M" ||
				 (*model) == "!ggSpin0M") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0M(d);
		} else if ((*model) == "Spin0M" ||
				 (*model) == "!Spin0M") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0M(d);
		}

		else if ((*model) == "ggSpin0Ph" ||
				 (*model) == "!ggSpin0Ph") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Ph(d);
		} else if ((*model) == "Spin0Ph" ||
				 (*model) == "!Spin0Ph") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Ph(d);
		}

		else if ((*model) == "ggSpin0" ||
				 (*model) == "!ggSpin0") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0(d, params_MG);
		} else if ((*model) == "Spin0" ||
				 (*model) == "!Spin0") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0(d, params_MG);
		}

		// Is it a spin-1 resonance?
		else if ((*model) == "qqSpin1M" ||
				 (*model) == "!qqSpin1M") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1M(d);
		} else if ((*model) == "Spin1M" ||
				 (*model) == "!Spin1M"){
			d.production = prod_no;
			Run_ME_Configurator_Spin1M(d);
		}

		else if ((*model) == "qqSpin1P" ||
				 (*model) == "!qqSpin1P") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1P(d);
		} else if ((*model) == "Spin1P" ||
				 (*model) == "!Spin1P") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1P(d);
		}

		else if ((*model) == "qqSpin1" ||
				 (*model) == "!qqSpin1") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1(d, params_MG);
		} else if ((*model) == "Spin1" ||
				 (*model) == "!Spin1") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1(d, params_MG);
		}

		// Is it a spin-2 resonance?
		else if ((*model) == "ggSpin2Pm" ||
				 (*model) == "!ggSpin2Pm") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "qqSpin2Pm" ||
				 (*model) == "!qqSpin2Pm") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "Spin2Pm" ||
				 (*model) == "!Spin2Pm") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d);
		}

		else if ((*model) == "ggSpin2Ph" ||
				 (*model) == "!ggSpin2Ph") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph(d);
		} else if ((*model) == "qqSpin2Ph" ||
				 (*model) == "!qqSpin2Ph") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph(d);
		} else if ((*model) == "Spin2Ph" ||
				 (*model) == "!Spin2Ph") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph(d);
		}

		else if ((*model) == "ggSpin2Mh" ||
				 (*model) == "!ggSpin2Mh") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh(d);
		} else if ((*model) == "qqSpin2Mh" ||
				 (*model) == "!qqSpin2Mh") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh(d);
		} else if ((*model) == "Spin2Mh" ||
				 (*model) == "!Spin2Mh") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh(d);
		}

		else if ((*model) == "ggSpin2Pb" ||
				 (*model) == "!ggSpin2Pb") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pb(d);
		} else if ((*model) == "qqSpin2Pb" ||
				 (*model) == "!qqSpin2Pb") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pb(d);
		} else if ((*model) == "Spin2Pb" ||
				 (*model) == "!Spin2Pb") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pb(d);
		}

		else if ((*model) == "ggSpin2Ph2" ||
				 (*model) == "!ggSpin2Ph2") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph2(d);
		} else if ((*model) == "qqSpin2Ph2" ||
				 (*model) == "!qqSpin2Ph2") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph2(d);
		} else if ((*model) == "Spin2Ph2" ||
				 (*model) == "!Spin2Ph2") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph2(d);
		}

		else if ((*model) == "ggSpin2Ph3" ||
				 (*model) == "!ggSpin2Ph3") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph3(d);
		} else if ((*model) == "qqSpin2Ph3" ||
				 (*model) == "!qqSpin2Ph3") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph3(d);
		} else if ((*model) == "Spin2Ph3" ||
				 (*model) == "!Spin2Ph3") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph3(d);
		}

		else if ((*model) == "ggSpin2Ph6" ||
				 (*model) == "!ggSpin2Ph6") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph6(d);
		} else if ((*model) == "qqSpin2Ph6" ||
				 (*model) == "!qqSpin2Ph6") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph6(d);
		} else if ((*model) == "Spin2Ph6" ||
				 (*model) == "!Spin2Ph6") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph6(d);
		}

		else if ((*model) == "ggSpin2Ph7" ||
				 (*model) == "!ggSpin2Ph7") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph7(d);
		} else if ((*model) == "qqSpin2Ph7" ||
				 (*model) == "!qqSpin2Ph7") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph7(d);
		} else if ((*model) == "Spin2Ph7" ||
				 (*model) == "!Spin2Ph7") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph7(d);
		}

		else if ((*model) == "ggSpin2Mh9" ||
				 (*model) == "!ggSpin2Mh9") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh9(d);
		} else if ((*model) == "qqSpin2Mh9" ||
				 (*model) == "!qqSpin2Mh9") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh9(d);
		} else if ((*model) == "Spin2Mh9" ||
				 (*model) == "!Spin2Mh9") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh9(d);
		}

		else if ((*model) == "ggSpin2Mh10" ||
				 (*model) == "!ggSpin2Mh10") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh10(d);
		} else if ((*model) == "qqSpin2Mh10" ||
				 (*model) == "!qqSpin2Mh10") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh10(d);
		} else if ((*model) == "Spin2Mh10" ||
				 (*model) == "!Spin2Mh10") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh10(d);
		}

		else if ((*model) == "ggSpin2" ||
				 (*model) == "!ggSpin2") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2(d, params_MG);
		} else if ((*model) == "qqSpin2" ||
				 (*model) == "!qqSpin2") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2(d, params_MG);
		} else if ((*model) == "Spin2" ||
				 (*model) == "!Spin2") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2(d, params_MG);
		}

		/// Resonance to 2l decay modes. Final states: 4 leptons (+photon)
		d.decay = decay_2f;

		// Is it a spin-0 resonance?
		if ((*model) == "ggSpin0Pm_2f" ||
			(*model) == "!ggSpin0Pm_2f") { // SM Higgs
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Pm(d);
		} else if ((*model) == "Spin0Pm_2f" ||
				 (*model) == "!Spin0Pm_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Pm(d);
		}

		else if ((*model) == "ggSpin0M_2f" ||
				 (*model) == "!ggSpin0M_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0M(d);
		} else if ((*model) == "Spin0M_2f" ||
				 (*model) == "!Spin0M_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0M(d);
		}

		else if ((*model) == "ggSpin0_2f" ||
				 (*model) == "!ggSpin0_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0(d, params_MG);
		} else if ((*model) == "Spin0_2f" ||
				 (*model) == "!Spin0_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0(d, params_MG);
		}

		// Is it a spin-1 resonance?
		else if ((*model) == "qqSpin1M_2f" ||
				 (*model) == "!qqSpin1M_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1M(d);
		} else if ((*model) == "Spin1M" ||
				 (*model) == "!Spin1M_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1M(d);
		}

		else if ((*model) == "qqSpin1P_2f" ||
				 (*model) == "!qqSpin1P_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1P(d);
		} else if ((*model) == "Spin1P_2f" ||
				 (*model) == "!Spin1P_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1P(d);
		}

		else if ((*model) == "qqSpin1_2f" ||
				 (*model) == "!qqSpin1_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1(d, params_MG);
		} else if ((*model) == "Spin1_2f" ||
				 (*model) == "!Spin1_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1(d, params_MG);
		}

		// Is it a spin-2 resonance?
		else if ((*model) == "ggSpin2Pm_2f" ||
				 (*model) == "!ggSpin2Pm_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "qqSpin2Pm_2f" ||
				 (*model) == "!qqSpin2Pm_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "Spin2Pm_2f" ||
				 (*model) == "!Spin2Pm_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d);
		}

		else if ((*model) == "ggSpin2_2f" ||
				 (*model) == "!ggSpin2_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "qqSpin2_2f" ||
				 (*model) == "!qqSpin2_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d);
		} else if ((*model) == "Spin2_2f" ||
				 (*model) == "!Spin2_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d);
		}

		// Is it a RAW MG5_aMC ME?
		if ((*model) == "ggCPPProcess" ||
			(*model) == "!ggCPPProcess") { // ME_RAW
			d.production = prod_gg;
			Run_ME_Configurator_CPPProcess(d);
		} else if ((*model) == "qqCPPProcess" ||
				 (*model) == "!qqCPPProcess") {
			d.production = prod_qq;
			Run_ME_Configurator_CPPProcess(d);
		} else if ((*model) == "CPPProcess" ||
				 (*model) == "!CPPProcess") {
			d.production = prod_no;
			Run_ME_Configurator_CPPProcess(d);
		}

		if (flag.Debug_Mode)
			cout << "Evaluated model: " << (*model)
				 << "; calculated ME: " << Signal_ME << endl;

		if (Test_Models.size() > 0 && Test_Model[0] != '!') {
			Signal_MEs[counter - 1] = Signal_ME;

			if (counter < Test_Models.size())
				model = &(Test_Models[counter]);
			else
				model = NULL;
		} else
			model = NULL;

		++counter;
	}
}

void MEKD::Load_p_set()
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
			if (final_state_ == final_2muA) {
				p_set[4][i] = pA1_internal[i];
				p_set[6][i] = 0;
			} else
				p_set[6][i] = pA1_internal[i];
		}
	}
}

void MEKD::Prepare_ml_s()
{
	if (final_state_ == final_4e || final_state_ == final_4eA) {
		ml1 = params_MG.get_block_entry("mass", 11, param.Electron_mass).real();
		ml2 = ml1;
		ml3 = ml1;
		ml4 = ml1;
	} else if (final_state_ == final_4mu || final_state_ == final_4muA) {
		ml1 = params_MG.get_block_entry("mass", 13, param.Muon_mass).real();
		ml2 = ml1;
		ml3 = ml1;
		ml4 = ml1;
	} else if (final_state_ == final_2e2mu || final_state_ == final_2e2muA) {
		ml1 = params_MG.get_block_entry("mass", 11, param.Electron_mass).real();
		ml2 = ml1;
		ml3 = params_MG.get_block_entry("mass", 13, param.Muon_mass).real();
		ml4 = ml3;
	} else if (final_state_ == final_2mu || final_state_ == final_2muA) {
		ml1 = params_MG.get_block_entry("mass", 13, param.Muon_mass).real();
		ml2 = ml1;
		ml3 = 0;
		ml4 = 0;
	} else {
		cerr << "MAYDAY!!! Undefined behavior!\n";
		exit(1);
	}
}

double MEKD::Get_PDF_x1(vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) +
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / param.sqrt_s;
}

double MEKD::Get_PDF_x2(vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) -
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / param.sqrt_s;
}

double MEKD::Get_invariant_m(vector<double *> &p, int p_range[2])
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

void MEKD::Normalize_parton_coeffs()
{
	double buffer_ = (param.parton_coeff_d + param.parton_coeff_u +
					  param.parton_coeff_s + param.parton_coeff_c);
	
	param.parton_coeff_d = param.parton_coeff_d / buffer_;
	param.parton_coeff_u = param.parton_coeff_u / buffer_;
	param.parton_coeff_c = param.parton_coeff_c / buffer_;
	param.parton_coeff_s = param.parton_coeff_s / buffer_;
}

void MEKD::Approx_neg_z_parton(double *p, double E)
{
	// 0-mass approximation
	p[0] = 0.5 * E;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0.5 * E; // to be recalculated
}

void MEKD::Approx_pos_z_parton(double *p, double E)
{
	// 0-mass approximation
	p[0] = 0.5 * E;
	p[1] = 0;
	p[2] = 0;
	p[3] = -0.5 * E; // to be recalculated
}

/*
 * Version 2 and earlier methods: left for backwards compatibility.
 */

///------------------------------------------------------------------------
/// MEKD::processParameters - sanity check for internal parameters
///------------------------------------------------------------------------
/// Might be merged to the constructor if these flags are not used as is(was)
///------------------------------------------------------------------------
int MEKD::processParameters()
{
	/// Check if the PDF name is supported and set PDF flag
	if (m_PDFName != "CTEQ6L" && m_PDFName != "" && m_PDFName != "no PDFs")
		return EXIT_ERROR_PDFS;
	m_usePDF = (m_PDFName == "CTEQ6L");

	flag.Use_PDF_w_pT0 = m_usePDF;

	/// Check if sqrt(s) is 7 or 8 TeV
	if (param.sqrt_s != 7000 && param.sqrt_s != 8000)
		cerr << "WARNING! You have set energy to be " << param.sqrt_s/1000
			 << " TeV\n";

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// MEKD::setProcessName - sanity check and setting of process names
///------------------------------------------------------------------------
int MEKD::setProcessName(string process)
{
	/// Check if process is supported, translation of namings
	if (process == "Custom") {
		m_process = "Custom";
	} // Parameter-card-defined model
	/// "Backgrounds"
	else if (process == "qqZZ" ||
			 process == "ZZ") {
		m_process = "qqZZ";
	} else if (process == "qqDY") {
		m_process = "qqDY";
	} else if (process == "DY") {
		m_process = "DY";
	}
	/// Spin-0 models
	else if (process == "Higgs" ||
			 process == "SMHiggs" ||
			 process == "ggSpin0Pm") {
		m_process = "ggSpin0Pm";
	} else if (process == "Spin0Pm") {
		m_process = "Spin0Pm";
	} else if (process == "CP-odd" ||
			   process == "Higgs0M" ||
			   process == "ggSpin0M") {
		m_process = "ggSpin0M";
	} else if (process == "Spin0M") {
		m_process = "Spin0M";
	} else if (process == "ggSpin0PH" ||
			   process == "ggSpin0Ph") {
		m_process = "ggSpin0Ph";
	} else if (process == "Spin0Ph") {
		m_process = "Spin0Ph";
	} else if (process == "ggSpin0") {
		m_process = "ggSpin0";
	} else if (process == "Spin0") {
		m_process = "Spin0";
	}
	/// Spin-1 models
	else if (process == "qqSpin1P") {
		m_process = "qqSpin1P";
	} else if (process == "Spin1P") {
		m_process = "Spin1P";
	} else if (process == "qqSpin1M") {
		m_process = "qqSpin1M";
	} else if (process == "Spin1M") {
		m_process = "Spin1M";
	} else if (process == "qqSpin1") {
		m_process = "qqSpin1";
	} else if (process == "Spin1") {
		m_process = "Spin1";
	}
	/// Spin-2 models
	else if (process == "ggSpin2PM" ||
			 process == "Graviton2PM" ||
			 process == "ggSpin2Pm") {
		m_process = "ggSpin2Pm";
	} else if (process == "qqSpin2PM" ||
			   process == "qqGraviton2PM" ||
			   process == "qqSpin2Pm") {
		m_process = "qqSpin2Pm";
	} else if (process == "Spin2Pm") {
		m_process = "Spin2Pm";
	} else if (process == "ggSpin2Ph") {
		m_process = "ggSpin2Ph";
	} else if (process == "qqSpin2Ph") {
		m_process = "qqSpin2Ph";
	} else if (process == "Spin2Ph") {
		m_process = "Spin2Ph";
	} else if (process == "ggSpin2Mh") {
		m_process = "ggSpin2Mh";
	} else if (process == "qqSpin2Mh") {
		m_process = "qqSpin2Mh";
	} else if (process == "Spin2Mh") {
		m_process = "Spin2Mh";
	} else if (process == "ggSpin2Pb") {
		m_process = "ggSpin2Pb";
	} else if (process == "qqSpin2Pb") {
		m_process = "qqSpin2Pb";
	} else if (process == "Spin2Pb") {
		m_process = "Spin2Pb";
	} else if (process == "ggSpin2Ph2") {
		m_process = "ggSpin2Ph2";
	} else if (process == "qqSpin2Ph2") {
		m_process = "qqSpin2Ph2";
	} else if (process == "Spin2Ph2") {
		m_process = "Spin2Ph2";
	} else if (process == "ggSpin2Ph3") {
		m_process = "ggSpin2Ph3";
	} else if (process == "qqSpin2Ph3") {
		m_process = "qqSpin2Ph3";
	} else if (process == "Spin2Ph3") {
		m_process = "Spin2Ph3";
	} else if (process == "ggSpin2Ph6") {
		m_process = "ggSpin2Ph6";
	} else if (process == "qqSpin2Ph6") {
		m_process = "qqSpin2Ph6";
	} else if (process == "Spin2Ph6") {
		m_process = "Spin2Ph6";
	} else if (process == "ggSpin2Ph7") {
		m_process = "ggSpin2Ph7";
	} else if (process == "qqSpin2Ph7") {
		m_process = "qqSpin2Ph7";
	} else if (process == "Spin2Ph7") {
		m_process = "Spin2Ph7";
	} else if (process == "ggSpin2Mh9") {
		m_process = "ggSpin2Mh9";
	} else if (process == "qqSpin2Mh9") {
		m_process = "qqSpin2Mh9";
	} else if (process == "Spin2Mh9") {
		m_process = "Spin2Mh9";
	} else if (process == "ggSpin2Mh10") {
		m_process = "ggSpin2Mh10";
	} else if (process == "qqSpin2Mh10") {
		m_process = "qqSpin2Mh10";
	} else if (process == "Spin2Mh10") {
		m_process = "Spin2Mh10";
	} else if (process == "ggSpin2") {
		m_process = "ggSpin2";
	} else if (process == "qqSpin2") {
		m_process = "qqSpin2";
	} else if (process == "Spin2") {
		m_process = "Spin2";
	}
	/// Spin-0-to-2-leptons models
	else if (process == "ggSpin0Pm_2f") {
		m_process = "ggSpin0Pm_2f";
	} else if (process == "Spin0Pm_2f") {
		m_process = "Spin0Pm_2f";
	} else if (process == "ggSpin0M_2f") {
		m_process = "ggSpin0M_2f";
	} else if (process == "Spin0M_2f") {
		m_process = "Spin0M_2f";
	} /*else if(process == "ggSpin0_2f") {
		m_process = "ggSpin0_2f";
	} else if(process == "Spin0_2f") {
		m_process = "Spin0_2f";
	}*/
	/// Spin-1-to-2-leptons models
	else if (process == "qqSpin1P_2f") {
		m_process = "qqSpin1P_2f";
	} else if (process == "Spin1P_2f") {
		m_process = "Spin1P_2f";
	} else if (process == "qqSpin1M_2f") {
		m_process = "qqSpin1M_2f";
	} else if (process == "Spin1M_2f") {
		m_process = "Spin1M_2f";
	} /*else if(process == "qqSpin1_2f") {
		m_process = "qqSpin1_2f";
	} else if(process == "Spin1_2f") {
		m_process = "Spin1_2f";
	}*/
	// Spin-2-to-2-leptons models
	else if (process == "ggSpin2Pm_2f") {
		m_process = "ggSpin2Pm_2f";
	} else if (process == "qqSpin2Pm_2f") {
		m_process = "qqSpin2Pm_2f";
	} else if (process == "Spin2Pm_2f") {
		m_process = "Spin2Pm_2f";
	} /*else if(process == "ggSpin2_2f") {
		m_process = "ggSpin2_2f";
	} else if(process == "qqSpin2_2f") {
		m_process = "qqSpin2_2f";
	} else if(process == "Spin2_2f") {
		m_process = "Spin2_2f";
	}*/
	/// Z->4l models
	else if (process == "qqZ4l_Background") {
		m_process = "qqZ4l_Background";
	} else if (process == "qqZ4l_Signal") {
		m_process = "qqZ4l_Signal";
	} else
		return EXIT_ERROR_PROCESS;

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// MEKD::setProcessNames - sanity check and setting of process names
///------------------------------------------------------------------------
int MEKD::setProcessNames(string processA, string processB)
{
	/// processes A and B should be different
	if (processA == processB)
		return EXIT_ERROR_PROCESS;
	/// check if processA is supported, translation of namings
	if (processA == "Custom") {
		m_processA = "Custom";
	} // Parameter-card-defined model

	else if (processA == "qqZZ" || processA == "ZZ") {
		m_processA = "qqZZ";
	} // "Background"
	else if (processA == "qqDY") {
		m_processA = "qqDY";
	} // "Background"
	else if (processA == "DY") {
		m_processA = "DY";
	}

	else if (processA == "Higgs" || processA == "SMHiggs" ||
			 processA == "ggSpin0Pm") {
		m_processA = "ggSpin0Pm";
	} // Spin-0 models
	else if (processA == "Spin0Pm") {
		m_processA = "Spin0Pm";
	} else if (processA == "CP-odd" || processA == "Higgs0M" ||
			   processA == "ggSpin0M") {
		m_processA = "ggSpin0M";
	} else if (processA == "Spin0M") {
		m_processA = "Spin0M";
	} else if (processA == "ggSpin0PH" || processA == "ggSpin0Ph") {
		m_processA = "ggSpin0Ph";
	} else if (processA == "Spin0Ph") {
		m_processA = "Spin0Ph";
	} else if (processA == "ggSpin0") {
		m_processA = "ggSpin0";
	} else if (processA == "Spin0") {
		m_processA = "Spin0";
	}

	else if (processA == "qqSpin1P") {
		m_processA = "qqSpin1P";
	} // Spin-1 models
	else if (processA == "Spin1P") {
		m_processA = "Spin1P";
	} else if (processA == "qqSpin1M") {
		m_processA = "qqSpin1M";
	} else if (processA == "Spin1M") {
		m_processA = "Spin1M";
	} else if (processA == "qqSpin1") {
		m_processA = "qqSpin1";
	} else if (processA == "Spin1") {
		m_processA = "Spin1";
	}

	else if (processA == "ggSpin2PM" || processA == "Graviton2PM" ||
			 processA == "ggSpin2Pm") {
		m_processA = "ggSpin2Pm";
	} // Spin-2 models
	else if (processA == "qqSpin2PM" || processA == "qqGraviton2PM" ||
			 processA == "qqSpin2Pm") {
		m_processA = "qqSpin2Pm";
	} else if (processA == "Spin2Pm") {
		m_processA = "Spin2Pm";
	} else if (processA == "ggSpin2Ph") {
		m_processA = "ggSpin2Ph";
	} else if (processA == "qqSpin2Ph") {
		m_processA = "qqSpin2Ph";
	} else if (processA == "Spin2Ph") {
		m_processA = "Spin2Ph";
	} else if (processA == "ggSpin2Mh") {
		m_processA = "ggSpin2Mh";
	} else if (processA == "qqSpin2Mh") {
		m_processA = "qqSpin2Mh";
	} else if (processA == "Spin2Mh") {
		m_processA = "Spin2Mh";
	} else if (processA == "ggSpin2Pb") {
		m_processA = "ggSpin2Pb";
	} else if (processA == "qqSpin2Pb") {
		m_processA = "qqSpin2Pb";
	} else if (processA == "Spin2Pb") {
		m_processA = "Spin2Pb";
	} else if (processA == "ggSpin2Ph2") {
		m_processA = "ggSpin2Ph2";
	} else if (processA == "qqSpin2Ph2") {
		m_processA = "qqSpin2Ph2";
	} else if (processA == "Spin2Ph2") {
		m_processA = "Spin2Ph2";
	} else if (processA == "ggSpin2Ph3") {
		m_processA = "ggSpin2Ph3";
	} else if (processA == "qqSpin2Ph3") {
		m_processA = "qqSpin2Ph3";
	} else if (processA == "Spin2Ph3") {
		m_processA = "Spin2Ph3";
	} else if (processA == "ggSpin2Ph6") {
		m_processA = "ggSpin2Ph6";
	} else if (processA == "qqSpin2Ph6") {
		m_processA = "qqSpin2Ph6";
	} else if (processA == "Spin2Ph6") {
		m_processA = "Spin2Ph6";
	} else if (processA == "ggSpin2Ph7") {
		m_processA = "ggSpin2Ph7";
	} else if (processA == "qqSpin2Ph7") {
		m_processA = "qqSpin2Ph7";
	} else if (processA == "Spin2Ph7") {
		m_processA = "Spin2Ph7";
	} else if (processA == "ggSpin2Mh9") {
		m_processA = "ggSpin2Mh9";
	} else if (processA == "qqSpin2Mh9") {
		m_processA = "qqSpin2Mh9";
	} else if (processA == "Spin2Mh9") {
		m_processA = "Spin2Mh9";
	} else if (processA == "ggSpin2Mh10") {
		m_processA = "ggSpin2Mh10";
	} else if (processA == "qqSpin2Mh10") {
		m_processA = "qqSpin2Mh10";
	} else if (processA == "Spin2Mh10") {
		m_processA = "Spin2Mh10";
	} else if (processA == "ggSpin2") {
		m_processA = "ggSpin2";
	} else if (processA == "qqSpin2") {
		m_processA = "qqSpin2";
	} else if (processA == "Spin2") {
		m_processA = "Spin2";
	}

	else if (processA == "ggSpin0Pm_2f") {
		m_processA = "ggSpin0Pm_2f";
	} // Spin-0-to-2-leptons models
	else if (processA == "Spin0Pm_2f") {
		m_processA = "Spin0Pm_2f";
	} else if (processA == "ggSpin0M_2f") {
		m_processA = "ggSpin0M_2f";
	} else if (processA == "Spin0M_2f") {
		m_processA = "Spin0M_2f";
	}
	// 	else if( processA=="ggSpin0_2f" )
	// {m_processA="ggSpin0_2f";
	// }
	// 	else if( processA==  "Spin0_2f" )											{m_processA=
	// "Spin0_2f";
	// }

	else if (processA == "qqSpin1P_2f") {
		m_processA = "qqSpin1P_2f";
	} // Spin-1-to-2-leptons models
	else if (processA == "Spin1P_2f") {
		m_processA = "Spin1P_2f";
	} else if (processA == "qqSpin1M_2f") {
		m_processA = "qqSpin1M_2f";
	} else if (processA == "Spin1M_2f") {
		m_processA = "Spin1M_2f";
	}
	// 	else if( processA=="qqSpin1_2f" )
	// {m_processA="qqSpin1_2f";
	// }
	// 	else if( processA==  "Spin1_2f" )											{m_processA=
	// "Spin1_2f";
	// }

	else if (processA == "ggSpin2Pm_2f") {
		m_processA = "ggSpin2Pm_2f";
	} // Spin-2-to-2-leptons models
	else if (processA == "qqSpin2Pm_2f") {
		m_processA = "qqSpin2Pm_2f";
	} else if (processA == "Spin2Pm_2f") {
		m_processA = "Spin2Pm_2f";
	}
	// 	else if( processA=="ggSpin2_2f" )
	// {m_processA="ggSpin2_2f";
	// }
	// 	else if( processA=="qqSpin2_2f" )
	// {m_processA="qqSpin2_2f";
	// }
	// 	else if( processA==  "Spin2_2f" )											{m_processA=
	// "Spin2_2f";
	// }

	else if (processA == "qqZ4l_Background") {
		m_processA = "qqZ4l_Background";
	} // Z->4l models
	else if (processA == "qqZ4l_Signal") {
		m_processA = "qqZ4l_Signal";
	} else
		return EXIT_ERROR_PROCESS;

	/// check if processB is supported, translation of namings
	if (processB == "Custom") {
		m_processB = "Custom";
	} // Parameter-card-defined model

	else if (processB == "qqZZ" || processB == "ZZ") {
		m_processB = "qqZZ";
	} // "Background"
	else if (processB == "qqDY") {
		m_processB = "qqDY";
	} // "Background"
	else if (processB == "DY") {
		m_processB = "DY";
	}

	else if (processB == "Higgs" || processB == "SMHiggs" ||
			 processB == "ggSpin0Pm") {
		m_processB = "ggSpin0Pm";
	} // Spin-0 models
	else if (processB == "Spin0Pm") {
		m_processB = "Spin0Pm";
	} else if (processB == "CP-odd" || processB == "Higgs0M" ||
			   processB == "ggSpin0M") {
		m_processB = "ggSpin0M";
	} else if (processB == "Spin0M") {
		m_processB = "Spin0M";
	} else if (processB == "ggSpin0PH" || processB == "ggSpin0Ph") {
		m_processB = "ggSpin0Ph";
	} else if (processB == "Spin0Ph") {
		m_processB = "Spin0Ph";
	} else if (processB == "ggSpin0") {
		m_processB = "ggSpin0";
	} else if (processB == "Spin0") {
		m_processB = "Spin0";
	}

	else if (processB == "qqSpin1P") {
		m_processB = "qqSpin1P";
	} // Spin-1 models
	else if (processB == "Spin1P") {
		m_processB = "Spin1P";
	} else if (processB == "qqSpin1M") {
		m_processB = "qqSpin1M";
	} else if (processB == "Spin1M") {
		m_processB = "Spin1M";
	} else if (processB == "qqSpin1") {
		m_processB = "qqSpin1";
	} else if (processB == "Spin1") {
		m_processB = "Spin1";
	}

	else if (processB == "ggSpin2PM" || processB == "Graviton2PM" ||
			 processB == "ggSpin2Pm") {
		m_processB = "ggSpin2Pm";
	} // Spin-2 models
	else if (processB == "qqSpin2PM" || processB == "qqGraviton2PM" ||
			 processB == "qqSpin2Pm") {
		m_processB = "qqSpin2Pm";
	} else if (processB == "Spin2Pm") {
		m_processB = "Spin2Pm";
	} else if (processB == "ggSpin2Ph") {
		m_processB = "ggSpin2Ph";
	} else if (processB == "qqSpin2Ph") {
		m_processB = "qqSpin2Ph";
	} else if (processB == "Spin2Ph") {
		m_processB = "Spin2Ph";
	} else if (processB == "ggSpin2Mh") {
		m_processB = "ggSpin2Mh";
	} else if (processB == "qqSpin2Mh") {
		m_processB = "qqSpin2Mh";
	} else if (processB == "Spin2Mh") {
		m_processB = "Spin2Mh";
	} else if (processB == "ggSpin2Pb") {
		m_processB = "ggSpin2Pb";
	} else if (processB == "qqSpin2Pb") {
		m_processB = "qqSpin2Pb";
	} else if (processB == "Spin2Pb") {
		m_processB = "Spin2Pb";
	} else if (processB == "ggSpin2Ph2") {
		m_processB = "ggSpin2Ph2";
	} else if (processB == "qqSpin2Ph2") {
		m_processB = "qqSpin2Ph2";
	} else if (processB == "Spin2Ph2") {
		m_processB = "Spin2Ph2";
	} else if (processB == "ggSpin2Ph3") {
		m_processB = "ggSpin2Ph3";
	} else if (processB == "qqSpin2Ph3") {
		m_processB = "qqSpin2Ph3";
	} else if (processB == "Spin2Ph3") {
		m_processB = "Spin2Ph3";
	} else if (processB == "ggSpin2Ph6") {
		m_processB = "ggSpin2Ph6";
	} else if (processB == "qqSpin2Ph6") {
		m_processB = "qqSpin2Ph6";
	} else if (processB == "Spin2Ph6") {
		m_processB = "Spin2Ph6";
	} else if (processB == "ggSpin2Ph7") {
		m_processB = "ggSpin2Ph7";
	} else if (processB == "qqSpin2Ph7") {
		m_processB = "qqSpin2Ph7";
	} else if (processB == "Spin2Ph7") {
		m_processB = "Spin2Ph7";
	} else if (processB == "ggSpin2Mh9") {
		m_processB = "ggSpin2Mh9";
	} else if (processB == "qqSpin2Mh9") {
		m_processB = "qqSpin2Mh9";
	} else if (processB == "Spin2Mh9") {
		m_processB = "Spin2Mh9";
	} else if (processB == "ggSpin2Mh10") {
		m_processB = "ggSpin2Mh10";
	} else if (processB == "qqSpin2Mh10") {
		m_processB = "qqSpin2Mh10";
	} else if (processB == "Spin2Mh10") {
		m_processB = "Spin2Mh10";
	} else if (processB == "ggSpin2") {
		m_processB = "ggSpin2";
	} else if (processB == "qqSpin2") {
		m_processB = "qqSpin2";
	} else if (processB == "Spin2") {
		m_processB = "Spin2";
	}

	else if (processB == "ggSpin0Pm_2f") {
		m_processB = "ggSpin0Pm_2f";
	} // Spin-0-to-2-leptons models
	else if (processB == "Spin0Pm_2f") {
		m_processB = "Spin0Pm_2f";
	} else if (processB == "ggSpin0M_2f") {
		m_processB = "ggSpin0M_2f";
	} else if (processB == "Spin0M_2f") {
		m_processB = "Spin0M_2f";
	}
	// 	else if( processB=="ggSpin0_2f" )
	// {m_processB="ggSpin0_2f";
	// }
	// 	else if( processB==  "Spin0_2f" )											{m_processB=
	// "Spin0_2f";
	// }

	else if (processB == "qqSpin1P_2f") {
		m_processB = "qqSpin1P_2f";
	} // Spin-1-to-2-leptons models
	else if (processB == "Spin1P_2f") {
		m_processB = "Spin1P_2f";
	} else if (processB == "qqSpin1M_2f") {
		m_processB = "qqSpin1M_2f";
	} else if (processB == "Spin1M_2f") {
		m_processB = "Spin1M_2f";
	}
	// 	else if( processB=="qqSpin1_2f" )
	// {m_processB="qqSpin1_2f";
	// }
	// 	else if( processB==  "Spin1_2f" )											{m_processB=
	// "Spin1_2f";
	// }

	else if (processB == "ggSpin2Pm_2f") {
		m_processB = "ggSpin2Pm_2f";
	} // Spin-2-to-2-leptons models
	else if (processB == "qqSpin2Pm_2f") {
		m_processB = "qqSpin2Pm_2f";
	} else if (processB == "Spin2Pm_2f") {
		m_processB = "Spin2Pm_2f";
	}
	// 	else if( processB=="ggSpin2_2f" )
	// {m_processB="ggSpin2_2f";
	// }
	// 	else if( processB=="qqSpin2_2f" )
	// {m_processB="qqSpin2_2f";
	// }
	// 	else if( processB==  "Spin2_2f" )											{m_processB=
	// "Spin2_2f";
	// }

	else if (processB == "qqZ4l_Background") {
		m_processB = "qqZ4l_Background";
	} // Z->4l models
	else if (processB == "qqZ4l_Signal") {
		m_processB = "qqZ4l_Signal";
	} else
		return EXIT_ERROR_PROCESS;

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD from precalculated MEs for input prcesses A and
/// B
///------------------------------------------------------------------------
int MEKD::computeKD(string processA, string processB, double &kd,
					double &me2processA, double &me2processB)
{
	int return_code;
	/// Sanity check for input process names
	if ((return_code = setProcessNames(processA, processB)) != 0)
		return return_code;

	/// Looking for the precalculated MEs
	if (ME_ZZ == 0) {
		cerr << "ERROR! The requested process has not been precalculated.\n";
		return EXIT_ERROR_PROCESS;
	} else if (m_processA == "ZZ")
		me2processA = ME_ZZ;
	else if (m_processA == "ggSpin0Pm")
		me2processA = ME_Spin0PSMH;
	else if (m_processA == "ggSpin0M")
		me2processA = ME_Spin0M;
	else if (m_processA == "ggSpin0Ph")
		me2processA = ME_Spin0Ph;
	else if (m_processA == "qqSpin1P")
		me2processA = ME_Spin1P;
	else if (m_processA == "qqSpin1M")
		me2processA = ME_Spin1M;
	else if (m_processA == "ggSpin2Pm")
		me2processA = ME_ggSpin2Pm;
	else if (m_processA == "qqSpin2Pm")
		me2processA = ME_qqSpin2Pm;
	else {
		cerr << "ERROR! The requested process has not been precalculated.\n";
		return EXIT_ERROR_PROCESS;
	}

	/// Looking for the precalculated MEs
	if (ME_ZZ == 0) {
		cerr << "ERROR! The requested process has not been precalculated.\n";
		return EXIT_ERROR_PROCESS;
	} else if (m_processB == "ZZ")
		me2processB = ME_ZZ;
	else if (m_processB == "ggSpin0Pm")
		me2processB = ME_Spin0PSMH;
	else if (m_processB == "ggSpin0M")
		me2processB = ME_Spin0M;
	else if (m_processB == "ggSpin0Ph")
		me2processB = ME_Spin0Ph;
	else if (m_processB == "qqSpin1P")
		me2processB = ME_Spin1P;
	else if (m_processB == "qqSpin1M")
		me2processB = ME_Spin1M;
	else if (m_processB == "ggSpin2Pm")
		me2processB = ME_ggSpin2Pm;
	else if (m_processB == "qqSpin2Pm")
		me2processB = ME_qqSpin2Pm;
	else {
		cerr << "ERROR! The requested process has not been precalculated.\n";
		return EXIT_ERROR_PROCESS;
	}

	/// Build Kinematic Discriminant (KD) as a ratio of logs of MEs
	kd = log(me2processA / me2processB);

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for input prcesses A and B
///------------------------------------------------------------------------
int MEKD::computeKD(string processA, string processB, double lept1P[],
					int lept1Id, double lept2P[], int lept2Id, double lept3P[],
					int lept3Id, double lept4P[], int lept4Id, double &kd,
					double &me2processA, double &me2processB)
{
	/// Load internal containers
	four_particle_Ps_i[0] = lept1P;
	four_particle_Ps_i[1] = lept2P;
	four_particle_Ps_i[2] = lept3P;
	four_particle_Ps_i[3] = lept4P;

	four_particle_IDs_i[0] = lept1Id;
	four_particle_IDs_i[1] = lept2Id;
	four_particle_IDs_i[2] = lept3Id;
	four_particle_IDs_i[3] = lept4Id;

	return computeKD(processA, processB, four_particle_Ps_i,
					 four_particle_IDs_i, kd, me2processA, me2processB);
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for the input processes A and B
///------------------------------------------------------------------------
int MEKD::computeKD(string processA, string processB, vector<double *> input_Ps,
					vector<int> input_IDs, double &kd, double &me2processA,
					double &me2processB)
{
	int return_code;
	/// Checks input for compatibility
	if (input_Ps.size() != input_IDs.size())
		return EXIT_ERROR_INPUT;
	if (input_Ps.size() < 2 || input_Ps.size() > 5)
		return EXIT_ERROR_INPUT;

	/// Sanity check for input process names and internal parameters
	if ((return_code = setProcessNames(processA, processB)) != 0)
		return return_code;
	if ((return_code = processParameters()) != 0)
		return return_code;

	/// Set input-particle kinematics
	p1 = input_Ps[0];
	id1 = input_IDs[0];
	p2 = input_Ps[1];
	id2 = input_IDs[1];
	if (input_IDs.size() >= 3) {
		p3 = input_Ps[2];
		id3 = input_IDs[2];
	} else
		id3 = 0;
	if (input_IDs.size() >= 4) {
		p4 = input_Ps[3];
		id4 = input_IDs[3];
	} else
		id4 = 0;
	if (input_IDs.size() >= 5) {
		p5 = input_Ps[4];
		id5 = input_IDs[4];
	} else
		id5 = 0;

	/// Compute ME for process A only (e.g. signal 1)
	return_code = Run(m_processA);
	/// Get ME for process A
	me2processA = Signal_ME;

	/// Compute ME for process B only (e.g. signal 2 or background)
	return_code = Run(m_processB);
	/// Get ME for process B
	me2processB = Signal_ME;
	/// Build Kinematic Discriminant (KD) as a ratio of logs of MEs
	kd = log(me2processA / me2processB);

	return return_code;
}

///------------------------------------------------------------------------
/// MEKD::computeME - compute ME for the input process
///------------------------------------------------------------------------
int MEKD::computeME(string processName, vector<double *> input_Ps,
					vector<int> input_IDs, double &me2process)
{
	int return_code;
	/// Checks input for compatibility
	if (input_Ps.size() != input_IDs.size())
		return EXIT_ERROR_INPUT;
	if (input_Ps.size() < 2 || input_Ps.size() > 5)
		return EXIT_ERROR_INPUT;

	/// Sanity check for input process names and internal parameters
	if ((return_code = setProcessName(processName)) != 0)
		return return_code;
	if ((return_code = processParameters()) != 0)
		return return_code;

	/// Set input-particle kinematics
	p1 = input_Ps[0];
	id1 = input_IDs[0];
	p2 = input_Ps[1];
	id2 = input_IDs[1];
	if (input_IDs.size() >= 3) {
		p3 = input_Ps[2];
		id3 = input_IDs[2];
	} else
		id3 = 0;
	if (input_IDs.size() >= 4) {
		p4 = input_Ps[3];
		id4 = input_IDs[3];
	} else
		id4 = 0;
	if (input_IDs.size() >= 5) {
		p5 = input_Ps[4];
		id5 = input_IDs[4];
	} else
		id5 = 0;

	/// Compute ME for the process (e.g. signal 1)
	return_code = Run(m_process);
	/// Get ME for the process
	me2process = Signal_ME;

	return return_code;
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(double lept1P[], int lept1Id, double lept2P[], int lept2Id,
					 double lept3P[], int lept3Id, double lept4P[], int lept4Id)
{
	/// Load internal containers
	four_particle_Ps_i[0] = lept1P;
	four_particle_Ps_i[1] = lept2P;
	four_particle_Ps_i[2] = lept3P;
	four_particle_Ps_i[3] = lept4P;

	four_particle_IDs_i[0] = lept1Id;
	four_particle_IDs_i[1] = lept2Id;
	four_particle_IDs_i[2] = lept3Id;
	four_particle_IDs_i[3] = lept4Id;

	return computeMEs(four_particle_Ps_i, four_particle_IDs_i);
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(vector<double *> input_Ps, vector<int> input_IDs)
{
	int return_code;
	/// Checks input for compatibility
	if (input_Ps.size() != input_IDs.size())
		return EXIT_ERROR_INPUT;
	if (input_Ps.size() < 2 || input_Ps.size() > 5)
		return EXIT_ERROR_INPUT;
	
	/// Sanity check for internal parameters
	if ((return_code = processParameters()) != 0)
		return return_code;

	/// Parameterize MEKD
	// Fills in "interesting" models to compute only once
	if (Test_Models.size() == 0)
	{
		Test_Models.push_back("ZZ");
		Test_Models.push_back("ggSpin0Pm");
		Test_Models.push_back("ggSpin0M");
		Test_Models.push_back("ggSpin0Ph");
		Test_Models.push_back("qqSpin1P");
		Test_Models.push_back("qqSpin1M");
		Test_Models.push_back("ggSpin2Pm");
		Test_Models.push_back("qqSpin2Pm");
	} else if (Test_Models.size() != 4)
		return EXIT_ERROR_PROCESS;

	/// Set input-particle kinematics
	p1 = input_Ps[0];
	id1 = input_IDs[0];
	p2 = input_Ps[1];
	id2 = input_IDs[1];
	if (input_IDs.size() >= 3) {
		p3 = input_Ps[2];
		id3 = input_IDs[2];
	} else
		id3 = 0;
	if (input_IDs.size() >= 4) {
		p4 = input_Ps[3];
		id4 = input_IDs[3];
	} else
		id4 = 0;
	if (input_IDs.size() >= 5) {
		p5 = input_Ps[4];
		id5 = input_IDs[4];
	} else
		id5 = 0;

	/// Compute MEs
	return_code = Run();

	/// ME value readouts
	ME_ZZ = Signal_MEs[0];
	ME_Spin0PSMH = Signal_MEs[1];
	ME_Spin0M = Signal_MEs[2];
	ME_Spin0Ph = Signal_MEs[3];
	ME_Spin1P = Signal_MEs[4];
	ME_Spin1M = Signal_MEs[5];
	ME_ggSpin2Pm = Signal_MEs[6];
	ME_qqSpin2Pm = Signal_MEs[7];

	return return_code;
}

///------------------------------------------------------------------------
/// Mixed-state ME mixer of production like qqSpin1M, qqSpin1P, exotic, exotic
/// pseudo, and decay like Spin1M, Spin1P states, corresponding couplings
/// rhoQ11, rhoQ12, rhoQ13, rhoQ14, b1z/rhomu11, b2z/rhomu12, rhomu13, rhomu14.
///------------------------------------------------------------------------
int MEKD::Mix_Spin0(complex<double> Spin0Pm_relamp,
					complex<double> Spin0Ph_relamp,
					complex<double> Spin0Phexo_relamp,
					complex<double> Spin0M_relamp)
{
	m_Mixing_Coefficients_Spin0[0] = Spin0Pm_relamp;
	m_Mixing_Coefficients_Spin0[1] = Spin0Ph_relamp;
	m_Mixing_Coefficients_Spin0[2] = Spin0Phexo_relamp;
	m_Mixing_Coefficients_Spin0[3] = Spin0M_relamp;

	if (m_Mixing_Coefficients_Spin0 == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// Mixed-state ME mixer of production like qqSpin1M, qqSpin1P, exotic, exotic
/// pseudo, and decay like Spin1M, Spin1P states, corresponding couplings
/// rhoQ11, rhoQ12, rhoQ13, rhoQ14, b1z/rhomu11, b2z/rhomu12, rhomu13, rhomu14.
///------------------------------------------------------------------------
int MEKD::Mix_Spin1(complex<double> prod_Spin1M_relamp,
					complex<double> prod_Spin1P_relamp,
					complex<double> prod_Spin1Mexo_relamp,
					complex<double> prod_Spin1Pexo_relamp,
					complex<double> dec_Spin1M_relamp,
					complex<double> dec_Spin1P_relamp,
					complex<double> dec_Spin1_rhomu13_relamp,
					complex<double> dec_Spin1_rhomu14_relamp)
{
	m_Mixing_Coefficients_Spin1[0] = prod_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[1] = prod_Spin1P_relamp;
	m_Mixing_Coefficients_Spin1[2] = prod_Spin1Mexo_relamp;
	m_Mixing_Coefficients_Spin1[3] = prod_Spin1Pexo_relamp;
	m_Mixing_Coefficients_Spin1[4] = dec_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[5] = dec_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[6] = dec_Spin1_rhomu13_relamp;
	m_Mixing_Coefficients_Spin1[7] = dec_Spin1_rhomu14_relamp;

	if (m_Mixing_Coefficients_Spin1 == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// Mixed-state ME mixer of Spin-2 states. Production couplings: k1g/rhoQ21,
/// ..., k4g/rhoQ24, ..., k10g, decay couplings: k1z/rhomu21, k4z/rhomu24, ...,
/// k10z.
///------------------------------------------------------------------------
int MEKD::Mix_Spin2(complex<double> *prod_Spin2_relamp,
					complex<double> *dec_Spin2_relamp)
{
	for (unsigned int i = 0; i < 10; ++i)
		m_Mixing_Coefficients_Spin2[i] = prod_Spin2_relamp[i];
	for (unsigned int i = 10; i < 20; ++i)
		m_Mixing_Coefficients_Spin2[i] = dec_Spin2_relamp[i];

	if (m_Mixing_Coefficients_Spin2 == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

#if (defined(MEKD_STANDALONE) && defined(MEKD_with_ROOT)) ||                   \
	!(defined(MEKD_STANDALONE))
///------------------------------------------------------------------------
/// (ROOT-compatabile overloads)
///------------------------------------------------------------------------

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for the input processes A and B
///------------------------------------------------------------------------
int MEKD::computeKD(TString processA, TString processB, TLorentzVector lept1P,
					int lept1Id, TLorentzVector lept2P, int lept2Id,
					TLorentzVector lept3P, int lept3Id, TLorentzVector lept4P,
					int lept4Id, double &kd, double &me2processA,
					double &me2processB)
{
	/// Prepare 4-momenta in the required format
	lept1P_i[0] = lept1P.E();
	lept1P_i[1] = lept1P.Px();
	lept1P_i[2] = lept1P.Py();
	lept1P_i[3] = lept1P.Pz();

	lept2P_i[0] = lept2P.E();
	lept2P_i[1] = lept2P.Px();
	lept2P_i[2] = lept2P.Py();
	lept2P_i[3] = lept2P.Pz();

	lept3P_i[0] = lept3P.E();
	lept3P_i[1] = lept3P.Px();
	lept3P_i[2] = lept3P.Py();
	lept3P_i[3] = lept3P.Pz();

	lept4P_i[0] = lept4P.E();
	lept4P_i[1] = lept4P.Px();
	lept4P_i[2] = lept4P.Py();
	lept4P_i[3] = lept4P.Pz();

	/// Load internal containers
	four_particle_Ps_i[0] = lept1P_i;
	four_particle_Ps_i[1] = lept2P_i;
	four_particle_Ps_i[2] = lept3P_i;
	four_particle_Ps_i[3] = lept4P_i;

	four_particle_IDs_i[0] = lept1Id;
	four_particle_IDs_i[1] = lept2Id;
	four_particle_IDs_i[2] = lept3Id;
	four_particle_IDs_i[3] = lept4Id;

	return computeKD((string)processA.Data(), (string)processB.Data(),
					 four_particle_Ps_i, four_particle_IDs_i, kd, me2processA,
					 me2processB);
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for the input processes A and B
///------------------------------------------------------------------------
int MEKD::computeKD(TString processA, TString processB,
					vector<TLorentzVector> input_Ps, vector<int> input_IDs,
					double &kd, double &me2processA, double &me2processB)
{
	/// Resize internal vector<double*> if needed
	if (input_Ps_i.size() != input_Ps.size()) {
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			delete input_Ps_i[i];
			input_Ps_i[i] = NULL;
		}
		input_Ps_i.resize(input_Ps.size(), NULL);
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			input_Ps_i[i] = new double[4];
		}
	}

	/// Put vector<TLorentzVector> into internal containers
	for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
		input_Ps_i[i][0] = input_Ps[i].E();
		input_Ps_i[i][1] = input_Ps[i].Px();
		input_Ps_i[i][2] = input_Ps[i].Py();
		input_Ps_i[i][3] = input_Ps[i].Pz();
	}

	return computeKD((string)processA.Data(), (string)processB.Data(),
					 input_Ps_i, input_IDs, kd, me2processA, me2processB);
}

///------------------------------------------------------------------------
/// MEKD::computeME - compute ME for the input process
///------------------------------------------------------------------------
int MEKD::computeME(TString processName, vector<TLorentzVector> input_Ps,
					vector<int> input_IDs, double &me2process)
{
	/// Resize internal vector<double*> if needed
	if (input_Ps_i.size() != input_Ps.size()) {
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			delete input_Ps_i[i];
			input_Ps_i[i] = NULL;
		}
		input_Ps_i.resize(input_Ps.size(), NULL);
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			input_Ps_i[i] = new double[4];
		}
	}

	/// Put vector<TLorentzVector> into internal containers
	for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
		input_Ps_i[i][0] = input_Ps[i].E();
		input_Ps_i[i][1] = input_Ps[i].Px();
		input_Ps_i[i][2] = input_Ps[i].Py();
		input_Ps_i[i][3] = input_Ps[i].Pz();
	}

	return computeME((string)processName.Data(), input_Ps_i, input_IDs,
					 me2process);
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(TLorentzVector lept1P, int lept1Id, TLorentzVector lept2P,
					 int lept2Id, TLorentzVector lept3P, int lept3Id,
					 TLorentzVector lept4P, int lept4Id)
{
	/// Prepare 4-momenta in the required format
	lept1P_i[0] = lept1P.E();
	lept1P_i[1] = lept1P.Px();
	lept1P_i[2] = lept1P.Py();
	lept1P_i[3] = lept1P.Pz();

	lept2P_i[0] = lept2P.E();
	lept2P_i[1] = lept2P.Px();
	lept2P_i[2] = lept2P.Py();
	lept2P_i[3] = lept2P.Pz();

	lept3P_i[0] = lept3P.E();
	lept3P_i[1] = lept3P.Px();
	lept3P_i[2] = lept3P.Py();
	lept3P_i[3] = lept3P.Pz();

	lept4P_i[0] = lept4P.E();
	lept4P_i[1] = lept4P.Px();
	lept4P_i[2] = lept4P.Py();
	lept4P_i[3] = lept4P.Pz();

	/// Load internal containers
	four_particle_Ps_i[0] = lept1P_i;
	four_particle_Ps_i[1] = lept2P_i;
	four_particle_Ps_i[2] = lept3P_i;
	four_particle_Ps_i[3] = lept4P_i;

	four_particle_IDs_i[0] = lept1Id;
	four_particle_IDs_i[1] = lept2Id;
	four_particle_IDs_i[2] = lept3Id;
	four_particle_IDs_i[3] = lept4Id;

	return computeMEs(four_particle_Ps_i, four_particle_IDs_i);
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(vector<TLorentzVector> input_Ps, vector<int> input_IDs)
{
	/// Resize internal vector<double*> if needed
	if (input_Ps_i.size() != input_Ps.size()) {
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			delete input_Ps_i[i];
			input_Ps_i[i] = NULL;
		}
		input_Ps_i.resize(input_Ps.size(), NULL);
		for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
			input_Ps_i[i] = new double[4];
		}
	}

	/// Put vector<TLorentzVector> into internal containers
	for (unsigned int i = 0; i < input_Ps_i.size(); ++i) {
		input_Ps_i[i][0] = input_Ps[i].E();
		input_Ps_i[i][1] = input_Ps[i].Px();
		input_Ps_i[i][2] = input_Ps[i].Py();
		input_Ps_i[i][3] = input_Ps[i].Pz();
	}

	return computeMEs(input_Ps_i, input_IDs);
}

//////////////////////////////////////////////////////////////////////////
#endif // end of (defined(MEKD_STANDALONE) && defined(MEKD_with_ROOT)) ||
	   // !(defined(MEKD_STANDALONE))

/// end of namespace
}

#endif // end of MEKD_MEKD_cpp
