/*
    __optoencoder_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__optoencoder_driver.h"
#include "__optoencoder_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __OPTOENCODER_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t rotaryFlag;
//static uint8_t rotaryFlag;
static uint8_t O1_flag;
static uint8_t O2_flag;
static int16_t _rotation;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __OPTOENCODER_DRV_SPI__

void optoencoder_spiDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OPTOENCODER_DRV_I2C__

void optoencoder_i2cDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OPTOENCODER_DRV_UART__

void optoencoder_uartDriverInit(T_OPTOENCODER_P gpioObj, T_OPTOENCODER_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void optoencoder_gpioDriverInit(T_OPTOENCODER_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t optoencoder_getO1()
{
    return hal_gpio_pwmGet();
}

uint8_t optoencoder_getO2()
{
    return hal_gpio_intGet();
}

void optoencoder_init()
{
    O1_flag = optoencoder_getO1();
    O2_flag = optoencoder_getO2();
    
    if( O1_flag == 1 && O2_flag == 1)  // 2
    {
        rotaryFlag = 2;
    }
    else if (O1_flag == 0 && O2_flag == 1) // 1
    {
        rotaryFlag = 1;
    }
    else if (O1_flag == 1 && O2_flag == 0) // 3
    {
        rotaryFlag = 3;
    }
    else if (O1_flag == 0 && O2_flag == 0) // 0
    {
        rotaryFlag = 0;
    }
    _rotation = 0;
}

int16_t optoencoder_getPosition()
{
      int8_t steps = 0;
      
      O1_flag = optoencoder_getO1();
      O2_flag = optoencoder_getO2();
      
      if( O1_flag == 1 && O2_flag == 1)  // 2
      {
          if( rotaryFlag == 1)
              _rotation = _rotation + 90;
          else if( rotaryFlag == 3)
              _rotation = _rotation - 90;
          else
              _rotation =  _rotation;
          
          rotaryFlag = 2;
      }
      else if (O1_flag == 0 && O2_flag == 1) // 1
      {
          if( rotaryFlag == 0)
              _rotation = _rotation + 90;
          else if( rotaryFlag == 2)
              _rotation = _rotation - 90;
          else
              _rotation =  _rotation;

          rotaryFlag = 1;
      }
      else if (O1_flag == 1 && O2_flag == 0) // 3
      {
          if( rotaryFlag == 2)
              _rotation = _rotation + 90;
          else if( rotaryFlag == 0)
              _rotation = _rotation - 90;
          else
              _rotation =  _rotation;
              
          rotaryFlag = 3;
      }
      else if (O1_flag == 0 && O2_flag == 0) // 0
      {
          if( rotaryFlag == 3)
              _rotation = _rotation + 90;
          else if( rotaryFlag == 1)
              _rotation = _rotation - 90;
          else
              _rotation =  _rotation;

          rotaryFlag = 0;
      }

      if( _rotation == 0 )
          return 0;

      steps = _rotation / 360;
      return  steps;
}




/* -------------------------------------------------------------------------- */
/*
  __optoencoder_driver.c

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