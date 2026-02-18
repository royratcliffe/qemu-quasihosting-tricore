cmake_minimum_required(VERSION 3.22)
project(Service C)

add_library(Service STATIC)
target_include_directories(Service PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/CpuGeneric
    ${CMAKE_CURRENT_SOURCE_DIR}/CpuGeneric/_Utilities
)
target_sources(Service PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CpuGeneric/SysSe/Bsp/Assert.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CpuGeneric/SysSe/Bsp/Bsp.c
)
target_link_libraries(Service
    Configurations
)
