#include<main.h>

extern int speed_flag;
extern int upright_flag;
extern int direction_flag;
extern int control_flag;

int main()
{
	SerialInit();                                //初始化
	pwm_Init();
	I2C_Init();
	bmq_Init ();
	adc_Init ();
	UART_Init(2,115200);
	InitPit(ZERO ,1 * CLK_BUS/1000);
	
	speed_flag = 0;
	upright_flag = 0;
  direction_flag = 0;
	control_flag = 0;
	
	
	while(1)
	{
		if(speed_flag == 1)
		{
			speed_pid ();
			speed_flag = 0;
		}
		if(upright_flag == 1)
		{
			upright_pid ();
			upright_flag = 0;
		}
		if(direction_flag == 1)
		{
			direction_pid ();
			direction_flag = 0;
		}
		if(control_flag == 1)
		{
			pwm_control();
			control_flag = 0;
		}
	}
}