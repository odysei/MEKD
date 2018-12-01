#ifndef MEKD__test_4l__functionality_cpp
#define MEKD__test_4l__functionality_cpp

#include "test_v3.h"
#include "check_models_v3.h"
#include <iomanip>

using namespace std;
using namespace mekd;

//////////////////////////////////
/// TEST Block "Models checking"
//////////////////////////////////

// /// Check 2l (plus photon) final-state models.
// int MEKD_Test_Check_Models_Test1(input &in)
// {
// 	/// TEST 1
// 	if (Show_Description)
// 		cout << "\n -- STARTING TEST 1 -- \n";
// 	MEKD test1(8.0, "");
//
// 	int id2l1, id2l2, id2l3;
//
// 	double p2l1[4] = {0}, p2l2[4] = {0}, p2lA1[4] = {0}, ME_value;
//
// 	vector<string> models_to_test;
// 	vector<double *> Set_Of_Arrays_2l, Set_Of_Arrays_2lpA;
// 	vector<int> Set_Of_IDs_2l, Set_Of_IDs_2lpA;
//
// 	if (Show_Description) {
// 		cout << "\n ------------------------------------------------ \n";
// 		cout << " ------------------------------------------------ \n";
// 		cout << " -- STARTING MODEL TESTs, using 2mu (+A) event -- \n";
// 		cout << " ------------------------------------------------ \n";
// 		cout << " ------------------------------------------------ \n";
// 	}
//
// 	id2l1 = 13;
// 	id2l2 = -13;
// 	id2l3 = 22;
//
// 	p2l1[0] = 62;
// 	p2l1[1] = 50;
// 	p2l1[2] = -17;
// 	p2l1[3] = -32.4805915;
//
// 	p2l2[0] = 62;
// 	p2l2[1] = -50;
// 	p2l2[2] = 17;
// 	p2l2[3] = 32.4805915;
//
// 	// setting collinear to the first lepton
// 	p2lA1[0] = 4;
// 	p2lA1[1] = 3.23;
// 	p2lA1[2] = -1.1;
// 	p2lA1[3] = -2.087367;
//
// 	Set_Of_Arrays_2l.push_back(p2l1);
// 	Set_Of_Arrays_2l.push_back(p2l2);
//
// 	Set_Of_IDs_2l.push_back(id2l1);
// 	Set_Of_IDs_2l.push_back(id2l2);
//
// 	Set_Of_Arrays_2lpA.push_back(p2l1);
// 	Set_Of_Arrays_2lpA.push_back(p2l2);
// 	Set_Of_Arrays_2lpA.push_back(p2lA1);
//
// 	Set_Of_IDs_2lpA.push_back(id2l1);
// 	Set_Of_IDs_2lpA.push_back(id2l2);
// 	Set_Of_IDs_2lpA.push_back(id2l3);
//
// 	models_to_test.push_back("qqDY");
// 	models_to_test.push_back("ggSpin0Pm");
// 	models_to_test.push_back("ggSpin0M");
// 	models_to_test.push_back("qqSpin1M");
// 	models_to_test.push_back("qqSpin1P");
// 	models_to_test.push_back("ggSpin2Pm");
// 	models_to_test.push_back("qqSpin2Pm");
//
// 	models_to_test.push_back("DY");
// 	models_to_test.push_back("Spin0Pm");
// 	models_to_test.push_back("Spin0M");
// 	models_to_test.push_back("Spin1M");
// 	models_to_test.push_back("Spin1P");
// 	models_to_test.push_back("Spin2Pm");
//
// 	/// RUNING CALCULATIONS BELOW
// 	cout << setw(30) << left << "Description " << setw(15) << left
// 		 << "Model name"
// 		 << ": "
// 		 << "ME value" << endl;
// 	cout << "-------------------------------------------------------------\n";
// 	for (unsigned int count_model = 0; count_model < models_to_test.size();
// 		 count_model++) {
// 		if ((error_value =
// 				 test1.computeME(models_to_test[count_model], Set_Of_Arrays_2l,
// 								 Set_Of_IDs_2l, ME_value)) != 0)
// 			cout << "ERROR CODE in ME for " << models_to_test[count_model]
// 				 << ": " << error_value << endl;
// 		else
// 			cout << setw(30) << left << "Result for " << setw(15) << left
// 				 << models_to_test[count_model] << ": " << ME_value << endl;
//
// 		if ((error_value = test1.computeME(models_to_test[count_model],
// 										   Set_Of_Arrays_2lpA, Set_Of_IDs_2lpA,
// 										   ME_value)) != 0)
// 			cout << "ERROR CODE in ME for " << models_to_test[count_model]
// 				 << ": " << error_value << endl;
// 		else
// 			cout << setw(30) << left << "Result for (with a photon)" << setw(15)
// 				 << left << models_to_test[count_model] << ": " << ME_value
// 				 << endl;
// 	}
//
// 	return 1;
// }

