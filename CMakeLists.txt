cmake_minimum_required(VERSION 3.22)
project(qemu_semihosting_tricore LANGUAGES C ASM)
message("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(cmake/ConfigurationsAndLibraries)

add_executable(${CMAKE_PROJECT_NAME}
    Cpu0_Main.c
    Cpu1_Main.c
    Cpu2_Main.c
)

# Add linked libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
    ConfigurationsAndLibraries
)

include(CTest)
enable_testing()

# The test uses TriCore test device to report results back to the host.
# The test has a timeout of 30 seconds.
add_executable(exit_test)
target_sources(exit_test PRIVATE
    # Add test sources.
    ${CMAKE_SOURCE_DIR}/Tests/exit_test.c
    # Add application sources.
    # Add system and startup sources.
    ${CMAKE_SOURCE_DIR}/Tests/ssw_tc0.c
)
target_link_libraries(exit_test
    ConfigurationsAndLibraries
)
set_target_properties(exit_test PROPERTIES TIMEOUT 30)

add_test(NAME exit_test
    COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} ${CMAKE_BINARY_DIR}/exit_test.elf
)
set_tests_properties(exit_test PROPERTIES
    WILL_FAIL TRUE
)
