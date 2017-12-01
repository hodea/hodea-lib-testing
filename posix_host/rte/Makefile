# Copyright (c) 2017, Franz Hollerer.
# SPDX-License-Identifier: MIT

# ---------------------------------------- project specific settings ---

TARGET := core
export BUILD_ROOT_DIR := ./build

# --------------------------------------- derived settings and rules ---

export PROJECT_ROOT_DIR ?= $(CURDIR)

export BUILD_TYPE ?= release

MAKEFILE := $(lastword $(MAKEFILE_LIST))

all:
	$(MAKE) -f $(MAKEFILE) CURRENT_TARGET=$(TARGET) $(TARGET)

debug:
	$(MAKE) -f $(MAKEFILE) BUILD_TYPE=debug

release:
	$(MAKE) -f $(MAKEFILE) BUILD_TYPE=release

coverage:
	$(MAKE) -f $(MAKEFILE) BUILD_TYPE=coverage

ifdef CURRENT_TARGET

BUILD_DIR := $(BUILD_ROOT_DIR)/$(BUILD_TYPE)

$(CURRENT_TARGET): $(BUILD_DIR)/CMakeLists.txt
	make -C $(BUILD_DIR)

$(BUILD_DIR)/CMakeLists.txt: \
    $(PROJECT_ROOT_DIR)/CMakeLists_$(CURRENT_TARGET).txt
	mkdir -p $(BUILD_DIR)
	cp $< $@
	cd $(BUILD_DIR) && \
	cmake -DPROJECT_ROOT_DIR=$(PROJECT_ROOT_DIR) \
	    -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

endif

clean:
	rm -rf $(BUILD_ROOT_DIR)
