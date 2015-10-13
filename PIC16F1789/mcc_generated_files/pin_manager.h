/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16LF1789
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS               TRISA0
#define channel_AN0_LAT                LATA0
#define channel_AN0_PORT               RA0
#define channel_AN0_WPU                WPUA0
#define channel_AN0_ANS                ANSA0
#define channel_AN0_SetHigh()    do { LATA0 = 1; } while(0)
#define channel_AN0_SetLow()   do { LATA0 = 0; } while(0)
#define channel_AN0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define channel_AN0_GetValue()         RA0
#define channel_AN0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define channel_AN0_SetPullup()    do { WPUA0 = 1; } while(0)
#define channel_AN0_ResetPullup()   do { WPUA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set channel_AN1 aliases
#define channel_AN1_TRIS               TRISA1
#define channel_AN1_LAT                LATA1
#define channel_AN1_PORT               RA1
#define channel_AN1_WPU                WPUA1
#define channel_AN1_ANS                ANSA1
#define channel_AN1_SetHigh()    do { LATA1 = 1; } while(0)
#define channel_AN1_SetLow()   do { LATA1 = 0; } while(0)
#define channel_AN1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define channel_AN1_GetValue()         RA1
#define channel_AN1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define channel_AN1_SetPullup()    do { WPUA1 = 1; } while(0)
#define channel_AN1_ResetPullup()   do { WPUA1 = 0; } while(0)
#define channel_AN1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define channel_AN1_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set channel_AN2 aliases
#define channel_AN2_TRIS               TRISA2
#define channel_AN2_LAT                LATA2
#define channel_AN2_PORT               RA2
#define channel_AN2_WPU                WPUA2
#define channel_AN2_ANS                ANSA2
#define channel_AN2_SetHigh()    do { LATA2 = 1; } while(0)
#define channel_AN2_SetLow()   do { LATA2 = 0; } while(0)
#define channel_AN2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define channel_AN2_GetValue()         RA2
#define channel_AN2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define channel_AN2_SetPullup()    do { WPUA2 = 1; } while(0)
#define channel_AN2_ResetPullup()   do { WPUA2 = 0; } while(0)
#define channel_AN2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define channel_AN2_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set channel_AN3 aliases
#define channel_AN3_TRIS               TRISA3
#define channel_AN3_LAT                LATA3
#define channel_AN3_PORT               RA3
#define channel_AN3_WPU                WPUA3
#define channel_AN3_ANS                ANSA3
#define channel_AN3_SetHigh()    do { LATA3 = 1; } while(0)
#define channel_AN3_SetLow()   do { LATA3 = 0; } while(0)
#define channel_AN3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define channel_AN3_GetValue()         RA3
#define channel_AN3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define channel_AN3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define channel_AN3_SetPullup()    do { WPUA3 = 1; } while(0)
#define channel_AN3_ResetPullup()   do { WPUA3 = 0; } while(0)
#define channel_AN3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define channel_AN3_SetDigitalMode()   do { ANSA3 = 0; } while(0)
// get/set IO_RA6 aliases
#define IO_RA6_TRIS               TRISA6
#define IO_RA6_LAT                LATA6
#define IO_RA6_PORT               RA6
#define IO_RA6_WPU                WPUA6
#define IO_RA6_SetHigh()    do { LATA6 = 1; } while(0)
#define IO_RA6_SetLow()   do { LATA6 = 0; } while(0)
#define IO_RA6_Toggle()   do { LATA6 = ~LATA6; } while(0)
#define IO_RA6_GetValue()         RA6
#define IO_RA6_SetDigitalInput()    do { TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISA6 = 0; } while(0)

#define IO_RA6_SetPullup()    do { WPUA6 = 1; } while(0)
#define IO_RA6_ResetPullup()   do { WPUA6 = 0; } while(0)
// get/set IO_RA7 aliases
#define IO_RA7_TRIS               TRISA7
#define IO_RA7_LAT                LATA7
#define IO_RA7_PORT               RA7
#define IO_RA7_WPU                WPUA7
#define IO_RA7_ANS                ANSA7
#define IO_RA7_SetHigh()    do { LATA7 = 1; } while(0)
#define IO_RA7_SetLow()   do { LATA7 = 0; } while(0)
#define IO_RA7_Toggle()   do { LATA7 = ~LATA7; } while(0)
#define IO_RA7_GetValue()         RA7
#define IO_RA7_SetDigitalInput()    do { TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISA7 = 0; } while(0)

