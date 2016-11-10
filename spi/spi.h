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

#endif
