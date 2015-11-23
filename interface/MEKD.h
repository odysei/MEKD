/*************************************************************************
*  Authors:   MEKD fans
*  More info: http://mekd.ihepa.ufl.edu
*  Contact:   odysei@cern.ch, mekd@phys.ufl.edu
*************************************************************************/
#ifndef MEKD_h
#define MEKD_h

// C++ includes
#include <cstdlib>

#if (defined MEKD_STANDALONE && defined MEKD_with_ROOT) || \
	!defined MEKD_STANDALONE
// ROOT includes
#include "TFile.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TROOT.h"
#include "TString.h"
#include "TTree.h"
#include "TTreeIndex.h"
#endif

// MEKD_MG merge
#include "MEKD_includes.h"

/* 
 * 
 * MEKD interface
 * 
 * Provides an interface to MadGraph_aMC@NLO-derived MEs and MEKD models behind
 * them.
 * 
 */

using namespace std;

namespace mekd
{

/// Part of pdfreader
extern "C" pdtStr pdtSg, pdtSd, pdtSu, pdtSs, pdtSc, pdtSad, pdtSau, pdtSas,
	pdtSac;

// #define PDTFILE "PDF_tables/cteq6l.pdt" // CalCHEP reads a table for CTEQ6L.
// You can change PDF set as you want.

class MEKD;

class ME_runner
{
public:
    virtual double evaluate(MEKD &in_MEKD, const input &in)
	{
		return -1;
	}
	
	virtual const process_description my_type()
	{
        process_description empty;
        empty.process = proc_empty;
        empty.resonance = reson_empty;
        empty.production = prod_empty;
        empty.decay = decay_empty;
        empty.final_state = final_empty;
        
		return empty;
	}
	
	virtual bool is_my_type(const process_description &in)
	{
		return false;
	}
	
	virtual bool initialize(const string &param_f)
    {
        return false;
    }
	
	bool compare_types(const process_description &in,
					   const process_description &in2)
	{
		return (in.process == in2.process &&
				in.resonance == in2.resonance &&
				in.production == in2.production &&
				in.decay == in2.decay &&
				in.final_state == in2.final_state);
	}
};

class MEKD
{
  public:
    void eval_MEs(const input_c &, vector<double> &);   // for custom coupl.
	void eval_MEs(const input &, vector<double> &);
	
	// new&internal. Will go to private:
	vector<ME_runner *> ME_runners;
	
