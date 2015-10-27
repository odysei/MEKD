///////////////////////////////////
/// Part responsible for        ///
/// momenta rearrangement       ///
///////////////////////////////////
#ifndef MEKD_sorter_cpp
#define MEKD_sorter_cpp

#include "../interface/MEKD.h"

namespace mekd
{

int MEKD::Arrange_Internal_pls(data &da)
{
	da.id[0] = id1;
	da.id[1] = id2;
	da.id[2] = id3;
	da.id[3] = id4;
	da.id[4] = id5;

	if (da.id[0] == 0)
		da.id[0] = 10000;
	if (da.id[1] == 0)
		da.id[1] = 10000;
	if (da.id[2] == 0)
		da.id[2] = 10000;
	if (da.id[3] == 0)
		da.id[3] = 10000;
	if (da.id[4] == 0)
		da.id[4] = 10000;
	sort(da.id.begin(), da.id.end());

	////////////////////////////
	/// 2mu-decay-mode block ///
	////////////////////////////

	/// Two-lepton final state block
	if (da.id[0] == -13 && da.id[1] == 13 && da.id[2] == 10000 &&
		da.id[3] == 10000 && da.id[4] == 10000) {
		if (id1 == 13)
			pl1_internal = p1;
		if (id2 == 13)
			pl1_internal = p2;

		if (id1 == -13)
			pl2_internal = p1;
		if (id2 == -13)
			pl2_internal = p2;

		pA1_internal = NULL;
		da.fs = final_2mu;

		return 0;
	}

	/// Two-lepton + photon final state block
	if (da.id[0] == -13 && da.id[1] == 13 && da.id[2] == 22 &&
		da.id[3] == 10000 && da.id[4] == 10000) {
		if (id1 == 13)
			pl1_internal = p1;
		if (id2 == 13)
			pl1_internal = p2;
		if (id3 == 13)
			pl1_internal = p3;

		if (id1 == -13)
			pl2_internal = p1;
		if (id2 == -13)
			pl2_internal = p2;
		if (id3 == -13)
			pl2_internal = p3;

		if (id1 == 22)
			pA1_internal = p1;
		if (id2 == 22)
			pA1_internal = p2;
		if (id3 == 22)
			pA1_internal = p3;
		da.fs = final_2muA;

		return 0;
	}

	///////////////////////////
	/// ZZ-decay-mode block ///
	///////////////////////////

	/// Four-lepton final state block
	if (da.id[0] == -13 && da.id[1] == -11 && da.id[2] == 11 &&
		da.id[3] == 13 && da.id[4] == 10000) {
		if (id1 == 11)
			pl1_internal = p1;
		if (id2 == 11)
			pl1_internal = p2;
		if (id3 == 11)
			pl1_internal = p3;
		if (id4 == 11)
			pl1_internal = p4;

		if (id1 == -11)
			pl2_internal = p1;
		if (id2 == -11)
			pl2_internal = p2;
		if (id3 == -11)
			pl2_internal = p3;
		if (id4 == -11)
			pl2_internal = p4;

		if (id1 == 13)
			pl3_internal = p1;
		if (id2 == 13)
			pl3_internal = p2;
		if (id3 == 13)
			pl3_internal = p3;
		if (id4 == 13)
			pl3_internal = p4;

		if (id1 == -13)
			pl4_internal = p1;
		if (id2 == -13)
			pl4_internal = p2;
		if (id3 == -13)
			pl4_internal = p3;
		if (id4 == -13)
			pl4_internal = p4;

		pA1_internal = NULL;
		da.fs = final_2e2mu;

		return 0;
	}

	if (da.id[0] == -13 && da.id[1] == -13 && da.id[2] == 13 &&
		da.id[3] == 13 && da.id[4] == 10000) {
		bool caught = false; // first muon has beed caught
		if (id1 == 13 && !caught) {
			pl1_internal = p1;
			caught = true;
		}
		if (id2 == 13 && caught)
			pl3_internal = p2;
		if (id2 == 13 && !caught) {
			pl1_internal = p2;
			caught = true;
		}
		if (id3 == 13 && caught)
			pl3_internal = p3;
		if (id3 == 13 && !caught) {
			pl1_internal = p3;
			caught = true;
		}
		if (id4 == 13 && caught)
			pl3_internal = p4;

		caught = false; // first antimuon has beed caught
		if (id1 == -13 && !caught) {
			pl2_internal = p1;
			caught = true;
		}
		if (id2 == -13 && caught)
			pl4_internal = p2;
		if (id2 == -13 && !caught) {
			pl2_internal = p2;
			caught = true;
		}
		if (id3 == -13 && caught)
			pl4_internal = p3;
		if (id3 == -13 && !caught) {
			pl2_internal = p3;
			caught = true;
		}
		if (id4 == -13 && caught)
			pl4_internal = p4;

		pA1_internal = NULL;
		da.fs = final_4mu;

		return 0;
	}

	if (da.id[0] == -11 && da.id[1] == -11 && da.id[2] == 11 &&
		da.id[3] == 11 && da.id[4] == 10000) {
		bool caught = false; // first electron has beed caught
		if (id1 == 11 && !caught) {
			pl1_internal = p1;
			caught = true;
		}
		if (id2 == 11 && caught)
			pl3_internal = p2;
		if (id2 == 11 && !caught) {
			pl1_internal = p2;
			caught = true;
		}
		if (id3 == 11 && caught)
			pl3_internal = p3;
		if (id3 == 11 && !caught) {
			pl1_internal = p3;
			caught = true;
		}
		if (id4 == 11 && caught)
			pl3_internal = p4;

		caught = false; // first positron has beed caught
		if (id1 == -11 && !caught) {
			pl2_internal = p1;
			caught = true;
		}
		if (id2 == -11 && caught)
			pl4_internal = p2;
		if (id2 == -11 && !caught) {
			pl2_internal = p2;
			caught = true;
		}
		if (id3 == -11 && caught)
			pl4_internal = p3;
		if (id3 == -11 && !caught) {
			pl2_internal = p3;
			caught = true;
		}
		if (id4 == -11 && caught)
			pl4_internal = p4;

		pA1_internal = NULL;
		da.fs = final_4e;

		return 0;
	}

	/// Four-lepton + photon final state block
	if (da.id[0] == -13 && da.id[1] == -11 && da.id[2] == 11 &&
		da.id[3] == 13 && da.id[4] == 22) {
		if (id1 == 11)
			pl1_internal = p1;
		if (id2 == 11)
			pl1_internal = p2;
		if (id3 == 11)
			pl1_internal = p3;
		if (id4 == 11)
			pl1_internal = p4;
		if (id5 == 11)
			pl1_internal = p5;

		if (id1 == -11)
			pl2_internal = p1;
		if (id2 == -11)
			pl2_internal = p2;
		if (id3 == -11)
			pl2_internal = p3;
		if (id4 == -11)
			pl2_internal = p4;
		if (id5 == -11)
			pl1_internal = p5;

		if (id1 == 13)
			pl3_internal = p1;
		if (id2 == 13)
			pl3_internal = p2;
		if (id3 == 13)
			pl3_internal = p3;
		if (id4 == 13)
			pl3_internal = p4;
		if (id5 == 13)
			pl3_internal = p5;

		if (id1 == -13)
			pl4_internal = p1;
		if (id2 == -13)
			pl4_internal = p2;
		if (id3 == -13)
			pl4_internal = p3;
		if (id4 == -13)
			pl4_internal = p4;
		if (id5 == -13)
			pl4_internal = p5;

		if (id1 == 22)
			pA1_internal = p1;
		if (id2 == 22)
			pA1_internal = p2;
		if (id3 == 22)
			pA1_internal = p3;
		if (id4 == 22)
			pA1_internal = p4;
		if (id5 == 22)
			pA1_internal = p5;
		da.fs = final_2e2muA;

		return 0;
	}

	if (da.id[0] == -13 && da.id[1] == -13 && da.id[2] == 13 &&
		da.id[3] == 13 && da.id[4] == 22) {
		bool caught = false; // first muon has beed caught
		if (id1 == 13 && !caught) {
			pl1_internal = p1;
			caught = true;
		}
		if (id2 == 13 && caught)
			pl3_internal = p2;
		if (id2 == 13 && !caught) {
			pl1_internal = p2;
			caught = true;
		}
		if (id3 == 13 && caught)
			pl3_internal = p3;
		if (id3 == 13 && !caught) {
			pl1_internal = p3;
			caught = true;
		}
		if (id4 == 13 && caught)
			pl3_internal = p4;
		if (id4 == 13 && !caught) {
			pl1_internal = p4;
			caught = true;
		}
		if (id5 == 13 && caught)
			pl3_internal = p5;

		caught = false; // first antimuon has beed caught
		if (id1 == -13 && !caught) {
			pl2_internal = p1;
			caught = true;
		}
		if (id2 == -13 && caught)
			pl4_internal = p2;
		if (id2 == -13 && !caught) {
			pl2_internal = p2;
			caught = true;
		}
		if (id3 == -13 && caught)
			pl4_internal = p3;
		if (id3 == -13 && !caught) {
			pl2_internal = p3;
			caught = true;
		}
		if (id4 == -13 && caught)
			pl4_internal = p4;
		if (id4 == -13 && !caught) {
			pl2_internal = p4;
			caught = true;
		}
		if (id5 == -13 && caught)
			pl4_internal = p5;

		if (id1 == 22)
			pA1_internal = p1;
		if (id2 == 22)
			pA1_internal = p2;
		if (id3 == 22)
			pA1_internal = p3;
		if (id4 == 22)
			pA1_internal = p4;
		if (id5 == 22)
			pA1_internal = p5;
		da.fs = final_4muA;

		return 0;
	}

	if (da.id[0] == -11 && da.id[1] == -11 && da.id[2] == 11 &&
		da.id[3] == 11 && da.id[4] == 22) {
		bool caught = false; // first electron has beed caught
		if (id1 == 11 && !caught) {
			pl1_internal = p1;
			caught = true;
		}
		if (id2 == 11 && caught)
			pl3_internal = p2;
		if (id2 == 11 && !caught) {
			pl1_internal = p2;
			caught = true;
		}
		if (id3 == 11 && caught)
			pl3_internal = p3;
		if (id3 == 11 && !caught) {
			pl1_internal = p3;
			caught = true;
		}
		if (id4 == 11 && caught)
			pl3_internal = p4;
		if (id4 == 11 && !caught) {
			pl1_internal = p4;
			caught = true;
		}
		if (id5 == 11 && caught)
			pl3_internal = p5;

		caught = false; // first positron has beed caught
		if (id1 == -11 && !caught) {
			pl2_internal = p1;
			caught = true;
		}
		if (id2 == -11 && caught)
			pl4_internal = p2;
		if (id2 == -11 && !caught) {
			pl2_internal = p2;
			caught = true;
		}
		if (id3 == -11 && caught)
			pl4_internal = p3;
		if (id3 == -11 && !caught) {
			pl2_internal = p3;
			caught = true;
		}
		if (id4 == -11 && caught)
			pl4_internal = p4;
		if (id4 == -11 && !caught) {
			pl2_internal = p4;
			caught = true;
		}
		if (id5 == -11 && caught)
			pl4_internal = p5;

		if (id1 == 22)
			pA1_internal = p1;
		if (id2 == 22)
			pA1_internal = p2;
		if (id3 == 22)
			pA1_internal = p3;
		if (id4 == 22)
			pA1_internal = p4;
		if (id5 == 22)
			pA1_internal = p5;
		da.fs = final_4eA;

		return 0;
	}

	if (da.id[0] == 10000 && da.id[1] == 10000 && da.id[2] == 10000 &&
		da.id[3] == 10000 && da.id[4] == 10000) {
		if (flag.Warning_Mode)
			cout << "Warning. Particle ids are not set. Assuming a proper "
					"input-particle configuration.\n";
		if (flag.Warning_Mode)
			cout << "Proceeding according to a specified final state ("
				 << da.fs << ").\n";
		pl1_internal = p1;
		pl2_internal = p2;
		pl3_internal = p3;
		pl4_internal = p4;
		pA1_internal = p5;

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