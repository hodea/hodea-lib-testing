// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Digital I/O pins used throughout the project.
 */
#if !defined _DIGIO_PINS_HPP_
#define _DIGIO_PINS_HPP_

#include <hodea/device/hal/digio.hpp>

static const hodea::Digio_output run_led{GPIOA, 5};

static GPIO_TypeDef* const digio_port = GPIOC;
constexpr unsigned digio_oc_out1_pin = 0;
constexpr unsigned digio_oc_out2_pin = 1;

static const hodea::Digio_output digio_oc_out1{GPIOC, 0};
static const hodea::Digio_output digio_oc_out2{GPIOC, 1};
static const hodea::Digio_input digio_in{GPIOC, 2};

#endif /*!_DIGIO_PINS_HPP_ */