	void Load_ME_runners(const vector<process_description> &);
	bool Load_ME_runners_try(const process_description &,
							 ME_runner *,
							 vector<ME_runner *> &);
	bool Load_ME_runners_try_Misc_4l(const process_description &,
									 vector<ME_runner *> &);
	bool Load_ME_runners_try_Misc_4lA(const process_description &,
									  vector<ME_runner *> &);
	bool Load_ME_runners_try_Z_4l(const process_description &,
								  vector<ME_runner *> &);
	bool Load_ME_runners_try_Z_4lA(const process_description &,
								   vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin0_4l(const process_description &,
									  vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin0_4lA(const process_description &,
									   vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin1_4l(const process_description &,
									  vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin1_4lA(const process_description &,
									   vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin2_4l(const process_description &,
									  vector<ME_runner *> &);
	bool Load_ME_runners_try_Spin2_4lA(const process_description &,
									   vector<ME_runner *> &);
    
	bool Load_ME_runners_try_Spin0_ttbb(const process_description &,
                                        vector<ME_runner *> &);
    
    void Initialize_ME_runners(const string &param_f, vector<ME_runner *> &);
	// end
	
	/// Flags
	flags flag;
	
	/// Parameters
	parameters param;

	/// Parameter container. For experts only
	SLHAReader_MEKD params_MG;
    
    /// Internal data
    data idata;

	/// String flags and file locations: Version 2 and earlier
	string Test_Model; // Models: ZZ, DY, Custom, CPevenScalar, ggSpin0Pm,
					   // ggSpin0M, ggSpin0Ph, qqSpin1P, qqSpin1M, ggSpin2Pm,
					   // ggSpin2Ph, ggSpin2Mh, ggSpin2Pb, qqSpin2Pm, qqSpin2Ph,
					   // qqSpin2Mh, qqSpin2Pb, Spin0Pm, Spin0M, Spin0Ph,
					   // Spin1P, Spin1M, Spin2Pm, Spin2Ph, Spin2Mh, Spin2Pb,
					   // qqZ4l_Signal, qqZ4l_Background
	vector<string> Test_Models; // same names as for the Test_Model

	/// Calculation results
	double Background_ME; // may not be used if running RUN(string) is chosen
	double Signal_ME;	 // is filled after running RUN_XXXX(...)
	vector<double> Signal_MEs; // is filled if Test_Models are set after running
							   // RUN_XXXX(...)

	/// Functions
// 	map<int, vector<double *>> Make_map(const vector<int> &,
//                                         const vector<double *> &);
	
	void Set_default_params();
	
	void Check_MEs();
	
	/// Run-related functions
	int Run(const input &);	// main routine to evaluate matrix elements; updates
				// "Calculation results"
	int Run(const input &, string Input_Model);	// Calculates a ME ONLY for a
                                            // chosen model; ignores automatic 
                                            // background calculation.
                                            // Updates Signal_ME
	void Run_make_p(data &);
    void Run_make_p_boost(const int, data &);    // int = 0: CM; 1: pT0
	void Run_calculate(data &);
	double Get_PDF_x1(const vector<double *> &p);
	double Get_PDF_x2(const vector<double *> &p);
	
	double Get_sys_m(const vector<double *> &p, const int p_range[2]);
	
	void Zero_first_two(vector<double *> &);
	void Approx_neg_z_parton(double *p, const double E);
	void Approx_pos_z_parton(double *p, const double E);
	void Normalize_parton_coeffs(parameters &);
	

	/// Constructors, destructors
	MEKD();
	MEKD(const vector<process_description> &desc): MEKD()
	{
		Load_ME_runners(desc);
	}
	~MEKD();

    /*
     * Temporary ME place. Should become a part of ME_runners
     */
	/// 4l final state (+photon)
qq_Z4l_SIG_DN_OF ME_qq_Z4l_SIG_DownType_OF;
qq_Z4l_SIG_DN_SF ME_qq_Z4l_SIG_DownType_SF;
qq_Z4l_SIG_UP_OF ME_qq_Z4l_SIG_UpType_OF;
qq_Z4l_SIG_UP_SF ME_qq_Z4l_SIG_UpType_SF;
qq_Z4l_SIG_DN_OFpA ME_qq_Z4l_SIG_DownType_OFpA;
qq_Z4l_SIG_DN_SFpA ME_qq_Z4l_SIG_DownType_SFpA;
qq_Z4l_SIG_UP_OFpA ME_qq_Z4l_SIG_UpType_OFpA;
qq_Z4l_SIG_UP_SFpA ME_qq_Z4l_SIG_UpType_SFpA;

qq_Z4l_BKG_DN_OF ME_qq_Z4l_BKG_DownType_OF;
qq_Z4l_BKG_DN_SF ME_qq_Z4l_BKG_DownType_SF;
qq_Z4l_BKG_UP_OF ME_qq_Z4l_BKG_UpType_OF;
qq_Z4l_BKG_UP_SF ME_qq_Z4l_BKG_UpType_SF;
qq_Z4l_BKG_DN_OFpA ME_qq_Z4l_BKG_DownType_OFpA;
qq_Z4l_BKG_DN_SFpA ME_qq_Z4l_BKG_DownType_SFpA;
qq_Z4l_BKG_UP_OFpA ME_qq_Z4l_BKG_UpType_OFpA;
qq_Z4l_BKG_UP_SFpA ME_qq_Z4l_BKG_UpType_SFpA;

qq_ZZ_DN_OF ME_qq_ZZ_DownType_OF;
qq_ZZ_DN_SF ME_qq_ZZ_DownType_SF;
qq_ZZ_UP_OF ME_qq_ZZ_UpType_OF;
qq_ZZ_UP_SF ME_qq_ZZ_UpType_SF;
qq_ZZ_DN_OFpA ME_qq_ZZ_DownType_OFpA;
qq_ZZ_DN_SFpA ME_qq_ZZ_DownType_SFpA;
qq_ZZ_UP_OFpA ME_qq_ZZ_UpType_OFpA;
qq_ZZ_UP_SFpA ME_qq_ZZ_UpType_SFpA;

gg_Spin0_OF ME_Signal_gg_Spin0_OF;
gg_Spin0_SF ME_Signal_gg_Spin0_SF;
gg_Spin0_OFpA ME_Signal_gg_Spin0_OFpA;
gg_Spin0_SFpA ME_Signal_gg_Spin0_SFpA;

// qq_Spin0_DN_OF ME_Signal_qq_Spin0_DownType_OF;
// qq_Spin0_DN_SF ME_Signal_qq_Spin0_DownType_SF;
// qq_Spin0_UP_OF ME_Signal_qq_Spin0_UpType_OF;
// qq_Spin0_UP_SF ME_Signal_qq_Spin0_UpType_SF;
// qq_Spin0_DN_OFpA ME_Signal_qq_Spin0_DownType_OFpA;
// qq_Spin0_DN_SFpA ME_Signal_qq_Spin0_DownType_SFpA;
// qq_Spin0_UP_OFpA ME_Signal_qq_Spin0_UpType_OFpA;
// qq_Spin0_UP_SFpA ME_Signal_qq_Spin0_UpType_SFpA;

qq_Spin1_DN_OF ME_Signal_qq_Spin1_DownType_OF;
qq_Spin1_DN_SF ME_Signal_qq_Spin1_DownType_SF;
qq_Spin1_UP_OF ME_Signal_qq_Spin1_UpType_OF;
qq_Spin1_UP_SF ME_Signal_qq_Spin1_UpType_SF;
qq_Spin1_DN_OFpA ME_Signal_qq_Spin1_DownType_OFpA;
qq_Spin1_DN_SFpA ME_Signal_qq_Spin1_DownType_SFpA;
qq_Spin1_UP_OFpA ME_Signal_qq_Spin1_UpType_OFpA;
qq_Spin1_UP_SFpA ME_Signal_qq_Spin1_UpType_SFpA;

gg_Spin2_OF ME_Signal_gg_Spin2_OF;
gg_Spin2_SF ME_Signal_gg_Spin2_SF;
gg_Spin2_OFpA ME_Signal_gg_Spin2_OFpA;
gg_Spin2_SFpA ME_Signal_gg_Spin2_SFpA;

qq_Spin2_DN_OF ME_Signal_qq_Spin2_DownType_OF;
qq_Spin2_DN_SF ME_Signal_qq_Spin2_DownType_SF;
qq_Spin2_UP_OF ME_Signal_qq_Spin2_UpType_OF;
qq_Spin2_UP_SF ME_Signal_qq_Spin2_UpType_SF;
qq_Spin2_DN_OFpA ME_Signal_qq_Spin2_DownType_OFpA;
qq_Spin2_DN_SFpA ME_Signal_qq_Spin2_DownType_SFpA;
qq_Spin2_UP_OFpA ME_Signal_qq_Spin2_UpType_OFpA;
qq_Spin2_UP_SFpA ME_Signal_qq_Spin2_UpType_SFpA;

/// ZZ and two-fermion couplings. 4l final state (+photon)
gg_Spin0_2f_OF ME_Signal_gg_Spin0_2f_OF;
gg_Spin0_2f_SF ME_Signal_gg_Spin0_2f_SF;
gg_Spin0_2f_OFpA ME_Signal_gg_Spin0_2f_OFpA;
gg_Spin0_2f_SFpA ME_Signal_gg_Spin0_2f_SFpA;

qq_Spin1_2f_DN_OF ME_Signal_qq_Spin1_2f_DownType_OF;
qq_Spin1_2f_DN_SF ME_Signal_qq_Spin1_2f_DownType_SF;
qq_Spin1_2f_UP_OF ME_Signal_qq_Spin1_2f_UpType_OF;
qq_Spin1_2f_UP_SF ME_Signal_qq_Spin1_2f_UpType_SF;
qq_Spin1_2f_DN_OFpA ME_Signal_qq_Spin1_2f_DownType_OFpA;
qq_Spin1_2f_DN_SFpA ME_Signal_qq_Spin1_2f_DownType_SFpA;
qq_Spin1_2f_UP_OFpA ME_Signal_qq_Spin1_2f_UpType_OFpA;
qq_Spin1_2f_UP_SFpA ME_Signal_qq_Spin1_2f_UpType_SFpA;

gg_Spin2_2f_OF ME_Signal_gg_Spin2_2f_OF;
gg_Spin2_2f_SF ME_Signal_gg_Spin2_2f_SF;
gg_Spin2_2f_OFpA ME_Signal_gg_Spin2_2f_OFpA;
gg_Spin2_2f_SFpA ME_Signal_gg_Spin2_2f_SFpA;

qq_Spin2_2f_DN_OF ME_Signal_qq_Spin2_2f_DownType_OF;
qq_Spin2_2f_DN_SF ME_Signal_qq_Spin2_2f_DownType_SF;
qq_Spin2_2f_UP_OF ME_Signal_qq_Spin2_2f_UpType_OF;
qq_Spin2_2f_UP_SF ME_Signal_qq_Spin2_2f_UpType_SF;
qq_Spin2_2f_DN_OFpA ME_Signal_qq_Spin2_2f_DownType_OFpA;
qq_Spin2_2f_DN_SFpA ME_Signal_qq_Spin2_2f_DownType_SFpA;
qq_Spin2_2f_UP_OFpA ME_Signal_qq_Spin2_2f_UpType_OFpA;
qq_Spin2_2f_UP_SFpA ME_Signal_qq_Spin2_2f_UpType_SFpA;

/// 1->4l final state (+photon)
DY_2l ME_DY_2l;
DY_2lpA ME_DY_2lpA;

Spin0_2l ME_Signal_Spin0_2l;
Spin0_OF ME_Signal_Spin0_OF;
Spin0_SF ME_Signal_Spin0_SF;
Spin0_2f_OF ME_Signal_Spin0_2f_OF;
Spin0_2f_SF ME_Signal_Spin0_2f_SF;
Spin0_2lpA ME_Signal_Spin0_2lpA;
Spin0_OFpA ME_Signal_Spin0_OFpA;
Spin0_SFpA ME_Signal_Spin0_SFpA;
Spin0_2f_OFpA ME_Signal_Spin0_2f_OFpA;
Spin0_2f_SFpA ME_Signal_Spin0_2f_SFpA;

Spin1_2l ME_Signal_Spin1_2l;
Spin1_OF ME_Signal_Spin1_OF;
Spin1_SF ME_Signal_Spin1_SF;
Spin1_2f_OF ME_Signal_Spin1_2f_OF;
Spin1_2f_SF ME_Signal_Spin1_2f_SF;
Spin1_2lpA ME_Signal_Spin1_2lpA;
Spin1_OFpA ME_Signal_Spin1_OFpA;
Spin1_SFpA ME_Signal_Spin1_SFpA;
Spin1_2f_OFpA ME_Signal_Spin1_2f_OFpA;
Spin1_2f_SFpA ME_Signal_Spin1_2f_SFpA;

Spin2_2l ME_Signal_Spin2_2l;
Spin2_OF ME_Signal_Spin2_OF;
Spin2_SF ME_Signal_Spin2_SF;
Spin2_2f_OF ME_Signal_Spin2_2f_OF;
Spin2_2f_SF ME_Signal_Spin2_2f_SF;
Spin2_2lpA ME_Signal_Spin2_2lpA;
Spin2_OFpA ME_Signal_Spin2_OFpA;
Spin2_SFpA ME_Signal_Spin2_SFpA;
Spin2_2f_OFpA ME_Signal_Spin2_2f_OFpA;
Spin2_2f_SFpA ME_Signal_Spin2_2f_SFpA;

/// 2mu final state (+photon)
qq_DY_DN_2l ME_qq_DY_DownType_2l;
qq_DY_UP_2l ME_qq_DY_UpType_2l;
qq_DY_DN_2lpA ME_qq_DY_DownType_2lpA;
qq_DY_UP_2lpA ME_qq_DY_UpType_2lpA;

gg_Spin0_2l ME_Signal_gg_Spin0_2l;
gg_Spin0_2lpA ME_Signal_gg_Spin0_2lpA;

// qq_Spin0_DN_2l ME_Signal_qq_Spin0_DownType_2l;
// qq_Spin0_UP_2l ME_Signal_qq_Spin0_UpType_2l;
// qq_Spin0_DN_2lpA ME_Signal_qq_Spin0_DownType_2lpA;
// qq_Spin0_UP_2lpA ME_Signal_qq_Spin0_UpType_2lpA;

qq_Spin1_DN_2l ME_Signal_qq_Spin1_DownType_2l;
qq_Spin1_UP_2l ME_Signal_qq_Spin1_UpType_2l;
qq_Spin1_DN_2lpA ME_Signal_qq_Spin1_DownType_2lpA;
qq_Spin1_UP_2lpA ME_Signal_qq_Spin1_UpType_2lpA;

gg_Spin2_2l ME_Signal_gg_Spin2_2l;
gg_Spin2_2lpA ME_Signal_gg_Spin2_2lpA;

qq_Spin2_DN_2l ME_Signal_qq_Spin2_DownType_2l;
qq_Spin2_UP_2l ME_Signal_qq_Spin2_UpType_2l;
qq_Spin2_DN_2lpA ME_Signal_qq_Spin2_DownType_2lpA;
qq_Spin2_UP_2lpA ME_Signal_qq_Spin2_UpType_2lpA;

/// RAW MG5_aMC ME. For testing purposes only.
// CPPProcess ME_RAW;

    /*
     * END OF
     * Temporary ME place. Should become a part of ME_runners
     */
    // private:

	/// Internal functions ///
	string Find_local_file(const string &input_f);
	
	int Load_parameters(parameters &, data &);
	void Load_parameters_MEs(const string &param_f);
	void Load_parameters_extract_params(SLHAReader_MEKD &, data &);
	void Load_parameters_eval_params(const data &, parameters &);
    // reloads parameter set and updates PDF file reader
	int Reload_params(parameters &, data &);
	
	void Print_4momenta(const vector<double *> &);
    void Print_4momenta_auto(const vector<double *> &);

	//int Arrange_Internal_pls(process_description &);	// updates description
	int Arrange_4momenta(vector<pair<int, double *> > &,
                         vector<double *> &,
                         final_state_types_ &);

	/// Sets up particular choices. Tier 3
	int Run_ME_Configurator_BKG_ZZ(const process_description &,
                                   data &);
	int Run_ME_Configurator_Custom(data &);
	// RAW MG5_aMC ME
	int Run_ME_Configurator_CPPProcess(const process_description &,
                                       data &);
	// Generic mixed spin-0 state
	int Run_ME_Configurator_Spin0(const process_description &,
                                  data &,
								  SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin0_produ(const complex<double> *c,
										 const double lgg,
                                         data &da,
                                         SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin0_decay(const complex<double> *c,
										 const double mZ, const double Mi,
										 const double hZZ,
                                         SLHAReader_MEKD &par_MG);
	// Generic mixed spin-1 state
	int Run_ME_Configurator_Spin1(const process_description &,
                                  data &,
								  SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin1_produ(const complex<double> *c,
										 const double lgg,
										 const double vev,
                                         data &da,
                                         SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin1_decay(const complex<double> *c,
										 const double mZ,
										 const double hZZ,
                                         SLHAReader_MEKD &par_MG);
	// Generic mixed spin-2 state
	int Run_ME_Configurator_Spin2(const process_description &,
                                  data &,
								  SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin2_produ(const complex<double> *c,
										 const double Mi,
										 const double lgg,
                                         data &da,
                                         SLHAReader_MEKD &par_MG);
	void Run_ME_Configurator_Spin2_decay(const complex<double> *c,
										 const double mZ, const double Mi,
										 const double hZZ,
                                         SLHAReader_MEKD &par_MG);
	// SM Higgs
	int Run_ME_Configurator_Spin0Pm(const process_description &,
                                    data &);
	// Exotic models
	int Run_ME_Configurator_Spin0M(const process_description &,
                                   data &);
	int Run_ME_Configurator_Spin0Ph(const process_description &,
                                    data &);
	int Run_ME_Configurator_Spin1P(const process_description &,
                                   data &);
	int Run_ME_Configurator_Spin1M(const process_description &,
                                   data &);
	int Run_ME_Configurator_Spin2Pm(const process_description &,
                                    data &);
	int Run_ME_Configurator_Spin2Ph(const process_description &,
                                    data &);
	int Run_ME_Configurator_Spin2Mh(const process_description &,
                                    data &);
	int Run_ME_Configurator_Spin2Pb(const process_description &,
                                    data &);
	int Run_ME_Configurator_Spin2Ph2(const process_description &,
                                     data &);
	int Run_ME_Configurator_Spin2Ph3(const process_description &,
                                     data &);
	int Run_ME_Configurator_Spin2Ph6(const process_description &,
                                     data &);
	int Run_ME_Configurator_Spin2Ph7(const process_description &,
                                     data &);
	int Run_ME_Configurator_Spin2Mh9(const process_description &,
                                     data &);
	int Run_ME_Configurator_Spin2Mh10(const process_description &,
                                      data &);
	// A mixed state of two contributions
	int Run_ME_Configurator_Spin0Pm_Spin0M(const process_description &,
                                           data &);
	int Run_ME_Configurator_Spin0Pm_Spin0Ph(const process_description &,
                                            data &);
	int Run_ME_Configurator_Spin0M_Spin0Ph(const process_description &,
                                           data &);
	int Run_ME_Configurator_Z4l_BKG(const process_description &, 
                                    data &);
	int Run_ME_Configurator_Z4l_SIG(const process_description &,
                                    data &);

	/// Dispatches MEs that have correct parameters. Tier 2
	// RAW MG5_aMC ME
	int Run_ME_Dispatcher_CPPProcess(const process_description &,
                                     data &);
	int Run_ME_Dispatcher_BKG_ZZ(const process_description &,
                                 data &);
	int Run_ME_Dispatcher_Z4l_BKG(const process_description &,
                                  data &);
	int Run_ME_Dispatcher_Z4l_SIG(const process_description &,
                                  data &);
	int Run_ME_Dispatcher_SIG_Spin0(const process_description &,
                                    data &);
	int Run_ME_Dispatcher_SIG_Spin1(const process_description &,
                                    data &);
	int Run_ME_Dispatcher_SIG_Spin2(const process_description &,
                                    data &);

	/// Evaluators. Blind-calculation functions. Handles MEs from Dispatchers.
	/// Tier 1
	template <class Generic_MEKD_ME>
	int Run_MEs_Evaluator_Initial_State_NO(data &da,
                                           const bool photon,
										   Generic_MEKD_ME &Generic_ME);

	template <class Generic_MEKD_ME>
	int Run_MEs_Evaluator_Initial_State_gg(data &da,
                                           const bool photon,
										   Generic_MEKD_ME &Generic_ME);

	template <class Generic_MEKD_ME_s, class Generic_MEKD_ME_c>
	int Run_MEs_Evaluator_Initial_State_qqbar(data &da,
                                              const bool photon,
											  Generic_MEKD_ME_s &Generic_ME_s,
											  Generic_MEKD_ME_c &Generic_ME_c);

  public:
	
	/*
	 * Version 2 and earlier methods: left for backwards compatibility.
	 */
	
	/*
	 * Unless otherwise specified:
	 * 
	 * Supported process names: "ZZ", "DY", "Custom", "ggSpin0Pm", "ggSpin0Ph",
	 * "ggSpin0M", "qqSpin1P", "qqSpin1M", "ggSpin2Pm", "ggSpin2Ph",
	 * "ggSpin2Mh", "ggSpin2Pb", "qqSpin2Pm", "qqSpin2Ph", "qqSpin2Mh",
	 * "qqSpin2Pb", "Spin0Pm", "Spin0Ph", "Spin0M" "Spin1P", "Spin1M",
	 * "Spin2Pm", "Spin2Ph", "Spin2Mh", "Spin2Pb", "ggSpin0", "qqSpin1",
	 * "ggSpin2", "qqSpin2", "Spin0", "Spin1", "Spin2", "qqZ4l_Background",
	 * "qqZ4l_Signal".
	 */
	///
	/// Constructor.
	///
	/// \param collision_energy					The sqrt(s) value in TeV.
	/// \param PDFName							The name of the parton density
	/// function. Default is none.
	///
	MEKD(const double &collision_energy, const string &PDF_name);

	///
	/// Compute and extract individual KD and MEs. Works after running int
	/// computeMEs(...).
	///
	/// Supported process names: "ZZ", "ggSpin0Pm", "ggSpin0M", "ggSpin0Ph",
	/// "qqSpin1P", "qqSpin1M", "ggSpin2Pm", "qqSpin2Pm".
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (string,
	/// REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const string &processA, const string &processB,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute KDs and MEs for process A and process B out of the 4-momenta of
	/// 4 leptons (lepton ordering does not matter).
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (string,
	/// REQUIRED).
	/// \param[in]  lept1P, lept2P, lept3P, lept4P		The input arrays with
	/// 4-momentum (E,px,py,pz) values of leptons N=1..4 (double*, REQUIRED).
	/// \param[in]  lept1Id, lept2Id, lept3Id, lept4Id	The input IDs (PDG) of
	/// leptons N=1..4 (int, REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const string &processA, const string &processB,
				  const double lept1P[], const int lept1Id,
                  const double lept2P[], const int lept2Id,
				  const double lept3P[], const int lept3Id,
                  const double lept4P[], const int lept4Id,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute KDs and MEs for process A and process B out of the 4-momenta of
	/// the input particles (ordering does not matter).
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (string,
	/// REQUIRED).
	/// \param[in]  input_Ps							The input vector of
	/// arrays with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<double*>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (vector<int>, REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const string &processA, const string &processB,
				  const vector<double *> &input_Ps,
                  const vector<int> &input_IDs,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute ME for a processName out of the 4-momenta of the input particles
	/// (ordering does not matter).
	///
	/// \param[in]  processName							The Name of the
	/// process for which the ME is to be computed (string, REQUIRED).
	/// \param[in]  input_Ps							The input vector of
	/// arrays with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<double*>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (vector<int>, REQUIRED).
	/// \param[out] me2process							The computed |ME|^2
	/// for process of interest (double).
	/// \return											See exit_codes
	///
	int computeME(const string &processName, const vector<double *> &input_Ps,
				  const vector<int> &input_IDs, double &me2process);

	///
	/// Compute all default MEs first for the use with
	/// computeKD(string, string, double&, double&, double&). Option Custom is
	/// outside this scope.
	///
	/// \param[in]  lept1P, lept2P, lept3P, lept4P		The input arrays with
	/// 4-momentum (E,px,py,pz) values of leptons N=1..4 (double*, REQUIRED).
	/// \param[in]  lept1Id, lept2Id, lept3Id, lept4Id	The input IDs (PDG) of
	/// leptons N=1..4 (int, REQUIRED).
	/// \return											See exit_codes
	///
	int computeMEs(const double lept1P[], const int lept1Id,
                   const double lept2P[], const int lept2Id,
				   const double lept3P[], const int lept3Id,
                   const double lept4P[], const int lept4Id);

	///
	/// Compute all important/default MEs first for the use with
	/// computeKD(string, string, double&, double&, double&). Option Custom is
	/// outside this scope.
	///
	/// \param[in]  input_Ps							The input vector of
	/// arrays with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<double*>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (vector<int>, REQUIRED).
	/// \return											See exit_codes
	///
	int computeMEs(const vector<double *> &input_Ps,
                   const vector<int> &input_IDs);

	///
	/// Mixed-state ME mixer of (gg)Spin0Pm, (gg)Spin0Ph, (gg)Spin0Phexotic, and
	/// (gg)Spin0M states, corresponding couplings kappa_1/rhomu01,
	/// kappa_2/rhomu02, kappa_3/rhomu03, kappa_4/rhomu04.
	///
	/// \param[in]	Spin0Pm_relamp						The relative complex
	/// amplitude of the Spin0Pm state
	/// \param[in]	Spin0Ph_relamp						The relative complex
	/// amplitude of the Spin0Ph state
	/// \param[in]	Spin0Phexo_relamp					The relative complex
	/// amplitude of the Spin0PhExotic state
	/// \param[in]	Spin0M_relamp						The relative complex
	/// amplitude of the Spin0M state
	/// \return											See exit_codes
	///
	int Mix_Spin0(const complex<double> Spin0Pm_relamp,
				  const complex<double> Spin0Ph_relamp,
				  const complex<double> Spin0Phexo_relamp,
				  const complex<double> Spin0M_relamp);

	///
	/// Mixed-state ME mixer of production like qqSpin1M, qqSpin1P, exotic,
	/// exotic pseudo, and decay like Spin1M, Spin1P states, corresponding
	/// couplings rhoQ11, rhoQ12, rhoQ13, rhoQ14, b1z/rhomu11, b2z/rhomu12,
	/// rhomu13, rhomu14.
	///
	/// \param[in]	prod_Spin1M_relamp					The relative complex
	/// amplitude for the Spin1M-like production
	/// \param[in]	prod_Spin1P_relamp					The relative complex
	/// amplitude for the Spin1P-like production
	/// \param[in]	prod_Spin1Mexo_relamp				The relative complex
	/// amplitude for the Spin1Mexotic-like production
	/// \param[in]	prod_Spin1Pexo_relamp				The relative complex
	/// amplitude for the Spin1Pexotic-like production
	/// \param[in]	dec_Spin1M_relamp					The relative complex
	/// amplitude for the Spin1M-like decay
	/// \param[in]	dec_Spin1P_relamp					The relative complex
	/// amplitude for the Spin1P-like decay
	/// \return											See exit_codes
	///
	int Mix_Spin1(const complex<double> prod_Spin1M_relamp,
				  const complex<double> prod_Spin1P_relamp,
				  const complex<double> prod_Spin1Mexo_relamp,
				  const complex<double> prod_Spin1Pexo_relamp,
				  const complex<double> dec_Spin1M_relamp,
				  const complex<double> dec_Spin1P_relamp,
				  const complex<double> dec_Spin1_rhomu13_relamp,
				  const complex<double> dec_Spin1_rhomu14_relamp);

	///
	/// Mixed-state ME mixer of Spin-2 states. Production couplings: k1g/rhoQ21,
	/// ..., k4g/rhoQ24, ..., k10g, decay couplings: k1z/rhomu21, k4z/rhomu24,
	/// ..., k10z.
	///
	/// \param[in]	*prod_Spin2_relamp					The relative complex
	/// amplitudes for the Spin-2 state production. An array of size 10
	/// \param[in]	*dec_Spin2_relamp					The relative complex
	/// amplitudes for the Spin-2 state decay. An array of size 10
	/// \return											See exit_codes
	///
	int Mix_Spin2(const complex<double> *prod_Spin2_relamp,
				  const complex<double> *dec_Spin2_relamp);

	/// Mixed-state ME mixer. Variables
	complex<double> m_Mixing_Coefficients_Spin0[4];
	complex<double> m_Mixing_Coefficients_Spin1[8];
	complex<double> m_Mixing_Coefficients_Spin2[20];

  private:
	/// Properties. Variables.
	// computeMEs(...) results
	double ME_ZZ, ME_Spin0PSMH, ME_Spin0Ph, ME_Spin0M; 
	double ME_Spin1P, ME_Spin1M, ME_ggSpin2Pm, ME_qqSpin2Pm;
	string m_PDFName;  // Name of the parton density functions to be used.
					   // Supported: CTEQ6l;
	string m_process;  // Name of the process (background, signal hypotheses,
					   // etc.). Supported: Custom, SMHiggs, CPoddScalar,
					   // CPevenScalar, Spin2particle, ZZ
	string m_processA; // Name of the process A (background, signal hypotheses,
					   // etc.). Supported: Custom, SMHiggs, CPoddScalar,
					   // CPevenScalar, Spin2particle, ZZ
	string m_processB; // Name of the process B (background, signal hypotheses,
					   // etc.). Supported: Custom, SMHiggs, CPoddScalar,
					   // CPevenScalar, Spin2particle, ZZ

	/// Methods
	int setProcessName(const string &process); // sanity check for input process
                                              // name, translation to the the
                                              // names supported by MEKD v2
	int setProcessNames(const string &processA,
						const string &processB); // sanity check for input
                                                 // process names, translation
                                                 // to the the names supported
                                                 // by MEKD v2
	int processParameters();			  // sanity check for internal paramters

#if (defined MEKD_STANDALONE && defined MEKD_with_ROOT) ||                     \
	!defined MEKD_STANDALONE
	//------------------------------------------------------------------------
	// ROOT-compatabile members
	//------------------------------------------------------------------------
  public:
	///
	/// Compute KDs and MEs for process A and process B. Works after running int
	/// computeMEs(...).
	/// The overloaded method that supports input parameters of ROOT types
	/// TString and TLorentzVector.
	///
	/// Supported process names: "ZZ", "ggSpin0Pm", "ggSpin0M", "ggSpin0Ph",
	/// "qqSpin1P", "qqSpin1M", "ggSpin2Pm", "qqSpin2Pm".
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (TString,
	/// REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const TString &processA, const TString &processB,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute KDs and MEs for process A and process B out of the 4-momenta of
	/// 4 leptons (lepton ordering does not matter).
	/// The overloaded method that supports input parameters of ROOT types
	/// TString and TLorentzVector.
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (TString,
	/// REQUIRED).
	/// \param[in]  lept1P, lept2P, lept3P, lept4P		The input arrays with
	/// 4-momentum (E,px,py,pz) values of leptons N=1..4 (TLorentzVector,
	/// REQUIRED).
	/// \param[in]  lept1Id, lept2Id, lept3Id, lept4Id	The input IDs (PDG) of
	/// leptons N=1..4 (int, REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const TString &processA, const TString &processB,
				  const TLorentzVector &lept1P, const int lept1Id,
				  const TLorentzVector &lept2P, const int lept2Id,
				  const TLorentzVector &lept3P, const int lept3Id,
				  const TLorentzVector &lept4P, const int lept4Id,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute KDs and MEs for process A and process B out of the 4-momenta of
	/// the input particles (ordering does not matter).
	/// The overloaded method that supports input parameters of ROOT types
	/// TString and TLorentzVector.
	///
	/// \param[in]  processA, processB					The names of the
	/// processes X = A, B for which the KDs and MEs are computed (Tstring,
	/// REQUIRED).
	/// \param[in]  input_Ps							The input vector of
	/// TLorentzVectors with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<TLorentzVector>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (int, REQUIRED).
	/// \param[out] kd									The computed KD value
	/// for discrimination of processes A and B (double).
	/// \param[out] me2processA							The computed |ME|^2
	/// for process A (double).
	/// \param[out] me2processB							The computed |ME|^2
	/// for process B (double).
	/// \return											See exit_codes
	///
	int computeKD(const TString &processA, const TString &processB,
				  const vector<TLorentzVector> &input_Ps,
                  const vector<int> &input_IDs,
				  double &kd, double &me2processA, double &me2processB);

	///
	/// Compute ME for a processName out of the 4-momenta of the input particles
	/// (ordering does not matter).
	///
	/// \param[in]  processName							The name of the
	/// process for which the ME is to be computed (TString, REQUIRED).
	/// \param[in]  input_Ps							The input vector of
	/// TLorentzVectors with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<TLorentzVector>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (vector<int>, REQUIRED).
	/// \param[out] me2process							The computed |ME|^2
	/// for process of interest (double).
	/// \return											See exit_codes
	///
	int computeME(const TString &processName,
                  const vector<TLorentzVector> &input_Ps,
				  const vector<int> &input_IDs, double &me2process);

	///
	/// Compute all important/default MEs first for the use with
	/// computeKD(TString, TString, double&, double&, double&). Option Custom is
	/// outside this scope.
	///
	/// \param[in]  lept1P, lept2P, lept3P, lept4P		The input arrays with
	/// 4-momentum (E,px,py,pz) values of leptons N=1..4 (TLorentzVector,
	/// REQUIRED).
	/// \param[in]  lept1Id, lept2Id, lept3Id, lept4Id	The input IDs (PDG) of
	/// leptons N=1..4 (int, REQUIRED).
	/// \return											See exit_codes
	///
	int computeMEs(const TLorentzVector &lept1P, const int lept1Id,
				   const TLorentzVector &lept2P, const int lept2Id,
				   const TLorentzVector &lept3P, const int lept3Id,
				   const TLorentzVector &lept4P, const int lept4Id);

	///
	/// Compute all important/default MEs first for the use with
	/// computeKD(string/TString, string/TString, double&, double&, double&).
	/// Option Custom is outside this scope.
	///
	/// \param[in]  input_Ps							The input vector of
	/// TLorentzVectors with 4-momentum (E,px,py,pz) values of particles N=1..5
	/// (vector<TLorentzVector>, REQUIRED).
	/// \param[in]  input_IDs							The input vector of IDs
	/// (PDG) of particles N=1..5 (vector<int>, REQUIRED).
	/// \return											See exit_codes
	///
	int computeMEs(const vector<TLorentzVector> &input_Ps,
                   const vector<int> &input_IDs);

  private:
	// For storing TLorentzVectors for internal use
	double lept1P_i[4], lept2P_i[4], lept3P_i[4], lept4P_i[4];
	// For storing vector of TLorentzVectors for internal use
	vector<double *> input_Ps_i;

#endif
};

/// end of namespace
}

#endif
