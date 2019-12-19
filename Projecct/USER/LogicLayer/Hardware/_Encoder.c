/** See a brief introduction (right-hand button) */
#include "_Encoder.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

#define Rcode			ftm0
#define Lcode			ftm1

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
/**
  * @brief  
  * @param  None
  * @retval None
  */

void EncoderInit()
{
    ftm_count_init(Rcode);   //��E0���������������м���    E0�ӱ�����LSB    
    gpio_init(C5,GPI,0);    //�����жϷ���                  C5�ӱ�����DIR
    port_pull(C5);          //IO����
    port_pull(E0);          //IO����
    
    ftm_count_init(Lcode);   //��E7���������������м���    E7�ӱ�����LSB
    gpio_init(C6,GPI,0);    //�����жϷ���                  H5�ӱ�����DIR
    port_pull(C6);          //IO����
    port_pull(E7);          //IO����
	
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
uint32_t sppedL()
{
	
	return 0;
}


/**
  * @brief  
  * @param  None
  * @retval None
  */

uint32_t sppedR()
{
	
	return 0;
}

/**
  * @brief  
  * @param  None
  * @retval None
  */

uint32_t spped()
{
	
	return 0;
}