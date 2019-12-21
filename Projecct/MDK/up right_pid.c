#include "main.h"
#include "up right_pid.h"
#include "up right.h"

static double angle_errvalue = 0;
static double angle_integralerrvalue = 0;
static double angle_erred = 0;
double a_1;
double a_2;
double a_3;
double Pitch_value;
double yaw_value;
double roll_value;
double angle_old;
double angle_set = 120;
double upright_out;
double upright_old;
double upright_value;
double I2C_ARR;
extern int     change_flag;
extern double  speed_out;
uint8_t pitch_angle[30];
	
void I2C_Init()
{
	i2c_init(i2c1 , 400);
}

short CharToShort(unsigned char cData[])
{
	return ((short)cData[1]<<8)|cData[0];
}

void upright_pid()
{
	i2c_read_reg_bytes(i2c1 , 0x50 , 0x34 , 24 , &pitch_angle[0]); //AX：X轴角速度
	
	Pitch_value =  (float)CharToShort(&pitch_angle[18])/32768.0*180; //Y轴角度
	yaw_value = ((float)CharToShort(&pitch_angle[20])/32768.0*180);  //Z轴角度
	roll_value = ((float)CharToShort(&pitch_angle[22])/32768.0*180); //X轴角度
	
	//printf("Pitch_value =  %f\n",Pitch_value);
	
	
	if(Pitch_value == 0)
		Pitch_value = angle_old;
	
	angle_errvalue = Pitch_value - angle_set;
	
	angle_integralerrvalue += angle_errvalue;
	
	if(angle_errvalue > 25)
		angle_errvalue = 25;
	if(angle_errvalue < -25)
		angle_errvalue = -25;
	
	static double const kP = -300,kI = 0,kD = -1000;
	
	upright_out = kP * (angle_errvalue - speed_out/1000) + kI * angle_integralerrvalue + kD * (angle_errvalue - angle_erred); //角度环和速度环串级
	
	angle_erred = angle_errvalue;
	
	if(upright_out > 8000)                                                       //角度环限幅
		upright_out = 8000;
	if(upright_out < -8000)
		upright_out = -8000;
	//printf("%f\n",upright_out);
	angle_old = Pitch_value;
		change_flag = 1;
	if(change_flag == 1)
	{
			upright_out = -2200;                //2150
	}
	upright_value = upright_out - upright_old;
	upright_old = upright_out;
}
