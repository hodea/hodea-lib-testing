// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <unistd.h>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/rte/htsc.hpp>

using namespace hodea;

constexpr long clk_hz = Htsc::counter_clk_hz;

TEST_CASE("Htsc_timer::sec_to_ticks()", "[htsc_timer_sec_to_ticks]")
{
    constexpr Htsc_timer::Ticks ticks = Htsc_timer::sec_to_ticks(2);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc_timer::ms_to_ticks()", "[htsc_timer_ms_to_ticks]")
{
    constexpr Htsc_timer::Ticks ticks = Htsc_timer::ms_to_ticks(2000);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc_timer::us_to_ticks()", "[htsc_timer_us_to_ticks]")
{
    constexpr Htsc_timer::Ticks ticks = Htsc_timer::us_to_ticks(2000000);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("Htsc_timer::i_us_to_ticks()", "[htsc_timer_i_us_to_ticks]")
{
    constexpr Htsc_timer::Ticks ticks = Htsc_timer::i_us_to_ticks(2000000);

    REQUIRE(ticks == (clk_hz * 2));
}

TEST_CASE("htsc_timer runtime operations)", "[htsc_timer_runtime_runtime]")
{
    Htsc_timer timer;

    REQUIRE(timer.is_stopped());
    REQUIRE(!timer.is_running());
    REQUIRE(!timer.is_expired());
    REQUIRE(timer.remaining() == 0);

    timer.start(clk_hz / 10);

    REQUIRE(!timer.is_stopped());
    REQUIRE(timer.is_running());
    REQUIRE(!timer.is_expired());
    REQUIRE(timer.remaining() == (clk_hz / 10));

    usleep(200000);

    timer.update();

    REQUIRE(!timer.is_stopped());
    REQUIRE(!timer.is_running());
    REQUIRE(timer.is_expired());
    REQUIRE(timer.remaining() == 0);

    timer.update();

    REQUIRE(!timer.is_stopped());
    REQUIRE(!timer.is_running());
    REQUIRE(timer.is_expired());
    REQUIRE(timer.remaining() == 0);

    timer.stop();

    REQUIRE(timer.is_stopped());
    REQUIRE(!timer.is_running());
    REQUIRE(!timer.is_expired());
    REQUIRE(timer.remaining() == 0);
}


