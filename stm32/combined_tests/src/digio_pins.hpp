// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * Digital I/O pins used throughout the project.
 */
#if !defined _DIGIO_PINS_HPP_
#define _DIGIO_PINS_HPP_

#include <hodea/device/hal/digio.hpp>

constexpr hodea::Digio_output run_led{GPIOA_BASE, 5};

constexpr hodea::Digio_output digio_oc_out1{GPIOC_BASE, 0};
constexpr hodea::Digio_output digio_oc_out2{GPIOC_BASE, 1};
constexpr hodea::Digio_input digio_in{GPIOC_BASE, 2};

#endif /*!_DIGIO_PINS_HPP_ */
