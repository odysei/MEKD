/*************************************************************************
*  Authors:     MEKD fans
*  More info:   http://mekd.ihepa.ufl.edu
*  Contact:     odysei@cern.ch, mekd@phys.ufl.edu
*  Info:        MEKD standard containers/structs are defined here.
*************************************************************************/
#ifndef MEKD_Inputs_h
#define MEKD_Inputs_h

#include "Definitions.h"
#include "Includes.h"

namespace mekd
{

// See definitions for descriptions
struct process_description {
    model_types model;
    process_types process;
    resonance_types resonance;
    production_types production;
    resonance_decay_types decay;
    final_state_types final_state;
};

// Standardized input to calculator
struct input {
    vector<double *> *p; // {E, px, py, pz}
    vector<int> *id;     // PDG ids
};

// Standardized input to calculator for custom coupling run
struct input_c : input {
    complex<double> mix_coeffs_Spin0[4];
    complex<double> mix_coeffs_Spin1[8];
    complex<double> mix_coeffs_Spin2[20];
};

/// Flags that are used in calculations
struct flags {
    bool Boost_To_CM;          // for a boosted data
    bool Debug_Mode;           // Enable debugging mode
    bool Fix_Spin0_Production; // use the SM Higgs production mechanism
    bool Fix_Spin1_Production; // use the a hybrid production mechanism
    // bool Force_g3_running;		// unused. Was included for alpha_QCD
    bool Overwrite_e_and_mu_masses; // switch for manual m_e, m_mu masses
                                    // parton contributions per event
    bool Use_Higgs_width;           // if false, width is fixed to =1
    bool use_mX_eq_Mdec;            // Set mX to decay products' inv. mass
    bool Use_mZ4l_eq_m4l;           // Set m_Z to m4l for Z4l events
    bool Use_PDF_w_pT0;             // Use PDFs in the pT=0 frame. If true,
                                    // Boost_To_CM is ignored
    bool Vary_resonance_width;      // Allow width to be varied with mass
    bool Vary_signal_couplings;     // Allow couplings to change with mass
    bool Warning_Mode;              // Print warnings

    bool use_prod_2013_convetion_for_4l; // 2013 convention for 4l states
    bool use_prod_ddx;                   // use ddx quarks in IS
    bool use_prod_uux;                   // use uux quarks in IS
    bool use_prod_ssx;                   // use ssx quarks in IS
    bool use_prod_ccx;                   // use ccx quarks in IS
    bool use_prod_bbx;                   // use bbx quarks in IS
    bool use_prod_gg;                    // use gg in IS
};

/// Parameters that are used in calculations, some are updated per run
struct parameters {
    bool loaded = false;

    /// General parameters
    // 	double GG;	// Assign QCD coupling, force g3 running if needed
    double sqrt_s; // Max energy, collision energy

    /// Physical parameters
    double Electron_mass; // 0.0005109989, for enabled overwriting
    double Higgs_mass;    // Works only if flag.use_mX_eq_Mdec=false
    double Higgs_width;   // Practically not used, for future implementations
    double Muon_mass;     // 0.10565837, for enabled overwriting
    double Proton_mass;   // Always used if needed

    /// Constants; gets updated in the code
    double vev; // Vacuum expectation value
    double hZZ_coupling;

    string params_MG_file; // Location where a parameter card is stored
    string PDF_file;       // PDF/PDT table file
};

/// end of namespace
}

#endif
