#include <msp430.h>
#include "song.h"
#include "stateAdvance_assembly.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  char beat = 68; // Represents the needed interrupts for an eighth note
  
  // Song Interrupts
  if(state == 1) {
      // While the song isn't finished, have 68 interrupts/sec 
      if(curr_verse < 48 && ++blink_count == beat) {
	state_advance();
	blink_count = 0;
      }
      // Once song is over, play a quarter note
      else {
	if(++blink_count == 136) {
	  state_advance();
	  blink_count = 0;
	}
     }
  }
  // Faster Blink Count For Dimming
  else if(state == 2 && ++blink_count == 1) {
     state_advance();
     blink_count = 0;
  }
  // Regular Blink Count
  else {
    if (++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }
}
