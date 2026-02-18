/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file core.c
 * \brief Core-specific function definitions.
 * \details This source file contains definitions for core-specific functions used
 * in the TriCore test suite.
 */

#include "core.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void core_exit(int code) {
  /*
   * Write the exit code to the TriCore test device to indicate the reason for
   * exit.
   */
  exit(code);
}

int core_printf(const char *format, ...) {
  /*
   * Forward the formatted string to the standard output stream. The output is
   * captured by the TriCore test device and can be used for debugging and
   * verification purposes.
   */
  va_list va;
  va_start(va, format);
  int rc = vprintf(format, va);
  va_end(va);
  return rc;
}
