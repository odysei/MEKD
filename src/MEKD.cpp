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

// idata.p(7, new double[4]), => some problems ???
MEKD::MEKD()
{
	Set_default_params();

	Check_MEs();

	idata.fp.reserve(5);
	idata.fp.push_back(new double[4]);
	idata.fp.push_back(new double[4]);
	idata.fp.push_back(new double[4]);
	idata.fp.push_back(new double[4]);
	idata.fp.push_back(new double[4]); // a photon comes here, otherwise, unused

	idata.p.reserve(7);
	idata.p.push_back(new double[4]);  // in parton 1
	idata.p.push_back(new double[4]);  // in parton 2
    for (auto i: idata.fp)
        idata.p.push_back(i);

	idata.id.resize(5, 10000); // idata.id.reserve(5);
    
    idata.mix_coeffs_Spin0 = NULL;
    idata.mix_coeffs_Spin1 = NULL;
    idata.mix_coeffs_Spin2 = NULL;

// 	p1 = new double[4];
// 	p2 = new double[4];
// 	p3 = new double[4];
// 	p4 = new double[4];
// 	p5 = new double[4];
// 
// 	id1 = 10000;
// 	id2 = 10000;
// 	id3 = 10000;
// 	id4 = 10000;
// 	id5 = 10000;
/*
	pl1_internal = NULL;
	pl2_internal = NULL;
	pl3_internal = NULL;
	pl4_internal = NULL;
	pA1_internal = NULL;*/
}

/*
 * MEKD::MEKD - Version 2 or earlier constructor
 */
MEKD::MEKD(const double &collision_energy, const string &PDF_name): MEKD()
{
	param.sqrt_s = collision_energy * 1000;	// translate TeV to GeV
	m_PDFName = PDF_name;

	ME_ZZ = 0;
	ME_Spin0PSMH = 0;
	ME_Spin0Ph = 0;
	ME_Spin0M = 0;
	ME_Spin1P = 0;
	ME_Spin1M = 0;
	ME_ggSpin2Pm = 0;
	ME_qqSpin2Pm = 0;
}

MEKD::~MEKD()
{
	if (param.loaded)
		Unload_pdfreader();

	idata.p.clear();
	idata.id.clear();
	
	for (auto runner: ME_runners)
		delete runner;
	ME_runners.clear();
}

int MEKD::Load_parameters(parameters &pa, data &da)
{
	params_MG.read_slha_file(pa.params_MG_file);
    
	/// Initializing parameters
	if (!pa.loaded)
		Load_parameters_MEs(pa.params_MG_file);	// init MEs
	Load_parameters_extract_params(params_MG, da);
	Load_parameters_eval_params(da, pa);
	Normalize_parton_coeffs(pa);
	
	if (pa.loaded)
		Unload_pdfreader();
	Load_pdfreader(const_cast<char *>(pa.PDF_file.c_str()));

	pa.loaded = true;
	return 0;
}

int MEKD::Reload_params(parameters &pa, data &da)
{
	if (!pa.loaded)
		return 1;

	return Load_parameters(pa, da);
}

void MEKD::eval_MEs(const input_c &in, vector<double> &ME2)
{
    input trimmed_in;
    trimmed_in.p = in.p;
    trimmed_in.id = in.id;
    
    // linking pointers
    idata.mix_coeffs_Spin0 = const_cast<complex<double> *>(
        in.mix_coeffs_Spin0);
    idata.mix_coeffs_Spin1 = const_cast<complex<double> *>(
        in.mix_coeffs_Spin1);
    idata.mix_coeffs_Spin2 = const_cast<complex<double> *>(
        in.mix_coeffs_Spin2);
    
	eval_MEs(trimmed_in, ME2);
    
    // clearing links
    idata.mix_coeffs_Spin0 = NULL;
    idata.mix_coeffs_Spin1 = NULL;
    idata.mix_coeffs_Spin2 = NULL;
}

