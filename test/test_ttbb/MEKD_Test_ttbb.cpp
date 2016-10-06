/*
 * MEKD Test Suite 2
 *
 * Test Suite 2 is aimed at MEKD v. 3.
 *
 * It is not the technology show-off and the class is NOT used in the optimal
 *way
 *
 */
#ifndef MEKD_Test_ttbb_cpp
#define MEKD_Test_ttbb_cpp

#include "MEKD_Test_ttbb.h"
#include "MEKD_Test_ttbb_Functionality.cpp"
#include "MEKD_Test_ttbb_Check_Models.cpp"

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
        cout << " -- STARTING TESTs, using ttxbbx event -- \n";
        cout << " ---------------------------------------- \n";
        cout << " ---------------------------------------- \n";
    }

    in.id = new vector<int>;
    in.id->reserve(4);
    //     in.id->push_back(11);
    //     in.id->push_back(-11);
    //     in.id->push_back(13);
    //     in.id->push_back(-13);
    in.id->push_back(6);
    in.id->push_back(-6);
    in.id->push_back(5);
    in.id->push_back(-5);

    in.p = new vector<double *>;
    in.p->reserve(4);
    // 	in.p->push_back(new double[4] {15.256290484000001, 8.6394505145000000,
    // 								   8.4375424780999992, 9.3232060364000002});
    //
    // 	in.p->push_back(new double[4] {24.535694836000001, 10.740685492000001,
    // 								   0.10512935225000000,
    // 22.059622477000001});
    //
    // 	in.p->push_back(new double[4] {96.282168608999996, -40.605831017000000,
    // 								   -34.322569567000002,
    // 80.270620613000006});
    //
    // 	in.p->push_back(new double[4] {144.24476946999999, 21.225695010999999,
    // 								   25.779897736999999, 140.32608132999999});

    in.p->push_back(new double[4]{412.3504456163, 300, 200, 100});

    in.p->push_back(new double[4]{269.3193086283, -200, -40, 30});

    in.p->push_back(new double[4]{111.881510536, 100, 40, -30});

    in.p->push_back(new double[4]{47.3547505537, -10, -45, -10});

    return in;
}

#endif