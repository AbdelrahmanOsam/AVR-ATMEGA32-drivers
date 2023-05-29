
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RFID_interface.h"
#include "RFID_private.h"
#include "RFID_config.h"


/*Timer will count the the time and it will be saved int these variables*/
u8 Global_u8Hours;
u8 Global_u8Minutes;
u8 Clobal_u8Seconds;


/*Array to store 32 BIT OF RFID*/
u32 u32MemorySlots[PARKING_TOTAL_SLOTS] = {0} ;

/*to store the entered time in hour , min and sec*/
u8 u8EntranceTime[(PARKING_TOTAL_SLOTS*3)] = {0} ;

void SmartParking_voidStoreEnternceID(u32 Copy_u32RFID)
{   /*this the variable that will store each part of (1 BYTE) id before send it to EEPROM */
    u8 Local_u8IDToEEPROM = 0;
	u16 Local_u16ArrayIndex  ;
	u8 Local_u8InnerLoopCounter = 0 ;
	for (Local_u16ArrayIndex = 0 ; Local_u16ArrayIndex< PARKING_TOTAL_SLOTS ;  Local_u16ArrayIndex ++)
	{
		if(u32MemorySlots[Local_u16ArrayIndex] == 0) // ask if slot is free
		{
			/*save the RFID in this array Index*/
			u32MemorySlots[Local_u16ArrayIndex ] = Copy_u32RFID ;   //slot is taken now

			/*to indicate the start of reserved block memory for this RFID*/
                u16 Local_u16WordNumber = (Local_u16ArrayIndex*6);

			for (Local_u8InnerLoopCounter = 0; Local_u8InnerLoopCounter < 4 ; Local_u8InnerLoopCounter ++)
			{
				/*split the ID into 4*1 Bytes */
			   Local_u8IDToEEPROM = Copy_u32RFID>>(Local_u8InnerLoopCounter*8);
               /*store 8 bit from id in EEPROM*/
			   EEPROM_voidSendDataByte(Local_u16WordNumber , Local_u8IDToEEPROM);
			   Local_u16WordNumber ++;
			}

                /*to indicate the start of reserved block memory for intrence hour and min*/
                u16 Local_u16TimeArrayIndex = (Local_u16ArrayIndex*3);
				u8EntranceTime[Local_u16TimeArrayIndex] = u8Hours ;
				u8EntranceTime[Local_u16TimeArrayIndex] = u8Mins ;

			for (Local_u8InnerLoopCounter = 0; Local_u8InnerLoopCounter < 2 ; Local_u8InnerLoopCounter ++)
			{


               /*store hours and mins in EEPROM*/
			   EEPROM_voidSendDataByte(Local_u16WordNumber ,u8EntranceTime[(Local_u16TimeArrayIndex+Local_u8InnerLoopCounter)]);
			   Local_u16WordNumber ++;
			}

		}
		else
		{
			//Do Nothing
		}
	}

}


void SmartParking_voidTimeCalculating(void)
{
    u8Secs++;
    if (u8Secs == 60)
    {
        u8Secs = 0 ;
        u8Mins ++ ;
        DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_HIGH);

    }
    else
    {
        //Do nothing
    }
    if (u8Mins == 60)
    {
        u8Mins = 0 ;
        u8Hours++;

    }
    else
    {

    }
    TIMER1_voidSetPreloadValue(0b1000010111101101);
}

void SmartParking_voidCalculateCost (u8 * Copy_u8CostPerHour , u32 Copy_u32RFID)
{
	u8 Local_u8LoopCounter ,  Local_u8IDIsFound = 0 ;
	u8 Local_u8Hour , Local_u8Min ;
	u16 Local_u16TimeArrayIndex;
for (Local_u8LoopCounter = 0 ; ((Local_u8LoopCounter <PARKING_TOTAL_SLOTS) && (Local_u8IDIsFound == 0)) ; Local_u8LoopCounter++)
{
	if (u32MemorySlots [Local_u8LoopCounter] == Copy_u32RFID)
	{   Local_u8IDIsFound = 1;
	   /*get the enterance time from time array*/
		Local_u16TimeArrayIndex = (Local_u8LoopCounter*3);
		Local_u8Hour = u8EntranceTime [Local_u16TimeArrayIndex];
		Local_u16TimeArrayIndex++;
		Local_u8Min = u8EntranceTime [Local_u16TimeArrayIndex];

		/*cost calculations*/
		if(Local_u8Hour < 1)
		{
			*Copy_u8CostPerHour = 10 ;
		}
		else
		{

			*Copy_u8CostPerHour = (10*Local_u8Hour);
			if(Local_u8Min > 30)
			{
				*Copy_u8CostPerHour += 10 ;
			}
			else
			{

			}

		}



	}
	else
	{
		//Do nothing
	}

}


}

