/*
Example for Opto_Encoder Click

    Date          : Feb 2018.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes PWM pin and INT pin as INPUT.
- Application Initialization - Initializes Driver init and opto encoder init.
- Application Task - (code snippet) - Detects the change of step and logs to usb uart number of stepped steps.
*/

#include "Click_Opto_Encoder_types.h"
#include "Click_Opto_Encoder_config.h"

int16_t newStep;
int16_t oldStep = 0;
char text[256];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    
    mikrobus_logWrite("--- System Inti --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    optoencoder_gpioDriverInit( (T_OPTOENCODER_P)&_MIKROBUS1_GPIO );
    optoencoder_init();
}

void applicationTask()
{
     newStep = optoencoder_getPosition();
     
     if(oldStep != newStep)
     {
         IntToStr(newStep, text);
         mikrobus_logWrite(" Step: ", _LOG_TEXT);
         mikrobus_logWrite(text, _LOG_LINE);
         oldStep = newStep;
     }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}