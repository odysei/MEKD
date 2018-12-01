#ifndef MEKD__test_4l_check_models_v3_h
#define MEKD__test_4l_check_models_v3_h

#include "MEKD.h"

int MEKD_Test_Check_Models_Test3(mekd::input &in);

std::vector<mekd::process_description> MEKD_Test_Check_Models_Test2_make_list();
std::vector<mekd::process_description> MEKD_Test_Check_Models_Test2_make_listA();
std::vector<std::string> MEKD_Test_Check_Models_Test2_make_list_str(); // v2 legacy

std::vector<mekd::process_description> MEKD_Test_Check_Models_Test3_make_list();
std::vector<mekd::process_description> MEKD_Test_Check_Models_Test3_make_listA();
std::vector<std::string> MEKD_Test_Check_Models_Test3_make_list_str(); // v2 legacy

#endif
