/*************************************************************************
*  Authors:		MEKD fans
*  More info:	http://mekd.ihepa.ufl.edu
*  Contact:		odysei@cern.ch, mekd@phys.ufl.edu
*  Info:		MEKD standard containers/structs are defined here.
*************************************************************************/
#ifndef MEKD_INPUTS_h
#define MEKD_INPUTS_h

#include "MEKD_defs.h"
#include "MEKD_MG.h"

namespace mekd
{

/// Flags that are used in calculations
struct flags
{
	bool Boost_To_CM;			// for a boosted data
	bool Debug_Mode;			// Enable debugging mode
	bool Fix_Spin0_Production; 	// use the SM Higgs production mechanism
	bool Fix_Spin1_Production; 	// use the a hybrid production mechanism
	//bool Force_g3_running;		// unused. Was included for alpha_QCD
	bool Overwrite_e_and_mu_masses; // switch for manual m_e, m_mu masses
	bool per_event_parton_coeffs;	// if PDF is not used, allow altering
									// parton contributions per event
	bool Use_Higgs_width;		// if false, width is fixed to =1
	bool Use_mh_eq_m4l;			// Set mh to m4l for every event
	bool Use_mZ4l_eq_m4l;		// Set m_Z to m4l for Z4l events
	bool Use_PDF_w_pT0; 		// Use PDFs in the pT=0 frame. If true,
								// Boost_To_CM is ignored
	bool Vary_resonance_width;  // Allow width to be varied with mass
	bool Vary_signal_couplings; // Allow couplings to change with mass
	bool Warning_Mode;			// Print warnings
};

// see definitions for descriptions
struct process_desciption
{
	process_types process;
	resonance_types resonance;
	production_types production;
	resonance_decay_types decay;
	final_state_types final_state;
};

// standardized input to calculator
struct input: process_desciption
{
	
};

/// end of namespace
}

#endif
