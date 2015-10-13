#include <stdint.h>
#include "port.h"
#include "LMD18200.h"
#include "mcc_generated_files/pwm1.h"



#define abs(n)   ( ((n) >= 0) ? (n) : -(n) )  // Not included in C18...

    void set_brake (int8_t);
    void set_direction (int8_t);
    void set_plant (int16_t);


/**
 * @brief Initialize the PIC18 to LMD18200 interface.
 *
 * @param void
 *
 * @return void
 *
 * @warning Be sure to order the PWM_config and LMD18200_config functions so
 * that the load will start with a known "safe" PWM value.
 *
 * \b Pseudocode
 *
 * - initialize the PWM to a known safe value
 *
 * - send the duty cycle to the PIC18's PWM
 *
 */
void LMD18200_config(void){

    LMD18200_set_PWM(0x0000);
    LMD18200_BRAKE_DIRECTION = OUTPUT;
    LMD18200_MOTOR_DIRECTION_DIRECTION = OUTPUT;
    LMD18200_set_brake(ON);
}



/**
 * @brief Set the motor speed by calling the PWM function.
 *
 * @param ctrl contains the desired drive level for the motor.
 * -1024 < ctrl < 1023
 *
 * @return void
 *
 * \b Pseudocode
 *
 * - turn off the LM18200's electronic break
 *
 * - set the LM18200's direction based on the sign of the ctrl parameter
 *
 * - set the LM18200's PWM duty cycle to the absolute value of ctrl
 *
 */
void LMD18200_drive_plant(int16_t ctrl){

    LMD18200_set_brake(OFF);

    if (ctrl > 0){            
        LMD18200_set_direction(CW);
    }
    else{
        LMD18200_set_direction(CCW);
    }
    if (ctrl> 0){
        LMD18200_set_PWM (ctrl);
    }
    else{
        LMD18200_set_PWM (0);
    }

}


/**
 * @brief Command the LMD18200's electronic brake.
 *
 * @param C contains a boolean value: the brake is either on or off.
 *
 * @return void
 *
 */
void LMD18200_set_brake (uint8_t C){

    if (C == ON)
        LMD18200_BRAKE_PIN = ON;
    else
        LMD18200_BRAKE_PIN = OFF;
}




/**
 * @brief Command the LMD18200 to move the motor clockwise or counter-clockwise.
 *
 * @param C contains a boolean value: the motor is commanded to turn CW or CCW.
 *
 * @return void
 *
 * @warning Actual motor direction is dependent on the motor's physical wiring.
 *
 */
void LMD18200_set_direction (uint8_t C){

    if (C == CCW)
        LMD18200_MOTOR_DIRECTION_PIN = CCW;
    else
        LMD18200_MOTOR_DIRECTION_PIN = CW ;
}






/**
 * @brief Set the motor speed by calling the PWM function.
 *
 * @param Duty_Cycle contains the duty cycle to which the PWM will be set.
 *        0 < Duty_cycle < 1024  This assumes the PWM has a 10 bit value.
 *
 * @return void
 *
 * \b Pseudocode:
 *
 * - limit the Duty cycle to 2^10 - 1.  Here we assume a 10 bit PWM will be used.
 *
 * - send the duty cycle to the PIC18's PWM.
 *
 * @todo Should the limits on the PWM value appear here or should they be moved
 *       to the PMW function?
 *
 * @warning Should this code be used as a template for other H-bridge drivers
 * additional limits should be coded to prevent shoot through.
 */
void LMD18200_set_PWM (uint16_t Duty_Cycle){ 

    if (Duty_Cycle > 1023){
        //PWM1_set_DC(1023);
        PWM1_LoadDutyValue(1023);
    }
    else{
        //PWM1_set_DC(Duty_Cycle);
        PWM1_LoadDutyValue(Duty_Cycle);
    }
}
