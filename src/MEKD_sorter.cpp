///////////////////////////////////
/// Part responsible for        ///
/// momenta rearrangement       ///
///////////////////////////////////
#ifndef MEKD_sorter_cpp
#define MEKD_sorter_cpp

#include "../interface/MEKD.h"

namespace mekd
{
// helper function, can be exported
int MEKD::Arrange_4momenta(data &da)
{
    vector<int> id(da.id);
    vector<double *> p(da.fp);
    
// 	id[0] = id1;
// 	id[1] = id2;
// 	id[2] = id3;
// 	id[3] = id4;
// 	id[4] = id5;

	if (id[0] == 0)
		id[0] = 10000;
	if (id[1] == 0)
		id[1] = 10000;
	if (id[2] == 0)
		id[2] = 10000;
	if (id[3] == 0)
		id[3] = 10000;
	if (id[4] == 0)
		id[4] = 10000;
	sort(id.begin(), id.end());

	////////////////////////////
	/// 2mu-decay-mode block ///
	////////////////////////////

	/// Two-lepton final state block
	if (id[0] == -13 && id[1] == 13 && id[2] == 10000 &&
		id[3] == 10000 && id[4] == 10000) {
		if (da.id[0] == 13)
			da.fp[0] = p[0];
		if (da.id[1] == 13)
			da.fp[0] = p[1];

		if (da.id[0] == -13)
			da.fp[1] = p[0];
		if (da.id[1] == -13)
			da.fp[1] = p[1];

// 		da.fp[4] = NULL;
		da.fs = final_2mu;

		return 0;
	}

	/// Two-lepton + photon final state block
	if (id[0] == -13 && id[1] == 13 && id[2] == 22 &&
		id[3] == 10000 && id[4] == 10000) {
		if (da.id[0] == 13)
			da.fp[0] = p[0];
		if (da.id[1] == 13)
			da.fp[0] = p[1];
		if (da.id[2] == 13)
			da.fp[0] = p[2];

		if (da.id[0] == -13)
			da.fp[1] = p[0];
		if (da.id[1] == -13)
			da.fp[1] = p[1];
		if (da.id[2] == -13)
			da.fp[1] = p[2];

		if (da.id[0] == 22)
			da.fp[4] = p[0];
		if (da.id[1] == 22)
			da.fp[4] = p[1];
		if (da.id[2] == 22)
			da.fp[4] = p[2];
		da.fs = final_2muA;

		return 0;
	}

	///////////////////////////
	/// ZZ-decay-mode block ///
	///////////////////////////

	/// Four-lepton final state block
	if (id[0] == -13 && id[1] == -11 && id[2] == 11 &&
		id[3] == 13 && id[4] == 10000) {
		if (da.id[0] == 11)
			da.fp[0] = p[0];
		if (da.id[1] == 11)
			da.fp[0] = p[1];
		if (da.id[2] == 11)
			da.fp[0] = p[2];
		if (da.id[3] == 11)
			da.fp[0] = p[3];

		if (da.id[0] == -11)
			da.fp[1] = p[0];
		if (da.id[1] == -11)
			da.fp[1] = p[1];
		if (da.id[2] == -11)
			da.fp[1] = p[2];
		if (da.id[3] == -11)
			da.fp[1] = p[3];

		if (da.id[0] == 13)
			da.fp[2] = p[0];
		if (da.id[1] == 13)
			da.fp[2] = p[1];
		if (da.id[2] == 13)
			da.fp[2] = p[2];
		if (da.id[3] == 13)
			da.fp[2] = p[3];

		if (da.id[0] == -13)
			da.fp[3] = p[0];
		if (da.id[1] == -13)
			da.fp[3] = p[1];
		if (da.id[2] == -13)
			da.fp[3] = p[2];
		if (da.id[3] == -13)
			da.fp[3] = p[3];

// 		da.fp[4] = NULL;
		da.fs = final_2e2mu;

		return 0;
	}

	if (id[0] == -13 && id[1] == -13 && id[2] == 13 &&
		id[3] == 13 && id[4] == 10000) {
		bool caught = false; // first muon has beed caught
		if (da.id[0] == 13 && !caught) {
			da.fp[0] = p[0];
			caught = true;
		}
		if (da.id[1] == 13 && caught)
			da.fp[2] = p[1];
		if (da.id[1] == 13 && !caught) {
			da.fp[0] = p[1];
			caught = true;
		}
		if (da.id[2] == 13 && caught)
			da.fp[2] = p[2];
		if (da.id[2] == 13 && !caught) {
			da.fp[0] = p[2];
			caught = true;
		}
		if (da.id[3] == 13 && caught)
			da.fp[2] = p[3];

		caught = false; // first antimuon has beed caught
		if (da.id[0] == -13 && !caught) {
			da.fp[1] = p[0];
			caught = true;
		}
		if (da.id[1] == -13 && caught)
			da.fp[3] = p[1];
		if (da.id[1] == -13 && !caught) {
			da.fp[1] = p[1];
			caught = true;
		}
		if (da.id[2] == -13 && caught)
			da.fp[3] = p[2];
		if (da.id[2] == -13 && !caught) {
			da.fp[1] = p[2];
			caught = true;
		}
		if (da.id[3] == -13 && caught)
			da.fp[3] = p[3];

// 		da.fp[4] = NULL;
		da.fs = final_4mu;

		return 0;
	}

	if (id[0] == -11 && id[1] == -11 && id[2] == 11 &&
		id[3] == 11 && id[4] == 10000) {
		bool caught = false; // first electron has beed caught
		if (da.id[0] == 11 && !caught) {
			da.fp[0] = p[0];
			caught = true;
		}
		if (da.id[1] == 11 && caught)
			da.fp[2] = p[1];
		if (da.id[1] == 11 && !caught) {
			da.fp[0] = p[1];
			caught = true;
		}
		if (da.id[2] == 11 && caught)
			da.fp[2] = p[2];
		if (da.id[2] == 11 && !caught) {
			da.fp[0] = p[2];
			caught = true;
		}
		if (da.id[3] == 11 && caught)
			da.fp[2] = p[3];

		caught = false; // first positron has beed caught
		if (da.id[0] == -11 && !caught) {
			da.fp[1] = p[0];
			caught = true;
		}
		if (da.id[1] == -11 && caught)
			da.fp[3] = p[1];
		if (da.id[1] == -11 && !caught) {
			da.fp[1] = p[1];
			caught = true;
		}
		if (da.id[2] == -11 && caught)
			da.fp[3] = p[2];
		if (da.id[2] == -11 && !caught) {
			da.fp[1] = p[2];
			caught = true;
		}
		if (da.id[3] == -11 && caught)
			da.fp[3] = p[3];

// 		da.fp[4] = NULL;
		da.fs = final_4e;

		return 0;
	}

	/// Four-lepton + photon final state block
	if (id[0] == -13 && id[1] == -11 && id[2] == 11 &&
		id[3] == 13 && id[4] == 22) {
		if (da.id[0] == 11)
			da.fp[0] = p[0];
		if (da.id[1] == 11)
			da.fp[0] = p[1];
		if (da.id[2] == 11)
			da.fp[0] = p[2];
		if (da.id[3] == 11)
			da.fp[0] = p[3];
		if (da.id[4] == 11)
			da.fp[0] = p[4];

		if (da.id[0] == -11)
			da.fp[1] = p[0];
		if (da.id[1] == -11)
			da.fp[1] = p[1];
		if (da.id[2] == -11)
			da.fp[1] = p[2];
		if (da.id[3] == -11)
			da.fp[1] = p[3];
		if (da.id[4] == -11)
			da.fp[0] = p[4];

		if (da.id[0] == 13)
			da.fp[2] = p[0];
		if (da.id[1] == 13)
			da.fp[2] = p[1];
		if (da.id[2] == 13)
			da.fp[2] = p[2];
		if (da.id[3] == 13)
			da.fp[2] = p[3];
		if (da.id[4] == 13)
			da.fp[2] = p[4];

		if (da.id[0] == -13)
			da.fp[3] = p[0];
		if (da.id[1] == -13)
			da.fp[3] = p[1];
		if (da.id[2] == -13)
			da.fp[3] = p[2];
		if (da.id[3] == -13)
			da.fp[3] = p[3];
		if (da.id[4] == -13)
			da.fp[3] = p[4];

		if (da.id[0] == 22)
			da.fp[4] = p[0];
		if (da.id[1] == 22)
			da.fp[4] = p[1];
		if (da.id[2] == 22)
			da.fp[4] = p[2];
		if (da.id[3] == 22)
			da.fp[4] = p[3];
		if (da.id[4] == 22)
			da.fp[4] = p[4];
		da.fs = final_2e2muA;

		return 0;
	}

	if (id[0] == -13 && id[1] == -13 && id[2] == 13 &&
		id[3] == 13 && id[4] == 22) {
		bool caught = false; // first muon has beed caught
		if (da.id[0] == 13 && !caught) {
			da.fp[0] = p[0];
			caught = true;
		}
		if (da.id[1] == 13 && caught)
			da.fp[2] = p[1];
		if (da.id[1] == 13 && !caught) {
			da.fp[0] = p[1];
			caught = true;
		}
		if (da.id[2] == 13 && caught)
			da.fp[2] = p[2];
		if (da.id[2] == 13 && !caught) {
			da.fp[0] = p[2];
			caught = true;
		}
		if (da.id[3] == 13 && caught)
			da.fp[2] = p[3];
		if (da.id[3] == 13 && !caught) {
			da.fp[0] = p[3];
			caught = true;
		}
		if (da.id[4] == 13 && caught)
			da.fp[2] = p[4];

		caught = false; // first antimuon has beed caught
		if (da.id[0] == -13 && !caught) {
			da.fp[1] = p[0];
			caught = true;
		}
		if (da.id[1] == -13 && caught)
			da.fp[3] = p[1];
		if (da.id[1] == -13 && !caught) {
			da.fp[1] = p[1];
			caught = true;
		}
		if (da.id[2] == -13 && caught)
			da.fp[3] = p[2];
		if (da.id[2] == -13 && !caught) {
			da.fp[1] = p[2];
			caught = true;
		}
		if (da.id[3] == -13 && caught)
			da.fp[3] = p[3];
		if (da.id[3] == -13 && !caught) {
			da.fp[1] = p[3];
			caught = true;
		}
		if (da.id[4] == -13 && caught)
			da.fp[3] = p[4];

		if (da.id[0] == 22)
			da.fp[4] = p[0];
		if (da.id[1] == 22)
			da.fp[4] = p[1];
		if (da.id[2] == 22)
			da.fp[4] = p[2];
		if (da.id[3] == 22)
			da.fp[4] = p[3];
		if (da.id[4] == 22)
			da.fp[4] = p[4];
		da.fs = final_4muA;

		return 0;
	}

	if (id[0] == -11 && id[1] == -11 && id[2] == 11 &&
		id[3] == 11 && id[4] == 22) {
		bool caught = false; // first electron has beed caught
		if (da.id[0] == 11 && !caught) {
			da.fp[0] = p[0];
			caught = true;
		}
		if (da.id[1] == 11 && caught)
			da.fp[2] = p[1];
		if (da.id[1] == 11 && !caught) {
			da.fp[0] = p[1];
			caught = true;
		}
		if (da.id[2] == 11 && caught)
			da.fp[2] = p[2];
		if (da.id[2] == 11 && !caught) {
			da.fp[0] = p[2];
			caught = true;
		}
		if (da.id[3] == 11 && caught)
			da.fp[2] = p[3];
		if (da.id[3] == 11 && !caught) {
			da.fp[0] = p[3];
			caught = true;
		}
		if (da.id[4] == 11 && caught)
			da.fp[2] = p[4];

		caught = false; // first positron has beed caught
		if (da.id[0] == -11 && !caught) {
			da.fp[1] = p[0];
			caught = true;
		}
		if (da.id[1] == -11 && caught)
			da.fp[3] = p[1];
		if (da.id[1] == -11 && !caught) {
			da.fp[1] = p[1];
			caught = true;
		}
		if (da.id[2] == -11 && caught)
			da.fp[3] = p[2];
		if (da.id[2] == -11 && !caught) {
			da.fp[1] = p[2];
			caught = true;
		}
		if (da.id[3] == -11 && caught)
			da.fp[3] = p[3];
		if (da.id[3] == -11 && !caught) {
			da.fp[1] = p[3];
			caught = true;
		}
		if (da.id[4] == -11 && caught)
			da.fp[3] = p[4];

		if (da.id[0] == 22)
			da.fp[4] = p[0];
		if (da.id[1] == 22)
			da.fp[4] = p[1];
		if (da.id[2] == 22)
			da.fp[4] = p[2];
		if (da.id[3] == 22)
			da.fp[4] = p[3];
		if (da.id[4] == 22)
			da.fp[4] = p[4];
		da.fs = final_4eA;

		return 0;
	}

	if (id[0] == 10000 && id[1] == 10000 && id[2] == 10000 &&
		id[3] == 10000 && id[4] == 10000) {
		if (flag.Warning_Mode)
			cout << "Warning. Particle ids are not set. Assuming a proper "
					"input-particle configuration.\n";
		if (flag.Warning_Mode)
			cout << "Proceeding according to a specified final state ("
				 << da.fs << ").\n";
		da.fp[0] = p[0];
		da.fp[1] = p[1];
		da.fp[2] = p[2];
		da.fp[3] = p[3];
		da.fp[4] = p[4];

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