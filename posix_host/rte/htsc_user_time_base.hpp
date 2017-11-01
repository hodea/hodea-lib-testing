// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * User time base for the hodea timestamp counter.
 *
 * \author f.hollerer@gmx.net
 */
#if !defined _HTSC_USER_TIME_BASE_HPP_
#define _HTSC_USER_TIME_BASE_HPP_

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

#endif /*!_HTSC_USER_TIME_BASE_HPP_ */
