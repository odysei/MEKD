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
int MEKD::Run_ME_Configurator_BKG_ZZ(const production_types IS)
{
	return Run_ME_Dispatcher_BKG_ZZ(IS);
}

/// Z4l Background processes (t channel)
int MEKD::Run_ME_Configurator_Z4l_BKG(const production_types IS)
{
	if (flag.Use_mZ4l_eq_m4l)
		params_MG.set_block_entry("mass", 23, Mass_4l);
	return Run_ME_Dispatcher_Z4l_BKG(IS);
}

/// Z4l Signal processes (s channel)
int MEKD::Run_ME_Configurator_Z4l_SIG(const production_types IS)
{
	if (flag.Use_mZ4l_eq_m4l)
		params_MG.set_block_entry("mass", 23, Mass_4l);
	return Run_ME_Dispatcher_Z4l_SIG(IS);
}

int MEKD::Run_ME_Configurator_Custom()
{
	if ((error_value = Run_ME_Dispatcher_SIG_Spin0(prod_gg)) != 0)
		return error_value;
	buffer_Custom = Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin1(prod_qq)) != 0)
		return error_value;
	buffer_Custom += Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin2(prod_gg)) != 0)
		return error_value;
	buffer_Custom += Signal_ME;
	if ((error_value = Run_ME_Dispatcher_SIG_Spin2(prod_qq)) != 0)
		return error_value;
	Signal_ME += buffer_Custom;

	return 0;
}

int MEKD::Run_ME_Configurator_CPPProcess(const production_types IS)
{
	return Run_ME_Dispatcher_CPPProcess(IS);
}

////////////////////////////////////
/// Spin-0 resonances start here ///
////////////////////////////////////

/// A SM Higgs
int MEKD::Run_ME_Configurator_Spin0Pm(const production_types IS)
{
	Predefined_Model = true;
	Mixing_Coefficients_Spin0_internal[0] = complex<double>(1, 0); // same 2l
	Mixing_Coefficients_Spin0_internal[1] = complex<double>(0, 0); // same 2l
	Mixing_Coefficients_Spin0_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin0_internal[3] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin0_internal[0] = complex<double>(1, 0);
		Mixing_Coefficients_Spin0_internal[1] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin0(IS);
}

/// A pseudoscalar
int MEKD::Run_ME_Configurator_Spin0M(const production_types IS)
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

	return Run_ME_Configurator_Spin0(IS);
}

/// A scalar with higher-order couplings
int MEKD::Run_ME_Configurator_Spin0Ph(const production_types IS)
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

	return Run_ME_Configurator_Spin0(IS);
}

////////////////////////////////////
/// Spin-1 resonances start here ///
////////////////////////////////////

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1M(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin1_internal[0] = complex<double>(1, 0);	// same 2l
	Mixing_Coefficients_Spin1_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[3] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin1_internal[4] = complex<double>(1, 0);
	Mixing_Coefficients_Spin1_internal[5] = complex<double>(0, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin1_internal[6] = complex<double>(0, 0);
		Mixing_Coefficients_Spin1_internal[7] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin1(IS);
}

/// A vector default configuration
int MEKD::Run_ME_Configurator_Spin1P(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin1_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[1] = complex<double>(1, 0);	// same 2l
	Mixing_Coefficients_Spin1_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[3] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin1_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin1_internal[5] = complex<double>(1, 0);

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA" || Resonance_decay_mode == "2l") {
		Mixing_Coefficients_Spin1_internal[6] = complex<double>(0, 0);
		Mixing_Coefficients_Spin1_internal[7] = complex<double>(0, 0);
	}

	return Run_ME_Configurator_Spin1(IS);
}

////////////////////////////////////
/// Spin-2 resonances start here ///
////////////////////////////////////

