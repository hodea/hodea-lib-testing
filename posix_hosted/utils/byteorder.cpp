// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/byteorder.hpp>

using namespace hodea;

TEST_CASE("Byteorder: fetch8() ", "[fetch8]")
{
    uint8_t buf[] = {0xaa};
    unsigned v;
    unsigned cnt;

    cnt = fetch8(v, buf);
    REQUIRE(v == 0xaa);
    REQUIRE(cnt == 1);
}

TEST_CASE("Byteorder: fetch16_le() ", "[fetch16_le]")
{
    uint8_t buf[] = {0x08, 0x15};
    unsigned v;
    unsigned cnt;

    cnt = fetch16_le(v, buf);
    REQUIRE(v == 0x1508);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: fetch32_le() ", "[fetch32_le]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe};
    unsigned v;
    unsigned cnt;

    cnt = fetch32_le(v, buf);
    REQUIRE(v == 0xfeca1508U);
    REQUIRE(cnt == 4);
}

TEST_CASE("Byteorder: fetch16_be() ", "[fetch16_be]")
{
    uint8_t buf[] = {0x08, 0x15};
    unsigned v;
    unsigned cnt;

    cnt = fetch16_be(v, buf);
    REQUIRE(v == 0x0815);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: fetch32_be() ", "[fetch32_be]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe};
    unsigned v;
    unsigned cnt;

    cnt = fetch32_be(v, buf);
    REQUIRE(v == 0x0815cafe);
    REQUIRE(cnt == 4);
}

