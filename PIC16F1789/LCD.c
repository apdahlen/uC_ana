
/**@todo Clean up this section?  It is a mess!!!*/


#include <stdlib.h>                             	// required for number conversion
#include "delay.h"                         	// required for proper LCD execution delays
#include "port.h"
#include "LCD.h"

// Private function declarations

    static void LCD_w_cmd (char C);

    static void LCD_w_data(char);

    static void LCD_w_byte(char);

    static void LCD_pulse(void);

// Private variables


// Private constants

    #define reset                   0x30
    #define set_4_bit               0x20
    #define set_2_line              0x28
    #define LCD_function            0x28            // data length, # of lines, char font
    #define clr_dsp                 0x01
    #define dsp_off                 0x08
    #define enter_mode              0x06            // move left, no display shift
    #define dsp_on                  0x0C
    #define dsp_on_blk              0x0E

    #define ON 0x01
    #define OFF 0x00


/**
 * 
 * @brief Configure the PIC18 to operate the LCD display using a 4-bit parallel
 *        interface.  It also sends the commands to ready the display itself.
 *
 * @param void
 *
 * @return void
 *
 * \b Usage
 * @code
 *      MAIN{
 *          .
 *          .
 *          .
 *          LCD_config();
 *          .
 *          .
 *          .
 *          while (TRUE){
 *              temp = 10;
 *              sprintf(buf, "temp = %d      ", temp);
 *              LCD_puts_RAM(buf, line_2, 0);
 *          }
 *      }
 * @endcode
 */
 void LCD_config(void){

    LCD_E_PIN = OFF;                          // enable has its own dedicated pin
    LCD_E_DIRECTION = OUTPUT;

    delay_ms(15);

    LCD_w_cmd (0x33);                   	// Initialize the LCD for 4 line operation
    delay_ms(5);
    LCD_w_cmd (0x32);
    LCD_w_cmd (LCD_function);
    LCD_w_cmd (dsp_off);
    LCD_w_cmd (clr_dsp);
    LCD_w_cmd (enter_mode);
    LCD_w_cmd (dsp_on);
    LCD_w_cmd (line_1);

 }


/**
 * @brief Send a string stored in RAM to the LCD display.
 *
 * @param *P is a RAM pointer
 * @param line is the address of the starting positions for each LCD line
 * @param offset is the number of spaces to the right of the starting position
 *
 * @return void
 *
 * \b Usage
 * @code
 *       temp = 100;
 *       sprintf(buf, "temp = %d      ", temp);
 *       LCD_puts_RAM(buf, line_2, 0);
 * @endcode
 *
 */
 void LCD_puts_RAM(char *P, uint8_t line, uint8_t offset){
     
     //TODO add code to strip away trailing CR and LF.

     LCD_w_cmd (line + offset);         // set LCD pointer to desired position
     do{
         LCD_w_data (*P);               // send data to the LCD display
         P++;
     } while(*P != NULL);               // stop on null char
 }



/**
 * @brief Send a string stored in ROM to the LCD display.  Note that this is
 * a type of PIC table read.
 *
 * @param *P point to start of ROM
 * @param line is the address of the starting positions for each LCD line.  Use
 *        the as found in the public header e.g., "line_1" or "line_2"
 * @param offset is the number of spaces to the right of the starting position
 *
 * @return void
 *
 * \b Usage
 * @code
 *     LCD_puts_ROM("Hello World!", line_1, 0);
 * @endcode
 *
 */
 //void LCD_puts_ROM(const far rom char *P, uint_8 line, uint_8 offset){
void LCD_puts_ROM(const char *P, uint8_t line, uint8_t offset){

     LCD_w_cmd (line + offset);
    do{
        LCD_w_data (*P);
        P++;
    } while(*P != NULL);
}





/**
 * @brief Write a single command to the LCD such as "display off"
 *
 * @param C is the byte width command to be sent.
 *
 * @return void
 *
 * @warning
 * This is a bug:
 *
 * @code
 *     LCD_RS_PIN = 0;
 *     LCD_E_PIN = 0;
 * @endcode
 *
 * Do you see it?  It took me a few hours to find.  Remember that the PIC
 * performs a read/modify/write operation on its ports.  You can't have
 * consecutive changes to a port.  The first write will be undone by the second.
 * The physical of the first write does not have time to change before the second
 * write.  Consequently, the "read" portion of the second write reads the
 * original i.e., unchanged value that existed before the first command.
 * All in all in infuriating bug that was discovered only after the compiler's
 * procedural abstraction was turned off...
 *
*/
static void LCD_w_cmd (char C){     			// command to the display

    LCD_RS_DIRECTION = OUTPUT;

    LCD_RS_PIN = 0;
    LCD_RS_PIN = 0;
    LCD_RS_PIN = 0;

    LCD_E_PIN = 0;

    LCD_w_byte (C);                        	// send the data to the LCD
    delay_ms(1);                           	// allow extra delay for LCD to process command
}




/**
 *       Purpose: send a byte to the LCD display registers
 *
 *       Input: none
 *
 *       Output: none
 *
 *       Comments:
 */
static void LCD_w_data (char C){     			// char to the display

    LCD_RS_DIRECTION = OUTPUT;

    LCD_RS_PIN = 1;                         	// Set LCD control pins to data byte write
    LCD_RS_PIN = 1;
    LCD_RS_PIN = 1;
    LCD_RS_PIN = 1;

    LCD_E_PIN = 0;

    LCD_w_byte (C);                             // send the data to the LCD
}




/**
 * @brief Send a byte to the LCD using a 4-bit wide interface.
 *
 * @param C is the character to be sent to the LCD.
 *
 * @return void
 *
 * @note
 *
 * - When assigning a char to a single bit the MICROCHIP C18 compiler assigns
 *   the the character's LSB to the single bit.  This is convenient in this
 *   function as it allows the individual bits to be assigned using a series of
 *   shift left commands.
 *
 * - This function assumes other background function will use the data I/O.
 *   Consequently, it starts by configuring the data lines as outputs.
 *
 */
static void LCD_w_byte (char C){

    LCD_D0_DIRECTION = OUTPUT;
    LCD_D1_DIRECTION = OUTPUT;
    LCD_D2_DIRECTION = OUTPUT;
    LCD_D3_DIRECTION = OUTPUT;

    LCD_D0_PIN = C >> 4;                		// send the upper nibble
    LCD_D1_PIN = C >> 5;
    LCD_D2_PIN = C >> 6;
    LCD_D3_PIN = C >> 7;

    LCD_pulse();

    LCD_D0_PIN = C & 0x01;                      // send the lower nibble
    LCD_D1_PIN = C >> 1;
    LCD_D2_PIN = C >> 2;
    LCD_D3_PIN = C >> 3;

    LCD_pulse();

 //   LCD_D3_DIRECTION = INPUT;            		/**@todo WHY? */
//    delay_ISR_ticks(2);
 }



/**
 * @brief Pulse the LCD enable pin.
 *
 * @param void
 *
 * @return void
 *
 * @todo Fix the FOR loop in this routine - the time delay should be based on
 *       the system clock parameter...
 *
 */
static void LCD_pulse (void){             	// Clock the data into the display

    uint8_t i;

    LCD_E_PIN = 1;                      	// pulse the LCD E pin

    for(i = 0; i < 20; i++){            	// E is high for a minimum of 450nS
        ;
    }

    LCD_E_PIN = 0;
              	
    for(i = 0; i < 100; i++){            	// delay 40uS for LCD to process input
        ;
    }

 }