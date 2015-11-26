/*
 * MEKD Test Suite 1
 *
 * It is not the technology show-off and the class is NOT used in the optimal
 *way
 *
 */

#ifndef MEKD_TEST_CPP
#define MEKD_TEST_CPP

#include "MEKD_Test.h"
#include "MEKD_Test_Check_Models.cpp"
#include "MEKD_Test_Consistency.cpp"
#include "MEKD_Test_Debug_Ghosts.cpp"

/// ROOT-include dependent
#if (defined MEKD_STANDALONE && defined MEKD_with_ROOT) ||                     \
    !defined MEKD_STANDALONE
#include "MEKD_Test_Functionality.cpp"
#include "MEKD_Test_Gen.cpp"
#include "MEKD_Test_Gen_Interference.cpp"
#endif

void Initialize_tester();
void test_block1();
void test_block2();
void test_block3();
void test_block4();
void test_block5();
void test_block6();

int main()
{
    Initialize_tester();

    test_block1();
    // 	test_block2();
    // 	test_block3();
    // 	test_block4();
    // 	test_block5();
    test_block6();

    return 0;
}

void test_block1()
{

    if (Show_Description) {
        cout << "\n ---------------------------------------- \n";
        cout << " -- Testing KD calculations on the fly -- \n";
        cout << " ---------------------------------------- \n";
    }

    error_value = MEKD_Test_Functionality_Test1();
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";

    error_value = MEKD_Test_Functionality_Test2();
    if (error_value == 0)
        cout << "TEST 2: PASSED\n";
    else
        cout << "TEST 2: FAILED\n";

    error_value = MEKD_Test_Functionality_Test3();
    if (error_value == 0)
        cout << "TEST 3: PASSED\n";
    else
        cout << "TEST 3: FAILED\n";

    error_value = MEKD_Test_Functionality_Test4();
    if (error_value == 0)
        cout << "TEST 4: PASSED\n";
    else
        cout << "TEST 4: FAILED\n";
}

void test_block2()
{
    if (Show_Description) {
        cout << "\n ----------------------------------------------------\n";
        cout << " -- Testing KD calculations from \"precalculated\" MEs --\n";
        cout << " ---------------------------------------------------- \n";
    }

    error_value = MEKD_Test_Functionality_Test5();
    if (error_value == 0)
        cout << "TEST 5: PASSED\n";
    else
        cout << "TEST 5: FAILED\n";

    error_value = MEKD_Test_Functionality_Test6();
    if (error_value == 0)
        cout << "TEST 6: PASSED\n";
    else
        cout << "TEST 6: FAILED\n";

    error_value = MEKD_Test_Functionality_Test7();
    if (error_value == 0)
        cout << "TEST 7: PASSED\n";
    else
        cout << "TEST 7: FAILED\n";

    error_value = MEKD_Test_Functionality_Test8();
    if (error_value == 0)
        cout << "TEST 8: PASSED\n";
    else
        cout << "TEST 8: FAILED\n";
}

void test_block3()
{
    if (Show_Description) {
        cout << "\n --------------------------------------------- \n";
        cout << " -- Testing ME calculations for consistency -- \n";
        cout << " --------------------------------------------- \n";
    }

    error_value = MEKD_Test_Consistency_Test1();
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";

    MEKD_Test_Gen_Test1(); // many tests at the moment
}

void test_block4()
{
    if (Show_Description) {
        cout << "\n -------------------------------------------------- \n";
        cout << " -- Testing ME calculations for the interference -- \n";
        cout << " --------------------------------------------- \n";
    }

    error_value = MEKD_Test_Gen_Interference_Test1();
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";

    error_value = MEKD_Test_Gen_Interference_Test2();
    if (error_value == 0)
        cout << "TEST 2: PASSED\n";
    else
        cout << "TEST 2: FAILED\n";
}

void test_block5()
{
    if (Show_Description) {
        cout << "\n -----------------------------------------------------\n";
        cout << " -- Testing ME calculations for the order dependece -- \n";
        cout << " ----------------------------------------------------- \n";
    }

    error_value = MEKD_Test_Debug_Ghosts_Test0();
    if (error_value == 0)
        cout << "TEST 0: PASSED\n";
    else
        cout << "TEST 0: FAILED\n";

    error_value = MEKD_Test_Debug_Ghosts_Test1();
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: FAILED\n";

    error_value = MEKD_Test_Debug_Ghosts_Test2();
    if (error_value == 0)
        cout << "TEST 2: PASSED\n";
    else
        cout << "TEST 2: FAILED\n";
}

void test_block6()
{
    if (Show_Description) {
        cout << "\n --------------------------------------------------- \n";
        cout << " -- Testing model integration for ME calculations -- \n";
        cout << " --------------------------------------------------- \n";
    }

    error_value = MEKD_Test_Check_Models_Test1();
    if (error_value == 0)
        cout << "TEST 1: PASSED\n";
    else
        cout << "TEST 1: \"FAILED\"\n";

    error_value = MEKD_Test_Check_Models_Test2();
    if (error_value == 0)
        cout << "TEST 2: PASSED\n";
    else
        cout << "TEST 2: \"FAILED\"\n";
}

void Initialize_tester()
{

    cout.setf(ios_base::scientific);
    cout.precision(8);

    if (Show_Description) {
        cout << "\n --------------------------------------- \n";
        cout << " --------------------------------------- \n";
        cout << " -- STARTING TESTs, using 2e2mu event -- \n";
        cout << " --------------------------------------- \n";
        cout << " --------------------------------------- \n";
    }

    id1 = 11;
    id2 = -11;
    id3 = 13;
    id4 = -13;

    p1[0] = 15.256290484000001;
    p1[1] = 8.6394505145000000;
    p1[2] = 8.4375424780999992;
    p1[3] = 9.3232060364000002;

    p2[0] = 24.535694836000001;
    p2[1] = 10.740685492000001;
    p2[2] = 0.10512935225000000;
    p2[3] = 22.059622477000001;

    p3[0] = 96.282168608999996;
    p3[1] = -40.605831017000000;
    p3[2] = -34.322569567000002;
    p3[3] = 80.270620613000006;

    p4[0] = 144.24476946999999;
    p4[1] = 21.225695010999999;
    p4[2] = 25.779897736999999;
    p4[3] = 140.32608132999999;

    Set_Of_Arrays.push_back(p1);
    Set_Of_Arrays.push_back(p2);
    Set_Of_Arrays.push_back(p3);
    Set_Of_Arrays.push_back(p4);

    Set_Of_IDs.push_back(id1);
    Set_Of_IDs.push_back(id2);
    Set_Of_IDs.push_back(id3);
    Set_Of_IDs.push_back(id4);

#if (defined MEKD_STANDALONE && defined MEKD_with_ROOT) ||                     \
    !defined MEKD_STANDALONE
    gSystem->Load("libTree"); // A workaround for >> "Warning in
                              // <TClass::TClass>: no dictionary for class ...

    Lp1.SetPxPyPzE(p1[1], p1[2], p1[3], p1[0]);
    Lp2.SetPxPyPzE(p2[1], p2[2], p2[3], p2[0]);
    Lp3.SetPxPyPzE(p3[1], p3[2], p3[3], p3[0]);
    Lp4.SetPxPyPzE(p4[1], p4[2], p4[3], p4[0]);
#endif
}

#endif