/*
 * ld2450.c
 *
 *  Created on: May 27, 2024
 *      Author: ksj10
 */


#include "ld2450.h"
#include "usart.h"
#include "dma.h"


int delay_ms = 1000;
static uint32_t delay_tick;

static uint8_t enable_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x04, 0x00, 0xFF, 0x00, 0x10, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t end_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xFE, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t single_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x80, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t multi_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x90, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t query_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x91, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t restore_factory[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xA2, 0x00, 0x04, 0x03, 0x02, 0x01};
static uint8_t restart_module[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xA3, 0x00, 0x04, 0x03, 0x02, 0x01};
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
    restoreFactoryLd2450();
}

void enableConfigLd2450(void)
{
    HAL_UART_DMAStop(&hlpuart1);
    delayLd2450(delay_ms);
    MX_DMA_Init();
    MX_LPUART1_UART_Init();
    HAL_UART_Receive_DMA(&hlpuart1, comm_inst.rx_buffer, DEF_RX_BUFFER_LENGTH);

    HAL_StatusTypeDef ret = HAL_UART_Transmit_DMA(&hlpuart1, enable_config, sizeof(enable_config));
    if(ret != HAL_OK)
    {
        MX_LPUART1_UART_Init();
        HAL_UART_Receive_DMA(&hlpuart1, comm_inst.rx_buffer, DEF_RX_BUFFER_LENGTH);
    }
	delayLd2450(delay_ms);
}

void endConfigLd2450(void)
{
	HAL_UART_Transmit_DMA(&hlpuart1, end_config, sizeof(end_config));
	delayLd2450(delay_ms);
}

void singleTargetTrackLd2450(void)
{
    HAL_UART_Transmit_DMA(&hlpuart1, single_target_track, sizeof(single_target_track));
	delayLd2450(delay_ms);
}

void multiTargetTrackLd2450(void)
{
    HAL_UART_Transmit_DMA(&hlpuart1, multi_target_track, sizeof(multi_target_track));
	delayLd2450(delay_ms);
}

void queryTargetTrackingLd2450(void)
{
    HAL_UART_Transmit_DMA(&hlpuart1, query_target_track, sizeof(query_target_track));
	delayLd2450(delay_ms);
}

void readFirmwareVersionLd2450(void)
{
	delayLd2450(delay_ms);
}

void settingBaudrateLd2450(uint32_t baud_rate)
{
	delayLd2450(delay_ms);
}

void restoreFactoryLd2450(void)
{
    HAL_UART_Transmit_DMA(&hlpuart1, restore_factory, sizeof(restore_factory));
	delayLd2450(delay_ms);
}

void restartLd2450(void)
{
    HAL_UART_Transmit_DMA(&hlpuart1, restart_module, sizeof(restart_module));
	delayLd2450(delay_ms);
}

void bluetoothSetup(void)
{
	delayLd2450(delay_ms);
}

void getMacAddress(void)
{
	delayLd2450(delay_ms);
}

void queryCurrentZoneFilteringConfig(void)
{
	HAL_UART_Transmit_DMA(&hlpuart1, read_current_zone_filtering, sizeof(read_current_zone_filtering));
	delayLd2450(delay_ms);
}

void settingRegionalFilteringConfig(void)
{
	HAL_Delay(delay_ms);
}

void radarDataOutput(void)
{
	HAL_Delay(delay_ms);
}
