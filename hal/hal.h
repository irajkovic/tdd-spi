#ifndef HAL
#define HAL

#include <inttypes.h>

/* Holding pointers to registers */ 
struct Registers
{
	volatile uint8_t* SPDR;	/* SPI Data Register */
	volatile uint8_t* SPSR;	/* SPI Data Status Register */
};

void InitRegisterAddresses(	volatile uint8_t* SPDR,
							volatile uint8_t* SPSR);


#define REG_set(register, value) (*(REGS.register) = value)
#define REG_or(register, value) (*(REGS.register) |= value)
#define REG_get(register) (*(REGS.register))
#define REG_bit_is_on(register, bit) (REG_get(register) & BIT(bit))
#define REG_bit_is_off(register, bit) (!REG_bit_is_on(register, bit))

#ifdef TESTING	
void SPDR_set(uint8_t val);
void SPDR_or(uint8_t val);
uint8_t SPDR_get();
#else
	#define SPDR_set(val) REG_set(SPDR, val)
	#define SPDR_or(val) REG_set(SPDR, val)
	#define SPDR_get() REG_get(SPDR)
#endif






#endif
