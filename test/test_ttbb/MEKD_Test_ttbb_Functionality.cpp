#ifndef MEKD_Test_ttbb_Functionality_cpp
#define MEKD_Test_ttbb_Functionality_cpp

#include "MEKD_Test_ttbb.h"

/*
 * 
 * TEST Block "on the fly".
 *
 */

int MEKD_Test_ttbb_Functionality_Test1(input &in)
{
	/// TEST 1
	if (Show_Description)
		cout << "\n -- STARTING TEST 1 -- \n";

	if (Show_Description)
		cout << "Testing void eval_MEs(const input &, vector<double> &);\n";
	
	process_description sig_bkg;
// 	process_description bkg;
	vector<process_description> init_desc;
	vector<double> MEs;
	
	sig_bkg.process = proc_ttX;
	sig_bkg.resonance = bkg_reson_Spin0Pm;
	sig_bkg.production = prod_all;
	sig_bkg.decay = decay_2f;
	sig_bkg.final_state = final_ttbb;
	
// 	bkg.process = proc_ttX;
// 	bkg.resonance = bkg_tt;
// 	bkg.production = prod_all;
// 	bkg.decay = decay_2f;
// 	bkg.final_state = final_ttbb;
	
	init_desc.push_back(sig_bkg);
// 	init_desc.push_back(bkg);
	
	MEKD test1(init_desc);
	test1.eval_MEs(in, MEs);

	if (Show_Basic_Data) {
        cout << "ME: estimation\n";
        unsigned int i = 0;
        for (auto ME: MEs) {
            cout << "ME" << i << ": " << ME << endl;
        }
	}

	return 0;
}

#endif