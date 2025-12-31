set(CMAKE_SYSTEM_NAME TriCore)
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

set(CMAKE_EXECUTABLE_SUFFIX_C .elf)

# Disable cores 1 an 2. The emulator only supports core 0.
# The Infineon start-up software (SSW) requires these definitions.
# Otherwise, the SSW will try to initialise all three cores,
# which leads to errors in the emulator.
add_compile_definitions(IFX_CFG_SSW_ENABLE_TRICORE1=0U)
add_compile_definitions(IFX_CFG_SSW_ENABLE_TRICORE2=0U)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Specify compiler flags.
set(CMAKE_C_FLAGS "--std=c99 -Wall -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Specify linker flags.
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -T\"${CMAKE_SOURCE_DIR}/Lcf_Gnuc_Tricore_Tc.lsl\"")
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -nocrt0 -Wl,--gc-sections -mtc162")
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -Wl,--print-memory-usage")

# QEMU System TriCore emulator configuration for cross-compiling tests.
# qemu-system-tricore.exe" -machine help
# Supported machines are:
# KIT_AURIX_TC277_TRB  Infineon AURIX TriBoard TC277 (D-Step)
# none                 empty machine
# tricore_testboard    a minimal TriCore board
set(CMAKE_CROSSCOMPILING_EMULATOR qemu-system-tricore
    -machine KIT_AURIX_TC277_TRB
    -nographic
    -no-reboot
    -kernel
)