#define IO_RA7_SetPullup()    do { WPUA7 = 1; } while(0)
#define IO_RA7_ResetPullup()   do { WPUA7 = 0; } while(0)
#define IO_RA7_SetAnalogMode()   do { ANSA7 = 1; } while(0)
#define IO_RA7_SetDigitalMode()   do { ANSA7 = 0; } while(0)
// get/set IO_RB0 aliases
#define IO_RB0_TRIS               TRISB0
#define IO_RB0_LAT                LATB0
#define IO_RB0_PORT               RB0
#define IO_RB0_WPU                WPUB0
#define IO_RB0_ANS                ANSB0
#define IO_RB0_SetHigh()    do { LATB0 = 1; } while(0)
#define IO_RB0_SetLow()   do { LATB0 = 0; } while(0)
#define IO_RB0_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define IO_RB0_GetValue()         RB0
#define IO_RB0_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define IO_RB0_SetPullup()    do { WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()   do { WPUB0 = 0; } while(0)
#define IO_RB0_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()   do { ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define IO_RB1_TRIS               TRISB1
#define IO_RB1_LAT                LATB1
#define IO_RB1_PORT               RB1
#define IO_RB1_WPU                WPUB1
#define IO_RB1_ANS                ANSB1
#define IO_RB1_SetHigh()    do { LATB1 = 1; } while(0)
#define IO_RB1_SetLow()   do { LATB1 = 0; } while(0)
#define IO_RB1_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define IO_RB1_GetValue()         RB1
#define IO_RB1_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define IO_RB1_SetPullup()    do { WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()   do { WPUB1 = 0; } while(0)
#define IO_RB1_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()   do { ANSB1 = 0; } while(0)
// get/set IO_RB2 aliases
#define IO_RB2_TRIS               TRISB2
#define IO_RB2_LAT                LATB2
#define IO_RB2_PORT               RB2
#define IO_RB2_WPU                WPUB2
#define IO_RB2_ANS                ANSB2
#define IO_RB2_SetHigh()    do { LATB2 = 1; } while(0)
#define IO_RB2_SetLow()   do { LATB2 = 0; } while(0)
#define IO_RB2_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define IO_RB2_GetValue()         RB2
#define IO_RB2_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define IO_RB2_SetPullup()    do { WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()   do { WPUB2 = 0; } while(0)
#define IO_RB2_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()   do { ANSB2 = 0; } while(0)
// get/set IO_RB3 aliases
#define IO_RB3_TRIS               TRISB3
#define IO_RB3_LAT                LATB3
#define IO_RB3_PORT               RB3
#define IO_RB3_WPU                WPUB3
#define IO_RB3_ANS                ANSB3
#define IO_RB3_SetHigh()    do { LATB3 = 1; } while(0)
#define IO_RB3_SetLow()   do { LATB3 = 0; } while(0)
#define IO_RB3_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define IO_RB3_GetValue()         RB3
#define IO_RB3_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define IO_RB3_SetPullup()    do { WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()   do { WPUB3 = 0; } while(0)
#define IO_RB3_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()   do { ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISB5
#define IO_RB5_LAT                LATB5
#define IO_RB5_PORT               RB5
#define IO_RB5_WPU                WPUB5
#define IO_RB5_ANS                ANSB5
#define IO_RB5_SetHigh()    do { LATB5 = 1; } while(0)
#define IO_RB5_SetLow()   do { LATB5 = 0; } while(0)
#define IO_RB5_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IO_RB5_GetValue()         RB5
#define IO_RB5_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IO_RB5_SetPullup()    do { WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()   do { ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISB6
#define IO_RB6_LAT                LATB6
#define IO_RB6_PORT               RB6
#define IO_RB6_WPU                WPUB6
#define IO_RB6_ANS                ANSB6
#define IO_RB6_SetHigh()    do { LATB6 = 1; } while(0)
#define IO_RB6_SetLow()   do { LATB6 = 0; } while(0)
#define IO_RB6_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define IO_RB6_GetValue()         RB6
#define IO_RB6_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define IO_RB6_SetPullup()    do { WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()   do { WPUB6 = 0; } while(0)
#define IO_RB6_SetAnalogMode()   do { ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()   do { ANSB6 = 0; } while(0)
// get/set RB7 aliases
#define RB7_TRIS               TRISB7
#define RB7_LAT                LATB7
#define RB7_PORT               RB7
#define RB7_WPU                WPUB7
#define RB7_SetHigh()    do { LATB7 = 1; } while(0)
#define RB7_SetLow()   do { LATB7 = 0; } while(0)
#define RB7_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define RB7_GetValue()         RB7
#define RB7_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define RB7_SetPullup()    do { WPUB7 = 1; } while(0)
#define RB7_ResetPullup()   do { WPUB7 = 0; } while(0)
// get/set CCP2 aliases
#define CCP2_TRIS               TRISC1
#define CCP2_LAT                LATC1
#define CCP2_PORT               RC1
#define CCP2_WPU                WPUC1
#define CCP2_ANS                ANSC1
#define CCP2_SetHigh()    do { LATC1 = 1; } while(0)
#define CCP2_SetLow()   do { LATC1 = 0; } while(0)
#define CCP2_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define CCP2_GetValue()         RC1
#define CCP2_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define CCP2_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define CCP2_SetPullup()    do { WPUC1 = 1; } while(0)
#define CCP2_ResetPullup()   do { WPUC1 = 0; } while(0)
#define CCP2_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define CCP2_SetDigitalMode()   do { ANSC1 = 0; } while(0)
// get/set CCP1 aliases
#define CCP1_TRIS               TRISC2
#define CCP1_LAT                LATC2
#define CCP1_PORT               RC2
#define CCP1_WPU                WPUC2
#define CCP1_ANS                ANSC2
#define CCP1_SetHigh()    do { LATC2 = 1; } while(0)
#define CCP1_SetLow()   do { LATC2 = 0; } while(0)
#define CCP1_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define CCP1_GetValue()         RC2
#define CCP1_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define CCP1_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define CCP1_SetPullup()    do { WPUC2 = 1; } while(0)
#define CCP1_ResetPullup()   do { WPUC2 = 0; } while(0)
#define CCP1_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define CCP1_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set SCK aliases
#define SCK_TRIS               TRISC3
#define SCK_LAT                LATC3
#define SCK_PORT               RC3
#define SCK_WPU                WPUC3
#define SCK_ANS                ANSC3
#define SCK_SetHigh()    do { LATC3 = 1; } while(0)
#define SCK_SetLow()   do { LATC3 = 0; } while(0)
#define SCK_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCK_GetValue()         RC3
#define SCK_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define SCK_SetPullup()    do { WPUC3 = 1; } while(0)
#define SCK_ResetPullup()   do { WPUC3 = 0; } while(0)
#define SCK_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define SCK_SetDigitalMode()   do { ANSC3 = 0; } while(0)
// get/set SDI aliases
#define SDI_TRIS               TRISC4
#define SDI_LAT                LATC4
#define SDI_PORT               RC4
#define SDI_WPU                WPUC4
#define SDI_ANS                ANSC4
#define SDI_SetHigh()    do { LATC4 = 1; } while(0)
#define SDI_SetLow()   do { LATC4 = 0; } while(0)
#define SDI_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDI_GetValue()         RC4
#define SDI_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define SDI_SetPullup()    do { WPUC4 = 1; } while(0)
#define SDI_ResetPullup()   do { WPUC4 = 0; } while(0)
#define SDI_SetAnalogMode()   do { ANSC4 = 1; } while(0)
#define SDI_SetDigitalMode()   do { ANSC4 = 0; } while(0)
// get/set SDO aliases
#define SDO_TRIS               TRISC5
#define SDO_LAT                LATC5
#define SDO_PORT               RC5
#define SDO_WPU                WPUC5
#define SDO_ANS                ANSC5
#define SDO_SetHigh()    do { LATC5 = 1; } while(0)
#define SDO_SetLow()   do { LATC5 = 0; } while(0)
#define SDO_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define SDO_GetValue()         RC5
#define SDO_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define SDO_SetPullup()    do { WPUC5 = 1; } while(0)
#define SDO_ResetPullup()   do { WPUC5 = 0; } while(0)
#define SDO_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define SDO_SetDigitalMode()   do { ANSC5 = 0; } while(0)
// get/set TX aliases
#define TX_TRIS               TRISC6
#define TX_LAT                LATC6
#define TX_PORT               RC6
#define TX_WPU                WPUC6
#define TX_ANS                ANSC6
#define TX_SetHigh()    do { LATC6 = 1; } while(0)
#define TX_SetLow()   do { LATC6 = 0; } while(0)
#define TX_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define TX_GetValue()         RC6
#define TX_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define TX_SetPullup()    do { WPUC6 = 1; } while(0)
#define TX_ResetPullup()   do { WPUC6 = 0; } while(0)
#define TX_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define TX_SetDigitalMode()   do { ANSC6 = 0; } while(0)
// get/set RX aliases
#define RX_TRIS               TRISC7
#define RX_LAT                LATC7
#define RX_PORT               RC7
#define RX_WPU                WPUC7
#define RX_ANS                ANSC7
#define RX_SetHigh()    do { LATC7 = 1; } while(0)
#define RX_SetLow()   do { LATC7 = 0; } while(0)
#define RX_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define RX_GetValue()         RC7
#define RX_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define RX_SetPullup()    do { WPUC7 = 1; } while(0)
#define RX_ResetPullup()   do { WPUC7 = 0; } while(0)
#define RX_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define RX_SetDigitalMode()   do { ANSC7 = 0; } while(0)
// get/set RD0 aliases
#define RD0_TRIS               TRISD0
#define RD0_LAT                LATD0
#define RD0_PORT               RD0
#define RD0_WPU                WPUD0
#define RD0_ANS                ANSD0
#define RD0_SetHigh()    do { LATD0 = 1; } while(0)
#define RD0_SetLow()   do { LATD0 = 0; } while(0)
#define RD0_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define RD0_GetValue()         RD0
#define RD0_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

