cmake_minimum_required(VERSION 3.22)
project(qemu_quasihosting_tricore LANGUAGES C ASM)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
message("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(cmake/ConfigurationsAndLibraries)

add_executable(${CMAKE_PROJECT_NAME}
    Cpu0_Main.c
    Cpu1_Main.c
    Cpu2_Main.c
)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    -nocrt0
    -T ${CMAKE_SOURCE_DIR}/Lcf_Gnuc_Tricore_Tc.lsl
    -Wl,-Map,$<TARGET_FILE_BASE_NAME:${CMAKE_PROJECT_NAME}>.map
)

# Add linked libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
    ConfigurationsAndLibraries
)

include(CTest)
include(tricore-quasihosting)
enable_testing()

# Disable cores 1 an 2 when testing. The emulator only supports core 0.
# The Infineon start-up software (SSW) requires these definitions.
# Otherwise, the SSW will try (and fail) to initialise all three cores,
# which leads to errors in the emulator.
set(TriCoreQuasihostingCompileDefinitions
    IFX_CFG_SSW_ENABLE_TRICORE1=0U
    IFX_CFG_SSW_ENABLE_TRICORE2=0U
)

set(TriCoreQuasihostingSystemSources
    ${CMAKE_SOURCE_DIR}/Tests/ssw_tc0.c
    ${CMAKE_SOURCE_DIR}/Tests/stdlib.c
)
set(TriCoreQuasihostingIncludeDirectories
    ${CMAKE_SOURCE_DIR}
)
set(TriCoreQuasihostingLinkLibraries
    ConfigurationsAndLibraries
)
set(TriCoreQuasihostingLinkOptions
    -T ${CMAKE_SOURCE_DIR}/Lcf_Gnuc_Tricore_Tc.lsl
)

# The test uses TriCore test device to report results back to the host.
# The test has a timeout of 30 seconds.
add_tricore_quasihosting_test(TEST_NAME exit_test
    TEST_SOURCES
        ${CMAKE_SOURCE_DIR}/Tests/exit_test.c
    TIMEOUT 30
)
set_tests_properties(exit_test PROPERTIES
    WILL_FAIL TRUE
)

add_tricore_quasihosting_test(TEST_NAME assert_true
    TEST_SOURCES
        ${CMAKE_SOURCE_DIR}/Tests/assert_true.c
)
add_tricore_quasihosting_test(TEST_NAME assert_false
    TEST_SOURCES
        ${CMAKE_SOURCE_DIR}/Tests/assert_false.c
)
set_tests_properties(assert_false PROPERTIES
    WILL_FAIL TRUE
)