void MEKD::eval_MEs(const input &in, vector<double> &ME2)
{
	if (ME2.size() != ME_runners.size())
		ME2.resize(ME_runners.size(), 0);
    
    {
        const unsigned int in_id_size = (*in.id).size();
        const unsigned int size = idata.id.size();
        
        for (unsigned int i = 0; i < size; ++i) {
            if (i < in_id_size) {
                idata.id[i] = (*in.id)[i];
                idata.fp[i][0] = (*in.p)[i][0];
                idata.fp[i][1] = (*in.p)[i][1];
                idata.fp[i][2] = (*in.p)[i][2];
                idata.fp[i][3] = (*in.p)[i][3];
            } else {
                idata.id[i] = 10000;
                idata.fp[i][0] = 0;
                idata.fp[i][1] = 0;
                idata.fp[i][2] = 0;
                idata.fp[i][3] = 0;
            }
        }
    }
	
	if (!param.loaded)
		Load_parameters(param, idata);
	if (Arrange_4momenta(idata) == 1) {	// loads&arranges plX_internal
		cerr << "Particle id error. Exiting.\n";
		exit(1);
	}
	
	Background_ME = 0;
	Signal_ME = 0;
	
	Run_make_p(idata);

	const int range[2] = {2, 6}; 
	idata.m.sys = Get_sys_m(idata.p, range);
	
	if (flag.per_event_parton_coeffs && !flag.Use_PDF_w_pT0)
		Normalize_parton_coeffs(param);
	
	if (flag.Debug_Mode) {
		cout << "4-momenta entering ME(E px py px):\n";
		Print_4momenta(idata.p);
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
		Print_4momenta(idata.p);
	}
}

int MEKD::Run(const input &in)
{
    // linking pointers. Version 2 or earlier compatibility hack
    idata.mix_coeffs_Spin0 = m_Mixing_Coefficients_Spin0;
    idata.mix_coeffs_Spin1 = m_Mixing_Coefficients_Spin1;
    idata.mix_coeffs_Spin2 = m_Mixing_Coefficients_Spin2;
    
    {
        const unsigned int in_id_size = (*in.id).size();
        const unsigned int size = idata.id.size();
        
        for (unsigned int i = 0; i < size; ++i) {
            if (i < in_id_size) {
                idata.id[i] = (*in.id)[i];
                idata.fp[i][0] = (*in.p)[i][0];
                idata.fp[i][1] = (*in.p)[i][1];
                idata.fp[i][2] = (*in.p)[i][2];
                idata.fp[i][3] = (*in.p)[i][3];
            } else {
                idata.id[i] = 10000;
                idata.fp[i][0] = 0;
                idata.fp[i][1] = 0;
                idata.fp[i][2] = 0;
                idata.fp[i][3] = 0;
            }
        }
    }
    
	if (!param.loaded)
		Load_parameters(param, idata);
	if (Arrange_4momenta(idata) == 1) {	// loads&arranges plX_internal
		cerr << "Particle id error. Exiting.\n";
		exit(1);
	}

	Background_ME = 0;
	Signal_ME = 0;
	
	Run_make_p(idata);

	const int range[2] = {2, 6}; 
	idata.m.sys = Get_sys_m(idata.p, range);
	
	if (flag.per_event_parton_coeffs && !flag.Use_PDF_w_pT0)
		Normalize_parton_coeffs(param);
	
	if (flag.Debug_Mode) {
		cout << "4-momenta entering ME(E px py px):\n";
		Print_4momenta(idata.p);
	}
	
	Run_calculate(idata);
	
	if (flag.Debug_Mode) {
		cout << "4-momenta after ME(E px py px) calculations:\n";
		Print_4momenta(idata.p);
	}
	
	// clearing links. Version 2 or earlier compatibility hack
    idata.mix_coeffs_Spin0 = NULL;
    idata.mix_coeffs_Spin1 = NULL;
    idata.mix_coeffs_Spin2 = NULL;

	return 0;
}

int MEKD::Run(const input &in, string Input_Model)
{
	const string buff = Test_Model;
	Test_Model = "!";
	Test_Model += Input_Model;

	int error_value = Run(in);

	Test_Model = buff;
	return error_value;
}

