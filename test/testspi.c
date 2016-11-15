#include "testspi.h"

TEST_GROUP(spi);

/* Fake registers */
uint8_t DDR = 0x00;
uint8_t SPDR = 0x00;
uint8_t SPCR = 0x00;
uint8_t SPSR = 0x00;

TEST_SETUP(spi)
{
	InitRegisterAddresses(&SPDR,&SPSR,&SPCR,&DDR);
}

TEST_TEAR_DOWN(spi)
{
}



/* Tests */
TEST(spi, ControlRegisterConstants)
{
	TEST_ASSERT_EQUAL_HEX8(0, SPR0);
	TEST_ASSERT_EQUAL_HEX8(1, SPR1);
	TEST_ASSERT_EQUAL_HEX8(2, CPHA);
	TEST_ASSERT_EQUAL_HEX8(3, CPOL);
	TEST_ASSERT_EQUAL_HEX8(4, MSTR);
	TEST_ASSERT_EQUAL_HEX8(5, DORD);
	TEST_ASSERT_EQUAL_HEX8(6, SPE);
	TEST_ASSERT_EQUAL_HEX8(7, SPIE);
}

TEST(spi, StatusRegisterConstants)
{
	TEST_ASSERT_EQUAL_HEX8(0, SPI2X);
	TEST_ASSERT_EQUAL_HEX8(6, WCOL);
	TEST_ASSERT_EQUAL_HEX8(7, SPIF);
}

TEST(spi, DataDirectionConstants)
{
	/* Table 14-3 */ 
	TEST_ASSERT_EQUAL(2, DD_SS);
	TEST_ASSERT_EQUAL(3, DD_MOSI);
	TEST_ASSERT_EQUAL(4, DD_MISO);
	TEST_ASSERT_EQUAL(5, DD_SCK);
}

TEST(spi, Init)
{	
	SPI_MasterInit();

	TEST_ASSERT_EQUAL_HEX8((1<<DD_MOSI)|(1<<DD_SCK), DDR);
	TEST_ASSERT_EQUAL_HEX8((1<<SPE)|(1<<MSTR)|(1<<SPR0), SPCR);
}

TEST(spi, SendByte)
{
	// setup
	const uint8_t data = 0xA5;
	SPSR = 0x00;
	SPDR = 0x00;
	SPI_MasterInit();
	
	// exercise
	SPI_SendByte(data);
	
	// verify
	TEST_ASSERT_EQUAL_HEX8(data, SPDR);
	TEST_ASSERT_EQUAL_HEX8(BIT(SPIF), SPSR);
		
	// cleanup
	SPSR = 0x00;
	SPDR = 0x00;	
}

TEST_GROUP_RUNNER(spi)
{ 
	RUN_TEST_CASE(spi, ControlRegisterConstants);
	RUN_TEST_CASE(spi, StatusRegisterConstants);
	RUN_TEST_CASE(spi, DataDirectionConstants);
	RUN_TEST_CASE(spi, Init);
	RUN_TEST_CASE(spi, SendByte);
}







