//==========================================================================
// This file has been automatically generated for C++ by
// MadGraph 5 v. 1.5.2, 2012-10-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//
// Updated to MadGraph5_aMC@NLO v. 2.3.3, 2015-10-25
// by Aurelijus Rinkevicius (odysei)
//==========================================================================

#ifndef Parameters_MEKD_H
#define Parameters_MEKD_H

#include <complex>
#include <iostream>
#include <iomanip>

#include "read_slha_MEKD.h"
using namespace std;

class Parameters_MEKD
{
  public:
	static Parameters_MEKD *getInstance();

	// Define "zero"
	double zero, ZERO;
	// Model parameters independent of aS
    /* Missed to rename with "mdl_": aEWM1, aS
     * 
     * OLD: mdl_cabi, mdl_cos__cabi, mdl_sin__cabi (without "mdl_")
     * 
     * MEKD extra: mdl_MD, mdl_MS, mdl_MU, mdl_MXG, mdl_MZp, mdl_WXG,
     *      mdl_WZp, mdl_ydo, mdl_yms, mdl_ymup, mdl_ys, mdl_yup
     * 
     * NEW (Wolfenstein): mdl_AWS, mdl_etaWS, mdl_lamWS, mdl_lamWS,
     *      mdl_lamWS__exp__2, mdl_lamWS__exp__3, mdl_rhoWS
     * 
     * NEW: mdl_WTau */
    double aEWM1, aS, mdl_AWS, mdl_Gf,
        mdl_MB, mdl_MC, mdl_MD, mdl_MH, mdl_MH__exp__2, mdl_MM, mdl_MS, mdl_MT,
        mdl_MTA, mdl_MU, mdl_MW, mdl_MW__exp__2, mdl_MXG, mdl_MZ,
        mdl_MZ__exp__2, mdl_MZ__exp__4, mdl_MZp, mdl_Me, mdl_WH, mdl_WT,
        mdl_WTau, mdl_WW, mdl_WXG, mdl_WZ, mdl_WZp, mdl_aEW, mdl_cw,
        mdl_cw__exp__2, mdl_ee, mdl_ee__exp__2, mdl_etaWS, mdl_g1, mdl_gw,
        mdl_lam, mdl_lamWS, mdl_lamWS__exp__2, mdl_lamWS__exp__3, mdl_muH,
        mdl_rhoWS, mdl_sqrt__2, mdl_sqrt__aEW, mdl_sqrt__sw2, mdl_sw, mdl_sw2,
        mdl_sw__exp__2, mdl_vev, mdl_vev__exp__2, mdl_yb, mdl_yc, mdl_ydo,
        mdl_ye, mdl_ym, mdl_ymb, mdl_ymc, mdl_ymdo, mdl_yme, mdl_ymm, mdl_yms,
        mdl_ymt, mdl_ymtau, mdl_ymup, mdl_ys, mdl_yt, mdl_ytau, mdl_yup;
    
    std::complex<double> mdl_CKM1x1, mdl_CKM1x2, mdl_CKM1x3, mdl_CKM2x1,
        mdl_CKM2x2, mdl_CKM2x3, mdl_CKM3x1, mdl_CKM3x2, mdl_CKM3x3,
        mdl_I1x11, mdl_I1x12, mdl_I1x13, mdl_I1x21, mdl_I1x22, mdl_I1x23,
        mdl_I1x31, mdl_I1x32, mdl_I1x33, mdl_I2x11, mdl_I2x12, mdl_I2x13,
        mdl_I2x21, mdl_I2x22, mdl_I2x23, mdl_I2x31, mdl_I2x32, mdl_I2x33,
        mdl_I3x11, mdl_I3x12, mdl_I3x13, mdl_I3x21, mdl_I3x22, mdl_I3x23,
        mdl_I3x31, mdl_I3x32, mdl_I3x33, mdl_I4x11, mdl_I4x12, mdl_I4x13,
        mdl_I4x21, mdl_I4x22, mdl_I4x23, mdl_I4x31, mdl_I4x32, mdl_I4x33,
        mdl_conjg__CKM1x1, mdl_conjg__CKM1x2, mdl_conjg__CKM1x3,
        mdl_conjg__CKM2x1, mdl_conjg__CKM2x2, mdl_conjg__CKM2x3,
        mdl_conjg__CKM3x1, mdl_conjg__CKM3x2, mdl_conjg__CKM3x3, mdl_complexi;
    
