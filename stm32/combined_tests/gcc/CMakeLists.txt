cmake_minimum_required(VERSION 3.5)

set(CMAKE_SYSTEM_NAME Generic)
set(TARGET_TRIPLET "arm-none-eabi")
set(CMAKE_ASM_COMPILER "${TARGET_TRIPLET}-gcc")
set(CMAKE_C_COMPILER "${TARGET_TRIPLET}-gcc")
set(CMAKE_CXX_COMPILER "${TARGET_TRIPLET}-g++")
set(CMAKE_OBJCOPY "${TARGET_TRIPLET}-objcopy")

enable_language(ASM)

set(CMAKE_SOURCE_DIR "../src")

set(HODEA_ROOT_DIR "${CMAKE_SOURCE_DIR}/../../../hodea-lib")
set(CMSIS_ROOT_DIR "${CMAKE_SOURCE_DIR}/../../../hodea-stm32f0-vpkg/CMSIS")

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_BUILD_TYPE "Release")
#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

set(CMAKE_C_FLAGS_DEBUG "-O0")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_C_FLAGS "\
    -g -Wall -ffreestanding -ffunction-sections -fdata-sections \
    -fno-common -mcpu=cortex-m0 -mthumb -std=c11"
    )
set(CMAKE_CXX_FLAGS "\
    -g -Wall -ffreestanding -ffunction-sections -fdata-sections \
    -fno-common -mcpu=cortex-m0 -mthumb -std=c++11"
    )
set(CMAKE_EXE_LINKER_FLAGS "\
    --specs=nano.specs -Xlinker --gc-sections \
    -T${CMAKE_SOURCE_DIR}/stm32f0/STM32F091RCTx_FLASH.ld"
    )

add_executable(stm32f0_combined_tests
    "${CMAKE_SOURCE_DIR}/main.cpp"
    "${CMAKE_SOURCE_DIR}/stm32f0/system_stm32f0xx.c"
    "${CMAKE_SOURCE_DIR}/stm32f0/startup_stm32f091xc.s"
    )

include_directories(
    "${HODEA_ROOT_DIR}"
    "${CMSIS_ROOT_DIR}/Include"
    "${CMSIS_ROOT_DIR}/Device/ST/STM32F0xx/Include"
    )

add_definitions(-DSTM32F091xC)

# bin and hex
add_custom_command(TARGET stm32f0_combined_tests POST_BUILD COMMAND
    ${CMAKE_OBJCOPY} -Oihex stm32f0_combined_tests.elf stm32f0_combined_tests.hex
    )
add_custom_command(TARGET stm32f0_combined_tests POST_BUILD COMMAND
    ${CMAKE_OBJCOPY} -Obinary stm32f0_combined_tests.elf stm32f0_combined_tests.bin
    )
