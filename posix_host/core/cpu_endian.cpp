// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/cpu_endian.hpp>

using namespace hodea;

TEST_CASE("Cpu endian: is_cpu_le()", "[is_cpu_le]")
{
    REQUIRE(is_cpu_le() == HONDEA_IS_CPU_LE);
}

TEST_CASE("Cpu endian: is_cpu_be()", "[is_cpu_be]")
{
    REQUIRE(is_cpu_be() == HONDEA_IS_CPU_BE);
}

#if HONDEA_IS_CPU_LE == true

TEST_CASE("Cpu endian: cpu_to_le16()", "[cpu_to_le16]")
{
    uint16_t x = 0x1234;

    REQUIRE(cpu_to_le16(x) == x);
}

TEST_CASE("Cpu endian: cpu_to_le32()", "[cpu_to_le32]")
{
    uint32_t x = 0x12345678;
    REQUIRE(cpu_to_le32(x) == x);
}

TEST_CASE("Cpu endian: cpu_to_le64()", "[cpu_to_le64]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(cpu_to_le64(x) == x);
}


TEST_CASE("Cpu endian: cpu_to_be16()", "[cpu_to_be16]")
{
    uint16_t x = 0x1234;

    REQUIRE(cpu_to_be16(x) == uswap16(x));
}

TEST_CASE("Cpu endian: cpu_to_be32()", "[cpu_to_be32]")
{
    uint32_t x = 0x12345678;
    REQUIRE(cpu_to_be32(x) == uswap32(x));
}

TEST_CASE("Cpu endian: cpu_to_be64()", "[cpu_to_be64]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(cpu_to_be64(x) == uswap64(x));
}

#else

TEST_CASE("Cpu endian: cpu_to_le16()", "[cpu_to_le16]")
{
    uint16_t x = 0x1234;

    REQUIRE(cpu_to_le16(x) == uswap16(x));
}

TEST_CASE("Cpu endian: cpu_to_le32()", "[cpu_to_le32]")
{
    uint32_t x = 0x12345678;
    REQUIRE(cpu_to_le32(x) == uswap32(x));
}

TEST_CASE("Cpu endian: cpu_to_le64()", "[cpu_to_le64]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(cpu_to_le64(x) == uswap64(x));
}


TEST_CASE("Cpu endian: cpu_to_be16()", "[cpu_to_be16]")
{
    uint16_t x = 0x1234;

    REQUIRE(cpu_to_be16(x) == x);
}

TEST_CASE("Cpu endian: cpu_to_be32()", "[cpu_to_be32]")
{
    uint32_t x = 0x12345678;
    REQUIRE(cpu_to_be32(x) == x);
}

TEST_CASE("Cpu endian: cpu_to_be64()", "[cpu_to_be64]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(cpu_to_be64(x) == x);
}

#endif

TEST_CASE("Cpu endian: le16_to_cpu()", "[le16_to_cpu]")
{
    uint16_t x = 0x1234;
    REQUIRE(le16_to_cpu(cpu_to_le16(x)) == x);
}

TEST_CASE("Cpu endian: le32_to_cpu()", "[le32_to_cpu]")
{
    uint32_t x = 0x12345678;
    REQUIRE(le32_to_cpu(cpu_to_le32(x)) == x);
}

TEST_CASE("Cpu endian: le64_to_cpu()", "[le64_to_cpu]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(le64_to_cpu(cpu_to_le64(x)) == x);
}

TEST_CASE("Cpu endian: be16_to_cpu()", "[be16_to_cpu]")
{
    uint16_t x = 0x1234;
    REQUIRE(be16_to_cpu(cpu_to_be16(x)) == x);
}

TEST_CASE("Cpu endian: be32_to_cpu()", "[be32_to_cpu]")
{
    uint32_t x = 0x12345678;
    REQUIRE(be32_to_cpu(cpu_to_be32(x)) == x);
}

TEST_CASE("Cpu endian: be64_to_cpu()", "[be64_to_cpu]")
{
    uint64_t x = 0x123456789abcdefULL;
    REQUIRE(be64_to_cpu(cpu_to_be64(x)) == x);
}
