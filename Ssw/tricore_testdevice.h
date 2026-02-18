#pragma once

#include <Platform_Types.h>

/*!
 * \brief Address of the TriCore test device used for quasihosting.
 * \details Writing to this address allows communication with the host
 * environment when running in a QEMU emulation context, typically used
 * for debugging and testing purposes.
 */
#define TRICORE_TESTDEVICE ((uint32 *)0xF0000000UL)
