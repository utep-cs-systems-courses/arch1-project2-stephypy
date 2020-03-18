#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

unsigned char red_on = 0, green_on = 0, led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

// Initialize LEDs
void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

// Update LEDs
void led_update(){

  switch(led_state) {
  case 1:
    {
    char ledFlags = redVal[red_on];

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    break;
    }
  case 2:
    {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    break;
    }
  case 3:
    {
    char ledFlags = greenVal[green_on];

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    break;
    }
  }
  switch_state_changed = 0;
}
