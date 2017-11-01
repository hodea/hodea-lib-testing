// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

#include <hodea/core/cstdint.hpp>
#include <hodea/device/hal/device_setup.hpp>
#include <hodea/device/hal/pin_config.hpp>
#include "pin_config_test.hpp"

using namespace hodea;

static void test_gpio_mode()
{
    GPIO_TypeDef gpio;

    gpio.MODER = 0;
    Config_gpio_mode(&gpio)
        .pin(15, Gpio_pin_mode::analog)
        .pin(8, Gpio_pin_mode::af)
        .pin(7, Gpio_pin_mode::output)
        .pin(0, Gpio_pin_mode::input).write();
    tfw_assert(gpio.MODER == 0xc0024000);

    gpio.MODER = 0xffffffff;
    Config_gpio_mode(&gpio)
        .read()
        .pin(15, Gpio_pin_mode::analog)
        .pin(8, Gpio_pin_mode::af)
        .pin(7, Gpio_pin_mode::output)
        .pin(0, Gpio_pin_mode::input).write();
    tfw_assert(gpio.MODER == 0xfffe7ffc);
}

static void test_gpio_otype()
{
    GPIO_TypeDef gpio;

    gpio.OTYPER = 0;
    Config_gpio_otype(&gpio)
        .pin(15, Gpio_pin_otype::push_pull)
        .pin(8, Gpio_pin_otype::open_drain)
        .pin(7, Gpio_pin_otype::push_pull)
        .pin(0, Gpio_pin_otype::open_drain).write();
    tfw_assert(gpio.OTYPER == 0x00000101);

    gpio.OTYPER = 0xffffffff;
    Config_gpio_otype(&gpio)
        .read()
        .pin(15, Gpio_pin_otype::push_pull)
        .pin(8, Gpio_pin_otype::open_drain)
        .pin(7, Gpio_pin_otype::push_pull)
        .pin(0, Gpio_pin_otype::open_drain).write();
    tfw_assert(gpio.OTYPER == 0x00007f7f);
}

static void test_gpio_ospeed()
{
    GPIO_TypeDef gpio;

    gpio.OSPEEDR = 0;
    Config_gpio_ospeed(&gpio)
        .pin(15, Gpio_pin_ospeed::low)
        .pin(8, Gpio_pin_ospeed::medium)
        .pin(7, Gpio_pin_ospeed::high)
        .pin(0, Gpio_pin_ospeed::low).write();
    tfw_assert(gpio.OSPEEDR == 0x0001c000);

    gpio.OSPEEDR = 0xffffffff;
    Config_gpio_ospeed(&gpio)
        .read()
        .pin(15, Gpio_pin_ospeed::low)
        .pin(8, Gpio_pin_ospeed::medium)
        .pin(7, Gpio_pin_ospeed::high)
        .pin(0, Gpio_pin_ospeed::low).write();
    tfw_assert(gpio.OSPEEDR == 0x3ffdfffc);
}

static void test_gpio_pupd()
{
    GPIO_TypeDef gpio;

    gpio.PUPDR = 0;
    Config_gpio_pupd(&gpio)
        .pin(15, Gpio_pin_pupd::none)
        .pin(8, Gpio_pin_pupd::pull_up)
        .pin(7, Gpio_pin_pupd::pull_down)
        .pin(0, Gpio_pin_pupd::none).write();
    tfw_assert(gpio.PUPDR == 0x00018000);

    gpio.PUPDR = 0xffffffff;
    Config_gpio_pupd(&gpio)
        .read()
        .pin(15, Gpio_pin_pupd::none)
        .pin(8, Gpio_pin_pupd::pull_up)
        .pin(7, Gpio_pin_pupd::pull_down)
        .pin(0, Gpio_pin_pupd::none).write();
    tfw_assert(gpio.PUPDR == 0x3ffdbffc);
}

static void test_gpio_af()
{
    GPIO_TypeDef gpio;

    gpio.AFR[0] = gpio.AFR[1] = 0;
    Config_gpio_af(&gpio)
        .pin(15, Gpio_pin_af::af7)
        .pin(8, Gpio_pin_af::af6)
        .pin(7, Gpio_pin_af::af5)
        .pin(0, Gpio_pin_af::af0).write();
    tfw_assert(gpio.AFR[1] == 0x70000006);
    tfw_assert(gpio.AFR[0] == 0x50000000);

    gpio.AFR[0] = gpio.AFR[1] = 0xffffffff;
    Config_gpio_af(&gpio)
        .read()
        .pin(15, Gpio_pin_af::af7)
        .pin(8, Gpio_pin_af::af6)
        .pin(7, Gpio_pin_af::af5)
        .pin(0, Gpio_pin_af::af0).write();
    tfw_assert(gpio.AFR[1] == 0x7ffffff6);
    tfw_assert(gpio.AFR[0] == 0x5ffffff0);
}

Tfw_status pin_config_test(Tfw_status current)
{
    try {
        test_gpio_mode();
        test_gpio_otype();
        test_gpio_ospeed();
        test_gpio_pupd();
        test_gpio_af();
    }
    catch (...) {
        return Tfw_status::failed;
    }
    return Tfw_status::success;
}

