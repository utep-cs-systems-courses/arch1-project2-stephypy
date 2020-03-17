#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "song.h"

char changed = 0;
char curr_state = -1; //Prior to attending a state

char red_status, toggle_status, green_status;

/* Allows to Change the State  */
void state_advance()	
{
  /* Determine the curr state */
  switch(curr_state) {

  /* Play Bubblegum */
  case 0:
    if(switch_state_changed) play_bubblegum();

  /* Dim Red To Bright Red */
  case 1:
    led_update();

  /* Toggle Between Red and Green */
  case 2:
    if(toggle_status == 1) toggle_status = 0;
    else toggle_status = 1;
    led_update();

  /* Bright Green To Dim Green */ 
  case 3:
    led_update();
  }
}



