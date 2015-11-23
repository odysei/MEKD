/*
 * 
 * Load_ME_runners_try functions
 * 
 * 
 */
#ifndef MEKD_Load_ME_runners_Spin2_4l_cpp
#define MEKD_Load_ME_runners_Spin2_4l_cpp

#include "MEKD.h"
#include "MEKD_Supported_MEs_Spin2_4l.h"

namespace mekd
{

bool MEKD::Load_ME_runners_try_Spin2_4l(const process_description &d,
										   vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Pm_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Pm_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Pm_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph2_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph2_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph2_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph3_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph3_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph3_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph4_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph4_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph4_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph5_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph5_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph5_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph6_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph6_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph6_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph7_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph7_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph7_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh8_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh8_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh8_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh9_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh9_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh9_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh10_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh10_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh10_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2_ZZ_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2_ZZ_4l(),
							v))
		return true;
	
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Pm_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Pm_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Pm_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2_2f_4l(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2_2f_4l(),
							v))
		return true;
	
	return false;
}

bool MEKD::Load_ME_runners_try_Spin2_4lA(const process_description &d,
											vector<ME_runner *> &v)
{
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Pm_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Pm_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Pm_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph2_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph2_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph2_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph3_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph3_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph3_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph4_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph4_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph4_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph5_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph5_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph5_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph6_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph6_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph6_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Ph7_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Ph7_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Ph7_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh8_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh8_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh8_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh9_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh9_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh9_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Mh10_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Mh10_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Mh10_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2_ZZ_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2_ZZ_4lA(),
							v))
		return true;
	
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2Pm_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2Pm_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2Pm_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_gg_Spin2_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_qq_Spin2_2f_4lA(),
							v))
		return true;
	if (Load_ME_runners_try(d, new ME_runner_no_Spin2_2f_4lA(),
							v))
		return true;
	
	return false;
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners_Spin2_4l_cpp
 */