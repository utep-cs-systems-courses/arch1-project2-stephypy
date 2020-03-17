#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "song.h"

char sw1_state_down, sw2_state_down, sw3_state_down, sw4_state_down;
char switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  // Determine which button is pressed down
   sw1_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
   sw2_state_down = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
   sw3_state_down = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
   sw4_state_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */

   // Determine the state for the state machine
   if(sw1_state_down) {          /* SW1 = Play Song */
     curr_state = 0;             // Selects current state
     switch_state_changed = 1;   // Acknowledges change in state
     state_advance();            // Advances to the state selected
   }
   if(sw2_state_down) {          /* SW2 = Dim Red to Bright Red */
     curr_state = 1;             // Selects current state
     switch_state_changed = 1;   // Acknowledges change in state
     state_advance();            // Advances to the state selected
   }
   if(sw3_state_down) {          /* SW3 = Toggle Lights */
     curr_state = 2;             // Selects current state
     switch_state_changed = 1;   // Acknowledges change in state
     state_advance();            // Advances to the state selected
     led_update();               /* Question: I know this updates the LED but isn't this line redundant since I am already calling led_update inside state_advance? However, I did notice an improvement when writing this line so that's why I am updating the LED again */
   }
   if(sw4_state_down) {          /* SW4 = Bright Green to Dim Green */
     curr_state = 3;             // Selects current state
     switch_state_changed = 1;   // Acknowledges change in state
     state_advance();            // Advances to the state selected
   }
}
