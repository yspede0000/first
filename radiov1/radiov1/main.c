#include <msp430g2231.h>
#include "i2c.h"

unsigned char radio = 0x11; // address on si4735
unsigned char expander = 0x20; //address on mcp23016
unsigned char dir0 = 0x06; // direction register Port0
unsigned char port0 = 0x00; // Port0; can be directly written/read.

void delay(void) {
	unsigned int o = 0;
	P1DIR |= 0x01;
	for (o = 0; o < 50000; o++) // This empty for-loop will cause the lines of code within to loop infinitely
			{
		P1OUT ^= 0x01;
	}
}

void ledon(void)
{
	i2c_start();
	i2c_write8(expander << 1);
	i2c_write8(dir0);
	i2c_write8(0x00); // all port0 output
	i2c_stop();

	i2c_start();
	i2c_write8(expander << 1);
	i2c_write8(port0);
	i2c_write8(0xFF); // all port0 high
	i2c_stop();
}

void ledoff(void)
{
	i2c_start();
	i2c_write8(expander << 1);
	i2c_write8(dir0);
	i2c_write8(0x00); // all port0 output
	i2c_stop();

	i2c_start();
	i2c_write8(expander << 1);
	i2c_write8(port0);
	i2c_write8(0x00); // all port0 low
	i2c_stop();
}

void startup(void) {
	P1DIR |= 0x1C;
	// set port 1.2 LOW (RST)
	P1OUT &= 0x04;

	// set port 1.3 LOW (VDD 3.3V)
	P1OUT &= 0x08;

	// set port 1.4 HIGH (SEN)
	P1OUT |= 0x10;

	delay();

	// set port 1.3 HIGH (VDD 3.3V)
	P1OUT |= 0x08;

	delay();

	// set port 1.2 High (RST)
	P1OUT |= ~0x04;

	delay();



}

void main(void) {
	WDTCTL = WDTPW + WDTHOLD;

	delay(); // wait a while

	i2c_init(); // startup i2c

	startup(); // startup the radio chip (not tested)

	ledon(); // set all pin on expander portA high
	ledoff(); // set all pin low on expander portA

	i2c_start();
	i2c_write8(radio << 1);
	i2c_write8(0x01); // startup register
	i2c_write8(0x10); // use crystal for clock
	i2c_write8(0x05); // analog output
	i2c_stop();


}