void MEKD::Run_make_p(data &da)
{
	if (flag.Overwrite_e_and_mu_masses) {
		params_MG.set_block_entry("mass", 11, param.Electron_mass);
		params_MG.set_block_entry("mass", 13, param.Muon_mass);
		da.m.e = param.Electron_mass;
		da.m.mu = param.Muon_mass;
	}

	Load_p_set(da);	// load 4-momenta from plX_internal
	
    /// Calculate values needed for the PDF in the pT=0 frame
	da.PDFx1 = Get_PDF_x1(da.p);
	da.PDFx2 = Get_PDF_x2(da.p);
	if (flag.Debug_Mode) {
		printf("Coefficients for PDF (x1, x2): (%.10E, %.10E)\n",
			   da.PDFx1, da.PDFx2);
	}
    
	/// If flag is true, boost to CM frame iff PDF is NOT included.
	if (flag.Boost_To_CM && !flag.Use_PDF_w_pT0) {
        Run_make_p_boost(0, da);
		const double collision_E = da.p[2][0] + da.p[3][0] + da.p[4][0] +
                                   da.p[5][0] + da.p[6][0];
		da.p[0][0] = 0.5 * collision_E;
		da.p[1][0] = 0.5 * collision_E;
	} else {
        if (flag.Use_PDF_w_pT0)
            Run_make_p_boost(1, da);
		Approx_neg_z_parton(da.p[0], da.PDFx1 * param.sqrt_s);
		Approx_pos_z_parton(da.p[1], da.PDFx2 * param.sqrt_s);
	}
}

// int = 0: CM; 1: pT0
void MEKD::Run_make_p_boost(const int mode, data &da)
{
	if (da.fs == final_4e || da.fs == final_4eA) {
		const double m = params_MG.get_block_entry("mass", 11,
                                                   param.Electron_mass).real();
        
        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], m, da.p[4],
                     m, da.p[5], 0, da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], m, da.p[4],
                           m, da.p[5], 0, da.p[6]);
            return;
        }
    }
    
	if (da.fs == final_4mu || da.fs == final_4muA) {
		const double m = params_MG.get_block_entry("mass", 13,
                                                   param.Muon_mass).real();
        
        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], m, da.p[4],
                     m, da.p[5], 0, da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], m, da.p[4],
                           m, da.p[5], 0, da.p[6]);
            return;
        }
    }
    
	if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
		const double m1 = params_MG.get_block_entry("mass", 11,
                                                   param.Electron_mass).real();
		const double m2 = params_MG.get_block_entry("mass", 13,
                                                    param.Muon_mass).real();
        
        if (mode == 0) {
            Boost2CM(m1, da.p[2], m1, da.p[3], m2, da.p[4],
                     m2, da.p[5], 0, da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m1, da.p[2], m1, da.p[3], m2, da.p[4],
                           m2, da.p[5], 0, da.p[6]);
            return;
        }
    }
    
	if (da.fs == final_2mu || da.fs == final_2muA) {
		const double m = params_MG.get_block_entry("mass", 13,
                                                   param.Muon_mass).real();
        
        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], 0, da.p[4],
                     0, da.p[5], 0, da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], 0, da.p[4],
                           0, da.p[5], 0, da.p[6]);
            return;
        }
	}
	
    cerr << "MAYDAY!!! Undefined behavior!\n";
    exit(1);
}

