/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/KEA128_pit.h 
  * @author  Debug406 Team
  * @date    13-May-2018
  * @brief   Header for KEA128_pit.c module
  ******************************************************************************
  * @attention
  
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KEA128_PIT_H
#define KEA128_PIT_H

/* Includes ------------------------------------------------------------------*/
#include "misc.h"
#include "common.h"
#include "SKEAZ1284.h"
#include "KEA128_port_cfg.h"

/* Exported types ------------------------------------------------------------*/
typedef enum PITn__
{
  ZERO,
  ONE
} Pit_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define     PIT_FLAG_CLR(Pit_t)           PIT->CHANNEL[Pit_t].TFLG |= PIT_TFLG_TIF_MASK
#define     PIT0_FLAG_CLR()               PIT->CHANNEL[ZERO].TFLG  |= PIT_TFLG_TIF_MASK
#define     PIT1_FLAG_CLR()               PIT->CHANNEL[ONE].TFLG   |= PIT_TFLG_TIF_MASK
//------------------------------------以下代码用于PIT中断------------------------------------
#define     pit_init_ms(PITn_e, ms)          InitPit(PITn_e,ms * CLK_BUS/1000);                  //初始化Pit_t，并设置定时时间(单位为 ms)
#define     pit_init_us(PITn_e, us)          InitPit(PITn_e,us * CLK_BUS/1000000);             //初始化Pit_t，并设置定时时间(单位为 us)
#define     pit_init_ns(PITn_e, ns)          InitPit(PITn_e,ns * CLK_BUS/1000000000);          //初始化Pit_t，并设置定时时间(单位为 ns)

//------------------------------------以下代码用于PIT延时------------------------------------
#define     pit_delay_ms(PITn_e, ms)         PitDelay(PITn_e,ms * CLK_BUS/1000);                //PIT延时 ms
#define     pit_delay_us(PITn_e, us)         PitDelay(PITn_e,us * CLK_BUS/1000000);           //PIT延时 us
#define     pit_delay_ns(PITn_e, ns)         PitDelay(PITn_e,ns * CLK_BUS/1000000000);        //PIT延时 ns(40M总线频率时最小单位为25ns)

/* Exported functions ------------------------------------------------------- */
void InitPit(Pit_t pit, uint32_t cnt);
void PitDelay(Pit_t pit, uint32_t cnt);
void PitStop(Pit_t pit);

uint32_t PitTimeGetFrom(Pit_t pit);

#endif //!KEA128_PIT_H
