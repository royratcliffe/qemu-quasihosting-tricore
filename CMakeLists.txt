cmake_minimum_required(VERSION 3.22)
project(qemu_semihosting_tricore LANGUAGES C ASM)
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
    -T ${CMAKE_SOURCE_DIR}/Lcf_Gnuc_Tricore_Tc.lsl
)

# Add linked libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
    ConfigurationsAndLibraries
)

include(CTest)
include(tricore-quasihosting)
enable_testing()

set(TriCoreQuasihostingSystemSources
    ${CMAKE_SOURCE_DIR}/Tests/ssw_tc0.c
)
set(TriCoreQuasihostingLinkLibraries
    ConfigurationsAndLibraries
)
set(TriCoreQuasihostingLinkOptions
    -T ${CMAKE_SOURCE_DIR}/testboard.lsl
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
