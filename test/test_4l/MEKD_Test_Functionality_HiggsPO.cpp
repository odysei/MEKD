#ifndef MEKD_TEST_FUNCTIONALITY_HiggsPO_CPP
#define MEKD_TEST_FUNCTIONALITY_HiggsPO_CPP

#include "MEKD_Test_HiggsPO.h"

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
    vector<process_description> init_desc;
    vector<double> MEs;

    ggSpin0Pm.model = model_HiggsPO;
    ggSpin0Pm.process = proc_simple;
    ggSpin0Pm.resonance = reson_Spin0Pm;
    ggSpin0Pm.production = prod_gg;
    ggSpin0Pm.decay = decay_VV;
    ggSpin0Pm.final_state = final_4l;

    init_desc.push_back(ggSpin0Pm);

    MEKD test1(init_desc);
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