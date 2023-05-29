

#ifndef RFID_INTERFACE_H
#define RFID_INTERFACE_H

void SmartParking_voidStoreEnternceID(u32 Copy_u32RFID);
void SmartParking_voidTimeCalculating(void);
/*this function will be called by EXTI */
void SmartParking_voidCalculateCost (u8 *Copy_u8CostPerHour, u32 Copy_u32RFID);

/*this function to get backup data that stored in EEPROM if any power issue occurred */
void SmartParking_voidGetBackupData (u8 * Copy_u8CostPerHour , u32 Copy_u32RFID);


#endif