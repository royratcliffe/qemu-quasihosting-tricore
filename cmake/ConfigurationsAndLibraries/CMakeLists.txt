# The include directories and source files for the Configurations and Libraries
# have interdependencies. Compile them together in a single CMake target to
# avoid issues.
cmake_minimum_required(VERSION 3.22)
enable_language(C)

set(ConfigurationsAndLibraries_Include_Directories
    ${CMAKE_SOURCE_DIR}/Configurations
    ${CMAKE_SOURCE_DIR}/Libraries
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Irq
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Trap
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Mtu
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Mtu/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Pms
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Pms/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Port
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Port/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Src
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Src/Std
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Stm
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Stm/Std
    ${CMAKE_SOURCE_DIR}/Libraries/Infra
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Sfr
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Sfr/TC37A
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Sfr/TC37A/_Reg
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A/Tricore
    ${CMAKE_SOURCE_DIR}/Libraries/Service
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/_Utilities
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/SysSe
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/SysSe/Bsp
)

set(ConfigurationsAndLibraries_Sources
    ${CMAKE_SOURCE_DIR}/Configurations/Debug/sync_on_halt.c
    ${CMAKE_SOURCE_DIR}/Configurations/Ifx_Cfg_Ssw.c
    ${CMAKE_SOURCE_DIR}/Configurations/Ifx_Cfg_SswBmhd.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxAsclin_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxCan_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxCcu6_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxCpu_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxDma_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxEray_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxEvadc_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxFlash_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxGeth_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxGtm_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxHssl_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxI2c_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxMsc_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxMtu_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxPort_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxPsi5_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxQspi_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxScu_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxSent_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxSmu_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxSrc_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_Impl/IfxStm_cfg.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxAsclin_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxCan_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxCcu6_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxDmu_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxEdsadc_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxEray_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxEvadc_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxGeth_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxGpt12_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxGtm_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxI2c_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxMsc_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxPms_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxPort_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxPsi5_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxPsi5s_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxQspi_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxScu_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxSent_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/_PinMap/IfxSmu_PinMap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Irq/IfxCpu_Irq.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Std/IfxCpu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Cpu/Trap/IfxCpu_Trap.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Atom.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Cmu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dpll.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Dtm.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Psm.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Spe.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tbu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tim.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm_Tom.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Gtm/Std/IfxGtm.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Mtu/Std/IfxMtu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Pms/Std/IfxPmsEvr.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Pms/Std/IfxPmsPm.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Port/Std/IfxPort.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Src/Std/IfxSrc.c
    ${CMAKE_SOURCE_DIR}/Libraries/iLLD/TC37A/Tricore/Stm/Std/IfxStm.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.c
    ${CMAKE_SOURCE_DIR}/Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.c
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/SysSe/Bsp/Assert.c
    ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.c
)

# Create a static library target for Configurations and Libraries.
# EXCLUDE_FROM_ALL prevents this target from being built unless explicitly requested.
add_library(ConfigurationsAndLibraries STATIC EXCLUDE_FROM_ALL)

target_sources(ConfigurationsAndLibraries PRIVATE ${ConfigurationsAndLibraries_Sources})

# The include directories for the target need to be set as PUBLIC
# to propagating them to targets that link against Libraries.
target_include_directories(ConfigurationsAndLibraries PUBLIC ${ConfigurationsAndLibraries_Include_Directories})
