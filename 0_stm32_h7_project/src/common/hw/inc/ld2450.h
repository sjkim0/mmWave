/*
 * ld2450.h
 *
 *  Created on: May 27, 2024
 *      Author: ksj10
 */

#ifndef INC_LD2450_H_
#define INC_LD2450_H_



#include "hw_def.h"


void ld2450Init(void);
void enableConfigLd2450(void);
void endConfigLd2450(void);
void singleTargetTrackLd2450(void);
void multiTargetTrackLd2450(void);
void queryTargetTrackingLd2450(void);
void readFirmwareVersionLd2450(void);
void settingBaudrateLd2450(uint32_t baud_rate);
void restoreFactoryLd2450(void);
void restartLd2450(void);
void bluetoothSetup(void);
void getMacAddress(void);
void queryCurrentZoneFilteringConfig(void);
void settingRegionalFilteringConfig(void);
void radarDataOutput(void);


#endif /* INC_LD2450_H_ */
