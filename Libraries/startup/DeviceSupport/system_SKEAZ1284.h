/**
  ******************************************************************************
  * @file    Project/Debug_SmartCar/system_SKEAZ1284.h 
  * @author  Debug406 Team
  * @date    13-May-2018
  * @brief   Header for KEA128_pit.c module
  ******************************************************************************
  * @attention
  
  *
  ******************************************************************************
  *=============================================================================
  *=============================================================================
  *                       Supported SKEAZ128 devices
  *-----------------------------------------------------------------------------
  *        System Clock source                    | PLL (HSE)
  *-----------------------------------------------------------------------------
  *        OSCCLK(Hz)                             | 16000000      (16MHZ)
  *-----------------------------------------------------------------------------
  *        OSCERCLK(Hz)     = OSCCLK              | 16000000      (16MHZ)
  *-----------------------------------------------------------------------------
  *        ICSIRCLK(Hz)                           | 32000         (32KHz)
  *-----------------------------------------------------------------------------
  *        ICSFFCLK(Hz)                           | Inn - 37.5KHz, Ext - 16MHz
  *-----------------------------------------------------------------------------
  *        ICSFLLCLK(Hz)    = 1280 * Inn/Ext      | Inn - 48MHz,   Ext0 - 40MHz 
  *-----------------------------------------------------------------------------
  *        ICSOUTCLK(Hz)    = FLL / BDIV          | Inn - 48MHz,   Ext0 - 40MHz
  *-----------------------------------------------------------------------------
  *        Core clock       = ICSOUTCLK / DIV1    | ICSOUTCLK(Hz)
  *-----------------------------------------------------------------------------
  *        Platform clock   = ICSOUTCLK / DIV1    | ICSOUTCLK(Hz)
  *-----------------------------------------------------------------------------
  *        System clock     = ICSOUTCLK / DIV1    | ICSOUTCLK(Hz)
  *-----------------------------------------------------------------------------
  *        Bus clock        = System clock / DIV2 | ICSOUTCLK(Hz)/2
  *-----------------------------------------------------------------------------
  *        Flash clock      = System clock / DIV2 | ICSOUTCLK(Hz)/2
  *-----------------------------------------------------------------------------
  *        Timer clock      = ICSOUTCLK / DIV3    | ICSOUTCLK(Hz)
  *-----------------------------------------------------------------------------
  *        LPOCLK(Hz)                             | 1000          (1KHz)
  *-----------------------------------------------------------------------------

 ********************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SYSTEM_SKEAZ1284_H_
#define SYSTEM_SKEAZ1284_H_                      

#ifdef __cplusplus
extern "C" {
#endif //!__cplusplus

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>  
#include "SKEAZ1284.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Clock Source */
#define INNER_SOURCE_CORECLOCK_48M
//#define EXTER_SOURCE_CORECLOCK_40M
//#define OVERC_SOURCE_CORECLOCK_80M
  
#define EX_REF_CLK  16000  
#if defined(INNER_SOURCE_CORECLOCK_48M)
  const static uint32_t CLK_SOUT = 48000000;
  const static uint32_t CLK_FTM  = 48000000;
  const static uint32_t CLK_CORE = 48000000;
  const static uint32_t CLK_BUS  = 24000000; //The only constant be used.
#elif defined(EXTER_SOURCE_CORECLOCK_40M)
  const static uint32_t CLK_SOUT = 40000000;
  const static uint32_t CLK_FTM  = 40000000;
  const static uint32_t CLK_CORE = 40000000;
  const static uint32_t CLK_BUS  = 20000000;
#elif defined(OVERC_SOURCE_CORECLOCK_80M)
  const static uint32_t CLK_SOUT = 80000000;
  const static uint32_t CLK_FTM  = 80000000;
  const static uint32_t CLK_CORE = 80000000;
  const static uint32_t CLK_BUS  = 20000000;
#endif 

/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif //!__cplusplus
#endif //!SYSTEM_SKEAZ1284_H_
