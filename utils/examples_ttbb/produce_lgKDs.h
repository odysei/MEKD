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

using namespace std;

string Find_local_file(const string &input_f);

vector<ifstream *> Load_files(const vector<string> &filenames);
void Close_files(vector<ifstream *> &files);

bool Fill_event(ifstream *f, vector<pair<int, double *>> &out);
bool Fill_event(ifstream *f, vector<int> &id, vector<double *> &p);

#endif