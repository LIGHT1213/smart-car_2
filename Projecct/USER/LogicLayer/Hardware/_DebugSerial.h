/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/../_DebugSerial.h 
  * @author  Debug406 Team
  * @date    26-March-2018
  * @brief   Header for _DebugSerial.c module
  ******************************************************************************
  * @attention
      UART2 - PI0 -> UART2_RX 
              PI1 -> UART2_TX
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEBUG_SMATRCAR_SERIAL_H
#define DEBUG_SMATRCAR_SERIAL_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SerialInit(void);
void SerialSendChar(uint8_t ch);
void SerialSendString(uint8_t buff[], uint16_t lenth);

/* Reference Only -> (F12) USART2_IRQHandler(); */
/*static*/ inline void _SerialRec_Interrupt(void);

#ifdef __GNUC__ /* printf() */
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#endif // !DEBUG_SMATRCAR_SERIAL_H 
