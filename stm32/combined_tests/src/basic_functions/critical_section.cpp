// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

#include <mutex>
#include <hodea/core/cstdint.hpp>
#include <hodea/device/hal/device_setup.hpp>
#include <hodea/rte/htsc.hpp>
#include <hodea/device/hal/critical_section.hpp>
#include "tfw.hpp"
#include "digio_pins.hpp"

using namespace hodea;


#if defined __ARMCC_VERSION && (__ARMCC_VERSION >= 6010050)
/*
 * The actual armclang compiler v6.7 does not provide std::lock_guard (see
 * support case 710223. Therefore, we have to implement it ourselves.
 * Hopefully, a future version will provide it.
 */
namespace std
{
template <class Mutex>
class lock_guard
{
public:
    typedef Mutex mutex_type;

    explicit lock_guard(mutex_type& m) : m(m) {m.lock();}
    ~lock_guard() {m.unlock();}

    lock_guard(lock_guard const&) = delete;
    lock_guard& operator=(lock_guard const&) = delete;

private:
    Mutex& m;
};
} // namespace std

#endif

static void test_lock_unlock()
{
    Critical_section cs;

    tfw_assert(__get_PRIMASK() == 0);
    {
        std::lock_guard<Critical_section> csl{cs};
        tfw_assert(__get_PRIMASK() == 1);
    }

    tfw_assert(__get_PRIMASK() == 0);

}

Tfw_status critical_section_test(Tfw_status)
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

