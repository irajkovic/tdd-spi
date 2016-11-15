#ifndef TEST_HAL
#define TEST_HAL

#include <inttypes.h>
#include "../../hal/hal.h"

#undef InitRegisterAddresses
#undef REG_set
#undef REG_or
#undef REG_get

#define REG_set(register, value) (register##_set(value))
#define REG_or(register, value) (register##_or(value))
#define REG_get(register) (register##_get())

void InitRegisterAddresses(	volatile uint8_t* SPDR,
							volatile uint8_t* SPSR,
							volatile uint8_t* SPCR,
							volatile uint8_t* DDR);

/* Holding pointers to registers */ 
struct Registers
{
	volatile uint8_t* SPDR;	/* SPI Data Register */
	volatile uint8_t* SPSR;	/* SPI Data Status Register */
	volatile uint8_t* SPCR;	/* SPI Data Configuration Register */
	volatile uint8_t* DDR;	/* SPI Data Direction Register */
};

void SPSR_set(uint8_t val);
void SPSR_or(uint8_t val);
uint8_t SPSR_get();

void SPDR_set(uint8_t val);
void SPDR_or(uint8_t val);
uint8_t SPDR_get();

void SPCR_set(uint8_t val);
void SPCR_or(uint8_t val);
uint8_t SPCR_get();


void DDR_set(uint8_t val);
void DDR_or(uint8_t val);
uint8_t DDR_get();



#endif

