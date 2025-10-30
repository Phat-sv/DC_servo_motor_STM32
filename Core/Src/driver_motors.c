/**
 * @file       driver_motors.c
 * @copyright
 * @license
 * @version    1.0.0
 * @date       2025-03-01
 * @author     Nguyen Tan Phat
 * @author
 *
 * @brief      <Functions to control motor by PID>
 *
 * @note
 * @example
 *             Example_1 description
 * @example
 *             Example_2 description
 */

/* Includes ----------------------------------------------------------- */
#include "driver_motors.h"

/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
int16_t pid_left(float set, float current, float kp, float ki, float kb, float dt)
{
  static float e_reset = 0.0f;
  static float ui_pre  = 0.0f;

  float error, up, ui;
  float pid, pid_out;

  error = set - current;
  up    = kp * error;
  ui    = ui_pre + ki * dt * error + kb * dt * e_reset;

  ui_pre = ui;

  pid = up + ui;

  if (pid > HILIM)
    pid_out = HILIM;
  else if (pid < LOLIM)
    pid_out = LOLIM;
  else
    pid_out = pid;

  e_reset = pid_out - pid;

  return (int16_t)pid_out;
}

int16_t pid_right(float set, float current, float kp, float ki, float kb, float dt)
{
  static float e_reset = 0.0f;
  static float ui_pre  = 0.0f;

  float error, up, ui;
  float pid, pid_out;

  error = set - current;
  up    = kp * error;
  ui    = ui_pre + ki * dt * error + kb * dt * e_reset;

  ui_pre = ui;

  pid = up + ui;

  if (pid > HILIM)
    pid_out = HILIM;
  else if (pid < LOLIM)
    pid_out = LOLIM;
  else
    pid_out = pid;

  e_reset = pid_out - pid;

  return (int16_t)pid_out;
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
