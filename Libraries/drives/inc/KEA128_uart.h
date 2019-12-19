/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		KEA128_uart
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
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
