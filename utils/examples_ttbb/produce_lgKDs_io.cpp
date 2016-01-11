#ifndef MEKD_example_produce_lgKDs_io_cpp
#define MEKD_example_produce_lgKDs_io_cpp
#include "produce_lgKDs.h"

using namespace std;

string Find_local_file(const string &input_f)
{
    vector<string> lookup;
    lookup.reserve(5);
    lookup.push_back("./");
    lookup.push_back("Events/");
    lookup.push_back("examples_ttbb/Events/");
    lookup.push_back("data/examples_ttbb/Events/");
    lookup.push_back("../data/examples_ttbb/Events/"); // [4]
    lookup.push_back("../../data/examples_ttbb/Events/");

    for (auto path : lookup) {
        string file_in_path = path + input_f;
        ifstream ifile(file_in_path.c_str());
        if (ifile) {
            ifile.close();
            return file_in_path;
        }
    }

    return "Find_local_file__file_not_found";
}

vector<ifstream *> Load_files(const vector<string> &filenames)
{
    vector<ifstream *> files;
    files.reserve(filenames.size());
    for (auto i : filenames) {
        ifstream *file;
        file = new ifstream;
        file->open(i);
        files.push_back(file);
    }

    return files;
}

void Close_files(vector<ifstream *> &files)
{
    for (auto f : files) {
        f->close();
        delete f;
    }
}

bool Fill_event(ifstream *f, vector<pair<int, double *>> &out)
{
    char out_c[1000];
    f->getline(out_c, 1000);
    if ((*f).eof() || !(*f).good())
        return false;
    stringstream ss(out_c);

    for (auto i = out.begin(); i != out.end(); ++i) {
        ss >> (*i).first;
        ss >> (*i).second[0];
        ss >> (*i).second[1];
        ss >> (*i).second[2];
        ss >> (*i).second[3];
    }

    return true;
}

bool Fill_event(ifstream *f, vector<int> &id, vector<double *> &p)
{
    char out_c[1000];
    f->getline(out_c, 1000);
    if ((*f).eof() || !(*f).good())
        return false;
    stringstream ss(out_c);

    auto i1 = id.begin();
    auto i2 = p.begin();
    while (i1 != id.end() && i2 != p.end()) {
        ss >> (*i1);
        ss >> (*i2)[0];
        ss >> (*i2)[1];
        ss >> (*i2)[2];
        ss >> (*i2)[3];
        ++i1;
        ++i2;
    }

    return true;
}

#endif