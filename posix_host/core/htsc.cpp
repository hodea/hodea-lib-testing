// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <unistd.h>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/htsc.hpp>

using namespace hodea;

constexpr long clk_hz = htsc::counter_clk_hz;

TEST_CASE("htsc counter clock ", "[htsc_counter_clk]")
{
    /*
     * The time base used by the Linux kernel depends on the
     * configuration and can determined at runtime using sysconf.
     *
     * Unfortunately, we need a constant expression for our htsc
     * in order to calculate the ticks at compile time.
     *
     * Therefore, we made an assumption on the Linux configuration.
     * This lines need to be changed if our assumption is wrong.
     */
    long linux_clk = sysconf(_SC_CLK_TCK);

    REQUIRE(clk_hz == linux_clk);
}

TEST_CASE("htsc::elapsed()", "[htsc_elapsed]")
{
    REQUIRE(htsc::elapsed(0, 0) == 0);
    REQUIRE(htsc::elapsed(0, 1) == 1);

    htsc::Ticks elapsed;

    elapsed = htsc::elapsed(htsc::counter_msk, 0);
    REQUIRE(elapsed == 1);

    elapsed = htsc::elapsed(htsc::counter_msk - 2, 1);
    REQUIRE(elapsed == 4);
}

TEST_CASE("htsc::is_elapsed()", "[htsc_is_elapsed]")
{
    htsc::Ticks t1 = htsc::timestamp();

    REQUIRE(htsc::is_elapsed(t1, clk_hz / 10) == false);
    usleep(200000);
    REQUIRE(htsc::is_elapsed(t1, clk_hz / 10) == true);
}

TEST_CASE("htsc::is_elapsed_repetitive()", "[htsc_is_elapsed_repetitive]")
{
    htsc::Ticks ts_start = htsc::timestamp();
    htsc::Ticks ts_start_moving = ts_start;

    for (int i = 0; i < 3; ++i) {
        while (!htsc::is_elapsed_repetitive(ts_start_moving,  clk_hz / 10))
            ;
    }

    htsc::Ticks ts_end = htsc::timestamp();
    REQUIRE(htsc::elapsed(ts_start, ts_end) >= (3 * clk_hz / 10));
}

TEST_CASE("htsc::delay()", "[htsc_delay]")
{
    htsc::Ticks ts_start = htsc::timestamp();
    htsc::delay(clk_hz / 10);
    htsc::Ticks ts_end = htsc::timestamp();
    REQUIRE(htsc::elapsed(ts_start, ts_end) >= (clk_hz / 10));
}

