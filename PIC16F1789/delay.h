/*!
 * @file delay_public.h
 *
 * @brief Delay functions for use in main().
 *
 * @todo Consider adding a delay using one of the hardware timers
 *
 */

#ifndef _DELAY_H
#define _DELAY_H

    #include <xc.h>
    #include <stdint.h>

    void service_delay(void);

    void delay_ISR_ticks(uint16_t X);

    void delay_ms(uint16_t X);

    void delay_nb_ISR_ticks_start(uint16_t X);

    uint8_t delay_is_nb_ISR_ticks_over(void);

#endif
