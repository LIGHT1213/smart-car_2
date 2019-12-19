/** See a brief introduction (right-hand button) */
#include "system_SKEAZ1284.h"

/* Private include -----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void _DisableWdog(void);
void _CoreStart(void);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  This function will call at startup_SKEAZ1284.s
  * @param  None
  * @retval None
  */
void _CoreStart(void)
{
  /* Core Start Part ****************************************************/
  /* Core Start configured as follows:
        [SIM]
          - NMIE (reg : 1) set 0, disenable NMI.
  
        [DIV]
          - DIV1 by 1
          - DIV2 by 2
  
        [OSC]
          - [ KEA128_CLOCK != 2 ]
             - OSC module enabled
             - Oscillator clock source is selected
             - Select High frequency range 
             - High-gain mode

          - [ KEA128_CLOCK == 2 (Reset value 00h)]
             - OSC module disabled
             - External clock source from EXTAL pin is selected
             - Low High frequency range 
             - Low-gain mode
  
        [ICS]
          -[ C2 ] 
             - Divides the selected clock by 1
             - Disabled in bypass modes
          -[ C1 != 2 ]
             - Output of FLL is selected
             - ICSIRCLK is Active
          -[ C1 == 2 ]
             - Output of FLL is selected
             - Internal Reference Clock is selected
             - Internal Reference Clock Enable
             - Internal Reference Stop Enable
   */   
  SIM->SOPT0 = 0x0C;
  SIM->CLKDIV = SIM_CLKDIV_OUTDIV1(0x00) | SIM_CLKDIV_OUTDIV2_MASK;
  _DisableWdog();

#if defined(INNER_SOURCE_CORECLOCK_48M)

  ICS->C2 = ICS_C2_BDIV(0x00) | ICS_C2_LP_MASK;
  ICS->C1 = ICS_C1_CLKS(0x00) | ICS_C1_IREFS_MASK 
                              | ICS_C1_IRCLKEN_MASK 
                              | ICS_C1_IREFSTEN_MASK;
  while((ICS->S & ICS_S_IREFST_MASK) == 0x00U){};
  while((ICS->S & ICS_S_LOCK_MASK) == 0x00U){};  
  while((ICS->S & 0x0CU) != 0x00U) {};  
        
#elif defined(EXTER_SOURCE_CORECLOCK_40M)
  //切换到FEE模式
  ICS->C2 = ICS_C2_BDIV(0x00) | ICS_C2_LP_MASK;
  OSC->CR = OSC_CR_OSCEN_MASK | OSC_CR_OSCOS_MASK 
                              | OSC_CR_RANGE_MASK 
                              | OSC_CR_HGO_MASK;
  ICS->C1 = ICS_C1_CLKS(0x00) | ICS_C1_RDIV(0x04) 
                              | ICS_C1_IRCLKEN_MASK;
  while((ICS->S & ICS_S_IREFST_MASK) != 0x00U) {};
  while((ICS->S & ICS_S_LOCK_MASK) == 0x00U){};   
  while((ICS->S & 0x0CU) != 0x00U) {}; 
        
#elif defined(OVERC_SOURCE_CORECLOCK_80M)
  //切换到FEE模式
  ICS->C2 = ICS_C2_BDIV(0x00) | ICS_C2_LP_MASK;
  OSC->CR = OSC_CR_OSCEN_MASK | OSC_CR_OSCOS_MASK 
                              | OSC_CR_RANGE_MASK 
                              | OSC_CR_HGO_MASK;
  ICS->C1 = ICS_C1_CLKS(0x00) | ICS_C1_RDIV(0x03) 
                              | ICS_C1_IRCLKEN_MASK;
  while((ICS->S & ICS_S_IREFST_MASK) != 0x00U) {};
  while((ICS->S & ICS_S_LOCK_MASK) == 0x00U){};   
  while((ICS->S & 0x0CU) != 0x00U) {}; 
    
#endif 
  //SIM->SOPT0 |= SIM_SOPT0_CLKOE_MASK;                   //H2输出总线时钟
}

/**
  * @brief  Stop Watch Dog
  * @param  None
  * @retval None
  */
void _DisableWdog(void)
{
    /* WDOG->TOVAL: TOVAL=0xE803 */
    WDOG->TOVAL = WDOG_TOVAL_TOVAL(0xE803); /* Timeout value */
    /* WDOG->CS2: WIN=0,FLG=0,??=0,PRES=0,??=0,??=0,CLK=1 */
    WDOG->CS2 = WDOG_CS2_CLK(0x01);         /* 1-kHz clock source */
    /* WDOG->CS1: EN=0,INT=0,UPDATE=1,TST=0,DBG=0,WAIT=1,STOP=1 */
    WDOG->CS1 = WDOG_CS1_UPDATE_MASK |
                WDOG_CS1_TST(0x00) |
                WDOG_CS1_WAIT_MASK |
                WDOG_CS1_STOP_MASK;
}
