/*
 * rwonce.h
 * Copyright (c) 2023, Roy Ratcliffe, Northumberland, United Kingdom
 * SPDX-License-Identifier: MIT
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
