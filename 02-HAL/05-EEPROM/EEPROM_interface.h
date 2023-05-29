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

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8Data);
void EEPROM_voidReceiveDataByte(u16 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData);

#endif
