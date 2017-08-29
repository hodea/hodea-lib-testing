# Copyright (c) 2017, Franz Hollerer. All rights reserved.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ---------------------------------------- project specific settings ---

# relative path to the hodea library
HODEA_ROOT_DIR := ../../hodea-lib

# relative path to the CMSIS package
CMSIS_ROOT_DIR := ../../hodea-stm32f0-cmsis

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

# Additional defines
export DEFINES := STM32F091xC

# Linker script
export LINKER_SCRIPT := src/stm32f0/STM32F091RCTx_FLASH.ld

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS := \
    $(HODEA_ROOT_DIR) \
    $(CMSIS_ROOT_DIR)/Include \
    $(CMSIS_ROOT_DIR)/Device/ST/STM32F0xx/Include

# root of the build directory
BUILD_ROOT_DIR := ./build

# ------------------------------------------------ default toolchain ---

ifeq ($(origin CC), default)
export CC = arm-none-eabi-gcc
endif

ifeq ($(origin CXX), default)
export CXX = arm-none-eabi-g++
endif

ifndef OBJCOPY
OBJCOPY := arm-none-eabi-objcopy
endif

# ----------------------------- let the build support do the rest... ---

include $(HODEA_ROOT_DIR)/build_support/cross_compile_std_targets.make.inc

