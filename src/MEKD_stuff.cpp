#ifndef MEKD_stuff_cpp
#define MEKD_stuff_cpp

#include "../interface/MEKD.h"

using namespace std;

namespace mekd
{

void MEKD::Check_MEs()
{
    /// Cross-cheking MEs for consistency. ZZ
    if (ME_qq_ZZ_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_ZZ_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_qq_Z4l_BKG_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_BKG_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_qq_Z4l_SIG_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_Z4l_SIG_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

//     if (ME_Signal_gg_Spin0_OF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_SF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_OFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_SFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }

    // 	if( ME_Signal_qq_Spin0_DownType_OF.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_DownType_SF.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_OF.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_SF.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_DownType_OFpA.nprocesses!=2 ) { cerr << "Problem
    // in ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_DownType_SFpA.nprocesses!=2 ) { cerr << "Problem
    // in ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_OFpA.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_SFpA.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }

    if (ME_Signal_qq_Spin1_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_gg_Spin2_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_qq_Spin2_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    /// Cross-cheking MEs for consistency. ZZ and two-fermion couplings
//     if (ME_Signal_gg_Spin0_2f_OF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_2f_SF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_2f_OFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_2f_SFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }

    if (ME_Signal_qq_Spin1_2f_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_2f_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_gg_Spin2_2f_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_2f_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_2f_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_2f_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_qq_Spin2_2f_DownType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_DownType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_UpType_OF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_UpType_SF.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_DownType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_DownType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_UpType_OFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_2f_UpType_SFpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    ///  Cross-cheking MEs for consistency. ZZ, no initial state
    if (ME_DY_2l.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_DY_2lpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

//     if (ME_Signal_Spin0_2l.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_OF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_SF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_2f_OF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_2f_SF.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_2lpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_OFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_SFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_2f_OFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_Spin0_2f_SFpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }

    if (ME_Signal_Spin1_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_2f_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_2f_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_2f_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin1_2f_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_Spin2_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_2f_OF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_2f_SF.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_2f_OFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_Spin2_2f_SFpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    /// Cross-cheking MEs for consistency. 2mu
    if (ME_qq_DY_DownType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_DY_UpType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_DY_DownType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_qq_DY_UpType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

//     if (ME_Signal_gg_Spin0_2l.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }
//     if (ME_Signal_gg_Spin0_2lpA.nprocesses != 1) {
//         cerr << "Problem in ME class detected. Exiting.\n";
//         exit(1);
//     }

    // 	if( ME_Signal_qq_Spin0_DownType_2l.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_2l.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_DownType_2lpA.nprocesses!=2 ) { cerr << "Problem
    // in ME class detected. Exiting.\n"; exit(1); }
    // 	if( ME_Signal_qq_Spin0_UpType_2lpA.nprocesses!=2 ) { cerr << "Problem in
    // ME class detected. Exiting.\n"; exit(1); }

    if (ME_Signal_qq_Spin1_DownType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_DownType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin1_UpType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_gg_Spin2_2l.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_gg_Spin2_2lpA.nprocesses != 1) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }

    if (ME_Signal_qq_Spin2_DownType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_2l.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_DownType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
    if (ME_Signal_qq_Spin2_UpType_2lpA.nprocesses != 2) {
        cerr << "Problem in ME class detected. Exiting.\n";
        exit(1);
    }
}

void MEKD::Load_parameters_MEs(const string &param_f)
{
    // ZZ
    ME_qq_ZZ_UpType_SF.initProc(param_f);
    ME_qq_ZZ_UpType_OF.initProc(param_f);
    ME_qq_ZZ_DownType_SF.initProc(param_f);
    ME_qq_ZZ_DownType_OF.initProc(param_f);
    ME_qq_ZZ_UpType_SFpA.initProc(param_f);
    ME_qq_ZZ_UpType_OFpA.initProc(param_f);
    ME_qq_ZZ_DownType_SFpA.initProc(param_f);
    ME_qq_ZZ_DownType_OFpA.initProc(param_f);

    ME_qq_Z4l_BKG_UpType_SF.initProc(param_f);
    ME_qq_Z4l_BKG_UpType_OF.initProc(param_f);
    ME_qq_Z4l_BKG_DownType_SF.initProc(param_f);
    ME_qq_Z4l_BKG_DownType_OF.initProc(param_f);
    ME_qq_Z4l_BKG_UpType_SFpA.initProc(param_f);
    ME_qq_Z4l_BKG_UpType_OFpA.initProc(param_f);
    ME_qq_Z4l_BKG_DownType_SFpA.initProc(param_f);
    ME_qq_Z4l_BKG_DownType_OFpA.initProc(param_f);

    ME_qq_Z4l_SIG_UpType_SF.initProc(param_f);
    ME_qq_Z4l_SIG_UpType_OF.initProc(param_f);
    ME_qq_Z4l_SIG_DownType_SF.initProc(param_f);
    ME_qq_Z4l_SIG_DownType_OF.initProc(param_f);
    ME_qq_Z4l_SIG_UpType_SFpA.initProc(param_f);
    ME_qq_Z4l_SIG_UpType_OFpA.initProc(param_f);
    ME_qq_Z4l_SIG_DownType_SFpA.initProc(param_f);
    ME_qq_Z4l_SIG_DownType_OFpA.initProc(param_f);

//     ME_Signal_gg_Spin0_SF.initProc(param_f);
//     ME_Signal_gg_Spin0_OF.initProc(param_f);
//     ME_Signal_gg_Spin0_SFpA.initProc(param_f);
//     ME_Signal_gg_Spin0_OFpA.initProc(param_f);

    // 	ME_Signal_qq_Spin0_DownType_SF.initProc(param_f);
    // 	ME_Signal_qq_Spin0_DownType_OF.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_SF.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_OF.initProc(param_f);
    // 	ME_Signal_qq_Spin0_DownType_SFpA.initProc(param_f);
    // 	ME_Signal_qq_Spin0_DownType_OFpA.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_SFpA.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_OFpA.initProc(param_f);

    ME_Signal_qq_Spin1_DownType_SF.initProc(param_f);
    ME_Signal_qq_Spin1_DownType_OF.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_SF.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_OF.initProc(param_f);
    ME_Signal_qq_Spin1_DownType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin1_DownType_OFpA.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_OFpA.initProc(param_f);

    ME_Signal_gg_Spin2_SF.initProc(param_f);
    ME_Signal_gg_Spin2_OF.initProc(param_f);
    ME_Signal_gg_Spin2_SFpA.initProc(param_f);
    ME_Signal_gg_Spin2_OFpA.initProc(param_f);

    ME_Signal_qq_Spin2_DownType_SF.initProc(param_f);
    ME_Signal_qq_Spin2_DownType_OF.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_SF.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_OF.initProc(param_f);
    ME_Signal_qq_Spin2_DownType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin2_DownType_OFpA.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_OFpA.initProc(param_f);

    // ZZ and two-fermion couplings
//     ME_Signal_gg_Spin0_2f_SF.initProc(param_f);
//     ME_Signal_gg_Spin0_2f_OF.initProc(param_f);
//     ME_Signal_gg_Spin0_2f_SFpA.initProc(param_f);
//     ME_Signal_gg_Spin0_2f_OFpA.initProc(param_f);

    ME_Signal_qq_Spin1_2f_DownType_SF.initProc(param_f);
    ME_Signal_qq_Spin1_2f_DownType_OF.initProc(param_f);
    ME_Signal_qq_Spin1_2f_UpType_SF.initProc(param_f);
    ME_Signal_qq_Spin1_2f_UpType_OF.initProc(param_f);
    ME_Signal_qq_Spin1_2f_DownType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin1_2f_DownType_OFpA.initProc(param_f);
    ME_Signal_qq_Spin1_2f_UpType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin1_2f_UpType_OFpA.initProc(param_f);

    ME_Signal_gg_Spin2_2f_SF.initProc(param_f);
    ME_Signal_gg_Spin2_2f_OF.initProc(param_f);
    ME_Signal_gg_Spin2_2f_SFpA.initProc(param_f);
    ME_Signal_gg_Spin2_2f_OFpA.initProc(param_f);

    ME_Signal_qq_Spin2_2f_DownType_SF.initProc(param_f);
    ME_Signal_qq_Spin2_2f_DownType_OF.initProc(param_f);
    ME_Signal_qq_Spin2_2f_UpType_SF.initProc(param_f);
    ME_Signal_qq_Spin2_2f_UpType_OF.initProc(param_f);
    ME_Signal_qq_Spin2_2f_DownType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin2_2f_DownType_OFpA.initProc(param_f);
    ME_Signal_qq_Spin2_2f_UpType_SFpA.initProc(param_f);
    ME_Signal_qq_Spin2_2f_UpType_OFpA.initProc(param_f);

    // ZZ, no itial state
    ME_DY_2l.initProc(param_f);
    ME_DY_2lpA.initProc(param_f);

//     ME_Signal_Spin0_2l.initProc(param_f);
//     ME_Signal_Spin0_SF.initProc(param_f);
//     ME_Signal_Spin0_OF.initProc(param_f);
//     ME_Signal_Spin0_2f_SF.initProc(param_f);
//     ME_Signal_Spin0_2f_OF.initProc(param_f);
//     ME_Signal_Spin0_2lpA.initProc(param_f);
//     ME_Signal_Spin0_SFpA.initProc(param_f);
//     ME_Signal_Spin0_OFpA.initProc(param_f);
//     ME_Signal_Spin0_2f_SFpA.initProc(param_f);
//     ME_Signal_Spin0_2f_OFpA.initProc(param_f);

    ME_Signal_Spin1_2l.initProc(param_f);
    ME_Signal_Spin1_SF.initProc(param_f);
    ME_Signal_Spin1_OF.initProc(param_f);
    ME_Signal_Spin1_2f_SF.initProc(param_f);
    ME_Signal_Spin1_2f_OF.initProc(param_f);
    ME_Signal_Spin1_2lpA.initProc(param_f);
    ME_Signal_Spin1_SFpA.initProc(param_f);
    ME_Signal_Spin1_OFpA.initProc(param_f);
    ME_Signal_Spin1_2f_SFpA.initProc(param_f);
    ME_Signal_Spin1_2f_OFpA.initProc(param_f);

    ME_Signal_Spin2_2l.initProc(param_f);
    ME_Signal_Spin2_SF.initProc(param_f);
    ME_Signal_Spin2_OF.initProc(param_f);
    ME_Signal_Spin2_2f_SF.initProc(param_f);
    ME_Signal_Spin2_2f_OF.initProc(param_f);
    ME_Signal_Spin2_2lpA.initProc(param_f);
    ME_Signal_Spin2_SFpA.initProc(param_f);
    ME_Signal_Spin2_OFpA.initProc(param_f);
    ME_Signal_Spin2_2f_SFpA.initProc(param_f);
    ME_Signal_Spin2_2f_OFpA.initProc(param_f);

    // 2mu
    ME_qq_DY_UpType_2l.initProc(param_f);
    ME_qq_DY_DownType_2l.initProc(param_f);
    ME_qq_DY_UpType_2lpA.initProc(param_f);
    ME_qq_DY_DownType_2lpA.initProc(param_f);

//     ME_Signal_gg_Spin0_2l.initProc(param_f);
//     ME_Signal_gg_Spin0_2lpA.initProc(param_f);

    // 	ME_Signal_qq_Spin0_DownType_2l.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_2l.initProc(param_f);
    // 	ME_Signal_qq_Spin0_DownType_2lpA.initProc(param_f);
    // 	ME_Signal_qq_Spin0_UpType_2lpA.initProc(param_f);

    ME_Signal_qq_Spin1_DownType_2l.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_2l.initProc(param_f);
    ME_Signal_qq_Spin1_DownType_2lpA.initProc(param_f);
    ME_Signal_qq_Spin1_UpType_2lpA.initProc(param_f);

    ME_Signal_gg_Spin2_2l.initProc(param_f);
    ME_Signal_gg_Spin2_2lpA.initProc(param_f);

    ME_Signal_qq_Spin2_DownType_2l.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_2l.initProc(param_f);
    ME_Signal_qq_Spin2_DownType_2lpA.initProc(param_f);
    ME_Signal_qq_Spin2_UpType_2lpA.initProc(param_f);

    //// RAW MG5_aMC ME. For testing purposes only.
    // ME_RAW.initProc("../src/MG5_aMCNLO/RAW/param_card.dat");
}

void MEKD::Load_parameters_extract_params(const Parameters_MEKD *pa, data &da)
{
    da.m.d = pa->mdl_MD;
    da.m.u = pa->mdl_MU;
    da.m.s = pa->mdl_MS;
    da.m.c = pa->mdl_MC;
    da.m.b = pa->mdl_MB;
    da.m.e = pa->mdl_Me;
    da.m.mu = pa->mdl_MM;
    da.m.Z = pa->mdl_MZ;
    
    da.c.rhou01 = pa->rhou01;
    da.c.rhou02 = pa->rhou02;
    da.c.rhoc01 = pa->rhoc01;
    da.c.rhoc02 = pa->rhoc02;
    da.c.rhod01 = pa->rhod01;
    da.c.rhod02 = pa->rhod02;
    da.c.rhos01 = pa->rhos01;
    da.c.rhos02 = pa->rhos02;
    da.c.rhob01 = pa->rhob01;
    da.c.rhob02 = pa->rhob02;

    da.c.rhou11 = pa->rhou11;
    da.c.rhou12 = pa->rhou12;
    da.c.rhou13 = pa->rhou13;
    da.c.rhou14 = pa->rhou14;
    da.c.rhoc11 = pa->rhoc11;
    da.c.rhoc12 = pa->rhoc12;
    da.c.rhoc13 = pa->rhoc13;
    da.c.rhoc14 = pa->rhoc14;
    da.c.rhod11 = pa->rhod11;
    da.c.rhod12 = pa->rhod12;
    da.c.rhod13 = pa->rhod13;
    da.c.rhod14 = pa->rhod14;
    da.c.rhos11 = pa->rhos11;
    da.c.rhos12 = pa->rhos12;
    da.c.rhos13 = pa->rhos13;
    da.c.rhos14 = pa->rhos14;
    da.c.rhob11 = pa->rhob11;
    da.c.rhob12 = pa->rhob12;
    da.c.rhob13 = pa->rhob13;
    da.c.rhob14 = pa->rhob14;

    da.c.rhou21 = pa->rhou21;
    da.c.rhou22 = pa->rhou22;
    da.c.rhou23 = pa->rhou23;
    da.c.rhou24 = pa->rhou24;
    da.c.rhoc21 = pa->rhoc21;
    da.c.rhoc22 = pa->rhoc22;
    da.c.rhoc23 = pa->rhoc23;
    da.c.rhoc24 = pa->rhoc24;
    da.c.rhod21 = pa->rhod21;
    da.c.rhod22 = pa->rhod22;
    da.c.rhod23 = pa->rhod23;
    da.c.rhod24 = pa->rhod24;
    da.c.rhos21 = pa->rhos21;
    da.c.rhos22 = pa->rhos22;
    da.c.rhos23 = pa->rhos23;
    da.c.rhos24 = pa->rhos24;
    da.c.rhob21 = pa->rhob21;
    da.c.rhob22 = pa->rhob22;
    da.c.rhob23 = pa->rhob23;
    da.c.rhob24 = pa->rhob24;
}

void MEKD::Load_parameters_eval_params(const Parameters_MEKD *paM,
                                       const data &da,
                                       parameters &pa)
{
    pa.vev = paM->mdl_vev; // = 1.0 / sqrt(sqrt(2) * paM->mdl_Gf;
    pa.hZZ_coupling = 2.0 * da.m.Z * da.m.Z / pa.vev;
}

/// end of namespace
}

#endif