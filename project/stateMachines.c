#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "song.h"
#include "switches.h"

char state = 0;
char led_state = 0;

void state_advance()
{
  switch(state) {
  case 1:
    play_song();
    break;
  case 2:
    led_changed = red_blink();
    led_state = 1;
    led_update();
    break;
  case 3:
    led_changed = red_plus_green();
    led_state = 2;
    led_update();
    break;
  case 4:
    led_changed = green_blink();
    led_state = 3;
    led_update();
    break;
  }
}

/* State 1 */
void play_song()
{
  if(switch_state_changed) {
    play_bubblegum();
  }
  switch_state_changed = 0;
}

/* State 2 */
char red_blink()
{
  static char curr_state_two = 0;

  switch (led_state) {
  case 0:
   red_on = 1;
   green_on = 0;
   curr_state_two = 1;
   break;

  case 1:
   red_on = 0;
   green_on = 1;
   curr_state_two = 0;
   break;
}
  return 1;
}


/* State 3 */
char red_plus_green()
{
  // Set the start (must be static)
  static char curr_state_three = 0;

  // Toggling; light changes with each button press
  switch(curr_state_three) {

  // Lit up the red light
  case 0:
    red_on = 1;
    green_on = 0;
    curr_state_three = 1;
    break;
    
  // Lit up green light
  case 1:
    red_on = 0;
    green_on = 1;
    curr_state_three = 2;
    break;

  // Lit up both lights
  case 2:
    red_on = 1;
    green_on = 1;
    curr_state_three = 3;
    break;

  // Turn off both lights and repeat
  case 3:
    red_on = 0;
    green_on = 0;
    curr_state_three = 0;
    break;
  }
  return 1;
}

/* State 4 */
char green_blink()
{
  static char curr_state_four = 0;
  return 1;
}
