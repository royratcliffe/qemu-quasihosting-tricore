set(CMAKE_SYSTEM_NAME Tricore)
set(CMMAKE_SYSTEM_PROCESSOR tricore)

set(CMAKE_C_COMPILER_ID GNU)
set(CMAKE_CXX_COMPILER_ID GNU)

set(TOOLCHAIN_PREFIX tricore-elf-)

set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
# Use g++ as the linker for C++ projects.
# Use gcc as the linker for C projects.
set(CMAKE_LINKER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

set(CMAKE_EXECUTABLE_SUFFIX .elf)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Specify compiler flags.
set(CMAKE_C_FLAGS "--std=c99 -Wall -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})

set(CMAKE_C_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})

# Specify linker flags.
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -T\"${CMAKE_SOURCE_DIR}/Lcf_Gnuc_Tricore_Tc.lsl\"")
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -nocrt0 -Wl,--gc-sections -mtc162")
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -Wl,--print-memory-usage")
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_C_LINK_FLAGS})