#define RD0_SetPullup()    do { WPUD0 = 1; } while(0)
#define RD0_ResetPullup()   do { WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()   do { ANSD0 = 1; } while(0)
#define RD0_SetDigitalMode()   do { ANSD0 = 0; } while(0)
// get/set RD1 aliases
#define RD1_TRIS               TRISD1
#define RD1_LAT                LATD1
#define RD1_PORT               RD1
#define RD1_WPU                WPUD1
#define RD1_ANS                ANSD1
#define RD1_SetHigh()    do { LATD1 = 1; } while(0)
#define RD1_SetLow()   do { LATD1 = 0; } while(0)
#define RD1_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define RD1_GetValue()         RD1
#define RD1_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

#define RD1_SetPullup()    do { WPUD1 = 1; } while(0)
#define RD1_ResetPullup()   do { WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()   do { ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()   do { ANSD1 = 0; } while(0)
// get/set RD2 aliases
#define RD2_TRIS               TRISD2
#define RD2_LAT                LATD2
#define RD2_PORT               RD2
#define RD2_WPU                WPUD2
#define RD2_ANS                ANSD2
#define RD2_SetHigh()    do { LATD2 = 1; } while(0)
#define RD2_SetLow()   do { LATD2 = 0; } while(0)
#define RD2_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define RD2_GetValue()         RD2
#define RD2_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define RD2_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define RD2_SetPullup()    do { WPUD2 = 1; } while(0)
#define RD2_ResetPullup()   do { WPUD2 = 0; } while(0)
#define RD2_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define RD2_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set RD3 aliases
#define RD3_TRIS               TRISD3
#define RD3_LAT                LATD3
#define RD3_PORT               RD3
#define RD3_WPU                WPUD3
#define RD3_SetHigh()    do { LATD3 = 1; } while(0)
#define RD3_SetLow()   do { LATD3 = 0; } while(0)
#define RD3_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define RD3_GetValue()         RD3
#define RD3_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define RD3_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define RD3_SetPullup()    do { WPUD3 = 1; } while(0)
#define RD3_ResetPullup()   do { WPUD3 = 0; } while(0)
// get/set IO_RD4 aliases
#define IO_RD4_TRIS               TRISD4
#define IO_RD4_LAT                LATD4
#define IO_RD4_PORT               RD4
#define IO_RD4_WPU                WPUD4
#define IO_RD4_SetHigh()    do { LATD4 = 1; } while(0)
#define IO_RD4_SetLow()   do { LATD4 = 0; } while(0)
#define IO_RD4_Toggle()   do { LATD4 = ~LATD4; } while(0)
#define IO_RD4_GetValue()         RD4
#define IO_RD4_SetDigitalInput()    do { TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISD4 = 0; } while(0)

