// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <cstddef>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/utils.hpp>

using namespace hodea;

TEST_CASE("utils: array_size()", "[array_size]")
{
    uint16_t buf[8];
    constexpr std::size_t size = array_size(buf);

    REQUIRE(size == 8);
}

