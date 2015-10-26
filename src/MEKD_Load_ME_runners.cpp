/*
 * 
 * Load_ME_runners
 * 
 * 
 */
#ifndef MEKD_Load_ME_runners_cpp
#define MEKD_Load_ME_runners_cpp

#include "../interface/MEKD.h"

namespace mekd
{

void MEKD::Load_ME_runners(vector<process_description> &desc)
{
	ME_runners.reserve(desc.size());	// speed up
	for (auto d: desc) {			// loop not very optimal but transparent
		if (Load_ME_runners_try_Misc_4l(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Misc_4lA(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Z_4l(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Z_4lA(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin0_4l(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin0_4lA(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin1_4l(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin1_4lA(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin2_4l(d, ME_runners))
			continue;
		if (Load_ME_runners_try_Spin2_4lA(d, ME_runners))
			continue;
		
		cerr << "ME runner not found:\n"
			 << "process: " << d.process << endl
			 << "resonance: " << d.resonance << endl
			 << "production: " << d.production << endl
			 << "decay: " << d.decay << endl
			 << "final_state: " << d.final_state << endl;
		ME_runners.push_back(NULL);
	}
}

bool MEKD::Load_ME_runners_try(const process_description &desc,
								  ME_runner *runner,
								  vector<ME_runner *> &v)
{
	if (runner->is_my_type(desc)) {
		v.push_back(runner);	// load if a correct one
		return true;
	}
	
	delete runner;				// dismiss if not the one
	return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners.cpp
 */