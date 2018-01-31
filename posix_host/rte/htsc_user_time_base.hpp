// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * User time base for the hodea timestamp counter.
 *
 * \author f.hollerer@hodea.org
 */
#if !defined HTSC_USER_TIME_BASE_HPP
#define HTSC_USER_TIME_BASE_HPP

#include <limits>
#include <sys/times.h>
#include <hodea/core/cstdint.hpp>

namespace hodea {

class Htsc_time_base {
public:
    typedef clock_t Ticks;

    static constexpr Ticks counter_msk = std::numeric_limits<Ticks>::max();
    static constexpr unsigned counter_clk_hz = 100;

    static void init() { }

    static void deinit() { }

    static Ticks now()
    {
        struct tms tms; 
        return times(&tms);
    }
};


} // namespace hodea

#endif /*!HTSC_USER_TIME_BASE_HPP */
