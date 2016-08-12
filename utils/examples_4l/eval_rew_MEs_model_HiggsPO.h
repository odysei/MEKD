/*
 * MEKD example: eval_rew_MEs_model_HiggsPO
 *
 * Details: produces lg-ratio discriminants for the input events. Input files
 * are simple text files with (4 x 5 =) 20 number columns of a structure 4x
 * (PDG_ID E px py pz).
 *
 * Output: SM_Higgs(ZZ only) SM_Higgs(ZZ only, 1->4) eZf_L(e, mu)
 * eZf_L(e, mu, 1->4) eZf_L/SM_Higgs eZf_L/SM_Higgs(1->4)
 *
 */
#ifndef MEKD_example_eval_rew_MEs_model_HiggsPO_h
#define MEKD_example_eval_rew_MEs_model_HiggsPO_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "MEKD.h"
#include "../examples_IO/examples_io.h"

using namespace std;

int Choice();
vector<string> Pick_filenames(int);
vector<mekd::process_description> Make_desc_CC(); // custom couplings
MG5_HiggsPO_UFO::input_c CC1(const mekd::input &);
MG5_HiggsPO_UFO::input_c CC2(const mekd::input &);
void My_flags(mekd::flags &);
void Main_loop(vector<ifstream *> &files, mekd::MEKD &calc_MEs_CC);

#endif
