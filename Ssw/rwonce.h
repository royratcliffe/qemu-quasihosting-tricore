/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2023, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file rwonce.h
 * \brief Macros for single-read and single-write access.
 * \details This header defines two macros, \c READ_ONCE and \c WRITE_ONCE,
 * which are used to ensure that a variable is read or written exactly once,
 * preventing compiler optimisations from reordering or eliminating these
 * accesses. The \c READ_ONCE macro reads a variable in a way that guarantees it
 * is read from memory exactly once, while the \c WRITE_ONCE macro writes to a
 * variable in a way that guarantees it is written to memory exactly once. These
 * macros are particularly useful in concurrent programming scenarios where
 * multiple threads may access the same variable, and it is important to ensure
 * that each thread sees a consistent view of the variable's value.
 */

#pragma once

/*!
 * \brief Always reads once.
 * \param lvalue Readable left-hand expression.
 *
 * The readable always reads once, even if already accessed and fully optimised.
 * In other words, the implementation guarantees a single memory-read operation.
 * Makes use of C11's `volatile` modifier and `typeof` built-in function.
 */
#define READ_ONCE(lvalue) (*(const volatile typeof(lvalue) *)&(lvalue))

/*!
 * \brief Writes once atomically.
 * \param lvalue Left-hand mutable expression.
 * \param rvalue Right-hand value to write once.
 *
 * Overrides any C optimisations that compile an assignment to less-than-atomic
 * write access by casting the left-hand value to a mutable volatile.
 */
#define WRITE_ONCE(lvalue, rvalue)                                                                                     \
  do {                                                                                                                 \
    *(volatile typeof(lvalue) *)&(lvalue) = (rvalue);                                                                  \
  } while (0)
