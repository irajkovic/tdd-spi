#include "hal.h"
#include "spi.h"

struct Registers REGS;

void InitRegisterAddresses(	volatile uint8_t* SPDR,
							volatile uint8_t* SPSR)
{
	REGS.SPDR = SPDR;
	REGS.SPSR = SPSR;
}

#ifdef TESTING
void SPDR_set(uint8_t val)
{
	REG_set(SPDR, val);
	
	// simulate SPIF of SPSR
	REG_or(SPSR, BIT(SPIF));
}	

void SPDR_or(uint8_t val)
{
	REG_set(SPDR, val);
}

uint8_t SPDR_get()
{
	return REG_get(SPDR);
}
#endif
