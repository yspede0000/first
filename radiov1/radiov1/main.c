#include <msp430g2231.h>
#include "i2c.h"

void setFreq() //~4158 Hz
{
  unsigned int oct = 2;
  unsigned int dac = 1;

  //f=2^oct*2078/(2-dac/1024)
  unsigned int reg = oct << 12 | dac << 2;

  unsigned char high = (reg >> 8) & 0xff;
  unsigned char low = reg & 0xff;

  i2c_start();
  i2c_write8(i2cAddress << 1);
  i2c_write8(high);
  i2c_write8(low);
  i2c_stop();
}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR |= 0x1C;
// set port 1.2 HIGH (RST)
P1OUT |= 0x04;

// set port 1.3 HIGH (VDD 3.3V)
P1OUT |= 0x08;

// delay 5ms

// set port 1.2 LOW (RST)
P1OUT &= ~0x04;

// set port 1.4 HIGH (SEN)
P1OUT |= 0x10;

unsigned char i2cAddress = 0x11;
i2c_init();
setFreq();
/*
 * CMD 0x01
 * ARG1 0x00
 * ARG2 0x05
 * status 0x80 reply status (clear to send high)
 *
 *
 */
return 0;
}

