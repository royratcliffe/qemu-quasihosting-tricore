cmake_minimum_required(VERSION 3.22)
project(qemu_semihosting_tricore LANGUAGES C ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(cmake/Libraries)

add_executable(${CMAKE_PROJECT_NAME}
    Cpu0_Main.c
    Cpu1_Main.c
    Cpu2_Main.c
)

# Add linked libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
    Libraries
)
