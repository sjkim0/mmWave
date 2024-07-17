/*
 * ld2450_cmd.h
 *
 *  Created on: Jul 17, 2024
 *      Author: ksj10
 */

#ifndef COMMON_HW_INC_LD2450_CMD_H_
#define COMMON_HW_INC_LD2450_CMD_H_


const int delay_ms = 1000;

uint8_t enable_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x04, 0x00, 0xFF, 0x00, 0x10, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t end_config[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xFE, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t single_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x80, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t multi_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x90, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t query_target_track[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0x91, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t restore_factory[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xA2, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t restart_module[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xA3, 0x00, 0x04, 0x03, 0x02, 0x01};
uint8_t read_current_zone_filtering[] = {0xFD, 0xFC, 0xFB, 0xFA, 0x02, 0x00, 0xC1, 0x00, 0x04, 0x03, 0x02, 0x01};


#endif /* COMMON_HW_INC_LD2450_CMD_H_ */
