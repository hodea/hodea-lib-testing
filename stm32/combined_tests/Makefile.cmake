
BUILD_ROOT_DIR := ./build/armgcc

BUILD_TYPE ?= Release

.PHONY: all clean release debug stm32f0

all: stm32f0

stm32f0: $(BUILD_ROOT_DIR)/stm32f0/CMakeLists.txt
	cd $(BUILD_ROOT_DIR)/stm32f0 && \
        cmake -DPROJECT_ROOT_DIR=$(CURDIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
	make -C $(BUILD_ROOT_DIR)/stm32f0

$(BUILD_ROOT_DIR)/stm32f0/CMakeLists.txt:
	mkdir -p $(dir $@)
	cp cmake_stm32f0.txt $@

release: 
	make -f Makefile.cmake BUILD_TYPE=Release all

debug: 
	make -f Makefile.cmake BUILD_TYPE=Debug all

clean:
	rm -rf $(BUILD_ROOT_DIR)
