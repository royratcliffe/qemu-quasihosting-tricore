/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file ssw.h
 * \brief Startup Software (SSW) header file.
 * \details This header file contains declarations and definitions for the
 * Startup Software (SSW) component of the TriCore test suite. It includes
 * function declarations for initialising the Context Save Area (CSA) linked
 * list, as well as macros for single-read and single-write access. The SSW
 * component provides essential services and utilities for the TriCore test
 * suite, including core initialisation, context management, and communication
 * with the TriCore test device. The functions and macros defined in this header
 * are used throughout the SSW implementation to ensure proper initialisation
 * and operation of the system software.
 * \note The SSW component is responsible for setting up the execution
 * environment for the TriCore architecture, including configuring the program
 * status word (PSW), initialising address registers, and ensuring that memory
 * operations are properly ordered using data and instruction synchronisation
 * barriers. It also provides core-specific functions for exiting and printing
 * output, which are used by the test code running on the emulated TriCore core.
 */

#ifndef SSW_H
#define SSW_H

#include <Ifx_Ssw_Infra.h>

#include "cxi.h"

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
   *
   * Why subtract three from the LCX index? Because LCX points to the last but
   * two context save areas in the linked list, so that when the last CSA is
   * allocated, LCX will point to the last CSA, and when that is allocated, LCX
   * will become equal to FCX, indicating CSA depletion.
   */
  const unsigned int num_of_csa = (csa_end - csa_begin) / IFX_SSW_CSA_SIZE;
  const unsigned int lcx_idx = num_of_csa - 3U;
  unsigned int *prv_csa = csa_begin;
  unsigned int *nxt_csa = csa_begin;

  /*
   * Iterate over all CSAs and link them in a linked list.
   */
  for (unsigned int csa_idx = 0U; csa_idx < num_of_csa; csa_idx++) {
    unsigned int cxi_val = CXI_OF_CSA(nxt_csa);

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
