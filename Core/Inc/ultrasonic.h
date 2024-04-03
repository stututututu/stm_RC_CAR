/*
 * ultrasonic.h
 *
 *  Created on: Apr 3, 2024
 *      Author: mujukpopo
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include "main.h"
#include "delay.h"

#define	LEFT_TRIG_PORT		GPIOC
#define LEFT_TRIG_PIN		GPIO_PIN_4
#define RIGHT_TRIG_PORT		GPIOA
#define RIGHT_TRIG_PIN		GPIO_PIN_1
#define CENTER_TRIG_PORT 	GPIOC
#define CENTER_TRIG_PIN		GPIO_PIN_5



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HCSR04_Left_Read(void);
void HCSR04_Right_Read(void);
void HCSR04_Center_Read(void);



#endif /* INC_ULTRASONIC_H_ */