	// Model parameters dependent on aS
    double mdl_sqrt__aS, G, mdl_G__exp__2; 
	// Model couplings independent of aS
	// Spin 0
	std::complex<double> rhob02, rhob01, rhos02, rhos01, rhod02, rhod01, rhoc02,
		rhoc01, rhou02, rhou01, g4z, g3z, g2z, g1z, g4g, g3g, g2g, g1g;
	std::complex<double> rhomu02, rhomu01, rhoe02, rhoe01; // 2l

	// Spin 1
	std::complex<double> rhob14, rhob13, rhob12, rhob11, rhos14, rhos13, rhos12,
		rhos11, rhod14, rhod13, rhod12, rhod11, rhoc14, rhoc13, rhoc12, rhoc11,
		rhou14, rhou13, rhou12, rhou11, b2z, b1z;
	std::complex<double> rhomu14, rhomu13, rhomu12, rhomu11, rhoe14, rhoe13,
		rhoe12, rhoe11; // 2l

	// Spin 2
	std::complex<double> rhob24, rhob23, rhob22, rhob21, rhos24, rhos23, rhos22,
		rhos21, rhod24, rhod23, rhod22, rhod21, rhoc24, rhoc23, rhoc22, rhoc21,
		rhou24, rhou23, rhou22, rhou21, k10g, k9g, k8g, k7g, k6g, k5g, k4g, k3g,
		k2g, k1g, k10z, k9z, k8z, k7z, k6z, k5z, k4z, k3z, k2z, k1z;
	std::complex<double> rhomu24, rhomu23, rhomu22, rhomu21, rhoe24, rhoe23,
		rhoe22, rhoe21; // 2l
    
    // ZZ decays
	std::complex<double> GC_1, GC_2, GC_3, GC_109, GC_110, GC_115, GC_116,
		Unitary_GC_5, Unitary_GC_6, Unitary_GC_7, Unitary_GC_70, Unitary_GC_71,
		Unitary_GC_74, Unitary_GC_75;

	// Coming extra from spin 0
	std::complex<double> HEF_MEKD_GC_3, HEF_MEKD_GC_4, HEF_MEKD_GC_5,
		HEF_MEKD_GC_13, HEF_MEKD_GC_14, HEF_MEKD_GC_15, HEF_MEKD_GC_18,
		HEF_MEKD_GC_19, HEF_MEKD_GC_22, HEF_MEKD_GC_23, HEF_MEKD_GC_25,
		HEF_MEKD_GC_106, HEF_MEKD_GC_107, HEF_MEKD_GC_116, HEF_MEKD_GC_117,
		HEF_MEKD_GC_126, HEF_MEKD_GC_127, HEF_MEKD_GC_136, HEF_MEKD_GC_137,
		HEF_MEKD_GC_161, HEF_MEKD_GC_168;

	// Coming extra from spin 1
	std::complex<double> HEF_MEKD_GC_1, HEF_MEKD_GC_2, HEF_MEKD_GC_108,
		HEF_MEKD_GC_109, HEF_MEKD_GC_110, HEF_MEKD_GC_111, HEF_MEKD_GC_118,
		HEF_MEKD_GC_119, HEF_MEKD_GC_120, HEF_MEKD_GC_121, HEF_MEKD_GC_128,
		HEF_MEKD_GC_129, HEF_MEKD_GC_130, HEF_MEKD_GC_131, HEF_MEKD_GC_138,
		HEF_MEKD_GC_139, HEF_MEKD_GC_140, HEF_MEKD_GC_141;

	// Coming extra from spin 2
	std::complex<double> HEF_MEKD_GC_62, HEF_MEKD_GC_63, HEF_MEKD_GC_64,
		HEF_MEKD_GC_67, HEF_MEKD_GC_68, HEF_MEKD_GC_71, HEF_MEKD_GC_72,
		HEF_MEKD_GC_75, HEF_MEKD_GC_76, HEF_MEKD_GC_79, HEF_MEKD_GC_80,
		HEF_MEKD_GC_81, HEF_MEKD_GC_82, HEF_MEKD_GC_83, HEF_MEKD_GC_84,
		HEF_MEKD_GC_85, HEF_MEKD_GC_86, HEF_MEKD_GC_90, HEF_MEKD_GC_91,
		HEF_MEKD_GC_92, HEF_MEKD_GC_112, HEF_MEKD_GC_113, HEF_MEKD_GC_114,
		HEF_MEKD_GC_115, HEF_MEKD_GC_122, HEF_MEKD_GC_123, HEF_MEKD_GC_124,
		HEF_MEKD_GC_125, HEF_MEKD_GC_132, HEF_MEKD_GC_133, HEF_MEKD_GC_134,
		HEF_MEKD_GC_135, HEF_MEKD_GC_142, HEF_MEKD_GC_143, HEF_MEKD_GC_144,
		HEF_MEKD_GC_145;

