///////////////////////////////////
///  Part responsible for ME    ///
///  calculations               ///
///////////////////////////////////
#ifndef MEKD_RunMEs_cpp
#define MEKD_RunMEs_cpp

#include "../interface/MEKD.h"

namespace mekd
{

/// ZZ and DY processes
int MEKD::Run_ME_Configurator_BKG_ZZ(string initial_state)
{
	return Run_ME_Dispatcher_BKG_ZZ(initial_state);
}

/// Z4l Background processes (t channel)
int MEKD::Run_ME_Configurator_Z4l_BKG(string initial_state)
{
	if (flag.Use_mZ4l_eq_m4l)
		Set_Of_Model_Parameters.set_block_entry("mass", 23, Mass_4l);
	return Run_ME_Dispatcher_Z4l_BKG(initial_state);
}

/// Z4l Signal processes (s channel)
int MEKD::Run_ME_Configurator_Z4l_SIG(string initial_state)
{
	if (flag.Use_mZ4l_eq_m4l)
		Set_Of_Model_Parameters.set_block_entry("mass", 23, Mass_4l);
	return Run_ME_Dispatcher_Z4l_SIG(initial_state);
}

int MEKD::Run_ME_Configurator_Custom()
{
	if ((error_value = Run_ME_Dispatcher_SIG_Spin0("gg")) != 0)
		return error_value;
	buffer_Custom = Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin1("qq")) != 0)
		return error_value;
	buffer_Custom += Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin2("gg")) != 0)
		return error_value;
	buffer_Custom += Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin2("qq")) != 0)
		return error_value;
	Signal_ME += buffer_Custom;

	return 0;
}

int MEKD::Run_ME_Configurator_CPPProcess(string initial_state)
{
	return Run_ME_Dispatcher_CPPProcess(initial_state);
}

////////////////////////////////////
/// Spin-0 resonances start here ///
////////////////////////////////////

/// A SM Higgs
int MEKD::Run_ME_Configurator_Spin0Pm(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin0_internal[0] =
		complex<double>(1, 0); // fits 2l case
	Mixing_Coefficients_Spin0_internal[1] =
		complex<double>(0, 0); // fits 2l case
	Mixing_Coefficients_Spin0_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[3] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin0_internal[0] = complex<double>(1, 0);
		Mixing_Coefficients_Spin0_internal[1] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin0(initial_state);
}

/// A pseudoscalar
int MEKD::Run_ME_Configurator_Spin0M(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin0_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[3] = complex<double>(1, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin0_internal[0] = complex<double>(0, 0);
		Mixing_Coefficients_Spin0_internal[1] = complex<double>(1, 0);
	}

	return Run_ME_Configurator_Spin0(initial_state);
}

/// A scalar with higher-order couplings
int MEKD::Run_ME_Configurator_Spin0Ph(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin0_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[1] = complex<double>(1, 0);
	Mixing_Coefficients_Spin0_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[3] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin0_internal[0] = complex<double>(0, 0);
		Mixing_Coefficients_Spin0_internal[1] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin0(initial_state);
}

