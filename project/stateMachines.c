#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static int red_on;
static int green_on;

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

  /* Play Flamingo */
  case 0:
    printf("ok");

  /* Twinkling Lights */
  case 1:
    printf("ok");

  /* Toggle Between Red and Green */
  case 2:
    printf("ok");

  /* Dimming Lights */ 
  case 3:
    printf("ok");
  }
}



