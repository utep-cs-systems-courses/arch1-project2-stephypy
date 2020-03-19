#include <msp430.h>
#include "stateMachines.h"
#include "song.h"
#include "assembly.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  if(state == 1) {
      if(curr_verse < 36 && ++blink_count == BEAT) {
	song_advance();
	blink_count = 0;
      }
      else {
	if(++blink_count == 136) {
	  song_advance();
	  blink_count = 0;
	}
     }
  }
  // Faster Blink Count For Dimming
  else if(state == 2 && ++blink_count == 1) {
     state_advance();
     blink_count = 0;
  }
  else if(state == 4 && ++blink_count == 1) {
    dim_green_assembly();
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
