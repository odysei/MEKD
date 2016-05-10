#ifndef MEKD_examples_io_h
#define MEKD_examples_io_h
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string Find_local_file(const string &input_f);

vector<ifstream *> Load_files(const vector<string> &filenames);
void Close_files(vector<ifstream *> &files);

bool Fill_event(ifstream *f, vector<pair<int, double *>> &out);
bool Fill_event(ifstream *f, vector<int> &id, vector<double *> &p);

#endif