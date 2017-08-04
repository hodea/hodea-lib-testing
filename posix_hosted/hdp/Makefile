# Copyright (c) 2017, Franz Hollerer.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ------------------------------------------- user defined variables ---

# path to the hodea library
HODEA_ROOT_DIR := ../../hodea

# executable to generate
TARGET := ts_hdp

# C++ source files
C_SOURCE_FILES := \
    hdp/hdp.c

# C++ source files
CXX_SOURCE_FILES := \
    ts_hdp.cpp \
    hdp/hdp.cpp

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS := \
    $(HODEA_ROOT_DIR)/..

# root of the build directory
BUILD_ROOT_DIR := ./build

# ---------------------------------------- project specific settings ---

CFLAGS = -g -MD
CXXFLAGS = $(CFLAGS)

# ------------------------------------------------ derived variables ---

# name of this makefile
MAKEFILE_NAME := $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

ifndef DEBUG
    DEBUG = 0
endif

ifneq ($(DEBUG), 0)
    CFLAGS += -O0
    BUILD_DIR := $(BUILD_ROOT_DIR)/debug
else
    CFLAGS += -O3
    BUILD_DIR := $(BUILD_ROOT_DIR)/release
endif

ifdef IN_BUILD
    INCLUDES = $(patsubst %,-I $(TOP_DIR)/%,$(INCLUDE_DIRS))
    CXXFLAGS += $(INCLUDES)

    C_OBJ_FILES := $(addsuffix .o, $(C_SOURCE_FILES))
    CXX_OBJ_FILES := $(addsuffix .o, $(CXX_SOURCE_FILES))
endif

# ---------------------------------------------------------- targets ---

.PHONY: all clean release debug do_build

all release: $(BUILD_DIR) do_build

clean:
	rm -rf $(BUILD_ROOT_DIR)

debug:
	$(MAKE) DEBUG=1 all

$(BUILD_DIR):
	for d in $(dir $(C_SOURCE_FILES) $(CXX_SOURCE_FILES)) ; do \
		mkdir -p $(BUILD_DIR)/$$d;  \
	done

do_build:
	$(MAKE) -C $(BUILD_DIR) -f $(CURDIR)/$(MAKEFILE_NAME) \
  		TOP_DIR=$(CURDIR) IN_BUILD=1 $(TARGET)

ifdef IN_BUILD

-include $(C_OBJ_FILES:.o=.d)
-include $(CXX_OBJ_FILES:.o=.d)

$(TARGET): $(C_OBJ_FILES) $(CXX_OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $@

$(C_OBJ_FILES):
	$(CC) $(CFLAGS) -c $(TOP_DIR)/$(basename $@) -o $@

$(CXX_OBJ_FILES):
	$(CXX) $(CXXFLAGS) -c $(TOP_DIR)/$(basename $@) -o $@

endif
