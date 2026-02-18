cmake_minimum_required(VERSION 3.22)
project(Infra C)

add_library(Infra STATIC)
target_include_directories(Infra PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers

    # Special Function Register (SFR) definitions.
    ${CMAKE_CURRENT_SOURCE_DIR}/Sfr/TC37x

    # Start-up software (SSW) sources and headers.
    ${CMAKE_CURRENT_SOURCE_DIR}/Ssw/TC3xx/Tricore
)
target_sources(Infra PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers/CompilerDcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers/CompilerGcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers/CompilerGhs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers/CompilerGnuc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Tricore/Compilers/CompilerTasking.c

    # Start-up software (SSW) source files.
    ${CMAKE_CURRENT_SOURCE_DIR}/Ssw/TC3xx/Tricore/Ifx_Ssw_Infra.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Ssw/TC3xx/Tricore/Ifx_Ssw_Tc0.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Ssw/TC3xx/Tricore/Ifx_Ssw_Tc1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Ssw/TC3xx/Tricore/Ifx_Ssw_Tc2.c
)
target_link_libraries(Infra PUBLIC
    # Infrastructure depends on the Configurations library.
    # It accesses the Ifx_Cfg.h header file for configuration settings.
    Configurations
    # Needs assertion utilities from the Service library.
    Service
    iLLD
)
