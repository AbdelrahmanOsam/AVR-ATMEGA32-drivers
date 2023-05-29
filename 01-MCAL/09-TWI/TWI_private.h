/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   27 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0        27 MAY, 2023    Asmaa Abd EL-kareim          Initial Creation
*********************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H


#define TWDR			*((volatile u8 *)(0x23))
#define	TWDR_TWD0		            0


#define TWAR			*((volatile u8 *)(0x22))
#define	TWAR_TWGCE		            0

#define TWSR			*((volatile u8 *)(0x21))
#define TWSR_TWPS0		            0
#define TWSR_TWPS1		            1

#define TWCR			*((volatile u8 *)(0x56))
#define	TWCR_TWIE	              	0
#define	TWCR_TWEN	             	2
#define	TWCR_TWWC		            3
#define	TWCR_TWSTO	            	4
#define	TWCR_TWSTA		            5
#define	TWCR_TWEA	            	6
#define	TWCR_TWINT	            	7

#define TWBR			*((volatile u8 *)(0x20))

#define STATUS_BIT_MASK		      0xF8



///////////////////////////////////////////////////////////

#define START_ACK                0x08
#define REP_START_ACK            0x10
#define SLAVE_ADD_AND_WR_ACK     0x18
#define SLAVE_ADD_AND_RD_ACK     0x40
#define MSTR_WR_BYTE_ACK         0x28
#define MSTR_RD_BYTE_WITH_ACK    0x50
#define MSTR_RD_BYTE_WITH_NACK   0x58
#define SLAVE_ADD_RCVD_RD_REQ    0xA8
#define SLAVE_ADD_RCVD_WR_REQ    0x60
#define SLAVE_DATA_RECEIVED      0x80
#define SLAVE_BYTE_TRANSMITTED   0xB8


#endif 
