// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <unistd.h>
#include <catch/catch.hpp>
#include <hodea/rte/setup.hpp>

using namespace hodea;

TEST_CASE("rte_init ", "[rte_init]")
{
    rte_init();
}

TEST_CASE("rte_deinit ", "[rte_deinit]")
{
    rte_deinit();
}

