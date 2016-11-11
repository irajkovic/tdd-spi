#include "hal.h"

static struct Registers REGS;

void RegSetSPDR(uint8_t byte)
{
	*(REGS.SPDR) = byte;
}

void InitRegisterAddresses(	volatile uint8_t* SPDR,
							volatile uint8_t* SPSR)
{
	REGS.SPDR = SPDR;
	REGS.SPSR = SPSR;
}
