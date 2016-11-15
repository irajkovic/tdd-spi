#include "hal.h"
#include "spi.h"

static struct Registers REGS;

void InitRegisterAddresses(	volatile uint8_t* SPDR,
							volatile uint8_t* SPSR,
							volatile uint8_t* SPCR,
							volatile uint8_t* DDR)
{
	REGS.SPDR = SPDR;
	REGS.SPSR = SPSR;
	REGS.SPCR = SPCR;
	REGS.DDR = DDR;
}

/* SPDR */
void SPDR_set(uint8_t val)
{
	*REGS.SPDR = val;
	
	// simulate SPIF of SPSR
	REG_or(SPSR, BIT(SPIF));
}	

void SPDR_or(uint8_t val)
{
	*REGS.SPDR |= val;
}

uint8_t SPDR_get()
{
	return *REGS.SPDR;
}

/* SPSR */
void SPSR_set(uint8_t val)
{
	*REGS.SPSR = val;
}

void SPSR_or(uint8_t val)
{
	*REGS.SPSR |= val;
}

uint8_t SPSR_get()
{
	return *REGS.SPSR;
}

/* DDR */
void DDR_set(uint8_t val)
{
	*REGS.DDR = val;
}

void DDR_or(uint8_t val)
{
	*REGS.DDR |= val;
}

uint8_t DDR_get()
{
	return *REGS.DDR;
}

/*  */
void SPCR_set(uint8_t val)
{
	*REGS.SPCR = val;
}

void SPCR_or(uint8_t val)
{
	*REGS.SPCR |= val;
}

uint8_t SPCR_get()
{
	return *REGS.SPCR;
}
