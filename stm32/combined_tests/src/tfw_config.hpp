// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * Test framework (tfw) configuration.
 * \author f.hollerer@gmx.net
 */
#if !defined TFW_CONFIG_HPP
#define TFW_CONFIG_HPP

#include "tfw.hpp"

constexpr Tfw_log_level tfw_log_level = Tfw_log_level::info;
constexpr bool enable_pin_config_test = true;
constexpr bool enable_digio_test = true;
constexpr bool enable_critical_section_test = true;

#endif /*!TFW_CONFIG_HPP */
