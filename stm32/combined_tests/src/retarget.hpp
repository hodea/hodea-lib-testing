// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Target-dependent support for I/O functions, e.g. printf().
 *
 * This file implements low level function to retarget output an UART,
 * using 115200:8:N:1.
 *
 * \author f.hollerer@gmx.net
 */
#if !defined _RETARGET_HPP_
#define _RETARGET_HPP_

void retarget_init();

#endif /*!_RETARGET_HPP_ */
