#ifndef MEKD_MG_cpp
#define MEKD_MG_cpp

#include "../interface/MEKD_MG.h"

using namespace std;

namespace mekd
{

void MEKD_MG::Check_MEs()
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

	if (ME_Signal_gg_Spin0_OF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_SF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_OFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_SFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}

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
	if (ME_Signal_gg_Spin0_2f_OF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_2f_SF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_2f_OFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_2f_SFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}

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

	if (ME_Signal_Spin0_2l.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_OF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_SF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_2f_OF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_2f_SF.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_2lpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_OFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_SFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_2f_OFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_Spin0_2f_SFpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}

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

	if (ME_Signal_gg_Spin0_2l.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}
	if (ME_Signal_gg_Spin0_2lpA.nprocesses != 1) {
		cerr << "Problem in ME class detected. Exiting.\n";
		exit(1);
	}

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

void MEKD_MG::Load_Parameters_MEs()
{
	// ZZ
	ME_qq_ZZ_UpType_SF.initProc(Parameter_file);
	ME_qq_ZZ_UpType_OF.initProc(Parameter_file);
	ME_qq_ZZ_DownType_SF.initProc(Parameter_file);
	ME_qq_ZZ_DownType_OF.initProc(Parameter_file);
	ME_qq_ZZ_UpType_SFpA.initProc(Parameter_file);
	ME_qq_ZZ_UpType_OFpA.initProc(Parameter_file);
	ME_qq_ZZ_DownType_SFpA.initProc(Parameter_file);
	ME_qq_ZZ_DownType_OFpA.initProc(Parameter_file);

	ME_qq_Z4l_BKG_UpType_SF.initProc(Parameter_file);
	ME_qq_Z4l_BKG_UpType_OF.initProc(Parameter_file);
	ME_qq_Z4l_BKG_DownType_SF.initProc(Parameter_file);
	ME_qq_Z4l_BKG_DownType_OF.initProc(Parameter_file);
	ME_qq_Z4l_BKG_UpType_SFpA.initProc(Parameter_file);
	ME_qq_Z4l_BKG_UpType_OFpA.initProc(Parameter_file);
	ME_qq_Z4l_BKG_DownType_SFpA.initProc(Parameter_file);
	ME_qq_Z4l_BKG_DownType_OFpA.initProc(Parameter_file);

	ME_qq_Z4l_SIG_UpType_SF.initProc(Parameter_file);
	ME_qq_Z4l_SIG_UpType_OF.initProc(Parameter_file);
	ME_qq_Z4l_SIG_DownType_SF.initProc(Parameter_file);
	ME_qq_Z4l_SIG_DownType_OF.initProc(Parameter_file);
	ME_qq_Z4l_SIG_UpType_SFpA.initProc(Parameter_file);
	ME_qq_Z4l_SIG_UpType_OFpA.initProc(Parameter_file);
	ME_qq_Z4l_SIG_DownType_SFpA.initProc(Parameter_file);
	ME_qq_Z4l_SIG_DownType_OFpA.initProc(Parameter_file);

	ME_Signal_gg_Spin0_SF.initProc(Parameter_file);
	ME_Signal_gg_Spin0_OF.initProc(Parameter_file);
	ME_Signal_gg_Spin0_SFpA.initProc(Parameter_file);
	ME_Signal_gg_Spin0_OFpA.initProc(Parameter_file);

	// 	ME_Signal_qq_Spin0_DownType_SF.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_DownType_OF.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_SF.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_OF.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_DownType_SFpA.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_DownType_OFpA.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_SFpA.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_OFpA.initProc( Parameter_file );

	ME_Signal_qq_Spin1_DownType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_DownType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_DownType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_DownType_OFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_OFpA.initProc(Parameter_file);

	ME_Signal_gg_Spin2_SF.initProc(Parameter_file);
	ME_Signal_gg_Spin2_OF.initProc(Parameter_file);
	ME_Signal_gg_Spin2_SFpA.initProc(Parameter_file);
	ME_Signal_gg_Spin2_OFpA.initProc(Parameter_file);

	ME_Signal_qq_Spin2_DownType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_DownType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_DownType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_DownType_OFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_OFpA.initProc(Parameter_file);

	// ZZ and two-fermion couplings
	ME_Signal_gg_Spin0_2f_SF.initProc(Parameter_file);
	ME_Signal_gg_Spin0_2f_OF.initProc(Parameter_file);
	ME_Signal_gg_Spin0_2f_SFpA.initProc(Parameter_file);
	ME_Signal_gg_Spin0_2f_OFpA.initProc(Parameter_file);

	ME_Signal_qq_Spin1_2f_DownType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_DownType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_UpType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_UpType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_DownType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_DownType_OFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_UpType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_2f_UpType_OFpA.initProc(Parameter_file);

	ME_Signal_gg_Spin2_2f_SF.initProc(Parameter_file);
	ME_Signal_gg_Spin2_2f_OF.initProc(Parameter_file);
	ME_Signal_gg_Spin2_2f_SFpA.initProc(Parameter_file);
	ME_Signal_gg_Spin2_2f_OFpA.initProc(Parameter_file);

	ME_Signal_qq_Spin2_2f_DownType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_DownType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_UpType_SF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_UpType_OF.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_DownType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_DownType_OFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_UpType_SFpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_2f_UpType_OFpA.initProc(Parameter_file);

	// ZZ, no itial state
	ME_DY_2l.initProc(Parameter_file);
	ME_DY_2lpA.initProc(Parameter_file);

	ME_Signal_Spin0_2l.initProc(Parameter_file);
	ME_Signal_Spin0_SF.initProc(Parameter_file);
	ME_Signal_Spin0_OF.initProc(Parameter_file);
	ME_Signal_Spin0_2f_SF.initProc(Parameter_file);
	ME_Signal_Spin0_2f_OF.initProc(Parameter_file);
	ME_Signal_Spin0_2lpA.initProc(Parameter_file);
	ME_Signal_Spin0_SFpA.initProc(Parameter_file);
	ME_Signal_Spin0_OFpA.initProc(Parameter_file);
	ME_Signal_Spin0_2f_SFpA.initProc(Parameter_file);
	ME_Signal_Spin0_2f_OFpA.initProc(Parameter_file);

	ME_Signal_Spin1_2l.initProc(Parameter_file);
	ME_Signal_Spin1_SF.initProc(Parameter_file);
	ME_Signal_Spin1_OF.initProc(Parameter_file);
	ME_Signal_Spin1_2f_SF.initProc(Parameter_file);
	ME_Signal_Spin1_2f_OF.initProc(Parameter_file);
	ME_Signal_Spin1_2lpA.initProc(Parameter_file);
	ME_Signal_Spin1_SFpA.initProc(Parameter_file);
	ME_Signal_Spin1_OFpA.initProc(Parameter_file);
	ME_Signal_Spin1_2f_SFpA.initProc(Parameter_file);
	ME_Signal_Spin1_2f_OFpA.initProc(Parameter_file);

	ME_Signal_Spin2_2l.initProc(Parameter_file);
	ME_Signal_Spin2_SF.initProc(Parameter_file);
	ME_Signal_Spin2_OF.initProc(Parameter_file);
	ME_Signal_Spin2_2f_SF.initProc(Parameter_file);
	ME_Signal_Spin2_2f_OF.initProc(Parameter_file);
	ME_Signal_Spin2_2lpA.initProc(Parameter_file);
	ME_Signal_Spin2_SFpA.initProc(Parameter_file);
	ME_Signal_Spin2_OFpA.initProc(Parameter_file);
	ME_Signal_Spin2_2f_SFpA.initProc(Parameter_file);
	ME_Signal_Spin2_2f_OFpA.initProc(Parameter_file);

	// 2mu
	ME_qq_DY_UpType_2l.initProc(Parameter_file);
	ME_qq_DY_DownType_2l.initProc(Parameter_file);
	ME_qq_DY_UpType_2lpA.initProc(Parameter_file);
	ME_qq_DY_DownType_2lpA.initProc(Parameter_file);

	ME_Signal_gg_Spin0_2l.initProc(Parameter_file);
	ME_Signal_gg_Spin0_2lpA.initProc(Parameter_file);

	// 	ME_Signal_qq_Spin0_DownType_2l.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_2l.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_DownType_2lpA.initProc( Parameter_file );
	// 	ME_Signal_qq_Spin0_UpType_2lpA.initProc( Parameter_file );

	ME_Signal_qq_Spin1_DownType_2l.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_2l.initProc(Parameter_file);
	ME_Signal_qq_Spin1_DownType_2lpA.initProc(Parameter_file);
	ME_Signal_qq_Spin1_UpType_2lpA.initProc(Parameter_file);

	ME_Signal_gg_Spin2_2l.initProc(Parameter_file);
	ME_Signal_gg_Spin2_2lpA.initProc(Parameter_file);

	ME_Signal_qq_Spin2_DownType_2l.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_2l.initProc(Parameter_file);
	ME_Signal_qq_Spin2_DownType_2lpA.initProc(Parameter_file);
	ME_Signal_qq_Spin2_UpType_2lpA.initProc(Parameter_file);

	//// RAW MG5_aMC ME. For testing purposes only.
	//ME_RAW.initProc( "../src/MG5_aMCNLO/RAW/param_card.dat" );
}

void MEKD_MG::Load_Parameters_extract_params(SLHAReader_MEKD &params)
{
	params_m_d = params.get_block_entry("mass", 1, 0).real();
	params_m_u = params.get_block_entry("mass", 2, 0).real();
	params_m_s = params.get_block_entry("mass", 3, 0).real();
	params_m_c = params.get_block_entry("mass", 4, 0).real();
	params_m_e = params.get_block_entry("mass", 11, 0).real();
	params_m_mu = params.get_block_entry("mass", 13, 0).real();
	params_m_Z = params.get_block_entry("mass", 23, 9.11876e+01).real();

	params_rhou11 = params.get_block_entry("heff", 9, 0);
	params_rhou12 = params.get_block_entry("heff", 10, 0);
	params_rhoc11 = params.get_block_entry("heff", 11, 0);
	params_rhoc12 = params.get_block_entry("heff", 12, 0);
	params_rhod11 = params.get_block_entry("heff", 13, 0);
	params_rhod12 = params.get_block_entry("heff", 14, 0);
	params_rhos11 = params.get_block_entry("heff", 15, 0);
	params_rhos12 = params.get_block_entry("heff", 16, 0);
	params_rhob11 = params.get_block_entry("heff", 17, 0);
	params_rhob12 = params.get_block_entry("heff", 18, 0);

	params_rhou11 = params.get_block_entry("vec", 3, 0);
	params_rhou12 = params.get_block_entry("vec", 4, 0);
	params_rhou13 = params.get_block_entry("vec", 5, 0);
	params_rhou14 = params.get_block_entry("vec", 6, 0);
	params_rhoc11 = params.get_block_entry("vec", 7, 0);
	params_rhoc12 = params.get_block_entry("vec", 8, 0);
	params_rhoc13 = params.get_block_entry("vec", 9, 0);
	params_rhoc14 = params.get_block_entry("vec", 10, 0);
	params_rhod11 = params.get_block_entry("vec", 11, 0);
	params_rhod12 = params.get_block_entry("vec", 12, 0);
	params_rhod13 = params.get_block_entry("vec", 13, 0);
	params_rhod14 = params.get_block_entry("vec", 14, 0);
	params_rhos11 = params.get_block_entry("vec", 15, 0);
	params_rhos12 = params.get_block_entry("vec", 16, 0);
	params_rhos13 = params.get_block_entry("vec", 17, 0);
	params_rhos14 = params.get_block_entry("vec", 18, 0);
	params_rhob11 = params.get_block_entry("vec", 19, 0);
	params_rhob12 = params.get_block_entry("vec", 20, 0);
	params_rhob13 = params.get_block_entry("vec", 21, 0);
	params_rhob14 = params.get_block_entry("vec", 22, 0);

	params_rhou21 = params.get_block_entry("gravity", 21, 0);
	params_rhou22 = params.get_block_entry("gravity", 22, 0);
	params_rhou23 = params.get_block_entry("gravity", 23, 0);
	params_rhou24 = params.get_block_entry("gravity", 24, 0);
	params_rhoc21 = params.get_block_entry("gravity", 25, 0);
	params_rhoc22 = params.get_block_entry("gravity", 26, 0);
	params_rhoc23 = params.get_block_entry("gravity", 27, 0);
	params_rhoc24 = params.get_block_entry("gravity", 28, 0);
	params_rhod21 = params.get_block_entry("gravity", 29, 0);
	params_rhod22 = params.get_block_entry("gravity", 30, 0);
	params_rhod23 = params.get_block_entry("gravity", 31, 0);
	params_rhod24 = params.get_block_entry("gravity", 32, 0);
	params_rhos21 = params.get_block_entry("gravity", 33, 0);
	params_rhos22 = params.get_block_entry("gravity", 34, 0);
	params_rhos23 = params.get_block_entry("gravity", 35, 0);
	params_rhos24 = params.get_block_entry("gravity", 36, 0);
	params_rhob21 = params.get_block_entry("gravity", 37, 0);
	params_rhob22 = params.get_block_entry("gravity", 38, 0);
	params_rhob23 = params.get_block_entry("gravity", 39, 0);
	params_rhob24 = params.get_block_entry("gravity", 40, 0);
}

void MEKD_MG::Load_Parameters_eval_params()
{
	v_expectation =
		1.0 /
		sqrt(sqrt(2) *
			 Set_Of_Model_Parameters.get_block_entry("sminputs", 2,
													 1.166370e-05).real());
	hZZ_coupling = 2.0 * params_m_Z * params_m_Z / v_expectation;
}

/// end of namespace
}

#endif