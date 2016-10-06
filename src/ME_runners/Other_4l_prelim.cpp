/*
 *
 * ME_runners. See defined processes below.
 *
 * Mostly: ZZ, Z backgrounds, Z s/t channels, some custom
 *
 *
 */
#ifndef MEKD__ME_runners__Other_4l_cpp
#define MEKD__ME_runners__Other_4l_cpp

#include "Supported_MEs_Other_4l.h"

namespace mekd
{

/*
 * Beginning of ME_runner classes
 */

/// ME_runner_gg_Custom_ZZ_4l
const process_description ME_runner_gg_Custom_ZZ_4l::my_type()
{
    return me;
}

bool ME_runner_gg_Custom_ZZ_4l::is_my_type(
    const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Custom_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Custom(in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_gg_CPPProcess_4l
// const process_description ME_runner_gg_CPPProcess_4l::my_type()
// {
//     return me;
// }
// 
// bool ME_runner_gg_CPPProcess_4l::is_my_type(const process_description &in)
// {
//     return compare_types(in, me);
// }
// 
// double ME_runner_gg_CPPProcess_4l::evaluate(MEKD &in_MEKD, const input &in)
// {
//     in_MEKD.Run_ME_Configurator_CPPProcess(me, in_MEKD.idata);
//     return in_MEKD.Signal_ME;
// }

/*
 * with photons
 */

/// ME_runner_gg_Custom_ZZ_4lA
const process_description ME_runner_gg_Custom_ZZ_4lA::my_type()
{
    return me;
}

bool ME_runner_gg_Custom_ZZ_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_gg_Custom_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Custom(in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/*
 * Z/ZZ EWK processes go below AKA backgrounds
 */

/// ME_runner_qq_bkg_Z_ZZ_4l
// const process_description ME_runner_qq_bkg_Z_ZZ_4l::my_type()
// {
//     return me;
// }
// 
// bool ME_runner_qq_bkg_Z_ZZ_4l::is_my_type(const process_description &in)
// {
//     return compare_types(in, me);
// }
// 
// double ME_runner_qq_bkg_Z_ZZ_4l::evaluate(MEKD &in_MEKD, const input &in)
// {
//     in_MEKD.Run_ME_Configurator_BKG_ZZ(me, in_MEKD.idata);
//     return in_MEKD.Signal_ME;
// }

/// ME_runner_qq_bkg_Z_2f_4l
const process_description ME_runner_qq_bkg_Z_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Z_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Z_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_BKG_ZZ(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_bkg_Zs_2f_4l
const process_description ME_runner_qq_bkg_Zs_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Zs_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Zs_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Z4l_SIG(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_bkg_Zt_2f_4l
const process_description ME_runner_qq_bkg_Zt_2f_4l::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Zt_2f_4l::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Zt_2f_4l::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Z4l_BKG(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/*
 * with photons
 */

/// ME_runner_qq_bkg_Z_ZZ_4lA
// const process_description ME_runner_qq_bkg_Z_ZZ_4lA::my_type()
// {
//     return me;
// }
// 
// bool ME_runner_qq_bkg_Z_ZZ_4lA::is_my_type(const process_description &in)
// {
//     return compare_types(in, me);
// }
// 
// double ME_runner_qq_bkg_Z_ZZ_4lA::evaluate(MEKD &in_MEKD, const input &in)
// {
//     in_MEKD.Run_ME_Configurator_BKG_ZZ(me, in_MEKD.idata);
//     return in_MEKD.Signal_ME;
// }

/// ME_runner_qq_bkg_Z_2f_4lA
const process_description ME_runner_qq_bkg_Z_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Z_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Z_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_BKG_ZZ(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_bkg_Zs_2f_4lA
const process_description ME_runner_qq_bkg_Zs_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Zs_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Zs_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Z4l_SIG(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/// ME_runner_qq_bkg_Zt_2f_4lA
const process_description ME_runner_qq_bkg_Zt_2f_4lA::my_type()
{
    return me;
}

bool ME_runner_qq_bkg_Zt_2f_4lA::is_my_type(const process_description &in)
{
    return compare_types(in, me);
}

double ME_runner_qq_bkg_Zt_2f_4lA::evaluate(MEKD &in_MEKD, const input &in)
{
    in_MEKD.Run_ME_Configurator_Z4l_BKG(me, in_MEKD.idata);
    return in_MEKD.Signal_ME;
}

/*
 * End of ME_runner classes
 */

/// end of namespace
}

#endif

/////////////////////////////////////
/// END OF MEKD__ME_runners__h   ///
/////////////////////////////////////
