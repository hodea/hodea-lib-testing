// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * User specific configuration for the HODEA source code library.
 *
 * \author f.hollerer@gmx.net
 */
#if !defined _HODEA_USER_CONFIG_HPP_
#define _HODEA_USER_CONFIG_HPP_

#define HODEA_CONFIG_HTSC_TIME_BASE_INCLUDE \
    <hodea/device/arm_cortex_m/htsc_systick_time_base.hpp>

namespace hodea {

 //! System core clock in [Hz].
constexpr unsigned config_sysclk_hz = 64000000;

//! Cortex system timer clock in [Hz].
constexpr unsigned config_systick_hz = config_sysclk_hz / 8;

//! APB1 peripheral clocks in [Hz].
constexpr unsigned config_apb1_pclk_hz = config_sysclk_hz / 2;

//! APB1 timer clocks in [Hz].
constexpr unsigned config_apb1_tclk_hz = config_sysclk_hz;

} // namespace hodea

#endif /*!_HODEA_USER_CONFIG_HPP_ */
