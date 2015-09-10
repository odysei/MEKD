#ifndef MEKD_MG_h
#define MEKD_MG_h

#include "MEKD_includes.h"

using namespace std;

namespace mekd
{

/// Part of pdfreader
extern "C" pdtStr pdtSg, pdtSd, pdtSu, pdtSs, pdtSc, pdtSad, pdtSau, pdtSas,
	pdtSac;

// #define PDTFILE "PDF_tables/cteq6l.pdt" // CalCHEP reads a table for CTEQ6L.
// You can change PDF set as you want.

class MEKD_MG
{
  public:
	/// Flags
	flags flag;

	/// General parameters
	// Values have no effect if PDF is used but variables are always used
	// Parton multipliers.
	double parton_coeff_d;
	double parton_coeff_u;
	double parton_coeff_s;
	double parton_coeff_c;
	// 	double GG;	// Assign QCD coupling, force g3 running if needed
	double Sqrt_s; // Max energy, collision energy

	/// State mixing
	complex<double> *Mixing_Coefficients_Spin0, *Mixing_Coefficients_Spin1,
		*Mixing_Coefficients_Spin2;

	/// Physical parameters
	double Electron_mass;	// 0.0005109989, for enabled overwriting
	double Higgs_mass;		// Works only if flag.Use_mh_eq_m4l=false
	double Higgs_width;		// Practically not used, for future implementations
	double Muon_mass;		// 0.10565837, for enabled overwriting
	double Proton_mass;		// Always used if needed

	/// Final-state lepton/photon information
	double *p1, *p2, *p3, *p4, *p5;
	double id1, id2, id3, id4, id5;

	/// String flags and file locations
	string Final_state;			 // Final state, for the moment: 4e, 4mu, 2e2mu
	string Resonance_decay_mode; // default: ZZ. Alternatives: 2l, 2l_s
	string Test_Model; // Models: ZZ, DY, Custom, CPevenScalar, ggSpin0Pm,
					   // ggSpin0M, ggSpin0Ph, qqSpin1P, qqSpin1M, ggSpin2Pm,
					   // ggSpin2Ph, ggSpin2Mh, ggSpin2Pb, qqSpin2Pm, qqSpin2Ph,
					   // qqSpin2Mh, qqSpin2Pb, Spin0Pm, Spin0M, Spin0Ph,
					   // Spin1P, Spin1M, Spin2Pm, Spin2Ph, Spin2Mh, Spin2Pb,
					   // qqZ4l_Signal, qqZ4l_Background
	vector<string> Test_Models; // same names as for the Test_Model
	string Parameter_file;		// Location where a parameter card is stored
	string PDF_file;			// PDF/PDT table file

	/// Calculation results
	double Mass_4l; // is filled after running RUN_XXXX(...). Invariant mass of
					// the final-state system
	double invariant_m;
	double Background_ME; // may not be used if running RUN_MEKD_MG(string) is
						  // chosen
	double Signal_ME;	 // is filled after running RUN_XXXX(...)
	vector<double> Signal_MEs; // is filled if Test_Models are set after running
							   // RUN_XXXX(...)
	double KD;				   // is not filled with RUN_MEKD_MG(string)

	/// Parameter container. For experts only
	SLHAReader_MEKD Set_Of_Model_Parameters;

	/// Functions
	void Set_Default_MEKD_MG_Parameters();

	int Reload_Parameters(); // reloads parameter set and updates PDF file
							 // reader
	
	void Check_MEs();
	
	/// Run-related functions
	int Run_MEKD_MG();   // main routine to evaluate matrix elements; updates
						 // "Calculation results"
	int Run_MEKD_MG(string Input_Model); // Calculates a ME ONLY for a chosen
										 // model; ignores automatic background
										 // calculation. Updates Signal_ME
	double Get_PDF_x1(vector<double *> &p);
	double Get_PDF_x2(vector<double *> &p);
	
	double Get_invariant_m(vector<double *> &p, int p_range[2]);
	
	void Prepare_ml_s();
	void Load_p_set();
	void Approx_neg_z_parton(double *p, double E);
	void Approx_pos_z_parton(double *p, double E);
	void Normalize_parton_coeffs();
	

	/// Constructors, destructors
	MEKD_MG();
	~MEKD_MG();

  private:
	
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
	
	bool Parameters_Are_Loaded, buffer_bool, Predefined_Model;

	int error_value;
	unsigned int counter;

	double *buffer, buffer_p[4], buffer_Custom, ml1, ml2, ml3, ml4, PDFx1,
		PDFx2, LmbdGG_calculated;
	// used by sorter, allows shuffling p_set
	double *pl1_internal, *pl2_internal, *pl3_internal, *pl4_internal,
		*pA1_internal;

