#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "song.h"

/* State 1 */
void play_song()
{
  play_bubblegum();
}

/* State 2 */
void red_blink()
{
  static char curr_state_two = 0;
}

/* State 3 */
void red_plus_green()
{
  // Set the start
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

  // Lit up both lights, then repeat
  case 2:
    red_on = 1;
    green_on = 1;
    curr_state_three = 0;
    break;
  }
}

/* State 4 */
void green_blink()
{
  static char curr_state_four = 0;
}
