/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/../_Motor.h 
  * @author  Debug406 Team
  * @date    26-March-2018
  * @brief   Header for _Gyro.c module
  ******************************************************************************
  * @attention
    MOTOR - PC5 -> IN1 -> PWM    (+)
            PC6 -> IN2 -> PIN    (-)
            B2  -> IN3 -> PWM    (-)
            B3  -> IN4 -> PWM    (+)
            F1  -> EN
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEBUG_SMATRCAR_MOTOR_H
#define DEBUG_SMATRCAR_MOTOR_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "main.h"
#include "KEA128_gpio.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define MotorEnable()                 gpio_set(F1, 1)
#define MotorDisable()                gpio_set(F1, 0)

/* Exported functions ------------------------------------------------------- */
void MotorInit(void);
void SetPWM(int16_t lValue, int16_t rValue);
void MotorEN(void);

#endif // DEBUG_SMATRCAR_MOTOR_H 
