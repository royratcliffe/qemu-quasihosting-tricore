#include "core.h"

#include <Ifx_Ssw_Infra.h>
#include <Platform_Types.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*!
 * \brief Size of a Context Save Area (CSA) in bytes.
 * \details Each CSA consists of 16 words (64 bytes) on the TriCore architecture.
 */
#define CSA_SIZE_BYTES sizeof(uint32[IFX_SSW_CSA_SIZE])

IFXCOMPILER_CORE_LINKER_SYMBOLS(0);

/*!
 * \brief Test to verify that the Context Save Area (CSA) is correctly aligned.
 * \details This test checks that the CSA area for core 0 is aligned to a
 * 64-byte boundary as required by the TriCore architecture. Misalignment of the
 * CSA can lead to system instability and unpredictable behaviour.
 */
void core0_main(void) {
  (void)printf("csa test\n");

  /*
   * Check that the CSA area is 64-byte aligned as required.
   */
  assert(((uint32)__CSA(0) & (CSA_SIZE_BYTES - 1)) == 0);
  assert(((uint32)__CSA_END(0) & (CSA_SIZE_BYTES - 1)) == 0);
  exit(0);
}
