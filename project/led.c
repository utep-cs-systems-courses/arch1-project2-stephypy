#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "song.h"

unsigned char red_on = 0;
unsigned char green_on = 0;
unsigned char led_changed = 0;

// Initialize LEDs
void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

// Update LEDs
void led_update(){

  char ledFlags = 0; /* by default, no LEDs on */
  
  // When states are changed:
  if (switch_state_changed) {

    // Dim Red to Bright Red
    if(sw2_state_down) {
      red_on = 0;
      // ledFlags |= sw2_state_down ? LED_RED : 0;
      //ledFlags |= sw2_state_down ? 0 : LED_GREEN;
    }

    // Toggle Between Red and Green
    if(sw3_state_down) {

      // Determine what color the LED should change to
      switch(toggle_status){

      /* Toggle Status 0 is RED */
      case 0:
	ledFlags |= LED_RED;
	break;

      /* Toggle Status 1 is GREEN */
      case 1:
	ledFlags |= LED_GREEN;
       	break;
      }

      P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
      P1OUT |= ledFlags;         // set bits for on leds
    }

    // Bright Green to Dim Green
    if(sw4_state_down) {
      red_on = 0;
      // ledFlags |= sw4_state_down ? LED_GREEN : 0;
      // ledFlags |= sw4_state_down ? 0 : LED_GREEN;
    }
    
    // P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    //P1OUT |= ledFlags; // set bits for on leds
  }
  switch_state_changed = 0;
}
