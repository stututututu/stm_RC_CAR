/*
 * ultrasonic.c
 *
 *  Created on: Apr 3, 2024
 *      Author: mujukpopo
 */


#include "ultrasonic.h"


uint16_t leftValue1 = 0;
uint16_t leftValue2 = 0;
uint16_t rightValue1 = 0;
uint16_t rightValue2 = 0;
uint16_t centerValue1 = 0;
uint16_t centerValue2 = 0;

uint16_t leftTime = 0;
uint16_t rightTime = 0;
uint16_t centerTime = 0;

uint8_t leftFlag = 0;
uint8_t rightFlag = 0;
uint8_t centerFlag = 0;

uint8_t leftDis = 0;
uint8_t rightDis = 0;
uint8_t centerDis = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(leftFlag == 0)
		{
			leftValue1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			leftFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(leftFlag == 1)
		{
			leftValue2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			__HAL_TIM_SET_COUNTER(htim, 0);
			if(leftValue2 > leftValue1)
			{
				leftTime = leftValue2 - leftValue1;
			}
			else if(leftValue1 > leftValue2)
			{
				leftTime = (0xffff - leftValue1) + leftValue2;
			}
			leftDis = leftTime / 58;
			leftFlag = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC1);
		}
	}
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if(rightFlag == 0)
		{
			rightValue1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			rightFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(rightFlag == 1)
		{
			rightValue2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			__HAL_TIM_SET_COUNTER(htim, 0);
			if(rightValue2 > rightValue1)
			{
				rightTime = rightValue2 - rightValue1;
			}
			else if(rightValue1 > rightValue2)
			{
				rightTime = (0xffff - rightValue1) + rightValue2;
			}
			rightDis = rightTime / 58;
			rightFlag = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC2);
		}
	}
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if(centerFlag == 0)
		{
			centerValue1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			centerFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(centerFlag == 1)
		{
			centerValue2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
			__HAL_TIM_SET_COUNTER(htim, 0);
			if(centerValue2 > centerValue1)
			{
				centerTime = centerValue2 - centerValue1;
			}
			else if(centerValue1 > centerValue2)
			{
				centerTime = (0xffff - centerValue1) + centerValue2;
				}
			centerDis = centerTime / 58;
			centerFlag = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC3);
		}
	}
}


void HCSR04_Left_Read(void)
{
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, GPIO_PIN_RESET);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC1);
}
void HCSR04_Right_Read(void)
{
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, GPIO_PIN_RESET);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC2);
}
void HCSR04_Center_Read(void)
{
	HAL_GPIO_WritePin(CENTER_TRIG_PORT, CENTER_TRIG_PIN, GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(CENTER_TRIG_PORT, CENTER_TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(CENTER_TRIG_PORT, CENTER_TRIG_PIN, GPIO_PIN_RESET);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC3);
}
