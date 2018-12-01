#ifndef MEKD_examples_io_h
#define MEKD_examples_io_h
#include <fstream>
#include <sstream>
#include <std::string>
#include <vector>

std::string Find_local_file(const string &input_f);

std::vector<ifstream *> Load_files(const vector<std::string> &filenames);
void Close_files(std::vector<ifstream *> &files);

bool Fill_event(ifstream *f, std::vector<pair<int, double *>> &out);
bool Fill_event(ifstream *f, std::vector<int> &id, vector<double *> &p);

#endif