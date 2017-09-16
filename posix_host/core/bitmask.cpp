// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmask.hpp>

using namespace hodea;

TEST_CASE("Bitmask: Bitmask() ", "[Bitmask]")
{
    constexpr uint8_t msk = Bitmask<uint8_t>{}.bit(0).bit(2);
    REQUIRE(msk == 0x5);
}

TEST_CASE("Bitmask: bit_pos_to_msk()", "[bit_pos_to_msk]")
{
    constexpr uint8_t m8 = bit_to_msk(7);

    REQUIRE(m8 == 0x80U);
}

TEST_CASE("Bitmask: make_bitmask()", "[make_bitmask]")
{
#if 0
    constexpr auto m1 = make_bitmask<uint8_t, 1>;

    REQUIRE(m1 == 0x20U);
#endif
}

