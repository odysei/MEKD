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
#include "../examples_IO/examples_io.h"
#include "MEKD.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <std::string>
#include <vector>

int Choice();
std::vector<std::string> Pick_filenames(int);
std::vector<mekd::process_description> Make_desc();
void My_flags(mekd::flags &);

#endif
