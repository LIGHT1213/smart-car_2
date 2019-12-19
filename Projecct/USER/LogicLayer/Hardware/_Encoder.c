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
    ftm_count_init(Rcode);   //对E0引脚输入的脉冲进行计数    E0接编码器LSB    
    gpio_init(C5,GPI,0);    //用于判断方向                  C5接编码器DIR
    port_pull(C5);          //IO上拉
    port_pull(E0);          //IO上拉
    
    ftm_count_init(Lcode);   //对E7引脚输入的脉冲进行计数    E7接编码器LSB
    gpio_init(C6,GPI,0);    //用于判断方向                  H5接编码器DIR
    port_pull(C6);          //IO上拉
    port_pull(E7);          //IO上拉
	
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