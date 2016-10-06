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
    // 	process_description sig;
    // 	process_description bkg;
    process_description sig_bkg2;
    process_description sig2;
    process_description bkg2;
    vector<process_description> init_desc;
    vector<double> MEs;

    sig_bkg.model = model_SM;
    sig_bkg.process = proc_ttX;
    sig_bkg.resonance = bkg_reson_Spin0Pm;
    sig_bkg.production = prod_all;
    sig_bkg.decay = decay_2f;
    sig_bkg.final_state = final_ttbb;

    //     sig.model = model_SM;
    // 	sig.process = proc_ttX;
    // 	sig.resonance = reson_Spin0Pm;
    // 	sig.production = prod_all;
    // 	sig.decay = decay_2f;
    // 	sig.final_state = final_ttbb;

    //     sig.model = model_SM;
    // 	bkg.process = proc_ttX;
    // 	bkg.resonance = bkg_tt;
    // 	bkg.production = prod_all;
    // 	bkg.decay = decay_2f;
    // 	bkg.final_state = final_ttbb;

    sig_bkg2.model = model_HEFTU;
    sig_bkg2.process = proc_ttX;
    sig_bkg2.resonance = bkg_reson_Spin0Pm;
    sig_bkg2.production = prod_all;
    sig_bkg2.decay = decay_2f;
    sig_bkg2.final_state = final_ttbb;

    sig2.model = model_HEFTU;
    sig2.process = proc_ttX;
    sig2.resonance = reson_Spin0Pm;
    sig2.production = prod_all;
    sig2.decay = decay_2f;
    sig2.final_state = final_ttbb;

    bkg2.model = model_HEFTU;
    bkg2.process = proc_ttX;
    bkg2.resonance = bkg_tt;
    bkg2.production = prod_all;
    bkg2.decay = decay_2f;
    bkg2.final_state = final_ttbb;

    init_desc.push_back(sig_bkg);
    // 	init_desc.push_back(sig);
    // 	init_desc.push_back(bkg);
    init_desc.push_back(sig_bkg2);
    init_desc.push_back(sig2);
    init_desc.push_back(bkg2);

    MEKD test1(init_desc);
    test1.flag.Use_PDF_w_pT0 = true;
    //     test1.flag.use_prod_ddx = false;
    //     test1.flag.use_prod_uux = false;
    //     test1.flag.use_prod_ssx = false;
    //     test1.flag.use_prod_ccx = false;
    test1.flag.use_prod_bbx = false;
    //     test1.flag.use_prod_gg = false;
    test1.eval_MEs(in, MEs);

    if (Show_Basic_Data) {
        cout << "ME: estimation\n";
        unsigned int i = 0;
        for (auto ME : MEs) {
            cout << "ME" << i << ": " << ME << endl;
            ++i;
        }
    }

    return 0;
}

#endif