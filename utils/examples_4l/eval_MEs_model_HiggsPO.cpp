#ifndef eval_MEs_model_HiggsPO_cpp
#define eval_MEs_model_HiggsPO_cpp

#include "eval_MEs_model_HiggsPO.h"

int main()
{
    vector<string> filenames = Pick_filenames(Choice());
    if (filenames.size() == 0)
        return 1;

    vector<ifstream *> files = Load_files(filenames);

    // initiate MEKD
    mekd::MEKD calc_MEs(Make_desc());
    mekd::MEKD calc_MEs_CC(Make_desc_CC()); // custom couplings

    // set favorite flags
    My_flags(calc_MEs.flag);
    My_flags(calc_MEs_CC.flag);

    // loop over events and print results
    Main_loop(files, calc_MEs, calc_MEs_CC);

    Close_files(files);

    return 0;
}

void Main_loop(vector<ifstream *> &files, mekd::MEKD &calc_MEs,
               mekd::MEKD &calc_MEs_CC)
{
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

        MG5_HiggsPO_UFO::input_c in_c1 = CC1(in);
        MG5_HiggsPO_UFO::input_c in_c2 = CC2(in);

        vector<double> MEs;
        vector<double> MEs_CC1;
        vector<double> MEs_CC2;
        while ((*f).good() && !(*f).eof()) {
            if (!Fill_event(f, event_id, event_p))
                continue;

            calc_MEs.eval_MEs(in, MEs);
            calc_MEs_CC.eval_MEs(in_c1, MEs_CC1);
            calc_MEs_CC.eval_MEs(in_c2, MEs_CC2);

            cout << log10(MEs[0]) << " " << log10(MEs[1]) << " "
                 << log10(MEs_CC1[0]) << " " << log10(MEs_CC1[1]) << " "
                 << log10(MEs_CC2[0]) << " " << log10(MEs_CC2[1]) << "\n";
        }

        for (auto i = event_p.begin(); i != event_p.end(); ++i)
            delete (*i);
    }
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
    const string file_4l_100 = Find_local_file("ID_exyz_eemm_100.dat");
    const string file_4l = Find_local_file("ID_exyz_eemm.dat");
    vector<string> fn;

    if (ch == 1) {
        cout << "Pick files:\n";
        cout << "1: " << file_4l_100 << endl;
        cout << "2: All above.\n";

        int i2;
        cin >> i2;
        if (i2 == 1)
            fn.push_back(file_4l_100.c_str());
        if (i2 == 2) {
            fn.push_back(file_4l_100.c_str());
        }
        return fn;
    }
    if (ch == 2) {
        cout << "Pick files:\n";
        cout << "1: " << file_4l << endl;
        cout << "2: All above.\n";

        int i2;
        cin >> i2;
        if (i2 == 1)
            fn.push_back(file_4l.c_str());
        if (i2 == 2) {
            fn.push_back(file_4l.c_str());
        }
        return fn;
    }

    return fn;
}

vector<mekd::process_description> Make_desc()
{
    mekd::process_description H_2to4;
    mekd::process_description H_1to4;

    H_2to4.model = mekd::model_HiggsPO;
    H_2to4.process = mekd::proc_simple;
    H_2to4.resonance = mekd::reson_Spin0Pm;
    H_2to4.production = mekd::prod_gg;
    H_2to4.decay = mekd::decay_VV;
    H_2to4.final_state = mekd::final_4l;

    H_1to4.model = mekd::model_HiggsPO;
    H_1to4.process = mekd::proc_simple;
    H_1to4.resonance = mekd::reson_Spin0Pm;
    H_1to4.production = mekd::prod_no;
    H_1to4.decay = mekd::decay_VV;
    H_1to4.final_state = mekd::final_4l;

    vector<mekd::process_description> init_desc;
    init_desc.reserve(2);
    init_desc.push_back(H_2to4);
    init_desc.push_back(H_1to4);

    return init_desc;
}

// custom couplings
vector<mekd::process_description> Make_desc_CC()
{
    mekd::process_description H_2to4;
    mekd::process_description H_1to4;

    H_2to4.model = mekd::model_HiggsPO;
    H_2to4.process = mekd::proc_simple;
    H_2to4.resonance = mekd::reson_Spin0;
    H_2to4.production = mekd::prod_gg;
    H_2to4.decay = mekd::decay_VV;
    H_2to4.final_state = mekd::final_4l;

    H_1to4.model = mekd::model_HiggsPO;
    H_1to4.process = mekd::proc_simple;
    H_1to4.resonance = mekd::reson_Spin0;
    H_1to4.production = mekd::prod_no;
    H_1to4.decay = mekd::decay_VV;
    H_1to4.final_state = mekd::final_4l;

    vector<mekd::process_description> init_desc;
    init_desc.reserve(2);
    init_desc.push_back(H_2to4);
    init_desc.push_back(H_1to4);

    return init_desc;
}

MG5_HiggsPO_UFO::input_c CC1(const mekd::input &in)
{
    MG5_HiggsPO_UFO::input_c input_w_CC;
    input_w_CC.p = in.p;
    input_w_CC.id = in.id;

    input_w_CC.c.kZZ = 1;
    input_w_CC.c.eZZ = 0;
    input_w_CC.c.eZZCP = 0;

    input_w_CC.c.kZA = 0;
    input_w_CC.c.lZACP = 0;

    input_w_CC.c.kAA = 0;
    input_w_CC.c.lAACP = 0;

    input_w_CC.c.eZeL = 0;
    input_w_CC.c.eZeR = 0;
    input_w_CC.c.eZmuL = 0;
    input_w_CC.c.eZmuR = 0;

    return input_w_CC;
}

MG5_HiggsPO_UFO::input_c CC2(const mekd::input &in)
{
    MG5_HiggsPO_UFO::input_c input_w_CC;
    input_w_CC.p = in.p;
    input_w_CC.id = in.id;

    input_w_CC.c.kZZ = 0;
    input_w_CC.c.eZZ = 0;
    input_w_CC.c.eZZCP = 0;

    input_w_CC.c.kZA = 0;
    input_w_CC.c.lZACP = 0;

    input_w_CC.c.kAA = 0;
    input_w_CC.c.lAACP = 0;

    input_w_CC.c.eZeL = 1;
    input_w_CC.c.eZeR = 1;
    input_w_CC.c.eZmuL = 1;
    input_w_CC.c.eZmuR = 1;

    return input_w_CC;
}

MG5_HiggsPO_UFO::input_c CC2(const mekd::input &);

void My_flags(mekd::flags &flag)
{
    flag.Use_PDF_w_pT0 = false;
    flag.use_prod_ddx = true;
    flag.use_prod_uux = true;
    flag.use_prod_ssx = true;
    flag.use_prod_ccx = true;
    flag.use_prod_bbx = false;
    flag.use_prod_gg = true;
}

#endif