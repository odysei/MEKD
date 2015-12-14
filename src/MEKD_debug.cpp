///////////////////////////////////
///  Helper functions useful for///
///  debugging                  ///
///////////////////////////////////
#ifndef MEKD_debug_cpp
#define MEKD_debug_cpp

#include "interface/MEKD.h"

namespace mekd
{

/// 7 4-momenta printout
void MEKD::Print_4momenta(const vector<double *> &p)
{
    printf("Initial state:\n");
    printf("%.10E %.10E %.10E %.10E\n", p[0][0], p[0][1], p[0][2], p[0][3]);
    printf("%.10E %.10E %.10E %.10E\n", p[1][0], p[1][1], p[1][2], p[1][3]);

    printf("Final state:\n");
    printf("%.10E %.10E %.10E %.10E\n", p[2][0], p[2][1], p[2][2], p[2][3]);
    printf("%.10E %.10E %.10E %.10E\n", p[3][0], p[3][1], p[3][2], p[3][3]);
    printf("%.10E %.10E %.10E %.10E\n", p[4][0], p[4][1], p[4][2], p[4][3]);
    printf("%.10E %.10E %.10E %.10E\n", p[5][0], p[5][1], p[5][2], p[5][3]);
    printf("%.10E %.10E %.10E %.10E\n", p[6][0], p[6][1], p[6][2], p[6][3]);
    printf("Sum px=%.10E\n", (p[2][1] + p[3][1] + p[4][1] + p[5][1] + p[6][1]));
    printf("Sum py=%.10E\n", (p[2][2] + p[3][2] + p[4][2] + p[5][2] + p[6][2]));
    printf("Sum pz=%.10E\n", (p[2][3] + p[3][3] + p[4][3] + p[5][3] + p[6][3]));
    printf("Sum E=%.10E\n", (p[2][0] + p[3][0] + p[4][0] + p[5][0] + p[6][0]));
}

void MEKD::Print_4momenta_auto(const vector<double *> &p)
{
    double p0 = 0;
    double p1 = 0;
    double p2 = 0;
    double p3 = 0;
    for (auto i : p) {
        const double ip0 = i[0];
        const double ip1 = i[1];
        const double ip2 = i[2];
        const double ip3 = i[3];
        printf("%.10E %.10E %.10E %.10E\n", ip0, ip1, ip2, ip3);
        p0 += ip0;
        p1 += ip1;
        p2 += ip2;
        p3 += ip3;
    }
    printf("Sum p[0]=%.10E\n", p0);
    printf("Sum p[1]=%.10E\n", p1);
    printf("Sum p[2]=%.10E\n", p2);
    printf("Sum p[3]=%.10E\n", p3);
}

/// end of namespace
}

#endif
///////////////////////////////
/// END OF MEKD_debug.cpp   ///
///////////////////////////////