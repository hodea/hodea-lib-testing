// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/ureverse.hpp>

using namespace hodea;

TEST_CASE("ureverse: urev16()", "[urev16]")
{
    REQUIRE(urev16(0x0123) == 0x2301);
}

TEST_CASE("ureverse: urev32()", "[urev32]")
{
    REQUIRE(urev32(0x01234567) == 0x67452301);
}

TEST_CASE("ureverse: urev64()", "[urev64]")
{
    REQUIRE(urev64(0x0123456789abcdefLLU) == 0xefcdab8967452301LLU);
}

