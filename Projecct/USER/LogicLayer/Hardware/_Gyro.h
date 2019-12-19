/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/../_Gyro.h 
  * @author  Debug406 Team
  * @date    26-March-2018
  * @brief   Header for _Gyro.c module
  ******************************************************************************
  * @attention
    IIC - A3 -> I2C0_SCL_PIN
          A2 -> I2C0_SDA_PIN
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEBUG_SMATRCAR_GYRO_H
#define DEBUG_SMATRCAR_GYRO_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "SEEKFREE_IIC.h"

#include "_DebugSerial.h"
#include "math.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void GyroInit(void);
uint8_t * UpdateGyroData(void);

#endif // DEBUG_SMATRCAR_GYRO_H 
