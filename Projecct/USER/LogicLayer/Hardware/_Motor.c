/** See a brief introduction (right-hand button) */
#include "_Motor.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#ifdef _Motor_EN
#define MOTOR_ENABLE    1
#else 
#define MOTOR_ENABLE    0
#endif  
  
#define PIN_EN          F1
#define GET_EN					E1
#define ARR_            10000

#define _GPIO_Init(pin, mode, elevel)   gpio_init(pin, mode, elevel)
#define _PortPull(pin)                  port_pull(pin)
#define _FTM_Init(ftm, channal, reg_ARR, reg_CCRx) \
                                        ftm_pwm_init(ftm, channal, reg_ARR, reg_CCRx)
#define _FTM_LMotorDuty(reg_CCRx)       ftm_pwm_duty(ftm1, ftm_ch1, reg_CCRx)
#define _GPIO_Set(pin, elevel)          gpio_set(pin, elevel);  

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void _MotorDrive(int16_t lValue, int16_t rValue);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  
  * @param  None
  * @retval None
  */
void MotorInit(void)
{
//  _GPIO_Init(C6, GPO, 0);
//	_PortPull(C6);
//  _FTM_Init(ftm1, ftm_ch1, ARR_, 0);
//  
//  _GPIO_Init(B2, GPO, 0);
//	_PortPull(B2);
//  _FTM_Init(ftm0, ftm_ch1, ARR_, 0);
//  

	_FTM_Init(ftm2,ftm_ch4,ARR_,0);
	_FTM_Init(ftm2,ftm_ch5,ARR_,0);
	
	_FTM_Init(ftm2,ftm_ch0,ARR_,0);
	_FTM_Init(ftm2,ftm_ch1,ARR_,0);

  _GPIO_Init(PIN_EN, GPO, MOTOR_ENABLE);
	_PortPull(PIN_EN);
	
	_GPIO_Init(GET_EN, GPI, 0);

}

/**
  * @brief  
  * @param  None
  * @retval None
  */
void SetPWM(int16_t lValue, int16_t rValue)
{
  if(rValue > 0)
  {
    rValue += 180;
  }
  else if(rValue < 0)
  {
    rValue -= 180;
  }
  
  _MotorDrive(lValue, rValue);
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
void _MotorDrive(int16_t lValue, int16_t rValue)
{
  gpio_set(PIN_EN, 0);  
  
//  if(lValue >= 0)
//  {
//    gpio_set(B2, 0);
//    (lValue >= ARR_) ?
//    ftm_pwm_duty(ftm0, ftm_ch1, ARR_)  :
//    ftm_pwm_duty(ftm0, ftm_ch1, lValue);    
//  }
//  else
//  {
//    gpio_set(B2, 1);
//    (lValue <= -ARR_) ?
//    ftm_pwm_duty(ftm0, ftm_ch1, 0)  :
//    ftm_pwm_duty(ftm0, ftm_ch1, lValue + ARR_);
//  }
//  
//  if(rValue >= 0)
//  {
//    gpio_set(C6, 0);
//    (rValue >= ARR_) ?
//    ftm_pwm_duty(ftm1, ftm_ch1, ARR_)  :
//    ftm_pwm_duty(ftm1, ftm_ch1, rValue);    
//  }
//  else
//  {
//    gpio_set(C6, 1);
//    (rValue <= -ARR_) ?
//    ftm_pwm_duty(ftm1, ftm_ch1, 0)  :
//    ftm_pwm_duty(ftm1, ftm_ch1, rValue + ARR_);
//  }
  if(lValue >= 0)
	{
		ftm_pwm_duty(ftm2,ftm_ch1,0);
		(lValue >= ARR_) ?
		ftm_pwm_duty(ftm2, ftm_ch0, ARR_)  :
		ftm_pwm_duty(ftm2, ftm_ch0, lValue);    
  }
	else
	{
		ftm_pwm_duty(ftm2,ftm_ch0,0);
		(lValue <= -ARR_) ?
		ftm_pwm_duty(ftm2, ftm_ch1, ARR_)  :
		ftm_pwm_duty(ftm2, ftm_ch1, -lValue);
	}
	
	if(rValue >= 0)
	{
		ftm_pwm_duty(ftm2,ftm_ch4,0);
		(rValue >= ARR_) ?
		ftm_pwm_duty(ftm2, ftm_ch5, ARR_)  :
		ftm_pwm_duty(ftm2, ftm_ch5, lValue);
	}		
	else
	{
		ftm_pwm_duty(ftm2,ftm_ch5,0);
		(rValue <= -ARR_) ?
		ftm_pwm_duty(ftm2, ftm_ch4, ARR_)  :
		ftm_pwm_duty(ftm2, ftm_ch4, -lValue);
	}
	
  gpio_set(PIN_EN, MOTOR_ENABLE);
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
void MotorEN(void)
{
	if(gpio_get(GET_EN)==0)
		MotorDisable();
	else
		MotorEnable();
		
}