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
//------------------------------------���´�������PIT�ж�------------------------------------
#define     pit_init_ms(PITn_e, ms)          InitPit(PITn_e,ms * CLK_BUS/1000);                  //��ʼ��Pit_t�������ö�ʱʱ��(��λΪ ms)
#define     pit_init_us(PITn_e, us)          InitPit(PITn_e,us * CLK_BUS/1000000);             //��ʼ��Pit_t�������ö�ʱʱ��(��λΪ us)
#define     pit_init_ns(PITn_e, ns)          InitPit(PITn_e,ns * CLK_BUS/1000000000);          //��ʼ��Pit_t�������ö�ʱʱ��(��λΪ ns)

//------------------------------------���´�������PIT��ʱ------------------------------------
#define     pit_delay_ms(PITn_e, ms)         PitDelay(PITn_e,ms * CLK_BUS/1000);                //PIT��ʱ ms
#define     pit_delay_us(PITn_e, us)         PitDelay(PITn_e,us * CLK_BUS/1000000);           //PIT��ʱ us
#define     pit_delay_ns(PITn_e, ns)         PitDelay(PITn_e,ns * CLK_BUS/1000000000);        //PIT��ʱ ns(40M����Ƶ��ʱ��С��λΪ25ns)

/* Exported functions ------------------------------------------------------- */
void InitPit(Pit_t pit, uint32_t cnt);
void PitDelay(Pit_t pit, uint32_t cnt);
void PitStop(Pit_t pit);

uint32_t PitTimeGetFrom(Pit_t pit);

#endif //!KEA128_PIT_H
