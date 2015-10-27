///////////////////////////////////
///  Helper functions useful for///
///  debugging                  ///
///////////////////////////////////
#ifndef MEKD_debug_cpp
#define MEKD_debug_cpp

#include "../interface/MEKD.h"

namespace mekd
{

/// 6 4-momenta printout
void MEKD::Print_4momenta(const vector<double *> &p)
{
	printf("Initial state:\n");
	printf("%.10E %.10E %.10E %.10E\n", p[0][0], p[0][1],
		   p[0][2], p[0][3]);
	printf("%.10E %.10E %.10E %.10E\n", p[1][0], p[1][1],
		   p[1][2], p[1][3]);
	
	printf("Final state:\n");
	printf("%.10E %.10E %.10E %.10E\n", p[2][0], p[2][1],
		   p[2][2], p[2][3]);
	printf("%.10E %.10E %.10E %.10E\n", p[3][0], p[3][1],
		   p[3][2], p[3][3]);
	printf("%.10E %.10E %.10E %.10E\n", p[4][0], p[4][1],
		   p[4][2], p[4][3]);
	printf("%.10E %.10E %.10E %.10E\n", p[5][0], p[5][1],
		   p[5][2], p[5][3]);
	printf("%.10E %.10E %.10E %.10E\n", p[6][0], p[6][1],
		   p[6][2], p[6][3]);
	printf("Sum px=%.10E\n", (p[2][1] + p[3][1] + p[4][1] +
							  p[5][1] + p[6][1]));
	printf("Sum py=%.10E\n", (p[2][2] + p[3][2] + p[4][2] +
							  p[5][2] + p[6][2]));
	printf("Sum pz=%.10E\n", (p[2][3] + p[3][3] + p[4][3] +
							  p[5][3] + p[6][3]));
	printf("Sum E=%.10E\n", (p[2][0] + p[3][0] + p[4][0] +
							 p[5][0] + p[6][0]));
}

/// end of namespace
}

#endif
///////////////////////////////
/// END OF MEKD_debug.cpp   ///
///////////////////////////////