/// A minimal-coupling KK graviton
int MEKD::Run_ME_Configurator_Spin2Pm(const production_types IS)
{
	Predefined_Model = true;
	// Production
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(-1, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[3] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Pb(const production_types IS)
{
	Predefined_Model = true;
	// Production
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph2(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph3(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[2] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph6(const production_types IS)
{
	Predefined_Model = true;
	// Production
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Ph7(const production_types IS)
{
	Predefined_Model = true;
	// Production
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh9(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

///
int MEKD::Run_ME_Configurator_Spin2Mh10(const production_types IS)
{
	Predefined_Model = true;
	// Production
	Mixing_Coefficients_Spin2_internal[0] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[1] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[2] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[3] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[4] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[5] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[6] = complex<double>(0, 0);
	if (IS == prod_gg)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(1, 0);
	Mixing_Coefficients_Spin2_internal[8] = complex<double>(0, 0);
	Mixing_Coefficients_Spin2_internal[9] = complex<double>(0, 0);
	// Decay
	Mixing_Coefficients_Spin2_internal[10] = complex<double>(0, 0);
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

	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[0] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[1] = complex<double>(1, 0);
	if (IS == prod_qq)
		Mixing_Coefficients_Spin2_internal[7] = complex<double>(0, 0);

	return Run_ME_Configurator_Spin2(IS, params_MG);
}

/// A generic spin-0 resonance handler
int MEKD::Run_ME_Configurator_Spin0(const production_types IS)
{
	// local copy for stack
	double mH = param.Higgs_mass;
	double mZ = params_m_Z;
	double M = Mass_4l;	// system's invariant mass
	double hZZ = hZZ_coupling;
	double lgg;	// lambda hgg
	complex<double> *c;	// mixing coefficients
	
	if (Predefined_Model) {
		c = Mixing_Coefficients_Spin0_internal;
		Predefined_Model = false;
	} else
		c = Mixing_Coefficients_Spin0;

	if (flag.Use_mh_eq_m4l) {
		params_MG.set_block_entry("mass", 9000006, M);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				params_MG.set_block_entry("decay", 9000006, static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M)));
			else
				params_MG.set_block_entry("decay", 9000006, param.Higgs_width);
		} else
			params_MG.set_block_entry("decay", 9000006, 1);

		lgg = LmbdGG(M);
	} else {
		params_MG.set_block_entry("mass", 9000006, mH);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				params_MG.set_block_entry("decay", 9000006, static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M)));
			else
				params_MG.set_block_entry("decay", 9000006, param.Higgs_width);
		} else
			params_MG.set_block_entry("decay", 9000006, 1);

		lgg = LmbdGG(mH);
	}

	if (flag.Vary_signal_couplings) {
		// gg
		if (flag.Fix_Spin0_Production) {
			params_MG.set_block_entry("heff", 1, complex<double>(0, 0));
			params_MG.set_block_entry("heff", 2, complex<double>(4 * lgg, 0)); // Spin0Pm
			params_MG.set_block_entry("heff", 3, complex<double>(0, 0));
			params_MG.set_block_entry("heff", 4, complex<double>(0, 0)); // Spin0M
		} else {
			params_MG.set_block_entry("heff", 1, complex<double>(0, 0));
			params_MG.set_block_entry("heff", 2, (c[0] + c[1] + c[2]) * complex<double>(4 * lgg, 0)); // Spin0P
			params_MG.set_block_entry("heff", 3, complex<double>(0, 0));
			params_MG.set_block_entry("heff", 4, c[3] * complex<double>(4 * lgg, 0)); // Spin0M
		}

		// Decay to ZZ
		if (flag.Use_mh_eq_m4l) {
			params_MG.set_block_entry("heff", 5, c[0] * complex<double>(hZZ, 0)); // Spin0Pm
			params_MG.set_block_entry("heff", 6, c[1] * complex<double>(hZZ / mZ / mZ, 0)); // Spin0Ph
			params_MG.set_block_entry("heff", 7, c[2] * complex<double>(hZZ / mZ / mZ / M / M, 0)); // Spin0Ph+
			params_MG.set_block_entry("heff", 8, c[3] * complex<double>(hZZ / mZ / mZ, 0)); // Spin0M
		} else {
			params_MG.set_block_entry("heff", 5, c[0] * complex<double>(hZZ, 0)); // Spin0Pm
			params_MG.set_block_entry("heff", 6, c[1] * complex<double>(hZZ / mZ / mZ, 0)); // Spin0Ph
			params_MG.set_block_entry("heff", 7, c[2] * complex<double>(hZZ / mZ / mZ / mH / mH, 0)); // Spin0Ph+
			params_MG.set_block_entry("heff", 8, c[3] * complex<double>(hZZ / mZ / mZ, 0)); // Spin0M
		}

		// Decay to 2l (or 2mu in 2f)
		params_MG.set_block_entry("heff", 19, c[0] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("heff", 20, c[1] * complex<double>(4.291210e-04, 0));

		// Decay to 2e (2f)
		params_MG.set_block_entry("heff", 21, c[0] * complex<double>(4.291210e-04, 0)); // for Hee should be 2.075371e-06
		params_MG.set_block_entry("heff", 22, c[1] * complex<double>(4.291210e-04, 0));
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

	return Run_ME_Dispatcher_SIG_Spin0(IS);
}

/// A generic spin-1 resonance handler
int MEKD::Run_ME_Configurator_Spin1(const production_types IS)
{
	// local copy for stack
	double mH = param.Higgs_mass;
	double mZ = params_m_Z;
	double M = Mass_4l;	// system's invariant mass
	double hZZ = hZZ_coupling;
	double lgg;	// lambda hgg
	complex<double> *c;	// mixing coefficients
	
	if (Predefined_Model) {
		c = Mixing_Coefficients_Spin1_internal;
		Predefined_Model = false;
	} else
		c = Mixing_Coefficients_Spin1;

	if (flag.Use_mh_eq_m4l) {
		params_MG.set_block_entry("mass", 300, M);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				params_MG.set_block_entry("decay", 300, static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M)));
			else
				params_MG.set_block_entry("decay", 300, param.Higgs_width);
		} else
			params_MG.set_block_entry("decay", 300, 1);

		lgg = LmbdGG(M);
	} else {
		params_MG.set_block_entry("mass", 300, mH);

		if (flag.Use_Higgs_width) {
			if (flag.Vary_resonance_width)
				params_MG.set_block_entry("decay", 300, static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M)));
			else
				params_MG.set_block_entry("decay", 300, param.Higgs_width);
		} else
			params_MG.set_block_entry("decay", 300, 1);

		lgg = LmbdGG(mH);
	}

	if (flag.Vary_signal_couplings) {
		// qq
		if (flag.Fix_Spin1_Production) {
			params_rhod11 = complex<double>(sqrt(1 / 2) * lgg * v_expectation, 0);
			params_rhos11 = complex<double>(sqrt(1 / 2) * lgg * v_expectation, 0);
			params_rhob11 = complex<double>(sqrt(1 / 2) * lgg * v_expectation, 0);
			params_rhou11 = complex<double>(sqrt(1 / 2) * lgg * v_expectation, 0);
			params_rhoc11 = complex<double>(sqrt(1 / 2) * lgg * v_expectation, 0);
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
			params_rhod11 = c[0] * complex<double>(lgg * v_expectation, 0);
			params_rhos11 = c[0] * complex<double>(lgg * v_expectation, 0);
			params_rhob11 = c[0] * complex<double>(lgg * v_expectation, 0);
			params_rhou11 = c[0] * complex<double>(lgg * v_expectation, 0);
			params_rhoc11 = c[0] * complex<double>(lgg * v_expectation, 0);
			params_rhod12 = c[1] * complex<double>(lgg * v_expectation, 0);
			params_rhos12 = c[1] * complex<double>(lgg * v_expectation, 0);
			params_rhob12 = c[1] * complex<double>(lgg * v_expectation, 0);
			params_rhou12 = c[1] * complex<double>(lgg * v_expectation, 0);
			params_rhoc12 = c[1] * complex<double>(lgg * v_expectation, 0);
			params_rhod13 = c[2] * complex<double>(lgg * v_expectation, 0);
			params_rhos13 = c[2] * complex<double>(lgg * v_expectation, 0);
			params_rhob13 = c[2] * complex<double>(lgg * v_expectation, 0);
			params_rhou13 = c[2] * complex<double>(lgg * v_expectation, 0);
			params_rhoc13 = c[2] * complex<double>(lgg * v_expectation, 0);
			params_rhod14 = c[3] * complex<double>(lgg * v_expectation, 0);
			params_rhos14 = c[3] * complex<double>(lgg * v_expectation, 0);
			params_rhob14 = c[3] * complex<double>(lgg * v_expectation, 0);
			params_rhou14 = c[3] * complex<double>(lgg * v_expectation, 0);
			params_rhoc14 = c[3] * complex<double>(lgg * v_expectation, 0);
		}

		// Decay to ZZ
		params_MG.set_block_entry("vec", 1, c[4] * complex<double>(hZZ / 2 / mZ, 0));
		params_MG.set_block_entry("vec", 2, c[5] * complex<double>(hZZ / 4 / mZ, 0));

		// Decay to 2l (or 2mu in 2f)
		params_MG.set_block_entry("vec", 23, c[4] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("vec", 24, c[5] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("vec", 25, c[6] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("vec", 26, c[7] * complex<double>(4.291210e-04, 0));

		// Decay to 2e (2f)
		params_MG.set_block_entry("vec", 27, c[4] * complex<double>(4.291210e-04, 0)); // for Hee should be 2.075371e-06
		params_MG.set_block_entry("vec", 28, c[5] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("vec", 29, c[6] * complex<double>(4.291210e-04, 0));
		params_MG.set_block_entry("vec", 30, c[7] * complex<double>(4.291210e-04, 0));
	}

	return Run_ME_Dispatcher_SIG_Spin1(IS);
}

/// A generic spin-2 resonance handler
int MEKD::Run_ME_Configurator_Spin2(const production_types IS,
									SLHAReader_MEKD &par_MG)
{
	// local copy for stack
	double mH = param.Higgs_mass;
	double mZ = params_m_Z;
	double M = Mass_4l;	// system's invariant mass
	double wH;
	double hZZ = hZZ_coupling;
	double lgg;	// lambda hgg
	complex<double> *c;	// mixing coefficients
	
	if (Predefined_Model) {
		c = Mixing_Coefficients_Spin2_internal;
		Predefined_Model = false;
	} else
		c = Mixing_Coefficients_Spin2;

	if (flag.Use_mh_eq_m4l) {
		par_MG.set_block_entry("mass", 9000007, M);

		if (flag.Use_Higgs_width && flag.Vary_resonance_width)
			wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(M));
		
		lgg = LmbdGG(M);
	} else {
		par_MG.set_block_entry("mass", 9000007, mH);

		if (flag.Use_Higgs_width && flag.Vary_resonance_width)
			wH = static_cast<double>(MEKD_CalcHEP_Extra::Higgs_width(mH));
		
		lgg = LmbdGG(mH);
	}
	
	if (flag.Use_Higgs_width) {
		if (!flag.Vary_resonance_width)
			wH = param.Higgs_width;
	} else
		wH = 1;
	par_MG.set_block_entry("decay", 9000007, wH);

	if (flag.Vary_signal_couplings) {
		if (flag.Use_mh_eq_m4l) {
			Run_ME_Configurator_Spin2_produ(par_MG, c, M, lgg);
			Run_ME_Configurator_Spin2_decay(par_MG, c, mZ, M, hZZ);
		} else {
			Run_ME_Configurator_Spin2_decay(par_MG, c, mZ, mH, hZZ);
			Run_ME_Configurator_Spin2_produ(par_MG, c, mH, lgg);
		}
	}

	return Run_ME_Dispatcher_SIG_Spin2(IS);
}

void MEKD::Run_ME_Configurator_Spin2_produ(SLHAReader_MEKD &par_MG,
										   const complex<double> *c,
										   const double &Mi,
										   const double &lgg)
{
	// gg
	par_MG.set_block_entry("gravity", 1, c[0] * complex<double>(8.0 * lgg, 0)); // 8 flavors
	par_MG.set_block_entry("gravity", 2, c[1] * complex<double>(8.0 * lgg / Mi / Mi, 0));
	par_MG.set_block_entry("gravity", 3, c[2] * complex<double>(8.0 * lgg / Mi / Mi, 0));
	par_MG.set_block_entry("gravity", 4, c[3] * complex<double>(8.0 * lgg / Mi / Mi, 0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
	par_MG.set_block_entry("gravity", 5, c[4] * complex<double>(8.0 * lgg * Mi * Mi, 0));
	par_MG.set_block_entry("gravity", 6, c[5] * complex<double>(8.0 * lgg / Mi / Mi, 0));
	par_MG.set_block_entry("gravity", 7, c[6] * complex<double>(8.0 * lgg, 0));
	par_MG.set_block_entry("gravity", 8, c[7] * complex<double>(8.0 * lgg / Mi / Mi, 0)); // old dummy scale factor a_s(100 GeV)^2/2Pi/m4l
	par_MG.set_block_entry("gravity", 9, c[8] * complex<double>(8.0 * lgg, 0));
	par_MG.set_block_entry("gravity", 10, c[9] * complex<double>(8.0 * lgg / Mi / Mi, 0));

	// qq
	params_rhod21 = c[0] * complex<double>(lgg, 0);
	params_rhos21 = c[0] * complex<double>(lgg, 0);
	params_rhob21 = c[0] * complex<double>(lgg, 0);
	params_rhou21 = c[0] * complex<double>(lgg, 0);
	params_rhoc21 = c[0] * complex<double>(lgg, 0);
	params_rhod22 = c[1] * complex<double>(lgg, 0);
	params_rhos22 = c[1] * complex<double>(lgg, 0);
	params_rhob22 = c[1] * complex<double>(lgg, 0);
	params_rhou22 = c[1] * complex<double>(lgg, 0);
	params_rhoc22 = c[1] * complex<double>(lgg, 0);
	params_rhod23 = c[2] * complex<double>(lgg, 0);
	params_rhos23 = c[2] * complex<double>(lgg, 0);
	params_rhob23 = c[2] * complex<double>(lgg, 0);
	params_rhou23 = c[2] * complex<double>(lgg, 0);
	params_rhoc23 = c[2] * complex<double>(lgg, 0);
	params_rhod24 = c[3] * complex<double>(lgg, 0);
	params_rhos24 = c[3] * complex<double>(lgg, 0);
	params_rhob24 = c[3] * complex<double>(lgg, 0);
	params_rhou24 = c[3] * complex<double>(lgg, 0);
	params_rhoc24 = c[3] * complex<double>(lgg, 0);
}

void MEKD::Run_ME_Configurator_Spin2_decay(SLHAReader_MEKD &par_MG,
										   const complex<double> *c,
										   const double &mZ, const double &Mi,
										   const double &hZZ)
{
	// Decay to ZZ
	par_MG.set_block_entry("gravity", 11, c[10] * complex<double>(hZZ / 2 / mZ / mZ / sqrt(2), 0));
	par_MG.set_block_entry("gravity", 12, c[11] * complex<double>(hZZ / 2 / mZ / mZ / Mi / Mi, 0));
	par_MG.set_block_entry("gravity", 13, c[12] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
	par_MG.set_block_entry("gravity", 14, c[13] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
	par_MG.set_block_entry("gravity", 15, c[14] * complex<double>(hZZ / 2 / sqrt(2), 0));
	par_MG.set_block_entry("gravity", 16, c[15] * complex<double>(hZZ / 2 / mZ / Mi, 0));
	par_MG.set_block_entry("gravity", 17, c[16] * complex<double>(hZZ / 2 / mZ / mZ, 0));
	par_MG.set_block_entry("gravity", 18, c[17] * complex<double>(hZZ / 2 / mZ / mZ / mZ, 0)); // or /mZ^4?
	par_MG.set_block_entry("gravity", 19, c[18] * complex<double>(hZZ / 2 / mZ / Mi, 0));
	par_MG.set_block_entry("gravity", 20, c[19] * complex<double>(hZZ / 2 / mZ / mZ / Mi / Mi, 0));

	// Decay to 2l (or 2mu in 2f)
	par_MG.set_block_entry("gravity", 41, c[10] * complex<double>(4.291210e-04, 0));
	par_MG.set_block_entry("gravity", 42, c[11] * complex<double>(4.291210e-04, 0));
	par_MG.set_block_entry("gravity", 43, c[12] * complex<double>(4.291210e-04, 0));
	par_MG.set_block_entry("gravity", 44, c[13] * complex<double>(4.291210e-04, 0));

	// Decay to 2e (2f)
	par_MG.set_block_entry("gravity", 45, c[10] * complex<double>(4.291210e-04, 0)); // for Hee should be 2.075371e-06
	par_MG.set_block_entry("gravity", 46, c[11] * complex<double>(4.291210e-04, 0));
	par_MG.set_block_entry("gravity", 47, c[12] * complex<double>(4.291210e-04, 0));
	par_MG.set_block_entry("gravity", 48, c[13] * complex<double>(4.291210e-04, 0));
}

/// ME_RAW (RAW MG5_aMC ME) dispatcher
int MEKD::Run_ME_Dispatcher_CPPProcess(const production_types IS)
{
	/*
	if( Resonance_decay_mode == "ZZ") {
		if(Final_state == "4e" || Final_state == "4eA") {
	// 		/// Common mass for the same-flavor leptons
	// 			params_MG.set_block_entry("mass", 13, params_m_e);
	
			if(IS==prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	
		if( Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
	// 			/// Common mass for the opposite-flavor leptons
	// 			params_MG.set_block_entry("mass", 11, params_m_e);
	// 			params_MG.set_block_entry("mass", 13, params_m_mu);
	
			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	
		if( Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
	// 			/// Common mass for the same-flavor leptons
	// 			params_MG.set_block_entry("mass", 13, params_m_mu);
	
			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA")
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	}
	
	if( Resonance_decay_mode == "2l") {
		if( Final_state == "4e" || Final_state == "4eA") {
	// 			/// Common mass for the same-flavor leptons
	// 			params_MG.set_block_entry("mass", 13, params_m_e);
	
			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	
		if( Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
	// 			/// Common mass for the opposite-flavor leptons
	// 			params_MG.set_block_entry("mass", 11, params_m_e);
	// 			params_MG.set_block_entry("mass", 13, params_m_mu);
	
			if (IS == prod_no &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	
		if( Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
	// 			/// Common mass for the same-flavor leptons
	// 			params_MG.set_block_entry("mass", 13, params_m_mu);
	
			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
															 ME_RAW);
		}
	}
	
	if(Final_state == "2m" || Final_state == "2mu" ||
		Final_state == "2mA" || Final_state == "2muA") {
	// 		/// Mass for the muons
	// 		params_MG.set_block_entry("mass", 13, params_m_mu);
	
		if (IS == prod_no &&
			(Final_state == "2m" || Final_state == "2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(false, ME_RAW);
	
		if (IS == prod_no &&
			(Final_state == "2mA" || Final_state == "2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_RAW);
	
		if (IS == prod_gg &&
			(Final_state == "2m" || Final_state == "2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(false, ME_RAW);
	
		if (IS == prod_gg &&
			(Final_state == "2mA" || Final_state == "2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(true, ME_RAW);
	
		if (IS == prod_qq &&
			(Final_state == "2m" || Final_state == "2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(false, ME_RAW,
															 ME_RAW);
	
		if (IS == prod_qq &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(true, ME_RAW,
														 ME_RAW);
	}
	*/

	return 1;
}

/// ZZ and DY ME dispatcher
int MEKD::Run_ME_Dispatcher_BKG_ZZ(const production_types IS)
{
	if (IS == prod_no &&
		!(Final_state == "2m" || Final_state == "2mu" ||
		Final_state == "2mA" || Final_state == "2muA")) {
		cerr << "ZZ gg initial state is not supported.\n";
		return 1;
	}
	if (IS == prod_gg) {
		cerr << "ZZ productionless state is not supported.\n";
		return 1;
	}

	if (Final_state == "4e" || Final_state == "4eA") {
		/// Common mass for the same-flavor leptons
		params_MG.set_block_entry("mass", 13, params_m_e);
		/*
		if (IS == prod_no && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_NO(false, ME_ZZ_SF);
		
		if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(true, ME_ZZ_SFpA);
		
		if (IS == prod_gg && Final_state == "4e")
					return Run_MEs_Evaluator_Initial_State_gg(false,
															  ME_gg_ZZ_SF);
		
		if (IS == prod_gg && Final_state == "4eA")
					return Run_MEs_Evaluator_Initial_State_gg(true,
															  ME_gg_ZZ_SFpA);
		*/

		if (IS == prod_qq && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

		if (IS == prod_qq && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		params_MG.set_block_entry("mass", 11, params_m_e);
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_ZZ_OF
		//);
		//
		// 		if (IS == prod_no && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_ZZ_OFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_ZZ_OF);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_ZZ_OFpA);

		if (IS == prod_qq &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_OF, ME_qq_ZZ_UpType_OF);

		if (IS == prod_qq &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_OFpA, ME_qq_ZZ_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_ZZ_SF
		//);
		//
		// 		if (IS == prod_no && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_ZZ_SFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_ZZ_SF);
		//
		// 		if (IS == prod_gg && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_ZZ_SFpA);

		if (IS == prod_qq &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_ZZ_DownType_SF, ME_qq_ZZ_UpType_SF);

		if (IS == prod_qq &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_ZZ_DownType_SFpA, ME_qq_ZZ_UpType_SFpA);
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		if (IS == prod_no &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(false, ME_DY_2l);

		if (IS == prod_no &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(true, ME_DY_2lpA);
		//
		// 		if (IS == prod_gg && (Final_state == "2m" ||
		// Final_state == "2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_DY_2l);
		//
		// 		if (IS == prod_gg && (Final_state == "2mA" ||
		// Final_state == "2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_DY_2lpA);

		if (IS == prod_qq &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_DY_DownType_2l, ME_qq_DY_UpType_2l);

		if (IS == prod_qq &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_DY_DownType_2lpA, ME_qq_DY_UpType_2lpA);
	}

	return 1;
}

/// Z4l Background ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_BKG(const production_types IS)
{
	if (IS == prod_no) {
		cerr << "Z -> 4l gg initial state is not supported.\n";
		return 1;
	}
	if (IS == prod_gg) {
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
		params_MG.set_block_entry("mass", 13, params_m_e);

		// 		if (IS == prod_no && Final_state == "4e")
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_BKG_SF);
		//
		// 		if (IS == prod_no && Final_state == "4eA")
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_BKG_SFpA);
		//
		// 		if (IS == prod_gg && Final_state == "4e")
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_BKG_SF);
		//
		// 		if (IS == prod_gg && Final_state == "4eA")
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_BKG_SFpA);

		if (IS == prod_qq && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

		if (IS == prod_qq && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_SFpA, ME_qq_Z4l_BKG_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		params_MG.set_block_entry("mass", 11, params_m_e);
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_BKG_OF);
		//
		// 		if (IS == prod_no && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_BKG_OFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_BKG_OF);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_BKG_OFpA);

		if (IS == prod_qq &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_OF, ME_qq_Z4l_BKG_UpType_OF);

		if (IS == prod_qq &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_OFpA, ME_qq_Z4l_BKG_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_BKG_SF);
		//
		// 		if (IS == prod_no && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_BKG_SFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_BKG_SF);
		//
		// 		if (IS == prod_gg && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_BKG_SFpA);

		if (IS == prod_qq &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_BKG_DownType_SF, ME_qq_Z4l_BKG_UpType_SF);

		if (IS == prod_qq &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_BKG_DownType_SFpA, ME_qq_Z4l_BKG_UpType_SFpA);
	}

	// 	if( Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
	// Final_state == "2muA")
	// 	{
	// 		/// Mass for the muons
	// 		params_MG.set_block_entry("mass", 13, params_m_mu);
	//
	// 		if (IS == prod_no && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO(false,
	// ME_Z4l_BKG_2l);
	//
	// 		if (IS == prod_no && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO(true,
	// ME_Z4l_BKG_2lpA);
	//
	// 		if (IS == prod_gg && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg(false,
	// ME_gg_Z4l_BKG__2l);
	//
	// 		if (IS == prod_gg && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg(true,
	// ME_gg_Z4l_BKG__2lpA);
	//
	// 		if (IS == prod_qq && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar(false,
	// ME_qq_Z4l_BKG_DownType_2l, ME_qq_Z4l_BKG_UpType_2l);
	//
	// 		if (IS == prod_qq && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar(true,
	// ME_qq_Z4l_BKG_DownType_2lpA, ME_qq_Z4l_BKG_UpType_2lpA);
	// 	}

	return 1;
}

/// Z4l Signal ME dispatcher
int MEKD::Run_ME_Dispatcher_Z4l_SIG(const production_types IS)
{
	if (IS == prod_no) {
		cerr << "Z -> 4l gg initial state is not supported.\n";
		return 1;
	}
	if (IS == prod_gg) {
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
		params_MG.set_block_entry("mass", 13, params_m_e);

		// 		if (IS == prod_no && Final_state == "4e")
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_SIG_SF);
		//
		// 		if (IS == prod_no && Final_state == "4eA")
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_SIG_SFpA);
		//
		// 		if (IS == prod_gg && Final_state == "4e")
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_SIG_SF);
		//
		// 		if (IS == prod_gg && Final_state == "4eA")
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_SIG_SFpA);

		if (IS == prod_qq && Final_state == "4e")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

		if (IS == prod_qq && Final_state == "4eA")
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_SFpA, ME_qq_Z4l_SIG_UpType_SFpA);
	}

	if (Final_state == "2e2m" || Final_state == "2e2mu" ||
		Final_state == "2e2mA" || Final_state == "2e2muA") {
		/// Common mass for the opposite-flavor leptons
		params_MG.set_block_entry("mass", 11, params_m_e);
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_SIG_OF);
		//
		// 		if (IS == prod_no && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_SIG_OFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2m" ||
		// Final_state == "2e2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_SIG_OF);
		//
		// 		if (IS == prod_gg && (Final_state == "2e2mA" ||
		// Final_state == "2e2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_SIG_OFpA);

		if (IS == prod_qq &&
			(Final_state == "2e2m" || Final_state == "2e2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_OF, ME_qq_Z4l_SIG_UpType_OF);

		if (IS == prod_qq &&
			(Final_state == "2e2mA" || Final_state == "2e2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_OFpA, ME_qq_Z4l_SIG_UpType_OFpA);
	}

	if (Final_state == "4m" || Final_state == "4mu" || Final_state == "4mA" ||
		Final_state == "4muA") {
		/// Common mass for the same-flavor leptons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		// 		if (IS == prod_no && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(false,
		// ME_Z4l_SIG_SF);
		//
		// 		if (IS == prod_no && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_NO(true,
		// ME_Z4l_SIG_SFpA);
		//
		// 		if (IS == prod_gg && (Final_state == "4m" ||
		// Final_state == "4mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_gg_Z4l_SIG_SF);
		//
		// 		if (IS == prod_gg && (Final_state == "4mA" ||
		// Final_state == "4muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_gg_Z4l_SIG_SFpA);

		if (IS == prod_qq &&
			(Final_state == "4m" || Final_state == "4mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_qq_Z4l_SIG_DownType_SF, ME_qq_Z4l_SIG_UpType_SF);

		if (IS == prod_qq &&
			(Final_state == "4mA" || Final_state == "4muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_qq_Z4l_SIG_DownType_SFpA, ME_qq_Z4l_SIG_UpType_SFpA);
	}

	// 	if( Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
	// Final_state == "2muA")
	// 	{
	// 		/// Mass for the muons
	// 		params_MG.set_block_entry("mass", 13, params_m_mu);
	//
	// 		if (IS == prod_no && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO(false,
	// ME_Z4l_SIG_2l);
	//
	// 		if (IS == prod_no && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_NO(true,
	// ME_Z4l_SIG_2lpA);
	//
	// 		if (IS == prod_gg && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg(false,
	// ME_gg_Z4l_SIG__2l);
	//
	// 		if (IS == prod_gg && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_gg(true,
	// ME_gg_Z4l_SIG__2lpA);
	//
	// 		if (IS == prod_qq && (Final_state == "2m" || Final_state == "2mu")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar(false,
	// ME_qq_Z4l_SIG_DownType_2l, ME_qq_Z4l_SIG_UpType_2l);
	//
	// 		if (IS == prod_qq && (Final_state == "2mA" ||
	// Final_state == "2muA")
	// )
	// 			return Run_MEs_Evaluator_Initial_State_qqbar(true,
	// ME_qq_Z4l_SIG_DownType_2lpA, ME_qq_Z4l_SIG_UpType_2lpA);
	// 	}

	return 1;
}

/// Spin-0 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin0(const production_types IS)
{
	if (IS == prod_qq) {
		cerr << "Spin-0 qqbar initial state is redundant, thus not provided.\n";
		return 1;
	}

	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_SFpA);

			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_SF);

			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_SFpA);

			// 			if (IS == prod_qq && Final_state == "4e")
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_SF, ME_Signal_qq_Spin0_UpType_SF);
			//
			// 			if (IS == prod_qq && Final_state == "4eA")
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_SFpA, ME_Signal_qq_Spin0_UpType_SFpA
			//);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_OFpA);

			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_OF);

			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_OFpA);

			// 			if (IS == prod_qq && (Final_state == "2e2m" ||
			// Final_state == "2e2mu"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_OF, ME_Signal_qq_Spin0_UpType_OF);
			//
			// 			if (IS == prod_qq && (Final_state == "2e2mA" ||
			// Final_state == "2e2muA"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_OFpA, ME_Signal_qq_Spin0_UpType_OFpA
			//);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_SFpA);

			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_SF);

			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_SFpA);

			// 			if (IS == prod_qq && (Final_state == "4m" ||
			// Final_state == "4mu"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_DownType_SF, ME_Signal_qq_Spin0_UpType_SF);
			//
			// 			if (IS == prod_qq && (Final_state == "4mA" ||
			// Final_state == "4muA"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_DownType_SFpA, ME_Signal_qq_Spin0_UpType_SFpA
			//);
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_SFpA);

			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_SF);

			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_SFpA);

			// 			if (IS == prod_qq && Final_state == "4e")
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_SF,
			// ME_Signal_qq_Spin0_2f_UpType_SF);
			//
			// 			if (IS == prod_qq && Final_state == "4eA")
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_SFpA,
			// ME_Signal_qq_Spin0_2f_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_OFpA);

			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_OF);

			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_OFpA);

			// 			if (IS == prod_qq && (Final_state == "2e2m" ||
			// Final_state == "2e2mu"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_OF,
			// ME_Signal_qq_Spin0_2f_UpType_OF);
			//
			// 			if (IS == prod_qq && (Final_state == "2e2mA" ||
			// Final_state == "2e2muA"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_OFpA,
			// ME_Signal_qq_Spin0_2f_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin0_2f_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin0_2f_SFpA);

			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin0_2f_SF);

			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin0_2f_SFpA);

			// 			if (IS == prod_qq && (Final_state == "4m" ||
			// Final_state == "4mu"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// false,
			// ME_Signal_qq_Spin0_2f_DownType_SF,
			// ME_Signal_qq_Spin0_2f_UpType_SF);
			//
			// 			if (IS == prod_qq && (Final_state == "4mA" ||
			// Final_state == "4muA"))
			// 				return Run_MEs_Evaluator_Initial_State_qqbar(
			// true,
			// ME_Signal_qq_Spin0_2f_DownType_SFpA,
			// ME_Signal_qq_Spin0_2f_UpType_SFpA);
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		if (IS == prod_no &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin0_2l);

		if (IS == prod_no &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin0_2lpA);

		if (IS == prod_gg &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_gg(
				false, ME_Signal_gg_Spin0_2l);

		if (IS == prod_gg &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_gg(
				true, ME_Signal_gg_Spin0_2lpA);

		// 		if (IS == prod_qq && (Final_state == "2m" ||
		// Final_state == "2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_qqbar(false,
		// ME_Signal_qq_Spin0_DownType_2l, ME_Signal_qq_Spin0_UpType_2l);

		// 		if (IS == prod_qq && (Final_state == "2mA" ||
		// Final_state == "2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_qqbar(true,
		// ME_Signal_qq_Spin0_DownType_2lpA, ME_Signal_qq_Spin0_UpType_2lpA);
	}

	return 1;
}

