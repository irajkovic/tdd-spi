#include "spi.h"
#include "hal.h"

extern struct Registers REGS;

void SPI_MasterInit(	volatile uint8_t* DDR,		/* SPI port data direction */
						volatile uint8_t* SPDR,		/* data */
						volatile uint8_t* SPCR,		/* config */
						volatile uint8_t* SPSR		/* status */)
{
	*DDR = PIN(DD_MOSI) | PIN(DD_SCK);	
	*SPCR = BIT(SPE) | BIT(MSTR) | BIT(SPR0);
	
	InitRegisterAddresses(SPDR, SPSR);
}

void SPI_SendByte(const uint8_t byte)
{
	SPDR_set(byte);
	
	while(REG_bit_is_off(SPSR, SPIF))
		; // wait
}



