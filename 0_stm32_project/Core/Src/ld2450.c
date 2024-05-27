/*
 * ld2450.c
 *
 *  Created on: May 27, 2024
 *      Author: ksj10
 */


#include "ld2450.h"
#include "usart.h"


static uint32_t delay_tick;

static uint8_t enable_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x04, 0x00, 0xFF, 0x00, 0x10, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t end_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0xFE, 0x00, 0x04, 0x03, 0x02, 0x01};

uint8_t read_current_zone_filtering[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xC1, 0x00, 0x04, 0x03, 0x02, 0x01};


static void delayLd2450(int tick);


static void delayLd2450(int tick)
{
	delay_tick = HAL_GetTick();
	while(HAL_GetTick() - delay_tick < tick)
	{

	}
}

void initLd2450(void)
{
	enableConfigLd2450();

	endConfigLd2450();
}

void enableConfigLd2450(void)
{
	HAL_UART_Transmit_DMA(&hlpuart1, enable_config, sizeof(enable_config));
	delayLd2450(1);
}

void endConfigLd2450(void)
{
	HAL_UART_Transmit_DMA(&hlpuart1, end_config, sizeof(end_config));
	delayLd2450(1);
}

void singleTargetTrackLd2450(void)
{
	delayLd2450(1);
}

void multiTargetTrackLd2450(void)
{
	delayLd2450(1);
}

void queryTargetTrackingLd2450(void)
{
	delayLd2450(1);
}

void readFirmwareVersionLd2450(void)
{
	delayLd2450(1);
}

void settingBaudrateLd2450(uint32_t baud_rate)
{
	delayLd2450(1);
}

void restoreFactoryLd2450(void)
{
	delayLd2450(1);
}

void restartLd2450(void)
{
	delayLd2450(1);
}

void bluetoothSetup(void)
{
	delayLd2450(1);
}

void getMacAddress(void)
{
	delayLd2450(1);
}

void queryCurrentZoneFilteringConfig(void)
{
	HAL_UART_Transmit_DMA(&hlpuart1, read_current_zone_filtering, sizeof(read_current_zone_filtering));
	delayLd2450(1);
}

void settingRegionalFilteringConfig(void)
{
	HAL_Delay(1);
}

void radarDataOutput(void)
{
	HAL_Delay(1);
}
