// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

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

