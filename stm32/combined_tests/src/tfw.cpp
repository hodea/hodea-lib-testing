// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Test framework (tfw) to organize tests.
 * \author f.hollerer@gmx.net
 */

#include <cstdio>
#include <stdarg.h>
#include <hodea/rte/htsc.hpp>
#include "tfw.hpp"
#include "tfw_config.hpp"
#include "digio_pins.hpp"

using namespace hodea;

extern Tfw_status pin_config_test(Tfw_status current);
extern Tfw_status digio_test(Tfw_status current);

struct Test_table_entry {
    bool is_enabled;
    Tfw_status status;
    Tfw_status (*p_func)(Tfw_status current);
};

static Test_table_entry tests[] = {
    // non-looping tests
    {
        enable_pin_config_test,
        Tfw_status::not_started,
        pin_config_test
    },
    {
        enable_digio_test,
        Tfw_status::not_started,
        digio_test
    }

    // looping tests

};

void tfw_report_failure(const char* file, int line, const char* fmt, ...)
{
    if (tfw_log_level >= Tfw_log_level::error) {
        va_list vl;
        va_start(vl, fmt);

        std::printf("%s:%d: ", file, line);
        std::vprintf(fmt, vl);
        va_end(vl);
        fflush(stdout);
    }
    throw Tfw_failed();
}

void tfw_info(const char* fmt, ...)
{
    if (tfw_log_level >= Tfw_log_level::info) {
        va_list vl;
        va_start(vl, fmt);
        std::vprintf(fmt, vl);
        va_end(vl);
        fflush(stdout);
    }
}

static void print_summary()
{
    int ok = 0;
    int nok = 0;

    for (auto& test: tests) {
        if (test.status == Tfw_status::success)
            ++ok;
        else if (test.status == Tfw_status::failed)
            ++nok;
    }

    int total = ok + nok;
    tfw_info("%d/%d tests succeeded, %d failed.\n", ok, total, nok);
}

void tfw_main()
{
    htsc::Ticks ts = htsc::now();
    bool again;
    do {
        again = false;

        for (auto& test: tests) {
            if (!test.is_enabled || (test.status >= Tfw_status::success))
                continue;
            test.status = test.p_func(test.status);
            again = again || (test.status < Tfw_status::success);
        }

        if (htsc::is_elapsed_repetitive(ts, htsc::ms_to_ticks(200)))
            run_led.toggle();

    } while (again);
    print_summary();

    for (;;) {
        if (htsc::is_elapsed_repetitive(ts, htsc::ms_to_ticks(200)))
            run_led.toggle();
    }
}
