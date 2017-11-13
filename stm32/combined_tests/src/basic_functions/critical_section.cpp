// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

#include <mutex>
#include <hodea/core/cstdint.hpp>
#include <hodea/device/hal/device_setup.hpp>
#include <hodea/rte/htsc.hpp>
#include <hodea/device/hal/critical_section.hpp>
#include "tfw.hpp"
#include "digio_pins.hpp"

using namespace hodea;

static void test_lock_unlock()
{
    Critical_section cs;
#warning "remove this.."
#if 0
    tfw_assert(__get_PRIMASK() == 0);
    {
        std::lock_guard<Critical_section> csl{cs};
        tfw_assert(__get_PRIMASK() == 1);
    }
#endif

    tfw_assert(__get_PRIMASK() == 1);

}

Tfw_status critical_section_test(Tfw_status current)
{
    tfw_info("Testing critical section.\n");
    try {
        test_lock_unlock();
    }
    catch (...) {
        return Tfw_status::failed;
    }
    return Tfw_status::success;
}

