///////////////////////////////////
/// Part responsible for        ///
/// momenta rearrangement       ///
///////////////////////////////////
#ifndef MEKD_sorter_cpp
#define MEKD_sorter_cpp

#include "MEKD.h"

namespace mekd
{
// helper function, can be exported
int MEKD::Arrange_4momenta(vector<pair<int, double *>> &id_p,
                           vector<double *> &p, final_state_types_ &fs)
{
    for (auto it = id_p.begin(); it != id_p.end(); ++it) {
        if ((*it).first == 0)
            (*it).first = 10000;
    }

    sort(id_p.begin(), id_p.end());

    if (id_p.size() != 5)
        return EXIT_ERROR_INPUT;

    // for size 5
    const int id0 = id_p[0].first;
    const int id1 = id_p[1].first;
    const int id2 = id_p[2].first;
    const int id3 = id_p[3].first;
    const int id4 = id_p[4].first;

    /*
    /* 2mu-decay-mode block
    */

    /// Two-lepton final state block
    if (id0 == -13 && id1 == 13 && id2 == 10000 && id3 == 10000 &&
        id4 == 10000) {
        p[2] = id_p[1].second;
        p[3] = id_p[0].second;
        fs = final_2mu;

        return 0;
    }

    /// Two-lepton + photon final state block
    if (id0 == -13 && id1 == 13 && id2 == 22 && id3 == 10000 && id4 == 10000) {
        p[2] = id_p[1].second;
        p[3] = id_p[0].second;
        p[4] = id_p[2].second;
        fs = final_2muA;

        return 0;
    }

    /*
    /* ZZ-decay-mode block
    */

    /// Four-lepton final state block
    if (id0 == -13 && id1 == -11 && id2 == 11 && id3 == 13 && id4 == 10000) {
        p[2] = id_p[2].second;
        p[3] = id_p[1].second;
        p[4] = id_p[3].second;
        p[5] = id_p[0].second;
        fs = final_2e2mu;

        return 0;
    }

    if (id0 == -13 && id1 == -13 && id2 == 13 && id3 == 13 && id4 == 10000) {
        p[2] = id_p[2].second;
        p[3] = id_p[0].second;
        p[4] = id_p[3].second;
        p[5] = id_p[1].second;
        fs = final_4mu;

        return 0;
    }

    if (id0 == -11 && id1 == -11 && id2 == 11 && id3 == 11 && id4 == 10000) {
        p[2] = id_p[2].second;
        p[3] = id_p[0].second;
        p[4] = id_p[3].second;
        p[5] = id_p[1].second;
        fs = final_4e;

        return 0;
    }

    /// Four-lepton + photon final state block
    if (id0 == -13 && id1 == -11 && id2 == 11 && id3 == 13 && id4 == 22) {
        p[2] = id_p[2].second;
        p[3] = id_p[1].second;
        p[4] = id_p[3].second;
        p[5] = id_p[0].second;
        p[6] = id_p[4].second;
        fs = final_2e2muA;

        return 0;
    }

    if (id0 == -13 && id1 == -13 && id2 == 13 && id3 == 13 && id4 == 22) {
        p[2] = id_p[2].second;
        p[3] = id_p[0].second;
        p[4] = id_p[3].second;
        p[5] = id_p[1].second;
        p[6] = id_p[4].second;
        fs = final_4muA;

        return 0;
    }

    if (id0 == -11 && id1 == -11 && id2 == 11 && id3 == 11 && id4 == 22) {
        p[2] = id_p[2].second;
        p[3] = id_p[0].second;
        p[4] = id_p[3].second;
        p[5] = id_p[1].second;
        p[6] = id_p[4].second;
        fs = final_4eA;

        return 0;
    }

    /*
    /* ttbb, bb-decay-mode block
    */

    if (id0 == -6 && id1 == -5 && id2 == 5 && id3 == 6 && id4 == 10000) {
        p[2] = id_p[3].second;
        p[3] = id_p[0].second;
        p[4] = id_p[2].second;
        p[5] = id_p[1].second;
        fs = final_ttbb_;

        return 0;
    }

    if (id0 == 10000 && id1 == 10000 && id2 == 10000 && id3 == 10000 &&
        id4 == 10000) {
        if (flag.Warning_Mode)
            cout << "Warning. Particle ids are not set. Assuming a proper "
                    "input-particle configuration.\n";
        if (flag.Warning_Mode)
            cout << "Proceeding according to a specified final state (" << fs
                 << ").\n";
        p[2] = id_p[0].second;
        p[3] = id_p[1].second;
        p[4] = id_p[2].second;
        p[5] = id_p[3].second;
        p[6] = id_p[4].second;

        return 0;
    }

    return 1;
}

/// end of namespace
}

#endif

////////////////////////////////
/// END OF MEKD_sorter.cpp   ///
////////////////////////////////