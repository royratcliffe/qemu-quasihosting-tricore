#include "core.h"

#include <assert.h>
#include <stdlib.h>

void core0_main(void) {
  assert(1 && "True is true");
  exit(0);
}
