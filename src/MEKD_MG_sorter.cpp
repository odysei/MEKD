///////////////////////////////////
/// Part responsible for        ///
/// momenta rearrangement       ///
///////////////////////////////////
#ifndef MEKD_MG_sorter_cpp
#define MEKD_MG_sorter_cpp

#include "../interface/MEKD_MG.h"

namespace mekd
{

int MEKD_MG::Arrange_Internal_pls()
{
	id_set[0] = id1;
	id_set[1] = id2;
	id_set[2] = id3;
	id_set[3] = id4;
	id_set[4] = id5;

	if (id_set[0] == 0)
		id_set[0] = 10000;
	if (id_set[1] == 0)
		id_set[1] = 10000;
	if (id_set[2] == 0)
		id_set[2] = 10000;
	if (id_set[3] == 0)
		id_set[3] = 10000;
	if (id_set[4] == 0)
		id_set[4] = 10000;
	sort(id_set.begin(), id_set.end());

	////////////////////////////
	/// 2mu-decay-mode block ///
	////////////////////////////

	/// Two-lepton final state block
	if (id_set[0] == -13 && id_set[1] == 13 && id_set[2] == 10000 &&
		id_set[3] == 10000 && id_set[4] == 10000) {
		if (id1 == 13)
			pl1_internal = p1;
		if (id2 == 13)
			pl1_internal = p2;

		if (id1 == -13)
			pl2_internal = p1;
		if (id2 == -13)
			pl2_internal = p2;

		pA1_internal = NULL;
		Final_state = "2m";

		return 0;
	}

	/// Two-lepton + photon final state block
	if (id_set[0] == -13 && id_set[1] == 13 && id_set[2] == 22 &&
		id_set[3] == 10000 && id_set[4] == 10000) {
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
		Final_state = "2mA";

		return 0;
	}

	///////////////////////////
	/// ZZ-decay-mode block ///
	///////////////////////////

	/// Four-lepton final state block
	if (id_set[0] == -13 && id_set[1] == -11 && id_set[2] == 11 &&
		id_set[3] == 13 && id_set[4] == 10000) {
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
		Final_state = "2e2m";

		return 0;
	}

	if (id_set[0] == -13 && id_set[1] == -13 && id_set[2] == 13 &&
		id_set[3] == 13 && id_set[4] == 10000) {
		buffer_bool = false; // first muon has beed caught
		if (id1 == 13 && !buffer_bool) {
			pl1_internal = p1;
			buffer_bool = true;
		}
		if (id2 == 13 && buffer_bool)
			pl3_internal = p2;
		if (id2 == 13 && !buffer_bool) {
			pl1_internal = p2;
			buffer_bool = true;
		}
		if (id3 == 13 && buffer_bool)
			pl3_internal = p3;
		if (id3 == 13 && !buffer_bool) {
			pl1_internal = p3;
			buffer_bool = true;
		}
		if (id4 == 13 && buffer_bool)
			pl3_internal = p4;

		buffer_bool = false; // first antimuon has beed caught
		if (id1 == -13 && !buffer_bool) {
			pl2_internal = p1;
			buffer_bool = true;
		}
		if (id2 == -13 && buffer_bool)
			pl4_internal = p2;
		if (id2 == -13 && !buffer_bool) {
			pl2_internal = p2;
			buffer_bool = true;
		}
		if (id3 == -13 && buffer_bool)
			pl4_internal = p3;
		if (id3 == -13 && !buffer_bool) {
			pl2_internal = p3;
			buffer_bool = true;
		}
		if (id4 == -13 && buffer_bool)
			pl4_internal = p4;

		pA1_internal = NULL;
		Final_state = "4mu";

		return 0;
	}

	if (id_set[0] == -11 && id_set[1] == -11 && id_set[2] == 11 &&
		id_set[3] == 11 && id_set[4] == 10000) {
		buffer_bool = false; // first electron has beed caught
		if (id1 == 11 && !buffer_bool) {
			pl1_internal = p1;
			buffer_bool = true;
		}
		if (id2 == 11 && buffer_bool)
			pl3_internal = p2;
		if (id2 == 11 && !buffer_bool) {
			pl1_internal = p2;
			buffer_bool = true;
		}
		if (id3 == 11 && buffer_bool)
			pl3_internal = p3;
		if (id3 == 11 && !buffer_bool) {
			pl1_internal = p3;
			buffer_bool = true;
		}
		if (id4 == 11 && buffer_bool)
			pl3_internal = p4;

		buffer_bool = false; // first positron has beed caught
		if (id1 == -11 && !buffer_bool) {
			pl2_internal = p1;
			buffer_bool = true;
		}
		if (id2 == -11 && buffer_bool)
			pl4_internal = p2;
		if (id2 == -11 && !buffer_bool) {
			pl2_internal = p2;
			buffer_bool = true;
		}
		if (id3 == -11 && buffer_bool)
			pl4_internal = p3;
		if (id3 == -11 && !buffer_bool) {
			pl2_internal = p3;
			buffer_bool = true;
		}
		if (id4 == -11 && buffer_bool)
			pl4_internal = p4;

		pA1_internal = NULL;
		Final_state = "4e";

		return 0;
	}

	/// Four-lepton + photon final state block
	if (id_set[0] == -13 && id_set[1] == -11 && id_set[2] == 11 &&
		id_set[3] == 13 && id_set[4] == 22) {
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
		Final_state = "2e2mA";

		return 0;
	}

	if (id_set[0] == -13 && id_set[1] == -13 && id_set[2] == 13 &&
		id_set[3] == 13 && id_set[4] == 22) {
		buffer_bool = false; // first muon has beed caught
		if (id1 == 13 && !buffer_bool) {
			pl1_internal = p1;
			buffer_bool = true;
		}
		if (id2 == 13 && buffer_bool)
			pl3_internal = p2;
		if (id2 == 13 && !buffer_bool) {
			pl1_internal = p2;
			buffer_bool = true;
		}
		if (id3 == 13 && buffer_bool)
			pl3_internal = p3;
		if (id3 == 13 && !buffer_bool) {
			pl1_internal = p3;
			buffer_bool = true;
		}
		if (id4 == 13 && buffer_bool)
			pl3_internal = p4;
		if (id4 == 13 && !buffer_bool) {
			pl1_internal = p4;
			buffer_bool = true;
		}
		if (id5 == 13 && buffer_bool)
			pl3_internal = p5;

		buffer_bool = false; // first antimuon has beed caught
		if (id1 == -13 && !buffer_bool) {
			pl2_internal = p1;
			buffer_bool = true;
		}
		if (id2 == -13 && buffer_bool)
			pl4_internal = p2;
		if (id2 == -13 && !buffer_bool) {
			pl2_internal = p2;
			buffer_bool = true;
		}
		if (id3 == -13 && buffer_bool)
			pl4_internal = p3;
		if (id3 == -13 && !buffer_bool) {
			pl2_internal = p3;
			buffer_bool = true;
		}
		if (id4 == -13 && buffer_bool)
			pl4_internal = p4;
		if (id4 == -13 && !buffer_bool) {
			pl2_internal = p4;
			buffer_bool = true;
		}
		if (id5 == -13 && buffer_bool)
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
		Final_state = "4muA";

		return 0;
	}

	if (id_set[0] == -11 && id_set[1] == -11 && id_set[2] == 11 &&
		id_set[3] == 11 && id_set[4] == 22) {
		buffer_bool = false; // first electron has beed caught
		if (id1 == 11 && !buffer_bool) {
			pl1_internal = p1;
			buffer_bool = true;
		}
		if (id2 == 11 && buffer_bool)
			pl3_internal = p2;
		if (id2 == 11 && !buffer_bool) {
			pl1_internal = p2;
			buffer_bool = true;
		}
		if (id3 == 11 && buffer_bool)
			pl3_internal = p3;
		if (id3 == 11 && !buffer_bool) {
			pl1_internal = p3;
			buffer_bool = true;
		}
		if (id4 == 11 && buffer_bool)
			pl3_internal = p4;
		if (id4 == 11 && !buffer_bool) {
			pl1_internal = p4;
			buffer_bool = true;
		}
		if (id5 == 11 && buffer_bool)
			pl3_internal = p5;

		buffer_bool = false; // first positron has beed caught
		if (id1 == -11 && !buffer_bool) {
			pl2_internal = p1;
			buffer_bool = true;
		}
		if (id2 == -11 && buffer_bool)
			pl4_internal = p2;
		if (id2 == -11 && !buffer_bool) {
			pl2_internal = p2;
			buffer_bool = true;
		}
		if (id3 == -11 && buffer_bool)
			pl4_internal = p3;
		if (id3 == -11 && !buffer_bool) {
			pl2_internal = p3;
			buffer_bool = true;
		}
		if (id4 == -11 && buffer_bool)
			pl4_internal = p4;
		if (id4 == -11 && !buffer_bool) {
			pl2_internal = p4;
			buffer_bool = true;
		}
		if (id5 == -11 && buffer_bool)
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
		Final_state = "4eA";

		return 0;
	}

	if (id_set[0] == 10000 && id_set[1] == 10000 && id_set[2] == 10000 &&
		id_set[3] == 10000 && id_set[4] == 10000) {
		if (Warning_Mode)
			cout << "Warning. Particle ids are not set. Assuming a proper "
					"input-particle configuration.\n";
		if (Warning_Mode)
			cout << "Proceeding according to a specified final state ("
				 << Final_state << ").\n";
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

///////////////////////////////////
/// END OF MEKD_MG_Sorter.cpp   ///
///////////////////////////////////