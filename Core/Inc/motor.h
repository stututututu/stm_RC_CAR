/*
 * motor.h
 *
 *  Created on: Apr 3, 2024
 *      Author: mujukpopo
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "tim.h"
#include "main.h"
#include "bt.h"


void Go(void);
void Stop(void);
void Left(void);
void Right(void);

void manualMode(void);
void autoMode(void);

//void drive_mode(void);
//void ddd(void);

#endif /* INC_MOTOR_H_ */
