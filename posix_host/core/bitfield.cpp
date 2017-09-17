// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.
#include <iostream>
#include <catch/catch.hpp>
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitfield.hpp>

using namespace hodea;

TEST_CASE("Bitfield: bitmask()", "[bitmask]")
{
    constexpr auto m1 = bitmask<unsigned>(3); 
    REQUIRE(m1 == 0x08U);

    constexpr auto m2 = bitmask<unsigned>(0, 2); 
    REQUIRE(m2 == 0x03U);

    constexpr auto m3 = bitmask<unsigned>(2, 2); 
    REQUIRE(m3 == 0x0CU);
}

TEST_CASE("Bitfied: Bitfield_descriptor", "[Bitfield_descriptor]")
{
    constexpr Bitfield_descriptor<unsigned> xx{2, 3};
}

TEST_CASE("Bitfied: val2fld(value, pos)", "[val2fld_pos]")
{
    
    REQUIRE(val2fld(3U, 2) == 0x0cU);
    REQUIRE(val2fld(7U, 2) == 0x1cU);

    uint64_t u64 = 0x0c;
    REQUIRE(val2fld(u64, 50) == 0x30000000000000ULL);
}

TEST_CASE("Bitfied: val2fld(value, pos, msk)", "[val2fld_pos_msk]")
{
    
    REQUIRE(val2fld(3U, 2, 0x0cU) == 0x0cU);
    REQUIRE(val2fld(7U, 2, 0x0cU) == 0x0cU);

    uint64_t u64;
    
    u64 = 0x00;
    REQUIRE(val2fld(u64, 50, 0x30000000000000ULL) == 0);

    u64 = 0x0f;
    REQUIRE(val2fld(u64, 50, 0x30000000000000ULL) == 0x30000000000000ULL);
}

TEST_CASE("Bitfied: val2fld(value, Bitfield_desriptor)",
    "[val2fld_Bitfield_descriptor]")
{
    constexpr Bitfield_descriptor<uint32_t> bfd1(2, 2);
    REQUIRE(val2fld(3U, bfd1) == 0x0cU);
    REQUIRE(val2fld(7U, bfd1) == 0x0cU);

    constexpr Bitfield_descriptor<uint64_t> bfd2(50, 2);
    REQUIRE(val2fld(0x0fUL, bfd2) == 0xc000000000000UL);
}

TEST_CASE("Bitfied: fld2val(fld, pos, msk)", "[fld2val_pos_msk]")
{
    
    REQUIRE(fld2val(0xffU, 2, 0x0cU) == 0x3U);

    uint64_t u64 = 0x70000000000000ULL;
    REQUIRE(fld2val(u64, 50, 0x30000000000000ULL) == 0x0cU);
}

TEST_CASE("Bitfied: fld2val(Bitfield_descriptor)",
    "[fld2val_Biffield_descriptor]")
{
    constexpr Bitfield_descriptor<uint32_t> bfd1(2, 2);

    REQUIRE(fld2val(0xffU, bfd1) == 0x3U);

    uint64_t u64 = 0xf000000000000000ULL;
    constexpr Bitfield_descriptor<uint64_t> bfd2(62, 2);

std::cout << "bfd.msk = " << std::hex << bfd2.msk << std::endl;

    REQUIRE(fld2val(u64, bfd2) == 0x03U);
}

