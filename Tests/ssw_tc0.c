#include "ssw.h"

/*
 * Add options to eliminate usage of stack pointers unnecessarily. This is
 * important during the initialisation phase before the context save area (CSA)
 * is set up.
 */
#if defined(__TASKING__)
#pragma optimize R
#elif defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#endif

extern void core0_main(void) __attribute__((noreturn));

/*
 * Include linker symbols for core 0. Declares external symbols used for stack
 * pointers, interrupt vector table, context save area, etc.
 */
IFX_SSW_CORE_LINKER_SYMBOLS(0);

void _START(void) {
  /*
   * Set the PSW register to its default value. This clears the IS bit in case
   * of a warm start.
   */
  Ifx_Ssw_MTCR(CPU_PSW, IFX_CFG_SSW_PSW_DEFAULT);

  /*
   * Initialise A0, A1, A8, A9 with data segment addresses. Initialise A10 with
   * the user stack pointer.
   */
  Ifx_Ssw_setAddressReg(a0, __SDATA1(0));
  Ifx_Ssw_setAddressReg(a1, __SDATA2(0));
  Ifx_Ssw_setAddressReg(a8, __SDATA3(0));
  Ifx_Ssw_setAddressReg(a9, __SDATA4(0));
  Ifx_Ssw_setAddressReg(a10, __USTACK(0));

  /*
   * Apply a data memory barrier to ensure that all memory accesses are
   * completed before proceeding. This is crucial before initialising the
   * context save area (CSA).
   */
  Ifx_Ssw_DSYNC();
  Ssw_initCSA(__CSA(0), __CSA_END(0));
  Ifx_Ssw_ISYNC();

  /*
   * Initialise C variables: initialised and blank static storage.
   */
  Ifx_C_Init();

  /*
   * Jump to the main function of core 0.
   */
  Ifx_Ssw_jumpToFunction(core0_main);
}
