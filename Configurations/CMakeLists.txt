cmake_minimum_required(VERSION 3.22)
project(Configurations C)

add_library(Configurations STATIC)
target_include_directories(Configurations PUBLIC
    # The Ifx_Cfg.h configuration header lives here.
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(Configurations PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Ifx_Cfg_Ssw.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Ifx_Cfg_SswBmhd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug/sync_on_halt.c
)
target_link_libraries(Configurations
    Infra
)
