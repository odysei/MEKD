/*************************************************************************
*  Authors:   MEKD fans
*  More info: http://mekd.ihepa.ufl.edu
*  Contact:   odysei@cern.ch, mekd@phys.ufl.edu
*************************************************************************/
#ifndef MEKD_cpp
#define MEKD_cpp

/// MEKD header
#include "MEKD.h"

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

/*
 * Constructors, destructors
 */
// idata.p(7, new double[4]), => some problems ???
MEKD::MEKD()
{
    Set_default_params(); // loads mostly flag (s) and param (s)
    params_MEKD = Parameters_MEKD::getInstance();
    params_sm_full = Parameters_sm_full::getInstance();
    params_HEFTU = Parameters_HEFTU::getInstance();

    Check_MEs();

    idata.id_p.reserve(5);
    idata.id_p.push_back(pair<int, double *>(10000, new double[4]));
    idata.id_p.push_back(pair<int, double *>(10000, new double[4]));
    idata.id_p.push_back(pair<int, double *>(10000, new double[4]));
    idata.id_p.push_back(pair<int, double *>(10000, new double[4]));
    idata.id_p.push_back(pair<int, double *>(10000, new double[4]));

    idata.p.reserve(7);
    idata.p.push_back(new double[4]); // in parton 1
    idata.p.push_back(new double[4]); // in parton 2
    for (auto i : idata.id_p)
        idata.p.push_back(i.second);

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
}

MEKD::~MEKD()
{
    if (param.loaded)
        Unload_pdfreader();

    idata.p.clear();
    idata.id_p.clear();

    for (auto runner : ME_runners) {
        if (runner != NULL) {
            runner->deinitialize();
            delete runner;
        }
    }
    ME_runners.clear();
}

int MEKD::Load_parameters(parameters &pa, data &da)
{
    params_MG.read_slha_file(pa.params_MG_file);

    SLHAReader_MEKD slha(pa.params_MG_file);
    params_MEKD->setIndependentParameters(slha);
    params_MEKD->setIndependentCouplings();
    params_sm_full->setIndependentParameters(slha);
    params_sm_full->setIndependentCouplings();
    params_HEFTU->setIndependentParameters(slha);
    params_HEFTU->setIndependentCouplings();

    /// Initializing parameters
    if (!pa.loaded) {
        Load_parameters_MEs(pa.params_MG_file); // init MEs
        Initialize_ME_runners(ME_runners);
    }
    Load_parameters_extract_params(params_MEKD, da);
    Load_parameters_eval_params(params_MEKD, da, pa);

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
    idata.mix_coeffs_Spin0 = const_cast<complex<double> *>(in.mix_coeffs_Spin0);
    idata.mix_coeffs_Spin1 = const_cast<complex<double> *>(in.mix_coeffs_Spin1);
    idata.mix_coeffs_Spin2 = const_cast<complex<double> *>(in.mix_coeffs_Spin2);

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
        const unsigned int size = idata.id_p.size();

        for (unsigned int i = 0; i < size; ++i) {
            if (i < in_id_size) {
                idata.id_p[i].first = (*in.id)[i];
                idata.id_p[i].second[0] = (*in.p)[i][0];
                idata.id_p[i].second[1] = (*in.p)[i][1];
                idata.id_p[i].second[2] = (*in.p)[i][2];
                idata.id_p[i].second[3] = (*in.p)[i][3];
            } else {
                idata.id_p[i].first = 10000;
                idata.id_p[i].second[0] = 0;
                idata.id_p[i].second[1] = 0;
                idata.id_p[i].second[2] = 0;
                idata.id_p[i].second[3] = 0;
            }
        }
    }

    if (!param.loaded)
        Load_parameters(param, idata);
    if (Arrange_4momenta(idata.id_p, idata.p, idata.fs) == 1) {
        cerr << "Particle id error. Exiting.\n";
        exit(1);
    }

    Background_ME = 0;
    Signal_ME = 0;

    Run_make_p(idata);

    {
        const int range[2] = {2, 6};
        idata.m.sys = Get_sys_m(idata.p, range);
    }
    if (idata.fs == final_ttbb_) {
        const int range[2] = {4, 5};
        idata.m.bbx = Get_sys_m(idata.p, range);
    }

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

