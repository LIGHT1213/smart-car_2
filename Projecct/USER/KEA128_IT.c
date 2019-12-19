/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/KEA128_IT.h 
  * @author  Debug406 Team
  * @date    13-May-2018
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention

  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "KEA128_IT.h"
#include "_DebugSerial.h"

int time;
int upright_flag;
int speed_flag;
int direction_flag;
int control_flag;

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*==============================================================================
             ##### Cortex-M0+ Processor Exceptions Handlers #####
 ==============================================================================*/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	
}

/*==============================================================================
                 ##### S9KEAxxx Peripherals Interrupt Handlers #####    
 ==============================================================================*/
/**-* No Use yet *-
  * @brief  This function handles PIT Channal0 Handler.
  * @param  None
  * @retval None
  */
void PIT_CH0_IRQHandler(void)
{
  PIT0_FLAG_CLR();
	
	time++;
	
	if(time%1 == 0)
		control_flag = 1;
	
	if(time%5 == 0)
		upright_flag = 1;
	
	if(time%25 == 0)
	{
		speed_flag = 1;
	}
	
	if(time%10 == 0)
		direction_flag = 1;
	
	if(time > 100)
		time = 0;
	
}

/**-* No Use yet *-
  * @brief  This function handles PIT Channal1 Handler.
  * @param  None
  * @retval None
  */
void PIT_CH1_IRQHandler(void)
{
  PIT1_FLAG_CLR();   
}

/**-* No Use yet *-
  * @brief  This function handles External Interrupt Handler.
  * @param  None
  * @retval None
  */
void IRQ_IRQHandler(void)
{
  CLEAR_IRQ_FLAG;    
}

/**-* No Use yet *-
  * @brief  This function Keyboard interrupt Handler.
  * @param  None
  * @retval None
  */
void KBI0_IRQHandler(void)
{
  CLEAN_KBI0_FLAG;    
}

/**-* No Use yet *-
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void UART2_IRQHandler(void)
{
  _SerialRec_Interrupt();
}


/**
  * @}
  */ 

/****END OF FILE****/