////////////////////////////////////
/// Spin-1 resonances start here ///
////////////////////////////////////

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1M(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin1_internal[0] =
		complex<double>(1, 0); // Production, same for 2l
	Mixing_Coefficients_Spin1_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[4] = complex<double>(1, 0); // Decay
	Mixing_Coefficients_Spin1_internal[5] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin1_internal[6] = complex<double>(0, 0);
		Mixing_Coefficients_Spin1_internal[7] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin1(initial_state);
}

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1P(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin1_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin1_internal[1] =
		complex<double>(1, 0); // same for 2l
	Mixing_Coefficients_Spin1_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[4] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin1_internal[5] = complex<double>(1, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin1_internal[6] = complex<double>(0, 0);
		Mixing_Coefficients_Spin1_internal[7] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin1(initial_state);
}

////////////////////////////////////
/// Spin-2 resonances start here ///
////////////////////////////////////

/// A minimal-coupling KK graviton
int MEKD::Run_ME_Configurator_Spin2Pm(string initial_state)
{
	Predefined_Model = true;
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[0] =
			complex<double>(1, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(-1, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(1, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[3] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Pb(string initial_state)
{
	Predefined_Model = true;
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[0] =
			complex<double>(1, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph2(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph3(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[2] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph6(string initial_state)
{
	Predefined_Model = true;
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[0] =
			complex<double>(1, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph7(string initial_state)
{
	Predefined_Model = true;
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[0] =
			complex<double>(1, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh9(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh10(string initial_state)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0); // Production
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (initial_state == "gg")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0); // Decay
	Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[14] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[15] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[16] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[17] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[18] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[19] = complex<double>(1, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[11] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[12] = complex<double>(0, 0);
		Mixing_Coefficients_Spin2_internal[13] = complex<double>(0, 0);
	}

	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (initial_state == "qq")
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(initial_state);
}

/// A generic spin-0 resonance handler
int MEKD::Run_ME_Configurator_Spin0(string initial_state)
{
	if (Predefined_Model) {
		buffer_complex = Mixing_Coefficients_Spin0_internal;
		Predefined_Model = false;
	} else
		buffer_complex = Mixing_Coefficients_Spin0;

	if (flag.Use_mh_eq_m4l) {
		Set_Of_Model_Parameters.set_block_entry("mass", 9000006, Mass_4l);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 9000006,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 9000006,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 9000006, 1);

		LmbdGG_calculated = LmbdGG(Mass_4l);
	} else {
		Set_Of_Model_Parameters.set_block_entry("mass", 9000006, Higgs_mass);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 9000006,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 9000006,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 9000006, 1);

		LmbdGG_calculated = LmbdGG(Higgs_mass);
	}

	if (flag.Vary_signal_couplings) {
		// gg
		if (flag.Fix_Spin0_Production) {
			Set_Of_Model_Parameters.set_block_entry("heff", 1,
													complex<double>(0, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 2,
				complex<double>(4 * LmbdGG_calculated, 0)); // Spin0Pm
			Set_Of_Model_Parameters.set_block_entry("heff", 3,
													complex<double>(0, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 4, complex<double>(0, 0)); // Spin0M
		} else {
			Set_Of_Model_Parameters.set_block_entry("heff", 1,
													complex<double>(0, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 2,
				(buffer_complex[0] + buffer_complex[1] + buffer_complex[2]) *
					complex<double>(4 * LmbdGG_calculated, 0)); // Spin0P
			Set_Of_Model_Parameters.set_block_entry("heff", 3,
													complex<double>(0, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 4,
				buffer_complex[3] *
					complex<double>(4 * LmbdGG_calculated, 0)); // Spin0M
		}

		// Decay to ZZ
		if (flag.Use_mh_eq_m4l) {
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 5, buffer_complex[0] *
							   complex<double>(hZZ_coupling, 0)); // Spin0Pm
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 6,
				buffer_complex[1] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z,
									0)); // Spin0Ph
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 7,
				buffer_complex[2] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z /
										Mass_4l / Mass_4l,
									0)); // Spin0Ph+
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 8,
				buffer_complex[3] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z,
									0)); // Spin0M
		} else {
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 5, buffer_complex[0] *
							   complex<double>(hZZ_coupling, 0)); // Spin0Pm
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 6,
				buffer_complex[1] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z,
									0)); // Spin0Ph
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 7,
				buffer_complex[2] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z /
										Higgs_mass / Higgs_mass,
									0)); // Spin0Ph+
			Set_Of_Model_Parameters.set_block_entry(
				"heff", 8,
				buffer_complex[3] *
					complex<double>(hZZ_coupling / params_m_Z / params_m_Z,
									0)); // Spin0M
		}

		// Decay to 2l (or 2mu in 2f)
		Set_Of_Model_Parameters.set_block_entry(
			"heff", 19, buffer_complex[0] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"heff", 20, buffer_complex[1] * complex<double>(4.291210e-04, 0));

		// Decay to 2e (2f)
		Set_Of_Model_Parameters.set_block_entry(
			"heff", 21,
			buffer_complex[0] *
				complex<double>(4.291210e-04,
								0)); // for Hee should be 2.075371e-06
		Set_Of_Model_Parameters.set_block_entry(
			"heff", 22, buffer_complex[1] * complex<double>(4.291210e-04, 0));
	}

	// qq
	params_rhou01 = complex<double>(0, 0);
	params_rhou02 = complex<double>(0, 0);
	params_rhoc01 = complex<double>(0, 0);
	params_rhoc02 = complex<double>(0, 0);
	params_rhod01 = complex<double>(0, 0);
	params_rhod02 = complex<double>(0, 0);
	params_rhos01 = complex<double>(0, 0);
	params_rhos02 = complex<double>(0, 0);
	params_rhob01 = complex<double>(0, 0);
	params_rhob02 = complex<double>(0, 0);

	buffer_complex = NULL;

	return Run_ME_Dispatcher_SIG_Spin0(initial_state);
}

/// A generic spin-1 resonance handler
int MEKD::Run_ME_Configurator_Spin1(string initial_state)
{
	if (Predefined_Model) {
		buffer_complex = Mixing_Coefficients_Spin1_internal;
		Predefined_Model = false;
	} else
		buffer_complex = Mixing_Coefficients_Spin1;

	if (flag.Use_mh_eq_m4l) {
		Set_Of_Model_Parameters.set_block_entry("mass", 300, Mass_4l);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 300,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 300,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 300, 1);

		LmbdGG_calculated = LmbdGG(Mass_4l);
	} else {
		Set_Of_Model_Parameters.set_block_entry("mass", 300, Higgs_mass);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 300,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 300,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 300, 1);

		LmbdGG_calculated = LmbdGG(Higgs_mass);
	}

	if (flag.Vary_signal_couplings) {
		// qq
		if (flag.Fix_Spin1_Production) {
			params_rhod11 = complex<double>(
				sqrt(1 / 2) * LmbdGG_calculated * v_expectation, 0);
			params_rhos11 = complex<double>(
				sqrt(1 / 2) * LmbdGG_calculated * v_expectation, 0);
			params_rhob11 = complex<double>(
				sqrt(1 / 2) * LmbdGG_calculated * v_expectation, 0);
			params_rhou11 = complex<double>(
				sqrt(1 / 2) * LmbdGG_calculated * v_expectation, 0);
			params_rhoc11 = complex<double>(
				sqrt(1 / 2) * LmbdGG_calculated * v_expectation, 0);
			params_rhod12 = complex<double>(0, 0);
			params_rhos12 = complex<double>(0, 0);
			params_rhob12 = complex<double>(0, 0);
			params_rhou12 = complex<double>(0, 0);
			params_rhoc12 = complex<double>(0, 0);
			params_rhod13 = complex<double>(0, 0);
			params_rhos13 = complex<double>(0, 0);
			params_rhob13 = complex<double>(0, 0);
			params_rhou13 = complex<double>(0, 0);
			params_rhoc13 = complex<double>(0, 0);
			params_rhod14 = complex<double>(0, 0);
			params_rhos14 = complex<double>(0, 0);
			params_rhob14 = complex<double>(0, 0);
			params_rhou14 = complex<double>(0, 0);
			params_rhoc14 = complex<double>(0, 0);
		} else {
			params_rhod11 =
				buffer_complex[0] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhos11 =
				buffer_complex[0] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhob11 =
				buffer_complex[0] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhou11 =
				buffer_complex[0] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhoc11 =
				buffer_complex[0] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhod12 =
				buffer_complex[1] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhos12 =
				buffer_complex[1] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhob12 =
				buffer_complex[1] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhou12 =
				buffer_complex[1] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhoc12 =
				buffer_complex[1] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhod13 =
				buffer_complex[2] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhos13 =
				buffer_complex[2] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhob13 =
				buffer_complex[2] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhou13 =
				buffer_complex[2] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhoc13 =
				buffer_complex[2] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhod14 =
				buffer_complex[3] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhos14 =
				buffer_complex[3] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhob14 =
				buffer_complex[3] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhou14 =
				buffer_complex[3] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
			params_rhoc14 =
				buffer_complex[3] *
				complex<double>(LmbdGG_calculated * v_expectation, 0);
		}

		// Decay to ZZ
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 1, buffer_complex[4] *
						  complex<double>(hZZ_coupling / 2 / params_m_Z, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 2, buffer_complex[5] *
						  complex<double>(hZZ_coupling / 4 / params_m_Z, 0));

		// Decay to 2l (or 2mu in 2f)
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 23, buffer_complex[4] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 24, buffer_complex[5] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 25, buffer_complex[6] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 26, buffer_complex[7] * complex<double>(4.291210e-04, 0));

		// Decay to 2e (2f)
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 27,
			buffer_complex[4] *
				complex<double>(4.291210e-04,
								0)); // for Hee should be 2.075371e-06
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 28, buffer_complex[5] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 29, buffer_complex[6] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"vec", 30, buffer_complex[7] * complex<double>(4.291210e-04, 0));
	}

	buffer_complex = NULL;

	return Run_ME_Dispatcher_SIG_Spin1(initial_state);
}

