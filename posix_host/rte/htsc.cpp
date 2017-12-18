// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <unistd.h>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/rte/htsc.hpp>

using namespace hodea;

constexpr long clk_hz = Htsc::counter_clk_hz;

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

TEST_CASE("Htsc::elapsed()", "[htsc_elapsed]")
{
    REQUIRE(Htsc::elapsed(0, 0) == 0);
    REQUIRE(Htsc::elapsed(0, 1) == 1);

    Htsc::Ticks elapsed;

    elapsed = Htsc::elapsed(Htsc::counter_msk, 0);
    REQUIRE(elapsed == 1);

    elapsed = Htsc::elapsed(Htsc::counter_msk - 2, 1);
    REQUIRE(elapsed == 4);
}

TEST_CASE("Htsc::is_elapsed()", "[htsc_is_elapsed]")
{
    Htsc::Ticks t1 = Htsc::now();

    REQUIRE(Htsc::is_elapsed(t1, clk_hz / 10) == false);
    usleep(200000);
    REQUIRE(Htsc::is_elapsed(t1, clk_hz / 10) == true);
}

TEST_CASE("Htsc::is_elapsed_repetitive()", "[htsc_is_elapsed_repetitive]")
{
    Htsc::Ticks ts_start = Htsc::now();
    Htsc::Ticks ts_start_moving = ts_start;

    for (int i = 0; i < 3; ++i) {
        while (!Htsc::is_elapsed_repetitive(ts_start_moving,  clk_hz / 10))
            ;
    }

    Htsc::Ticks ts_end = Htsc::now();
    REQUIRE(Htsc::elapsed(ts_start, ts_end) >= (3 * clk_hz / 10));
}

TEST_CASE("Htsc::delay()", "[htsc_delay]")
{
    Htsc::Ticks ts_start = Htsc::now();
    Htsc::delay(clk_hz / 10);
    Htsc::Ticks ts_end = Htsc::now();
    REQUIRE(Htsc::elapsed(ts_start, ts_end) >= (clk_hz / 10));
}

TEST_CASE("Htsc::sec_to_ticks()", "[htsc_sec_to_ticks]")
{
    constexpr Htsc::Ticks ticks = Htsc::sec_to_ticks(2);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc::ms_to_ticks()", "[htsc_ms_to_ticks]")
{
    constexpr Htsc::Ticks ticks = Htsc::ms_to_ticks(2000);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc::us_to_ticks()", "[htsc_us_to_ticks]")
{
    constexpr Htsc::Ticks ticks = Htsc::us_to_ticks(2000000);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc::i_us_to_ticks()", "[htsc_i_us_to_ticks]")
{
    constexpr Htsc::Ticks ticks = Htsc::i_us_to_ticks(2000000);

    REQUIRE(ticks == (clk_hz * 2));
}

