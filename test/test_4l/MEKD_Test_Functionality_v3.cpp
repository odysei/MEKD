#ifndef MEKD_TEST_FUNCTIONALITY_V3_CPP
#define MEKD_TEST_FUNCTIONALITY_V3_CPP

#include "MEKD_Test_v3.h"

bool Reference_is_calculated = false;

double KD1, ME11, ME21;

/*
 *
 * TEST Block "on the fly".
 *
 */

int MEKD_Test_Functionality_Test1(input &in)
{
    /// TEST 1
    if (Show_Description)
        cout << "\n -- STARTING TEST 1 -- \n";
    // 	double KD1, ME11, ME21;

    if (Show_Description)
        cout << "Testing void eval_MEs(const input &, vector<double> &);\n";

    process_description ggSpin0Pm;
    process_description ZZ;
    vector<process_description> init_desc;
    vector<double> MEs;

    ggSpin0Pm.model = model_MEKD;
    ggSpin0Pm.process = proc_simple;
    ggSpin0Pm.resonance = reson_Spin0Pm;
    ggSpin0Pm.production = prod_gg;
    ggSpin0Pm.decay = decay_ZZ;
    ggSpin0Pm.final_state = final_4l;

    ZZ.model = model_HEF_UFO;
    ZZ.process = proc_simple;
    ZZ.resonance = bkg_Z;
    ZZ.production = prod_qq;
    ZZ.decay = decay_ZZ;
    ZZ.final_state = final_4l;

    init_desc.push_back(ggSpin0Pm);
    init_desc.push_back(ZZ);

    MEKD test1(init_desc);
    test1.eval_MEs(in, MEs);

    ME11 = MEs[0];
    ME21 = MEs[1];
    KD1 = log(MEs[0] / MEs[1]);

    if (Show_Basic_Data) {
        cout << "Output: ME1 ME2 KD\n";
        cout << ME11 << " " << ME21 << " " << KD1 << endl;
    }

    Reference_is_calculated = true;

    return 0;
}

#endif