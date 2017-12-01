// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmanip.hpp>
#include <hodea/core/scoped_enum.hpp>

using namespace hodea;

enum struct Msk : unsigned {
    b0 = 1,
    b1 = 2
};

DEFINE_SCOPED_ENUM_OR_OPERATOR(Msk)


TEST_CASE("scoped_enum: or operator", "[scoped_enum_or_operator]")
{
    unsigned val = 0x0f;

    REQUIRE(is_bit_set(val, enum_to_underlying(Msk::b0 | Msk::b1)) == true);
}

TEST_CASE("scoped_enum: enum_to_underlying", "[scoped_enum_to_underlying]")
{
    REQUIRE(enum_to_underlying(Msk::b1) == 2);
}
