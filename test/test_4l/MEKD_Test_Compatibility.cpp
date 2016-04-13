#ifndef MEKD_Test_Compatibility_cpp
#define MEKD_Test_Compatibility_cpp

#include "MEKD_Test_HiggsPO.h"

/*
 *
 * TEST Block "on the fly".
 *
 */

int MEKD_Test_Compatibility_Test1(input &in)
{
    /// TEST 1
    if (Show_Description)
        cout << "\n -- STARTING TEST 1 -- \n";
    // 	double KD1, ME11, ME21;

    if (Show_Description)
        cout << "Testing model_HiggsPO (XVV) vs. model_MEKD (XZZ) with "
                "reson_Spin0Pm\n";

    process_description ggSpin0Pm_HPO;
    process_description ggSpin0Pm_MEKD;
    vector<process_description> init_desc;
    vector<double> MEs;

    ggSpin0Pm_HPO.model = model_HiggsPO;
    ggSpin0Pm_HPO.process = proc_simple;
    ggSpin0Pm_HPO.resonance = reson_Spin0Pm;
    ggSpin0Pm_HPO.production = prod_gg;
    ggSpin0Pm_HPO.decay = decay_VV;
    ggSpin0Pm_HPO.final_state = final_4l;

    ggSpin0Pm_MEKD.model = model_MEKD;
    ggSpin0Pm_MEKD.process = proc_simple;
    ggSpin0Pm_MEKD.resonance = reson_Spin0Pm;
    ggSpin0Pm_MEKD.production = prod_gg;
    ggSpin0Pm_MEKD.decay = decay_ZZ;
    ggSpin0Pm_MEKD.final_state = final_4l;

    init_desc.push_back(ggSpin0Pm_HPO);
    init_desc.push_back(ggSpin0Pm_MEKD);

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

    if (MEs.size() == 2) {
        const double ratio = MEs[0] / MEs[1];
        const double error = 0.02;
        if (ratio < (1.0 + error) && ratio > (1.0 - error))
            return 0;
    }

    return 1;
}

int MEKD_Test_Compatibility_Test2(input &in)
{
    /// TEST 1
    if (Show_Description)
        cout << "\n -- STARTING TEST 2 -- \n";
    // 	double KD1, ME11, ME21;

    if (Show_Description)
        cout << "Testing model_HiggsPO (XZZ custom) with reson_Spin0 vs. "
                "model_MEKD (XZZ) with reson_Spin0Pm\n";

    process_description ggSpin0Pm_HPO;
    process_description ggSpin0Pm_MEKD;
    vector<process_description> init_desc;
    vector<double> MEs;

    ggSpin0Pm_HPO.model = model_HiggsPO;
    ggSpin0Pm_HPO.process = proc_simple;
    ggSpin0Pm_HPO.resonance = reson_Spin0;
    ggSpin0Pm_HPO.production = prod_gg;
    ggSpin0Pm_HPO.decay = decay_VV;
    ggSpin0Pm_HPO.final_state = final_4l;

    ggSpin0Pm_MEKD.model = model_MEKD;
    ggSpin0Pm_MEKD.process = proc_simple;
    ggSpin0Pm_MEKD.resonance = reson_Spin0Pm;
    ggSpin0Pm_MEKD.production = prod_gg;
    ggSpin0Pm_MEKD.decay = decay_ZZ;
    ggSpin0Pm_MEKD.final_state = final_4l;

    init_desc.push_back(ggSpin0Pm_HPO);
    init_desc.push_back(ggSpin0Pm_MEKD);

    MG5_HiggsPO_UFO::input_c in_c;
    in_c.p = in.p;
    in_c.id = in.id;
    in_c.c.kZZ = 1;
    in_c.c.eZZ = 0;
    in_c.c.eZZCP = 0;

    in_c.c.kZA = 0;
    in_c.c.lZACP = 0;

    in_c.c.kAA = 0;
    in_c.c.lAACP = 0;

    in_c.c.eZeL = 0;
    in_c.c.eZeR = 0;
    in_c.c.eZmuL = 0;
    in_c.c.eZmuR = 0;

    MEKD test1(init_desc);
    test1.eval_MEs(in_c, MEs);

    if (Show_Basic_Data) {
        cout << "ME: estimation\n";
        unsigned int i = 0;
        for (auto ME : MEs) {
            cout << "ME" << i << ": " << ME << endl;
            ++i;
        }
    }

    if (MEs.size() == 2) {
        const double ratio = MEs[0] / MEs[1];
        const double error = 0.01;
        if (ratio < (1.0 + error) && ratio > (1.0 - error))
            return 0;
    }

    return 1;
}

#endif