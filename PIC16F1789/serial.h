/**
 * @file serial_public.h
 *
 * @brief Contain the public access to the PIC.
 *
 * The code for USART reception is split between the Interrupt Service Routine
 * and MAIN.  A circular buffer is used to transfer data between from the ISR
 * to main().
 *
 */
#ifndef _SERIAL_PUBLIC_H
    #define _SERIAL_PUBLIC_H

    #include <xc.h>
    #include <stdint.h>

    // Alias for ASCII characters
        #define LF 0x0A         // Line Feed
        #define CR 0x0D         // Carriage Return

    void service_serial(void);
  
    uint8_t serial_is_string(void);

    uint8_t serial_gets(char *P);
    
    void serial_puts_RAM(char *P);
    
    void serial_puts_ROM(const char *P);

#endif	/* SERIAL_PUBLIC_H */