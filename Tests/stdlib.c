#include <stdlib.h>

#include "rwonce.h"
#include "tricore_testdevice.h"

/*
 * Exit the program by writing the status code to the TriCore test device. This
 * function does not return.
 */
void exit(int status) {
  WRITE_ONCE(*TRICORE_TESTDEVICE, status);
  while (1) {
    ;
  }
}

/*
 * Abort the program by calling exit with a specific status code. Why exit code
 * 8? It's arbitrary but distinct. Exit codes do have meanings in some
 * environments. See https://tldp.org/LDP/abs/html/exitcodes.html for instance.
 * This function does not return.
 */
void abort(void) { exit(8); }
