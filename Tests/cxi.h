/*!
 * \file cxi.h
 * \brief Macros to convert between CXI values and CSA pointers.
 * \details This header defines two macros, \c CXI_OF_CSA and \c CSA_OF_CXI,
 * which are used to convert between Context Save Area (CSA) pointers and their
 * corresponding CXI values on the TriCore architecture.
 */

#pragma once

#include <Platform_Types.h>

/*!
 * \brief Calculate the CXI value for a given CSA pointer.
 * \param csa_adr Pointer to the CSA.
 * \return The CXI value corresponding to the CSA pointer.
 */
#define CXI_OF_CSA(csa_adr)                                                                                            \
  ((((uint32)(csa_adr) & ((uint32)0xfU << 28U)) >> 12U) | (((uint32)(csa_adr) & ((uint32)0xffffU << 6U)) >> 6U))

/*!
 * \brief Calculate the CSA pointer for a given CXI value.
 * \param cxi_val The CXI value.
 * \return Pointer to the CSA corresponding to the CXI value.
 */
#define CSA_OF_CXI(cxi_val) (uint32 *)((((cxi_val) & 0xf0000U) << 12U) | (((cxi_val) & 0xffffU) << 6U))