#define IO_RD4_SetPullup()    do { WPUD4 = 1; } while(0)
#define IO_RD4_ResetPullup()   do { WPUD4 = 0; } while(0)
// get/set IO_RD5 aliases
#define IO_RD5_TRIS               TRISD5
#define IO_RD5_LAT                LATD5
#define IO_RD5_PORT               RD5
#define IO_RD5_WPU                WPUD5
#define IO_RD5_SetHigh()    do { LATD5 = 1; } while(0)
#define IO_RD5_SetLow()   do { LATD5 = 0; } while(0)
#define IO_RD5_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define IO_RD5_GetValue()         RD5
#define IO_RD5_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define IO_RD5_SetPullup()    do { WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()   do { WPUD5 = 0; } while(0)
// get/set IO_RD6 aliases
#define IO_RD6_TRIS               TRISD6
#define IO_RD6_LAT                LATD6
#define IO_RD6_PORT               RD6
#define IO_RD6_WPU                WPUD6
#define IO_RD6_SetHigh()    do { LATD6 = 1; } while(0)
#define IO_RD6_SetLow()   do { LATD6 = 0; } while(0)
#define IO_RD6_Toggle()   do { LATD6 = ~LATD6; } while(0)
#define IO_RD6_GetValue()         RD6
#define IO_RD6_SetDigitalInput()    do { TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISD6 = 0; } while(0)

