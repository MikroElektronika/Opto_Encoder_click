![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Opto_Encoder Click

- **CIC Prefix**  : OPTOENCODER
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Feb 2018.

---

### Software Support

We provide a library for the Opto Encoder Click on our [LibStock](https://libstock.mikroe.com/projects/view/2350/opto-encoder-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Description :

This library contains basinc functions that will alow you to read the sensor.

Key functions :

- ```void optoencoder_init();``` - Initialization for the click board.
- ```uint8_t optoencoder_getO1();``` - Read the state of encoder channel 1.
- ```uint8_t optoencoder_getO2();``` - Read the state of the encoder channel 2.
- ```int16_t optoencoder_getPosition();``` - Return's the current position.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes PWM pin and INT pin as INPUT.
- Application Initialization - Initializes Driver init and opto encoder init.
- Application Task - (code snippet) - Detects the change of step and logs to usb uart number of stepped steps.


```
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2350/opto-encoder-click) page.

Other mikroE Libraries used in the example:

- UART Library
- Conversions Library
- C_String Library

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
