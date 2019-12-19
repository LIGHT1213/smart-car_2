#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "KEA128_port_cfg.h"
#include "stdio.h"
#include "KEA128_ftm.h"
#include "KEA128_pit.h"
#include "KEA128_gpio.h"
#include "KEA128_port.h"
#include "KEA128_adc.h"
#include "KEA128_irq.h"
#include "KEA128_uart.h"
#include "KEA128_kbi.h"
#include "KEA128_flash.h"
#include "KEA128_systick.h"
#include "KEA128_i2c.h"
#include "KEA128_spi.h"
//-------------

#include "SEEKFREE_18TFT.h"
#include "SEEKFREE_FUN.h"
#include "SEEKFREE_IIC.h"
#include "SEEKFREE_L3G4200D.h"
#include "SEEKFREE_MMA8451.h"
#include "SEEKFREE_MPU6050.h"
#include "SEEKFREE_NRF24L01.h"
#include "SEEKFREE_OLED.h"
#include "SEEKFREE_TSL1401.h"
#include "SKEAZ1284.h"

/* Debug Lab's HeadLib */
#include "_DebugSerial.h"
#include "direction.h"
#include "KEA128_IT.h"
#include "dir_pid.h"
#include "speed.h"
#include "speed_pid.h"
#include "up right_pid.h"

#define _TEST_TAG_

/* Serial Debug */
#define _SERIAL_DEBUG_

/* IIC Mode */
#define _SOFT_IIC_SIMULATION_

/* Motor Enable */
#define _Motor_EN

#endif