/*this function to get backup data that stored in EEPROM if any power issue occurred */
void SmartParking_voidGetBackupData (u8 *Copy_u8CostPerHour , u32 Copy_u32RFID)
{
	u8  Local_u8IDIsFound = 0 ;
	u8 Local_u8ReturnedEEPROMValue ;
	u16 Local_u16LoopCounter, Local_u16InnerLoopCounter ;
	u32 Local_u32StoredID, Local_u32Temp ;
	u8 Local_u8Hour , Local_u8Min ;
	u16 Local_u16TimeArrayIndex;

	for (Local_u16LoopCounter = 0 ; Local_u8IDIsFound == 0 ; Local_u16LoopCounter++)
	{
		for (Local_u16InnerLoopCounter = 0 ; Local_u16InnerLoopCounter < 4 ; Local_u16InnerLoopCounter ++)
		{
			EEPROM_voidReceiveDataByte((Local_u16LoopCounter + Local_u16InnerLoopCounter ),&Local_u8ReturnedEEPROMValue);

			Local_u32Temp = Local_u8ReturnedEEPROMValue;
			Local_u32Temp = (Local_u32Temp<< (Local_u16LoopCounter*8));
			Local_u32StoredID |= Local_u32Temp ;


		}

		if (Local_u32StoredID == Copy_u32RFID )
		{
			Local_u8IDIsFound = 1;
			Local_u16TimeArrayIndex = Local_u16LoopCounter + Local_u16InnerLoopCounter + 1 ;
			EEPROM_voidReceiveDataByte(Local_u16TimeArrayIndex,&Local_u8Hour);
			Local_u16TimeArrayIndex ++;
			EEPROM_voidReceiveDataByte(Local_u16TimeArrayIndex,&Local_u8Min);

			SmartParking_voidCalculateCost(&Copy_u8CostPerHour , Copy_u32RFID);

		}
		else
		{
			//Do Nothing
		}
	}


}
/*************Before main**********************/
///*Timer will count the the time and it will be saved int these variables*/
//u8 u8Hours , u8Mins , u8Secs ;
//
//
///*Array to store 32 BIT OF RFID*/
//u32 u32MemorySlots [PARKING_TOTAL_SLOTS] = {0} ;
//
///*to store the entered time in hour , min and sec*/
//u8 u8EntranceTime [(PARKING_TOTAL_SLOTS*3)] = {0} ;
//
//
//void SmartParking_voidStoreEnternceID(u32 Copy_u32RFID);
//void SmartParking_voidTimeCalculating(void);
///*this function will be called by EXTI */
//void SmartParking_voidCalculateCost (u8 *Copy_u8CostPerHour, u32 Copy_u32RFID);
//
///*this function to get backup data that stored in EEPROM if any power issue occurred */
//void SmartParking_voidGetBackupData (u8 * Copy_u8CostPerHour , u32 Copy_u32RFID);

/*************** After main *****************/

