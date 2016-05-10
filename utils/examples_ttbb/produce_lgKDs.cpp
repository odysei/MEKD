#ifndef MEKD_example_produce_lgKDs_cpp
#define MEKD_example_produce_lgKDs_cpp
#include "produce_lgKDs.h"

int main()
{
    vector<string> filenames = Pick_filenames(Choice());
    if (filenames.size() == 0)
        return 1;

    vector<ifstream *> files = Load_files(filenames);

    mekd::MEKD calc_MEs(Make_desc());
    My_flags(calc_MEs.flag);

    for (auto f : files) {
        vector<int> event_id;
        vector<double *> event_p;
        event_id.resize(4, 0);
        event_p.resize(4, nullptr);
        for (auto i = event_p.begin(); i != event_p.end(); ++i)
            (*i) = new double[4];

        mekd::input in;
        in.id = &event_id;
        in.p = &event_p;

        vector<double> MEs;
        while ((*f).good() && !(*f).eof()) {
            if (!Fill_event(f, event_id, event_p))
                continue;

            calc_MEs.eval_MEs(in, MEs);
            cout << log10(MEs[0] / MEs[2]) << " " << log10(MEs[1] / MEs[2])
                 << endl;
        }

        for (auto i = event_p.begin(); i != event_p.end(); ++i)
            delete (*i);
    }

    Close_files(files);

    return 0;
}

int Choice()
{
    cout << "Choose your run.\n";
    cout << "Run on short files (100): 1\n";
    cout << "Run on long files: 2\n";

    int i;
    cin >> i;

    cout << "Your choice was " << i << endl;
    return i;
}

vector<string> Pick_filenames(int ch)
{
    const string file_ttbb_100 = Find_local_file("ttbb_all_100.lhe_proc");
    const string file_ttbb_h_100 = Find_local_file("ttbb_h_100.lhe_proc");
    const string file_ttbb_noh_100 = Find_local_file("ttbb_noh_100.lhe_proc");
    const string file_ttbb = Find_local_file("ttbb_all.lhe_proc");
    const string file_ttbb_h = Find_local_file("ttbb_h.lhe_proc");
    const string file_ttbb_noh = Find_local_file("ttbb_noh.lhe_proc");
    vector<string> fn;

    if (ch == 1) {
        cout << "Pick files:\n";
        cout << "1: " << file_ttbb_100 << endl;
        cout << "2: " << file_ttbb_h_100 << endl;
        cout << "3: " << file_ttbb_noh_100 << endl;
        cout << "4: All above.\n";

        int i2;
        cin >> i2;
        if (i2 == 1)
            fn.push_back(file_ttbb_100.c_str());
        if (i2 == 2)
            fn.push_back(file_ttbb_h_100.c_str());
        if (i2 == 3)
            fn.push_back(file_ttbb_noh_100.c_str());
        if (i2 == 4) {
            fn.push_back(file_ttbb_100.c_str());
            fn.push_back(file_ttbb_h_100.c_str());
            fn.push_back(file_ttbb_noh_100.c_str());
        }
        return fn;
    }
    if (ch == 2) {
        cout << "Pick files:\n";
        cout << "1: " << file_ttbb << endl;
        cout << "2: " << file_ttbb_h << endl;
        cout << "3: " << file_ttbb_noh << endl;
        cout << "4: All above.\n";

        int i2;
        cin >> i2;
        if (i2 == 1)
            fn.push_back(file_ttbb.c_str());
        if (i2 == 2)
            fn.push_back(file_ttbb_h.c_str());
        if (i2 == 3)
            fn.push_back(file_ttbb_noh.c_str());
        if (i2 == 4) {
            fn.push_back(file_ttbb.c_str());
            fn.push_back(file_ttbb_h.c_str());
            fn.push_back(file_ttbb_noh.c_str());
        }
        return fn;
    }

    return fn;
}

vector<mekd::process_description> Make_desc()
{
    mekd::process_description sig_bkg;
    mekd::process_description sig;
    mekd::process_description bkg;

    sig_bkg.model = mekd::model_HEFTU;
    sig_bkg.process = mekd::proc_ttX;
    sig_bkg.resonance = mekd::bkg_reson_Spin0Pm;
    sig_bkg.production = mekd::prod_all;
    sig_bkg.decay = mekd::decay_2f;
    sig_bkg.final_state = mekd::final_ttbb;

    sig.model = mekd::model_HEFTU;
    sig.process = mekd::proc_ttX;
    sig.resonance = mekd::reson_Spin0Pm;
    sig.production = mekd::prod_all;
    sig.decay = mekd::decay_2f;
    sig.final_state = mekd::final_ttbb;

    bkg.model = mekd::model_HEFTU;
    bkg.process = mekd::proc_ttX;
    bkg.resonance = mekd::bkg_tt;
    bkg.production = mekd::prod_all;
    bkg.decay = mekd::decay_2f;
    bkg.final_state = mekd::final_ttbb;

    vector<mekd::process_description> init_desc;
    init_desc.reserve(3);
    init_desc.push_back(sig_bkg);
    init_desc.push_back(sig);
    init_desc.push_back(bkg);

    return init_desc;
}

void My_flags(mekd::flags &flag)
{
    flag.Use_PDF_w_pT0 = true;
    flag.use_prod_ddx = true;
    flag.use_prod_uux = true;
    flag.use_prod_ssx = true;
    flag.use_prod_ccx = true;
    flag.use_prod_bbx = false;
    flag.use_prod_gg = true;
}

#endif