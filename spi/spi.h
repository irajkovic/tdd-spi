#ifndef SPI
#define SPI

#define PIN(n) (1 << n)
#define BIT(n) (1 << n)

/****** ATMEGA328p pin definitions  ******/

/* Control register constants */
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

/* Status register constants */
#define SPI2X 0
#define WCOL 6
#define SPIF 7

/* Data direction constants */
#define DD_SS 2
#define DD_MOSI 3
#define DD_MISO 4
#define DD_SCK 5

#include <inttypes.h>

/****** Function definitions *******/
				
void SPI_MasterInit();
						
void SPI_SendByte(const uint8_t byte);

#endif
