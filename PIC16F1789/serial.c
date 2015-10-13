
#include "serial.h"
#include "mcc_generated_files/eusart.h"                     // The EUSART Generated Driver File
#include <stdint.h>

// Set the size of the circular buffer

    #define circ_buf_len 128                                        // must be a power of 2 (PO2)
    #define modulo_mask 0b01111111                                  // must be the binary representation of circ_buf_len - 1

// Private variables

    static volatile uint8_t circ_buf[circ_buf_len];
    static volatile uint8_t circ_buf_head = 0;
    static volatile uint8_t circ_buf_tail = 0;
    static volatile char line_terminator = 0x0A;                    // default is ASCII Line Feed

  
 /** service_serial
  *
  * @brief When called from the ISR this function transfers characters from a small serial buffer
  * to a larger buffer. Code in main() then retrieves data from this buffer.  Observe that this 
  * mechanism allows data to be received at a high rate of speed independent of the main loop.
  * 
  * @CAUTION If this routine is not called fast enough characters will be lost.
 */
 void service_serial(void){
        
    if (EUSART_DataReady){                                          // MICROCHIP driver specific
        if (RCREG != CR){
            circ_buf[circ_buf_head] = EUSART_Read();                // MICROCHIP driver specific
            circ_buf_head++;
            circ_buf_head &= modulo_mask;
        }
    }
}


/** USART_set_terminator
 *
 * @brief Allows the user to set the string line terminator.  This function is optional.
 * The user may elect to use the default ASCII line feed terminator (0x0A)
 *
 * @param terminator set the desired line terminator.
 */
void USART_set_terminator(char terminator){
    line_terminator = terminator;
}


 

/**
  * @brief Transfer a string from the circular buffer to the identified buffer.
  *
  * \b Pseudocode:
  *
  * - Verify that there is data in the buffer.
  *
  * - Transfer each char from the circular buffer to the specified buffer.
  *
  * - Finish with the null char
  *
  * @param *P pointer to a character buffer.
  *
  * @return number of characters
  *
  * @note
  *
  * - Normally called from main().
  *
  * - Returns null if buffer is empty this shouldn't happen if serial_is_string
  *   is used to first check that there is data in the buffer.
  *
  * - Assumes MAIN's buffer is able to hold contents of circular buffer.
  *
  * @see service_USART_RCVR and is_str_in_circ_buf
  *
  */
  uint8_t serial_gets (char *P){

    uint8_t num_char = 0;

    while (circ_buf_tail != circ_buf_head){
        if (circ_buf[circ_buf_tail++] == line_terminator){
      //      circ_buf_tail++;
            circ_buf_tail &= modulo_mask;
            break;
        }
        *P++ = circ_buf[circ_buf_tail++];
        num_char++;
    //    P++;
    //    circ_buf_tail++;
        circ_buf_tail &= modulo_mask;
    }
    *P = 0x00;                                                      // null terminate
    return num_char;
}


/**
  * @brief Determine if a string is present in the circular buffer.  A string
  * is defined as zero or more characters ending in line_terminator.
  *
  * \b Pseudocode:
  *
  * - First see if there is anything in the buffer.  Does head = tail?  If not
  *     then continue
  *
  * - If there is data in buffer than test every byte starting at tail.  Stop
  *   looking when line_terminator is found or when head is reached.
  *
  * @param void
  *
  * @return boolean
  *
  * @notes
  *
  * - This is a non-blocking routine that is normally called from MAIN.
  *
  * - This routine makes use of global variables.
  *
  * @see service_USART_RCVR
  *
  * @todo This code could be optimized.  Instead of running through every char
  *       in buffer we could remember that we have already looked at a char...
  *
  */
