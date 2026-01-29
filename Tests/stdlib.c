#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "rwonce.h"
#include "tricore_testdevice.h"

ssize_t write(int fd, const void *buf, size_t nbyte) {
  switch (fd) {
  case 1:
    /*
     * Write each character to the TriCore test device, ensuring that each
     * character is written exactly once using the WRITE_ONCE macro.
     */
    for (size_t i = 0; i < nbyte; i++) {
      WRITE_ONCE(*TRICORE_TESTDEVICE, 0x100U | (*(const char *)buf++ & 0xffU));
    }
    /*
     * Flush the output buffer by writing a magic value to the TriCore test
     * device. The test device flushes the emulator's standard output buffer
     * upon receiving this value.
     */
    WRITE_ONCE(*TRICORE_TESTDEVICE, 0x200U);
    return nbyte;
  }
  errno = EBADF;
  return -1;
}

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
