/*
 * ld2450.c
 *
 *  Created on: May 27, 2024
 *      Author: ksj10
 */


#include "ld2450.h"
#include "ld2450_cmd.h"
#include "usart.h"
#include "bdma.h"
#include "hw_comm.h"


static hw_comm_t ld2450_comm_inst;
static UART_HandleTypeDef *p_huart_2450;
static uint32_t delay_tick;


static void delayLd2450(int tick);


void ld2450Init(void)
{
	ld2450_comm_inst.tx_dma_done = true;
	ld2450_comm_inst.rx_dma_done = true;
	p_huart_2450 = &hlpuart1;


    restoreFactoryLd2450();
}

void enableConfigLd2450(void)
{
    HAL_StatusTypeDef ret = HAL_UART_Transmit_DMA(p_huart_2450, enable_config, sizeof(enable_config));
	delayLd2450(delay_ms);

    if(ret != HAL_OK)
    {
        MX_LPUART1_UART_Init();
        HAL_UART_Receive_DMA(p_huart_2450, ld2450_comm_inst.rx_buff, DEF_COMM_BUFF_LENGTH);
    }
	delayLd2450(delay_ms);
}

void endConfigLd2450(void)
{
	HAL_UART_Transmit_DMA(p_huart_2450, end_config, sizeof(end_config));
	delayLd2450(delay_ms);
}

void singleTargetTrackLd2450(void)
{
    HAL_UART_Transmit_DMA(p_huart_2450, single_target_track, sizeof(single_target_track));
	delayLd2450(delay_ms);
}

void multiTargetTrackLd2450(void)
{
    HAL_UART_Transmit_DMA(p_huart_2450, multi_target_track, sizeof(multi_target_track));
	delayLd2450(delay_ms);
}

void queryTargetTrackingLd2450(void)
{
    HAL_UART_Transmit_DMA(p_huart_2450, query_target_track, sizeof(query_target_track));
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
    HAL_UART_Transmit(p_huart_2450, restore_factory, sizeof(restore_factory), 0xFF);
	delayLd2450(delay_ms);
}

void restartLd2450(void)
{
    HAL_UART_Transmit_DMA(p_huart_2450, restart_module, sizeof(restart_module));
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
	HAL_UART_Transmit_DMA(p_huart_2450, read_current_zone_filtering, sizeof(read_current_zone_filtering));
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

static void delayLd2450(int tick)
{
	delay_tick = millis();
	while(millis() - delay_tick < tick)
	{

	}
}
