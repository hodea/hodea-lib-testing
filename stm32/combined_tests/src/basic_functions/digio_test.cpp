// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

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
    Htsc::delay(Htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 0);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.set();
    digio_oc_out2.reset();
    Htsc::delay(Htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 0);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.reset();
    digio_oc_out2.set();
    Htsc::delay(Htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out1.real_pin_value() == 0);
    tfw_assert(digio_oc_out2.value() == 1);
    tfw_assert(digio_oc_out2.real_pin_value() == 0);
    tfw_assert(digio_in.value() == 0);

    digio_oc_out1.set();
    digio_oc_out2.set();
    Htsc::delay(Htsc::us_to_ticks(1));
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out1.real_pin_value() == 1);
    tfw_assert(digio_oc_out2.value() == 1);
    tfw_assert(digio_oc_out2.real_pin_value() == 1);

    digio_modify_outputs(
        digio_oc_out1.device, digio_oc_out1.msk, digio_oc_out2.msk
        );
    tfw_assert(digio_oc_out1.value() == 0);
    tfw_assert(digio_oc_out2.value() == 1);

    digio_modify_outputs(
        digio_oc_out1.device, digio_oc_out2.msk, digio_oc_out1.msk
        );
    tfw_assert(digio_oc_out1.value() == 1);
    tfw_assert(digio_oc_out2.value() == 0);
}

Tfw_status digio_test(Tfw_status)
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

