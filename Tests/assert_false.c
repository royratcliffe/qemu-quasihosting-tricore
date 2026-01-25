#include <assert.h>

void core0_main(void) __attribute__((noreturn));

void core0_main(void) {
  assert(0 && "False is false");
}
