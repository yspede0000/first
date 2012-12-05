#include <msp430g2231.h>
#include "i2c.h"

unsigned char expander = 0x20; //address on mcp23016
unsigned char dir0 = 0x06; // direction register Port0
unsigned char port0 = 0x00; // Port0; can be directly written/read.




void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;

	   i2c_init(); // startup i2c

 /*
  P1DIR |= 0x1C;
// set port 1.2 LOW (RST)
P1OUT &= 0x04;

// set port 1.3 LOW (VDD 3.3V)
P1OUT &= 0x08;

// set port 1.4 HIGH (SEN)
P1OUT |= 0x10;



// delay 1ms
delay(201);

// set port 1.2 High (RST)
P1OUT &= ~0x04;

// delay 100ms

// set port 1.3 HIGH (VDD 3.3V)
P1OUT |= 0x08;
*/



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


/*
 * CMD 0x01 // point on startup reg
 * ARG1 0x10 // send use crystal
 * ARG2 0x05 // use analog output.
 * status 0x80 reply status (clear to send high)
 *
 *
 */

}
