# Copyright (c) 2017, Franz Hollerer. All rights reserved.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# ------------------------------------------- user defined variables ---

# list of executables to generate
TARGETS := $(basename $(wildcard *.cpp))

# everything in SOURCE_DIRS will be searched for source files
SOURCE_DIRS = \
    .

# everything in INCLUDE_DIRS will be searched for include files
INCLUDE_DIRS = \
    ../../
    

# ---------------------------------------- project specific settings ---

CXXFLAGS = -g -MD

# ------------------------------------------------ derived variables ---

# name of this makefile
MAKEFILE_NAME := $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

ifndef DEBUG
    DEBUG = 0
endif

ifneq ($(DEBUG), 0)
    CXXFLAGS += -O0
    BUILD_DIR := ./build/debug
else
    CXXFLAGS += -O3
    BUILD_DIR := ./build/release
endif

# magic to translate a list into a colon separated path for VPATH
# (http://stackoverflow.com/questions/1541844)
NOOP=
SPACE = $(NOOP) $(NOOP)
VPATH = $(subst $(SPACE),:,$(patsubst %,$(TOP_DIR)/%,$(SOURCE_DIRS)))

INCLUDES = $(patsubst %,-I $(TOP_DIR)/%,$(INCLUDE_DIRS))

CXXFLAGS += $(INCLUDES)

# ---------------------------------------------------------- targets ---

.PHONY: all clean debug

all:
	mkdir -p $(BUILD_DIR) && \
	$(MAKE) -C $(BUILD_DIR) -f $(CURDIR)/$(MAKEFILE_NAME) \
		TOP_DIR=$(CURDIR) TARGETS="$(TARGETS)" do_build

debug:
	$(MAKE) DEBUG=1 all

clean:
	rm -rf ./build

-include $(TARGETS:=.d)

do_build: $(TARGETS)

