#include "main.h"
#include "speed_pid.h"

double speed_out;
double speed_old;
double speed_r;
double speed_l;
double speed_value;
double speed_set;
int bmq_r;
int bmq_l;
int bmq_value;
static double speed_errvalue = 0;
static double speed_integralerrvalue = 0;
static double speed_erred = 0;
static double speed_smooth = 0;

void bmq_Init()
{
	ftm_count_init(ftm0);
  ftm_count_init(ftm1);
}

void speed_pid()
{
	speed_set = 350;  //first:660  best:500    450
	
	bmq_r = ftm_count_get(ftm0);
	bmq_l = ftm_count_get(ftm1);
	ftm_count_clean(ftm0);
	ftm_count_clean(ftm1);
	bmq_value = bmq_r + bmq_l;
	
	//printf("%d    %d\n",bmq_r,bmq_l);
	
	speed_r = bmq_r / 512.0 / 40.0 * 1000 * ( 30 / 68.0 ) * 0.2;
  speed_l = bmq_l / 512.0 / 40.0 * 1000 * ( 30 / 68.0 ) * 0.2;
	
	speed_value = ( speed_r + speed_l ) / 2.0;
	
	speed_smooth = bmq_value - speed_set;
	speed_errvalue *= 0.8;
	speed_errvalue += speed_smooth * 0.2;
	
//	printf("%f\n",speed_value);
	
	speed_integralerrvalue += speed_errvalue;
	
	if(speed_integralerrvalue > 10000)
	  speed_integralerrvalue = 10000;
	if(speed_integralerrvalue < -10000)
	  speed_integralerrvalue = 10000;
	
	speed_old = speed_out ;
	
	static double const kP = -60 , kI = -0.3, kD = 0;
	
	speed_out = kP * speed_errvalue + kI * speed_integralerrvalue + kD * ( speed_errvalue - speed_erred );
	speed_erred = speed_out;
	
	speed_out = 0.1 * speed_out + 0.9 * speed_old;
	
	//speed_out = 0;

	if(speed_out > 8000)
		speed_out = 8000;
	if(speed_out < -8000)
		speed_out = -8000;
	//printf("%f\n",speed_out);
}
