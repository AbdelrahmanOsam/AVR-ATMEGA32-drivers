/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: SPI
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit(void)
{
	/* Set the micro to be master */
	SET_BIT(SPI_SPCR_REG,SPI_SPCR_MSTR);

	/* Set MSB to be sent first */
	CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_DORD);

	/* Set leading edge to rising and trailing edge to falling */
	#if CLOCK_POLARITY_SELECTION == LEADING_RISING_TRAILING_FALLING_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_CPOL);
	#elif CLOCK_POLARITY_SELECTION == LEADING_FALLING_TRAILING_RISING_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_CPOL);
	#else
		#error "Configuration error : Clock polarity selection error"
	#endif
	
	/* sample at leading edge */
	#if CLOCK_PHASE_SELECTION == SAMPLE_LEADING_SETUP_TRAILING_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_CPHA);
	#elif CLOCK_PHASE_SELECTION == SETUP_LEADING_SAMPLE_TRAILING_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_CPHA);	
	#else
		#error "Configuration error : Clock phase selection error"
	#endif

	/* prescaler , divide by 16 */
	#if CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_4_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_16_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_64_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_128_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_2_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		SET_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_8_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		SET_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_32_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		SET_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#elif CLOCK_RATE_SELECTION == FREQUENCY_DIVIDE_BY_64_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR0);
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPR1);
		SET_BIT(SPI_SPCR_REG,SPI_SPSR_SPI2X);
	#else 
		#error "Configuration error : Clock rate selection error"
	#endif


	/* Enable SPI */
	SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPE);

}

void SPI_voidSlaveInit(void)
{
	/* Set the micro to be slave */
	CLEAR_BIT(SPI_SPCR_REG , SPI_SPCR_MSTR);

	/* Set MSB to be sent first */
	CLR_BIT(SPI_SPCR_REG , SPI_SPCR_DORD);

	/* Set leading edge to rising and trailing edge to falling */
	#if CLOCK_POLARITY_SELECTION == LEADING_RISING_TRAILING_FALLING_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_CPOL);
	#elif CLOCK_POLARITY_SELECTION == LEADING_FALLING_TRAILING_RISING_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_CPOL);
	#else
		#error "Configuration error : Clock polarity selection error"
	#endif

	/* sample at leading edge */
	#if CLOCK_PHASE_SELECTION == SAMPLE_LEADING_SETUP_TRAILING_MODE
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_CPHA);
	#elif CLOCK_PHASE_SELECTION == SETUP_LEADING_SAMPLE_TRAILING_MODE
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_CPHA);	
	#else
		#error "Configuration error : Clock phase selection error"
	#endif

	/* Enable SPI */
	SET_BIT(SPI_SPCR_REG , SPI_SPCR_SPE);
}

u8 SPI_u8SendReceive(u8 Copy_u8Data)
{
	/* set data in SPI_SPDR_REG to send */
	SPI_SPDR_REG = Copy_u8Data;

	/* polling (Busy wait) until transimission completed */
	while(GET_BIT(SPI_SPSR_REG,SPI_SPSR_SPIF) == 0);

	/* Clear the flag */
	//SET_BIT(SPI_SPSR_REG , SPI_SPSR_SPIF);

	/* Get exchanged data */
	return SPI_SPDR_REG;
}

void SPI_voidsendData(u8 Copy_Data)
{
	SPI_SPDR_REG = Copy_Data;
}

u8 SPI_u8ReceiveData(u8 *pdata)
{
	if(GET_BIT(SPI_SPSR_REG ,SSPI_ SPSR_SPIF) == 1){
		*pdata =  SPI_SPDR_REG;
		return 1;
	}

	return 0;
}