/// Spin-1 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin1(const production_types IS)
{
	if (IS == prod_gg) {
		cerr << "Spin-1 gg initial state is not possible, thus not provided.\n";
		return 1;
	}

	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_SFpA);

			// 			if (IS == prod_gg && Final_state == "4e")
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_SF);
			//
			// 			if (IS == prod_gg && Final_state == "4eA")
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_SFpA);

			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_SF,
					ME_Signal_qq_Spin1_UpType_SF);

			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_SFpA,
					ME_Signal_qq_Spin1_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_OFpA);

			//	 		if (IS == prod_gg && (Final_state == "2e2m" ||
			// Final_state == "2e2mu"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_OF);
			//
			// 			if (IS == prod_gg && (Final_state == "2e2mA" ||
			// Final_state == "2e2muA"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_OFpA);

			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_OF,
					ME_Signal_qq_Spin1_UpType_OF);

			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_OFpA,
					ME_Signal_qq_Spin1_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_SFpA);

			// 			if (IS == prod_gg && (Final_state == "4m" ||
			// Final_state == "4mu"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_SF);
			//
			// 			if (IS == prod_gg && (Final_state == "4mA" ||
			// Final_state == "4muA"))
			//	 			return Run_MEs_Evaluator_Initial_State_gg(
			//true,
			// ME_Signal_gg_Spin1_SFpA);

			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_DownType_SF,
					ME_Signal_qq_Spin1_UpType_SF);

			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_DownType_SFpA,
					ME_Signal_qq_Spin1_UpType_SFpA);
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_SFpA);

			// 			if (IS == prod_gg && Final_state == "4e")
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_SF);
			//
			// 			if (IS == prod_gg && Final_state == "4eA")
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_2f_SFpA);

			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_SF,
					ME_Signal_qq_Spin1_2f_UpType_SF);

			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
					ME_Signal_qq_Spin1_2f_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_OFpA);

			//	 		if (IS == prod_gg && (Final_state == "2e2m" ||
			// Final_state == "2e2mu"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_OF);
			//
			// 			if (IS == prod_gg && (Final_state == "2e2mA" ||
			// Final_state == "2e2muA"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// true,
			// ME_Signal_gg_Spin1_2f_OFpA);

			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_OF,
					ME_Signal_qq_Spin1_2f_UpType_OF);

			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_OFpA,
					ME_Signal_qq_Spin1_2f_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin1_2f_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin1_2f_SFpA);

			// 			if (IS == prod_gg && (Final_state == "4m" ||
			// Final_state == "4mu"))
			// 				return Run_MEs_Evaluator_Initial_State_gg(
			// false,
			// ME_Signal_gg_Spin1_2f_SF);
			//
			// 			if (IS == prod_gg && (Final_state == "4mA" ||
			// Final_state == "4muA"))
			//	 			return Run_MEs_Evaluator_Initial_State_gg(
			//true,
			// ME_Signal_gg_Spin1_2f_SFpA);

			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin1_2f_DownType_SF,
					ME_Signal_qq_Spin1_2f_UpType_SF);

			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin1_2f_DownType_SFpA,
					ME_Signal_qq_Spin1_2f_UpType_SFpA);
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		if (IS == prod_no &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin1_2l);

		if (IS == prod_no &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin1_2lpA);

		// 		if (IS == prod_gg && (Final_state == "2m" ||
		// Final_state == "2mu"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(false,
		// ME_Signal_gg_Spin1_2l);
		//
		// 		if (IS == prod_gg && (Final_state == "2mA" ||
		// Final_state == "2muA"))
		// 			return Run_MEs_Evaluator_Initial_State_gg(true,
		// ME_Signal_gg_Spin1_2lpA);

		if (IS == prod_qq &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_Signal_qq_Spin1_DownType_2l,
				ME_Signal_qq_Spin1_UpType_2l);

		if (IS == prod_qq &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				true, ME_Signal_qq_Spin1_DownType_2lpA,
				ME_Signal_qq_Spin1_UpType_2lpA);
	}

	return 1;
}

