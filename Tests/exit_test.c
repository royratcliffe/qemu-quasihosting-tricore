#include "core.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void core0_main(void) {
  /*
   * Write the string "EXIT" to the TriCore test device to indicate test
   * completion.
   */
  (void)printf("EXIT");

  /*
   * Write the magic value to the TriCore test device to flush the output
   * buffer.
   */
  assert(fflush(stdout) == 0);

  /*
   * Write a value to the TriCore test device to trigger an exit.
   * The value written determines the exit code of QEMU.
   */
  exit(8);
}