uint8_t serial_is_string(void){

    uint8_t result = 0x00;                                          // default answer
    uint8_t i = circ_buf_tail;                                      // start looking at end

    if (circ_buf_tail != circ_buf_head){

        /* The next line of code requires a bit of explanation.  Recall that the next char
         * into the circular buffer is inserted at the location pointed to by HEAD.  As we
         * "peek" into the circular buffer we start at TAIL and work our way to HEAD.
         * However, we don't want to look at HEAD itself.  We want one less than HEAD.
         * An easy way to perform this calculation is to take advantage of modulo math.
         * Add one less than the size of the buffer and mask of the "overflow bit."
         */

        while (i != ((circ_buf_head + (circ_buf_len - 1)) & modulo_mask )){
            i++;
            i &= modulo_mask;
            if (circ_buf[i] == line_terminator){
                result = 0x01;
                break;
            }
        }
    }
    return result;
}


 
 
 /**
 * @brief Write a string to the USART.
 *
 * @param *P Pointer to a buffer holding a null terminates string.
 *
 * @return void
 *
 * @note
 *
 * - This is a blocking routine that is normally called from main().
 *
 * - Recall that the PIC18 is a modified Harvard device.  Data transfers to ROM
 *   are different than transfers to RAM.  Consequently there are two separate
 *   files.  One for RAM and on for RAM.
 *
 * - This allows a single line of text such as:
 *   @code
 *       USART_puts_ROM("Hello World\n");
 *   @endcode
 *
 *   As oposed to:
 *
 *   @code
 *      sprintf(buf, "Hello World on two lines...\n");
 *      USART_puts_RAM(buf);
 *   @endcode
 * 
 * @see put_s
 */
 
 void serial_puts_RAM(char *P){

    do {
        EUSART_Write(*P++);                                 // MICROCHIP driver note: is blocking
    }
    while(*P != 0x00);
}

 void serial_puts_ROM(const char *P){

    do {
        EUSART_Write(*P++);                                 // MICROCHIP driver note: is blocking
    }
    while(*P != 0x00);
}







/************************ DELETE me after testing *****************
 * 
 * 
 * 
 *    /**
    * @brief Retrieve data from the PIC18 USART and place it into a circular buffer.
    *
    * \b Pseudo-code: 
    * 
    * - On every iteration checks the USART interrupt flag to determine if a byte
    *   is in the USART buffer.
    * 
    * - If a byte is found it is placed it in the circular buffer to be read by MAIN.
    * 
    * - Ignore the carriage return character
    *
    * @param void
    *
    * @return void
    *
    * @warning
    *
    * - Be sure to configure the I/O port in the config_SFR section.  For example:
    *
    *   @code
    *       TRISBbits.RB5 = 1;              // part of serial
    *   @endcode
    *
    * - Limit baud rate to 19200!  Observe that that this routine is called
    *   from the ISR.  Consequently, the incoming data must be slower than the
    *   tick rate of the ISR.  Assuming 10 bits per byte (includes start and stop
    *   bits), a baud rate of 19200 equates to 1900 bytes per second.  An ISR with
    *   10,000 ticks per second gives a 5x safety margin.
    *
    * - No success detection is implimented which is to say MAIN must read the
    *   circuar buffer faster than it is written or data will be lost.
    *
    * @note
    *
    * - This is a non blocking routine that is normally called from ISR.
    *
    * - Ref PIC18 data sheet: RCIF is set when when data is in USART FIFO
    *
    * - Ref PIC18 data sheet: a read of RCREG will automatically clear RCIF.
    *
    */




    
    
    /**
 * @brief Write a string contained in a RAM buffer to the PIC18's USART.
 *
 * @param *P Pointer to a buffer holding a null terminates string.
 *
 * @return void
 *
 * \b Example:
 *    @code
 *      sprintf(buf, "Hello World! \n");
 *      USART_puts_RAM(buf);
 *    @endcode
 *
 * \b Comments:
 *
 * - This is a blocking routine that is normally called from MAIN.
 *
 * @see put_s_ROM
*/
//void USART_puts_RAM(char *P);