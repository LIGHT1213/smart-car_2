2018年KEA128接口定义：
/***************************************************
作者：HJL
时间：2018-6-25
/***************************************************
名称：ADC接口
功能：读取电磁传感器放大后的电压值，用于转弯.
			读取电池电压值用于警报。
接口：			对应：
C3					AD1
F4					AD2
F5                                                                            AD3
F6         					AD4
F7					AD5
C0        					AD6
C1					AD7
C2					P_ad
/*******************************************************
名称：陀螺仪接口（I2C1）
功能：读取陀螺仪数据

接口：			对应：
H4					SCL
H3					SDA
/*****************************************************
名称：蓝牙接口（UART2）
功能：使用蓝牙读数据，控制。

接口：			对应：
I1					TX
I0					RX
/****************************************************
名称：电机控制接口(FTM2)
功能：控制两个电机的正转反转与速度。

接口：			对应：
H0					IN1(ch0)
H1					IN2(ch1)
B4					IN3(ch4)
B5					IN4(ch5)

/****************************************************
名称：OLED接口(I2C0)
功能：显示屏幕

接口：			对应：
A3					SCL
A2					SDA
/**************************************************
名称：coding接口(ftm0,ftm2)
功能：计数，计算速度

接口：			对应：
E0					C1OUT，ftm0
E7					C2OUT，ftm1
C5					C1DIR,
C6					C2DIR,
/*************************************************
名称：电机使能口
功能：电机的使能于否

接口：			对应：
E1					C_EN

/****************************************************
名称：拨码开关
功能：提供多模式调试的可能

接口：			对应：
C7					K1
D2					K2
D3					K3
D4					K4


