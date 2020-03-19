#include <msp430.h>
#include "stateMachines.h"
#include "song.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  if(state == 1) {
      if(note_counter < 5 && ++blink_count == intro_beats[curr_intro]) {
	song_advance();
	blink_count = 0;
      }
      else if(note_counter < 10 && ++blink_count == verse_beats[curr_verse]) {
	song_advance();
	blink_count = 0;
      }
      else {
	if(++blink_count == 100) {
	  song_advance();
	  blink_count = 0;
	}
      }
  }
  
  // Faster Blink Count For Dimming
  else if(state == 2 || state == 4) {
    /*
      state 2 = dim red
      state 4 = dim green
     */
    if (++blink_count == 1) {
      state_advance();
      blink_count = 0;
    }
  }
  
  // Regular Blink Count
  else {
    if (++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }
}