void MEKD::Run_make_p(data &da)
{
    if (flag.Overwrite_e_and_mu_masses) {
        params_MEKD->mdl_Me = param.Electron_mass;
        params_MEKD->mdl_MM = param.Muon_mass;
        da.m.e = param.Electron_mass;
        da.m.mu = param.Muon_mass;
    }

    Zero_first_two(da.p); // zero first two 4-momenta

    /// Calculate values needed for the PDF in the pT=0 frame
    da.PDFx1 = Get_PDF_x1(da.p);
    da.PDFx2 = Get_PDF_x2(da.p);
    if (flag.Debug_Mode) {
        printf("Coefficients for PDF (x1, x2): (%.10E, %.10E)\n", da.PDFx1,
               da.PDFx2);
    }

    /// If flag is true, boost to CM frame iff PDF is NOT included.
    if (flag.Boost_To_CM && !flag.Use_PDF_w_pT0) {
        Run_make_p_boost(0, da);
        const double collision_E =
            da.p[2][0] + da.p[3][0] + da.p[4][0] + da.p[5][0] + da.p[6][0];
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
        const double m = da.m.e;

        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], m, da.p[4], m, da.p[5], 0,
                     da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], m, da.p[4], m, da.p[5], 0,
                           da.p[6]);
            return;
        }
    }

    if (da.fs == final_4mu || da.fs == final_4muA) {
        const double m = da.m.mu;

        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], m, da.p[4], m, da.p[5], 0,
                     da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], m, da.p[4], m, da.p[5], 0,
                           da.p[6]);
            return;
        }
    }

    if (da.fs == final_2e2mu || da.fs == final_2e2muA) {
        const double m1 = da.m.e;
        const double m2 = da.m.mu;

        if (mode == 0) {
            Boost2CM(m1, da.p[2], m1, da.p[3], m2, da.p[4], m2, da.p[5], 0,
                     da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m1, da.p[2], m1, da.p[3], m2, da.p[4], m2, da.p[5],
                           0, da.p[6]);
            return;
        }
    }

    if (da.fs == final_2mu || da.fs == final_2muA) {
        const double m = da.m.mu;

        if (mode == 0) {
            Boost2CM(m, da.p[2], m, da.p[3], 0, da.p[4], 0, da.p[5], 0,
                     da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m, da.p[2], m, da.p[3], 0, da.p[4], 0, da.p[5], 0,
                           da.p[6]);
            return;
        }
    }

    if (da.fs == final_ttbb_) {
        const double m1 = da.m.b;
        const double m2 = da.m.t;

        if (mode == 0) {
            Boost2CM(m2, da.p[2], m2, da.p[3], m1, da.p[4], m1, da.p[5], 0,
                     da.p[6]);
            return;
        }
        if (mode == 1) {
            Boost_5p_2_pT0(m2, da.p[2], m2, da.p[3], m1, da.p[4], m1, da.p[5],
                           0, da.p[6]);
            return;
        }
    }

    cerr << "MAYDAY!!! Undefined behavior!\n";
    exit(1);
}

void MEKD::Zero_first_two(vector<double *> &p)
{
    p[0][0] = 0;
    p[0][1] = 0;
    p[0][2] = 0;
    p[0][3] = 0;

    p[1][0] = 0;
    p[1][1] = 0;
    p[1][2] = 0;
    p[1][3] = 0;
}

// exact mT/sqrt_s * (e^eta3 + e^eta4), mt=sqrt(m^2+pT^2), 12 -> 34
double MEKD::Get_PDF_x1(const vector<double *> &p)
{
    return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) +
            (p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) /
           param.sqrt_s;
}

// exact mT/sqrt_s * (e^-eta3 + e^-eta4), mt=sqrt(m^2+pT^2), 12 -> 34
double MEKD::Get_PDF_x2(const vector<double *> &p)
{
    return ((p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]) -
            (p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3])) /
           param.sqrt_s;
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

    return sqrt(sum_E * sum_E - sum_px * sum_px - sum_py * sum_py -
                sum_pz * sum_pz);
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

/// end of namespace
}

#endif // end of MEKD_MEKD_cpp
