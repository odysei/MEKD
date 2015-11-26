//////////////////////////////////////////////
///  Evaluators for v3. Run by ME_runners  ///
//////////////////////////////////////////////
#ifndef MEKD_Evaluators_h
#define MEKD_Evaluators_h

#include "MEKD.h"

namespace mekd
{

template <class cME_q>
double ME_Evaluator_IS_q(const double &parton_coeff, const bool use_PDFs,
                         data &da, cME_q *ME_q,
                         const double &m_q, const long &PDG_q)
{
	/// Generic quark block.
	if (parton_coeff != 0 && ME_q != NULL) {
        const double m_q2 = m_q * m_q;
		da.p[0][3] = sqrt(da.p[0][0] * da.p[0][0] - m_q2);
		da.p[1][3] = -sqrt(da.p[1][0] * da.p[1][0] - m_q2);

		ME_q->updateProc();
		ME_q->setMomenta(da.p);
		ME_q->sigmaKin();
		const double *buffer = ME_q->getMatrixElements();

		if (use_PDFs) {
			const double ME_value1 = buffer[0] *
                                        pdfreader(PDG_q, da.PDFx1, da.m.sys) *
                                        pdfreader(-PDG_q, da.PDFx2, da.m.sys);
			return (ME_value1 + buffer[1] *
                                    pdfreader(-PDG_q, da.PDFx1, da.m.sys) *
                                    pdfreader(PDG_q, da.PDFx2, da.m.sys));
		} else
			return parton_coeff * (buffer[0] + buffer[1]);
	}

	return 0;
}

/// Down quark block. Down type (s-like)
template <class cME_d>
double ME_Evaluator_IS_d(const double &parton_coeff_d, const bool use_PDFs,
                         data &da, cME_d *ME_d)
{
    return ME_Evaluator_IS_q(parton_coeff_d, use_PDFs,
                             da, ME_d, da.m.d, 1);
}

/// Up quark block. Up type (c-like)
template <class cME_u>
double ME_Evaluator_IS_u(const double &parton_coeff_u, const bool use_PDFs,
                         data &da, cME_u *ME_u)
{
    return ME_Evaluator_IS_q(parton_coeff_u, use_PDFs,
                             da, ME_u, da.m.u, 2);
}

/// Strange quark block. Down type (s-like)
template <class cME_s>
double ME_Evaluator_IS_s(const double &parton_coeff_s, const bool use_PDFs,
                         data &da, cME_s *ME_s)
{
    return ME_Evaluator_IS_q(parton_coeff_s, use_PDFs,
                             da, ME_s, da.m.s, 3);
}

/// Charm quark block. Up type (c-like)
template <class cME_c>
double ME_Evaluator_IS_c(const double &parton_coeff_c, const bool use_PDFs,
                         data &da, cME_c *ME_c)
{
    return ME_Evaluator_IS_q(parton_coeff_c, use_PDFs,
                             da, ME_c, da.m.c, 4);
}

/// Bottom quark block. Down type (s-like)
template <class cME_b>
double ME_Evaluator_IS_b(const double &parton_coeff_b, const bool use_PDFs,
                         data &da, cME_b *ME_b)
{
    return ME_Evaluator_IS_b(parton_coeff_b, use_PDFs,
                             da, ME_b, da.m.b, 5);
}

/// end of namespace
}

#endif
/////////////////////////////
/// END OF Evaluators.h   ///
/////////////////////////////