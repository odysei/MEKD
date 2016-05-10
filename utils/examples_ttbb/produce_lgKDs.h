/*
 * MEKD example: produce_lgKDs
 *
 * Details: produces lg-ratio discriminants for the input events. Input files
 * are simple text files with (4 x 5 =) 20 number columns of a structure 4x
 * (PDG_ID E px py pz).
 *
 * Output: KD(sig + bkg; bkg) KD(sig; bkg)
 *
 */
#ifndef MEKD_example_produce_lgKDs_h
#define MEKD_example_produce_lgKDs_h
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
vector<mekd::process_description> Make_desc();
void My_flags(mekd::flags &);

#endif