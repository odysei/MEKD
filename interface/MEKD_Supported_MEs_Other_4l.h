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
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Custom();
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Custom &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

// class ME_runner_gg_CPPProcess_4l: public ME_runner
// {
// public:
// 	double evaluate(MEKD &in_MEKD, const input &in)
// 	{
// 		in_MEKD.Run_ME_Configurator_CPPProcess("gg");
// 		return in_MEKD.Signal_ME;
// 	}
// 	
// 	bool is_my_type(const process_description &in)
// 	{
// 		return (in.process == proc_RAW &&
// 				in.resonance == reson_Custom &&
// 				in.production == prod_gg &&
// 				in.final_state == final_4l);
// 	}
// };

/*
 * with photons
 */

class ME_runner_gg_Custom_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Custom();
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == reson_Custom &&
				in.production == prod_gg &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

class ME_runner_qq_bkg_Z_ZZ_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Z_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Zs_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_SIG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zs &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

class ME_runner_qq_bkg_Zt_2f_4l: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_BKG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zt &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4l);
	}
};

/*
 * with photons
 */

class ME_runner_qq_bkg_Z_ZZ_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_ZZ &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_bkg_Z_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_BKG_ZZ("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Z &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_bkg_Zs_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_SIG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zs &&
				in.production == prod_qq &&
				in.decay == decay_2f &&
				in.final_state == final_4lA);
	}
};

class ME_runner_qq_bkg_Zt_2f_4lA: public ME_runner
{
public:
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		in_MEKD.Run_ME_Configurator_Z4l_BKG("qq");
		return in_MEKD.Signal_ME;
	}
	
	bool is_my_type(const process_description &in)
	{
		return (in.process == proc_simple &&
				in.resonance == bkg_Zt &&
				in.production == prod_qq &&
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