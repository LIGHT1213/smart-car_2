/** See a brief introduction (right-hand button) */
#include "Up_Right.h"
#include "_Gyro.h"
#include "_DebugSerial.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct PIDPack__
{
  double _anglePredic;
  double _angleRate;
} PIDPack_t;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define STANDUP_ANGLE 20.8

/* Private variables ---------------------------------------------------------*/
const static double _RADIAN_TO_ANGLE = 180 / 3.1415926535;
static PIDPack_t _pidPackge = { 0, 0 };

/* Private function prototypes -----------------------------------------------*/
void   _Kalman_Filter(double angle_read, double anglerate_read);
double _PIDController(PIDPack_t newValue);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  
  * @param  None
  * @retval None
  */
uint16_t UpRightControl()
{
  uint8_t * pGyro      = UpdateGyroData();
  double gyroAngle     = -( asin((float)
                          ( ((int16_t)(pGyro[10] << 8) | pGyro[11]) >> 2) 
                            / 0x1000) * _RADIAN_TO_ANGLE ),
         gyroAngleRate = (((float)((int16_t)(pGyro[2] << 8) | pGyro[3]))*7.820) / 1000.0;  
  int16_t pidValue;
  
  _Kalman_Filter(gyroAngle, gyroAngleRate);
  pidValue = _PIDController((PIDPack_t){ STANDUP_ANGLE - _pidPackge._anglePredic, 
                                                         _pidPackge._angleRate });
  
  #ifdef _SERIAL_DEBUG_
  printf("%f, %d\n", gyroAngle, pidValue);
  systick_delay_ms(100);
  #endif
  
  SetPWM(pidValue, pidValue);
  return pidValue;
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
double _PIDController(PIDPack_t newValue)
{
  static double const kP = -95, kI = 0, kD =0;//8.6
  static double const integralThreshold = 0.8;
  static double       integralErr = 0;

  integralErr += newValue._anglePredic;
  if (integralErr >  integralThreshold) integralErr =  integralThreshold;
  if (integralErr < -integralThreshold) integralErr = -integralThreshold;
  double output = kP *  newValue._anglePredic + 
                  kI *  integralErr + 
                  kD *  newValue._angleRate;
  
  return output;
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
void _Kalman_Filter(double angle_read, double anglerate_read)
{
  static float P[2][2] = { { 1, 0 },
                           { 0, 1 } };
  static float Q_angle = 6, Q_gyro = 0.05, R_angle = 0.6, dt = 0.005;
  static float t_0 = 0, t_1 = 0;
  static float Pdot[2][2] = { {0,0},{0,0} };
  static float C = 1;
  static float E = 0;
  static float q_bias = 0;
  static float Angle_err = 0;
  static float PCt[2] = {0, 0};
  static float K[2] = {0, 0};
  
	/* Prediction  - 积分t-1时的量, 来估计t时的角度量 */
	_pidPackge._anglePredic += (anglerate_read - q_bias) * dt;
	/* new message - 观测值减估计值 */
	Angle_err = angle_read - _pidPackge._anglePredic;
  
	Pdot[0][0] =  Q_angle - P[0][1] - P[1][0];	//协方差暂存
	Pdot[0][1] = -P[1][1];
	Pdot[1][0] = -P[1][1];
	Pdot[1][1] =  Q_gyro;

	P[0][0] += Pdot[0][0] * dt;		//协方差积分
	P[0][1] += Pdot[0][1] * dt;
	P[1][0] += Pdot[1][0] * dt;
	P[1][1] += Pdot[1][1] * dt;	

	PCt[0] = C * P[0][0];			//计算新的估计误差协方差矩阵
	PCt[1] = C * P[1][0];	

	E = R_angle + C * PCt[0];		//计算新息协方差

	K[0] = PCt[0] / E;				//计算卡尔曼增益
	K[1] = PCt[1] / E;

	t_0 = C * P[0][0];					//新协方差
	t_1 = C * P[0][1];

	P[0][0] -= K[0] * t_0;			//向量相乘
	P[0][1] -= K[0] * t_1;
	P[1][0] -= K[1] * t_0;
	P[1][1] -= K[1] * t_1;
	
	/* 预测结果 = 转移矩阵 * 上一状态预测值 + 卡尔曼系数 * 新息值 */
	/*  */
	_pidPackge._anglePredic += K[0] * Angle_err;
	/* 后验估计误差协方差 */
	q_bias      += K[1] * Angle_err;
	/* 最优角速度输出 */
	_pidPackge._angleRate = anglerate_read - q_bias;
}
