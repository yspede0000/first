#include <msp430g2231.h>
#include "i2c.h"

unsigned char i2cAddress = 0x40;
int i;

void setFreq() //~4158 Hz
{
  unsigned int oct = 2;
  unsigned int dac = 1;

  //f=2^oct*2078/(2-dac/1024)
  unsigned int reg = oct << 12 | dac << 2;

  unsigned char high = (reg >> 8) & 0xff;
  unsigned char low = reg & 0xff;


}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR |= 0x1C;
// set port 1.2 HIGH (RST)
P1OUT |= 0x04;

// set port 1.3 HIGH (VDD 3.3V)
P1OUT |= 0x08;

for (i=1; i<30000; i=i+1) {}  //Delay

// delay 5ms

// set port 1.2 LOW (RST)
P1OUT &= ~0x04;

// set port 1.4 HIGH (SEN)
P1OUT |= 0x10;


i2c_init();
setFreq();
i2c_write8(i2cAddress << 1);
//while(1) {
  i2c_write8(0x2h);
  i2c_write8(0x7f);

//}
  i2c_stop();
/*
 * CMD 0x01
 * ARG1 0x00
 * ARG2 0x05
 * status 0x80 reply status (clear to send high)
 *
 *
 */

}

