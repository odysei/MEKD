#ifndef MEKD_MG_2Model_Mixer_cpp
#define MEKD_MG_2Model_Mixer_cpp

/////////////////////////////////////////
/// Part responsible for              ///
/// holding mixed couplings           ///
/////////////////////////////////////////

#include "../interface/MEKD_MG_2Model_Mixer.h"




complex<double>* MEKD_2Model_Mixer_Block::get_entry(string submodel, complex<double>* def_val)
{
	if( _entries.find(submodel) == _entries.end() )
	{
		cout << "Warning: No such entry in " << _name << ", using default value " << def_val << endl;
		return def_val;
	}
	
	return _entries[submodel];
}


void MEKD_2Model_Mixer_Block::set_entry(string submodel, complex<double>* value)
{
	_entries[submodel] = value;
}


complex<double>* MEKD_2Model_Mixer::get_block_entry(string block_name, string submodel, complex<double>* def_val)
{
	if( _blocks.find(block_name) == _blocks.end() )
	{
		cout << "No such block " << block_name << ", using default value " << def_val << endl;
		return def_val;
	}
	
	return _blocks[block_name].get_entry(submodel);
}


void MEKD_2Model_Mixer::set_block_entry(string block_name, string submodel, complex<double>* value)
{
	if( _blocks.find(block_name) == _blocks.end() )
	{
		MEKD_2Model_Mixer_Block block(block_name);
		_blocks[block_name] = block;
	}
	
	_blocks[block_name].set_entry(submodel, value);
}


#endif