	complex<double> *buffer_complex, *Mixing_Coefficients_Spin0_internal,
		*Mixing_Coefficients_Spin1_internal,
		*Mixing_Coefficients_Spin2_internal;

	string *Test_Model_buffer;

	// Parameters
	double v_expectation; // Vacuum expectation value
	double hZZ_coupling;
	double params_m_d, params_m_u, params_m_s, params_m_c, params_m_e,
		params_m_mu, params_m_Z;
	complex<double> params_rhou01, params_rhou02, params_rhoc01, params_rhoc02,
		params_rhod01, params_rhod02, params_rhos01, params_rhos02,
		params_rhob01, params_rhob02;
	complex<double> params_rhou11, params_rhou12, params_rhou13, params_rhou14,
		params_rhoc11, params_rhoc12, params_rhoc13, params_rhoc14,
		params_rhod11, params_rhod12, params_rhod13, params_rhod14,
		params_rhos11, params_rhos12, params_rhos13, params_rhos14,
		params_rhob11, params_rhob12, params_rhob13, params_rhob14;
	complex<double> params_rhou21, params_rhou22, params_rhou23, params_rhou24,
		params_rhoc21, params_rhoc22, params_rhoc23, params_rhoc24,
		params_rhod21, params_rhod22, params_rhod23, params_rhod24,
		params_rhos21, params_rhos22, params_rhos23, params_rhos24,
		params_rhob21, params_rhob22, params_rhob23, params_rhob24;

	string buffer_string;

	vector<double> id_set;
	vector<double *> p_set;

	/// Internal functions ///
	string Find_local_file(string input_f);
	
	int Load_Parameters();
	void Load_Parameters_MEs();
	void Load_Parameters_extract_params(SLHAReader_MEKD&);
	void Load_Parameters_eval_params();
	
	void Print_4momenta(vector<double *>&);

	int Arrange_Internal_pls();

	/// Sets up particular choices. Tier 3
	int Run_MEKD_MG_ME_Configurator_BKG_ZZ(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Custom();
	int Run_MEKD_MG_ME_Configurator_CPPProcess(
		string initial_state); // RAW MG5_aMC ME
	int Run_MEKD_MG_ME_Configurator_Spin0(
		string initial_state); // A general mixed spin-0 state
	int Run_MEKD_MG_ME_Configurator_Spin1(
		string initial_state); // A general mixed spin-1 state
	int Run_MEKD_MG_ME_Configurator_Spin2(
		string initial_state); // A general mixed spin-2 state
	int Run_MEKD_MG_ME_Configurator_Spin0Pm(string initial_state); // SM Higgs
	int Run_MEKD_MG_ME_Configurator_Spin0M(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin0Ph(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin1P(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin1M(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Pm(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Ph(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Mh(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Pb(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Ph2(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Ph3(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Ph6(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Ph7(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Mh9(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin2Mh10(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin0Pm_Spin0M(
		string initial_state); // A mixed state of two contributions
	int Run_MEKD_MG_ME_Configurator_Spin0Pm_Spin0Ph(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Spin0M_Spin0Ph(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Z4l_BKG(string initial_state);
	int Run_MEKD_MG_ME_Configurator_Z4l_SIG(string initial_state);

	/// Dispatches MEs that have correct parameters. Tier 2
	int Run_MEKD_MG_ME_Dispatcher_CPPProcess(
		string initial_state); // RAW MG5_aMC ME
	int Run_MEKD_MG_ME_Dispatcher_BKG_ZZ(string initial_state);
	int Run_MEKD_MG_ME_Dispatcher_Z4l_BKG(string initial_state);
	int Run_MEKD_MG_ME_Dispatcher_Z4l_SIG(string initial_state);
	int Run_MEKD_MG_ME_Dispatcher_SIG_Spin0(string initial_state);
	int Run_MEKD_MG_ME_Dispatcher_SIG_Spin1(string initial_state);
	int Run_MEKD_MG_ME_Dispatcher_SIG_Spin2(string initial_state);

	/// Evaluators. Blind-calculation functions. Handles MEs from Dispatchers.
	/// Tier 1
	template <class Generic_MEKD_MG_ME>
	int
	Run_MEKD_MG_MEs_Evaluator_Initial_State_NO(bool photon,
											   Generic_MEKD_MG_ME &Generic_ME);

	template <class Generic_MEKD_MG_ME>
	int
	Run_MEKD_MG_MEs_Evaluator_Initial_State_gg(bool photon,
											   Generic_MEKD_MG_ME &Generic_ME);

	template <class Generic_MEKD_MG_ME_s, class Generic_MEKD_MG_ME_c>
	int Run_MEKD_MG_MEs_Evaluator_Initial_State_qqbar(
		bool photon, Generic_MEKD_MG_ME_s &Generic_ME_s,
		Generic_MEKD_MG_ME_c &Generic_ME_c);
};

/// end of namespace
}

#endif