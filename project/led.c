#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    if (switch_state_down_s1) {

      ledFlags |= switch_state_down_s1 ? LED_GREEN : 0;
      ledFlags |= switch_state_down_s1 ? 0 : LED_RED;

    }

    if (switch_state_down_s2) {

      ledFlags |= switch_state_down_s2 ? LED_GREEN : 0;
      ledFlags |= switch_state_down_s2 ? 0 : LED_RED;

    }

    if (switch_state_down_s3) {

      ledFlags |= switch_state_down_s3 ? LED_GREEN : 0;
      ledFlags |= switch_state_down_s3 ? 0 : LED_RED;

    }

    if (switch_state_down_s4) {

      ledFlags |= switch_state_down_s4 ? LED_GREEN : 0;
      ledFlags |= switch_state_down_s4 ? 0 : LED_RED;

    }

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds

  }
  switch_state_changed = 0;
}

