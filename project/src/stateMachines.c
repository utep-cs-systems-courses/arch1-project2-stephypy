#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "song.h"

/* State 1 
** Found in file song.c
*/

/* State 2 */
void dim_red() {
  // Restart values for state 1
  curr_verse = 0;
  buzzer_set_period(0);
  
  // Set Start
  static char curr_state_two = 0;
   switch (curr_state_two) {

   // Cases 0 - 3 have both lights turned off
   case 0:
    red_on = 0;
    green_on = 0;
    curr_state_two = 1; // Next
    break;

   case 1:
    red_on = 0;
    green_on = 0;
    curr_state_two = 2; // Next
    break;
       
   case 2:
    red_on = 0;
    green_on = 0;
    curr_state_two = 3; // Next
    break;

   case 3:
    red_on = 0;
    green_on = 0;
    curr_state_two = 4; // Next
    break;

   // Turn on red light and since the blink count is 1, it will appear dimmmed
   case 4:
    red_on = 1;
    green_on = 0;
    curr_state_two = 0; // Repeat
    break;
  }
}

/* State 3 */
void red_plus_green() {
  // Restart values for state 1
  curr_verse = 0;
  buzzer_set_period(0);
  
  // Set the start (must be static)
  static char curr_state_three = 0;

  // Get ready for a light show~
  switch(curr_state_three) {

  // Lit up the red light
  case 0:
    red_on = 1;
    green_on = 0;
    curr_state_three = 1; // Next
    break;
    
  // Lit up green light
  case 1:
    red_on = 0;
    green_on = 1;
    curr_state_three = 2; // Next
    break;

  // Lit up both lights
  case 2:
    red_on = 1;
    green_on = 1;
    curr_state_three = 3; // Next
    break;

  // Turn off both lights and repeat
  case 3:
    red_on = 0;
    green_on = 0;
    curr_state_three = 0; // Repeat
    break;
  }
}

/* State 4 */
void green_to_red() {
  // Restart values for state 1
  curr_verse = 0;
  buzzer_set_period(0);
  
  static char curr_state_four = 0;
  switch(curr_state_four) {
  case 0:
    red_on = 0;
    green_on = 1;
    curr_state_four = 1;
    break;

  case 1:
    red_on = 1;
    green_on = 0;
    curr_state_four = 0;
    break;
  }
}
