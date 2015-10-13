
#include "mcc_generated_files/mcc.h"
#include "isr.h"
#include "serial.h"
#include "delay.h"

#include "port.h"


void ms_ISR(void) {
    
    static uint16_t LED_PIN_counter = 0;
    
    service_serial();
    service_delay();
    
    if(++LED_PIN_counter == 500){          // toggle keep alive LED pin at 1 Hz
        LED_PIN = !LED_PIN;
        LED_PIN_counter = 0;
    }

}