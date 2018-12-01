#ifndef MEKD__test_zp_4l__check_models_cpp
#define MEKD__test_zp_4l__check_models_cpp

#include "test.h"
#include "check_models.h"
#include <iomanip>

using namespace std;
using namespace mekd;

//////////////////////////////////
/// TEST Block "Models checking"
//////////////////////////////////

int MEKD_Test_ttbb_Check_Models_Test1(input &in)
{
    /// TEST 1
    if (Show_Description)
        cout << "\n -- STARTING TEST 1 -- \n";

    if (Show_Description) {
        cout << "\n -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -- STARTING MODEL TESTs, using 2e2mu (+A) event -- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
    }

    vector<process_description> models =
        MEKD_Test_ttbb_Check_Models_Test1_make_list();
    vector<string> models_v2 =
        MEKD_Test_ttbb_Check_Models_Test1_make_list_str();
    vector<double> MEs;

    if (models.size() != models_v2.size()) {
        cerr << "ERROR: vectors mismatch!\n";
        exit(1);
    }

    input inA;
    inA.id = new vector<int>(*in.id);
    inA.id->push_back(22);

    /// RUNING CALCULATIONS BELOW
    cout << setw(30) << left << "Description " << setw(15) << left
         << "Model name"
         << ": "
         << "ME value" << endl;
    cout << "-------------------------------------------------------------\n";

    MEKD test2(models);
    test2.eval_MEs(in, MEs);
    {
        const unsigned int size = MEs.size();
        for (unsigned int count_model = 0; count_model < size; ++count_model) {
            cout << setw(30) << left << "Result for " << setw(15) << left
                 << models_v2[count_model] << ": " << MEs[count_model] << endl;
        }
    }

    if (Show_Description) {
        cout << "\n ------------------------------------------------ \n";
        cout << " ------------------------------------------------ \n";
        cout << " -- STARTING MODEL TESTs, using 4mu (+A) event -- \n";
        cout << " ------------------------------------------------ \n";
        cout << " ------------------------------------------------ \n";
    }

    (*in.id)[0] = 13;
    (*in.id)[1] = -13;

    /// RUNING CALCULATIONS BELOW
    cout << setw(30) << left << "Description " << setw(15) << left
         << "Model name"
         << ": "
         << "ME value" << endl;
    cout << "-------------------------------------------------------------\n";

    test2.eval_MEs(in, MEs);
    {
        const unsigned int size = MEs.size();
        for (unsigned int count_model = 0; count_model < size; ++count_model) {
            cout << setw(30) << left << "Result for " << setw(15) << left
                 << models_v2[count_model] << ": " << MEs[count_model] << endl;
        }
    }

    // revert input
    (*in.id)[0] = 11;
    (*in.id)[1] = -11;

    return 1;
}

vector<process_description> MEKD_Test_ttbb_Check_Models_Test1_make_list()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(17);

    proc.process = proc_simple;
    proc.resonance = bkg_Z;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc); // [9]

    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc); // [16]

    return models;
}

vector<string> MEKD_Test_ttbb_Check_Models_Test1_make_list_str()
{
    vector<string> models;
    models.reserve(17);
    models.push_back("qqZZ");
    models.push_back("ggSpin0Pm");
    models.push_back("ggSpin0Ph");
    models.push_back("ggSpin0M");
    // 	models.push_back( "ggSpin0Pm_2f" );
    // 	models.push_back( "ggSpin0M_2f" );
    models.push_back("qqSpin1M");
    models.push_back("qqSpin1P");
    models.push_back("ggSpin2Pm");
    models.push_back("qqSpin2Pm");
    models.push_back("ggSpin2Pm_2f");
    models.push_back("qqSpin2Pm_2f"); // [9]

    models.push_back("Spin0Pm");
    models.push_back("Spin0Ph");
    models.push_back("Spin0M");
    // 	models.push_back( "Spin0Pm_2f" );
    // 	models.push_back( "Spin0M_2f" );
    models.push_back("Spin1M");
    models.push_back("Spin1P");
    models.push_back("Spin2Pm");
    models.push_back("Spin2Pm_2f"); // [16]

    return models;
}

#endif
