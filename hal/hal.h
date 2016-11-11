#ifndef HAL
#define HAL

#include <inttypes.h>

/* Holding pointers to registers */ 
struct Registers
{
	volatile uint8_t* SPDR;	/* SPI Data Register */
	volatile uint8_t* SPSR;	/* SPI Data Status Register */
};

void InitRegisterAddresses(volatile uint8_t* SPDR,
			volatile uint8_t* SPSR);
void RegSetSPDR(uint8_t byte);


#endif
