/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		KEA128_port
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/
#include "misc.h"
#include "common.h"
#include "SKEAZ1284.h"
#include "KEA128_port_cfg.h"

#ifndef _KEA128_port_h
#define _KEA128_port_h

typedef enum GPIO_MODE__ //枚举端口状态
{
  GPI = 0, //定义管脚输入方向      
  GPO = 1  //定义管脚输出方向
} GPIO_MOD;

typedef enum PTX_N__ // 枚举管脚编号 
{
    //  A端口     //0~7
    A0,  A1,  A2,  A3,  A4,  A5,  A6,  A7,

    //  B端口     //8~15
    B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,

    //  C端口     //16~23
    C0,  C1,  C2,  C3,  C4,  C5,  C6,  C7,

    //  D端口     //24~31
    D0,  D1,  D2,  D3,  D4,  D5,  D6,  D7,

    //  E端口     //32~39
    E0,  E1,  E2,  E3,  E4,  E5,  E6,  E7,
    
    //  F端口     //40~47
    F0,  F1,  F2,  F3,  F4,  F5,  F6,  F7,
    
    //  G端口     //48~55
    G0,  G1,  G2,  G3,  G4,  G5,  G6,  G7,
    
    //  H端口     //56~63
    H0,  H1,  H2,  H3,  H4,  H5,  H6,  H7,
    
    //  I端口     //64~71
    I0,  I1,  I2,  I3,  I4,  I5,  I6
} PTX_n;

#define PTX(PTX_n)  (PTX_n >> 5)  //获取模块号 PTX_n/32
#define PTn(PTX_n)  (PTX_n & 0x1f)//获取引脚号 PTX_n%32

void port_pull(PTX_n ptx_n);

#endif
