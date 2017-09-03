# Copyright (c) 2017, Franz Hollerer. All rights reserved.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ---------------------------------------- project specific settings ---

# relative path to the hodea library
HODEA_ROOT_DIR := ../../hodea-lib

# relative path to the CMSIS package
CMSIS_ROOT_DIR := ../../hodea-stm32f0-vpkg/CMSIS

# executable to generate
export TARGET := stm32f0_combined_tests

# assembler source files
export AS_SOURCE_FILES := \
    src/stm32f0/startup_stm32f091xc.s

# C source files
export C_SOURCE_FILES := \
    src/stm32f0/system_stm32f0xx.c

# C++ source files
export CXX_SOURCE_FILES := \
    src/main.cpp 

# Project specific flags which need to be passed to the compiler
export USER_FLAGS := -DSTM32F091xC -mcpu=cortex-m0 -mthumb

# Linker script
export LINKER_SCRIPT := src/stm32f0/STM32F091RCTx_FLASH.ld

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS := \
    $(HODEA_ROOT_DIR) \
    $(CMSIS_ROOT_DIR)/Include \
    $(CMSIS_ROOT_DIR)/Device/ST/STM32F0xx/Include

# root of the build directory
BUILD_ROOT_DIR := ./build

# ----------------------------- let the build support do the rest... ---

include $(HODEA_ROOT_DIR)/build_support/cross_compile_std_targets.make.inc

