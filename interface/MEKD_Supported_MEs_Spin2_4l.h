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
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Pm_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Pm_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph3_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph4_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph5_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph6_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Ph7_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Mh8_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Mh9_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Mh10_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Pm_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph2 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph3_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph3("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph3 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph4_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph4 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph5_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pb("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph5 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph6_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph6("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph6 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Ph7_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Ph7("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Ph7 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Mh8_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh8 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Mh9_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh9("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh9 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Mh10_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Mh10("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Mh10 &&
				in.production == prod_no &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "ZZ";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
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
 * Spin-2 resonances
 */

class ME_runner_gg_Spin2Pm_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2Pm_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2Pm_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_gg_Spin2_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_Spin2_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_no_Spin2_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_gg_Spin2Pm_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2Pm_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2Pm_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2Pm("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2Pm &&
				in.production == prod_no &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_gg_Spin2_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("gg");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_gg &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_Spin2_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_no_Spin2_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD_MG &in_MEKD, const input &in)
	{
		in_MEKD.Resonance_decay_mode = "2l";
		in_MEKD.Run_MEKD_MG_ME_Configurator_Spin2("NO");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Spin2 &&
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