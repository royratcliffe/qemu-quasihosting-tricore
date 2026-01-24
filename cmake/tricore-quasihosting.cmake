# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026, Roy Ratcliffe, Northumberland, United Kingdom
# CMake module for setting up TriCore quasihosting tests.

# CMake function to add TriCore quasihosting tests.
# Parameters:
# TEST_NAME - Name of the test executable.
# TEST_SOURCES - List of source files for the test.
# APP_SOURCES - List of application source files to include in the test.
# SYSTEM_SOURCES - List of system source files, e.g. startup code.
# LINK_LIBRARIES - List of libraries to link against.
# TIMEOUT - Optional timeout for the test.
# Usage:
# add_tricore_quasihosting_test(TEST_NAME my_test
#     TEST_SOURCES
#         test1.c
#         test2.c
#     APP_SOURCES
#         app1.c
#         app2.c
#     SYSTEM_SOURCES
#         system1.c
#         system2.c
#     LINK_LIBRARIES
#         library1
#         library2
# )
function(add_tricore_quasihosting_test)
    set(options)
    set(oneValueArgs TEST_NAME TIMEOUT)
    set(multiValueArgs TEST_SOURCES APP_SOURCES SYSTEM_SOURCES LINK_LIBRARIES LINK_OPTIONS)
    cmake_parse_arguments(ATQT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_executable(${ATQT_TEST_NAME})
    target_sources(${ATQT_TEST_NAME} PRIVATE
        ${TriCoreQuasihostingTestSources}
        ${ATQT_TEST_SOURCES}
        ${TriCoreQuasihostingAppSources}
        ${ATQT_APP_SOURCES}
        ${TriCoreQuasihostingSystemSources}
        ${ATQT_SYSTEM_SOURCES}
    )
    target_include_directories(${ATQT_TEST_NAME} PRIVATE ${TriCoreQuasihostingIncludeDirectories})
    target_compile_definitions(${ATQT_TEST_NAME} PRIVATE ${TriCoreQuasihostingCompileDefinitions})

    # Link against the any additional libraries, e.g. TriCore math.
    target_link_libraries(${ATQT_TEST_NAME} PRIVATE
        ${TriCoreQuasihostingLinkLibraries}
        ${ATQT_LINK_LIBRARIES}
    )

    # Link with quasihosting specifications. The test device provides quasihosting
    # support for TriCore targets.
    target_link_options(${ATQT_TEST_NAME} PRIVATE
        ${TriCoreQuasihostingLinkOptions}
        ${ATQT_LINK_OPTIONS}
    )

    # Set timeout for the test if specified.
    if(ATQT_TIMEOUT)
        set_target_properties(${ATQT_TEST_NAME} PROPERTIES TIMEOUT ${ATQT_TIMEOUT})
    endif()

    add_test(NAME ${ATQT_TEST_NAME} COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:${ATQT_TEST_NAME}>)
endfunction()