	/// HEF_MEKD2_1 model
	// Coming from DY
	std::complex<double> HEF_MEKD2_1_GC_3, HEF_MEKD2_1_GC_4, HEF_MEKD2_1_GC_5,
		HEF_MEKD2_1_GC_181, HEF_MEKD2_1_GC_182, HEF_MEKD2_1_GC_187,
		HEF_MEKD2_1_GC_188;

	// Coming extra from spin 0
	std::complex<double> HEF_MEKD2_1_GC_13, HEF_MEKD2_1_GC_14,
		HEF_MEKD2_1_GC_15, HEF_MEKD2_1_GC_18, HEF_MEKD2_1_GC_19,
		HEF_MEKD2_1_GC_22, HEF_MEKD2_1_GC_23, HEF_MEKD2_1_GC_25,
		HEF_MEKD2_1_GC_126, HEF_MEKD2_1_GC_127, HEF_MEKD2_1_GC_136,
		HEF_MEKD2_1_GC_137;

	// Coming extra from spin 1
	std::complex<double> HEF_MEKD2_1_GC_1, HEF_MEKD2_1_GC_2, HEF_MEKD2_1_GC_108,
		HEF_MEKD2_1_GC_109, HEF_MEKD2_1_GC_110, HEF_MEKD2_1_GC_111,
		HEF_MEKD2_1_GC_128, HEF_MEKD2_1_GC_129, HEF_MEKD2_1_GC_130,
		HEF_MEKD2_1_GC_131, HEF_MEKD2_1_GC_138, HEF_MEKD2_1_GC_139,
		HEF_MEKD2_1_GC_140, HEF_MEKD2_1_GC_141, HEF_MEKD2_1_GC_148,
		HEF_MEKD2_1_GC_149, HEF_MEKD2_1_GC_150, HEF_MEKD2_1_GC_151;

	// Coming extra from spin 2
	std::complex<double> HEF_MEKD2_1_GC_62, HEF_MEKD2_1_GC_63,
		HEF_MEKD2_1_GC_64, HEF_MEKD2_1_GC_67, HEF_MEKD2_1_GC_68,
		HEF_MEKD2_1_GC_71, HEF_MEKD2_1_GC_72, HEF_MEKD2_1_GC_75,
		HEF_MEKD2_1_GC_76, HEF_MEKD2_1_GC_79, HEF_MEKD2_1_GC_80,
		HEF_MEKD2_1_GC_81, HEF_MEKD2_1_GC_82, HEF_MEKD2_1_GC_83,
		HEF_MEKD2_1_GC_84, HEF_MEKD2_1_GC_85, HEF_MEKD2_1_GC_86,
		HEF_MEKD2_1_GC_90, HEF_MEKD2_1_GC_91, HEF_MEKD2_1_GC_92,
		HEF_MEKD2_1_GC_112, HEF_MEKD2_1_GC_113, HEF_MEKD2_1_GC_114,
		HEF_MEKD2_1_GC_115, HEF_MEKD2_1_GC_132, HEF_MEKD2_1_GC_133,
		HEF_MEKD2_1_GC_134, HEF_MEKD2_1_GC_135, HEF_MEKD2_1_GC_142,
		HEF_MEKD2_1_GC_143, HEF_MEKD2_1_GC_144, HEF_MEKD2_1_GC_145,
		HEF_MEKD2_1_GC_152, HEF_MEKD2_1_GC_153, HEF_MEKD2_1_GC_154,
		HEF_MEKD2_1_GC_155;

	// Model couplings dependent on aS

	// Set parameters that are unchanged during the run
	void setIndependentParameters(SLHAReader_MEKD &slha);
	// Set couplings that are unchanged during the run
	void setIndependentCouplings();
	// Set parameters that are changed event by event
	void setDependentParameters();
	// Set couplings that are changed event by event
	void setDependentCouplings();

  private:
	static Parameters_MEKD *instance;
};

#endif // Parameters_MEKD_H
