/*
 * motor.c
 *
 *  Created on: Apr 3, 2024
 *      Author: mujukpopo
 */


#include "motor.h"

extern uint8_t rxData[1];
extern uint8_t driveMode;

void Go(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);//right
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);// reverse right

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);//left
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);//reverse left

}
void Stop(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
}
void Left(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
}
void Right(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
}

void manualMode(void)
{
	if(rxData[0] == 'w')
	{
		TIM1->CCR1 = 400;
		TIM1->CCR2 = 400;
		Go();
	}
	else if(rxData[0] == 's')
	{
		TIM1->CCR1 = 400;
		TIM1->CCR2 = 400;
		Stop();
	}
	else if(rxData[0] == 'a')
	{
		TIM1->CCR1 = 400;
		TIM1->CCR2 = 400;
		Left();
	}
	else if(rxData[0] == 'd')
	{
		TIM1->CCR1 = 400;
		TIM1->CCR2 = 400;
		Right();
	}
}

void autoMode(void)
{
	;
}




