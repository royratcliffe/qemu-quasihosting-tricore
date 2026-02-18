/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file core.h
 * \brief Core-specific function declarations.
 * \details This header file contains declarations for core-specific functions used
 * in the TriCore test suite.
 */

#pragma once

/*!
 * \brief Core-0 main function declaration.
 * \details This function is marked with the "no return" attribute to indicate
 * that it does not return.
 */
void core0_main(void) __attribute__((noreturn));

/*!
 * \brief Core-1 main function declaration.
 */
void core1_main(void) __attribute__((noreturn));

/*!
 * \brief Core-2 main function declaration.
 */
void core2_main(void) __attribute__((noreturn));

/*!
 * \brief Core exit function declaration.
 * \details This function terminates the execution of the current core and
 * reports the exit code to the TriCore test device. The exit code can be used
 * to indicate the reason for exit, such as test success or failure. This
 * function is marked with the "no return" attribute to indicate that it does
 * not return to the caller.
 */
void core_exit(int code) __attribute__((noreturn));

/*!
 * \brief Core printf function.
 * \details This function formats and prints a string to the standard output
 * stream. The output is captured by the TriCore test device and can be used
 * for debugging and verification purposes.
 */
int core_printf(const char *format, ...);
