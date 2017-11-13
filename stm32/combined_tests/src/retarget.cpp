// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Target-dependent support for I/O functions, e.g. printf().
 *
 * This file implements low level function to retarget output to an UART,
 * using 115200:8:N:1.
 *
 * \author f.hollerer@gmx.net
 */
#include <hodea/core/cstdint.hpp>
#include <hodea/core/bitmanip.hpp>
#include <hodea/core/math.hpp>
#include <hodea/device/hal/device_setup.hpp>
#include "retarget.hpp"

using namespace hodea;

static USART_TypeDef* const uart = USART2;
constexpr unsigned baudrate = 115200;

void retarget_init()
{
    uart->CR1 = USART_CR1_TE;
    uart->BRR =
        math_round_to<uint32_t>(1.0 * config_apb1_pclk_hz / baudrate);
    set_bit(uart->CR1, USART_CR1_UE);
}

#if defined __GNUC__

extern "C" int _write (int handle, char *buffer, int size);
int _write (int handle, char *buffer, int size)
{
    if (buffer == nullptr)
        return -1;

    for (int i = 0; i < size; i++) {
        while (!is_bit_set(uart->ISR, USART_ISR_TXE)) ;
        uart->TDR = buffer[i];
    }
    return size;
}

#elif defined __ARMCC_VERSION && (__ARMCC_VERSION >= 6010050)

#include <stdio.h>

extern "C" {

__asm(".global __use_no_semihosting\n\t");

struct __FILE { int handle; };
FILE __stdout;

int sendchar(int ch)
{
    uart->TDR = ch;
    while (!is_bit_set(uart->ISR, USART_ISR_TXE)) {
        ;
    }
    return ch;
}

int fputc(int ch, FILE* f)
{
    return sendchar(ch);
}

int ferror(FILE* f)
{
    return EOF;
}

void _ttywrch(int ch)
{
    sendchar (ch);
}


void _sys_exit(int return_code)
{
  while (1) ;   /* endless loop */
}

} // extern "C"

#endif

