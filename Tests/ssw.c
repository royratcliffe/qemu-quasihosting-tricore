#include "ssw.h"
#include "Ifx_Ssw.h"
#include "Ifx_Ssw_Infra.h"

void Ssw_initCSA(unsigned int *csa_begin, unsigned int *csa_end) {
  const unsigned int num_of_csa = (((unsigned int)csa_end - (unsigned int)csa_begin) / (IFX_SSW_CSA_SIZE << 2U));
  const unsigned int lcx_idx = num_of_csa - 3U;
  unsigned int *prv_csa = csa_begin;
  unsigned int *nxt_csa = csa_begin;

  /*
   * Iterate over all CSAs and link them in a linked list.
   */
  for (unsigned int csa_idx = 0U; csa_idx < num_of_csa; csa_idx++) {
    unsigned int cxi_adr = (unsigned int)nxt_csa;
    unsigned int cxi_val =
        ((cxi_adr & ((unsigned int)0xfU << 28U)) >> 12U) | ((cxi_adr & ((unsigned int)0xffffU << 6U)) >> 6U);

    /*
     * Link the previous CSA to the current one.
     * For the first CSA, set FCX register.
     */
    if (csa_idx == 0U) {
      Ifx_Ssw_MTCR(CPU_FCX, cxi_val);
    } else {
      *prv_csa = cxi_val;
    }

    /*
     * For the last CSA, link it to LCX register.
     */
    if (csa_idx == lcx_idx) {
      Ifx_Ssw_MTCR(CPU_LCX, cxi_val);
    }

    /*
     * Move to the next CSA.
     */
    prv_csa = nxt_csa;
    nxt_csa += IFX_SSW_CSA_SIZE;
  }

  /*
   * Terminate the linked list.
   */
  *prv_csa = 0U;
  Ifx_Ssw_DSYNC();
}
