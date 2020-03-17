#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "song.h"

char color_state = 0;
char changed = 0;
char curr_state = 0;
char state_1, state_2, state_3, state_4;

char toggle_red()		/* always toggle! */
{
  static char state = 0;
  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* change the state */
{
  /* Determine the curr state */
  switch(curr_state) {

  /* Play Bubblegum */
  case 0:
    if(switch_state_changed) play_bubblegum();

  /* Dim Red To Bright Red */
  case 1:
    color_state = 1;
    led_update();

  /* Toggle Between Red and Green */
  case 2:
    // changed = 1;
    led_update();

  /* Bright Green To Dim Green */ 
  case 3:
    color_state = 3;
    led_update();
  }
}



