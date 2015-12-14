/*
 *
 * ME_runners. See defined processes below.
 *
 *
 */
#ifndef MEKD_Supported_MEs_Spin0_4l_init_cpp
#define MEKD_Supported_MEs_Spin0_4l_init_cpp

#include "Supported_MEs_Spin0_4l.h"
#include "MEKD_Initiators.h"

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

/// ME_runner_gg_Spin0Pm_ZZ_4l
bool ME_runner_gg_Spin0Pm_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Pm_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Pm_ZZ_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Pm_ZZ_4l
bool ME_runner_no_Spin0Pm_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Pm_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Pm_ZZ_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0Ph_ZZ_4l
bool ME_runner_gg_Spin0Ph_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Ph_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Ph_ZZ_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Ph_ZZ_4l
bool ME_runner_no_Spin0Ph_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Ph_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Ph_ZZ_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0M_ZZ_4l
bool ME_runner_gg_Spin0M_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0M_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0M_ZZ_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0M_ZZ_4l
bool ME_runner_no_Spin0M_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0M_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0M_ZZ_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0_ZZ_4l
bool ME_runner_gg_Spin0_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0_ZZ_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0_ZZ_4l
bool ME_runner_no_Spin0_ZZ_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0_ZZ_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0_ZZ_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_ZZ_4lA
bool ME_runner_gg_Spin0Pm_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Pm_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Pm_ZZ_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Pm_ZZ_4lA
bool ME_runner_no_Spin0Pm_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Pm_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Pm_ZZ_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0Ph_ZZ_4lA
bool ME_runner_gg_Spin0Ph_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Ph_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Ph_ZZ_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Ph_ZZ_4lA
bool ME_runner_no_Spin0Ph_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Ph_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Ph_ZZ_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0M_ZZ_4lA
bool ME_runner_gg_Spin0M_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0M_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0M_ZZ_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0M_ZZ_4lA
bool ME_runner_no_Spin0M_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0M_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0M_ZZ_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0_ZZ_4lA
bool ME_runner_gg_Spin0_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0_ZZ_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0_ZZ_4lA
bool ME_runner_no_Spin0_ZZ_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0_ZZ_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0_ZZ_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/*
 * Resonance to 2f decay modes.
 *
 * Final states: 4 leptons (+photon)
 */

/*
 * Spin-0 resonances
 */

/// ME_runner_gg_Spin0Pm_2f_4l
bool ME_runner_gg_Spin0Pm_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Pm_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Pm_2f_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Pm_2f_4l
bool ME_runner_no_Spin0Pm_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Pm_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Pm_2f_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0M_2f_4l
bool ME_runner_gg_Spin0M_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0M_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0M_2f_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0M_2f_4l
bool ME_runner_no_Spin0M_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0M_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0M_2f_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0_2f_4l
bool ME_runner_gg_Spin0_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OF(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SF(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0_2f_4l::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0_2f_4l
bool ME_runner_no_Spin0_2f_4l::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OF(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SF(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0_2f_4l::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0_2f_4l::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/*
 * with photons
 */

/// ME_runner_gg_Spin0Pm_2f_4lA
bool ME_runner_gg_Spin0Pm_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0Pm_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0Pm_2f_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0Pm_2f_4lA
bool ME_runner_no_Spin0Pm_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0Pm_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0Pm_2f_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0M_2f_4lA
bool ME_runner_gg_Spin0M_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0M_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0M_2f_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0M_2f_4lA
bool ME_runner_no_Spin0M_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0M_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0M_2f_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/// ME_runner_gg_Spin0_2f_4lA
bool ME_runner_gg_Spin0_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_gg_OF", 1, new gg_Spin0_2f_OFpA(),
                     ME_gg_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_gg_SF", 1, new gg_Spin0_2f_SFpA(),
                     ME_gg_SF))
        return false;
    
    return true;
}

bool ME_runner_gg_Spin0_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_gg_Spin0_2f_4lA::deinitialize()
{
    delete ME_gg_OF;
    delete ME_gg_SF;
}

/// ME_runner_no_Spin0_2f_4lA
bool ME_runner_no_Spin0_2f_4lA::initialize(const string &param_f)
{
    if (!ME_Initiator(param_f, "ME_OF", 1, new Spin0_2f_OFpA(),
                     ME_OF))
        return false;
    
    if (!ME_Initiator(param_f, "ME_SF", 1, new Spin0_2f_SFpA(),
                     ME_SF))
        return false;
    
    return true;
}

bool ME_runner_no_Spin0_2f_4lA::initialize()
{
    return initialize("");
}

void ME_runner_no_Spin0_2f_4lA::deinitialize()
{
    delete ME_OF;
    delete ME_SF;
}

/*
 * End of ME_runner classes
 */

/// end of namespace
}

#endif

/////////////////////////////////////
/// END OF MEKD_Supported_MEs_h   ///
/////////////////////////////////////