///////////////////////////////////
///  Helper functions useful for///
///  debugging                  ///
///////////////////////////////////
#ifndef MEKD_MG_DEBUG_cpp
#define MEKD_MG_DEBUG_cpp

#include "../interface/MEKD.h"

namespace mekd
{

/// 6 4-momenta printout
void MEKD_MG::Print_4momenta(vector<double *> &p_set)
{
	printf("Initial state:\n");
	printf("%.10E %.10E %.10E %.10E\n", p_set[0][0], p_set[0][1],
		   p_set[0][2], p_set[0][3]);
	printf("%.10E %.10E %.10E %.10E\n", p_set[1][0], p_set[1][1],
		   p_set[1][2], p_set[1][3]);
	
	printf("Final state:\n");
	printf("%.10E %.10E %.10E %.10E\n", p_set[2][0], p_set[2][1],
		   p_set[2][2], p_set[2][3]);
	printf("%.10E %.10E %.10E %.10E\n", p_set[3][0], p_set[3][1],
		   p_set[3][2], p_set[3][3]);
	printf("%.10E %.10E %.10E %.10E\n", p_set[4][0], p_set[4][1],
		   p_set[4][2], p_set[4][3]);
	printf("%.10E %.10E %.10E %.10E\n", p_set[5][0], p_set[5][1],
		   p_set[5][2], p_set[5][3]);
	printf("%.10E %.10E %.10E %.10E\n", p_set[6][0], p_set[6][1],
		   p_set[6][2], p_set[6][3]);
	printf("Sum px=%.10E\n", (p_set[2][1] + p_set[3][1] + p_set[4][1] +
							  p_set[5][1] + p_set[6][1]));
	printf("Sum py=%.10E\n", (p_set[2][2] + p_set[3][2] + p_set[4][2] +
							  p_set[5][2] + p_set[6][2]));
	printf("Sum pz=%.10E\n", (p_set[2][3] + p_set[3][3] + p_set[4][3] +
							  p_set[5][3] + p_set[6][3]));
	printf("Sum E=%.10E\n", (p_set[2][0] + p_set[3][0] + p_set[4][0] +
							 p_set[5][0] + p_set[6][0]));
}

/// end of namespace
}

#endif
//////////////////////////////////
/// END OF MEKD_MG_debug.cpp   ///
//////////////////////////////////