/// Spin-2 ME dispatcher
int MEKD::Run_ME_Dispatcher_SIG_Spin2(const production_types IS)
{
	if (Resonance_decay_mode == "ZZ") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_SFpA);

			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_SF);

			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_SFpA);

			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_SF,
					ME_Signal_qq_Spin2_UpType_SF);

			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_SFpA,
					ME_Signal_qq_Spin2_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_OFpA);

			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_OF);

			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_OFpA);

			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_OF,
					ME_Signal_qq_Spin2_UpType_OF);

			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_OFpA,
					ME_Signal_qq_Spin2_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_SFpA);

			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_SF);

			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_SFpA);

			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_DownType_SF,
					ME_Signal_qq_Spin2_UpType_SF);

			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_DownType_SFpA,
					ME_Signal_qq_Spin2_UpType_SFpA);
		}
	}

	if (Resonance_decay_mode == "2l") {
		if (Final_state == "4e" || Final_state == "4eA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_e);

			if (IS == prod_no && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_SF);

			if (IS == prod_no && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_SFpA);

			if (IS == prod_gg && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_SF);

			if (IS == prod_gg && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_SFpA);

			if (IS == prod_qq && Final_state == "4e")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_SF,
					ME_Signal_qq_Spin2_2f_UpType_SF);

			if (IS == prod_qq && Final_state == "4eA")
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
					ME_Signal_qq_Spin2_2f_UpType_SFpA);
		}

		if (Final_state == "2e2m" || Final_state == "2e2mu" ||
			Final_state == "2e2mA" || Final_state == "2e2muA") {
			/// Common mass for the opposite-flavor leptons
			params_MG.set_block_entry("mass", 11, params_m_e);
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_OF);

			if (IS == prod_no &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_OFpA);

			if (IS == prod_gg &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_OF);

			if (IS == prod_gg &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_OFpA);

			if (IS == prod_qq &&
				(Final_state == "2e2m" || Final_state == "2e2mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_OF,
					ME_Signal_qq_Spin2_2f_UpType_OF);

			if (IS == prod_qq &&
				(Final_state == "2e2mA" || Final_state == "2e2muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_OFpA,
					ME_Signal_qq_Spin2_2f_UpType_OFpA);
		}

		if (Final_state == "4m" || Final_state == "4mu" ||
			Final_state == "4mA" || Final_state == "4muA") {
			/// Common mass for the same-flavor leptons
			params_MG.set_block_entry("mass", 13, params_m_mu);

			if (IS == prod_no &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_NO(
					false, ME_Signal_Spin2_2f_SF);

			if (IS == prod_no &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_NO(
					true, ME_Signal_Spin2_2f_SFpA);

			if (IS == prod_gg &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_gg(
					false, ME_Signal_gg_Spin2_2f_SF);

			if (IS == prod_gg &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_gg(
					true, ME_Signal_gg_Spin2_2f_SFpA);

			if (IS == prod_qq &&
				(Final_state == "4m" || Final_state == "4mu"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					false, ME_Signal_qq_Spin2_2f_DownType_SF,
					ME_Signal_qq_Spin2_2f_UpType_SF);

			if (IS == prod_qq &&
				(Final_state == "4mA" || Final_state == "4muA"))
				return Run_MEs_Evaluator_Initial_State_qqbar(
					true, ME_Signal_qq_Spin2_2f_DownType_SFpA,
					ME_Signal_qq_Spin2_2f_UpType_SFpA);
		}
	}

	if (Final_state == "2m" || Final_state == "2mu" || Final_state == "2mA" ||
		Final_state == "2muA") {
		/// Mass for the muons
		params_MG.set_block_entry("mass", 13, params_m_mu);

		if (IS == prod_no &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_NO(
				false, ME_Signal_Spin2_2l);

		if (IS == prod_no &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_NO(
				true, ME_Signal_Spin2_2lpA);

		if (IS == prod_gg &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_gg(
				false, ME_Signal_gg_Spin2_2l);

		if (IS == prod_gg &&
			(Final_state == "2mA" || Final_state == "2muA"))
			return Run_MEs_Evaluator_Initial_State_gg(
				true, ME_Signal_gg_Spin2_2lpA);

		if (IS == prod_qq &&
			(Final_state == "2m" || Final_state == "2mu"))
			return Run_MEs_Evaluator_Initial_State_qqbar(
				false, ME_Signal_qq_Spin2_DownType_2l,
				ME_Signal_qq_Spin2_UpType_2l);

		if (IS == prod_qq &&
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

	Generic_ME.updateProc(params_MG);
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

	Generic_ME.updateProc(params_MG);
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
	if (param.parton_coeff_d != 0) {
		params_MG.set_block_entry("mass", 3, params_m_d);
		// 		params_MG.set_block_entry("heff", 15,
		// params_rhod01
		//);
		// 		params_MG.set_block_entry("heff", 16,
		// params_rhod02
		//);
		params_MG.set_block_entry("vec", 15, params_rhod11);
		params_MG.set_block_entry("vec", 16, params_rhod12);
		params_MG.set_block_entry("vec", 17, params_rhod13);
		params_MG.set_block_entry("vec", 18, params_rhod14);
		params_MG.set_block_entry("gravity", 33, params_rhod21);
		params_MG.set_block_entry("gravity", 34, params_rhod22);
		params_MG.set_block_entry("gravity", 35, params_rhod23);
		params_MG.set_block_entry("gravity", 36, params_rhod24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_d * params_m_d);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_d * params_m_d);

		Generic_ME_s.updateProc(params_MG);
		Generic_ME_s.setMomenta(p_set);
		Generic_ME_s.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_s.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			param.parton_coeff_d =
				pdfreader(1, PDFx1, Mass_4l) * pdfreader(-1, PDFx2, Mass_4l);
			Signal_ME = param.parton_coeff_d * buffer[0];
			param.parton_coeff_d =
				pdfreader(-1, PDFx1, Mass_4l) * pdfreader(1, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_d * buffer[1];
		} else
			Signal_ME = param.parton_coeff_d * (buffer[0] + buffer[1]);
	}

	/// Strange quark block. Down type (s-like)
	if (param.parton_coeff_s != 0) {
		params_MG.set_block_entry("mass", 3, params_m_s);
		// 		params_MG.set_block_entry("heff", 15,
		// params_rhos01
		//);
		// 		params_MG.set_block_entry("heff", 16,
		// params_rhos02
		//);
		params_MG.set_block_entry("vec", 15, params_rhos11);
		params_MG.set_block_entry("vec", 16, params_rhos12);
		params_MG.set_block_entry("vec", 17, params_rhos13);
		params_MG.set_block_entry("vec", 18, params_rhos14);
		params_MG.set_block_entry("gravity", 33, params_rhos21);
		params_MG.set_block_entry("gravity", 34, params_rhos22);
		params_MG.set_block_entry("gravity", 35, params_rhos23);
		params_MG.set_block_entry("gravity", 36, params_rhos24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_s * params_m_s);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_s * params_m_s);

		Generic_ME_s.updateProc(params_MG);
		Generic_ME_s.setMomenta(p_set);
		Generic_ME_s.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_s.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			param.parton_coeff_s =
				pdfreader(3, PDFx1, Mass_4l) * pdfreader(-3, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_s * buffer[0];
			param.parton_coeff_s =
				pdfreader(-3, PDFx1, Mass_4l) * pdfreader(3, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_s * buffer[1];
		} else
			Signal_ME += param.parton_coeff_s * (buffer[0] + buffer[1]);
	}

	/// Up quark block. Up type (c-like)
	if (param.parton_coeff_u != 0) {
		params_MG.set_block_entry("mass", 4, params_m_u);
		// 		params_MG.set_block_entry("heff", 11,
		// params_rhou01
		//);
		// 		params_MG.set_block_entry("heff", 12,
		// params_rhou02
		//);
		params_MG.set_block_entry("vec", 7, params_rhou11);
		params_MG.set_block_entry("vec", 8, params_rhou12);
		params_MG.set_block_entry("vec", 9, params_rhou13);
		params_MG.set_block_entry("vec", 10, params_rhou14);
		params_MG.set_block_entry("gravity", 25, params_rhou21);
		params_MG.set_block_entry("gravity", 26, params_rhou22);
		params_MG.set_block_entry("gravity", 27, params_rhou23);
		params_MG.set_block_entry("gravity", 28, params_rhou24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_u * params_m_u);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_u * params_m_u);

		Generic_ME_c.updateProc(params_MG);
		Generic_ME_c.setMomenta(p_set);
		Generic_ME_c.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_c.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			param.parton_coeff_u =
				pdfreader(2, PDFx1, Mass_4l) * pdfreader(-2, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_u * buffer[0];
			param.parton_coeff_u =
				pdfreader(-2, PDFx1, Mass_4l) * pdfreader(2, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_u * buffer[1];
		} else
			Signal_ME += param.parton_coeff_u * (buffer[0] + buffer[1]);
	}

	/// Charm quark block. Up type (c-like)
	if (param.parton_coeff_c != 0) {
		params_MG.set_block_entry("mass", 4, params_m_c);
		// 		params_MG.set_block_entry("heff", 11,
		// params_rhoc01
		//);
		// 		params_MG.set_block_entry("heff", 12,
		// params_rhoc02
		//);
		params_MG.set_block_entry("vec", 7, params_rhoc11);
		params_MG.set_block_entry("vec", 8, params_rhoc12);
		params_MG.set_block_entry("vec", 9, params_rhoc13);
		params_MG.set_block_entry("vec", 10, params_rhoc14);
		params_MG.set_block_entry("gravity", 25, params_rhoc21);
		params_MG.set_block_entry("gravity", 26, params_rhoc22);
		params_MG.set_block_entry("gravity", 27, params_rhoc23);
		params_MG.set_block_entry("gravity", 28, params_rhoc24);
		p_set[0][3] = sqrt(p_set[0][0] * p_set[0][0] - params_m_c * params_m_c);
		p_set[1][3] =
			-sqrt(p_set[1][0] * p_set[1][0] - params_m_c * params_m_c);

		Generic_ME_c.updateProc(params_MG);
		Generic_ME_c.setMomenta(p_set);
		Generic_ME_c.sigmaKin();
		buffer = const_cast<double *>(Generic_ME_c.getMatrixElements());

		if (flag.Use_PDF_w_pT0) {
			param.parton_coeff_c =
				pdfreader(4, PDFx1, Mass_4l) * pdfreader(-4, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_c * buffer[0];
			param.parton_coeff_c =
				pdfreader(-4, PDFx1, Mass_4l) * pdfreader(4, PDFx2, Mass_4l);
			Signal_ME += param.parton_coeff_c * buffer[1];
		} else
			Signal_ME += param.parton_coeff_c * (buffer[0] + buffer[1]);
	}

	if (flag.Use_mZ4l_eq_m4l)
		params_MG.set_block_entry(
			"mass", 23, params_m_Z); // return to real mass. Used in Z -> 4l

	return 0;
}

/// end of namespace
}

#endif
////////////////////////////////
/// END OF MEKD_RunMEs.cpp   ///
////////////////////////////////