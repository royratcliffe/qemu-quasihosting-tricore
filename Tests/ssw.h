#ifndef SSW_H
#define SSW_H

#include "Ifx_Ssw_Infra.h"

/*!
 * \brief Initialise the Context Save Area (CSA) linked list.
 * \details This function initialises the CSA linked list for the CPU on which
 * it is called. It links all CSAs in a linked list fashion and sets the FCX and
 * LCX registers accordingly.
 * \param csa_begin Pointer to the start of the CSA area.
 * \param csa_end Pointer to the end of the CSA area.
 * \note Each CSA consists of 16 words (64 bytes). The number of CSAs is
 * calculated based on the provided begin and end pointers.
 * \note The function ensures that all memory operations are completed before
 * returning by executing a DSYNC instruction.
 * \note This function \e must always be declared with the \c IFX_SSW_INLINE
 * macro, which declares it as an \c always_inline function. This avoids any
 * function call overhead and stack usage before the CSA is initialised;
 * otherwise, calling it as a regular function would require a CSA for saving
 * the context, leading to a deadlock situation, since the CSA linked list is
 * not yet initialised.
 * \warning This function should be called only once during system initialisation
 * and before any context switch or interrupt handling occurs.
 * \warning Incorrect initialisation of the CSA linked list can lead to system
 * instability and unpredictable behaviour.
 * \warning The caller must ensure that the provided memory region for CSAs is
 * valid and not used by other parts of the system.
 * \warning The memory region defined by \c csa_begin and \c csa_end must be
 * properly 64-byte aligned and sized to hold an integer number of CSAs.
 */
IFX_SSW_INLINE void Ssw_initCSA(unsigned int *csa_begin, unsigned int *csa_end) {
  /*
   * Calculate the number of CSAs and the LCX index. Each CSA consists of
   * IFX_SSW_CSA_SIZE words (16 words to be exact). The number of CSAs can be
   * calculated as:
   *
   *    (((unsigned int)csa_end - (unsigned int)csa_begin) / (IFX_SSW_CSA_SIZE << 2U))
   */
  const unsigned int num_of_csa = (csa_end - csa_begin) / IFX_SSW_CSA_SIZE;
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
     * Link the previous CSA to the current one. For the first CSA, set FCX
     * register.
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
   * Terminate the linked list. Apply a data memory barrier to ensure all memory
   * operations are completed.
   */
  *prv_csa = 0U;
  Ifx_Ssw_DSYNC();
}

#endif /* SSW_H */
