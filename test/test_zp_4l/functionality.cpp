#ifndef MEKD__test__zp_4l__functionality_cpp
#define MEKD__test__zp_4l__functionality_cpp

#include "functionality.h"
#include "test.h"

using namespace mekd;

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

    process_description pd1;
    pd1.model = model_Leptophilic_Zp;
    pd1.process = proc_cascade;
    pd1.resonance = reson_Spin1M;
    pd1.production = prod_qq;
    pd1.decay = decay_2f;
    pd1.final_state = final_4l;

    process_description pd2;
    pd2.model = model_HEF_UFO;
    pd2.process = proc_simple;
    pd2.resonance = bkg_Z;
    pd2.production = prod_qq;
    pd2.decay = decay_ZZ;
    pd2.final_state = final_4l;

    // process_description pd3;
    // pd3.model = model_HEF_UFO;
    // pd3.process = proc_simple;
    // pd3.resonance = bkg_Zs;
    // pd3.production = prod_qq;
    // pd3.decay = decay_2f;
    // pd3.final_state = final_4l;
    //
    // process_description pd4;
    // pd4.model = model_HEF_UFO;
    // pd4.process = proc_simple;
    // pd4.resonance = bkg_Zt;
    // pd4.production = prod_qq;
    // pd4.decay = decay_2f;
    // pd4.final_state = final_4l;

    vector<process_description> init_desc;
    init_desc.push_back(pd1);
    init_desc.push_back(pd2);
    // init_desc.push_back(pd3);
    // init_desc.push_back(pd4);

    MEKD test1(init_desc);
    // test1.flag.Debug_Mode = true;
    test1.flag.Use_PDF_w_pT0 = false;
    // test1.flag.use_prod_2013_convetion_for_4l = false;
    // test1.flag.use_prod_ddx = false;
    // test1.flag.use_prod_uux = false;
    // test1.flag.use_prod_ssx = true;
    // test1.flag.use_prod_ccx = true;
    // test1.flag.use_prod_bbx = false;
    // test1.flag.use_prod_gg = false;
    vector<double> MEs;
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
