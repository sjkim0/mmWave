/*
 * hw.c
 *
 *  Created on: Jul 17, 2024
 *      Author: ksj10
 */


#include "hw.h"


void hwInit(void)
{
	bspInit();

	MX_GPIO_Init();
	MX_BDMA_Init();
	MX_LPUART1_UART_Init();

	ld2450Init();
}
