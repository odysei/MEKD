#ifndef MEKD__test_4l__check_models_HiggsPO_cpp
#define MEKD__test_4l__check_models_HiggsPO_cpp

#include "test_HiggsPO.h"
#include <iomanip>

using namespace std;
using namespace mekd;

vector<process_description> MEKD_Test_Check_Models_Test1_make_list();
// vector<process_description> MEKD_Test_Check_Models_Test1_make_listA();
vector<string> MEKD_Test_Check_Models_Test1_make_list_str(); // v2 legacy

//////////////////////////////////
/// TEST Block "Models checking"
//////////////////////////////////

/// Check 2l (plus photon) final-state models.
int MEKD_Test_Check_Models_Test1(input &in)
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
        MEKD_Test_Check_Models_Test1_make_list();
    vector<process_description> modelsA =
        MEKD_Test_Check_Models_Test1_make_listA();
    vector<string> models_v2 = MEKD_Test_Check_Models_Test1_make_list_str();
    vector<double> MEs; //, MEsA;

    if (models.size() != modelsA.size() || models.size() != models_v2.size()) {
        cerr << "ERROR: vectors mismatch!\n";
        exit(1);
    }

    input inA;
    inA.id = new vector<int>(*in.id);
    inA.id->push_back(22);

    inA.p = new vector<double *>(*in.p);
    // setting collinear to the first lepton
    inA.p->push_back(new double[4]{0.4, 0.23, 0.221, -0.24136902});

    /// RUNING CALCULATIONS BELOW
    cout << setw(30) << left << "Description " << setw(15) << left
         << "Model name"
         << ": "
         << "ME value" << endl;
    cout << "-------------------------------------------------------------\n";

    MEKD test2(models);
    MEKD test2A(modelsA);
    test2.eval_MEs(in, MEs);
    test2A.eval_MEs(inA, MEsA);
    {
        const unsigned int size = MEs.size();
        for (unsigned int count_model = 0; count_model < size; ++count_model) {
            cout << setw(30) << left << "Result for " << setw(15) << left
                 << models_v2[count_model] << ": " << MEs[count_model] << endl;

            cout << setw(30) << left << "Result for (with a photon)" << setw(15)
                 << left << models_v2[count_model] << ": " << MEsA[count_model]
                 << endl;
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

    (*inA.id)[0] = 13;
    (*inA.id)[1] = -13;

    /// RUNING CALCULATIONS BELOW
    cout << setw(30) << left << "Description " << setw(15) << left
         << "Model name"
         << ": "
         << "ME value" << endl;
    cout << "-------------------------------------------------------------\n";

    test2.eval_MEs(in, MEs);
    test2A.eval_MEs(inA, MEsA);
    {
        const unsigned int size = MEs.size();
        for (unsigned int count_model = 0; count_model < size; ++count_model) {
            cout << setw(30) << left << "Result for " << setw(15) << left
                 << models_v2[count_model] << ": " << MEs[count_model] << endl;

            cout << setw(30) << left << "Result for (with a photon)" << setw(15)
                 << left << models_v2[count_model] << ": " << MEsA[count_model]
                 << endl;
        }
    }

    // revert input
    (*in.id)[0] = 11;
    (*in.id)[1] = -11;

    delete inA.id;
    delete inA.p;

    return 1;
}

vector<process_description> MEKD_Test_Check_Models_Test1_make_list()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(1);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_VV;
    proc.final_state = final_4l;
    models.push_back(proc);

    return models;
}

// vector<process_description> MEKD_Test_Check_Models_Test1_make_listA()
// {
//     vector<process_description> models;
//     process_description proc;
//     models.reserve(1);
//
//     proc.model = model_MEKD;
//     proc.process = proc_simple;
//     proc.resonance = reson_Spin0Pm;
//     proc.production = prod_gg;
//     proc.decay = decay_ZZ;
//     proc.final_state = final_4lA;
//     models.push_back(proc);
//
//     return models;
// }

vector<string> MEKD_Test_Check_Models_Test1_make_list_str()
{
    vector<string> models;
    models.reserve(1);

    models.push_back("ggSpin0Pm");

    return models;
}

#endif
