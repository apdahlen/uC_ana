
/*!
 * @file LCD_Public.h
 *
 * @brief Interface to a Hitachi LCD character display using a 4-bit interface.
 *
 * @warning Be sure to physically ground the the unused LCD pins (lower nibble).
 *          You will likely have erratic operation if you fail to do this!
 * @note
 *
 * - Reference http://en.wikipedia.org/wiki/Hitachi_HD44780_LCD_controller
 *
 * - Reference the data sheet for the Hitachi HD44780U LCD driver chip
 * 
 * - This module assumes the LCD I/O will be shared with other modules.  As such
 *   it always reconfigures the I/O.  
 * 
 * - Be sure to add the following code to the ports.h file.  Adjust the I/O pin
 *   names as appropriate for your project
 *
 * @code
 *     #define LCD_E_PIN PORTXbits.RXX
 *     #define LCD_RS_PIN PORTXbits.RXX
 *
 *     #define LCD_E_DIRECTION DDRXbits.RXX
 *     #define LCD_RS_DIRECTION DDRXbits.RXX
 *
 *     #define LCD_D3_PIN PORTXbits.RXX
 *     #define LCD_D2_PIN PORTXbits.RXX
 *     #define LCD_D1_PIN PORTXbits.RXX
 *     #define LCD_D0_PIN PORTXbits.RXX
 *
 *     #define LCD_D3_DIRECTION DDRXbits.RXX
 *     #define LCD_D2_DIRECTION DDRXbits.RXX
 *     #define LCD_D1_DIRECTION DDRXbits.RXX
 *     #define LCD_D0_DIRECTION DDRXbits.RXX
 * @endcode
 *
 */

#ifndef _LCD_H
#define _LCD_H
//#include "types.h"


// Public constants

    // The following constants point to the starting positions of each LCD line.

        #define line_1                  0x80            // point to each line
        #define line_2                  0xC0
        #define line_3                  0x94
        #define line_4                  0xD4

void LCD_config(void);

void LCD_puts_RAM(char *data, uint8_t line, uint8_t offset);

void LCD_puts_ROM(const char *data, uint8_t line, uint8_t offset);

#endif
