cmake_minimum_required(VERSION 3.22)
project(iLLD C)

add_library(iLLD STATIC)
target_include_directories(iLLD PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Irq
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Trap
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Can
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Can/Can
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Mtu
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Mtu/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Pms
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Pms/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Port
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Port/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Src
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Src/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Stm
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Stm/Std
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_PinMap
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_PinMap/TC37x

    # Do not include the Bsp directory here. It defines Assert.h which conflicts
    # with the standard assert.h on platforms that use case-insensitive file
    # systems, e.g. Windows.
    # ${CMAKE_SOURCE_DIR}/Libraries/Service/CpuGeneric/SysSe/Bsp
)
target_sources(iLLD PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxAsclin_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxCan_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxCcu6_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxCpu_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxEray_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxEvadc_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxFlash_cfg_TC37x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxGeth_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxGtm_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxHssl_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxI2c_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxMtu_cfg_TC37x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxPort_cfg_TC37x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxQspi_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/_Impl/IfxStm_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Irq/IfxCpu_Irq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Std/IfxCpu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Cpu/Trap/IfxCpu_Trap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Atom.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Cmu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Dpll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Dtm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Psm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Spe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Tbu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm_Tom.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Gtm/Std/IfxGtm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Mtu/Std/IfxMtu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Pms/Std/IfxPmsEvr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Pms/Std/IfxPmsPm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Port/Std/IfxPort.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std/IfxScuCcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std/IfxScuEru.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std/IfxScuLbist.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std/IfxScuRcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Scu/Std/IfxScuWdt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Src/Std/IfxSrc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Stm/Std/IfxStm.c

    # CAN sources are added here instead of the TC3xx/Tricore/Can directory
    # because they depend on the Canny_Ifx library, which in turn depends on
    # iLLD. Adding them to the Can directory would create a circular dependency.
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Can/Std/IfxCan.c
    ${CMAKE_CURRENT_SOURCE_DIR}/TC3xx/Tricore/Can/Can/IfxCan_Can.c
)
target_link_libraries(iLLD
    # iLLD depends on the Configurations library.
    # Sources access the Ifx_Cfg.h header file for configuration settings.
    Configurations
)
