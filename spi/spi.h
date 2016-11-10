#ifndef SPI
#define SPI

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
#define DD_SS 0	
#define DD_MOSI 0
#define DD_MISO 0
#define DD_SCK 0

/****** Function definitions *******/
void SPI_MasterInit(	volatile uint8_t* DDR,		/* SPI port data direction */
						volatile uint8_t* SPDR,		/* data */
						volatile uint8_t* SPCR,		/* config */
						volatile uint8_t* SPSR		/* status */);

#endif
