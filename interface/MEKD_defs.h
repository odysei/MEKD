/*************************************************************************
*  Authors:		MEKD fans
*  More info:	http://mekd.ihepa.ufl.edu
*  Contact:		odysei@cern.ch, mekd@phys.ufl.edu
*  Info:		MEKD definitions are provided here.
*************************************************************************/
#ifndef MEKD_DEFS_h
#define MEKD_DEFS_h

#include "MEKD.h"

namespace mekd
{

enum process_types {
	proc_simple,	// typically production couples to X
	proc_RAW		// an experimental setting
};

enum resonance_types {
	bkg_Z,
	bkg_Zs,			// Z -> 4l via s ch.
	bkg_Zt,			// Z -> 4l via t ch.
	reson_Spin0,	// generic spin 0 resonance, many couplings
	reson_Spin0Pm,	// 0^+_m, Higgs
	reson_Spin0Ph,	// 0^+_h
	reson_Spin0M,	// 0^-
	reson_Spin1,	// generic spin 1 resonance, many couplings
	reson_Spin1M,	// 1^-, vector
	reson_Spin1P,	// 1^+, pseudovector
	reson_Spin2,	// generic spin 2 resonance, many couplings
	reson_Spin2Pm,	// 2^+_m, graviton-like resonance
	reson_Spin2Ph2,	// 2^+_h2
	reson_Spin2Ph3,	// 2^+_h3
	reson_Spin2Ph4,	// 2^+_h4 also 2^+_h
	reson_Spin2Ph5,	// 2^+_h5 also 2^+_b
	reson_Spin2Ph6,	// 2^+_h6
	reson_Spin2Ph7,	// 2^+_h7
	reson_Spin2Mh8,	// 2^-_h8 also 2^-_h
	reson_Spin2Mh9,	// 2^-_h9
	reson_Spin2Mh10,// 2^-_h10
	reson_Custom	// an experimental setting
};

enum production_types {
	prod_all,		// many if applicable
	prod_gg,
	prod_qq,
	prod_no
};

enum resonance_decay_types {
	decay_ZZ,
	decay_2f
};

enum final_state_types {
	final_4l,
	final_4lA,	// 4l plus photon
	final_2l,
	final_2lA	// 2l plus photon
};

/// explicit final state types. Internal use.
enum final_state_types_ {
	final_4e,
	final_2e2mu,
	final_4mu,
	final_4eA,	// 4l plus photon
	final_2e2muA,
	final_4muA,
	final_2e,
	final_2mu,
	final_2eA,	// 2l plus photon
	final_2muA
};

enum exit_codes {
	EXIT_SUCCESS_,	// already present
	EXIT_FAILURE_,	// already present
	EXIT_ERROR_SQRT,
	EXIT_ERROR_PDFS,
	EXIT_ERROR_PROCESS,
	EXIT_ERROR_INPUT
};

struct data {
    final_state_types_ fs;  //final_state_types_ final_state_;

	std::vector<double> id;
	std::vector<double *> p;
    
    // filled after running RUN_XXXX(...). Invariant mass of the final state
	double invariant_m;
    double PDFx1, PDFx2;
    
    std::complex<double> *mix_coeffs_Spin0;
    std::complex<double> *mix_coeffs_Spin1;
    std::complex<double> *mix_coeffs_Spin2;
    std::complex<double> mix_coeffs_Spin0_pred[4];
    std::complex<double> mix_coeffs_Spin1_pred[8];
    std::complex<double> mix_coeffs_SpinX_pred[20];  // should be max of all
};

}

#endif
