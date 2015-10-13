/**
 * 
 * @File Name
 *   delay.c
 *
 *  @Summary
 *   Facilitate delay routines to be used in main(). 
 *
 *  @Description
 *   This code depends on an ISR and is written to safe code and memory space. Blocking as well 
 *   as non-bocking delays are included. 
 *
 */


#include "delay.h"
#include <stdint.h>

// Private variables

    volatile static uint16_t mailbox;
    volatile static uint8_t flag;

    volatile static uint16_t nb_mailbox;
    volatile static uint8_t nb_flag;

/**
 * @brief Facilitate the various delay routines used by the background code.
 *
 * This function is the counterpart to DELAY_ISR_ticks and the
 * DELAY_nb_ISR_ticks_start / Delay_is_nb_ISR_ticks_over combination.  Together
 * these function provide a time delay for background tasks.  This convoluted
 * code allows for reasonably accurate time delays without the requirement of
 * using a hardware timer.
 *
 * @param void
 *
 * @return void
 *
 * \b Pseudo code for DELAY_ISR_ticks
 *
 * 1) The background function calls DELAY_ISR_ticks with a desired delay.
 *
 * 2) DELAY_ISR_ticks places the desired delay in "mailbox" and sets "flag"
 *    signalling DELAY_service to act.  DELAY_ISR_ticks waits (blocks) until 
 *    "flag" is cleared.
 *
 * 3) Delay_service decrements the mailbox count.  When it reaches zero "flag"
 *    is cleared.
 *
 * 4) When the "flag" is cleared DELAY_ISR_ticks is complete.
 *
 * \b Example code for blinking an LED:
 *
 * @code
 *
 * ISR{
 *    .
 *    .
 *    .
 *    DELAY_service( );
 *    .
 *    .
 *    .
 * }
 *
 * MAIN{
 *     while(1){
 *         LED_PIN = ON;
 *         DELAY_ISR_ticks(5000);      // assume ISR ticks 10,000 a second
 *         LED_PIN = OFF;
 *         DELAY_ISR_ticks(5000);
 *    }
 * }
 * @endcode
 *
 * @note
 *
 * - DELAY_service is called from the ISR (foreground).
 *
 * - DELAY_ISR_ticks is called from various places in MAIN (background).
 *
 */
void service_delay(void){

    if(flag){
        mailbox--;
        if (mailbox == 0){
            flag = 0x00;
        }
    }

    if (nb_flag){
        nb_mailbox--;
        if (nb_mailbox == 0){
            nb_flag = 0x00;
        }
    }
}




/**
 * @brief Delay the specified number of ISR ticks where 2 < X < 65535 ticks
 *
 * @param X contains the number of ISR ticks to wait.
 *
 * @return void
 *
 * \b Example
 *
 * @code
 *      DELAY_ISR_ticks(100);  // delay 100 ISR ticks
 * @endcode
 *
 * @warning This code has an uncertainty of one ISR tick time period.
 *
 * @note
 *
 * - Since there is an uncertainty of one ISR tick associated with this function
 *   any time it is called with a number less than or equal to two it will
 *   assume the programmer intended to code input parameter X as 2.
 *
 * - This routine performs a delay in conjunction with the ISR.  It
 *   assumes that the ISR is configured to produce a regular tick.
 *   Typical ISR "ticks" occur 1,000 or 10,000 "ticks" per second.
 *
 * @see DELAY_service
 *
 */
void delay_ISR_ticks(uint16_t X){

    if (X <= 2){
        mailbox = 2;
        flag = 0x01;
    }
    else{
        mailbox = X;
        flag = 0x01;
    }
    while(flag);
}




/**
 * @brief Delay X microsecond where 1 < X < 65535 ms
 *
 * @param X contains the number of ms to delay.
 *
 * @return void
 *
 * \b Example
 *
 * @code
 *      DELAY_ms(100);  // delay 100 ms
 * @endcode
 * 
 * @warning As coded this function assumes an ISR that ticks 10,000 a second.
 *
 * @note
 *
 * - This function provides delays that are APPROXIMATLY one millisecond long.
 *   If you need accurate time delays your code should probably "live" in the
 *   ISR (foreground).  You should also consider using a hardware timer.
 *
 * - If called with a zero delay this function assumes the programmer intended
 *   a 1 ms delay.
 *
 * @see delay_ISR
 *
 */
void delay_ms(uint16_t X){

    uint16_t i;

    if (X == 0){                    // delay at least one ms
        delay_ISR_ticks(1);
    }
    else{
        for(i = 0; i < X; i++){
            delay_ISR_ticks(1);
        }
    }
}










/**
 * @brief Initialize a counter to facilitate a non-blocking delay routine.  The
 *        parameter specifies the  number of ISR ticks where 2 < X < 65535 ticks
 *
 * @param X contains the number of ISR ticks to wait.
 *
 * @return void
 *
 * \b Example
 *
 * @code
 *
 * ISR{
 *    .
 *    .
 *    .
 *    DELAY_service( );
 *    .
 *    .
 *    .
 * }
 *
 * MAIN{
 *     while(1){
 *         .
 *         .
 *         .
 *         DELAY_nb_ISR_ticks_start(uint16_t X)  //assume ISR ticks 10,000 a second
 *
 *         if ( Delay_is_nb_ISR_ticks_over( ) ){
 *             LED_PIN = ! LED_PIN;
 *         }
 *         .
 *         .
 *         .
 *    }
 * }
 * @endcode
 *
 * @warning At best this is a sloppy time delay.  While the delay counter as
 * maintained by the ISR is reasonably accurate, there may be long delays in
 * the super-loop before Delay_is_nb_ISR_ticks_over is executed and the
 * delayed portion of the code operates.  If accurate time delays are required
 * the ISR or a hardware timer should be used.
 *
 * @note
 *
 * - This is a non blocking delay - the other code in the super-loop continues
 *   to operate while the delay counter is processed by the ISR.
 *
 * - This code is provided as an alternative to using a hardware timer...
 *
 * - Since there is an uncertainty of one ISR tick associated with this function
 *   any time it is called with a number less than or equal to two it will
 *   assume the programmer intended to code input parameter X as 2.
 *
 * - This routine performs a delay in conjunction with the ISR.  It
 *   assumes that the ISR is configured to produce a regular tick.
 *   Typical ISR "ticks" occur 1,000 or 10,000 "ticks" per second.
 *
 *
 * @see delay_ISR
 *
 */
void DELAY_nb_ISR_ticks_start(uint16_t X){

    if (X <= 2){
        nb_mailbox = 2;

    }
    else{
        nb_mailbox = X;
    }

    nb_flag = 0x01;
}




/**
 * @brief Returns TRUE when the time delay started by DELAY_nb_ISR_ticks_start
 *        has completed.
 *
 * @param void
 *
 * @return Boolean: True indicates time delay specified by
 *         DELAY_nb_ISR_ticks_start has expired.
 *
 * @see DELAY_nb_ISR_ticks_start
 *
 */
uint8_t Delay_is_nb_ISR_ticks_over(void){

    return !nb_flag;
 //   if (nb_flag){
 //       return FALSE;
 //   }
 //   else{
 //       return TRUE;
 //   }
}