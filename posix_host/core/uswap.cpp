// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/uswap.hpp>

using namespace hodea;

TEST_CASE("uswap: uswap16()", "[uswap16]")
{
    REQUIRE(uswap16(0x0123) == 0x2301);
}

TEST_CASE("uswap: uswap32()", "[uswap32]")
{
    REQUIRE(uswap32(0x01234567) == 0x67452301);
}

TEST_CASE("uswap: uswap64()", "[uswap64]")
{
    REQUIRE(uswap64(0x0123456789abcdefLLU) == 0xefcdab8967452301LLU);
}

