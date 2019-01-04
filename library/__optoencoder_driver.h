/*
    __optoencoder_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __optoencoder_driver.h
@brief    Opto_Encoder Driver
@mainpage Opto_Encoder Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   OPTOENCODER
@brief      Opto_Encoder Click Driver
@{

| Global Library Prefix | **OPTOENCODER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _OPTOENCODER_H_
#define _OPTOENCODER_H_

/** 
 * @macro T_OPTOENCODER_P
 * @brief Driver Abstract type 
 */
#define T_OPTOENCODER_P    const uint8_t*

/** @defgroup OPTOENCODER_COMPILE Compilation Config */              /** @{ */

//  #define   __OPTOENCODER_DRV_SPI__                            /**<     @macro __OPTOENCODER_DRV_SPI__  @brief SPI driver selector */
//  #define   __OPTOENCODER_DRV_I2C__                            /**<     @macro __OPTOENCODER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __OPTOENCODER_DRV_UART__                           /**<     @macro __OPTOENCODER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup OPTOENCODER_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup OPTOENCODER_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OPTOENCODER_INIT Driver Initialization */              /** @{ */

#ifdef   __OPTOENCODER_DRV_SPI__
void optoencoder_spiDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P spiObj);
#endif
#ifdef   __OPTOENCODER_DRV_I2C__
void optoencoder_i2cDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P i2cObj, uint8_t slave);
#endif
#ifdef   __OPTOENCODER_DRV_UART__
void optoencoder_uartDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void optoencoder_gpioDriverInit(T_OPTOENCODER_P gpioObj);
                                                                       /** @} */
/** @defgroup OPTOENCODER_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Initialization functions
 */
void optoencoder_init();

/**
 * @brief Functions for reading O1 state
 *
 * @return O1 pin state
 */
uint8_t optoencoder_getO1();

/**
 * @brief Functions for reading O2 state
 *
 * @return O2 pin state
 */
uint8_t optoencoder_getO2();

/**
 * @brief Functions for reading the position of the encoder
 *
 * @return position of the encoder
 */
int16_t optoencoder_getPosition();







                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Opto_Encoder_STM.c
    @example Click_Opto_Encoder_TIVA.c
    @example Click_Opto_Encoder_CEC.c
    @example Click_Opto_Encoder_KINETIS.c
    @example Click_Opto_Encoder_MSP.c
    @example Click_Opto_Encoder_PIC.c
    @example Click_Opto_Encoder_PIC32.c
    @example Click_Opto_Encoder_DSPIC.c
    @example Click_Opto_Encoder_AVR.c
    @example Click_Opto_Encoder_FT90x.c
    @example Click_Opto_Encoder_STM.mbas
    @example Click_Opto_Encoder_TIVA.mbas
    @example Click_Opto_Encoder_CEC.mbas
    @example Click_Opto_Encoder_KINETIS.mbas
    @example Click_Opto_Encoder_MSP.mbas
    @example Click_Opto_Encoder_PIC.mbas
    @example Click_Opto_Encoder_PIC32.mbas
    @example Click_Opto_Encoder_DSPIC.mbas
    @example Click_Opto_Encoder_AVR.mbas
    @example Click_Opto_Encoder_FT90x.mbas
    @example Click_Opto_Encoder_STM.mpas
    @example Click_Opto_Encoder_TIVA.mpas
    @example Click_Opto_Encoder_CEC.mpas
    @example Click_Opto_Encoder_KINETIS.mpas
    @example Click_Opto_Encoder_MSP.mpas
    @example Click_Opto_Encoder_PIC.mpas
    @example Click_Opto_Encoder_PIC32.mpas
    @example Click_Opto_Encoder_DSPIC.mpas
    @example Click_Opto_Encoder_AVR.mpas
    @example Click_Opto_Encoder_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __optoencoder_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */