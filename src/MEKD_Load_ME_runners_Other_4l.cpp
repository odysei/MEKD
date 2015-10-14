/*
 * 
 * Load_ME_runners_try functions
 * 
 * 
 */
#ifndef MEKD_Load_ME_runners_Other_4l_cpp
#define MEKD_Load_ME_runners_Other_4l_cpp

#include "../interface/MEKD.h"
#include "../interface/MEKD_Supported_MEs_Other_4l.h"

namespace mekd
{
	
bool MEKD::Load_ME_runners_try_Misc_4l(const process_description &d,
										  vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_gg_Custom_ZZ_4l(),
							v))
		return true;
// 	if (Load_ME_runners_try(d, new ME_runner_gg_CPPProcess_4l(),
// 							v))
// 		return true;
	
	return false;
}

bool MEKD::Load_ME_runners_try_Misc_4lA(const process_description &d,
										   vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_gg_Custom_ZZ_4lA(),
							v))
		return true;
	
	return false;
}

bool MEKD::Load_ME_runners_try_Z_4l(const process_description &d,
									   vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Z_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Z_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Zs_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Zt_2f_4l(),
							v))
		return true;
	
	return false;
}

bool MEKD::Load_ME_runners_try_Z_4lA(const process_description &d,
									    vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Z_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Z_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Zs_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_bkg_Zt_2f_4lA(),
							v))
		return true;
	
	return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners_Other_4l_cpp
 */