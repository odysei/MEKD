/*
 * MEKD Test Suite 2
 *
 * Test Suite 2 is aimed at MEKD v. 3.
 *
 * It is not the technology show-off and the class is NOT used in the optimal
 *way
 *
 */
#ifndef MEKD__test__zp_4l__main_cpp
#define MEKD__test__zp_4l__main_cpp

#include "MEKD.h"
#include "check_models.h"
#include "functionality.h"
#include "test.h"

using namespace mekd;

input Initialize_tester(input &);
void test_block1(input &);
void test_block6(input &);

int main()
{
    cout.setf(ios_base::scientific);
    cout.precision(8);
    input test;

    Initialize_tester(test);

    test_block1(test);
    // 	test_block6(test);

    return 0;
}

void test_block1(input &in)
{

    if (Show_Description) {
        cout << "\n ---------------------------------------- \n";
        cout << " -- Testing KD calculations on the fly -- \n";
        cout << " ---------------------------------------- \n";
    }

    int error_value = MEKD_Test_ttbb_Functionality_Test1(in);
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";
}

void test_block6(input &in)
{
    if (Show_Description) {
        cout << "\n --------------------------------------------------- \n";
        cout << " -- Testing model integration for ME calculations -- \n";
        cout << " --------------------------------------------------- \n";
    }

    int error_value = MEKD_Test_ttbb_Check_Models_Test1(in);
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: \"FAILED\"\n";
}

input Initialize_tester(input &in)
{
    if (Show_Description) {
        cout << "\n ---------------------------------------- \n";
        cout << " ---------------------------------------- \n";
        cout << " -- STARTING TESTs, using XYZ event -- \n";
        cout << " ---------------------------------------- \n";
        cout << " ---------------------------------------- \n";
    }

    in.id = new vector<int>;
    in.id->reserve(4);
    in.id->push_back(11);
    in.id->push_back(-11);
    in.id->push_back(13);
    in.id->push_back(-13);

    in.p = new vector<double *>;
    in.p->reserve(4);
    in.p->push_back(new double[4]{4.2621653039e+01, 2.9619065864e+01,
                                  2.9236670684e+01, -9.1942010082});

    in.p->push_back(new double[4]{5.0850757806e+01, -2.3851305751e+01,
                                  -3.6426902287e+01, 2.6267766806e+01});

    in.p->push_back(
        new double[4]{5.5643996058, 4.1393213289, -3.2198530106, 1.8574026123});

    in.p->push_back(new double[4]{1.4650444330e+01, -9.9070814421,
                                  1.0410084614e+01, 2.8467930522});

    return in;
}

#endif
