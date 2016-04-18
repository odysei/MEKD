//////////////////////////////////////////////
///  Evaluators for v3. Run by ME_runners  ///
//////////////////////////////////////////////
#ifndef MEKD_Evaluators_h
#define MEKD_Evaluators_h

#include "MEKD.h"

namespace mekd
{

template <class cME> double ME_Evaluator_IS_no(const data &da, cME *ME)
{
    /// No initial state block
    if (ME != nullptr) {
        vector<double *> p(da.p.size() - 1); // local "copy" for 1->N
        double p_X[4] = {0, 0, 0, 0};
        p[0] = p_X;
        for (unsigned int i = 2; i < da.p.size(); ++i)
            p[i - 1] = da.p[i];

        for (unsigned int i = 1; i < p.size(); ++i) {
            p[0][0] += da.p[i][0];
            p[0][1] += da.p[i][1];
            p[0][2] += da.p[i][2];
            p[0][3] += da.p[i][3];
        }

        ME->updateProc();
        ME->setMomenta(p);
        ME->sigmaKin();
        const double *buffer = ME->getMatrixElements();

        return buffer[0];
    }

    return 0;
}

template <class cME_gg>
double ME_Evaluator_IS_gg(const bool use_PDFs, data &da, cME_gg *ME_gg)
{
    /// gg block
    if (ME_gg != nullptr) {
        da.p[0][3] = da.p[0][0];
        da.p[1][3] = -da.p[1][0];

        ME_gg->updateProc();
        ME_gg->setMomenta(da.p);
        ME_gg->sigmaKin();
        const double *buffer = ME_gg->getMatrixElements();

        if (use_PDFs) {
            return buffer[0] * pdfreader(21, da.PDFx1, da.m.sys) *
                   pdfreader(21, da.PDFx2, da.m.sys);
        } else
            return buffer[0];
    }

    return 0;
}

template <class cME_qqx>
double ME_Evaluator_IS_qqx(const bool use_PDFs, data &da, cME_qqx *ME_qqx,
                           const double &m_q, const long &PDG_q)
{
    /// Generic quark block.
    if (ME_qqx != nullptr) {
        const double m_q2 = m_q * m_q;
        da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - m_q2);
        da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - m_q2);

        ME_qqx->updateProc();
        ME_qqx->setMomenta(da.p);
        ME_qqx->sigmaKin();
        const double *buffer = ME_qqx->getMatrixElements();

        if (use_PDFs) {
            const double ME_value1 = buffer[0] *
                                     pdfreader(PDG_q, da.PDFx1, da.m.sys) *
                                     pdfreader(-PDG_q, da.PDFx2, da.m.sys);
            return (ME_value1 +
                    buffer[1] * pdfreader(-PDG_q, da.PDFx1, da.m.sys) *
                        pdfreader(PDG_q, da.PDFx2, da.m.sys));
        } else
            return (buffer[0] + buffer[1]);
    }

    return 0;
}

/// Down quark block. Down type (s-like)
template <class cME_ddx>
double ME_Evaluator_IS_ddx(const bool use_PDFs, data &da, cME_ddx *ME_ddx)
{
    return ME_Evaluator_IS_qqx(use_PDFs, da, ME_ddx, da.m.d, 1);
}

/// Up quark block. Up type (c-like)
template <class cME_uux>
double ME_Evaluator_IS_uux(const bool use_PDFs, data &da, cME_uux *ME_uux)
{
    return ME_Evaluator_IS_qqx(use_PDFs, da, ME_uux, da.m.u, 2);
}

/// Strange quark block. Down type (s-like)
template <class cME_ssx>
double ME_Evaluator_IS_ssx(const bool use_PDFs, data &da, cME_ssx *ME_ssx)
{
    return ME_Evaluator_IS_qqx(use_PDFs, da, ME_ssx, da.m.s, 3);
}

/// Charm quark block. Up type (c-like)
template <class cME_ccx>
double ME_Evaluator_IS_ccx(const bool use_PDFs, data &da, cME_ccx *ME_ccx)
{
    return ME_Evaluator_IS_qqx(use_PDFs, da, ME_ccx, da.m.c, 4);
}

/// Bottom quark block. Down type (s-like)
template <class cME_bbx>
double ME_Evaluator_IS_bbx(const bool use_PDFs, data &da, cME_bbx *ME_bbx)
{
    return ME_Evaluator_IS_qqx(use_PDFs, da, ME_bbx, da.m.b, 5);
}

/// end of namespace
}

#endif
/////////////////////////////
/// END OF Evaluators.h   ///
/////////////////////////////