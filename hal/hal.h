#ifndef HAL
#define HAL

#include <inttypes.h>

#define REG_bit_is_on(register, bit) (REG_get(register) & BIT(bit))
#define REG_bit_is_off(register, bit) (!REG_bit_is_on(register, bit))
											
#define REG_set(register, value) (register = value)
#define REG_or(register, value) (register |= value)
#define REG_get(register) (register)

#endif

