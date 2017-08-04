# Copyright (c) 2017, Franz Hollerer.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ---------------------------------------- project specific settings ---

# path to the hodea library
export HODEA_ROOT_DIR := ../../hodea

# executable to generate
export TARGET := ts_hdp

# C++ source files
export C_SOURCE_FILES := \
    hdp/hdp.c

# C++ source files
export CXX_SOURCE_FILES := \
    ts_hdp.cpp \
    hdp/hdp.cpp

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS := \
    $(HODEA_ROOT_DIR)

# root of the build directory
BUILD_ROOT_DIR := ./build

# ----------------------------the make support files do the reset... ---

include $(HODEA_ROOT_DIR)/make/posix_hosted_std_targets.mk.inc

