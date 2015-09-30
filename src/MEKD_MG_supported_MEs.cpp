///////////////////////////////////
/// Part responsible for        ///
/// momenta rearrangement       ///
///////////////////////////////////
#ifndef MEKD_MG_supported_MEs_cpp
#define MEKD_MG_supported_MEs_cpp

#include "../interface/MEKD_MG.h"

namespace mekd
{


// 	while (Test_Model_buffer != NULL) {
// 		// Is it a parameter card defined?
// 		if ((*Test_Model_buffer) == "Custom" ||
// 			(*Test_Model_buffer) == "!Custom")
// 			Run_MEKD_MG_ME_Configurator_Custom();
// 
// 		// Is it a "background"?
// 		else if ((*Test_Model_buffer) == "qqZZ" ||
// 				 (*Test_Model_buffer) == "!qqZZ")
// 			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
// 		else if ((*Test_Model_buffer) == "ZZ" || (*Test_Model_buffer) == "!ZZ")
// 			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
// 
// 		else if ((*Test_Model_buffer) == "qqDY" ||
// 				 (*Test_Model_buffer) == "!qqDY")
// 			Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
// 		else if ((*Test_Model_buffer) == "DY" || (*Test_Model_buffer) == "!DY")
// 			Run_MEKD_MG_ME_Configurator_BKG_ZZ("NO");
// 
// 		// Is it a Z boson resonance?
// 		else if ((*Test_Model_buffer) == "qqZ4l_Background" ||
// 				 (*Test_Model_buffer) == "!qqZ4l_Background")
// 			Run_MEKD_MG_ME_Configurator_Z4l_BKG("qq");
// 		else if ((*Test_Model_buffer) == "qqZ4l_Signal" ||
// 				 (*Test_Model_buffer) == "!qqZ4l_Signal")
// 			Run_MEKD_MG_ME_Configurator_Z4l_SIG("qq");
// 
// 		/// Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
// 		/// Final states: 4 leptons (+photon) also 2 muons (+photon)
// 		Resonance_decay_mode = "ZZ";
// 
// 		// Is it a spin-0 resonance?
// 		if ((*Test_Model_buffer) == "ggSpin0Pm" ||
// 			(*Test_Model_buffer) == "!ggSpin0Pm") // SM Higgs
// 			Run_MEKD_MG_ME_Configurator_Spin0Pm("gg");
// 		else if ((*Test_Model_buffer) == "Spin0Pm" ||
// 				 (*Test_Model_buffer) == "!Spin0Pm")
// 			Run_MEKD_MG_ME_Configurator_Spin0Pm("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin0M" ||
// 				 (*Test_Model_buffer) == "!ggSpin0M")
// 			Run_MEKD_MG_ME_Configurator_Spin0M("gg");
// 		else if ((*Test_Model_buffer) == "Spin0M" ||
// 				 (*Test_Model_buffer) == "!Spin0M")
// 			Run_MEKD_MG_ME_Configurator_Spin0M("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin0Ph" ||
// 				 (*Test_Model_buffer) == "!ggSpin0Ph")
// 			Run_MEKD_MG_ME_Configurator_Spin0Ph("gg");
// 		else if ((*Test_Model_buffer) == "Spin0Ph" ||
// 				 (*Test_Model_buffer) == "!Spin0Ph")
// 			Run_MEKD_MG_ME_Configurator_Spin0Ph("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin0" ||
// 				 (*Test_Model_buffer) == "!ggSpin0")
// 			Run_MEKD_MG_ME_Configurator_Spin0("gg");
// 		else if ((*Test_Model_buffer) == "Spin0" ||
// 				 (*Test_Model_buffer) == "!Spin0")
// 			Run_MEKD_MG_ME_Configurator_Spin0("NO");
// 
// 		// Is it a spin-1 resonance?
// 		else if ((*Test_Model_buffer) == "qqSpin1M" ||
// 				 (*Test_Model_buffer) == "!qqSpin1M")
// 			Run_MEKD_MG_ME_Configurator_Spin1M("qq");
// 		else if ((*Test_Model_buffer) == "Spin1M" ||
// 				 (*Test_Model_buffer) == "!Spin1M")
// 			Run_MEKD_MG_ME_Configurator_Spin1M("NO");
// 
// 		else if ((*Test_Model_buffer) == "qqSpin1P" ||
// 				 (*Test_Model_buffer) == "!qqSpin1P")
// 			Run_MEKD_MG_ME_Configurator_Spin1P("qq");
// 		else if ((*Test_Model_buffer) == "Spin1P" ||
// 				 (*Test_Model_buffer) == "!Spin1P")
// 			Run_MEKD_MG_ME_Configurator_Spin1P("NO");
// 
// 		else if ((*Test_Model_buffer) == "qqSpin1" ||
// 				 (*Test_Model_buffer) == "!qqSpin1")
// 			Run_MEKD_MG_ME_Configurator_Spin1("qq");
// 		else if ((*Test_Model_buffer) == "Spin1" ||
// 				 (*Test_Model_buffer) == "!Spin1")
// 			Run_MEKD_MG_ME_Configurator_Spin1("NO");
// 
// 		// Is it a spin-2 resonance?
// 		else if ((*Test_Model_buffer) == "ggSpin2Pm" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Pm")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Pm" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Pm")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Pm" ||
// 				 (*Test_Model_buffer) == "!Spin2Pm")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Ph" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Ph")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Ph" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Ph")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Ph" ||
// 				 (*Test_Model_buffer) == "!Spin2Ph")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Mh" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Mh")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Mh" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Mh")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Mh" ||
// 				 (*Test_Model_buffer) == "!Spin2Mh")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Pb" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Pb")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pb("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Pb" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Pb")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pb("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Pb" ||
// 				 (*Test_Model_buffer) == "!Spin2Pb")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pb("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Ph2" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Ph2")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph2("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Ph2" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Ph2")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph2("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Ph2" ||
// 				 (*Test_Model_buffer) == "!Spin2Ph2")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph2("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Ph3" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Ph3")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph3("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Ph3" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Ph3")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph3("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Ph3" ||
// 				 (*Test_Model_buffer) == "!Spin2Ph3")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph3("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Ph6" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Ph6")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph6("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Ph6" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Ph6")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph6("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Ph6" ||
// 				 (*Test_Model_buffer) == "!Spin2Ph6")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph6("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Ph7" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Ph7")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph7("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Ph7" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Ph7")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph7("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Ph7" ||
// 				 (*Test_Model_buffer) == "!Spin2Ph7")
// 			Run_MEKD_MG_ME_Configurator_Spin2Ph7("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Mh9" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Mh9")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh9("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Mh9" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Mh9")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh9("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Mh9" ||
// 				 (*Test_Model_buffer) == "!Spin2Mh9")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh9("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2Mh10" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Mh10")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh10("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Mh10" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Mh10")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh10("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Mh10" ||
// 				 (*Test_Model_buffer) == "!Spin2Mh10")
// 			Run_MEKD_MG_ME_Configurator_Spin2Mh10("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2" ||
// 				 (*Test_Model_buffer) == "!ggSpin2")
// 			Run_MEKD_MG_ME_Configurator_Spin2("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2" ||
// 				 (*Test_Model_buffer) == "!qqSpin2")
// 			Run_MEKD_MG_ME_Configurator_Spin2("qq");
// 		else if ((*Test_Model_buffer) == "Spin2" ||
// 				 (*Test_Model_buffer) == "!Spin2")
// 			Run_MEKD_MG_ME_Configurator_Spin2("NO");
// 
// 		/// Resonance to 2l decay modes. Final states: 4 leptons (+photon)
// 		Resonance_decay_mode = "2l";
// 
// 		// Is it a spin-0 resonance?
// 		if ((*Test_Model_buffer) == "ggSpin0Pm_2f" ||
// 			(*Test_Model_buffer) == "!ggSpin0Pm_2f") // SM Higgs
// 			Run_MEKD_MG_ME_Configurator_Spin0Pm("gg");
// 		else if ((*Test_Model_buffer) == "Spin0Pm_2f" ||
// 				 (*Test_Model_buffer) == "!Spin0Pm_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin0Pm("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin0M_2f" ||
// 				 (*Test_Model_buffer) == "!ggSpin0M_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin0M("gg");
// 		else if ((*Test_Model_buffer) == "Spin0M_2f" ||
// 				 (*Test_Model_buffer) == "!Spin0M_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin0M("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin0_2f" ||
// 				 (*Test_Model_buffer) == "!ggSpin0_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin0("gg");
// 		else if ((*Test_Model_buffer) == "Spin0_2f" ||
// 				 (*Test_Model_buffer) == "!Spin0_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin0("NO");
// 
// 		// Is it a spin-1 resonance?
// 		else if ((*Test_Model_buffer) == "qqSpin1M_2f" ||
// 				 (*Test_Model_buffer) == "!qqSpin1M_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1M("qq");
// 		else if ((*Test_Model_buffer) == "Spin1M" ||
// 				 (*Test_Model_buffer) == "!Spin1M_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1M("NO");
// 
// 		else if ((*Test_Model_buffer) == "qqSpin1P_2f" ||
// 				 (*Test_Model_buffer) == "!qqSpin1P_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1P("qq");
// 		else if ((*Test_Model_buffer) == "Spin1P_2f" ||
// 				 (*Test_Model_buffer) == "!Spin1P_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1P("NO");
// 
// 		else if ((*Test_Model_buffer) == "qqSpin1_2f" ||
// 				 (*Test_Model_buffer) == "!qqSpin1_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1("qq");
// 		else if ((*Test_Model_buffer) == "Spin1_2f" ||
// 				 (*Test_Model_buffer) == "!Spin1_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin1("NO");
// 
// 		// Is it a spin-2 resonance?
// 		else if ((*Test_Model_buffer) == "ggSpin2Pm_2f" ||
// 				 (*Test_Model_buffer) == "!ggSpin2Pm_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2Pm_2f" ||
// 				 (*Test_Model_buffer) == "!qqSpin2Pm_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
// 		else if ((*Test_Model_buffer) == "Spin2Pm_2f" ||
// 				 (*Test_Model_buffer) == "!Spin2Pm_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
// 
// 		else if ((*Test_Model_buffer) == "ggSpin2_2f" ||
// 				 (*Test_Model_buffer) == "!ggSpin2_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
// 		else if ((*Test_Model_buffer) == "qqSpin2_2f" ||
// 				 (*Test_Model_buffer) == "!qqSpin2_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
// 		else if ((*Test_Model_buffer) == "Spin2_2f" ||
// 				 (*Test_Model_buffer) == "!Spin2_2f")
// 			Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
// 
// 		// Is it a RAW MG5_aMC ME?
// 		if ((*Test_Model_buffer) == "ggCPPProcess" ||
// 			(*Test_Model_buffer) == "!ggCPPProcess") // ME_RAW
// 			Run_MEKD_MG_ME_Configurator_CPPProcess("gg");
// 		else if ((*Test_Model_buffer) == "qqCPPProcess" ||
// 				 (*Test_Model_buffer) == "!qqCPPProcess")
// 			Run_MEKD_MG_ME_Configurator_CPPProcess("qq");
// 		else if ((*Test_Model_buffer) == "CPPProcess" ||
// 				 (*Test_Model_buffer) == "!CPPProcess")
// 			Run_MEKD_MG_ME_Configurator_CPPProcess("NO");

class ME_runner_gg_Custom_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_Custom();
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Custom &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Z_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Z_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Zs_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_Z4l_SIG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zs &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Zt_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_Z4l_BKG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zt &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0Pm_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin0Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

void MEKD_MG::Load_ME_runners(vector<process_description> &desc)
{
	ME_runners.reserve(desc.size());	// speed up
	for (auto d: desc) {			// not very optimal loop but transparent
		if (Load_ME_runners_try(new ME_runner_qq_bkg_Z_ZZ_4l(),
								ME_runners, d) != NULL)
			continue;
		if (Load_ME_runners_try(new ME_runner_qq_bkg_Z_2f_4l(),
								ME_runners, d) != NULL)
			continue;
		if (Load_ME_runners_try(new ME_runner_qq_bkg_Zs_2f_4l(),
								ME_runners, d) != NULL)
			continue;
		if (Load_ME_runners_try(new ME_runner_qq_bkg_Zt_2f_4l(),
								ME_runners, d) != NULL)
			continue;
		
		
		if (Load_ME_runners_try(new ME_runner_gg_Spin0Pm_ZZ_4l(),
								ME_runners, d) != NULL)
			continue;
		
		cerr << "ME runner not found:\n"
			 << "process: " << d.process << endl
			 << "resonance: " << d.resonance << endl
			 << "production: " << d.production << endl
			 << "decay: " << d.decay << endl
			 << "final_state: " << d.final_state << endl;
		ME_runners.push_back(NULL);
	}
}

ME_runner* MEKD_MG::Load_ME_runners_try(ME_runner *runner,
										vector<ME_runner *> &v,
										const process_description &desc)
{
	if (runner->is_my_type(desc)) {
		v.push_back(runner);	// load if a correct one
		return runner;
	}
	
	delete runner;				// dismiss if not the one
	return NULL;
}

/// end of namespace
}

#endif

//////////////////////////////////////////
/// END OF MEKD_MG_supported_MEs.cpp   ///
//////////////////////////////////////////