# Copyright (c) 2017, Franz Hollerer. All rights reserved.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ---------------------------------------- project specific settings ---

# relative path to the hodea library
HODEA_ROOT_DIR := ../../hodea-lib

# relative path to third party libraries
THIRD_PARTY_ROOT_DIR := ../../third_party

# executable to generate
export TARGET := ts_utils

# C++ source files
export C_SOURCE_FILES :=

# C++ source files
export CXX_SOURCE_FILES := \
    main.cpp bitmanip.cpp byteorder.cpp

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS := \
    $(HODEA_ROOT_DIR) \
    $(THIRD_PARTY_ROOT_DIR)

# root of the build directory
BUILD_ROOT_DIR := ./build

# ----------------------------- let the build support do the rest... ---

include $(HODEA_ROOT_DIR)/build_support/posix_hosted_std_targets.make.inc

