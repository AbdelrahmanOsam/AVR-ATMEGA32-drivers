/*********************************************
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


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "LCD_interface.h"

#include "util/delay.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8Data)
{
	//u32 error_state ;

    u8 Local_u8SlaveAddress = FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

    //Send Start Condition
    TWI_ERRSendStartCondition();
    /*Send Slave Address + Write Request*/
    TWI_ERRSendSlaveAddressWithWrite(Local_u8SlaveAddress);
    /*Send Location Address*/
    TWI_ERRSendDataPacket((u8)Copy_u16LocationAddress);
    /*Send Data*/
    TWI_ERRSendDataPacket(Copy_u8Data);
    /*Send Stop Condition*/
    TWI_voidSendStopCondition();
    /*Delay 10 msec*/
    _delay_ms(10);
}

void EEPROM_voidReceiveDataByte(u16 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8SlaveAddress = FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);
    //Send Start Condition
    TWI_ERRSendStartCondition();

    /*Send Slave Address + Write Request*/
    TWI_ERRSendSlaveAddressWithWrite(Local_u8SlaveAddress);
    /*Send Location Address*/
    TWI_ERRSendDataPacket((u8)Copy_u16LocationAddress);
    /*Send Repeated Start Condition*/
    TWI_ERRSendRepeatedStartCondition();
    /*Send Slave Address + Read Request*/
    TWI_voidSendSlaveAddressWithRead(Local_u8SlaveAddress);
    /*Receive Data*/
    TWI_ERRReceiveDataPacket(Copy_pu8ReceivedData);
    /*Send Stop Condition*/
    TWI_voidSendStopCondition();
}
