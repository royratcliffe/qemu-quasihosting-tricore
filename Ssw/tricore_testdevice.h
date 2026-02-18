/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025, Roy Ratcliffe, Northumberland, United Kingdom
 */
/*!
 * \file tricore_testdevice.h
 * \brief Definition of the TriCore test device address for quasihosting.
 * \details This header file defines the address of the TriCore test device used
 * for quasihosting. The test device allows communication with the host
 * environment when running in a QEMU emulation context, enabling features such
 * as output capture and program termination signaling. The defined address can
 * be used by the SSW component and other parts of the TriCore test suite to
 * interact with the test device for various purposes, such as sending output or
 * signaling exit conditions.
 * \note The TriCore test device is used in a QEMU emulation context for
 * debugging and testing purposes. It provides a mechanism for the emulated
 * TriCore architecture to communicate with the host environment, allowing for
 * features such as output capture and program termination signaling.
 * \warning The address defined in this header is specific to the TriCore test
 * device and should not be used for other purposes or in contexts where it may
 * conflict with other memory-mapped devices or regions. Users should ensure
 * that the test device is properly configured and that the address is used in
 * accordance with the intended purpose of the test suite.
 */

#pragma once

#include <Platform_Types.h>

/*!
 * \brief Address of the TriCore test device used for quasihosting.
 * \details Writing to this address allows communication with the host
 * environment when running in a QEMU emulation context, typically used
 * for debugging and testing purposes.
 */
#define TRICORE_TESTDEVICE ((uint32 *)0xF0000000UL)
