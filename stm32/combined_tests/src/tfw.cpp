// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Test framework (tfw) to organize tests.
 * \author f.hollerer@gmx.net
 */

#include <cstdio>
#include <stdarg.h>
#include "tfw.hpp"
#include "tfw_config.hpp"

void tfw_report_failure(const char* file, int line, const char* fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    std::printf("%s:%d: ", file, line);
    std::vprintf(fmt, vl);
    va_end(vl);
    fflush(stdout);
}
