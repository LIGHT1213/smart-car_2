#include "main.h"
#include "dir_pid.h"
#include "math.h"

int ones = 0;
int count2 = 0;
double dir_out;
double dir_out_last = 0;
double dir_value = 0;

extern double a[5];


void direction_pid()
{
    adc_read();
	
	  printf("%.0f  %.0f  %.0f  %.0f  %.0f\n",a[0],a[1],a[2],a[3],a[4]);
//	  printf("%.0f  %.0f    ",a[0],a[4]);
	
    dir_value = 1000*(( sqrt(a[0])- sqrt( a[4])) //电感值整合
                            / (a[0] + a[4]));
	
		//printf("%f\n",dir_value);

    static double dir_errvalue = 0;
    static double dir_integralerrvalue = 0;
    static double dir_erred;
    static double middline = 0;
		
    double kP = 25, kI = 0, kD = 200;

    dir_errvalue = dir_value - middline;
    dir_integralerrvalue += dir_errvalue;

    dir_out = kP * dir_errvalue +
              kI * dir_integralerrvalue +
              kD * (dir_errvalue - dir_erred);
		
    dir_erred = dir_errvalue;
    dir_out_last = dir_out;
    dir_out = dir_out_last * 0.9 + dir_out * 0.1;  //低通滤波

    if(dir_out > 7000)                     //6000  //方向环限幅
        dir_out = 7000;
    if(dir_out < -7000)
        dir_out = -7000;
		
//		printf("%f\n",dir_out);

}