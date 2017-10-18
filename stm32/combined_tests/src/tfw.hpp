// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Test framework (tfw) to organize tests.
 * \author f.hollerer@gmx.net
 */
#if !defined _TFW_HPP_
#define _TFW_HPP_

enum class Tfw_log_level { none, error, info };
enum class Tfw_failed;

#define tfw_failed(...) \
    tfw_report_failure(__FILE__, __LINE__, __VA_ARGS__);

void tfw_report_failure(const char* file, int line, const char* fmt, ...);

#endif /*!_TFW_HPP_ */
