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

# This test is run using QEMU emulating a Netduino Plus 2 board (STM32F407VG).
# The test uses semihosting to report results back to the host.
# The test has a timeout of 30 seconds.
add_executable(a_test)
target_sources(a_test PRIVATE
    # Add test sources.
    ${CMAKE_SOURCE_DIR}/Tests/a_test.c
    # Add application sources.
    # Add system and startup sources.
)
target_include_directories(a_test PRIVATE ${MX_Test_Include_Dirs})
target_compile_definitions(a_test PRIVATE ${MX_Test_Defines_Syms})
add_test(NAME a_test COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} ${CMAKE_BINARY_DIR}/a_test.elf)
set_target_properties(a_test PROPERTIES TIMEOUT 30)
