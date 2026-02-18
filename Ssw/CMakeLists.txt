cmake_minimum_required(VERSION 3.22)
project(Ssw C)

add_library(Ssw OBJECT)
target_include_directories(Ssw PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(Ssw PRIVATE
    ssw_tc0.c
    core.c
    unistd.c
)
target_link_libraries(Ssw
    Infra
)