/// Check 2l (plus photon) final-state models.
int MEKD_Test_Check_Models_Test2(input &in)
{
    /// TEST 2
    if (Show_Description)
        cout << "\n -- STARTING TEST 2 -- \n";

    if (Show_Description) {
        cout << "\n -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -- STARTING MODEL TESTs, using 2e2mu (+A) event -- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
    }

    vector<process_description> models =
        MEKD_Test_Check_Models_Test2_make_list();
    vector<process_description> modelsA =
        MEKD_Test_Check_Models_Test2_make_listA();
    vector<string> models_v2 = MEKD_Test_Check_Models_Test2_make_list_str();
    vector<double> MEs, MEsA;

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

vector<process_description> MEKD_Test_Check_Models_Test2_make_list()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(17);

    proc.model = model_HEF_UFO;
    proc.process = proc_simple;
    proc.resonance = bkg_Z;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc); // [9]

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc); // [16]

    return models;
}

vector<process_description> MEKD_Test_Check_Models_Test2_make_listA()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(17);

    proc.model = model_HEF_UFO;
    proc.process = proc_simple;
    proc.resonance = bkg_Z;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc); // [9]

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc); // [16]

    return models;
}

vector<string> MEKD_Test_Check_Models_Test2_make_list_str()
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

/// Check 2l (plus photon) final-state models.
int MEKD_Test_Check_Models_Test3(input &in)
{
    /// TEST 2
    if (Show_Description)
        cout << "\n -- STARTING TEST 3 -- \n";

    if (Show_Description) {
        cout << "\n -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -- STARTING MODEL TESTs, using 2e2mu (+A) event -- \n";
        cout << " -------------------------------------------------- \n";
        cout << " -------------------------------------------------- \n";
    }

    vector<process_description> models =
        MEKD_Test_Check_Models_Test3_make_list();
    vector<process_description> modelsA =
        MEKD_Test_Check_Models_Test3_make_listA();
    vector<string> models_v2 = MEKD_Test_Check_Models_Test3_make_list_str();
    vector<double> MEs, MEsA;

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

vector<process_description> MEKD_Test_Check_Models_Test3_make_list()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(17);

    proc.model = model_HEF_UFO;
    proc.process = proc_simple;
    proc.resonance = bkg_Z;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4l;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_2f;
    proc.final_state = final_4l;
    models.push_back(proc);

    return models;
}

vector<process_description> MEKD_Test_Check_Models_Test3_make_listA()
{
    vector<process_description> models;
    process_description proc;
    models.reserve(17);

    proc.model = model_HEF_UFO;
    proc.process = proc_simple;
    proc.resonance = bkg_Z;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_gg;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_qq;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_gg;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_qq;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0Ph;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin0M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1M;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin1P;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph2;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph3;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph4;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph5;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph6;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Ph7;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh8;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh9;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Mh10;
    proc.production = prod_no;
    proc.decay = decay_ZZ;
    proc.final_state = final_4lA;
    models.push_back(proc);

    proc.model = model_MEKD;
    proc.process = proc_simple;
    proc.resonance = reson_Spin2Pm;
    proc.production = prod_no;
    proc.decay = decay_2f;
    proc.final_state = final_4lA;
    models.push_back(proc);

    return models;
}

vector<string> MEKD_Test_Check_Models_Test3_make_list_str()
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

    models.push_back("ggSpin2Ph2");
    models.push_back("qqSpin2Ph2");
    models.push_back("ggSpin2Ph3");
    models.push_back("qqSpin2Ph3");
    models.push_back("ggSpin2Ph4");
    models.push_back("qqSpin2Ph4");
    models.push_back("ggSpin2Ph5");
    models.push_back("qqSpin2Ph5");
    models.push_back("ggSpin2Ph6");
    models.push_back("qqSpin2Ph6");
    models.push_back("ggSpin2Ph7");
    models.push_back("qqSpin2Ph7");
    models.push_back("ggSpin2Mh8");
    models.push_back("qqSpin2Mh8");
    models.push_back("ggSpin2Mh9");
    models.push_back("qqSpin2Mh9");
    models.push_back("ggSpin2Mh10");
    models.push_back("qqSpin2Mh10");

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

    models.push_back("Spin2Ph2");
    models.push_back("Spin2Ph3");
    models.push_back("Spin2Ph4");
    models.push_back("Spin2Ph5");
    models.push_back("Spin2Ph6");
    models.push_back("Spin2Ph7");
    models.push_back("Spin2Mh8");
    models.push_back("Spin2Mh9");
    models.push_back("Spin2Mh10");

    models.push_back("Spin2Pm_2f"); // [16]

    return models;
}

#endif
