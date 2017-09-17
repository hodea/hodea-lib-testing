// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmanip.hpp>
#include <hodea/core/scoped_enum_or_operator.hpp>

enum struct Msk : unsigned {
    b0 = 1,
    b1 = 2
};

DEFINE_SCOPED_ENUM_OR_OPERATOR(Msk)


TEST_CASE("scoped_enum_bitmask", "[scoped_enum_bitop]")
{
    unsigned val = 0x0f;

    REQUIRE(hodea::is_bit_set(val, Msk::b0 | Msk::b1) == true);
}
