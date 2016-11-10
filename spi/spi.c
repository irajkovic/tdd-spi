#include "spi.h"

void SPI_MasterInit(	volatile uint8_t* DDR,		/* SPI port data direction */
						volatile uint8_t* SPDR,		/* data */
						volatile uint8_t* SPCR,		/* config */
						volatile uint8_t* SPSR		/* status */)
{
	*DDR = PIN(DD_MOSI) | PIN(DD_SCK);	
	*SPCR = BIT(SPE) | BIT(MSTR) | BIT(SPR0);
}

