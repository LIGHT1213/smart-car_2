/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/../_Encoder.h 
  * @author  Debug406 Team
  * @date    26-March-2018
  * @brief   Header for _Encoder.c module
  ******************************************************************************
  * @attention

  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEBUG_SMATRCAR_ENCODER_H
#define DEBUG_SMATRCAR_ENCODER_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "main.h"
#include "KEA128_ftm.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void EncoderInit(void);
uint32_t sppedL(void);
uint32_t sppedR(void);
uint32_t spped(void);

#endif // DEBUG_SMATRCAR_ENCODER_H 
