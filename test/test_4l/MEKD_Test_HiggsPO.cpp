/*
 * MEKD Test Suite 2
 *
 * Test Suite 2 is aimed at MEKD v. 3.
 *
 * It is not the technology show-off and the class is NOT used in the optimal
 *way
 *
 */
#ifndef MEKD_TEST_HiggsPO_CPP
#define MEKD_TEST_HiggsPO_CPP

#include "MEKD_Test_HiggsPO.h"
#include "MEKD_Test_Functionality_HiggsPO.cpp"
#include "MEKD_Test_Compatibility.cpp"
// #include "MEKD_Test_Check_Models_HiggsPO.cpp"

input Initialize_tester(input &);
void test_block1(input &);
// void test_block6(input &);
void test_block7(input &);

int main()
{
    cout.setf(ios_base::scientific);
    cout.precision(8);
    input test;

    Initialize_tester(test);

    test_block1(test);
    //     test_block6(test);
    test_block7(test);

    return 0;
}

void test_block1(input &in)
{

    if (Show_Description) {
        cout << "\n ---------------------------------------- \n";
        cout << " -- Testing KD calculations on the fly -- \n";
        cout << " ---------------------------------------- \n";
    }

    int error_value = MEKD_Test_Functionality_Test1(in);
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";
}

// void test_block6(input &in)
// {
//     if (Show_Description) {
//         cout << "\n --------------------------------------------------- \n";
//         cout << " -- Testing model integration for ME calculations -- \n";
//         cout << " --------------------------------------------------- \n";
//     }
//
//     // 	error_value = MEKD_Test_Check_Models_Test1();
//     // 	if (error_value == 0)
//     // 		cout << "TEST 1: PASSED\n";
//     // 	else
//     // 		cout << "TEST 1: \"FAILED\"\n";
//     //
//     // 	int error_value = MEKD_Test_Check_Models_Test2(in);
//     // 	if (error_value == 0)
//     // 		cout << "TEST 2: PASSED\n";
//     // 	else
//     // 		cout << "TEST 2: \"FAILED\"\n";
//
//     int error_value = MEKD_Test_Check_Models_Test3(in);
//     if (error_value == 0)
//         cout << "TEST 3: PASSED\n";
//     else
//         cout << "TEST 3: \"FAILED\"\n";
// }

void test_block7(input &in)
{

    if (Show_Description) {
        cout << "\n --------------------------------------------------- \n";
        cout << " -- Testing HEF_MEKD and HiggPO_UFO compatibility -- \n";
        cout << " --------------------------------------------------- \n";
    }

    int error_value = MEKD_Test_Compatibility_Test1(in);
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";

    error_value = MEKD_Test_Compatibility_Test2(in);
    if (error_value == 0)
        cout << "TEST 2: PASSED\n";
    else
        cout << "TEST 2: FAILED\n";
}

input Initialize_tester(input &in)
{
    if (Show_Description) {
        cout << "\n --------------------------------------- \n";
        cout << " --------------------------------------- \n";
        cout << " -- STARTING TESTs, using 2e2mu event -- \n";
        cout << " --------------------------------------- \n";
        cout << " --------------------------------------- \n";
    }

    in.id = new vector<int>;
    in.id->reserve(4);
    in.id->push_back(11);
    in.id->push_back(-11);
    in.id->push_back(13);
    in.id->push_back(-13);

    in.p = new vector<double *>;
    in.p->reserve(4);
    in.p->push_back(new double[4]{15.256290484000001, 8.6394505145000000,
                                  8.4375424780999992, 9.3232060364000002});

    in.p->push_back(new double[4]{24.535694836000001, 10.740685492000001,
                                  0.10512935225000000, 22.059622477000001});

    in.p->push_back(new double[4]{96.282168608999996, -40.605831017000000,
                                  -34.322569567000002, 80.270620613000006});

    in.p->push_back(new double[4]{144.24476946999999, 21.225695010999999,
                                  25.779897736999999, 140.32608132999999});

    return in;
}

#endif