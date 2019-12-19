/** See a brief introduction (right-hand button) */
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#ifndef _TEST_TAG_
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Local variables *****************************************************/  
  /* Initialize Step *****************************************************/
  SerialInit();
  GyroInit();
  MotorInit();
  
  /* Infinite loop *******************************************************/
  while(1)
  {
		MotorEN();
    UpRightControl();
  }
}

#else

/**
  * @brief  Test main program
  * @param  None
  * @retval None
  */
int /*Test*/ main(void)
{
  /* Local variables *****************************************************/
  
  /* Initialize Step *****************************************************/
  SerialInit();
  GyroInit();
  MotorInit();
	EncoderInit();
  gpio_init(G0,GPO,0);
	port_pull(G0);          //IO…œ¿≠
  /* Infinite loop *******************************************************/
  while(1)
  {
//		MotorEN();
//		UpRightControl();
    uint8_t * tmp, i;
    tmp = UpdateGyroData();
    gpio_turn(G0);
//		printf("%d\n",ftm_count_get(ftm1));
//		ftm_count_clean(ftm1);
//		printf("%d\n",ftm_count_get(ftm1));
    printf("%3.6f, %3.6f\n", 
    -(asin((float)(((int16_t)(tmp[10] << 8) | tmp[11]) >> 2) / 0x1000) * 180 / 3.1415926535), 
    (((float)((int16_t)(tmp[2] << 8) | tmp[3]))*7.820) / 1000.0 );
    
    systick_delay_ms(100);
  }
}

#endif //!_TEST_TAG_

