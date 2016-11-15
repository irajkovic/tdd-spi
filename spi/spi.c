#include "spi.h"
#include "hal.h"

void SPI_MasterInit()
{
	REG_set(DDR, PIN(DD_MOSI) | PIN(DD_SCK));
	REG_set(SPCR, BIT(SPE) | BIT(MSTR) | BIT(SPR0));
}

void SPI_SendByte(const uint8_t byte)
{
	REG_set(SPDR, byte);
	while(REG_bit_is_off(SPSR, SPIF))
		; // wait
}



