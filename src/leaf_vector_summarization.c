/****************************************************************************
 *                     Summarization of a "leaf vector"                     *
 ****************************************************************************/
#include "leaf_vector_summarization.h"

#include "Rvector_summarization.h"
#include "leaf_vector_utils.h"


int _summarize_leaf_vector(SEXP lv, int d,
		const SummarizeOp *summarize_op, SummarizeResult *res)
{
	int lv_len;
	SEXP lv_offs, lv_vals;

	lv_len = _split_leaf_vector(lv, &lv_offs, &lv_vals);
	/* We add 'd - lv_len' instead of 'd' because _summarize_Rvector()
	   will add 'lv_len'. */
	res->totalcount += d - lv_len;
	res->nzcount += lv_len;  /* assuming 'lv_vals' contains no zeros! */
	return _summarize_Rvector(lv_vals, summarize_op, res);
}
