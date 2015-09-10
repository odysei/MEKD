/*************************************************************************
*  Authors:		MEKD fans
*  More info:	http://mekd.ihepa.ufl.edu
*  Contact:		odysei@cern.ch, mekd@phys.ufl.edu
*  Info:		MEKD standard containers/structs are defined here.
*************************************************************************/
#ifndef MEKD_INPUTS_h
#define MEKD_INPUTS_h

namespace mekd
{

// see definitions for descriptions
struct process_desciption
{
	process_types process;
	resonance_types resonance;
	production_types production;
	resonance_decay_types decay;
	final_state_types final_state;
}

// standardized input to calculator
struct input: process_desciption
{
	
}

#endif
