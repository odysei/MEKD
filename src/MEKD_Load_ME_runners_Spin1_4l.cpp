/*
 * 
 * Load_ME_runners_try functions
 * 
 * 
 */
#ifndef MEKD_Load_ME_runners_Spin1_4l_cpp
#define MEKD_Load_ME_runners_Spin1_4l_cpp

#include "../interface/MEKD_MG.h"
#include "../interface/MEKD_Supported_MEs_Spin1_4l.h"

namespace mekd
{

bool MEKD_MG::Load_ME_runners_try_Spin1_4l(const process_description &d,
										   vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1_ZZ_4l(),
							v))
		return true;
	
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1_2f_4l(),
							v))
		return true;
	
	return false;
}

bool MEKD_MG::Load_ME_runners_try_Spin1_4lA(const process_description &d,
											vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1_ZZ_4lA(),
							v))
		return true;
	
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1M_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1M_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1P_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1P_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin1_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin1_2f_4lA(),
							v))
		return true;
	
	return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners_Spin1_4l_cpp
 */