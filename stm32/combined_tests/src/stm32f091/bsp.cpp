// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Board support package.
 *
 * \author f.hollerer@gmx.net
 */
#include <hodea/device/hal/hal_pin_config.hpp>
#include "bsp.hpp"

using namespace hodea;

void init_pins_alternate_function()
{
    Config_gpio_af{GPIOA}
        .pin(2, Gpio_pin_af::af1)
        .pin(3, Gpio_pin_af::af1)
        .pin(4, Gpio_pin_af::af0)
        .pin(6, Gpio_pin_af::af0)
        .pin(7, Gpio_pin_af::af0)
        .pin(9, Gpio_pin_af::af1)
        .pin(10, Gpio_pin_af::af0)
        .pin(11, Gpio_pin_af::af1)
        .pin(12, Gpio_pin_af::af1)
        .pin(13, Gpio_pin_af::af0)
        .pin(14, Gpio_pin_af::af0)
        .write();
    Config_gpio_af{GPIOB}
        .pin(3, Gpio_pin_af::af0)
        .pin(5, Gpio_pin_af::af3)
        .pin(6, Gpio_pin_af::af1)
        .pin(7, Gpio_pin_af::af1)
        .pin(9, Gpio_pin_af::af2)
        .pin(10, Gpio_pin_af::af4)
        .pin(11, Gpio_pin_af::af4)
        .pin(14, Gpio_pin_af::af4)
        .write();
    Config_gpio_af{GPIOC}.write();
    Config_gpio_af{GPIOD}.write();
    Config_gpio_af{GPIOF}.write();
}
