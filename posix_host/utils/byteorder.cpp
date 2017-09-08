// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <stdint.h>
#include <catch/catch.hpp>
#include <hodea/utils/byteorder.hpp>

using namespace hodea;

TEST_CASE("Byteorder: fetch8()", "[fetch8]")
{
    uint8_t buf[] = {0xaa};
    unsigned v;
    int cnt;

    cnt = fetch8(v, buf);
    REQUIRE(v == 0xaa);
    REQUIRE(cnt == 1);
}

TEST_CASE("Byteorder: fetch16_le()", "[fetch16_le]")
{
    uint8_t buf[] = {0x08, 0x15};
    unsigned v;
    int cnt;

    cnt = fetch16_le(v, buf);
    REQUIRE(v == 0x1508);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: fetch32_le()", "[fetch32_le]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe};
    unsigned v;
    int cnt;

    cnt = fetch32_le(v, buf);
    REQUIRE(v == 0xfeca1508U);
    REQUIRE(cnt == 4);
}

TEST_CASE("Byteorder: fetch64_le()", "[fetch64_le]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe, 0x41, 0x11, 0xc0, 0x01};
    uint64_t v;
    int cnt;

    cnt = fetch64_le(v, buf);
    REQUIRE(v == 0x01c01141feca1508LLU);
    REQUIRE(cnt == 8);
}

TEST_CASE("Byteorder: fetch16_be()", "[fetch16_be]")
{
    uint8_t buf[] = {0x08, 0x15};
    unsigned v;
    int cnt;

    cnt = fetch16_be(v, buf);
    REQUIRE(v == 0x0815);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: fetch32_be()", "[fetch32_be]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe};
    unsigned v;
    int cnt;

    cnt = fetch32_be(v, buf);
    REQUIRE(v == 0x0815cafe);
    REQUIRE(cnt == 4);
}

TEST_CASE("Byteorder: fetch64_be()", "[fetch64_be]")
{
    uint8_t buf[] = {0x08, 0x15, 0xca, 0xfe, 0x41, 0x11, 0xc0, 0x01};
    uint64_t v;
    unsigned cnt;

    cnt = fetch64_be(v, buf);
    REQUIRE(v == 0x0815cafe4111c001LLU);
    REQUIRE(cnt == 8);
}

TEST_CASE("Byteorder: store8()", "[store8]")
{
    uint8_t buf[] = {0};
    int cnt;

    cnt = store8(buf, 0x11);
    REQUIRE(buf[0] == 0x11);
    REQUIRE(cnt == 1);
}

TEST_CASE("Byteorder: store16_le()", "[store16_le]")
{
    uint8_t buf[] = {0, 0};
    int cnt;

    cnt = store16_le(buf, 0x4711);
    REQUIRE(buf[0] == 0x11);
    REQUIRE(buf[1] == 0x47);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: store32_le()", "[store32_le]")
{
    uint8_t buf[] = {0, 0, 0, 0};
    int cnt;

    cnt = store32_le(buf, 0x08154711);
    REQUIRE(buf[0] == 0x11);
    REQUIRE(buf[1] == 0x47);
    REQUIRE(buf[2] == 0x15);
    REQUIRE(buf[3] == 0x08);
    REQUIRE(cnt == 4);
}

TEST_CASE("Byteorder: store64_le()", "[store64_le]")
{
    uint8_t buf[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int cnt;

    cnt = store64_le(buf, 0xc001cafe08154711LLU);
    REQUIRE(buf[0] == 0x11);
    REQUIRE(buf[1] == 0x47);
    REQUIRE(buf[2] == 0x15);
    REQUIRE(buf[3] == 0x08);
    REQUIRE(buf[4] == 0xfe);
    REQUIRE(buf[5] == 0xca);
    REQUIRE(buf[6] == 0x01);
    REQUIRE(buf[7] == 0xc0);
    REQUIRE(cnt == 8);
}

TEST_CASE("Byteorder: store16_be()", "[store16_be]")
{
    uint8_t buf[] = {0, 0};
    int cnt;

    cnt = store16_be(buf, 0x4711);
    REQUIRE(buf[0] == 0x47);
    REQUIRE(buf[1] == 0x11);
    REQUIRE(cnt == 2);
}

TEST_CASE("Byteorder: store32_be()", "[store32_be]")
{
    uint8_t buf[] = {0, 0, 0, 0};
    int cnt;

    cnt = store32_be(buf, 0x08154711);
    REQUIRE(buf[0] == 0x08);
    REQUIRE(buf[1] == 0x15);
    REQUIRE(buf[2] == 0x47);
    REQUIRE(buf[3] == 0x11);
    REQUIRE(cnt == 4);
}

TEST_CASE("Byteorder: store64_be()", "[store64_le]")
{
    uint8_t buf[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int cnt;

    cnt = store64_be(buf, 0xc001cafe08154711LLU);
    REQUIRE(buf[0] == 0xc0);
    REQUIRE(buf[1] == 0x01);
    REQUIRE(buf[2] == 0xca);
    REQUIRE(buf[3] == 0xfe);
    REQUIRE(buf[4] == 0x08);
    REQUIRE(buf[5] == 0x15);
    REQUIRE(buf[6] == 0x47);
    REQUIRE(buf[7] == 0x11);
    REQUIRE(cnt == 8);
}

