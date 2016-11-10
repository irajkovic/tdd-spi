#include "spi.h"

void SPI_MasterInit(	volatile uint8_t* DDR,		/* SPI port data direction */
						volatile uint8_t* SPDR,		/* data */
						volatile uint8_t* SPCR,		/* config */
						volatile uint8_t* SPSR		/* status */)
{
	*DDR = (1<<DD_MOSI) | (1<<DD_SCK);
}
