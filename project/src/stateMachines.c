#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "song.h"
#include "switches.h"
#include "assembly.h"

char state = 0;

/* Activating selected state from switches.c */
void state_advance()
{
  switch(state) {
  // State 1: Playing Fallen Down
  /*
    State 1 functions are found in file song.c
  */
    
  // State 2: Red Dim
  case 2:
    // Restart the values for state 1
    note_counter = 0;
    curr_verse = 0;

    // Call the function corresponding to state 2
    dim_red(); 
    led_update();
    break;

  // State 3: Red Plus Green
  case 3:
    // Restart the values for state 1
    note_counter = 0;
    curr_verse = 0;

    // Call the function corresponding to state 3
    red_plus_green();
    led_update();
    break;

  // State 4: Green Dim
  /*
    State 4 functions are found in file assembly.s
  */

  case 4:
    dim_green_assembly();
    break;
  /*
  case 4:
    // Restart the values for state 1
    note_counter = 0;
    curr_verse = 0;

    // Call the function corresponding to state 4
    dim_green();
    led_update();
    break;
  */
  }
}

/* State 1 
** Found in file song.c
*/

/* State 2 */
void dim_red()
{
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
void red_plus_green()
{
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
/* C code for State 4; Go to assembly.s for state 4 code */
/*
void dim_green()
{
  // Set Start
  static char curr_state_four = 0;

  switch (curr_state_four) {
  // Cases 0 - 3 will have both lights turned off  
  case 0:
   red_on = 0;
   green_on = 0;
   curr_state_four = 1; // Next
   break;

  case 1:
   red_on = 0;
   green_on = 0;
   curr_state_four = 2; // Next
   break;
       
  case 2:
   red_on = 0;
   green_on = 0;
   curr_state_four = 3; // Next
   break;
   
  case 3:
   red_on = 0;
   green_on = 0;
   curr_state_four = 4; // Next
   break;

  // Turn on green light; blink count is at 1 so it will appear dimmed
  case 4:
   red_on = 0;
   green_on = 1;
   curr_state_four = 0; // Repeat
   break;
  }
}
*/