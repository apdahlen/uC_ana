/*!
 * @file LMD18200_Public.h
 *
 * @brief This module contains functions that are used to interface with the
 *        Texas instruments LMD18200 H-Bridge.
 *
 * The LMD18200 H-bridge provides a 3A, 55V bridge in an 11-pin SIP package.
 * It was originally designed by National Semiconductor - recently NS was
 * purchased by TI...
 *
 * @warning Be sure to order the PWM_config and LMD18200_config functions so
 * that the load will start with a known "safe" PWM value.
 *
 * @note
 *
 * - The load is assumed to be a motor.  This is rflected in these comments as
 *   well as the function naming conventions.
 *
 * - Be sure to add the following code to the ports.h file.  Adjust the I/O pin
 *   names as appropriate for the project:
 *
 *   @code
 *       #define LMD18200_BRAKE_PIN PORTXbits.RXX
 *       #define LMD18200_MOTOR_DIRECTION_PIN PORTXbits.RXX
 *
 *       #define LMD18200_BRAKE_TRIS PORTXbits.RXX
 *       #define LMD18200_MOTOR_DIRECTION_TRIS PORTXbits.RXX
 *   @endcode
 *
 * - Also, be sure to initialize the PWM.
 *
 */

#ifndef _LMD18200_H
    #define _LMD18200_H

    /*! 8-bit shortcut for logic "1" */
        #define ON 0x01
    /*! 8-bit shortcut for logic "0" */
        #define OFF 0x00

    /*! 8-bit shortcut for "ClockWise" */
        #define CW 0x01
    /*! 8-bit shortcut for "Counter ClockWise" */
        #define CCW 0x00


    void LMD18200_config(void);

    void LMD18200_drive_plant(int16_t ctrl);

    void LMD18200_set_brake (uint8_t C);

    void LMD18200_set_direction (uint8_t C);

    void LMD18200_set_PWM (uint16_t Duty_Cycle);

#endif	/* LMD18200_H */

