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
 * Spin-1 resonances
 */

class ME_runner_qq_Spin1M_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1M_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin1P_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1P_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin1_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_qq_Spin1M_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1M_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin1P_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1P_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin1_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
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
 * Spin-1 resonances
 */

class ME_runner_qq_Spin1M_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1M_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin1P_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1P_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin1_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin1_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_qq_Spin1M_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1M_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1M("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1M &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin1P_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1P_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1P("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1P &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin1_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin1_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin1("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin1 &&
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