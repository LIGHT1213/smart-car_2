#ifndef _upright_h__
#define _up right_h__

#include <stdint.h>
#include "SEEKFREE_IIC.h"

#include "_DebugSerial.h"
#include "math.h"

void Gyro_Init(void);
uint8_t * UpdateGyroData(void);

#endif