void MEKD::Run_calculate(data &da)
{
	/// Background is interesting in any case, except for the Signal Runs or '!'
	/// is indicated in the first model to save CPU
	process_description d;
	if (Test_Model[0] != '!' && Test_Models.size() == 0) {
		d.production = prod_qq;
		Run_ME_Configurator_BKG_ZZ(d, da);
		Background_ME = Signal_ME;
	} else if (Test_Models.size() > 0) {
		if (Test_Models[0][0] != '!') {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d, da);
			Background_ME = Signal_ME;
		}
	}

	string *model = NULL;
	/// Signal ME(s) is(are) chosen here
	if (Test_Models.size() > 0 && Test_Model[0] != '!') {
		if (Signal_MEs.size() != Test_Models.size())
			Signal_MEs.resize(Test_Models.size());
		fill(Signal_MEs.begin(), Signal_MEs.end(), 0);
		model = &(Test_Models[0]); // Should be NULL or undefined
                                   // before this point; works as
                                   // counter=0
	} else
		model = &Test_Model;	   // Should be NULL or undefined
                                   // before this point

	unsigned int counter = 1;
	while (model != NULL) {
		// Is it a parameter card defined?
		if ((*model) == "Custom" ||
			(*model) == "!Custom")
			Run_ME_Configurator_Custom(da);

		// Is it a "background"?
		else if ((*model) == "qqZZ" ||
				 (*model) == "!qqZZ") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d, da);
		} else if ((*model) == "ZZ" ||
			(*model) == "!ZZ") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d, da);
		}

		else if ((*model) == "qqDY" ||
				 (*model) == "!qqDY") {
			d.production = prod_qq;
			Run_ME_Configurator_BKG_ZZ(d, da);
		}
		else if ((*model) == "DY" ||
			(*model) == "!DY") {
			d.production = prod_no;
			Run_ME_Configurator_BKG_ZZ(d, da);
		}

		// Is it a Z boson resonance?
		else if ((*model) == "qqZ4l_Background" ||
				 (*model) == "!qqZ4l_Background") {
			d.production = prod_qq;
			Run_ME_Configurator_Z4l_BKG(d, da);
		} else if ((*model) == "qqZ4l_Signal" ||
				 (*model) == "!qqZ4l_Signal") {
			d.production = prod_qq;
			Run_ME_Configurator_Z4l_SIG(d, da);
		}

		/// Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
		/// Final states: 4 leptons (+photon) also 2 muons (+photon)
		d.decay = decay_ZZ;

		// Is it a spin-0 resonance?
		if ((*model) == "ggSpin0Pm" ||
			(*model) == "!ggSpin0Pm") { // SM Higgs
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Pm(d, da);
		} else if ((*model) == "Spin0Pm" ||
				 (*model) == "!Spin0Pm") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Pm(d, da);
		}

		else if ((*model) == "ggSpin0M" ||
				 (*model) == "!ggSpin0M") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0M(d, da);
		} else if ((*model) == "Spin0M" ||
				 (*model) == "!Spin0M") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0M(d, da);
		}

		else if ((*model) == "ggSpin0Ph" ||
				 (*model) == "!ggSpin0Ph") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Ph(d, da);
		} else if ((*model) == "Spin0Ph" ||
				 (*model) == "!Spin0Ph") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Ph(d, da);
		}

		else if ((*model) == "ggSpin0" ||
				 (*model) == "!ggSpin0") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0(d, da, params_MG);
		} else if ((*model) == "Spin0" ||
				 (*model) == "!Spin0") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0(d, da, params_MG);
		}

		// Is it a spin-1 resonance?
		else if ((*model) == "qqSpin1M" ||
				 (*model) == "!qqSpin1M") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1M(d, da);
		} else if ((*model) == "Spin1M" ||
				 (*model) == "!Spin1M"){
			d.production = prod_no;
			Run_ME_Configurator_Spin1M(d, da);
		}

		else if ((*model) == "qqSpin1P" ||
				 (*model) == "!qqSpin1P") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1P(d, da);
		} else if ((*model) == "Spin1P" ||
				 (*model) == "!Spin1P") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1P(d, da);
		}

		else if ((*model) == "qqSpin1" ||
				 (*model) == "!qqSpin1") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1(d, da, params_MG);
		} else if ((*model) == "Spin1" ||
				 (*model) == "!Spin1") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1(d, da, params_MG);
		}

		// Is it a spin-2 resonance?
		else if ((*model) == "ggSpin2Pm" ||
				 (*model) == "!ggSpin2Pm") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "qqSpin2Pm" ||
				 (*model) == "!qqSpin2Pm") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "Spin2Pm" ||
				 (*model) == "!Spin2Pm") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d, da);
		}

		else if ((*model) == "ggSpin2Ph" ||
				 (*model) == "!ggSpin2Ph") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph(d, da);
		} else if ((*model) == "qqSpin2Ph" ||
				 (*model) == "!qqSpin2Ph") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph(d, da);
		} else if ((*model) == "Spin2Ph" ||
				 (*model) == "!Spin2Ph") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph(d, da);
		}

		else if ((*model) == "ggSpin2Mh" ||
				 (*model) == "!ggSpin2Mh") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh(d, da);
		} else if ((*model) == "qqSpin2Mh" ||
				 (*model) == "!qqSpin2Mh") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh(d, da);
		} else if ((*model) == "Spin2Mh" ||
				 (*model) == "!Spin2Mh") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh(d, da);
		}

		else if ((*model) == "ggSpin2Pb" ||
				 (*model) == "!ggSpin2Pb") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pb(d, da);
		} else if ((*model) == "qqSpin2Pb" ||
				 (*model) == "!qqSpin2Pb") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pb(d, da);
		} else if ((*model) == "Spin2Pb" ||
				 (*model) == "!Spin2Pb") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pb(d, da);
		}

		else if ((*model) == "ggSpin2Ph2" ||
				 (*model) == "!ggSpin2Ph2") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph2(d, da);
		} else if ((*model) == "qqSpin2Ph2" ||
				 (*model) == "!qqSpin2Ph2") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph2(d, da);
		} else if ((*model) == "Spin2Ph2" ||
				 (*model) == "!Spin2Ph2") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph2(d, da);
		}

		else if ((*model) == "ggSpin2Ph3" ||
				 (*model) == "!ggSpin2Ph3") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph3(d, da);
		} else if ((*model) == "qqSpin2Ph3" ||
				 (*model) == "!qqSpin2Ph3") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph3(d, da);
		} else if ((*model) == "Spin2Ph3" ||
				 (*model) == "!Spin2Ph3") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph3(d, da);
		}

		else if ((*model) == "ggSpin2Ph6" ||
				 (*model) == "!ggSpin2Ph6") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph6(d, da);
		} else if ((*model) == "qqSpin2Ph6" ||
				 (*model) == "!qqSpin2Ph6") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph6(d, da);
		} else if ((*model) == "Spin2Ph6" ||
				 (*model) == "!Spin2Ph6") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph6(d, da);
		}

		else if ((*model) == "ggSpin2Ph7" ||
				 (*model) == "!ggSpin2Ph7") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Ph7(d, da);
		} else if ((*model) == "qqSpin2Ph7" ||
				 (*model) == "!qqSpin2Ph7") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Ph7(d, da);
		} else if ((*model) == "Spin2Ph7" ||
				 (*model) == "!Spin2Ph7") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Ph7(d, da);
		}

		else if ((*model) == "ggSpin2Mh9" ||
				 (*model) == "!ggSpin2Mh9") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh9(d, da);
		} else if ((*model) == "qqSpin2Mh9" ||
				 (*model) == "!qqSpin2Mh9") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh9(d, da);
		} else if ((*model) == "Spin2Mh9" ||
				 (*model) == "!Spin2Mh9") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh9(d, da);
		}

		else if ((*model) == "ggSpin2Mh10" ||
				 (*model) == "!ggSpin2Mh10") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Mh10(d, da);
		} else if ((*model) == "qqSpin2Mh10" ||
				 (*model) == "!qqSpin2Mh10") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Mh10(d, da);
		} else if ((*model) == "Spin2Mh10" ||
				 (*model) == "!Spin2Mh10") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Mh10(d, da);
		}

		else if ((*model) == "ggSpin2" ||
				 (*model) == "!ggSpin2") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2(d, da, params_MG);
		} else if ((*model) == "qqSpin2" ||
				 (*model) == "!qqSpin2") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2(d, da, params_MG);
		} else if ((*model) == "Spin2" ||
				 (*model) == "!Spin2") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2(d, da, params_MG);
		}

		/// Resonance to 2l decay modes. Final states: 4 leptons (+photon)
		d.decay = decay_2f;

		// Is it a spin-0 resonance?
		if ((*model) == "ggSpin0Pm_2f" ||
			(*model) == "!ggSpin0Pm_2f") { // SM Higgs
			d.production = prod_gg;
			Run_ME_Configurator_Spin0Pm(d, da);
		} else if ((*model) == "Spin0Pm_2f" ||
				 (*model) == "!Spin0Pm_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0Pm(d, da);
		}

		else if ((*model) == "ggSpin0M_2f" ||
				 (*model) == "!ggSpin0M_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0M(d, da);
		} else if ((*model) == "Spin0M_2f" ||
				 (*model) == "!Spin0M_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0M(d, da);
		}

		else if ((*model) == "ggSpin0_2f" ||
				 (*model) == "!ggSpin0_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin0(d, da, params_MG);
		} else if ((*model) == "Spin0_2f" ||
				 (*model) == "!Spin0_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin0(d, da, params_MG);
		}

		// Is it a spin-1 resonance?
		else if ((*model) == "qqSpin1M_2f" ||
				 (*model) == "!qqSpin1M_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1M(d, da);
		} else if ((*model) == "Spin1M" ||
				 (*model) == "!Spin1M_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1M(d, da);
		}

		else if ((*model) == "qqSpin1P_2f" ||
				 (*model) == "!qqSpin1P_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1P(d, da);
		} else if ((*model) == "Spin1P_2f" ||
				 (*model) == "!Spin1P_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1P(d, da);
		}

		else if ((*model) == "qqSpin1_2f" ||
				 (*model) == "!qqSpin1_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin1(d, da, params_MG);
		} else if ((*model) == "Spin1_2f" ||
				 (*model) == "!Spin1_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin1(d, da, params_MG);
		}

		// Is it a spin-2 resonance?
		else if ((*model) == "ggSpin2Pm_2f" ||
				 (*model) == "!ggSpin2Pm_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "qqSpin2Pm_2f" ||
				 (*model) == "!qqSpin2Pm_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "Spin2Pm_2f" ||
				 (*model) == "!Spin2Pm_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d, da);
		}

		else if ((*model) == "ggSpin2_2f" ||
				 (*model) == "!ggSpin2_2f") {
			d.production = prod_gg;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "qqSpin2_2f" ||
				 (*model) == "!qqSpin2_2f") {
			d.production = prod_qq;
			Run_ME_Configurator_Spin2Pm(d, da);
		} else if ((*model) == "Spin2_2f" ||
				 (*model) == "!Spin2_2f") {
			d.production = prod_no;
			Run_ME_Configurator_Spin2Pm(d, da);
		}

		// Is it a RAW MG5_aMC ME?
		if ((*model) == "ggCPPProcess" ||
			(*model) == "!ggCPPProcess") { // ME_RAW
			d.production = prod_gg;
			Run_ME_Configurator_CPPProcess(d, da);
		} else if ((*model) == "qqCPPProcess" ||
				 (*model) == "!qqCPPProcess") {
			d.production = prod_qq;
			Run_ME_Configurator_CPPProcess(d, da);
		} else if ((*model) == "CPPProcess" ||
				 (*model) == "!CPPProcess") {
			d.production = prod_no;
			Run_ME_Configurator_CPPProcess(d, da);
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

void MEKD::Load_p_set(data &da)
{
	for (unsigned int i = 0; i < 4; ++i) {
		da.p[0][i] = 0;
		da.p[1][i] = 0;
	}
	
	for (unsigned int i = 0; i < da.fp.size(); ++i)
        da.p[i + 2] = da.fp[i];
}

// exact mT/sqrt_s * (e^eta3 + e^eta4), mt=sqrt(m^2+pT^2), 12 -> 34
double MEKD::Get_PDF_x1(const vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) +
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / param.sqrt_s;
}

