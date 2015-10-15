/*
 * 
 * ME_runners. See defined processes below.
 * 
 * Mostly: ZZ, Z backgrounds, Z s/t channels, some custom
 * 
 * 
 */
#include "MEKD.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

class ME_runner_gg_Custom_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Custom,	// resonance
		prod_gg,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Custom();
		return in_MEKD.Signal_ME;
	}
};

// class ME_runner_gg_CPPProcess_4l: public ME_runner
// {
// public:
// 	const process_description me =
// 	{
// 		proc_RAW,	// process
// 		reson_Custom,	// resonance
// 		prod_gg,		// production
// 		decay_ZZ,		// decay
// 		final_4l		// final_state
// 	};
// 	
// 	bool is_my_type(const process_description &in)
// 	{
// 		return compare_types(in, me);
// 	}
// 	
// 	double evaluate(MEKD &in_MEKD, const input &in)
// 	{
// 		in_MEKD.Run_ME_Configurator_CPPProcess(me);
// 		return in_MEKD.Signal_ME;
// 	}
// };

/*
 * with photons
 */

class ME_runner_gg_Custom_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Custom,	// resonance
		prod_gg,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Custom();
		return in_MEKD.Signal_ME;
	}
};

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

class ME_runner_qq_bkg_Z_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Z,			// resonance
		prod_qq,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Z_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Z,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Zs_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Zs,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_SIG(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Zt_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Zt,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_BKG(me);
		return in_MEKD.Signal_ME;
	}
};

/*
 * with photons
 */

class ME_runner_qq_bkg_Z_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Z,			// resonance
		prod_qq,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Z_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Z,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Zs_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Zs,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_SIG(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_bkg_Zt_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		bkg_Zt,			// resonance
		prod_qq,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_BKG(me);
		return in_MEKD.Signal_ME;
	}
};

/*
 * End of ME_runner classes
 */

/// end of namespace
}

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////