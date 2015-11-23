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
 * Resonance to 2f decay modes.
 * 
 * Final states: t tbar b bbar
 */

/*
 * Spin-0 resonances
 */

class ME_runner_all_bkg_Spin0Pm_2f_ttbb: public ME_runner
{
public:
	const process_description me =
	{
		proc_ttX,	    // process
		bkg_reson_Spin0Pm,	// resonance
		prod_all,		// production
		decay_2f,		// decay
		final_ttbb		// final_state
	};
    
    virtual const process_description my_type()
	{
        return me;
	}
	
	bool is_my_type(const process_description &in)
	{
		return compare_types(in, me);
	}
	
	bool initialize(const string &param_f)
    {
        ME = new MG5_sm_full::cc_ttbb;
        if (ME->nprocesses != 2) {
            cerr << "Problem in ME class detected.\n";
            return false;
        }
        ME->initProc(param_f);
        return true;
    }
	
	double evaluate(MEKD &in_MEKD, const input &in)
	{
		ME->setMomenta(in_MEKD.idata.p);
		ME->sigmaKin();
		const double *buffer = ME->getMatrixElements();
        
		return (buffer[0] + buffer[1]);
	}
	
	// Actual MEs
    MG5_sm_full::cc_ttbb *ME;
};

/*
 * End of ME_runner classes
 */

/// end of namespace
}

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////