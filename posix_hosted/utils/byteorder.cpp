// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/bitmanip.hpp>

using namespace hodea;

TEST_CASE("Byteorder: fetch_le() ", "[fetch_le]")
{
    unsigned v = 0xcafeU;
    
    clr_bit(v, 0x028eU);
    REQUIRE(v == 0xc870U);
}

