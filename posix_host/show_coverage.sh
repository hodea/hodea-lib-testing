# Copyright (c) 2017, Franz Hollerer. All rights reserved.
# This code is licensed under the MIT License (MIT).
# See LICENSE file for full details.

# This scrip runs a program which compiled with clang for code coverage
# analysis and creates a report form generated profiling data.

if [ $# -ne 1 ]; then
    echo "usage: $0 file"
    exit 1
fi

export LLVM_PROFILE_FILE=$1.profraw

eval $1

llvm-profdata merge -sparse $LLVM_PROFILE_FILE -o $1.profdata
llvm-cov show $1 -instr-profile=$1.profdata
llvm-cov report $1 -instr-profile=$1.profdata

