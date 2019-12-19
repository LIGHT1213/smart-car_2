#include "main.h"
#include "speed.h"
#include "KEA128_uart.h"
#include "KEA128_IT.h"

#define PIN_EN  F1
#define CON_EN  E1

double r_Value_P;
double l_Value_P;
double r_Value_N;
double l_Value_N;
double r_out_P;
double l_out_P;
double r_out_N;
double l_out_N;
double upright;
extern double upright_out;
extern double upright_value;
extern double speed_out;
extern double dir_out;
extern int stop_flag;
#define RMOTOR_POSTIVE_COMPEN   300  //调节电机死区电压 0-r
#define RMOTOR_NAGTIVE_COMPEN   750      //750

#define LMOTOR_POSTIVE_COMPEN   530  
#define LMOTOR_NAGTIVE_COMPEN  530      //530


void pwm_Init(void)
{
	ftm_pwm_init(ftm2, ftm_ch0, 2000, 5000);
	ftm_pwm_init(ftm2, ftm_ch1, 2000, 5000);
	
	ftm_pwm_init(ftm2, ftm_ch4, 2000, 5000);
	ftm_pwm_init(ftm2, ftm_ch5, 2000, 5000);
	
	gpio_init(CON_EN,GPI,1); 
	gpio_init(PIN_EN,GPO,0); 
}

void pwm_control(void)
{
	gpio_ddr(CON_EN,GPI); //电机使能
	gpio_ddr(PIN_EN,GPO);
	
	gpio_set(PIN_EN,1);
	
	upright = upright_out + upright_value/5; //平滑输出
	
	r_Value_P = RMOTOR_POSTIVE_COMPEN + upright;
	l_Value_P = LMOTOR_POSTIVE_COMPEN + upright;
	
	r_out_P = r_Value_P - dir_out;
	l_out_P = l_Value_P + dir_out;
	
	//printf("%f   %f\n",r_out_P,l_out_P);
	
	if(r_out_P > 9500) //pwm输出限幅
		r_out_P = 9500; 
	if(r_out_P < -9500)
		r_out_P = -9500;
	
	if(l_out_P >9500)
		l_out_P = 9500;
	if(l_out_P < -9500)
		l_out_P = -9500;

	//printf("%f    %f\n",r_out_P,l_out_P);
	//printf("%f    %f\n",r_out_N,l_out_N);
	 
	if(stop_flag == 1)
	{
	 ftm_pwm_duty(ftm2, ftm_ch0, 0);
	 ftm_pwm_duty(ftm2, ftm_ch1, 0);
	
	 ftm_pwm_duty(ftm2, ftm_ch5, 0);
	 ftm_pwm_duty(ftm2, ftm_ch4, 0);
	}
	else if((gpio_get(CON_EN) == 1))
	{
		if(r_out_P >= 0)
		{
			if(l_out_P >= 0)
			{
				ftm_pwm_duty(ftm2, ftm_ch0, r_out_P);
				ftm_pwm_duty(ftm2, ftm_ch5, l_out_P);
				ftm_pwm_duty(ftm2, ftm_ch1, 0);
				ftm_pwm_duty(ftm2, ftm_ch4, 0);
			}
			else
			{
				ftm_pwm_duty(ftm2, ftm_ch0, r_out_P);
				ftm_pwm_duty(ftm2, ftm_ch5, 0);
				ftm_pwm_duty(ftm2, ftm_ch1, 0);
				ftm_pwm_duty(ftm2, ftm_ch4, -l_out_P);
			}
		}
		else
		{
			if(l_out_P >= 0)
			{
				ftm_pwm_duty(ftm2, ftm_ch0, 0);
				ftm_pwm_duty(ftm2, ftm_ch5, l_out_P);
				ftm_pwm_duty(ftm2, ftm_ch1, -r_out_P);
				ftm_pwm_duty(ftm2, ftm_ch4, 0);
			}
			else
			{
				ftm_pwm_duty(ftm2, ftm_ch0, 0);
				ftm_pwm_duty(ftm2, ftm_ch5, 0);
				ftm_pwm_duty(ftm2, ftm_ch1, -r_out_P);
				ftm_pwm_duty(ftm2, ftm_ch4, -l_out_P);
			}
		}
	}
	else
	{
	 ftm_pwm_duty(ftm2, ftm_ch0, 0);
	 ftm_pwm_duty(ftm2, ftm_ch1, 0);
	
	 ftm_pwm_duty(ftm2, ftm_ch5, 0);
	 ftm_pwm_duty(ftm2, ftm_ch4, 0);
	}
	
	
}
