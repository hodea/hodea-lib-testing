// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmanip.hpp>

using namespace hodea;

TEST_CASE("Bit manipulation: bit_to_mask()", "[bit_to_mask]")
{
    REQUIRE(bit_to_msk(3) == 0x08U);
}

TEST_CASE("Bit manipulation: bitmask()", "[bitmask]")
{
    constexpr auto m1 = bitmask<unsigned>(3); 
    REQUIRE(m1 == 0x08U);

    constexpr auto m2 = bitmask<unsigned>(0, 2); 
    REQUIRE(m2 == 0x03U);

    constexpr auto m3 = bitmask<unsigned>(2, 2); 
    REQUIRE(m3 == 0x0CU);
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

TEST_CASE("Bit manipulation: toggle_bit()", "[toggle_bit]")
{
    unsigned v = 0xffaaffaa;
    toggle_bit(v, 0x000000ff);
    REQUIRE(v == 0xffaaff55);
}

TEST_CASE("Bit manipulation: is_bit_set()", "[is_bit_set]")
{
    unsigned v = 3;

    REQUIRE(is_bit_set(v, 1) == true);
    REQUIRE(is_bit_set(v, 2) == true);
    REQUIRE(is_bit_set(v, 3) == true);
    REQUIRE(is_bit_set(v, 4) == false);
    REQUIRE(is_bit_set(v, 7) == true);

    REQUIRE(is_bit_set(v, 1, true) == true);
    REQUIRE(is_bit_set(v, 2, true) == true);
    REQUIRE(is_bit_set(v, 3, true) == true);
    REQUIRE(is_bit_set(v, 4, true) == false);
    REQUIRE(is_bit_set(v, 7, true) == false);
}

TEST_CASE("Bit manipulation: enum_bitmask()", "[enum_bitmask]")
{
    enum {
        b0 = 1,
        b1 = 2
    };

    unsigned v = 3;

    clr_bit(v, b0);
    REQUIRE(v == 2);

    set_bit(v, b0);
    REQUIRE(v == 3);

    set_bit_value(v, b1, 0);
    REQUIRE(v == 1);

    modify_bits(v, b0, b1);
    REQUIRE(v == 2);

    toggle_bit(v, b0);
    REQUIRE(v == 3);

    REQUIRE(is_bit_set(v, b0) == true);
}


TEST_CASE("Bit manipulation: scoped_enum_bitmask()",
    "[scoped_enum_bitmask]")
{
    enum struct msk {
        b0 = 1,
        b1 = 2
    };

    unsigned v = 3;

    clr_bit(v, msk::b0);
    REQUIRE(v == 2);

    set_bit(v, msk::b0);
    REQUIRE(v == 3);

    set_bit_value(v, msk::b1, 0);
    REQUIRE(v == 1);

    modify_bits(v, msk::b0, msk::b1);
    REQUIRE(v == 2);

    toggle_bit(v, msk::b0);
    REQUIRE(v == 3);

    REQUIRE(is_bit_set(v, msk::b0) == true);
}
