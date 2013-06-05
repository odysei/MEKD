#ifndef MEKD_MG_2Model_Mixer_h
#define MEKD_MG_2Model_Mixer_h

/////////////////////////////////////////
/// Part responsible for              ///
/// holding mixed couplings           ///
/////////////////////////////////////////

#include <complex>
#include <iostream>
#include <map>
#include <string>

using namespace std;



class MEKD_2Model_Mixer_Block
{
public:
	MEKD_2Model_Mixer_Block(string name = ""){_name = name;}
	~MEKD_2Model_Mixer_Block(){}
	
	void set_entry(string submodel, complex<double>* value);
	void set_name(string name) {_name = name;}
	
	complex<double>* get_entry(string submodel, complex<double>* def_val = NULL);
	
	string get_name(){return _name;}

private:
	string _name;
	map<string,complex<double>*> _entries;
};



class MEKD_2Model_Mixer
{
public:
	complex<double>* get_block_entry(string block_name, string submodel, complex<double>* def_val = NULL);
	
	void set_block_entry(string block_name, string submodel, complex<double>* value);
	
private:
	map<string, MEKD_2Model_Mixer_Block> _blocks;
};


#endif