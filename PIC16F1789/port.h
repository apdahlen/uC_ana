/**
 * @file port.h
 *
 * @brief This file is designed to increase code portability by gathering
 * all I/O items into one location.  Note that hardware specific pins such as
 * the USART's TX and RX pins are not explicitly addresses.
 *
 * This is the only place in the project where I/O pins are identified.
 * Elsewhere they should be aliased as FOO_PIN and FOO_TRIS.  This
 * action makes it easy to change PIC family member or even between
 * microprocessor architectures.
 *
 * Recall that MICROCHIP calls the data direction registers TRIS which stands
 * for "TRIState" since the port can have three states: Output high, output low,
 * high impedance input.
 *
 * To use an I/O pin be sure to identify both the port / pin as well as the
 * TRIS.  Change all of the "X" characters in the code below: 
 * @code
 *     #define LED_PIN PORTXbits.RXX
 *     #define LED_DIRECTION DDRXbits.RXX
 * @endcode
 *
 *
 * Example usage:
 * @code
 *     LED_DIRECTION = output;
 *
 *     LED_PIN = 1;
 * @endcode
 *
 */


#ifndef PORT_H
#define PORT_H

 /*! Shortcut for the Data Direction aka TRIS register because it hurts my brain every time I have to think about it!" */
    #define INPUT 1
/*! Shortcut for the TRIS register..." */
    #define OUTPUT 0


// I'm alive blinking LED

    #define LED_PIN PORTBbits.RB2
    #define LED_DIRECTION TRISbits.TRISB2

// LM18200 H-bridge driver

    #define LMD18200_BRAKE_PIN PORTBbits.RB4
    #define LMD18200_MOTOR_DIRECTION_PIN PORTCbits.RC6

    #define LMD18200_BRAKE_DIRECTION TRISBbits.TRISB4
    #define LMD18200_MOTOR_DIRECTION_DIRECTION TRISCbits.TRISC6

    #define USART_RX_PIN PORTAbits.RB7
 //   #define USART_RX_DIRECTION DDRAbits.RB7

    #define USART_TX_PIN PORTAbits.RB7
 //   #define USART_TX_DIRECTION DDRAbits.RB7


// LCD with nibble wide interface

    #define LCD_E_PIN PORTBbits.RB0
    #define LCD_RS_PIN PORTBbits.RB1

    #define LCD_E_DIRECTION TRISBbits.TRISB0
    #define LCD_RS_DIRECTION TRISBbits.TRISB1

    #define LCD_D3_PIN PORTDbits.RD3
    #define LCD_D2_PIN PORTDbits.RD2
    #define LCD_D1_PIN PORTDbits.RD1
    #define LCD_D0_PIN PORTDbits.RD0

    #define LCD_D3_DIRECTION TRISDbits.TRISD3
    #define LCD_D2_DIRECTION TRISDbits.TRISD2
    #define LCD_D1_DIRECTION TRISDbits.TRISD1
    #define LCD_D0_DIRECTION TRISDbits.TRISD0


// Rotary encoder

    #define ROT_ENC_A_PIN PORTCbits.RC2
    #define ROT_ENC_B_PIN PORTCbits.RC2

    #define ROT_ENC_A_TRIS TRISCbits.TRISC2
    #define ROT_ENC_B_TRIS TRISCbits.TRISC2

#endif