#define IO_RD6_SetPullup()    do { WPUD6 = 1; } while(0)
#define IO_RD6_ResetPullup()   do { WPUD6 = 0; } while(0)
// get/set IO_RD7 aliases
#define IO_RD7_TRIS               TRISD7
#define IO_RD7_LAT                LATD7
#define IO_RD7_PORT               RD7
#define IO_RD7_WPU                WPUD7
#define IO_RD7_SetHigh()    do { LATD7 = 1; } while(0)
#define IO_RD7_SetLow()   do { LATD7 = 0; } while(0)
#define IO_RD7_Toggle()   do { LATD7 = ~LATD7; } while(0)
#define IO_RD7_GetValue()         RD7
#define IO_RD7_SetDigitalInput()    do { TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISD7 = 0; } while(0)

#define IO_RD7_SetPullup()    do { WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()   do { WPUD7 = 0; } while(0)
// get/set CCP3 aliases
#define CCP3_TRIS               TRISE0
#define CCP3_LAT                LATE0
#define CCP3_PORT               RE0
#define CCP3_WPU                WPUE0
#define CCP3_ANS                ANSE0
#define CCP3_SetHigh()    do { LATE0 = 1; } while(0)
#define CCP3_SetLow()   do { LATE0 = 0; } while(0)
#define CCP3_Toggle()   do { LATE0 = ~LATE0; } while(0)
#define CCP3_GetValue()         RE0
#define CCP3_SetDigitalInput()    do { TRISE0 = 1; } while(0)
#define CCP3_SetDigitalOutput()   do { TRISE0 = 0; } while(0)

#define CCP3_SetPullup()    do { WPUE0 = 1; } while(0)
#define CCP3_ResetPullup()   do { WPUE0 = 0; } while(0)
#define CCP3_SetAnalogMode()   do { ANSE0 = 1; } while(0)
#define CCP3_SetDigitalMode()   do { ANSE0 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */