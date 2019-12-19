/** See a brief introduction (right-hand button) */
#include "KEA128_pit.h"

/* Private include -----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  PIT(Periodic Interrupt Timer) Initialize.
  * @param  pit : channal number - ZERO or ONE.
            cnt : count - Set TDVAL(Timer Load Value Register)
  * @retval None
  */
void InitPit(Pit_t pit, uint32_t cnt)
{
  /* PIT configuration **************************************************/
  /* PIT configured as follows:
       - PIT clock -> ???
       - Set Interrupt time -> 
       - Reset PIT;
       - Open PIT interrupt.
   */
	SIM->SCGC |= SIM_SCGC_PIT_MASK;
	PIT->MCR   = 0x00;
	PIT->CHANNEL[pit].LDVAL  = cnt;
	PIT_FLAG_CLR(pit);
	PIT->CHANNEL[pit].TCTRL &= ~ PIT_TCTRL_TEN_MASK;
  PIT->CHANNEL[pit].TCTRL  = ( 0
              | PIT_TCTRL_TEN_MASK
              | PIT_TCTRL_TIE_MASK );
  
	NVIC_EnableIRQ((IRQx_Type)(PIT_CH0_IRQn + (int)pit));
}

/**
  * @brief  PIT(Periodic Interrupt Timer) Initialize.
  * @param  pit : channal number - ZERO or ONE.
            cnt : count - Set TDVAL(Timer Load Value Register)
  * @retval None
  */
void PitDelay(Pit_t pit, uint32_t cnt)
{
  /* PIT configuration **************************************************/
  /* PIT configured as follows:
       - PIT clock -> ???
       - Set Interrupt time -> 
       - Reset PIT;
       - Delay.
   */
	SIM->SCGC |= SIM_SCGC_PIT_MASK;
	PIT->MCR   = 0x00;
	PIT->CHANNEL[pit].LDVAL  = cnt;
	PIT_FLAG_CLR(pit);
	PIT->CHANNEL[pit].TCTRL &= ~ PIT_TCTRL_TEN_MASK;
  PIT->CHANNEL[pit].TCTRL  = PIT_TCTRL_TEN_MASK;
  
	while( !((PIT->CHANNEL[pit].TFLG) & PIT_TFLG_TIF_MASK) ){}
  PIT_FLAG_CLR(pit);
}

/**
  * @brief  PIT(Periodic Interrupt Timer) Stop.
  * @param  pit : channal number - ZERO or ONE.
  * @retval None
  */
void PitStop(Pit_t pit)
{
	PIT_FLAG_CLR(pit);
	PIT->CHANNEL[pit].TCTRL &= ~ PIT_TCTRL_TEN_MASK; 
}

/**
  * @brief  Get pit time.
  * @param  pit : channal number - ZERO or ONE.
  * @retval If overtime, return 0XFFFFFFFF,
            else return time.
  */
uint32_t PitTimeGetFrom(Pit_t pit)
{
	if(PIT->CHANNEL[pit].TFLG &  PIT_TFLG_TIF_MASK)
	{
		PIT_FLAG_CLR(pit);
		PIT->CHANNEL[pit].TCTRL &= ~ PIT_TCTRL_TEN_MASK;
		return 0XFFFFFFFF;
	}
  else
  {
    return (uint32_t)(~0) - PIT->CHANNEL[pit].CVAL;
  }
}

void pit0Init(uint32_t cnt, uint32_t priority)
{
	InitPit(ZERO,cnt);
	NVIC_SetPriority(PIT_CH0_IRQn,priority);
	NVIC_EnableIRQ(PIT_CH0_IRQn);
	
}

/**
  * @brief  initpit1.
	* @param  cnt : time,prioprity £º1-X.
  * @retval 
	* @simple pit0Init(1000,1);
  */

void pit1Init(uint32_t cnt, uint32_t priority)
{
	InitPit(ONE,cnt);
	NVIC_SetPriority(PIT_CH1_IRQn,priority);
	NVIC_EnableIRQ(PIT_CH1_IRQn);
	
}
