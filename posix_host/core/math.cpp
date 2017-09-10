// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/math.hpp>

using namespace hodea;

TEST_CASE("math: math_min()", "[math_min]")
{
    REQUIRE(math_min(4, 5) == 4);
}

TEST_CASE("math: math_max()", "[math_max]")
{
    REQUIRE(math_max(4, 5) == 5);
}

TEST_CASE("math: math_limit()", "[math_limit]")
{
    REQUIRE(math_limit(5, 2, 10) == 5);
    REQUIRE(math_limit(10, 2, 10) == 10);
    REQUIRE(math_limit(11, 2, 10) == 10);
    REQUIRE(math_limit(0, 2, 10) == 2);
    REQUIRE(math_limit(-1, 2, 10) == 2);
}

TEST_CASE("math: math_limit_positive()", "[math_limit_positive]")
{
    REQUIRE(math_limit_positive(5) == 5);
    REQUIRE(math_limit_positive(0) == 0);
    REQUIRE(math_limit_positive(-1) == 0);
}

TEST_CASE("math: math_round_to()", "[math_round_to]")
{
    constexpr int x1 = math_round_to<int>(0);
    REQUIRE(x1 == 0);

    constexpr int x2 = math_round_to<int>(1.75);
    REQUIRE(x2 == 2);

    constexpr int x3 = math_round_to<int>(-1.75);
    REQUIRE(x3 == -2);
}
