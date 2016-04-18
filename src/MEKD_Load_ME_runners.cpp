/*
 *
 * Load_ME_runners
 *
 *
 */
#ifndef MEKD_Load_ME_runners_cpp
#define MEKD_Load_ME_runners_cpp

#include "MEKD.h"

namespace mekd
{

void MEKD::Load_ME_runners(const vector<process_description> &desc)
{
    ME_runners.reserve(desc.size()); // speed up
    for (auto d : desc) {            // loop not very optimal but transparent
        if (Load_ME_runners_try_Misc_4l(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Misc_4lA(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Z_4l(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Z_4lA(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin0_4l(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin0_4lA(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin1_4l(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin1_4lA(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin2_4l(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin2_4lA(d, ME_runners))
            continue;

        if (Load_ME_runners_try_Other_ttbb(d, ME_runners))
            continue;
        if (Load_ME_runners_try_Spin0_ttbb(d, ME_runners))
            continue;

        cerr << "ME runner not found:\n"
             << "process: " << d.process << endl
             << "resonance: " << d.resonance << endl
             << "production: " << d.production << endl
             << "decay: " << d.decay << endl
             << "final_state: " << d.final_state << endl;
        ME_runners.push_back(nullptr);
    }
}

bool MEKD::Load_ME_runners_try(const process_description &desc,
                               ME_runner *runner, vector<ME_runner *> &v)
{
    if (runner->is_my_type(desc)) {
        v.push_back(runner); // load if a correct one
        return true;
    }

    delete runner; // dismiss if not the one
    return false;
}

void MEKD::Initialize_ME_runners(vector<ME_runner *> &ME_runners)
{
    for (auto r : ME_runners) {
        if (r == nullptr)
            continue;
        if (!r->initialize()) {
            cerr << "ME runner not initializable:\n"
                 << "model: " << r->my_type().model << endl
                 << "process: " << r->my_type().process << endl
                 << "resonance: " << r->my_type().resonance << endl
                 << "production: " << r->my_type().production << endl
                 << "decay: " << r->my_type().decay << endl
                 << "final_state: " << r->my_type().final_state << endl;
        }
    }
}

void MEKD::Initialize_ME_runners(const string &param_f,
                                 vector<ME_runner *> &ME_runners)
{
    for (auto r : ME_runners) {
        if (r == nullptr)
            continue;
        if (!r->initialize(param_f)) {
            cerr << "ME runner not initializable:\n"
                 << "model: " << r->my_type().model << endl
                 << "process: " << r->my_type().process << endl
                 << "resonance: " << r->my_type().resonance << endl
                 << "production: " << r->my_type().production << endl
                 << "decay: " << r->my_type().decay << endl
                 << "final_state: " << r->my_type().final_state << endl;
        }
    }
}

/// end of namespace
}

#endif
/*
 * End of MEKD_Load_ME_runners.cpp
 */