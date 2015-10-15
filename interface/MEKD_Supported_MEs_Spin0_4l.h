/*
 * 
 * ME_runners. See defined processes below.
 * 
 * 
 */
#include "MEKD.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/*
 * Resonance to ZZ decay modes (with exceptions for 2l, 2l+A states).
 * 
 * Final states: 4 leptons (+photon) also 2 muons (+photon)
 */

/*
 * Spin-0 resonances
 */

class ME_runner_gg_Spin0Pm_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Pm_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0Ph_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Ph,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Ph_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Ph,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0M_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0M_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Pm_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0Ph_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Ph,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Ph_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Ph,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0M_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0M_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_no,		// production
		decay_ZZ,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * Resonance to 2f decay modes.
 * 
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-0 resonances
 */

class ME_runner_gg_Spin0Pm_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Pm_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0M_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0M_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4l		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0Pm_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0Pm,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0M_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0M_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0M,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0M(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin0_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_gg,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin0_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin0,	// resonance
		prod_no,		// production
		decay_2f,		// decay
		final_4lA		// final_state
	};
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Spin0(me, in_MEKD.params_MG);
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