// exact mT/sqrt_s * (e^-eta3 + e^-eta4), mt=sqrt(m^2+pT^2), 12 -> 34
double MEKD::Get_PDF_x2(const vector<double *> &p)
{
	return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) -
			(p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) / param.sqrt_s;
}

double MEKD::Get_sys_m(const vector<double *> &p, const int p_range[2])
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

void MEKD::Normalize_parton_coeffs(parameters &pa)
{
	double buffer_ = (param.parton_coeff_d + param.parton_coeff_u +
					  param.parton_coeff_s + param.parton_coeff_c);
	
	param.parton_coeff_d = param.parton_coeff_d / buffer_;
	param.parton_coeff_u = param.parton_coeff_u / buffer_;
	param.parton_coeff_c = param.parton_coeff_c / buffer_;
	param.parton_coeff_s = param.parton_coeff_s / buffer_;
}

void MEKD::Approx_neg_z_parton(double *p, const double E)
{
	// 0-mass approximation
	p[0] = 0.5 * E;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0.5 * E; // to be recalculated
}

void MEKD::Approx_pos_z_parton(double *p, const double E)
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
	flag.Use_PDF_w_pT0 = (m_PDFName == "CTEQ6L");

	/// Check if sqrt(s) is 7 or 8 TeV
	if (param.sqrt_s != 7000 && param.sqrt_s != 8000)
		cerr << "WARNING! You have set energy to be " << param.sqrt_s/1000
			 << " TeV\n";

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// MEKD::setProcessName - sanity check and setting of process names
///------------------------------------------------------------------------
int MEKD::setProcessName(const string &process)
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
int MEKD::setProcessNames(const string &processA, const string &processB)
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
int MEKD::computeKD(const string &processA, const string &processB,
                    double &kd, double &me2processA, double &me2processB)
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
int MEKD::computeKD(const string &processA, const string &processB,
                    const double lept1P[], const int lept1Id,
                    const double lept2P[], const int lept2Id,
                    const double lept3P[], const int lept3Id,
                    const double lept4P[], const int lept4Id,
                    double &kd, double &me2processA, double &me2processB)
{
	vector<double *> p(4);
    vector<int> id(4);
    
	/// Load temp containers
	p[0] = const_cast<double *>(lept1P);
	p[1] = const_cast<double *>(lept2P);
	p[2] = const_cast<double *>(lept3P);
	p[3] = const_cast<double *>(lept4P);

	id[0] = lept1Id;
	id[1] = lept2Id;
	id[2] = lept3Id;
	id[3] = lept4Id;

	return computeKD(processA, processB, p, id,
                     kd, me2processA, me2processB);
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for the input processes A and B
///------------------------------------------------------------------------
int MEKD::computeKD(const string &processA, const string &processB,
                    const vector<double *> &input_Ps,
					const vector<int> &input_IDs, double &kd,
					double &me2processA, double &me2processB)
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
    input in;
    in.p = const_cast<vector<double *> *>(&input_Ps);
    in.id = const_cast<vector<int> *>(&input_IDs);

	/// Compute ME for process A only (e.g. signal 1)
	return_code = Run(in, m_processA);
	/// Get ME for process A
	me2processA = Signal_ME;

	/// Compute ME for process B only (e.g. signal 2 or background)
	return_code = Run(in, m_processB);
	/// Get ME for process B
	me2processB = Signal_ME;
	/// Build Kinematic Discriminant (KD) as a ratio of logs of MEs
	kd = log(me2processA / me2processB);

	return return_code;
}

