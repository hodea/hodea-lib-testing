// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/cpu_endian.hpp>

using namespace hodea;

TEST_CASE("Cpu endian: is_cpu_le()", "[is_cpu_le]")
{
    REQUIRE(is_cpu_le() == true);
}

TEST_CASE("Cpu endian: is_cpu_be()", "[is_cpu_be]")
{
    REQUIRE(is_cpu_be() == false);
}

