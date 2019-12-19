/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		KEA128_uart
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/

#ifndef _KEA128_uart_h
#define _KEA128_uart_h

#include "misc.h"
#include "common.h"
#include "SKEAZ1284.h"
#include "KEA128_port_cfg.h"
#include "stdio.h"

#define UART_0 0
#define UART_1 1
#define UART_2 2
typedef int UARTn;

#define DEBUG_PORT  UART_2
#define USE_USART0
#define USE_USART1
#define USE_USART2
#define DEBUG_BAUD  115200

uint32_t UART_Init(UARTn uartn, uint32_t baud);
void uart_putchar (UARTn uartn, uint8_t ch);
void uart_putbuff (UARTn uartn, uint8_t *buff, uint32_t len);
void uart_putstr (UARTn uartn, const uint8_t *str);
void uart_getchar (UARTn uartn, uint8_t *ch);
void uart_rx_irq_en(UARTn uartn);
void uart_txc_irq_en(UARTn uartn);
void uart_rx_irq_dis(UARTn uartn);
void uart_txc_irq_dis(UARTn uartn);

#endif