/// A generic spin-2 resonance handler
int MEKD::Run_ME_Configurator_Spin2(string initial_state)
{
	if (Predefined_Model) {
		buffer_complex = Mixing_Coefficients_Spin2_internal;
		Predefined_Model = false;
	} else
		buffer_complex = Mixing_Coefficients_Spin2;

	if (flag.Use_mh_eq_m4l) {
		Set_Of_Model_Parameters.set_block_entry("mass", 9000007, Mass_4l);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 9000007,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 9000007,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 9000007, 1);

		LmbdGG_calculated = LmbdGG(Mass_4l);
	} else {
		Set_Of_Model_Parameters.set_block_entry("mass", 9000007, Higgs_mass);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				Set_Of_Model_Parameters.set_block_entry(
					"decay", 9000007,
					static_cast<double>(
						MEKD_CalcHEP_Extra::Higgs_width(Mass_4l)));
			else
				Set_Of_Model_Parameters.set_block_entry("decay", 9000007,
														Higgs_width);
		} else
			Set_Of_Model_Parameters.set_block_entry("decay", 9000007, 1);

		LmbdGG_calculated = LmbdGG(Higgs_mass);
	}

	if (flag.Vary_signal_couplings) {
		// gg
		if (flag.Use_mh_eq_m4l) {
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 1,
				buffer_complex[0] *
					complex<double>(8.0 * LmbdGG_calculated, 0)); // 8 flavors
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 2,
				buffer_complex[1] *
					complex<double>(8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 3,
				buffer_complex[2] *
					complex<double>(8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 4,
				buffer_complex[3] *
					complex<double>(
						8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
						0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 5,
				buffer_complex[4] *
					complex<double>(8.0 * LmbdGG_calculated * Mass_4l * Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 6,
				buffer_complex[5] *
					complex<double>(8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 7, buffer_complex[6] *
								  complex<double>(8.0 * LmbdGG_calculated, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 8,
				buffer_complex[7] *
					complex<double>(
						8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
						0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 9, buffer_complex[8] *
								  complex<double>(8.0 * LmbdGG_calculated, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 10,
				buffer_complex[9] *
					complex<double>(8.0 * LmbdGG_calculated / Mass_4l / Mass_4l,
									0));
		} else {
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 1,
				buffer_complex[0] *
					complex<double>(8.0 * LmbdGG_calculated, 0)); // 8 flavors
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 2,
				buffer_complex[1] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 3,
				buffer_complex[2] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 4,
				buffer_complex[3] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 5,
				buffer_complex[4] *
					complex<double>(
						8.0 * LmbdGG_calculated * Higgs_mass * Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 6,
				buffer_complex[5] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 7, buffer_complex[6] *
								  complex<double>(8.0 * LmbdGG_calculated, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 8,
				buffer_complex[7] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 9, buffer_complex[8] *
								  complex<double>(8.0 * LmbdGG_calculated, 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 10,
				buffer_complex[9] *
					complex<double>(
						8.0 * LmbdGG_calculated / Higgs_mass / Higgs_mass, 0));
		}

		// qq
		params_rhod21 =
			buffer_complex[0] * complex<double>(LmbdGG_calculated, 0);
		params_rhos21 =
			buffer_complex[0] * complex<double>(LmbdGG_calculated, 0);
		params_rhob21 =
			buffer_complex[0] * complex<double>(LmbdGG_calculated, 0);
		params_rhou21 =
			buffer_complex[0] * complex<double>(LmbdGG_calculated, 0);
		params_rhoc21 =
			buffer_complex[0] * complex<double>(LmbdGG_calculated, 0);
		params_rhod22 =
			buffer_complex[1] * complex<double>(LmbdGG_calculated, 0);
		params_rhos22 =
			buffer_complex[1] * complex<double>(LmbdGG_calculated, 0);
		params_rhob22 =
			buffer_complex[1] * complex<double>(LmbdGG_calculated, 0);
		params_rhou22 =
			buffer_complex[1] * complex<double>(LmbdGG_calculated, 0);
		params_rhoc22 =
			buffer_complex[1] * complex<double>(LmbdGG_calculated, 0);
		params_rhod23 =
			buffer_complex[2] * complex<double>(LmbdGG_calculated, 0);
		params_rhos23 =
			buffer_complex[2] * complex<double>(LmbdGG_calculated, 0);
		params_rhob23 =
			buffer_complex[2] * complex<double>(LmbdGG_calculated, 0);
		params_rhou23 =
			buffer_complex[2] * complex<double>(LmbdGG_calculated, 0);
		params_rhoc23 =
			buffer_complex[2] * complex<double>(LmbdGG_calculated, 0);
		params_rhod24 =
			buffer_complex[3] * complex<double>(LmbdGG_calculated, 0);
		params_rhos24 =
			buffer_complex[3] * complex<double>(LmbdGG_calculated, 0);
		params_rhob24 =
			buffer_complex[3] * complex<double>(LmbdGG_calculated, 0);
		params_rhou24 =
			buffer_complex[3] * complex<double>(LmbdGG_calculated, 0);
		params_rhoc24 =
			buffer_complex[3] * complex<double>(LmbdGG_calculated, 0);

		// Decay to ZZ
		if (flag.Use_mh_eq_m4l) {
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 11,
				buffer_complex[10] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										sqrt(2),
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 12,
				buffer_complex[11] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										Mass_4l / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 13,
				buffer_complex[12] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 14,
				buffer_complex[13] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 15,
				buffer_complex[14] *
					complex<double>(hZZ_coupling / 2 / sqrt(2), 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 16,
				buffer_complex[15] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 17,
				buffer_complex[16] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 18,
				buffer_complex[17] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 19,
				buffer_complex[18] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / Mass_4l,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 20,
				buffer_complex[19] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										Mass_4l / Mass_4l,
									0));

		} else {
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 11,
				buffer_complex[10] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										sqrt(2),
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 12,
				buffer_complex[11] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										Higgs_mass / Higgs_mass,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 13,
				buffer_complex[12] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 14,
				buffer_complex[13] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 15,
				buffer_complex[14] *
					complex<double>(hZZ_coupling / 2 / sqrt(2), 0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 16,
				buffer_complex[15] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / Higgs_mass,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 17,
				buffer_complex[16] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 18,
				buffer_complex[17] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										params_m_Z,
									0)); // or /mZ^4?
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 19,
				buffer_complex[18] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / Higgs_mass,
									0));
			Set_Of_Model_Parameters.set_block_entry(
				"gravity", 20,
				buffer_complex[19] *
					complex<double>(hZZ_coupling / 2 / params_m_Z / params_m_Z /
										Higgs_mass / Higgs_mass,
									0));
		}

		// Decay to 2l (or 2mu in 2f)
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 41,
			buffer_complex[10] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 42,
			buffer_complex[11] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 43,
			buffer_complex[12] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 44,
			buffer_complex[13] * complex<double>(4.291210e-04, 0));

		// Decay to 2e (2f)
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 45,
			buffer_complex[10] *
				complex<double>(4.291210e-04,
								0)); // for Hee should be 2.075371e-06
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 46,
			buffer_complex[11] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 47,
			buffer_complex[12] * complex<double>(4.291210e-04, 0));
		Set_Of_Model_Parameters.set_block_entry(
			"gravity", 48,
			buffer_complex[13] * complex<double>(4.291210e-04, 0));
	}

	buffer_complex = NULL;

	return Run_ME_Dispatcher_SIG_Spin2(initial_state);
}

