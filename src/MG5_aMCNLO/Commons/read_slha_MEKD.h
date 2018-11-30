#ifndef READ_SLHA_MEKD_H
#define READ_SLHA_MEKD_H

#include <complex>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class SLHABlock_MEKD
{
  public:
    SLHABlock_MEKD(std::string name = "") { _name = name; }
    ~SLHABlock_MEKD() {}

    void set_entry(std::vector<int> indices, std::complex<double> value);
    std::complex<double> get_entry(std::vector<int> indices,
                                   std::complex<double> def_val = 0);
    void set_name(std::string name) { _name = name; }
    std::string get_name() { return _name; }
    int get_indices() { return _indices; }

  private:
    std::string _name;
    std::map<std::vector<int>, std::complex<double>> _entries;
    unsigned int _indices;
};

class SLHAReader_MEKD
{
  public:
    SLHAReader_MEKD(std::string file_name = "")
    {
        if (file_name != "")
            read_slha_file(file_name);
    }

    void read_slha_file(std::string file_name);
    std::complex<double> get_block_entry(std::string block_name,
                                         std::vector<int> indices,
                                         std::complex<double> def_val = 0);
    std::complex<double> get_block_entry(std::string block_name, int index,
                                         std::complex<double> def_val = 0);
    void set_block_entry(std::string block_name, std::vector<int> indices,
                         std::complex<double> value);
    void set_block_entry(std::string block_name, int index,
                         std::complex<double> value);

  private:
    std::map<std::string, SLHABlock_MEKD> _blocks;
};

#endif
