/*
 * delay.c
 *
 *  Created on: Apr 1, 2024
 *      Author: mujukpopo
 */

#include "delay.h"

void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim11, 0);
	while((__HAL_TIM_GET_COUNTER(&htim11)) < us);
}







