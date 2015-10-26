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
 * Spin-2 resonances
 */

class ME_runner_gg_Spin2Pm_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Pm_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Pm_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2_ZZ_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph2(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph3,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph3(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph4,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph5,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pb(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph6,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph6(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Ph7,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Ph7(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh8,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh9,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh9(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Mh10,// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Mh10(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2_ZZ_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * Resonance to 2f decay modes.
 * 
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-2 resonances
 */

class ME_runner_gg_Spin2Pm_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Pm_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Pm_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2_2f_4l: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin2Pm_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2Pm_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2Pm_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2Pm,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2Pm(me);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_gg_Spin2_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_qq_Spin2_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
		return in_MEKD.Signal_ME;
	}
};

class ME_runner_no_Spin2_2f_4lA: public ME_runner
{
public:
	const process_description me =
	{
		proc_simple,	// process
		reson_Spin2,	// resonance
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
		in_MEKD.Run_ME_Configurator_Spin2(me, in_MEKD.params_MG);
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