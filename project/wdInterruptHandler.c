#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  // Faster Blink Count For Dimming
  if(state == 2 || state == 4) {
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
