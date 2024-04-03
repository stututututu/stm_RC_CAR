/*
 * bt.c
 *
 *  Created on: Apr 3, 2024
 *      Author: mujukpopo
 */

#include "bt.h"

uint8_t rxData[1];


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_DMA(&huart1, rxData, sizeof(rxData));
}
