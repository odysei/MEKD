/*************************************************************************
*  Authors:     MEKD fans
*  More info:   http://mekd.ihepa.ufl.edu
*  Contact:     odysei@cern.ch, mekd@phys.ufl.edu
*  Info:        MEKD definitions are provided here.
*************************************************************************/
#ifndef MEKD_Definitions_h
#define MEKD_Definitions_h

#include "MEKD.h"

using namespace std;

namespace mekd
{

enum model_types {
    model_empty,
    model_MEKD,     // any HEF_MEKDn model
    model_HEF_UFO,  // HEF_UFO or HEF_Unitary
    model_SM,       // sm-full
    model_HEFTU     // updated heft-full
};

enum process_types {
    proc_empty,
    proc_simple, // typically production couples to X
    proc_ttX,
    proc_test,  // a place to put in new MEs for tests
    proc_RAW    // an experimental setting
};

enum resonance_types {
    reson_empty,
    bkg_Z,
    bkg_Zs, // Z -> 4l via s ch.
    bkg_Zt, // Z -> 4l via t ch.
    bkg_tt,
    bkg_reson_Spin0Pm, // bkg + resonance (H)
    reson_Spin0,       // generic spin 0 resonance, many couplings
    reson_Spin0Pm,     // 0^+_m, Higgs
    reson_Spin0Ph,     // 0^+_h
    reson_Spin0M,      // 0^-
    reson_Spin1,       // generic spin 1 resonance, many couplings
    reson_Spin1M,      // 1^-, vector
    reson_Spin1P,      // 1^+, pseudovector
    reson_Spin2,       // generic spin 2 resonance, many couplings
    reson_Spin2Pm,     // 2^+_m, graviton-like resonance
    reson_Spin2Ph2,    // 2^+_h2
    reson_Spin2Ph3,    // 2^+_h3
    reson_Spin2Ph4,    // 2^+_h4 also 2^+_h
    reson_Spin2Ph5,    // 2^+_h5 also 2^+_b
    reson_Spin2Ph6,    // 2^+_h6
    reson_Spin2Ph7,    // 2^+_h7
    reson_Spin2Mh8,    // 2^-_h8 also 2^-_h
    reson_Spin2Mh9,    // 2^-_h9
    reson_Spin2Mh10,   // 2^-_h10
    reson_Custom       // an experimental setting
};

enum production_types {
    prod_empty,
    prod_all, // many if applicable
    prod_gg,
    prod_qq,
    prod_no
};

enum resonance_decay_types { decay_empty, decay_ZZ, decay_2f };

enum final_state_types {
    final_empty,
    final_4l,
    final_4lA, // 4l plus photon
    final_2l,
    final_2lA, // 2l plus photon
    final_ttbb
};

/*
 * Internal descriptors below
 */

/// explicit final state types. Internal use.
enum final_state_types_ {
    final_4e,
    final_2e2mu,
    final_4mu,
    final_4eA, // 4l plus photon
    final_2e2muA,
    final_4muA,
    final_2e,
    final_2mu,
    final_2eA, // 2l plus photon
    final_2muA,
    final_ttbb_
};

enum exit_codes {
    EXIT_SUCCESS_, // already present
    EXIT_FAILURE_, // already present
    EXIT_ERROR_SQRT,
    EXIT_ERROR_PDFS,
    EXIT_ERROR_PROCESS,
    EXIT_ERROR_INPUT,
    EXIT_ERROR_CONFIG
};

struct masses {
    // system's invariant mass
    double sys;
    
    // subsystem's invariant mass
    double bbx;

    // quarks
    double d, u, s, c, b, t;

    // leptons
    double e, mu;

    // vectors
    double Z;
};

struct couplings {
    // spin 0
    complex<double> rhou01, rhou02, rhoc01, rhoc02, rhod01, rhod02, rhos01,
        rhos02, rhob01, rhob02;

    // spin 1
    complex<double> rhou11, rhou12, rhou13, rhou14, rhoc11, rhoc12, rhoc13,
        rhoc14, rhod11, rhod12, rhod13, rhod14, rhos11, rhos12, rhos13, rhos14,
        rhob11, rhob12, rhob13, rhob14;

    // spin 2
    complex<double> rhou21, rhou22, rhou23, rhou24, rhoc21, rhoc22, rhoc23,
        rhoc24, rhod21, rhod22, rhod23, rhod24, rhos21, rhos22, rhos23, rhos24,
        rhob21, rhob22, rhob23, rhob24;
};

struct data {
    // delete
    //     vector<int> id;
    // 	vector<double *> fp;  // final state p

    vector<pair<int, double *>> id_p;

    final_state_types_ fs; // final_state_types_ final_state_;
    vector<double *> p; // with initial state partons

    double PDFx1, PDFx2;

    masses m;
    couplings c;

    complex<double> *mix_coeffs_Spin0;
    complex<double> *mix_coeffs_Spin1;
    complex<double> *mix_coeffs_Spin2;
    // Are not really needed for v3 and will be dropped:
    complex<double> mix_coeffs_Spin0_pred[4];
    complex<double> mix_coeffs_Spin1_pred[8];
    complex<double> mix_coeffs_SpinX_pred[20]; // should be max of all
};
}

#endif
