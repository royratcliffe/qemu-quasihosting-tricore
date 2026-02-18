/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file unistd.c
 * \brief Minimal implementation of unistd.h functions for the TriCore test suite.
 * \details This source file provides minimal implementations of the functions
 * declared in unistd.h, which are required by the standard library functions
 * used in the TriCore test suite. The implementations are designed to work with
 * the TriCore test device, allowing for basic input/output operations and
 * program termination. The write function is implemented to send output to the
 * TriCore test device, while the exit and abort functions are implemented to
 * signal program termination to the test device. This file serves as a bridge
 * between the standard library functions and the TriCore test device, enabling
 * the test code to perform necessary operations while running on the emulated
 * TriCore architecture.
 * \note The write function is implemented to handle writes to standard output
 * (file descriptor 1) and standard error (file descriptor 2) by sending the
 * output to the TriCore test device. For any other file descriptors, the
 * function sets errno to EBADF and returns -1, indicating a bad file
 * descriptor.
 * \note The exit function sends the exit status code to the TriCore test device
 * and then enters an infinite loop to prevent returning to the caller, as the
 * test device will handle the termination of the program.
 * \note The abort function calls exit with a specific status code (8 in this
 * case) to indicate an abnormal termination, and it also does not return to the
 * caller.
 * \warning The implementations in this file are minimal and may not cover all
 * edge cases or conform to the full specifications of the standard library
 * functions. They are intended to provide just enough functionality to support
 * the test code running on the TriCore architecture and may not be suitable for
 * general-purpose use.
 * \warning The write function assumes that the TriCore test device is properly
 * set up to handle the output and may not work correctly if the test device is
 * not configured or if the file descriptors are used in an unexpected way.
 * \warning The exit and abort functions rely on the TriCore test device to
 * handle program termination, and their behavior may be undefined if the test
 * device does not function as expected.
 * \warning Users of this file should be aware that it is a minimal
 * implementation and may not provide the full functionality of the standard
 * library functions, and it should be used with caution in contexts outside of
 * the TriCore test suite.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rwonce.h"
#include "tricore_testdevice.h"

/*
 * Note that Unix write returns ssize_t, which is signed according to POSIX.
 * Newlib does not follow this convention. It returns int instead.
 */
int write(int fd, const void *buf, size_t nbyte) {
  switch (fd) {
  case 1:
  case 2:
    /*
     * Write each character to the TriCore test device, ensuring that each
     * character is written exactly once using the WRITE_ONCE macro.
     */
    for (size_t i = 0; i < nbyte; i++) {
      WRITE_ONCE(*TRICORE_TESTDEVICE, 0x100U | (((const char *)buf)[i] & 0xffU));
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
