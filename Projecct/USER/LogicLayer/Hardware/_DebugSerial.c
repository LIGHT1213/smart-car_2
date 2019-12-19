/** See a brief introduction (right-hand button) */
#include "_DebugSerial.h"
#include "SKEAZ1284.h"
#include "string.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define RESET        0
#define SET          1
#define _SERIAL_UART UART2

/* Private variables ---------------------------------------------------------*/
const static uint32_t _BAUD_RATE   = 115200;
const static uint16_t _SERIAL_BAUD = (CLK_BUS >> 4) / _BAUD_RATE;

int stop_flag = 1;
int change_flag = 0;
int wait_flag = 0;

/* Private function prototypes -----------------------------------------------*/
inline void _SerialRec_Interrupt(void);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  KEA128 Serial Init function.
  * @param  None
  * @retval None
  */
void SerialInit(void)
{  
  /* Enable UART2's Clock *************************************************/
  /* UART2's configured as follows:
        - Pin -> PTI1( _TX ); PTI0( _RX )
        - [Reg : C1]
          LOOP) 0 - Normal operation - RxD and TxD use separate pins.
             M) 0 - 8Bit Mode.
            PE) 0 - No hardware parity generation or checking.
            PT) 0 - Even parity.
        - Baudrate -> 115200 (not precise)
        - Receive Interrupt enable.
              
   */
//	
//  SIM->SCGC         |= SIM_SCGC_UART2_MASK;  
//  SIM->PINSEL1      |= SIM_PINSEL1_UART2PS_MASK;
//  _SERIAL_UART->C1  |= 0x00;  
//  _SERIAL_UART->BDH &= ~UART_BDH_SBR_MASK;
//  _SERIAL_UART->BDH |= UART_BDH_SBR(_SERIAL_BAUD >> 8);      
//  _SERIAL_UART->BDL  = UART_BDL_SBR((uint8_t)(_SERIAL_BAUD & 0x00FF ));   
//  _SERIAL_UART->C2  |= UART_C2_RIE_MASK;
//  
  

//  /* Enable Transport & Enable Receive. ***********************************/
//  _SERIAL_UART->C2  |= (0
//                       | UART_C2_TE_MASK
//                       | UART_C2_RE_MASK );

UART_Init(2,115200);
//	uart_txc_irq_en(2);
	uart_rx_irq_en(2);
	NVIC_EnableIRQ(UART2_IRQn);
}

/**
  * @brief  UART output an char.
  * @param  ch - ASCII code
  * @retval None
  */
void SerialSendChar(uint8_t ch)
{  
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  _SERIAL_UART->D = (uint8_t)ch;
  
  /* Loop until the end of transmission */
  while(((_SERIAL_UART->S1) & UART_S1_TDRE_MASK) == RESET) 
  {}
}

/**
  * @brief  UART output a string.
  * @param  buff  - String buffer.
            lenth - String Lenth.
  * @retval None
  */
void SerialSendString(uint8_t buff[], uint16_t lenth)
{
  uint16_t loop = 0;
  for(loop = 0; loop < lenth; ++loop)
  {
    _SERIAL_UART->D = (uint8_t)buff[loop];
    
    while(((_SERIAL_UART->S1) & UART_S1_TDRE_MASK) == RESET) 
    {}
  }
}

/**
  * @brief  UART2 Interrupt Interface.
            Reference Only -> (F12) USART2_IRQHandler();
  * @param  None
  * @retval None
  */
void _SerialRec_Interrupt(void)
{
	const uint8_t f_stop = 9;
	const uint8_t f_start = 8;
	const uint8_t f_change = 7;
	const uint8_t f_common = 6;
	const uint8_t f_wait = 5;
	
  static uint8_t _serialBuffer[1] = "";

  
  _serialBuffer[0] = _SERIAL_UART->D;
	
   if(_serialBuffer[0] == f_stop )
	{
		stop_flag = 0;
		printf("start\n");
	}
	 if(_serialBuffer[0] == f_start)
	{
		stop_flag = 1;
		printf("stop\n");
	}
	//printf("%d\n",_serialBuffer[0]);
	_serialBuffer[0] = NULL;
	
	static uint8_t _Buffer[1] = "";

  
  _Buffer[0] = _SERIAL_UART->D;
	
   if(_Buffer[0] == f_change)
	{
		change_flag = 1;
		printf("change\n");
	}
	
	if(_Buffer[0] == f_wait)
	{
		wait_flag = 1;
		change_flag = 0;
		printf("wait\n");
	}
	
	if(_Buffer[0] == f_common)
	{
		wait_flag = 0;
		printf("common\n");
	}
	
	//printf("%d\n",_Buffer[0]);
	_Buffer[0] = NULL;
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  _SERIAL_UART->D = (uint8_t)ch;
  
  /* Loop until the end of transmission */
  while(((_SERIAL_UART->S1) & UART_S1_TDRE_MASK) == RESET) 
  {}

  return ch;
}
