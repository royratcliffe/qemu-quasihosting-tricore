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
# Forcibly disable link libraries for the SSW. If some other target links to
# Ssw, it should not link to Infra. The SSW is a special case. It is not linked
# into the main executable, but instead its object files are linked directly.
# This is because the SSW contains the entry point for the application, and
# linking it as a library would not automatically link its object files.
# Therefore, we need to ensure that the SSW does not have any link libraries, as
# these would be ignored when linking the SSW object files directly.
set_target_properties(Ssw PROPERTIES INTERFACE_LINK_LIBRARIES "")
