/**
 * @file       driver_motors.h
 * @copyright
 * @license
 * @version    1.0.0
 * @date       2025-03-01
 * @author     Nguyen Tan Phat
 * @author
 *
 * @brief      <Header file: define variables, functions to control motor by PID>
 *
 * @note
 * @example
 *             Example_1 description
 * @example
 *             Example_2 description
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __DRV_MOTORS_H
#define __DRV_MOTORS_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>

/* Public defines ----------------------------------------------------- */
#define PI          (3.14159265358979323846f) /*!< pi constant */
#define HILIM       (100)                     /*!< High limit of PWM */
#define LOLIM       (0)                       /*!< Low limit of PWM */
#define X1_ENCODING (990)  /*!< Number of encoder's pulse per revolution in reading x1 mode */
#define X2_ENCODING (1980) /*!< Number of encoder's pulse per revolution in reading x2 mode */
#define X4_ENCODING (3960) /*!< Number of encoder's pulse per revolution in reading x4 mode */

/* Public enumerate/structure ----------------------------------------- */

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief  <This function calculate pwm by pid for left motor>
 *
 * @param[in]     <set>  <set point>
 *                <current>  <current value from feedback>
 *                <kp>  <variable for P term>
 *                <ki>  <variable for I term>
 *                <kb>  <variable for anti-windup>
 * @return
 *  pwm
 */
int16_t pid_left(float set, float current, float kp, float ki, float kb, float dt);

/**
 * @brief  <This function calculate pwm by pid for right motor>
 *
 * @param[in]     <set>  <set point>
 *                <current>  <current value from feedback>
 *                <kp>  <variable for P term>
 *                <ki>  <variable for I term>
 *                <kb>  <variable for anti-windup>
 * @return
 *  pwm
 */
int16_t pid_right(float set, float current, float kp, float ki, float kb, float dt);

#endif  // __DRV_MOTORS_H

/* End of file -------------------------------------------------------- */
