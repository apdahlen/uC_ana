/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16LF1789
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "serial.h"
#include "delay.h"
#include "line_parser.h"
#include "port.h"
#include "LCD.h"
#include "GPS_Distance.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables

   char line[100];              // Ideally this would have been declared in main(),
                                // however, if you do that the compiler attempts to 
                                // put the array in the stack and runs out of space...

/*
                         Main application
 */
void main(void) {

    double lat1, lon1, lat2, lon2, dist, head;
    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    LCD_config();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    serial_puts_ROM("Hello World!\n");
    LCD_puts_ROM("Hello World!    ", line_2, 0);
    delay_ms(1000);
 //   LCD_w_cmd (clr_dsp);
  
    while (1) {
       
        if(serial_is_string( )){
            serial_gets(line);
            serial_puts_RAM(line);                           // echo to terminal

     //       lcd.setCursor(0, 1);
     //       lcd.print("                ");              // Clear old material from LCD before printing new line
     //       lcd.setCursor(0, 1);
     //       lcd.print(line);

            
            sprintf(line, "count = %X ", 0x10);
            LCD_puts_RAM(line, line_1, 0);

      //      sprintf(buf, "cnt sqr = %d ", counter * counter);
//            LCD_puts_RAM(buf, line_2, 0);
            
            line_parser(line, ',');
            
            get_field(line, 1);
            lat1 = atof(line);
            sprintf(line, "lat1 = %f", lat1);
            LCD_puts_RAM(line, line_1, 0);

            get_field(line, 2);
            lon1 = atof(line);
            sprintf(line, "lon1 = %f", lon1);
            LCD_puts_RAM(line, line_2, 0);
            
            get_field(line, 3);
            lat2 = atof(line);
            sprintf(line, "lat2 = %f", lat2);
            LCD_puts_RAM(line, line_3, 0);

            get_field(line, 4);
            lon2 = atof(line);
            sprintf(line, "lon2 = %f", lon2);
            LCD_puts_RAM(line, line_4, 0);
            
            dist = distance(lat1, lon1, lat2, lon2, 'k');
                    
            head = heading(lat1, lon1, lat2, lon2);
            
            sprintf(line, "distance = %f angle = %f ", dist, head);
            LCD_puts_RAM(line, line_1, 0);
            serial_puts_RAM(line);
            
            }
        }

        serial_puts_ROM("\n");
    }
//}
/**
 End of File
 */