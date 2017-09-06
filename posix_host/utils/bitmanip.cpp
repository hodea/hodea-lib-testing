// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/bitmanip.hpp>

using namespace hodea;

TEST_CASE("Bit manipulation: Bitmask ", "[Bitmask]")
{
    constexpr uint8_t msk = Bitmask<uint8_t>{}.bit(0).bit(2);
    REQUIRE(msk == 0x5);
}

TEST_CASE("Bit manipulation: bit_pos_to_msk()", "[bit_pos_to_msk]")
{
    constexpr uint8_t m8 = bit_to_msk(7);

    REQUIRE(m8 == 0x80U);
}

TEST_CASE("Bit manipulation: clr_bit() ", "[clr_bit]")
{
    unsigned v = 0xcafeU;
    
    clr_bit(v, 0x028eU);
    REQUIRE(v == 0xc870U);
}

TEST_CASE("Bit manipulation: set_bit()", "[set_bit]")
{
    unsigned v = 0;
    int8_t m = 0xff;

    set_bit(v, m);
    REQUIRE(v == 0xff);
}

TEST_CASE("Bit manipulation: set_bit_value()", "[set_bit_value]")
{
    unsigned v = 0xaa;

    set_bit_value(v, 0x55, 1);
    REQUIRE(v == 0xff);

    set_bit_value(v, 0xaa, 0);
    REQUIRE(v == 0x55);
}

TEST_CASE("Bit manipulation: modify_bits()", "[modify_bits]")
{
    unsigned v = 0xffaaffaa;
    modify_bits(v, 0x5500aa00, 0x00550055);
    REQUIRE(v == 0xaaff55ff);
}

TEST_CASE("Bit manipulation: is_bit_set()", "[is_bit_set]")
{
    unsigned v = 3;

    REQUIRE(is_bit_set(v, 1) == true);
    REQUIRE(is_bit_set(v, 2) == true);
    REQUIRE(is_bit_set(v, 3) == true);
    REQUIRE(is_bit_set(v, 4) == false);
    REQUIRE(is_bit_set(v, 7) == false);
}

