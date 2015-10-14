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
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0Pm_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0Ph_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Ph("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Ph &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0Ph_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Ph("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Ph &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0M_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0M("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0M_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0Pm_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin0Ph_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Ph("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Ph &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0Ph_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0Ph("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Ph &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin0M_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0M("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0M_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin0_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_ME_Configurator_Spin0("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
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
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0Pm_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0M_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0M("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0M_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin0_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin0_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin0Pm_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0Pm_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0Pm &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin0M_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0M("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0M_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0M &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin0_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin0_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_ME_Configurator_Spin0("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin0 &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
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