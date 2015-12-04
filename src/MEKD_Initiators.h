//////////////////////////////////////////////
///  Initiators for v3. Run by ME_runners  ///
//////////////////////////////////////////////
#ifndef MEKD_Initiators_h
#define MEKD_Initiators_h

#include "MEKD.h"

namespace mekd
{

// true: initialized successfully
template <class cME>
bool ME_Initiator(const string &param_f, const string &name,
                  const int nprocesses_,
                  cME *i_ME, cME *&o_ME)
{
    // o_ME consumes i_ME
    o_ME = i_ME;
    if (o_ME->nprocesses != nprocesses_) {
        cerr << "Problem in " << name << " class detected.\n";
        delete o_ME;
        o_ME = NULL;
        
        return false;
    }
    
    if (param_f == "")
        o_ME->initProc();
    else
        o_ME->initProc(param_f);
    
    return true;
}

/// end of namespace
}

#endif
//////////////////////////////////
/// END OF MEKD_Initiators.h   ///
//////////////////////////////////