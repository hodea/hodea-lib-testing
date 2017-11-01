// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

#include <cstring>
#include <hodea/core/cstdint.hpp>
#include <hodea/device/hal/device_setup.hpp>
#include <hodea/rte/htsc.hpp>
#include <hodea/device/hal/digio.hpp>
#include "tfw.hpp"
#include "digio_pins.hpp"

using namespace hodea;

static void test_digio_pin_value_type()
{
    Digio_pin_value pin;

    pin = (1ULL << 63);

    tfw_assert(pin == 1);
}

static void test_digio_loopback()
{
    digio_oc_out1.reset();
    digio_oc_out2.reset();
    htsc::delay(htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 0);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.set();
    digio_oc_out2.reset();
    htsc::delay(htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 0);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.reset();
    digio_oc_out2.set();
    htsc::delay(htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 1);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.set();
    digio_oc_out2.set();
    htsc::delay(htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out1.real_pin_value() == 1);
    tfw_assert(digio_oc_out2.value() == 1);
    tfw_assert(digio_oc_out2.real_pin_value() == 1);

    Digio_output::modify(
        digio_port, 1U << digio_oc_out1_pin, 1U << digio_oc_out2_pin
        );
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out2.value() == 1);

    Digio_output::modify(
        digio_port, 1U << digio_oc_out2_pin, 1U << digio_oc_out1_pin
        );
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out2.value() == 0);
}

Tfw_status digio_test(Tfw_status current)
{
    tfw_info("Testing digital input / output module.\n");
    try {
        test_digio_pin_value_type();
        test_digio_loopback();
    }
    catch (...) {
        return Tfw_status::failed;
    }
    return Tfw_status::success;
}

