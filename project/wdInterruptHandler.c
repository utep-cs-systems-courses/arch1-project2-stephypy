#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  // super speedyboi fast for dimming
  if(state == 2 || state == 4) {
    if (++blink_count == 1) {
      state_advance();
      blink_count = 0;
    }
  }
  else {
    if (++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }
}
