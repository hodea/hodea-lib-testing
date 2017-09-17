// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmask.hpp>

using namespace hodea;

TEST_CASE("Bitmask: Right_aligned_mask", "[Right_aligned_mask]")
{
    using namespace helper;

    auto m1 = Right_aligned_mask<unsigned, 1>{};
    REQUIRE(m1 == 0x01U);

    constexpr int s = 3;
    constexpr auto m2 = Right_aligned_mask<unsigned, s>{};
    REQUIRE(m2 == 0x07U);

    constexpr auto m3 = Right_aligned_mask<uint8_t, 8>{};
    REQUIRE(m3 == 0xffU);

    // The following code must case an compile time error as
    // the requested mask does not fit in the type.
#if 0
    constexpr uint8_t m4 = Right_aligned_mask<uint8_t, 9>{};
    REQUIRE(m4 == 0xffU);
#endif
}


TEST_CASE("Bitmask: bitmask()", "[bitmask]")
{
    constexpr auto m1 = bitmask<unsigned, 3>(); 
    REQUIRE(m1 == 0x08U);

    constexpr auto m2 = bitmask<unsigned, 0, 2>(); 
    REQUIRE(m2 == 0x03U);

    constexpr auto m3 = bitmask<unsigned, 2, 2>(); 
    REQUIRE(m3 == 0x0CU);
}