///------------------------------------------------------------------------
/// MEKD::computeME - compute ME for the input process
///------------------------------------------------------------------------
int MEKD::computeME(const string &processName,
                    const vector<double *> &input_Ps,
					const vector<int> &input_IDs, double &me2process)
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
    input in;
    in.p = const_cast<vector<double *> *>(&input_Ps);
    in.id = const_cast<vector<int> *>(&input_IDs);

	/// Compute ME for the process (e.g. signal 1)
	return_code = Run(in, m_process);
	/// Get ME for the process
	me2process = Signal_ME;

	return return_code;
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(const double lept1P[], const int lept1Id,
                     const double lept2P[], const int lept2Id,
					 const double lept3P[], const int lept3Id,
                     const double lept4P[], const int lept4Id)
{
    vector<double *> p(4);
    vector<int> id(4);
    
	/// Load temp containers
	p[0] = const_cast<double *>(lept1P);
	p[1] = const_cast<double *>(lept2P);
	p[2] = const_cast<double *>(lept3P);
	p[3] = const_cast<double *>(lept4P);

	id[0] = lept1Id;
	id[1] = lept2Id;
	id[2] = lept3Id;
	id[3] = lept4Id;

	return computeMEs(p, id);
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(const vector<double *> &input_Ps,
                     const vector<int> &input_IDs)
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
    input in;
    in.p = const_cast<vector<double *> *>(&input_Ps);
    in.id = const_cast<vector<int> *>(&input_IDs);

	/// Compute MEs
	return_code = Run(in);

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
int MEKD::Mix_Spin0(const complex<double> Spin0Pm_relamp,
					const complex<double> Spin0Ph_relamp,
					const complex<double> Spin0Phexo_relamp,
					const complex<double> Spin0M_relamp)
{
	m_Mixing_Coefficients_Spin0[0] = Spin0Pm_relamp;
	m_Mixing_Coefficients_Spin0[1] = Spin0Ph_relamp;
	m_Mixing_Coefficients_Spin0[2] = Spin0Phexo_relamp;
	m_Mixing_Coefficients_Spin0[3] = Spin0M_relamp;

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// Mixed-state ME mixer of production like qqSpin1M, qqSpin1P, exotic, exotic
/// pseudo, and decay like Spin1M, Spin1P states, corresponding couplings
/// rhoQ11, rhoQ12, rhoQ13, rhoQ14, b1z/rhomu11, b2z/rhomu12, rhomu13, rhomu14.
///------------------------------------------------------------------------
int MEKD::Mix_Spin1(const complex<double> prod_Spin1M_relamp,
					const complex<double> prod_Spin1P_relamp,
					const complex<double> prod_Spin1Mexo_relamp,
					const complex<double> prod_Spin1Pexo_relamp,
					const complex<double> dec_Spin1M_relamp,
					const complex<double> dec_Spin1P_relamp,
					const complex<double> dec_Spin1_rhomu13_relamp,
					const complex<double> dec_Spin1_rhomu14_relamp)
{
	m_Mixing_Coefficients_Spin1[0] = prod_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[1] = prod_Spin1P_relamp;
	m_Mixing_Coefficients_Spin1[2] = prod_Spin1Mexo_relamp;
	m_Mixing_Coefficients_Spin1[3] = prod_Spin1Pexo_relamp;
	m_Mixing_Coefficients_Spin1[4] = dec_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[5] = dec_Spin1M_relamp;
	m_Mixing_Coefficients_Spin1[6] = dec_Spin1_rhomu13_relamp;
	m_Mixing_Coefficients_Spin1[7] = dec_Spin1_rhomu14_relamp;

	return EXIT_SUCCESS;
}

///------------------------------------------------------------------------
/// Mixed-state ME mixer of Spin-2 states. Production couplings: k1g/rhoQ21,
/// ..., k4g/rhoQ24, ..., k10g, decay couplings: k1z/rhomu21, k4z/rhomu24, ...,
/// k10z.
///------------------------------------------------------------------------
int MEKD::Mix_Spin2(const complex<double> *prod_Spin2_relamp,
					const complex<double> *dec_Spin2_relamp)
{
	for (unsigned int i = 0; i < 10; ++i)
		m_Mixing_Coefficients_Spin2[i] = prod_Spin2_relamp[i];
	for (unsigned int i = 10; i < 20; ++i)
		m_Mixing_Coefficients_Spin2[i] = dec_Spin2_relamp[i];

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
int MEKD::computeKD(const TString &processA, const TString &processB,
                    const TLorentzVector &lept1P, const int lept1Id,
                    const TLorentzVector &lept2P, const int lept2Id,
					const TLorentzVector &lept3P, const int lept3Id,
                    const TLorentzVector &lept4P, const int lept4Id,
                    double &kd, double &me2processA, double &me2processB)
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

    vector<double *> p(4);
    vector<int> id(4);
    
	/// Load temp containers
	p[0] = lept1P_i;
	p[1] = lept2P_i;
	p[2] = lept3P_i;
	p[3] = lept4P_i;

	id[0] = lept1Id;
	id[1] = lept2Id;
	id[2] = lept3Id;
	id[3] = lept4Id;

	return computeKD((string)processA.Data(), (string)processB.Data(),
					 p, id, kd, me2processA, me2processB);
}

///------------------------------------------------------------------------
/// MEKD::computeKD - compute KD and MEs for the input processes A and B
///------------------------------------------------------------------------
int MEKD::computeKD(const TString &processA, const TString &processB,
					const vector<TLorentzVector> &input_Ps,
                    const vector<int> &input_IDs,
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
int MEKD::computeME(const TString &processName,
                    const vector<TLorentzVector> &input_Ps,
					const vector<int> &input_IDs, double &me2process)
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
int MEKD::computeMEs(const TLorentzVector &lept1P, const int lept1Id,
                     const TLorentzVector &lept2P, const int lept2Id,
                     const TLorentzVector &lept3P, const int lept3Id,
					 const TLorentzVector &lept4P, const int lept4Id)
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

	vector<double *> p(4);
    vector<int> id(4);
    
	/// Load temp containers
	p[0] = lept1P_i;
	p[1] = lept2P_i;
	p[2] = lept3P_i;
	p[3] = lept4P_i;

	id[0] = lept1Id;
	id[1] = lept2Id;
	id[2] = lept3Id;
	id[3] = lept4Id;

	return computeMEs(p, id);
}

///------------------------------------------------------------------------
/// MEKD::computeMEs - compute MEs for a multiple reuse
///------------------------------------------------------------------------
int MEKD::computeMEs(const vector<TLorentzVector> &input_Ps,
                     const vector<int> &input_IDs)
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