/// ME_RAW (RAW MG5_aMC ME) dispatcher
int MEKD::Run_ME_Dispatcher_CPPProcess(string initial_state)
{
	// 	if( Resonance_decay_mode=="ZZ" )
	// 	{
	// 		if( Final_state=="4e" || Final_state=="4eA" )
	// 		{
	// // 			/// Common mass for the same-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_e
	// );
	//
	// 			if( initial_state=="NO" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	//
	// 		if( Final_state=="2e2m" || Final_state=="2e2mu" ||
	// Final_state=="2e2mA"
	// || Final_state=="2e2muA" )
	// 		{
	// // 			/// Common mass for the opposite-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 11,
	// params_m_e
	// );
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_mu
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	//
	// 		if( Final_state=="4m" || Final_state=="4mu" || Final_state=="4mA" ||
	// Final_state=="4muA" )
	// 		{
	// // 			/// Common mass for the same-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_mu
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	// 	}
	//
	// 	if( Resonance_decay_mode=="2l" )
	// 	{
	// 		if( Final_state=="4e" || Final_state=="4eA" )
	// 		{
	// // 			/// Common mass for the same-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_e
	// );
	//
	// 			if( initial_state=="NO" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && Final_state=="4e" )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && Final_state=="4eA" )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	//
	// 		if( Final_state=="2e2m" || Final_state=="2e2mu" ||
	// Final_state=="2e2mA"
	// || Final_state=="2e2muA" )
	// 		{
	// // 			/// Common mass for the opposite-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 11,
	// params_m_e
	// );
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_mu
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && (Final_state=="2e2m" ||
	// Final_state=="2e2mu") )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && (Final_state=="2e2mA" ||
	// Final_state=="2e2muA") )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	//
	// 		if( Final_state=="4m" || Final_state=="4mu" || Final_state=="4mA" ||
	// Final_state=="4muA" )
	// 		{
	// // 			/// Common mass for the same-flavor leptons
	// // 			Set_Of_Model_Parameters.set_block_entry( "mass", 13,
	// params_m_mu
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="NO" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="gg" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_RAW
	// );
	//
	// 			if( initial_state=="qq" && (Final_state=="4m" ||
	// Final_state=="4mu")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 			if( initial_state=="qq" && (Final_state=="4mA" ||
	// Final_state=="4muA")
	// )
	// 				return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 		}
	// 	}
	//
	// 	if( Final_state=="2m" || Final_state=="2mu" || Final_state=="2mA" ||
	// Final_state=="2muA" )
	// 	{
	// // 		/// Mass for the muons
	// // 		Set_Of_Model_Parameters.set_block_entry( "mass", 13, params_m_mu
	// );
	//
	// 		if( initial_state=="NO" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( false, ME_RAW
	// );
	//
	// 		if( initial_state=="NO" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( true, ME_RAW
	// );
	//
	// 		if( initial_state=="gg" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( false, ME_RAW
	// );
	//
	// 		if( initial_state=="gg" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( true, ME_RAW
	// );
	//
	// 		if( initial_state=="qq" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_RAW,
	// ME_RAW );
	//
	// 		if( initial_state=="qq" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_RAW,
	// ME_RAW );
	// 	}

	return 1;
}

/// ZZ and DY ME dispatcher
int MEKD::Run_ME_Dispatcher_BKG_ZZ(string initial_state)
{
	if (initial_state == "NO" &&
		!(Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		  Final_state == "2muA")) {
		cerr << "ZZ gg initial state is not supported.\n";
		return 1;
	}
	if (initial_state == "gg") {
		cerr << "ZZ productionless state is not supported.\n";
		return 1;
	}

	if (Final_state == "4e" || Final_state == "4eA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

		// 		if( initial_state=="NO" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_ZZ_SF
		// );
		//
		// 		if( initial_state=="NO" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_ZZ_SFpA );
		//
		// 		if( initial_state=="gg" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_ZZ_SF );
		//
		// 		if( initial_state=="gg" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_ZZ_SFpA );

		if (initial_state == "qq" && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

		if (initial_state == "qq" && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_ZZ_OF
		// );
		//
		// 		if( initial_state=="NO" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_ZZ_OFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_ZZ_OF );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_ZZ_OFpA );

		if (initial_state == "qq" &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_OF, ME_qq_ZZ_UpType_OF);

		if (initial_state == "qq" &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_OFpA, ME_qq_ZZ_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_ZZ_SF
		// );
		//
		// 		if( initial_state=="NO" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_ZZ_SFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_ZZ_SF );
		//
		// 		if( initial_state=="gg" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_ZZ_SFpA );

		if (initial_state == "qq" &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

		if (initial_state == "qq" &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		if (initial_state == "NO" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(false, ME_DY_2l);

		if (initial_state == "NO" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(true, ME_DY_2lpA);
		//
		// 		if( initial_state=="gg" && (Final_state=="2m" ||
		// Final_state=="2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_DY_2l );
		//
		// 		if( initial_state=="gg" && (Final_state=="2mA" ||
		// Final_state=="2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_DY_2lpA );

		if (initial_state == "qq" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_DY_DownType_2l, ME_qq_DY_UpType_2l);

		if (initial_state == "qq" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_DY_DownType_2lpA, ME_qq_DY_UpType_2lpA);
	}

	return 1;
}

/// Z4l Background ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_BKG(string initial_state)
{
	if (initial_state == "NO") {
		cerr << "Z -> 4l gg initial state is not supported.\n";
		return 1;
	}
	if (initial_state == "gg") {
		cerr << "Z -> 4l productionless state is not supported.\n";
		return 1;
	}
	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		cerr << "Z -> 4l to 2 lepton is pointless. Run Drell-Yan (DY) instead "
				"(ZZ-based).\n";
		return 1;
	}

	if (Final_state == "4e" || Final_state == "4eA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

		// 		if( initial_state=="NO" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_BKG_SF );
		//
		// 		if( initial_state=="NO" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_BKG_SFpA );
		//
		// 		if( initial_state=="gg" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_BKG_SF );
		//
		// 		if( initial_state=="gg" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_BKG_SFpA );

		if (initial_state == "qq" && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

		if (initial_state == "qq" && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_SFpA, ME_qq_Z4l_BKG_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_BKG_OF );
		//
		// 		if( initial_state=="NO" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_BKG_OFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_BKG_OF );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_BKG_OFpA );

		if (initial_state == "qq" &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_OF, ME_qq_Z4l_BKG_UpType_OF);

		if (initial_state == "qq" &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_OFpA, ME_qq_Z4l_BKG_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_BKG_SF );
		//
		// 		if( initial_state=="NO" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_BKG_SFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_BKG_SF );
		//
		// 		if( initial_state=="gg" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_BKG_SFpA );

		if (initial_state == "qq" &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

		if (initial_state == "qq" &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_SFpA, ME_qq_Z4l_BKG_UpType_SFpA);
	}

	// 	if( Final_state=="2m" || Final_state=="2mu" || Final_state=="2mA" ||
	// Final_state=="2muA" )
	// 	{
	// 		/// Mass for the muons
	// 		Set_Of_Model_Parameters.set_block_entry( "mass", 13, params_m_mu );
	//
	// 		if( initial_state=="NO" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_Z4l_BKG_2l );
	//
	// 		if( initial_state=="NO" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_Z4l_BKG_2lpA );
	//
	// 		if( initial_state=="gg" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_gg_Z4l_BKG__2l );
	//
	// 		if( initial_state=="gg" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_gg_Z4l_BKG__2lpA );
	//
	// 		if( initial_state=="qq" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_qq_Z4l_BKG_DownType_2l, ME_qq_Z4l_BKG_UpType_2l );
	//
	// 		if( initial_state=="qq" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_qq_Z4l_BKG_DownType_2lpA, ME_qq_Z4l_BKG_UpType_2lpA );
	// 	}

	return 1;
}

/// Z4l Signal ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_SIG(string initial_state)
{
	if (initial_state == "NO") {
		cerr << "Z -> 4l gg initial state is not supported.\n";
		return 1;
	}
	if (initial_state == "gg") {
		cerr << "Z -> 4l productionless state is not supported.\n";
		return 1;
	}
	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		cerr << "Z -> 4l to 2 lepton is pointless. Run Drell-Yan (DY) instead "
				"(ZZ-based).\n";
		return 1;
	}

	if (Final_state == "4e" || Final_state == "4eA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

		// 		if( initial_state=="NO" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_SIG_SF );
		//
		// 		if( initial_state=="NO" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_SIG_SFpA );
		//
		// 		if( initial_state=="gg" && Final_state=="4e" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_SIG_SF );
		//
		// 		if( initial_state=="gg" && Final_state=="4eA" )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_SIG_SFpA );

		if (initial_state == "qq" && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

		if (initial_state == "qq" && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_SFpA, ME_qq_Z4l_SIG_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_SIG_OF );
		//
		// 		if( initial_state=="NO" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_SIG_OFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2m" ||
		// Final_state=="2e2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_SIG_OF );
		//
		// 		if( initial_state=="gg" && (Final_state=="2e2mA" ||
		// Final_state=="2e2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_SIG_OFpA );

		if (initial_state == "qq" &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_OF, ME_qq_Z4l_SIG_UpType_OF);

		if (initial_state == "qq" &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_OFpA, ME_qq_Z4l_SIG_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		// 		if( initial_state=="NO" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( false,
		// ME_Z4l_SIG_SF );
		//
		// 		if( initial_state=="NO" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_NO( true,
		// ME_Z4l_SIG_SFpA );
		//
		// 		if( initial_state=="gg" && (Final_state=="4m" ||
		// Final_state=="4mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_gg_Z4l_SIG_SF );
		//
		// 		if( initial_state=="gg" && (Final_state=="4mA" ||
		// Final_state=="4muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_gg_Z4l_SIG_SFpA );

		if (initial_state == "qq" &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

		if (initial_state == "qq" &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_SFpA, ME_qq_Z4l_SIG_UpType_SFpA);
	}

	// 	if( Final_state=="2m" || Final_state=="2mu" || Final_state=="2mA" ||
	// Final_state=="2muA" )
	// 	{
	// 		/// Mass for the muons
	// 		Set_Of_Model_Parameters.set_block_entry( "mass", 13, params_m_mu );
	//
	// 		if( initial_state=="NO" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( false,
	// ME_Z4l_SIG_2l );
	//
	// 		if( initial_state=="NO" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO( true,
	// ME_Z4l_SIG_2lpA );
	//
	// 		if( initial_state=="gg" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( false,
	// ME_gg_Z4l_SIG__2l );
	//
	// 		if( initial_state=="gg" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg( true,
	// ME_gg_Z4l_SIG__2lpA );
	//
	// 		if( initial_state=="qq" && (Final_state=="2m" || Final_state=="2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( false,
	// ME_qq_Z4l_SIG_DownType_2l, ME_qq_Z4l_SIG_UpType_2l );
	//
	// 		if( initial_state=="qq" && (Final_state=="2mA" ||
	// Final_state=="2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar( true,
	// ME_qq_Z4l_SIG_DownType_2lpA, ME_qq_Z4l_SIG_UpType_2lpA );
	// 	}

	return 1;
}

/// Spin-0 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin0(string initial_state)
{
	if (initial_state == "qq") {
		cerr << "Spin-0 qqbar initial state is redundant, thus not provided.\n";
		return 1;
	}

	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_SFpA);

			if (initial_state == "gg" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_SF);

			if (initial_state == "gg" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_SFpA);

			// 			if( initial_state=="qq" && Final_state=="4e" )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_SF, ME_Signal_qq_Spin0_UpType_SF );
			//
			// 			if( initial_state=="qq" && Final_state=="4eA" )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_SFpA, ME_Signal_qq_Spin0_UpType_SFpA
			// );
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_OFpA);

			if (initial_state == "gg" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_OF);

			if (initial_state == "gg" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_OFpA);

			// 			if( initial_state=="qq" && (Final_state=="2e2m" ||
			// Final_state=="2e2mu") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_OF, ME_Signal_qq_Spin0_UpType_OF );
			//
			// 			if( initial_state=="qq" && (Final_state=="2e2mA" ||
			// Final_state=="2e2muA") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_OFpA, ME_Signal_qq_Spin0_UpType_OFpA
			// );
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_SFpA);

			if (initial_state == "gg" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_SF);

			if (initial_state == "gg" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_SFpA);

			// 			if( initial_state=="qq" && (Final_state=="4m" ||
			// Final_state=="4mu") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_SF, ME_Signal_qq_Spin0_UpType_SF );
			//
			// 			if( initial_state=="qq" && (Final_state=="4mA" ||
			// Final_state=="4muA") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_SFpA, ME_Signal_qq_Spin0_UpType_SFpA
			// );
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_SFpA);

			if (initial_state == "gg" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_SF);

			if (initial_state == "gg" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_SFpA);

			// 			if( initial_state=="qq" && Final_state=="4e" )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_SF,
			// ME_Signal_qq_Spin0_2f_UpType_SF );
			//
			// 			if( initial_state=="qq" && Final_state=="4eA" )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_SFpA,
			// ME_Signal_qq_Spin0_2f_UpType_SFpA );
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_OFpA);

			if (initial_state == "gg" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_OF);

			if (initial_state == "gg" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_OFpA);

			// 			if( initial_state=="qq" && (Final_state=="2e2m" ||
			// Final_state=="2e2mu") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_OF,
			// ME_Signal_qq_Spin0_2f_UpType_OF );
			//
			// 			if( initial_state=="qq" && (Final_state=="2e2mA" ||
			// Final_state=="2e2muA") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_OFpA,
			// ME_Signal_qq_Spin0_2f_UpType_OFpA );
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_SFpA);

			if (initial_state == "gg" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_SF);

			if (initial_state == "gg" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_SFpA);

			// 			if( initial_state=="qq" && (Final_state=="4m" ||
			// Final_state=="4mu") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_SF,
			// ME_Signal_qq_Spin0_2f_UpType_SF );
			//
			// 			if( initial_state=="qq" && (Final_state=="4mA" ||
			// Final_state=="4muA") )
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_SFpA,
			// ME_Signal_qq_Spin0_2f_UpType_SFpA );
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		if (initial_state == "NO" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin0_2l);

		if (initial_state == "NO" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin0_2lpA);

		if (initial_state == "gg" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_gg(
				false, ME_Signal_gg_Spin0_2l);

		if (initial_state == "gg" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_gg(
				true, ME_Signal_gg_Spin0_2lpA);

		// 		if( initial_state=="qq" && (Final_state=="2m" ||
		// Final_state=="2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_qqbar( false,
		// ME_Signal_qq_Spin0_DownType_2l, ME_Signal_qq_Spin0_UpType_2l );

		// 		if( initial_state=="qq" && (Final_state=="2mA" ||
		// Final_state=="2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_qqbar( true,
		// ME_Signal_qq_Spin0_DownType_2lpA, ME_Signal_qq_Spin0_UpType_2lpA );
	}

	return 1;
}

/// Spin-1 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin1(string initial_state)
{
	if (initial_state == "gg") {
		cerr << "Spin-1 gg initial state is not possible, thus not provided.\n";
		return 1;
	}

	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_SFpA);

			// 			if( initial_state=="gg" && Final_state=="4e" )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_SF );
			//
			// 			if( initial_state=="gg" && Final_state=="4eA" )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_SFpA );

			if (initial_state == "qq" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_SF,
					ME_Signal_qq_Spin1_UpType_SF);

			if (initial_state == "qq" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_SFpA,
					ME_Signal_qq_Spin1_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_OFpA);

			//	 		if( initial_state=="gg" && (Final_state=="2e2m" ||
			// Final_state=="2e2mu") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_OF );
			//
			// 			if( initial_state=="gg" && (Final_state=="2e2mA" ||
			// Final_state=="2e2muA") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_OFpA );

			if (initial_state == "qq" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_OF,
					ME_Signal_qq_Spin1_UpType_OF);

			if (initial_state == "qq" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_OFpA,
					ME_Signal_qq_Spin1_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_SFpA);

			// 			if( initial_state=="gg" && (Final_state=="4m" ||
			// Final_state=="4mu") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_SF );
			//
			// 			if( initial_state=="gg" && (Final_state=="4mA" ||
			// Final_state=="4muA") )
			//	 			return Run_MEs_Evaluator_Initial_State_gg(
			//true,
			// ME_Signal_gg_Spin1_SFpA );

			if (initial_state == "qq" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_SF,
					ME_Signal_qq_Spin1_UpType_SF);

			if (initial_state == "qq" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_SFpA,
					ME_Signal_qq_Spin1_UpType_SFpA);
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_SFpA);

			// 			if( initial_state=="gg" && Final_state=="4e" )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_SF );
			//
			// 			if( initial_state=="gg" && Final_state=="4eA" )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_2f_SFpA );

			if (initial_state == "qq" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_SF,
					ME_Signal_qq_Spin1_2f_UpType_SF);

			if (initial_state == "qq" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
					ME_Signal_qq_Spin1_2f_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_OFpA);

			//	 		if( initial_state=="gg" && (Final_state=="2e2m" ||
			// Final_state=="2e2mu") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_OF );
			//
			// 			if( initial_state=="gg" && (Final_state=="2e2mA" ||
			// Final_state=="2e2muA") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_2f_OFpA );

			if (initial_state == "qq" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_OF,
					ME_Signal_qq_Spin1_2f_UpType_OF);

			if (initial_state == "qq" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_OFpA,
					ME_Signal_qq_Spin1_2f_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_SFpA);

			// 			if( initial_state=="gg" && (Final_state=="4m" ||
			// Final_state=="4mu") )
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_SF );
			//
			// 			if( initial_state=="gg" && (Final_state=="4mA" ||
			// Final_state=="4muA") )
			//	 			return Run_MEs_Evaluator_Initial_State_gg(
			//true,
			// ME_Signal_gg_Spin1_2f_SFpA );

			if (initial_state == "qq" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_SF,
					ME_Signal_qq_Spin1_2f_UpType_SF);

			if (initial_state == "qq" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
					ME_Signal_qq_Spin1_2f_UpType_SFpA);
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		if (initial_state == "NO" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin1_2l);

		if (initial_state == "NO" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin1_2lpA);

		// 		if( initial_state=="gg" && (Final_state=="2m" ||
		// Final_state=="2mu") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( false,
		// ME_Signal_gg_Spin1_2l );
		//
		// 		if( initial_state=="gg" && (Final_state=="2mA" ||
		// Final_state=="2muA") )
		// 			return Run_MEs_Evaluator_Initial_State_gg( true,
		// ME_Signal_gg_Spin1_2lpA );

		if (initial_state == "qq" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_Signal_qq_Spin1_DownType_2l,
				ME_Signal_qq_Spin1_UpType_2l);

		if (initial_state == "qq" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_Signal_qq_Spin1_DownType_2lpA,
				ME_Signal_qq_Spin1_UpType_2lpA);
	}

	return 1;
}

/// Spin-2 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin2(string initial_state)
{
	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_SFpA);

			if (initial_state == "gg" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_SF);

			if (initial_state == "gg" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_SFpA);

			if (initial_state == "qq" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_SF,
					ME_Signal_qq_Spin2_UpType_SF);

			if (initial_state == "qq" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_SFpA,
					ME_Signal_qq_Spin2_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_OFpA);

			if (initial_state == "gg" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_OF);

			if (initial_state == "gg" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_OFpA);

			if (initial_state == "qq" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_OF,
					ME_Signal_qq_Spin2_UpType_OF);

			if (initial_state == "qq" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_OFpA,
					ME_Signal_qq_Spin2_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_SFpA);

			if (initial_state == "gg" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_SF);

			if (initial_state == "gg" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_SFpA);

			if (initial_state == "qq" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_SF,
					ME_Signal_qq_Spin2_UpType_SF);

			if (initial_state == "qq" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_SFpA,
					ME_Signal_qq_Spin2_UpType_SFpA);
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_e);

			if (initial_state == "NO" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_SF);

			if (initial_state == "NO" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_SFpA);

			if (initial_state == "gg" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_SF);

			if (initial_state == "gg" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_SFpA);

			if (initial_state == "qq" && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_SF,
					ME_Signal_qq_Spin2_2f_UpType_SF);

			if (initial_state == "qq" && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
					ME_Signal_qq_Spin2_2f_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 11, params_m_e);
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_OF);

			if (initial_state == "NO" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_OFpA);

			if (initial_state == "gg" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_OF);

			if (initial_state == "gg" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_OFpA);

			if (initial_state == "qq" &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_OF,
					ME_Signal_qq_Spin2_2f_UpType_OF);

			if (initial_state == "qq" &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_OFpA,
					ME_Signal_qq_Spin2_2f_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

			if (initial_state == "NO" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_SF);

			if (initial_state == "NO" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_SFpA);

			if (initial_state == "gg" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_SF);

			if (initial_state == "gg" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_SFpA);

			if (initial_state == "qq" &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_SF,
					ME_Signal_qq_Spin2_2f_UpType_SF);

			if (initial_state == "qq" &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
					ME_Signal_qq_Spin2_2f_UpType_SFpA);
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		Set_Of_Model_Parameters.set_block_entry("mass", 13, params_m_mu);

		if (initial_state == "NO" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin2_2l);

		if (initial_state == "NO" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin2_2lpA);

		if (initial_state == "gg" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_gg(
				false, ME_Signal_gg_Spin2_2l);

		if (initial_state == "gg" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_gg(
				true, ME_Signal_gg_Spin2_2lpA);

		if (initial_state == "qq" &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_Signal_qq_Spin2_DownType_2l,
				ME_Signal_qq_Spin2_UpType_2l);

		if (initial_state == "qq" &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_Signal_qq_Spin2_DownType_2lpA,
				ME_Signal_qq_Spin2_UpType_2lpA);
	}

	return 1;
}

template <class Generic_MEKD_ME>
int MEKD::Run_MEs_Evaluator_Initial_State_NO(bool photon,
											 Generic_MEKD_ME &Generic_ME)
{
	Signal_ME = 0;

	/// No initial state block
	for (unsigned int count = 0; count < 4; count++)
		buffer_p[count] = p_set[0][count];

	if (!photon) {
		p_set[0][0] = p_set[2][0] + p_set[3][0] + p_set[4][0] + p_set[5][0];
		p_set[0][1] = p_set[2][1] + p_set[3][1] + p_set[4][1] + p_set[5][1];
		p_set[0][2] = p_set[2][2] + p_set[3][2] + p_set[4][2] + p_set[5][2];
		p_set[0][3] = p_set[2][3] + p_set[3][3] + p_set[4][3] + p_set[5][3];

		buffer = p_set[1];
		for (unsigned int count = 0; count < 4; count++)
			p_set[count + 1] = p_set[count + 2];
		p_set[5] = buffer;
	} else {
		p_set[0][0] =
			p_set[2][0] + p_set[3][0] + p_set[4][0] + p_set[5][0] + p_set[6][0];
		p_set[0][1] =
			p_set[2][1] + p_set[3][1] + p_set[4][1] + p_set[5][1] + p_set[6][1];
		p_set[0][2] =
			p_set[2][2] + p_set[3][2] + p_set[4][2] + p_set[5][2] + p_set[6][2];
		p_set[0][3] =
			p_set[2][3] + p_set[3][3] + p_set[4][3] + p_set[5][3] + p_set[6][3];

		buffer = p_set[1];
		for (unsigned int count = 0; count < 5; count++)
			p_set[count + 1] = p_set[count + 2];
		p_set[6] = buffer;
	}

	Generic_ME.updateProc(Set_Of_Model_Parameters);
	Generic_ME.setMomenta(p_set);
	Generic_ME.sigmaKin();
	buffer = const_cast<double *>(Generic_ME.getMatrixElements());

	Signal_ME = buffer[0];

	if (!photon) {
		buffer = p_set[5];
		for (unsigned int count = 4; count > 0; count--)
			p_set[count + 1] = p_set[count];
		p_set[1] = buffer;
	} else {
		buffer = p_set[6];
		for (unsigned int count = 5; count > 0; count--)
			p_set[count + 1] = p_set[count];
		p_set[1] = buffer;
	}

	for (unsigned int count = 0; count < 4; count++)
		p_set[0][count] = buffer_p[count];

	return 0;
}

template <class Generic_MEKD_ME>
int MEKD::Run_MEs_Evaluator_Initial_State_gg(bool photon,
											 Generic_MEKD_ME &Generic_ME)
{
	Signal_ME = 0;

	/// gg block
	p_set[0][3] = p_set[0][0];
	p_set[1][3] = -p_set[1][0];

	Generic_ME.updateProc(Set_Of_Model_Parameters);
	Generic_ME.setMomenta(p_set);
	Generic_ME.sigmaKin();
	buffer = const_cast<double *>(Generic_ME.getMatrixElements());

	if (flag.Use_PDF_w_pT0) {
		Signal_ME = pdfreader(21, PDFx1, Mass_4l) *
					pdfreader(21, PDFx2, Mass_4l) * buffer[0];
	} else
		Signal_ME = buffer[0];

	return 0;
}

template <class Generic_MEKD_ME_s, class Generic_MEKD_ME_c>
int MEKD::Run_MEs_Evaluator_Initial_State_qqbar(bool photon,
												Generic_MEKD_ME_s &Generic_ME_s,
												Generic_MEKD_ME_c &Generic_ME_c)
{
	Signal_ME = 0;

	/// Down quark block. Down type (s-like)
	if (parton_coeff_d != 0) {
		Set_Of_Model_Parameters.set_block_entry("mass", 3, params_m_d);
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 15,
		// params_rhod01
		// );
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 16,
		// params_rhod02
		// );
		Set_Of_Model_Parameters.set_block_entry("vec", 15, params_rhod11);
		Set_Of_Model_Parameters.set_block_entry("vec", 16, params_rhod12);
		Set_Of_Model_Parameters.set_block_entry("vec", 17, params_rhod13);
		Set_Of_Model_Parameters.set_block_entry("vec", 18, params_rhod14);
		Set_Of_Model_Parameters.set_block_entry("gravity", 33, params_rhod21);
		Set_Of_Model_Parameters.set_block_entry("gravity", 34, params_rhod22);
		Set_Of_Model_Parameters.set_block_entry("gravity", 35, params_rhod23);
		Set_Of_Model_Parameters.set_block_entry("gravity", 36, params_rhod24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_d * params_m_d);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_d * params_m_d);

		Generic_ME_s.updateProc(Set_Of_Model_Parameters);
		Generic_ME_s.setMomenta(p_set);
		Generic_ME_s.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_s.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			parton_coeff_d =
				pdfreader(1, PDFx1, Mass_4l) * pdfreader(-1, PDFx2, Mass_4l);
			Signal_ME = parton_coeff_d * buffer[0];
			parton_coeff_d =
				pdfreader(-1, PDFx1, Mass_4l) * pdfreader(1, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_d * buffer[1];
		} else
			Signal_ME = parton_coeff_d * (buffer[0] + buffer[1]);
	}

	/// Strange quark block. Down type (s-like)
	if (parton_coeff_s != 0) {
		Set_Of_Model_Parameters.set_block_entry("mass", 3, params_m_s);
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 15,
		// params_rhos01
		// );
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 16,
		// params_rhos02
		// );
		Set_Of_Model_Parameters.set_block_entry("vec", 15, params_rhos11);
		Set_Of_Model_Parameters.set_block_entry("vec", 16, params_rhos12);
		Set_Of_Model_Parameters.set_block_entry("vec", 17, params_rhos13);
		Set_Of_Model_Parameters.set_block_entry("vec", 18, params_rhos14);
		Set_Of_Model_Parameters.set_block_entry("gravity", 33, params_rhos21);
		Set_Of_Model_Parameters.set_block_entry("gravity", 34, params_rhos22);
		Set_Of_Model_Parameters.set_block_entry("gravity", 35, params_rhos23);
		Set_Of_Model_Parameters.set_block_entry("gravity", 36, params_rhos24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_s * params_m_s);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_s * params_m_s);

		Generic_ME_s.updateProc(Set_Of_Model_Parameters);
		Generic_ME_s.setMomenta(p_set);
		Generic_ME_s.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_s.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			parton_coeff_s =
				pdfreader(3, PDFx1, Mass_4l) * pdfreader(-3, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_s * buffer[0];
			parton_coeff_s =
				pdfreader(-3, PDFx1, Mass_4l) * pdfreader(3, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_s * buffer[1];
		} else
			Signal_ME += parton_coeff_s * (buffer[0] + buffer[1]);
	}

	/// Up quark block. Up type (c-like)
	if (parton_coeff_u != 0) {
		Set_Of_Model_Parameters.set_block_entry("mass", 4, params_m_u);
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 11,
		// params_rhou01
		// );
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 12,
		// params_rhou02
		// );
		Set_Of_Model_Parameters.set_block_entry("vec", 7, params_rhou11);
		Set_Of_Model_Parameters.set_block_entry("vec", 8, params_rhou12);
		Set_Of_Model_Parameters.set_block_entry("vec", 9, params_rhou13);
		Set_Of_Model_Parameters.set_block_entry("vec", 10, params_rhou14);
		Set_Of_Model_Parameters.set_block_entry("gravity", 25, params_rhou21);
		Set_Of_Model_Parameters.set_block_entry("gravity", 26, params_rhou22);
		Set_Of_Model_Parameters.set_block_entry("gravity", 27, params_rhou23);
		Set_Of_Model_Parameters.set_block_entry("gravity", 28, params_rhou24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_u * params_m_u);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_u * params_m_u);

		Generic_ME_c.updateProc(Set_Of_Model_Parameters);
		Generic_ME_c.setMomenta(p_set);
		Generic_ME_c.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_c.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			parton_coeff_u =
				pdfreader(2, PDFx1, Mass_4l) * pdfreader(-2, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_u * buffer[0];
			parton_coeff_u =
				pdfreader(-2, PDFx1, Mass_4l) * pdfreader(2, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_u * buffer[1];
		} else
			Signal_ME += parton_coeff_u * (buffer[0] + buffer[1]);
	}

	/// Charm quark block. Up type (c-like)
	if (parton_coeff_c != 0) {
		Set_Of_Model_Parameters.set_block_entry("mass", 4, params_m_c);
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 11,
		// params_rhoc01
		// );
		// 		Set_Of_Model_Parameters.set_block_entry( "heff", 12,
		// params_rhoc02
		// );
		Set_Of_Model_Parameters.set_block_entry("vec", 7, params_rhoc11);
		Set_Of_Model_Parameters.set_block_entry("vec", 8, params_rhoc12);
		Set_Of_Model_Parameters.set_block_entry("vec", 9, params_rhoc13);
		Set_Of_Model_Parameters.set_block_entry("vec", 10, params_rhoc14);
		Set_Of_Model_Parameters.set_block_entry("gravity", 25, params_rhoc21);
		Set_Of_Model_Parameters.set_block_entry("gravity", 26, params_rhoc22);
		Set_Of_Model_Parameters.set_block_entry("gravity", 27, params_rhoc23);
		Set_Of_Model_Parameters.set_block_entry("gravity", 28, params_rhoc24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_c * params_m_c);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_c * params_m_c);

		Generic_ME_c.updateProc(Set_Of_Model_Parameters);
		Generic_ME_c.setMomenta(p_set);
		Generic_ME_c.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_c.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			parton_coeff_c =
				pdfreader(4, PDFx1, Mass_4l) * pdfreader(-4, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_c * buffer[0];
			parton_coeff_c =
				pdfreader(-4, PDFx1, Mass_4l) * pdfreader(4, PDFx2, Mass_4l);
			Signal_ME += parton_coeff_c * buffer[1];
		} else
			Signal_ME += parton_coeff_c * (buffer[0] + buffer[1]);
	}

	if (flag.Use_mZ4l_eq_m4l)
		Set_Of_Model_Parameters.set_block_entry(
			"mass", 23, params_m_Z); // return to real mass. Used in Z -> 4l

	return 0;
}

/// end of namespace
}

#endif
////////////////////////////////
/// END OF MEKD_RunMEs.cpp   ///
////////////////////////////////