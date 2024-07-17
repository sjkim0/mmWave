/*
 * hw_comm.h
 *
 *  Created on: Jul 17, 2024
 *      Author: ksj10
 */

#ifndef COMMON_HW_INC_HW_COMM_H_
#define COMMON_HW_INC_HW_COMM_H_


#include "hw_def.h"


#define DEF_COMM_BUFF_LENGTH (100U)


typedef struct
{
	uint8_t rx_buff[DEF_COMM_BUFF_LENGTH];
	uint8_t tx_buff[DEF_COMM_BUFF_LENGTH];
	bool tx_dma_done;
	bool rx_dma_done;
	int rx_index_head;
	int rx_index_tail;
	int tx_index_head;
	int tx_index_tail;
}hw_comm_t;


extern hw_comm_t hw_comm_inst;


void hwCommInit(void);


#endif /* COMMON_HW_INC_HW_COMM_H_ */