//void SmartParking_voidStoreEnternceID(u32 Copy_u32RFID)
//{   /*this the variable that will store each part of (1 BYTE) id before send it to EEPROM */
//    u8 Local_u8IDToEEPROM = 0;
//	u16 Local_u16ArrayIndex  ;
//	u8 Local_u8InnerLoopCounter = 0 ;
//	for (Local_u16ArrayIndex = 0 ; Local_u16ArrayIndex< PARKING_TOTAL_SLOTS ;  Local_u16ArrayIndex ++)
//	{
//		if(u32MemorySlots[Local_u16ArrayIndex] == 0) // ask if slot is free
//		{
//			/*save the RFID in this array Index*/
//			u32MemorySlots[Local_u16ArrayIndex ] = Copy_u32RFID ;   //slot is taken now
//
//			/*to indicate the start of reserved block memory for this RFID*/
//                u16 Local_u16WordNumber = (Local_u16ArrayIndex*6);
//
//			for (Local_u8InnerLoopCounter = 0; Local_u8InnerLoopCounter < 4 ; Local_u8InnerLoopCounter ++)
//			{
//				/*split the ID into 4*1 Bytes */
//			   Local_u8IDToEEPROM = Copy_u32RFID>>(Local_u8InnerLoopCounter*8);
//               /*store 8 bit from id in EEPROM*/
//			   EEPROM_voidSendDataByte(Local_u16WordNumber , Local_u8IDToEEPROM);
//			   Local_u16WordNumber ++;
//			}
//
//                /*to indicate the start of reserved block memory for intrence hour and min*/
//                u16 Local_u16TimeArrayIndex = (Local_u16ArrayIndex*3);
//				u8EntranceTime[Local_u16TimeArrayIndex] = u8Hours ;
//				u8EntranceTime[Local_u16TimeArrayIndex] = u8Mins ;
//
//			for (Local_u8InnerLoopCounter = 0; Local_u8InnerLoopCounter < 2 ; Local_u8InnerLoopCounter ++)
//			{
//
//
//               /*store hours and mins in EEPROM*/
//			   EEPROM_voidSendDataByte(Local_u16WordNumber ,u8EntranceTime[(Local_u16TimeArrayIndex+Local_u8InnerLoopCounter)]);
//			   Local_u16WordNumber ++;
//			}
//
//		}
//		else
//		{
//			//Do Nothing
//		}
//	}
//
//}
//
//
//void SmartParking_voidTimeCalculating(void)
//{
//    u8Secs++;
//    if (u8Secs == 60)
//    {
//        u8Secs = 0 ;
//        u8Mins ++ ;
//        DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_HIGH);
//
//    }
//    else
//    {
//        //Do nothing
//    }
//    if (u8Mins == 60)
//    {
//        u8Mins = 0 ;
//        u8Hours++;
//
//    }
//    else
//    {
//
//    }
//    TIMER1_voidSetPreloadValue(0b1000010111101101);
//}
//
//void SmartParking_voidCalculateCost (u8 * Copy_u8CostPerHour , u32 Copy_u32RFID)
//{
//	u8 Local_u8LoopCounter ,  Local_u8IDIsFound = 0 ;
//	u8 Local_u8Hour , Local_u8Min ;
//	u16 Local_u16TimeArrayIndex;
//for (Local_u8LoopCounter = 0 ; ((Local_u8LoopCounter <PARKING_TOTAL_SLOTS) && (Local_u8IDIsFound == 0)) ; Local_u8LoopCounter++)
//{
//	if (u32MemorySlots [Local_u8LoopCounter] == Copy_u32RFID)
//	{   Local_u8IDIsFound = 1;
//	   /*get the enterance time from time array*/
//		Local_u16TimeArrayIndex = (Local_u8LoopCounter*3);
//		Local_u8Hour = u8EntranceTime [Local_u16TimeArrayIndex];
//		Local_u16TimeArrayIndex++;
//		Local_u8Min = u8EntranceTime [Local_u16TimeArrayIndex];
//
//		/*cost calculations*/
//		if(Local_u8Hour < 1)
//		{
//			*Copy_u8CostPerHour = 10 ;
//		}
//		else
//		{
//
//			*Copy_u8CostPerHour = (10*Local_u8Hour);
//			if(Local_u8Min > 30)
//			{
//				*Copy_u8CostPerHour += 10 ;
//			}
//			else
//			{
//
//			}
//
//		}
//
//
//
//	}
//	else
//	{
//		//Do nothing
//	}
//
//}
//
//
//}
//
///*this function to get backup data that stored in EEPROM if any power issue occurred */
//void SmartParking_voidGetBackupData (u8 *Copy_u8CostPerHour , u32 Copy_u32RFID)
//{
//	u8  Local_u8IDIsFound = 0 ;
//	u8 Local_u8ReturnedEEPROMValue ;
//	u16 Local_u16LoopCounter, Local_u16InnerLoopCounter ;
//	u32 Local_u32StoredID, Local_u32Temp ;
//	u8 Local_u8Hour , Local_u8Min ;
//	u16 Local_u16TimeArrayIndex;
//
//	for (Local_u16LoopCounter = 0 ; Local_u8IDIsFound == 0 ; Local_u16LoopCounter++)
//	{
//		for (Local_u16InnerLoopCounter = 0 ; Local_u16InnerLoopCounter < 4 ; Local_u16InnerLoopCounter ++)
//		{
//			EEPROM_voidReceiveDataByte((Local_u16LoopCounter + Local_u16InnerLoopCounter ),&Local_u8ReturnedEEPROMValue);
//
//			Local_u32Temp = Local_u8ReturnedEEPROMValue;
//			Local_u32Temp = (Local_u32Temp<< (Local_u16LoopCounter*8));
//			Local_u32StoredID |= Local_u32Temp ;
//
//
//		}
//
//		if (Local_u32StoredID == Copy_u32RFID )
//		{
//			Local_u8IDIsFound = 1;
//			Local_u16TimeArrayIndex = Local_u16LoopCounter + Local_u16InnerLoopCounter + 1 ;
//			EEPROM_voidReceiveDataByte(Local_u16TimeArrayIndex,&Local_u8Hour);
//			Local_u16TimeArrayIndex ++;
//			EEPROM_voidReceiveDataByte(Local_u16TimeArrayIndex,&Local_u8Min);
//
//			SmartParking_voidCalculateCost(&Copy_u8CostPerHour , Copy_u32RFID);
//
//		}
//		else
//		{
//			//Do Nothing
//		}
//	}
//
//
//}