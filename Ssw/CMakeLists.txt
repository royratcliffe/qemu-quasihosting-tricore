cmake_minimum_required(VERSION 3.22)
project(Ssw C)

add_library(Ssw STATIC)
target_include_directories(Ssw PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(Ssw PRIVATE
    ssw_tc0.c
    stdlib.c
)
target_link_libraries(Ssw
    Infra
)
