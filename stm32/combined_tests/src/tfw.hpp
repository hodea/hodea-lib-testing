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

/**
 * Enumeration describing the status of an individual test.
 */
enum class Tfw_status {
    not_started = 0,    //!< Test is not yet started.
    executing,          //!< Test is executing, needs another invocation.
    stopping,           //!< Test is stopping, needs another invocation.
    success,            //!< Test completed successfully.
    failed,             //!< Test completed but failed.
};

#define tfw_failed(...) \
    tfw_report_failure(__FILE__, __LINE__, __VA_ARGS__);

#define tfw_assert(expr) \
    do {                                                                \
        if (!(expr))                                                    \
            tfw_report_failure(                                         \
                __FILE__, __LINE__, "tfw_assert(%s) failed\n", # expr   \
                );                                                      \
    } while (0)

void tfw_report_failure(const char* file, int line, const char* fmt, ...);

void tfw_info(const char* fmt, ...);

/**
 * Test framework main function.
 */
void tfw_main();

#endif /*!_TFW_HPP_ */
