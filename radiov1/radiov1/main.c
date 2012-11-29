#include <msp430g2231.h>
#include "i2c.h"



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
